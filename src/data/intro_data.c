#include "data/intro_data.h"

#include "oam.h"
#include "macros.h"
#include "constants/intro.h"

const u16 sIntroEmergencyOrderTextOAM[OAM_DATA_SIZE(17)] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1b8, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1c0, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1c8, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1d0, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1d8, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1e0, 0x100a,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1e8, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1f0, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1f8, 0x1006,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x0, 0x1017,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x8, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x10, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x18, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x20, 0x1007,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x28, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x30, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x38, 0x101c
};

const u16 sIntroExterminateAllTextOAM[OAM_DATA_SIZE(54)] = {
    0x36,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x198, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1a0, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1a8, 0x1016,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1b0, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1b8, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1c0, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1c8, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1d0, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1d8, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1e0, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1e8, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1f0, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1f8, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x0, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x8, 0x100d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x10, 0x100d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x18, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x20, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x28, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x30, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x38, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x40, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x48, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x50, 0x1007,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x58, 0x101c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x188, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x190, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x198, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1a0, 0x100a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1a8, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1b0, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1b8, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1c0, 0x1013,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1c8, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1d0, 0x1013,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1d8, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1e0, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1e8, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1f0, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1f8, 0x1011,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x0, 0x100d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x8, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x10, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x18, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x20, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x28, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x30, 0x1018,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x38, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x40, 0x1005,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x48, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x50, 0x1013,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x58, 0x101e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x60, 0x101f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x68, 0x101f
};

const u16 sIntroDefeatTheTextOAM[OAM_DATA_SIZE(52)] = {
    0x34,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x198, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1a0, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1a8, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1b0, 0x1007,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1b8, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1c0, 0x1007,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1c8, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1d0, 0x1009,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1d8, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1e0, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1e8, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1f0, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1f8, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x0, 0x100b,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x8, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x10, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x18, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x20, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x28, 0x1006,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x30, 0x100b,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x38, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x40, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x48, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x50, 0x1006,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x58, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x60, 0x100d,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x68, 0x101c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1a0, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1a8, 0x100d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1b0, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1b8, 0x1009,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1c0, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1c8, 0x105e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1d0, 0x1009,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1d8, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1e0, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1e8, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1f0, 0x105d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1f8, 0x1003,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x0, 0x100e,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x8, 0x1010,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x10, 0x1014,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x18, 0x100b,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x20, 0x1008,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x28, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x30, 0x101d,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x38, 0x1005,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x40, 0x1012,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x48, 0x1004,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x50, 0x100c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x58, 0x100f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x60, 0x105f
};

const u16 sIntroTextMarkerOAM[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, 0x1f8, 0x1020,
    0xf8, 0x0, 0x1021,
    0xf8, 0x8, 0x1022
};

const u16 sIntroShipFlyingTowardsCameraOam_1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xd8, OBJ_SIZE_64x64 | 0x1c0, 0x3041,
    0xd8, OBJ_SIZE_64x64 | 0x0, 0x3049,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1b8, 0x3100,
    OBJ_SHAPE_VERTICAL | 0x8, 0x40, 0x3111,
    OBJ_MODE_SEMI_TRANSPARENT | 0xd8, OBJ_SIZE_64x64 | 0x1c8, 0x4052,
    OBJ_MODE_SEMI_TRANSPARENT | 0xd8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x1f8, 0x4052
};

const u16 sIntroShipFlyingTowardsCameraOam_2[OAM_DATA_SIZE(9)] = {
    0x9,
    0xd8, OBJ_SIZE_64x64 | 0x1c0, 0x3041,
    0xd8, OBJ_SIZE_64x64 | 0x0, 0x3049,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, 0x3147,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x1b8, 0x3080,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x40, 0x3091,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1b8, 0x3100,
    OBJ_SHAPE_VERTICAL | 0x8, 0x40, 0x3111,
    OBJ_MODE_SEMI_TRANSPARENT | 0xd8, OBJ_SIZE_64x64 | 0x1c8, 0x4160,
    OBJ_MODE_SEMI_TRANSPARENT | 0xd8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x1f8, 0x4160
};

const u16 sIntroViewOfZebesShipOAM[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1f0, 0x3040,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x30, 0x3048,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x30c0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x10, 0x30c4
};

const u16 sIntroViewOfZebesHeatOAM_2[OAM_DATA_SIZE(12)] = {
    0xc,
    0xa0, OBJ_SIZE_64x64 | 0x0, 0x4050,
    0xa0, OBJ_SIZE_64x64 | 0x40, 0x4058,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e8, 0x410d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f8, 0x410f,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1e8, 0x418d,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, 0x418f,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x0, 0x4150,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x40, 0x4158,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, 0x41d0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x20, 0x41d4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x40, 0x41d8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x60, 0x41dc
    
};

