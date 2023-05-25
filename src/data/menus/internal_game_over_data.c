#include "data/menus/internal_game_over_data.h"
#include "data/menus/game_over_data.h"
#include "macros.h"

const u32* const sGameOverTextPromptGfxPointers[MAX_AMOUNT_OF_LANGUAGES] = {
    [LANGUAGE_JAPANESE] = sGameOverTextPromptEnglishGFX,
    [LANGUAGE_HIRAGANA] = sGameOverTextPromptHiragnaGFX,
    [LANGUAGE_ENGLISH] = sGameOverTextPromptEnglishGFX,
    [LANGUAGE_GERMAN] = sGameOverTextPromptEnglishGFX,
    [LANGUAGE_FRENCH] = sGameOverTextPromptEnglishGFX,
    [LANGUAGE_ITALIAN] = sGameOverTextPromptEnglishGFX,
    [LANGUAGE_SPANISH] = sGameOverTextPromptEnglishGFX
};

const u8 sGameOverTextPaletteMaxTimers[3] = {
    20, 20, 20
};

const i8 sGameOver_760b0f[9] = {
    0, 1, 2, 3, 2, 1, 0, 0, 0
};

static const u8 sTempArray_760b18[0x96c1c] = INCBIN_U8("data/Blob_760b18_7f7734.bin");
