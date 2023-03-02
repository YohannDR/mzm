#include "softreset.h"
#include "gba.h"

#include "constants/game_state.h"
#include "structs/audio.h"
#include "structs/game_state.h"

#define SOFTRESET_KEYS (KEY_A | KEY_B | KEY_START | KEY_SELECT)

void SoftresetVBlankCallback(void)
{
    /* probably left over from some debugging code */
    volatile u8 c = 0;
}

void SoftresetCheck(void)
{
    if (gMainGameMode == GM_START_SOFTRESET)
        return;

    if (gDisableSoftreset)
        return;

    if ((gButtonInput & SOFTRESET_KEYS) == SOFTRESET_KEYS)
        gMainGameMode = GM_START_SOFTRESET;
}

void Softreset(void)
{
    sub_0805d034();
    unk_33dc();

    write16(REG_IME, FALSE);
    write16(REG_IE, 0);
    write16(REG_DISPSTAT, 0);
    PLTT_BG[0] = 0;
    write16(REG_DISPCNT, 0);
    write16(REG_BLDY, 0x10);
    write16(REG_BLDCNT, 0xff);

    dma_fill32(3, 0, EWRAM_BASE, 0x40000);
    dma_fill32(3, 0, IWRAM_BASE, 0x7e00);

    ClearGfxRam();
    LoadInterruptCode();
    CallbackSetVBlank(SoftresetVBlankCallback);
    SramRead_All();
    init_sound();

    write16(REG_IE, IF_VBLANK | IF_DMA2 | IF_GAMEPAK);
    write16(REG_DISPSTAT, DSTAT_IF_VBLANK);

    gMainGameMode = GM_INTRO;
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
