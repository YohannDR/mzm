#include "data/hud_data.h"
#include "macros.h"

// 32ba08

const u16 sCommonSpritesPAL[96] = INCBIN_U16("data/hud/Common.pal");
const u32 sCommonSpritesGfx[3584] = INCBIN_U32("data/hud/Common.gfx");

const u8 sMissileDigitsGfx[2304] = INCBIN_U8("data/hud/MissileDigits.gfx");
const u8 sPowerBombDigitsGfx[2304] = INCBIN_U8("data/hud/PowerBombDigits.gfx");

const u8 sMissileHUDGfx_Inactive[64] = INCBIN_U8("data/hud/MissileHUD_Inactive.gfx");
const u8 sMissileHUDGfx_Selected[64] = INCBIN_U8("data/hud/MissileHUD_Selected.gfx");
const u8 sMissileHUDGfx_Active[64] = INCBIN_U8("data/hud/MissileHUD_Active.gfx");
const u8 sMissileHUDGfx_Refill1[64] = INCBIN_U8("data/hud/MissileHUD_Refill1.gfx");
const u8 sMissileHUDGfx_Refill2[64] = INCBIN_U8("data/hud/MissileHUD_Refill2.gfx");
const u8 sMissileHUDGfx_Refill3[64] = INCBIN_U8("data/hud/MissileHUD_Refill3.gfx");

const u8 sSuperMissileHUDGfx_Inactive[64] = INCBIN_U8("data/hud/SuperMissileHUD_Inactive.gfx");
const u8 sSuperMissileHUDGfx_Selected[64] = INCBIN_U8("data/hud/SuperMissileHUD_Selected.gfx");
const u8 sSuperMissileHUDGfx_Active[64] = INCBIN_U8("data/hud/SuperMissileHUD_Active.gfx");
const u8 sSuperMissileHUDGfx_Refill1[64] = INCBIN_U8("data/hud/SuperMissileHUD_Refill1.gfx");
const u8 sSuperMissileHUDGfx_Refill2[64] = INCBIN_U8("data/hud/SuperMissileHUD_Refill2.gfx");
const u8 sSuperMissileHUDGfx_Refill3[64] = INCBIN_U8("data/hud/SuperMissileHUD_Refill3.gfx");

const u8 sPowerBombHUDGfx_Inactive[64] = INCBIN_U8("data/hud/PowerBombHUD_Inactive.gfx");
const u8 sPowerBombHUDGfx_Selected[64] = INCBIN_U8("data/hud/PowerBombHUD_Selected.gfx");
const u8 sPowerBombHUDGfx_Active[64] = INCBIN_U8("data/hud/PowerBombHUD_Active.gfx");
const u8 sPowerBombHUDGfx_Refill1[64] = INCBIN_U8("data/hud/PowerBombHUD_Refill1.gfx");
const u8 sPowerBombHUDGfx_Refill2[64] = INCBIN_U8("data/hud/PowerBombHUD_Refill2.gfx");
const u8 sPowerBombHUDGfx_Refill3[64] = INCBIN_U8("data/hud/PowerBombHUD_Refill3.gfx");

const u8 sEnergyDigitsTensGfx[10 * 32] = INCBIN_U8("data/hud/EnergyDigitsTens.gfx");
const u8 sEnergyDigitsOnesGfx[10 * 32] = INCBIN_U8("data/hud/EnergyDigitsOnes.gfx");
const u8 sEnergyDigitsRefill1Gfx[20 * 32] = INCBIN_U8("data/hud/EnergyDigitsRefill1.gfx");
const u8 sEnergyDigitsRefill2Gfx[20 * 32] = INCBIN_U8("data/hud/EnergyDigitsRefill2.gfx");
const u8 sEnergyDigitsRefill3Gfx[20 * 32] = INCBIN_U8("data/hud/EnergyDigitsRefill3.gfx");

const u8 sEnergyTanksGfx_Zero[160 * 1] = INCBIN_U8("data/hud/EnergyTanksZero.gfx");
const u8 sEnergyTanksGfx_One[160 * 2] = INCBIN_U8("data/hud/EnergyTanksOne.gfx");
const u8 sEnergyTanksGfx_Two[160 * 3] = INCBIN_U8("data/hud/EnergyTanksTwo.gfx");
const u8 sEnergyTanksGfx_Three[160 * 4] = INCBIN_U8("data/hud/EnergyTanksThree.gfx");
const u8 sEnergyTanksGfx_Four[160 * 5] = INCBIN_U8("data/hud/EnergyTanksFour.gfx");
const u8 sEnergyTanksGfx_Five[160 * 6] = INCBIN_U8("data/hud/EnergyTanksFive.gfx");
const u8 sEnergyTanksGfx_Six[160 * 7] = INCBIN_U8("data/hud/EnergyTanksSix.gfx");
const u8 sEnergyTanksGfx_Seven[160 * 8] = INCBIN_U8("data/hud/EnergyTanksSeven.gfx");
const u8 sEnergyTanksGfx_Eight[160 * 9] = INCBIN_U8("data/hud/EnergyTanksEight.gfx");
const u8 sEnergyTanksGfx_Nine[160 * 10] = INCBIN_U8("data/hud/EnergyTanksNine.gfx");
const u8 sEnergyTanksGfx_Ten[160 * 11] = INCBIN_U8("data/hud/EnergyTanksTen.gfx");
const u8 sEnergyTanksGfx_Eleven[160 * 12] = INCBIN_U8("data/hud/EnergyTanksEleven.gfx");
const u8 sEnergyTanksGfx_Twelve[160 * 13] = INCBIN_U8("data/hud/EnergyTanksTwelve.gfx");

const u8 sEnergyTanksRefillGfx_One[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillOne.gfx");
const u8 sEnergyTanksRefillGfx_Two[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillTwo.gfx");
const u8 sEnergyTanksRefillGfx_Three[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillThree.gfx");
const u8 sEnergyTanksRefillGfx_Four[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillFour.gfx");
const u8 sEnergyTanksRefillGfx_Five[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillFive.gfx");
const u8 sEnergyTanksRefillGfx_Six[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillSix.gfx");
const u8 sEnergyTanksRefillGfx_Seven[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillSeven.gfx");
const u8 sEnergyTanksRefillGfx_Eight[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillEight.gfx");
const u8 sEnergyTanksRefillGfx_Nine[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillNine.gfx");
const u8 sEnergyTanksRefillGfx_Ten[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillTen.gfx");
const u8 sEnergyTanksRefillGfx_Eleven[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillEleven.gfx");
const u8 sEnergyTanksRefillGfx_Twelve[160 * 3] = INCBIN_U8("data/hud/EnergyTanksRefillTwelve.gfx");

const u8 sSuitlessHUDChargeBarGfx[56 * 256] = INCBIN_U8("data/hud/SuitlessHUDBar.gfx");

// 339aa8
