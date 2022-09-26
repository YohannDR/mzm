#ifndef POWER_GRIP_DATA_H
#define POWER_GRIP_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u32 sPowerGripGFX[279] = INCBIN_U32("data/sprites/PowerGrip.gfx.lz");
static const u16 sPowerGripPAL[32] = INCBIN_U16("data/sprites/PowerGrip.pal");

static const u16 sPowerGripOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sPowerGripOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sPowerGripOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sPowerGripGlowOAM_Idle_Frame0[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1206,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1208
};

static const u16 sPowerGripGlowOAM_Idle_Frame2[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120a,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x120c
};

static const u16 sPowerGripGlowOAM_Idle_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120e,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1210,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1210
};

static const u16 sPowerGripGlowOAM_Idle_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1212,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1214,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1214
};

static const u16 sPowerGripGlowOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1216
};

static const struct FrameData sPowerGripOAM_Idle[5] = {
    sPowerGripOAM_Idle_Frame0,
    0xA,
    sPowerGripOAM_Idle_Frame1,
    0xA,
    sPowerGripOAM_Idle_Frame2,
    0xA,
    sPowerGripOAM_Idle_Frame1,
    0xA,
    NULL,
    0x0
};

static const struct FrameData sPowerGripGlowOAM_Idle[15] = {
    sPowerGripGlowOAM_Idle_Frame0,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame2,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame4,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame6,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame4,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame2,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    sPowerGripGlowOAM_Idle_Frame0,
    0x2,
    sPowerGripGlowOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};

#endif