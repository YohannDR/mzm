#include "data/sprites/enemy_drop.h"
#include "macros.h"

const u16 sEnemyDropOAM_SmallEnergy_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x4183
};

const u16 sEnemyDropOAM_SmallEnergy_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x41a3
};

const u16 sEnemyDropOAM_SmallEnergy_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x4184
};

const u16 sEnemyDropOAM_SmallEnergy_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x41a4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_LargeEnergy_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c2,
};

const u16 sEnemyDropOAM_LargeEnergy_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_Missile_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sEnemyDropOAM_Missile_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4190
};

const u16 sEnemyDropOAM_SuperMissile_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

const u16 sEnemyDropOAM_SuperMissile_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4191
};

const u16 sEnemyDropOAM_PowerBomb_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x414b
};

const u16 sEnemyDropOAM_PowerBomb_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x416c
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c4,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c6,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c4,
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c0,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c2,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c6,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c6
};

const struct FrameData sEnemyDropOAM_SmallEnergy[5] = {
    [0] = {
        .pFrame = sEnemyDropOAM_SmallEnergy_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_SmallEnergy_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOAM_SmallEnergy_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOAM_SmallEnergy_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_LargeEnergy[5] = {
    [0] = {
        .pFrame = sEnemyDropOAM_LargeEnergy_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_LargeEnergy_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOAM_LargeEnergy_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOAM_LargeEnergy_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_Missile[3] = {
    [0] = {
        .pFrame = sEnemyDropOAM_Missile_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_Missile_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_SuperMissile[3] = {
    [0] = {
        .pFrame = sEnemyDropOAM_SuperMissile_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_SuperMissile_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_PowerBomb[3] = {
    [0] = {
        .pFrame = sEnemyDropOAM_PowerBomb_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_PowerBomb_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot1[5] = {
    [0] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot3[5] = {
    [0] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot2[5] = {
    [0] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
