#include "data/menus/internal_game_over_data.h"
#include "data/menus/game_over_data.h"
#include "macros.h"

const u32* const sGameOverTextPromptGfxPointers[MAX_AMOUNT_OF_LANGUAGES] = {
    [LANGUAGE_JAPANESE] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_HIRAGANA] = sGameOverTextPromptHiragnaGfx,
    [LANGUAGE_ENGLISH] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_GERMAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_FRENCH] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_ITALIAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_SPANISH] = sGameOverTextPromptEnglishGfx
};

const u8 sGameOverTextPaletteMaxTimers[3] = {
    20, 20, 20
};

const s8 sGameOver_760b0f[9] = {
    0, 1, 2, 3, 2, 1, 0, 0, 0
};

static const u8 sTempArray_760b18[0x1fc] = INCBIN_U8("data/Blob_760b18_760d14.bin");
