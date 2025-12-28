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
WM148System::usage = "WM148System is the Wolfram Physics universe WM148 (fresh-vertex rule {{x,y}} -> {{x,y},{y,z}}) as a WL association.";

ToJSONString::usage =
  "ToJSONString[x] encodes a JSON-compatible WL expression (numbers, strings, lists, associations, booleans, Null) as a JSON string. \
This is intended as a lightweight fallback for WL runtimes that do not implement Export/ExportString to JSON (e.g. Mathics).";

BuildMultiwayJSON::usage =
  "BuildMultiwayJSON[sys, maxDepth] computes the bounded multiway exploration and returns a WL association matching the Lean JSON schema.";

CE1JSON::usage = "CE1JSON[maxDepth] returns the multiway JSON object for CE1.";
CE2JSON::usage = "CE2JSON[maxDepth] returns the multiway JSON object for CE2.";
WM148JSON::usage = "WM148JSON[maxDepth] returns the multiway JSON object for WM148 (deterministic fresh vertices).";

CE1JSONString::usage = "CE1JSONString[maxDepth] returns CE1JSON[maxDepth] encoded as a JSON string.";
CE2JSONString::usage = "CE2JSONString[maxDepth] returns CE2JSON[maxDepth] encoded as a JSON string.";
WM148JSONString::usage = "WM148JSONString[maxDepth] returns WM148JSON[maxDepth] encoded as a JSON string.";

ExportCE1JSON::usage = "ExportCE1JSON[path, maxDepth] writes CE1JSON[maxDepth] to `path` as JSON.";
ExportCE2JSON::usage = "ExportCE2JSON[path, maxDepth] writes CE2JSON[maxDepth] to `path` as JSON.";
ExportWM148JSON::usage = "ExportWM148JSON[path, maxDepth] writes WM148JSON[maxDepth] to `path` as JSON.";

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
(* Minimal JSON encoder       *)
(* ------------------------- *)

JsonEscapeString[s_String] := StringReplace[s, {
  "\\" -> "\\\\",
  "\"" -> "\\\"",
  "\b" -> "\\b",
  "\f" -> "\\f",
  "\n" -> "\\n",
  "\r" -> "\\r",
  "\t" -> "\\t"
}];

