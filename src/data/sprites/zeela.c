#include "data/sprites/zeela.h"
#include "macros.h"

const s16 sZeelaEyesFallingFromUpSpeed[16] = {
    -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const s16 sZeelaEyesFallingFromBottomSpeed[12] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const u32 sZeelaGfx[578] = INCBIN_U32("data/sprites/Zeela.gfx.lz");
const u16 sZeelaPAL[32] = INCBIN_U16("data/sprites/Zeela.pal");

const u16 sZeelaOam_OnGround_Frame0[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x202
};

const u16 sZeelaOam_OnGround_Frame1[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x205,
    0xe8, 0x2, OBJ_SPRITE_OAM | 0x266
};

const u16 sZeelaOam_OnGround_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x242
};

const u16 sZeelaOam_OnGround_Frame3[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x243,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x245
};

const u16 sZeelaOam_TurningEdgeLeft_Frame0[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x4, OBJ_SPRITE_OAM | 0x230,
    0xeb, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sZeelaOam_TurningEdgeLeft_Frame1[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x25a
};

const u16 sZeelaOam_TurningEdgeLeft_Frame2[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x7, OBJ_SPRITE_OAM | 0x21f,
    0x3, 0x1ff, OBJ_SPRITE_OAM | 0x25e
};

const u16 sZeelaOam_OnWall_Frame0[7] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x246
};

const u16 sZeelaOam_OnWall_Frame1[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x248,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x267
};

const u16 sZeelaOam_OnWall_Frame2[7] = {
    0x2,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24a
};

const u16 sZeelaOam_OnWall_Frame3[7] = {
    0x2,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sZeelaOam_TurningCornerRight_Frame0[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x230,
    0xec, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sZeelaOam_TurningCornerRight_Frame1[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x25a
};

const u16 sZeelaOam_TurningCornerRight_Frame2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x21f,
    0x0, 0x1fa, OBJ_SPRITE_OAM | 0x25e
};

const u16 sZeelaOam_TurningCornerLeft_Frame0[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf2, 0xa, OBJ_SPRITE_OAM | 0x21f,
    0x2, 0x2, OBJ_SPRITE_OAM | 0x25e
};

const u16 sZeelaOam_TurningCornerLeft_Frame1[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf1, 0xb, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1fb, OBJ_SPRITE_OAM | 0x25a
};

const u16 sZeelaOam_TurningCornerLeft_Frame2[10] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xf5, 0xa, OBJ_SPRITE_OAM | 0x230,
    0xed, 0x2, OBJ_SPRITE_OAM | 0x20f
};

const u16 sZeelaOam_WalkingOnSlope_Frame0[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x2, OBJ_SPRITE_OAM | 0x230,
    0xea, 0x1fa, OBJ_SPRITE_OAM | 0x20f
};

const u16 sZeelaOam_WalkingOnSlope_Frame1[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x3, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fb, OBJ_SPRITE_OAM | 0x252
};

const u16 sZeelaOam_WalkingOnSlope_Frame2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x255
};

const u16 sZeelaOam_WalkingOnSlope_Frame3[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x3, OBJ_SPRITE_OAM | 0x239,
    0xec, 0x1fb, OBJ_SPRITE_OAM | 0x218
};

const u16 sZeelaOam_FallingOnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1f7, OBJ_SPRITE_OAM | 0x268,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x202
};

const u16 sZeelaOam_FallingOnGround_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f7, OBJ_SPRITE_OAM | 0x26a,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x205,
    0xe8, 0x2, OBJ_SPRITE_OAM | 0x266
};

const u16 sZeelaOam_FallingOnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x274,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x242
};

const u16 sZeelaOam_FallingOnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x276,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x243,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x245
};

const u16 sZeelaOam_FallingOnGround_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1f7, OBJ_SPRITE_OAM | 0x270,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x202
};

const u16 sZeelaOam_FallingOnGround_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f7, OBJ_SPRITE_OAM | 0x272,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2, OBJ_SPRITE_OAM | 0x205,
    0xe8, 0x2, OBJ_SPRITE_OAM | 0x266
};

const u16 sZeelaOam_FallingOnGround_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x26c,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x242
};

const u16 sZeelaOam_FallingOnGround_Frame7[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x26e,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x243,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x6, OBJ_SPRITE_OAM | 0x245
};

const u16 sZeelaOam_FallingOnWall_Frame0[13] = {
    0x4,
    0xf7, 0x9, OBJ_SPRITE_OAM | 0x279,
    0x0, 0x9, OBJ_SPRITE_OAM | 0x279,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x246
};

const u16 sZeelaOam_FallingOnWall_Frame1[16] = {
    0x5,
    0xf7, 0x8, OBJ_SPRITE_OAM | 0x27a,
    0x0, 0xa, OBJ_SPRITE_OAM | 0x27a,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x248,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x267
};

const u16 sZeelaOam_FallingOnWall_Frame2[13] = {
    0x4,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x27e,
    0x1, 0x9, OBJ_SPRITE_OAM | 0x27e,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24a
};

