#include "time_attack.h"

#include "data/intro_data.h"
#include "data/time_attack_data.h"

#include "structs/in_game_timer.h"

/**
 * @brief 7f120 | 28 | Performs an exclusive or on all the values of the seed with the value param
 * 
 * @param pSeed Seed pointer
 * @param length Length of seed
 * @param value Value to eor with
 */
void TimeAttackEORSeed(u8* pSeed, i32 length, u8 value)
{
    i32 i;

    for (i = 0; i < length; i++)
        pSeed[i] ^= value;
}

/**
 * @brief 7f148 | 24 | Gets a garbled value from the seed
 * 
 * @param pSeed Seed pointer
 * @param value Reference value
 * @return u8 Seed value
 */
u8 TimeAttackGetGarbledSeedValue(u8* pSeed, i32 value)
{
    u32 shift;
    i32 local = value / 8;

    shift = (value - (local << 3));

    return (u8)(pSeed[local] << shift) >> 7;
}

/**
 * @brief 7f16c | 38 | Garbles a seed value
 * 
 * @param pSeed Seed pointer
 * @param value1 Random value
 * @param value2 Reference value
 */
void TimeAttackGarbleSeedValue(u8* pSeed, i32 value1, i32 value2)
{
    i32 local;
    u8 bicFlag;
    u32 orrFlag;
    u32 shift;

    bicFlag = 1;
    orrFlag = value2 & 1;
    local = value1 / 8;

    shift = 7 - (value1 - (local << 3));

    orrFlag <<= shift;
    bicFlag <<= shift;

    pSeed[local] = (pSeed[local] & ~bicFlag) | orrFlag;
}

/**
 * @brief 7f1a4 | 38 | Garbles 2 seed values
 * 
 * @param pSeed Seed pointer
 * @param value1 Reference value 1
 * @param value2 Reference value 2
 */
void TimeAttackGarbleRandomSeedValues(u8* pSeed, i32 value1, i32 value2)
{
    u32 ref1;
    u32 ref2;

    ref1 = TimeAttackGetGarbledSeedValue(pSeed, value1);
    ref2 = TimeAttackGetGarbledSeedValue(pSeed, value2);
    TimeAttackGarbleSeedValue(pSeed, value1, ref2);
    TimeAttackGarbleSeedValue(pSeed, value2, ref1);
}

/**
 * @brief 7f1dc | 24 | Function that randomizes the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedRandomFunc1(u8* pSeed, i32 length)
{
    i32 i;
    i32 limit;

    limit = length * 4;
    for (i = 0; i < limit; i += 2)
        TimeAttackGarbleRandomSeedValues(pSeed, i, i + limit);
}

/**
 * @brief 7f200 | 38 | Function that randomizes the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedRandomFunc2(u8* pSeed, i32 length)
{
    i32 i;
    i32 limit;
    i32 value;

    limit = length * 4;
    value = length * 8 - 1;
    for (i = 0; i < limit; )
    {
        TimeAttackGarbleRandomSeedValues(pSeed, i, value);
        i++;
        value--;
    }
}

/**
 * @brief 7f228 | 30 | Function that randomizes the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedRandomFunc3(u8* pSeed, i32 length)
{
    i32 i;
    i32 limit;
    i32 value;

    limit = length * 8 / 9;
    value = limit;
    for (i = 0; i < limit; )
    {
        TimeAttackGarbleRandomSeedValues(pSeed, i, value);
        i++;
        value += 8;
    }
}

/**
 * @brief 7f258 | 28 | Function that randomizes the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedRandomFunc4(u8* pSeed, i32 length)
{
    i32 i;
    i32 value;

    value = length;
    for (i = 0; i < length; )
    {
        TimeAttackGarbleRandomSeedValues(pSeed, i, value);
        i++;
        value += 7;
    }
}

/**
 * @brief 7f280 | 30 | Function that randomizes the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedRandomFunc5(u8* pSeed, i32 length)
{
    i32 i;
    i32 limit;
    i32 value;

    limit = length * 8 / 6;
    value = limit;
    for (i = 0; i < limit; )
    {
        TimeAttackGarbleRandomSeedValues(pSeed, i, value);
        i++;
        value += 5;
    }
}

/**
 * @brief 7f2b0 | c0 | Generates a time attack password from a seed
 * 
 * @param pSeed Seed pointer
 * @param pPassword Password pointer (destination)
 * @param length Password length
 */
void TimeAttackGeneratePassword(u8* pSeed, u8* pPassword, i32 length)
{
    u32 input1;
    u32 input2;
    u32 input3;
    u32 input4;
    u32 input5;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value5;
    i32 i;

    if (length > 0)
    {
        input1 = 4;
        input2 = 3;
        input3 = 2;
        input4 = 1;
        input5 = 0;

        for (i = length; i != 0; i--)
        {
            value1 = TimeAttackGetGarbledSeedValue(pSeed, input5);
            value2 = TimeAttackGetGarbledSeedValue(pSeed, input4);
            value3 = TimeAttackGetGarbledSeedValue(pSeed, input3);
            value4 = TimeAttackGetGarbledSeedValue(pSeed, input2);
            value5 = TimeAttackGetGarbledSeedValue(pSeed, input1);

            *pPassword++ = sTimeAttackPasswordCharacters[value1 << 4 | value2 << 3 | value3 << 2 | value4 << 1 | value5];

            input1 += 5;
            input2 += 5;
            input3 += 5;
            input4 += 5;
            input5 += 5;
        }
    }

    *pPassword = 0;
}

