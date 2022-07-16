#include "screen_shake.h"
#include "globals.h"

u8 ScreenShakeStartVertical(u8 duration, u8 unk)
{
    if (duration != 0x0 && duration > gScreenShakeY.timer)
    {
        gScreenShakeY.timer = duration;
        gScreenShakeY.loopCounter = 0x0;
        gScreenShakeY.unknown = unk;
        gScreenShakeY.unknown2 = 0x0;
        gScreenShakeYRelated = 0x0;
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
        gScreenShakeX.unknown2 = 0x0;
        gScreenShakeXRelated = 0x0;
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
        gScreenShakeX.unknown2 = 0x0;
        gScreenShakeXRelated = 0x0;
    }
    return gScreenShakeX.timer;
}

i32 ScreenShakeUpdateVertical(void)
{
    i32 offset;
    i32 unk;
    u8 unk2;
    u8 zero;

    zero = 0x0;
    gScreenShakeYRelated = zero;
    if (gScreenShakeY.timer == 0x0)
        return 0x0;
    else
    {
        gScreenShakeY.timer--;
        if (gScreenShakeY.loopCounter < 0x2)
        {
            gScreenShakeY.loopCounter++;
            return 0x0;
        }
        else
        {
            gScreenShakeY.loopCounter = zero;
            unk2 = gScreenShakeY.unknown & 0x7F;
            unk = -0x2;
            if (gScreenShakeY.unknown2 != 0x0)
            {
                unk = 0x2;
                unk = (-(unk2) | unk2) >> 0x1F & 0x2;
            }
            gScreenShakeY.unknown2 ^= 0x1;
            if (gScreenShakeY.timer < 0x10)
                unk >>= 0x1;
            gScreenShakeYRelated = (u8)unk;
            offset = unk;
        }
    }
    return offset;
}

i32 ScreenShakeUpdateHorizontal(void)
{
    i32 offset;
    i32 unk;
    u8 unk2;
    u8 zero;

    zero = 0x0;
    gScreenShakeXRelated = zero;
    if (gScreenShakeX.timer == 0x0)
    return 0x0;
    else
    {
        gScreenShakeX.timer--;
        if (gScreenShakeX.loopCounter < 0x2)
        {
            gScreenShakeX.loopCounter++;
            offset = 0x0;
        }
        else
        {
            gScreenShakeX.loopCounter = zero;
            unk2 = gScreenShakeX.unknown & 0x7F;
            unk = -0x2;
            if (gScreenShakeX.unknown2 != 0x0)
            {
                unk = 0x2;
                unk = (-(unk2) | unk2) >> 0x1F & unk;
            }
            gScreenShakeX.unknown2 ^= 0x1;
            if (gScreenShakeX.timer < 0x10)
                unk >>= 0x1;
            gScreenShakeXRelated = (u8)unk;
            offset = unk;
        }
    }
    return offset;
}