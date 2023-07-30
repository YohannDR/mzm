#include "data/cutscenes/getting_fully_powered_suit_data.h"
#include "cutscenes/getting_fully_powered_suit.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sGettingFullyPoweredSuitPageData[3] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0x8000
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x8000
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

const struct CutscenePaletteData sGettingFullyPoweredSuitPaletteData = {
    .active = TRUE,
    .timer = 0,
    .paletteRow = 0,
    .maxTimer = 2
};

const u8 sGettingFullyPoweredSuitRingPaletteRows[7] = {
    0, 1, 2, 3, 4, 5, 6
};

const u16 sGettingFullyPoweredSuitRingSparklesPositions[OAM_RING_SPARKLES_AMOUNT][2] = {
    [0] = {
        -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 8), 0x18
    },
    [1] = {
        -(BLOCK_SIZE + HALF_BLOCK_SIZE + 8), HALF_BLOCK_SIZE + 8
    },
    [2] = {
        BLOCK_SIZE * 3 + 8, 0x18
    },
    [3] = {
        BLOCK_SIZE + QUARTER_BLOCK_SIZE, HALF_BLOCK_SIZE + 12
    },
    [4] = {
        BLOCK_SIZE * 4 + HALF_BLOCK_SIZE -8, -QUARTER_BLOCK_SIZE
    },
    [5] = {
        -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), -20
    }
};

const u16 sGettingFullyPoweredSuitUpSparklesXPositions[6] = {
    BLOCK_SIZE * 6 + HALF_BLOCK_SIZE, BLOCK_SIZE * 10 + 8, BLOCK_SIZE * 5,
    BLOCK_SIZE * 12 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 3, 0
};

extern const struct FrameData sGettingFullyPoweredSuitOam_SparkleGoingUp[7];
extern const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing1[11];
extern const struct FrameData sGettingFullyPoweredSuitOam_RingBottom[3];
extern const struct FrameData sGettingFullyPoweredSuitOam_RingTop[3];
extern const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing2[9];

const struct OamArray sGettingFullyPoweredSuitCutsceneOam[6] = {
    [0] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleGoingUp,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_GOING_UP] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleGoingUp,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING1] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleAroundRing1,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING2] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleAroundRing2,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_BOTTOM] = {
        .pOam = sGettingFullyPoweredSuitOam_RingBottom,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_TOP] = {
        .pOam = sGettingFullyPoweredSuitOam_RingTop,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame0[7] = {
    0x2,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2080,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2040
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2000,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c0
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame2[7] = {
    0x2,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2100,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2040
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame3[10] = {
    0x3,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2140,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2000,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2080
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame4[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2040,
    0x2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c0
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame5[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2000,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2100,
    OBJ_SHAPE_VERTICAL | 0x3, 0x1f8, OBJ_SPRITE_OAM | 0x2140
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2052
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2002
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2006
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame9[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200a
};

const u16 sGettingFullyPoweredSuitOam_RingBottom_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x20c3,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x20c7,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20cb,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x20cf,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x20d3
};

const u16 sGettingFullyPoweredSuitOam_RingBottom_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1b8, OBJ_SPRITE_OAM | 0x2144,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2148,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x18, OBJ_SPRITE_OAM | 0x2150,
    0x0, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x2154
};

const u16 sGettingFullyPoweredSuitOam_RingTop_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x2082,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x208e,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x28, OBJ_SPRITE_OAM | 0x2092,
    0xf0, OBJ_SIZE_16x16 | 0x48, OBJ_SPRITE_OAM | 0x2096
};

const u16 sGettingFullyPoweredSuitOam_RingTop_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x2103,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2107,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210b,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210f,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x2113
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2012
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2014
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2016
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2018
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x201a
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleGoingUp[7] = {
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame0,
    4,
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame1,
    4,
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame2,
    4,
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame3,
    4,
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame4,
    4,
    sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame5,
    4,
    NULL,
    0
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing1[11] = {
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0,
    2,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1,
    2,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame2,
    2,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
    3,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame9,
    3,
    NULL,
    0
};

const struct FrameData sGettingFullyPoweredSuitOam_RingBottom[3] = {
    sGettingFullyPoweredSuitOam_RingBottom_Frame0,
    4,
    sGettingFullyPoweredSuitOam_RingBottom_Frame1,
    4,
    NULL,
    0
};

const struct FrameData sGettingFullyPoweredSuitOam_RingTop[3] = {
    sGettingFullyPoweredSuitOam_RingTop_Frame0,
    4,
    sGettingFullyPoweredSuitOam_RingTop_Frame1,
    4,
    NULL,
    0
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing2[9] = {
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame2,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3,
    4,
    sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
    4,
    NULL,
    0
};


const u16 sGettingFullyPoweredSuitPal[19 * 16] = INCBIN_U16("data/cutscenes/GettingFullyPoweredSuit/Palette.pal");
const u32 sGettingFullyPoweredSuitSamusGfx[2608] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Samus.gfx.lz");
const u32 sGettingFullyPoweredSuitRingSparklesGfx[646] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/RingSparkles.gfx.lz");
const u32 sGettingFullyPoweredSuitSamusTileTable[387] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Samus.tt");
const u8 sGettingFullyPoweredSuitBackgroundGfx[13872] = INCBIN_U8("data/cutscenes/GettingFullyPoweredSuit/Background.gfx.lz");
const u32 sGettingFullyPoweredSuitBackgroundTileTable[734] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Background.tt");
const u16 sGettingFullyPoweredSuitRingPAL[7 * 16] = INCBIN_U16("data/cutscenes/GettingFullyPoweredSuit/RingPalette.pal");
