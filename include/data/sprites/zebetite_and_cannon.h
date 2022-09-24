#ifndef ZEBETITE_AND_CANNON_DATA_C
#define ZEBETITE_AND_CANNON_DATA_C

#include "types.h"
#include "oam.h"

static const u32 sRinkaZebetiteAndCannonGFX[476];
static const u16 sRinkaZebetiteAndCannonPAL[32];

static const u16 sRinkaMotherBrainOAM_Moving_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1200
};

static const u16 sRinkaMotherBrainOAM_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1201,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1201
};

static const u16 sRinkaMotherBrainOAM_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1202
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1203,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1203
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1204
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1205
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1206,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1206
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1240,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x1241,
    0x8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1241,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x1261,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x1261
};

static const u16 sRinkaMotherBrainOAM_Spawning_Frame5[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1242,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x1243,
    0x8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1243,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x1263,
    0xfc, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x1263
};

// Zebetite and cannon frames

static const struct FrameData sRinkaMotherBrainOAM_Spawning[16] = {
    sRinkaMotherBrainOAM_Spawning_Frame0,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame1,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame2,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame3,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame4,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame5,
    0x4,
    sRinkaMotherBrainOAM_Spawning_Frame3,
    0x8,
    sRinkaMotherBrainOAM_Moving_Frame0,
    0x6,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0x6,
    sRinkaMotherBrainOAM_Moving_Frame2,
    0x6,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0x8,
    sRinkaMotherBrainOAM_Moving_Frame0,
    0x7,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0x7,
    sRinkaMotherBrainOAM_Moving_Frame2,
    0x7,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0x7,
    NULL,
    0x0
};

static const struct FrameData sRinkaMotherBrainOAM_Moving[5] = {
    sRinkaMotherBrainOAM_Moving_Frame0,
    0xC,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0xC,
    sRinkaMotherBrainOAM_Moving_Frame2,
    0xC,
    sRinkaMotherBrainOAM_Moving_Frame1,
    0xC,
    NULL,
    0x0
};

// Zebetite and cannon OAM

#endif