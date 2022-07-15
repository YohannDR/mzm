#ifndef ZOMMER_AI_H
#define ZOMMER_AI_H

#include "../types.h"

u8 ZoomerCheckCollidingWithAir(void);
void ZoomerCollisionInit(void);
void ZoomerGFXInit(void);
void ZoomerNormalDirectionGFXInit(void);
void ZoomerInit(void);
void ZoomerCallGFXInit(void);
void ZoomerMove(void);
void ZoomerGFXRotationUpdate(void);
void ZoomerTurning(void);
void Zoomer_Unused(void);
void ZoomerBackOnGround(void);
void ZoomerStartFalling(void);
void ZoomerFalling(void);
void ZoomerDeath(void);
void Zoomer(void);

#endif   /* ZOMMER_AI_H */