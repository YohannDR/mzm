#ifndef ZEB_DATA_C
#define ZEB_DATA_C

#include "../../types.h"
#include "../../oam.h"

static const u32 sZebGFX[162];
static const u16 sZebPAL[16];
static const u32 sZebBlueGFX[162];
static const u16 sZebBluePAL[16];

static const u16 sZebOAM_Idle_Frame0[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x200
};

static const u16 sZebOAM_Idle_Frame1[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x204
};

static const u16 sZebOAM_Idle_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x208
};

static const struct FrameData sZebOAM_Idle[5] = {
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

static const struct FrameData sZebOAM_Moving[5] = {
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

#endif