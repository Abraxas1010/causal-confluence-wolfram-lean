# Wolfram Project — Audit & Outstanding Work (Living Checklist)

**Date:** 2025-12-26  
**Scope:** `lean/HeytingLean/WPP/Wolfram/*` (+ bridges to the generic WPP multiway nucleus)

This file is the working checklist for “buttoning up” the Wolfram project to a
researcher-grade package (formal + reproducible), with **no `sorry`/axioms/stubs**
in the Lean proof tree.

---

## Current Status (already implemented)

✅ Implemented and proof-complete (workspace Lean sources have no proof escapes):

- `lean/HeytingLean/WPP/Multiway.lean`
  - `JR` forward-invariance kernel (contractive, idempotent, meet-preserving)
  - inflationary `reachabilityNucleus` packaging (LoF convention)
- `lean/HeytingLean/WPP/Wolfram/Hypergraph.lean`
  - SetReplace-faithful states: `Expr V := List V`, `HGraph V := Multiset (Expr V)`
  - vertex-renaming + `HGraph.Iso`
- `lean/HeytingLean/WPP/Wolfram/Rewrite.lean`
  - rule instantiation by injective substitution
  - **multi-rule** systems (SetReplace-style): `System.rules : List (Rule P)`
  - singleway evolutions + normal forms
- `lean/HeytingLean/WPP/Wolfram/CausalGraph.lean`
  - SetReplace causal graph (unlabeled edges): “created then destroyed”
- `lean/HeytingLean/WPP/Wolfram/CausalGraphLabeled.lean`
  - multiplicity-aware causal graph (`output ∩ input` labels) + forgetful map back to `CausalGraph`
- `lean/HeytingLean/WPP/Wolfram/Multiway.lean`
  - finite enumerators for substitutions / event-data (finite `P`/`V`)
  - multiway step edges + multiway reachable sets at depth
  - ordering/scheduler API + bridge to `HeytingLean.WPP.Multiway.WppRule`
- `lean/HeytingLean/WPP/Wolfram/MultiwayBridge.lean`
  - proof-level bridge: `t ∈ stepStates s ↔ System.Step s t`
  - `WppRule.StepStar (sys.toWppRule) ↔ System.StepStar`
- `lean/HeytingLean/WPP/Wolfram/Branchial.lean`
  - branchial edges at depth (siblings share a predecessor)
  - bounded event-data path enumeration + `pathCountAtDepth`
- `lean/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
  - relation-theoretic layer: `Step`, `StepStar`, Church–Rosser predicates
  - bounded-termination predicate `TerminatingFrom`
- `lean/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
  - terminating notions:
    - `Properties.ConfluentNF` (unique normal form up to `HGraph.Iso`)
    - `Properties.CausalInvariant` (causal graphs of normal-form evolutions are iso)
  - Piskunov bulletin counterexamples:
    - CE1: confluent but not causally invariant
    - CE2: causally invariant but not confluent
  - independence theorem
  - `Counterexamples.CE1.terminatingFrom_init`, `Counterexamples.CE2.terminatingFrom_init`
- `lean/HeytingLean/CLI/WolframMultiwayMain.lean`
  - executable demo: bounded multiway + branchial (CE1/CE2), emits JSON

✅ Guard/build/QA checks (local; strict per `AGENTS.md`):

- `./scripts/guard_no_sorry.sh`
- `cd lean && lake build -- -DwarningAsError=true`
- `./scripts/build_all_exes.sh --strict`
- `./scripts/run_all_exes.sh`
- `./scripts/qa_robustness_all.sh`
- `./scripts/qa_portability.sh`
- Researcher bundle: `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/scripts/verify_wolfram.sh`

---

## Audit Findings (repo-visible gaps)

### A. Hard blockers / hygiene

- No `TODO`/`FIXME`/`STUB` markers in `lean/HeytingLean/WPP/Wolfram/`.
- No `sorry`/`admit` in `lean/HeytingLean/WPP/Wolfram/`.
- No unnecessary `classical` usage in CE2 proof case split (removed).

### B. Conceptual scope gaps (real “future work”)

All items required for a “complete package” of the terminating-independence result are landed.

Optional follow-ons (now implemented):

1. **Beyond finiteness**: `HeytingLean.WPP.MultiwayRel` and the Wolfram adapter
   `HeytingLean.WPP.Wolfram.MultiwayRel` expose `System.Step` as a relation-based multiway rule
   (no bounded enumerator required).
2. **Richer visuals**: offline HTML viewer and GraphViz exports are shipped in `Wolfram_PaperPack`
   and mirrored into the self-contained `RESEARCHER_BUNDLE`.

### C. Documentation debt (not a Lean blocker)

- `WIP/wolfram_combinators.md` has been rewritten as a clean entrypoint pointing to the
  implemented modules and the paper pack (no draft `sorry` code remains).

---

## Execution Plan (will be checked off as we go)

- [x] Refactor Wolfram core to multi-rule systems (preserve CE1/CE2 as a 1-rule instance).
- [x] Add multiway semantics + strategy/ordering API + bounded enumerator for finite systems.
- [x] Add confluence theory: Church–Rosser layer + termination predicate.
- [x] Add labeled/multiplicity-aware causal graphs + forgetful map.
- [x] Add branchial graphs + path counting (bounded depth).
- [x] Deepen WPP nucleus + SKY multiway lens bridge.
- [x] Produce `Wolfram_PaperPack` researcher bundle + verification scripts + generated artifacts.
