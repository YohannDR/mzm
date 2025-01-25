#include "data/sprites/escape_gate.h"

#include "macros.h"

const u8 sEscapeGateAndTimerGfx[2048] = INCBIN_U8("data/sprites/EscapeGateAndTimer.gfx");
const u16 sEscapeGateAndTimerPal[16] = INCBIN_U16("data/sprites/EscapeGateAndTimer.pal");
const u16 sEscapeGateFlashingPal[96] = INCBIN_U16("data/sprites/EscapeGateFlashing.pal");

const u16 sEscapeGateOAM_Closed_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73db
};

const u16 sEscapeGateOAM_Opening_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73fb
};

const u16 sEscapeGateOAM_Opening_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xce, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xca, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb
};

const u16 sEscapeGateOAM_Opening_Frame9[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame10[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame11[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame12[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame13[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame14[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame15[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame16[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73ef,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const struct FrameData sEscapeGateOAM_Closed[2] = {
    [0] = {
        .pFrame = sEscapeGateOAM_Closed_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEscapeGateOAM_Opening[18] = {
    [0] = {
        .pFrame = sEscapeGateOAM_Closed_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [1] = {
        .pFrame = sEscapeGateOAM_Opening_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sEscapeGateOAM_Opening_Frame2,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [3] = {
        .pFrame = sEscapeGateOAM_Opening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEscapeGateOAM_Opening_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sEscapeGateOAM_Opening_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sEscapeGateOAM_Opening_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sEscapeGateOAM_Opening_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sEscapeGateOAM_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sEscapeGateOAM_Opening_Frame9,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sEscapeGateOAM_Opening_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sEscapeGateOAM_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sEscapeGateOAM_Opening_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sEscapeGateOAM_Opening_Frame13,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sEscapeGateOAM_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sEscapeGateOAM_Opening_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sEscapeGateOAM_Opening_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEscapeGateOAM_Opened[2] = {
    [0] = {
        .pFrame = sEscapeGateOAM_Opening_Frame16,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