const u16 sIntroViewOfZebesHeatOAM_1[OAM_DATA_SIZE(24)] = {
    0x18,
    OBJ_SHAPE_HORIZONTAL | 0xa0, OBJ_SIZE_64x32 | 0x0, 0x4210,
    OBJ_SHAPE_HORIZONTAL | 0xa0, OBJ_SIZE_64x32 | 0x40, 0x4218,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x0, 0x4290,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x20, 0x4294,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x40, 0x4298,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x60, 0x429c,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x8 | 0x0, 0x42d0,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x8 | 0x20, 0x42d4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x8 | 0x40, 0x42d8,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x8 | 0x60, 0x42dc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e8, 0x42cd,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f8, 0x42cf,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1e8, 0x434d,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, 0x434f,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x0, 0x42f0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x40, 0x42f8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x4370,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x20, 0x4374,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x40, 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x60, 0x437c,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x0, 0x43b0,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x20, 0x43b4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x40, 0x43b8,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x60, 0x43bc
};

const u16 sIntroFuzzOAM[OAM_DATA_SIZE(17)] = {
    0x11,
    0x80, OBJ_SIZE_64x64 | 0x180, 0x0,
    0x80, OBJ_SIZE_64x64 | 0x1c0, 0x8,
    0x80, OBJ_SIZE_64x64 | 0x0, 0x10,
    OBJ_SHAPE_VERTICAL | 0x80, OBJ_SIZE_32x64 | 0x40, 0x18,
    OBJ_SHAPE_VERTICAL | 0x80, OBJ_SIZE_16x32 | 0x60, 0x1c,
    OBJ_SHAPE_VERTICAL | 0xa0, OBJ_SIZE_16x32 | 0x60, 0x9c,
    0xc0, OBJ_SIZE_64x64 | 0x180, 0x100,
    0xc0, OBJ_SIZE_64x64 | 0x1c0, 0x108,
    0xc0, OBJ_SIZE_64x64 | 0x0, 0x110,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_32x64 | 0x40, 0x118,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x60, 0x11c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x60, 0x19c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x180, 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x1c0, 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x0, 0x210,
    0x0, OBJ_SIZE_32x32 | 0x40, 0x218,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x60, 0x21c
};

const u16 sIntroTextAndShipPal[16 * 6] = INCBIN_U16("data/intro/TextAndShip.pal");
const u16 sIntroPal_45f9d4[16 * 1] = INCBIN_U16("data/intro/45f9d4.pal");
const u16 sIntroSamusInHerShipPal[16 * 5] = INCBIN_U16("data/intro/SamusInHerShip.pal");
const u16 sIntroViewOfZebesPal[16 * 10] = INCBIN_U16("data/intro/ViewOfZebes.pal");
const u16 sIntroMotherBrainPal[16 * 5] = INCBIN_U16("data/intro/MotherBrain.pal");


const u8 sIntroFuzzRandomValues_1[64] = {
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 239, 61,
    181, 86, 255, 127, 239, 61, 255, 127, 255, 127, 239, 61, 239, 61,
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 255, 127,
    255, 127, 49, 70, 255, 127, 181, 86, 49, 70, 239, 61, 255, 127
};

const u8 sIntroFuzzRandomValues_2[64] = {
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 239, 61,
    49, 70, 255, 127, 239, 61, 255, 127, 49, 70, 255, 127, 49, 70, 31,
    0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 255, 127, 49,
    70, 255, 127, 181, 86, 239, 61, 156, 115, 255, 127, 255, 127
};

const u8 sTimeAttackPasswordCharacters[32] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '#',
    '?', 'C', '%', 'F', 'H', 'J', 'K', 'L', 'M', 'N', 'P',
    'Q', 'R', 'T', 'V', 'W', 'X', 'Y', '=', '-', '+'
};

const u32 sTimeAttackAntiCheatTimes[4] = {
    0 | 0 << 8 | 5 << 16  | 0 << 24,
    0 | 0 << 8 | 10 << 16 | 0 << 24,
    0 | 0 << 8 | 16 << 16 | 0 << 24,
    0 | 0 << 8 | 22 << 16 | 0 << 24
};

