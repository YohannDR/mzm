#include "data/sprites/gamet.h"
#include "macros.h"

const u32 sGametBlueGfx[168] = INCBIN_U32("data/sprites/GametBlue.gfx.lz");
const u16 sGametBluePal[16] = INCBIN_U16("data/sprites/GametBlue.pal");
const u32 sGametRedGfx[168] = INCBIN_U32("data/sprites/GametRed.gfx.lz");
const u16 sGametRedPal[16] = INCBIN_U16("data/sprites/GametRed.pal");

const u16 sGametOAM_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x201,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sGametOAM_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x203,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sGametOAM_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sGametOAM_Moving_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x201,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209
};

const u16 sGametOAM_Moving_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x203,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209
};

const u16 sGametOAM_Moving_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const struct FrameData sGametOAM_Idle[5] = {
    [0] = {
        .pFrame = sGametOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGametOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGametOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGametOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGametOAM_Moving[5] = {
    [0] = {
        .pFrame = sGametOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGametOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sGametOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGametOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};
