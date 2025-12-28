import Mathlib.Data.Finset.Sort
import HeytingLean.WPP.Wolfram.CausalGraph

namespace HeytingLean
namespace WPP
namespace Wolfram

/-!
# "Garbage-collected" causal graphs (observable-event coarse-graining)

The SetReplace-style causal graph (`HeytingLean.WPP.Wolfram.System.causalGraphOf`) uses **all**
event steps in a chosen evolution as vertices.

For comparisons that should ignore transient bookkeeping steps, we define a coarse-grained causal
graph whose vertices are only those events that create at least one expression that is present in
the endpoint state. Intuitively, we "garbage-collect" events whose created expressions do not
survive to the endpoint.

This is **not** the SetReplace definition; it is an "observable-event" abstraction.
-/

universe u v

namespace System

variable {V : Type u} {P : Type v} (sys : System V P)
variable [DecidableEq V]

open System

namespace Event

/-- `x` is *created (nontrivially)* by an event `e` if it appears in the output and not in the input. -/
def Created (e : sys.Event) (x : Expr V) : Prop :=
  x ∈ e.output (sys := sys) ∧ x ∉ e.input (sys := sys)

/-- An event is *observable* w.r.t. an endpoint state `t` if it creates some expression present in `t`. -/
def Observable (e : sys.Event) (t : HGraph V) : Prop :=
  ∃ x, Created (sys := sys) e x ∧ x ∈ t

end Event

/-- The finset of indices of events in `es` that are observable w.r.t. endpoint `t`. -/
noncomputable def observableIdxs (es : List sys.Event) (t : HGraph V) : Finset (Fin es.length) := by
  classical
  exact Finset.univ.filter (fun i => Event.Observable (sys := sys) (es.get i) t)

/-- Observable-event causal graph of an evolution ending in `t` (a "garbage-collected" abstraction). -/
noncomputable def causalGraphGCOf (es : List sys.Event) (t : HGraph V) : CausalGraph := by
  classical
  let S : Finset (Fin es.length) := observableIdxs (sys := sys) es t
  refine { n := S.card, edge := ?_ }
  intro i j
  let ii : Fin es.length := (S.orderIsoOfFin rfl i).1
  let jj : Fin es.length := (S.orderIsoOfFin rfl j).1
  exact ii.1 < jj.1 ∧ (es.get ii).Causes (sys := sys) (es.get jj)

end System

namespace Properties

variable {V : Type u} {P : Type v} (sys : System V P)
variable [DecidableEq V]

/-- Observable-event ("GC") causal invariance for terminating systems. -/
def GCausalInvariant : Prop :=
  ∀ ⦃es₁ es₂ : List sys.Event⦄ ⦃t₁ t₂ : HGraph V⦄,
    sys.Evolves sys.init es₁ t₁ → sys.NormalForm t₁ →
    sys.Evolves sys.init es₂ t₂ → sys.NormalForm t₂ →
    CausalGraph.Iso (sys.causalGraphGCOf es₁ t₁) (sys.causalGraphGCOf es₂ t₂)

end Properties

end Wolfram
end WPP
end HeytingLean

