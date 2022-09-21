#ifndef GERUTA_AI_H
#define GERUTA_AI_H

#include "types.h"

#define GERUTA_POSE_IDLE_INIT 0x8
#define GERUTA_POSE_IDLE 0x9
#define GERUTA_POSE_WARNING_INIT 0x32
#define GERUTA_POSE_WARNING 0x33
#define GERUTA_POSE_LAUNCHING 0x35
#define GERUTA_POSE_GOING_DOWN 0x37
#define GERUTA_POSE_BOUNCING 0x39
#define GERUTA_POSE_GOING_UP 0x3B
#define GERUTA_POSE_BOUNCING_ON_CEILING 0x3D

u8 GerutaYMovement(u16 movement);
u8 GerutaXMovement(u16 movement);
void GerutaInit(void);
void GerutaIdleInit(void);
void GerutaDetectSamus(void);
void GerutaWarningInit(void);
void GerutaCheckWarningEnded(void);
void GerutaCheckLaunchingAnimEnded(void);
void GerutaGoingDown(void);
void GerutaCheckBouncingAnimEnded(void);
void GerutaGoingUp(void);
void GerutaCheckBouncingOnCeilingAnimEnded(void);
void Geruta(void);

#endif /* GERUTA_AI_H */