# Wolfram Project — Audit & Outstanding Work (Living Checklist)

**Date:** 2025-12-28  
**Scope:** `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/*` (+ bridges to the generic WPP multiway nucleus)

This file is the working checklist for “buttoning up” the Wolfram project to a
researcher-grade package (formal + reproducible), with **no `sorry`/axioms/stubs**
in the Lean proof tree.

---

## Current Status (already implemented)

✅ Implemented and proof-complete (workspace Lean sources have no proof escapes):

- `RESEARCHER_BUNDLE/HeytingLean/WPP/Multiway.lean`
  - `JR` forward-invariance kernel (contractive, idempotent, meet-preserving)
  - inflationary `reachabilityNucleus` packaging (LoF convention)
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Hypergraph.lean`
  - SetReplace-faithful states: `Expr V := List V`, `HGraph V := Multiset (Expr V)`
  - vertex-renaming + `HGraph.Iso`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Rewrite.lean`
  - rule instantiation by substitution `σ : P → V` (**not assumed injective**; SetReplace permits non-injective matches)
  - **multi-rule** systems (SetReplace-style): `System.rules : List (Rule P)`
  - singleway evolutions + normal forms
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/FreshSupply.lean`
  - explicit fresh-vertex supply interface (`FreshSupply V`) for rules that allocate new vertices
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/RewriteFresh.lean`
  - rewrite semantics with fresh vertices + α-equivalence up to renaming
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/SimpleHypergraph.lean`
  - injective-WLOG lemma under a “simple edges” invariant
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraph.lean`
  - SetReplace causal graph (unlabeled edges): “created then destroyed”
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraphGC.lean`
  - observable-event (“GC”) causal graph abstraction: keep only events whose created expressions survive in the endpoint
  - used to coarse-grain away detours like CE1’s extra step, without changing endpoint normal forms
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraphLabeled.lean`
  - multiplicity-aware causal graph (`output ∩ input` labels) + forgetful map back to `CausalGraph`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Multiway.lean`
  - finite enumerators for substitutions / event-data (finite `P`/`V`)
  - multiway step edges + multiway reachable sets at depth
  - ordering/scheduler API + bridge to `HeytingLean.WPP.Multiway.WppRule`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/MultiwayBridge.lean`
  - proof-level bridge: `t ∈ stepStates s ↔ System.Step s t`
  - `WppRule.StepStar (sys.toWppRule) ↔ System.StepStar`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Branchial.lean`
  - branchial edges at depth (siblings share a predecessor)
  - bounded event-data path enumeration + `pathCountAtDepth`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
  - relation-theoretic layer: `Step`, `StepStar`, Church–Rosser predicates
  - bounded-termination predicate `TerminatingFrom`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
  - terminating notions:
    - `Properties.ConfluentNF` (unique normal form up to `HGraph.Iso`)
    - `Properties.CausalInvariant` (causal graphs of normal-form evolutions are iso)
  - Piskunov bulletin counterexamples:
    - CE1: confluent but not causally invariant
    - CE2: causally invariant but not confluent
  - independence theorem
  - `Counterexamples.CE1.terminatingFrom_init`, `Counterexamples.CE2.terminatingFrom_init`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvarianceGC.lean`
  - CE1/CE2 theorems for the observable-event (“GC”) causal-graph notion:
    - `CE1.causalGraphGC_iso_short_long` (the CE1 “detour” disappears under GC causal graphs)
    - `CE2.causalInvariantGC : Properties.GCausalInvariant (sys := CE2.sys)`
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalInvarianceSingleLHS.lean`
  - causal invariance as branch-pair resolution (fresh-vertex semantics)
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/WM148.lean`
  - WM148 system definition (`{{x,y}} → {{x,y},{y,z}}`) with explicit fresh vertices
- `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/WM148CausalInvariant.lean`
  - proof: `WM148.causalInvariant : SystemFresh.CausalInvariant (sys := WM148.sys)`
