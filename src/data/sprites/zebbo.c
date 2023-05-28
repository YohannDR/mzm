#include "data/sprites/zebbo.h"
#include "macros.h"

const u32 sZebboGreenGfx[124] = INCBIN_U32("data/sprites/ZebboGreen.gfx.lz");
const u16 sZebboGreenPAL[16] = INCBIN_U16("data/sprites/ZebboGreen.pal");
const u32 sZebboYellowGfx[124] = INCBIN_U32("data/sprites/ZebboYellow.gfx.lz");
const u16 sZebboYellowPAL[16] = INCBIN_U16("data/sprites/ZebboYellow.pal");

const u16 sZebboOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sZebboOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sZebboOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sZebboOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sZebboOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZebboOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const struct FrameData sZebboOAM_Idle[5] = {
    sZebboOAM_Idle_Frame0,
    0x3,
    sZebboOAM_Idle_Frame1,
    0x3,
    sZebboOAM_Idle_Frame2,
    0x3,
    sZebboOAM_Idle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZebboOAM_Moving[5] = {
    sZebboOAM_Moving_Frame0,
    0x2,
    sZebboOAM_Moving_Frame1,
    0x1,
    sZebboOAM_Moving_Frame2,
    0x2,
    sZebboOAM_Moving_Frame1,
    0x1,
    NULL,
    0x0
};
