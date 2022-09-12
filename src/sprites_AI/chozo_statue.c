#include "chozo_statue.h"
#include "unknown_item_chozo_statue.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sChozoStatueMultiSpriteData_Standing_Frame0[15] = {
    8, -176, -104,
    15, -192, -160,
    4, -296, -96,
    0, 0, 0,
    3, -256, -44
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame0[15] = {
    8, -168, -100,
    15, -184, -156,
    4, -288, -92,
    1, 0, 0,
    3, -248, -40
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame1[15] = {
    8, -152, -96,
    15, -168, -152,
    4, -272, -88,
    1, 4, 0,
    3, -232, -36
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame2[15] = {
    8, -124, -88,
    15, -140, -144,
    4, -244, -80,
    1, 4, 0,
    3, -204, -28
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame3[15] = {
    8, -120, -88,
    15, -136, -144,
    4, -240, -80,
    1, 4, 0,
    3, -200, -28
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame5[15] = {
    8, -116, -52,
    15, -132, -108,
    4, -236, -44,
    1, 4, 0,
    3, -196, 8
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame6[15] = {
    8, -92, -12,
    15, -108, -68,
    4, -212, -4,
    1, 4, 0,
    3, -172, 48
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame7[15] = {
    8, -64, -4,
    15, -80, -60,
    4, -184, 4,
    1, 4, 0,
    3, -144, 56
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame8[15] = {
    8, -40, -4,
    15, -56, -60,
    4, -160, 4,
    1, 4, 0,
    3, -120, 56
};

const i16 sChozoStatueMultiSpriteData_Sitting_Frame9[15] = {
    8, -44, 0,
    15, -60, -56,
    4, -164, 8,
    2, 4, 0,
    3, -124, 60
};

const i16 sChozoStatueMultiSpriteData_Seated_Frame0[15] = {
    8, -48, 0,
    15, -64, -56,
    4, -168, 8,
    2, 4, 0,
    3, -128, 60
};

const struct FrameData sChozoStatueMultiSpriteData_Standing[2] = {
    sChozoStatueMultiSpriteData_Standing_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatueMultiSpriteData_Sitting[11] = {
    sChozoStatueMultiSpriteData_Sitting_Frame0,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame1,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame2,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame3,
    0x5,
    sChozoStatueMultiSpriteData_Sitting_Frame2,
    0x1E,
    sChozoStatueMultiSpriteData_Sitting_Frame5,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame6,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame7,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame8,
    0xA,
    sChozoStatueMultiSpriteData_Sitting_Frame9,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChozoStatueMultiSpriteData_Seated[2] = {
    sChozoStatueMultiSpriteData_Seated_Frame0,
    0xFF,
    NULL,
    0x0
};

const u8 sChozoStatueFlashingPaletteRows[4] = {
    1, 2, 3, 2
};

const u32 sChozoStatueLongBeamGFX[1335];
const u16 sChozoStatueLongBeamPAL[80];


const u16 sChozoStatuePartOAM_LegStanding_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

const u16 sChozoStatuePartOAM_LegSitting_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd9, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

const u16 sChozoStatuePartOAM_LegSitting_Frame1[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x127a,
    0xe8, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x129b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd4, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120e,
    0xdc, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122d
};

const u16 sChozoStatuePartOAM_LegSitting_Frame2[16] = {
0x5,
OBJ_SHAPE_VERTICAL | 0xe1, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
0xe9, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
0xdc, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
OBJ_SHAPE_VERTICAL | 0xdc, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

const u16 sChozoStatuePartOAM_LegSitting_Frame3[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
    0xea, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xdd, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_VERTICAL | 0xdd, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

const u16 sChozoStatuePartOAM_LegSitting_Frame5[13] = {
    0x4,
    0xe0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1275,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f1, OBJ_SPRITE_OAM | 0x12b6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x1213
};

const u16 sChozoStatuePartOAM_LegSitting_Frame6[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1273,
    0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x12b3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x126a,
    0xde, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0xe6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x1238
};

const u16 sChozoStatuePartOAM_LegSitting_Frame7[16] = {
    0x5,
    0xe1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1271,
    0xf1, 0x1f7, OBJ_SPRITE_OAM | 0x12b1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    0xe3, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xeb, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

const u16 sChozoStatuePartOAM_LegSitting_Frame8[16] = {
    0x5,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x126f,
    0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x12af,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e4, OBJ_SPRITE_OAM | 0x126a,
    0xe8, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xf0, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

const u16 sChozoStatuePartOAM_LegSeated_Frame0[19] = {
    0x6,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x126e,
    0xe8, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x128d,
    0xf0, 0x1eb, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x126a,
    0xe9, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x121a,
    0xf1, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x123b
};

const u16 sChozoStatueOAM_Idle_Frame0[13] = {
    0x4,
    0xe8, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x1204,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1282,
    0x8, 0x1f0, OBJ_SPRITE_OAM | 0x1281
};

const u16 sChozoStatuePartOAM_EyeClosing_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1280
};

const u16 sChozoStatuePartOAM_EyeClosing_Frame1[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a0
};

const u16 sChozoStatuePartOAM_EyeClosed_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a1
};

const u16 sChozoStatuePartOAM_ArmIdle_Frame0[13] = {
    0x4,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1207,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1209
};

const u16 sChozoStatuePartOAM_ArmGlow_Frame1[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1300,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1302,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

const u16 sChozoStatuePartOAM_ArmGlow_Frame2[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1320,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1322,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

const u16 sChozoStatuePartOAM_ArmGlow_Frame3[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1303,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1305,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

const u16 sChozoStatuePartOAM_ArmGlow_Frame4[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1323,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1325,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

const u16 sChozoStatuePartOAM_ArmSamusGrabbed_Frame0[13] = {
    0x4,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1247,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1249
};

const u16 sChozoBallOAM_NormalClosed_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1307,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x1309,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1310
};

const u16 sChozoBallOAM_NormalClosed_Frame1[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130a,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130c,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1330
};

const u16 sChozoBallOAM_NormalClosed_Frame3[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130d,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130f,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1312
};

const u16 sChozoBallOAM_NormalRevealing_Frame0[16] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x1317,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, OBJ_SPRITE_OAM | 0x1332,
    0x4, 0x4, OBJ_SPRITE_OAM | 0x1334,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

const u16 sChozoBallOAM_NormalRevealing_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x1319,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131b,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x1318,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x1339,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

const u16 sChozoBallOAM_NormalRevealing_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x131d,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131f,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x131c,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x133d,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

const u16 sChozoBallOAM_NormalRevealed_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sChozoBallOAM_NormalRevealed_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x286,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x24c
};

const u16 sChozoBallOAM_NormalRevealed_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x288,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sChozoStatueRefillOAM_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sChozoStatueRefillOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce
};

const u16 sChozoStatueRefillOAM_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0
};

const u16 sChozoStatueRefillOAM_Frame10[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2
};

const u16 sChozoStatueRefillOAM_Frame12[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4
};

const u16 sChozoStatueRefillOAM_Frame18[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sChozoStatueRefillOAM_Frame20[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8
};

const u16 sChozoStatueRefillOAM_Frame26[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sChozoStatueRefillOAM_Frame28[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc
};

const u16 sChozoStatueRefillOAM_Frame34[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de
};

const u16 sChozoStatuePartOAM_EyeOpened_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1314
};

const u16 sChozoStatuePartOAM_GlowIdle_Frame0[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sChozoStatuePartOAM_GlowIdle_Frame4[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sChozoStatuePartOAM_GlowIdle_Frame8[19] = {
    0x6,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

const u16 sChozoStatuePartOAM_GlowIdle_Frame12[25] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame16[31] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame20[37] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame24[37] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame28[31] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame32[25] = {
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

const u16 sChozoStatuePartOAM_GlowIdle_Frame36[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c9,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c8
};

const struct FrameData sChozoStatuePartOAM_LegStanding[2] = {
    sChozoStatuePartOAM_LegStanding_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_LegSitting[10] = {
    sChozoStatuePartOAM_LegSitting_Frame0,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame1,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame2,
    0x5,
    sChozoStatuePartOAM_LegSitting_Frame3,
    0x1E,
    sChozoStatuePartOAM_LegSitting_Frame2,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame5,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame6,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame7,
    0xA,
    sChozoStatuePartOAM_LegSitting_Frame8,
    0x14,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_LegSeated[2] = {
    sChozoStatuePartOAM_LegSeated_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatueOAM_Idle[2] = {
    sChozoStatueOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_EyeOpened[2] = {
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_EyeClosing[3] = {
    sChozoStatuePartOAM_EyeClosing_Frame0,
    0xA,
    sChozoStatuePartOAM_EyeClosing_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_EyeOpening[3] = {
    sChozoStatuePartOAM_EyeClosing_Frame1,
    0xA,
    sChozoStatuePartOAM_EyeClosing_Frame0,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_EyeClosed[2] = {
    sChozoStatuePartOAM_EyeClosed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_ArmIdle[2] = {
    sChozoStatuePartOAM_ArmIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_ArmGlow[9] = {
    sChozoStatuePartOAM_ArmIdle_Frame0,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame1,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame2,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame3,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame4,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame3,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame2,
    0xA,
    sChozoStatuePartOAM_ArmGlow_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_ArmSamusGrabbed[2] = {
    sChozoStatuePartOAM_ArmSamusGrabbed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_NormalClosed[5] = {
    sChozoBallOAM_NormalClosed_Frame0,
    0xE,
    sChozoBallOAM_NormalClosed_Frame1,
    0xE,
    sChozoBallOAM_NormalClosed_Frame0,
    0xE,
    sChozoBallOAM_NormalClosed_Frame3,
    0xE,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_NormalRevealing[4] = {
    sChozoBallOAM_NormalRevealing_Frame0,
    0x2,
    sChozoBallOAM_NormalRevealing_Frame1,
    0x2,
    sChozoBallOAM_NormalRevealing_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChozoBallOAM_NormalRevealed[5] = {
    sChozoBallOAM_NormalRevealed_Frame0,
    0xA,
    sChozoBallOAM_NormalRevealed_Frame1,
    0xA,
    sChozoBallOAM_NormalRevealed_Frame2,
    0xA,
    sChozoBallOAM_NormalRevealed_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChozoStatueRefillOAM[41] = {
    sChozoStatueRefillOAM_Frame0,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame2,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame4,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame2,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame4,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame10,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame12,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame10,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame12,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame18,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame20,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame18,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame20,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame26,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame28,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame26,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame28,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame34,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame0,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOAM_Frame34,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOAM_GlowIdle[41] = {
    sChozoStatuePartOAM_GlowIdle_Frame0,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame0,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame4,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame4,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame8,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame8,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame12,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame12,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame16,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame16,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame20,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame20,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame24,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame24,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame28,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame28,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame32,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame32,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame36,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOAM_GlowIdle_Frame36,
    0x2,
    sChozoStatuePartOAM_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const u32 sChozoStatueIceBeamGFX[1335];
const u16 sChozoStatueIceBeamPAL[80];

const u32 sChozoStatueWaveBeamGFX[1335];
const u16 sChozoStatueWaveBeamPAL[80];

const u32 sChozoStatueBombsGFX[1339];
const u16 sChozoStatueBombsPAL[80];

const u32 sChozoStatueSpeedboosterGFX[1342];
const u16 sChozoStatueSpeedboosterPAL[80];

const u32 sChozoStatueHighJumpGFX[1372];
const u16 sChozoStatueHighJumpPAL[80];

const u32 sChozoStatueScrewAttackGFX[1378];
const u16 sChozoStatueScrewAttackPAL[80];

const u32 sChozoStatueVariaGFX[1378];
const u16 sChozoStatueVariaPAL[80];


void ChozoStatueSyncSubSprites(void)
{

}

/**
 * @brief 138d8 | 30c | Registers a chozo statue item/hint
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoStatueRegisterItem(u8 spriteID)
{
    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            gEquipment.beamBombs |= BBF_LONG_BEAM;

        case PSPRITE_CHOZO_STATUE_LONG_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_LONG_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_ICE:
            gEquipment.beamBombs |= BBF_ICE_BEAM;

        case PSPRITE_CHOZO_STATUE_ICE_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_ICE_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            gEquipment.beamBombs |= BBF_WAVE_BEAM;

        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_WAVE_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            gEquipment.beamBombs |= BBF_BOMBS;

        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_BOMBS_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            gEquipment.suitMisc |= SMF_SPEEDBOOSTER;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_SPEEDBOOSTER_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            gEquipment.suitMisc |= SMF_HIGH_JUMP;
            EventFunction(EVENT_ACTION_SETTING, EVENT_HIGH_JUMP_OBTAINED);

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_HIGH_JUMP_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            gEquipment.suitMisc |= SMF_SCREW_ATTACK;
            EventFunction(EVENT_ACTION_SETTING, EVENT_SCREW_ATTACK_OBTAINED);

        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_SCREW_ATTACK_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            gEquipment.suitMisc |= SMF_VARIA_SUIT;
            EventFunction(EVENT_ACTION_SETTING, EVENT_VARIA_SUIT_OBTAINED);

        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_VARIA_SUIT_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gEquipment.suitMisc |= SMF_SPACE_JUMP;
            EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_JUMP_OBTAINED);
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gEquipment.suitMisc |= SMF_GRAVITY_SUIT;
            EventFunction(EVENT_ACTION_SETTING, EVENT_GRAVITY_SUIT_OBTAINED);
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gEquipment.beamBombs |= BBF_PLASMA_BEAM;
            EventFunction(EVENT_ACTION_SETTING, EVENT_PLASMA_BEAM_OBTAINED);
            break;
    }
}

/**
 * @brief 13be4 | 1fc | Sets the direction of a chozo statue
 * 
 */
void ChozoStatueSetDirection(void)
{
    switch (gCurrentSprite.spriteID)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE_HINT:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
        case PSPRITE_CHOZO_STATUE_VARIA:
        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            break;

        case PSPRITE_CHOZO_STATUE_LONG_HINT:
        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            break;
    }
}

/**
 * @brief 13de0 | 2bc | Gets the behavior of the chozo statue with the ID in parameter
 * 
 * @param spriteID Chozo statue sprite ID
 * @return u8 Behavior
 */
u8 ChozoStatueGetBehavior(u8 spriteID)
{
    u8 behavior;

    behavior = CHOZO_STATUE_BEHAVIOR_ITEM;

    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_LONG_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_LONG_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_ICE_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_ICE_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_WAVE_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_BOMBS_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_SPEEDBOOSTER_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_HIGH_JUMP_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_SCREW_ATTACK_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_VARIA_SUIT_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_LONG:
            if (gEquipment.beamBombs & BBF_LONG_BEAM)
                behavior++;
            break;
        
        case PSPRITE_CHOZO_STATUE_ICE:
            if (gEquipment.beamBombs & BBF_ICE_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            if (gEquipment.beamBombs & BBF_WAVE_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            if (gEquipment.beamBombs & BBF_PLASMA_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            if (gEquipment.beamBombs & BBF_BOMBS)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            if (gEquipment.suitMisc & SMF_SPEEDBOOSTER)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            if (gEquipment.suitMisc & SMF_HIGH_JUMP)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            if (gEquipment.suitMisc & SMF_SCREW_ATTACK)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            if (gEquipment.suitMisc & SMF_VARIA_SUIT)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            if (gEquipment.suitMisc & SMF_SPACE_JUMP)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            if (gEquipment.suitMisc & SMF_GRAVITY_SUIT)
                behavior++;
            break;
    }

    return behavior;
}

/**
 * @brief 1409c | 1f8 | Initializes a Chozo statue sprite
 * 
 */
void ChozoStatueInit(void)
{
    u8 behavior;
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;

    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);

    ChozoStatueSetDirection();
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    else
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;

    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = 0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = 0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x1;

    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
    gSubSpriteData1.workVariable2 = 0x0;
    gSubSpriteData1.workVariable3 = FALSE;

    behavior = ChozoStatueGetBehavior(gCurrentSprite.spriteID);
    if (behavior > CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Is hint
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;
        if (behavior == CHOZO_STATUE_BEHAVIOR_HINT_TAKEN)
        {
            // Set seated
            gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
            ChozoStatueSeatedChangeCCAA(CAA_MAKE_SOLID3);
        }
        else
        {
            // Set standing
            gSubSpriteData1.workVariable3 = TRUE;
            gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Standing;
            ChozoStatueStandingChangeCCAA(CAA_MAKE_SOLID3, CAA_MAKE_SOLID_GRIPPABLE);
        }
    }
    else
    {
        // Is item
        gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
        ChozoStatueSeatedChangeCCAA(CAA_MAKE_SOLID3);

        if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
        {
            // Item
            gCurrentSprite.pose = CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED;

            // Spawn chozo ball
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0x0, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    gSubSpriteData1.xPosition + 0x38, 0x0);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0x0, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    gSubSpriteData1.xPosition - 0x38, 0x0);
            }
        }
        else
            gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE; // Refill
    }

    gCurrentSprite.roomSlot = CHOZO_STATUE_PART_HEAD;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Spawn eye
    gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_EYE,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);

    // Spawn arm
    behavior = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_ARM,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);

    // Spawn leg
    SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_LEG, gfxSlot, ramSlot,
        yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);

    // Spawn glow
    newRamSlot = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_GLOW, gfxSlot,
        ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
    gSpriteData[newRamSlot].workVariable = behavior;
}

/**
 * @brief 14294 | 4 | Empty function
 * 
 */
void ChozoStatue_Empty(void)
{
    return;
}

/**
 * @brief 14298 | 64 | Registers the hint
 * 
 */
void ChozoStatueRegisterHint(void)
{
    u8 eyeSlot;

    // Open eye
    eyeSlot = gCurrentSprite.workVariable;
    gSpriteData[eyeSlot].pose = CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT;

    gCurrentSprite.pose = CHOZO_STATUE_POSE_HINT_FLASHING;
    gCurrentSprite.timer = 0x78;
    gCurrentSprite.workVariable2 = 0xC;
    gCurrentSprite.arrayOffset = 0x0;

    if (gCurrentSprite.spriteID == PSPRITE_CHOZO_STATUE_LONG_HINT)
    {
        make_background_flash(0x1); // Undefined || Update transparency for long beam statue
        gCurrentSprite.timer += 0x28;
    }

    // Register hint
    ChozoStatueRegisterItem(gCurrentSprite.spriteID);
    MusicFade(0x3C);
}

/**
 * @brief 142fc | bc | Handles the flashing before a chozo statue hint
 * 
 */
void ChozoStatueHintFlashing(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;

    if (gSpriteData[ramSlot].pose == 0x61)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = CHOZO_STATUE_POSE_SITTING_INIT;
            gCurrentSprite.paletteRow = 0x0;

            // Start hint
            gPauseScreenFlag = PAUSE_SCREEN_CHOZO_HINT;

            MusicPlay(MUSIC_CHOZO_STATUE_HINT, 0x0);
        }
        else
        {
            if (gCurrentSprite.timer == 0x77)
            {
                make_background_flash(0x0); // Undefined || Slight yellow flash
                SoundPlay(0x11B); // Chozo hint
            }
            else if (gCurrentSprite.timer > 0x77)
                return;

            // Update palette
            gCurrentSprite.workVariable2--;
            if (gCurrentSprite.workVariable2 == 0x0)
            {
                // Reset delay
                gCurrentSprite.workVariable2 = 0xC;
                // Change row
                gCurrentSprite.paletteRow = sChozoStatueFlashingPaletteRows[gCurrentSprite.arrayOffset];
                
                // Update offset
                if (gCurrentSprite.arrayOffset > 0x2)
                    gCurrentSprite.arrayOffset = 0x0;
                else
                    gCurrentSprite.arrayOffset++;
            }
        }
    }
}

/**
 * @brief 143b8 | 40 | Initializes a Chozo statue to be sitting
 * 
 */
void ChozoStatueSittingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_SITTING;

    gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Sitting;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    ChozoStatueStandingChangeCCAA(CAA_REMOVE_SOLID, CAA_REMOVE_SOLID);
    SoundPlay(0x11C);

    gSlowScrollingTimer = 0x3C;
}

/**
 * @brief 143f8 | 4c | Handles a chozo statue sitting
 * 
 */
void ChozoStatueSitting(void)
{
    SpriteUtilUpdateSubSprite1Timer();
    if (gSubSpriteData1.workVariable2 != 0x0)
        SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = CHOZO_STATUE_POSE_DELAY_AFTER_SITTING;
        gCurrentSprite.timer = 0x1E;

        ChozoStatueSeatedChangeCCAA(CAA_MAKE_SOLID3);
    }
}

/**
 * @brief 14444 | 24 | Handles the delay before the refill after the statue sat down
 * 
 */
void ChozoStatueDelayBeforeRefillAfterHint(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;   
}

/**
 * @brief 14468 | 2c | Waits for the item to be grabbed
 * 
 */
void ChozoStatueWaitForItemToBeCollected(void)
{
    // Check behavior
    if (ChozoStatueGetBehavior(gCurrentSprite.spriteID) == CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Hint behavior, thus item was took
        gCurrentSprite.pose = CHOZO_STATUE_POSE_TIMER_AFTER_ITEM;
        gCurrentSprite.timer = 0x28;
    }
}

/**
 * @brief 14494 | 24 | Timer after the item is grabbed, unknown purpose
 * 
 */
void ChozoStatueTimerAfterItemGrabbed(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;
}

/**
 * @brief 144b8 | 48 | Initializes a chozo statue for a refill
 * 
 */
void ChozoStatueRefillInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_REFILL;
    gCurrentSprite.workVariable2 = 0x4;
    gCurrentSprite.arrayOffset = 0x0;

    SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_REFILL, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gSamusData.yPosition - 0x18, gSamusData.xPosition, 0x0);
}

/**
 * @brief 14500 | 4c | Handles a chozo statue refilling Samus
 * 
 */
void ChozoStatueRefillSamus(void)
{
    // Update palette
    gCurrentSprite.workVariable2--;
    if (gCurrentSprite.workVariable2 == 0x0)
    {
        // Reset delay
        gCurrentSprite.workVariable2 = 0x4;
        // Change row
        gCurrentSprite.paletteRow = sChozoStatueFlashingPaletteRows[gCurrentSprite.arrayOffset];
        
        // Update offset
        if (gCurrentSprite.arrayOffset > 0x2)
            gCurrentSprite.arrayOffset = 0x0;
        else
            gCurrentSprite.arrayOffset++;
    }
}

/**
 * @brief 1454c | 20 | Initializes a chozos statue to be sleeping
 * 
 */
void ChozoStatueSleepingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_SLEEPING;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.timer = 0x46;
}

/**
 * @brief 1456c | 58 | Handles a chozo statue going to sleep
 * 
 */
void ChozoStatueSleeping(void)
{
    u8 ramSlot;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Close eye
        ramSlot = gCurrentSprite.workVariable;
        gSpriteData[ramSlot].pose = CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT;

        gCurrentSprite.pose = CHOZO_STATUE_POSE_DO_NOTHING;

        // Replay room music if hint
        if (gSubSpriteData1.workVariable3)
            MusicPlay(gMusicTrackInfo.currentRoomTrack, 0x0);
    }
}

/**
 * @brief 145c4 | 174 | Initializes a chozo statue part sprite
 * 
 */
void ChozoStatuePartInit(void)
{
    u8 ramSlot;
    u8 behavior;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x2;
    
    gCurrentSprite.hitboxTopOffset = 0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = 0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    behavior = ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteID);

    switch (gCurrentSprite.roomSlot)
    {
        case CHOZO_STATUE_PART_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x1E;

            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT;
            else
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;

            if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
                gCurrentSprite.pOam = sChozoStatuePartOAM_ArmIdle;
            else
                gCurrentSprite.pOam = sChozoStatuePartOAM_ArmGlow;
            break;
    
        case CHOZO_STATUE_PART_LEG:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_LEG_IDLE;
            else
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
            break;

        case CHOZO_STATUE_PART_EYE:
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pOam = sChozoStatuePartOAM_EyeClosed;
            else
                gCurrentSprite.pOam = sChozoStatuePartOAM_EyeOpened;
            break;

        case CHOZO_STATUE_PART_GLOW:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x1;
            gCurrentSprite.drawDistanceHorizontalOffset = 0xC;

            gCurrentSprite.pOam = sChozoStatuePartOAM_GlowIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_GLOW_IDLE;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 14738 | 5c | Handles the glow being idle
 * 
 */
void ChozoStatuePartGlowIdle(void)
{
    u8 ramSlot;

    // Arm part slot
    ramSlot = gCurrentSprite.workVariable;

    if (gSpriteData[ramSlot].pOam == sChozoStatuePartOAM_ArmGlow)
    {
        // Display if arm has glow
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
}

/**
 * @brief 14794 | a0 | Detects if Samus in in the hand (for a hint)
 * 
 */
void ChozoStatuePartArmCheckGrabSamusHint(void)
{
    u8 ramSlot;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        xPosition += CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= CHOZO_STATUE_HAND_X_OFFSET;

    // In range, chozo statue is idle, either morph ball or rolling
    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_IDLE &&
        gSamusData.yPosition == gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET &&
        gSamusData.xPosition > xPosition - QUARTER_BLOCK_SIZE && gSamusData.xPosition < xPosition + QUARTER_BLOCK_SIZE &&
        (u8)(gSamusData.pose - SPOSE_MORPH_BALL) < (SPOSE_UNMORPHING - SPOSE_MORPH_BALL))
    {
        // Set pose
        SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
        
        // Update statue
        gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_REGISTER_HINT;
        
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SITTING;

        // Set samus grabbed
        gCurrentSprite.pOam = sChozoStatuePartOAM_ArmSamusGrabbed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gDisablePause = TRUE;
    }
}

/**
 * @brief 14834 | 30 | Synchronizes Samus' position with the hand position
 * 
 */
void ChozoStatuePartSyncSamusPosition(void)
{
    gSamusData.yPosition = gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gSamusData.xPosition = gCurrentSprite.xPosition + CHOZO_STATUE_HAND_X_OFFSET;
    else
        gSamusData.xPosition = gCurrentSprite.xPosition - CHOZO_STATUE_HAND_X_OFFSET;
}

/**
 * @brief 14864 | 44 | Handles the arm part sitting
 * 
 */
void ChozoStatuePartArmSitting(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Check set seated
    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SEATED;

    ChozoStatuePartSyncSamusPosition();

    // Spawn echo
    if (gSubSpriteData1.workVariable2)
        SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);
}

/**
 * @brief 148a8 | 40 | Handles the arm part being seated
 * 
 */
void ChozoStatuePartArmSeated(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    ChozoStatuePartSyncSamusPosition();

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_IDLE)
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;
        gDisablePause = FALSE;
    }
}

/**
 * @brief 148e8 | fc | Detects if Samus in in the hand (for a refill)
 * 
 */
void ChozoStatuePartArmCheckGrabSamusRefill(void)
{
    u8 ramSlot;
    u8 isGrabbed;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Update OAM
    if (gCurrentSprite.pOam == sChozoStatuePartOAM_ArmIdle && gPreventMovementTimer == 0x0 &&
        ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteID) != CHOZO_STATUE_BEHAVIOR_ITEM)
        gCurrentSprite.pOam = sChozoStatuePartOAM_ArmGlow;

    isGrabbed = FALSE;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        xPosition += CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= CHOZO_STATUE_HAND_X_OFFSET;

    // In range, chozo statue is idle
    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_IDLE &&
        gSamusData.yPosition == gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET &&
        gSamusData.xPosition > xPosition - QUARTER_BLOCK_SIZE && gSamusData.xPosition < xPosition + QUARTER_BLOCK_SIZE)
    {
        if (gSamusData.pose == SPOSE_MORPH_BALL)
        {
            // Set grabbed
            SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
            isGrabbed++;
        }
        else if (gSamusData.pose == SPOSE_GRABBED_BY_CHOZO_STATUE)
            isGrabbed++; // Already grabbed

        if (isGrabbed)
        {
            gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_REFILL_INIT;
            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_REFILL;

            ChozoStatuePartSyncSamusPosition();

            gCurrentSprite.pOam = sChozoStatuePartOAM_ArmSamusGrabbed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0x1E;
        }
    }
}

/**
 * @brief 149e4 | 140 | Refills Samus
 * 
 */
void ChozoStatuePartArmRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_REFILL)
    {
        if (gCurrentSprite.timer == 0x1E)
        {
            // Refill energy
            if (!SpriteUtilRefillEnergy())
            {
                gCurrentSprite.timer--;
                gEnergyRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x1D)
        {
            // Refill missiles
            if (gEnergyRefillAnimation != 0x0)
                gEnergyRefillAnimation--;
            else if (!SpriteUtilRefillMissiles())
            {
                gCurrentSprite.timer--;
                gMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x1C)
        {
            // Refill super missiles
            if (gMissileRefillAnimation != 0x0)
                gMissileRefillAnimation--;
            else if (!SpriteUtilRefillSuperMissiles())
            {
                gCurrentSprite.timer--;
                gSuperMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x1B)
        {
            // Refill power bombs
            if (gSuperMissileRefillAnimation != 0x0)
                gSuperMissileRefillAnimation--;
            else if (!SpriteUtilRefillPowerBombs())
            {
                gCurrentSprite.timer--;
                gPowerBombRefillAnimation = 0xD;
            }
        }
        else
        {
            // Check refill anim ended
            if (gPowerBombRefillAnimation != 0x0)
                gPowerBombRefillAnimation--;
            else if (gCurrentSprite.timer != 0x0)
                gCurrentSprite.timer--; // Update timer
            else
            {
                // Set sleeping
                gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_SLEEPING_INIT;
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT;

                // Spawn refill correct ended message
                if (gEquipment.maxMissiles == 0x0 && gEquipment.maxSuperMissiles == 0x0 && gEquipment.maxPowerBombs == 0x0)
                {
                    // Only energy
                    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ENERGY_TANK_RECHARGE_COMPLETE, 0x6,
                        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
                }
                else
                {
                    // Energy and weapons
                    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED, 0x6,
                        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
                }
            }
        }
    }
}

/**
 * @brief 14b24 | 4 | Empty function
 * 
 */
void ChozoStatuePart_Empty(void)
{
    return;
}

/**
 * @brief 14b28 | 30 | Initializes the arm part to be sleeping
 * 
 */
void ChozoStatuePartSleepingInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SLEEPING)
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SLEEPING;
}

/**
 * @brief 14b58 | 38 | Handles the arm part sleeping
 * 
 */
void ChozoStatuePartArmSleeping(void)
{
    // Check release samus
    if (gPreventMovementTimer == 0x0 && gCurrentSprite.pOam == sChozoStatuePartOAM_ArmSamusGrabbed)
    {
        // Release samus
        gCurrentSprite.pOam = sChozoStatuePartOAM_ArmIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        SamusSetPose(SPOSE_MORPH_BALL);
    }
}

/**
 * @brief 14b90 | 20 | Initializes the eye part to be opening
 * 
 */
void ChozoStatuePartEyeOpeningInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_EYE_OPENING;

    gCurrentSprite.pOam = sChozoStatuePartOAM_EyeOpening;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 14bb0 | 2c | Handles the eye part opening
 * 
 */
void ChozoStatuePartEyeOpening(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set opened
        gCurrentSprite.pOam = sChozoStatuePartOAM_EyeOpened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 14bdc | 20 | Initializes the eye part to be closing
 * 
 */
void ChozoStatuePartEyeClosingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_EYE_CLOSING;

    gCurrentSprite.pOam = sChozoStatuePartOAM_EyeClosing;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 14bfc | 2c | Handles the eye part closing
 * 
 */
void ChozoStatuePartEyeClosing(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set closed
        gCurrentSprite.pOam = sChozoStatuePartOAM_EyeClosed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 14c28 | 48 | Handles the leg part being idle
 * 
 */
void ChozoStatuePartLegIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SITTING)
    {
        // Spawn echo
        if (gSubSpriteData1.workVariable2 != 0x0)
            SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);
    }
    else if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
}

/**
 * @brief 14c70 | 148 | Chozo statue AI
 * 
 */
void ChozoStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChozoStatueInit();
            break;

        case CHOZO_STATUE_POSE_IDLE:
            ChozoStatue_Empty();
            break;

        case CHOZO_STATUE_POSE_REGISTER_HINT:
            ChozoStatueRegisterHint();
            break;

        case CHOZO_STATUE_POSE_HINT_FLASHING:
            ChozoStatueHintFlashing();
            break;

        case CHOZO_STATUE_POSE_SITTING_INIT:
            ChozoStatueSittingInit();
            break;

        case CHOZO_STATUE_POSE_SITTING:
            ChozoStatueSitting();
            break;

        case CHOZO_STATUE_POSE_DELAY_AFTER_SITTING:
            ChozoStatueDelayBeforeRefillAfterHint();
            break;

        case CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED:
            ChozoStatueWaitForItemToBeCollected();
            break;

        case CHOZO_STATUE_POSE_TIMER_AFTER_ITEM:
            ChozoStatueTimerAfterItemGrabbed();
            break;

        case CHOZO_STATUE_POSE_REFILL_INIT:
            ChozoStatueRefillInit();
            break;

        case CHOZO_STATUE_POSE_REFILL:
            ChozoStatueRefillSamus();
            break;

        case CHOZO_STATUE_POSE_SLEEPING_INIT:
            ChozoStatueSleepingInit();
            break;

        case CHOZO_STATUE_POSE_SLEEPING:
            ChozoStatueSleeping();
    }

    SpriteUtilUpdateSubSprite1Anim();
    ChozoStatueSyncSubSprites();
}

/**
 * @brief 14db8 | 248 | Chozo statue part AI
 * 
 */
void ChozoStatuePart(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChozoStatuePartInit();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT:
            ChozoStatuePartArmCheckGrabSamusHint();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SITTING:
            ChozoStatuePartArmSitting();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SEATED:
            ChozoStatuePartArmSeated();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL:
            ChozoStatuePartArmCheckGrabSamusRefill();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_REFILL:
            ChozoStatuePartArmRefill();
            ChozoStatuePart_Empty();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT:
            ChozoStatuePartSleepingInit();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SLEEPING:
            ChozoStatuePartArmSleeping();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT:
            ChozoStatuePartEyeOpeningInit();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_OPENING:
            ChozoStatuePartEyeOpening();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT:
            ChozoStatuePartEyeClosingInit();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_CLOSING:
            ChozoStatuePartEyeClosing();
            break;

        case CHOZO_STATUE_PART_POSE_LEG_IDLE:
            ChozoStatuePartLegIdle();
            break;

        case CHOZO_STATUE_PART_POSE_GLOW_IDLE:
            ChozoStatuePartGlowIdle();

        case CHOZO_STATUE_PART_POSE_DO_NOTHING:
            break;
    }

    if (gCurrentSprite.roomSlot == CHOZO_STATUE_PART_LEG)
        ChozoStatueSyncSubSprites();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM();

    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
}

/**
 * @brief 15000 | a8 | Chozo statue refill AI
 * 
 */
void ChozoStatueRefill(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 0x1;

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
        
        gCurrentSprite.hitboxTopOffset = 0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = 0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pose = 0x9;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sChozoStatueRefillOAM;

        SoundPlay(0x10F); // Chozo statue refill
    }
    else if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SLEEPING)
    {
        gCurrentSprite.status = 0x0;
        SoundFade(0x10F, 0x1E); // Chozo statue refill
    }
}
