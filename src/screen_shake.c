#include "screen_shake.h"
#include "structs/screen_shake.h"

/**
 * @brief 55344 | 34 | Starts a vertical screen shake
 * 
 * @param duration Duration
 * @param param_2 To document
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartVertical(u8 duration, u8 param_2)
{
    if (duration != 0 && duration > gScreenShakeY.timer)
    {
        gScreenShakeY.timer = duration;
        gScreenShakeY.loopCounter = 0;
        gScreenShakeY.unk_2 = param_2;
        gScreenShakeY.direction = 0;

        gScreenShakeYOffset = 0;
    }

    return gScreenShakeY.timer;
}

/**
 * @brief 55378 | 34 | Starts an horizontal screen shake
 * 
 * @param duration Duration
 * @param param_2 To document
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartHorizontal(u8 duration, u8 param_2)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0;
        gScreenShakeX.unk_2 = param_2;
        gScreenShakeX.direction = 0;

        gScreenShakeXOffset = 0;
    }

    return gScreenShakeX.timer;
}

/**
 * @brief 553ac | 30 | Starts an horizontal screen shake, unused
 * 
 * @param duration Duration
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartHorizontal_Unused(u8 duration)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0;
        gScreenShakeX.unk_2 = 0;
        gScreenShakeX.direction = 0;

        gScreenShakeXOffset = 0;
    }

    return gScreenShakeX.timer;
}

/**
 * @brief 553dc | 68 | Updates the vertical screen shake
 * 
 * @return s32 Screen offset
 */
s32 ScreenShakeUpdateVertical(void)
{
    // https://decomp.me/scratch/je2b5

    s32 offset;
    u32 unk;
    
    offset = 0;
    gScreenShakeYOffset = 0;

    if (gScreenShakeY.timer == 0)
        return 0;

    do {
    }while(0);
    gScreenShakeY.timer--;
    if (gScreenShakeY.loopCounter < 2)
    {
        gScreenShakeY.loopCounter++;
        return 0;
    }

    gScreenShakeY.loopCounter = 0;

    unk = gScreenShakeY.unk_2 & 0x7F;
    offset = -2;
    if (gScreenShakeY.direction)
    {
        if (!unk)
            offset = 0;
        else
            offset = 2;
    }

    gScreenShakeY.direction ^= TRUE;
    if (gScreenShakeY.timer < 16)
        offset >>= 1;

    gScreenShakeYOffset = offset;

    return offset;
}

/**
 * @brief 55444 | 68 | Updates the horizontal screen shake
 * 
 * @return s32 Screen offset
 */
s32 ScreenShakeUpdateHorizontal(void)
{
    // https://decomp.me/scratch/O4FYJ
    
    s32 offset;
    u32 unk;
    
    offset = 0;
    gScreenShakeXOffset = 0;

    if (gScreenShakeX.timer == 0)
        return 0;

    do {
    }while(0);
    gScreenShakeX.timer--;
    if (gScreenShakeX.loopCounter < 2)
    {
        gScreenShakeX.loopCounter++;
        return 0;
    }

    gScreenShakeX.loopCounter = 0;

    unk = gScreenShakeX.unk_2 & 0x7F;
    offset = -2;
    if (gScreenShakeX.direction)
    {
        if (!unk)
            offset = 0;
        else
            offset = 2;
    }

    gScreenShakeX.direction ^= TRUE;
    if (gScreenShakeX.timer < 16)
        offset >>= 1;

    gScreenShakeXOffset = offset;

    return offset;
}
