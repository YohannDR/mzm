#include "demo_input.h"
#include "gba.h"

#include "constants/demo.h"

#include "structs/demo.h"
#include "structs/game_state.h"

/**
 * @brief c2d8 | 24 | Main loop for a demo
 * 
 */
void DemoMainLoop(void)
{
    if (gDemoState == DEMO_STATE_NONE)
        return;

    if (gDemoState == DEMO_STATE_RECORDING_DEBUG)
        RecordDemo();
    else if (gDemoState == DEMO_STATE_PLAYING)
        UpdateDemoInput();
}

/**
 * @brief c2fc | 88 | Handles a demo being recorded
 * 
 */
void RecordDemo(void)
{
    // Max duration - 2 to leave space for the KEY_START at the end
    if (gDemoInputNumber >= DEMO_MAX_DURATION - 2)
    {
        // Reached max demo duration, force the end
        gChangedInput = KEY_START;
        return;
    }

    if (gButtonInput == gDemoInputData[gDemoInputNumber])
    {
        // Same input as before
        if (gDemoInputDuration[gDemoInputNumber] == USHORT_MAX)
        {
            // Held input for more than USHORT_MAX frames, delegate to next slot
            gDemoInputNumber++;
            gDemoInputData[gDemoInputNumber] = gButtonInput;
        }

        // Increase timer
        gDemoInputDuration[gDemoInputNumber]++;
        return;
    }

    // New input detected, setup next slot
    gDemoInputNumber++;
    gDemoInputData[gDemoInputNumber] = gButtonInput;
    gDemoInputDuration[gDemoInputNumber] = 1;
}

/**
 * @brief c384 | 90 | Updates the demo input
 * 
 */
void UpdateDemoInput(void)
{
    // Max duration - 2 to leave space for the KEY_START at the end
    if (gDemoInputNumber >= DEMO_MAX_DURATION - 2 || gDemoInputTimer == USHORT_MAX || gButtonInput != KEY_NONE)
    {
        gChangedInput = KEY_START;
        if (gButtonInput != KEY_NONE)
            gButtonInput = KEY_NONE;
        return;
    }

    if (gDemoInputTimer == 0)
    {
        // Input timer ended
        gDemoInputNumber++;
        gDemoInputTimer = gDemoInputDuration[gDemoInputNumber];
    }

    // Inlined call to CopyDemoInput ?
    // Copy to button input
    gButtonInput = gDemoInputData[gDemoInputNumber];
    // Set changed input
    gChangedInput = (gDemoInput ^ gButtonInput) & gButtonInput;
    // Set demo input
    gDemoInput = gButtonInput;
    // Update input timer
    gDemoInputTimer--;
}

/**
 * @brief c414 | 34 | Copies the demo input
 * 
 */
void CopyDemoInput(void)
{
    // Copy to button input
    gButtonInput = gDemoInputData[gDemoInputNumber];
    // Set changed input
    gChangedInput = (gDemoInput ^ gButtonInput) & gButtonInput;
    // Set demo input
    gDemoInput = gButtonInput;
}

/**
 * @brief c448 | 6c | Resets a demo (input and duration)
 * 
 */
void DemoResetInputAndDuration(void)
{
    s32 i;
    if (gDemoState == DEMO_STATE_RECORDING_DEBUG)
    {
        // Clear both input and duration to leave space to record 
        for (i = 0; i < DEMO_MAX_DURATION; i++)
        {
            gDemoInputData[i] = KEY_NONE;
            gDemoInputDuration[i] = 0;
        }

        gDemoInputTimer = 0;
    }
    else
    {
        // Set first timer
        gDemoInputTimer = gDemoInputDuration[0];
    }

    gDemoInputNumber = 0;
    gDemoInput = KEY_NONE;
}
