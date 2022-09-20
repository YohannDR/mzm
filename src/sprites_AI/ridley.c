#include "ridley.h"
#include "../../data/data.h"
#include "../data/pointers.c"
#include "../globals.h"

const i16 sRidleyMultiSpriteData_Idle_Frame0[18] = {
    17, -76, 16,
    4, -84, -116,
    0, 0, 0,
    9, 0, 0,
    30, 16, 124,
    18, -76, -16
};

const i16 sRidleyMultiSpriteData_Idle_Frame1[18] = {
    17, -72, 16,
    4, -80, -116,
    0, 0, 0,
    9, 0, 0,
    30, 20, 124,
    18, -72, -16
};

const i16 sRidleyMultiSpriteData_Idle_Frame2[18] = {
    17, -68, 16,
    4, -76, -116,
    0, 0, 0,
    9, 0, 0,
    30, 24, 124,
    18, -68, -16
};

const i16 sRidleyMultiSpriteData_SpittingFireballs_Frame0[18] = {
    21, -68, 16,
    6, -88, -116,
    1, 0, 0,
    10, 0, 0,
    30, 16, 124,
    22, -68, -16
};

const i16 sRidleyMultiSpriteData_SpittingFireballs_Frame1[18] = {
    21, -64, 16,
    6, -88, -116,
    1, 0, 0,
    10, 0, 0,
    30, 20, 124,
    22, -64, -16
};

const i16 sRidleyMultiSpriteData_TurningAroundFirstPart_Frame0[18] = {
    17, -76, 0,
    8, -84, -88,
    2, 0, 0,
    11, 0, 0,
    30, 16, 64,
    18, -76, -24
};

const i16 sRidleyMultiSpriteData_TurningAroundFirstPart_Frame1[18] = {
    17, -76, -8,
    8, -84, -52,
    2, 0, 0,
    11, 0, 0,
    30, 16, 40,
    18, -76, -28
};

const i16 sRidleyMultiSpriteData_TurningAroundSecondPart_Frame0[18] = {
    17, -76, -8,
    8, -84, -52,
    3, 0, 0,
    12, 0, 0,
    30, 16, 40,
    18, -76, -28
};

