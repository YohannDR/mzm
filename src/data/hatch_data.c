#ifndef HATCH_DATA_C
#define HATCH_DATA_C

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
    [6] = HATCH_LOCKED,
    [7] = HATCH_LOCKED_AND_LOCK_DESTINATION,
};

static const struct HatchLockEvent sHatchLockEventsBrinstar[1] = {
    {
        .room = 9,
        .event = EVENT_VIEWED_STATUE_ROOM,
        .isBefore = TRUE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    }
};

static const struct HatchLockEvent sHatchLockEventsKraid[1] = {
    {
        .room = 4,
        .event = EVENT_ACID_WORM_KILLED,
        .isBefore = TRUE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    }
};

static const struct HatchLockEvent sHatchLockEventsNorfair[2] = {
    {
        .room = 0,
        .event = EVENT_MOTHER_BRAIN_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = TRUE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 8,
        .event = EVENT_BUGS_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    }
};

static const struct HatchLockEvent sHatchLockEventsChozodia[15] = {
    {
        .room = 13,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = TRUE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 13,
        .event = EVENT_HARD,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 44,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 46,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 51,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 52,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 53,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 58,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 59,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 60,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = TRUE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 69,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 70,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 92,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 70,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = TRUE,
        .hatchesToLock2 = FALSE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    },
    {
        .room = 96,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .isBefore = FALSE,
        .hatchesToLock1 = FALSE,
        .hatchesToLock2 = TRUE,
        .hatchesToLock3 = FALSE,
        .hatchesToLock4 = FALSE,
        .hatchesToLock5 = FALSE,
        .hatchesToLock6 = FALSE,
        .hatchesToLock7 = FALSE,
        .hatchesToLock8 = FALSE,
        .hatchesToLockPart2_1 = FALSE,
        .hatchesToLockPart2_2 = FALSE,
        .hatchesToLockPart2_3 = FALSE,
        .hatchesToLockPart2_4 = FALSE,
        .hatchesToLockPart2_5 = FALSE,
        .hatchesToLockPart2_6 = FALSE,
        .hatchesToLockPart2_7 = FALSE,
        .hatchesToLockPart2_8 = FALSE
    }
};

static const struct EventBasedConnection sEventBasedConnections[MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS] = {
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 198,
        .event = EVENT_HARD,
        .destinationDoor = 212
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 195,
        .event = EVENT_HARD,
        .destinationDoor = 235
    },
    {
        .sourceArea = AREA_NORFAIR,
        .sourceDoor = 66,
        .event = EVENT_ENTER_RIDLEY_DEMO_PLAYED,
        .destinationDoor = 95
    },
    {
        .sourceArea = AREA_NORFAIR,
        .sourceDoor = 69,
        .event = EVENT_ENTER_RIDLEY_DEMO_PLAYED,
        .destinationDoor = 96
    },
    {
        .sourceArea = AREA_CRATERIA,
        .sourceDoor = 30,
        .event = EVENT_POWER_GRIP_OBTAINED,
        .destinationDoor = 29
    },
    {
        .sourceArea = AREA_CRATERIA,
        .sourceDoor = 19,
        .event = EVENT_CHOZO_PILLAR_FULLY_EXTENDED,
        .destinationDoor = 47
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 132,
        .event = EVENT_SPACE_JUMP_OBTAINED,
        .destinationDoor = 202
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 136,
        .event = EVENT_SPACE_JUMP_OBTAINED,
        .destinationDoor = 203
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 153,
        .event = EVENT_SPACE_JUMP_OBTAINED,
        .destinationDoor = 208
    },
    {
        .sourceArea = AREA_KRAID,
        .sourceDoor = 70,
        .event = EVENT_KRAID_KILLED,
        .destinationDoor = 89
    },
    {
        .sourceArea = AREA_NORFAIR,
        .sourceDoor = 94,
        .event = EVENT_CATERPILLAR_KILLED,
        .destinationDoor = 93
    },
    {
        .sourceArea = AREA_RIDLEY,
        .sourceDoor = 74,
        .event = EVENT_IMAGO_TUNNEL_DISCOVERED,
        .destinationDoor = 66
    },
    {
        .sourceArea = AREA_RIDLEY,
        .sourceDoor = 43,
        .event = EVENT_IMAGO_KILLED,
        .destinationDoor = 59
    },
    {
        .sourceArea = AREA_RIDLEY,
        .sourceDoor = 63,
        .event = EVENT_IMAGO_KILLED,
        .destinationDoor = 65
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 88,
        .event = EVENT_REPEL_MACHINE_KILLED,
        .destinationDoor = 93
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 91,
        .event = EVENT_REPEL_MACHINE_KILLED,
        .destinationDoor = 92
    },
    {
        .sourceArea = AREA_TOURIAN,
        .sourceDoor = 13,
        .event = EVENT_ESCAPED_ZEBES,
        .destinationDoor = 20
    },
    {
        .sourceArea = AREA_CRATERIA,
        .sourceDoor = 27,
        .event = EVENT_ESCAPED_ZEBES,
        .destinationDoor = 14
    },
    {
        .sourceArea = AREA_CRATERIA,
        .sourceDoor = 4,
        .event = EVENT_ESCAPED_ZEBES,
        .destinationDoor = 46
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 161,
        .event = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        .destinationDoor = 228
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 164,
        .event = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        .destinationDoor = 229
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 188,
        .event = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP,
        .destinationDoor = 227
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 82,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 192
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 85,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 191
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 46,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 224
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 53,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 169
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 176,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 201
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 57,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 118
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 76,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 121
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 64,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 120
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 67,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 119
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 86,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 209
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 54,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 148
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 79,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 147
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 238,
        .event = EVENT_FULLY_POWERED_SUIT_OBTAINED,
        .destinationDoor = 242
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 172,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 215
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 96,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 216
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 100,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 217
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 104,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 218
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 128,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 233
    },
    {
        .sourceArea = AREA_CHOZODIA,
        .sourceDoor = 152,
        .event = EVENT_MECHA_RIDLEY_KILLED,
        .destinationDoor = 234
    }
};

