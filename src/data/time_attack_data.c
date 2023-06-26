#include "data/time_attack_data.h"
#include "time_attack.h"

const TimeAttackFunc_T sTimeAttackSeedShuffleFunctionPointers[16] = {
    [0]  = TimeAttackSeedShuffleFunc1,
    [1]  = TimeAttackSeedShuffleFunc2,
    [2]  = TimeAttackSeedShuffleFunc3,
    [3]  = TimeAttackSeedShuffleFunc4,
    [4]  = TimeAttackSeedShuffleFunc5,
    [5]  = TimeAttackSeedShuffleFunc6,
    [6]  = TimeAttackSeedShuffleFunc7,
    [7]  = TimeAttackSeedShuffleFunc8,
    [8]  = TimeAttackSeedShuffleFunc1,
    [9]  = TimeAttackSeedShuffleFunc2,
    [10] = TimeAttackSeedShuffleFunc3,
    [11] = TimeAttackSeedShuffleFunc4,
    [12] = TimeAttackSeedShuffleFunc5,
    [13] = TimeAttackSeedShuffleFunc6,
    [14] = TimeAttackSeedShuffleFunc7,
    [15] = TimeAttackSeedShuffleFunc8
};
