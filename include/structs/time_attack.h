#ifndef TIME_ATTACK_STRUCT_H
#define TIME_ATTACK_STRUCT_H

#include "types.h"

typedef void (*TimeAttackFunc_T)(u8*, i32);

struct TimeAttackData {
    u32 timeAttack;
    u8 igtHours;
    u8 igtMinutes;
    u8 igtSeconds;
    u8 unk_7;
    u8 unk_8;
    u8 completionPercentage;
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

#endif /* TIME_ATTACK_STRUCT_H */
