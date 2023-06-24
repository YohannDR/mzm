#ifndef CONNECTION_H
#define CONNECTION_H

#include "types.h"

// Functions

void ConnectionUpdateHatches(void);
void ConnectionUpdateHatchAnimation(u8 dontSetRaw, u32 hatch);
void ConnectionHatchFlashingAnimation(u8 hatch);
void ConnectionOverrideOpenedHatch(u8 hatch, u32 type);
u32 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition);
u32 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition);
void ConnectionProcessDoorType(u8 type);
u8 ConnectionFindEventBasedDoor(u8 sourceDoor);
u32 ConnectionSetHatchAsOpened(u8 action, u8 hatch);
void ConnectionCheckUnlockDoors(void);
void ConnectionHatchStartLockAnimation(u8 dontSetRaw, u8 hatch, u8 status);
void ConnectionLockHatches(u8 isEvent);
void ConnectionLoadDoors(void);
void ConnectionLockHatchesWithTimer(void);
void ConnectionCheckHatchLockEvents(void);
void ConnectionCheckPlayCutsceneDuringTransition(u8 area, u8 dstRoomPlusOne);
void ConnectionCheckPlayCutsceneDuringElevator(void);

#endif /* CONNECTION_H */