/**
 * @brief 7f370 | 210 | Checks the validity of the current save file
 * 
 * @return u8 bool, valid
 */
u8 TimeAttackCheckSaveFileValidity(void)
{
    u32 convertedIgt[MAX_AMOUNT_OF_IGT_AT_BOSSES - 1];
    u8 i;
    u8 j;

    // Concatenate in game timer struct to an u32
    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES - 1; i++)
    {
        convertedIgt[i] = (gInGameTimerAtBosses[i].hours << 24) + (gInGameTimerAtBosses[i].minutes << 16) +
            (gInGameTimerAtBosses[i].seconds << 8) + gInGameTimerAtBosses[i].frames;
    }

    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES - 1; i++)
    {
        // Check beat every boss in order
        for (j = i + 1; j < MAX_AMOUNT_OF_IGT_AT_BOSSES - 1; j++)
        {
            if (convertedIgt[i] >= convertedIgt[j])
                return FALSE;
        }

        // Check is below anti cheat times
        if (convertedIgt[i] <= sTimeAttackAntiCheatTimes[i])
            return FALSE;
    }

    return TRUE;
}

void CheckUnlockTimeAttack(void)
{

}

u8 unk_7f60c(u8* param_1)
{

}

/**
 * @brief 7f694 | 44 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc1(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 70);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 73);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackSeedRandomFunc5(pSeed, length);
}

/**
 * @brief 7f6d8 | 44 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc2(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 144);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 94);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
}

/**
 * @brief 7f71c | 44 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc3(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 145);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 227);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
}

/**
 * @brief 7f760 | 50 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc4(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 89);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 99);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 57);
}

/**
 * @brief 7f7b0 | 44 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc5(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 149);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 252);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackSeedRandomFunc5(pSeed, length);
}

/**
 * @brief 7f7f4 | 50 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc6(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 77);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 74);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 83);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
}

/**
 * @brief 7f844 | 58 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc7(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 65);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 89);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 79);
    TimeAttackSeedRandomFunc1(pSeed, length);
}

/**
 * @brief 7f89c | 60 | Function that shuffles the seed
 * 
 * @param pSeed Seed pointer
 * @param length Seed length
 */
void TimeAttackSeedShuffleFunc8(u8* pSeed, i32 length)
{
    TimeAttackEORSeed(pSeed, length, 84);
    TimeAttackSeedRandomFunc3(pSeed, length);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackSeedRandomFunc5(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 79);
    TimeAttackSeedRandomFunc1(pSeed, length);
    TimeAttackSeedRandomFunc2(pSeed, length);
    TimeAttackEORSeed(pSeed, length, 77);
    TimeAttackSeedRandomFunc4(pSeed, length);
    TimeAttackSeedRandomFunc5(pSeed, length);
}

/**
 * @brief 7f8fc | 84 | Randomizes some values of the seed
 * 
 * @param pSeed Seed pointer
 * @param rng Rng
 */
void TimeAttackRandomizeSeed(u8* pSeed, u32 rng)
{
    u8 value0;
    u8 value4;
    u8 value8;
    u8 value10;
    u32 addedValue;

    pSeed[12] = pSeed[0] & 0x80 | (pSeed[4] & 0x40) | (pSeed[8] & 0x20) | (pSeed[10] & 0x10);

    value0 = pSeed[0] & 0x7F;
    value4 = pSeed[4] & 0xBF;
    value8 = pSeed[8] & 0xDF;
    value10 = pSeed[10] & 0xEF;

    addedValue = rng * 16;

    pSeed[0] = value0 | (addedValue & 0x80);
    pSeed[4] = value4 | (addedValue & 0x40);
    pSeed[8] = value8 | (addedValue & 0x20);
    pSeed[10] = value10 | (addedValue & 0x10);
}

u8 TimeAttackGenerateSeed(struct TimeAttackData* pTimeAttack)
{
    // https://decomp.me/scratch/D8huk

    u8 seed[16];
    u8 rng;
    i32 i;
    i32 seedOffset;
    u32 mask;
    u32 value;

    seedOffset = 0;
    mask = 1;

    for (i = 32; i > 0; i--)
    {
        if (pTimeAttack->timeAttack & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }
    
    mask = 1;
    for (i = 6; i > 0; i--)
    {
        if (pTimeAttack->igtHours & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }
    
    mask = 1;
    for (i = 5; i > 0; i--)
    {
        if (pTimeAttack->igtMinutes & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }
    
    mask = 1;
    for (i = 5; i > 0; i--)
    {
        if (pTimeAttack->igtSeconds & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }
    
    mask = 1;
    for (i = 5; i > 0; i--)
    {
        if (pTimeAttack->unk_7 & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }

    mask = 1;
    for (i = 4; i > 0; i--)
    {
        if (pTimeAttack->unk_8 & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }

    mask = 1;
    for (i = 3; i > 0; i--)
    {
        if (pTimeAttack->completionPercentage & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }

    mask = 1;
    for (i = 3; i > 0; i--)
    {
        if (pTimeAttack->unk_A & mask)
            value = TRUE;
        else
            value = FALSE;

        pTimeAttack->passwordSeed[seedOffset] = value;
        mask <<= 1;
        seedOffset++;
    }

    sTimeAttackSeedShuffleFunctionPointers[rng](seed, 12);
    TimeAttackRandomizeSeed(seed, pTimeAttack->rng);
    TimeAttackGeneratePassword(seed, pTimeAttack->password, sizeof(pTimeAttack->password));

    return FALSE;
}

u8 TimeAttackCheckSetNewRecord(void)
{

}
