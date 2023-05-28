#include "data/sprites/zoomer.h"
#include "macros.h"

const u32 sZoomerGfx[379] = INCBIN_U32("data/sprites/Zoomer.gfx.lz");
const u16 sZoomerPAL[32] = INCBIN_U16("data/sprites/Zoomer.pal");

const u16 sZoomerOAM_Falling_Frame0[13] = {
    0x4,
    0xee, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xee, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x20f
};

const u16 sZoomerOAM_Falling_Frame1[13] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x210
};

const u16 sZoomerOAM_Falling_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x22f,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x22f
};

const u16 sZoomerOAM_OnGround_Frame0[13] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x227
};

const u16 sZoomerOAM_OnGround_Frame1[13] = {
    0x4,
    0xee, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xee, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x228
};

const u16 sZoomerOAM_OnGround_Frame2[13] = {
    0x4,
    0xef, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x227,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x207
};

const u16 sZoomerOAM_OnGround_Frame3[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x228,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208
};

const u16 sZoomerOAM_TurningEdgeLeft_Frame0[10] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f7, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x21b
};

const u16 sZoomerOAM_TurningEdgeLeft_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xb, OBJ_SPRITE_OAM | 0x21c
};

const u16 sZoomerOAM_TurningEdgeLeft_Frame2[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf9, 0xa, OBJ_SPRITE_OAM | 0x21d
};

const u16 sZoomerOAM_OnWall_Frame0[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1, OBJ_SPRITE_OAM | 0x239,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23e
};

const u16 sZoomerOAM_OnWall_Frame1[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x2, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x21f,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23f
};

const u16 sZoomerOAM_OnWall_Frame2[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x20d,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x23e,
    0x3, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21e
};

const u16 sZoomerOAM_OnWall_Frame3[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x0, OBJ_SPRITE_OAM | 0x239,
    0xf6, 0x0, OBJ_SPRITE_OAM | 0x23f,
    0x1, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21f
};

const u16 sZoomerOAM_TurningCornerRight_Frame0[10] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f7, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x21b
};

const u16 sZoomerOAM_TurningCornerRight_Frame1[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xeb, 0x1f6, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x6, OBJ_SPRITE_OAM | 0x21c
};

const u16 sZoomerOAM_TurningCornerRight_Frame2[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1f5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x5, OBJ_SPRITE_OAM | 0x21d
};

const u16 sZoomerOAM_TurningCornerLeft_Frame0[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fe, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xe, OBJ_SPRITE_OAM | 0x21d
};

const u16 sZoomerOAM_TurningCornerLeft_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x0, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x10, OBJ_SPRITE_OAM | 0x21c
};

const u16 sZoomerOAM_TurningCornerLeft_Frame2[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1ff, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf8, 0xf, OBJ_SPRITE_OAM | 0x21b
};

const u16 sZoomerOAM_WalkingOnLeftSlope_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    0xf6, 0x1f0, OBJ_SPRITE_OAM | 0x243
};

const u16 sZoomerOAM_WalkingOnLeftSlope_Frame1[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x6, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x246
};

const u16 sZoomerOAM_WalkingOnLeftSlope_Frame2[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x7, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x248
};

const u16 sZoomerOAM_WalkingOnLeftSlope_Frame3[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x7, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24a
};

const u16 sZoomerOAM_WalkingOnRightSlope_Frame0[13] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    0xf6, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x243
};

const u16 sZoomerOAM_WalkingOnRightSlope_Frame1[10] = {
    0x3,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x246
};

const u16 sZoomerOAM_WalkingOnRightSlope_Frame2[10] = {
    0x3,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x248
};

const u16 sZoomerOAM_WalkingOnRightSlope_Frame3[10] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x242,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x24a
};

const struct FrameData sZoomerOAM_Falling[5] = {
    sZoomerOAM_Falling_Frame0,
    0x3,
    sZoomerOAM_Falling_Frame1,
    0x3,
    sZoomerOAM_Falling_Frame2,
    0x3,
    sZoomerOAM_Falling_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_OnGround[5] = {
    sZoomerOAM_OnGround_Frame0,
    0x3,
    sZoomerOAM_OnGround_Frame1,
    0x3,
    sZoomerOAM_OnGround_Frame2,
    0x3,
    sZoomerOAM_OnGround_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_TurningEdgeLeft[4] = {
    sZoomerOAM_TurningEdgeLeft_Frame0,
    0x2,
    sZoomerOAM_TurningEdgeLeft_Frame1,
    0x2,
    sZoomerOAM_TurningEdgeLeft_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_TurningEdgeRight[4] = {
    sZoomerOAM_TurningEdgeLeft_Frame2,
    0x2,
    sZoomerOAM_TurningEdgeLeft_Frame1,
    0x2,
    sZoomerOAM_TurningEdgeLeft_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_OnWall[5] = {
    sZoomerOAM_OnWall_Frame0,
    0x3,
    sZoomerOAM_OnWall_Frame1,
    0x3,
    sZoomerOAM_OnWall_Frame2,
    0x3,
    sZoomerOAM_OnWall_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_TurningCornerRight[4] = {
    sZoomerOAM_TurningCornerRight_Frame0,
    0x2,
    sZoomerOAM_TurningCornerRight_Frame1,
    0x2,
    sZoomerOAM_TurningCornerRight_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_TurningCornerLeft[4] = {
    sZoomerOAM_TurningCornerLeft_Frame0,
    0x2,
    sZoomerOAM_TurningCornerLeft_Frame1,
    0x2,
    sZoomerOAM_TurningCornerLeft_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_WalkingOnLeftSlope[5] = {
    sZoomerOAM_WalkingOnLeftSlope_Frame0,
    0x3,
    sZoomerOAM_WalkingOnLeftSlope_Frame1,
    0x3,
    sZoomerOAM_WalkingOnLeftSlope_Frame2,
    0x3,
    sZoomerOAM_WalkingOnLeftSlope_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZoomerOAM_WalkingOnRightSlope[5] = {
    sZoomerOAM_WalkingOnRightSlope_Frame0,
    0x3,
    sZoomerOAM_WalkingOnRightSlope_Frame1,
    0x3,
    sZoomerOAM_WalkingOnRightSlope_Frame2,
    0x3,
    sZoomerOAM_WalkingOnRightSlope_Frame3,
    0x3,
    NULL,
    0x0
};
