#include "data/menus/status_screen_data.h"
#include "constants/menus/status_screen.h"
#include "constants/menus/pause_screen.h"
#include "macros.h"

const u16 sStatusScreen_40dd10[6 * 16] = INCBIN_U16("data/menus/PauseScreen/40dd10.pal");
const u16 sStatusScreen_40ddd0[4 * 16] = INCBIN_U16("data/menus/PauseScreen/40ddd0.pal");

const u8 sStatusScreenGroupsData[13][5] = {
    [ABILITY_GROUP_BEAMS] = {
        4, 10, 0, 7, 0
    },
    [ABILITY_GROUP_BOMBS] = {
        2, 5, 18, 29, 1
    },
    [ABILITY_GROUP_SUITS] = {
        5, 8, 20, 29, 2
    },
    [ABILITY_GROUP_MISC] = {
        9, 16, 20, 29, 3
    },
    [ABILITY_GROUP_MISSILES] = {
        11, 16, 0, 8, 4
    },
    [ABILITY_GROUP_CURRENT_ENERGY] = {
        2, 2, 8, 11, 5
    },
    [ABILITY_GROUP_MAX_ENERGY] = {
        2, 2, 13, 16, 6
    },
    [ABILITY_GROUP_CURRENT_MISSILES] = {
        13, 13, 1, 3, 7
    },
    [ABILITY_GROUP_MAX_MISSILES] = {
        13, 13, 5, 7, 8
    },
    [ABILITY_GROUP_CURRENT_SUPER_MISSILES] = {
        15, 15, 1, 3, 9
    },
    [ABILITY_GROUP_MAX_SUPER_MISSILES] = {
        15, 15, 5, 7, 10
    },
    [ABILITY_GROUP_CURRENT_POWER_BOMBS] = {
        4, 4, 24, 25, 11
    },
    [ABILITY_GROUP_MAX_POWER_BOMBS] = {
        4, 4, 27, 28, 12
    }
};

const u8 sStatusScreenUnknownItemsData[10][5] = {
    [ABILITY_GROUP_BEAMS] = {
        20, 25, 0, 7, 0
    },
    [ABILITY_GROUP_BOMBS] = {
        20, 24, 8, 19, 1
    },
    [ABILITY_GROUP_SUITS] = {
        25, 27, 10, 19, 2
    },
    [ABILITY_GROUP_MISC] = {
        24, 31, 20, 29, 3
    },
    [ABILITY_GROUP_MISSILES] = {
        26, 31, 0, 8, 4
    },
    [ABILITY_GROUP_CURRENT_ENERGY] = {
        0, 0, 0, 0, 0
    },
    [ABILITY_GROUP_MAX_ENERGY] = {
        0, 0, 0, 0, 0
    },
    [ABILITY_GROUP_CURRENT_MISSILES] = {
        0, 0, 0, 0, 0
    },
    [ABILITY_GROUP_MAX_MISSILES] = {
        0, 0, 0, 0, 0
    },
    [ABILITY_GROUP_CURRENT_SUPER_MISSILES] = {
        0, 0, 0, 0, 0
    }
};

const struct StatusScreenItemData sStatusScreenItemsData[18] = {
    [0] = {
        .group = ABILITY_GROUP_CURRENT_ENERGY,
        .abilityOffset = 0,
        .row = 0,
        .unk_3 = 0
    },
    [1] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .row = 1,
        .unk_3 = 1
    },
    [2] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 1,
        .row = 2,
        .unk_3 = 1
    },
    [3] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 2,
        .row = 3,
        .unk_3 = 1
    },
    [4] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 3,
        .row = 4,
        .unk_3 = 1
    },
    [5] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 4,
        .row = 5,
        .unk_3 = 1
    },
    [6] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = 0,
        .row = 1,
        .unk_3 = 0
    },
    [7] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = 1,
        .row = 3,
        .unk_3 = 0
    },
    [8] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = 0,
        .row = 1,
        .unk_3 = 0
    },
    [9] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = 1,
        .row = 2,
        .unk_3 = 0
    },
    [10] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = 0,
        .row = 1,
        .unk_3 = 2
    },
    [11] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = 1,
        .row = 2,
        .unk_3 = 2
    },
    [12] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 0,
        .row = 1,
        .unk_3 = 2
    },
    [13] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 1,
        .row = 2,
        .unk_3 = 2
    },
    [14] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 2,
        .row = 3,
        .unk_3 = 2
    },
    [15] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 3,
        .row = 4,
        .unk_3 = 2
    },
    [16] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 4,
        .row = 5,
        .unk_3 = 2
    },
    [17] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 5,
        .row = 6,
        .unk_3 = 2
    }
};

const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[22] = {
    [0] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 0
    },
    [1] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 0
    },
    [2] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 0
    },
    [ITEM_ACQUISITION_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 6
    },
    [4] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 0
    },
    [ITEM_ACQUISITION_SUPER_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 2,
        .unk_3 = 7
    },
    [6] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 0
    },
    [ITEM_ACQUISITION_POWER_BOMB] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 1,
        .unk_3 = 9
    },
    [ITEM_ACQUISITION_LONG_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .unk_3 = 1
    },
    [ITEM_ACQUISITION_CHARGE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 1,
        .unk_3 = 1
    },
    [ITEM_ACQUISITION_ICE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 2,
        .unk_3 = 1
    },
    [ITEM_ACQUISITION_WAVE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 3,
        .unk_3 = 1
    },
    [ITEM_ACQUISITION_PLASMA_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 4,
        .unk_3 = 1
    },
    [ITEM_ACQUISITION_BOMBS] = {
        .unk_0 = 2,
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = 0,
        .unk_3 = 8
    },
    [ITEM_ACQUISITION_VARIA] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = 0,
        .unk_3 = 10
    },
    [ITEM_ACQUISITION_GRAVITY] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = 1,
        .unk_3 = 10
    },
    [ITEM_ACQUISITION_MORPH_BALL] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 0,
        .unk_3 = 12
    },
    [ITEM_ACQUISITION_SPEEDBOOSTER] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 2,
        .unk_3 = 12
    },
    [ITEM_ACQUISITION_HIGH_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 3,
        .unk_3 = 12
    },
    [ITEM_ACQUISITION_SCREW_ATTACK] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 4,
        .unk_3 = 12
    },
    [ITEM_ACQUISITION_SPACE_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 5,
        .unk_3 = 12
    },
    [ITEM_ACQUISITION_POWER_GRIP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = 1,
        .unk_3 = 12
    },
};

const u8 sStatusScreen_40df64[8] = {
    0, 1, 2, 3,
    4, 3, 2, 1
};

const u8 sStatusScreen_40df6c[6] = {
    0, 1, 2, 3, 4, 5
};

const u8 sStatusScreen_40df72[6] = {
    0, 1, 2, 3, 0, 0
};


