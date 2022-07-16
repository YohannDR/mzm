#ifndef METROID_AI_H
#define METROID_AI_H

#include "../types.h"

u8 MetroidCheckAirCollision(u16 yPosition, u16 xPosition);
void MetroidMove(u16 samus_y, u16 samus_x, u8 speed_y, u8 speed_x, u8 speed_divisor);
u8 MetroidBombDetection(void);
void MetroidCheckBouncingOnMetroid(u16 movement);
u8 MetroidCheckSamusGrabbed(void);
void MetroidPlaySound(void);
void MetroidInit(void);
void MetroidCheckSpawn(void);
void MetroidSpawning(void);
void MetroidSpawnedGFXInit(void);
void MetroidMovement(void);
void MetroidGrabSamusGFXInit(void);
void MetroidSamusGrabbed(void);
void MetroidDeath(void);
void Metroid(void);
void MetroidShell(void);
void MetroidDoorLock(void);

#endif /* METROID_AI_H */