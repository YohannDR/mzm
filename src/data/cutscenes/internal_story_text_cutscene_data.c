#include "data/cutscenes/internal_story_text_cutscene_data.h"
#include "cutscenes/story_text_cutscene.h"

#include "constants/game_state.h"

const u16** const sStoryTextPointers[7] = {
    [LANGUAGE_JAPANESE] = (const u16**)0x8760804,
    [LANGUAGE_HIRAGANA] = (const u16**)0x87608fc,
    [LANGUAGE_ENGLISH] = (const u16**)0x87609f4,
    [LANGUAGE_GERMAN] = (const u16**)0x87609f4,
    [LANGUAGE_FRENCH] = (const u16**)0x87609f4,
    [LANGUAGE_ITALIAN] = (const u16**)0x87609f4,
    [LANGUAGE_SPANISH] = (const u16**)0x87609f4
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
