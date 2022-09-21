#ifndef SOVA_AI_H
#define SOVA_AI_H

#include "types.h"

u8 SovaCheckCollidingWithAir(void);
void SovaHitboxUpdate(void);
void SovaGFXUpdate(void);
void SovaInit(void);
void SovaIdleInit(void);
void SovaMove(void);
void SovaTurningAroundGFXUpdate(void);
void SovaTurningAround(void);
void SovaBackOnGround(void);
void SovaCheckBackOnGroundAnimEnded(void);
void SovaStartFalling(void);
void SovaFalling(void);
void SovaDeath(void);
void Sova(void);

#endif /* SOVA_AI_H */