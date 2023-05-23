#include "data/sprites/sova.h"
#include "macros.h"

const u32 sSovaGfx[851] = INCBIN_U32("data/sprites/Sova.gfx.lz");
const u16 sSovaPal[3 * 16] = INCBIN_U16("data/sprites/Sova.pal");

static const u16 sSovaOam_OnGround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSovaOam_OnGround_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x203
};

static const u16 sSovaOam_OnGround_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sSovaOam_OnGround_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x22e
};

static const u16 sSovaOam_OnGround_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe4, 0x1f8, OBJ_SPRITE_OAM | 0x272
};

static const u16 sSovaOam_OnGround_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x273
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x296,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x240
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x296,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x240
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x243
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x247,
    0xe9, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x26b
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    0xec, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x24c,
    0xe4, 0x1, OBJ_SPRITE_OAM | 0x26b
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    0xec, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x24e,
    0xe0, 0x2, OBJ_SPRITE_OAM | 0x24b
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x243
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x247,
    0xe9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x26b
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x29e,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x24c,
    0xe4, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x26b
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x29e,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x24e,
    0xe0, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x24b
};

static const u16 sSovaOam_WalkingOnLeft_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0xc, OBJ_SPRITE_OAM | 0x252
};

static const u16 sSovaOam_WalkingOnLeft_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21d,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x254,
    0xee, 0xc, OBJ_SPRITE_OAM | 0x256
};

static const u16 sSovaOam_WalkingOnLeft_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21d,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x257
};

static const u16 sSovaOam_WalkingOnLeft_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x259,
    0xee, 0xc, OBJ_SPRITE_OAM | 0x27b
};

static const u16 sSovaOam_WalkingOnLeft_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf4, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x25c,
    0xea, 0xc, OBJ_SPRITE_OAM | 0x27b
};

static const u16 sSovaOam_WalkingOnLeft_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf4, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x25e,
    0xec, 0x10, OBJ_SPRITE_OAM | 0x25b
};

static const u16 sSovaOam_WalkingOnRight_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0xc, OBJ_SPRITE_OAM | 0x252
};

static const u16 sSovaOam_WalkingOnRight_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, OBJ_SPRITE_OAM | 0x21d,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x254,
    0xee, 0xc, OBJ_SPRITE_OAM | 0x256
};

static const u16 sSovaOam_WalkingOnRight_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, OBJ_SPRITE_OAM | 0x21d,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x257
};

static const u16 sSovaOam_WalkingOnRight_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x259,
    0xee, 0xc, OBJ_SPRITE_OAM | 0x27b
};

static const u16 sSovaOam_WalkingOnRight_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x25c,
    0xec, 0xc, OBJ_SPRITE_OAM | 0x27b
};

static const u16 sSovaOam_WalkingOnRight_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x25e,
    0xee, 0x10, OBJ_SPRITE_OAM | 0x25b
};

static const u16 sSovaOam_WalkingOnCeiling_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x280
};

static const u16 sSovaOam_WalkingOnCeiling_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x283
};

static const u16 sSovaOam_WalkingOnCeiling_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x287
};

static const u16 sSovaOam_WalkingOnCeiling_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x28a
};

static const u16 sSovaOam_WalkingOnCeiling_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x238,
    0x4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28e
};

static const u16 sSovaOam_WalkingOnCeiling_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x238,
    0x4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x290
};

static const u16 sSovaOam_TurningRight_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x296,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSovaOam_TurningRight_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x247
};

static const u16 sSovaOam_TurningRight_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x21f,
    0xf4, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x259,
    0xec, 0xc, OBJ_SPRITE_OAM | 0x25b
};

static const u16 sSovaOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x296,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSovaOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1fe, OBJ_SPRITE_OAM | 0x247
};

static const u16 sSovaOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x21f,
    0xec, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x259,
    0xe4, 0x7, OBJ_SPRITE_OAM | 0x25b
};

static const u16 sSovaOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x296,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSovaOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x4, OBJ_SPRITE_OAM | 0x247
};

static const u16 sSovaOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x21f,
    0xf2, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x259,
    0xea, 0xd, OBJ_SPRITE_OAM | 0x25b
};

static const u16 sSovaOam_Falling_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x203
};

