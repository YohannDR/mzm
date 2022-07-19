#ifndef SKREE_AI_H
#define SKREE_AI_H

#include "../types.h"

#define SKREE_POSE_DETECTING_SAMUS 0x9
#define SKREE_POSE_SPINNING_INIT 0x22
#define SKREE_POSE_SPINNING 0x23
#define SKREE_POSE_GOING_DOWN_INIT 0x34
#define SKREE_POSE_GOING_DOWN 0x35
#define SKREE_POSE_CRASHING 0x37

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