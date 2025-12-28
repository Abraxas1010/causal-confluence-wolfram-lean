import HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance
import HeytingLean.WPP.Wolfram.ConfluenceCausalInvarianceGC
import HeytingLean.WPP.Wolfram.MultiwayBridge
import HeytingLean.WPP.Wolfram.SimpleHypergraph

/-!
Audit file: print the kernel axioms footprint of the core Wolfram results.

This file is intentionally not imported by the library; it is executed by
`scripts/verify_wolfram.sh` and its output is captured in `reports/AXIOMS_PRINT.txt`.
-/

#check HeytingLean.WPP.Wolfram.Counterexamples.confluence_causal_invariance_independent
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.confluence_causal_invariance_independent

#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE1.confluentNF
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE1.not_causalInvariant
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE1.causalGraphGC_iso_short_long

#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE2.causalInvariant
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE2.not_confluentNF
#print axioms HeytingLean.WPP.Wolfram.Counterexamples.CE2.causalInvariantGC

#print axioms HeytingLean.WPP.Wolfram.System.stepStates_iff_step
#print axioms HeytingLean.WPP.Wolfram.System.wpp_stepStar_iff_stepStar

#check HeytingLean.WPP.Wolfram.System.Event.injective_of_applicable_of_finRange_mem_lhs
#print axioms HeytingLean.WPP.Wolfram.System.Event.injective_of_applicable_of_finRange_mem_lhs

#check HeytingLean.WPP.Wolfram.SystemFresh.Event.applyWith_iso
#print axioms HeytingLean.WPP.Wolfram.SystemFresh.Event.applyWith_iso
