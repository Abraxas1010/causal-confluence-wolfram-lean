# Wolfram / SetReplace Formalization — Technical Report (Self-Contained Bundle)

**Date:** 2025-12-26  
**Bundle root:** this folder (`WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/`)

This document summarizes what is included in the Wolfram researcher bundle and how it relates
to the mathematical goals (SetReplace-faithful rewriting, confluence vs causal invariance,
multiway/branchial structure).

---

## 1. What this bundle contains

### Lean sources (subset of HeytingLean)

- `HeytingLean/WPP/Wolfram/*`
  - SetReplace-faithful hypergraph rewriting (`Rewrite.lean`)
  - causal graphs (`CausalGraph.lean`, `CausalGraphLabeled.lean`)
  - rewriting theory scaffold (`ConfluenceTheory.lean`)
  - confluence vs causal invariance (CE1/CE2 + independence) (`ConfluenceCausalInvariance.lean`)
  - finite multiway enumerator + branchial slices (`Multiway.lean`, `Branchial.lean`)
  - bridges:
    - enumerator ↔ relation (`MultiwayBridge.lean`)
    - infinite (enumeration-free) semantics (`MultiwayRel.lean`)

- `HeytingLean/WPP/Multiway.lean`
  - `WppRule` (finite multiway interface)
  - `JR` forward-invariance kernel + inflationary `reachabilityNucleus`

- `HeytingLean/WPP/MultiwayRel.lean`
  - `WppRel` (enumeration-free multiway interface)
  - `JR` kernel + inflationary `reachabilityNucleus`

- `HeytingLean/CLI/WolframMultiwayMain.lean`
  - `wolfram_multiway_demo` executable emitting JSON for bounded CE1/CE2 exploration

### Verification script

- `scripts/verify_wolfram.sh`
  - pins deps via `lake update`
  - strict builds (`-Dno sorry -DwarningAsError=true`)
  - runs `wolfram_multiway_demo`
  - greps for forbidden markers (`axiom`/`sorry`/`admit`)
  - collects compiler IR + `.olean` outputs
  - produces `sha256sum` over the bundle
  - optionally generates DOT/SVG visuals if `python3` exists

### Artifacts and visuals

- `artifacts/generated_ce1.json`, `artifacts/generated_ce2.json` (produced by the verifier)
- `artifacts/wolfram_viewer.html` (offline viewer; pan/zoom; node inspection)
- `artifacts/visuals/` (DOT + SVG graphs; multiway/branchial/combined)

---

## 2. Mathematical outline

### 2.1 Rewrite semantics (SetReplace-faithful)

- State: a multiset of vertex-lists (hyperedges).
- Rule schema: LHS/RHS hypergraphs over pattern vertices.
- Event: a rule index + injective substitution of pattern vertices into concrete ones.
- One step: replace instantiated LHS by instantiated RHS (multiset `-` / `+`).

### 2.2 Terminating confluence vs causal invariance

- `ConfluentNF`: any two reachable normal forms are isomorphic hypergraphs.
- `CausalInvariant`: any two singleway evolutions to normal forms yield isomorphic causal graphs.

Counterexamples:

- CE1: confluentNF but not causalInvariant.
- CE2: causalInvariant but not confluentNF.
- Therefore: independence of the properties.

### 2.3 Multiway/branchial

- For finite `P` and `V`, bounded multiway exploration is implemented using `Finset` enumerators.
- Branchial edges are computed between sibling states (children of the same parent).
- A bounded path-counting function is provided.

### 2.4 Beyond finiteness: relation-based multiway interface

- `WppRel` models multiway dynamics without enumerating successors.
- Any Wolfram system induces a `WppRel` via the one-step rewrite relation `System.Step`.

---

## 3. How to verify (one command)

From this folder:

1. `./scripts/verify_wolfram.sh`

Look at:

- `reports/BUILD_TRANSCRIPT_STRICT.txt`
- `reports/GREP_AXIOM_SORRY_ADMIT.txt`
- `reports/SHA256SUMS.txt`

---

## 4. How to view the graphs

- Open `artifacts/wolfram_viewer.html`
- Load either:
  - `artifacts/generated_ce1.json` / `artifacts/generated_ce2.json` (after verification), or
  - the included samples `artifacts/ce1_multiway_depth3.json` / `artifacts/ce2_multiway_depth2.json`.

DOT/SVG generation:

- `python3 scripts/wolfram_json_to_dot.py <json> artifacts/visuals/<prefix> --render-svg`

