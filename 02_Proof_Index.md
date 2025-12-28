# Proof Index (what is proved, and where)

This is the minimal set of "results you can cite" from this mechanization.

Paths below are relative to this PaperPack repository: `RESEARCHER_BUNDLE/HeytingLean/...`
(in the main HeytingLean monorepo the same sources live under `lean/HeytingLean/...`).

## Tier 1: Hypergraph Rewriting Semantics

1. **SetReplace-faithful hypergraph data model**
   - Lean: `HeytingLean.WPP.Wolfram.Expr`, `HeytingLean.WPP.Wolfram.HGraph`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Hypergraph.lean`
   - Informal: expressions are ordered vertex lists (`List V`); hypergraphs are multisets of expressions.

2. **Substitution instantiation (SetReplace-style; not assumed injective)**
   - Lean: `HeytingLean.WPP.Wolfram.HGraph.rename`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Hypergraph.lean`
   - Informal: pattern vertices are replaced by an arbitrary match-substitution `σ : P → V` (Wolfram/SetReplace allows non-injective matches).

3. **Hypergraph isomorphism (vertex relabeling)**
   - Lean: `HeytingLean.WPP.Wolfram.HGraph.Iso`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Hypergraph.lean`
   - Informal: two hypergraphs are isomorphic if there exists a bijective renaming of vertices.

## Tier 2: Rewrite Rules and Evolution

4. **Rule schema and event application (non-injective matches allowed)**
   - Lean: `HeytingLean.WPP.Wolfram.Rule`, `HeytingLean.WPP.Wolfram.Event`, `HeytingLean.WPP.Wolfram.Event.apply`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Rewrite.lean`
   - Informal: a rule has LHS/RHS patterns; an event instantiates a rule with a substitution; apply removes instantiated LHS and adds instantiated RHS.

5. **Applicability predicate**
   - Lean: `HeytingLean.WPP.Wolfram.Event.Applicable`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Rewrite.lean`
   - Informal: an event is applicable when instantiated LHS is a submultiset of the current state.

6. **Singleway evolution relation**
   - Lean: `HeytingLean.WPP.Wolfram.Evolves`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Rewrite.lean`
   - Informal: a sequence of events tracks the evolution from initial to final state.

## Tier 3: Causal Graphs

7. **Causal graph construction ("created then destroyed")**
   - Lean: `HeytingLean.WPP.Wolfram.causalGraphOf`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraph.lean`
   - Informal: edge `e₁ → e₂` exists iff some expression is created by `e₁` and destroyed by `e₂`.

8. **Causal graph isomorphism**
   - Lean: `HeytingLean.WPP.Wolfram.CausalGraph.Iso`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraph.lean`
   - Informal: two causal graphs are isomorphic if there exists a bijection on events preserving edges.

9. **Labeled causal graph (multiplicity-aware)**
   - Lean: `HeytingLean.WPP.Wolfram.labeledCausalGraphOf`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraphLabeled.lean`
   - Informal: edges are labeled by the multiset intersection `output ∩ input`; forgetful map recovers unlabeled graph.

9a. **Observable-event (“GC”) causal graph (coarse-graining)**
   - Lean: `HeytingLean.WPP.Wolfram.System.causalGraphGCOf`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraphGC.lean`
   - Informal: discard events whose created expressions do **not** survive to the endpoint, then build the causal graph
     on the remaining events (a detour-insensitive abstraction; not SetReplace’s definition).

9b. **GC causal invariance (terminating, normal forms)**
   - Lean: `HeytingLean.WPP.Wolfram.Properties.GCausalInvariant`
   - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/CausalGraphGC.lean`
   - Informal: any two evolutions to normal forms have isomorphic GC causal graphs.

## Tier 4: Confluence Theory (Relation-Theoretic Layer)

10. **One-step relation (Step)**
    - Lean: `HeytingLean.WPP.Wolfram.System.Step`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
    - Informal: `Step s t` holds iff there exists an applicable event whose application transforms `s` to `t`.

11. **Reflexive-transitive closure (StepStar)**
    - Lean: `HeytingLean.WPP.Wolfram.System.StepStar`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
    - Informal: reachability via `Relation.ReflTransGen`.

12. **Church-Rosser predicates**
    - Lean: `HeytingLean.WPP.Wolfram.Joinable`, `HeytingLean.WPP.Wolfram.Confluent`, `HeytingLean.WPP.Wolfram.SemiConfluent`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
    - Informal: standard abstract rewriting definitions adapted to Wolfram systems.

13. **Bounded termination predicate**
    - Lean: `HeytingLean.WPP.Wolfram.System.TerminatingFrom`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceTheory.lean`
    - Informal: all rewrite sequences from an initial state eventually reach a normal form.

