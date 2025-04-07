#include "data/sprites/viola.h"
#include "macros.h"

const u32 sViolaBlueGfx[302] = INCBIN_U32("data/sprites/ViolaBlue.gfx.lz");
const u16 sViolaBluePal[16] = INCBIN_U16("data/sprites/ViolaBlue.pal");
const u32 sViolaOrangeGfx[305] = INCBIN_U32("data/sprites/ViolaOrange.gfx.lz");
const u16 sViolaOrangePal[16] = INCBIN_U16("data/sprites/ViolaOrange.pal");

const u16 sViolaOAM_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_Moving_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_Moving_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_Moving_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_Moving_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_Moving_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetUp_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetUp_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetUp_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetUp_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetUp_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetUp_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetUp_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetUp_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetUp_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetRight_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetRight_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetRight_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetRight_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetRight_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetRight_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetRight_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetRight_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetRight_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetDown_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetDown_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetDown_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetDown_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetDown_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetDown_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetDown_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetDown_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetDown_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const struct FrameData sViolaOAM_Moving[17] = {
    [0] = {
        .pFrame = sViolaOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOAM_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOAM_Moving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOAM_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOAM_MovingOffsetUp[17] = {
    [0] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOAM_MovingOffsetUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOAM_MovingOffsetRight[17] = {
    [0] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOAM_MovingOffsetRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOAM_MovingOffsetDown[17] = {
    [0] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOAM_MovingOffsetDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};
