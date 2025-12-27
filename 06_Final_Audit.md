# Final Audit — Wolfram / SetReplace Formalization (HeytingLean WPP)

**Date:** 2025-12-27  
**Source branch (HeytingLean monorepo):** `quantum_extended`  
**Source commit (baseline):** `102957ac` (“Wolfram: add WM148 causal invariance proof + demo bundle”)

## [STATUS: PASSED]

This audit is a submission-readiness check: the *Lean proof tree used for the Wolfram/SetReplace results* must contain **no** `sorry`/`admit` and must pass strict builds and executable QA per `AGENTS.md`.

### Scope Audited

1. **Main repo Lean slice** (authoritative development):
   - `lean/HeytingLean/WPP/**`
   - `lean/HeytingLean/WPP/Wolfram/**`
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

### Notes on Token-Scan “False Positives”

Documentation may mention strings like “sorry” (e.g. in flag names `-Dno sorry`) or contain `TODO` checklists.
The PaperPack verifier only fails if such markers appear in the Lean sources under `RESEARCHER_BUNDLE/HeytingLean/`.
