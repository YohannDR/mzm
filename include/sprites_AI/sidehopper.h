#ifndef SIDEHOPPER_AI_H
#define SIDEHOPPER_AI_H

#include "types.h"

#define SIDEHOPPER_POSE_JUMP_WARNING_INIT 0x8
#define SIDEHOPPER_POSE_JUMP_WARNING 0x9
#define SIDEHOPPER_POSE_IDLE 0xF
#define SIDEHOPPER_POSE_FALLING 0x1F
#define SIDEHOPPER_POSE_JUMPING 0x23
#define SIDEHOPPER_POSE_LANDING 0x25

u8 SidehopperCheckSamusNearLeftRight(void);
void SidehopperInit(void);
void SidehopperJumpWarningInit(void);
void SidehopperJumpingInit(void);
void SidehopperLandingInit(void);
void SidehopperIdleInit(void);
void SidehopperFallingInit(void);
void SidehopperJumpWarningGround(void);
void SidehopperJumpWarningCeiling(void);
void SidehopperJumpingGround(void);
void SidehopperJumpingCeiling(void);
void SidehopperCheckLandingAnimEnded(void);
void SidehopperFallingGround(void);
void SidehopperFallingCeiling(void);
void SidehopperIdleGround(void);
void SidehopperIdleCeiling(void);
void SidehopperDeath(void);
void Sidehopper(void);

#endif /* SIDEHOPPER_AI_H */