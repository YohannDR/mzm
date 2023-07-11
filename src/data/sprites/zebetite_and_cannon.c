#include "data/sprites/zebetite_and_cannon.h"
#include "macros.h"

const u32 sRinkaZebetiteAndCannonGfx[476] = INCBIN_U32("data/sprites/ZebetiteRinkaCannon.gfx.lz");
const u16 sRinkaZebetiteAndCannonPAL[32] = INCBIN_U16("data/sprites/ZebetiteRinkaCannon.pal");

const u16 sRinkaMotherBrainOAM_Moving_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1200
};

const u16 sRinkaMotherBrainOAM_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1201,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1201
};

const u16 sRinkaMotherBrainOAM_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1202
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1203,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1203
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1204
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1205
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1206,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1206
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1240,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x1241,
    0x8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1241,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x1261,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x1261
};

const u16 sRinkaMotherBrainOAM_Spawning_Frame5[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1242,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x1243,
    0x8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1243,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x1263,
    0xfc, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x1263
};

const u16 sZebetiteOam_Phase1_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

const u16 sZebetiteOam_Phase1_Frame1[25] = {
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

const u16 sZebetiteOam_Phase1_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase1_Frame3[25] = {
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

const u16 sZebetiteOam_Phase1_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZebetiteOam_Phase1_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase2_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

const u16 sZebetiteOam_Phase2_Frame1[25] = {
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

const u16 sZebetiteOam_Phase2_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase2_Frame3[25] = {
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

const u16 sZebetiteOam_Phase2_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZebetiteOam_Phase2_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase4_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

const u16 sZebetiteOam_Phase4_Frame1[25] = {
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

const u16 sZebetiteOam_Phase4_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase4_Frame3[25] = {
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

const u16 sZebetiteOam_Phase4_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZebetiteOam_Phase4_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase6_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209
};

const u16 sZebetiteOam_Phase6_Frame1[25] = {
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

const u16 sZebetiteOam_Phase6_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sZebetiteOam_Phase6_Frame3[25] = {
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

const u16 sZebetiteOam_Phase6_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZebetiteOam_Phase6_Frame5[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x211,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sCannonOam_AimingLeft_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x207
};

const u16 sCannonOam_ShootingLeft_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0xfc, 0x1f1, OBJ_SPRITE_OAM | 0x25b
};

const u16 sCannonOam_ShootingLeft_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0xfc, 0x1f2, OBJ_SPRITE_OAM | 0x25b
};

const u16 sCannonOam_LeftToDownLeftTransition_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f0, OBJ_SPRITE_OAM | 0x267
};

const u16 sCannonOam_AimingDownLeft_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0x5, 0x1f3, OBJ_SPRITE_OAM | 0x228
};

const u16 sCannonOam_ShootingDownLeft_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0x4, 0x1f4, OBJ_SPRITE_OAM | 0x248
};

const u16 sCannonOam_ShootingDownLeft_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0x3, 0x1f5, OBJ_SPRITE_OAM | 0x248
};

const u16 sCannonOam_DownLeftToDownTransition_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f9, OBJ_SPRITE_OAM | 0x227
};

const u16 sCannonOam_AimingDown_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0x8, 0x1fc, OBJ_SPRITE_OAM | 0x208
};

const u16 sCannonOam_ShootingDown_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0x7, 0x1fc, OBJ_SPRITE_OAM | 0x27b
};

const u16 sCannonOam_ShootingDown_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0x6, 0x1fc, OBJ_SPRITE_OAM | 0x27b
};

const u16 sCannonOam_DownToDownRightTransition_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x227
};

const u16 sCannonOam_AimingDownRight_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0x5, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x228
};

const u16 sCannonOam_ShootingDownRight_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0x4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x248
};

const u16 sCannonOam_ShootingDownRight_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0x3, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x248
};

const u16 sCannonOam_RightToRightTransition_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x267
};

const u16 sCannonOam_AimingRight_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207
};

const u16 sCannonOam_ShootingRight_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0xfc, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x25b
};

const u16 sCannonOam_ShootingRight_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c,
    0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x25b
};

const u16 sCannonBulletOam_Left_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sCannonBulletOam_Left_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1264
};

const u16 sCannonBulletOam_DownLeft_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1245
};

const u16 sCannonBulletOam_DownLeft_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1265
};

const u16 sCannonBulletOam_Down_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1246
};

const u16 sCannonBulletOam_Down_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1266
};

const u16 sCannonBulletOam_DownRight_Frame0[4] = {
    0x1,
    0xfc, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1245
};

const u16 sCannonBulletOam_DownRight_Frame1[4] = {
    0x1,
    0xfc, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1265
};

const u16 sCannonBulletOam_Right_Frame0[4] = {
    0x1,
    0xfc, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sCannonBulletOam_Right_Frame1[4] = {
    0x1,
    0xfc, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1264
};

const u16 sMotherBrainBlockOAM_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x1f8, OBJ_SPRITE_OAM | 0x23e
};

const u16 sMotherBrainBlockOAM_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x1f8, OBJ_SPRITE_OAM | 0x23e
};

const u16 sMotherBrainBlockOAM_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1f8, OBJ_SPRITE_OAM | 0x23e
};

const u16 sMotherBrainBlockOAM_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};



