#include "data/cutscenes/internal_ridley_spawn_data.h"
#include "cutscenes/ridley_spawn.h"
#include "cutscenes/cutscene_utils.h"

const struct RawCoordsX sRidleySpawnRidleyPositions[3] = {
    [0] = {
        .x = BLOCK_SIZE * 9,
        .y = BLOCK_SIZE * 5 + 0x34
    },
    [1] = {
        .x = BLOCK_SIZE * 7,
        .y = BLOCK_SIZE * 3
    },
    [2] = {
        .x = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        .y = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE
    }
};

const struct CutsceneSubroutineData sRidleySpawnSubroutineData[5] = {
    [0] = {
        .pFunction = RidleySpawnInit,
        .oamLength = 1,
    },
    [1] = {
        .pFunction = RidleySpawnSamusLookingUp,
        .oamLength = 1
    },
    [2] = {
        .pFunction = RidleySpawnHelmetReflection,
        .oamLength = 1
    },
    [3] = {
        .pFunction = RidleySpawnRidleyFlyingIn,
        .oamLength = 1
    },
    [4] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 1
    }
};
