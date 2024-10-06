#ifndef HUD_H
#define HUD_H

#include "types.h"

// Defines

enum HudHighlightStatus {
    HIGHLIGHT_STATUS_NOT_HIGHLIGHTED,
    HIGHLIGHT_STATUS_SELECTED,
    HIGHLIGHT_STATUS_HIGHLIGHTED
};

// Functions

void HudUpdateOam(void);
void HudUpdateEnergyTanks(u8* pDst, const u8* pSrcNormal, const u8* pSrcRefill, u8 nbrTanks, u8 refillStage);
void HudDrawEnergy(u8 fileNumber);
void HudDrawMissileDigits(u16 hundreds, u16 tens, u16 ones, u16 highlightStatus);
void HudDrawSuperMissileDigits(u16 tens, u16 ones, u16 highlightStatus);
void HudDrawPowerBombDigits(u16 tens, u16 ones, u16 highlightStatus);
void HudDrawMissiles(u8 updateHighlight);
void HudDrawPowerBomb(u8 updateHighlight);
void HudDrawSuperMissiles(u8 updateHighlight);
void HudUpdateGfx(void);
void HudDrawSuitless(void);
void HudDraw(void);

#endif /* HUD_H */