#ifndef BOSS_STATUES_AI_H
#define BOSS_STATUES_AI_H

#include "types.h"

#define BOSS_STATUE_POSE_CHECK_START_OPEN 0x9
#define BOSS_STATUE_POSE_OPENING 0xB
#define BOSS_STATUE_POSE_IDLE 0xF

void BossStatueVerticalLignChangeCcaa(u8 caa);
void KraidStatueHorizontalLignThreeChangeCcaa(u8 caa);
void KraidStatueInsideChangeCcaa(u8 caa);
void KraidStatueOpenedInit(void);
void KraidStatueInit(void);
void KraidStatueCheckBackgroundLocked(void);
void KraidStatueOpening(void);
void RidleyStatueChangeThreeCcaa(u8 caa);
void RidleyStatueInsideChangeCcaa(u8 caa);
void RidleyStatueOpenedInit(void);
void RidleyStatueInit(void);
void RidleyStatueCheckBackgroundLocked(void);
void RidleyStatueOpening(void);
void KraidStatue(void);
void RidleyStatue(void);

#endif /* BOSS_STATUES_AI_H */