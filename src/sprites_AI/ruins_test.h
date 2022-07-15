#ifndef RUINS_TEST_AI_H
#define RUINS_TEST_AI_H

#include "../types.h"

void RuinsTestCalculateDelay(u8 delay);
void RuinsTestChangeCCAA(u8 action);
void RuinsTestMoveToPosition(u16 yTarget, u16 xTarget, u16 yPosition, u16 xPosition, u8 speedMultiplier, u8 speed);
u8 RuinsTestProjectileCollision(void);
void unk_38d28(void);
void unk_38d70(void);
u8 RuinsTestCheckSamusHurting(void);
void unk_38e28(void);
void RuinsTestGhostMove(u8 rng);
void RuinsTestInit(void);
void RuinsTestSpawningAnim(void);
void RuinsTestSpawnReflectionStart(void);
void unk_39194(void);
void RuinsTestCheckSamusNotFacingBackground(void);
void unk_391f0(void);
void RuinsTestSpawnGhost(void);
void RuinsTestAfterGhostSpawn(void);
void RuinsTestGhostMaybeMoveSecondPhase(void);
void RuinsTestMaybeMoveSecondPhase(void);
void RuinsTestMoveGhostToCenter(void);
void RuinsTestCheckAllSymbolsInPlace(void);
void RuinsTestReflectionEnd(void);
void RuinsTestGhostInit(void);
void RuinsTestGhostSpawn(void);
void RuinsTestGhostSyncPosition(void);
void RuinsTestGhostDespawn(void);
void unk_39a40(void);
void RuinsTestGhostAfterFirstSymbol(void);
void RuinsTestGhostAfterFight(void);
void unk_39e14(void);
void unk_39e3c(void);
void RuinsTest(void);
void RuinsTestSymbol(void);
void RuinsTestSamusReflectionStart(void);
void RuinsTestReflectionCover(void);
void RuinsTestGhostOutline(void);
void RuinsTestShootableSymbol(void);
void RuinsTestGhost(void);
void RuinsTestSamusReflectionEnd(void);
void RuinsTestLightningInit(void);
void RuinsTestLightning(void);

#endif /* RUINS_TEST_AI_H */