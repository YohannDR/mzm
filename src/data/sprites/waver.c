#include "data/sprites/waver.h"
#include "macros.h"

const u32 sWaverGfx[289] = INCBIN_U32("data/sprites/Waver.gfx.lz");
const u16 sWaverPal[16] = INCBIN_U16("data/sprites/Waver.pal");

const u16 sWaverOAM_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x216
};

const u16 sWaverOAM_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x204
};

const u16 sWaverOAM_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x207
};

const u16 sWaverOAM_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20b
};

const u16 sWaverOAM_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x236
};

const u16 sWaverOAM_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x21a
};

const struct FrameData sWaverOAM[7] = {
    [0] = {
        .pFrame = sWaverOAM_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sWaverOAM_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sWaverOAM_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sWaverOAM_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sWaverOAM_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sWaverOAM_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};
