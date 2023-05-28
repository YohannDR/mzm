#include "data/sprites/zeb.h"
#include "macros.h"

const u32 sZebPinkGfx[162] = INCBIN_U32("data/sprites/ZebPink.gfx.lz");
const u16 sZebPinkPAL[16] = INCBIN_U16("data/sprites/ZebPink.pal");
const u32 sZebBlueGfx[162] = INCBIN_U32("data/sprites/ZebBlue.gfx.lz");
const u16 sZebBluePAL[16] = INCBIN_U16("data/sprites/ZebBlue.pal");

const u16 sZebOAM_Idle_Frame0[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x200
};

const u16 sZebOAM_Idle_Frame1[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x204
};

const u16 sZebOAM_Idle_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x208
};

const struct FrameData sZebOAM_Idle[5] = {
    sZebOAM_Idle_Frame0,
    0x4,
    sZebOAM_Idle_Frame1,
    0x3,
    sZebOAM_Idle_Frame2,
    0x4,
    sZebOAM_Idle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sZebOAM_Moving[5] = {
    sZebOAM_Idle_Frame0,
    0x3,
    sZebOAM_Idle_Frame1,
    0x1,
    sZebOAM_Idle_Frame2,
    0x2,
    sZebOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};
