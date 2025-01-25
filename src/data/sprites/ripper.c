#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipperBrownGfx[141] = INCBIN_U32("data/sprites/RipperBrown.gfx.lz");
const u16 sRipperBrownPal[16] = INCBIN_U16("data/sprites/RipperBrown.pal");
const u32 sRipperPurpleGfx[141] = INCBIN_U32("data/sprites/RipperPurple.gfx.lz");
const u16 sRipperPurplePal[16] = INCBIN_U16("data/sprites/RipperPurple.pal");

const u16 sRipperOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRipperOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf3, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sRipperOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xf3, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sRipperOam_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sRipperOam_TurningAround_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const struct FrameData sRipperOam_Moving[5] = {
    [0] = {
        .pFrame = sRipperOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sRipperOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sRipperOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sRipperOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipperOam_TurningAround[3] = {
    [0] = {
        .pFrame = sRipperOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipperOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipperOam_TurningAroundPart2[3] = {
    [0] = {
        .pFrame = sRipperOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipperOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};