- `RESEARCHER_BUNDLE/HeytingLean/CLI/WolframMultiwayMain.lean`
  - executable demo: bounded multiway + branchial (CE1/CE2), emits JSON
- `RESEARCHER_BUNDLE/HeytingLean/CLI/WolframWM148Main.lean`
  - executable demo: bounded multiway exploration for WM148, emits JSON

✅ Guard/build/QA checks (local; strict per `AGENTS.md`):

- PaperPack verifier (strict, builds+runs demos, robustness checks, `ldd`, reproducible hashes):
  - `cd RESEARCHER_BUNDLE && ./scripts/verify_wolfram.sh`

---

## Audit Findings (repo-visible gaps)

### A. Hard blockers / hygiene

- No `TODO`/`FIXME`/`STUB` markers in `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/`.
- No `sorry`/`admit` in `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/`.
- No unnecessary `classical` usage in CE2 proof case split (removed).

### B. Conceptual scope gaps (real “future work”)

All items required for a “complete package” of the terminating-independence result are landed.

Optional follow-ons (implemented):

1. **Beyond finiteness**: `HeytingLean.WPP.MultiwayRel` and the Wolfram adapter
   `HeytingLean.WPP.Wolfram.MultiwayRel` expose `System.Step` as a relation-based multiway rule
   (no bounded enumerator required).
2. **Richer visuals**: offline HTML viewer and GraphViz exports are shipped in `Wolfram_PaperPack`
   and mirrored into the self-contained `RESEARCHER_BUNDLE`.
3. **Wolfram Language cross-check**: `RESEARCHER_BUNDLE/tools/wolfram_ce1_ce2.wl` reproduces the CE1/CE2 bounded multiway JSON
   format in pure Wolfram Language, and a small WM148 bounded multiway JSON used to cross-check the fresh-vertex semantics
   (no Lean required), enabling a side-by-side comparison in Wolfram tooling.
4. **Causal-graph meaning refinement (bridge abstraction)**: `CausalGraphGC` provides an observable-event (“garbage-collected”)
   causal graph notion that is stable under “detour steps” whose created expressions do not survive to the endpoint.
   This addresses the conceptual mismatch between SetReplace-style causal graphs and the WPP branch-pair-resolution semantics.

Remaining future work (optional “perfection” upgrades):

- **Bridge the invariance notions under hypotheses**: relate branch-pair resolution (`SystemFresh.CausalInvariant`) to normal-form
  causal-graph invariance (`Properties.CausalInvariant`) and/or the observable-event notion (`Properties.GCausalInvariant`) under explicit
  termination + compatibility hypotheses, so WM148 and CE1/CE2 sit under one unified formal narrative.
- **Minimize classical choice**: attempt to eliminate avoidable `Classical.choice` dependencies in the Wolfram slice and re-run `#print axioms`.
  Note: Mathlib’s `Multiset.sub` currently pulls in classical choice; if we require SetReplace-faithful multiset subtraction, this may be irreducible.

### C. Documentation debt (not a Lean blocker)

- PaperPack docs are consolidated under `0[1-6]_*.md` and `TECHNICAL_REPORT_FULL.md`.

---

## Execution Plan (will be checked off as we go)

- [x] Refactor Wolfram core to multi-rule systems (preserve CE1/CE2 as a 1-rule instance).
- [x] Add multiway semantics + strategy/ordering API + bounded enumerator for finite systems.
- [x] Add confluence theory: Church–Rosser layer + termination predicate.
- [x] Add labeled/multiplicity-aware causal graphs + forgetful map.
- [x] Add observable-event (“GC”) causal graphs (coarse-graining) + CE1/CE2 lemmas.
- [x] Add branchial graphs + path counting (bounded depth).
- [x] Deepen WPP nucleus + SKY multiway lens bridge.
- [x] Produce `Wolfram_PaperPack` researcher bundle + verification scripts + generated artifacts.
