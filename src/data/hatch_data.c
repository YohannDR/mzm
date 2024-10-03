#include "data/hatch_data.h"

#include "macros.h"

#include "constants/event.h"
#include "constants/clipdata.h"

// 360130

const u8 sHatchTypeTable[HATCH_COUNT] = {
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_NO_DOOR)] = HATCH_NONE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_GRAY_DOOR)] = HATCH_LOCKED,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_REGULAR_DOOR)] = HATCH_NORMAL,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_MISSILE_DOOR)] = HATCH_MISSILE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_SUPER_MISSILE_DOOR)] = HATCH_SUPER_MISSILE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_POWER_BOMB_DOOR)] = HATCH_POWER_BOMB,
    [6] = HATCH_LOCKED,
    [7] = HATCH_LOCKED_NAVIGATION,
};

const struct HatchLockEvent sHatchLockEventsBrinstar[1] = {
    {
        .room = 9,
        .event = EVENT_VIEWED_STATUE_ROOM,
        .type = HATCH_LOCK_EVENT_TYPE_BEFORE,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    }
};

const struct HatchLockEvent sHatchLockEventsKraid[1] = {
    {
        .room = 4,
        .event = EVENT_ACID_WORM_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_BEFORE,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    }
};

const struct HatchLockEvent sHatchLockEventsCrateria[2] = {
    {
        .room = 0,
        .event = EVENT_MOTHER_BRAIN_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = TRUE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 8,
        .event = EVENT_BUGS_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    }
};

const struct HatchLockEvent sHatchLockEventsChozodia[15] = {
    {
        .room = 13,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = TRUE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 13,
        .event = EVENT_HARD,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 44,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 46,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 51,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 52,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = TRUE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 53,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 58,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 59,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 60,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = TRUE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 69,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 70,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 71,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 92,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = TRUE,
        .hatchesToLock_1 = FALSE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    },
    {
        .room = 96,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .type = HATCH_LOCK_EVENT_TYPE_AFTER,
        .hatchesToLock_0 = FALSE,
        .hatchesToLock_1 = TRUE,
        .hatchesToLock_2 = FALSE,
        .hatchesToLock_3 = FALSE,
        .hatchesToLock_4 = FALSE,
        .hatchesToLock_5 = FALSE,
        .hatchesToLock_6 = FALSE,
        .hatchesToLock_7 = FALSE,
        .hatchesToLock_8 = FALSE,
        .hatchesToLock_9 = FALSE,
        .hatchesToLock_10 = FALSE,
        .hatchesToLock_11 = FALSE,
        .hatchesToLock_12 = FALSE,
        .hatchesToLock_13 = FALSE,
        .hatchesToLock_14 = FALSE,
        .hatchesToLock_15 = FALSE
    }
};

const u8 sEventBasedConnections[41][EVENT_BASED_CONNECTION_FIELD_COUNT] = {
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 198,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HARD,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 212
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 195,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_HARD,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 235
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 66,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTER_RIDLEY_DEMO_PLAYED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 95
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 69,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ENTER_RIDLEY_DEMO_PLAYED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 96
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 30,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_POWER_GRIP_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 29
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 19,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_CHOZO_PILLAR_FULLY_EXTENDED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 47
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 132,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SPACE_JUMP_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 202
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 136,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SPACE_JUMP_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 203
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 153,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_SPACE_JUMP_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 208
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_KRAID,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 70,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_KRAID_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 89
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 94,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_CATERPILLAR_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 93
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_RIDLEY,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 74,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_IMAGO_TUNNEL_DISCOVERED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 66
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_RIDLEY,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 43,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_IMAGO_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 59
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_RIDLEY,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 63,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_IMAGO_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 65
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 88,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_REPEL_MACHINE_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 93
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 91,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_REPEL_MACHINE_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 92
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_TOURIAN,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 13,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ESCAPED_ZEBES,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 20
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 27,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ESCAPED_ZEBES,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 14
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 4,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_ESCAPED_ZEBES,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 46
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 161,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 228
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 164,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 229
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 188,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 227
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 82,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 192
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 85,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 191
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 46,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 224
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 53,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 169
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 176,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 201
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 57,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 118
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 76,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 121
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 64,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 120
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 67,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 119
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 86,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 209
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 54,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 148
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 79,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 147
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 238,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 242
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 172,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 215
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 96,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 216
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 100,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 217
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 104,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 218
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 128,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 233
    },
    {
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR] = 152,
        [EVENT_BASED_CONNECTION_FIELD_EVENT] = EVENT_MECHA_RIDLEY_KILLED,
        [EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR] = 234
    }
};