const u8 sSpriteXHalfRadius[3][4] = {
    [OAM_SHAPE_SQUARE] = {
        [OAM_SIZE_S_8x8] = 8/2,
        [OAM_SIZE_S_16x16] = 16/2,
        [OAM_SIZE_S_32x32] = 32/2,
        [OAM_SIZE_S_64x64] = 64/2
    },
    [OAM_SHAPE_HORIZONTAL] = {
        [OAM_SIZE_H_16x8] = 16/2,
        [OAM_SIZE_H_32x8] = 32/2,
        [OAM_SIZE_H_32x16] = 32/2,
        [OAM_SIZE_H_64x32] = 64/2
    },
    [OAM_SHAPE_VERTICAL] = {
        [OAM_SIZE_V_8x16] = 8/2,
        [OAM_SIZE_V_8x32] = 8/2,
        [OAM_SIZE_V_16x32] = 16/2,
        [OAM_SIZE_V_32x64] = 32/2
    }
};

const u8 sSpriteYHalfRadius[3][4] = {
    [OAM_SHAPE_SQUARE] = {
        [OAM_SIZE_S_8x8] = 8/2,
        [OAM_SIZE_S_16x16] = 16/2,
        [OAM_SIZE_S_32x32] = 32/2,
        [OAM_SIZE_S_64x64] = 64/2
    },
    [OAM_SHAPE_HORIZONTAL] = {
        [OAM_SIZE_H_16x8] = 8/2,
        [OAM_SIZE_H_32x8] = 8/2,
        [OAM_SIZE_H_32x16] =16/2,
        [OAM_SIZE_H_64x32] = 32/2
    },
    [OAM_SHAPE_VERTICAL] = {
        [OAM_SIZE_V_8x16] = 16/2,
        [OAM_SIZE_V_8x32] = 32/2,
        [OAM_SIZE_V_16x32] = 32/2,
        [OAM_SIZE_V_32x64] = 64/2
    }
};

const u8 sIntroEmergencyOrderActions[16] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // M
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // R
    INTRO_TEXT_ACTION_NONE,            // G
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // N
    INTRO_TEXT_ACTION_NONE,            // C
    INTRO_TEXT_ACTION_NONE,            // Y
    INTRO_TEXT_ACTION_SPACE,           // 
    INTRO_TEXT_ACTION_NONE,            // O
    INTRO_TEXT_ACTION_NONE,            // R
    INTRO_TEXT_ACTION_NONE,            // D
    INTRO_TEXT_ACTION_SKIP_CHARACTER,  // E
    INTRO_TEXT_ACTION_END,             // R
};

const u8 sIntroExterminateAllActions[52] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // X
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // I
    INTRO_TEXT_ACTION_NEW_LINE,         // D
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // G
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // P
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // Z
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // B
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_NONE,             // .
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // .
    INTRO_TEXT_ACTION_END,              // .
};

const u8 sIntroDefeatTheActions[50] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // D
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // D
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // C
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // C
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // A
    INTRO_TEXT_ACTION_NEW_LINE,         // 
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // -
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // ,
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // B
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // N
    INTRO_TEXT_ACTION_END,              // .
};


const u32 sIntroTextAndShipFlyingInGfx[1310] = INCBIN_U32("data/intro/TextAndShip.gfx.lz");
const u32 sIntroSpaceBackgroundGfx[3181] = INCBIN_U32("data/intro/SpaceBackground.gfx.lz");
const u32 sIntroSpaceBackgroundTileTable[577] = INCBIN_U32("data/intro/SpaceBackground.tt");
const u32 sIntroSamusInHerShipGfx[4800] = INCBIN_U32("data/intro/SamusInHerShip.gfx.lz");
const u32 sIntroSamusInHerShipTileTable[418] = INCBIN_U32("data/intro/SamusInHerShip.tt");
const u32 sIntroSamusShipViewOfZebesGfx[1224] = INCBIN_U32("data/intro/SamusShipViewOfZebes.gfx.lz");
const u32 sIntroViewOfZebesGfx[2986] = INCBIN_U32("data/intro/ViewOfZebes.gfx.lz");
const u32 sIntroViewOfZebesTileTable[577] = INCBIN_U32("data/intro/ViewOfZebes.tt");
const u32 sIntroMotherBrainGfx[5004] = INCBIN_U32("data/intro/MotherBrain.gfx.lz");
const u32 sIntroMotherBrainTileTable[577] = INCBIN_U32("data/intro/MotherBrain.tt");
const u32 sIntroFuzzGfx[5224] = INCBIN_U32("data/intro/Fuzz.gfx.lz");
const u32 sIntro_47920c[125] = INCBIN_U32("data/intro/47920c.tt");

