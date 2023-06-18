#ifndef TIME_ATTACK_STRUCT_H
#define TIME_ATTACK_STRUCT_H

#include "types.h"
#include "structs/in_game_timer.h"

typedef void (*TimeAttackFunc_T)(u8*, s32);

struct TimeAttackData {
    u32 timeAttack;
    u8 igtHours;
    u8 igtMinutes;
    u8 igtSeconds;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 igtAtBosses1;
    u8 igtAtBosses2;
    u8 rng;
    u8 password[20];
    u8 unk_24;
    u8 passwordSeed[62];
};

struct TimeAttackRecord {
    u8 password[20];
    struct InGameTimer igt;
    u8 password100[20];
    struct InGameTimer igt100;
};

extern struct TimeAttackData gTimeAttackData;
extern struct TimeAttackRecord gTimeAttackRecord;

#endif /* TIME_ATTACK_STRUCT_H */
