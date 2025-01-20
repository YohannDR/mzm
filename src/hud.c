#include "hud.h"
#include "gba.h"
#include "macros.h"
#include "oam.h"

#include "data/hud_data.h"

#include "constants/minimap.h"
#include "constants/samus.h"

#include "structs/hud.h"
#include "structs/minimap.h"
#include "structs/samus.h"
#include "structs/game_state.h"

#define HUD_HEALTH_BAR_Y (SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2))
#define HUD_HEALTH_BAR_X (SUB_PIXEL_TO_PIXEL(0))

#define HUD_CHARGE_BAR_Y (SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE))
#define HUD_CHARGE_BAR_X (SUB_PIXEL_TO_PIXEL(PIXEL_SIZE))

#define HUD_MISSILES_Y (SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2))
#define HUD_MISSILES_X (SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE))

#define HUD_SUPER_MISSILES_Y (SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2))
#define HUD_SUPER_MISSILES_X (SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5))

#define HUD_POWER_BOMBS_Y (SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2))
#define HUD_POWER_BOMBS_X (SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE))

#define HUD_MINIMAP_Y (-SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 6))
#define HUD_MINIMAP_X (SCREEN_SIZE_X - SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE))

#define HUD_MINIMAP_SQUARE_Y (HUD_MINIMAP_Y + SUB_PIXEL_TO_PIXEL(BLOCK_SIZE))
#define HUD_MINIMAP_SQUARE_X (HUD_MINIMAP_X + SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE))

/**
 * @brief 52308 | 35c | Updates the OAM of the HUD
 * 
 */
