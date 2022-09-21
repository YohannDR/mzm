#ifndef HOLTZ_AI_H
#define HOLTZ_AI_H

#include "types.h"

#define HOLTZ_POSE_IDLE_INIT 0x8
#define HOLTZ_POSE_IDLE 0x9
#define HOLTZ_POSE_WARNING_INIT 0x32
#define HOLTZ_POSE_WARNING 0x33
#define HOLTZ_POSE_GOING_DOWN 0x35
#define HOLTZ_POSE_SLIDING 0x37
#define HOLTZ_POSE_GOING_UP 0x39
#define HOLTZ_POSE_BACK_TO_CEILING 0x3B

#define HOLTZ_SIZE 0x28

u8 HoltzYMovement(u16 movement);
u8 HoltzXMovement(u16 movement);
void HoltzInit(void);
void HoltzIdleInit(void);
void HoltzIdle(void);
void HoltzWarningInit(void);
void HoltzCheckWarningAnimEnded(void);
void HoltzGoingDownMove(void);
void HoltzSlidingMove(void);
void HoltzGoingUpMove(void);
void HoltzBackToCeiling(void);
void Holtz(void);

#endif /* HOLTZ_AI_H */