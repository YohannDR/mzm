#include "data/cutscenes/internal_before_charlie_data.h"
#include "cutscenes/cutscene_utils.h"
#include "cutscenes/before_charlie.h"

const struct CutsceneGraphicsData sBeforeCharlieCutsceneGraphicsData = {
    .active = FALSE,
    .paletteStage = 0,
    .maxTimer = 4,
    .maxPaletteStage = 0,
    .timer = 0,
};

const struct CutsceneSubroutineData sBeforeCharlieSubroutineData[5] = {
    [0] = {
        .pFunction = BeforeCharlieInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = BeforeCharlieChozoWallSides,
        .oamLength = 0
    },
    [2] = {
        .pFunction = BeforeCharlieWallAndGreyVoice,
        .oamLength = 0
    },
    [3] = {
        .pFunction = BeforeCharlieSamusCloseUp,
        .oamLength = 0
    },
    [4] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 0
    },
};