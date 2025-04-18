#include "softreset_input.h"
#include "gba.h"
#include "macros.h"
#include "menus/boot_debug.h"

#include "constants/game_state.h"
#include "structs/audio.h"
#include "structs/game_state.h"

#define SOFTRESET_KEYS (KEY_A | KEY_B | KEY_START | KEY_SELECT)

/**
 * @brief 7c4 | c | Removed code for V-Blank during softreset
 * 
 */
void SoftresetVBlankCallback(void)
{
    /* probably left over from some debugging code */
    volatile u8 c = 0;
}

/**
 * @brief 7d0 | 34 | Checks for softreset conditions
 * 
 */
void SoftresetCheck(void)
{
    if (gMainGameMode == GM_START_SOFTRESET)
        return;

    if (gDisableSoftreset)
        return;

    if ((gButtonInput & SOFTRESET_KEYS) == SOFTRESET_KEYS)
        gMainGameMode = GM_START_SOFTRESET;
}

/**
 * @brief 804 | 108 | Prepares game and register states for a soft reset
 * 
 */
void Softreset(void)
{
    HazeTransferAndDeactivate();
    RestartSound();

    write16(REG_IME, FALSE);
    write16(REG_IE, 0);
    write16(REG_DISPSTAT, 0);
    SET_BACKDROP_COLOR(COLOR_BLACK);
    write16(REG_DISPCNT, 0);
    write16(REG_BLDY, BLDY_MAX_VALUE);
    write16(REG_BLDCNT, 0xff);

    dma_fill32(3, 0, EWRAM_BASE, EWRAM_SIZE);
    dma_fill32(3, 0, IWRAM_BASE, IWRAM_SIZE - 0x200);

    ClearGfxRam();
    LoadInterruptCode();
    CallbackSetVBlank(SoftresetVBlankCallback);
    SramRead_All();
    InitializeAudio();

    write16(REG_IE, IF_VBLANK | IF_DMA2 | IF_GAMEPAK);
    write16(REG_DISPSTAT, DSTAT_IF_VBLANK);

    #ifdef DEBUG
    BootDebugReadSram();
    gMainGameMode = gDebugMode ? GM_DEBUG_MENU : GM_INTRO;
    #else // !DEBUG
    gMainGameMode = GM_INTRO;
    #endif // DEBUG

    gGameModeSub1 = 0;
    gGameModeSub2 = 0;
    gResetGame = 0;
    gStereoFlag = 0;
    gButtonInput = KEY_NONE;
    gPreviousButtonInput = KEY_NONE;
    gChangedInput = KEY_NONE;

    write16(REG_IF, 0xffff);
    write16(REG_IME, TRUE);
}
