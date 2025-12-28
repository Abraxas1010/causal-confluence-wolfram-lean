# Final Audit — Wolfram / SetReplace Formalization (HeytingLean WPP)

**Date:** 2025-12-28  
**Authoritative source branch (HeytingLean monorepo):** `quantum_extended`

This PaperPack is mirrored into the standalone repository:

- https://github.com/Abraxas1010/causal-confluence-wolfram-lean

## [STATUS: PASSED]

This audit is a submission-readiness check: the *Lean proof tree used for the Wolfram/SetReplace results* must contain **no** `sorry`/`admit` and must pass strict builds and executable QA per `AGENTS.md`.

### Status

- [STATUS: PASSED] for standalone `main` (repo: https://github.com/Abraxas1010/causal-confluence-wolfram-lean)
- Ran `RESEARCHER_BUNDLE/scripts/verify_wolfram.sh` with strict flags (`-DwarningAsError=true -Dno sorry`), builds + runs all `lean_exe`, compiles + runs emitted C, WL cross-check via Mathics, robustness + portability; exit code `0`.

This audit includes the added observable-event (“GC”) causal graph abstraction (`CausalGraphGC`) and its CE1/CE2 lemmas (`ConfluenceCausalInvarianceGC`).

### Scope Audited

1. **Main repo Lean slice** (authoritative development):
   - `lean/HeytingLean/WPP/**`
   - `lean/HeytingLean/WPP/Wolfram/**`
   - `lean/HeytingLean/WPP/Wolfram/CausalGraphGC.lean`
   - `lean/HeytingLean/WPP/Wolfram/ConfluenceCausalInvarianceGC.lean`
   - `lean/HeytingLean/CLI/WolframMultiwayMain.lean`
   - `lean/HeytingLean/CLI/WolframWM148Main.lean`
2. **Researcher bundle (self-contained)**:
   - `RESEARCHER_BUNDLE/**`

### Strict QA (AGENTS.md) — Main Repo

All commands succeeded **with strict flags**:

1. Strict library build (no sorries, warnings-as-errors):
   - `cd lean && lake build -- -DwarningAsError=true -Dno sorry`
2. Strict executable compilation (C backend / linking exercised):
   - `./scripts/build_all_exes.sh --strict`
3. Mandatory runtime execution (happy paths + expected-failure checks):
   - `./scripts/run_all_exes.sh`
4. Robustness tests (missing files/env/PATH, expected non-zero on negative paths):
   - `./scripts/qa_robustness_all.sh`
5. Portability check (dynamic dependencies):
   - `./scripts/qa_portability.sh`

### Marker Scans (Lean sources)

The following marker scans found **no forbidden markers** in the Wolfram slice:

- `rg -n --type lean -S "\\b(sorry|admit|TODO|FIXME|STUB|PLACEHOLDER)\\b" lean/HeytingLean/WPP`
- `rg -n --type lean -S "^\\s*axiom\\s" lean/HeytingLean/WPP`
- `rg -n --type lean -S "^\\s*constant\\s+[A-Za-z0-9_']+\\s*:" lean/HeytingLean/WPP`

Repo-wide, `./scripts/guard_no_sorry.sh` also passed (fast guard).

### Researcher Bundle Verification (Self-contained)

The bundle verifier passed end-to-end:

- `RESEARCHER_BUNDLE/scripts/verify_wolfram.sh`

It performs:

- `lake update` in the bundle
- strict builds under `-DwarningAsError=true -Dno sorry`
- runs `wolfram_multiway_demo` for both CE1 and CE2
- runs `wolfram_wm148_demo` (WM148 bounded multiway; fresh-vertex semantics)
- runs `wolfram_bundle_demo` and compiles the emitted C artifact
- greps bundle Lean sources for `axiom|sorry|admit`
- collects `.olean` and compiler IR artifacts
- produces `reports/SHA256SUMS.txt`

Artifacts and transcripts are under:

- `RESEARCHER_BUNDLE/reports/`
- `RESEARCHER_BUNDLE/artifacts/`

### Kernel Footprint (“Axioms Print”)

To make the proof foundations explicit for reviewers, the bundle now also records `#print axioms` for the key theorems.

- Input file:
  - `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/AxiomsAudit.lean`
- Output:
  - `RESEARCHER_BUNDLE/reports/AXIOMS_PRINT.txt`

The key theorems depend only on the standard Lean kernel axioms:

- `propext`
- `Classical.choice`
- `Quot.sound`

No project-specific axioms were introduced.

## Formal Foundations

- No proof escapes in the audited Lean sources: no `sorry`/`admit`/`axiom`/`constant` under `RESEARCHER_BUNDLE/HeytingLean/**`
  (confirmed by the verifier’s grep + strict build).
- Kernel footprint of the headline results is “mathlib-standard only”: `propext`, `Classical.choice`, `Quot.sound`
  (see `RESEARCHER_BUNDLE/reports/AXIOMS_PRINT.txt`).

## Main Formalism Concerns (Not Failures)

- There are three “causal invariance” notions in play:
  - causal-graph invariance for normal-form evolutions (`HeytingLean.WPP.Wolfram.Properties.CausalInvariant`), and
  - observable-event (“GC”) causal-graph invariance for normal-form evolutions (`HeytingLean.WPP.Wolfram.Properties.GCausalInvariant`), and
  - branch-pair resolution up to iso for fresh-vertex semantics (`HeytingLean.WPP.Wolfram.SystemFresh.CausalInvariant`).
  The README is careful; `TECHNICAL_REPORT_FULL.md` now contains an explicit “three notions” paragraph to preempt reviewer confusion.
- `ConfluentNF` / `Properties.CausalInvariant` are phrased via “reachable normal forms” and can be vacuous for non-terminating systems.
  CE1/CE2 are terminating and explicitly exhibit reachable normal forms (see e.g. `Counterexamples.CE1.terminatingFrom_init` and
  `Counterexamples.CE2.terminatingFrom_init`), but we now state this explicitly where the properties are introduced in `TECHNICAL_REPORT_FULL.md`.

## Optional “Perfection” Upgrades

- Minimize `Classical.choice`: isolate any avoidable classical choice in the Wolfram slice and re-run `#print axioms` to check whether it drops out.
  Note: `System.Event.apply` is defined using `Multiset.sub` (SetReplace-faithful multiset subtraction), and Mathlib’s `Multiset.sub`
  currently depends on `Classical.choice` via the `List.diff` permutation coherence used to lift subtraction to quotient-multisets.
- Add a bridge result (or clearly-marked future work) relating branch-pair resolution (`SystemFresh.CausalInvariant`) to normal-form
  causal-graph invariance (`Properties.CausalInvariant`) and/or the coarse-grained observable-event notion (`Properties.GCausalInvariant`)
  under explicit termination hypotheses, so WM148 and CE1/CE2 sit under one unified formal narrative.

### Notes on Token-Scan “False Positives”

Documentation may mention strings like “sorry” (e.g. in flag names `-Dno sorry`) or contain `TODO` checklists.
The PaperPack verifier only fails if such markers appear in the Lean sources under `RESEARCHER_BUNDLE/HeytingLean/`.
