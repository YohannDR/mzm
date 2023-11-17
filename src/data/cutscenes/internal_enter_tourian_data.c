#include "data/cutscenes/internal_enter_tourian_data.h"
#include "cutscenes/cutscene_utils.h"
#include "cutscenes/enter_tourian.h"

const u16 sEnterTourian_760090[9][2] = {
    [0] = {
        BLOCK_SIZE * 38 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 39 - QUARTER_BLOCK_SIZE
    },
    [1] = {
        BLOCK_SIZE * 37 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 38 + QUARTER_BLOCK_SIZE + 8
    },
    [2] = {
        BLOCK_SIZE * 39 - QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 38 + HALF_BLOCK_SIZE
    },
    [3] = {
        BLOCK_SIZE * 38,
        BLOCK_SIZE * 38
    },
    [4] = {
        BLOCK_SIZE * 38 + 8,
        BLOCK_SIZE * 39 + 8
    },
    [5] = {
        0,
        0
    },
    [6] = {
        0,
        0
    },
    [7] = {
        0,
        0
    },
    [8] = {
        0,
        0
    }
};

const s16 sEnterTourian_7600b4[4][2] = {
    [0] = {
        BLOCK_SIZE * 38 + 12,
        BLOCK_SIZE * 34 + HALF_BLOCK_SIZE
    },
    [1] = {
        BLOCK_SIZE * 37 - QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 37
    },
    [2] = {
        BLOCK_SIZE * 42 - QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 37 + QUARTER_BLOCK_SIZE
    },
    [3] = {
        BLOCK_SIZE * 40,
        BLOCK_SIZE * 36 + HALF_BLOCK_SIZE + 8
    }
};

const struct CutsceneSubroutineData sEnterTourianSubroutineData[3] = {
    [0] = {
        .pFunction = EnterTourianInit,
        .oamLength = 9
    },
    [1] = {
        .pFunction = EnterTourianAnimation,
        .oamLength = 9
    },
    [2] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 9
    }
};
