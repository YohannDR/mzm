#ifndef CONNECTION_H
#define CONNECTION_H

#include "types.h"
#include "event.h"
#include "music.h"

// Globals

#define MAX_AMOUNT_OF_HATCHES 16
#define MAX_AMOUNT_OF_AREAS 8
#define MAX_AMOUNT_OF_HATCH_TYPES 8
#define MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS 41

extern u32 gHatchesOpened[MAX_AMOUNT_OF_AREAS][8];

extern struct HatchesState gHatchesState;
extern struct HatchData gHatchData[MAX_AMOUNT_OF_HATCHES];
extern u8 gNumberOfValidHatchesInRoom;

// Defines

#define AREA_BRINSTAR 0x0
#define AREA_KRAID 0x1
#define AREA_NORFAIR 0x2
#define AREA_RIDLEY 0x3
#define AREA_TOURIAN 0x4
#define AREA_CRATERIA 0x5
#define AREA_CHOZODIA 0x6
#define AREA_INVALID 0x7
#define AREA_NONE 0xFF

#define DOOR_TYPE_NONE 0x0
#define DOOR_TYPE_AREA_CONNECTION 0x1
#define DOOR_TYPE_NO_HATCH 0x2
#define DOOR_TYPE_OPEN_HATCH 0x3
#define DOOR_TYPE_CLOSED_HATCH 0x4
#define DOOR_TYPE_REMOVE_MOTHER_SHIP 0x5
#define DOOR_TYPE_SET_MOTHER_SHIP 0x6
#define DOOR_TYPE_NO_FLAGS 0xF
#define DOOR_TYPE_EXISTS 0x10
#define DOOR_TYPE_LOAD_EVENT_BASED_ROOM 0x20
#define DOOR_TYPE_DISPLAYS_ROOM_LOCATION 0x40

#define HATCH_NONE 0x0
#define HATCH_UNUSED 0x1
#define HATCH_NORMAL 0x2
#define HATCH_MISSILE 0x3
#define HATCH_SUPER_MISSILE 0x4
#define HATCH_POWER_BOMB 0x5
#define HATCH_LOCKED 0x6
#define HATCH_LOCKED_AND_LOCK_DESTINATION 0x7

#define HATCH_ACTION_CHECKING_OPENED 0x0
#define HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION 0x1
#define HATCH_ACTION_SETTING_SOURCE 0x2

#define HATCH_OPENING_ACTION_NOT_OPENING 0x0
#define HATCH_OPENING_ACTION_OPENING 0x1
#define HATCH_OPENING_ACTION_LOCKED 0x2

#define HATCH_VERTICAL_SIZE 4

#define ELEVATOR_ROUTE_NONE 0x0
#define ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR 0x1
#define ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR 0x2
#define ELEVATOR_ROUTE_BRINSTAR_TO_KRAID 0x3
#define ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY 0x4
#define ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN 0x5
#define ELEVATOR_ROUTE_CRATERIA_TO_TOURIAN 0x6
#define ELEVATOR_ROUTE_CRATERIA_TO_NORFAIR 0x7

#define ELEVATOR_DIRECTION_DOWN 0x1
#define ELEVATOR_DIRECTION_UP -0x1

// Structs

struct Door {
    u8 type;
    u8 sourceRoom;
    u8 xStart;
    u8 xEnd;
    u8 yStart;
    u8 yEnd;
    u8 destinationDoor;
    i8 xExit;
    i8 yExit;
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
    u8 exists:1;
    u8 currentAnimationFrame:3;
    u8 facingRight:1;
    u8 padding:3;
    /* 1 */
    u8 opening:2;
    u8 locked:2;
    u8 flashingTimer:4;
    /* 2 */
    u8 hitTimer:4;
    u8 hits:4;
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
    i8 direction;
};

struct HatchesState {
    i8 unlocking;
    i8 unk;
    u16 hatchesLockedWithTimer;
    u16 hatchesLockedWithEvent;
    u16 unk2;
};

// Functions

void ConnectionUpdateHatches(void);
void ConnectionUpdateHatchAnimation(u8 dontSetRaw, u32 hatch);
void ConnectionHatchFlashingAnimation(u8 hatch);
void ConnectionOverrideOpenedHatch(u8 hatch, u32 type);
u8 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition);
u8 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition);
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