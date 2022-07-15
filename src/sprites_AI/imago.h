#ifndef IMAGO_AI_H
#define IMAGO_AI_H

#include "../types.h"

void ImagoSyncSubSprites(void);
void ImagoShootNeedles(void);
void ImagoCoreFlashingAnim(void);
void ImagoSetSidesHtibox(void);
void ImagoInit(void);
void ImagoFadeMusic(void);
void ImagoStartMusic(void);
void ImagoComingDown(void);
void ImagoComingDownMove(void);
void ImagoMove(void);
void ImagoGoingUp(void);
void ImagoAttackingGFXInit(void);
void ImagoAttackingGoingDown(void);
void ImagoAttackingGoingUp(void);
void ImagoSpawnDamagedStinger(void);
void ImagoCheckSamusAtSuperMissile(void);
void ImagoChargeThroughWall(void);
void ImagoDestroyWall(void);
void ImagoDying(void);
void ImagoSetEvent(void);
void ImagoBodySetSidesHitbox(void);
void ImagoBodyInit(void);
void ImagoBodyBeforeSpawn(void);
void ImagoBodyUpdatePalette(void);
void ImagoBodySyncPalette(void);
void Imago(void);
void ImagoBody(void);
void ImagoNeedle(void);
void ImagoDamagedStinger(void);
void ImagoEgg(void);

#endif /* IMAGO_AI_H */