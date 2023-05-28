#include "data/sprites/unused_sprites.h"
#include "macros.h"

const u16 sUnusedSpritesOAM_Idle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x3151
};

const u16 sUnusedSpritesOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x3150
};

const struct FrameData sUnusedSpritesOAM_Idle[3] = {
    sUnusedSpritesOAM_Idle_Frame0,
    30,
    sUnusedSpritesOAM_Idle_Frame1,
    30,
    NULL,
    0
};

const struct FrameData sUnusedSpritesOAM_Unused[2] = {
    sUnusedSpritesOAM_Idle_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const u32 sUnusedSpritesGfx[6] = INCBIN_U32("data/sprites/UnusedSprites.gfx.lz");
const u16 sUnusedSpritesPAL[16] = INCBIN_U16("data/sprites/UnusedSprites.pal");
