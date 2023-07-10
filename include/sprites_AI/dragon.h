#ifndef DRAGON_AI_H
#define DRAGON_AI_H

#include "types.h"

#define DRAGON_POSE_IDLE_INIT 0x8
#define DRAGON_POSE_IDLE 0x9
#define DRAGON_POSE_TURN_AROUND_INIT 0xA
#define DRAGON_POSE_TURN_AROUND_FIRST_HALF 0xB
#define DRAGON_POSE_TURN_AROUND_SECOND_HALF 0xC
#define DRAGON_POSE_WARNING_INIT 0x34
#define DRAGON_POSE_WARNING 0x35
#define DRAGON_POSE_SPIT 0x37

#define DRAGON_FIREBALL_POSE_MOVE 0x9
#define DRAGON_FIREBALL_POSE_EXPLODING 0x43

void DragonYMovement(void);
void DragonInit(void);
void DragonIdleInit(void);
void DragonGoUp(void);
void DragonTurningAroundInit(void);
void DragonCheckTurningAroundFirstHalfAnimEnded(void);
void DragonCheckTurningAroundSecondHalfAnimEnded(void);
void DragonWarningInit(void);
void DragonWarning(void);
void DragonSpit(void);
void DragonFireballInit(void);
void DragonFireballMove(void);
void DragonFireballExplodingInit(void);
void DragonFireballCheckExplodingAnimEnded(void);
void Dragon(void);
void DragonFireball(void);

#endif /* DRAGON_AI_H */