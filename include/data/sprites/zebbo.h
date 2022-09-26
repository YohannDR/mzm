#ifndef ZEBBO_DATA_H
#define ZEBBO_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u32 sZebboGreenGFX[124] = INCBIN_U32("data/sprites/ZebboGreen.gfx.lz");
static const u16 sZebboGreenPAL[16] = INCBIN_U16("data/sprites/ZebboGreen.pal");
static const u32 sZebboYellowGFX[124] = INCBIN_U32("data/sprites/ZebboYellow.gfx.lz");
static const u16 sZebboYellowPAL[16] = INCBIN_U16("data/sprites/ZebboYellow.pal");

static const u16 sZebboOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sZebboOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sZebboOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sZebboOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sZebboOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZebboOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const struct FrameData sZebboOAM_Idle[5] = {
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

static const struct FrameData sZebboOAM_Moving[5] = {
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

#endif