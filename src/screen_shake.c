#include "screen_shake.h"
#include "structs/screen_shake.h"

/**
 * @brief 55344 | 34 | Starts a vertical screen shake
 * 
 * @param duration Duration
 * @param unk Unknown
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartVertical(u8 duration, u8 unk)
{
    if (duration != 0x0 && duration > gScreenShakeY.timer)
    {
        gScreenShakeY.timer = duration;
        gScreenShakeY.loopCounter = 0x0;
        gScreenShakeY.unknown = unk;
        gScreenShakeY.direction = 0x0;
        gScreenShakeYOffset = 0x0;
    }
    return gScreenShakeY.timer;
}

/**
 * @brief 55378 | 34 | Starts an horizontal screen shake
 * 
 * @param duration Duration
 * @param unk Unknown
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartHorizontal(u8 duration, u8 unk)
{
    if (duration != 0x0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0x0;
        gScreenShakeX.unknown = unk;
        gScreenShakeX.direction = 0x0;
        gScreenShakeXOffset = 0x0;
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
    if (duration != 0x0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0x0;
        gScreenShakeX.unknown = 0x0;
        gScreenShakeX.direction = 0x0;
        gScreenShakeXOffset = 0x0;
    }
    return gScreenShakeX.timer;
}

/**
 * @brief 553dc | 68 | Updates the vertical screen shake
 * 
 * @return i32 Screen offset
 */
i32 ScreenShakeUpdateVertical(void)
{
    i32 offset;
    i32 unk;

    offset = 0;
    gScreenShakeYOffset = offset;

    if (gScreenShakeY.timer == 0)
        return offset;
    else
    {
        gScreenShakeY.timer--;
        if (gScreenShakeY.loopCounter < 2)
        {
            gScreenShakeY.loopCounter++;
            return offset;
        }

        gScreenShakeY.loopCounter = 0;

        unk = gScreenShakeY.unknown & 0x7F;
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
    }

    return offset;
}

/**
 * @brief 55444 | 68 | Updates the horizontal screen shake
 * 
 * @return i32 Screen offset
 */
i32 ScreenShakeUpdateHorizontal(void)
{
    i32 offset;
    i32 unk;

    offset = 0;
    gScreenShakeXOffset = offset;

    if (gScreenShakeX.timer == 0)
        return offset;
    else
    {
        gScreenShakeX.timer--;
        if (gScreenShakeX.loopCounter < 2)
        {
            gScreenShakeX.loopCounter++;
            return offset;
        }

        gScreenShakeX.loopCounter = 0;

        unk = gScreenShakeX.unknown & 0x7F;
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
    }

    return offset;
}