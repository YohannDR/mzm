#include "hud.h"
#include "data/generic.h"
#include "globals.h"

void HUDUpdateOAM(void)
{
    // https://decomp.me/scratch/YlLyU

    u32 oamSlot;
    u16* dst;
    
    oamSlot = 0x0;

    if (!gHideHud)
    {
        dst = (u16*)gOamData;

        // Left part of health bar
        *dst++ = 0x0;
        gOamData[oamSlot].split.y = 0x2;
        gOamData[oamSlot].split.shape = 0x1;

        *dst++ = 0x0;
        gOamData[oamSlot].split.x = 0x0;
        gOamData[oamSlot].split.size = 0x1;
        
        *dst++ = 0x0;
        gOamData[oamSlot].split.tileNum = 0x50;
        gOamData[oamSlot].split.paletteNum = 0x4;

        dst++;
        oamSlot++;

        // Right part of health bar
        *dst++ = 0x0;
        gOamData[oamSlot].split.y = 0x2;
        gOamData[oamSlot].split.shape = 0x1;
        
        *dst++ = 0x0;
        gOamData[oamSlot].split.x = 0x20;
        gOamData[oamSlot].split.size = 0x1;
        
        *dst++ = 0x0;
        gOamData[oamSlot].split.tileNum = 0x54;
        gOamData[oamSlot].split.paletteNum = 0x4;

        dst++;
        oamSlot++;

        if (gEquipment.suitType == SUIT_SUITLESS)
        {
            // Left part of charge bar
            *dst++ = 0x0;
            gOamData[oamSlot].split.y = 0xA;
            gOamData[oamSlot].split.shape = 0x1;
            
            *dst++ = 0x0;
            gOamData[oamSlot].split.x = 0x1;
            gOamData[oamSlot].split.size = 0x1;
            
            *dst++ = 0x0;
            gOamData[oamSlot].split.tileNum = 0x88;
            gOamData[oamSlot].split.paletteNum = 0x4;

            dst++;
            oamSlot++;
            
            // Right part of charge bar
            *dst++ = 0x0;
            gOamData[oamSlot].split.y = 0xA;
            gOamData[oamSlot].split.shape = 0x1;
            
            *dst++ = 0x0;
            gOamData[oamSlot].split.x = 0x21;
            gOamData[oamSlot].split.size = 0x1;
            
            *dst++ = 0x0;
            gOamData[oamSlot].split.tileNum = 0x8C;
            gOamData[oamSlot].split.paletteNum = 0x4;

            dst++;
            oamSlot++;
        }
        else
        {
            if (gEquipment.maxMissiles != 0x0)
            {
                // Missile digits
                
                *dst++ = 0x0;
                gOamData[oamSlot].split.y = 0x2;
                gOamData[oamSlot].split.shape = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.x = 0x36;
                gOamData[oamSlot].split.size = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.tileNum = 0x70;
                gOamData[oamSlot].split.paletteNum = 0x4;

                dst++;
                oamSlot++;
            }
            
            if (gEquipment.maxSuperMissiles != 0x0)
            {
                // Super missile digits
                *dst++ = 0x0;
                gOamData[oamSlot].split.y = 0x2;
                gOamData[oamSlot].split.shape = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.x = 0x50;
                gOamData[oamSlot].split.size = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.tileNum = 0x74;
                gOamData[oamSlot].split.paletteNum = 0x4;

                dst++;
                oamSlot++;
            }

            if (gEquipment.maxPowerBombs != 0x0)
            {
                // Power bomb digits

                *dst++ = 0x0;
                gOamData[oamSlot].split.y = 0x2;
                gOamData[oamSlot].split.shape = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.x = 0x6A;
                gOamData[oamSlot].split.size = 0x1;

                *dst++ = 0x0;
                gOamData[oamSlot].split.tileNum = 0x58;
                gOamData[oamSlot].split.paletteNum = 0x4;

                dst++;
                oamSlot++;
            }
        }

        // Minimap white square

        *dst++ = 0x0;
        gOamData[oamSlot].split.y = 0xA;
        gOamData[oamSlot].split.shape = 0x0;

        *dst++ = 0x0;
        gOamData[oamSlot].split.x = 0xDE;
        gOamData[oamSlot].split.size = 0x0;

        *dst++ = 0x0;

        if (gFrameCounter8Bit & 0x8)
            gOamData[oamSlot].split.tileNum = 0xBF;
        else
            gOamData[oamSlot].split.tileNum = 0x140;
        gOamData[oamSlot].split.paletteNum = 0x5;

        dst++;
        oamSlot++;

        // Minimap
        *dst++ = 0x0;
        gOamData[oamSlot].split.y = 0xFA;
        gOamData[oamSlot].split.shape = 0x0;

        *dst++ = 0x0;
        gOamData[oamSlot].split.x = 0xD6;
        gOamData[oamSlot].split.size = 0x2;

        *dst++ = 0x0;
        gOamData[oamSlot].split.tileNum = 0xDC;
        gOamData[oamSlot].split.paletteNum = 0x5;
        
        oamSlot++;
    }

    gNextOAMSlot = oamSlot;
}

