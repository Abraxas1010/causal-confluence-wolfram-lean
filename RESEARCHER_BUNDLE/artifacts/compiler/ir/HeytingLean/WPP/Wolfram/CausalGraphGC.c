// Lean compiler output
// Module: HeytingLean.WPP.Wolfram.CausalGraphGC
// Imports: Init Mathlib.Data.Multiset.Fold HeytingLean.WPP.Wolfram.CausalGraph
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
lean_object* l_HeytingLean_WPP_Wolfram_System_Event_output___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_causalGraphGCOf(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* l_HeytingLean_WPP_Wolfram_System_Event_input___redArg(lean_object*, lean_object*);
lean_object* l_Multiset_map___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1(uint8_t, uint8_t);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0(lean_object*, lean_object*, lean_object*);
lean_object* l_List_filterTR_loop___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_List_hasDecEq___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_causalGraphGCOf___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_foldrTR___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_List_get___redArg(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Multiset_decidableMem___redArg(lean_object*, lean_object*, lean_object*);
uint8_t l_instDecidableNot___redArg(uint8_t);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_finRange(lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; 
x_4 = l_List_hasDecEq___redArg(x_1, x_2, x_3);
return x_4;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; uint8_t x_8; uint8_t x_9; 
x_7 = l_HeytingLean_WPP_Wolfram_System_Event_input___redArg(x_1, x_2);
lean_inc(x_6);
x_8 = l_Multiset_decidableMem___redArg(x_3, x_6, x_7);
x_9 = l_instDecidableNot___redArg(x_8);
if (x_9 == 0)
{
lean_dec(x_6);
lean_dec(x_5);
lean_dec_ref(x_4);
return x_9;
}
else
{
uint8_t x_10; 
x_10 = l_Multiset_decidableMem___redArg(x_4, x_6, x_5);
return x_10;
}
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1(uint8_t x_1, uint8_t x_2) {
_start:
{
if (x_1 == 0)
{
return x_2;
}
else
{
return x_1;
}
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; uint8_t x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; 
x_5 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0___boxed), 3, 1);
lean_closure_set(x_5, 0, x_2);
lean_inc_ref(x_5);
lean_inc_ref(x_3);
lean_inc_ref(x_1);
x_6 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2___boxed), 6, 5);
lean_closure_set(x_6, 0, x_1);
lean_closure_set(x_6, 1, x_3);
lean_closure_set(x_6, 2, x_5);
lean_closure_set(x_6, 3, x_5);
lean_closure_set(x_6, 4, x_4);
x_7 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1___boxed), 2, 0);
x_8 = 0;
x_9 = l_HeytingLean_WPP_Wolfram_System_Event_output___redArg(x_1, x_3);
lean_dec_ref(x_1);
x_10 = l_Multiset_map___redArg(x_6, x_9);
x_11 = lean_box(x_8);
x_12 = l_List_foldrTR___redArg(x_7, x_11, x_10);
return x_12;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_Event_observableB(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; uint8_t x_8; 
x_7 = l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg(x_3, x_4, x_5, x_6);
x_8 = lean_unbox(x_7);
lean_dec(x_7);
return x_8;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__0(x_1, x_2, x_3);
x_5 = lean_box(x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; lean_object* x_8; 
x_7 = l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__2(x_1, x_2, x_3, x_4, x_5, x_6);
lean_dec_ref(x_1);
x_8 = lean_box(x_7);
return x_8;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; uint8_t x_4; uint8_t x_5; lean_object* x_6; 
x_3 = lean_unbox(x_1);
x_4 = lean_unbox(x_2);
x_5 = l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg___lam__1(x_3, x_4);
x_6 = lean_box(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_Event_observableB___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
uint8_t x_7; lean_object* x_8; 
x_7 = l_HeytingLean_WPP_Wolfram_System_Event_observableB(x_1, x_2, x_3, x_4, x_5, x_6);
x_8 = lean_box(x_7);
return x_8;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = l_List_get___redArg(x_1, x_5);
x_7 = l_HeytingLean_WPP_Wolfram_System_Event_observableB___redArg(x_2, x_3, x_6, x_4);
x_8 = lean_unbox(x_7);
return x_8;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
lean_inc(x_3);
x_5 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0___boxed), 5, 4);
lean_closure_set(x_5, 0, x_3);
lean_closure_set(x_5, 1, x_1);
lean_closure_set(x_5, 2, x_2);
lean_closure_set(x_5, 3, x_4);
x_6 = l_List_lengthTR___redArg(x_3);
lean_dec(x_3);
x_7 = l_List_finRange(x_6);
x_8 = lean_box(0);
x_9 = l_List_filterTR_loop___redArg(x_5, x_7, x_8);
return x_9;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg(x_3, x_4, x_5, x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
uint8_t x_6; lean_object* x_7; 
x_6 = l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg___lam__0(x_1, x_2, x_3, x_4, x_5);
lean_dec(x_1);
x_7 = lean_box(x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_causalGraphGCOf___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; 
x_5 = l_HeytingLean_WPP_Wolfram_System_observableIdxs___redArg(x_1, x_2, x_3, x_4);
x_6 = l_List_lengthTR___redArg(x_5);
lean_dec(x_5);
return x_6;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_System_causalGraphGCOf(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_HeytingLean_WPP_Wolfram_System_causalGraphGCOf___redArg(x_3, x_4, x_5, x_6);
return x_7;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Multiset_Fold(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_WPP_Wolfram_CausalGraph(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_WPP_Wolfram_CausalGraphGC(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Multiset_Fold(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_WPP_Wolfram_CausalGraph(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
