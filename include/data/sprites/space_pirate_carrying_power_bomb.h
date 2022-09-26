#ifndef SPACE_PIRATE_CARRYING_POWER_BOMB_DATA_H
#define SPACE_PIRATE_CARRYING_POWER_BOMB_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u8 sFakePowerBombGFX[460] = INCBIN_U32("data/sprites/FakePowerBomb.gfx.lz");
static const u16 sFakePowerBombPAL[16] = INCBIN_U16("data/sprites/FakePowerBomb.pal");

static const u16 sFakePowerBombOAM_Idle_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sFakePowerBombOAM_Idle_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sFakePowerBombOAM_Idle_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sFakePowerBombOAM_Idle_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const struct FrameData sFakePowerBombOAM_Idle[5] = {
    sFakePowerBombOAM_Idle_Frame0,
    0x6,
    sFakePowerBombOAM_Idle_Frame1,
    0x6,
    sFakePowerBombOAM_Idle_Frame2,
    0x6,
    sFakePowerBombOAM_Idle_Frame3,
    0x6,
    NULL,
    0x0
};

#endif