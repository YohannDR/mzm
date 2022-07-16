#include "hud.h"
#include "globals.h"

void HUDUpdateOAM(void)
{

}

void HUDUpdateEnergyTanks(u8* pDst, u8* pSrcNormal, u8* pSrcRefill, u8 nbrTanks, u8 refillStage)
{

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