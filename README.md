# Wolfram PaperPack (WPP / SetReplace semantics)

This folder is the reproducible, researcher-facing bundle for the Wolfram/SetReplace
formalization inside HeytingLean.

**Goal:** provide a **self-contained** and **verifiable** package (Lean proofs + artifacts)
for the Wolfram Physics (multiway) work, analogous to `WIP/ClosingTheLoop_PaperPack`.

## Index

- `wolfram_audit_outstanding.md` — living audit + remaining work checklist.
- `01_Lean_Map.md` — map from concepts to Lean namespaces/files.
- `02_Proof_Index.md` — declaration index (theorems/lemmas) for the Wolfram modules.
- `03_Reproducibility.md` — exact commands to rebuild and verify.
- `04_Dependencies.md` — Lean/Lake pin + Mathlib dependency notes.
- `05_Technical_Report.md` — full technical report of what was built and why.
- `artifacts/` — generated demo outputs (JSON) for CE1/CE2 multiway + branchial slices.
  - `artifacts/wolfram_viewer.html` — offline viewer (pan/zoom, node inspection).
  - `artifacts/visuals/` — GraphViz DOT + rendered SVGs (multiway / branchial / combined).

`RESEARCHER_BUNDLE/` is the self-contained verification bundle (pinned toolchain + scripts).
