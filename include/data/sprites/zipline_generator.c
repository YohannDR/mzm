#ifndef ZIPLINE_GENERATOR_DATA_C
#define ZIPLINE_GENERATOR_DATA_C

#include "types.h"
#include "oam.h"

static const u32 sZiplineGeneratorGFX[1124];
static const u16 sZiplineGeneratorPAL[64];

static const u16 sZiplineGeneratorPartOAM_ConductorDeactivated_Frame0[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x204,
    0xc0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x206,
    0xf8, 0x1e0, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x23f
};

static const u16 sZiplineGeneratorPartOAM_ConductorActivating_Frame1[52] = {
    0x11,
    0xae, 0x1fc, OBJ_SPRITE_OAM | 0x2ae,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_8x32 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    0xc0, 0x1e9, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xa8, 0xf, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x26e,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x204,
    0xc0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x206,
    0xf8, 0x1e0, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x23f
};

static const u16 sZiplineGeneratorPartOAM_ConductorActivating_Frame2[52] = {
    0x11,
    0xae, 0x1fc, OBJ_SPRITE_OAM | 0x2b1,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_8x32 | 0x1e9, OBJ_SPRITE_OAM | 0x211,
    0xc0, 0x1e9, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_VERTICAL | 0xa8, 0xf, OBJ_SPRITE_OAM | 0x2d1,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x271,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x204,
    0xc0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x206,
    0xf8, 0x1e0, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x23f
};

static const u16 sZiplineGeneratorPartOAM_ConductorActivating_Frame3[52] = {
    0x11,
    0xae, 0x1fc, OBJ_SPRITE_OAM | 0x2b4,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_8x32 | 0x1e9, OBJ_SPRITE_OAM | 0x214,
    0xc0, 0x1e9, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x295,
    OBJ_SHAPE_VERTICAL | 0xa8, 0xf, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x204,
    0xc0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x206,
    0xf8, 0x1e0, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x23f
};

static const u16 sZiplineGeneratorOAM_Deactivated_Frame0[19] = {
    0x6,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    0xe0, 0x8, OBJ_SPRITE_OAM | 0x22d
};

static const u16 sZiplineGeneratorOAM_Activating_Frame1[31] = {
    0xa,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x286,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2cf,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x2c8,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    0xe0, 0x8, OBJ_SPRITE_OAM | 0x22d
};

static const u16 sZiplineGeneratorOAM_Activating_Frame2[31] = {
    0xa,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x288,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2d2,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x2cc,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    0xe0, 0x8, OBJ_SPRITE_OAM | 0x22d
};

static const u16 sZiplineGeneratorOAM_Activating_Frame3[31] = {
    0xa,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2d5,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x2bc,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    0xe0, 0x8, OBJ_SPRITE_OAM | 0x22d
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21d
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame4[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame5[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x24c
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame1[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame5[4] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

static const u16 sZiplineGeneratorPartOAM_ElectricityActivating_Frame7[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1277
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1278
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x1257
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame3[4] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1278
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x12dc
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame5[16] = {
    0x5,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12fa,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame6[16] = {
    0x5,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12f9,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c
};

static const u16 sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame7[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12f8
};

static const struct FrameData sZiplineGeneratorPartOAM_ConductorDeactivated[2] = {
    sZiplineGeneratorPartOAM_ConductorDeactivated_Frame0,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorOAM_Deactivated[2] = {
    sZiplineGeneratorOAM_Deactivated_Frame0,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorPartOAM_ConductorActivating[7] = {
    sZiplineGeneratorPartOAM_ConductorDeactivated_Frame0,
    0xC,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame1,
    0x6,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame2,
    0x5,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame3,
    0x5,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame2,
    0x5,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame1,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorOAM_Activating[7] = {
    sZiplineGeneratorOAM_Deactivated_Frame0,
    0xC,
    sZiplineGeneratorOAM_Activating_Frame1,
    0x6,
    sZiplineGeneratorOAM_Activating_Frame2,
    0x5,
    sZiplineGeneratorOAM_Activating_Frame3,
    0x5,
    sZiplineGeneratorOAM_Activating_Frame2,
    0x5,
    sZiplineGeneratorOAM_Activating_Frame1,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorPartOAM_ConductorActivated[7] = {
    sZiplineGeneratorPartOAM_ConductorDeactivated_Frame0,
    0x10,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame1,
    0x10,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame2,
    0xC,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame3,
    0xA,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame2,
    0xC,
    sZiplineGeneratorPartOAM_ConductorActivating_Frame1,
    0x10,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorOAM_Activated[7] = {
    sZiplineGeneratorOAM_Deactivated_Frame0,
    0x10,
    sZiplineGeneratorOAM_Activating_Frame1,
    0x10,
    sZiplineGeneratorOAM_Activating_Frame2,
    0xC,
    sZiplineGeneratorOAM_Activating_Frame3,
    0xA,
    sZiplineGeneratorOAM_Activating_Frame2,
    0xC,
    sZiplineGeneratorOAM_Activating_Frame1,
    0x10,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorPartOAM_MorphSymbolActivating[7] = {
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame0,
    0x4,
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame1,
    0x4,
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame2,
    0x4,
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame3,
    0x4,
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame4,
    0x4,
    sZiplineGeneratorPartOAM_MorphSymbolActivating_Frame5,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorPartOAM_MorphSymbolActivated[9] = {
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame0,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame1,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame2,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame3,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame4,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame5,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame6,
    0x2,
    sZiplineGeneratorPartOAM_MorphSymbolActivated_Frame7,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sZiplineGeneratorPartOAM_ElectricityActivating[12] = {
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame0,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame1,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame2,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame3,
    0xA,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame4,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame5,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame3,
    0xA,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame7,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame3,
    0xA,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame0,
    0x3,
    sZiplineGeneratorPartOAM_ElectricityActivating_Frame4,
    0x3,
    NULL,
    0x0
};

#endif