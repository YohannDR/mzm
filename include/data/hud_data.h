#ifndef HUD_DATA_H
#define HUD_DATA_H

#include "types.h"

#define SUITLESS_BAR_NBR_ELEMS 56
#define SUITLESS_BAR_SIZE 256

// 32ba08

extern const u16 sCommonSpritesPAL[96];
extern const u32 sCommonSpritesGfx[3584];

extern const u8 sMissileDigitsGfx[2304];
extern const u8 sPowerBombDigitsGfx[2304];

extern const u8 sMissileHUDGfx_Inactive[64];
extern const u8 sMissileHUDGfx_Selected[64];
extern const u8 sMissileHUDGfx_Active[64];
extern const u8 sMissileHUDGfx_Refill1[64];
extern const u8 sMissileHUDGfx_Refill2[64];
extern const u8 sMissileHUDGfx_Refill3[64];

extern const u8 sSuperMissileHUDGfx_Inactive[64];
extern const u8 sSuperMissileHUDGfx_Selected[64];
extern const u8 sSuperMissileHUDGfx_Active[64];
extern const u8 sSuperMissileHUDGfx_Refill1[64];
extern const u8 sSuperMissileHUDGfx_Refill2[64];
extern const u8 sSuperMissileHUDGfx_Refill3[64];

extern const u8 sPowerBombHUDGfx_Inactive[64];
extern const u8 sPowerBombHUDGfx_Selected[64];
extern const u8 sPowerBombHUDGfx_Active[64];
extern const u8 sPowerBombHUDGfx_Refill1[64];
extern const u8 sPowerBombHUDGfx_Refill2[64];
extern const u8 sPowerBombHUDGfx_Refill3[64];

extern const u8 sEnergyDigitsTensGfx[10 * 32];
extern const u8 sEnergyDigitsOnesGfx[10 * 32];
extern const u8 sEnergyDigitsRefill1Gfx[20 * 32];
extern const u8 sEnergyDigitsRefill2Gfx[20 * 32];
extern const u8 sEnergyDigitsRefill3Gfx[20 * 32];

extern const u8 sEnergyTanksGfx_Zero[160 * 1];
extern const u8 sEnergyTanksGfx_One[160 * 2];
extern const u8 sEnergyTanksGfx_Two[160 * 3];
extern const u8 sEnergyTanksGfx_Three[160 * 4];
extern const u8 sEnergyTanksGfx_Four[160 * 5];
extern const u8 sEnergyTanksGfx_Five[160 * 6];
extern const u8 sEnergyTanksGfx_Six[160 * 7];
extern const u8 sEnergyTanksGfx_Seven[160 * 8];
extern const u8 sEnergyTanksGfx_Eight[160 * 9];
extern const u8 sEnergyTanksGfx_Nine[160 * 10];
extern const u8 sEnergyTanksGfx_Ten[160 * 11];
extern const u8 sEnergyTanksGfx_Eleven[160 * 12];
extern const u8 sEnergyTanksGfx_Twelve[160 * 13];

extern const u8 sEnergyTanksRefillGfx_One[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Two[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Three[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Four[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Five[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Six[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Seven[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Eight[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Nine[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Ten[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Eleven[160 * 3];
extern const u8 sEnergyTanksRefillGfx_Twelve[160 * 3];

extern const u8 sSuitlessHUDChargeBarGfx[SUITLESS_BAR_NBR_ELEMS * SUITLESS_BAR_SIZE];

// 8339aa8

#endif