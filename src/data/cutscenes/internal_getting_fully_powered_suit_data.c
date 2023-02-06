#include "data/cutscenes/internal_getting_fully_powered_suit_data.h"
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
        .pFunction = (CutsceneFunc_T)0x8061228,//CutsceneEndFunction,
        .oamLength = 0
    }
};

const u8 sTempArray_760044[0x976f0] = INCBIN_U8("data/Blob_760044_7f7734.bin");
