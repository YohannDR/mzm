#include "data/save_file_data.h"
#include "gba.h"

#include "constants/connection.h"

const u8 sMetZeroSramCheck_Text[SRAM_TEXT_SIZE] = "MetZeroSramCheck";
const u8 sZERO_MISSION_010_Text[SRAM_TEXT_SIZE] = "ZERO_MISSION_010";
const u8 sPlanetZebes_Text[SRAM_TEXT_SIZE] = "Planet Zebes... ";
const u8 sSamusAran_Text[SRAM_TEXT_SIZE] = " - Samus Aran - ";

const u8 sJpnVer_Text[20] = "ZeroMissionJPNver005";
const u8 sEurVer_Text[20] = "ZeroMissionEURver005";
const u8 sUsaVer_Text[20] = "ZeroMissionUSAver005";

const struct FileScreenOptionsUnlocked sFileScreenOptionsUnlocked_Empty = {
    .galleryImages = 0,
    .fusionGalleryImages = 0,
    .soundTestAndOgMetroid = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .timeAttack = 0
};

const u8 sMostRecentFileSave_Text[2][SRAM_TEXT_SIZE] = {
    "SELECTSAVENUM_00",
    "ENDDATA_SEL_SAVE"
};

const u8 sSoundModeSave_Text[2][SRAM_TEXT_SIZE] = {
    "_SOUNDMODE_SAVE_",
    "SoundModeSAVEEND"
};

const u8 sLanguageSave_Text[2][SRAM_TEXT_SIZE] = {
    "_SELECT_LANGUAGE",
    "ENDKEY_LANGUAGE_"
};

const u8 sTimeAttackSave_Text[2][SRAM_TEXT_SIZE] = {
    "SUKPIFZAILU25976", 
    "_StartKey_198129"
};

const u8 sATRUNED_Text[8] = "ATRUNEND";

const struct ButtonAssignments sDefaultButtonAssignments = {
    .armWeapon = KEY_R,
    .diagonalAim = KEY_L,
    .pause = KEY_START,
    .swapMissiles = KEY_SELECT
};

const struct InGameTimer sInGameTimer_Empty = {
    .hours = 0,
    .minutes = 0,
    .seconds = 0,
    .frames = 0
};

const struct InGameTimer sBestCompletionTime_Empty = {
    .hours = UCHAR_MAX,
    .minutes = UCHAR_MAX,
    .seconds = UCHAR_MAX,
    .frames = UCHAR_MAX
};

const u8 sUnk_411520[4] = {
    8, 8, 0, 0
};

const struct StartingInfo sStartingInfo = {
    .startingArea = AREA_CRATERIA,
    .unk_1 = 5,
    .unk_2 = 0,
    .unk_3 = 0
};