void HudUpdateOam(void)
{
    u32 oamSlot;
    u16* dst;
    struct Equipment* pEquipment = &gEquipment;
    
    oamSlot = 0;

    if (!gHideHud)
    {
        dst = (u16*)gOamData;

        // Left part of health bar
        *dst++ = 0;
        gOamData[oamSlot].split.y = HUD_HEALTH_BAR_Y;
        gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;

        *dst++ = 0;
        gOamData[oamSlot].split.x = HUD_HEALTH_BAR_X;
        gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;
        
        *dst++ = 0;
        gOamData[oamSlot].split.tileNum = 0x20 * 2 + 0x10;
        gOamData[oamSlot].split.paletteNum = 4;

        dst++;
        oamSlot++;

        // Right part of health bar
        *dst++ = 0;
        gOamData[oamSlot].split.y = HUD_HEALTH_BAR_Y;
        gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;

        *dst++ = 0;
        gOamData[oamSlot].split.x = HUD_HEALTH_BAR_X + 32;
        gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;
        
        *dst++ = 0;
        gOamData[oamSlot].split.tileNum = 0x20 * 2 + 0x14;
        gOamData[oamSlot].split.paletteNum = 4;

        dst++;
        oamSlot++;

        if (pEquipment->suitType == SUIT_SUITLESS)
        {
            // Left part of charge bar
            *dst++ = 0;
            gOamData[oamSlot].split.y = HUD_CHARGE_BAR_Y;
            gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;
            
            *dst++ = 0;
            gOamData[oamSlot].split.x = HUD_CHARGE_BAR_X;
            gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;
            
            *dst++ = 0;
            gOamData[oamSlot].split.tileNum = 0x20 * 4 + 0x8;
            gOamData[oamSlot].split.paletteNum = 4;

            dst++;
            oamSlot++;
            
            // Right part of charge bar
            *dst++ = 0;
            gOamData[oamSlot].split.y = HUD_CHARGE_BAR_Y;
            gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;
            
            *dst++ = 0;
            gOamData[oamSlot].split.x = HUD_CHARGE_BAR_X + 32;
            gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;
            
            *dst++ = 0;
            gOamData[oamSlot].split.tileNum = 0x20 * 4 + 0xC;
            gOamData[oamSlot].split.paletteNum = 4;

            dst++;
            oamSlot++;
        }
        else
        {
            if (pEquipment->maxMissiles != 0)
            {
                // Missile digits
                
                *dst++ = 0;
                gOamData[oamSlot].split.y = HUD_MISSILES_Y;
                gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;

                *dst++ = 0;
                gOamData[oamSlot].split.x = HUD_MISSILES_X;
                gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;

                *dst++ = 0;
                gOamData[oamSlot].split.tileNum = 0x20 * 3 + 0x10;
                gOamData[oamSlot].split.paletteNum = 4;

                dst++;
                oamSlot++;
            }

            if (pEquipment->maxSuperMissiles != 0)
            {
                // Super missile digits

                *dst++ = 0;
                gOamData[oamSlot].split.y = HUD_SUPER_MISSILES_Y;
                gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;

                *dst++ = 0;
                gOamData[oamSlot].split.x = HUD_SUPER_MISSILES_X;
                gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;

                *dst++ = 0;
                gOamData[oamSlot].split.tileNum = 0x20 * 3 + 0x14;
                gOamData[oamSlot].split.paletteNum = 4;

                dst++;
                oamSlot++;
            }

            if (pEquipment->maxPowerBombs != 0)
            {
                // Power bomb digits

                *dst++ = 0;
                gOamData[oamSlot].split.y = HUD_POWER_BOMBS_Y;
                gOamData[oamSlot].split.shape = OAM_SHAPE_HORIZONTAL;

                *dst++ = 0;
                gOamData[oamSlot].split.x = HUD_POWER_BOMBS_X;
                gOamData[oamSlot].split.size = OAM_SIZE_H_32x8;

                *dst++ = 0;
                gOamData[oamSlot].split.tileNum = 0x20 * 2 + 0x18;
                gOamData[oamSlot].split.paletteNum = 4;

                dst++;
                oamSlot++;
            }
        }

        // Minimap white square
        *dst++ = 0;
        gOamData[oamSlot].split.y = HUD_MINIMAP_SQUARE_Y;
        gOamData[oamSlot].split.shape = OAM_SHAPE_SQUARE;

        *dst++ = 0;
        gOamData[oamSlot].split.x = HUD_MINIMAP_SQUARE_X;
        gOamData[oamSlot].split.size = OAM_SIZE_S_8x8;

        *dst++ = 0;

        if (MOD_BLOCK_AND(gFrameCounter8Bit, CONVERT_SECONDS(2.f / 15)))
            gOamData[oamSlot].split.tileNum = 0x20 * 5 + 0x1F;
        else
            gOamData[oamSlot].split.tileNum = 0x20 * 10;

        gOamData[oamSlot].split.paletteNum = 5;

        dst++;
        oamSlot++;

        // Minimap
        *dst++ = 0;
        gOamData[oamSlot].split.y = HUD_MINIMAP_Y;
        gOamData[oamSlot].split.shape = OAM_SHAPE_SQUARE;

        *dst++ = 0;
        gOamData[oamSlot].split.x = HUD_MINIMAP_X;
        gOamData[oamSlot].split.size = OAM_SIZE_S_32x32;

        *dst = 0;
        gOamData[oamSlot].split.tileNum = 0x20 * 6 + 0x1C;
        gOamData[oamSlot].split.paletteNum = 5;
        
        oamSlot++;
    }

    gNextOamSlot = oamSlot;
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
void HudUpdateEnergyTanks(u8* pDst, const u8* pSrcNormal, const u8* pSrcRefill, u8 nbrTanks, u8 refillStage)
{
    if (refillStage == 0)
    {
        DMA_SET(3, pSrcRefill, pDst + 0x40, C_32_2_16(DMA_ENABLE, 0x50));
    }
    else if (refillStage == 1)
    {
        DMA_SET(3, pSrcRefill + 0xA0 * refillStage, pDst + 0x40, C_32_2_16(DMA_ENABLE, 0x50));
    }
    else if (refillStage == 2)
    {
        DMA_SET(3, pSrcRefill + 0xA0 * refillStage, pDst + 0x40, C_32_2_16(DMA_ENABLE, 0x50));
    }
    else if (refillStage == 3)
    {
        DMA_SET(3, pSrcNormal + 0xA0 * nbrTanks, pDst + 0x40, C_32_2_16(DMA_ENABLE, 0x50));
    }
}

/**
 * @brief 526d4 | 598 | Updates the energy HUD
 * 
 * @param fileNumber File number
 */
void HudDrawEnergy(u8 fileNumber)
{
    u8* dst;
    u16 maxEnergy;
    u16 energy;
    u8 nbrTanks;
    u8 digit;
    u8 needUpdate;
    u16 v;

    if (fileNumber != 0)
    {
        if (fileNumber < 4)
        {
            gEnergyRefillAnimation = 0;
            gEnergyDigits.ones = 0xF;
            gEnergyDigits.tens = 0xF;
            gEnergyDigits.hundreds = 0xF;
            gEnergyDigits.thousands = 0xF;
            gMaxEnergyDigits.ones = 0xF;
            gMaxEnergyDigits.tens = 0xF;
            gMaxEnergyDigits.hundreds = 0xF;
            gMaxEnergyDigits.thousands = 0xF;
            dst = (VRAM_BASE + 0x20 + (fileNumber - 1) * 0xE0);
        }
        else
            return;
    }
    else
        dst = VRAM_OBJ + 0xA00;

    needUpdate = FALSE;

    v = gEquipment.maxEnergy;

    digit = (u8)(v / 1000) % 10;
    if (gMaxEnergyDigits.thousands != digit)
    {
        gMaxEnergyDigits.thousands = digit;
        needUpdate++;
    }

    nbrTanks = v / 100;
    digit = nbrTanks % 10;
    if (gMaxEnergyDigits.hundreds != digit)
    {
        gMaxEnergyDigits.hundreds = digit;
        needUpdate++;
    }

    digit = (u8)(v / 10) % 10;
    if (gMaxEnergyDigits.tens != digit)
    {
        gMaxEnergyDigits.tens = digit;
        needUpdate++;
    }

    digit = v % 10;
    if (gMaxEnergyDigits.ones != digit)
    {
        gMaxEnergyDigits.ones = digit;
        needUpdate++;
    }

    energy = gEquipment.currentEnergy;

    digit = (u8)(energy / 1000) % 10;
    if (gEnergyDigits.thousands != digit)
    {
        gEnergyDigits.thousands = digit;
        needUpdate++;
    }

    maxEnergy = (u8)(energy / 100);
    digit = maxEnergy % 10;
    if (gEnergyDigits.hundreds != digit)
    {
        gEnergyDigits.hundreds = digit;
        needUpdate++;
    }

    digit = (u8)(energy / 10) % 10;
    if (gEnergyDigits.tens != digit)
    {
        gEnergyDigits.tens = digit;
        needUpdate++;

        DMA_SET(3, &sEnergyDigitsTensGfx[digit * 32], dst, C_32_2_16(DMA_ENABLE, 16));
    }

    digit = energy % 10;
    if (gEnergyDigits.ones != digit)
    {
        gEnergyDigits.ones = digit;
        needUpdate++;

        DMA_SET(3, &sEnergyDigitsOnesGfx[digit * 32], dst + 32, C_32_2_16(DMA_ENABLE, 16));
    }

    if (needUpdate)
    {
        if (energy < 30)
            gEquipment.lowHealth = TRUE;
        else
            gEquipment.lowHealth = FALSE;

        switch (nbrTanks)
        {
            case 0:
                DMA_SET(3, sEnergyTanksGfx_Zero, dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;

            case 1:
                DMA_SET(3, (sEnergyTanksGfx_One + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 2:
                DMA_SET(3, (sEnergyTanksGfx_Two + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 3:
                DMA_SET(3, (sEnergyTanksGfx_Three + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 4:
                DMA_SET(3, (sEnergyTanksGfx_Four + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 5:
                DMA_SET(3, (sEnergyTanksGfx_Five + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 6:
                DMA_SET(3, (sEnergyTanksGfx_Six + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 7:
                DMA_SET(3, (sEnergyTanksGfx_Seven + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 8:
                DMA_SET(3, (sEnergyTanksGfx_Eight + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 9:
                DMA_SET(3, (sEnergyTanksGfx_Nine + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 10:
                DMA_SET(3, (sEnergyTanksGfx_Ten + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 11:
                DMA_SET(3, (sEnergyTanksGfx_Eleven + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
                
            case 12:
                DMA_SET(3, (sEnergyTanksGfx_Twelve + (maxEnergy * 160)), dst + 64, C_32_2_16(DMA_ENABLE, 80));
                break;
        }
    }

    if (gEnergyRefillAnimation != 0)
    {
        if (gEnergyRefillAnimation == 13)
        {
            DMA_SET(3, &sEnergyDigitsRefill1Gfx[gEnergyDigits.tens * 32], dst, C_32_2_16(DMA_ENABLE, 16));
            DMA_SET(3, &sEnergyDigitsRefill1Gfx[gEnergyDigits.ones * 32 + 10 * 32], dst + 32, C_32_2_16(DMA_ENABLE, 16));
            needUpdate = 0;
        }
        else if (gEnergyRefillAnimation == 10)
        {
            DMA_SET(3, &sEnergyDigitsRefill2Gfx[gEnergyDigits.tens * 32], dst, C_32_2_16(DMA_ENABLE, 16));
            DMA_SET(3, &sEnergyDigitsRefill2Gfx[gEnergyDigits.ones * 32 + 10 * 32], dst + 32, C_32_2_16(DMA_ENABLE, 16));
            needUpdate = 1;
        }
        else if (gEnergyRefillAnimation == 4)
        {
            DMA_SET(3, &sEnergyDigitsRefill3Gfx[gEnergyDigits.tens * 32], dst, C_32_2_16(DMA_ENABLE, 16));
            DMA_SET(3, &sEnergyDigitsRefill3Gfx[gEnergyDigits.ones * 32 + 10 * 32], dst + 32, C_32_2_16(DMA_ENABLE, 16));
            needUpdate = 2;
        }
        else if (gEnergyRefillAnimation == 1)
        {
            DMA_SET(3, &sEnergyDigitsTensGfx[gEnergyDigits.tens * 32], dst, C_32_2_16(DMA_ENABLE, 16));
            DMA_SET(3, &sEnergyDigitsTensGfx[gEnergyDigits.ones * 32 + 10 * 32], dst + 32, C_32_2_16(DMA_ENABLE, 16));
            needUpdate = 3;
        }
        else
            return;
        switch (nbrTanks)
        {
            case 1:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_One, sEnergyTanksRefillGfx_One, nbrTanks, needUpdate);
                break;
    
            case 2:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Two, sEnergyTanksRefillGfx_Two, nbrTanks, needUpdate);
                break;
    
            case 3:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Three, sEnergyTanksRefillGfx_Three, nbrTanks, needUpdate);
                break;
    
            case 4:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Four, sEnergyTanksRefillGfx_Four, nbrTanks, needUpdate);
                break;
    
            case 5:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Five, sEnergyTanksRefillGfx_Five, nbrTanks, needUpdate);
                break;
    
            case 6:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Six, sEnergyTanksRefillGfx_Six, nbrTanks, needUpdate);
                break;
    
            case 7:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Seven, sEnergyTanksRefillGfx_Seven, nbrTanks, needUpdate);
                break;
    
            case 8:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Eight, sEnergyTanksRefillGfx_Eight, nbrTanks, needUpdate);
                break;
    
            case 9:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Nine, sEnergyTanksRefillGfx_Nine, nbrTanks, needUpdate);
                break;
    
            case 10:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Ten, sEnergyTanksRefillGfx_Ten, nbrTanks, needUpdate);
                break;
    
            case 11:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Eleven, sEnergyTanksRefillGfx_Eleven, nbrTanks, needUpdate);
                break;
    
            case 12:
                HudUpdateEnergyTanks(dst, sEnergyTanksGfx_Twelve, sEnergyTanksRefillGfx_Twelve, nbrTanks, needUpdate);
                break;
        }
    }
}

/**
 * @brief 52c6c | 100 | Draws the missile digits to the ammo digits
 * 
 * @param hundreds Hundreds
 * @param tens Tens
 * @param ones Ones
 * @param highlightStatus Highlight status
 */
void HudDrawMissileDigits(u16 hundreds, u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[hundreds];
        row++;
        hundreds++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[hundreds];
        row++;
        hundreds += 0x3;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[tens];
        row++;
        tens++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[tens];
        row++;
        tens += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[ones];
        row++;
        ones++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[ones];
        row++;
        ones += 0x3;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[highlightStatus];
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
void HudDrawSuperMissileDigits(u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[tens];
        row++;
        tens++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[tens];
        row++;
        tens += 0x3;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[ones];
        row++;
        ones++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[ones];
        row++;
        ones += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGfx[row] = sMissileDigitsGfx[highlightStatus];
        row++;
        highlightStatus += 0x3;
        gAmmoDigitsGfx[row] = 0;
        row++;
        gAmmoDigitsGfx[row] = 0;
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
void HudDrawPowerBombDigits(u16 tens, u16 ones, u16 highlightStatus)
{
    u8 row;
    u8 i;

    row = 0;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[tens];
        row++;
        tens++;
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[tens];
        row++;
        tens += 0x3;
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[ones];
        row++;
        ones++;
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[ones];
        row++;
        ones += 0x3;
    }

    row = 0x20;
    for (i = 0; i < 8; i++)
    {
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[highlightStatus];
        row++;
        highlightStatus++;
        gAmmoDigitsGfx[row] = sPowerBombDigitsGfx[highlightStatus];
        row++;
        highlightStatus += 0x3;
        gAmmoDigitsGfx[row] = 0;
        row++;
        gAmmoDigitsGfx[row] = 0;
        row++;
    }
}

/**
 * @brief 52f1c | 220 | Updates the missile HUD
 * 
 * @param updateHighlight Update highlight flag
 */
void HudDrawMissiles(u8 updateHighlight)
{
    u16 refillStage;
    u8 digit;
    u8 needUpdate;
    u16 missiles;
    u16 hundreds;
    u16 tens;
    u16 ones;

    needUpdate = FALSE;

    if (updateHighlight)
        needUpdate++;
    else
    {
        // Update missile digits
        missiles = gEquipment.currentMissiles;

        // Update hundreds
        digit = missiles / 100 % 10;
        if (gMissileDigits.hundreds != digit)
        {
            gMissileDigits.hundreds = digit;
            needUpdate++;
        }

        // Update tens
        digit = missiles / 10 % 10;
        if (gMissileDigits.tens != digit)
        {
            gMissileDigits.tens = digit;
            needUpdate++;
        }

        // Update ones
        digit = missiles % 10;
        if (gMissileDigits.ones != digit)
        {
            gMissileDigits.ones = digit;
            needUpdate++;
        }
    }

    if (needUpdate)
    {
        hundreds = gMissileDigits.hundreds;
        tens = gMissileDigits.tens;
        ones = gMissileDigits.ones;

        // Check set empty Gfx
        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        // Offset for graphics
        hundreds *= 32;
        tens *= 32;
        ones *= 32;

        missiles = gMissileHighlightStatus * 384;
        
        // Offset depending on highlight
        hundreds += missiles;
        tens += missiles;
        ones += missiles;
        refillStage = missiles + 352;
        
        // Update Gfx
        HudDrawMissileDigits(hundreds, tens, ones, refillStage);
        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10E40, C_32_2_16(DMA_ENABLE, 32));
    }

    if (gMissileRefillAnimation != 0 && !updateHighlight)
    {
        hundreds = gMissileDigits.hundreds;
        tens = gMissileDigits.tens;
        ones = gMissileDigits.ones;

        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        hundreds *= 32;
        tens *= 32;
        ones *= 32;

        refillStage = 352;
        
        // Update missile symbol for refill
        if (gMissileRefillAnimation == 13)
        {
            missiles = 0x480;
            DMA_SET(3, sMissileHUDGfx_Refill1, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gMissileRefillAnimation == 10)
        {
            missiles = 0x600;
            DMA_SET(3, sMissileHUDGfx_Refill2, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gMissileRefillAnimation == 4)
        {
            missiles = 0x780;
            DMA_SET(3, sMissileHUDGfx_Refill3, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gMissileRefillAnimation == 1)
        {
            needUpdate = gMissileHighlightStatus;
            missiles = needUpdate * 384;
            DMA_SET(3, sMissileHUDGfx_Inactive + (gMissileHighlightStatus * 64), VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
        }
        else
            return;

        hundreds += missiles;
        tens += missiles;
        ones += missiles;
        refillStage += missiles;
        HudDrawMissileDigits(hundreds, tens, ones, refillStage);

        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10E40, C_32_2_16(DMA_ENABLE, 32));
    }
}

/**
 * @brief 5313c | 1f8 | Updates the power bomb HUD
 * 
 * @param updateHighlight Update highlight flag
 */
void HudDrawPowerBomb(u8 updateHighlight)
{
    u16 refillStage;
    u8 digit;
    u8 needUpdate;
    u16 powerBombs;
    u16 hundreds;
    u16 tens;
    u16 ones;

    needUpdate = FALSE;

    if (updateHighlight)
        needUpdate++;
    else
    {
        // Update missile digits
        powerBombs = gEquipment.currentPowerBombs;

        // Update hundreds
        digit = powerBombs / 100 % 10;
        if (gPowerBombDigits.hundreds != digit)
        {
            gPowerBombDigits.hundreds = digit;
            needUpdate++;
        }

        // Update tens
        digit = powerBombs / 10 % 10;
        if (gPowerBombDigits.tens != digit)
        {
            gPowerBombDigits.tens = digit;
            needUpdate++;
        }

        // Update ones
        digit = powerBombs % 10;
        if (gPowerBombDigits.ones != digit)
        {
            gPowerBombDigits.ones = digit;
            needUpdate++;
        }
    }

    if (needUpdate)
    {
        hundreds = gPowerBombDigits.hundreds;
        tens = gPowerBombDigits.tens;
        ones = gPowerBombDigits.ones;

        // Check set empty Gfx
        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        // Offset for graphics
        tens *= 32;
        ones *= 32;

        powerBombs = gPowerBombHighlightStatus * 384;
        
        // Offset depending on highlight
        tens += powerBombs;
        ones += powerBombs;
        refillStage = powerBombs + 352;
        
        // Update Gfx
        HudDrawPowerBombDigits(tens, ones, refillStage);
        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10B40, C_32_2_16(DMA_ENABLE, 32));
    }

    if (gPowerBombRefillAnimation != 0 && !updateHighlight)
    {
        hundreds = gPowerBombDigits.hundreds;
        tens = gPowerBombDigits.tens;
        ones = gPowerBombDigits.ones;

        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        tens *= 32;
        ones *= 32;

        refillStage = 352;
        
        // Update power bomb symbol for refill
        if (gPowerBombRefillAnimation == 0xD)
        {
            powerBombs = 0x480;
            DMA_SET(3, sPowerBombHUDGfx_Refill1, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gPowerBombRefillAnimation == 0xA)
        {
            powerBombs = 0x600;
            DMA_SET(3, sPowerBombHUDGfx_Refill2, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gPowerBombRefillAnimation == 0x4)
        {
            powerBombs = 0x780;
            DMA_SET(3, sPowerBombHUDGfx_Refill3, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gPowerBombRefillAnimation == 0x1)
        {
            needUpdate = gPowerBombHighlightStatus;
            powerBombs = needUpdate * 384;
            DMA_SET(3, sPowerBombHUDGfx_Inactive + (gPowerBombHighlightStatus * 64), VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
        }
        else
            return;

        tens += powerBombs;
        ones += powerBombs;
        refillStage += powerBombs;
        HudDrawPowerBombDigits(tens, ones, refillStage);

        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10B40, C_32_2_16(DMA_ENABLE, 32));
    }
}

/**
 * @brief 53334 | 1f8 | Updates the super missile HUD
 * 
 * @param updateHighlight Update highlight flag
 */
void HudDrawSuperMissiles(u8 updateHighlight)
{
    u16 refillStage;
    u8 digit;
    u8 needUpdate;
    u16 superMissiles;
    u16 hundreds;
    u16 tens;
    u16 ones;

    needUpdate = FALSE;

    if (updateHighlight)
        needUpdate++;
    else
    {
        // Update missile digits
        superMissiles = gEquipment.currentSuperMissiles;

        // Update hundreds
        digit = superMissiles / 100 % 10;
        if (gSuperMissileDigits.hundreds != digit)
        {
            gSuperMissileDigits.hundreds = digit;
            needUpdate++;
        }

        // Update tens
        digit = superMissiles / 10 % 10;
        if (gSuperMissileDigits.tens != digit)
        {
            gSuperMissileDigits.tens = digit;
            needUpdate++;
        }

        // Update ones
        digit = superMissiles % 10;
        if (gSuperMissileDigits.ones != digit)
        {
            gSuperMissileDigits.ones = digit;
            needUpdate++;
        }
    }

    if (needUpdate)
    {
        hundreds = gSuperMissileDigits.hundreds;
        tens = gSuperMissileDigits.tens;
        ones = gSuperMissileDigits.ones;

        // Check set empty Gfx
        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        // Offset for graphics
        tens *= 32;
        ones *= 32;

        superMissiles = gSuperMissileHighlightStatus * 384;
        
        // Offset depending on highlight
        tens += superMissiles;
        ones += superMissiles;
        refillStage = superMissiles + 352;
        
        // Update Gfx
        HudDrawSuperMissileDigits(tens, ones, refillStage);
        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10EC0, C_32_2_16(DMA_ENABLE, 32));
    }

    if (gSuperMissileRefillAnimation != 0 && !updateHighlight)
    {
        hundreds = gSuperMissileDigits.hundreds;
        tens = gSuperMissileDigits.tens;
        ones = gSuperMissileDigits.ones;

        if (hundreds == 0)
        {
            hundreds = 10;
            if (tens == 0)
                tens = 10;
        }

        tens *= 32;
        ones *= 32;

        refillStage = 352;
        
        // Update power bomb symbol for refill
        if (gSuperMissileRefillAnimation == 0xD)
        {
            superMissiles = 0x480;
            DMA_SET(3, sSuperMissileHUDGfx_Refill1, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gSuperMissileRefillAnimation == 0xA)
        {
            superMissiles = 0x600;
            DMA_SET(3, sSuperMissileHUDGfx_Refill2, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gSuperMissileRefillAnimation == 0x4)
        {
            superMissiles = 0x780;
            DMA_SET(3, sSuperMissileHUDGfx_Refill3, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
        }
        else if (gSuperMissileRefillAnimation == 0x1)
        {
            needUpdate = gSuperMissileHighlightStatus;
            superMissiles = needUpdate * 384;
            DMA_SET(3, sSuperMissileHUDGfx_Inactive + (gSuperMissileHighlightStatus * 64), VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
        }
        else
            return;

        tens += superMissiles;
        ones += superMissiles;
        refillStage += superMissiles;
        HudDrawSuperMissileDigits(tens, ones, refillStage);

        DMA_SET(3, gAmmoDigitsGfx, VRAM_BASE + 0x10EC0, C_32_2_16(DMA_ENABLE, 32));
    }
}

/**
 * @brief 5352c | 3bc | Updates the Gfx of the HUD
 * 
 */
void HudUpdateGfx(void)
{
    // Update missile Gfx
    if (gMissileHighlightStatus == HIGHLIGHT_STATUS_HIGHLIGHTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_MISSILE))
        {
            if (gSamusWeaponInfo.missilesSelected || gEquipment.currentMissiles == 0)
            {
                DMA_SET(3, sMissileHUDGfx_Inactive, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
                gMissileHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;
            }
            else
            {
                DMA_SET(3, sMissileHUDGfx_Selected, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
                gMissileHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
            }

            HudDrawMissiles(TRUE);
        }
    }
    else if (gMissileHighlightStatus == HIGHLIGHT_STATUS_SELECTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_MISSILE))
        {
            if (gSamusWeaponInfo.missilesSelected || gEquipment.currentMissiles == 0)
            {
                DMA_SET(3, sMissileHUDGfx_Inactive, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
                gMissileHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;

                HudDrawMissiles(TRUE);
            }
        }
        else
        {
            DMA_SET(3, sMissileHUDGfx_Active, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
            gMissileHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
            
            HudDrawMissiles(TRUE);
        }
    }
    else if (gMissileHighlightStatus == HIGHLIGHT_STATUS_NOT_HIGHLIGHTED)
    {
        if (gSamusWeaponInfo.weaponHighlighted & WH_MISSILE)
        {
            DMA_SET(3, sMissileHUDGfx_Active, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
            gMissileHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
                
            HudDrawMissiles(TRUE);
        }
        else
        {
            if (!gSamusWeaponInfo.missilesSelected && gEquipment.currentMissiles != 0)
            {
                DMA_SET(3, sMissileHUDGfx_Selected, VRAM_BASE + 0x10E00, C_32_2_16(DMA_ENABLE, 32));
                gMissileHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
                
                HudDrawMissiles(TRUE);
            }
        }
    }

    // Update power bomb Gfx
    if (gPowerBombHighlightStatus == HIGHLIGHT_STATUS_HIGHLIGHTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_POWER_BOMB))
        {
            if (gEquipment.currentPowerBombs != 0)
            {
                DMA_SET(3, sPowerBombHUDGfx_Selected, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
                gPowerBombHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
            }
            else
            {
                DMA_SET(3, sPowerBombHUDGfx_Inactive, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
                gPowerBombHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;
            }

            HudDrawPowerBomb(TRUE);
        }
    }
    
    if (gPowerBombHighlightStatus == HIGHLIGHT_STATUS_SELECTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_POWER_BOMB))
        {
            if (gEquipment.currentPowerBombs == 0)
            {
                DMA_SET(3, sPowerBombHUDGfx_Inactive, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
                gPowerBombHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;
                
                HudDrawPowerBomb(TRUE);
            }
        }
        else
        {
            DMA_SET(3, sPowerBombHUDGfx_Active, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
            gPowerBombHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
            
            HudDrawPowerBomb(TRUE);
        }
    }
    else if (gPowerBombHighlightStatus == HIGHLIGHT_STATUS_NOT_HIGHLIGHTED)
    {
        if (gSamusWeaponInfo.weaponHighlighted & WH_POWER_BOMB)
        {
            DMA_SET(3, sPowerBombHUDGfx_Active, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
            gPowerBombHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
                
            HudDrawPowerBomb(TRUE);
        }
        else
        {
            if (gEquipment.currentPowerBombs != 0)
            {
                DMA_SET(3, sPowerBombHUDGfx_Selected, VRAM_BASE + 0x10B00, C_32_2_16(DMA_ENABLE, 32));
                gPowerBombHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
                
                HudDrawPowerBomb(TRUE);
            }
        }
    }

    // Update super missile Gfx
    if (gSuperMissileHighlightStatus == HIGHLIGHT_STATUS_HIGHLIGHTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_SUPER_MISSILE))
        {
            if (!gSamusWeaponInfo.missilesSelected)
            {
                DMA_SET(3, sSuperMissileHUDGfx_Inactive, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
                gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;
            }
            else
            {
                DMA_SET(3, sSuperMissileHUDGfx_Selected, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
                gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
            }

            HudDrawSuperMissiles(TRUE);
        }
    }
    else if (gSuperMissileHighlightStatus == HIGHLIGHT_STATUS_SELECTED)
    {
        if (!(gSamusWeaponInfo.weaponHighlighted & WH_SUPER_MISSILE))
        {
            if (!gSamusWeaponInfo.missilesSelected)
            {
                DMA_SET(3, sSuperMissileHUDGfx_Inactive, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
                gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_NOT_HIGHLIGHTED;
                
                HudDrawSuperMissiles(TRUE);
            }
        }
        else
        {
            DMA_SET(3, sSuperMissileHUDGfx_Active, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
            gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
        
            HudDrawSuperMissiles(TRUE);
        }
    }
    else if (gSuperMissileHighlightStatus == HIGHLIGHT_STATUS_NOT_HIGHLIGHTED)
    {
        if (gSamusWeaponInfo.weaponHighlighted & WH_SUPER_MISSILE)
        {
            DMA_SET(3, sSuperMissileHUDGfx_Active, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
            gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_HIGHLIGHTED;
                
            HudDrawSuperMissiles(TRUE);
        }
        else
        {
            if (gSamusWeaponInfo.missilesSelected)
            {
                DMA_SET(3, sSuperMissileHUDGfx_Selected, VRAM_BASE + 0x10E80, C_32_2_16(DMA_ENABLE, 32));
                gSuperMissileHighlightStatus = HIGHLIGHT_STATUS_SELECTED;
                
                HudDrawSuperMissiles(TRUE);
            }
        }
    }

    // Update minimap Gfx
    if (gUpdateMinimapFlag != MINIMAP_UPDATE_FLAG_NONE)
    {
        gUpdateMinimapFlag--;
        DMA_SET(3, (gMinimapTilesGfx + gUpdateMinimapFlag * 24), (VRAM_BASE + 0x11F80) + (gUpdateMinimapFlag * 1024), C_32_2_16(DMA_ENABLE, 48));
    }
}

/**
 * @brief 538e8 | 48 | Draws the HUD (for suitless)
 * 
 */
void HudDrawSuitless(void)
{
    u8 chargeCounter;
    u8 normalized;

    chargeCounter = gSamusWeaponInfo.chargeCounter;
    if (chargeCounter >= SUITLESS_BAR_NBR_ELEMS * 2)
    {
        // Normalize to 0
        normalized = gSamusWeaponInfo.chargeCounter - SUITLESS_BAR_NBR_ELEMS * 2;

        // Switch between the last 4 graphics
        chargeCounter = normalized / 4 + SUITLESS_BAR_NBR_ELEMS - 4;
    }
    else
    {
        chargeCounter /= 2;
    }

    // Transfer graphics
    if (chargeCounter < SUITLESS_BAR_NBR_ELEMS)
    {
        DMA_SET(3, &sSuitlessHUDChargeBarGfx[chargeCounter * SUITLESS_BAR_SIZE], VRAM_BASE + 0x11100,
            C_32_2_16(DMA_ENABLE, SUITLESS_BAR_SIZE / 2));
    }
}

/**
 * 53930 | 38 | Main function that draws the HUD
 * 
 */
void HudDraw(void)
{
    HudDrawEnergy(0);

    HudDrawMissiles(FALSE);
    HudDrawPowerBomb(FALSE);
    HudDrawSuperMissiles(FALSE);

    HudUpdateGfx();

    if (gEquipment.suitType == SUIT_SUITLESS)
        HudDrawSuitless();

    HudUpdateOam();
}
