#ifndef HUD_H
#define HUD_H

#include "types.h"

// Defines

#define HIGHLIGHT_STATUS_NOT_HIGHLIGHTED 0
#define HIGHLIGHT_STATUS_SELECTED 1
#define HIGHLIGHT_STATUS_HIGHLIGHTED 2

// Globals

extern u8 gHideHud;
extern u8 gMissileHighlightStatus;
extern u8 gPowerBombHighlightStatus;
extern u8 gSuperMissileHighlightStatus;

extern struct HudDigits gEnergyDigits;
extern struct HudDigits gMaxEnergyDigits;
extern struct HudDigits gMissileDigits;
extern struct HudDigits gPowerBombDigits;
extern struct HudDigits gSuperMissileDigits;

extern u8 gAmmoDigitsGFX[64];

// Structs

struct HudDigits {
    u8 ones;
    u8 tens;
    u8 hundreds;
    u8 thousands;
};

// Functions

void HUDUpdateOAM(void);
void HUDUpdateEnergyTanks(u8* pDst, u8* pSrcNormal, u8* pSrcRefill, u8 nbrTanks, u8 refillStage);
void HUDDrawEnergy(u8 fileNumber);
void HUDDrawMissileDigits(u16 hundreds, u16 tens, u16 ones, u16 highlightStatus);
void HUDDrawSuperMissileDigits(u16 tens, u16 ones, u16 highlightStatus);
void HUDDrawPowerBombDigits(u16 tens, u16 ones, u16 highlightStatus);
void HUDDrawMissiles(u8 updateHighlight);
void HUDDrawPowerBomb(u8 updateHighlight);
void HUDDrawSuperMissiles(u8 updateHighlight);
void HUDUpdateGFX(void);
void HUDDrawSuitless(void);
void HUDDraw(void);

#endif /* HUD_H */