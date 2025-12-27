// Lean compiler output
// Module: HeytingLean.MiniC.ToC
// Imports: Init HeytingLean.MiniC.Syntax HeytingLean.C.Syntax
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
static lean_object* l_HeytingLean_MiniC_ToC_compileExpr___closed__1;
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileStmt(lean_object*);
static lean_object* l_HeytingLean_MiniC_ToC_compileExpr___closed__3;
lean_object* lean_nat_to_int(lean_object*);
static lean_object* l_HeytingLean_MiniC_ToC_compileExpr___closed__0;
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileExpr(lean_object*);
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileFun(lean_object*);
static lean_object* l_HeytingLean_MiniC_ToC_compileExpr___closed__2;
static lean_object* l_HeytingLean_MiniC_ToC_compileStmt___closed__0;
static lean_object* _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_HeytingLean_MiniC_ToC_compileExpr___closed__0;
x_2 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_HeytingLean_MiniC_ToC_compileExpr___closed__2;
x_2 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileExpr(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
switch (lean_obj_tag(x_1)) {
case 0:
{
uint8_t x_8; 
x_8 = !lean_is_exclusive(x_1);
if (x_8 == 0)
{
lean_ctor_set_tag(x_1, 1);
return x_1;
}
else
{
lean_object* x_9; lean_object* x_10; 
x_9 = lean_ctor_get(x_1, 0);
lean_inc(x_9);
lean_dec(x_1);
x_10 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_10, 0, x_9);
return x_10;
}
}
case 1:
{
uint8_t x_11; 
x_11 = !lean_is_exclusive(x_1);
if (x_11 == 0)
{
lean_ctor_set_tag(x_1, 0);
return x_1;
}
else
{
lean_object* x_12; lean_object* x_13; 
x_12 = lean_ctor_get(x_1, 0);
lean_inc(x_12);
lean_dec(x_1);
x_13 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_13, 0, x_12);
return x_13;
}
}
case 2:
{
uint8_t x_14; 
x_14 = lean_ctor_get_uint8(x_1, 0);
lean_dec_ref(x_1);
if (x_14 == 0)
{
lean_object* x_15; 
x_15 = l_HeytingLean_MiniC_ToC_compileExpr___closed__1;
return x_15;
}
else
{
lean_object* x_16; 
x_16 = l_HeytingLean_MiniC_ToC_compileExpr___closed__3;
return x_16;
}
}
case 3:
{
uint8_t x_17; 
x_17 = !lean_is_exclusive(x_1);
if (x_17 == 0)
{
lean_object* x_18; lean_object* x_19; lean_object* x_20; lean_object* x_21; 
x_18 = lean_ctor_get(x_1, 0);
x_19 = lean_ctor_get(x_1, 1);
x_20 = l_HeytingLean_MiniC_ToC_compileExpr(x_18);
x_21 = l_HeytingLean_MiniC_ToC_compileExpr(x_19);
lean_ctor_set_tag(x_1, 2);
lean_ctor_set(x_1, 1, x_21);
lean_ctor_set(x_1, 0, x_20);
return x_1;
}
else
{
lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_22 = lean_ctor_get(x_1, 0);
x_23 = lean_ctor_get(x_1, 1);
lean_inc(x_23);
lean_inc(x_22);
lean_dec(x_1);
x_24 = l_HeytingLean_MiniC_ToC_compileExpr(x_22);
x_25 = l_HeytingLean_MiniC_ToC_compileExpr(x_23);
x_26 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_26, 0, x_24);
lean_ctor_set(x_26, 1, x_25);
return x_26;
}
}
case 4:
{
uint8_t x_27; 
x_27 = !lean_is_exclusive(x_1);
if (x_27 == 0)
{
lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; 
x_28 = lean_ctor_get(x_1, 0);
x_29 = lean_ctor_get(x_1, 1);
x_30 = l_HeytingLean_MiniC_ToC_compileExpr(x_28);
x_31 = l_HeytingLean_MiniC_ToC_compileExpr(x_29);
lean_ctor_set_tag(x_1, 3);
lean_ctor_set(x_1, 1, x_31);
lean_ctor_set(x_1, 0, x_30);
return x_1;
}
else
{
lean_object* x_32; lean_object* x_33; lean_object* x_34; lean_object* x_35; lean_object* x_36; 
x_32 = lean_ctor_get(x_1, 0);
x_33 = lean_ctor_get(x_1, 1);
lean_inc(x_33);
lean_inc(x_32);
lean_dec(x_1);
x_34 = l_HeytingLean_MiniC_ToC_compileExpr(x_32);
x_35 = l_HeytingLean_MiniC_ToC_compileExpr(x_33);
x_36 = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(x_36, 0, x_34);
lean_ctor_set(x_36, 1, x_35);
return x_36;
}
}
case 6:
{
uint8_t x_37; 
x_37 = !lean_is_exclusive(x_1);
if (x_37 == 0)
{
lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; 
x_38 = lean_ctor_get(x_1, 0);
x_39 = lean_ctor_get(x_1, 1);
x_40 = l_HeytingLean_MiniC_ToC_compileExpr(x_38);
x_41 = l_HeytingLean_MiniC_ToC_compileExpr(x_39);
lean_ctor_set(x_1, 1, x_41);
lean_ctor_set(x_1, 0, x_40);
return x_1;
}
else
{
lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; lean_object* x_46; 
x_42 = lean_ctor_get(x_1, 0);
x_43 = lean_ctor_get(x_1, 1);
lean_inc(x_43);
lean_inc(x_42);
lean_dec(x_1);
x_44 = l_HeytingLean_MiniC_ToC_compileExpr(x_42);
x_45 = l_HeytingLean_MiniC_ToC_compileExpr(x_43);
x_46 = lean_alloc_ctor(6, 2, 0);
lean_ctor_set(x_46, 0, x_44);
lean_ctor_set(x_46, 1, x_45);
return x_46;
}
}
case 7:
{
uint8_t x_47; 
x_47 = !lean_is_exclusive(x_1);
if (x_47 == 0)
{
lean_object* x_48; lean_object* x_49; lean_object* x_50; lean_object* x_51; 
x_48 = lean_ctor_get(x_1, 0);
x_49 = lean_ctor_get(x_1, 1);
x_50 = l_HeytingLean_MiniC_ToC_compileExpr(x_48);
x_51 = l_HeytingLean_MiniC_ToC_compileExpr(x_49);
lean_ctor_set_tag(x_1, 5);
lean_ctor_set(x_1, 1, x_51);
lean_ctor_set(x_1, 0, x_50);
return x_1;
}
else
{
lean_object* x_52; lean_object* x_53; lean_object* x_54; lean_object* x_55; lean_object* x_56; 
x_52 = lean_ctor_get(x_1, 0);
x_53 = lean_ctor_get(x_1, 1);
lean_inc(x_53);
lean_inc(x_52);
lean_dec(x_1);
x_54 = l_HeytingLean_MiniC_ToC_compileExpr(x_52);
x_55 = l_HeytingLean_MiniC_ToC_compileExpr(x_53);
x_56 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_56, 0, x_54);
lean_ctor_set(x_56, 1, x_55);
return x_56;
}
}
case 8:
{
lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; 
x_57 = lean_ctor_get(x_1, 0);
lean_inc_ref(x_57);
lean_dec_ref(x_1);
x_58 = l_HeytingLean_MiniC_ToC_compileExpr(x_57);
x_59 = l_HeytingLean_MiniC_ToC_compileExpr___closed__1;
x_60 = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(x_60, 0, x_58);
lean_ctor_set(x_60, 1, x_59);
return x_60;
}
case 10:
{
uint8_t x_61; 
x_61 = !lean_is_exclusive(x_1);
if (x_61 == 0)
{
lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; lean_object* x_67; 
x_62 = lean_ctor_get(x_1, 0);
x_63 = lean_ctor_get(x_1, 1);
x_64 = l_HeytingLean_MiniC_ToC_compileExpr___closed__3;
x_65 = l_HeytingLean_MiniC_ToC_compileExpr(x_62);
x_66 = l_HeytingLean_MiniC_ToC_compileExpr(x_63);
lean_ctor_set_tag(x_1, 2);
lean_ctor_set(x_1, 1, x_66);
lean_ctor_set(x_1, 0, x_65);
x_67 = lean_alloc_ctor(6, 2, 0);
lean_ctor_set(x_67, 0, x_64);
lean_ctor_set(x_67, 1, x_1);
return x_67;
}
else
{
lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; lean_object* x_73; lean_object* x_74; 
x_68 = lean_ctor_get(x_1, 0);
x_69 = lean_ctor_get(x_1, 1);
lean_inc(x_69);
lean_inc(x_68);
lean_dec(x_1);
x_70 = l_HeytingLean_MiniC_ToC_compileExpr___closed__3;
x_71 = l_HeytingLean_MiniC_ToC_compileExpr(x_68);
x_72 = l_HeytingLean_MiniC_ToC_compileExpr(x_69);
x_73 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_73, 0, x_71);
lean_ctor_set(x_73, 1, x_72);
x_74 = lean_alloc_ctor(6, 2, 0);
lean_ctor_set(x_74, 0, x_70);
lean_ctor_set(x_74, 1, x_73);
return x_74;
}
}
default: 
{
lean_object* x_75; lean_object* x_76; 
x_75 = lean_ctor_get(x_1, 0);
lean_inc_ref(x_75);
x_76 = lean_ctor_get(x_1, 1);
lean_inc_ref(x_76);
lean_dec_ref(x_1);
x_2 = x_75;
x_3 = x_76;
goto block_7;
}
}
block_7:
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_4 = l_HeytingLean_MiniC_ToC_compileExpr(x_2);
x_5 = l_HeytingLean_MiniC_ToC_compileExpr(x_3);
x_6 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_6, 0, x_4);
lean_ctor_set(x_6, 1, x_5);
return x_6;
}
}
}
static lean_object* _init_l_HeytingLean_MiniC_ToC_compileStmt___closed__0() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_HeytingLean_MiniC_ToC_compileExpr___closed__1;
x_2 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileStmt(lean_object* x_1) {
_start:
{
switch (lean_obj_tag(x_1)) {
case 0:
{
lean_object* x_2; 
x_2 = l_HeytingLean_MiniC_ToC_compileStmt___closed__0;
return x_2;
}
case 1:
{
uint8_t x_3; 
x_3 = !lean_is_exclusive(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_1, 1);
x_5 = l_HeytingLean_MiniC_ToC_compileExpr(x_4);
lean_ctor_set(x_1, 1, x_5);
return x_1;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_6 = lean_ctor_get(x_1, 0);
x_7 = lean_ctor_get(x_1, 1);
lean_inc(x_7);
lean_inc(x_6);
lean_dec(x_1);
x_8 = l_HeytingLean_MiniC_ToC_compileExpr(x_7);
x_9 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_9, 0, x_6);
lean_ctor_set(x_9, 1, x_8);
return x_9;
}
}
case 2:
{
uint8_t x_10; 
x_10 = !lean_is_exclusive(x_1);
if (x_10 == 0)
{
lean_object* x_11; lean_object* x_12; lean_object* x_13; lean_object* x_14; 
x_11 = lean_ctor_get(x_1, 0);
x_12 = lean_ctor_get(x_1, 1);
x_13 = l_HeytingLean_MiniC_ToC_compileStmt(x_11);
x_14 = l_HeytingLean_MiniC_ToC_compileStmt(x_12);
lean_ctor_set(x_1, 1, x_14);
lean_ctor_set(x_1, 0, x_13);
return x_1;
}
else
{
lean_object* x_15; lean_object* x_16; lean_object* x_17; lean_object* x_18; lean_object* x_19; 
x_15 = lean_ctor_get(x_1, 0);
x_16 = lean_ctor_get(x_1, 1);
lean_inc(x_16);
lean_inc(x_15);
lean_dec(x_1);
x_17 = l_HeytingLean_MiniC_ToC_compileStmt(x_15);
x_18 = l_HeytingLean_MiniC_ToC_compileStmt(x_16);
x_19 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_19, 0, x_17);
lean_ctor_set(x_19, 1, x_18);
return x_19;
}
}
case 3:
{
uint8_t x_20; 
x_20 = !lean_is_exclusive(x_1);
if (x_20 == 0)
{
lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_21 = lean_ctor_get(x_1, 0);
x_22 = lean_ctor_get(x_1, 1);
x_23 = lean_ctor_get(x_1, 2);
x_24 = l_HeytingLean_MiniC_ToC_compileExpr(x_21);
x_25 = l_HeytingLean_MiniC_ToC_compileStmt(x_22);
x_26 = l_HeytingLean_MiniC_ToC_compileStmt(x_23);
lean_ctor_set(x_1, 2, x_26);
lean_ctor_set(x_1, 1, x_25);
lean_ctor_set(x_1, 0, x_24);
return x_1;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; lean_object* x_31; lean_object* x_32; lean_object* x_33; 
x_27 = lean_ctor_get(x_1, 0);
x_28 = lean_ctor_get(x_1, 1);
x_29 = lean_ctor_get(x_1, 2);
lean_inc(x_29);
lean_inc(x_28);
lean_inc(x_27);
lean_dec(x_1);
x_30 = l_HeytingLean_MiniC_ToC_compileExpr(x_27);
x_31 = l_HeytingLean_MiniC_ToC_compileStmt(x_28);
x_32 = l_HeytingLean_MiniC_ToC_compileStmt(x_29);
x_33 = lean_alloc_ctor(3, 3, 0);
lean_ctor_set(x_33, 0, x_30);
lean_ctor_set(x_33, 1, x_31);
lean_ctor_set(x_33, 2, x_32);
return x_33;
}
}
case 4:
{
uint8_t x_34; 
x_34 = !lean_is_exclusive(x_1);
if (x_34 == 0)
{
lean_object* x_35; lean_object* x_36; lean_object* x_37; lean_object* x_38; 
x_35 = lean_ctor_get(x_1, 0);
x_36 = lean_ctor_get(x_1, 1);
x_37 = l_HeytingLean_MiniC_ToC_compileExpr(x_35);
x_38 = l_HeytingLean_MiniC_ToC_compileStmt(x_36);
lean_ctor_set(x_1, 1, x_38);
lean_ctor_set(x_1, 0, x_37);
return x_1;
}
else
{
lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; 
x_39 = lean_ctor_get(x_1, 0);
x_40 = lean_ctor_get(x_1, 1);
lean_inc(x_40);
lean_inc(x_39);
lean_dec(x_1);
x_41 = l_HeytingLean_MiniC_ToC_compileExpr(x_39);
x_42 = l_HeytingLean_MiniC_ToC_compileStmt(x_40);
x_43 = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(x_43, 0, x_41);
lean_ctor_set(x_43, 1, x_42);
return x_43;
}
}
default: 
{
uint8_t x_44; 
x_44 = !lean_is_exclusive(x_1);
if (x_44 == 0)
{
lean_object* x_45; lean_object* x_46; 
x_45 = lean_ctor_get(x_1, 0);
x_46 = l_HeytingLean_MiniC_ToC_compileExpr(x_45);
lean_ctor_set_tag(x_1, 0);
lean_ctor_set(x_1, 0, x_46);
return x_1;
}
else
{
lean_object* x_47; lean_object* x_48; lean_object* x_49; 
x_47 = lean_ctor_get(x_1, 0);
lean_inc(x_47);
lean_dec(x_1);
x_48 = l_HeytingLean_MiniC_ToC_compileExpr(x_47);
x_49 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_49, 0, x_48);
return x_49;
}
}
}
}
}
LEAN_EXPORT lean_object* l_HeytingLean_MiniC_ToC_compileFun(lean_object* x_1) {
_start:
{
uint8_t x_2; 
x_2 = !lean_is_exclusive(x_1);
if (x_2 == 0)
{
lean_object* x_3; lean_object* x_4; 
x_3 = lean_ctor_get(x_1, 2);
x_4 = l_HeytingLean_MiniC_ToC_compileStmt(x_3);
lean_ctor_set(x_1, 2, x_4);
return x_1;
}
else
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_5 = lean_ctor_get(x_1, 0);
x_6 = lean_ctor_get(x_1, 1);
x_7 = lean_ctor_get(x_1, 2);
lean_inc(x_7);
lean_inc(x_6);
lean_inc(x_5);
lean_dec(x_1);
x_8 = l_HeytingLean_MiniC_ToC_compileStmt(x_7);
x_9 = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(x_9, 0, x_5);
lean_ctor_set(x_9, 1, x_6);
lean_ctor_set(x_9, 2, x_8);
return x_9;
}
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_MiniC_Syntax(uint8_t builtin, lean_object*);
lean_object* initialize_HeytingLean_C_Syntax(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_HeytingLean_MiniC_ToC(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_MiniC_Syntax(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_HeytingLean_C_Syntax(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_HeytingLean_MiniC_ToC_compileExpr___closed__0 = _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__0();
lean_mark_persistent(l_HeytingLean_MiniC_ToC_compileExpr___closed__0);
l_HeytingLean_MiniC_ToC_compileExpr___closed__1 = _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__1();
lean_mark_persistent(l_HeytingLean_MiniC_ToC_compileExpr___closed__1);
l_HeytingLean_MiniC_ToC_compileExpr___closed__2 = _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__2();
lean_mark_persistent(l_HeytingLean_MiniC_ToC_compileExpr___closed__2);
l_HeytingLean_MiniC_ToC_compileExpr___closed__3 = _init_l_HeytingLean_MiniC_ToC_compileExpr___closed__3();
lean_mark_persistent(l_HeytingLean_MiniC_ToC_compileExpr___closed__3);
l_HeytingLean_MiniC_ToC_compileStmt___closed__0 = _init_l_HeytingLean_MiniC_ToC_compileStmt___closed__0();
lean_mark_persistent(l_HeytingLean_MiniC_ToC_compileStmt___closed__0);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
