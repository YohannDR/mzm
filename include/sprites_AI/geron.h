#ifndef GERON_AI_H
#define GERON_AI_H

#include "types.h"

#define GERON_POSE_IDLE 0x9
#define GERON_POSE_GETTING_DESTROYED 0x23
#define GERON_POSE_DELAY_BEFORE_DESTROYED 0x25
#define GERON_POSE_DESTROYED 0x61

void Geron(void);

#endif /* GERON_AI_H */