static const u8 sAreaConnections[26][3] = {
    {
        AREA_NORFAIR,
        70,
        AREA_RIDLEY
    },
    {
        AREA_RIDLEY,
        0,
        AREA_NORFAIR
    },
    {
        AREA_BRINSTAR,
        57,
        AREA_NORFAIR
    },
    {
        AREA_NORFAIR,
        0,
        AREA_BRINSTAR
    },
    {
        AREA_BRINSTAR,
        61,
        AREA_TOURIAN
    },
    {
        AREA_TOURIAN,
        0,
        AREA_BRINSTAR
    },
    {
        AREA_BRINSTAR,
        9,
        AREA_KRAID
    },
    {
        AREA_KRAID,
        0,
        AREA_BRINSTAR
    },
    {
        AREA_BRINSTAR,
        0,
        AREA_CRATERIA
    },
    {
        AREA_CRATERIA,
        11,
        AREA_BRINSTAR
    },
    {
        AREA_CRATERIA,
        13,
        AREA_TOURIAN
    },
    {
        AREA_TOURIAN,
        11,
        AREA_CRATERIA
    },
    {
        AREA_CRATERIA,
        17,
        AREA_NORFAIR
    },
    {
        AREA_NORFAIR,
        76,
        AREA_CRATERIA
    },
    {
        AREA_CRATERIA,
        33,
        AREA_CHOZODIA
    },
    {
        AREA_CHOZODIA,
        150,
        AREA_CRATERIA
    },
    {
        AREA_TOURIAN,
        21,
        AREA_CRATERIA
    },
    {
        AREA_NORFAIR,
        108,
        AREA_RIDLEY
    },
    {
        AREA_RIDLEY,
        60,
        AREA_NORFAIR
    },
    {
        AREA_CHOZODIA,
        220,
        AREA_CRATERIA
    },
    {
        AREA_CRATERIA,
        24,
        AREA_CHOZODIA
    },
    {
        AREA_CRATERIA,
        49,
        AREA_CHOZODIA
    },
    {
        AREA_NORFAIR,
        129,
        AREA_KRAID
    },
    {
        AREA_KRAID,
        103,
        AREA_NORFAIR
    },
    {
        AREA_CRATERIA,
        51,
        AREA_TOURIAN
    },
    {
        AREA_NONE,
        255,
        AREA_NONE
    }
};

static const u8 sHatchesAnimationDurationCounter[6] = {
    3, 3, 3, 3, 3, 255
};

static const u16 sHatchesTilemapValues[MAX_AMOUNT_OF_HATCH_TYPES] = {
    [HATCH_NONE] = 0x49A,
    [HATCH_UNUSED] = 0x490,
    [HATCH_NORMAL] = 0x492,
    [HATCH_MISSILE] = 0x494,
    [HATCH_SUPER_MISSILE] = 0x496,
    [HATCH_POWER_BOMB] = 0x498,
    [HATCH_LOCKED] = 0x490,
    [HATCH_LOCKED_AND_LOCK_DESTINATION] = 0x41A
};

static const u16 sNumberOfHatchLockEventsPerArea[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = 1,
    [AREA_KRAID] = 1,
    [AREA_NORFAIR] = 0,
    [AREA_RIDLEY] = 0,
    [AREA_TOURIAN] = 0,
    [AREA_CRATERIA] = 2,
    [AREA_CHOZODIA] = 15,
    [AREA_INVALID] = 0
};

// 3602e8

#endif