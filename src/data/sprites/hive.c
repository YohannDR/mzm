#include "data/sprites/hive.h"
#include "macros.h"

const s16 sMellowIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1,
    -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2,
    -1, -1, -1, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMellowIdleXVelocity[81] = {
    0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
    7, 7, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0,
    -1, -1, -2, -2, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7,
    -7, -7, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3,
    -2, -2, -1, -1, 0, 0, SHORT_MAX
};

const u32 sHiveGfx[1799] = INCBIN_U32("data/sprites/Hive.gfx.lz");
const u16 sHivePAL[96] = INCBIN_U16("data/sprites/Hive.pal");

const u16 sMellowOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sMellowOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sMellowOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellowOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sHiveOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1210
};

const u16 sHiveOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1214
};

const u16 sHiveOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sHiveOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x121c
};

const u16 sHiveRootsOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1245,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1246
};

const u16 sHiveRootsOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1246,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1247
};

const u16 sHiveRootsOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1247,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1245,
    0x17, 0x1f3, OBJ_SPRITE_OAM | 0x1245
};

const u16 sHiveOAM_Phase2_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x2208
};

const u16 sHiveOAM_Phase2_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x220c
};

const u16 sHiveOAM_Phase2_Frame2[7] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2308,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2310
};

const u16 sHiveOAM_Phase2_Frame3[7] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x230c,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2314
};

const u16 sHiveOAM_Phase3_Frame0[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3300,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Phase3_Frame1[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3304,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x331a
};

const u16 sHiveOAM_Phase3_Frame2[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3284,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Dying_Frame8[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x4242
};

const u16 sHiveOAM_Dying_Frame9[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4364,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4324,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    0xe5, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe2, 0x1fb, OBJ_SPRITE_OAM | 0x4243
};

const u16 sHiveOAM_Dying_Frame10[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4209,
    0xf0, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe8, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x4241
};

const u16 sHiveOAM_Dying_Frame11[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4280,
    0xa, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0x2, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xe7, 0x1fb, OBJ_SPRITE_OAM | 0x3243
};

const u16 sHiveOAM_Dying_Frame12[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x431c
};

const u16 sHiveOAM_Dying_Frame13[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x433c
};

const u16 sHiveOAM_Dying_Frame14[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x435c
};

const u16 sHiveOAM_Dying_Frame30[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x337c
};

const struct FrameData sMellowOAM_Idle[6] = {
    sMellowOAM_Idle_Frame0,
    0x3,
    sMellowOAM_Idle_Frame1,
    0x2,
    sMellowOAM_Idle_Frame2,
    0x2,
    sMellowOAM_Idle_Frame3,
    0x3,
    sMellowOAM_Idle_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMellowOAM_SamusDetected[6] = {
    sMellowOAM_Idle_Frame0,
    0x2,
    sMellowOAM_Idle_Frame1,
    0x1,
    sMellowOAM_Idle_Frame2,
    0x1,
    sMellowOAM_Idle_Frame3,
    0x2,
    sMellowOAM_Idle_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Idle[19] = {
    sHiveOAM_Idle_Frame0,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xB,
    sHiveOAM_Idle_Frame2,
    0xA,
    sHiveOAM_Idle_Frame3,
    0xB,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame0,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame3,
    0xC,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame0,
    0x8,
    sHiveOAM_Idle_Frame1,
    0x8,
    sHiveOAM_Idle_Frame2,
    0x6,
    sHiveOAM_Idle_Frame3,
    0x4,
    sHiveOAM_Idle_Frame2,
    0x8,
    sHiveOAM_Idle_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sHiveRootsOAM_Idle[4] = {
    sHiveRootsOAM_Idle_Frame0,
    0x4,
    sHiveRootsOAM_Idle_Frame1,
    0x4,
    sHiveRootsOAM_Idle_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Phase2[12] = {
    sHiveOAM_Phase2_Frame0,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x9,
    sHiveOAM_Phase2_Frame2,
    0xA,
    sHiveOAM_Phase2_Frame3,
    0x9,
    sHiveOAM_Phase2_Frame2,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x6,
    sHiveOAM_Phase2_Frame2,
    0x6,
    sHiveOAM_Phase2_Frame3,
    0x6,
    sHiveOAM_Phase2_Frame2,
    0x6,
    sHiveOAM_Phase2_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Phase3[13] = {
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x5,
    sHiveOAM_Phase3_Frame2,
    0x6,
    sHiveOAM_Phase3_Frame1,
    0x5,
    sHiveOAM_Phase3_Frame0,
    0x3,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame2,
    0x5,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame0,
    0x2,
    sHiveOAM_Phase3_Frame1,
    0x3,
    sHiveOAM_Phase3_Frame2,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Dying[32] = {
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame0,
    0x3,
    sHiveOAM_Phase3_Frame1,
    0x3,
    sHiveOAM_Phase3_Frame0,
    0x2,
    sHiveOAM_Phase3_Frame1,
    0x2,
    sHiveOAM_Dying_Frame8,
    0x2,
    sHiveOAM_Dying_Frame9,
    0x2,
    sHiveOAM_Dying_Frame10,
    0x3,
    sHiveOAM_Dying_Frame11,
    0x4,
    sHiveOAM_Dying_Frame12,
    0x4,
    sHiveOAM_Dying_Frame13,
    0x5,
    sHiveOAM_Dying_Frame14,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x5,
    sHiveOAM_Dying_Frame12,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame14,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame12,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x9,
    sHiveOAM_Dying_Frame14,
    0xA,
    sHiveOAM_Dying_Frame13,
    0x9,
    sHiveOAM_Dying_Frame12,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame14,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame12,
    0xC,
    sHiveOAM_Dying_Frame13,
    0x10,
    sHiveOAM_Dying_Frame30,
    0xFF,
    NULL,
    0x0
};
