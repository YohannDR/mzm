#include "data/cutscenes/internal_ridley_in_space_data.h"
#include "cutscenes/ridley_in_space.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const struct RawCoordsX sRidleyInSpaceShipLeavingPosition = {
    .x = -(BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE),
    .y = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE
};

const struct RawCoordsX sRidleyInSpaceShipsStartPosition[3] = {
    [0] = {
        .x = -(BLOCK_SIZE + HALF_BLOCK_SIZE),
        .y = BLOCK_SIZE * 10 - 8
    },
    [1] = {
        .x = BLOCK_SIZE * 18,
        .y = BLOCK_SIZE * 9 + 4
    },
    [2] = {
        .x = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        .y = -(BLOCK_SIZE + 24)
    }
};

const s8 sRidleyInSpaceShipsYMovementOffsets[8] = {
    4, 4, -4, -4, -4, -4, 4, 4
};

const struct CutsceneSubroutineData sRidleyInSpaceSubroutineData[6] = {
    [0] = {
        .pFunction = (CutsceneFunc_T)0x80642BD,//RidleyInSpaceInit,
        .oamLength = 30
    },
    [1] = {
        .pFunction = (CutsceneFunc_T)0x8063FB5,//RidleyInSpaceViewOfShip,
        .oamLength = 30
    },
    [2] = {
        .pFunction = (CutsceneFunc_T)0x8063D91,//RidleyInSpaceRedAlert,
        .oamLength = 30
    },
    [3] = {
        .pFunction = (CutsceneFunc_T)0x8063BE1,//RidleyInSpaceRidleySuspicious,
        .oamLength = 30
    },
    [4] = {
        .pFunction = (CutsceneFunc_T)0x8063885,//RidleyInSpaceShipLeaving,
        .oamLength = 30
    },
    [5] = {
        .pFunction = (CutsceneFunc_T)0x8061229, //CutsceneEndFunction,
        .oamLength = 30
    }
};
