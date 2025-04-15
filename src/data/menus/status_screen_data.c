#include "data/menus/status_screen_data.h"
#include "constants/menus/status_screen.h"
#include "constants/menus/pause_screen.h"
#include "macros.h"

const u16 sStatusScreenUnknownItemsWhiteFlashingPal[6 * 16] = INCBIN_U16("data/menus/PauseScreen/MapScreenUnknownItemsFlashing.pal");
const u16 sStatusScreenUnknownItemsNamesFlashingPal[4 * 16] = INCBIN_U16("data/menus/PauseScreen/MapScreenUnknownItemsNamesFlashing.pal");

/*
 * 0: Y1 position (top)
 * 1: Y2 position (bottom)
 * 2: X1 position (left)
 * 3: X2 position (right)
 * 4: Ability group?
 */
const u8 sStatusScreenGroupsPositions[ABILITY_GROUP_END][5] = {
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

/*
 * 0: Y1 position (top)
 * 1: Y2 position (bottom)
 * 2: X1 position (left)
 * 3: X2 position (right)
 * 4: Ability group?
 */
const u8 sStatusScreenUnknownItemsPositions[10][5] = {
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

const struct StatusScreenItemData sStatusScreenItemsData[STATUS_SLOT_END] = {
    [STATUS_SLOT_0] = {
        .group = ABILITY_GROUP_CURRENT_ENERGY,
        .abilityOffset = 0,
        .row = 0,
        .unk_3 = 0
    },
    [STATUS_SLOT_LONG_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_LONG,
        .row = 1,
        .unk_3 = 1
    },
    [STATUS_SLOT_CHARGE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_CHARGE,
        .row = 2,
        .unk_3 = 1
    },
    [STATUS_SLOT_ICE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_ICE,
        .row = 3,
        .unk_3 = 1
    },
    [STATUS_SLOT_WAVE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_WAVE,
        .row = 4,
        .unk_3 = 1
    },
    [STATUS_SLOT_PLASMA_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_PLASMA,
        .row = 5,
        .unk_3 = 1
    },
    [STATUS_SLOT_NORMAL_MISSILE] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_NORMAL,
        .row = 1,
        .unk_3 = 0
    },
    [STATUS_SLOT_SUPER_MISSILE] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_SUPER,
        .row = 3,
        .unk_3 = 0
    },
    [STATUS_SLOT_NORMAL_BOMB] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_NORMAL,
        .row = 1,
        .unk_3 = 0
    },
    [STATUS_SLOT_POWER_BOMB] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_POWER,
        .row = 2,
        .unk_3 = 0
    },
    [STATUS_SLOT_VARIA] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_VARIA,
        .row = 1,
        .unk_3 = 2
    },
    [STATUS_SLOT_GRAVITY] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_GRAVITY,
        .row = 2,
        .unk_3 = 2
    },
    [STATUS_SLOT_MORPH_BALL] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_MORPH_BALL,
        .row = 1,
        .unk_3 = 2
    },
    [STATUS_SLOT_POWER_GRIP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_POWER_GRIP,
        .row = 2,
        .unk_3 = 2
    },
    [STATUS_SLOT_SPEED_BOOSTER] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER,
        .row = 3,
        .unk_3 = 2
    },
    [STATUS_SLOT_HIGH_JUMP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP,
        .row = 4,
        .unk_3 = 2
    },
    [STATUS_SLOT_SCREW_ATTACK] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK,
        .row = 5,
        .unk_3 = 2
    },
    [STATUS_SLOT_SPACE_JUMP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP,
        .row = 6,
        .unk_3 = 2
    }
};

const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[ITEM_ACQUISITION_END] = {
    [0] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [1] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [2] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_NORMAL,
        .statusSlot = STATUS_SLOT_NORMAL_MISSILE
    },
    [4] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_SUPER_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_SUPER + 1,
        .statusSlot = STATUS_SLOT_SUPER_MISSILE
    },
    [6] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_POWER_BOMB] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_POWER,
        .statusSlot = STATUS_SLOT_POWER_BOMB
    },
    [ITEM_ACQUISITION_LONG_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_LONG,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_CHARGE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_CHARGE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_ICE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_ICE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_WAVE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_WAVE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_PLASMA_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_PLASMA,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_BOMBS] = {
        .unk_0 = 2,
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_NORMAL,
        .statusSlot = STATUS_SLOT_NORMAL_BOMB
    },
    [ITEM_ACQUISITION_VARIA] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_VARIA,
        .statusSlot = STATUS_SLOT_SUIT
    },
    [ITEM_ACQUISITION_GRAVITY] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_GRAVITY,
        .statusSlot = STATUS_SLOT_SUIT
    },
    [ITEM_ACQUISITION_MORPH_BALL] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_MORPH_BALL,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SPEEDBOOSTER] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_HIGH_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SCREW_ATTACK] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SPACE_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_POWER_GRIP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_POWER_GRIP,
        .statusSlot = STATUS_SLOT_MISC
    },
};

const u8 sStatusScreenUnknownItemsPartialFlash[8] = {
    0, 1, 2, 3,
    4, 3, 2, 1
};

const u8 sStatusScreenUnknownItemsFullFlash[6] = {
    0, 1, 2, 3, 4, 5
};

const u8 sStatusScreenUnknownItemsNamesFlash[4] = {
    0, 1, 2, 3
};


