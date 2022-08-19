#include "hud.h"
#include "globals.h"

void HUDUpdateOAM(void)
{

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

void HUDDrawSuitless(void)
{

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