#include "data/sprites/zipline_generator.h"
#include "macros.h"

const u32 sZiplineGeneratorGfx[1124] = INCBIN_U32("data/sprites/ZiplineGenerator.gfx.lz");
const u16 sZiplineGeneratorPal[64] = INCBIN_U16("data/sprites/ZiplineGenerator.pal");

const u16 sZiplineGeneratorPartOam_ConductorDeactivated_Frame0[OAM_DATA_SIZE(10)] = {
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

const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame1[OAM_DATA_SIZE(17)] = {
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

const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame2[OAM_DATA_SIZE(17)] = {
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

const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame3[OAM_DATA_SIZE(17)] = {
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

const u16 sZiplineGeneratorOam_Deactivated_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    0xd0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    0xd0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    0xe0, 0x8, OBJ_SPRITE_OAM | 0x22d
};

const u16 sZiplineGeneratorOam_Activating_Frame1[OAM_DATA_SIZE(10)] = {
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

const u16 sZiplineGeneratorOam_Activating_Frame2[OAM_DATA_SIZE(10)] = {
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

const u16 sZiplineGeneratorOam_Activating_Frame3[OAM_DATA_SIZE(10)] = {
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

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21d
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x24c
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1277
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1278
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x1257
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1278
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x12dc
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12fa,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12f9,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28c
};

const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x12f8
};

const struct FrameData sZiplineGeneratorPartOam_ConductorDeactivated[2] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Deactivated[2] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ConductorActivating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Activating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ConductorActivated[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Activated[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_MorphSymbolActivating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_MorphSymbolActivated[9] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ElectricityActivating[12] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = FRAME_DATA_TERMINATOR
};
