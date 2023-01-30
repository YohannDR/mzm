#ifndef INTRO_DATA_H
#define INTRO_DATA_H

#include "types.h"
#include "structs/in_game_timer.h"

extern const u16 sIntroEmergencOrderTextOAM[52];
extern const u16 sIntroExterminateAllTextOAM[163];
extern const u16 sIntroDefeatTheTextOAM[163];
extern const u16 sIntroTextMarkerOAM[10];

extern const u16 sIntroShipFlyingTowardsCameraOAM_1[19];
extern const u16 sIntroShipFlyingTowardsCameraOAM_2[28];

extern const u16 sIntroViewOfZebesShipOAM[13];
extern const u16 sIntroViewOfZebesHeatOAM_1[37];
extern const u16 sIntroViewOfZebesHeatOAM_2[73];

extern const u16 sIntroFuzzOAM[52];

extern const u16 sIntroTextAndSipPAL[16 * 6];
extern const u16 sIntroPAL_45f9d4[16 * 1];
extern const u16 sIntroSamusInHerShipPAL[16 * 5];
extern const u16 sIntroViewOfZebesPAL[16 * 10];
extern const u16 sIntroMotherBrainPAL[16 * 5];

extern const u8 sIntroFuzzRandomValues_1[64];
extern const u8 sIntroFuzzRandomValues_2[64];
extern const u8 sTimeAttackPasswordCharacters[32];

extern const struct InGameTimer sTimeAttackAntiCheatTimes[4];

extern const u8 sArray_45fd24[12];
extern const u8 sArray_45fd30[4];
extern const u8 sArray_45fd34[4];

#endif /* INTRO_DATA_H */