## Tier 5: Confluence vs Causal Invariance Independence (Main Theorem)

14. **Confluence-as-normal-form (ConfluentNF)**
    - Lean: `HeytingLean.WPP.Wolfram.Properties.ConfluentNF`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
    - Informal: any two reachable normal forms are hypergraph-isomorphic (vertex relabeling).

15. **Causal invariance (CausalInvariant)**
    - Lean: `HeytingLean.WPP.Wolfram.Properties.CausalInvariant`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
    - Informal: any two maximal evolutions reaching normal forms have isomorphic causal graphs.

16. **Counterexample CE1: confluent but NOT causally invariant**
    - Lean: `HeytingLean.WPP.Wolfram.Counterexamples.CE1.confluentNF`, `HeytingLean.WPP.Wolfram.Counterexamples.CE1.not_causalInvariant`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
    - Informal: explicit construction of a terminating system that reaches a unique normal form but has non-isomorphic causal graphs along different paths.

17. **Counterexample CE2: causally invariant but NOT confluent**
    - Lean: `HeytingLean.WPP.Wolfram.Counterexamples.CE2.causalInvariant`, `HeytingLean.WPP.Wolfram.Counterexamples.CE2.not_confluentNF`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
    - Informal: explicit construction of a terminating system with isomorphic causal graphs but multiple non-isomorphic normal forms.

18. **Independence theorem (main result)**
    - Lean: `HeytingLean.WPP.Wolfram.Counterexamples.confluence_causal_invariance_independent`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvariance.lean`
    - Informal: confluence and causal invariance are independent properties; neither implies the other.

18a. **CE1 detour disappears under GC causal graphs**
    - Lean: `HeytingLean.WPP.Wolfram.Counterexamples.CE1.causalGraphGC_iso_short_long`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvarianceGC.lean`
    - Informal: CE1’s short/long normal-form evolutions become causally-graph-isomorphic after GC coarse-graining.

18b. **CE2 is GC-causally-invariant**
    - Lean: `HeytingLean.WPP.Wolfram.Counterexamples.CE2.causalInvariantGC`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/ConfluenceCausalInvarianceGC.lean`
    - Informal: CE2 remains causally invariant under the GC causal-graph notion.

## Tier 6: Multiway and Branchial Infrastructure

19. **Finite multiway enumerator (stepStates)**
    - Lean: `HeytingLean.WPP.Wolfram.System.stepStates`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Multiway.lean`
    - Informal: for finite `V`/`P`, enumerate all one-step successors as a `Finset`.

20. **States at depth (bounded exploration)**
    - Lean: `HeytingLean.WPP.Wolfram.System.statesAtDepth`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Multiway.lean`
    - Informal: iteratively compute all reachable states up to depth `n`.

21. **Branchial edges at depth**
    - Lean: `HeytingLean.WPP.Wolfram.System.branchialEdgesAtDepth`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Branchial.lean`
    - Informal: siblings are states that share a common predecessor at depth `n-1`.

22. **Path count at depth**
    - Lean: `HeytingLean.WPP.Wolfram.System.pathCountAtDepth`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/Branchial.lean`
    - Informal: count distinct paths from initial state to a given state at depth `n`.

## Tier 7: Bridges to Generic WPP Interfaces

23. **Bridge: Finset ↔ Step relation**
    - Lean: `HeytingLean.WPP.Wolfram.System.stepStates_iff_step`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/MultiwayBridge.lean`
    - Informal: `t ∈ stepStates s ↔ Step s t`; the finite enumerator is correct.

24. **Bridge: WppRule.StepStar ↔ System.StepStar**
    - Lean: `HeytingLean.WPP.Wolfram.System.wpp_stepStar_iff_stepStar`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/MultiwayBridge.lean`
    - Informal: the generic `WppRule` interface agrees with the Wolfram-specific `StepStar`.

25. **Enumeration-free bridge (WppRel)**
    - Lean: `HeytingLean.WPP.Wolfram.System.toWppRel`, `HeytingLean.WPP.Wolfram.System.toWppRel_stepStar_iff`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/MultiwayRel.lean`
    - Informal: Wolfram systems can be lifted to the `Prop`-level `WppRel` interface without finiteness assumptions.

