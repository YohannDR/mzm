#ifndef ZEBETITE_AND_CANNON_DATA_H
#define ZEBETITE_AND_CANNON_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u32 sRinkaZebetiteAndCannonGFX[476] = INCBIN_U32("data/sprites/ZebetiteRinkaCannon.gfx.lz");
static const u16 sRinkaZebetiteAndCannonPAL[32] = INCBIN_U16("data/sprites/ZebetiteRinkaCannon.pal");

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

static const u16 sZebetiteOAM_Phase1_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase1_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x232,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase1_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase1_Frame3[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase1_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase1_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase2_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase2_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x232,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase2_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase2_Frame3[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase2_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase2_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase4_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase4_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x234,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase4_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase4_Frame3[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase4_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase4_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase6_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase6_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x234,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase6_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sZebetiteOAM_Phase6_Frame3[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sZebetiteOAM_Phase6_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZebetiteOAM_Phase6_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

// Cannon frames

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

static const struct FrameData sZebetiteOAM_Phase1[7] = {
    sZebetiteOAM_Phase1_Frame0,
    3,
    sZebetiteOAM_Phase1_Frame1,
    3,
    sZebetiteOAM_Phase1_Frame2,
    3,
    sZebetiteOAM_Phase1_Frame3,
    3,
    sZebetiteOAM_Phase1_Frame4,
    3,
    sZebetiteOAM_Phase1_Frame5,
    3,
    NULL,
    0
};

static const struct FrameData sZebetiteOAM_Phase2[7] = {
    sZebetiteOAM_Phase2_Frame0,
    3,
    sZebetiteOAM_Phase2_Frame1,
    3,
    sZebetiteOAM_Phase2_Frame2,
    3,
    sZebetiteOAM_Phase2_Frame3,
    3,
    sZebetiteOAM_Phase2_Frame4,
    3,
    sZebetiteOAM_Phase2_Frame5,
    3,
    NULL,
    0
};

static const struct FrameData sZebetiteOAM_Phase4[7] = {
    sZebetiteOAM_Phase4_Frame0,
    3,
    sZebetiteOAM_Phase4_Frame1,
    3,
    sZebetiteOAM_Phase4_Frame2,
    3,
    sZebetiteOAM_Phase4_Frame3,
    3,
    sZebetiteOAM_Phase4_Frame4,
    3,
    sZebetiteOAM_Phase4_Frame5,
    3,
    NULL,
    0
};

static const struct FrameData sZebetiteOAM_Phase6[7] = {
    sZebetiteOAM_Phase6_Frame0,
    3,
    sZebetiteOAM_Phase6_Frame1,
    3,
    sZebetiteOAM_Phase6_Frame2,
    3,
    sZebetiteOAM_Phase6_Frame3,
    3,
    sZebetiteOAM_Phase6_Frame4,
    3,
    sZebetiteOAM_Phase6_Frame5,
    3,
    NULL,
    0
};


// Cannon OAM

#endif