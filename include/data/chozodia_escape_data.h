#ifndef CHOZODIA_ESCAPE_DATA_H
#define CHOZODIA_ESCAPE_DATA_H

#include "types.h"
#include "oam.h"

extern const u16 sChozodiaEscapeShipHeatingUpPAL[8 * 16];
extern const u16 sChozodiaEscapeGroundHeatingUpPAL[8 * 16];

extern const u16 sChozodiaEscapeShipExplodingPAL[9 * 16];
extern const u16 sChozodiaEscapeMissionAccomplishedPAL[16 * 16];
extern const u16 sChozodiaEscapeSamusInBlueShipPAL[1 * 16];

extern const u16 sChozodiaEscapeOAM_ShipExterior_Frame0[31];
extern const u16 sChozodiaEscapeOAM_BlueShipAngledDown_Frame0[7];
extern const u16 sChozodiaEscapeOAM_BlueShipAngledUp_Frame0[10];
extern const u16 sChozodiaEscapeOAM_MotherShipDoorClosed_Frame0[19];

extern const struct FrameData sChozodiaEscapeOAM_MotherShipDoorOpening[9];

extern const u16 sChozodiaEscapeOAM_BlueShipFarAway_Frame0[4];
extern const u16 sChozodiaEscapeOAM_BlueShipVeryClose_Frame0[13];

extern const u16 sChozodiaEscapeOAM_MissionAccomplishedEnglish_Frame0[61];
extern const u16 sChozodiaEscapeOAM_MissionAccomplishedHiragana_Frame0[28];

extern const u8 sChozodiaEscapeHeatingUpPalOffsets[8];

extern const struct FrameData* const sChozodiaEscape_5ca0c4[5];

// ...

extern const u32 sChozodiaEscapeCraterBackgroundGFX[5227];
extern const u32 sChozodiaEscapeCraterBackgroundTileTable[418];

extern const u32 sChozodiaEscapeBlueShipVeryCloseGFX[1079];

extern const u32 sChozodiaEscapeZebesBackgroundTileTable[176];
extern const u32 sChozodiaEscapeZebesAndSkyGFX[4574];
extern const u32 sChozodiaEscapeZebesSkyTileTable[418];

extern const u32 sChozodiaEscapeSamusInBlueShipGFX[2699];
extern const u32 sChozodiaEscapeSamusInBlueShipTileTable[368];

extern const u32 sChozodiaEscapeMissionAccomplishedLettersGFX[414];

#endif /* CHOZODIA_ESCAPE_DATA_H */