static const u16 sSovaOam_Falling_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sSovaOam_Falling_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xe4, 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sSovaOam_Falling_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x236,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe3, 0x1f8, OBJ_SPRITE_OAM | 0x272
};

static const u16 sSovaOam_Falling_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x236,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xdf, 0x1fc, OBJ_SPRITE_OAM | 0x273
};


const struct FrameData sSovaOam_OnGround[7] = {
    sSovaOam_OnGround_Frame0,
    6,
    sSovaOam_OnGround_Frame1,
    6,
    sSovaOam_OnGround_Frame2,
    6,
    sSovaOam_OnGround_Frame3,
    6,
    sSovaOam_OnGround_Frame4,
    6,
    sSovaOam_OnGround_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_WalkingOnLeftSlope[7] = {
    sSovaOam_WalkingOnLeftSlope_Frame0,
    6,
    sSovaOam_WalkingOnLeftSlope_Frame1,
    6,
    sSovaOam_WalkingOnLeftSlope_Frame2,
    6,
    sSovaOam_WalkingOnLeftSlope_Frame0,
    6,
    sSovaOam_WalkingOnLeftSlope_Frame4,
    6,
    sSovaOam_WalkingOnLeftSlope_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_WalkingOnRightSlope[7] = {
    sSovaOam_WalkingOnRightSlope_Frame0,
    6,
    sSovaOam_WalkingOnRightSlope_Frame1,
    6,
    sSovaOam_WalkingOnRightSlope_Frame2,
    6,
    sSovaOam_WalkingOnRightSlope_Frame0,
    6,
    sSovaOam_WalkingOnRightSlope_Frame4,
    6,
    sSovaOam_WalkingOnRightSlope_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_WalkingOnLeft[7] = {
    sSovaOam_WalkingOnLeft_Frame0,
    6,
    sSovaOam_WalkingOnLeft_Frame1,
    6,
    sSovaOam_WalkingOnLeft_Frame2,
    6,
    sSovaOam_WalkingOnLeft_Frame3,
    6,
    sSovaOam_WalkingOnLeft_Frame4,
    6,
    sSovaOam_WalkingOnLeft_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_WalkingOnRight[7] = {
    sSovaOam_WalkingOnRight_Frame0,
    6,
    sSovaOam_WalkingOnRight_Frame1,
    6,
    sSovaOam_WalkingOnRight_Frame2,
    6,
    sSovaOam_WalkingOnRight_Frame3,
    6,
    sSovaOam_WalkingOnRight_Frame4,
    6,
    sSovaOam_WalkingOnRight_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_WalkingOnCeiling[7] = {
    sSovaOam_WalkingOnCeiling_Frame0,
    6,
    sSovaOam_WalkingOnCeiling_Frame1,
    6,
    sSovaOam_WalkingOnCeiling_Frame2,
    6,
    sSovaOam_WalkingOnCeiling_Frame3,
    6,
    sSovaOam_WalkingOnCeiling_Frame4,
    6,
    sSovaOam_WalkingOnCeiling_Frame5,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_TurningCornerRight[4] = {
    sSovaOam_TurningRight_Frame0,
    6,
    sSovaOam_TurningRight_Frame1,
    6,
    sSovaOam_TurningRight_Frame2,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_TurningEdgeRight[4] = {
    sSovaOam_TurningRight_Frame2,
    6,
    sSovaOam_TurningRight_Frame1,
    6,
    sSovaOam_TurningRight_Frame0,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_TurningEdgeLeft[4] = {
    sSovaOam_TurningEdgeLeft_Frame0,
    6,
    sSovaOam_TurningEdgeLeft_Frame1,
    6,
    sSovaOam_TurningEdgeLeft_Frame2,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_TurningCornerLeft[4] = {
    sSovaOam_TurningCornerLeft_Frame0,
    6,
    sSovaOam_TurningCornerLeft_Frame1,
    6,
    sSovaOam_TurningCornerLeft_Frame2,
    6,
    NULL,
    0
};

const struct FrameData sSovaOam_Falling[7] = {
    sSovaOam_OnGround_Frame0,
    6,
    sSovaOam_Falling_Frame1,
    6,
    sSovaOam_Falling_Frame2,
    6,
    sSovaOam_Falling_Frame3,
    6,
    sSovaOam_Falling_Frame4,
    6,
    sSovaOam_Falling_Frame5,
    6,
    NULL,
    0
};
