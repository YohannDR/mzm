#ifndef IN_GAME_TIMER_STRUCT_H
#define IN_GAME_TIMER_STRUCT_H

#include "types.h"

#define MAX_AMOUNT_OF_IGT_AT_BOSSES 5

struct InGameTimer {
    u8 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

extern u8 gMaxInGameTimerFlag;
extern struct InGameTimer gInGameTimer;
extern struct InGameTimer gInGameTimerAtBosses[MAX_AMOUNT_OF_IGT_AT_BOSSES];
extern struct InGameTimer gBestCompletionTimes[12];

#endif