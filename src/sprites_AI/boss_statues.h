#ifndef BOSS_STATUES_AI_H
#define BOSS_STATUES_AI_H

#include "../types.h"

void BossStatueVerticalLignChangeCCAA(u8 caa);
void BossStatueHorizontalLignThreeChangeCCAA(u8 caa);
void BossStatueHorizontalLignHeightChangeCCAA(u8 caa);
void KraidStatueAfterOpen(void);
void KraidStatueInit(void);
void KraidStatueCheckBackgroundLocked(void);
void KraidStatueOpening(void);
void RidleyStatueChangeThreeCCAA(u8 caa);
void RidleyStatueChangeFourCCAA(u8 caa);
void RidleyStatueAfterOpen(void);
void RidleyStatueInit(void);
void RidleyStatueCheckBackgroundLocked(void);
void RidleyStatueOpening(void);
void KraidStatue(void);
void RidleyStatue(void);

#endif /* BOSS_STATUES_AI_H */