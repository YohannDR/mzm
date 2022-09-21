#ifndef DESSGEEGA_AI_H
#define DESSGEEGA_AI_H

#include "types.h"

#define DESSGEEGA_POSE_JUMP_WARNING_INIT 0x8
#define DESSGEEGA_POSE_JUMP_WARNING 0x9
#define DESSGEEGA_POSE_IDLE 0xF
#define DESSGEEGA_POSE_LONG_BEAM_DETECT 0x11
#define DESSGEEGA_POSE_FALLING 0x1F
#define DESSGEEGA_POSE_JUMPING 0x23
#define DESSGEEGA_POSE_LANDING 0x25
#define DESSGEEGA_POSE_LONG_BEAM_SPAWNING 0x33

u8 DessgeegaCheckSamusNearLeftRight(void);
void DessgeegaInit(void);
void DessgeegaJumpWarningInit(void);
void DessgeegaJumpingInit(void);
void DessgeegaLandingInit(void);
void DessgeegaIdleInit(void);
void DessgeegaFallingInit(void);
void DessgeegaJumpWarningGround(void);
void DessgeegaJumpWarningCeiling(void);
void DessgeegaJumpingGround(void);
void DessgeegaJumpingCeiling(void);
void DessgeegaCheckLandingAnimEnded(void);
void DessgeegaFallingGround(void);
void DessgeegaFallingCeiling(void);
void DessgeegaIdleGround(void);
void DessgeegaIdleCeiling(void);
void DessgeegaDeath(void);
void DessgeegaLongBeamDetectSamus(void);
void DessgeegaLongBeamSpawning(void);
void Dessgeega(void);

#endif /* DESSGEEGA_AI_H */