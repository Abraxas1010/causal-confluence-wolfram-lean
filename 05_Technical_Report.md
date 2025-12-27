# Wolfram / SetReplace Formalization — Technical Report (HeytingLean WPP)

**Date:** 2025-12-26  
**Primary scope:** `lean/HeytingLean/WPP/Wolfram/*` (+ WPP multiway interfaces and demos)  
**Deliverable:** a researcher-grade, locally verifiable package with strict QA: no `sorry`/`admit`/axioms/stubs in the Lean proof tree, executable builds, runtime execution, robustness checks, and portability checks.

This report is written to be readable by a category-/rewriting-/Wolfram-physics audience, while remaining faithful to the actual Lean artifacts in this repository.

---

## 1. Project Objectives and Constraints

### Objectives

1. **SetReplace-faithful rewrite semantics** for Wolfram-like systems, including multi-rule systems.
2. **Formalize terminating notions** of:
   - confluence-as-unique-normal-form (up to vertex renaming), and
   - causal invariance (up to causal-graph isomorphism),
   and prove **independence** via explicit counterexamples.
3. Provide **multiway semantics** (bounded, finite enumerator) and **branchial graph** slices as computable objects.
4. Provide **bridges** to HeytingLean’s generic multiway interfaces:
   - finite (`Finset`) interface, and
   - enumeration-free (`Prop`-level) interface, for infinite state spaces.
5. Ship a **researcher bundle** (`WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE`) with pinned toolchain + scripts + artifacts.
6. Provide **offline visuals** suitable for sharing and inspection without installing the full repo.

### QA/Process Constraints (from `AGENTS.md`)

The completion is required to satisfy local QA expectations:

- strict build with `-DwarningAsError=true` (treats proof holes as errors)
- build all `lean_exe` targets (C backend + linking)
- run executables on happy path
- robustness checks (missing files/env vars/PATH)
- portability checks (dynamic deps via `ldd`)

No CI/CD configuration was added or changed.

---

## 2. Mathematical and Lean Architecture

### 2.1 States, rules, and events (SetReplace-faithful)

**State model**:

- Expressions are vertex lists: `Expr V := List V`.
- Hypergraph states are multisets of expressions: `HGraph V := Multiset (Expr V)`.

**Rules and systems**:

- A rule schema `Rule P` has `lhs : HGraph P` and `rhs : HGraph P`.
- A system `System V P` has `rules : List (Rule P)` and an initial state `init : HGraph V`.

**Events**:

- An event chooses:
  - a rule index `idx : Fin sys.rules.length`, and
  - an injective substitution `σ : P → V` with proof `inj : Function.Injective σ`.

Applicability and execution:

- `Applicable`: instantiated LHS is a submultiset of the current state.
- `apply`: replace instantiated LHS by instantiated RHS via multiset subtraction/addition.

Key Lean modules:

- `HeytingLean.WPP.Wolfram.Hypergraph`
- `HeytingLean.WPP.Wolfram.Rewrite`

### 2.2 Causal graphs (SetReplace-style) + multiplicity-aware refinement

Two notions are formalized:

1. **Unlabeled causal graph**: an edge `e₁ → e₂` exists if some expression is created by `e₁` and destroyed by `e₂`.
2. **Labeled/multiplicity-aware causal graph**: edges are labeled by the multiset intersection `output ∩ input`, then a forgetful map recovers the unlabeled graph.

Key Lean modules:

- `HeytingLean.WPP.Wolfram.CausalGraph`
- `HeytingLean.WPP.Wolfram.CausalGraphLabeled`

### 2.3 Confluence theory layer (relation-theoretic scaffold)

To keep the “semantic” Wolfram layer stable while enabling standard rewriting arguments, a relation-theoretic interface is added:

- `System.Step` (one-step relation): “there exists an applicable event whose application yields the next state”.
- `System.StepStar`: reflexive–transitive closure (`Relation.ReflTransGen`).
- Church–Rosser style predicates (`Joinable`, `Confluent`, `SemiConfluent`).
- A uniform bounded termination predicate from an initial state (`TerminatingFrom`).

Key Lean module:

- `HeytingLean.WPP.Wolfram.ConfluenceTheory`

### 2.4 Terminating confluence vs terminating causal invariance (independence result)

We formalize the terminating versions used in the Wolfram Physics / SetReplace discussion:

- `Properties.ConfluentNF`:
  any two **reachable normal forms** are hypergraph-isomorphic (vertex relabeling).
- `Properties.CausalInvariant`:
  any two **singleway evolutions** reaching normal forms have isomorphic causal graphs.

Then two explicit SetReplace-style counterexamples are implemented:

- **CE1**: confluentNF but not causalInvariant.
- **CE2**: causalInvariant but not confluentNF.

And finally:

- `Counterexamples.confluence_causal_invariance_independent`:
  the two properties are independent (neither implies the other).

