#ifndef HUD_STRUCT_H
#define HUD_STRUCT_H

#include "types.h"

// Structs

struct HudDigits {
    u8 ones;
    u8 tens;
    u8 hundreds;
    u8 thousands;
};

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

extern u8 gEnergyRefillAnimation;
extern u8 gMissileRefillAnimation;
extern u8 gSuperMissileRefillAnimation;
extern u8 gPowerBombRefillAnimation;

extern u8 gAmmoDigitsGfx[64];

#endif