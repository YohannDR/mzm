#include "../types.h"
#include "../connection.h"
#include "../clipdata.h"

// 360130

static const u8 sHatchTypeTable[MAX_AMOUNT_OF_HATCH_TYPES] = {
    [0] = HATCH_NONE,
    [behavior_to_door(CLIP_BEHAVIOR_GRAY_DOOR)] = HATCH_LOCKED,
    [behavior_to_door(CLIP_BEHAVIOR_REGULAR_DOOR)] = HATCH_NORMAL,
    [behavior_to_door(CLIP_BEHAVIOR_MISSILE_DOOR)] = HATCH_MISSILE,
    [behavior_to_door(CLIP_BEHAVIOR_SUPER_MISSILE_DOOR)] = HATCH_SUPER_MISSILE,
    [behavior_to_door(CLIP_BEHAVIOR_POWER_BOMB_DOOR)] = HATCH_POWER_BOMB,
    [5] = HATCH_LOCKED,
    [6] = HATCH_LOCKED_AND_LOCK_DESTINATION,
};

static const struct HatchLockEvent sHatchLockEventsBrinstar[1] = {
    {
        .destinationRoom = 9,
        .event = EVENT_VIEWED_STATUE_ROOM,
        .isBefore = TRUE,
        .hatchesToLock = 2,
        .unknown = 0
    }
};

static const struct HatchLockEvent sHatchLockEventsKraid[1] = {
    {
        .destinationRoom = 4,
        .event = EVENT_ACID_WORM_KILLED,
        .isBefore = TRUE,
        .hatchesToLock = 1,
        .unknown = 0
    }
};

static const struct HatchLockEvent sHatchLockEventsNorfair[2] = {
    {
        .destinationRoom = 0,
        .event = EVENT_MOTHER_BRAIN_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 3 | 1,
        .unknown = 0
    },
    {
        .destinationRoom = 8,
        .event = EVENT_BUGS_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 1,
        .unknown = 0
    }
};

static const struct HatchLockEvent sHatchLockEventsChozodia[15] = {
    {
        .destinationRoom = 13,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 8,
        .unknown = 0
    },
    {
        .destinationRoom = 13,
        .event = EVENT_HARD,
        .isBefore = FALSE,
        .hatchesToLock = 1,
        .unknown = 0
    },
    {
        .destinationRoom = 44,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 46,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 1,
        .unknown = 0
    },
    {
        .destinationRoom = 51,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 52,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 1 | 2,
        .unknown = 0
    },
    {
        .destinationRoom = 53,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 58,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 59,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 60,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2 | 4,
        .unknown = 0
    },
    {
        .destinationRoom = 69,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 70,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 92,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    },
    {
        .destinationRoom = 70,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 1,
        .unknown = 0
    },
    {
        .destinationRoom = 96,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock = 2,
        .unknown = 0
    }
};
