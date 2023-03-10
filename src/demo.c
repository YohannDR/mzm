#include "demo.h"
#include "callbacks.h"

#include "data/demo_data.h"

#include "constants/connection.h"
#include "constants/demo.h"
#include "constants/event.h"

#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/save_file.h"

/**
 * @brief 60b14 | c | Demo v-blank, empty
 * 
 */
void DemoVBlank(void)
{
    vu8 c = 0;
}

/**
 * @brief 60b20 | 5c | Starts a new demo
 * 
 */
void DemoStart(void)
{
    u32 demoNbr;
    u32 fc8;

    gCurrentDemo.noDemoShuffle = FALSE;

    if (!gCurrentDemo.unk_2_0)
    {
        gCurrentDemo.unk_2_0 = TRUE;

        fc8 = gFrameCounter8Bit;
        demoNbr = (gFrameCounter16Bit >> 8) + gFrameCounter8Bit;

        gCurrentDemo.number = demoNbr & 1 ? 8 : 0;
    }

    gDemoState = DEMO_STATE_STARTING;
    DemoInit();
}

/**
 * @brief 60b7c | 140 | Initializes a demo
 * 
 */
void DemoInit(void)
{
    i32 demoNbr;

    CallbackSetVBlank(DemoVBlank);

    // Get demo number
    if (gCurrentDemo.noDemoShuffle)
        demoNbr = gCurrentDemo.number;
    else
    {
        if (gCurrentDemo.number >= MAX_AMOUNT_OF_DEMOS)
            gCurrentDemo.number = 0;

        demoNbr = sDemoNumbers[gCurrentDemo.number];
    }

    // Load ram values
    unk_7584c(0x1);
    SramLoad_DemoRamValues(FALSE, demoNbr);

    if (gDemoState == DEMO_STATE_STARTING)
    {
        // Transfer input and duration data from ROM to RAM
        DMATransfer(3, sDemoEntries[demoNbr].pInputs, gDemoInputData, sDemoEntries[demoNbr].inputsSize, 16);
        DMATransfer(3, sDemoEntries[demoNbr].pDuration, gDemoInputDuration, sDemoEntries[demoNbr].durationSize, 16);

        gDemoState = DEMO_STATE_PLAYING;
    }

    // Setup appropriate flags for the current demo
    switch (demoNbr)
    {
        case 6:
            EventFunction(EVENT_ACTION_SETTING, EVENT_ZIPLINES_ACTIVATED);
            EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_JUMP_OBTAINED);
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
            break;

        case 7:
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
            EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);
            break;

        case 10:
            EventFunction(EVENT_ACTION_SETTING, EVENT_ZIPLINES_ACTIVATED);
            break;

        case 11:
            // FIXME, another way to write this maybe?
            write32(&gMinimapTilesWithObtainedItems[AREA_BRINSTAR * MINIMAP_SIZE + 15], 1);
            break;
    }

    // Reset demo input number
    gDemoInputNumber = 0;

    // Set demo flags
    gCurrentDemo.loading = TRUE;
    gCurrentDemo.active = TRUE;
    gCurrentDemo.endedWithInput = FALSE;

    // Reset frame counters, also resets randomness
    gFrameCounter8Bit = 0;
    gFrameCounter16Bit = 0;

    CallbackSetVBlank(DemoVBlank);
}

/**
 * @brief 60cbc | 7c | To document
 * 
 * @param param_1 To document
 */
void unk_60cbc(u8 param_1)
{
    u32 demoNbr;

    if (gCurrentDemo.noDemoShuffle)
        demoNbr = gCurrentDemo.number;
    else
        demoNbr = sDemoNumbers[gCurrentDemo.number];

    if (!param_1)
    {
        gCurrentRoom = 0;
        return;
    }

    // Load samus data
    SramLoad_DemoRamValues(TRUE, demoNbr);
    gCurrentDemo.loading = FALSE;

    // Reset frame counters, also resets randomness
    gFrameCounter8Bit = 0;
    gFrameCounter16Bit = 0;

    if (gDemoState == DEMO_STATE_NONE)
        gCurrentDemo.noDemoShuffle = FALSE;
}

/**
 * @brief 60d38 | f0 | ends a demo
 * 
 */
void DemoEnd(void)
{
    gCurrentDemo.active = FALSE;

    if (gDemoState == DEMO_STATE_IN_CONTROL_DEBUG)
    {
        // Debug, forward demo input and duration to SRAM, and save it flash
        dma_set(3, gDemoInputData, gSramDemoInputData, DMA_ENABLE << 16 | DEMO_MAX_DURATION);
        dma_set(3, gDemoInputDuration, gSramDemoInputDuration, DMA_ENABLE << 16 | DEMO_MAX_DURATION);
    
        do_sram_operation(SRAM_OPERATION_SAVE_RECORDED_DEMO);

        // Debug leftover
        gGameModeSub2 = 16;

        // End demo
        gDemoState = DEMO_STATE_NONE;
        return;
    }

    gGameModeSub2 = 11;

    if (gCurrentDemo.noDemoShuffle)
    {
        gDemoState = DEMO_STATE_NONE;
        gGameModeSub2 = 2;
    }
    else if (gCurrentDemo.endedWithInput)
    {
        // Increment demo number
        gCurrentDemo.number++;
        if (gCurrentDemo.number >= MAX_AMOUNT_OF_DEMOS)
            gCurrentDemo.number = 0;

        // Fade every sound and music
        FadeAllSounds(10);
        FadeMusicForDemo(10);

        // Sets to no demo
        gDemoState = DEMO_STATE_NONE;
        gGameModeSub2 = 2;
        return;
    }
    else
    {
        // Demo ended naturally, load new one

        // Increment demo number
        gCurrentDemo.number++;
        if (gCurrentDemo.number >= MAX_AMOUNT_OF_DEMOS)
        {
            gDemoState = DEMO_STATE_NONE;
            gCurrentDemo.number = 0;
            gGameModeSub2 = 1;
        }
        else
        {
            // Check end naturally after 8 demos played
            if (gCurrentDemo.number == 8)
            {
                // End, go back to intro
                gDemoState = DEMO_STATE_NONE;
                gGameModeSub2 = 2;
            }
            else
            {
                // Start new demo
                gDemoState = DEMO_STATE_STARTING;
            }
        }
    }

    if (gDemoState == DEMO_STATE_NONE)
    {
        gCurrentDemo.noDemoShuffle = FALSE;

        // Stop every sound and music
        FadeAllSounds(0);
        FadeMusicForDemo(0);
    }
}
