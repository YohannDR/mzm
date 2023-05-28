#ifndef CHOZODIA_ESCAPE_DATA_H
#define CHOZODIA_ESCAPE_DATA_H

#include "types.h"
#include "oam.h"
#include "macros.h"

extern const u16 sChozodiaEscapeShipHeatingUpPAL[8 * 16];
extern const u16 sChozodiaEscapeGroundHeatingUpPAL[8 * 16];

extern const u16 sChozodiaEscapeShipExplodingPAL[9 * 16];
extern const u16 sChozodiaEscapeMissionAccomplishedPAL[16 * 16];
extern const u16 sChozodiaEscapeSamusInBlueShipPAL[1 * 16];

extern const u16 sChozodiaEscapeOam_ShipExterior_Frame0[OAM_DATA_SIZE(10)];
extern const u16 sChozodiaEscapeOam_BlueShipAngledDown_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sChozodiaEscapeOam_BlueShipAngledUp_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sChozodiaEscapeOam_MotherShipDoorClosed_Frame0[OAM_DATA_SIZE(6)];

extern const struct FrameData sChozodiaEscapeOam_MotherShipDoorOpening[9];

extern const u16 sChozodiaEscapeOam_BlueShipFarAway_Frame0[OAM_DATA_SIZE(1)];
extern const u16 sChozodiaEscapeOam_BlueShipVeryClose_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0[OAM_DATA_SIZE(20)];
extern const u16 sChozodiaEscapeOam_MissionAccomplishedHiragana_Frame0[OAM_DATA_SIZE(9)];

extern const u8 sChozodiaEscapeHeatingUpPalOffsets[8];

extern const struct FrameData* const sChozodiaEscape_5ca0c4[5];

extern const u16 sChozodiaEscape_5ca0d8[8][2];
extern const u16 sChozodiaEscape_5ca0f8[8][2];

extern const u32 sChozodiaEscapeCraterBackgroundGfx[5227];
extern const u32 sChozodiaEscapeCraterBackgroundTileTable[418];

extern const u32 sChozodiaEscapeBlueShipVeryCloseGfx[1079];

extern const u32 sChozodiaEscapeZebesBackgroundTileTable[176];
extern const u32 sChozodiaEscapeZebesAndSkyGfx[4574];
extern const u32 sChozodiaEscapeZebesSkyTileTable[418];

extern const u32 sChozodiaEscapeSamusInBlueShipGfx[2699];
extern const u32 sChozodiaEscapeSamusInBlueShipTileTable[368];

extern const u32 sChozodiaEscapeMissionAccomplishedLettersGfx[414];

#endif /* CHOZODIA_ESCAPE_DATA_H */
