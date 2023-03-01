#include "data/cutscenes/internal_statue_opening_data.h"
#include "cutscenes/statue_opening.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const struct CutsceneSubroutineData sStatueOpeningSubroutineData[3] = {
    [0] = {
        .pFunction = StatueOpeningInit,
        .oamLength = 2
    },
    [1] = {
        .pFunction = StatueOpeningOpening,
        .oamLength = 2
    },
    [2] = {
        .pFunction = (CutsceneFunc_T)0x8061229, //CutsceneEndFunction,
        .oamLength = 2
    }
};

const u8 sTempArray_760090[0x390] = INCBIN_U8("data/Blob_760090_760420.bin");
