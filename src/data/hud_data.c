#include "data/hud_data.h"
#include "macros.h"

// 32ba08

const u16 sCommonSpritesPAL[96] = INCBIN_U16("data/common/Common.pal");
const u32 sCommonSpritesGFX[3584] = INCBIN_U32("data/common/Common.gfx");

const u8 sMissileDigitsGFX[2304] = INCBIN_U8("data/common/MissileDigits.gfx");
const u8 sPowerBombDigitsGFX[2304] = INCBIN_U8("data/common/PowerBombDigits.gfx");

const u8 sMissileHUDGFX_Inactive[64] = INCBIN_U8("data/common/MissileHUDInactive.gfx");
const u8 sMissileHUDGFX_Selected[64] = INCBIN_U8("data/common/MissileHUDSelected.gfx");
const u8 sMissileHUDGFX_Active[64] = INCBIN_U8("data/common/MissileHUDActive.gfx");
const u8 sMissileHUDGFX_Refill1[64] = INCBIN_U8("data/common/MissileHUDRefill1.gfx");
const u8 sMissileHUDGFX_Refill2[64] = INCBIN_U8("data/common/MissileHUDRefill2.gfx");
const u8 sMissileHUDGFX_Refill3[64] = INCBIN_U8("data/common/MissileHUDRefill3.gfx");

const u8 sSuperMissileHUDGFX_Inactive[64] = INCBIN_U8("data/common/SuperMissileHUDInactive.gfx");
const u8 sSuperMissileHUDGFX_Selected[64] = INCBIN_U8("data/common/SuperMissileHUDSelected.gfx");
const u8 sSuperMissileHUDGFX_Active[64] = INCBIN_U8("data/common/SuperMissileHUDActive.gfx");
const u8 sSuperMissileHUDGFX_Refill1[64] = INCBIN_U8("data/common/SuperMissileHUDRefill1.gfx");
const u8 sSuperMissileHUDGFX_Refill2[64] = INCBIN_U8("data/common/SuperMissileHUDRefill2.gfx");
const u8 sSuperMissileHUDGFX_Refill3[64] = INCBIN_U8("data/common/SuperMissileHUDRefill3.gfx");

const u8 sPowerBombHUDGFX_Inactive[64] = INCBIN_U8("data/common/PowerBombHUDInactive.gfx");
const u8 sPowerBombHUDGFX_Selected[64] = INCBIN_U8("data/common/PowerBombHUDSelected.gfx");
const u8 sPowerBombHUDGFX_Active[64] = INCBIN_U8("data/common/PowerBombHUDActive.gfx");
const u8 sPowerBombHUDGFX_Refill1[64] = INCBIN_U8("data/common/PowerBombHUDRefill1.gfx");
const u8 sPowerBombHUDGFX_Refill2[64] = INCBIN_U8("data/common/PowerBombHUDRefill2.gfx");
const u8 sPowerBombHUDGFX_Refill3[64] = INCBIN_U8("data/common/PowerBombHUDRefill3.gfx");

// TODO make 1D arrays
const u8 sEnergyDigitsTensGFX[10][32] = INCBIN_U8("data/common/EnergyDigitsTens.gfx");
const u8 sEnergyDigitsOnesGFX[10][32] = INCBIN_U8("data/common/EnergyDigitsOnes.gfx");
const u8 sEnergyDigitsRefill1GFX[20][32] = INCBIN_U8("data/common/EnergyDigitsRefill1.gfx");
const u8 sEnergyDigitsRefill2GFX[20][32] = INCBIN_U8("data/common/EnergyDigitsRefill2.gfx");
const u8 sEnergyDigitsRefill3GFX[20][32] = INCBIN_U8("data/common/EnergyDigitsRefill3.gfx");

const u8 sEnergyTanksGFX_Zero[160 * 1] = INCBIN_U8("data/common/EnergyTanksZero.gfx");
const u8 sEnergyTanksGFX_One[160 * 2] = INCBIN_U8("data/common/EnergyTanksOne.gfx");
const u8 sEnergyTanksGFX_Two[160 * 3] = INCBIN_U8("data/common/EnergyTanksTwo.gfx");
const u8 sEnergyTanksGFX_Three[160 * 4] = INCBIN_U8("data/common/EnergyTanksThree.gfx");
const u8 sEnergyTanksGFX_Four[160 * 5] = INCBIN_U8("data/common/EnergyTanksFour.gfx");
const u8 sEnergyTanksGFX_Five[160 * 6] = INCBIN_U8("data/common/EnergyTanksFive.gfx");
const u8 sEnergyTanksGFX_Six[160 * 7] = INCBIN_U8("data/common/EnergyTanksSix.gfx");
const u8 sEnergyTanksGFX_Seven[160 * 8] = INCBIN_U8("data/common/EnergyTanksSeven.gfx");
const u8 sEnergyTanksGFX_Eight[160 * 9] = INCBIN_U8("data/common/EnergyTanksEight.gfx");
const u8 sEnergyTanksGFX_Nine[160 * 10] = INCBIN_U8("data/common/EnergyTanksNine.gfx");
const u8 sEnergyTanksGFX_Ten[160 * 11] = INCBIN_U8("data/common/EnergyTanksTen.gfx");
const u8 sEnergyTanksGFX_Eleven[160 * 12] = INCBIN_U8("data/common/EnergyTanksEleven.gfx");
const u8 sEnergyTanksGFX_Twelve[160 * 13] = INCBIN_U8("data/common/EnergyTanksTwelve.gfx");

const u8 sEnergyTanksRefillGFX_One[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillOne.gfx");
const u8 sEnergyTanksRefillGFX_Two[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillTwo.gfx");
const u8 sEnergyTanksRefillGFX_Three[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillThree.gfx");
const u8 sEnergyTanksRefillGFX_Four[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillFour.gfx");
const u8 sEnergyTanksRefillGFX_Five[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillFive.gfx");
const u8 sEnergyTanksRefillGFX_Six[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillSix.gfx");
const u8 sEnergyTanksRefillGFX_Seven[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillSeven.gfx");
const u8 sEnergyTanksRefillGFX_Eight[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillEight.gfx");
const u8 sEnergyTanksRefillGFX_Nine[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillNine.gfx");
const u8 sEnergyTanksRefillGFX_Ten[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillTen.gfx");
const u8 sEnergyTanksRefillGFX_Eleven[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillEleven.gfx");
const u8 sEnergyTanksRefillGFX_Twelve[160 * 3] = INCBIN_U8("data/common/EnergyTanksRefillTwelve.gfx");

const u8 sSuitlessHUDChargeBarGFX[56 * 256] = INCBIN_U8("data/common/SuitlessHUDBar.gfx");

// 339aa8
