#include "data/menus/internal_erase_sram_data.h"
#include "macros.h"
#include "data/menus/erase_sram_data.h"

const u32* const sEraseSramTextGfxPointers[LANGUAGE_END][2] = {
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
    #ifdef REGION_US_BETA
    [LANGUAGE_GERMAN] = {
        sEraseSramMenuQuestionGermanGfx,
        sEraseSramMenuConfirmGermanGfx
    },
    [LANGUAGE_FRENCH] = {
        sEraseSramMenuQuestionFrenchGfx,
        sEraseSramMenuConfirmFrenchGfx
    },
    [LANGUAGE_ITALIAN] = {
        sEraseSramMenuQuestionItalianGfx,
        sEraseSramMenuConfirmItalianGfx
    },
    [LANGUAGE_SPANISH] = {
        sEraseSramMenuQuestionSpanishGfx,
        sEraseSramMenuConfirmSpanishGfx
    }
    #else // !REGION_US_BETA
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
    }
    #endif // REGION_US_BETA
};
