#ifndef HUD_H
#define HUD_H

#include "types.h"

void HUDUpdateOAM(void);
void HUDUpdateEnergyTanks(u8* dst, u8* normal_src, u8* refill_src, u8 nbr_tanks, u8 refill_stage);
void HUDDrawEnergy(u8 file_number);
void HUDDrawMissileDigits(u16 hundreds_place, u16 tens_place, u16 ones_place, u16 highlight_status);
void HUDDrawSuperMissileDigits(u16 tens_place, u16 ones_place, u16 highlight_status);
void HUDDrawPowerBombDigits(u16 tens_place, u16 ones_place, u16 highlight_status);
void HUDDrawMissiles(u8 update_highlight);
void HUDDrawPowerBomb(u8 update_highlight);
void HUDDrawSuperMissiles(u8 update_highlight);
void HUDDrawHighlight(void);
void HUDDrawSuitless(void);
void HUDDraw(void);

#endif /* HUD_H */