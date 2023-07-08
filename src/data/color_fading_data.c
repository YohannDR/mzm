#include "data/color_fading_data.h"
#include "constants/color_fading.h"
#include "color_fading.h"
#include "macros.h"

const struct ColorFadingData sColorFadingData[25] = {
    [0] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 0
    },
    [COLOR_FADING_FLASH] = {
        .isWhite = TRUE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 0,
        .unk_C = ColorFading_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_CANCEL] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 0,
        .unk_C = ColorFading_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_WHITE] = {
        .isWhite = TRUE,
        .unk_4 = ColorFading_UpdateDoorTransition,
        .firstColorSet = 1,
        .unk_C = ColorFading_DoorTransition,
        .secondColorSet = 1,
        .bgColorMask = 0xFFFD,
        .objColorMask = 0xFFC7,
        .unk_16 = 1
    },
    [COLOR_FADING_DOOR_TRANSITION] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDoorTransition,
        .firstColorSet = 1,
        .unk_C = ColorFading_DoorTransition,
        .secondColorSet = 1,
        .bgColorMask = 0xFFFD,
        .objColorMask = 0xFFC7,
        .unk_16 = 1
    },
    [COLOR_FADING_FLASH2] = {
        .isWhite = TRUE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 0,
        .unk_C = ColorFading_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFC7,
        .unk_16 = 1
    },
    [COLOR_FADING_NO_TRANSITION] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 0,
        .unk_C = ColorFading_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFC7,
        .unk_16 = 1
    },
    [COLOR_FADING_FLASH_NO_TRANSITION] = {
        .isWhite = TRUE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 4,
        .unk_C = ColorFading_Default,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_NO_TRANSITION_HUD_HIDE] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 4,
        .unk_C = ColorFading_Default,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_SLOW_WHITE] = {
        .isWhite = TRUE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 3,
        .unk_C = ColorFading_Default,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_SLOW_BLACK] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 3,
        .unk_C = ColorFading_Default,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_AFTER_ENTER_MOTHER_SHIP] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_UpdateDefault,
        .firstColorSet = 0,
        .unk_C = ColorFading_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 1
    },
    [COLOR_FADING_ESCAPE_FAILED] = {
        .isWhite = TRUE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_EscapeFailed,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_DEMO_ENDING_AUTO] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_BeforeDemoEnding,
        .secondColorSet = 2,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_DEMO_ENDING_WITH_INPUT] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_BeforeDemoEnding,
        .secondColorSet = 2,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_CHOZODIA_ESCAPE] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_ChozodiaEscape,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_TOURIAN_ESCAPE] = {
        .isWhite = TRUE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_TourianEscape,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_GETTING_FULLY_POWERED] = {
        .isWhite = TRUE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_GettingFullyPowered,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_RIDLEY_SPAWN] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_BeforeRidleySpawn,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_STATUE_CUTSCENE] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_StatueOpening,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_INTRO_TEXT] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_BeforeIntroText,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_LANDING_SHIP] = {
        .isWhite = FALSE,
        .unk_4 = ColorFading_BeforeLandingShip,
        .firstColorSet = 0,
        .unk_C = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_SAMUS_IN_BLUE_SHIP] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = ColorFading_BeforeBlueShip,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .unk_16 = 2
    },
    [COLOR_FADING_TO_WHITE] = {
        .isWhite = TRUE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFFC,
        .unk_16 = 3
    },
    [COLOR_FADING_TO_BLACK] = {
        .isWhite = FALSE,
        .unk_4 = NULL,
        .firstColorSet = 0,
        .unk_C = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFFC,
        .unk_16 = 3
    },
};

static const u8 sColorFading_345f58[8] = {
    3, 7, 11, 15, 19, 23, 27, 32
};

static const u8 sColorFading_345f60[16] = {
    2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};

static const u8 sColorFading_345f70[32] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
};

static const u8 sColorFading_345f90[60] = {
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6,
    6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 11, 11, 12,
    12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 21,
    22, 23, 24, 26, 28, 30, 32
};

static const u8 sColorFading_345fcc[1] = {
    32
};

const struct ColorFadingColorInfo sColorFadingColorInfo[5] = {
    [0] = {
        .colorArray = sColorFading_345f58,
        .size = ARRAY_SIZE(sColorFading_345f58)
    },
    [1] = {
        .colorArray = sColorFading_345f60,
        .size = ARRAY_SIZE(sColorFading_345f60)
    },
    [2] = {
        .colorArray = sColorFading_345f70,
        .size = ARRAY_SIZE(sColorFading_345f70)
    },
    [3] = {
        .colorArray = sColorFading_345f90,
        .size = ARRAY_SIZE(sColorFading_345f90)
    },
    [4] = {
        .colorArray = sColorFading_345fcc,
        .size = ARRAY_SIZE(sColorFading_345fcc)
    }
};
