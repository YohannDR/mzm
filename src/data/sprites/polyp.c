#include "data/sprites/polyp.h"
#include "macros.h"

const s16 sPolypProjectileYVelocity[44] = {
    -16, -16, -14, -14, -12, -12, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

const u32 sPolypGfx[241] = INCBIN_U32("data/sprites/Polyp.gfx.lz");
const u16 sPolypPal[16] = INCBIN_U16("data/sprites/Polyp.pal");

const u16 sPolypOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sPolypOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sPolypOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOam_Warning_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
}; 

const u16 sPolypOam_Warning_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOam_Warning_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOam_Warning_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOam_AfterSpitting_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypProjectileOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sPolypProjectileOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sPolypProjectileOam_Right_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sPolypProjectileOam_Right_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sPolypProjectileOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sPolypProjectileOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sPolypProjectileOam_Left_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sPolypProjectileOam_Left_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sPolypProjectileOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218
};

const u16 sPolypProjectileOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sPolypProjectileOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sPolypProjectileOam_Exploding_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const struct FrameData sPolypOam_Idle[5] = {
    [0] = {
        .pFrame = sPolypOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sPolypOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sPolypOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sPolypOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Warning[5] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPolypOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPolypOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Spitting[2] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame2,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_AfterSpitting[4] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPolypOam_AfterSpitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Retracting[3] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Right[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Right_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Right_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Right_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Right_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Left[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Left_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Left_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Left_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Left_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Exploding[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
