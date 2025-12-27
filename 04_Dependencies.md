# Dependencies / pins

This repo is a Lean 4 + mathlib project built with Lake.

## Lean toolchain

- `lean-toolchain` (repo root) pins the Lean version.
- The RESEARCHER_BUNDLE ships its own `lean-toolchain` for independent verification.

## mathlib

- Pinned in `lean/lakefile.lean`.
- Concrete commit recorded in `lake-manifest.json`.

## Wolfram-specific Mathlib imports

The Wolfram formalization uses:

- `Mathlib.Data.Multiset.*` — SetReplace-faithful multisets of expressions
- `Mathlib.Logic.Relation` — Church–Rosser / joinability / reflexive-transitive closure
- `Mathlib.Data.Fin.Basic` + `Mathlib.Data.Finset.*` — bounded finite enumerators
- `Mathlib.Order.Nucleus` — LoF-style (inflationary) nucleus packaging on `Set`

## Internal dependencies (HeytingLean modules)

The Wolfram formalization depends on:

- `HeytingLean.WPP.Multiway` — nucleus interface; Wolfram → `WppRule` bridge
- `HeytingLean.WPP.MultiwayRel` — enumeration-free multiway interface
- `HeytingLean.WPP.Wolfram.MultiwayBridge` — Step/StepStar equivalences for `toWppRule`
- `HeytingLean.WPP.Wolfram.MultiwayRel` — Wolfram → `WppRel` bridge via `System.Step`

## Researcher bundle pins

The standalone verifier bundle under `RESEARCHER_BUNDLE/` ships its own:

- `RESEARCHER_BUNDLE/lean-toolchain`
- `RESEARCHER_BUNDLE/lakefile.lean`
- `RESEARCHER_BUNDLE/lake-manifest.json`

Notable packages (non-exhaustive):
- `Cli` — command-line argument parsing for demos
- `batteries` — extended standard library
- `aesop` — automation tactics
- `proofwidgets` — interactive proof widgets
- `importGraph` — dependency visualization

## Other Lake packages

The complete dependency set is recorded in:

- `lean/lake-manifest.json` (main repo)
- `RESEARCHER_BUNDLE/lake-manifest.json` (bundle)

## OS/runtime tools used by QA scripts (non-Lean)

The local QA loop (see `03_Reproducibility.md`) may call:

- `bash`
- `python3`
- `cc` (C compiler) and system linker
- `jq` (optional, for JSON processing)
- `ldd` (optional, for portability checks)
- `graphviz` (`dot`) (optional, for SVG generation)
