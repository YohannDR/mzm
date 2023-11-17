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
        .pFunction = MotherBrainCloseUpInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = MotherBrainCloseUpTankView,
        .oamLength = 0
    },
    [2] = {
        .pFunction = MotherBrainCloseUpEyeOpening,
        .oamLength = 8
    },
    [3] = {
        .pFunction = MotherBrainCloseUpLookingAtSamus,
        .oamLength = 2
    },
    [4] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 2
    }
};

const u16 sMotherBrainCloseUpBubblesSpawnPositions[2][2] = {
    [0] = {
        BLOCK_SIZE * 11 + PIXEL_SIZE * 2, BLOCK_SIZE * 10 + QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 2
    },
    [1] = {
        BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 10 + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3
    }
};
