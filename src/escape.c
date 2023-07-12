#include "escape.h"
#include "gba.h"

#include "data/visual_effects_data.h"

#include "constants/event.h"
#include "constants/escape.h"
#include "constants/game_state.h"
#include "constants/particle.h"

#include "structs/escape.h"
#include "structs/game_state.h"
#include "structs/particle.h"
#include "structs/samus.h"

/**
 * @brief 53968 | 40 | Determines the current escape timer (if any) based on the events
 * 
 * @return u8 Escape ID
 */
u8 EscapeDetermineTimer(void)
{
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            return ESCAPE_MOTHER_BRAIN;
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA) &&
            EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        return ESCAPE_MECHA_RIDLEY;
    }

    return ESCAPE_NONE;
}

/**
 * @brief 539a8 | 38 | Checks if Samus has escaped
 * 
 * @return u8 TRUE if escaped, FALSE otherwise
 */
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

/**
 * @brief 539e0 | 38 | Updates the OAM of the escape timer
 * 
 */
void EscapeUpdateOAM(void)
{
    u16 increment;

    increment = 0x33C0;

    gParticleEscapeOamFrames[24] = gEscapeTimerDigits.hundredths + increment;
    gParticleEscapeOamFrames[21] = gEscapeTimerDigits.tenths + increment;
    gParticleEscapeOamFrames[15] = gEscapeTimerDigits.secondsOnes + increment;
    gParticleEscapeOamFrames[12] = gEscapeTimerDigits.secondsTens + increment;
    gParticleEscapeOamFrames[6] = gEscapeTimerDigits.minutesOnes + increment;
    gParticleEscapeOamFrames[3] = gEscapeTimerDigits.minutesTens + increment;
}

/**
 * @brief 53a18 | 30 | Checks if the escape timer graphics should reload
 * 
 */
void EscapeCheckReloadGraphics(void)
{
    if (EscapeDetermineTimer() != ESCAPE_NONE)
    {
        DMA_SET(3, sEscapeTimerDigitsGfx, VRAM_BASE + 0x17800, DMA_ENABLE << 16 | sizeof(sEscapeTimerDigitsGfx) / 2);
    }
}

/**
 * @brief 53a48 | 60 | Starts an escape
 * 
 */
void EscapeStart(void)
{
    DMA_SET(3, sEscapeTimerDigitsGfx, VRAM_BASE + 0x17800, DMA_ENABLE << 16 | 0xB0);
    DMA_SET(3, sEscapeTimerDigitsGfx + 1024, VRAM_BASE + 0x17c00, DMA_ENABLE << 16 | 0xB0);
    DMA_SET(3, sParticleEscapeOAM, gParticleEscapeOamFrames, DMA_ENABLE << 16 | sizeof(gParticleEscapeOamFrames) / 2);
    ParticleSet(2, 141, PE_ESCAPE);
}

/**
 * @brief 53aa8 | bc | Sets the timer for the current escape
 * 
 */
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

/**
 * @brief 53b64 | 104 | Updates the escape timer
 * 
 */
void EscaepUpdateTimer(void)
{
    u32 counter;

    if (EscapeDetermineTimer() == ESCAPE_NONE || gCurrentEscapeStatus != ESCAPE_STATUS_HAPPENNING)
    {
        gCurrentEscapeStatus = ESCAPE_STATUS_NONE;
        return;
    }

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    if (gPreventMovementTimer != 0x0)
        return;

    counter = ++gEscapeTimerCounter;

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