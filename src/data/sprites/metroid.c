#include "data/sprites/metroid.h"
#include "macros.h"

const s16 sMetroidSpawningYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2, 2, 1,
    1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -2, -2, -1,
    -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidSpawningXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1,
    -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX 
};

const u32 sMetroidGfx[793] = INCBIN_U32("data/sprites/Metroid.gfx.lz");
const u16 sMetroidPal[80] = INCBIN_U16("data/sprites/Metroid.pal");
const u16 sMetroidPal_SamusGrabbed[80] = INCBIN_U16("data/sprites/MetroidSamusGrabbed.pal");

const u16 sMetroidShellOAM_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xef, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x208
};

const u16 sMetroidShellOAM_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xef, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x288
};

const u16 sMetroidOAM_Moving_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x240,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x304,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x304
};

const u16 sMetroidOAM_Moving_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Moving_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame9[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Moving_Frame10[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x32a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xdf, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x210
};

const u16 sMetroidOAM_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xdf, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x218
};

const u16 sMetroidOAM_SamusGrabbed_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4240,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4304
};

const u16 sMetroidOAM_SamusGrabbed_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const u16 sMetroidOAM_SamusGrabbed_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x420a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x424a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame8[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x428a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42ca,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const u16 sMetroidOAM_SamusGrabbed_Frame9[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42ea,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x432a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const struct FrameData sMetroidShellOAM_Idle[3] = {
    [0] = {
        .pFrame = sMetroidShellOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMetroidShellOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOAM_Moving[17] = {
    [0] = {
        .pFrame = sMetroidOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMetroidOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMetroidOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMetroidOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMetroidOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMetroidOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sMetroidOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sMetroidOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = {
        .pFrame = sMetroidOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [9] = {
        .pFrame = sMetroidOAM_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sMetroidOAM_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sMetroidOAM_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sMetroidOAM_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sMetroidOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sMetroidOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [15] = {
        .pFrame = sMetroidOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOAM_SamusGrabbed[15] = {
    [0] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [13] = {
        .pFrame = sMetroidOAM_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOAM_Spanwing[3] = {
    [0] = {
        .pFrame = sMetroidOAM_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMetroidOAM_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};
