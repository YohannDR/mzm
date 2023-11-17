#include "data/cutscenes/internal_getting_fully_powered_suit_data.h"
#include "cutscenes/cutscene_utils.h"
#include "cutscenes/getting_fully_powered_suit.h"
#include "macros.h"

const struct CutsceneSubroutineData sGettingFullyPoweredSuitSubroutineData[3] = {
    [0] = {
        .pFunction = GettingFullyPoweredSuitInit,
        .oamLength = 14
    },
    [1] = {
        .pFunction = GettingFullyPoweredSuitAnimation,
        .oamLength = 14
    },
    [2] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 0
    }
};
