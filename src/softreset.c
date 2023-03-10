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
    dma_set(3, &buffer, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);    

    write16(REG_BLDCNT, CUTSCENE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
        BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
        BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);
    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOAM();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;
    write16(PALRAM_BASE, 0);
    gGameModeSub3 = 0;

    gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = 0;
    gBG1HOFS_NonGameplay = gBG1VOFS_NonGameplay = 0;
    gBG2HOFS_NonGameplay = gBG2VOFS_NonGameplay = 0;
    gBG3HOFS_NonGameplay = gBG3VOFS_NonGameplay = 0;

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
