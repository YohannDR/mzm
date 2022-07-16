#ifndef HUD_H
#define HUD_H

#include "types.h"

// Globals

extern u8 gHideHud;

// Functions

void HUDUpdateOAM(void);
void HUDUpdateEnergyTanks(u8* pDst, u8* pSrcNormal, u8* pSrcRefill, u8 nbrTanks, u8 refillStage);
void HUDDrawEnergy(u8 file_number);
void HUDDrawMissileDigits(u16 hundredsPlace, u16 tensPlace, u16 onesPlace, u16 highlightStatus);
void HUDDrawSuperMissileDigits(u16 tensPlace, u16 onesPlace, u16 highlightStatus);
void HUDDrawPowerBombDigits(u16 tensPlace, u16 onesPlace, u16 highlightStatus);
void HUDDrawMissiles(u8 updateHighlight);
void HUDDrawPowerBomb(u8 updateHighlight);
void HUDDrawSuperMissiles(u8 updateHighlight);
void HUDDrawHighlight(void);
void HUDDrawSuitless(void);
void HUDDraw(void);

#endif /* HUD_H */