#include "data/cutscenes/internal_kraid_rising_data.h"

#include "cutscenes/cutscene_utils.h"
#include "cutscenes/kraid_rising.h"

const u16 sKraidRisingPuffData[11][4] = {
    [0] = {
        BLOCK_SIZE,
        BLOCK_SIZE * 7,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        1
    },
    [1] = {
        HALF_BLOCK_SIZE,
        BLOCK_SIZE * 9 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        3
    },
    [2] = {
        BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 9,
        KRAID_RISING_OAM_ID_BIG_PUFF,
        8
    },
    [3] = {
        BLOCK_SIZE * 3 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        5
    },
    [4] = {
        BLOCK_SIZE * 5,
        BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_BIG_PUFF,
        7
    },
    [5] = {
        BLOCK_SIZE * 9,
        BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        7
    },
    [6] = {
        BLOCK_SIZE * 10 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 9,
        KRAID_RISING_OAM_ID_BIG_PUFF,
        10
    },
    [7] = {
        BLOCK_SIZE * 11 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 7,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        6
    },
    [8] = {
        BLOCK_SIZE * 13,
        BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_BIG_PUFF,
        12
    },
    [9] = {
        BLOCK_SIZE * 14 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        4
    },
    [10] = {
        BLOCK_SIZE * 14 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 9 + HALF_BLOCK_SIZE,
        KRAID_RISING_OAM_ID_SMALL_PUFF,
        2
    }
};

const u16 sKraidRisingDebrisSpawnXPosition[6] = {
    BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE * 3 + HALF_BLOCK_SIZE,
    BLOCK_SIZE * 5 + HALF_BLOCK_SIZE, BLOCK_SIZE * 9, BLOCK_SIZE * 11,
    BLOCK_SIZE * 13 + HALF_BLOCK_SIZE
};

const struct CutsceneSubroutineData sKraidRisingSubroutineData[4] = {
    {
        .pFunction = KraidRisingInit,
        .oamLength = 18
    },
    {
        .pFunction = KraidRisingOpeningEyes,
        .oamLength = 18
    },
    {
        .pFunction = KraidRisingRising,
        .oamLength = 18
    },
    {
        .pFunction = CutsceneEndFunction,
        .oamLength = 18
    }
};
