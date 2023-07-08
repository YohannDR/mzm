#ifndef HUD_H
#define HUD_H

#include "types.h"

// Defines

#define HIGHLIGHT_STATUS_NOT_HIGHLIGHTED 0
#define HIGHLIGHT_STATUS_SELECTED 1
#define HIGHLIGHT_STATUS_HIGHLIGHTED 2

// Functions

void HUDUpdateOAM(void);
void HUDUpdateEnergyTanks(u8* pDst, const u8* pSrcNormal, const u8* pSrcRefill, u8 nbrTanks, u8 refillStage);
void HudDrawEnergy(u8 fileNumber);
void HudDrawMissileDigits(u16 hundreds, u16 tens, u16 ones, u16 highlightStatus);
void HudDrawSuperMissileDigits(u16 tens, u16 ones, u16 highlightStatus);
void HudDrawPowerBombDigits(u16 tens, u16 ones, u16 highlightStatus);
void HudDrawMissiles(u8 updateHighlight);
void HudDrawPowerBomb(u8 updateHighlight);
void HudDrawSuperMissiles(u8 updateHighlight);
void HUDUpdateGfx(void);
void HudDrawSuitless(void);
void HudDraw(void);

#endif /* HUD_H */