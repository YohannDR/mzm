#ifndef CONNECTION_H
#define CONNECTION_H

#include "types.h"
#include "event.h"
#include "music.h"

// Globals


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

#define DOOR_NONE 0x0
#define DOOR_AREA_CONNECTION 0x1
#define DOOR_NO_HATCH 0x2
#define DOOR_OPEN_HATCH 0x3
#define DOOR_CLOSED_HATCH 0x4
#define DOOR_REMOVE_MOTHER_SHIP 0x5
#define DOOR_SET_MOTHER_SHIP 0x6
#define DOOR_LOAD_EVENT_BASED_ROOM 0x20
#define DOOR_DISPLAYS_ROOM_LOCATION 0x40

#define HATCH_NONE 0x0
#define HATCH_UNUSED 0x1
#define HATCH_NORMAL 0x2
#define HATCH_MISSILE 0x3
#define HATCH_SUPER_MISSILE 0x4
#define HATCH_POWER_BOMB 0x5
#define HATCH_LOCKED 0x7
#define HATCH_LOCKED_AND_LOCK_DESTINATION 0x7

#define HATCH_ACTION_CHECKING_OPENED 0x0
#define HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION 0x1
#define HATCH_ACTION_SETTING_SOURCE 0x2

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
    u8 destinationRoom;
    i8 xExit;
    i8 yyExit;
};

struct __attribute__((packed)) AreaConnection {
    u8 sourceArea;
    u8 sourceDoor;
    u8 destinationArea;
};

struct EventBasedConnection {
    u8 sourceArea;
    u8 sourceDoor;
    u8 event;
    u8 destinationRoom;
};

struct HatchLockEvent {
    u8 destinationRoom;
    u8 event;
    u8 isBefore;
    u8 hatchesToLock;
    u8 unknown;
};

struct HatchData {
    u8 direction;
    u8 status;
    u8 hits;
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

// Functions

void ConnectionUpdateOpeningClosingHatches(void);
void ConnectionUpdateHatchAnimation(u8 dontSetRaw, u8 hatch);
void ConnectionHatchFlashingAnimation(u8 hatch);
void ConnectionOverrideOpenedHatch(u8 hatch, u8 type);
u8 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition);
u8 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition);
void ConnectionProcessDoorType(u8 type);
u8 ConnectionFindEventBasedDoor(u8 sourceDoor);
u8 ConnectionSetHatchAsOpened(u8 action, u8 hatch);
void ConnectionCheckUnlockDoors(void);
void ConnectionStartLockAnimation(u8 dontSetRaw, u8 hatch, u8 status);
void ConnectionLockHatches(u8 isEvent);
void ConnectionLoadDoors(void);
void ConnectionLockHatchesWithTimer(void);
void ConnectionCheckHatchLockEvents(void);
void ConnectionCheckPlayCutsceneDuringTransition(u8 area, u8 dstRoomPlusOne);
void ConnectionCheckPlayCutsceneDuringElevator(void);

#endif /* CONNECTION_H */