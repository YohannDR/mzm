#include "screen_shake.h"
#include "structs/screen_shake.h"

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

i32 ScreenShakeUpdateVertical(void)
{
    // https://decomp.me/scratch/je2b5

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

        gScreenShakeY.loopCounter = offset;

        unk = gScreenShakeY.unknown & 0x7F;
        offset = -2;
        if (gScreenShakeY.direction)
        {
            offset = 2;
            offset &= (-unk | unk) >> 0x1F;
        }

        gScreenShakeY.direction ^= TRUE;
        if (gScreenShakeY.timer < 16)
            offset >>= 1;

        gScreenShakeYOffset = offset;
    }

    return offset;
}

i32 ScreenShakeUpdateHorizontal(void)
{
    // https://decomp.me/scratch/O4FYJ

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
            offset = 2;
            offset &= (-unk | unk) >> 0x1F;
        }

        gScreenShakeX.direction ^= TRUE;
        if (gScreenShakeX.timer < 16)
            offset >>= 1;

        gScreenShakeXOffset = offset;
    }

    return offset;
}