#include "data/sprites/deorem.h"
#include "macros.h"

const s16 sDeoremSegmentXVelocity[33] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
    SHORT_MAX
};

const s16 sDeoremThornYVelocity[40] = {
    -8, -7, -6, -5, -4, -3, -2, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9,
    10, 10, 10, 10, 10,
    SHORT_MAX
};

const u32 sDeoremGfx[1569] = INCBIN_U32("data/sprites/deorem.gfx.lz");
const u16 sDeoremPal[16 * 5] = INCBIN_U16("data/sprites/deorem.pal");

static const u16 sDeoremSegmentOam_Middle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1210
};

static const u16 sDeoremSegmentOam_Middle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208
};

static const u16 sDeoremSegmentOam_Middle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1200
};

static const u16 sDeoremSegmentOam_Junction_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x131c
};

static const u16 sDeoremSegmentOam_Junction_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x131c
};

static const u16 sDeoremSegmentOam_Junction_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x131c
};

static const u16 sDeoremSegmentOam_Tail_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1290,
    0x0, 0x1e7, OBJ_SPRITE_OAM | 0x1331,
    0xfd, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x1330
};

static const u16 sDeoremSegmentOam_Tail_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd3, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1218,
    0xef, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x128c,
    0xfe, 0x1e8, OBJ_SPRITE_OAM | 0x1332,
    0xfe, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1332
};

static const u16 sDeoremSegmentOam_Tail_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1288,
    0x0, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1331,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x1330
};

static const u16 sDeoremThornOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1314
};

static const u16 sDeoremEyeOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

static const u16 sDeoremEyeOam_Pulsing_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4316,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

static const u16 sDeoremEyeOam_Pulsing_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4318,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

static const u16 sDeoremEyeOam_Pulsing_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x431a,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

static const u16 sDeoremOam_Closing_Frame3[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Closed_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf7, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Closed_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Closed_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf5, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Opening_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Opening_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf4, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x299,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Opening_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Opening_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe5, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

static const u16 sDeoremOam_Opened_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe4, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x21c,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

static const u16 sDeoremOam_Opened_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

static const u16 sDeoremOam_Warning_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Warning_Frame3[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe8, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Warning_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf4, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x299,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Warning_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf5, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

static const u16 sDeoremOam_Warning_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf7, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const struct FrameData sDeoremSegmentOam_Middle[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremSegmentOam_Junction[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremSegmentOam_Tail[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremThornOam_Idle[2] = {
    [0] = {
        .pFrame = sDeoremThornOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremEyeOam_Idle[2] = {
    [0] = {
        .pFrame = sDeoremEyeOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremEyeOam_Pulsing[6] = {
    [0] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame1,
        .timer = 6
    },
    [4] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame0,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_ClosedSlow[5] = {
    [0] = {
        .pFrame = sDeoremOam_Closed_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sDeoremOam_Closed_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Opening[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_OpenedSlow[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opened_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = 12
    },
    [2] = {
        .pFrame = sDeoremOam_Opened_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Closing[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = 2
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sDeoremOam_Closing_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Warning[9] = {
    [0] = {
        .pFrame = sDeoremOam_Warning_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sDeoremOam_Warning_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sDeoremOam_Warning_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sDeoremOam_Warning_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sDeoremOam_Warning_Frame3,
        .timer = 3
    },
    [6] = {
        .pFrame = sDeoremOam_Warning_Frame2,
        .timer = 3
    },
    [7] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = 3
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_GoingDown[3] = {
    [0] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = 3
    },
    [1] = {
        .pFrame = sDeoremOam_Warning_Frame0,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_OpenedFast[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opened_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = 4
    },
    [2] = {
        .pFrame = sDeoremOam_Opened_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_ClosedFast[5] = {
    [0] = {
        .pFrame = sDeoremOam_Closed_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sDeoremOam_Closed_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Dying[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};
