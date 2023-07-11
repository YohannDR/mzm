#include "data/menus/title_screen_data.h"
#include "constants/menus/title_screen.h"
#include "gba.h"
#include "macros.h"

const u16 sTitleScreenPal[15 * 16] = INCBIN_U16("data/menus/TitleScreen/Palette.pal");
const u16 sTitleScreenPromptPAL[5 * 16] = INCBIN_U16("data/menus/TitleScreen/Prompt.pal");

static const u16 sTitleScreenOAM_Comet_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x6000
};

static const u16 sTitleScreenOAM_Comet_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x6002
};

static const u16 sTitleScreenOAM_Comet_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x6004
};

static const u16 sTitleScreenOAM_CometFlying_Frame0[7] = {
    0x2,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x6008,
    0x0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x6026
};

static const u16 sTitleScreenOAM_SparkleIdle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600a
};

static const u16 sTitleScreenOAM_SparkleIdle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600c
};

static const u16 sTitleScreenOAM_SparkleIdle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600e
};

static const u16 sTitleScreenOAM_SparkleIdle_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x6010
};

static const u16 sTitleScreenOAM_SparkleDisappearing_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600a
};

static const u16 sTitleScreenOAM_SparkleDisappearing_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600c
};

static const u16 sTitleScreenOAM_SparkleDisappearing_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x600e
};

static const u16 sTitleScreenOAM_SparkleDisappearing_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x6012
};

static const u16 sTitleScreenOAM_SparkleDisappearing_Frame4[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x6016
};

static const struct FrameData sTitleScreenOAM_Comet[4] = {
    sTitleScreenOAM_Comet_Frame0,
    4,
    sTitleScreenOAM_Comet_Frame1,
    4,
    sTitleScreenOAM_Comet_Frame2,
    4,
    NULL,
    0
};

static const struct FrameData sTitleScreenOAM_CometFlying[2] = {
    sTitleScreenOAM_CometFlying_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sTitleScreenOAM_SparkleIdle[5] = {
    sTitleScreenOAM_SparkleIdle_Frame0,
    4,
    sTitleScreenOAM_SparkleIdle_Frame1,
    4,
    sTitleScreenOAM_SparkleIdle_Frame2,
    4,
    sTitleScreenOAM_SparkleIdle_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sTitleScreenOAM_SparkleDisappearing[6] = {
    sTitleScreenOAM_SparkleDisappearing_Frame0,
    4,
    sTitleScreenOAM_SparkleDisappearing_Frame1,
    4,
    sTitleScreenOAM_SparkleDisappearing_Frame2,
    4,
    sTitleScreenOAM_SparkleDisappearing_Frame3,
    4,
    sTitleScreenOAM_SparkleDisappearing_Frame4,
    4,
    NULL,
    0
};

const u32 sTitleScreenTitleGfx[1095] = INCBIN_U32("data/menus/TitleScreen/Title.gfx.lz");
const u32 sTitleScreenSparklesGfx[256] = INCBIN_U32("data/menus/TitleScreen/Sparkles.gfx.lz");
const u32 sTitleScreenSpaceBackgroundGfx[3203] = INCBIN_U32("data/menus/TitleScreen/SpaceBackground.gfx.lz");
const u32 sTitleScreenSpaceBackgroundDecorationGfx[797] = INCBIN_U32("data/menus/TitleScreen/SpaceBackgroundDecoration.gfx.lz");
const u32 sTitleScreenSpaceAndGroundBackgroundGfx[1920] = INCBIN_U32("data/menus/TitleScreen/SpaceAndGroundBackground.gfx.lz");
const u32 sTitleScreenTitleTileTable[199] = INCBIN_U32("data/menus/TitleScreen/Title.tt");
const u32 sTitleScreenSpaceBackgroundTileTable[702] = INCBIN_U32("data/menus/TitleScreen/SpaceBackground.tt");

const u8 sTitleScreenRomInfoPosition[4] = {
    BLOCK_SIZE * 2 + 8, BLOCK_SIZE + QUARTER_BLOCK_SIZE, 'P', 'x'
};

const u8 sTitleScreenRomInfoTime[12] = "12/04 22:00";
const u8 sTitleScreenRomInfoRegionUSA[4] = "USA";
const u8 sTitleScreenRomInfoRegionEUR[4] = "EUR";
const u8 sTitleScreenRomInfoRegionJPN[4] = "JPN";

const struct TitleScreenPageData sTitleScreenPageData[2] = {
    [0] = {
        .tiletablePage = 2,
        .graphicsPage = 3,
        .priority = 1,
        .screenSize = 0,
        .bg = DCNT_BG1,
        .tiletablePointer = sTitleScreenTitleTileTable
    },
    [1] = {
        .tiletablePage = 0,
        .graphicsPage = 1,
        .priority = 3,
        .screenSize = 0x8000,
        .bg = DCNT_BG3,
        .tiletablePointer = sTitleScreenSpaceBackgroundTileTable
    }
};

const struct MenuOamData sTitleScreenTopSparkleBaseOam = {
    .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
    .xPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = TITLE_SCREEN_OAM_ID_SPARKLE_IDLE,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = TRUE,
    .boundBackground = 0,
    .unk_E = 0 
};

const struct MenuOamData sTitleScreenBottomSparkleBaseOam = {
    .yPosition = BLOCK_SIZE * 5 - 8,
    .xPosition = BLOCK_SIZE * 14 + 8,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = TITLE_SCREEN_OAM_ID_SPARKLE_IDLE,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = TRUE,
    .boundBackground = 0,
    .unk_E = 0 
};

const struct OamArray sTitleScreenOam[7] = {
    [0] = {
        .pOam = sTitleScreenOAM_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [TITLE_SCREEN_OAM_ID_COMET_SPAWNING] = {
        .pOam = sTitleScreenOAM_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_COMET_APPEARING] = {
        .pOam = sTitleScreenOAM_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TITLE_SCREEN_OAM_ID_COMET_FLYING] = {
        .pOam = sTitleScreenOAM_CometFlying,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_IDLE] = {
        .pOam = sTitleScreenOAM_SparkleIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_GROWING] = {
        .pOam = sTitleScreenOAM_SparkleIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_DISAPPEARING] = {
        .pOam = sTitleScreenOAM_SparkleDisappearing,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
};
