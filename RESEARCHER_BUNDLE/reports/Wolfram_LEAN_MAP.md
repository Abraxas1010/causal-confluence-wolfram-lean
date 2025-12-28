# Wolfram Project — Lean Map

This is the concept-to-Lean map for the Wolfram/SetReplace formalization.

## Core namespaces

- `HeytingLean.WPP.Multiway`
  - generic `WppRule` interface
  - `JR` forward-invariance kernel
  - inflationary `reachabilityNucleus` (LoF convention)

- `HeytingLean.WPP.MultiwayRel`
  - enumeration-free multiway interface `WppRel` (`stepRel : State → State → Prop`)
  - `JR` forward-invariance kernel and `reachabilityNucleus` packaging

- `HeytingLean.WPP.Wolfram.Hypergraph`
  - `Expr V := List V`
  - `HGraph V := Multiset (Expr V)`
  - `HGraph.rename`, `HGraph.Iso`

- `HeytingLean.WPP.Wolfram.Rewrite`
  - rule schemas + instantiation by substitution `σ : P → V` (not assumed injective)
  - singleway evolution relation
  - normal forms / reachability

- `HeytingLean.WPP.Wolfram.FreshSupply`
  - explicit fresh-vertex supply interface (`FreshSupply V`)

- `HeytingLean.WPP.Wolfram.RewriteFresh`
  - rewrite semantics that allocate fresh vertices + α-equivalence up to renaming

- `HeytingLean.WPP.Wolfram.SimpleHypergraph`
  - injective-WLOG lemma under a “simple edges” invariant

- `HeytingLean.WPP.Wolfram.CausalGraph`
  - causal graphs from a singleway evolution (“created then destroyed”)

- `HeytingLean.WPP.Wolfram.CausalGraphLabeled`
  - multiplicity-aware causal graph (`output ∩ input` labels) + forgetful map back to `CausalGraph`

- `HeytingLean.WPP.Wolfram.CausalGraphGC`
  - observable-event (“GC”) causal graph abstraction (`System.causalGraphGCOf`)
  - property: `Properties.GCausalInvariant`

- `HeytingLean.WPP.Wolfram.Multiway`
  - finite enumerators (finite `P`/`V`) for event-data and multiway branching
  - ordering/scheduler API
  - bridge to `HeytingLean.WPP.Multiway.WppRule`

- `HeytingLean.WPP.Wolfram.MultiwayBridge`
  - proof-level bridge between `System.Step` and `WppRule.stepRel`
  - `WppRule.StepStar (sys.toWppRule)` coincides with `System.StepStar`

- `HeytingLean.WPP.Wolfram.MultiwayRel`
  - enumeration-free bridge: `System.toWppRel` (no finiteness assumptions)

- `HeytingLean.WPP.Wolfram.Branchial`
  - branchial edges at depth (siblings share a predecessor)
  - bounded event-data path enumeration + `pathCountAtDepth`

- `HeytingLean.WPP.Wolfram.ConfluenceTheory`
  - relation-theoretic layer: `Step`, `StepStar`, Church–Rosser predicates
  - bounded-termination predicate `TerminatingFrom`

- `HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance`
  - `Properties.ConfluentNF`, `Properties.CausalInvariant`
  - Piskunov counterexamples CE1/CE2 + independence theorem

- `HeytingLean.WPP.Wolfram.ConfluenceCausalInvarianceGC`
  - CE1/CE2 under the observable-event (“GC”) causal graph abstraction

- `HeytingLean.WPP.Wolfram.CausalInvarianceSingleLHS`
  - branch-pair resolution causal invariance (`SystemFresh.CausalInvariant`) for fresh-vertex rewriting

- `HeytingLean.WPP.Wolfram.WM148`
  - WM148 system definition (fresh vertices)

- `HeytingLean.WPP.Wolfram.WM148CausalInvariant`
  - proof: `WM148.causalInvariant : SystemFresh.CausalInvariant (sys := WM148.sys)`

- `HeytingLean.CLI.WolframMultiwayMain`
  - executable demo: bounded multiway + branchial (CE1/CE2), emits JSON

## Optional extensions (not required for the current Wolfram bundle)

- Enumeration-free (non-`Finset`) multiway interface for infinite Wolfram systems.
- Extra offline visuals beyond the JSON artifacts.
