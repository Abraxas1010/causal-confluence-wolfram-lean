(* ::Package:: *)
(* HeytingLean Wolfram Bridge — Wolfram Language reference implementation
   This file provides a small, dependency-free Wolfram Language script that reproduces the
   CE1/CE2 multiway evolution JSON emitted by the Lean executable `wolfram_multiway_demo`.

   Goals:
   - Provide a Wolfram Language artifact that independently reproduces the same bounded multiway graphs.
   - Match the Lean semantics used in `HeytingLean.WPP.Wolfram`:
       * states are multisets of ordered vertex-lists (hyperedges)
       * matches σ : P → V are not assumed injective (we enumerate all σ for P = Fin 2)
       * applicability is multiset inclusion of instantiated LHS
       * event application removes instantiated LHS and adds instantiated RHS

   Usage (in Wolfram/Mathematica):
     Get["RESEARCHER_BUNDLE/tools/wolfram_ce1_ce2.wl"];
     Export["ce1_from_wl.json", CE1JSON[3], "JSON"];
     Export["ce2_from_wl.json", CE2JSON[2], "JSON"];
     CompareWithLeanJSON[CE1JSON[3], "RESEARCHER_BUNDLE/artifacts/generated_ce1.json"]
*)

BeginPackage["HeytingLeanWolframBridge`"];

CE1System::usage = "CE1System is the CE1 counterexample system (confluent ∧ ¬causal-invariant) as a WL association.";
CE2System::usage = "CE2System is the CE2 counterexample system (causal-invariant ∧ ¬confluent) as a WL association.";

BuildMultiwayJSON::usage =
  "BuildMultiwayJSON[sys, maxDepth] computes the bounded multiway exploration and returns a WL association matching the Lean JSON schema.";

CE1JSON::usage = "CE1JSON[maxDepth] returns the multiway JSON object for CE1.";
CE2JSON::usage = "CE2JSON[maxDepth] returns the multiway JSON object for CE2.";

ExportCE1JSON::usage = "ExportCE1JSON[path, maxDepth] writes CE1JSON[maxDepth] to `path` as JSON.";
ExportCE2JSON::usage = "ExportCE2JSON[path, maxDepth] writes CE2JSON[maxDepth] to `path` as JSON.";

CompareWithLeanJSON::usage =
  "CompareWithLeanJSON[obj, leanPath] imports `leanPath` as JSON and returns an association with equality and (if different) a minimal summary.";

Begin["`Private`"];

(* ------------------------- *)
(* Canonicalization utilities *)
(* ------------------------- *)

exprSortKey[expr_List] := {Length[expr], expr};

NormalizeHGraph[g_List] := SortBy[g, exprSortKey];

HGraphKey[g_List] := ToString[NormalizeHGraph[g], InputForm];

(* ------------------------- *)
(* Multiset primitives        *)
(* ------------------------- *)

