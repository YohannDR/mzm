#include "data/menus/internal_game_over_data.h"
#include "data/menus/game_over_data.h"
#include "macros.h"

const u32* const sGameOverTextPromptGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_HIRAGANA] = sGameOverTextPromptHiragnaGfx,
    [LANGUAGE_ENGLISH] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_GERMAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_FRENCH] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_ITALIAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_SPANISH] = sGameOverTextPromptEnglishGfx
};

const u8 sGameOverTextPaletteMaxTimers[3] = {
    ONE_THIRD_SECOND, ONE_THIRD_SECOND, ONE_THIRD_SECOND
};

const s8 sGameOverTextGradientPaletteOffset[9] = {
    0, 1, 2, 3, 2, 1, 0, 0, 0
};
