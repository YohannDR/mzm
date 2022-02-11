#include "screen_shake.h"
#include "globals.h"

u8 screen_shake_start_vertical(u8 duration, u8 unk)
{
    if (duration != 0x0 && duration > screen_shake_y.timer)
    {
        screen_shake_y.timer = duration;
        screen_shake_y.loop_counter = 0x0;
        screen_shake_y.unknown = unk;
        screen_shake_y.unknown2 = 0x0;
        screen_shake_y_related = 0x0;
    }
    return screen_shake_y.timer;
}

u8 screen_shake_start_horizontal(u8 duration, u8 unk)
{
    if (duration != 0x0 && duration > screen_shake_x.timer)
    {
        screen_shake_x.timer = duration;
        screen_shake_x.loop_counter = 0x0;
        screen_shake_x.unknown = unk;
        screen_shake_x.unknown2 = 0x0;
        screen_shake_x_related = 0x0;
    }
    return screen_shake_x.timer;
}

u8 screen_shake_start_horizontal_unused(u8 duration)
{
    if (duration != 0x0 && duration > screen_shake_x.timer)
    {
        screen_shake_x.timer = duration;
        screen_shake_x.loop_counter = 0x0;
        screen_shake_x.unknown = 0x0;
        screen_shake_x.unknown2 = 0x0;
        screen_shake_x_related = 0x0;
    }
    return screen_shake_x.timer;
}

i32 screen_shake_update_vertical(void)
{
    i32 offset;
    i32 unk;
    u8 unk2;
    u8 zero;

    zero = 0x0;
    screen_shake_y_related = zero;
    if (screen_shake_y.timer == 0x0)
        return 0x0;
    else
    {
        screen_shake_y.timer--;
        if (screen_shake_y.loop_counter < 0x2)
        {
            screen_shake_y.loop_counter++;
            return 0x0;
        }
        else
        {
            screen_shake_y.loop_counter = zero;
            unk2 = screen_shake_y.unknown & 0x7F;
            unk = -0x2;
            if (screen_shake_y.unknown2 != 0x0)
            {
                unk = 0x2;
                unk = (-(unk2) | unk2) >> 0x1F & 0x2;
            }
            screen_shake_y.unknown2 ^= 0x1;
            if (screen_shake_y.timer < 0x10)
                unk >>= 0x1;
            screen_shake_y_related = (u8)unk;
            offset = unk;
        }
    }
    return offset;
}

i32 screen_shake_update_horizontal(void)
{
    i32 offset;
    i32 unk;
    u8 unk2;
    u8 zero;

    zero = 0x0;
    screen_shake_x_related = zero;
    if (screen_shake_x.timer == 0x0) return 0x0;
    else
    {
        screen_shake_x.timer--;
        if (screen_shake_x.loop_counter < 0x2)
        {
            screen_shake_x.loop_counter++;
            offset = 0x0;
        }
        else
        {
            screen_shake_x.loop_counter = zero;
            unk2 = screen_shake_x.unknown & 0x7F;
            unk = -0x2;
            if (screen_shake_x.unknown2 != 0x0)
            {
                unk = 0x2;
                unk = (-(unk2) | unk2) >> 0x1F & unk;
            }
            screen_shake_x.unknown2 ^= 0x1;
            if (screen_shake_x.timer < 0x10)
                unk >>= 0x1;
            screen_shake_x_related = (u8)unk;
            offset = unk;
        }
    }
    return offset;
}