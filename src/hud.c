#include "hud.h"
#include "data/hud_data.h"
#include "globals.h"

/**
 * @brief 52308 | 35c | Updates the OAM of the HUD
 * 
 */
void HUDUpdateOAM(void)
{
    u32 oamSlot;
    u16* dst;
    struct Equipment* pEquipment = &gEquipment;
    
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

        
        if (pEquipment->suitType == SUIT_SUITLESS)
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
            if (pEquipment->maxMissiles != 0x0)
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
            if (pEquipment->maxSuperMissiles != 0x0)
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
            if (pEquipment->maxPowerBombs != 0x0)
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

        *dst = 0x0;
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

void HUDDrawEnergy(u8 fileNumber)
{

}

/**
 * @brief 52c6c | 100 | Draws the missile digits to the ammo digits
 * 
 * @param hundreds Hundreds
 * @param tens Tens
 * @param ones Ones
 * @param highlightStatus Highlight status
 */
void HUDDrawMissileDigits(u16 hundreds, u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[hundreds];
        row++;
        hundreds++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[hundreds];
        row++;
        hundreds += 0x3;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[tens];
        row++;
        tens++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[tens];
        row++;
        tens += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[ones];
        row++;
        ones++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[ones];
        row++;
        ones += 0x3;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[highlightStatus];
        row++;
        highlightStatus += 0x3;
    }
}

/**
 * @brief 52d6c | d8 | Draws the super missile digits to the ammo digits
 * 
 * @param tens Tens
 * @param ones Ones
 * @param highlightStatus Highlight status
 */
void HUDDrawSuperMissileDigits(u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[tens];
        row++;
        tens++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[tens];
        row++;
        tens += 0x3;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[ones];
        row++;
        ones++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[ones];
        row++;
        ones += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGFX[row] = sMissileDigitsGFX[highlightStatus];
        row++;
        highlightStatus += 0x3;
        gAmmoDigitsGFX[row] = 0x0;
        row++;
        gAmmoDigitsGFX[row] = 0x0;
        row++;
    }
}

/**
 * @brief 52e44 | d8 | Draws the power bomb digits to the ammo digits
 * 
 * @param tens Tens
 * @param ones Ones
 * @param highlightStatus Highlight status
 */
void HUDDrawPowerBombDigits(u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[tens];
        row++;
        tens++;
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[tens];
        row++;
        tens += 0x3;
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[ones];
        row++;
        ones++;
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[ones];
        row++;
        ones += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGFX[row] = sPowerBombDigitsGFX[highlightStatus];
        row++;
        highlightStatus += 0x3;
        gAmmoDigitsGFX[row] = 0x0;
        row++;
        gAmmoDigitsGFX[row] = 0x0;
        row++;
    }
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