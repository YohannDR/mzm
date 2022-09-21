#ifndef BOSS_STATUES_AI_H
#define BOSS_STATUES_AI_H

#include "types.h"

#define BOSS_STATUE_POSE_CHECK_START_OPEN 0x9
#define BOSS_STATUE_POSE_OPENING 0xB
#define BOSS_STATUE_POSE_IDLE 0xF

void BossStatueVerticalLignChangeCCAA(u8 caa);
void KraidStatueHorizontalLignThreeChangeCCAA(u8 caa);
void KraidStatueInsideChangeCCAA(u8 caa);
void KraidStatueOpenedInit(void);
void KraidStatueInit(void);
void KraidStatueCheckBackgroundLocked(void);
void KraidStatueOpening(void);
void RidleyStatueChangeThreeCCAA(u8 caa);
void RidleyStatueInsideChangeCCAA(u8 caa);
void RidleyStatueOpenedInit(void);
void RidleyStatueInit(void);
void RidleyStatueCheckBackgroundLocked(void);
void RidleyStatueOpening(void);
void KraidStatue(void);
void RidleyStatue(void);

#endif /* BOSS_STATUES_AI_H */