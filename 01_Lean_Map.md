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
  - rule schemas + instantiation by injective substitution
  - singleway evolution relation
  - normal forms / reachability

- `HeytingLean.WPP.Wolfram.CausalGraph`
  - causal graphs from a singleway evolution (“created then destroyed”)

- `HeytingLean.WPP.Wolfram.CausalGraphLabeled`
  - multiplicity-aware causal graph (`output ∩ input` labels) + forgetful map back to `CausalGraph`

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
  
- `HeytingLean.CLI.WolframMultiwayMain`
  - executable demo: bounded multiway + branchial (CE1/CE2), emits JSON

## Optional extensions (not required for the current Wolfram bundle)

- Enumeration-free (non-`Finset`) multiway interface for infinite Wolfram systems.
- Extra offline visuals beyond the JSON artifacts.