const struct FrameData sRinkaMotherBrainOAM_Spawning[16] = {
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

const struct FrameData sRinkaMotherBrainOAM_Moving[5] = {
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

const struct FrameData sZebetiteOam_Phase1[7] = {
    sZebetiteOam_Phase1_Frame0,
    3,
    sZebetiteOam_Phase1_Frame1,
    3,
    sZebetiteOam_Phase1_Frame2,
    3,
    sZebetiteOam_Phase1_Frame3,
    3,
    sZebetiteOam_Phase1_Frame4,
    3,
    sZebetiteOam_Phase1_Frame5,
    3,
    NULL,
    0
};

const struct FrameData sZebetiteOam_Phase2[7] = {
    sZebetiteOam_Phase2_Frame0,
    3,
    sZebetiteOam_Phase2_Frame1,
    3,
    sZebetiteOam_Phase2_Frame2,
    3,
    sZebetiteOam_Phase2_Frame3,
    3,
    sZebetiteOam_Phase2_Frame4,
    3,
    sZebetiteOam_Phase2_Frame5,
    3,
    NULL,
    0
};

const struct FrameData sZebetiteOam_Phase4[7] = {
    sZebetiteOam_Phase4_Frame0,
    3,
    sZebetiteOam_Phase4_Frame1,
    3,
    sZebetiteOam_Phase4_Frame2,
    3,
    sZebetiteOam_Phase4_Frame3,
    3,
    sZebetiteOam_Phase4_Frame4,
    3,
    sZebetiteOam_Phase4_Frame5,
    3,
    NULL,
    0
};

const struct FrameData sZebetiteOam_Phase6[7] = {
    sZebetiteOam_Phase6_Frame0,
    3,
    sZebetiteOam_Phase6_Frame1,
    3,
    sZebetiteOam_Phase6_Frame2,
    3,
    sZebetiteOam_Phase6_Frame3,
    3,
    sZebetiteOam_Phase6_Frame4,
    3,
    sZebetiteOam_Phase6_Frame5,
    3,
    NULL,
    0
};

const struct FrameData sCannonOam_AimingLeft[2] = {
    sCannonOam_AimingLeft_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const struct FrameData sCannonOam_ShootingLeft[4] = {
    sCannonOam_AimingLeft_Frame0,
    16,
    sCannonOam_ShootingLeft_Frame1,
    2,
    sCannonOam_ShootingLeft_Frame2,
    2,
    NULL,
    0
};

const struct FrameData sCannonOam_LeftToDownLeftTransition[2] = {
    sCannonOam_LeftToDownLeftTransition_Frame0,
    3,
    NULL,
    0
};

const struct FrameData sCannonOam_AimingDownLeft[2] = {
    sCannonOam_AimingDownLeft_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const struct FrameData sCannonOam_ShootingDownLeft[4] = {
    sCannonOam_AimingDownLeft_Frame0,
    16,
    sCannonOam_ShootingDownLeft_Frame1,
    2,
    sCannonOam_ShootingDownLeft_Frame2,
    2,
    NULL,
    0
};

const struct FrameData sCannonOam_DownLeftToDownTransition[2] = {
    sCannonOam_DownLeftToDownTransition_Frame0,
    3,
    NULL,
    0
};

const struct FrameData sCannonOam_AimingDown[2] = {
    sCannonOam_AimingDown_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const struct FrameData sCannonOam_ShootingDown[4] = {
    sCannonOam_AimingDown_Frame0,
    16,
    sCannonOam_ShootingDown_Frame1,
    2,
    sCannonOam_ShootingDown_Frame2,
    2,
    NULL,
    0
};

const struct FrameData sCannonOam_DownToDownRightTransition[2] = {
    sCannonOam_DownToDownRightTransition_Frame0,
    3,
    NULL,
    0
};

const struct FrameData sCannonOam_AimingDownRight[2] = {
    sCannonOam_AimingDownRight_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const struct FrameData sCannonOam_ShootingDownRight[4] = {
    sCannonOam_AimingDownRight_Frame0,
    16,
    sCannonOam_ShootingDownRight_Frame1,
    2,
    sCannonOam_ShootingDownRight_Frame2,
    2,
    NULL,
    0
};

const struct FrameData sCannonOam_DownRightToRightTransition[2] = {
    sCannonOam_RightToRightTransition_Frame0,
    3,
    NULL,
    0
};

const struct FrameData sCannonOam_AimingRight[2] = {
    sCannonOam_AimingRight_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const struct FrameData sCannonOam_ShootingRight[4] = {
    sCannonOam_AimingRight_Frame0,
    16,
    sCannonOam_ShootingRight_Frame1,
    2,
    sCannonOam_ShootingRight_Frame2,
    2,
    NULL,
    0
};

const struct FrameData sCannonBulletOam_Left[3] = {
    sCannonBulletOam_Left_Frame0,
    3,
    sCannonBulletOam_Left_Frame1,
    3,
    NULL,
    0
};

const struct FrameData sCannonBulletOam_DownLeft[3] = {
    sCannonBulletOam_DownLeft_Frame0,
    3,
    sCannonBulletOam_DownLeft_Frame1,
    3,
    NULL,
    0
};

const struct FrameData sCannonBulletOam_Down[3] = {
    sCannonBulletOam_Down_Frame0,
    3,
    sCannonBulletOam_Down_Frame1,
    3,
    NULL,
    0
};

const struct FrameData sCannonBulletOam_DownRight[3] = {
    sCannonBulletOam_DownRight_Frame0,
    3,
    sCannonBulletOam_DownRight_Frame1,
    3,
    NULL,
    0
};

const struct FrameData sCannonBulletOam_Right[3] = {
    sCannonBulletOam_Right_Frame0,
    3,
    sCannonBulletOam_Right_Frame1,
    3,
    NULL,
    0
};

const struct FrameData sMotherBrainBlockOAM[5] = {
    sMotherBrainBlockOAM_Frame0,
    4,
    sMotherBrainBlockOAM_Frame1,
    4,
    sMotherBrainBlockOAM_Frame2,
    4,
    sMotherBrainBlockOAM_Frame3,
    UCHAR_MAX,
    NULL,
    0
};

