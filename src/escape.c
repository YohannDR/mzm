#include "escape.h"
#include "event.h"
#include "globals.h"

u8 EscapeDetermineTimer(void)
{
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            return ESCAPE_MOTHER_BRAIN;
    }
    else if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA) &&
        EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        return ESCAPE_MECHA_RIDLEY;
    return ESCAPE_NONE;
}

u8 EscapeCheckHasEscaped(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA))
            return TRUE;
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            return FALSE;
            
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
            return TRUE;
    }
    return FALSE;
}

void EscapeUpdateOAM(void)
{
    u16 increment;

    increment = 0x33C0;

    gParticleEscapeOAMFrames[24] = gEscapeTimerDigits.hundredths + increment;
    gParticleEscapeOAMFrames[21] = gEscapeTimerDigits.tenths + increment;
    gParticleEscapeOAMFrames[15] = gEscapeTimerDigits.secondsOnes + increment;
    gParticleEscapeOAMFrames[12] = gEscapeTimerDigits.secondsTens + increment;
    gParticleEscapeOAMFrames[6] = gEscapeTimerDigits.minutesOnes + increment;
    gParticleEscapeOAMFrames[3] = gEscapeTimerDigits.minutesTens + increment;
}

void EscapeCheckReloadGraphics(void)
{

}

void EscapeStart(void)
{

}

void EscapeSetTimer(void)
{
    u8 escape;

    escape = EscapeDetermineTimer();
    gEscapeTimerCounter = 0xFF;
    if (escape == ESCAPE_MOTHER_BRAIN)
    {
        if (gDifficulty == DIFF_EASY)
        {
            gEscapeTimerDigits.hundredths = 0x0;
            gEscapeTimerDigits.tenths = 0x0;
            gEscapeTimerDigits.secondsOnes = 0x0;
            gEscapeTimerDigits.secondsTens = 0x0;
            gEscapeTimerDigits.minutesOnes = 0x3;
            gEscapeTimerDigits.minutesTens = 0x0;
        }
        else if (gDifficulty == DIFF_HARD)
        {
            gEscapeTimerDigits.hundredths = 0x0;
            gEscapeTimerDigits.tenths = 0x0;
            gEscapeTimerDigits.secondsOnes = 0x0;
            gEscapeTimerDigits.secondsTens = 0x0;
            gEscapeTimerDigits.minutesOnes = 0x1;
            gEscapeTimerDigits.minutesTens = 0x0;
        }
        else
        {
            gEscapeTimerDigits.hundredths = 0x0;
            gEscapeTimerDigits.tenths = 0x0;
            gEscapeTimerDigits.secondsOnes = 0x0;
            gEscapeTimerDigits.secondsTens = 0x0;
            gEscapeTimerDigits.minutesOnes = 0x2;
            gEscapeTimerDigits.minutesTens = 0x0;
        }
    }
    else if (escape == ESCAPE_MECHA_RIDLEY)
    {
        if (gDifficulty == DIFF_HARD)
        {
            gEscapeTimerDigits.hundredths = 0x0;
            gEscapeTimerDigits.tenths = 0x0;
            gEscapeTimerDigits.secondsOnes = 0x0;
            gEscapeTimerDigits.secondsTens = 0x0;
            gEscapeTimerDigits.minutesOnes = 0x3;
            gEscapeTimerDigits.minutesTens = 0x0;
        }
        else
        {
            gEscapeTimerDigits.hundredths = 0x0;
            gEscapeTimerDigits.tenths = 0x0;
            gEscapeTimerDigits.secondsOnes = 0x0;
            gEscapeTimerDigits.secondsTens = 0x0;
            gEscapeTimerDigits.minutesOnes = 0x5;
            gEscapeTimerDigits.minutesTens = 0x0;
        }
    }
    else
    {
        gEscapeTimerDigits.hundredths = 0x9;
        gEscapeTimerDigits.tenths = 0x9;
        gEscapeTimerDigits.secondsOnes = 0x9;
        gEscapeTimerDigits.secondsTens = 0x9;
        gEscapeTimerDigits.minutesOnes = 0x9;
        gEscapeTimerDigits.minutesTens = 0x9;
    }
}

void EscaepUpdateTimer(void)
{
    u32 counter;

    if (EscapeDetermineTimer() << 0x18 == ESCAPE_NONE || gCurrentEscapeStatus != ESCAPE_STATUS_HAPPENNING)
    {
        gCurrentEscapeStatus = ESCAPE_STATUS_NONE;
        return;
    }

    if (gGameModeSub1 != 0x2)
        return;
    if (gPreventMovementTimer != 0x0)
        return;

    counter = gEscapeTimerCounter = gEscapeTimerCounter + 0x1;

    if (counter & 0x1)
    {
        if (gEscapeTimerDigits.hundredths > 0x1)
            gEscapeTimerDigits.hundredths -= 0x2;
        else
        {
            gEscapeTimerDigits.hundredths += 0x8;
            if (gEscapeTimerDigits.tenths != 0x0)
                gEscapeTimerDigits.tenths--;
            else
                gEscapeTimerDigits.tenths = 0x9;
        }
    }
    else
    {
        if (gEscapeTimerDigits.hundredths != 0x0)
            gEscapeTimerDigits.hundredths--;
        else
        {
            gEscapeTimerDigits.hundredths = 0x9;
            if (gEscapeTimerDigits.tenths != 0x0)
                gEscapeTimerDigits.tenths--;
            else
                gEscapeTimerDigits.tenths = 0x9;
        }
    }

    if ((counter & 0x3F) == 0x0)
    {
        gEscapeTimerDigits.hundredths = 0x9;
        gEscapeTimerDigits.tenths = 0x9;
        if (gEscapeTimerDigits.secondsOnes != 0x0)
            gEscapeTimerDigits.secondsOnes--;
        else
        {
            gEscapeTimerDigits.secondsOnes = 0x9;
            if (gEscapeTimerDigits.secondsTens != 0x0)
                gEscapeTimerDigits.secondsTens--;
            else
            {
                gEscapeTimerDigits.secondsTens = 0x5;
                if (gEscapeTimerDigits.minutesOnes != 0x0)
                    gEscapeTimerDigits.minutesOnes--;
                else
                {
                    gEscapeTimerDigits.minutesOnes = 0x9;
                    if (gEscapeTimerDigits.minutesTens != 0x0)
                        gEscapeTimerDigits.minutesTens--;
                    else
                    {
                        gEscapeTimerDigits.hundredths = 0x0;
                        gEscapeTimerDigits.tenths = 0x0;
                        gEscapeTimerDigits.secondsOnes = 0x0;
                        gEscapeTimerDigits.secondsTens = 0x0;
                        gEscapeTimerDigits.minutesOnes = 0x0;
                        gEscapeTimerDigits.minutesTens = 0x0;
                        gCurrentEscapeStatus = ESCAPE_STATUS_FAILED;
                    }
                }
            }
        }
    }
}