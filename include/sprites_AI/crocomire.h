#ifndef CROCOMIRE_AI_H
#define CROCOMIRE_AI_H

#include "types.h"

#define CROCOMIRE_POSE_IDLE_INIT 0x8
#define CROCOMIRE_POSE_IDLE 0x9

// Crocomire part

enum CrocomirePart {
    CROCOMIRE_PART_RIGHT_ARM,
    CROCOMIRE_PART_HEAD,
    CROCOMIRE_PART_LEGS,
    CROCOMIRE_PART_BODY,
    CROCOMIRE_PART_TONGUE,
    CROCOMIRE_PART_LEFT_ARM,

    CROCOMIRE_PART_END
};

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