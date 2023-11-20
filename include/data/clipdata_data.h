#ifndef CLIPDATA_DATA_H
#define CLIPDATA_DATA_H

#include "types.h"

#include "structs/clipdata.h"
#include "structs/scroll.h"

extern const u16 sMovementClipdataValues[16];
extern const u16 sHazardsDefinitions[8][2];
extern const u16 sHazardClipdataValues[4];
extern const u8 sGroundEffectsClipdataValues[8];
extern const struct ElevatorPair sElevatorRoomPairs[9]; 
extern const u8 sScroll_Empty[11];
extern const struct CameraScrollVelocityCaps sScrollVelocityCaps[3];

#endif /* CLIPDATA_DATA_H */
