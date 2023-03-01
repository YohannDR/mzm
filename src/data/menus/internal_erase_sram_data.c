#include "data/menus/internal_erase_sram_data.h"
#include "macros.h"
#include "data/menus/erase_sram_data.h"
#include "constants/game_state.h"

const u32* const sEraseSramTextGfxPointers[7][2] = {
    [LANGUAGE_JAPANESE] = {
        sEraseSramMenuQuestionJapaneseGFX,
        sEraseSramMenuConfirmJapanseGFX
    },
    [LANGUAGE_HIRAGANA] = {
        sEraseSramMenuQuestionJapaneseGFX,
        sEraseSramMenuConfirmJapanseGFX
    },
    [LANGUAGE_ENGLISH] = {
        sEraseSramMenuQuestionEnglishGFX,
        sEraseSramMenuConfirmEnglishGFX
    },
    [LANGUAGE_GERMAN] = {
        sEraseSramMenuQuestionEnglishGFX,
        sEraseSramMenuConfirmEnglishGFX
    },
    [LANGUAGE_FRENCH] = {
        sEraseSramMenuQuestionEnglishGFX,
        sEraseSramMenuConfirmEnglishGFX
    },
    [LANGUAGE_ITALIAN] = {
        sEraseSramMenuQuestionEnglishGFX,
        sEraseSramMenuConfirmEnglishGFX
    },
    [LANGUAGE_SPANISH] = {
        sEraseSramMenuQuestionEnglishGFX,
        sEraseSramMenuConfirmEnglishGFX
    },
};

const u8 sTempArray_760458[0x648] = INCBIN_U8("data/Blob_760458_760aa0.bin");
