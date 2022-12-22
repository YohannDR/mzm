#include "data/sprites/unknown_item_chozo_statue.h"
#include "macros.h"

const i16 sUnknownItemChozoStatueMultiSpriteData_Standing_Frame0[15] = {
    8, -176, -104,
    15, -192, -160,
    4, -296, -96,
    0, 0, 0,
    3, -256, -44
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame0[15] = {
    8, -168, -100,
    15, -184, -156,
    4, -288, -92,
    1, 0, 0,
    3, -248, -40
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame1[15] = {
    8, -152, -96,
    15, -168, -152,
    4, -272, -88,
    1, 4, 0,
    3, -232, -36
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame2[15] = {
    8, -124, -88,
    15, -140, -144,
    4, -244, -80,
    1, 4, 0,
    3, -204, -28
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame3[15] = {
    8, -120, -88,
    15, -136, -144,
    4, -240, -80,
    1, 4, 0,
    3, -200, -28
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame5[15] = {
    8, -116, -52,
    15, -132, -108,
    4, -236, -44,
    1, 4, 0,
    3, -196, 8
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame6[15] = {
    8, -92, -12,
    15, -108, -68,
    4, -212, -4,
    1, 4, 0,
    3, -172, 48
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame7[15] = {
    8, -64, -4,
    15, -80, -60,
    4, -184, 4,
    1, 4, 0,
    3, -144, 56
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame8[15] = {
    8, -40, -4,
    15, -56, -60,
    4, -160, 4,
    1, 4, 0,
    3, -120, 56
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame9[15] = {
    8, -44, 0,
    15, -60, -56,
    4, -164, 8,
    2, 4, 0,
    3, -124, 60
};

const i16 sUnknownItemChozoStatueMultiSpriteData_Seated_Frame0[15] = {
    8, -48, 0,
    15, -64, -56,
    4, -168, 8,
    2, 4, 0,
    3, -128, 60
};

const struct FrameData sUnknownItemChozoStatueMultiSpriteData_Standing[2] = {
    sUnknownItemChozoStatueMultiSpriteData_Standing_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatueMultiSpriteData_Sitting[11] = {
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame0,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame1,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame2,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame3,
    0x5,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame2,
    0x1E,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame5,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame6,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame7,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame8,
    0xA,
    sUnknownItemChozoStatueMultiSpriteData_Sitting_Frame9,
    0xA,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatueMultiSpriteData_Seated[2] = {
    sUnknownItemChozoStatueMultiSpriteData_Seated_Frame0,
    0xFF,
    NULL,
    0x0
};

const u8 sUnknownItemChozoStatueFlashingPaletteRows[4] = {
    1, 2, 3, 2
};

const u32 sChozoStatueSpaceJumpGFX[1353] = INCBIN_U32("data/sprites/ChozoStatueSpaceJump.gfx.lz");
const u16 sChozoStatueSpaceJumpPAL[80] = INCBIN_U16("data/sprites/ChozoStatueSpaceJump.pal");

const u16 sUnknownItemChozoStatuePartOAM_LegStanding_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd9, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame1[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x127a,
    0xe8, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x129b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd4, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120e,
    0xdc, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122d
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
    0xe9, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xdc, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_VERTICAL | 0xdc, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame3[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
    0xea, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xdd, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_VERTICAL | 0xdd, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame5[13] = {
    0x4,
    0xe0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1275,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f1, OBJ_SPRITE_OAM | 0x12b6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x1213
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame6[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1273,
    0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x12b3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x126a,
    0xde, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0xe6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x1238
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame7[16] = {
    0x5,
    0xe1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1271,
    0xf1, 0x1f7, OBJ_SPRITE_OAM | 0x12b1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    0xe3, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xeb, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

const u16 sUnknownItemChozoStatuePartOAM_LegSitting_Frame8[16] = {
    0x5,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x126f,
    0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x12af,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e4, OBJ_SPRITE_OAM | 0x126a,
    0xe8, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xf0, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

const u16 sUnknownItemChozoStatuePartOAM_LegSeated_Frame0[25] = {
    0x8,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x126e,
    0xe8, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x128d,
    0xf0, 0x1eb, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x126a,
    0xf8, 0x1da, OBJ_SPRITE_OAM | 0x124c,
    0xf0, 0x1e3, OBJ_SPRITE_OAM | 0x128c,
    0xe9, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x121a,
    0xf1, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x123b
};

const u16 sUnknownItemChozoStatueOAM_Idle_Frame0[16] = {
    0x5,
    0xe8, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x1204,
    0x8, 0x1f0, OBJ_SPRITE_OAM | 0x1281,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1282,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1e0, OBJ_SPRITE_OAM | 0x1306
};

const u16 sUnknownItemChozoStatuePartOAM_EyeClosing_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1280
};

const u16 sUnknownItemChozoStatuePartOAM_EyeClosing_Frame1[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a0
};

const u16 sUnknownItemChozoStatuePartOAM_EyeClosed_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a1
};

const u16 sUnknownItemChozoStatuePartOAM_ArmIdle_Frame0[28] = {
    0x9,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1207,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1209,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0x1e6, OBJ_SPRITE_OAM | 0x124f,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x1251,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sUnknownItemChozoStatuePartOAM_ArmGlow_Frame1[34] = {
    0xb,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1300,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1302,
    0xee, 0x1e6, OBJ_SPRITE_OAM | 0x128a,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x128b,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sUnknownItemChozoStatuePartOAM_ArmGlow_Frame2[34] = {
    0xb,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1320,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1322,
    0xee, 0x1e6, OBJ_SPRITE_OAM | 0x12aa,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x12ab,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sUnknownItemChozoStatuePartOAM_ArmGlow_Frame3[34] = {
    0xb,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1303,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1305,
    0xee, 0x1e6, OBJ_SPRITE_OAM | 0x12ca,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x12cb,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sUnknownItemChozoStatuePartOAM_ArmGlow_Frame4[34] = {
    0xb,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1323,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1325,
    0xee, 0x1e6, OBJ_SPRITE_OAM | 0x12ea,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x12eb,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sUnknownItemChozoStatuePartOAM_ArmSamusGrabbed_Frame0[28] = {
    0x9,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x6, OBJ_SPRITE_OAM | 0x12a6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fe, OBJ_SPRITE_OAM | 0x1288,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1247,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1249,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0x1e6, OBJ_SPRITE_OAM | 0x1252,
    0xee, 0x1f6, OBJ_SPRITE_OAM | 0x1254,
    0xf6, 0xe, OBJ_SPRITE_OAM | 0x1289
};

const u16 sChozoBallOAM_UnknownClosed_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1307,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x1309,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1310
};

const u16 sChozoBallOAM_UnknownClosed_Frame1[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130a,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130c,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1330
};

const u16 sChozoBallOAM_UnknownClosed_Frame3[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130d,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130f,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1312
};

const u16 sChozoBallOAM_UnknownRevealing_Frame0[16] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x1317,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, OBJ_SPRITE_OAM | 0x1332,
    0x4, 0x4, OBJ_SPRITE_OAM | 0x1334,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x2a4
};

const u16 sChozoBallOAM_UnknownRevealing_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x1319,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131b,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x1318,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x1339,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sChozoBallOAM_UnknownRevealing_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x131d,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131f,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x131c,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x133d,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sChozoBallOAM_UnknownRevealed_Frame0[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sChozoBallOAM_UnknownRevealed_Frame1[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sChozoBallOAM_UnknownRevealed_Frame2[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame10[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame12[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame18[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame20[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame26[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame28[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc
};

const u16 sUnknownItemChozoStatueRefillOAM_Frame34[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de
};

const u16 sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1314
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame0[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame4[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame8[19] = {
    0x6,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame12[25] = {
    0x8,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c9,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c8
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame16[31] = {
    0xa,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c6
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame20[37] = {
    0xc,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf1, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame24[37] = {
    0xc,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf1, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xee, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame28[31] = {
    0xa,
    0xf9, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xef, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame32[25] = {
    0x8,
    0xf9, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xf4, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c7,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f9, OBJ_SPRITE_OAM | 0x12c6
};

const u16 sUnknownItemChozoStatuePartOAM_GlowIdle_Frame36[14] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c9,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c8
};

const struct FrameData sUnknownItemChozoStatuePartOAM_LegStanding[2] = {
    sUnknownItemChozoStatuePartOAM_LegStanding_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_LegSitting[10] = {
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame0,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame1,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame2,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame3,
    0x5,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame2,
    0x1E,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame5,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame6,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame7,
    0xA,
    sUnknownItemChozoStatuePartOAM_LegSitting_Frame8,
    0x14,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_LegSeated[2] = {
    sUnknownItemChozoStatuePartOAM_LegSeated_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatueOAM_Idle[2] = {
    sUnknownItemChozoStatueOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_EyeOpened[2] = {
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_EyeClosing[3] = {
    sUnknownItemChozoStatuePartOAM_EyeClosing_Frame0,
    0xA,
    sUnknownItemChozoStatuePartOAM_EyeClosing_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_EyeOpening[3] = {
    sUnknownItemChozoStatuePartOAM_EyeClosing_Frame1,
    0xA,
    sUnknownItemChozoStatuePartOAM_EyeClosing_Frame0,
    0xA,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_EyeClosed[2] = {
    sUnknownItemChozoStatuePartOAM_EyeClosed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_ArmIdle[2] = {
    sUnknownItemChozoStatuePartOAM_ArmIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_ArmGlow[9] = {
    sUnknownItemChozoStatuePartOAM_ArmIdle_Frame0,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame1,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame2,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame3,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame4,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame3,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame2,
    0xA,
    sUnknownItemChozoStatuePartOAM_ArmGlow_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_ArmSamusGrabbed[2] = {
    sUnknownItemChozoStatuePartOAM_ArmSamusGrabbed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_UnknownClosed[5] = {
    sChozoBallOAM_UnknownClosed_Frame0,
    0xE,
    sChozoBallOAM_UnknownClosed_Frame1,
    0xE,
    sChozoBallOAM_UnknownClosed_Frame0,
    0xE,
    sChozoBallOAM_UnknownClosed_Frame3,
    0xE,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_UnknownRevealing[4] = {
    sChozoBallOAM_UnknownRevealing_Frame0,
    0x2,
    sChozoBallOAM_UnknownRevealing_Frame1,
    0x2,
    sChozoBallOAM_UnknownRevealing_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_UnknownRevealed[5] = {
    sChozoBallOAM_UnknownRevealed_Frame0,
    0xA,
    sChozoBallOAM_UnknownRevealed_Frame1,
    0xA,
    sChozoBallOAM_UnknownRevealed_Frame2,
    0xA,
    sChozoBallOAM_UnknownRevealed_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatueRefillOAM[41] = {
    sUnknownItemChozoStatueRefillOAM_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame2,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame4,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame2,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame4,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame10,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame12,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame10,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame12,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame18,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame20,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame18,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame20,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame26,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame28,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame26,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame28,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame34,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatueRefillOAM_Frame34,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sUnknownItemChozoStatuePartOAM_GlowIdle[41] = {
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame4,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame4,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame8,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame8,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame12,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame12,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame16,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame16,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame20,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame20,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame24,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame24,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame28,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame28,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame32,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame32,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame36,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sUnknownItemChozoStatuePartOAM_GlowIdle_Frame36,
    0x2,
    sUnknownItemChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const u32 sChozoStatueGravitySuitGFX[1357] = INCBIN_U32("data/sprites/ChozoStatueGravitySuit.gfx.lz");
const u16 sChozoStatueGravitySuitPAL[80] = INCBIN_U16("data/sprites/ChozoStatueGravitySuit.pal");

const u32 sChozoStatuePlasmaBeamGFX[1356] = INCBIN_U32("data/sprites/ChozoStatuePlasmaBeam.gfx.lz");
const u16 sChozoStatuePlasmaBeamPAL[80] = INCBIN_U16("data/sprites/ChozoStatuePlasmaBeam.pal");
