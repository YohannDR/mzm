#include "data/menus/internal_erase_sram_data.h"
#include "macros.h"
#include "data/menus/erase_sram_data.h"
#include "constants/game_state.h"

const u32* const sEraseSramTextGfxPointers[7][2] = {
    [LANGUAGE_JAPANESE] = {
        sEraseSramMenuQuestionJapaneseGfx,
        sEraseSramMenuConfirmJapanseGfx
    },
    [LANGUAGE_HIRAGANA] = {
        sEraseSramMenuQuestionJapaneseGfx,
        sEraseSramMenuConfirmJapanseGfx
    },
    [LANGUAGE_ENGLISH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_GERMAN] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_FRENCH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_ITALIAN] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_SPANISH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
};

const u8 sTempArray_760458[0x648] = INCBIN_U8("data/Blob_760458_760aa0.bin");
