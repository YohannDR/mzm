#include "data/sprites/rinka.h"
#include "macros.h"

const u32 sRinkaOrangeGfx[242] = INCBIN_U32("data/sprites/RinkaOrange.gfx.lz");
const u16 sRinkaOrangePal[16] = INCBIN_U16("data/sprites/RinkaOrange.pal");
const u32 sRinkaGreenGfx[242] = INCBIN_U32("data/sprites/RinkaGreen.gfx.lz");
const u16 sRinkaGreenPal[16] = INCBIN_U16("data/sprites/RinkaGreen.pal");

const u16 sRinkaOrangeOAM_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaOrangeOAM_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaOrangeOAM_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaOrangeOAM_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaOrangeOAM_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaOrangeOAM_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaOrangeOAM_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaOrangeOAM_Spawning_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaOrangeOAM_Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaOrangeOAM_Spawning[16] = {
    [0] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sRinkaOrangeOAM_Spawning_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [11] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [12] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [13] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [14] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRinkaOrangeOAM_Moving[5] = {
    [0] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sRinkaOrangeOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};


const u16 sRinkaGreenOAM_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaGreenOAM_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaGreenOAM_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaGreenOAM_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaGreenOAM_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaGreenOAM_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaGreenOAM_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaGreenOAM_Spawning_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaGreenOAM_Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaGreenOAM_Spawning[16] = {
    [0] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sRinkaGreenOAM_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [11] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRinkaGreenOAM_Moving[5] = {
    [0] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sRinkaGreenOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