const u8 sAreaConnections[][AREA_CONNECTION_FIELD_COUNT] = {
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 70,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_RIDLEY
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_RIDLEY,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NORFAIR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_BRINSTAR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 57,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NORFAIR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_BRINSTAR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_BRINSTAR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 61,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_TOURIAN
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_TOURIAN,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_BRINSTAR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_BRINSTAR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 9,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_KRAID
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_KRAID,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_BRINSTAR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_BRINSTAR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 0,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 11,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_BRINSTAR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 13,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_TOURIAN
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_TOURIAN,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 11,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 17,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NORFAIR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 76,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 33,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CHOZODIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 150,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_TOURIAN,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 21,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 108,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_RIDLEY
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_RIDLEY,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 60,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NORFAIR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CHOZODIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 220,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CRATERIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 24,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CHOZODIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 49,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_CHOZODIA
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NORFAIR,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 129,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_KRAID
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_KRAID,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 103,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NORFAIR
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_CRATERIA,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = 51,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_TOURIAN
    },
    {
        [AREA_CONNECTION_FIELD_SOURCE_AREA] = AREA_NONE,
        [AREA_CONNECTION_FIELD_SOURCE_DOOR] = UCHAR_MAX,
        [AREA_CONNECTION_FIELD_DESTINATION_AREA] = AREA_NONE
    }
};

const u8 sHatchesAnimationDurationCounter[6] = {
    [0] = CONVERT_SECONDS(.05f),
    [1] = CONVERT_SECONDS(.05f),
    [2] = CONVERT_SECONDS(.05f),
    [3] = CONVERT_SECONDS(.05f),
    [4] = CONVERT_SECONDS(.05f),
    [5] = UCHAR_MAX
};

const u16 sHatchesTilemapValues[HATCH_COUNT] = {
    [HATCH_NONE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_NO_HATCH_DOOR_TOP_LEFT,
    [HATCH_UNUSED] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_GRAY_DOOR_TOP_LEFT,
    [HATCH_NORMAL] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_REGULAR_DOOR_TOP_LEFT,
    [HATCH_MISSILE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_DOOR_TOP_LEFT,
    [HATCH_SUPER_MISSILE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SUPER_MISSILE_DOOR_TOP_LEFT,
    [HATCH_POWER_BOMB] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_DOOR_TOP_LEFT,
    [HATCH_LOCKED] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_GRAY_DOOR_TOP_LEFT,
    [HATCH_LOCKED_NAVIGATION] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_CLOSED_DOOR_TOP_LEFT
};

const u16 sNumberOfHatchLockEventsPerArea[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = ARRAY_SIZE(sHatchLockEventsBrinstar),
    [AREA_KRAID] = ARRAY_SIZE(sHatchLockEventsKraid),
    [AREA_NORFAIR] = 0,
    [AREA_RIDLEY] = 0,
    [AREA_TOURIAN] = 0,
    [AREA_CRATERIA] = ARRAY_SIZE(sHatchLockEventsCrateria),
    [AREA_CHOZODIA] = ARRAY_SIZE(sHatchLockEventsChozodia),
    [AREA_DEBUG_1] = 0
};
