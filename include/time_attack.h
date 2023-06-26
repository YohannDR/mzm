#ifndef TIME_ATTACK_H
#define TIME_ATTACK_H

#include "types.h"
#include "structs/time_attack.h"

void TimeAttackEORSeed(u8* pSeed, s32 length, u8 value);
u32 TimeAttackGetGarbledSeedValue(u8* pSeed, s32 value);
void TimeAttackGarbleSeedValue(u8* pSeed, s32 value1, s32 value2);
void TimeAttackGarbleRandomSeedValues(u8* pSeed, s32 value1, s32 value2);
void TimeAttackSeedRandomFunc1(u8* pSeed, s32 length);
void TimeAttackSeedRandomFunc2(u8* pSeed, s32 length);
void TimeAttackSeedRandomFunc3(u8* pSeed, s32 length);
void TimeAttackSeedRandomFunc4(u8* pSeed, s32 length);
void TimeAttackSeedRandomFunc5(u8* pSeed, s32 length);
void TimeAttackGeneratePassword(u8* pSeed, u8* pPassword, s32 length);
u8 TimeAttackCheckSaveFileValidity(void);
void CheckUnlockTimeAttack(void);
u8 unk_7f60c(u8* param_1);
void TimeAttackSeedShuffleFunc1(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc2(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc3(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc4(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc5(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc6(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc7(u8* pSeed, s32 length);
void TimeAttackSeedShuffleFunc8(u8* pSeed, s32 length);
void TimeAttackRandomizeSeed(u8* pSeed, u32 rng);
u8 TimeAttackGenerateSeed(struct TimeAttackData* pTimeAttack);
u8 TimeAttackCheckSetNewRecord(void);

#endif /* TIME_ATTACK_H */
