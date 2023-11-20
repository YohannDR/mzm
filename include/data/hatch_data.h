#ifndef HATCH_DATA_H
#define HATCH_DATA_H

#include "types.h"

#include "structs/connection.h"

// 360130

extern const u8 sHatchTypeTable[MAX_AMOUNT_OF_HATCH_TYPES];

extern const struct HatchLockEvent sHatchLockEventsBrinstar[1];

extern const struct HatchLockEvent sHatchLockEventsKraid[1];

extern const struct HatchLockEvent sHatchLockEventsNorfair[2];

extern const struct HatchLockEvent sHatchLockEventsChozodia[15];

extern const u8 sEventBasedConnections[MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS][4];

extern const u8 sAreaConnections[26][3];

extern const u8 sHatchesAnimationDurationCounter[6];

extern const u16 sHatchesTilemapValues[MAX_AMOUNT_OF_HATCH_TYPES];

extern const u16 sNumberOfHatchLockEventsPerArea[MAX_AMOUNT_OF_AREAS];

// 3603e8

#endif