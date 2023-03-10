#ifndef INTRO_DATA_H
#define INTRO_DATA_H

#include "types.h"
#include "structs/in_game_timer.h"
#include "structs/intro.h"

extern const u16 sIntroEmergencyOrderTextOAM[52];
extern const u16 sIntroExterminateAllTextOAM[163];
extern const u16 sIntroDefeatTheTextOAM[157];
extern const u16 sIntroTextMarkerOAM[10];

extern const u16 sIntroShipFlyingTowardsCameraOAM_2[28];
extern const u16 sIntroShipFlyingTowardsCameraOAM_1[19];

extern const u16 sIntroViewOfZebesShipOAM[13];
extern const u16 sIntroViewOfZebesHeatOAM_2[37];
extern const u16 sIntroViewOfZebesHeatOAM_1[73];

extern const u16 sIntroFuzzOAM[52];

extern const u16 sIntroTextAndShipPAL[16 * 6];
extern const u16 sIntroPAL_45f9d4[16 * 1];
extern const u16 sIntroSamusInHerShipPAL[16 * 5];
extern const u16 sIntroViewOfZebesPAL[16 * 10];
extern const u16 sIntroMotherBrainPAL[16 * 5];

extern const u8 sIntroFuzzRandomValues_1[64];
extern const u8 sIntroFuzzRandomValues_2[64];
extern const u8 sTimeAttackPasswordCharacters[32];

extern const u32 sTimeAttackAntiCheatTimes[4];

extern const u8 sArray_45fd24[12];
extern const u8 sArray_45fd30[4];
extern const u8 sIntroFuzzRandomValues_3[8];

extern const u8 sIntroEmergencyOrderActions[16];
extern const u8 sIntroExterminateAllActions[52];
extern const u8 sIntroDefeatTheActions[50];

extern const u32 sIntroTextAndShipFlyingInGFX[1310];
extern const u32 sIntroSpaceBackgroundGFX[3181];
extern const u32 sIntroSpaceBackgroundTileTable[577];
extern const u32 sIntroSamusInHerShipGFX[4800];
extern const u32 sIntroSamusInHerShipTileTable[418];
extern const u32 sIntroSamusShipViewOfZebesGFX[1224];
extern const u32 sIntroViewOfZebesGFX[2986];
extern const u32 sIntroViewOfZebesTileTable[577];
extern const u32 sIntroMotherBrainGFX[5004];
extern const u32 sIntroMotherBrainTileTable[577];
extern const u32 sIntroFuzzGFX[5224];
extern const u32 sIntro_47920c[125];

// TODO move to another file
extern const IntroFunc_T sIntroSubroutinesFunctionsPointer[8];

#endif /* INTRO_DATA_H */
