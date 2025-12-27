# Mechanized Independence of Confluence and Causal Invariance in Wolfram Physics Models

**A Formal Verification Study in Lean 4**

---

## Executive Summary

This report documents the complete formal verification, in Lean 4, of Max Piskunov's 2020 result demonstrating that **confluence** and **causal invariance** are **independent properties** of terminating Wolfram-model multiway systems. The formalization is fully mechanized with no proof gaps (`sorry`/`admit`), depends only on standard Lean kernel axioms, and includes executable demonstrations, visualization tools, and a self-contained researcher verification bundle.

In addition, the bundle includes a Wolfram Physics case study (**WM148**) in the fresh-vertex semantics, together with a mechanized causal-invariance proof and an executable demo (`wolfram_wm148_demo`) that emits bounded multiway JSON.

**Main Theorem (Mechanized):**
```
confluence_causal_invariance_independent :
  (¬ (ConfluentNF → CausalInvariant)) ∧ (¬ (CausalInvariant → ConfluentNF))
```

---

## Table of Contents

1. [Introduction and Motivation](#1-introduction-and-motivation)
2. [Background: The Wolfram Physics Project](#2-background-the-wolfram-physics-project)
3. [Mathematical Foundations](#3-mathematical-foundations)
4. [Repository Structure](#4-repository-structure)
5. [Formalization Architecture](#5-formalization-architecture)
6. [The Independence Proof](#6-the-independence-proof)
7. [Multiway and Branchial Infrastructure](#7-multiway-and-branchial-infrastructure)
8. [Proof Engineering Considerations](#8-proof-engineering-considerations)
9. [Verification and Reproducibility](#9-verification-and-reproducibility)
10. [Artifacts and Tooling](#10-artifacts-and-tooling)
11. [Conclusions and Future Work](#11-conclusions-and-future-work)

---

## 1. Introduction and Motivation

### 1.1 The Problem

The Wolfram Physics Project posits that our universe may emerge from the application of simple rewrite rules to hypergraph structures. A central claim is that **causal invariance**—the property that different orders of rule application yield isomorphic causal graphs—is responsible for:

- Relativistic invariance (Lorentz covariance)
- General covariance in spacetime
- Objective reality in quantum mechanics
- Local gauge invariance

Early presentations sometimes conflated causal invariance with **confluence**, a well-known property from term rewriting where all paths lead to the same result. This conflation is mathematically incorrect.

### 1.2 Piskunov's Contribution

In November 2020, Max Piskunov published a bulletin demonstrating via explicit counterexamples that:

1. **Confluence does not imply causal invariance**: A system can have a unique final state while having causal graphs of different structures depending on the execution order.

2. **Causal invariance does not imply confluence**: A system can have identical causal graphs for all executions while reaching genuinely different final states.

### 1.3 Why Formal Verification?

The distinction between these properties is subtle but foundational. If the Wolfram Physics program's claims about the physical significance of causal invariance are correct, then confusing it with confluence would misidentify the property responsible for fundamental physics. A machine-checked proof:

- Eliminates any possibility of error in the counterexample constructions
- Provides a verified reference implementation of the core definitions
- Creates infrastructure for further formalized research
- Demonstrates the feasibility of formal methods in theoretical physics

---

## 2. Background: The Wolfram Physics Project

### 2.1 Core Concepts

The Wolfram Physics Project models the universe as an evolving hypergraph:

| Concept | Definition | Physical Interpretation |
|---------|------------|------------------------|
| **Hypergraph** | Multiset of hyperedges (ordered vertex lists) | Spatial structure |
| **Rewrite Rule** | Pattern → replacement transformation | Fundamental law of physics |
| **Event** | Application of a rule at specific vertices | Atomic unit of change |
| **Causal Graph** | DAG where edges represent "created then destroyed" | Spacetime causal structure |
| **Multiway System** | All possible execution branches simultaneously | Quantum superposition |

### 2.2 Causal Invariance: The Key Property

When a hypergraph state admits multiple applicable rule instances, we have a choice. The **multiway system** considers all choices simultaneously. **Causal invariance** holds when:

> All maximal evolutions (paths to normal forms) produce isomorphic causal graphs.

This is distinct from asking whether the final hypergraph states are the same.

### 2.3 Physical Significance

According to Wolfram:

- Different rule-application orders correspond to different reference frames
- Causal invariance ensures physics is the same in all frames (relativity)
- The causal graph structure determines the spacetime metric
- Branching and merging in multiway systems relates to quantum mechanics

If this picture is correct, causal invariance—not confluence—is the property that makes physics possible.

---

## 3. Mathematical Foundations

### 3.1 SetReplace-Faithful Data Model

The formalization follows the SetReplace implementation conventions:

**Definition (Expression):**
```lean
abbrev Expr (V : Type u) : Type u := List V
```
An expression is an ordered list of vertices. Order matters: `[1,2] ≠ [2,1]`.

**Definition (Hypergraph State):**
```lean
abbrev HGraph (V : Type u) : Type u := Multiset (Expr V)
```
A hypergraph is a multiset of expressions. Multiplicity matters: two copies of the same edge are distinct.

### 3.2 Rewrite Semantics

**Definition (Rule Schema):**
```lean
structure Rule (P : Type u) where
  lhs : HGraph P
  rhs : HGraph P
```
A rule is parameterized by pattern vertices `P`. Application uses a substitution `σ : P → V` **not assumed injective**
(SetReplace permits non-injective matches in general).

**Definition (Event):**
```lean
structure Event (sys : System V P) where
  idx : Fin sys.rules.length  -- which rule
  σ : P → V                    -- substitution
```

**Definition (Application):**
```lean
def apply (e : sys.Event) (s : HGraph V) : HGraph V :=
  s - e.input + e.output
```
Replace the instantiated left-hand side with the instantiated right-hand side.

### 3.3 Causal Graphs

**Definition (Causal Dependency):**
Event `e₁` causes event `e₂` if there exists an expression created by `e₁` and destroyed by `e₂`:
```lean
def Causes (e₁ e₂ : sys.Event) : Prop :=
  ∃ x, x ∈ e₁.output ∧ x ∈ e₂.input
```

**Definition (Causal Graph):**
```lean
structure CausalGraph where
  n : Nat
  edge : Fin n → Fin n → Prop
```
Vertices are event indices; edges represent causal dependencies.

### 3.4 The Two Properties

**Definition (Confluence for Terminating Systems):**
```lean
def ConfluentNF (sys : System V P) : Prop :=
  ∀ s₁ s₂, sys.Reachable s₁ → sys.NormalForm s₁ →
           sys.Reachable s₂ → sys.NormalForm s₂ →
           HGraph.Iso s₁ s₂
```
All reachable normal forms are hypergraph-isomorphic (up to vertex renaming).

**Definition (Causal Invariance for Terminating Systems):**
```lean
def CausalInvariant (sys : System V P) : Prop :=
  ∀ es₁ es₂ t₁ t₂,
    sys.Evolves sys.init es₁ t₁ → sys.NormalForm t₁ →
    sys.Evolves sys.init es₂ t₂ → sys.NormalForm t₂ →
    CausalGraph.Iso (sys.causalGraphOf es₁) (sys.causalGraphOf es₂)
```
All maximal evolutions have isomorphic causal graphs.

---

## 4. Repository Structure

This package is organized for both verification and readability:

```
Wolfram_PaperPack/
├── README.md                      # Package overview and quick-start
├── TECHNICAL_REPORT_FULL.md       # This document
│
├── 01_Lean_Map.md                 # Concept → Lean namespace mapping
├── 02_Proof_Index.md              # Theorem/lemma declaration index
├── 03_Reproducibility.md          # Build and verification instructions
├── 04_Dependencies.md             # Lean/Mathlib version pins
├── 05_Technical_Report.md         # Condensed technical summary
├── 06_Final_Audit.md              # QA checklist and verification status
├── wolfram_audit_outstanding.md   # Development audit trail
│
├── artifacts/                     # Generated outputs
│   ├── ce1_multiway_depth3.json   # CE1 multiway exploration (JSON)
│   ├── ce2_multiway_depth2.json   # CE2 multiway exploration (JSON)
│   ├── wolfram_viewer.html        # Offline interactive viewer
│   └── visuals/                   # GraphViz exports
│       ├── ce1_multiway.dot/.svg
│       ├── ce1_branchial.dot/.svg
│       ├── ce2_multiway.dot/.svg
│       └── ...
│
├── tools/                         # Utility scripts
│   └── wolfram_json_to_dot.py     # JSON → GraphViz converter
│
└── RESEARCHER_BUNDLE/             # Self-contained verification package
    ├── README_VERIFY.md           # Verification instructions
    ├── lakefile.lean              # Lake build configuration
    ├── lean-toolchain             # Pinned Lean version
    ├── lake-manifest.json         # Locked dependency versions
    │
    ├── HeytingLean/               # Lean source files
    │   ├── CLI/
    │   │   ├── WolframMultiwayMain.lean
    │   │   ├── WolframBundleDemoMain.lean
    │   │   └── WolframWM148Main.lean
    │   └── WPP/
    │       ├── Multiway.lean
    │       ├── MultiwayRel.lean
    │       └── Wolfram/
    │           ├── Hypergraph.lean
    │           ├── Rewrite.lean
    │           ├── RewriteFresh.lean
    │           ├── CausalInvarianceSingleLHS.lean
    │           ├── CausalGraph.lean
    │           ├── CausalGraphLabeled.lean
    │           ├── ConfluenceTheory.lean
    │           ├── ConfluenceCausalInvariance.lean
    │           ├── Multiway.lean
    │           ├── Branchial.lean
    │           ├── MultiwayBridge.lean
    │           ├── MultiwayRel.lean
    │           ├── WM148.lean
    │           ├── WM148CausalInvariant.lean
    │           └── AxiomsAudit.lean
    │
    ├── scripts/
    │   ├── verify_wolfram.sh      # One-command verification
    │   └── wolfram_json_to_dot.py # Visual export tool
    │
    ├── artifacts/                 # Bundle-local artifacts
    │   ├── generated_ce1.json
    │   ├── generated_ce2.json
    │   ├── generated_wm148.json
    │   ├── wolfram_viewer.html
    │   └── visuals/
    │
    └── reports/                   # Verification outputs
        ├── BUILD_TRANSCRIPT_STRICT.txt
        ├── AXIOMS_PRINT.txt
        ├── GREP_AXIOM_SORRY_ADMIT.txt
        ├── SHA256SUMS.txt
        └── Wolfram_*.md           # Documentation copies
```

### Key Entry Points

| Task | Location |
|------|----------|
| **Quick verification** | `RESEARCHER_BUNDLE/scripts/verify_wolfram.sh` |
| **Read the proofs** | `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/` |
| **View multiway graphs** | `artifacts/wolfram_viewer.html` |
| **Run WM148 demo** | `cd RESEARCHER_BUNDLE && lake exe wolfram_wm148_demo` |
| **Understand the math** | `01_Lean_Map.md` + `02_Proof_Index.md` |
| **Check axiom footprint** | `RESEARCHER_BUNDLE/reports/AXIOMS_PRINT.txt` |

---

## 5. Formalization Architecture

### 5.1 Module Structure

The Lean sources in `RESEARCHER_BUNDLE/HeytingLean/WPP/` are organized as:

```
HeytingLean/WPP/
├── Multiway.lean              # Generic WppRule interface (Finset-based)
├── MultiwayRel.lean           # Generic WppRel interface (Prop-based)
└── Wolfram/
    ├── Hypergraph.lean        # Expr, HGraph, rename, Iso
    ├── Rewrite.lean           # Rule, System, Event, Evolves, NormalForm
    ├── CausalGraph.lean       # CausalGraph, Iso, causalGraphOf
    ├── CausalGraphLabeled.lean # Multiplicity-aware causal graphs
    ├── ConfluenceTheory.lean  # Step, StepStar, Church-Rosser predicates
    ├── ConfluenceCausalInvariance.lean  # Main theorem + counterexamples
    ├── Multiway.lean          # Finite enumerators, EventData, stepStates
    ├── Branchial.lean         # Branchial edges, path counting
    ├── MultiwayBridge.lean    # Bridge: stepStates ↔ Step relation
    └── MultiwayRel.lean       # Bridge to enumeration-free interface
```

### 5.2 Design Decisions

**Choice: Multiset vs Set for Hypergraphs**

We use `Multiset (Expr V)` rather than `Finset` to faithfully represent:
- Edge multiplicity (two copies of `[1,2]` are distinct)
- SetReplace's actual semantics

**Choice: Lists for Expressions**

We use `List V` rather than `Finset V` because:
- Vertex order matters: `[1,2] ≠ [2,1]`
- Self-loops are possible: `[1,1]` is valid
- This matches SetReplace's representation

**Choice: Substitutions (not assumed injective)**

Wolfram/SetReplace rewriting permits **non-injective** matches `σ : P → V` in general, so the mechanization
does not assume injectivity at the semantic level.

When working in an injective-only regime, we recover it as a theorem under a clear invariant:

- `HeytingLean.WPP.Wolfram.System.Event.injective_of_applicable_of_finRange_mem_lhs`:
  under a “simple hypergraph” hypothesis (no repeated vertices in an edge), the standard finite rule-shapes used
  in the CE development force `σ` to be injective.

### 5.3 Dependency Structure

```
Hypergraph ──┬── Rewrite ──┬── CausalGraph ──┬── ConfluenceCausalInvariance
             │             │                 │
             │             └── ConfluenceTheory ──┘
             │                      │
             └── Multiway ──────────┴── MultiwayBridge
                    │
                    └── Branchial
```

---

## 6. The Independence Proof

### 6.1 Counterexample 1: Confluent but Not Causally Invariant

**System CE1:**
- Pattern type: `P := Fin 2`
- Vertex type: `V := Fin 3`
- Rule: `{{0}, {0,1}} → {{0,1}, {1}}`
- Initial state: `{{0}, {0,1}, {1,2}, {0,2}}`

**Proof of Confluence:**

All evolutions terminate at the unique normal form `s₂ = {{2}, {0,1}, {1,2}, {0,2}}` (up to vertex renaming). The proof proceeds by exhaustive case analysis:

1. From initial state `s₀`, only two events are applicable:
   - `e₁₂`: applies rule with `σ(0)=0, σ(1)=1`
   - `e₁₃`: applies rule with `σ(0)=0, σ(1)=2`

2. Path via `e₁₂`:
   - `s₀ →[e₁₂]→ s₁ = {{1}, {0,1}, {1,2}, {0,2}}`
   - From `s₁`, only `e₂₃` is applicable
   - `s₁ →[e₂₃]→ s₂`
   - `s₂` is a normal form

3. Path via `e₁₃`:
   - `s₀ →[e₁₃]→ s₂`
   - `s₂` is a normal form (same state!)

**Proof of Non-Causal-Invariance:**

The two paths have different causal graphs:
- Short path `[e₁₃]`: causal graph has 1 vertex, 0 edges
- Long path `[e₁₂, e₂₃]`: causal graph has 2 vertices

Causal graphs with different vertex counts cannot be isomorphic:
```lean
lemma not_Iso_of_n_ne {g₁ g₂ : CausalGraph} (h : g₁.n ≠ g₂.n) : ¬ Iso g₁ g₂
```

### 6.2 Counterexample 2: Causally Invariant but Not Confluent

**System CE2:**
- Pattern type: `P := Fin 2`
- Vertex type: `V := Fin 2`
- Rule: `{{0,1}, {1,0}} → {{0}}`
- Initial state: `{{0,1}, {1,0}, {0}}`

**Proof of Causal Invariance:**

All maximal evolutions have length exactly 1:
1. From `s₀`, two events are applicable:
   - `e_id`: applies rule with `σ(0)=0, σ(1)=1` → reaches `nf₁ = {{0}, {0}}`
   - `e_swap`: applies rule with `σ(0)=1, σ(1)=0` → reaches `nf₂ = {{0}, {1}}`

2. Both `nf₁` and `nf₂` are normal forms (no length-2 edges remain).

3. All causal graphs have exactly 1 vertex and 0 edges.

4. All 1-vertex, 0-edge graphs are trivially isomorphic.

**Proof of Non-Confluence:**

The two normal forms are not hypergraph-isomorphic:
- `nf₁ = {{0}, {0}}` — multiset with two copies of `[0]`
- `nf₂ = {{0}, {1}}` — multiset with one `[0]` and one `[1]`

Any permutation of `Fin 2` either:
- Maps `0 ↦ 0, 1 ↦ 1` (identity): `nf₁` stays `{{0}, {0}}` ≠ `nf₂`
- Maps `0 ↦ 1, 1 ↦ 0` (swap): `nf₁` becomes `{{1}, {1}}` ≠ `nf₂`

### 6.3 The Main Theorem

Located in `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`:

```lean
theorem confluence_causal_invariance_independent :
    (¬ (∀ {V P : Type} (sys : System V P) [DecidableEq V],
        ConfluentNF sys → CausalInvariant sys)) ∧
    (¬ (∀ {V P : Type} (sys : System V P) [DecidableEq V],
        CausalInvariant sys → ConfluentNF sys)) := by
  constructor
  · intro h
    have : CausalInvariant CE1.sys := h CE1.confluentNF
    exact CE1.not_causalInvariant this
  · intro h
    have : ConfluentNF CE2.sys := h CE2.causalInvariant
    exact CE2.not_confluentNF this
```

---

## 7. Multiway and Branchial Infrastructure

### 7.1 Generic Multiway Interfaces

The formalization provides two generic interfaces for multiway systems:

**Finite Interface (`WppRule`)** in `RESEARCHER_BUNDLE/HeytingLean/WPP/Multiway.lean`:
```lean
structure WppRule (State : Type u) where
  step : State → Finset State
```
Suitable for finite state spaces with decidable enumeration.

**Relational Interface (`WppRel`)** in `RESEARCHER_BUNDLE/HeytingLean/WPP/MultiwayRel.lean`:
```lean
structure WppRel (State : Type u) where
  stepRel : State → State → Prop
```
Suitable for infinite state spaces; no enumeration required.

### 7.2 Wolfram Instantiations

Both interfaces are instantiated for Wolfram systems:

```lean
def System.toWppRule : WppRule (HGraph V) :=
  { step := fun s => sys.stepStates s }

def System.toWppRel : WppRel (HGraph V) :=
  { stepRel := fun s t => Step sys s t }
```

### 7.3 Bridge Theorems

In `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/MultiwayBridge.lean`:

```lean
theorem stepStates_iff_step {s t : HGraph V} :
    t ∈ sys.stepStates s ↔ Step sys s t

theorem wpp_stepStar_iff_stepStar {s t : HGraph V} :
    WppRule.StepStar sys.toWppRule s t ↔ StepStar sys s t
```

### 7.4 Forward-Invariance Kernel

The `JR` operator captures forward invariance:
```lean
def JR (U : Set State) : Set State :=
  fun s => ∀ t, StepStar s t → U t
```

Properties proven:
- `JR.mono`: monotonic
- `JR.contractive`: `JR U ⊆ U`
- `JR.idem`: `JR (JR U) = JR U`
- `JR.inf`: `JR (U ∩ V) = JR U ∩ JR V`

This forms the basis for a `Nucleus` on `Set State`, connecting to Laws of Form (LoF) conventions.

### 7.5 Branchial Graphs

In `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Branchial.lean`:

```lean
def branchialEdgesAtDepth : Nat → Finset (Sym2 (HGraph V))
  | 0 => ∅
  | n + 1 => (statesAtDepth n).biUnion siblingEdges
```

---

## 8. Proof Engineering Considerations

### 8.1 Decidability and Computation

The formalization leverages decidability extensively:
- `DecidableEq V` enables computational proofs via `decide`
- `Fintype P`, `Fintype V` enable exhaustive enumeration
- Many lemmas proven by `decide` for the small counterexample types (`Fin 2`, `Fin 3`)

Example:
```lean
lemma e12_apply_s0 : e12.apply sys s0 = s1 := by decide
```

### 8.2 Case Analysis Strategy

The counterexample proofs use systematic case analysis on:
- Substitution values: `σ 0 = 0 ∨ σ 0 = 1 ∨ σ 0 = 2`
- Injectivity constraints: `σ 0 ≠ σ 1`
- Evolution structure: pattern matching on `Evolves` constructors

### 8.3 Mathlib Integration

Key Mathlib dependencies (see `04_Dependencies.md`):
- `Data.Multiset`: multiset operations, submultiset ordering
- `Data.Finset`: finite set enumeration
- `Data.Fintype`: finiteness typeclass
- `Logic.Relation`: `ReflTransGen`, `Join`, Church-Rosser
- `Order.Nucleus`: nucleus infrastructure (for LoF connections)

### 8.4 Avoiding Common Pitfalls

**Pitfall: Assuming lemma names from other Mathlib versions**

The formalization explicitly searches for lemmas:
```bash
rg "lemma_name" .lake/packages/mathlib/
```

**Pitfall: Incomplete case analysis**

Every case split is explicitly exhaustive. Impossible cases are proven `False.elim`.

---

## 9. Verification and Reproducibility

### 9.1 Quick Verification

From the `RESEARCHER_BUNDLE/` directory:

```bash
./scripts/verify_wolfram.sh
```

This performs:
1. `lake update` (fetch pinned dependencies)
2. Strict build with `-DwarningAsError=true -Dno sorry`
3. Runs `wolfram_multiway_demo` for both CE1 and CE2
4. Runs `wolfram_wm148_demo` (WM148 bounded multiway; fresh vertices)
5. Runs `wolfram_bundle_demo` (emits LambdaIR → MiniC → C) and compiles/runs the emitted C
6. Greps for `axiom`/`sorry`/`admit` in sources
7. Generates SHA256 checksums

### 9.2 Strict Build Requirements

All proofs pass strict verification:
```bash
cd RESEARCHER_BUNDLE
lake build -- -DwarningAsError=true -Dno sorry
```

### 9.3 Marker Scans

No forbidden markers in the proof tree (see `reports/GREP_AXIOM_SORRY_ADMIT.txt`):
```bash
rg "\b(sorry|admit)\b" --type lean HeytingLean/  # 0 results
rg "^\s*axiom\s" --type lean HeytingLean/        # 0 results
```

### 9.4 Axiom Footprint

From `reports/AXIOMS_PRINT.txt`:

```
'confluence_causal_invariance_independent' depends on axioms:
  [propext, Classical.choice, Quot.sound]
```

These are standard Lean kernel axioms:
- `propext`: Propositional extensionality
- `Classical.choice`: Axiom of choice (classical logic)
- `Quot.sound`: Quotient soundness

**No project-specific axioms were introduced.**

### 9.5 Reproducibility Checksums

See `reports/SHA256SUMS.txt` for cryptographic hashes of all source files, enabling verification that files have not been modified.

---

## 10. Artifacts and Tooling

### 10.1 Executable Demo

The `wolfram_multiway_demo` executable (built from `HeytingLean/CLI/WolframMultiwayMain.lean`):

```bash
cd RESEARCHER_BUNDLE
lake exe wolfram_multiway_demo --sys ce1 --maxDepth 3
lake exe wolfram_multiway_demo --sys ce2 --maxDepth 2
```

Outputs JSON containing:
- Multiway graph nodes (states as expression counts)
- Edges (labeled by rule index and substitution)
- Levels (states reachable at each depth)
- Branchial edges (sibling connections)
- Path counts per state per depth

### 10.2 Certified Compiler Artifacts (LambdaIR → C)

The bundle also includes a minimal, independently verifiable “proof → program” artifact:

- `wolfram_bundle_demo` emits:
  - `artifacts/compiler/ir/wpp_add1.lambdair.txt`
  - `artifacts/compiler/ir/wpp_add1.minic.txt`
  - `artifacts/compiler/c/wpp_add1.c`
- `verify_wolfram.sh` then compiles the emitted C via `cc` and runs it (expected output: `42`).

### 10.3 Pre-Generated Artifacts

Located in `artifacts/`:

| File | Description |
|------|-------------|
| `ce1_multiway_depth3.json` | CE1 multiway exploration to depth 3 |
| `ce2_multiway_depth2.json` | CE2 multiway exploration to depth 2 |
| `wolfram_viewer.html` | Offline interactive graph viewer |
| `visuals/*.dot` | GraphViz source files |
| `visuals/*.svg` | Rendered graph images |

### 10.3 Offline Viewer

Open `artifacts/wolfram_viewer.html` in any browser:
- Pan/zoom navigation
- Click nodes to inspect state details
- Toggle between multiway and branchial views
- No server or dependencies required

### 10.4 GraphViz Export

Use `tools/wolfram_json_to_dot.py` to regenerate visuals:

```bash
python3 tools/wolfram_json_to_dot.py artifacts/ce1_multiway_depth3.json
# Outputs: ce1_multiway.dot, ce1_branchial.dot, ce1_combined.dot
dot -Tsvg ce1_multiway.dot -o ce1_multiway.svg
```

### 10.5 Sample JSON Output (CE1)

From `artifacts/ce1_multiway_depth3.json`:

```json
{
  "maxDepth": 3,
  "nodes": [
    [1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0],
    [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0],
    [0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0]
  ],
  "edges": [
    {"src": 0, "dst": 1, "label": {"ruleIdx": 0, "sigma": [0, 1]}},
    {"src": 0, "dst": 2, "label": {"ruleIdx": 0, "sigma": [0, 2]}},
    {"src": 1, "dst": 2, "label": {"ruleIdx": 0, "sigma": [1, 2]}}
  ],
  "branchial": [{"i": 1, "j": 2}]
}
```

---

## 11. Conclusions and Future Work

### 11.1 Summary of Contributions

1. **First fully mechanized proof** of the confluence/causal-invariance independence
2. **SetReplace-faithful formalization** of Wolfram hypergraph rewriting
3. **Verified infrastructure** for multiway and branchial analysis
4. **Bridge theorems** connecting Wolfram semantics to generic multiway interfaces
5. **Reproducible artifacts** including executable demos and visualizations

### 11.2 Significance

This work:
- Resolves any ambiguity about the relationship between confluence and causal invariance
- Provides a verified foundation for further Wolfram Physics formalization
- Demonstrates that subtle foundational distinctions can and should be machine-checked
- Creates reusable infrastructure for studying multiway rewriting systems

### 11.3 Limitations

- The counterexamples are for **terminating** systems only
- No formalization yet of the **infinite** (non-terminating) regime
- The causal graph definition uses the simpler "created then destroyed" relation
- No direct connection yet to physical observables

### 11.4 Future Directions

1. **Non-terminating systems**: Extend to coinductive causal invariance notions
2. **Continuous limits**: Connect to differential geometry / spacetime metrics
3. **Quantum mechanics**: Formalize branchial space and Hilbert space correspondences
4. **Computational complexity**: Analyze decidability of causal invariance checking
5. **Wolfram Language cross-checks**: `RESEARCHER_BUNDLE/tools/wolfram_ce1_ce2.wl` reproduces CE1/CE2 bounded multiway JSON;
   extend this to an automatic exporter for arbitrary systems and (optionally) SetReplace/WolframModel execution.

---

## Appendix A: File Listing

| File | Lines | Purpose |
|------|-------|---------|
| `Hypergraph.lean` | 106 | Core data types and isomorphism |
| `Rewrite.lean` | 114 | Rewrite semantics |
| `CausalGraph.lean` | 66 | Causal graph construction |
| `CausalGraphLabeled.lean` | ~80 | Multiplicity-aware variant |
| `ConfluenceTheory.lean` | 127 | Relation-theoretic layer |
| `ConfluenceCausalInvariance.lean` | 797 | Main theorem and counterexamples |
| `Multiway.lean` (Wolfram) | 201 | Finite multiway enumerator |
| `Branchial.lean` | 140 | Branchial graph infrastructure |
| `MultiwayBridge.lean` | 99 | Bridge to WppRule |
| `MultiwayRel.lean` (Wolfram) | ~60 | Bridge to WppRel |

---

## Appendix B: Key Theorem Signatures

```lean
-- Independence theorem
theorem confluence_causal_invariance_independent :
    (¬ (∀ sys, ConfluentNF sys → CausalInvariant sys)) ∧
    (¬ (∀ sys, CausalInvariant sys → ConfluentNF sys))

-- CE1 is confluent
theorem CE1.confluentNF : ConfluentNF CE1.sys

-- CE1 is not causally invariant
theorem CE1.not_causalInvariant : ¬ CausalInvariant CE1.sys

-- CE2 is causally invariant
theorem CE2.causalInvariant : CausalInvariant CE2.sys

-- CE2 is not confluent
theorem CE2.not_confluentNF : ¬ ConfluentNF CE2.sys

-- Bridge: finite enumerator ↔ step relation
theorem stepStates_iff_step : t ∈ sys.stepStates s ↔ Step sys s t

-- Bridge: WppRule closure ↔ System closure
theorem wpp_stepStar_iff_stepStar :
    WppRule.StepStar sys.toWppRule s t ↔ StepStar sys s t
```

---

## Appendix C: Verification Commands

```bash
# === From RESEARCHER_BUNDLE directory ===

# One-command full verification
./scripts/verify_wolfram.sh

# Manual strict build
lake build -- -DwarningAsError=true -Dno sorry

# Check for forbidden markers
rg "\b(sorry|admit)\b" --type lean HeytingLean/

# Print axiom dependencies
lake env lean -c 'import HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.confluence_causal_invariance_independent'

# Run executable demos
lake exe wolfram_multiway_demo -- --sys ce1 --maxDepth 3
lake exe wolfram_multiway_demo -- --sys ce2 --maxDepth 2
lake exe wolfram_wm148_demo -- --maxDepth 6

# Generate visuals (requires Python 3 + graphviz)
python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce1.json artifacts/visuals/generated_ce1 --render-svg
python3 scripts/wolfram_json_to_dot.py artifacts/generated_ce2.json artifacts/visuals/generated_ce2 --render-svg
```

---

## References

1. Piskunov, M. (2020). "Confluence and Causal Invariance." Wolfram Physics Bulletins.
   https://bulletins.wolframphysics.org/2020/11/confluence-and-causal-invariance/

2. Wolfram, S. (2020). "A Project to Find the Fundamental Theory of Physics."
   https://www.wolframphysics.org/

3. Wolfram, S. (2020). "Finally We May Have a Path to the Fundamental Theory of Physics."
   https://writings.stephenwolfram.com/2020/04/finally-we-may-have-a-path-to-the-fundamental-theory-of-physics-and-its-beautiful/

4. SetReplace Documentation. GitHub: maxitg/SetReplace.
   https://github.com/maxitg/SetReplace

5. The Mathlib Community. Mathlib4.
   https://github.com/leanprover-community/mathlib4

---

**Document Version:** 1.1
**Date:** 2025-12-26
**Verification Status:** PASSED (all gates)
