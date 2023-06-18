#include "data/sprites/atomic.h"

#include "macros.h"

const s16 sAtomicIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -2, -2, -1, -1, -1, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sAtomicIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
    0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1,
    -1, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sAtomicGfx[752] = INCBIN_U32("data/sprites/Atomic.gfx.lz");
const u16 sAtomicPAL[64] = INCBIN_U16("data/sprites/Atomic.pal");

const u16 sAtomicOAM_Idle_Frame0[13] = {
    0x4,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x292,
    0xfc, 0x4, OBJ_SPRITE_OAM | 0x291,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0x1, 0x1f7, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame1[10] = {
    0x3,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x293,
    0x0, 0x1, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sAtomicOAM_Idle_Frame2[13] = {
    0x4,
    0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fe, OBJ_SPRITE_OAM | 0x292,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame3[13] = {
    0x4,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfb, 0x1f5, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame4[13] = {
    0x4,
    0xfd, 0x1fe, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fa, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame5[13] = {
    0x4,
    0x1, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    0xf5, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x292,
    0xff, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x291
};

const u16 sAtomicOAM_Idle_Frame6[13] = {
    0x4,
    0xf4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x292,
    0xfc, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x291,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0x1, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame7[10] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x293,
    0x0, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sAtomicOAM_Idle_Frame8[13] = {
    0x4,
    0xfc, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x292,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf7, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame9[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfb, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame10[13] = {
    0x4,
    0xfd, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0xf8, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame11[13] = {
    0x4,
    0x1, 0x1f7, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    0xf5, 0x1ff, OBJ_SPRITE_OAM | 0x292,
    0xff, 0x2, OBJ_SPRITE_OAM | 0x291
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x20, 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame5[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame7[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x20, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame9[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame10[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1279
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1279
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame0[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1280
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame1[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1284
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame3[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1280
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame5[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1284
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame6[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1288
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame7[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x128c
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame9[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1288
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame10[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x128c
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame0[4] = {
    0x1,
    0x10, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x129a
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame1[4] = {
    0x1,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x129a
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame2[4] = {
    0x1,
    0x10, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame3[4] = {
    0x1,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame7[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame10[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_X_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12b5
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x12b5
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1290
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12dc
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1210
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x120c
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame4[13] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame5[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x129a,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x129a,
    0x11, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x129a,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x129a,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame6[25] = {
    0x8,
    0xdb, OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x12da,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x12da,
    0x15, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x12da,
    0x15, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x12da,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x120c
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame4[13] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame5[37] = {
    0xc,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d8, OBJ_SPRITE_OAM | 0x12b5,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x12b7,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, OBJ_SPRITE_OAM | 0x12b5,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x12b7
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame6[37] = {
    0xc,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x1279,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x12b9,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d0, OBJ_SPRITE_OAM | 0x12d6,
    0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x12d8,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1279,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x12b9,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, OBJ_SPRITE_OAM | 0x12d6,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, OBJ_SPRITE_OAM | 0x12d8
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1204
};

const u16 sAtomicElectricityOAM_Charging_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

const u16 sAtomicElectricityOAM_Charging_Frame1[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sAtomicElectricityOAM_Charging_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const u16 sAtomicElectricityOAM_Charging_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

const u16 sAtomicElectricityOAM_Charging_Frame5[4] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sAtomicElectricityOAM_Charging_Frame7[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const struct FrameData sAtomicOAM_Idle[13] = {
    sAtomicOAM_Idle_Frame0,
    0x8,
    sAtomicOAM_Idle_Frame1,
    0x8,
    sAtomicOAM_Idle_Frame2,
    0x8,
    sAtomicOAM_Idle_Frame3,
    0x8,
    sAtomicOAM_Idle_Frame4,
    0x8,
    sAtomicOAM_Idle_Frame5,
    0x8,
    sAtomicOAM_Idle_Frame6,
    0x8,
    sAtomicOAM_Idle_Frame7,
    0x8,
    sAtomicOAM_Idle_Frame8,
    0x8,
    sAtomicOAM_Idle_Frame9,
    0x8,
    sAtomicOAM_Idle_Frame10,
    0x8,
    sAtomicOAM_Idle_Frame11,
    0x8,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingVertical[13] = {
    sAtomicElectricityOAM_MovingVertical_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingVertical_Unused[5] = {
    sAtomicElectricityOAM_MovingVertical_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingDiagonal[13] = {
    sAtomicElectricityOAM_MovingDiagonal_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingDiagonal_Unused[5] = {
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingHorizontal[13] = {
    sAtomicElectricityOAM_MovingHorizontal_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingHorizontal_Unused[5] = {
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_ExplodingNonDiagonal[8] = {
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame3,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame4,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame5,
    0x4,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame6,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_ExplodingDiagonal[8] = {
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame3,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame4,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame5,
    0x4,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame6,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_Charging[12] = {
    sAtomicElectricityOAM_Charging_Frame0,
    0x3,
    sAtomicElectricityOAM_Charging_Frame1,
    0x3,
    sAtomicElectricityOAM_Charging_Frame2,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame4,
    0x3,
    sAtomicElectricityOAM_Charging_Frame5,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame7,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame0,
    0x3,
    sAtomicElectricityOAM_Charging_Frame4,
    0x3,
    NULL,
    0x0
};
