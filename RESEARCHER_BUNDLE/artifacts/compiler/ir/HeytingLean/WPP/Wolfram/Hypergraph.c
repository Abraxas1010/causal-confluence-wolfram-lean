// Lean compiler output
// Module: HeytingLean.WPP.Wolfram.Hypergraph
// Imports: Init Mathlib.Data.List.Basic Mathlib.Data.Multiset.MapFold
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
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Expr_rename(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Expr_rename___redArg(lean_object*, lean_object*);
lean_object* l_Multiset_map___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_HGraph_rename___redArg(lean_object*, lean_object*);
lean_object* l_List_mapTR_loop___at___List_mapAsyncChunked_spec__0___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_HGraph_rename(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Expr_rename___redArg(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_box(0);
x_4 = l_List_mapTR_loop___at___List_mapAsyncChunked_spec__0___redArg(x_1, x_2, x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Expr_rename(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_WPP_Wolfram_Expr_rename___redArg(x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_HGraph_rename___redArg(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Expr_rename), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, lean_box(0));
lean_closure_set(x_3, 2, x_1);
x_4 = l_Multiset_map___redArg(x_3, x_2);
return x_4;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_HGraph_rename(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_WPP_Wolfram_HGraph_rename___redArg(x_3, x_4);
return x_5;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_List_Basic(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Multiset_MapFold(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_WPP_Wolfram_Hypergraph(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_List_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Multiset_MapFold(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
