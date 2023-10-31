#include "data/menus/internal_status_screen_data.h"

#include "constants/menus/status_screen.h"

const u8 sStatusScreenRowsData[6][3] = {
    [0] = {
        [0] = ABILITY_GROUP_CURRENT_ENERGY,
        [1] = 1,
        [2] = 9
    },
    [1] = {
        [0] = ABILITY_GROUP_BOMBS,
        [1] = 4,
        [2] = 12
    },
    [2] = {
        [0] = ABILITY_GROUP_BEAMS,
        [1] = 7,
        [2] = 8
    },
    [3] = {
        [0] = ABILITY_GROUP_SUITS,
        [1] = 4,
        [2] = 10
    },
    [4] = {
        [0] = ABILITY_GROUP_MISC,
        [1] = 8,
        [2] = 10
    },
    [5] = {
        [0] = ABILITY_GROUP_MISSILES,
        [1] = 6,
        [2] = 9
    },
};

const u8 sPauseScreen_7603ea[6] = {
    [0] = 0,
    [1] = 1,
    [2] = 3,
    [3] = 0,
    [4] = 0,
    [5] = 0
};
