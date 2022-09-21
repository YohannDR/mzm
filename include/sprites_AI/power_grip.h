#ifndef POWER_GRIP_AI_H
#define POWER_GRIP_AI_H

#include "types.h"

#define POWER_GRIP_POSE_IDLE 0x9
#define POWER_GRIP_POSE_BEING_ACQUIRED 0x23

void PowerGrip(void);
void PowerGripGlow(void);

#endif /* POWER_GRIP_AI_H */