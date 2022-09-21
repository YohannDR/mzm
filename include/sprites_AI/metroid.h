#ifndef METROID_AI_H
#define METROID_AI_H

#include "types.h"

#define METROID_POSE_CHECK_SPAWN 0x1
#define METROID_POSE_SPAWNING 0x2
#define METROID_POSE_MOVING_INIT 0x8
#define METROID_POSE_MOVING 0x9
#define METROID_POSE_GRAB_SAMUS_INIT 0x42
#define METROID_POSE_SAMUS_GRABBED 0x43
#define METROID_POSE_DEATH 0x62

u8 MetroidCheckAirCollision(u16 yPosition, u16 xPosition);
void MetroidMove(u16 samusY, u16 samusX, u8 speedY, u8 speedX, u8 speedDivisor);
u8 MetroidBombDetection(void);
void MetroidCheckBouncingOnMetroid(u16 movement);
u8 MetroidCheckSamusGrabbed(void);
void MetroidPlaySound(void);
void MetroidInit(void);
void MetroidCheckSpawn(void);
void MetroidSpawning(void);
void MetroidMovingInit(void);
void MetroidMovement(void);
void MetroidSamusGrabbedInit(void);
void MetroidSamusGrabbed(void);
void MetroidDeath(void);
void Metroid(void);
void MetroidShell(void);
void MetroidDoorLock(void);

#endif /* METROID_AI_H */