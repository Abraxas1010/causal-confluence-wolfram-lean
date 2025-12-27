# Wolfram Project — Lean Map

This is the concept-to-Lean map for the Wolfram/SetReplace formalization.

For the standalone PaperPack, the pinned Lean sources live under `RESEARCHER_BUNDLE/HeytingLean/…`.

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
  - rule schemas + instantiation by substitution (not assumed injective)
  - singleway evolution relation
  - normal forms / reachability

- `HeytingLean.WPP.Wolfram.FreshSupply`
  - polymorphic fresh-vertex supply typeclass (`FreshSupply`)
  - finite fresh allocation (`FreshSupply.alloc`) with proofs (injective + disjoint from forbidden set)

- `HeytingLean.WPP.Wolfram.RewriteFresh`
  - rewrite semantics with explicit fresh vertices on the RHS
  - α-equivalence lemma: different fresh choices yield isomorphic results

- `HeytingLean.WPP.Wolfram.SimpleHypergraph`
  - “simple edge” invariant (no repeated vertices within any edge)
  - injective-WLOG lemmas: applicability forces injectivity for standard LHS shapes

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

- `HeytingLean.WPP.Wolfram.CausalInvarianceSingleLHS`
  - causal invariance as branch-pair resolution (up to `HGraph.Iso`) for **fresh-vertex** rewriting

- `HeytingLean.WPP.Wolfram.WM148`
  - Wolfram Physics WM148 system definition (`{{x,y}} → {{x,y},{y,z}}`) with explicit fresh allocation

- `HeytingLean.WPP.Wolfram.WM148CausalInvariant`
  - proof: `WM148.causalInvariant : SystemFresh.CausalInvariant (sys := WM148.sys)`
  
- `HeytingLean.CLI.WolframMultiwayMain`
  - executable demo: bounded multiway + branchial (CE1/CE2), emits JSON

- `HeytingLean.CLI.WolframWM148Main`
  - executable demo: bounded multiway exploration for WM148, emits JSON

## Optional extensions (not required for the current Wolfram bundle)

- Enumeration-free (non-`Finset`) multiway interface for infinite Wolfram systems.
- Extra offline visuals beyond the JSON artifacts.
