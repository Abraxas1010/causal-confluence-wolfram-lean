import HeytingLean.LambdaIR.NatCompileFrag
import HeytingLean.LambdaIR.NatCompileFragCorrectness
import HeytingLean.MiniC.ToC
import HeytingLean.C.Emit

namespace HeytingLean
namespace CLI

namespace WolframBundleDemo

open HeytingLean.LambdaIR
open HeytingLean.LambdaIR.NatFunFragment
open HeytingLean.LambdaIR.NatCompileFrag

private def varIndex : {Γ : Ctx} → {τ : Ty} → Var Γ τ → Nat
  | _, _, .vz => 0
  | _, _, .vs v => varIndex v + 1

private partial def termToString : {Γ : Ctx} → {τ : Ty} → Term Γ τ → String
  | _, _, .var v => s!"(var {varIndex v})"
  | _, _, .lam body => s!"(lam {termToString body})"
  | _, _, .app f x => s!"(app {termToString f} {termToString x})"
  | _, _, .pair t₁ t₂ => s!"(pair {termToString t₁} {termToString t₂})"
  | _, _, .fst t => s!"(fst {termToString t})"
  | _, _, .snd t => s!"(snd {termToString t})"
  | _, _, .inl t => s!"(inl {termToString t})"
  | _, _, .inr t => s!"(inr {termToString t})"
  | _, _, .matchSum s k₁ k₂ => s!"(matchSum {termToString s} {termToString k₁} {termToString k₂})"
  | _, _, .if_ c t e => s!"(if {termToString c} {termToString t} {termToString e})"
  | _, _, .constNat n => s!"(nat {n})"
  | _, _, .constBool b => s!"(bool {b})"
  | _, _, .primAddNat => "(primAddNat)"
  | _, _, .primEqNat => "(primEqNat)"

private def add1Term : Term [] (Core.Ty.arrow Core.Ty.nat Core.Ty.nat) :=
  Term.lam
    (Term.app (Term.app Term.primAddNat (Term.var Core.Var.vz)) (Term.constNat 1))

private theorem add1Term_isNatFun : IsNatFun add1Term := by
  refine ⟨_, rfl, ?_⟩
  refine IsNatBody.expr ?_
  refine IsNatExpr.add ?_ ?_
  · exact IsNatExpr.var
  · exact IsNatExpr.constNat 1

private theorem add1Term_spec (funName paramName : String) :
    NatFunSpecFrag funName paramName add1Term := by
  simpa using (compileNatFunFrag_correct (funName := funName) (paramName := paramName) add1Term_isNatFun)

private def writeFileSafely (path : System.FilePath) (contents : String) : IO Bool := do
  try
    match path.parent with
    | some dir => IO.FS.createDirAll dir
    | none => pure ()
    IO.FS.writeFile path contents
    return true
  catch e =>
    IO.eprintln s!"[wolfram_bundle_demo] write failed: {path}: {e}"
    return false

private def driverC (funName : String) (x : Nat) : String :=
  String.intercalate "\n"
    [ ""
    , ""
    , "int main(void) {"
    , s!"  long long x = {x};"
    , s!"  printf(\"%lld\\n\", {funName}(x));"
    , "  return 0;"
    , "}"
    , ""
    ]

def main (_argv : List String) : IO UInt32 := do
  try
    IO.println "[wolfram_bundle_demo] generating LambdaIR + C artifacts"

    let funName := "wpp_add1"
    let paramName := "x"
    let t := add1Term
    let compiledMiniC := compileNatFunFrag funName paramName t
    let cFun := HeytingLean.MiniC.ToC.compileFun compiledMiniC

    let sample : Nat := 41
    let outLean :=
      LambdaIR.evalClosed (LambdaIR.Term.app t (LambdaIR.Term.constNat sample))
    let outMiniC :=
      HeytingLean.MiniC.runNatFunFrag compiledMiniC paramName sample

    let outNat : Nat := outLean
    IO.println s!"[demo] evalClosed wpp_add1({sample}) = {outNat}"
    IO.println s!"[demo] runNatFunFrag wpp_add1({sample}) = {reprStr outMiniC}"

    have _certified : NatFunSpecFrag funName paramName t :=
      add1Term_spec funName paramName

    let ok₁ ← writeFileSafely
      "artifacts/compiler/ir/wpp_add1.lambdair.txt"
      (termToString t ++ "\n")

    let ok₂ ← writeFileSafely
      "artifacts/compiler/ir/wpp_add1.minic.txt"
      (reprStr compiledMiniC ++ "\n")

    let cProgram :=
      "#include <stdio.h>\n\n" ++ HeytingLean.C.Emit.funDef cFun ++ driverC funName sample
    let ok₃ ← writeFileSafely
      "artifacts/compiler/c/wpp_add1.c"
      cProgram

    if ok₁ && ok₂ && ok₃ then
      IO.println "[wolfram_bundle_demo] done"
      return (0 : UInt32)
    else
      IO.eprintln "[wolfram_bundle_demo] one or more artifact writes failed"
      return (2 : UInt32)
  catch e =>
    IO.eprintln s!"[wolfram_bundle_demo] error: {e}"
    return (1 : UInt32)

end WolframBundleDemo

end CLI
end HeytingLean

/-- Expose entry point for the Lake executable target. -/
def main (args : List String) : IO UInt32 :=
  HeytingLean.CLI.WolframBundleDemo.main args
