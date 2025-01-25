#include "data/sprites/morph_ball.h"
#include "macros.h"

const u32 sMorphBallGfx[168] = INCBIN_U32("data/sprites/MorphBall.gfx.lz");
const u16 sMorphBallPal[16] = INCBIN_U16("data/sprites/MorphBall.pal");

const u16 sMorphBallOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMorphBallOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sMorphBallOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sMorphBallOutsideOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sMorphBallOutsideOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sMorphBallOutsideOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sMorphBallOutsideOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sMorphBallOutsideOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const struct FrameData sMorphBallOam_Idle[5] = {
    [0] = {
        .pFrame = sMorphBallOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sMorphBallOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sMorphBallOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sMorphBallOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMorphBallOutsideOam_Idle[6] = {
    [0] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f) + CONVERT_SECONDS(2.f / 3)
    },
    [1] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = FRAME_DATA_TERMINATOR
};
