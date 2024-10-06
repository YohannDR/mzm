#include "types.h"
#include "structs/in_game_timer.h"

/**
 * @brief 579b8 | 6c | Updates the in game timer
 * 
 */
void InGameTimerUpdate(void)
{
    if (gMaxInGameTimerFlag)
        return;

    gInGameTimer.frames++;
    if (gInGameTimer.frames >= SIMULATED_FPS)
    {
        gInGameTimer.frames = 0;
        gInGameTimer.seconds++;
        if (gInGameTimer.seconds > 59)
        {
            gInGameTimer.seconds = 0;
            gInGameTimer.minutes++;
            if (gInGameTimer.minutes > 59)
            {
                gInGameTimer.minutes = 0;
                if (gInGameTimer.hours < 100)
                    gInGameTimer.hours++;
            }
        }
    }
                
    if (gInGameTimer.hours > 99)
    {
        gMaxInGameTimerFlag = TRUE;
        gInGameTimer.hours = 99;
        gInGameTimer.minutes = 59;
        gInGameTimer.seconds = 59;
        gInGameTimer.frames = 63;
    }
}