/**
 * @brief 52664 | 70 | Updates the energy tanks on the HUD
 * 
 * @param pDst Destination Address
 * @param pSrcNormal Source Address (normal graphics)
 * @param pSrcRefill Source Address (refill graphics)
 * @param nbrTanks Number of energy tanks
 * @param refillStage Refill stage
 */
void HUDUpdateEnergyTanks(u8* pDst, u8* pSrcNormal, u8* pSrcRefill, u8 nbrTanks, u8 refillStage)
{
    if (refillStage == 0x0)
    {
        dma_set(3, pSrcRefill, pDst + 0x40, (DMA_ENABLE << 16) | 0x50);
    }
    else if (refillStage == 0x1)
    {
        dma_set(3, pSrcRefill + 0xA0 * refillStage, pDst + 0x40, (DMA_ENABLE << 16) | 0x50);
    }
    else if (refillStage == 0x2)
    {
        dma_set(3, pSrcRefill + 0xA0 * refillStage, pDst + 0x40, (DMA_ENABLE << 16) | 0x50);
    }
    else if (refillStage == 0x3)
    {
        dma_set(3, pSrcNormal + 0xA0 * nbrTanks, pDst + 0x40, (DMA_ENABLE << 16) | 0x50);
    } 
}

void HUDDrawEnergy(u8 file_number)
{

}

void HUDDrawMissileDigits(u16 hundredsPlace, u16 tensPlace, u16 onesPlace, u16 highlightStatus)
{

}

void HUDDrawSuperMissileDigits(u16 tensPlace, u16 onesPlace, u16 highlightStatus)
{

}

void HUDDrawPowerBombDigits(u16 tensPlace, u16 onesPlace, u16 highlightStatus)
{

}

void HUDDrawMissiles(u8 updateHighlight)
{

}

void HUDDrawPowerBomb(u8 updateHighlight)
{

}

void HUDDrawSuperMissiles(u8 updateHighlight)
{

}

void HUDDrawHighlight(void)
{

}

/**
 * @brief 538e8 | 48 | Draws the HUD (for suitless)
 * 
 */
void HUDDrawSuitless(void)
{
    u32 chargeCounter;

    chargeCounter = gSamusWeaponInfo.chargeCounter;
    if (chargeCounter >= 0x70)
        chargeCounter = (u8)(gSamusWeaponInfo.chargeCounter - 0x70) / 4 + 0x34;
    else
        chargeCounter /= 2;

    if (chargeCounter < 0x38)
    {
        dma_set(3, sSuitlessHUDChargeBarGFX[chargeCounter], VRAM_BASE + 0x11100, (DMA_ENABLE << 16) | 0x80);
    }
}

/**
 * 53930 | 38 | Main function that draws the HUD
 * 
 */
void HUDDraw(void)
{
    HUDDrawEnergy(0x0);
    HUDDrawMissiles(FALSE);
    HUDDrawPowerBomb(FALSE);
    HUDDrawSuperMissiles(FALSE);
    HUDDrawHighlight();
    if (gEquipment.suitType == SUIT_SUITLESS)
        HUDDrawSuitless();
    HUDUpdateOAM();
}