const i16 sRidleyMultiSpriteData_TurningAroundSecondPart_Frame1[18] = {
    17, -76, 0,
    8, -84, -88,
    3, 0, 0,
    12, 0, 0,
    30, 16, 64,
    18, -76, -24
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame0[24] = {
    23, 0, 0,
    23, -4, 36,
    23, 12, 68,
    23, 36, 92,
    23, 72, 80,
    23, 104, 72,
    23, 136, 84,
    24, 208, 96
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame1[24] = {
    23, -4, 0,
    23, -12, 36,
    23, -8, 72,
    23, 8, 104,
    23, 36, 120,
    23, 68, 128,
    23, 104, 120,
    24, 180, 128
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame2[24] = {
    23, -8, 0,
    23, -24, 28,
    23, -36, 64,
    23, -24, 100,
    23, 4, 120,
    23, 32, 132,
    23, 68, 132,
    24, 144, 132
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame3[24] = {
    23, -12, 0,
    23, -20, 32,
    23, -44, 64,
    23, -60, 100,
    23, -36, 128,
    23, -12, 148,
    23, 24, 152,
    24, 100, 164
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame4[24] = {
    23, -8, 0,
    23, -4, 36,
    23, -16, 68,
    23, -48, 88,
    23, -64, 104,
    23, -52, 132,
    23, -24, 148,
    24, 52, 156
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame5[24] = {
    23, 0, 0,
    23, 8, 36,
    23, 4, 72,
    23, -32, 80,
    23, -68, 96,
    23, -60, 128,
    23, -48, 156,
    26, 8, 192
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame6[24] = {
    23, 4, 0,
    23, 20, 32,
    23, 40, 64,
    23, 0, 84,
    23, -44, 92,
    23, -80, 112,
    23, -100, 144,
    27, -128, 188
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame7[24] = {
    23, 8, 0,
    23, 44, 28,
    23, 72, 56,
    23, 36, 84,
    23, -12, 96,
    23, -56, 88,
    23, -100, 112,
    27, -140, 160
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame8[24] = {
    23, 16, 0,
    23, 52, 24,
    23, 88, 40,
    23, 64, 80,
    23, 12, 100,
    23, -24, 80,
    23, -76, 92,
    25, -144, 100
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame9[24] = {
    23, 24, 0,
    23, 56, 20,
    23, 88, 32,
    23, 92, 76,
    23, 52, 104,
    23, 8, 120,
    23, -40, 132,
    29, -96, 116
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame10[24] = {
    23, 20, 0,
    23, 40, 24,
    23, 72, 44,
    23, 96, 68,
    23, 76, 108,
    23, 48, 140,
    23, 12, 148,
    29, -40, 136
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame11[24] = {
    23, 16, 0,
    23, 32, 28,
    23, 64, 52,
    23, 88, 68,
    23, 100, 108,
    23, 80, 144,
    23, 52, 172,
    27, 0, 196
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame12[24] = {
    23, 12, 0,
    23, 24, 32,
    23, 48, 60,
    23, 76, 84,
    23, 108, 100,
    23, 100, 128,
    23, 84, 152,
    26, 124, 196
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame13[24] = {
    23, 8, 0,
    23, 12, 36,
    23, 24, 72,
    23, 56, 92,
    23, 88, 100,
    23, 112, 116,
    23, 132, 136,
    26, 184, 168
};

const i16 sRidleyTailMultiSpriteData_Idle_Frame14[24] = {
    23, 4, 0,
    23, 4, 40,
    23, 16, 80,
    23, 52, 100,
    23, 84, 104,
    23, 120, 92,
    23, 156, 84,
    28, 220, 48
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame0[24] = {
    23, 16, 0,
    23, 44, 20,
    23, 80, 40,
    23, 100, 64,
    23, 80, 96,
    23, 52, 116,
    23, 32, 144,
    25, -28, 160
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame1[24] = {
    23, 20, 0,
    23, 48, 12,
    23, 80, 32,
    23, 100, 56,
    23, 104, 92,
    23, 92, 124,
    23, 124, 140,
    27, 80, 188
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame2[24] = {
    23, 20, -4,
    23, 48, 8,
    23, 80, 20,
    23, 100, 36,
    23, 108, 52,
    23, 128, 60,
    23, 148, 36,
    26, 220, 60
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame3[24] = {
    23, 20, -8,
    23, 52, 4,
    23, 84, 8,
    23, 108, 24,
    23, 144, 20,
    23, 160, -16,
    23, 140, -80,
    28, 200, -124
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame4[24] = {
    23, 20, -8,
    23, 56, 0,
    23, 96, 4,
    23, 128, -8,
    23, 132, -44,
    23, 124, -76,
    23, 88, -108,
    28, 144, -156
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame5[24] = {
    23, 16, -4,
    23, 60, -4,
    23, 104, -12,
    23, 136, -52,
    23, 132, -104,
    23, 76, -120,
    23, 24, -120,
    29, -28, -152
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame6[24] = {
    23, 12, -4,
    23, 44, -24,
    23, 84, -44,
    23, 68, -100,
    23, 20, -120,
    23, -28, -104,
    23, -64, -60,
    25, -112, -32
    };

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame7[24] = {
    23, 8, -4,
    23, 20, -36,
    23, -16, -76,
    23, -68, -76,
    23, -100, -48,
    23, -116, -4,
    23, -108, 36,
    27, -144, 84
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame8[24] = {
    23, 4, 0,
    23, -12, -24,
    23, -44, -12,
    23, -76, 4,
    23, -100, 32,
    23, -100, 68,
    23, -92, 100,
    27, -128, 144
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame9[24] = {
    23, 4, 0,
    23, -4, 20,
    23, -16, 40,
    23, -32, 64,
    23, -48, 76,
    23, -64, 92,
    23, -72, 124,
    27, -104, 172
};

const i16 sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame10[24] = {
    23, 8, 0,
    23, 28, 20,
    23, 40, 52,
    23, 28, 84,
    23, 24, 112,
    23, -12, 116,
    23, -28, 144,
    27, -72, 188
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame3[24] = {
    23, 24, -8,
    23, 56, -4,
    23, 96, 0,
    23, 128, -4,
    23, 156, -16,
    23, 184, -32,
    23, 204, -64,
    28, 272, -108
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame4[24] = {
    23, 28, -8,
    23, 68, -20,
    23, 112, -28,
    23, 144, -48,
    23, 184, -76,
    23, 216, -100,
    23, 244, -140,
    28, 316, -192
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame5[24] = {
    23, 28, -12,
    23, 56, -40,
    23, 92, -72,
    23, 120, -104,
    23, 164, -148,
    23, 208, -196,
    23, 244, -240,
    28, 332, -296
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame6[24] = {
    23, 24, -12,
    23, 56, -48,
    23, 92, -88,
    23, 124, -120,
    23, 164, -168,
    23, 204, -216,
    23, 244, -264,
    28, 320, -316
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame7[24] = {
    23, 24, -16,
    23, 52, -56,
    23, 88, -100,
    23, 120, -140,
    23, 156, -184,
    23, 196, -236,
    23, 236, -292,
    28, 316, -352
};

const i16 sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame11[24] = {
    23, 24, -8,
    23, 60, 4,
    23, 96, -4,
    23, 136, -4,
    23, 172, -28,
    23, 196, -60,
    23, 188, -100,
    28, 260, -140
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame3[24] = {
    23, 20, -4,
    23, 56, 0,
    23, 88, 16,
    23, 116, 20,
    23, 144, 28,
    23, 168, 28,
    23, 200, 24,
    24, 280, 24
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame4[24] = {
    23, 20, -4,
    23, 64, 0,
    23, 116, 12,
    23, 152, 12,
    23, 192, 8,
    23, 228, 8,
    23, 260, 4,
    24, 340, 4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5[24] = {
    23, 24, -4,
    23, 72, -4,
    23, 120, -4,
    23, 160, -4,
    23, 208, -4,
    23, 252, -4,
    23, 292, -4,
    24, 376, -4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame6[24] = {
    23, 28, -4,
    23, 76, -4,
    23, 128, -4,
    23, 176, -4,
    23, 224, -4,
    23, 272, -4,
    23, 312, -4,
    24, 392, -4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8[24] = {
    23, 24, -4,
    23, 64, -4,
    23, 112, 0,
    23, 148, 0,
    23, 188, -4,
    23, 216, -4,
    23, 236, -4,
    24, 312, -4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9[24] = {
    23, 20, -4,
    23, 52, -4,
    23, 84, 8,
    23, 108, 4,
    23, 136, 0,
    23, 156, -4,
    23, 176, -4,
    24, 248, -4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10[24] = {
    23, 16, -4,
    23, 36, 0,
    23, 48, 8,
    23, 64, 8,
    23, 80, 0,
    23, 96, -4,
    23, 116, -4,
    24, 180, -4
};

const i16 sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame11[24] = {
    23, 12, -4,
    23, 24, 0,
    23, 32, 8,
    23, 44, 8,
    23, 52, 0,
    23, 64, 0,
    23, 76, -4,
    24, 136, -4
};

const struct FrameData sRidleyMultiSpriteData_Idle[6] = {
    sRidleyMultiSpriteData_Idle_Frame0,
    0x1C,
    sRidleyMultiSpriteData_Idle_Frame1,
    0xE,
    sRidleyMultiSpriteData_Idle_Frame2,
    0x8,
    sRidleyMultiSpriteData_Idle_Frame1,
    0xE,
    sRidleyMultiSpriteData_Idle_Frame0,
    0xE,
    NULL,
    0x0
};

const struct FrameData sRidleyMultiSpriteData_SpittingFireballs[3] = {
    sRidleyMultiSpriteData_SpittingFireballs_Frame0,
    0x3,
    sRidleyMultiSpriteData_SpittingFireballs_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sRidleyMultiSpriteData_TurningAroundFirstPart[3] = {
    sRidleyMultiSpriteData_TurningAroundFirstPart_Frame0,
    0x4,
    sRidleyMultiSpriteData_TurningAroundFirstPart_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyMultiSpriteData_TurningAroundSecondPart[3] = {
    sRidleyMultiSpriteData_TurningAroundSecondPart_Frame0,
    0x4,
    sRidleyMultiSpriteData_TurningAroundSecondPart_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_Idle[16] = {
    sRidleyTailMultiSpriteData_Idle_Frame0,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame1,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame2,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame3,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame4,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame5,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame6,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame7,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame8,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame9,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame10,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame11,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame12,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame13,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame14,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_Dying[16] = {
    sRidleyTailMultiSpriteData_Idle_Frame0,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame1,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame2,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame3,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame4,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame5,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame6,
    0x3,
    sRidleyTailMultiSpriteData_Idle_Frame7,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame8,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame9,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame10,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame11,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame12,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame13,
    0x1,
    sRidleyTailMultiSpriteData_Idle_Frame14,
    0x1,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_MoveToAttack[12] = {
    sRidleyTailMultiSpriteData_Idle_Frame0,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame1,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame2,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame3,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame4,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame5,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame6,
    0x6,
    sRidleyTailMultiSpriteData_Idle_Frame7,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame8,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame9,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame10,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_SettingUpDiagonalTailAttack[12] = {
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame0,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame1,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame2,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame3,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame4,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame5,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame6,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame7,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame8,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame9,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame10,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack[12] = {
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame0,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame1,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame2,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame3,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame4,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame6,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame7,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame8,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame9,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame10,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_DiagonalTailAttack[21] = {
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame0,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame1,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame2,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame3,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame4,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame6,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame7,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame6,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame4,
    0x2,
    sRidleyTailMultiSpriteData_DiagonalTailAttack_Frame11,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame3,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame4,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame6,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame7,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame8,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame9,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame10,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_ChargingVerticalTailAttack[13] = {
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame0,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame1,
    0x2,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame2,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame3,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame4,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame6,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame11,
    0x6,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_VerticalTailAttack[11] = {
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame6,
    0x8,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10,
    0x2,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame11,
    0x6,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_LastVerticalAttack[17] = {
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame6,
    0x8,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame5,
    0x4,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame8,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame9,
    0x3,
    sRidleyTailMultiSpriteData_ChargingVerticalTailAttack_Frame10,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame4,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame5,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame6,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame7,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame8,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame9,
    0x3,
    sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack_Frame10,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyTailMultiSpriteData_BackToIdle[4] = {
    sRidleyTailMultiSpriteData_Idle_Frame12,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame13,
    0x4,
    sRidleyTailMultiSpriteData_Idle_Frame14,
    0x4,
    NULL,
    0x0
};

const i16 sRidleySpawningSpittingFireballsYOffsets[81] = {
    0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3,
    -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3,
    -3, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1,
    1, 0, 0, 0, 0, SHORT_MAX
};

const i16 sRidleyIdleYOffsets[65] = {
    0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3,
    -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, -1,
    -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0,
    0, 0, 0, SHORT_MAX
};

const u32 sRidleyGFX[2211];
const u16 sRidleyPAL[128];

const u16 sRidleyOAM_Idle_Frame0[49] = {
    0x10,
    0xe, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x3, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe3, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1e, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1e, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_Idle_Frame1[49] = {
    0x10,
    0xf, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x2, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1a, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1a, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe3, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1d, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1d, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_Idle_Frame2[49] = {
    0x10,
    0x10, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x318,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x2, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x19, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x19, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe4, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1c, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1c, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_Idle_Frame3[55] = {
    0x12,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0x318,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f1, OBJ_SPRITE_OAM | 0x31a,
    0x17, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x33a,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x2, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe5, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1b, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1b, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_SpittingFireballs_Frame1[49] = {
    0x10,
    0xd, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x1ea, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x2, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1a, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1a, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe4, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0x0, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1d, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1d, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_SpittingFireballs_Frame2[49] = {
    0x10,
    0xe, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x318,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x2ec,
    0x3, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_SIZE_16x32 | 0xe, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_SIZE_8x32 | 0x1e, OBJ_SPRITE_OAM | 0x38d,
    0xe3, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0x13, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x254,
    0x1e, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x28e,
    0x1e, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_TurningAround_Frame0[49] = {
    0x10,
    0xe, OBJ_SIZE_32x32 | 0x1e2, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x1, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_8x32 | 0x1ec, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x2ec,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x38d,
    0xe3, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x254,
    0x1e, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x28e,
    0x1e, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyOAM_TurningAround_Frame1[49] = {
    0x10,
    0xe, OBJ_SIZE_32x32 | 0x1ed, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1ff, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x7, OBJ_SPRITE_OAM | 0x28c,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x7, OBJ_SPRITE_OAM | 0x2ec,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x38b,
    OBJ_SHAPE_VERTICAL | 0x1b, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, OBJ_SPRITE_OAM | 0x38d,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x254,
    0x1e, OBJ_SIZE_32x32 | 0x1dd, OBJ_SPRITE_OAM | 0x28e,
    0x1e, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1e5, OBJ_SPRITE_OAM | 0x214
};

const u16 sRidleyPartOAM_HeadIdle_Frame0[13] = {
    0x4,
    0xe8, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x281,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x300,
    0x8, 0x1fc, OBJ_SPRITE_OAM | 0x302,
    0xff, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_HeadIdle_Frame1[13] = {
    0x4,
    0xe9, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x281,
    OBJ_SHAPE_VERTICAL | 0x9, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x300,
    0x9, 0x1fc, OBJ_SPRITE_OAM | 0x302,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_OpeningMouth_Frame0[13] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x2ee,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x312,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2d2,
    0xff, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_MouthOpened_Frame0[13] = {
    0x4,
    0xe1, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xe9, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    0x0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_MouthOpened_Frame1[13] = {
    0x4,
    0xe2, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xea, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    0xff, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_HeadDying_Frame0[16] = {
    0x5,
    0xe3, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xea, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    OBJ_SHAPE_VERTICAL | 0xfe, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_SIZE_16x32 | 0x1ff, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRidleyPartOAM_HeadDying_Frame1[16] = {
    0x5,
    0xed, 0x1fe, OBJ_SPRITE_OAM | 0x2d4,
    0xe1, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xe9, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    0x0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_HeadDying_Frame2[19] = {
    0x6,
    0xee, 0x1fe, OBJ_SPRITE_OAM | 0x2d5,
    0xe3, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xea, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    OBJ_SHAPE_VERTICAL | 0xfe, OBJ_SIZE_16x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_SIZE_16x32 | 0x1ff, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRidleyPartOAM_HeadDying_Frame3[16] = {
    0x5,
    0xed, 0x1fe, OBJ_SPRITE_OAM | 0x2f5,
    0xe1, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1eb, OBJ_SPRITE_OAM | 0x296,
    0xe9, OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x314,
    0x0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRidleyPartOAM_HeadTurningAround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x393,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x396
};

const u16 sRidleyPartOAM_ClawIdle_Frame0[13] = {
    0x4,
    0xc, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x21c,
    0x6, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x250,
    0xe, 0x1db, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawIdle_Frame1[13] = {
    0x4,
    0xd, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x29c,
    0x7, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x250,
    0xf, 0x1db, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawIdle_Frame2[13] = {
    0x4,
    0xe, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x31c,
    0x8, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x250,
    0x10, 0x1da, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawIdle_Frame3[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_SIZE_16x32 | 0x1c1, OBJ_SPRITE_OAM | 0x31c,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_SIZE_8x32 | 0x1d1, OBJ_SPRITE_OAM | 0x31e,
    0xe, 0x1d9, OBJ_SPRITE_OAM | 0x31f,
    OBJ_SHAPE_VERTICAL | 0x15, 0x1d9, OBJ_SPRITE_OAM | 0x33f,
    0x9, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x250,
    0x11, 0x1da, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawSpittingFireballs_Frame1[13] = {
    0x4,
    0xb, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x29c,
    0x5, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x250,
    0xd, 0x1db, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawSpittingFireballs_Frame2[13] = {
    0x4,
    0xc, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x31c,
    0x6, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x250,
    0xe, 0x1db, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawTurningAround_Frame0[13] = {
    0x4,
    0xb, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x21c,
    0x6, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x250,
    0xe, 0x1d7, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawTurningAround_Frame1[13] = {
    0x4,
    0xe, OBJ_SIZE_32x32 | 0x1ca, OBJ_SPRITE_OAM | 0x218,
    0x6, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x250,
    0xe, 0x1df, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawLiftingSamus_Frame0[16] = {
    0x5,
    0x7, OBJ_SIZE_32x32 | 0x1bd, OBJ_SPRITE_OAM | 0x21c,
    0x2, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x250,
    0xa, 0x1d8, OBJ_SPRITE_OAM | 0x26f,
    0xee, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x38f,
    0xfd, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x3cf
};

const u16 sRidleyPartOAM_ClawLiftingSamus_Frame1[16] = {
    0x5,
    0x1, OBJ_SIZE_32x32 | 0x1b7, OBJ_SPRITE_OAM | 0x21c,
    0xfc, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x250,
    0x4, 0x1d4, OBJ_SPRITE_OAM | 0x26f,
    0xed, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x38f,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x3cf
};

const u16 sRidleyPartOAM_ClawLiftingSamus_Frame2[16] = {
    0x5,
    0xfa, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1d5, OBJ_SPRITE_OAM | 0x250,
    0xfd, 0x1cd, OBJ_SPRITE_OAM | 0x26f,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x20f,
    0xed, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawLiftingSamus_Frame3[13] = {
    0x4,
    0xf1, OBJ_SIZE_32x32 | 0x1b0, OBJ_SPRITE_OAM | 0x21c,
    0xeb, OBJ_SIZE_16x16 | 0x1d3, OBJ_SPRITE_OAM | 0x250,
    0xf3, 0x1cb, OBJ_SPRITE_OAM | 0x26f,
    0xec, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_ClawLiftingSamus_Frame4[13] = {
    0x4,
    0xeb, OBJ_SIZE_32x32 | 0x1af, OBJ_SPRITE_OAM | 0x21c,
    0xe5, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x250,
    0xed, 0x1ca, OBJ_SPRITE_OAM | 0x26f,
    0xeb, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_SamusLifted_Frame0[13] = {
    0x4,
    0xe2, OBJ_SIZE_32x32 | 0x1ad, OBJ_SPRITE_OAM | 0x21c,
    0xdd, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0x250,
    0xe5, 0x1c8, OBJ_SPRITE_OAM | 0x26f,
    0xea, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x38f
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame0[13] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x385,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x345,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x369,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x8, OBJ_SPRITE_OAM | 0x326
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x385,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3c5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3e5,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x345,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x369,
    OBJ_SHAPE_HORIZONTAL | 0xca, 0x9, OBJ_SPRITE_OAM | 0x326
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame2[10] = {
    0x3,
    0xe1, OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x2a5,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x285,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x289
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x245,
    0xf0, OBJ_SIZE_16x16 | 0x21, OBJ_SPRITE_OAM | 0x249
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x1245,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x21, OBJ_SPRITE_OAM | 0x1249
};

const u16 sRidleyPartOAM_LeftWingIdle_Frame5[10] = {
    0x3,
    0xfe, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x12a5,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x1285,
    OBJ_SHAPE_VERTICAL | 0x6, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x1289
};

const u16 sRidleyPartOAM_RightWingIdle_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x1345,
    0xee, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x13c5,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1347,
    0xf4, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x13c7,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x2, OBJ_SPRITE_OAM | 0x1369
};

const u16 sRidleyPartOAM_RightWingIdle_Frame1[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1345,
    0xef, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x13c5,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1347,
    0xf4, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x13c7,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_16x32 | 0x2, OBJ_SPRITE_OAM | 0x1369
};

const u16 sRidleyPartOAM_RightWingIdle_Frame2[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xd9, 0x1f0, OBJ_SPRITE_OAM | 0x1285,
    0xe1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12a5,
    0xf1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12e5,
    0xd9, 0x0, OBJ_SPRITE_OAM | 0x1288,
    0xe1, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x12a7,
    0xf1, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x12e7,
    0xd9, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x1289,
    0xe9, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x12c9
};

const u16 sRidleyPartOAM_RightWingIdle_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x1245,
    0xf1, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x1249
};

const u16 sRidleyPartOAM_RightWingIdle_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x1245,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x1249
};

const u16 sRidleyPartOAM_RightWingIdle_Frame5[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x285,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2a5,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2e5,
    0x20, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x288,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x2a7,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x2e7,
    0x18, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x289,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x2c9
};

const u16 sRidleyTailOAM_Part_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207
};

const u16 sRidleyTailOAM_TipPointingDown_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x380
};

const u16 sRidleyTailOAM_TipPointingUp_Frame0[4] = {
    0x1,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x380
};

const u16 sRidleyTailOAM_TipPointingDiagonallyDownRight_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x398
};

const u16 sRidleyTailOAM_TipPointingDiagonallyUpRight_Frame0[4] = {
    0x1,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x398
};

const u16 sRidleyTailOAM_TipPointingDiagonallyDownLeft_Frame0[4] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x398
};

const u16 sRidleyTailOAM_TipPointingDiagonallyUpLeft_Frame0[4] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x398
};

const u16 sRidleyOAM_Square_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x303
};

const u16 sRidleyFireballOAM_Small_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2209
};

const u16 sRidleyFireballOAM_Big_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x239c
};

const struct FrameData sRidleyOAM_Idle[7] = {
    sRidleyOAM_Idle_Frame0,
    0xE,
    sRidleyOAM_Idle_Frame1,
    0xE,
    sRidleyOAM_Idle_Frame2,
    0xE,
    sRidleyOAM_Idle_Frame3,
    0xE,
    sRidleyOAM_Idle_Frame2,
    0xE,
    sRidleyOAM_Idle_Frame1,
    0xE,
    NULL,
    0x0
};

const struct FrameData sRidleyOAM_SpittingFireballs[5] = {
    sRidleyOAM_Idle_Frame0,
    0x3,
    sRidleyOAM_SpittingFireballs_Frame1,
    0x3,
    sRidleyOAM_SpittingFireballs_Frame2,
    0x3,
    sRidleyOAM_SpittingFireballs_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyOAM_TurningAroundFirstPart[3] = {
    sRidleyOAM_TurningAround_Frame0,
    0x4,
    sRidleyOAM_TurningAround_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyOAM_TurningAroundSecondPart[3] = {
    sRidleyOAM_TurningAround_Frame1,
    0x4,
    sRidleyOAM_TurningAround_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_HeadIdle[3] = {
    sRidleyPartOAM_HeadIdle_Frame0,
    0xE,
    sRidleyPartOAM_HeadIdle_Frame1,
    0x40,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_OpeningMouth[2] = {
    sRidleyPartOAM_OpeningMouth_Frame0,
    0x5,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_MouthOpened[3] = {
    sRidleyPartOAM_MouthOpened_Frame0,
    0x3,
    sRidleyPartOAM_MouthOpened_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_HeadDying[5] = {
    sRidleyPartOAM_HeadDying_Frame0,
    0x3,
    sRidleyPartOAM_HeadDying_Frame1,
    0x3,
    sRidleyPartOAM_HeadDying_Frame2,
    0x3,
    sRidleyPartOAM_HeadDying_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_HeadTurningAround[2] = {
    sRidleyPartOAM_HeadTurningAround_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawIdle[7] = {
    sRidleyPartOAM_ClawIdle_Frame0,
    0xE,
    sRidleyPartOAM_ClawIdle_Frame1,
    0xE,
    sRidleyPartOAM_ClawIdle_Frame2,
    0xE,
    sRidleyPartOAM_ClawIdle_Frame3,
    0x8,
    sRidleyPartOAM_ClawIdle_Frame2,
    0xE,
    sRidleyPartOAM_ClawIdle_Frame1,
    0xE,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawSpittingFireballs[5] = {
    sRidleyPartOAM_ClawIdle_Frame0,
    0x3,
    sRidleyPartOAM_ClawSpittingFireballs_Frame1,
    0x3,
    sRidleyPartOAM_ClawSpittingFireballs_Frame2,
    0x3,
    sRidleyPartOAM_ClawSpittingFireballs_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawTurningAroundFirstPart[3] = {
    sRidleyPartOAM_ClawTurningAround_Frame0,
    0x4,
    sRidleyPartOAM_ClawTurningAround_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawTurningAroundSecondPart[3] = {
    sRidleyPartOAM_ClawTurningAround_Frame1,
    0x4,
    sRidleyPartOAM_ClawTurningAround_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawCarryingSamus[2] = {
    sRidleyPartOAM_ClawIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawLiftingSamus[6] = {
    sRidleyPartOAM_ClawLiftingSamus_Frame0,
    0x6,
    sRidleyPartOAM_ClawLiftingSamus_Frame1,
    0x6,
    sRidleyPartOAM_ClawLiftingSamus_Frame2,
    0x6,
    sRidleyPartOAM_ClawLiftingSamus_Frame3,
    0x6,
    sRidleyPartOAM_ClawLiftingSamus_Frame4,
    0x6,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawSamusLifted[2] = {
    sRidleyPartOAM_SamusLifted_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_ClawReleasingSamus[6] = {
    sRidleyPartOAM_ClawLiftingSamus_Frame4,
    0x2,
    sRidleyPartOAM_ClawLiftingSamus_Frame3,
    0x2,
    sRidleyPartOAM_ClawLiftingSamus_Frame2,
    0x2,
    sRidleyPartOAM_ClawLiftingSamus_Frame1,
    0x2,
    sRidleyPartOAM_ClawLiftingSamus_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_LeftWingIdle[11] = {
    sRidleyPartOAM_LeftWingIdle_Frame0,
    0x4,
    sRidleyPartOAM_LeftWingIdle_Frame1,
    0x4,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x3,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame5,
    0x4,
    sRidleyPartOAM_LeftWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x3,
    sRidleyPartOAM_LeftWingIdle_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_RightWingIdle[11] = {
    sRidleyPartOAM_RightWingIdle_Frame0,
    0x4,
    sRidleyPartOAM_RightWingIdle_Frame1,
    0x4,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x3,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame5,
    0x4,
    sRidleyPartOAM_RightWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x3,
    sRidleyPartOAM_RightWingIdle_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_LeftWing_Unused[11] = {
    sRidleyPartOAM_LeftWingIdle_Frame0,
    0x3,
    sRidleyPartOAM_LeftWingIdle_Frame1,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x1,
    sRidleyPartOAM_LeftWingIdle_Frame4,
    0x1,
    sRidleyPartOAM_LeftWingIdle_Frame5,
    0x3,
    sRidleyPartOAM_LeftWingIdle_Frame4,
    0x1,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x1,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_RightWing_Unused[11] = {
    sRidleyPartOAM_RightWingIdle_Frame0,
    0x3,
    sRidleyPartOAM_RightWingIdle_Frame1,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x1,
    sRidleyPartOAM_RightWingIdle_Frame4,
    0x1,
    sRidleyPartOAM_RightWingIdle_Frame5,
    0x3,
    sRidleyPartOAM_RightWingIdle_Frame4,
    0x1,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x1,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_LeftWingSpittingFireballs[7] = {
    sRidleyPartOAM_LeftWingIdle_Frame0,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_LeftWingIdle_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyPartOAM_RightWingSpittingFireballs[7] = {
    sRidleyPartOAM_RightWingIdle_Frame0,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame4,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame3,
    0x2,
    sRidleyPartOAM_RightWingIdle_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_Part[2] = {
    sRidleyTailOAM_Part_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingDown[2] = {
    sRidleyTailOAM_TipPointingDown_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingUp[2] = {
    sRidleyTailOAM_TipPointingUp_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingDiagonallyDownRight[2] = {
    sRidleyTailOAM_TipPointingDiagonallyDownRight_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingDiagonallyUpRight[2] = {
    sRidleyTailOAM_TipPointingDiagonallyUpRight_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingDiagonallyDownLeft[2] = {
    sRidleyTailOAM_TipPointingDiagonallyDownLeft_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyTailOAM_TipPointingDiagonallyUpLeft[2] = {
    sRidleyTailOAM_TipPointingDiagonallyUpLeft_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyOAM_Square[2] = {
    sRidleyOAM_Square_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyFireballOAM_Small[2] = {
    sRidleyFireballOAM_Small_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyFireballOAM_Big[2] = {
    sRidleyFireballOAM_Big_Frame0,
    0xFF,
    NULL,
    0x0
};


/**
 * @brief 31aa4 | 9c | Synchronize the sub sprites of Ridley
 * 
 */
void RidleySyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];

    if (gCurrentSprite.roomSlot == RIDLEY_PART_TAIL)
    {
        gSubSpriteData2.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData2.xPosition = gCurrentSprite.xPosition;
    }
}

/**
 * @brief 31b40 | 88 | Synchronize the sub sprites of the Ridley tail
 * 
 */
void RidleyTailSyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData2.yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 31bc8 | 44 | Handles the floating Y movement when idle
 * 
 */
void RidleyIdleYFloatingMovement(void)
{
    u8 offset;
    i32 movement;

    offset = gCurrentSprite.arrayOffset;
    movement = sRidleyIdleYOffsets[offset];
    if (movement == SHORT_MAX)
    {
        movement = sRidleyIdleYOffsets[0]; // 0
        offset = 0x0;
    }

    gCurrentSprite.arrayOffset = offset + 0x1;
    gSubSpriteData1.yPosition += movement;
}

/**
 * @brief 31c0c | 4c | Handles the floating Y movement when spitting fireballs after spawning
 * 
 */
void RidleySpawnSpittingFireballsYFloatingMovement(void)
{
    u8 offset;
    i32 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sRidleySpawningSpittingFireballsYOffsets[offset];
        if (movement == SHORT_MAX)
        {
            movement = sRidleySpawningSpittingFireballsYOffsets[0]; // 0
            offset = 0x0;
        }

        gCurrentSprite.arrayOffset = offset + 0x1;
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 31c58 | 180 | Updates the health of Ridley
 * 
 */
void RidleyUpdateHealth(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
        case RIDLEY_POSE_SPAWNING:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
        case RIDLEY_POSE_TAIL_ATTACKS:
            gBossWork.work3 = 0x0;
            break;

        default:
            if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x10)
                SoundPlayNotAlreadyPlaying(0x1ED);

            if (gCurrentSprite.health == 0x0 && gSubSpriteData1.health != 0x0)
            {
                // Dead
                gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                gBossWork.work3 = 0x0;
            }
            else
            {
                // Update received damage
                gBossWork.work3 += gSubSpriteData1.health - gCurrentSprite.health;
                if (gBossWork.work3 > 0xC8)
                {
                    // Agressive threshold, set big fireballs
                    gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                    gBossWork.work3 = 0x0;
                }
            }

            gSubSpriteData1.health = gCurrentSprite.health;
    }
}

/**
 * @brief 31dd8 | 68 | Checks if Ridley is grabbing Samus
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u8 1 if grabbing, 0 otherwise
 */
u8 RidleyCheckGrabbing(u16 yPosition, u16 xPosition)
{
    u16 xOffset;
    
    yPosition += BLOCK_SIZE * 4;

    if (gSamusData.xPosition > xPosition)
        xOffset = xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
    else
        xOffset = xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);

    if (SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.drawDistanceLeftOffset) == COLLISION_AIR &&
        SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.drawDistanceRightOffset) == COLLISION_AIR)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 31e40 | 256 | Handles the claw being idle
 * 
 * @param ramSlot Ridley's RAM slot
 */
void RidleyPartClawIdle(u8 ramSlot)
{
    u8 updatePosition;
    u8 interval;
    u16 yPosition;
    u16 xPosition;

    updatePosition = FALSE;

    // Check samus is grabbed
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING))
        return;

    // Get damage interval
    if (gDifficulty == DIFF_EASY)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 0x7;
        else
            interval = 0x3;
    }
    else if (gDifficulty == DIFF_HARD)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 0x1;
        else
            interval = 0x0;
    }
    else
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 0x3;
        else
            interval = 0x1;
    }

    // Apply damage
    if (!(gFrameCounter8Bit & interval))
    {
        if (gEquipment.currentEnergy > 0x1)
        {
            gEquipment.currentEnergy--;
            gSamusData.invincibilityTimer = 0x8;
        }
        else
        {
            gEquipment.currentEnergy = 0x0;
            SamusSetPose(SPOSE_HURT_REQUEST);
        }
    }

    if (gSamusData.pose != SPOSE_MIDAIR)
        SamusSetPose(SPOSE_MIDAIR);

    // Get Samus position
    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
        case RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS:
            updatePosition++;

            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 4;
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            else
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS:
            updatePosition++;

            switch (gCurrentSprite.currentAnimationFrame)
            {
                case 0x0:
                    yPosition = gCurrentSprite.yPosition + 0xEC;
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        xPosition = gCurrentSprite.xPosition + 0xB8;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xB8;
                    break;
                
                case 0x1:
                    yPosition = gCurrentSprite.yPosition + 0xDC;
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        xPosition = gCurrentSprite.xPosition + 0xD0;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xD0;
                    break;
                
                case 0x2:
                    yPosition = gCurrentSprite.yPosition + 0xC0;
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        xPosition = gCurrentSprite.xPosition + 0xEC;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xEC;
                    break;
                
                case 0x3:
                    yPosition = gCurrentSprite.yPosition + 0x9C;
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        xPosition = gCurrentSprite.xPosition + 0xF0;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xF0;
                    break;
                
                case 0x4:
                    yPosition = gCurrentSprite.yPosition + 0x7C;
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        xPosition = gCurrentSprite.xPosition + 0xF0;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xF0;
                    break;
            }
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED:
        case RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH:
        case RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS:
            updatePosition++;
            yPosition = gCurrentSprite.yPosition + 0x60;
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                xPosition = gCurrentSprite.xPosition + 0x100;
            else
                xPosition = gCurrentSprite.xPosition - 0x100;
            break;
    }

    if (updatePosition)
    {
        if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.drawDistanceLeftOffset) == COLLISION_AIR &&
            SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.drawDistanceRightOffset) == COLLISION_AIR)
        {
            gSamusData.yPosition = yPosition;
            gSamusData.xPosition = xPosition;
        }
        else
        {
            // Release
            gSpriteData[ramSlot].pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
            gBossWork.work3 = 0x0;
        }
    }
    
}

/**
 * @brief 320a8 | 30 | Checks if a screen shake should start when Ridley does the vertical tail attack
 * 
 */
void RidleyTailCheckStartScreenShakeVerticalTailAttack(void)
{
    if (gCurrentSprite.yPositionSpawn + 0x14 < RIDLEY_GROUND_POSITION && gCurrentSprite.yPosition + 0x14 > (BLOCK_SIZE * 18 - 2))
        ScreenShakeStartVertical(0x14, 0x81);

    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 320d8 | b0 | Handles Ridley's X movement when doing a tail attack
 * 
 * @param movement X Movement
 * @return u8  1 if hitting solid, 0 otherwise
 */
u8 RidleyTailAttacksXMove(u16 movement)
{
    u8 ramSlot;
    u8 result;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    result = FALSE;
    
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check on right
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition += movement;
    }
    else
    {
        // Check on left
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition -= movement;
    }

    // Check flip
    if (result)
        gSpriteData[ramSlot].status ^= SPRITE_STATUS_FACING_RIGHT;
    
    return result;
}

/**
 * @brief 32188 | 44 | Handles Ridley's Y movement when doing a tail attack
 * 
 * @param movement Y Movement
 */
void RidleyTailAttacksYMove(u16 movement)
{
    if (gSamusData.yPosition >= gSubSpriteData1.yPosition &&
        gSubSpriteData1.yPosition < (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE) &&
        gCurrentSprite.yPosition + 0x14 < RIDLEY_GROUND_POSITION)
    {
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 321cc | 58 | Spawns an ascending fireball
 * 
 * @param timer Influences room slot
 */
void RidleySpawnAscendingFireball(u16 timer)
{
    u16 status;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        status = SPRITE_STATUS_FACING_RIGHT;
        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }
    else
    {
        status = SPRITE_STATUS_NONE;
        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, timer / 16 & 0xF, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition,
        xPosition, status);
}

/**
 * @brief 32224 | 284 | Initializes Ridley
 * 
 */
void RidleyInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u16 health;
    u8 ramSlot;
    u8 caa;

    gBossWork.work1 = gCurrentSprite.yPosition;
    gBossWork.work2 = gCurrentSprite.xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
    {
        // Already dead, destroy blocks
        yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
        xPosition = gBossWork.work2;
        caa = CAA_REMOVE_SOLID;

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);
        gCurrentSprite.status = 0x0;
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
            gCurrentSprite.status = 0x0;
        else
        {
            // Has gravity
            // Lock doors
            gDoorUnlockTimer = 0x1;

            gCurrentSprite.drawOrder = 0x8;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            
            // Move in ceiling
            gCurrentSprite.yPosition -= BLOCK_SIZE * 8;
            gCurrentSprite.xPosition -= BLOCK_SIZE;

            gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
            gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

            health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.health = health;
            gSubSpriteData1.health = health;

            // Damage threshold
            gBossWork.work3 = 0x0;

            gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = RIDLEY_POSE_CHECK_PLAY_CUTSCENE;
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_XFLIP |
                SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.roomSlot = RIDLEY_PART_BODY;

            yPosition = gSubSpriteData1.yPosition;
            xPosition = gSubSpriteData1.xPosition;
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.primarySpriteRAMSlot;

            // Spawn left wing
            SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_LEFT_WING, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);

            // Spawn head
            gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_HEAD,
                gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_XFLIP);

            // Spawn tail
            SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_TAIL, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);

            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_TIP, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MOST, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MIDDLE, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_RIGHT, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MOST, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MIDDLE, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_LEFT, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_BODY_ATTACHMENT, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);

            // Spawn claw
            gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_CLAW,
                gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_XFLIP);

            // Spawn right wing
            SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_RIGHT_WING, gfxSlot, ramSlot,
                yPosition, xPosition, SPRITE_STATUS_XFLIP);
        }
    }
}

/**
 * @brief 324a8 | b4 | Checks if the cutscene should play
 * 
 */
void RidleyCheckPlayCutscene(void)
{
    i32 spriteX;
    i32 samusX;
    u8 inRange;

    inRange = FALSE;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gSamusData.yPosition == RIDLEY_GROUND_POSITION)
    {
        spriteX = (u16)(gBossWork.work2 + HALF_BLOCK_SIZE);
        samusX = gSamusData.xPosition;

        // Left of platform
        if (spriteX + BLOCK_SIZE * 5 > samusX && spriteX + BLOCK_SIZE * 4 < samusX)
            inRange++;
        // Near door
        else if (spriteX + BLOCK_SIZE * 7 < samusX)
            inRange++;

        // In range and facing left
        if (inRange && gSamusData.direction & KEY_LEFT)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.pose = RIDLEY_POSE_SPAWNING;

            gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;

            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
            gCurrentSprite.oamScaling = 0x12C;

            start_effect_for_cutscene(0x5); // Undefined
        }
    }
}

/**
 * @brief 3255c | 6e4 | Handles Ridley spawning
 * 
 */
void RidleySpawning(void)
{
    u16 yPosition;
    u16 yMovement;
    u16 xPosition;
    u8 turning;

    turning = FALSE;
    switch (gCurrentSprite.workVariable)
    {
        case RIDLEY_SPAWNING_ACTION_GOING_DOWN:
            // Move down
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > HALF_BLOCK_SIZE)
                    yMovement = HALF_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
                xPosition = gBossWork.work2;
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - BLOCK_SIZE * 6) != COLLISION_AIR)
                {
                    // Destroy ground
                    turning = CAA_REMOVE_SOLID;

                    // Left blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);
                    
                    // Right blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
                    
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);

                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlay(0x1F2);
                }

                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(0x1E, 0x81);
                gCurrentSprite.workVariable++;
                gCurrentSprite.timer = 0x1E;
                gCurrentSprite.arrayOffset = 0x0;
                SoundPlay(0x1E6);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
                SoundPlay(0x1E5);
                gCurrentSprite.timer = 0x5;
                gCurrentSprite.workVariable++;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_OPENING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawSpittingFireballs;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable++;
                SoundPlay(0x1E7);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_SPITTING_FIREBALLS:
            // Spawn fireballs
            if (!(gCurrentSprite.oamScaling & 0xF))
                RidleySpawnAscendingFireball(gCurrentSprite.oamScaling);

            if (gCurrentSprite.oamScaling != 0x0)
            {
                gCurrentSprite.oamScaling--;

                // Check turn if samus is behind
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (!turning)
                    break;
            }
            
            gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
            gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
            gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0x5;
            gCurrentSprite.workVariable++;
            SoundFade(0x1E7, 0x1E);
            break;

        case RIDLEY_SPAWNING_ACTION_CLOSING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                // Check turning
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (turning)
                {
                    // Set turning
                    gCurrentSprite.timer = 0xA;
                    gCurrentSprite.workVariable++;
                }
                else
                {
                    // Set taking off
                    gCurrentSprite.workVariable = RIDLEY_SPAWNING_ACTION_TAKING_OFF;
                    gCurrentSprite.timer = 0x1E;
                }
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_INIT:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadTurningAround;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawTurningAroundFirstPart;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable++;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_FIRST_PART:
            if (SpriteUtilCheckEndSubSprite1Anim())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawTurningAroundSecondPart;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.workVariable++;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_SECOND_PART:
            if (SpriteUtilCheckEndSubSprite1Anim())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                gCurrentSprite.timer = 0xA;
                gCurrentSprite.workVariable = RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TAKING_OFF:
            if (gCurrentSprite.timer == 0x0)
            {
                // Move Y on 8 blocks
                yMovement = (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                if (yMovement < gSubSpriteData1.yPosition)
                {
                    yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                    yMovement /= 4;

                    if (yMovement > HALF_BLOCK_SIZE)
                        yMovement = HALF_BLOCK_SIZE;
                    else if (yMovement < 0x4)
                        yMovement = 0x4;

                    gSubSpriteData1.yPosition -= yMovement;
                }
                else
                {
                    // Set idle
                    gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                    gSubSpriteData1.health = gCurrentSprite.health;
                }
            }
            else
                gCurrentSprite.timer--;

            return;

        case RIDLEY_SPAWNING_ACTION_UNKNOWN:
            if (gCurrentSprite.timer != 0x0)
                gCurrentSprite.timer--;
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + 0x17C) != COLLISION_AIR)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    else
                        gSubSpriteData1.xPosition += QUARTER_BLOCK_SIZE;
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - 0x17C) != COLLISION_AIR)
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    else
                        gSubSpriteData1.xPosition -= QUARTER_BLOCK_SIZE;
                }

                if (--gCurrentSprite.workVariable2 == 0x0)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
                    else
                        gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
                    
                    gCurrentSprite.workVariable = RIDLEY_SPAWNING_ACTION_GOING_DOWN;
                }
            }

        default:
            return;
    }
    
    RidleyIdleYFloatingMovement();
}

/**
 * @brief 32c40 | b8 | Initializes Ridley to be idle
 * 
 */
void RidleyIdleInit(void)
{
    u8 clawSlot;
    u16 range;

    clawSlot = gSubSpriteData1.workVariable5;

    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    // Update head
    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0x0;
    gSpriteData[clawSlot].currentAnimationFrame = 0x0;
    gSpriteData[clawSlot].samusCollision = SSC_RIDLEY_CLAW;

    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pose = RIDLEY_POSE_IDLE;

    range = (BLOCK_SIZE * 10 - 1);
    if (range < gSubSpriteData1.yPosition)
    {
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
    else
    {
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    }
}

/**
 * @brief 32cf8 | 5fc | Handles Ridley being idle
 * 
 */
void RidleyIdle(void)
{
    u8 samusGrabbed;
    u8 startSlide;
    u8 turningAround;
    u8 clawSlot;
    u16 yMovement;
    u16 xMovement;
    u8 action;

    turningAround = FALSE;
    samusGrabbed = FALSE;
    startSlide = FALSE;

    clawSlot = gSubSpriteData1.workVariable5;
    action = gSpriteData[clawSlot].workVariable;

    if (gSpriteData[clawSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Samus grabbed behavior
        samusGrabbed = TRUE;

        if (action == RIDLEY_SAMUS_GRABBED_ACTION_NONE)
        {
            gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawCarryingSamus;
            gSpriteData[clawSlot].animationDurationCounter = 0x0;
            gSpriteData[clawSlot].currentAnimationFrame = 0x0;
            gSpriteData[clawSlot].drawOrder = 0x8;
            
            gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS;
            gSpriteData[clawSlot].timer = 0x14;
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS)
        {
            gSpriteData[clawSlot].timer--;
            if (gSpriteData[clawSlot].timer == 0x0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawLiftingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0x0;
                gSpriteData[clawSlot].currentAnimationFrame = 0x0;

                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS;
                gSpriteData[clawSlot].timer = 0x1C;
                SoundPlay(0x1E4);
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS)
        {
            gSpriteData[clawSlot].timer--;
            if (gSpriteData[clawSlot].timer == 0x0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawSamusLifted;
                gSpriteData[clawSlot].animationDurationCounter = 0x0;
                gSpriteData[clawSlot].currentAnimationFrame = 0x0;
                
                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED;
                gSpriteData[clawSlot].timer = 0x14;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED)
        {
            gSpriteData[clawSlot].timer--;
            if (gSpriteData[clawSlot].timer == 0x0)
            {
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
                
                SoundPlay(0x1E5);
                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH;
                gSpriteData[clawSlot].timer = 0x5;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH)
        {
            gSpriteData[clawSlot].timer--;
            if (gSpriteData[clawSlot].timer == 0x0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
                
                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS;
                gSpriteData[clawSlot].timer = 0x0;
                gSpriteData[clawSlot].workVariable2 = 0x0;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS)
        {
            if (!(gSpriteData[clawSlot].timer++ & 0xF))
            {
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_PART_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), SPRITE_STATUS_FACING_RIGHT);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_PART_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), SPRITE_STATUS_NONE);
                }

                SoundPlay(0x1E8);
            }

            // Update release timer
            if (gChangedInput & (KEY_A | KEY_B | KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN))
                gSpriteData[clawSlot].workVariable2 += 0x4;
            else if (gSpriteData[clawSlot].workVariable2 != 0x0)
                gSpriteData[clawSlot].workVariable2--;

            // Check release Samus (timer overflowed or mashed enough keys)
            if (gSpriteData[clawSlot].timer == 0x0 || gSpriteData[clawSlot].workVariable2 > 0x10)
            {
                // Release Samus
                gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawReleasingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0x0;
                gSpriteData[clawSlot].currentAnimationFrame = 0x0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS;
                gSpriteData[clawSlot].timer = 0x5;
                gSpriteData[clawSlot].drawOrder = 0x9;
                gSpriteData[clawSlot].ignoreSamusCollisionTimer = 0x1F;
            }
        }
    }
    else
    {
        if (action == RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS)
        {
            gSpriteData[clawSlot].timer--;
            if (gSpriteData[clawSlot].timer == 0x0)
            {
                gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                gSpriteData[clawSlot].workVariable = RIDLEY_SAMUS_GRABBED_ACTION_NONE;
            }
        }
    }

    if (gCurrentSprite.timer != 0x0)
    {
        if (!samusGrabbed)
        {
            // Check start new attack
            gCurrentSprite.timer--;
            if (SpriteUtilCheckCrouchingOrMorphed() && gSpriteRNG > 0x7 && gCurrentSprite.timer == 0x0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRNG > 0xD)
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRNG > 0xD)
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
            }
            
            // Check start big fireballs attack
            if (!(gFrameCounter8Bit & 0xF) && gSpriteRNG > 0x8 && gCurrentSprite.timer < 0xA)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
            }
        }

        RidleyIdleYFloatingMovement();
    }
    else
    {
        // Update Ridley position

        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            yMovement = gSubSpriteData1.yPosition + BLOCK_SIZE * 4 + 4;
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Going down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                yMovement /= 4;

                if (yMovement > 0x10)
                    yMovement = 0x10;

                gSubSpriteData1.yPosition += yMovement;
                if (yMovement == 0x0)
                {
                    if (gCurrentSprite.workVariable < 0x11)
                        gCurrentSprite.workVariable++;

                    // Check should start slide
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (gSubSpriteData1.xPosition + BLOCK_SIZE * 3 < gSamusData.xPosition)
                            startSlide++;
                    }
                    else
                    {
                        if (gSubSpriteData1.xPosition - BLOCK_SIZE * 3 > gSamusData.xPosition)
                            startSlide++;
                    }
                }
            }
            
            if ((gCurrentSprite.workVariable > 0x10 && !startSlide) || samusGrabbed)
            {
                gCurrentSprite.workVariable = 0x0;
                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
            }
        }
        else
        {
            // Going up

            // Get destination
            if (samusGrabbed)
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 11;
            else
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8;

            if (yMovement < gSubSpriteData1.yPosition)
            {
                yMovement = gSubSpriteData1.yPosition - yMovement;
                yMovement /= 4;

                if (yMovement > 0x10)
                    yMovement = 0x10;
                else if (yMovement < 0x4)
                    yMovement = 0x4;

                gSubSpriteData1.yPosition -= yMovement;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gCurrentSprite.timer = 0xA;
            }
        }
    }

    if (!samusGrabbed)
    {
        // Move X
        yMovement = BLOCK_SIZE * 4 + 4;

        // Get X movement
        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            if (startSlide)
                xMovement = 0x8;
            else
                xMovement = 0x2;            
        }
        else
            xMovement = 0x8;

        // Apply movement, check turning around
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition += xMovement;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition -= xMovement;
        }

        // Check turn around
        if (turningAround && (gCurrentSprite.timer != 0x0 || (gCurrentSprite.workVariable > 0x10 && startSlide)))
            gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Move X when samus grabbed
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition -= 0x2;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition += 0x2;
        }
    }
}

/**
 * @brief 332f4 | 88 | Initializes Ridley to be turning around
 * 
 */
void RidleyTurningAroundInit(void)
{
    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    // Update head
    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadTurningAround;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

    // Update claw
    gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawTurningAroundFirstPart;
    gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
    gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

    gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_FIRST_PART;
}

/**
 * @brief 3337c | 94 | Handles the first part of Ridley turning around
 * 
 */
void RidleyTurningAroundFirstPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_SECOND_PART;

        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        // Update claw
        gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawTurningAroundSecondPart;
        gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

        // Flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        if(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
}

/**
 * @brief 33410 | 94 | Handles the second part of Ridley turning around
 * 
 */
void RidleyTurningAroundSecondPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set idle
        gCurrentSprite.pose = RIDLEY_POSE_IDLE;
        
        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        // Update head
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

        // Update claw
        gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawIdle;
        gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 334a4 | 68 | Initializes Ridley for the small fireball attack
 * 
 */
void RidleySmallFireballsAttackInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.workVariable5;

    gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0x0;
    gSpriteData[clawSlot].currentAnimationFrame = 0x0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].workVariable = 0x0;
    gSpriteData[clawSlot].drawOrder = 0x9;

    gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK;
    gCurrentSprite.workVariable = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.oamScaling = 0xB4;
}

/**
 * @brief 3350c | 330 | Handles ridley doing the small fireballs attack
 * 
 */
void RidleySmallFireballsAttack(void)
{
    u8 stopAttack;
    u16 yMovement;

    stopAttack = FALSE;

    switch (gCurrentSprite.workVariable)
    {
        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN:
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Go down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > 0x20)
                    yMovement = 0x20;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                // Reached ground
                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(0x1E, 0x81);

                gCurrentSprite.workVariable++;
                gCurrentSprite.timer = 0x1E;
                gCurrentSprite.arrayOffset = 0x0;

                SoundPlay(0x1E6);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                SoundPlay(0x1E5);
                gCurrentSprite.timer = 0x5;
                gCurrentSprite.workVariable++;
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_OPENING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Set spitting fireballs behavior
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable++;
                SoundPlay(0x1E7);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_SPITTING_FIREBALLS:
            // Spawn fireball
            if (!(gCurrentSprite.oamScaling & 0xF))
                RidleySpawnAscendingFireball(gCurrentSprite.oamScaling);

            if (gCurrentSprite.oamScaling != 0x0)
            {
                gCurrentSprite.oamScaling--;
                // Check stop attack if samus is behind Ridley
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        stopAttack++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        stopAttack++;
                }

                if (!stopAttack)
                    break;
            }

            // Update head
            gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
            gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
            gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0x5;
            gCurrentSprite.workVariable++;
            SoundFade(0x1E7, 0x1E);
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_CLOSING_MOUTH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0x0;
                gSubSpriteData1.currentAnimationFrame = 0x0;

                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

                // Update claw
                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOAM_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0x0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF;
                gCurrentSprite.timer = 0x1E;
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF:
            if (gCurrentSprite.timer != 0x0)
                gCurrentSprite.timer--;
            else
            {
                yMovement = (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                if (yMovement < gSubSpriteData1.yPosition)
                {
                    // Move upwards
                    yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                    yMovement /= 4;
                    if (yMovement > 0x20)
                        yMovement = 0x20;
                    else if (yMovement < 0x4)
                        yMovement = 0x4;

                    gSubSpriteData1.yPosition -= yMovement;
                }
                else
                    gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT; // Set idle
            }
            break;
    }
}

/**
 * @brief 3383c | 78 | Initializes Ridley for any tail attack
 * 
 */
void RidleyTailAttacksInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.workVariable5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadIdle;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;

    gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0x0;
    gSpriteData[clawSlot].currentAnimationFrame = 0x0;
}

/**
 * @brief 338b4 | 4 | Empty function (tail attacks)
 * 
 */
void Ridley_Empty(void)
{
    return;
}

/**
 * @brief 338b8 | 11c | Initializes Ridley for the big fireballs attack
 * 
 */
void RidleyBigFireballsAttackInit(void)
{
    u8 clawSlot;
    u8 pose;

    clawSlot = gSubSpriteData1.workVariable5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT)
    {
        // Normal attack
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_MouthOpened;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
        pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK;
    }
    else
    {
        // Attack forced because Ridley got hurt
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_HeadDying;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
        pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK;
    }

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOAM_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0x0;
    gSpriteData[clawSlot].currentAnimationFrame = 0x0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].workVariable = 0x0;
    gSpriteData[clawSlot].drawOrder = 0x9;

    if (gCurrentSprite.health == 0x0)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_POSE_DYING;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x96;
        gCurrentSprite.workVariable2 = 0xB4;
        gCurrentSprite.arrayOffset = 0x1;
        SoundPlay(0x1EE);
    }
    else
    {
        // Set doing attack
        gCurrentSprite.pose = pose;
        gCurrentSprite.timer = 0x32;
    }
}

/**
 * @brief 339d4 | 12c | Handles ridley doing the big fireballs attack
 * 
 */
void RidleyBigFireballsAttack(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 status;

    if (--gCurrentSprite.timer == 0x0)
    {
        // Set new pose
        if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK)
        {
            // Idle if started the attack normally
            gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
        }
        else
        {
            // Tail attack init if started the attack because Ridley got hurt
            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
        }
    }
    else if (gCurrentSprite.timer == 0x4)
    {
        // Update head
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOAM_OpeningMouth;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0x0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0x0;
    }
    else if (gCurrentSprite.timer == 0x14)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            status = SPRITE_STATUS_FACING_RIGHT;
            xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }
        else
        {
            status = SPRITE_STATUS_NONE;
            xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }

        yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);

        // Spawn fireballs, floating pattern
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_TOP,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE_TOP,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE_BOTTOM,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_BOTTOM,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, status);

        SoundPlay(0x1E9);
    }
}

/**
 * @brief 33b00 | 214 | Handles ridley dying
 * 
 */
void RidleyDying(void)
{
    u8 rngParam1;
    u8 rngParam2;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.workVariable2 != 0x0)
    {
        if (gCurrentSprite.workVariable2 > 0x2)
            gCurrentSprite.workVariable2--;
        else
        {
            if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 5))
                gCurrentSprite.workVariable2--;

            if (gCurrentSprite.workVariable2 == 0x1)
                start_effect_for_cutscene(0x6); // Undefined
            else if (gCurrentSprite.workVariable2 == 0x0)
                MusicFade(0x96);
        }
    }

    // Slowly move to ground
    if (gSubSpriteData1.yPosition < (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 3))
        gSubSpriteData1.yPosition++;

    rngParam1 = gSpriteRNG;
    rngParam2 = gFrameCounter8Bit;

    // Play effects
    if (!(gCurrentSprite.timer & 0x1F))
    {
        if (gCurrentSprite.timer & 0x20)
            ParticleSet(gCurrentSprite.yPosition - 0x96 + rngParam1 * 4, gCurrentSprite.xPosition + 0x6E - rngParam1 * 4, PE_SPRITE_EXPLOSION_HUGE);
        else
            ParticleSet(gCurrentSprite.yPosition + 0x96 - rngParam1 * 4, gCurrentSprite.xPosition - 0x6E + rngParam1 * 4, PE_SPRITE_EXPLOSION_BIG);
    }

    if (!(gCurrentSprite.arrayOffset & 0x1F))
    {
        if (gCurrentSprite.arrayOffset & 0x20)
            ParticleSet(gCurrentSprite.yPosition - 0x50 + rngParam2 / 4, gCurrentSprite.xPosition + 0x3C - rngParam2 / 4, PE_MAIN_BOSS_DEATH);
        else
            ParticleSet(gCurrentSprite.yPosition + 0x50 - rngParam2 / 4, gCurrentSprite.xPosition - 0x3C + rngParam2 / 4, PE_MAIN_BOSS_DEATH);
    }

    gCurrentSprite.timer++;
    gCurrentSprite.arrayOffset++;

    if (gCurrentSprite.workVariable2 == 0x0)
    {
        // After cutscen

        // Add more effects
        if (!(gCurrentSprite.timer & 0xF))
        {
            if (gCurrentSprite.timer & 0x8)
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * 8, gCurrentSprite.xPosition - rngParam1 * 8, PE_SPRITE_EXPLOSION_BIG);
            else
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * 4, gCurrentSprite.xPosition - rngParam1 * 4, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }

        if (!(gCurrentSprite.arrayOffset & 0xF))
        {
            if (gCurrentSprite.arrayOffset & 0x8)
                ParticleSet(gCurrentSprite.yPosition - 0x40 - rngParam1 * 8, gCurrentSprite.xPosition + 0x20 + rngParam1 * 8, PE_SPRITE_EXPLOSION_BIG);
            else
                ParticleSet(gCurrentSprite.yPosition + 0x50 + rngParam1 * 8, gCurrentSprite.xPosition + 0x20 + rngParam1 * 2, PE_SPRITE_EXPLOSION_BIG);
        }

        // Flicker
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        if (--gCurrentSprite.workVariable == 0x0)
        {
            // Kill sprite
            gCurrentSprite.status = 0x0;
            // Unlock doors
            gDoorUnlockTimer = -0x3C;
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_KILLED);
            // Update minimap
            MinimapUpdateChunk(EVENT_RIDLEY_KILLED);
            MusicPlay(MUSIC_BOSS_KILLED, 0x0);
        }
        else if (gCurrentSprite.workVariable == 0x95)
            SoundPlay(0x1EF);
    }
}

/**
 * @brief 33d14 | 148 | Initializes a Ridley part sprite
 * 
 */
void RidleyPartInit(void)
{
    gCurrentSprite.pose = RIDLEY_PART_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_PART_LEFT_WING:
            gCurrentSprite.drawOrder = 0x6;
            
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_HEAD:
            gCurrentSprite.drawOrder = 0x7;

            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            break;

        case RIDLEY_PART_CLAW:
            gCurrentSprite.drawOrder = 0x9;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = 0x60;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = -0xE0;
            gCurrentSprite.hitboxRightOffset = -0xA0;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.workVariable = 0x0;
            break;

        case RIDLEY_PART_TAIL:
            gCurrentSprite.drawOrder = 0x8;

            gCurrentSprite.drawDistanceTopOffset = 0x1;
            gCurrentSprite.drawDistanceBottomOffset = 0x1;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x1;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_RIGHT_WING:
            gCurrentSprite.drawOrder = 0xA;
            
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }

    RidleySyncSubSprites();
}

/**
 * @brief 33e5c | 70 | Plays the wing flapping sound
 * 
 * @param ramSlot Ridley's RAM slot
 */
void RidleyPartWingPlaySound(u8 ramSlot)
{
    if (gSpriteData[ramSlot].pose > RIDLEY_POSE_CHECK_PLAY_CUTSCENE &&
        (gSpriteData[ramSlot].pose != RIDLEY_POSE_DYING || gSpriteData[ramSlot].workVariable2 != 0x0) &&
        gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
    {
        if (gCurrentSprite.pOam == sRidleyPartOAM_LeftWingIdle)
            SoundPlay(0x1E1);
        else if (gCurrentSprite.pOam == sRidleyPartOAM_LeftWingSpittingFireballs)
            SoundPlay(0x1E2);
    }
}

/**
 * @brief 33ecc | 38 | Updates the frozen palette offset of a wing
 * 
 */
void RidleyPartWingSetPaletteOffset(void)
{
    u16 part;
    u16 flag;

    part = gCurrentSprite.pOam[gCurrentSprite.currentAnimationFrame].pFrame[3];
    flag = 15 << 12;
    
    if ((part & flag) == 1 << 15)
        gCurrentSprite.frozenPaletteRowOffset = 0x0;
    else
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

/**
 * @brief 33f04 | Synchronizes the palette of a Ridley part with Ridley
 * 
 * @param ramSlot Ridley's RAM slot
 */
void RidleyPartSyncPalette(u8 ramSlot)
{
    if (gSpriteData[ramSlot].paletteRow == 0xE)
        gCurrentSprite.paletteRow = 0xE - gCurrentSprite.frozenPaletteRowOffset;
    else
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 33f48 | 2c | Updates the side hitboxes of the claw
 * 
 */
void RidleyPartClawUpdateSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.hitboxLeftOffset = 0xA0;
        gCurrentSprite.hitboxRightOffset = 0xE0;
    }
    else
    {
        gCurrentSprite.hitboxLeftOffset = -0xE0;
        gCurrentSprite.hitboxRightOffset = -0xA0;
    }
}

/**
 * @brief 33f74 | 146 | Handles a Ridley tail dying
 * 
 */
void RidleyTailDead(void)
{
    u8 rng;

    rng = gSpriteRNG;
    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_TAIL_PART_BODY_ATTACHMENT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x44 + rng,
                gSubSpriteData1.xPosition + 0x64 - rng * 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0xA0 - rng,
                gSubSpriteData1.xPosition - rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x30 + rng,
                gSubSpriteData1.xPosition - 0x1C - rng * 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x30 + rng,
                gSubSpriteData1.xPosition - 0x50 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x20 - rng,
                gSubSpriteData1.xPosition + 0x50 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_LEFT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x64 - rng,
                gSubSpriteData1.xPosition - 0x8C - rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x50 - rng,
                gSubSpriteData1.xPosition + 0x28 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_TIP:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x78 + rng,
                gSubSpriteData1.xPosition - 0x78 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x1F0);
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 340b8 | 9c | Initializes a Ridley tail sprite
 * 
 */
void RidleyTailInit(void)
{
    gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.health = 0x1;
    gCurrentSprite.drawOrder = 0xB;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.roomSlot == RIDLEY_TAIL_PART_TIP)
    {
        // Set multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;

        gCurrentSprite.yPositionSpawn = 0x0;

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0x30;
        gCurrentSprite.hitboxBottomOffset = 0x30;
        gCurrentSprite.hitboxLeftOffset = -0x30;
        gCurrentSprite.hitboxRightOffset = 0x30;
    }
    else
    {
        // Initialize parts
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x20;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;
    }
}

/**
 * @brief 34154 | 74 | Handles a Ridley tail being idle
 * 
 */
void RidleyTailIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSubSpriteData1.pMultiOam != sRidleyMultiSpriteData_SpittingFireballs && gSubSpriteData2.pMultiOam == sRidleyTailMultiSpriteData_Dying)
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;
    }
    
    if (gSpriteData[ramSlot].pose == RIDLEY_POSE_TAIL_ATTACKS_INIT)
    {
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_MOVE_TO_ATTACK;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_MoveToAttack;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 341c8 | 30 | Checks if the moving tail to attack animation ended
 * 
 */
void RidleyTailCheckMovingToAttackAnimEnded(void)
{
    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_SettingUpDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_SETTING_UP_ATTACK;
    }
}

/**
 * @brief 341f8 | 80 | Handles the tail setting up an attack
 * 
 */
void RidleyTailSettingUpAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EA);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;

        // Number of swipes
        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.timer = 0x2;
        else
            gCurrentSprite.timer = gSpriteRNG / 2 + 0x2;
    }

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x2;
}

/**
 * @brief 34278 | 128 | Handles the Ridley tail charging the attack
 * 
 */
void RidleyTailChargingAttack(void)
{
    u8 ramSlot;
    u8 doDiagonal;

    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EA);

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    doDiagonal = FALSE;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSpriteData[ramSlot].pose = RIDLEY_POSE_TAIL_ATTACKS;

        // Flip and check do diagonal attack or not
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_XFLIP)
        {
            if (gSubSpriteData1.xPosition - BLOCK_SIZE * 2 > gSamusData.xPosition)
                gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
            {
                gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                doDiagonal = TRUE;
            }
        }
        else
        {
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition)
            {
                gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
                doDiagonal = TRUE;
            }
            else
                gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
        }

        if (doDiagonal)
        {
            // Do diagonal
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_DiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_DIAGONAL_ATTACK;
        }
        else
        {
            // No diagonal
            if (gDifficulty == DIFF_EASY)
            {
                gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
                gSubSpriteData2.animationDurationCounter = 0x0;
                gSubSpriteData2.currentAnimationFrame = 0x0;

                // Only 1 attack if easy
                gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
                gCurrentSprite.timer = 0x0;
            }
            else
            {
                gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingVerticalTailAttack;
                gSubSpriteData2.animationDurationCounter = 0x0;
                gSubSpriteData2.currentAnimationFrame = 0x0;

                gCurrentSprite.pose = RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK;
            }
        }
    }
}

/**
 * @brief 343a0 | 80 | Handles the first vertical attack
 * 
 */
void RidleyTailFirstVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_VerticalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_VERTICAL_ATTACK;
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 0x8)
            RidleyTailAttacksYMove(0xC);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= 0x8;

        RidleyTailAttacksXMove(0x2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 34420 | ec | Handles the Ridley tail doing the vertical attack
 * 
 */
void RidleyTailVerticalAttack(void)
{
    u8 stopAttack;
    u8 ramSlot;

    if (gSubSpriteData2.currentAnimationFrame == 0x0 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    stopAttack = FALSE;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Check stop attack
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            stopAttack++;
        else
        {
            // Stop if samus is behind Ridley
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    stopAttack++;
            }
            else
            {
                if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    stopAttack++;
            }
        }

        if (stopAttack)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
            return;
        }
    }
    
    if (gSubSpriteData2.currentAnimationFrame < 0x5)
        RidleyTailAttacksYMove(0xC);
    else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x8;

    RidleyTailAttacksXMove(0x4);
    RidleyTailCheckStartScreenShakeVerticalTailAttack();
}

/**
 * @brief 3450c | a8 | Handles the last vertical attack
 * 
 */
void RidleyTailLastVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0x0 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Check still has swipes left
        if (gCurrentSprite.timer != 0x0)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
        else
        {
            // Back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 0x5)
            RidleyTailAttacksYMove(0xC);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= 0x8;

        RidleyTailAttacksXMove(0x2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 345b4 | 88 | Handles the Ridley tail doing the diagonal attack
 * 
 */
void RidleyTailDiagonalAttack(void)
{
    struct SpriteData* pSprite;

    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EB);

    // Why
    pSprite = &gCurrentSprite;
    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Decrement swipe counter
        pSprite->timer--;
        if (pSprite->timer == 0x0)
        {
            // No more swipes, set back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;
            pSprite->pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
        else
        {
            // Start new swipe
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0x0;
            gSubSpriteData2.currentAnimationFrame = 0x0;
            pSprite->pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
    }
    else
    {
        RidleyTailAttacksYMove(0x4);
        RidleyTailAttacksXMove(0x4);
    }
}

/**
 * @brief 3463c | 84 | Checks if the back to idle animation ended
 * 
 */
void RidleyTailCheckBackToIdleAnimEnded(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x8;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Update multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;

        // Set the tail and Ridley to idle
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
        gSpriteData[ramSlot].pose = RIDLEY_POSE_IDLE_INIT;

        if (gSpriteData[ramSlot].status & SPRITE_STATUS_XFLIP)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
        else
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 346c0 | 50 | Checks if a Ridley fireball should slide off a wall
 * 
 */
void RidleyFireballCheckSlideOnWall(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY; // Touched ground, destroy
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check wall on right
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset) != COLLISION_AIR)
                gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
        else
        {
            // Check wall on left
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset) != COLLISION_AIR)
                gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
    }
}

/**
 * @brief 34710 | 14c | Initializes a Ridley fireball sprite
 * 
 */
void RidleyFireballInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x2;
    
    if (gCurrentSprite.spriteID == SSPRITE_RIDLEY_BIG_FIREBALL)
    {
        // Big fireball
        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0x28;
        gCurrentSprite.hitboxBottomOffset = 0x28;
        gCurrentSprite.hitboxLeftOffset = -0x28;
        gCurrentSprite.hitboxRightOffset = 0x28;

        gCurrentSprite.pOam = sRidleyFireballOAM_Big;
    }
    else
    {
        // Small fireball
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x1C;
        gCurrentSprite.hitboxBottomOffset = 0x1C;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;

        gCurrentSprite.pOam = sRidleyFireballOAM_Small;
    }
    
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.oamRotation = 0x0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;

    // Set pattern
    if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_PART_SAMUS_GRABBED)
    {
        // Diagonal pattern (when Samus is grabbed)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK;
        gCurrentSprite.oamScaling = 0x80;
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN;
    }
    else if (gCurrentSprite.roomSlot & RIDLEY_FIREBALL_PART_FLOATING_PATTERN)
    {
        // Floating pattern (big fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN;
    }
    else
    {
        // Descending pattern (small fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.oamScaling = 0x80;
        gCurrentSprite.timer = 0x10;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN;

        if (gCurrentSprite.yPosition < gSamusData.yPosition)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
}

/**
 * @brief 3485c | 50 | Handles a Ridley fireball moving in a diagonal pattern
 * 
 */
void RidleyFireballMoveDiagonalPattern(void)
{
    if (gCurrentSprite.oamScaling < 0xF0)
    {
        gCurrentSprite.yPosition = gSpriteData[gCurrentSprite.primarySpriteRAMSlot].yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.oamScaling += 0x10;
    }
    else
    {
        // Move
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += 0x8;
        else
            gCurrentSprite.xPosition -= 0x8;

        gCurrentSprite.yPosition += 0xA;

        RidleyFireballCheckSlideOnWall();
    }
}

/**
 * @brief 348b4 | 6c | Handles a Ridley fireball moving in a floating pattern
 * 
 */
void RidleyFireballMoveFloatingPattern(void)
{
    u8 part;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += 0x4;
    else
        gCurrentSprite.xPosition -= 0x4;

    // Update Y position
    part = gCurrentSprite.roomSlot & 0x7F;
    switch (part)
    {
        case RIDLEY_FIREBALL_PART_MIDDLE_TOP:
            gCurrentSprite.yPosition -= 0x4;
            break;

        case RIDLEY_FIREBALL_PART_MIDDLE:
            gCurrentSprite.yPosition += 0x4;
            break;

        case RIDLEY_FIREBALL_PART_MIDDLE_BOTTOM:
            gCurrentSprite.yPosition += 0x8;
            break;

        case RIDLEY_FIREBALL_PART_BOTTOM:
            gCurrentSprite.yPosition += 0xC;
    }

    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 34920 | 74 | Handles a Ridley fireball moving in a descending pattern
 * 
 */
void RidleyFireballMoveDescendingPattern(void)
{
    u16 movement;
    
    movement = gCurrentSprite.workVariable2++;

    if (gCurrentSprite.oamScaling < 0xF0)
        gCurrentSprite.oamScaling += 0x10;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += movement;
    else
        gCurrentSprite.xPosition -= movement;

    gCurrentSprite.yPosition += 0xC;
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.workVariable2 = 0x10;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = 0x10;
    }
}

/**
 * @brief 34994 | 50 | Handles a Ridley fireball moving in an ascending pattern
 * 
 */
void RidleyFireballMoveAscendingPattern(void)
{
    u16 yOffset;

    if (gCurrentSprite.roomSlot == 0x3)
        yOffset = 0x32;
    else if (gCurrentSprite.roomSlot == 0x2)
        yOffset = 0x64;
    else if (gCurrentSprite.roomSlot == 0x1)
        yOffset = 0x96;
    else
        yOffset = 0x0;

    SpriteUtilRidleyFireballMove((u16)(gSubSpriteData1.yPosition + 0x48 - yOffset), gSamusData.xPosition, 0x20, 0x28, 0x2);
    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 349e4 | 18 | Initializes a Ridley fireball to be sliding on a wall
 * 
 */
void RidleyFireballSlideOnWallInit(void)
{
    gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL;
    gCurrentSprite.arrayOffset = 0x4;
}

/**
 * @brief 349fc | 3c | Handles a Ridley fireball sliding on a wall
 * 
 */
void RidleyFireballSlideOnWall(void)
{
    u16 movement;

    movement = gCurrentSprite.arrayOffset / 4;
    
    if (movement < 0x14)
        gCurrentSprite.arrayOffset++;

    gCurrentSprite.yPosition += movement;
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY;
}

/**
 * @brief 34a38 | 2ec | Ridley AI
 * 
 */
void Ridley(void)
{
    RidleyUpdateHealth();

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            RidleyInit();
            break;

        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
            RidleyCheckPlayCutscene();
            break;
        
        case RIDLEY_POSE_SPAWNING:
            RidleySpawning();
            break;

        case RIDLEY_POSE_IDLE_INIT:
            RidleyIdleInit();
        
        case RIDLEY_POSE_IDLE:
            RidleyIdle();
            break;

        case RIDLEY_POSE_TURNING_AROUND_INIT:
            RidleyTurningAroundInit();

        case RIDLEY_POSE_TURNING_AROUND_FIRST_PART:
            RidleyTurningAroundFirstPart();
            break;

        case RIDLEY_POSE_TURNING_AROUND_SECOND_PART:
            RidleyTurningAroundSecondPart();
            break;

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT:
            RidleySmallFireballsAttackInit();

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK:
            RidleySmallFireballsAttack();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
            RidleyTailAttacksInit();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS:
            Ridley_Empty();
            break;

        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
            RidleyBigFireballsAttackInit();
            break;

        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
            RidleyBigFireballsAttack();
            break;

        case RIDLEY_POSE_DYING:
            RidleyDying();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_EXISTS)
    {
        if (gCurrentSprite.paletteRow != 0xE)
        {
            if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0] / 4)
            {
                gCurrentSprite.paletteRow = 0x5;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
            else if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0] / 2)
            {
                gCurrentSprite.paletteRow = 0x3;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.hitboxLeftOffset = -0x60;
            gCurrentSprite.hitboxRightOffset = 0x80;
        }
        else
        {
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = 0x60;
        }

        if (gSamusData.yPosition < (BLOCK_SIZE * 13 - 1) && !(gSpriteData[gSubSpriteData1.workVariable5].status & SPRITE_STATUS_SAMUS_COLLIDING))
            gLockScreen.lock = FALSE;
        else
        {
            gLockScreen.lock = TRUE;
            gLockScreen.yPositionCenter = gSamusData.yPosition - BLOCK_SIZE * 2;
            gLockScreen.xPositionCenter = gSamusData.xPosition;
        }
    }
    else
        gLockScreen.lock = FALSE;

    SpriteUtilUpdateSubSprite1Anim();
    RidleySyncSubSprites();
}

/**
 * @brief 34d24 | 310 | Ridley tail AI
 * 
 */
void RidleyTail(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;

    if (gSpriteData[ramSlot].health == 0x0 && gCurrentSprite.pose < RIDLEY_TAIL_POSE_DEAD)
    {
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_DEAD;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Dying;
        gSubSpriteData2.animationDurationCounter = 0x0;
        gSubSpriteData2.currentAnimationFrame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

    if (gCurrentSprite.roomSlot != RIDLEY_TAIL_PART_TIP)
    {
        if (gCurrentSprite.pose == 0x0)
            RidleyTailInit();
        else if (gCurrentSprite.pose == RIDLEY_TAIL_POSE_DEAD)
        {
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (gSpriteData[ramSlot].status == 0x0)
            {
                RidleyTailDead();
                return;
            }
        }
        
        RidleyTailSyncSubSprites();
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                RidleyTailInit();
                break;

            case RIDLEY_TAIL_POSE_IDLE:
                RidleyTailIdle();
                break;

            case RIDLEY_TAIL_POSE_MOVE_TO_ATTACK:
                RidleyTailCheckMovingToAttackAnimEnded();
                break;

            case RIDLEY_TAIL_POSE_SETTING_UP_ATTACK:
                RidleyTailSettingUpAttack();
                break;

            case RIDLEY_TAIL_POSE_CHARGING_ATTACK:
                RidleyTailChargingAttack();
                break;

            case RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK:
                RidleyTailFirstVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_VERTICAL_ATTACK:
                RidleyTailVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK:
                RidleyTailLastVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_DIAGONAL_ATTACK:
                RidleyTailDiagonalAttack();
                break;

            case RIDLEY_TAIL_POSE_BACK_TO_IDLE:
                RidleyTailCheckBackToIdleAnimEnded();
                break;
            
            default:
                if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                if (gSpriteData[ramSlot].status == 0x0)
                {
                    RidleyTailDead();
                    return;
                }
        }

        SpriteUtilUpdateSubSprite2Anim();
        RidleyTailSyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley part AI
 * 
 */
void RidleyPart(void)
{
    u8 ramSlot;
    u8 part;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    part = gCurrentSprite.roomSlot;

    if (gCurrentSprite.pose == 0x0)
    {
        RidleyPartInit();
        return;
    }

    if (gCurrentSprite.pose == RIDLEY_PART_POSE_DYING)
    {
        if (part != RIDLEY_PART_TAIL)
        {
            if (part == RIDLEY_PART_LEFT_WING)
                RidleyPartWingPlaySound(ramSlot);

            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }

        if (gSpriteData[ramSlot].status == 0x0)
        {
            gCurrentSprite.status = 0x0;
            return;
        }

    }
    else if (gSpriteData[ramSlot].health == 0x0 && gCurrentSprite.pose < RIDLEY_PART_POSE_DYING)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_PART_POSE_DYING;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

    if (part != RIDLEY_PART_TAIL && gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    switch (part)
    {
        case RIDLEY_PART_LEFT_WING:
            RidleyPartWingPlaySound(ramSlot);

        case RIDLEY_PART_RIGHT_WING:
            RidleyPartWingSetPaletteOffset();
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
            break;

        case RIDLEY_PART_CLAW:
            RidleyPartClawIdle(ramSlot);
            RidleyPartClawUpdateSidesHitbox();

        case RIDLEY_PART_HEAD:
            RidleyPartSyncPalette(ramSlot);
            SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM();
            break;

        default:
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley fireball AI
 * 
 */
void RidleyFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            RidleyFireballInit();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN:
            RidleyFireballMoveDescendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN:
            RidleyFireballMoveAscendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN:
            RidleyFireballMoveFloatingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN:
            RidleyFireballMoveDiagonalPattern();
            break;

        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT:
            RidleyFireballSlideOnWallInit();
        
        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL:
            RidleyFireballSlideOnWall();
            break;

        case RIDLEY_FIREBALL_POSE_DESTROY:
            gCurrentSprite.status = 0x0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x1F1);
            return;

        default:
            if (gCurrentSprite.spriteID == SSPRITE_RIDLEY_BIG_FIREBALL)
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
            else
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.oamRotation += 0x20;
    else
        gCurrentSprite.oamRotation -= 0x20;
}
