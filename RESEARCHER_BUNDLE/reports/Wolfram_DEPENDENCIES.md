# Wolfram Project — Dependencies

## Toolchain pin

- `lean-toolchain` (repo root) pins the Lean version used for this project.

## Libraries

This Wolfram project uses:

- Mathlib:
  - `Mathlib.Data.Multiset.*` for SetReplace-faithful multisets of expressions
  - `Mathlib.Logic.Relation` for Church–Rosser / joinability lemmas
  - `Mathlib.Data.Fin.Basic` + `Mathlib.Data.Finset.*` for bounded finite enumerators
  - `Mathlib.Order.Nucleus` for LoF-style (inflationary) nucleus packaging on `Set`

## Internal dependencies

- `HeytingLean.WPP.Multiway` (nucleus interface; Wolfram → `WppRule` bridge)
- `HeytingLean.WPP.Wolfram.MultiwayBridge` (Step/StepStar equivalences for `toWppRule`)
- `HeytingLean.WPP.MultiwayRel` (enumeration-free multiway interface)
- `HeytingLean.WPP.Wolfram.MultiwayRel` (Wolfram → `WppRel` bridge via `System.Step`)