MultisetLeqQ[a_List, b_List] := Module[{ca, cb, ks},
  ca = Counts[a];
  cb = Counts[b];
  ks = Keys[ca];
  And @@ (Lookup[cb, #, 0] >= ca[#] & /@ ks)
];

MultisetRemoveOnce[g_List, e_] := Module[{pos},
  pos = FirstPosition[g, e, Missing["NotFound"]];
  If[pos === Missing["NotFound"], g, Delete[g, pos[[1]]]]
];

MultisetRemoveList[g_List, es_List] := Fold[MultisetRemoveOnce, g, es];

(* ------------------------- *)
(* Rule instantiation         *)
(* ------------------------- *)

(* Pattern vertices (the Lean development uses P = Fin 2). *)
p0 = Unique["p0$"];
p1 = Unique["p1$"];

InstantiateExpr[expr_List, sigma_List] := expr /. {p0 -> sigma[[1]], p1 -> sigma[[2]]};

InstantiateHGraph[edges_List, sigma_List] := InstantiateExpr[#, sigma] & /@ edges;

ApplicableQ[sys_Association, sigma_List, state_List] := Module[{lhsInst},
  lhsInst = InstantiateHGraph[sys["rule"]["lhs"], sigma];
  MultisetLeqQ[lhsInst, state]
];

ApplyEvent[sys_Association, sigma_List, state_List] := Module[{lhsInst, rhsInst, sMinus},
  lhsInst = InstantiateHGraph[sys["rule"]["lhs"], sigma];
  rhsInst = InstantiateHGraph[sys["rule"]["rhs"], sigma];
  sMinus = MultisetRemoveList[state, lhsInst];
  NormalizeHGraph@Join[sMinus, rhsInst]
];

(* ------------------------- *)
(* Basis + count vectors      *)
(* ------------------------- *)

BasisLen1Len2[verts_List] := Join[List /@ verts, Flatten[Table[{a, b}, {a, verts}, {b, verts}], 1]];

HGraphCountsVector[g_List, basis_List] := Module[{cg},
  cg = Counts[g];
  Lookup[cg, basis, 0]
];

(* ------------------------- *)
(* Bounded multiway builder   *)
(* ------------------------- *)

AllSigmasFin2[verts_List] := Tuples[verts, 2]; (* includes non-injective assignments *)

PairEdges[idxs_List] := Flatten[Table[{idxs[[i]], idxs[[j]]}, {i, 1, Length[idxs]}, {j, i + 1, Length[idxs]}], 1];

BuildMultiwayJSON[sys_Association, maxDepth_Integer?NonNegative] := Module[
  {verts, basis, nodes, nodeId, edges, branchial, levels, pathCounts,
   currStates, currCounts, getOrAddNode},

  verts = sys["verts"];
  basis = BasisLen1Len2[verts];

  nodes = {NormalizeHGraph[sys["init"]]};
  nodeId = Association[HGraphKey[sys["init"]] -> 0];
  edges = {};
  branchial = {};
  levels = {{0}};

  currStates = {NormalizeHGraph[sys["init"]]};
  currCounts = Association[0 -> 1];
  pathCounts = {{<|"id" -> 0, "count" -> 1|>}};

  getOrAddNode = Function[{g},
    Module[{key, id},
      key = HGraphKey[g];
      If[KeyExistsQ[nodeId, key],
        nodeId[key],
        id = Length[nodes];
        AppendTo[nodes, NormalizeHGraph[g]];
        AssociateTo[nodeId, key -> id];
        id
      ]
    ]
  ];

  Do[
    Module[{nextRaw = {}, nextCounts = Association[], sigmas = AllSigmasFin2[verts]},
      Do[
        Module[{s = currStates[[k]], srcId, srcCount, childIds = {}},
          srcId = nodeId[HGraphKey[s]];
          srcCount = Lookup[currCounts, srcId, 0];
          Do[
            Module[{sigma = sigmas[[m]]},
              If[ApplicableQ[sys, sigma, s],
                Module[{t, dstId},
                  t = ApplyEvent[sys, sigma, s];
                  dstId = getOrAddNode[t];
                  AppendTo[edges, <|
                    "src" -> srcId,
                    "dst" -> dstId,
                    "label" -> <|"ruleIdx" -> 0, "sigma" -> sigma|>
                  |>];
                  AppendTo[childIds, dstId];
                  AppendTo[nextRaw, t];
                  AssociateTo[nextCounts, dstId -> (Lookup[nextCounts, dstId, 0] + srcCount)];
                ],
                Null
              ]
            ],
            {m, Length[sigmas]}
          ];
          Module[{childIdsDedup = DeleteDuplicates[childIds]},
            Do[
              branchial = Append[branchial, <|"i" -> p[[1]], "j" -> p[[2]]|>],
              {p, PairEdges[childIdsDedup]}
            ]
          ];
        ],
        {k, Length[currStates]}
      ];

      Module[{nextStates, nextLevelIds, nextLevelCounts},
        nextStates = DeleteDuplicatesBy[nextRaw, HGraphKey];
        nextLevelIds = nodeId[HGraphKey[#]] & /@ nextStates;
        levels = Append[levels, nextLevelIds];

        nextLevelCounts = (<|"id" -> #, "count" -> Lookup[nextCounts, #, 0]|> &) /@ nextLevelIds;
        pathCounts = Append[pathCounts, nextLevelCounts];

        currStates = nextStates;
        currCounts = nextCounts;
      ];
    ],
    {maxDepth}
  ];

  <|
    "maxDepth" -> maxDepth,
    "basis_len1_len2" -> basis,
    "nodes" -> (HGraphCountsVector[#, basis] & /@ nodes),
    "edges" -> edges,
    "levels" -> levels,
    "branchial" -> branchial,
    "pathCounts" -> pathCounts
  |>
];

(* ------------------------- *)
(* CE1 / CE2 systems          *)
(* ------------------------- *)

CE1System = <|
  "verts" -> {0, 1, 2},
  "rule" -> <|
    "lhs" -> {{p0}, {p0, p1}},
    "rhs" -> {{p0, p1}, {p1}}
  |>,
  "init" -> {{0}, {0, 1}, {1, 2}, {0, 2}}
|>;

CE2System = <|
  "verts" -> {0, 1},
  "rule" -> <|
    "lhs" -> {{p0, p1}, {p1, p0}},
    "rhs" -> {{p0}}
  |>,
  "init" -> {{0, 1}, {1, 0}, {0}}
|>;

CE1JSON[maxDepth_Integer?NonNegative : 3] := BuildMultiwayJSON[CE1System, maxDepth];
CE2JSON[maxDepth_Integer?NonNegative : 2] := BuildMultiwayJSON[CE2System, maxDepth];

ExportCE1JSON[path_String, maxDepth_Integer?NonNegative : 3] := Export[path, CE1JSON[maxDepth], "JSON"];
ExportCE2JSON[path_String, maxDepth_Integer?NonNegative : 2] := Export[path, CE2JSON[maxDepth], "JSON"];

CompareWithLeanJSON[obj_Association, leanPath_String] := Module[{leanObj, eq},
  leanObj = Import[leanPath, "JSON"];
  eq = (obj === leanObj);
  <|
    "equal" -> eq,
    "leanPath" -> leanPath,
    "note" -> If[eq, "WL object matches Lean JSON import.", "WL object differs from Lean JSON import (compare in a notebook for details)."]
  |>
];

End[];
EndPackage[];

