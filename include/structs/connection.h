#ifndef CONNECTION_STRUCT_H
#define CONNECTION_STRUCT_H

#include "types.h"

// Structs

struct Door {
    u8 type;
    u8 sourceRoom;
    u8 xStart;
    u8 xEnd;
    u8 yStart;
    u8 yEnd;
    u8 destinationDoor;
    s8 xExit;
    s8 yExit;
};

struct EventBasedConnection {
    u8 sourceArea;
    u8 sourceDoor;
    u8 event;
    u8 destinationDoor;
};

struct HatchLockEvent {
    u8 room;
    u8 event;
    u8 isBefore;
    u8 hatchesToLock1:1;
    u8 hatchesToLock2:1;
    u8 hatchesToLock3:1;
    u8 hatchesToLock4:1;
    u8 hatchesToLock5:1;
    u8 hatchesToLock6:1;
    u8 hatchesToLock7:1;
    u8 hatchesToLock8:1;
    u8 hatchesToLockPart2_1:1;
    u8 hatchesToLockPart2_2:1;
    u8 hatchesToLockPart2_3:1;
    u8 hatchesToLockPart2_4:1;
    u8 hatchesToLockPart2_5:1;
    u8 hatchesToLockPart2_6:1;
    u8 hatchesToLockPart2_7:1;
    u8 hatchesToLockPart2_8:1;
};

struct HatchData {
    /* 0 */
    u16 exists:1;
    u16 currentAnimationFrame:3;
    u16 facingRight:1;
    u16 padding:3;
    /* 1 */
    u8 opening:2;
    u16 locked:2;
    u16 flashingTimer:4;
    /* 2 */
    u16 hitTimer:4;
    u16 hits:4;
    /* 3 */
    u8 type;
    u8 animationDurationCounter;
    u8 xPosition;
    u8 yPosition;
    u8 sourceDoor;
};

struct LastElevatorUsed {
    u16 unused;
    u8 route;
    s8 direction;
};

struct HatchesState {
    s8 unlocking;
    s8 unk;
    u16 hatchesLockedWithTimer;
    u16 hatchesLockedWithEvent;
    u16 unk2;
};

struct HatchFlashingAnimation {
    u8 unlocking_delay;
    s8 unlocking_paletteRow;

    // Assumed to be left over from fusion (navigation doors)
    u8 navigation_delay;
    s8 navigation_paletteRow;
};

#define MAX_AMOUNT_OF_HATCHES 16
#define MAX_AMOUNT_OF_AREAS 8
#define MAX_AMOUNT_OF_HATCH_TYPES 8
#define MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS 41

extern u32 gHatchesOpened[MAX_AMOUNT_OF_AREAS][16];

extern u8 gWhichBGPositionIsWrittenToBG3OFS;
extern struct RawCoordsX gDoorPositionStart;
extern u8 gUseMotherShipDoors;
extern u8 gCurrentArea;
extern u8 gAreaBeforeTransition;
extern u8 gCurrentRoom;
extern u8 gLastDoorUsed;
extern u8 gLastDoorProperties;
extern u8 gDisplayLocationText;
extern s8 gDoorUnlockTimer;
extern struct HatchesState gHatchesState;
extern struct HatchData gHatchData[MAX_AMOUNT_OF_HATCHES];
extern struct LastElevatorUsed gLastElevatorUsed;
extern u8 gNumberOfValidHatchesInRoom;

extern struct HatchFlashingAnimation gHatchFlashingAnimation;

#endif