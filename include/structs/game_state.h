#ifndef GAME_STATE_STRUCT_H
#define GAME_STATE_STRUCT_H

#include "types.h"
#include "input.h"

struct GameCompletion {
    u8 completedGame;
    u8 introPlayed;
    u8 language;
};

extern struct GameCompletion gGameCompletion;

struct FileScreenOptionsUnlocked {
    u16 galleryImages;
    u16 fusionGalleryImages;
    u8 soundTestAndOgMetroid;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u32 timeAttack;
};

extern struct FileScreenOptionsUnlocked gFileScreenOptionsUnlocked;
extern struct ButtonAssignments gButtonAssignments;
extern i8 gTourianEscapeCutsceneStage;
extern vu16 gVBlankRequestFlag;
extern u8 gDisableSoftreset;
extern u8 gDebugFlag;
extern u8 gSramErrorFlag;
extern u8 gDisablePause;
extern u8 gDisableScrolling;
extern u8 gShipLandingFlag;
extern u8 gTimeAttackFlag;
extern u16 gButtonInput;
extern u16 gPreviousButtonInput;
extern u16 gChangedInput;
extern i8 gIsLoadingFile;
extern i8 gPauseScreenFlag;
extern i8 gVblankActive;
extern u8 gFrameCounter8Bit;
extern u16 gFrameCounter16Bit;
extern u8 gDifficulty;
extern i8 gLanguage;
extern u8 gResetGame;
extern u8 gNotPressingUp;
extern u8 gEndingFlags;

extern i16 gMainGameMode;
extern i16 gGameModeSub1;
extern i8 gGameModeSub2;
extern i8 gGameModeSub3;
extern u8 gSubGameModeStage;

extern u8 gHasSaved;
extern i8 gMostRecentSaveFile;

#endif
