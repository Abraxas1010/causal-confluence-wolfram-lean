// Lean compiler output
// Module: HeytingLean.WPP.Wolfram.ConfluenceCausalInvariance
// Imports: Init Mathlib.Data.Fin.Basic Mathlib.Data.Multiset.ZeroCons HeytingLean.WPP.Wolfram.CausalGraph HeytingLean.WPP.Wolfram.ConfluenceTheory
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
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id;
lean_object* l_Fin_cases___redArg(lean_object*, lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_instDecidableEqV___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2;
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_instDecidableEqV(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___boxed(lean_object*, lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8;
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0;
lean_object* lean_nat_mod(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0;
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_instDecidableEqV(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_instDecidableEqV___boxed(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_s0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0___boxed(lean_object*, lean_object*);
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys;
static lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1;
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_inc(x_1);
return x_1;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0___boxed), 2, 1);
lean_closure_set(x_4, 0, x_2);
x_5 = l_Fin_cases___redArg(x_1, x_4, x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg(x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___lam__0(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___redArg(x_1, x_2, x_3);
lean_dec(x_3);
lean_dec(x_1);
return x_4;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2(x_1, x_2, x_3, x_4);
lean_dec(x_4);
lean_dec(x_2);
return x_5;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_nat_mod(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(2u);
x_2 = lean_unsigned_to_nat(1u);
x_3 = lean_nat_mod(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_nat_mod(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = lean_unsigned_to_nat(1u);
x_3 = lean_nat_mod(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_unsigned_to_nat(3u);
x_2 = lean_unsigned_to_nat(2u);
x_3 = lean_nat_mod(x_2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1;
return x_1;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_instDecidableEqV(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lean_nat_dec_eq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_instDecidableEqV___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_instDecidableEqV(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
lean_closure_set(x_3, 2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0;
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
lean_closure_set(x_3, 2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2;
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
lean_closure_set(x_3, 2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s0() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys;
x_2 = lean_ctor_get(x_1, 1);
lean_inc(x_2);
return x_2;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = lean_box(0);
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0;
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1;
return x_1;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_instDecidableEqV(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; 
x_3 = lean_nat_dec_eq(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_instDecidableEqV___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_instDecidableEqV(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
x_4 = lean_box(x_3);
return x_4;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0;
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
lean_closure_set(x_3, 2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2;
x_3 = lean_alloc_closure((void*)(l_HeytingLean_WPP_Wolfram_Counterexamples_sigma2___boxed), 4, 3);
lean_closure_set(x_3, 0, lean_box(0));
lean_closure_set(x_3, 1, x_2);
lean_closure_set(x_3, 2, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0;
x_2 = lean_unsigned_to_nat(0u);
x_3 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_s0() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys;
x_2 = lean_ctor_get(x_1, 1);
lean_inc(x_2);
return x_2;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0;
return x_1;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7;
x_2 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1;
x_3 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_3, 0, x_2);
lean_ctor_set(x_3, 1, x_1);
return x_3;
}
}
static lean_object* _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2() {
_start:
{
lean_object* x_1; 
x_1 = l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0;
return x_1;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Fin_Basic(uint8_t builtin, lean_object*);
lean_object* initialize_Mathlib_Data_Multiset_ZeroCons(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_WPP_Wolfram_CausalGraph(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_WPP_Wolfram_ConfluenceTheory(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_WPP_Wolfram_ConfluenceCausalInvariance(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Fin_Basic(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Mathlib_Data_Multiset_ZeroCons(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_WPP_Wolfram_CausalGraph(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_WPP_Wolfram_ConfluenceTheory(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__2);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__3);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__4);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__5);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__6);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__7);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__8);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule___closed__9);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_rule);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__2);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__3);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__4);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__5);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__6);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__7);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__8);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__9);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__10);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__11);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init___closed__12);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_init);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_sys);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e12);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e13);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_e23);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE1_s2);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__2);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__3);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule___closed__4);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_rule);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_init);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_sys);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__id);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap___closed__1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_e__swap);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_s0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_s0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_s0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf1);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2___closed__0);
l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2 = _init_l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2();
lean_mark_persistent(l_HeytingLean_WPP_Wolfram_Counterexamples_CE2_nf2);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
