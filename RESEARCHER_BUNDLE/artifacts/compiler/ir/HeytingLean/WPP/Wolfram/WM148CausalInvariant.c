// Lean compiler output
// Module: HeytingLean.WPP.Wolfram.WM148CausalInvariant
// Imports: Init Mathlib.Data.Multiset.AddSub HeytingLean.WPP.Wolfram.CausalInvarianceSingleLHS HeytingLean.WPP.Wolfram.WM148
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
LEAN_EXPORT lean_object* l___private_HeytingLean_WPP_Wolfram_WM148CausalInvariant_0__HeytingLean_WPP_Wolfram_WM148_fresh0___boxed(lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_WPP_Wolfram_WM148CausalInvariant_0__HeytingLean_WPP_Wolfram_WM148_fresh0(lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_WPP_Wolfram_WM148CausalInvariant_0__HeytingLean_WPP_Wolfram_WM148_fresh0(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_unsigned_to_nat(0u);
return x_2;
}
}
LEAN_EXPORT lean_object* l___private_HeytingLean_WPP_Wolfram_WM148CausalInvariant_0__HeytingLean_WPP_Wolfram_WM148_fresh0___boxed(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = l___private_HeytingLean_WPP_Wolfram_WM148CausalInvariant_0__HeytingLean_WPP_Wolfram_WM148_fresh0(x_1);
lean_dec_ref(x_1);
return x_2;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Multiset_AddSub(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_WPP_Wolfram_CausalInvarianceSingleLHS(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_WPP_Wolfram_WM148(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_WPP_Wolfram_WM148CausalInvariant(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Multiset_AddSub(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_WPP_Wolfram_CausalInvarianceSingleLHS(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_WPP_Wolfram_WM148(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
