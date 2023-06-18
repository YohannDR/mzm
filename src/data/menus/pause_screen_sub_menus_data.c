#include "data/menus/pause_screen_sub_menus_data.h"

#include "constants/menus/pause_screen.h"
#include "constants/event.h"
#include "constants/connection.h"
#include "constants/samus.h"

const struct ChozoStatueTarget sChozoStatueTargets[16] = {
    [TARGET_LONG_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 9,
        .statueXEnd = 9,
        .statueYStart = 15,
        .statueYEnd = 15,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 6,
        .targetY = 6,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_BOMBS] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 9,
        .statueXEnd = 9,
        .statueYStart = 3,
        .statueYEnd = 3,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 24,
        .targetY = 6,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_ICE_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 18,
        .statueXEnd = 18,
        .statueYStart = 10,
        .statueYEnd = 10,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 18,
        .targetY = 3,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_SPEED_BOOSTER] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 18,
        .statueXEnd = 18,
        .statueYStart = 1,
        .statueYEnd = 1,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_KRAID,
        .targetX = 8,
        .targetY = 15,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_HIGH_JUMP] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 8,
        .statueXEnd = 8,
        .statueYStart = 18,
        .statueYEnd = 18,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 19,
        .targetY = 8,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_VARIA] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 21,
        .statueXEnd = 21,
        .statueYStart = 10,
        .statueYEnd = 10,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_BRINSTAR,
        .targetX = 14,
        .targetY = 2,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_WAVE_BEAM] = {
        .statueArea = AREA_BRINSTAR,
        .statueXStart = 26,
        .statueXEnd = 26,
        .statueYStart = 4,
        .statueYEnd = 4,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 10,
        .targetY = 12,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_SCREW_ATTACK] = {
        .statueArea = AREA_NORFAIR,
        .statueXStart = 19,
        .statueXEnd = 19,
        .statueYStart = 13,
        .statueYEnd = 13,
        .startIcon = TARGET_OAM_ID_TARGET,
        .targetArea = AREA_NORFAIR,
        .targetX = 6,
        .targetY = 7,
        .endIcon = TARGET_OAM_ID_TARGET
    },
    [TARGET_KRAID_FLAME] = {
        .statueArea = AREA_KRAID,
        .statueXStart = 9,
        .statueXEnd = 10,
        .statueYStart = 14,
        .statueYEnd = 15,
        .startIcon = TARGET_OAM_GREEN_FLAME_SPAWNING,
        .targetArea = AREA_BRINSTAR,
        .targetX = 3,
        .targetY = 3,
        .endIcon = TARGET_OAM_GREEN_FLAME_MOVING
    },
    [TARGET_RIDLEY_FLAME] = {
        .statueArea = AREA_RIDLEY,
        .statueXStart = 7,
        .statueXEnd = 8,
        .statueYStart = 6,
        .statueYEnd = 7,
        .startIcon = TARGET_OAM_PURPLE_FLAME_SPAWNING,
        .targetArea = AREA_BRINSTAR,
        .targetX = 2,
        .targetY = 3,
        .endIcon = TARGET_OAM_PURPLE_FLAME_MOVING
    },
    [10] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [11] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [12] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [13] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [14] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
    [15] = {
        .statueArea = AREA_NONE,
        .statueXStart = 0,
        .statueXEnd = 0,
        .statueYStart = 0,
        .statueYEnd = 0,
        .startIcon = 0,
        .targetArea = AREA_NONE,
        .targetX = 0,
        .targetY = 0,
        .endIcon = 0
    },
};

const u8 sChozoStatueTargetConditions[16][2] = {
    [TARGET_LONG_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_LONG_BEAM
    },
    [TARGET_BOMBS] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_BOMBS
    },
    [TARGET_ICE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_ICE_BEAM
    },
    [TARGET_SPEED_BOOSTER] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_SPEEDBOOSTER
    },
    [TARGET_HIGH_JUMP] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_HIGH_JUMP
    },
    [TARGET_VARIA] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_VARIA_SUIT
    },
    [TARGET_WAVE_BEAM] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS,
        BBF_WAVE_BEAM
    },
    [TARGET_SCREW_ATTACK] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC,
        SMF_SCREW_ATTACK
    },
    [TARGET_KRAID_FLAME] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_KRAID_STATUE_OPENED
    },
    [TARGET_RIDLEY_FLAME] = {
        CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT,
        EVENT_RIDLEY_STATUE_OPENED
    },
    [10] = {
        UCHAR_MAX,
        0
    },
    [11] = {
        UCHAR_MAX,
        0
    },
    [12] = {
        UCHAR_MAX,
        0
    },
    [13] = {
        UCHAR_MAX,
        0
    },
    [14] = {
        UCHAR_MAX,
        0
    },
    [15] = {
        UCHAR_MAX,
        0
    }
};

