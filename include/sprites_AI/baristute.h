#ifndef BARISTUTE_AI_H
#define BARISTUTE_AI_H

#include "types.h"

#define BARISTUTE_POSE_JUMP_WARNING_INIT 0x8
#define BARISTUTE_POSE_CHECK_WARNING_ENDED 0x9
#define BARISTUTE_POSE_IDLE_INIT 0xE
#define BARISTUTE_POSE_IDLE 0xF
#define BARISTUTE_POSE_FALLING_INIT 0x1E
#define BARISTUTE_POSE_FALLING 0x1F
#define BARISTUTE_POSE_JUMPING 0x23
#define BARISTUTE_POSE_LANDING_INIT 0x24
#define BARISTUTE_POSE_LANDING 0x25
#define BARISTUTE_POSE_WALKING_INIT 0x26
#define BARISTUTE_POSE_WALKING 0x27

u8 BaristuteCheckSamusInRange(void);
void BaristuteInit(void);
void BaristuteJumpWarningInit(void);
void BaristuteCheckBeforeJumpingAnimEnded(void);
void BaristuteJumping(void);
void BaristuteLandingInit(void);
void BaristuteCheckLandingAnimNearEnded(void);
void BaristuteIdleInit(void);
void BaristuteIdle(void);
void BaristuteWalkingInit(void);
void BaristutePlayWalkingSound(void);
void BaristuteWalking(void);
void BaristuteFallingInit(void);
void BaristuteFalling(void);
void BaristuteDeath(void);
void Baristute(void);

#endif /* BARISTUTE_AI_H */