## Tier 8: Generic WPP (Shared Infrastructure)

26. **Forward-invariance kernel (JR)**
    - Lean: `HeytingLean.WPP.WppRule.JR`, `HeytingLean.WPP.WppRel.JR`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Multiway.lean`, `RESEARCHER_BUNDLE/HeytingLean/WPP/MultiwayRel.lean`
    - Informal: `JR P s := { t | StepStar s t → P t }`; kernel of forward reachability.

27. **JR is monotone, contractive, idempotent, and meet-preserving**
    - Lean: `HeytingLean.WPP.WppRule.JR.mono`, `.contractive`, `.idem`, `.inf`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Multiway.lean`
    - Informal: standard properties ensuring JR forms a nucleus on predicates.

28. **Reachability nucleus (inflationary)**
    - Lean: `HeytingLean.WPP.WppRule.reachabilityNucleus`, `HeytingLean.WPP.WppRel.reachabilityNucleus`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Multiway.lean`, `RESEARCHER_BUNDLE/HeytingLean/WPP/MultiwayRel.lean`
    - Informal: packaging JR as a `Nucleus` on `Set State` (LoF convention: inflationary).

## CLI / Executable

29. **Executable demo (wolfram_multiway_demo)**
    - Lean: `HeytingLean.CLI.WolframMultiwayMain.main`
    - File: `RESEARCHER_BUNDLE/HeytingLean/CLI/WolframMultiwayMain.lean`
    - Informal: bounded multiway + branchial exploration for CE1/CE2; outputs JSON for visualization.

## Tier 9: Wolfram Physics WM148 (fresh vertices)

30. **WM148 system (explicit fresh vertices)**
    - Lean: `HeytingLean.WPP.Wolfram.WM148.sys`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/WM148.lean`
    - Informal: the WPP WM148 rule `{{x,y}} -> {{x,y},{y,z}}` with a one-vertex fresh allocation on the RHS.

31. **WM148 causal invariance (branch-pair resolution)**
    - Lean: `HeytingLean.WPP.Wolfram.WM148.causalInvariant`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/WM148CausalInvariant.lean`
    - Informal: causal invariance as branch-pair resolution up to `HGraph.Iso` in `SystemFresh`.

32. **Executable demo (wolfram_wm148_demo)**
    - Lean: `HeytingLean.CLI.WolframWM148Main.main`
    - File: `RESEARCHER_BUNDLE/HeytingLean/CLI/WolframWM148Main.lean`
    - Informal: bounded multiway exploration for WM148; emits JSON for visualization.

## Tier 10: Extensions: Wolfram-ontology correspondence (polymorphic)

33. **Fresh-vertex supply (polymorphic)**
    - Lean: `HeytingLean.WPP.Wolfram.FreshSupply`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/FreshSupply.lean`
    - Informal: a typeclass `FreshSupply V` that allocates vertices not in a finite forbidden set, with proofs.

34. **Fresh-vertex rewrite semantics**
    - Lean: `HeytingLean.WPP.Wolfram.RuleFresh`, `HeytingLean.WPP.Wolfram.SystemFresh`, `HeytingLean.WPP.Wolfram.SystemFresh.Event.applyWith`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/RewriteFresh.lean`
    - Informal: RHS may introduce fresh vertices; semantics explicitly allocates them using `FreshSupply`.

35. **α-equivalence of fresh choices**
    - Lean: `HeytingLean.WPP.Wolfram.SystemFresh.Event.applyWith_iso`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/RewriteFresh.lean`
    - Informal: any two valid fresh allocations yield isomorphic results (equivalence up to vertex renaming fixing old vertices).

36. **Injective-WLOG under a “simple hypergraph” invariant**
    - Lean: `HeytingLean.WPP.Wolfram.HGraph.SimpleEdges`, `HeytingLean.WPP.Wolfram.System.Event.injective_of_applicable_of_finRange_mem_lhs`
    - File: `RESEARCHER_BUNDLE/HeytingLean/WPP/Wolfram/SimpleHypergraph.lean`
    - Informal: if edges are nodup, then standard rule-shapes force injective matches; this recovers the “injective matches” special case as a theorem.
