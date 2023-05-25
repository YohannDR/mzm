#include "data/menus/internal_title_screen_data.h"
#include "data/menus/title_screen_data.h"
#include "macros.h"
#include "constants/menus/title_screen.h"

const struct TitleScreenAnimatedPalette sTitleScreenAnimatedPaletteTemplates[4] = {
    [0] = {
        .paletteRow = 0,
        .maxTimer = 17,
        .timer = 17,
        .unk_4 = 0
    },
    [1] = {
        .paletteRow = 0,
        .maxTimer = 3,
        .timer = 3,
        .unk_4 = 2
    },
    [2] = {
        .paletteRow = 0,
        .maxTimer = 9,
        .timer = 9,
        .unk_4 = 0
    },
    [3] = {
        .paletteRow = 0,
        .maxTimer = 4,
        .timer = 4,
        .unk_4 = 1
    },
};

static const u8* const sRomInfoStringPointers[4] = {
    sTitleScreenRomInfoTime,
    sTitleScreenRomInfoRegionJPN,
    sTitleScreenRomInfoRegionEUR,
    sTitleScreenRomInfoRegionUSA,
};

const u8 sTitleScreenCometsFlags[2][2] = {
    [0] = {
        TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE, TITLE_SCREEN_TYPE_FIRST_COMET_ENDED
    },
    [1] = {
        TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE, TITLE_SCREEN_TYPE_SECOND_COMET_ENDED
    }
};

const u8 sTitleScreenSkyDecorationsPaletteRows[6] = {
    8, 9, 10, 11, 10, 9
};

const u8 sTitleScreenTitlePaletteRows[14] = {
    0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1
};

const u8 sTitleScreenPromptPaletteRows[7] = {
    0, 1, 2, 3, 2, 1, 0
};
