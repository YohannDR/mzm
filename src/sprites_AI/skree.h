#ifndef SKREE_AI_H
#define SKREE_AI_H

#include "../types.h"

void SkreeInit(void);
void SkreeGFXInit(void);
void SkreeDetectSamus(void);
void SkreeSpinGFXInit(void);
void SkreeCheckSpinAnimEnded(void);
void SkreeStartGoingDown(void);
void SkreeGoDown(void);
void SkreeCrashGround(void);
void SkreeExplosionInit(void);
void SkreeExplosionMove(void);
void Skree(void);
void SkreeExplosion(void);

#endif /* SKREE_AI_H */