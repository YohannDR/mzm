#include "data/sprites/zeb.h"
#include "macros.h"

const u32 sZebPinkGfx[162] = INCBIN_U32("data/sprites/ZebPink.gfx.lz");
const u16 sZebPinkPal[16] = INCBIN_U16("data/sprites/ZebPink.pal");
const u32 sZebBlueGfx[162] = INCBIN_U32("data/sprites/ZebBlue.gfx.lz");
const u16 sZebBluePal[16] = INCBIN_U16("data/sprites/ZebBlue.pal");

const u16 sZebOAM_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x200
};

const u16 sZebOAM_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x204
};

const u16 sZebOAM_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x208
};

const struct FrameData sZebOAM_Idle[5] = {
    [0] = {
        .pFrame = sZebOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sZebOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sZebOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebOAM_Moving[5] = {
    [0] = {
        .pFrame = sZebOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sZebOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZebOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};
