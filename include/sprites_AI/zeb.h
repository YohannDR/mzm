#ifndef ZEB_AI_H
#define ZEB_AI_H

#define ZEB_POSE_IDLE_INIT 0x8
#define ZEB_POSE_IDLE 0x9
#define ZEB_POSE_GOING_UP 0x23
#define ZEB_POSE_MOVING 0x25

void ZebInit(void);
void ZebIdleInit(void);
void ZebIdle(void);
void ZebGoingUp(void);
void ZebRespawn(void);
void ZebMove(void);
void Zeb(void);

#endif /* ZEB_AI_H */