#ifndef CROCOMIRE_AI_H
#define CROCOMIRE_AI_H

#include "types.h"

#define CROCOMIRE_POSE_IDLE_INIT 0x8
#define CROCOMIRE_POSE_IDLE 0x9

// Crocomire part

#define CROCOMIRE_PART_RIGHT_ARM 0x0
#define CROCOMIRE_PART_HEAD 0x1
#define CROCOMIRE_PART_LEGS 0x2
#define CROCOMIRE_PART_BODY 0x3
#define CROCOMIRE_PART_TONGUE 0x4
#define CROCOMIRE_PART_LEFT_ARM 0x5

#define CROCOMIRE_PART_POSE_IDLE 0x9
#define CROCOMIRE_PART_POSE_DYING 0x67

void CrocomireSyncSubSprites(void);
void CrocomireInit(void);
void CrocomireIdleInit(void);
void Crocomire_Empty(void);
void CrocomirePartInit(void);
void Crocomire(void);
void CrocomirePart(void);

#endif /* CROCOMIRE_AI_H */