const u16 sZeelaOam_FallingOnWall_Frame3[13] = {
    0x4,
    0xf8, 0x9, OBJ_SPRITE_OAM | 0x27d,
    0x1, 0x8, OBJ_SPRITE_OAM | 0x27d,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sZeelaOam_FallingOnWall_Frame4[13] = {
    0x4,
    0xf7, 0x9, OBJ_SPRITE_OAM | 0x27c,
    0x0, 0x9, OBJ_SPRITE_OAM | 0x27c,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x246
};

const u16 sZeelaOam_FallingOnWall_Frame5[16] = {
    0x5,
    0xf7, 0x8, OBJ_SPRITE_OAM | 0x27d,
    0x0, 0xa, OBJ_SPRITE_OAM | 0x27d,
    0xf2, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x0, OBJ_SPRITE_OAM | 0x248,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x267
};

const u16 sZeelaOam_FallingOnWall_Frame6[13] = {
    0x4,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x27b,
    0x1, 0x9, OBJ_SPRITE_OAM | 0x27b,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24a
};

const u16 sZeelaOam_FallingOnWall_Frame7[13] = {
    0x4,
    0xf8, 0x9, OBJ_SPRITE_OAM | 0x27a,
    0x1, 0x8, OBJ_SPRITE_OAM | 0x27a,
    0xf6, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sZeelaEyesOAM_Idle_Frame0[4] = {
    0x1,
    0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x27f
};

const u16 sZeelaEyesOAM_Spinning_Unused_Frame0[4] = {
    0x1,
    0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x268
};

const u16 sZeelaEyesOAM_Spinning_Unused_Frame1[4] = {
    0x1,
    0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x270
};

const u16 sZeelaEyesOAM_Exploding_Frame0[13] = {
    0x4,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x25c,
    0x0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x25c,
    0x0, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sZeelaEyesOAM_Exploding_Frame1[13] = {
    0x4,
    0xf5, 0x1f5, OBJ_SPRITE_OAM | 0x25d,
    0xf5, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x25d,
    0x3, 0x3, OBJ_SPRITE_OAM | 0x25d,
    0x3, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x25d
};

const u16 sZeelaEyesOAM_Exploding_Frame2[13] = {
    0x4,
    0xf3, 0x1f3, OBJ_SPRITE_OAM | 0x25f,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x25f,
    0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x25f,
    0x5, 0x1f3, OBJ_SPRITE_OAM | 0x25f
};

const struct FrameData sZeelaOam_OnGround[5] = {
    sZeelaOam_OnGround_Frame0,
    0xC,
    sZeelaOam_OnGround_Frame1,
    0xC,
    sZeelaOam_OnGround_Frame2,
    0xC,
    sZeelaOam_OnGround_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_TurningEdgeLeft[4] = {
    sZeelaOam_TurningEdgeLeft_Frame0,
    0x2,
    sZeelaOam_TurningEdgeLeft_Frame1,
    0x2,
    sZeelaOam_TurningEdgeLeft_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_TurningEdgeRight[4] = {
    sZeelaOam_TurningEdgeLeft_Frame2,
    0x2,
    sZeelaOam_TurningEdgeLeft_Frame1,
    0x2,
    sZeelaOam_TurningEdgeLeft_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_OnWall[5] = {
    sZeelaOam_OnWall_Frame0,
    0xC,
    sZeelaOam_OnWall_Frame1,
    0xC,
    sZeelaOam_OnWall_Frame2,
    0xC,
    sZeelaOam_OnWall_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_TurningCornerRight[4] = {
    sZeelaOam_TurningCornerRight_Frame0,
    0x2,
    sZeelaOam_TurningCornerRight_Frame1,
    0x2,
    sZeelaOam_TurningCornerRight_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_TurningCornerLeft[4] = {
    sZeelaOam_TurningCornerLeft_Frame0,
    0x2,
    sZeelaOam_TurningCornerLeft_Frame1,
    0x2,
    sZeelaOam_TurningCornerLeft_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_WalkingOnSlope[5] = {
    sZeelaOam_WalkingOnSlope_Frame0,
    0xC,
    sZeelaOam_WalkingOnSlope_Frame1,
    0xC,
    sZeelaOam_WalkingOnSlope_Frame2,
    0xC,
    sZeelaOam_WalkingOnSlope_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_FallingOnGround[9] = {
    sZeelaOam_FallingOnGround_Frame0,
    0xC,
    sZeelaOam_FallingOnGround_Frame1,
    0xC,
    sZeelaOam_FallingOnGround_Frame2,
    0xC,
    sZeelaOam_FallingOnGround_Frame3,
    0xC,
    sZeelaOam_FallingOnGround_Frame4,
    0xC,
    sZeelaOam_FallingOnGround_Frame5,
    0xC,
    sZeelaOam_FallingOnGround_Frame6,
    0xC,
    sZeelaOam_FallingOnGround_Frame7,
    0xC,
    NULL,
    0x0
};

const struct FrameData sZeelaOam_FallingOnWall[9] = {
    sZeelaOam_FallingOnWall_Frame0,
    0xC,
    sZeelaOam_FallingOnWall_Frame1,
    0xC,
    sZeelaOam_FallingOnWall_Frame2,
    0xC,
    sZeelaOam_FallingOnWall_Frame3,
    0xC,
    sZeelaOam_FallingOnWall_Frame4,
    0xC,
    sZeelaOam_FallingOnWall_Frame5,
    0xC,
    sZeelaOam_FallingOnWall_Frame6,
    0xC,
    sZeelaOam_FallingOnWall_Frame7,
    0xC,
    NULL,
    0x0
};

const struct FrameData sZeelaEyesOAM_Idle[2] = {
    sZeelaEyesOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sZeelaEyesOAM_Spinning_Unused[5] = {
    sZeelaEyesOAM_Spinning_Unused_Frame0,
    0x5,
    sZeelaEyesOAM_Spinning_Unused_Frame1,
    0xC,
    sZeelaEyesOAM_Spinning_Unused_Frame0,
    0x5,
    sZeelaEyesOAM_Idle_Frame0,
    0xA,
    NULL,
    0x0
};

const struct FrameData sZeelaEyesOAM_Exploding[4] = {
    sZeelaEyesOAM_Exploding_Frame0,
    0x3,
    sZeelaEyesOAM_Exploding_Frame1,
    0x3,
    sZeelaEyesOAM_Exploding_Frame2,
    0x3,
    NULL,
    0x0
};
