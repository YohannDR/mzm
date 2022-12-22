#include "data/sprites/enemy_drop.h"

const u16 sEnemyDropOAM_SmallEnergy_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x4183
};

const u16 sEnemyDropOAM_SmallEnergy_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x41a3
};

const u16 sEnemyDropOAM_SmallEnergy_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x4184
};

const u16 sEnemyDropOAM_SmallEnergy_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x41a4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_LargeEnergy_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c2,
};

const u16 sEnemyDropOAM_LargeEnergy_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_Missile_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sEnemyDropOAM_Missile_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4190
};

const u16 sEnemyDropOAM_SuperMissile_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

const u16 sEnemyDropOAM_SuperMissile_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4191
};

const u16 sEnemyDropOAM_PowerBomb_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x414b
};

const u16 sEnemyDropOAM_PowerBomb_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x416c
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c4,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c6,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c4,
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c0,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c2,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c6,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c6
};

const struct FrameData sEnemyDropOAM_SmallEnergy[5] = {
    sEnemyDropOAM_SmallEnergy_Frame0,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame1,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame2,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_LargeEnergy[5] = {
    sEnemyDropOAM_LargeEnergy_Frame0,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame1,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame2,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_Missile[3] = {
    sEnemyDropOAM_Missile_Frame0,
    0x4,
    sEnemyDropOAM_Missile_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_SuperMissile[3] = {
    sEnemyDropOAM_SuperMissile_Frame0,
    0x4,
    sEnemyDropOAM_SuperMissile_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_PowerBomb[3] = {
    sEnemyDropOAM_PowerBomb_Frame0,
    0x4,
    sEnemyDropOAM_PowerBomb_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot1[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot3[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot2[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3,
    0x8,
    NULL,
    0x0
};
