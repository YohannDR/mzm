#include "data/cutscenes/internal_mother_brain_close_up_data.h"
#include "cutscenes/mother_brain_close_up.h"
#include "cutscenes/cutscene_utils.h"

const u16 sMotherBrainCloseUpLookingAtSamusTimers[2] = {
    60 * 3 + 10, 60 * 2
};

const u16 sMotherBrainCloseUpEyeOpeningTimers[4] = {
    40, 40, 60 + 20, 60
};

const struct CutsceneSubroutineData sMotherBrainCloseUpSubroutineData[5] = {
    [0] = {
        .pFunction = (CutsceneFunc_T)0x8063585,//MotherBrainCloseUpInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = (CutsceneFunc_T)0x80634C1,//MotherBrainCloseUpTankView,
        .oamLength = 0
    },
    [2] = {
        .pFunction = (CutsceneFunc_T)0x8063285,//MotherBrainCloseUpEyeOpening,
        .oamLength = 8
    },
    [3] = {
        .pFunction = (CutsceneFunc_T)0x8063009,//MotherBrainCloseUpLookingAtSamus,
        .oamLength = 2
    },
    [4] = {
        .pFunction = (CutsceneFunc_T)0x8061229,//CutsceneEndFunction,
        .oamLength = 2
    }
};

const u16 sMotherBrainCloseUpBubblesSpawnPositions[2][2] = {
    [0] = {
        BLOCK_SIZE * 11 + 8, BLOCK_SIZE * 10 + 56
    },
    [1] = {
        BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 10 + 28
    }
};
