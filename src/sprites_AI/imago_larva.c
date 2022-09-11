#include "imago_larva.h"
#include "../sprite_util.h" // sprite_util.h include is REQUIRED
#include "../../data/data.h"
#include "../globals.h"

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame0[18] = {
    4, 0, 0,
    13, -140, -72,
    12, -116, -108,
    11, -72, -124,
    0, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame1[18] = {
    4, -4, 0,
    13, -144, -72,
    12, -120, -108,
    11, -72, -124,
    0, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame2[18] = {
    4, 4, -47,
    13, -136, -72,
    12, -112, -108,
    11, -72, -132,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame3[18] = {
    4, 0, 0,
    13, -140, -72,
    12, -116, -108,
    11, -72, -124,
    0, 0, 0,
    18, 0, 4
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame4[18] = {
    4, 0, -8,
    13, -140, -72,
    12, -116, -108,
    11, -72, -128,
    0, 0, 0,
    18, 0, 4
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame5[18] = {
    4, 0, -4,
    13, -140, -72,
    12, -116, -112,
    11, -72, -140,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame6[18] = {
    4, 0, 0,
    13, -136, -76,
    12, -108, -112,
    11, -68, -140,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame7[18] = {
    4, 4, -4,
    13, -136, -80,
    12, -108, -116,
    11, -68, -140,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame8[18] = {
    4, -4, 0,
    13, -140, -80,
    12, -112, -116,
    11, -68, -136,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame9[18] = {
    4, -4, 0,
    13, -140, -76,
    12, -112, -112,
    11, -68, -132,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Attacking_Frame10[18] = {
    4, 0, 4,
    13, -140, -76,
    12, -112, -108,
    11, -68, -128,
    0, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Idle_Frame0[18] = {
    5, 0, 0,
    13, -140, -72,
    12, -116, -108,
    11, -72, -128,
    1, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Idle_Frame1[18] = {
    5, 0, -8,
    13, -136, -72,
    12, -116, -108,
    11, -72, -132,
    1, 0, 0,
    18, 0, -12
};

const i16 sImagoLarvaMultiSpriteData_Idle_Frame2[18] = {
    5, 0, -16,
    13, -136, -72,
    12, -116, -108,
    11, -72, -136,
    1, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame0[18] = {
    6, 0, 4,
    13, -140, -76,
    12, -112, -108,
    11, -68, -120,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame1[18] = {
    6, -4, 0,
    13, -140, -76,
    12, -112, -112,
    11, -68, -124,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame2[18] = {
    6, -4, 0,
    13, -140, -80,
    12, -112, -116,
    11, -68, -128,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame3[18] = {
    6, 4, -4,
    13, -136, -80,
    12, -112, -116,
    11, -68, -136,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame4[18] = {
    6, 0, 0,
    13, -136, -76,
    12, -108, -112,
    11, -68, -132,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame5[18] = {
    6, 0, -4,
    13, -140, -72,
    12, -116, -112,
    11, -72, -136,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame6[18] = {
    6, 0, -8,
    13, -140, -72,
    12, -116, -108,
    11, -72, -136,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame7[18] = {
    6, 0, -4,
    13, -140, -72,
    12, -116, -108,
    11, -72, -132,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame8[18] = {
    6, 4, -4,
    13, -140, -72,
    12, -116, -108,
    11, -72, -128,
    2, 0, 0,
    18, 0, -16
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame9[18] = {
    6, -4, 0,
    13, -144, -72,
    12, -120, -108,
    11, -68, -120,
    2, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Retreating_Frame10[18] = {
    6, 0, 0,
    13, -140, -72,
    12, -116, -108,
    11, -68, -116,
    2, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Dying_Frame0[18] = {
    7, 0, 0,
    13, -140, -72,
    12, -116, -108,
    11, -72, -124,
    3, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Dying_Frame1[18] = {
    7, -4, 0,
    13, -144, -72,
    12, -120, -112,
    11, -76, -128,
    3, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Dying_Frame2[18] = {
    7, -8, -4,
    13, -148, -72,
    12, -124, -112,
    11, -84, -132,
    3, 0, 0,
    18, -4, -4
};

const i16 sImagoLarvaMultiSpriteData_Dying_Frame5[18] = {
    7, 4, 0,
    13, -140, -68,
    12, -112, -108,
    11, -68, -124,
    3, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Dying_Frame6[18] = {
    7, 8, 4,
    13, -136, -68,
    12, -108, -104,
    11, -64, -124,
    3, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_Warning_Frame0[18] = {
    19, -16, 0,
    13, -148, -64,
    12, -124, -100,
    11, -84, -120,
    17, 0, 0,
    21, 0, -20
};

const i16 sImagoLarvaMultiSpriteData_Warning_Frame1[18] = {
    19, -20, 4,
    13, -156, -64,
    12, -132, -100,
    11, -92, -120,
    17, 0, 0,
    21, 0, -20
};

const i16 sImagoLarvaMultiSpriteData_Warning_Frame2[18] = {
    20, -24, 4,
    13, -160, -60,
    12, -136, -96,
    11, -96, -116,
    17, 0, 0,
    21, 0, -20
};

const i16 sImagoLarvaMultiSpriteData_Warning_Frame3[18] = {
    20, -24, 0,
    13, -164, -60,
    12, -140, -96,
    11, -100, -120,
    17, 0, 0,
    21, 0, -20
};

const i16 sImagoLarvaMultiSpriteData_TakingDamage_Frame0[18] = {
    7, -4, 0,
    13, -140, -68,
    12, -116, -104,
    11, -72, -124,
    22, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_TakingDamage_Frame1[18] = {
    7, 0, 0,
    13, -140, -68,
    12, -112, -104,
    11, -72, -124,
    22, 0, 0,
    18, 0, -4
};

const i16 sImagoLarvaMultiSpriteData_TakingDamage_Frame2[18] = {
    7, 4, 0,
    13, -136, -68,
    12, -108, -104,
    11, -64, -120,
    22, 0, 0,
    18, 0, -4
};

const struct FrameData sImagoLarvaMultiSpriteData_Attacking[12] = {
    sImagoLarvaMultiSpriteData_Attacking_Frame0,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame1,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame2,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame3,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame4,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame5,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame6,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame7,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame8,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame9,
    0x2,
    sImagoLarvaMultiSpriteData_Attacking_Frame10
};

const struct FrameData sImagoLarvaMultiSpriteData_Idle[5] = {
    sImagoLarvaMultiSpriteData_Idle_Frame0,
    0x18,
    sImagoLarvaMultiSpriteData_Idle_Frame1,
    0x18,
    sImagoLarvaMultiSpriteData_Idle_Frame2,
    0x18,
    sImagoLarvaMultiSpriteData_Idle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaMultiSpriteData_Retreating[12] = {
    sImagoLarvaMultiSpriteData_Retreating_Frame0,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame1,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame2,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame3,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame4,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame5,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame6,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame7,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame8,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame9,
    0x8,
    sImagoLarvaMultiSpriteData_Retreating_Frame10,
    0x8,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaMultiSpriteData_Dying[9] = {
    sImagoLarvaMultiSpriteData_Dying_Frame0,
    0x1,
    sImagoLarvaMultiSpriteData_Dying_Frame1,
    0x2,
    sImagoLarvaMultiSpriteData_Dying_Frame2,
    0x3,
    sImagoLarvaMultiSpriteData_Dying_Frame1,
    0x2,
    sImagoLarvaMultiSpriteData_Dying_Frame0,
    0x1,
    sImagoLarvaMultiSpriteData_Dying_Frame5,
    0x2,
    sImagoLarvaMultiSpriteData_Dying_Frame6,
    0x3,
    sImagoLarvaMultiSpriteData_Dying_Frame5,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaMultiSpriteData_Warning[10] = {
    sImagoLarvaMultiSpriteData_Warning_Frame0,
    0x2,
    sImagoLarvaMultiSpriteData_Warning_Frame1,
    0x2,
    sImagoLarvaMultiSpriteData_Warning_Frame2,
    0x3,
    sImagoLarvaMultiSpriteData_Warning_Frame3,
    0x4,
    sImagoLarvaMultiSpriteData_Warning_Frame2,
    0x4,
    sImagoLarvaMultiSpriteData_Warning_Frame3,
    0x4,
    sImagoLarvaMultiSpriteData_Warning_Frame2,
    0xE,
    sImagoLarvaMultiSpriteData_Warning_Frame1,
    0x3,
    sImagoLarvaMultiSpriteData_Warning_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaMultiSpriteData_TakingDamage[5] = {
    sImagoLarvaMultiSpriteData_TakingDamage_Frame0,
    0x6,
    sImagoLarvaMultiSpriteData_TakingDamage_Frame1,
    0x6,
    sImagoLarvaMultiSpriteData_TakingDamage_Frame2,
    0x6,
    sImagoLarvaMultiSpriteData_TakingDamage_Frame1,
    0x6,
    NULL,
    0x0
};

const u8 sImagoLarvaPaletteRows[4] = {
    1, 2, 1, 0
};

const u32 sImagoLarvaGFX[1195];
const u16 sImagoLarvaPAL[80];

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame0[82] = {
    0x1b,
    0xd6, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe5, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xef, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame1[82] = {
    0x1b,
    0xd5, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd3, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdb, 0x14, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x1c, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x21, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x25, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xee, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1d8, OBJ_SPRITE_OAM | 0x243,
    0xde, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x240,
    0xcf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x20f,
    0xee, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x1b, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1b, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2f, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame2[82] = {
    0x1b,
    0xd6, 0x1f4, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0xa, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x1c, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x22, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x26, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1b, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1c, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1c, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x14, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame3[82] = {
    0x1b,
    0xd7, 0x1f4, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0xa, OBJ_SPRITE_OAM | 0x202,
    0xdd, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1c, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x22, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x26, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xf1, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1de, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d6, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d3, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1b, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1c, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1c, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x14, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame4[82] = {
    0x1b,
    0xd8, 0x1f4, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xa, OBJ_SPRITE_OAM | 0x202,
    0xdd, 0x12, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x21, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x26, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xf1, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d5, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d1, OBJ_SPRITE_OAM | 0x240,
    0xd1, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1c, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1c, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x14, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame5[82] = {
    0x1b,
    0xd8, 0x1f3, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xa, OBJ_SPRITE_OAM | 0x202,
    0xdd, 0x12, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1a, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x25, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xf1, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1dd, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f5, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d4, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x240,
    0xd1, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1b, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame6[82] = {
    0x1b,
    0xd9, 0x1f2, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xa, OBJ_SPRITE_OAM | 0x202,
    0xdd, 0x11, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x19, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x1f, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x1e4, OBJ_SPRITE_OAM | 0x207,
    0xf2, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f4, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1d4, OBJ_SPRITE_OAM | 0x243,
    0xe0, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0xd1, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x19, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2f, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame7[82] = {
    0x1b,
    0xd9, 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0x1fd, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x9, OBJ_SPRITE_OAM | 0x202,
    0xdd, 0x10, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x19, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x1f, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x25, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x207,
    0xf2, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1db, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f3, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1db, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1d3, OBJ_SPRITE_OAM | 0x243,
    0xe0, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0xd1, OBJ_SIZE_32x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x18, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame8[82] = {
    0x1b,
    0xd8, 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0x1fd, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0x9, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x10, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x19, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x1f, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x207,
    0xf1, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1db, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f3, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1d5, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d3, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x18, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2f, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame9[82] = {
    0x1b,
    0xd7, 0x1f2, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0x1fd, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0x9, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x10, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x19, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x1f, OBJ_SPRITE_OAM | 0x204,
    0xe9, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e4, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f4, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x18, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2f, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellAttacking_Frame10[82] = {
    0x1b,
    0xd7, 0x1f3, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0x1fd, OBJ_SPRITE_OAM | 0x202,
    0xd7, 0x9, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x10, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x19, OBJ_SPRITE_OAM | 0x203,
    0xe3, 0x1e, OBJ_SPRITE_OAM | 0x204,
    0xe9, 0x23, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1dd, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f5, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1d8, OBJ_SPRITE_OAM | 0x243,
    0xdf, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x18, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x16, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x26, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ClawsWarningFirstPart_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e9, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e0, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xfa, 0x1f6, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e4, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1ec, OBJ_SPRITE_OAM | 0x2cf
};

const u16 sImagoLarvaPartOAM_ClawsWarningFirstPart_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1e8, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1e1, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1e5, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1ed, OBJ_SPRITE_OAM | 0x2cf
};

const u16 sImagoLarvaPartOAM_ClawsWarningSecondPart_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1e8, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1ed, OBJ_SPRITE_OAM | 0x2cf,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f2, OBJ_SPRITE_OAM | 0x217,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsWarningSecondPart_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e8, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1ed, OBJ_SPRITE_OAM | 0x2cf,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2ca,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x2c8,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f2, OBJ_SPRITE_OAM | 0x217,
    0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ShellWarning_Frame0[82] = {
    0x1b,
    0xd6, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe5, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xec, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xdd, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x240,
    0xce, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x19, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf8, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellWarning_Frame1[82] = {
    0x1b,
    0xd3, 0x1f6, OBJ_SPRITE_OAM | 0x202,
    0xd2, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd6, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xda, 0x12, OBJ_SPRITE_OAM | 0x203,
    0xdf, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe6, 0x21, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xca, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x207,
    0xea, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xca, OBJ_SIZE_8x32 | 0x1df, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xca, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xea, 0x1f7, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xd9, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xdc, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x240,
    0xcd, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x20f,
    0xec, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x19, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf9, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellWarning_Frame2[82] = {
    0x1b,
    0xd0, 0x1f7, OBJ_SPRITE_OAM | 0x202,
    0xd0, 0x0, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xda, 0x12, OBJ_SPRITE_OAM | 0x203,
    0xdf, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe5, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xea, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x207,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_SIZE_8x32 | 0x1e0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xd7, 0x1d8, OBJ_SPRITE_OAM | 0x243,
    0xd9, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x240,
    0xca, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xec, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf9, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellWarning_Frame3[82] = {
    0x1b,
    0xcf, 0x1f6, OBJ_SPRITE_OAM | 0x202,
    0xcf, 0x0, OBJ_SPRITE_OAM | 0x202,
    0xd3, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xde, 0x1c, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xe9, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xc7, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x207,
    0xe7, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xc7, OBJ_SIZE_8x32 | 0x1e0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xc7, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1f8, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xd6, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xd7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x240,
    0xc9, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x20f,
    0xeb, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_SIZE_8x32 | 0x1b, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xf9, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaOAM_Warning_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x22c2,
    0xe0, OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sImagoLarvaOAM_Warning_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x22c2,
    0xe0, OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sImagoLarvaOAM_Warning_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x22c2,
    0xde, OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sImagoLarvaOAM_Warning_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x22c2,
    0xdd, OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sImagoLarvaPartOAM_ClawsAttacking_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e9, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e0, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e4, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0xfa, 0x1f3, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsAttacking_Frame1[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e6, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e1, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e6, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0xf6, 0x1f0, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsAttacking_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1e7, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1ec, OBJ_SPRITE_OAM | 0x2cf,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f1, OBJ_SPRITE_OAM | 0x217,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsAttacking_Frame3[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e7, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1ec, OBJ_SPRITE_OAM | 0x2cf,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2ca,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x2c8,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f1, OBJ_SPRITE_OAM | 0x217,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ShellDying_Frame1[82] = {
    0x1b,
    0xd6, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xe9, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xee, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1de, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1d6, OBJ_SPRITE_OAM | 0x243,
    0xde, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x21, OBJ_SPRITE_OAM | 0x255,
    0xf6, 0x19, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x29, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x31, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellDying_Frame2[82] = {
    0x1b,
    0xd5, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe0, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe4, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xe9, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xed, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1d5, OBJ_SPRITE_OAM | 0x243,
    0xda, OBJ_SIZE_32x32 | 0x1d4, OBJ_SPRITE_OAM | 0x240,
    0xcf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xf0, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x19, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_8x32 | 0x11, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x25b,
    0xf6, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x25d
};

const u16 sImagoLarvaPartOAM_ShellDying_Frame5[82] = {
    0x1b,
    0xd6, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd4, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe6, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xeb, 0x24, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1d7, OBJ_SPRITE_OAM | 0x243,
    0xe1, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x240,
    0xd0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x255,
    0xfa, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x27, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x2e, OBJ_SPRITE_OAM | 0x257
};

const u16 sImagoLarvaPartOAM_ShellDying_Frame6[82] = {
    0x1b,
    0xd8, 0x1f5, OBJ_SPRITE_OAM | 0x202,
    0xd5, 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0xb, OBJ_SPRITE_OAM | 0x202,
    0xdc, 0x13, OBJ_SPRITE_OAM | 0x203,
    0xe1, 0x1b, OBJ_SPRITE_OAM | 0x203,
    0xe7, 0x20, OBJ_SPRITE_OAM | 0x204,
    0xed, 0x25, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x207,
    0xf2, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1df, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f7, OBJ_SPRITE_OAM | 0x289,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1d8, OBJ_SPRITE_OAM | 0x243,
    0xe4, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x240,
    0xd1, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x20f,
    0xef, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28f,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x1a, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1a, OBJ_SPRITE_OAM | 0x2b3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x12, OBJ_SPRITE_OAM | 0x252,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x258,
    0xfa, 0x18, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x28, OBJ_SPRITE_OAM | 0x259,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x30, OBJ_SPRITE_OAM | 0x25a
};

const u16 sImagoLarvaPartOAM_ClawsTakingDamage_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e9, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e0, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e4, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0xfa, 0x1f3, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsTakingDamage_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1e8, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x1ed, OBJ_SPRITE_OAM | 0x2cf,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2cc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2c8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f2, OBJ_SPRITE_OAM | 0x217,
    0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_ClawsTakingDamage_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1e7, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1ec, OBJ_SPRITE_OAM | 0x2cf,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1f1, OBJ_SPRITE_OAM | 0x217,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x216
};

const u16 sImagoLarvaPartOAM_DotAppearing_Frame0[4] = {
    0x1,
    0xfd, 0x1fd, OBJ_SPRITE_OAM | 0x205
};

const u16 sImagoLarvaPartOAM_DotAppearing_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x202
};

const u16 sImagoLarvaPartOAM_DotAppearing_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sImagoLarvaPartOAM_ClawsIdle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xf9, 0x1f2, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e7, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1ec, OBJ_SPRITE_OAM | 0x2cf,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2ca,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sImagoLarvaPartOAM_ClawsIdle_Frame1[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xf7, 0x1f1, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1e6, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1eb, OBJ_SPRITE_OAM | 0x2cf,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2ca
};

const u16 sImagoLarvaPartOAM_ClawsIdle_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xf6, 0x1f1, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1e7, OBJ_SPRITE_OAM | 0x2ce,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1ec, OBJ_SPRITE_OAM | 0x2cf,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x2ca
};

const u16 sImagoLarvaOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0
};

const u16 sImagoLarvaOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0
};

const u16 sImagoLarvaOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x22c0
};

const struct FrameData sImagoLarvaPartOAM_ShellAttacking[12] = {
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame1,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame2,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame3,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame4,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame5,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame6,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame7,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame8,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame9,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame10,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ShellIdle[5] = {
    sImagoLarvaPartOAM_ShellAttacking_Frame2,
    0x18,
    sImagoLarvaPartOAM_ShellAttacking_Frame3,
    0x18,
    sImagoLarvaPartOAM_ShellAttacking_Frame4,
    0x18,
    sImagoLarvaPartOAM_ShellAttacking_Frame3,
    0x18,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ShellRetreating[12] = {
    sImagoLarvaPartOAM_ShellAttacking_Frame10,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame9,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame8,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame7,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame6,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame5,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame4,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame3,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame2,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame1,
    0x8,
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x8,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ShellDying[9] = {
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x1,
    sImagoLarvaPartOAM_ShellDying_Frame1,
    0x2,
    sImagoLarvaPartOAM_ShellDying_Frame2,
    0x3,
    sImagoLarvaPartOAM_ShellDying_Frame1,
    0x2,
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x1,
    sImagoLarvaPartOAM_ShellDying_Frame5,
    0x2,
    sImagoLarvaPartOAM_ShellDying_Frame6,
    0x3,
    sImagoLarvaPartOAM_ShellDying_Frame5,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsAttacking[5] = {
    sImagoLarvaPartOAM_ClawsAttacking_Frame0,
    0x2,
    sImagoLarvaPartOAM_ClawsAttacking_Frame1,
    0x2,
    sImagoLarvaPartOAM_ClawsAttacking_Frame2,
    0x2,
    sImagoLarvaPartOAM_ClawsAttacking_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsIdle[5] = {
    sImagoLarvaPartOAM_ClawsIdle_Frame0,
    0x18,
    sImagoLarvaPartOAM_ClawsIdle_Frame1,
    0xC,
    sImagoLarvaPartOAM_ClawsIdle_Frame2,
    0x18,
    sImagoLarvaPartOAM_ClawsIdle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsRetreating[5] = {
    sImagoLarvaPartOAM_ClawsAttacking_Frame3,
    0x6,
    sImagoLarvaPartOAM_ClawsAttacking_Frame2,
    0x6,
    sImagoLarvaPartOAM_ClawsAttacking_Frame1,
    0x6,
    sImagoLarvaPartOAM_ClawsAttacking_Frame0,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsTakingDamage[4] = {
    sImagoLarvaPartOAM_ClawsTakingDamage_Frame0,
    0x4,
    sImagoLarvaPartOAM_ClawsTakingDamage_Frame1,
    0x4,
    sImagoLarvaPartOAM_ClawsTakingDamage_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_LeftDotAppearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_MiddleDotAppearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_RightDotAppearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_LeftDotVisible[2] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_MiddleDotVisible[2] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_RightDotVisible[2] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_LeftDotDisappearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_MiddleDotDisappearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_RightDotDisappearing[4] = {
    sImagoLarvaPartOAM_DotAppearing_Frame2,
    0x1,
    sImagoLarvaPartOAM_DotAppearing_Frame1,
    0xC,
    sImagoLarvaPartOAM_DotAppearing_Frame0,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ShellWarning[10] = {
    sImagoLarvaPartOAM_ShellWarning_Frame0,
    0x2,
    sImagoLarvaPartOAM_ShellWarning_Frame1,
    0x2,
    sImagoLarvaPartOAM_ShellWarning_Frame2,
    0x3,
    sImagoLarvaPartOAM_ShellWarning_Frame3,
    0x3,
    sImagoLarvaPartOAM_ShellWarning_Frame2,
    0x4,
    sImagoLarvaPartOAM_ShellWarning_Frame3,
    0x4,
    sImagoLarvaPartOAM_ShellWarning_Frame2,
    0xE,
    sImagoLarvaPartOAM_ShellWarning_Frame1,
    0x3,
    sImagoLarvaPartOAM_ShellWarning_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaOAM_Idle[9] = {
    sImagoLarvaOAM_Idle_Frame0,
    0xC,
    sImagoLarvaOAM_Idle_Frame1,
    0x6,
    sImagoLarvaOAM_Idle_Frame2,
    0x8,
    sImagoLarvaOAM_Idle_Frame1,
    0x6,
    sImagoLarvaOAM_Idle_Frame0,
    0xC,
    sImagoLarvaOAM_Idle_Frame1,
    0x6,
    sImagoLarvaOAM_Idle_Frame2,
    0x10,
    sImagoLarvaOAM_Idle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsWarningFirstPart[3] = {
    sImagoLarvaPartOAM_ClawsWarningFirstPart_Frame0,
    0xC,
    sImagoLarvaPartOAM_ClawsWarningFirstPart_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ClawsWarningSecondPart[3] = {
    sImagoLarvaPartOAM_ClawsWarningSecondPart_Frame0,
    0x4,
    sImagoLarvaPartOAM_ClawsWarningSecondPart_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaOAM_Warning[10] = {
    sImagoLarvaOAM_Warning_Frame0,
    0x2,
    sImagoLarvaOAM_Warning_Frame1,
    0x2,
    sImagoLarvaOAM_Warning_Frame2,
    0x3,
    sImagoLarvaOAM_Warning_Frame3,
    0x3,
    sImagoLarvaOAM_Warning_Frame2,
    0x4,
    sImagoLarvaOAM_Warning_Frame3,
    0x4,
    sImagoLarvaOAM_Warning_Frame2,
    0xE,
    sImagoLarvaOAM_Warning_Frame1,
    0x3,
    sImagoLarvaOAM_Warning_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoLarvaPartOAM_ShellTakingDamage[5] = {
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x6,
    sImagoLarvaPartOAM_ShellDying_Frame1,
    0x6,
    sImagoLarvaPartOAM_ShellAttacking_Frame0,
    0x6,
    sImagoLarvaPartOAM_ShellDying_Frame5,
    0x6,
    NULL,
    0x0
};

void ImagoLarvaSyncSubSprites(struct SubSpriteData* pSub)
{

}

/**
 * @brief 25a24 | 5c | Updates the palette of an Imago larva
 * 
 */
void ImagoLarvaUpdatePalette(void)
{
    u8 timer;
    u8 timerLimit;
    
    if (!(gCurrentSprite.invicibilityStunFlashTimer & 0x7F))
    {
        gCurrentSprite.workVariable2++;
        timer = gCurrentSprite.workVariable2;
        timerLimit = 0xA;
        if (timer >= timerLimit)
        {
            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.arrayOffset++;
            if (gCurrentSprite.arrayOffset > 0x3)
                gCurrentSprite.arrayOffset = 0x0;
        }

        gCurrentSprite.absolutePaletteRow = sImagoLarvaPaletteRows[gCurrentSprite.arrayOffset];
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 25a80 | 194 | Initializes an Imago larva sprite
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaInit(struct SubSpriteData* pSub)
{
    u8 spriteID;
    u16 health;
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 status;
    u16 offset;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CATERPILLAR_KILLED))
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.yPosition += 0x8;
        pSub->yPosition = gCurrentSprite.yPosition;
        pSub->xPosition = gCurrentSprite.xPosition;

        yPosition = pSub->yPosition;
        xPosition = pSub->xPosition;

        gCurrentSprite.xPositionSpawn = xPosition;
        spriteID = gCurrentSprite.spriteID;
        if (spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        {
            // Left larva
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.hitboxLeftOffset = -0x78;
            gCurrentSprite.hitboxRightOffset = 0x58;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;
            gDoorUnlockTimer = 0x1;
            MusicPlay(MUSIC_CATTERPILLARS_BATTLE_2, 0x0);
        }
        else
        {
            // Right larva
            gCurrentSprite.hitboxLeftOffset = -0x58;
            gCurrentSprite.hitboxRightOffset = 0x78;

            // Move to cocoon
            pSub->xPosition += BLOCK_SIZE * 11;
            xPosition += BLOCK_SIZE * 11;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_DETECT_SAMUS;
        }

        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x30;
        gCurrentSprite.hitboxBottomOffset = 0x0;

        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.yPositionSpawn = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;

        health = sPrimarySpriteStats[spriteID][0];
        gCurrentSprite.health = health;
        pSub->health = health;

        pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
        pSub->animationDurationCounter = 0x0;
        pSub->currentAnimationFrame = 0x0;

        // Immune to retreating flag
        pSub->workVariable2 = FALSE;
        // Retreating counter
        pSub->workVariable1 = 0x0;

        gCurrentSprite.drawOrder = 0x6;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.roomSlot = IMAGO_LARVA_PART_LARVA;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        status = gCurrentSprite.status & SPRITE_STATUS_XFLIP;

        // Spawn secondaries
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_CLAWS, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_RIGHT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_MIDDLE_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_LEFT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_SHELL, gfxSlot, ramSlot, yPosition, xPosition, status);
    }
}

/**
 * @brief 25c14 | 38 | Checks if samus is in range for an Imago larva to attack
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDetectSamus(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (pSub->xPosition > gSamusData.xPosition && pSub->xPosition - gSamusData.xPosition < BLOCK_SIZE * 5)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25c4c | 1c | Initializes an Imago larva to be idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaIdleInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;
}

/**
 * @brief 25c68 | c | Handles an Imago larva being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaIdle(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();
}

/**
 * @brief 25c74 | 28 | Initializes an Imago larva to be retreating
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaRetreatingInit(struct SubSpriteData* pSub)
{
    if (pSub->pMultiOam != sImagoLarvaMultiSpriteData_Retreating)
    {
        pSub->pMultiOam = sImagoLarvaMultiSpriteData_Retreating;
        pSub->animationDurationCounter = 0x0;
        pSub->currentAnimationFrame = 0x0;
    }

    gCurrentSprite.pose = IMAGO_LARVA_POSE_RETREATING;
}

/**
 * @brief 25c9c | 68 | Handles an Imago larva retreating
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaRetreating(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.timer-- != 0x0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // Check can move
            if (pSub->xPosition >= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 5)
                pSub->xPosition -= gCurrentSprite.yPositionSpawn;
        }
        else
        {
            // Check can move
            if (pSub->xPosition <= gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                pSub->xPosition += gCurrentSprite.yPositionSpawn;
        }
    }
    else
        gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED_INIT;
}

/**
 * @brief 25d04 | 1c | Initializes an Imago larva sprite to be stunned
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaStunnedInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED;
}

/**
 * @brief 25d20 | 28 | Handles an Imago larva being stunned
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaStunned(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.workVariable-- == 0x0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25d48 | 34 | Initializes an Imago larva to do the warning
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaWarningInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Warning;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING;
    gCurrentSprite.timer = 0x3C;
    pSub->workVariable1 = 0x0;

    SoundPlay(0xAD);
}

/**
 * @brief 25d7c | 24 | Checks if the warning animation has ended
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaCheckWarningAnimEnded(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (SpriteUtilCheckNearEndSubSpriteAnim(pSub))
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25da0 | 28 | Initializes an Imago larva to be attacking
 * 
 * @param pSub 
 */
void ImagoLarvaAttackingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Attacking;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING;
    SoundPlay(0xAE);
}

/**
 * @brief 25dc8 | 34 | Handles an Imago larva attacking
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaAttacking(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        pSub->xPosition += 0x8;
        if (pSub->xPosition >= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(0xAE, 0xA);
        }
    }
    else
    {
        pSub->xPosition -= 0x8;
        if (pSub->xPosition <= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(0xAE, 0xA);
        }
    }
}

/**
 * @brief 25e2c | 38 | Initializes an Imago larva to be taking damage
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaTakingDamageInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_TakingDamage;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE;
    gCurrentSprite.timer = 0x2F;
    pSub->workVariable1 = 0x0;

    SoundFade(0xAE, 0xA);
}

/**
 * @brief 25e64 | 24 | Handles an Imago larva taking damage 
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaTakingDamage(struct SubSpriteData* pSub)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25e88 | 64 | Initializes an Imago larva to be dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDyingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Dying;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_DYING;
    gCurrentSprite.timer = 0x64;
    gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
    gCurrentSprite.invicibilityStunFlashTimer |= gCurrentSprite.timer;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.health = 0x1;

    SoundFade(0xAE, 0xA);
    SoundPlay(0xB0);

    if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_RIGHT)
        MusicFade(0xA);
}

/**
 * @brief 25eec | 28 | Handles an Imago larva dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDying(struct SubSpriteData* pSub)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = IMAGO_LARVA_POSE_DEAD;
        gCurrentSprite.timer = 0x2;
    }
}

/**
 * @brief 25f14 | 5c | Kills the Imago larva
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDead(struct SubSpriteData* pSub)
{
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
    {
        if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_RIGHT)
        {
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_CATERPILLAR_KILLED);
            // Unlock doors
            gDoorUnlockTimer = -0x3C;
            MusicPlay(MUSIC_BOSS_KILLED, 0x0);
        }

        // Kill sprite
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x24, gCurrentSprite.xPosition, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 25f70 | 1cc | Initializes an Imago larva part sprite
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartInit(struct SubSpriteData* pSub)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = 0x1;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_LARVA_PART_RIGHT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_MIDDLE_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_LEFT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;

        case IMAGO_LARVA_PART_SHELL:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -0xB0;
            gCurrentSprite.hitboxBottomOffset = 0x0;

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = -0xA8;
                gCurrentSprite.hitboxRightOffset = 0x98;
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -0x98;
                gCurrentSprite.hitboxRightOffset=  0xA8;
            }

            gCurrentSprite.samusCollision = SSC_KRAID;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_SHELL_IDLE;
            gCurrentSprite.health = 0xFF;
            break;

        case IMAGO_LARVA_PART_CLAWS:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_CLAWS_IDLE;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 2613c | 180 | Handles an Imago larva shell being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartShellIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u8 speed;
    u16 health;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_STUNNED ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_DETECT_SAMUS)
    {
        if (gCurrentSprite.currentAnimationFrame & 0x1 && gCurrentSprite.animationDurationCounter == 0x1 &&
            gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0xAA);
    }

    if (gSpriteData[ramSlot].spriteID == PSPRITE_IMAGO_LARVA_LEFT)
    {
        if (pSub->xPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE) < gSamusData.xPosition &&
            pSub->xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE) > gSamusData.xPosition)
            gCurrentSprite.hitboxBottomOffset = -0x20;
        else
            gCurrentSprite.hitboxBottomOffset = 0x0;

        if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0xFF;
        }
    }
    else if (pSub->xPosition < gSamusData.xPosition)
    {
        if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0xFF;
        }
    }
    else if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
    {
        // Hit by something, check should retreat
        if (!pSub->workVariable2)
        {
            // Get speed
            health = 0xFF - gCurrentSprite.health;
            if (health >= 0x64)
                speed = 0x8;
            else if (health >= 0x14)
                speed = 0x4;
            else
                speed = 0x1;

            if (speed > 0x1)
                SoundPlay(0xAC);
            else
                SoundPlay(0xAB);

            // Update retreating counter
            if (pSub->workVariable1 < 0x8)
                pSub->workVariable1++;

            // Set retracting
            gSpriteData[ramSlot].timer = 0x10;
            // Set stunned delay
            gSpriteData[ramSlot].workVariable = pSub->workVariable1 * 8;
            // Set moving speed
            gSpriteData[ramSlot].yPositionSpawn = speed;
            gSpriteData[ramSlot].pose = IMAGO_LARVA_POSE_RETREATING_INIT;
        }

        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
        gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
        gCurrentSprite.health = 0xFF;
    }
}

/**
 * @brief 262bc | 60 | Handles an Imago larva dot being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDotIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_WARNING)
    {
        // Set disappearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotDisappearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotDisappearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotDisappearing;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REMOVING;
        // Set immune to retreat flag
        pSub->workVariable2 = TRUE;
    }
}

/**
 * @brief 2631c | 50 | Checks if the disappearing animation ended
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDotCheckDisappearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 2636c | 68 | Checks if an Imago larva dot should re-appear
 * 
 * @param pSub 
 */
void ImagoLarvaPartDotCheckShouldReappear(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE)
    {
        // Set appearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotAppearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotAppearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotAppearing;

        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REAPPEARING;
    }
}

/**
 * @brief 263d4 | 50 | Checks if the appearing animation ended
 * 
 * @param pSub 
 */
void ImagoLarvaPartDotCheckAppearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set visible
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
        // Remove immune to retreat flag
        pSub->workVariable2 = FALSE;
    }
}

/**
 * @brief 26424 | d0 | Handles an Imago larva part dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDead(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_DEAD)
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        switch (gCurrentSprite.roomSlot)
        {
            case IMAGO_LARVA_PART_RIGHT_DOT:
                yPosition += QUARTER_BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= 0x48;
                else
                    xPosition += 0x48;
                break;

            case IMAGO_LARVA_PART_MIDDLE_DOT:
                yPosition -= QUARTER_BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= HALF_BLOCK_SIZE;
                else
                    xPosition += HALF_BLOCK_SIZE;
                break;

            case IMAGO_LARVA_PART_SHELL:
                yPosition -= BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= 0x78;
                else
                    xPosition += 0x78;
                break;

            case IMAGO_LARVA_PART_CLAWS:
                gCurrentSprite.status = 0x0;
                return;

            default:
            case IMAGO_LARVA_PART_LEFT_DOT:
                break;
        }

        // Kill sprite
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, FALSE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 264f4 | 2c0 | Imago larva AI
 * 
 */
void ImagoLarva(void)
{
    struct SubSpriteData* pSub;

    // Get sub sprite data pointer
    if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if ((u8)(gCurrentSprite.pose - 0x1) < IMAGO_LARVA_POSE_DYING_INIT - 1)
    {
        // Not dying
        // Check play damaged sound
        if (gCurrentSprite.properties & SP_DAMAGED)
        {
            gCurrentSprite.properties &= ~SP_DAMAGED;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0xAF);
        }

        // Check took damage
        if (pSub->health != gCurrentSprite.health)
        {
            pSub->health = gCurrentSprite.health;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT;
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoLarvaInit(pSub);
            break;

        case IMAGO_LARVA_POSE_DETECT_SAMUS:
            ImagoLarvaDetectSamus(pSub);
            break;

        case IMAGO_LARVA_POSE_IDLE_INIT:
            ImagoLarvaIdleInit(pSub);

        case IMAGO_LARVA_POSE_IDLE:
            ImagoLarvaIdle(pSub);
            break;

        case IMAGO_LARVA_POSE_RETREATING_INIT:
            ImagoLarvaRetreatingInit(pSub);

        case IMAGO_LARVA_POSE_RETREATING:
            ImagoLarvaRetreating(pSub);
            break;

        case IMAGO_LARVA_POSE_STUNNED_INIT:
            ImagoLarvaStunnedInit(pSub);

        case IMAGO_LARVA_POSE_STUNNED:
            ImagoLarvaStunned(pSub);
            break;

        case IMAGO_LARVA_POSE_WARNING_INIT:
            ImagoLarvaWarningInit(pSub);

        case IMAGO_LARVA_POSE_WARNING:
            ImagoLarvaCheckWarningAnimEnded(pSub);
            break;

        case IMAGO_LARVA_POSE_ATTACKING_INIT:
            ImagoLarvaAttackingInit(pSub);

        case IMAGO_LARVA_POSE_ATTACKING:
            ImagoLarvaAttacking(pSub);
            break;

        case IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT:
            ImagoLarvaTakingDamageInit(pSub);

        case IMAGO_LARVA_POSE_TAKING_DAMAGE:
            ImagoLarvaTakingDamage(pSub);
            break;

        case IMAGO_LARVA_POSE_DYING_INIT:
            ImagoLarvaDyingInit(pSub);

        case IMAGO_LARVA_POSE_DYING:
            ImagoLarvaDying(pSub);
            break;

        case IMAGO_LARVA_POSE_DEAD:
            ImagoLarvaDead(pSub);
    }

    if (gCurrentSprite.health != 0x0)
    {
        // Update sub sprites
        SpriteUtilUpdateSubSpriteAnim(pSub);
        ImagoLarvaSyncSubSprites(pSub);
    }
}

/**
 * @brief 267b4 | 108 | Imago larva part AI
 * 
 */
void ImagoLarvaPart(void)
{
    struct SubSpriteData* pSub;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Get sub sprite data pointer
    if (gSpriteData[ramSlot].spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    if (gSpriteData[ramSlot].pose >= IMAGO_LARVA_POSE_DYING_INIT && gCurrentSprite.pose <= 0x61)
    {
        // Set dead
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DEAD;
        gCurrentSprite.invicibilityStunFlashTimer = gSpriteData[ramSlot].invicibilityStunFlashTimer;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoLarvaPartInit(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_IDLE:
            ImagoLarvaPartDotIdle(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REMOVING:
            ImagoLarvaPartDotCheckDisappearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR:
            ImagoLarvaPartDotCheckShouldReappear(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REAPPEARING:
            ImagoLarvaPartDotCheckAppearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_SHELL_IDLE:
            ImagoLarvaPartShellIdle(pSub);
            break;
        
        case IMAGO_LARVA_PART_POSE_DEAD:
            ImagoLarvaPartDead(pSub);
            break;
    }

    if (gCurrentSprite.health != 0x0)
    {
        // Update sub sprites
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_SHELL || gCurrentSprite.roomSlot == IMAGO_LARVA_PART_CLAWS)
            ImagoLarvaSyncSubSprites(pSub);
        else
        {
            if (gCurrentSprite.pose == IMAGO_LARVA_PART_POSE_DEAD)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                ImagoLarvaSyncSubSprites(pSub);                
            }
            else
                SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(pSub);
        }
    }
}
