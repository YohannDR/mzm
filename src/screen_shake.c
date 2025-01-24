#include "screen_shake.h"
#include "macros.h"

#include "structs/screen_shake.h"

/**
 * @brief 55344 | 34 | Starts a vertical screen shake
 * 
 * @param duration Duration
 * @param intensity 
 * @return u8 Screen shake Y timer
 */
u8 ScreenShakeStartVertical(u8 duration, u8 intensity)
{
    if (duration != 0 && duration > gScreenShakeY.timer)
    {
        gScreenShakeY.timer = duration;
        gScreenShakeY.delay = 0;
        gScreenShakeY.intensity = intensity;
        gScreenShakeY.direction = 0;

        gScreenShakeYOffset = 0;
    }

    return gScreenShakeY.timer;
}

/**
 * @brief 55378 | 34 | Starts an horizontal screen shake
 * 
 * @param duration Duration
 * @param intensity To document
 * @return u8 Screen shake X timer
 */
u8 ScreenShakeStartHorizontal(u8 duration, u8 intensity)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.delay = 0;
        gScreenShakeX.intensity = intensity;
        gScreenShakeX.direction = 0;

        gScreenShakeXOffset = 0;
    }

    return gScreenShakeX.timer;
}

/**
 * @brief 553ac | 30 | Starts an horizontal screen shake, unused
 * 
 * @param duration Duration
 * @return u8 Screen shake X timer
 */
u8 ScreenShakeStartHorizontal_Unused(u8 duration)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.delay = 0;
        gScreenShakeX.intensity = 0;
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
    s32 offset;
    u32 intensity;
    
    offset = 0;
    gScreenShakeYOffset = 0;

    if (gScreenShakeY.timer == 0)
        return 0;

    APPLY_DELTA_TIME_DEC(gScreenShakeY.timer);
    if (gScreenShakeY.delay < 2 * DELTA_TIME)
    {
        gScreenShakeY.delay++;
        return 0;
    }

    gScreenShakeY.delay = 0;

    intensity = gScreenShakeY.intensity & 0x7F;
    offset = 2 * SHAKE_UP;
    if (gScreenShakeY.direction)
    {
        if (intensity == 0)
            offset = 0;
        else
            offset = 2 * SHAKE_DOWN;
    }

    EMPTY_DO_WHILE

    gScreenShakeY.direction ^= SWITCH_DIRECTION;
    if (gScreenShakeY.timer <= CONVERT_SECONDS(1.f / 4))
        offset = DIV_SHIFT(offset, 2);

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
    s32 offset;
    u32 intensity;
    
    offset = 0;
    gScreenShakeXOffset = 0;

    if (gScreenShakeX.timer == 0)
        return 0;

    APPLY_DELTA_TIME_DEC(gScreenShakeX.timer);
    if (gScreenShakeX.delay < 2 * DELTA_TIME)
    {
        gScreenShakeX.delay++;
        return 0;
    }

    gScreenShakeX.delay = 0;

    intensity = gScreenShakeX.intensity & 0x7F;
    offset = 2 * SHAKE_LEFT;
    if (gScreenShakeX.direction)
    {
        if (intensity == 0)
            offset = 0;
        else
            offset = 2 * SHAKE_RIGHT;
    }

    EMPTY_DO_WHILE

    gScreenShakeX.direction ^= SWITCH_DIRECTION;
    if (gScreenShakeX.timer <= CONVERT_SECONDS(1.f / 4))
        offset = DIV_SHIFT(offset, 2);

    gScreenShakeXOffset = offset;

    return offset;
}
