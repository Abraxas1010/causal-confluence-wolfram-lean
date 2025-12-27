// Lean compiler output
// Module: HeytingLean.LambdaIR.Semantics
// Imports: Init HeytingLean.Core.SemanticsBase HeytingLean.LambdaIR.Syntax
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
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__4___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_HeytingLean_LambdaIR_eval___lam__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___boxed(lean_object**);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg___boxed(lean_object**);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_int_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_HeytingLean_Core_extendEnv___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__3___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_Core_extendEnv___redArg(x_1, x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_HeytingLean_Core_extendEnv___redArg(x_3, x_4, x_5, x_6);
return x_7;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___redArg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_LambdaIR_extendEnv___redArg(x_1, x_2, x_3, x_4);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_extendEnv___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; 
x_7 = l_HeytingLean_LambdaIR_extendEnv(x_1, x_2, x_3, x_4, x_5, x_6);
lean_dec(x_4);
lean_dec(x_2);
lean_dec(x_1);
return x_7;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__0(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_Core_extendEnv___redArg(x_1, x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6) {
_start:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_7 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__0___boxed), 4, 2);
lean_closure_set(x_7, 0, x_1);
lean_closure_set(x_7, 1, x_6);
x_8 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_8, 0, x_2);
lean_ctor_set(x_8, 1, x_3);
x_9 = l_HeytingLean_LambdaIR_eval(x_8, x_4, x_5, x_7);
return x_9;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__2(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_Core_extendEnv___redArg(x_1, x_2, x_3, x_4);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__4(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_nat_add(x_1, x_2);
return x_3;
}
}
LEAN_EXPORT uint8_t l_HeytingLean_LambdaIR_eval___lam__3(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; uint8_t x_5; 
x_3 = lean_nat_to_int(x_1);
x_4 = lean_nat_to_int(x_2);
x_5 = lean_int_dec_eq(x_3, x_4);
lean_dec(x_4);
lean_dec(x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
switch (lean_obj_tag(x_3)) {
case 0:
{
lean_object* x_5; lean_object* x_6; 
lean_dec(x_1);
x_5 = lean_ctor_get(x_3, 2);
lean_inc_ref(x_5);
lean_dec_ref(x_3);
x_6 = lean_apply_2(x_4, x_2, x_5);
return x_6;
}
case 1:
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; 
lean_dec(x_2);
x_7 = lean_ctor_get(x_3, 0);
lean_inc(x_7);
x_8 = lean_ctor_get(x_3, 2);
lean_inc(x_8);
x_9 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_9);
lean_dec_ref(x_3);
x_10 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__1), 6, 5);
lean_closure_set(x_10, 0, x_4);
lean_closure_set(x_10, 1, x_7);
lean_closure_set(x_10, 2, x_1);
lean_closure_set(x_10, 3, x_8);
lean_closure_set(x_10, 4, x_9);
return x_10;
}
case 2:
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; lean_object* x_15; lean_object* x_16; lean_object* x_17; 
x_11 = lean_ctor_get(x_3, 1);
lean_inc(x_11);
x_12 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_12);
x_13 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_13);
lean_dec_ref(x_3);
lean_inc(x_11);
x_14 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_14, 0, x_11);
lean_ctor_set(x_14, 1, x_2);
lean_inc(x_4);
lean_inc(x_1);
x_15 = l_HeytingLean_LambdaIR_eval(x_1, x_11, x_13, x_4);
x_16 = l_HeytingLean_LambdaIR_eval(x_1, x_14, x_12, x_4);
x_17 = lean_apply_1(x_16, x_15);
return x_17;
}
case 3:
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; 
lean_dec(x_2);
x_18 = lean_ctor_get(x_3, 1);
lean_inc(x_18);
x_19 = lean_ctor_get(x_3, 2);
lean_inc(x_19);
x_20 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_20);
x_21 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_21);
lean_dec_ref(x_3);
lean_inc(x_4);
lean_inc(x_1);
x_22 = l_HeytingLean_LambdaIR_eval(x_1, x_18, x_20, x_4);
x_23 = l_HeytingLean_LambdaIR_eval(x_1, x_19, x_21, x_4);
x_24 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_24, 0, x_22);
lean_ctor_set(x_24, 1, x_23);
return x_24;
}
case 4:
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; lean_object* x_29; 
x_25 = lean_ctor_get(x_3, 2);
lean_inc(x_25);
x_26 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_26);
lean_dec_ref(x_3);
x_27 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_27, 0, x_2);
lean_ctor_set(x_27, 1, x_25);
x_28 = l_HeytingLean_LambdaIR_eval(x_1, x_27, x_26, x_4);
x_29 = lean_ctor_get(x_28, 0);
lean_inc(x_29);
lean_dec(x_28);
return x_29;
}
case 5:
{
lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; 
x_30 = lean_ctor_get(x_3, 1);
lean_inc(x_30);
x_31 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_31);
lean_dec_ref(x_3);
x_32 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_2);
x_33 = l_HeytingLean_LambdaIR_eval(x_1, x_32, x_31, x_4);
x_34 = lean_ctor_get(x_33, 1);
lean_inc(x_34);
lean_dec(x_33);
return x_34;
}
case 6:
{
lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; 
lean_dec(x_2);
x_35 = lean_ctor_get(x_3, 1);
lean_inc(x_35);
x_36 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_36);
lean_dec_ref(x_3);
x_37 = l_HeytingLean_LambdaIR_eval(x_1, x_35, x_36, x_4);
x_38 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_38, 0, x_37);
return x_38;
}
case 7:
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; 
lean_dec(x_2);
x_39 = lean_ctor_get(x_3, 1);
lean_inc(x_39);
x_40 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_40);
lean_dec_ref(x_3);
x_41 = l_HeytingLean_LambdaIR_eval(x_1, x_39, x_40, x_4);
x_42 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_42, 0, x_41);
return x_42;
}
case 8:
{
lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; 
x_43 = lean_ctor_get(x_3, 1);
lean_inc(x_43);
x_44 = lean_ctor_get(x_3, 2);
lean_inc(x_44);
x_45 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_45);
x_46 = lean_ctor_get(x_3, 5);
lean_inc_ref(x_46);
x_47 = lean_ctor_get(x_3, 6);
lean_inc_ref(x_47);
lean_dec_ref(x_3);
lean_inc(x_44);
lean_inc(x_43);
x_48 = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(x_48, 0, x_43);
lean_ctor_set(x_48, 1, x_44);
lean_inc(x_4);
lean_inc(x_1);
x_49 = l_HeytingLean_LambdaIR_eval(x_1, x_48, x_45, x_4);
if (lean_obj_tag(x_49) == 0)
{
lean_object* x_50; lean_object* x_51; lean_object* x_52; 
lean_dec_ref(x_47);
lean_dec(x_44);
x_50 = lean_ctor_get(x_49, 0);
lean_inc(x_50);
lean_dec_ref(x_49);
x_51 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__2___boxed), 4, 2);
lean_closure_set(x_51, 0, x_4);
lean_closure_set(x_51, 1, x_50);
x_52 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_52, 0, x_43);
lean_ctor_set(x_52, 1, x_1);
x_1 = x_52;
x_3 = x_46;
x_4 = x_51;
goto _start;
}
else
{
lean_object* x_54; lean_object* x_55; lean_object* x_56; 
lean_dec_ref(x_46);
lean_dec(x_43);
x_54 = lean_ctor_get(x_49, 0);
lean_inc(x_54);
lean_dec_ref(x_49);
x_55 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__2___boxed), 4, 2);
lean_closure_set(x_55, 0, x_4);
lean_closure_set(x_55, 1, x_54);
x_56 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_56, 0, x_44);
lean_ctor_set(x_56, 1, x_1);
x_1 = x_56;
x_3 = x_47;
x_4 = x_55;
goto _start;
}
}
case 9:
{
lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; uint8_t x_63; 
x_58 = lean_ctor_get(x_3, 2);
lean_inc_ref(x_58);
x_59 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_59);
x_60 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_60);
lean_dec_ref(x_3);
x_61 = lean_box(1);
lean_inc(x_4);
lean_inc(x_1);
x_62 = l_HeytingLean_LambdaIR_eval(x_1, x_61, x_58, x_4);
x_63 = lean_unbox(x_62);
lean_dec(x_62);
if (x_63 == 0)
{
lean_dec_ref(x_59);
x_3 = x_60;
goto _start;
}
else
{
lean_dec_ref(x_60);
x_3 = x_59;
goto _start;
}
}
case 10:
{
lean_object* x_66; 
lean_dec(x_4);
lean_dec(x_2);
lean_dec(x_1);
x_66 = lean_ctor_get(x_3, 1);
lean_inc(x_66);
lean_dec_ref(x_3);
return x_66;
}
case 11:
{
uint8_t x_67; lean_object* x_68; 
lean_dec(x_4);
lean_dec(x_2);
lean_dec(x_1);
x_67 = lean_ctor_get_uint8(x_3, sizeof(void*)*1);
lean_dec_ref(x_3);
x_68 = lean_box(x_67);
return x_68;
}
case 12:
{
lean_object* x_69; 
lean_dec(x_4);
lean_dec_ref(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_69 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__4___boxed), 2, 0);
return x_69;
}
default: 
{
lean_object* x_70; 
lean_dec(x_4);
lean_dec_ref(x_3);
lean_dec(x_2);
lean_dec(x_1);
x_70 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_eval___lam__3___boxed), 2, 0);
return x_70;
}
}
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__0___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_LambdaIR_eval___lam__0(x_1, x_2, x_3, x_4);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__2___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_HeytingLean_LambdaIR_eval___lam__2(x_1, x_2, x_3, x_4);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__4___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_HeytingLean_LambdaIR_eval___lam__4(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_eval___lam__3___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
uint8_t x_3; lean_object* x_4; 
x_3 = l_HeytingLean_LambdaIR_eval___lam__3(x_1, x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12, lean_object* x_13, lean_object* x_14, lean_object* x_15, lean_object* x_16, lean_object* x_17, lean_object* x_18) {
_start:
{
switch (lean_obj_tag(x_3)) {
case 0:
{
lean_object* x_19; lean_object* x_20; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
x_19 = lean_ctor_get(x_3, 2);
lean_inc_ref(x_19);
lean_dec_ref(x_3);
x_20 = lean_apply_4(x_5, x_1, x_2, x_19, x_4);
return x_20;
}
case 1:
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
lean_dec(x_2);
x_21 = lean_ctor_get(x_3, 0);
lean_inc(x_21);
x_22 = lean_ctor_get(x_3, 2);
lean_inc(x_22);
x_23 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_23);
lean_dec_ref(x_3);
x_24 = lean_apply_5(x_6, x_1, x_21, x_22, x_23, x_4);
return x_24;
}
case 2:
{
lean_object* x_25; lean_object* x_26; lean_object* x_27; lean_object* x_28; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_6);
lean_dec(x_5);
x_25 = lean_ctor_get(x_3, 1);
lean_inc(x_25);
x_26 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_26);
x_27 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_27);
lean_dec_ref(x_3);
x_28 = lean_apply_6(x_7, x_1, x_2, x_25, x_26, x_27, x_4);
return x_28;
}
case 3:
{
lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_2);
x_29 = lean_ctor_get(x_3, 1);
lean_inc(x_29);
x_30 = lean_ctor_get(x_3, 2);
lean_inc(x_30);
x_31 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_31);
x_32 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_32);
lean_dec_ref(x_3);
x_33 = lean_apply_6(x_8, x_1, x_29, x_30, x_31, x_32, x_4);
return x_33;
}
case 4:
{
lean_object* x_34; lean_object* x_35; lean_object* x_36; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_34 = lean_ctor_get(x_3, 2);
lean_inc(x_34);
x_35 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_35);
lean_dec_ref(x_3);
x_36 = lean_apply_5(x_9, x_1, x_2, x_34, x_35, x_4);
return x_36;
}
case 5:
{
lean_object* x_37; lean_object* x_38; lean_object* x_39; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_37 = lean_ctor_get(x_3, 1);
lean_inc(x_37);
x_38 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_38);
lean_dec_ref(x_3);
x_39 = lean_apply_5(x_10, x_1, x_2, x_37, x_38, x_4);
return x_39;
}
case 6:
{
lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_2);
x_40 = lean_ctor_get(x_3, 1);
lean_inc(x_40);
x_41 = lean_ctor_get(x_3, 2);
lean_inc(x_41);
x_42 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_42);
lean_dec_ref(x_3);
x_43 = lean_apply_5(x_11, x_1, x_40, x_41, x_42, x_4);
return x_43;
}
case 7:
{
lean_object* x_44; lean_object* x_45; lean_object* x_46; lean_object* x_47; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_2);
x_44 = lean_ctor_get(x_3, 1);
lean_inc(x_44);
x_45 = lean_ctor_get(x_3, 2);
lean_inc(x_45);
x_46 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_46);
lean_dec_ref(x_3);
x_47 = lean_apply_5(x_12, x_1, x_44, x_45, x_46, x_4);
return x_47;
}
case 8:
{
lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; lean_object* x_52; lean_object* x_53; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_48 = lean_ctor_get(x_3, 1);
lean_inc(x_48);
x_49 = lean_ctor_get(x_3, 2);
lean_inc(x_49);
x_50 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_50);
x_51 = lean_ctor_get(x_3, 5);
lean_inc_ref(x_51);
x_52 = lean_ctor_get(x_3, 6);
lean_inc_ref(x_52);
lean_dec_ref(x_3);
x_53 = lean_apply_8(x_13, x_1, x_2, x_48, x_49, x_50, x_51, x_52, x_4);
return x_53;
}
case 9:
{
lean_object* x_54; lean_object* x_55; lean_object* x_56; lean_object* x_57; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_54 = lean_ctor_get(x_3, 2);
lean_inc_ref(x_54);
x_55 = lean_ctor_get(x_3, 3);
lean_inc_ref(x_55);
x_56 = lean_ctor_get(x_3, 4);
lean_inc_ref(x_56);
lean_dec_ref(x_3);
x_57 = lean_apply_6(x_14, x_1, x_2, x_54, x_55, x_56, x_4);
return x_57;
}
case 10:
{
lean_object* x_58; lean_object* x_59; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_2);
x_58 = lean_ctor_get(x_3, 1);
lean_inc(x_58);
lean_dec_ref(x_3);
x_59 = lean_apply_3(x_15, x_1, x_58, x_4);
return x_59;
}
case 11:
{
uint8_t x_60; lean_object* x_61; lean_object* x_62; 
lean_dec(x_18);
lean_dec(x_17);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec(x_2);
x_60 = lean_ctor_get_uint8(x_3, sizeof(void*)*1);
lean_dec_ref(x_3);
x_61 = lean_box(x_60);
x_62 = lean_apply_3(x_16, x_1, x_61, x_4);
return x_62;
}
case 12:
{
lean_object* x_63; 
lean_dec(x_18);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec_ref(x_3);
lean_dec(x_2);
x_63 = lean_apply_2(x_17, x_1, x_4);
return x_63;
}
default: 
{
lean_object* x_64; 
lean_dec(x_17);
lean_dec(x_16);
lean_dec(x_15);
lean_dec(x_14);
lean_dec(x_13);
lean_dec(x_12);
lean_dec(x_11);
lean_dec(x_10);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
lean_dec_ref(x_3);
lean_dec(x_2);
x_64 = lean_apply_2(x_18, x_1, x_4);
return x_64;
}
}
}
}
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5, lean_object* x_6, lean_object* x_7, lean_object* x_8, lean_object* x_9, lean_object* x_10, lean_object* x_11, lean_object* x_12, lean_object* x_13, lean_object* x_14, lean_object* x_15, lean_object* x_16, lean_object* x_17, lean_object* x_18, lean_object* x_19) {
_start:
{
lean_object* x_20; 
x_20 = l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg(x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10, x_11, x_12, x_13, x_14, x_15, x_16, x_17, x_18, x_19);
return x_20;
}
}
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg___boxed(lean_object** _args) {
lean_object* x_1 = _args[0];
lean_object* x_2 = _args[1];
lean_object* x_3 = _args[2];
lean_object* x_4 = _args[3];
lean_object* x_5 = _args[4];
lean_object* x_6 = _args[5];
lean_object* x_7 = _args[6];
lean_object* x_8 = _args[7];
lean_object* x_9 = _args[8];
lean_object* x_10 = _args[9];
lean_object* x_11 = _args[10];
lean_object* x_12 = _args[11];
lean_object* x_13 = _args[12];
lean_object* x_14 = _args[13];
lean_object* x_15 = _args[14];
lean_object* x_16 = _args[15];
lean_object* x_17 = _args[16];
lean_object* x_18 = _args[17];
_start:
{
lean_object* x_19; 
x_19 = l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___redArg(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10, x_11, x_12, x_13, x_14, x_15, x_16, x_17, x_18);
return x_19;
}
}
LEAN_EXPORT lean_object* l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter___boxed(lean_object** _args) {
lean_object* x_1 = _args[0];
lean_object* x_2 = _args[1];
lean_object* x_3 = _args[2];
lean_object* x_4 = _args[3];
lean_object* x_5 = _args[4];
lean_object* x_6 = _args[5];
lean_object* x_7 = _args[6];
lean_object* x_8 = _args[7];
lean_object* x_9 = _args[8];
lean_object* x_10 = _args[9];
lean_object* x_11 = _args[10];
lean_object* x_12 = _args[11];
lean_object* x_13 = _args[12];
lean_object* x_14 = _args[13];
lean_object* x_15 = _args[14];
lean_object* x_16 = _args[15];
lean_object* x_17 = _args[16];
lean_object* x_18 = _args[17];
lean_object* x_19 = _args[18];
_start:
{
lean_object* x_20; 
x_20 = l___private_HeytingLean_LambdaIR_Semantics_0__HeytingLean_LambdaIR_eval_match__5_splitter(x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10, x_11, x_12, x_13, x_14, x_15, x_16, x_17, x_18, x_19);
return x_20;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed___lam__0(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_internal_panic_unreachable();
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_alloc_closure((void*)(l_HeytingLean_LambdaIR_evalClosed___lam__0___boxed), 2, 0);
x_4 = lean_box(0);
x_5 = l_HeytingLean_LambdaIR_eval(x_4, x_1, x_2, x_3);
return x_5;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_LambdaIR_evalClosed___lam__0___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_HeytingLean_LambdaIR_evalClosed___lam__0(x_1, x_2);
lean_dec_ref(x_2);
lean_dec(x_1);
return x_3;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_Core_SemanticsBase(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_LambdaIR_Syntax(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_LambdaIR_Semantics(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_Core_SemanticsBase(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_LambdaIR_Syntax(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
