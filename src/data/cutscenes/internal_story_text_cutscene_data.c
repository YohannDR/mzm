#include "data/cutscenes/internal_story_text_cutscene_data.h"
#include "data/text_pointers.h"
#include "cutscenes/story_text_cutscene.h"

#include "constants/game_state.h"

const u16* const * const sStoryTextPointers[7] = {
    [LANGUAGE_JAPANESE] = sJapaneseTextPointers_Story,
    [LANGUAGE_HIRAGANA] = sHiraganaTextPointers_Story,
    [LANGUAGE_ENGLISH] = sEnglishTextPointers_Story,
    [LANGUAGE_GERMAN] = sEnglishTextPointers_Story,
    [LANGUAGE_FRENCH] = sEnglishTextPointers_Story,
    [LANGUAGE_ITALIAN] = sEnglishTextPointers_Story,
    [LANGUAGE_SPANISH] = sEnglishTextPointers_Story
};

const struct CutsceneSubroutineData sStoryTextCutsceneSubroutineData[7] = {
    [0] = {
        .pFunction = StoryTextCutsceneInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = StoryTextCutsceneProcessText,
        .oamLength = 0
    },
    [2] = {
        .pFunction = StoryTextCutsceneSetVerticalOffset,
        .oamLength = 0
    },
    [3] = {
        .pFunction = StoryTextCutsceneFadeIn,
        .oamLength = 0
    },
    [4] = {
        .pFunction = StoryTextCutsceneCheckInput,
        .oamLength = 0
    },
    [5] = {
        .pFunction = StoryTextCutsceneFadeOut,
        .oamLength = 0
    },
    [6] = {
        .pFunction = StoryTextCutsceneEnd,
        .oamLength = 0
    },
};
