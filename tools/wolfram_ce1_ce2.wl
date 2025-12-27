(* ::Package:: *)
(* Convenience loader (root-level) for the self-contained bundle WL script. *)

Module[{baseDir, target},
  baseDir = If[$InputFileName =!= "", DirectoryName[$InputFileName], NotebookDirectory[]];
  target = FileNameJoin[{baseDir, "..", "RESEARCHER_BUNDLE", "tools", "wolfram_ce1_ce2.wl"}];
  If[FileExistsQ[target],
    Get[target],
    Print["E: could not find bundle WL script at: ", target]
  ];
];