ToJSONString[x_String] := "\"" <> JsonEscapeString[x] <> "\"";
ToJSONString[True] := "true";
ToJSONString[False] := "false";
ToJSONString[Null] := "null";
ToJSONString[x_?NumericQ] := ToString[x, InputForm];
ToJSONString[x_List] := "[" <> StringRiffle[ToJSONString /@ x, ","] <> "]";
ToJSONString[x_Association] := Module[{ks, pairs},
  ks = Keys[x];
  pairs = (ToJSONString[#] <> ":" <> ToJSONString[x[#]] &) /@ ks;
  "{" <> StringRiffle[pairs, ","] <> "}"
];
ToJSONString[x_] := ToJSONString[ToString[x, InputForm]];

(* ------------------------- *)
(* Multiset primitives        *)
(* ------------------------- *)

TallyLookupCount[tally_List, e_] := Module[{pos},
  pos = FirstPosition[tally[[All, 1]], e, Missing["NotFound"]];
  If[pos === Missing["NotFound"], 0, tally[[pos[[1]], 2]]]
];

MultisetLeqQ[a_List, b_List] := Module[{ta, tb},
  ta = Tally[a];
  tb = Tally[b];
  And @@ ((TallyLookupCount[tb, #[[1]]] >= #[[2]]) & /@ ta)
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

HGraphCountsVector[g_List, basis_List] := Module[{t},
  t = Tally[g];
  TallyLookupCount[t, #] & /@ basis
];

(* ------------------------- *)
(* Bounded multiway builder   *)
(* ------------------------- *)

AllSigmasFin2[verts_List] := Tuples[verts, 2]; (* includes non-injective assignments *)

PairEdges[idxs_List] := Flatten[Table[{idxs[[i]], idxs[[j]]}, {i, 1, Length[idxs]}, {j, i + 1, Length[idxs]}], 1];

DeleteDuplicatesByKey[ls_List, keyf_] := Module[{seen = {}, out = {}, k},
  Do[
    k = keyf[ls[[i]]];
    If[!MemberQ[seen, k],
      AppendTo[seen, k];
      AppendTo[out, ls[[i]]];
    ],
    {i, Length[ls]}
  ];
  out
];

CountLookup[counts_List, id_Integer] := Module[{pos},
  If[counts === {}, 0,
    pos = FirstPosition[counts[[All, 1]], id, Missing["NotFound"]];
    If[pos === Missing["NotFound"], 0, counts[[pos[[1]], 2]]]
  ]
];

CountAdd[counts_List, id_Integer, delta_Integer] := Module[{pos},
  If[counts === {},
    {{id, delta}},
    pos = FirstPosition[counts[[All, 1]], id, Missing["NotFound"]];
    If[pos === Missing["NotFound"],
      Append[counts, {id, delta}],
      ReplacePart[counts, pos[[1]] -> {id, counts[[pos[[1]], 2]] + delta}]
    ]
  ]
];

BuildMultiwayJSON[sys_Association, maxDepth_Integer?NonNegative] := Module[
  {verts, basis, nodes, nodeKeys, edges, branchial, levels, pathCounts,
   currStates, currCounts, getOrAddNode, nodeIdOfState},

  verts = sys["verts"];
  basis = BasisLen1Len2[verts];

  nodes = {NormalizeHGraph[sys["init"]]};
  nodeKeys = {HGraphKey[sys["init"]]};
  edges = {};
  branchial = {};
  levels = {{0}};

  currStates = {NormalizeHGraph[sys["init"]]};
  currCounts = {{0, 1}};
  pathCounts = {{<|"id" -> 0, "count" -> 1|>}};

  nodeIdOfState = Function[{g},
    Module[{key, pos},
      key = HGraphKey[g];
      pos = FirstPosition[nodeKeys, key, Missing["NotFound"]];
      If[pos === Missing["NotFound"], Missing["NotFound"], pos[[1]] - 1]
    ]
  ];

  getOrAddNode = Function[{g},
    Module[{key, pos, id},
      key = HGraphKey[g];
      pos = FirstPosition[nodeKeys, key, Missing["NotFound"]];
      If[pos === Missing["NotFound"],
        AppendTo[nodeKeys, key];
        AppendTo[nodes, NormalizeHGraph[g]];
        id = Length[nodes] - 1;
        id,
        pos[[1]] - 1
      ]
    ]
  ];

  Do[
    Module[{nextRaw = {}, nextCounts = {}, sigmas = AllSigmasFin2[verts]},
      Do[
        Module[{s = currStates[[k]], srcId, srcCount, childIds = {}},
          srcId = nodeIdOfState[s];
          srcCount = CountLookup[currCounts, srcId];
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
                  nextCounts = CountAdd[nextCounts, dstId, srcCount];
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
        nextStates = DeleteDuplicatesByKey[nextRaw, HGraphKey];
        nextLevelIds = nodeIdOfState /@ nextStates;
        levels = Append[levels, nextLevelIds];

        nextLevelCounts = (<|"id" -> #, "count" -> CountLookup[nextCounts, #]|> &) /@ nextLevelIds;
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

HeytingLeanWolframBridge`CE1JSON[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`BuildMultiwayJSON[HeytingLeanWolframBridge`CE1System, maxDepth];
HeytingLeanWolframBridge`CE1JSON[] := HeytingLeanWolframBridge`CE1JSON[3];

HeytingLeanWolframBridge`CE2JSON[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`BuildMultiwayJSON[HeytingLeanWolframBridge`CE2System, maxDepth];
HeytingLeanWolframBridge`CE2JSON[] := HeytingLeanWolframBridge`CE2JSON[2];

HeytingLeanWolframBridge`CE1JSONString[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`ToJSONString[HeytingLeanWolframBridge`CE1JSON[maxDepth]];
HeytingLeanWolframBridge`CE1JSONString[] := HeytingLeanWolframBridge`CE1JSONString[3];

HeytingLeanWolframBridge`CE2JSONString[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`ToJSONString[HeytingLeanWolframBridge`CE2JSON[maxDepth]];
HeytingLeanWolframBridge`CE2JSONString[] := HeytingLeanWolframBridge`CE2JSONString[2];

ExportCE1JSON[path_String, maxDepth_Integer] /; maxDepth >= 0 := Export[path, CE1JSON[maxDepth], "JSON"];
ExportCE1JSON[path_String] := ExportCE1JSON[path, 3];

ExportCE2JSON[path_String, maxDepth_Integer] /; maxDepth >= 0 := Export[path, CE2JSON[maxDepth], "JSON"];
ExportCE2JSON[path_String] := ExportCE2JSON[path, 2];

(* ------------------------- *)
(* WM148 (fresh-vertex)       *)
(* ------------------------- *)

WM148System = <|
  "init" -> {{0, 0}}
|>;

MaxVertexOfState[state_List] := Module[{flat = Flatten[state]},
  If[flat === {}, 0, Max[flat]]
];

HeytingLeanWolframBridge`BuildWM148JSON[maxDepth_Integer?NonNegative] := Module[
  {nodes, nodeKeys, edges, levels, currStates, nodeIdOfState, getOrAddNode, init,
   maxVertex, verts, basis},

  init = NormalizeHGraph[WM148System["init"]];

  nodes = {init};
  nodeKeys = {HGraphKey[init]};
  edges = {};
  levels = {{0}};
  currStates = {init};

  nodeIdOfState = Function[{g},
    Module[{key, pos},
      key = HGraphKey[g];
      pos = FirstPosition[nodeKeys, key, Missing["NotFound"]];
      If[pos === Missing["NotFound"], Missing["NotFound"], pos[[1]] - 1]
    ]
  ];

  getOrAddNode = Function[{g},
    Module[{key, pos, id},
      key = HGraphKey[g];
      pos = FirstPosition[nodeKeys, key, Missing["NotFound"]];
      If[pos === Missing["NotFound"],
        AppendTo[nodeKeys, key];
        AppendTo[nodes, NormalizeHGraph[g]];
        id = Length[nodes] - 1;
        id,
        pos[[1]] - 1
      ]
    ]
  ];

  Do[
    Module[{nextRaw = {}},
      Do[
        Module[{s = currStates[[k]], srcId, maxV, vals},
          srcId = nodeIdOfState[s];
          maxV = MaxVertexOfState[s];
          vals = Range[0, maxV];
          Do[
            Module[{a = vals[[ia]], b = vals[[ib]], lhsEdge, z, t, dstId},
              lhsEdge = {a, b};
              If[MemberQ[s, lhsEdge],
                z = maxV + 1;
                t = NormalizeHGraph@Join[s, {{b, z}}];
                dstId = getOrAddNode[t];
                AppendTo[edges, <|
                  "src" -> srcId,
                  "dst" -> dstId,
                  "label" -> <|"ruleIdx" -> 0, "sigma" -> {a, b}|>
                |>];
                AppendTo[nextRaw, t],
                Null
              ]
            ],
            {ia, Length[vals]}, {ib, Length[vals]}
          ];
        ],
        {k, Length[currStates]}
      ];

      Module[{nextStates, nextLevelIds},
        nextStates = DeleteDuplicatesByKey[nextRaw, HGraphKey];
        nextLevelIds = nodeIdOfState /@ nextStates;
        levels = Append[levels, nextLevelIds];
        currStates = nextStates;
      ];
    ],
    {maxDepth}
  ];

  maxVertex = If[nodes === {}, 0, Max[MaxVertexOfState /@ nodes]];
  verts = Range[0, maxVertex];
  basis = BasisLen1Len2[verts];

  <|
    "system" -> "wm148",
    "maxDepth" -> maxDepth,
    "maxVertex" -> maxVertex,
    "basis_len1_len2" -> basis,
    "nodes" -> (HGraphCountsVector[#, basis] & /@ nodes),
    "edges" -> edges,
    "levels" -> levels
  |>
];

HeytingLeanWolframBridge`WM148JSON[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`BuildWM148JSON[maxDepth];
HeytingLeanWolframBridge`WM148JSON[] := HeytingLeanWolframBridge`WM148JSON[3];

HeytingLeanWolframBridge`WM148JSONString[maxDepth_Integer] /; maxDepth >= 0 :=
  HeytingLeanWolframBridge`ToJSONString[HeytingLeanWolframBridge`WM148JSON[maxDepth]];
HeytingLeanWolframBridge`WM148JSONString[] := HeytingLeanWolframBridge`WM148JSONString[3];

ExportWM148JSON[path_String, maxDepth_Integer] /; maxDepth >= 0 := Export[path, WM148JSON[maxDepth], "JSON"];
ExportWM148JSON[path_String] := ExportWM148JSON[path, 3];

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
