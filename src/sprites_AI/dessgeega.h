#ifndef DESSGEEGA_AI_H
#define DESSGEEGA_AI_H

#include "../types.h"

u8 DessgeegaCheckSamusNearLeftRight(void);
void DessgeegaInit(void);
void DessgeegaJumpingGFXInit(void);
void DessgeegaBeforeJumping(void);
void DessgeegaBeforeLanding(void);
void DessgeegaCheckSamusInRange(void);
void DessgeegaBouncingGFXInit(void);
void DessgeegaCheckBouncing(void);
void DessgeegaCheckBeforeJumpingCeilingAnimEnded(void);
void DessgeegaMoveGround(void);
void DessgeegaMoveCeiling(void);
void DessgeegaCheckLandingAnimEnded(void);
void DessgeegaJumpingGroundIntoBlock(void);
void DessgeegaJumpingCeilingIntoBlock(void);
void DessgeegaGroundIdleAnim(void);
void DessgeegaCeilingdleAnim(void);
void DessgeegaDeath(void);
void DessgeegaLongBeamDetectSamus(void);
void DessgeegaLongBeamSpawning(void);
void Dessgeega(void);

#endif /* DESSGEEGA_AI_H */