Key Lean module:

- `HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance`

### 2.5 Multiway semantics (finite enumerator) + branchial graph slices

For finite vertex/pattern types (`Fintype`), we build a finite enumerator:

- enumerate substitutions and event-data,
- compute outgoing multiway edges and reachable states by depth,
- compute branchial edges (“siblings share a predecessor”),
- compute bounded path counts.

Key Lean modules:

- `HeytingLean.WPP.Wolfram.Multiway`
- `HeytingLean.WPP.Wolfram.Branchial`

### 2.6 Bridges to generic multiway interfaces (finite and infinite)

**Finite interface (enumerator-based)**:

- Generic interface `WppRule` (one-step successors as `Finset`).
- Wolfram finite systems instantiate `WppRule` via `System.toWppRule`.

Proof-level bridge:

- `t ∈ sys.stepStates s ↔ System.Step s t`
- `WppRule.StepStar (sys.toWppRule) s t ↔ System.StepStar s t`

Key Lean module:

- `HeytingLean.WPP.Wolfram.MultiwayBridge`

**Infinite interface (enumeration-free)**:

- Generic interface `WppRel` (one-step successors as a relation `State → State → Prop`).
- Wolfram systems instantiate `WppRel` via the one-step rewrite relation `System.Step`.

Key Lean modules:

- `HeytingLean.WPP.MultiwayRel`
- `HeytingLean.WPP.Wolfram.MultiwayRel`

---

## 3. Executables and Concrete Artifacts

### 3.1 Executable: `wolfram_multiway_demo`

Lean entry point:

- `HeytingLean.CLI.WolframMultiwayMain`

This executable:

- runs bounded multiway exploration for CE1 (default) or CE2,
- outputs JSON containing:
  - node states (as counts over a fixed finite basis of expressions of length 1–2),
  - multiway edges (labeled by rule index and σ),
  - levels (by depth),
  - branchial edges,
  - path counts by depth.

Sample artifacts (committed):

- `WIP/Wolfram_PaperPack/artifacts/ce1_multiway_depth3.json`
- `WIP/Wolfram_PaperPack/artifacts/ce2_multiway_depth2.json`

---

## 4. Offline Visuals (Optional Follow-on Completed)

Two offline options are provided:

1. **HTML viewer** (no dependencies; pan/zoom; node inspection):
   - `WIP/Wolfram_PaperPack/artifacts/wolfram_viewer.html`
   - `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/artifacts/wolfram_viewer.html`

2. **GraphViz exports** from JSON:
   - Script:
     - `WIP/Wolfram_PaperPack/tools/wolfram_json_to_dot.py`
     - `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/scripts/wolfram_json_to_dot.py`
   - Outputs (DOT + rendered SVGs):
     - `*_multiway.dot/.svg`
     - `*_branchial.dot/.svg`
     - `*_combined.dot/.svg`

Pre-generated visuals are committed in:

- `WIP/Wolfram_PaperPack/artifacts/visuals/`
- `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/artifacts/visuals/`

---

## 5. Reproducibility and Researcher Bundle

### 5.1 Repo-local reproducibility

See:

- `WIP/Wolfram_PaperPack/03_Reproducibility.md`

### 5.2 Self-contained researcher bundle

Folder:

- `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/`

One-command verification:

- `./scripts/verify_wolfram.sh`

What it does:

- `lake update` (pinned deps)
- strict builds `-DwarningAsError=true` for all Wolfram modules + bridge modules + demo exe
- runs `wolfram_multiway_demo` to produce JSON
- greps for `axiom`/`sorry`/`admit` in bundle sources
- collects compiler artifacts (`.olean` + C IR)
- computes `sha256sum` over the bundle (excluding `.lake/`, `build/`, `vendor/`)
- optionally generates DOT/SVG visuals if `python3` is available

Entry docs:

- `WIP/Wolfram_PaperPack/RESEARCHER_BUNDLE/README_VERIFY.md`

---

## 6. Status: Formal Completeness

Within this Wolfram scope:

- no `sorry`/`admit` markers in the relevant Lean proof tree,
- no new axioms are introduced for the Wolfram development,
- strict builds are supported (`-DwarningAsError=true`),
- executable builds/run/robustness/portability checks are supported locally.

---

## 7. Remaining Work (If We Choose to Extend the Mathematics)

Everything identified as “optional follow-on” in the Wolfram audit has been implemented.

The remaining directions are research extensions rather than completion gaps:

- strengthen the Wolfram demo encoding from “counts over a short basis” to a fully faithful JSON encoding of `HGraph V` (at the cost of bigger outputs),
- add enumeration-free “invariance checks” on the relation-based multiway interface (requires additional hypotheses or search procedures),
- connect Wolfram causal invariance to further HeytingLean lenses beyond WPP (e.g. categorical/process encodings).
