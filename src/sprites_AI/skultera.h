#ifndef SKULTERA_AI_H
#define SKULTERA_AI_H

#include "../types.h"

#define SKULTERA_POSE_IDLE_INIT 0x8
#define SKULTERA_POSE_IDLE 0x9
#define SKULTERA_POSE_TURNING_AROUND 0xA
#define SKULTERA_POSE_CHECK_TURNING_AROUND_ENDED 0xB
#define SKULTERA_POSE_CHASING_SAMUS_INIT 0x34
#define SKULTERA_POSE_CHASING_SAMUS 0x35

void SkulteraSetSidesHitbox(void);
u8 SkulteraXMovement(u16 movement);
void SkulteraInit(void);
void SkulteraIdleInit(void);
void SkulteraMoving(void);
void SkulteraChasingSamusInit(void);
void SkulteraChasingSamus(void);
void SkulteraTurningAroundInit(void);
void SkulteraCheckTurningAroundAnimEnded(void);
void Skultera(void);

#endif /* SKULTERA_AI_H */