const u8 sChozoStatueHintEvents[16] = {
    [TARGET_LONG_BEAM] = EVENT_STATUE_LONG_BEAM_GRABBED,
    [TARGET_BOMBS] = EVENT_STATUE_BOMBS_GRABBED,
    [TARGET_ICE_BEAM] = EVENT_STATUE_ICE_BEAM_GRABBED,
    [TARGET_SPEED_BOOSTER] = EVENT_STATUE_SPEEDBOOSTER_GRABBED,
    [TARGET_HIGH_JUMP] = EVENT_STATUE_HIGH_JUMP_GRABBED,
    [TARGET_VARIA] = EVENT_STATUE_VARIA_SUIT_GRABBED,
    [TARGET_WAVE_BEAM] = EVENT_STATUE_WAVE_BEAM_GRABBED,
    [TARGET_SCREW_ATTACK] = EVENT_STATUE_SCREW_ATTACK_GRABBED,
    [TARGET_KRAID_FLAME] = EVENT_KRAID_KILLED,
    [TARGET_RIDLEY_FLAME] = EVENT_RIDLEY_KILLED,
    [10] = UCHAR_MAX,
    [11] = UCHAR_MAX,
    [12] = UCHAR_MAX,
    [13] = UCHAR_MAX,
    [14] = UCHAR_MAX,
    [15] = UCHAR_MAX
};

const s8 sChozoStatueTargetPathBrinstar[9][2] = {
    [0] = {
        0, 0x40
    },
    [1] = {
        0, 0x40
    },
    [2] = {
        0, 0x40
    },
    [3] = {
        3, 0x40
    },
    [4] = {
        0, 0x40
    },
    [5] = {
        0, 0x40
    },
    [6] = {
        2, 0x40
    },
    [7] = {
        0, 0x40
    },
    [8] = {
        0, 0x40
    },
};

const s8 sChozoStatueTargetPathKraid[9][2] = {
    [0] = {
        3, -0x40
    },
    [1] = {
        0, 0x40
    },
    [2] = {
        0, 0x40
    },
    [3] = {
        0, 0x40
    },
    [4] = {
        0, 0x40
    },
    [5] = {
        0, 0x40
    },
    [6] = {
        3, -0x40
    },
    [7] = {
        2, 0x40
    },
    [8] = {
        0, 0x40
    },
};

const s8 sChozoStatueTargetPathNorfair[9][2] = {
    [0] = {
        2, -0x40
    },
    [1] = {
        0, 0x40
    },
    [2] = {
        0, 0x40
    },
    [3] = {
        2, -0x40
    },
    [4] = {
        3, 0x40
    },
    [5] = {
        0, 0x40
    },
    [6] = {
        0, 0x40
    },
    [7] = {
        0, 0x40
    },
    [8] = {
        0, 0x40
    },
};

const s8 sChozoStatueTargetPathRidley[9][2] = {
    [0] = {
        4, -0x40
    },
    [1] = {
        2, -0x40
    },
    [2] = {
        0, 0x40
    },
    [3] = {
        4, -0x40
    },
    [4] = {
        2, -0x40
    },
    [5] = {
        3, 0x40
    },
    [6] = {
        4, -0x40
    },
    [7] = {
        0, 0x40
    },
    [8] = {
        0, 0x40
    },
};

const s8 sChozoStatueTargetPathCrateria[9][2] = {
    [0] = {
        7, 0x40
    },
    [1] = {
        2, -0x40
    },
    [2] = {
        0, 0x40
    },
    [3] = {
        7, 0x40
    },
    [4] = {
        2, -0x40
    },
    [5] = {
        3, 0x40
    },
    [6] = {
        7, 0x40
    },
    [7] = {
        0, 0x40
    },
    [8] = {
        0, 0x40
    },
};
