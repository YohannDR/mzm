#include "data/hatch_data.h"

#include "macros.h"

#include "constants/event.h"
#include "constants/clipdata.h"
#include "constants/connection.h"

// 360130

const u8 sHatchTypeTable[MAX_AMOUNT_OF_HATCH_TYPES] = {
    [0] = HATCH_NONE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_GRAY_DOOR)] = HATCH_LOCKED,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_REGULAR_DOOR)] = HATCH_NORMAL,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_MISSILE_DOOR)] = HATCH_MISSILE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_SUPER_MISSILE_DOOR)] = HATCH_SUPER_MISSILE,
    [BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_POWER_BOMB_DOOR)] = HATCH_POWER_BOMB,
    [6] = HATCH_LOCKED,
    [7] = HATCH_LOCKED_AND_LOCK_DESTINATION,
};

const struct HatchLockEvent sHatchLockEventsBrinstar[1] = {
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

const struct HatchLockEvent sHatchLockEventsKraid[1] = {
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

const struct HatchLockEvent sHatchLockEventsNorfair[2] = {
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

const struct HatchLockEvent sHatchLockEventsChozodia[15] = {
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
        .room = 71,
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

const u8 sEventBasedConnections[MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS][4] = {
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 198, // Source door
        [2] = EVENT_HARD, // Event
        [3] = 212 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 195, // Source door
        [2] = EVENT_HARD, // Event
        [3] = 235 // Destination door
    },
    {
        [0] = AREA_NORFAIR, // Source area
        [1] = 66, // Source door
        [2] = EVENT_ENTER_RIDLEY_DEMO_PLAYED, // Event
        [3] = 95 // Destination door
    },
    {
        [0] = AREA_NORFAIR, // Source area
        [1] = 69, // Source door
        [2] = EVENT_ENTER_RIDLEY_DEMO_PLAYED, // Event
        [3] = 96 // Destination door
    },
    {
        [0] = AREA_CRATERIA, // Source area
        [1] = 30, // Source door
        [2] = EVENT_POWER_GRIP_OBTAINED, // Event
        [3] = 29 // Destination door
    },
    {
        [0] = AREA_CRATERIA, // Source area
        [1] = 19, // Source door
        [2] = EVENT_CHOZO_PILLAR_FULLY_EXTENDED, // Event
        [3] = 47 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 132, // Source door
        [2] = EVENT_SPACE_JUMP_OBTAINED, // Event
        [3] = 202 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 136, // Source door
        [2] = EVENT_SPACE_JUMP_OBTAINED, // Event
        [3] = 203 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 153, // Source door
        [2] = EVENT_SPACE_JUMP_OBTAINED, // Event
        [3] = 208 // Destination door
    },
    {
        [0] = AREA_KRAID, // Source area
        [1] = 70, // Source door
        [2] = EVENT_KRAID_KILLED, // Event
        [3] = 89 // Destination door
    },
    {
        [0] = AREA_NORFAIR, // Source area
        [1] = 94, // Source door
        [2] = EVENT_CATERPILLAR_KILLED, // Event
        [3] = 93 // Destination door
    },
    {
        [0] = AREA_RIDLEY, // Source area
        [1] = 74, // Source door
        [2] = EVENT_IMAGO_TUNNEL_DISCOVERED, // Event
        [3] = 66 // Destination door
    },
    {
        [0] = AREA_RIDLEY, // Source area
        [1] = 43, // Source door
        [2] = EVENT_IMAGO_KILLED, // Event
        [3] = 59 // Destination door
    },
    {
        [0] = AREA_RIDLEY, // Source area
        [1] = 63, // Source door
        [2] = EVENT_IMAGO_KILLED, // Event
        [3] = 65 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 88, // Source door
        [2] = EVENT_REPEL_MACHINE_KILLED, // Event
        [3] = 93 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 91, // Source door
        [2] = EVENT_REPEL_MACHINE_KILLED, // Event
        [3] = 92 // Destination door
    },
    {
        [0] = AREA_TOURIAN, // Source area
        [1] = 13, // Source door
        [2] = EVENT_ESCAPED_ZEBES, // Event
        [3] = 20 // Destination door
    },
    {
        [0] = AREA_CRATERIA, // Source area
        [1] = 27, // Source door
        [2] = EVENT_ESCAPED_ZEBES, // Event
        [3] = 14 // Destination door
    },
    {
        [0] = AREA_CRATERIA, // Source area
        [1] = 4, // Source door
        [2] = EVENT_ESCAPED_ZEBES, // Event
        [3] = 46 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 161, // Source door
        [2] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP, // Event
        [3] = 228 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 164, // Source door
        [2] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP, // Event
        [3] = 229 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 188, // Source door
        [2] = EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP, // Event
        [3] = 227 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 82, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 192 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 85, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 191 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 46, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 224 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 53, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 169 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 176, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 201 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 57, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 118 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 76, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 121 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 64, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 120 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 67, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 119 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 86, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 209 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 54, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 148 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 79, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 147 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 238, // Source door
        [2] = EVENT_FULLY_POWERED_SUIT_OBTAINED, // Event
        [3] = 242 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 172, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 215 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 96, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 216 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 100, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 217 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 104, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 218 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 128, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 233 // Destination door
    },
    {
        [0] = AREA_CHOZODIA, // Source area
        [1] = 152, // Source door
        [2] = EVENT_MECHA_RIDLEY_KILLED, // Event
        [3] = 234 // Destination door
    }
};

const u8 sAreaConnections[26][3] = {
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
        UCHAR_MAX,
        AREA_NONE
    }
};

const u8 sHatchesAnimationDurationCounter[6] = {
    3, 3, 3, 3, 3, UCHAR_MAX
};

const u16 sHatchesTilemapValues[MAX_AMOUNT_OF_HATCH_TYPES] = {
    [HATCH_NONE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_NO_HATCH_DOOR_TOP_LEFT,
    [HATCH_UNUSED] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_GRAY_DOOR_TOP_LEFT,
    [HATCH_NORMAL] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_REGULAR_DOOR_TOP_LEFT,
    [HATCH_MISSILE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_DOOR_TOP_LEFT,
    [HATCH_SUPER_MISSILE] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SUPER_MISSILE_DOOR_TOP_LEFT,
    [HATCH_POWER_BOMB] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_DOOR_TOP_LEFT,
    [HATCH_LOCKED] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_GRAY_DOOR_TOP_LEFT,
    [HATCH_LOCKED_AND_LOCK_DESTINATION] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_CLOSED_DOOR_TOP_LEFT
};

const u16 sNumberOfHatchLockEventsPerArea[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = 1,
    [AREA_KRAID] = 1,
    [AREA_NORFAIR] = 0,
    [AREA_RIDLEY] = 0,
    [AREA_TOURIAN] = 0,
    [AREA_CRATERIA] = 2,
    [AREA_CHOZODIA] = 15,
    [AREA_DEBUG_1] = 0
};
