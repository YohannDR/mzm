#include "data/sprites/geega.h"
#include "macros.h"

const u32 sGeegaGfx[153] = INCBIN_U32("data/sprites/Geega.gfx.lz");
const u16 sGeegaPAL[16] = INCBIN_U16("data/sprites/Geega.pal");
const u32 sGeegaWhiteGfx[153] = INCBIN_U32("data/sprites/GeegaWhite.gfx.lz");
const u16 sGeegaWhitePAL[16] = INCBIN_U16("data/sprites/GeegaWhite.pal");

const u16 sGeegaOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sGeegaOAM_Idle_Frame1[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sGeegaOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sGeegaOAM_Moving_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sGeegaOAM_Moving_Frame5[4] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sGeegaOAM_Moving_Frame6[4] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const struct FrameData sGeegaOAM_Idle[5] = {
    sGeegaOAM_Idle_Frame0,
    0x4,
    sGeegaOAM_Idle_Frame1,
    0x3,
    sGeegaOAM_Idle_Frame2,
    0x4,
    sGeegaOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGeegaOAM_Moving[9] = {
    sGeegaOAM_Idle_Frame0,
    0x3,
    sGeegaOAM_Idle_Frame1,
    0x2,
    sGeegaOAM_Idle_Frame2,
    0x3,
    sGeegaOAM_Idle_Frame1,
    0x1,
    sGeegaOAM_Moving_Frame4,
    0x3,
    sGeegaOAM_Moving_Frame5,
    0x2,
    sGeegaOAM_Moving_Frame6,
    0x3,
    sGeegaOAM_Moving_Frame5,
    0x1,
    NULL,
    0x0
};
