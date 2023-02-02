#include "data/cutscenes/kraid_rising.h"

#include "cutscenes/cutscene_utils.h"
#include "cutscenes/kraid_rising.h"

// 75fe5c

const struct KraidRisingPuffData sKraidRisingPuffData[11] = {
    {
        .xPosition = BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 1
    },
    {
        .xPosition = HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 9 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 3
    },
    {
        .xPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 9,
        .oamID = KRAID_RISING_OAM_ID_BIG_PUFF,
        .timer = 8
    },
    {
        .xPosition = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 5
    },
    {
        .xPosition = BLOCK_SIZE * 5,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_BIG_PUFF,
        .timer = 7
    },
    {
        .xPosition = BLOCK_SIZE * 9,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 7
    },
    {
        .xPosition = BLOCK_SIZE * 10 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 9,
        .oamID = KRAID_RISING_OAM_ID_BIG_PUFF,
        .timer = 10
    },
    {
        .xPosition = BLOCK_SIZE * 11 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 6
    },
    {
        .xPosition = BLOCK_SIZE * 13,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_BIG_PUFF,
        .timer = 12
    },
    {
        .xPosition = BLOCK_SIZE * 14 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 4
    },
    {
        .xPosition = BLOCK_SIZE * 14 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 9 + HALF_BLOCK_SIZE,
        .oamID = KRAID_RISING_OAM_ID_SMALL_PUFF,
        .timer = 2
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
        .oamLength = 12
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

// 75fee0
