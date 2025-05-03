#include "softreset.h"
#include "gba.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"

#include "constants/cutscene.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/cutscene.h"

/**
 * @brief 7ef9c | 54 | Subroutine for a softreset
 * 
 * @return u32 bool, ended
 */
u32 SoftresetSubroutine(void)
{
    switch (gGameModeSub1)
    {
        case 0:
            SoftresetInit();
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay - 4 < 1)
                gWrittenToBLDY_NonGameplay = 0;
            else
                gWrittenToBLDY_NonGameplay -= 4;
            
            if (gWrittenToBLDY_NonGameplay == 0)
                gGameModeSub1++;
            break;

        case 2:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7eff0 | 110 | Initializes a soft reset
 * 
 */
void SoftresetInit(void)
{
    // The use of non gameplay ram in this function is inconsequential

    u32 buffer;

    CallbackSetVBlank(SoftresetVBlank_Empty);
    
    buffer = 0;
    DMA_SET(3, &buffer, &gNonGameplayRam, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRam) / sizeof(u32)));    

    write16(REG_BLDCNT, CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);
    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;
    SET_BACKDROP_COLOR(COLOR_BLACK);
    gGameModeSub3 = 0;

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);
    
    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);

    CallbackSetVBlank(SoftresetVBlank);
}

/**
 * @brief 7f100 | 14 | V-blank code for a softreset
 * 
 */
void SoftresetVBlank(void)
{
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
}

/**
 * @brief 7f114 | c | Empty v-blank for a softreset
 * 
 */
void SoftresetVBlank_Empty(void)
{
    vu8 c = 0;
}
