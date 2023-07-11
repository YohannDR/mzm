#ifndef SKREE_AI_H
#define SKREE_AI_H

#include "types.h"

#define SKREE_POSE_DETECTING_SAMUS 0x9
#define SKREE_POSE_SPINNING_INIT 0x22
#define SKREE_POSE_SPINNING 0x23
#define SKREE_POSE_GOING_DOWN_INIT 0x34
#define SKREE_POSE_GOING_DOWN 0x35
#define SKREE_POSE_CRASHING 0x37

#define SKREE_EXPLOSION_PART_GOING_UP 0x0
#define SKREE_EXPLOSION_PART_GOING_DOWN 0x1

#define SKREE_EXPLOSION_POSE_MOVING 0x9

#define SKREE_Y_RANGE (BLOCK_SIZE * 10 + PIXEL_SIZE)
#define SKREE_X_RANGE (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2)

void SkreeInit(void);
void SkreeIdleInit(void);
void SkreeDetectSamus(void);
void SkreeSpinningInit(void);
void SkreeCheckSpinAnimEnded(void);
void SkreeGoingDownInit(void);
void SkreeGoDown(void);
void SkreeCrashGround(void);
void SkreeExplosionInit(void);
void SkreeExplosionMove(void);
void Skree(void);
void SkreeExplosion(void);

#endif /* SKREE_AI_H */