#include "chozodia_escape.h"
#include "gba.h"
#include "callbacks.h"

#include "data/block_data.h"
#include "data/shortcut_pointers.h"

#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/chozodia_escape.h"
#include "structs/display.h"

/**
 * @brief 8784c | ec | V-blank code for the chozodia escape
 * 
 */
void ChozodiaEscapeVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, CHOZODIA_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, CHOZODIA_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBG0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBG0YPosition & 0xFF);
    write16(REG_BG1HOFS, gBG1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBG1YPosition & 0xFF);
    write16(REG_BG2HOFS, gBG2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBG2YPosition & 0xFF);

    CHOZODIA_ESCAPE_DATA.unk_36f = CHOZODIA_ESCAPE_DATA.unk_36e;
}

/**
 * @brief 87938 | 3c | H-blank code for the chozodia escape
 * 
 */
void ChozodiaEscapeHBlank(void)
{
    u16 vcount;

    vcount = read16(REG_VCOUNT);

    // Write to the window 0 width register using the previously calculated haze values
    // Since this is h-blank code, this gets called at the end of each scanline, thus the VCOUNT register is used
    // to forward the correct value
    write16(REG_WIN0H, CHOZODIA_ESCAPE_DATA.explosionHazeValues[CHOZODIA_ESCAPE_DATA.unk_36f][vcount]);
}

/**
 * @brief 87974 | 34 | Transfers and sets the h-blank code
 * 
 */
void ChozodiaEscapeSetHBlank(void)
{
    // Transfer code to RAM
    dma_set(3, ChozodiaEscapeHBlank, CHOZODIA_ESCAPE_DATA.hblankCode, DMA_ENABLE << 16 | 0x20);
    
    // Set pointer
    CallbackSetHBlank((Func_T)(CHOZODIA_ESCAPE_DATA.hblankCode + 1));
}

/**
 * @brief 879a8 | 64 | Sets up the registers for the h-blank code
 * 
 */
void ChozodiaEscapeSetupHBlankRegisters(void)
{
    // Setup window 0 size (no width, max height)
    write16(REG_WIN0H, 0);
    write16(REG_WIN0V, 160);
    
    // Setup window 0 masks with every background and obj (BG0, BG1, BG2, BG3, OBJ)
    // Mask out color effects
    write16(REG_WININ, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT);
    write16(REG_WINOUT, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ);

    // Enable window 0 and H-blank
    CHOZODIA_ESCAPE_DATA.dispcnt |= (DCNT_OAM_HBL | DCNT_WIN0);

    // Disable interrupts
    write16(REG_IME, FALSE);

    // Enable H-blank
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) | DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) | IF_HBLANK);

    // Enable interrupts
    write16(REG_IME, TRUE);
}

void ChozodiaEscapeUpdateExplosionHaze(void)
{

}

/**
 * @brief 87aec | 11c | Calculates the
 * 
 * @return u32 
 */
u32 ChozodiaEscapeGetItemCountAndEndingNumber(void)
{
    u32 energyNbr;
    u32 missilesNbr;
    u8 superMissilesNbr;
    u8 powerBombNbr;
    u8 i;
    u32 mask;
    u32 abilityCount;
    u32 ending;
    u32 percentage;
    u32 difficulty;

    difficulty = gDifficulty;

    // Calculate the amount of tanks of each type (remove starting energy)
    energyNbr = (gEquipment.maxEnergy - 99) / sTankIncreaseAmount[difficulty].energy;
    missilesNbr = gEquipment.maxMissiles / sTankIncreaseAmount[difficulty].missile;
    superMissilesNbr = gEquipment.maxSuperMissiles / sTankIncreaseAmount[difficulty].superMissile;
    powerBombNbr = gEquipment.maxPowerBombs / sTankIncreaseAmount[difficulty].powerBomb;

    // Count the number of suit/misc items
    abilityCount = 0;
    mask = 1;
    for (i = 0; i < 8; i++)
    {
        if (gEquipment.suitMisc & mask)
            abilityCount++;

        mask <<= 1;
    }

    // Count the number of beam/bombs items
    mask = 1;
    for (i = 0; i < 5; i++)
    {
        if (gEquipment.beamBombs & mask)
            abilityCount++;

        mask <<= 1;
    }

    // Check for bomb flag
    // Probably because flag 0x20 and 0x40 are unused, so they didn't want that to interfere with the result
    if (gEquipment.beamBombs & BBF_BOMBS)
        abilityCount++;

    // Calculate completion percentage (sum of every item/tank)
    percentage = abilityCount + energyNbr + missilesNbr + superMissilesNbr + powerBombNbr;

    // Determine ending
    ending = 0;
    if (difficulty != DIFF_EASY)
    {
        if (percentage < 16)
        {
            // Low% ending (6 and 7)
            ending = difficulty + 5;
        }
        else if (percentage >= 100)
        {
            // 100% ending
            if (gInGameTimer.hours >= 2)
                ending = 3; // Over 2 hours
            else
            {
                // Under 2 hours (4 and 5)
                ending = difficulty + 3;
            }
        }
        else
        {
            // Any% endings
            if (gInGameTimer.hours < 2)
                ending = 2; // Under 2 hours
            else if (gInGameTimer.hours < 4)
                ending = 1; // Under 4 hours
        }
    }

    // Final resutl, formatted on 32bits as follow :
    //      0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0       0 0 0 0                    0 0 0 0               0 0 0 0              0 0 0 0
    return (energyNbr << 24) + (missilesNbr << 16) + (superMissilesNbr << 12) + (powerBombNbr << 8) + (abilityCount << 4) + ending;
}

void ChozodiaEscapeProcessOam_1(void)
{

}

void ChozodiaEscapeProcessOam_2(void)
{

}

void ChozodiaEscapeInit(void)
{

}

u8 ChozodiaEscapeShipLeaving(void)
{

}

u8 ChozodiaEscapeShipHeatingUp(void)
{

}

u8 ChozodiaEscapeShipBlowingUp(void)
{

}

u8 ChozodiaEscapeShipLeavingPlanet(void)
{

}

u8 ChozodiaEscapeMissionAccomplished(void)
{

}

u32 ChozodiaEscapeSubroutine(void)
{

}
