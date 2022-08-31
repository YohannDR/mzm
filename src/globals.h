#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
#include "sprite.h"
#include "room.h"
#include "particle.h"
#include "oam.h"
#include "screen_shake.h"
#include "display.h"
#include "samus.h"
#include "gba/keys.h"
#include "projectile.h"
#include "scroll.h"
#include "connection.h"
#include "bg_clip.h"
#include "io.h"
#include "escape.h"
#include "clipdata.h"
#include "input.h"

// EWRAM

extern u32 gEventsTriggered[8];
extern u16 unk_02035400;

// IWRAM

enum PauseScreenFlags {
    PAUSE_SCREEN_NONE,
    PAUSE_SCREEN_UNKNOWN_1,
    PAUSE_SCREEN_PAUSE_OR_CUTSCENE,
    PAUSE_SCREEN_UNKNOWN_3,
    PAUSE_SCREEN_CHOZO_HINT,
    PAUSE_SCREEN_MAP_DOWNLOAD,
    PAUSE_SCREEN_ITEM_ACQUISITION,
    PAUSE_SCREEN_SUITLESS_ITEMS,
    PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS,
    PAUSE_SCREEN_UNKNOWN_9,
};

enum Difficulty {
    DIFF_EASY = 0x0,
    DIFF_NORMAL = 0x1,
    DIFF_HARD = 0x2
};

// Temporary place

#define CUTSCENE_NONE 0x0
#define CUTSCENE_INTRO_TEXT 0x1
#define CUTSCENE_MOTHERSHIP_MONOLOGUE 0x2
#define CUTSCENE_COULD_I_SURVIVE 0x3
#define CUTSCENE_MOTHER_BRAIN_CLOSE_UP 0x4
#define CUTSCENE_KRAID_RISING 0x5
#define CUTSCENE_STATUE_OPENING 0x6
#define CUTSCENE_RIDLEY_IN_SPACE 0x7
#define CUTSCENE_RIDLEY_LANDING 0x8
#define CUTSCENE_RIDLEY_SPAWNING 0x9
#define CUTSCENE_ENTER_TOURIAN 0xA
#define CUTSCENE_BEFORE_CHARLIE 0xB
#define CUTSCENE_GETTING_FULLY_POWERED 0xC
#define CUTSCENE_MECHA_RIDLEY_SEES_SAMUS 0xD
#define CUTSCENE_SAMUS_IN_BLUE_SHIP 0xE

struct InGameTimer {
    u8 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

extern struct InGameTimer gInGameTimer;
extern struct InGameTimer gInGameTimerAtBosses[5];

///

extern u8 unk_02038000[];

extern u8 gDebugFlag;
extern u16 gFrameCounter16Bit;
extern u16 gWrittenToDISPCNT;
extern u8 gStereoFlag;
extern struct MusicTrackInfo gMusicTrackInfo;
extern u32 gCurrentDemo; /* XXX: type */
extern u8 gMonochromeBGFading;
extern u8 gWhichBGPositionIsWrittenToBG3OFS;
extern u8 gSamusOnTopOfBackgrounds;
extern u8 gDifficulty;
extern u8 gUseMotherShip;
extern u8 gResetGame;
extern u8 gDisableScrolling;
extern u16 gSlowScrollingTimer;
extern u8 gSkipDoorTransition;
extern u8 gDisableSoftreset;
extern u8 gDisableDoorAndTanks;
extern i8 gCollectingTank;
extern u8 gDisablePause;
extern u8 gDisableClipdataChangingTransparency;
extern i8 gDisableAnimatedPalette;
extern u8 gCurrentArea;
extern u8 gCurrentRoom;
extern u8 gLastDoorUsed;
extern u8 gLastDoorProperties;
extern u8 gDisplayLocationText;
extern u16 gEffectYPosition;
extern i16 gEffectYPositionOffset;
extern u8 gScreenShakeXRelated;
extern u8 gScreenShakeYRelated;
extern u16 gScreenShakeRelated;
extern u16 gDISPCNTBackup;
extern u8 gSpriteset;
extern u8 gCurrentClipdataAffectingAction;
extern u8 gSpritesetEntryUsed;
extern i8 gDoorUnlockTimer;
extern i8 gCurrentCutscene;
extern i8 gTourianEscapeCutsceneStage;
extern struct IORegistersBackup gIORegistersBackup;
extern struct BackgroundPointersAndDimensions gBGPointersAndDimensions;

extern u8 gEnergyRefillAnimation;
extern u8 gMissileRefillAnimation;
extern u8 gSuperMissileRefillAnimation;
extern u8 gPowerBombRefillAnimation;

extern struct RawCoordsX gWaitingSpacePiratesPosition;
extern struct BG2Movement gBG2Movement;
extern struct ScreenShake gScreenShakeY;
extern struct ScreenShake gScreenShakeX;
extern struct LastElevatorUsed gLastElevatorUsed;
extern i8 gIsLoadingFile;
extern i8 gPauseScreenFlag;
extern i8 gClearedEveryFrame;
extern u8 gFrameCounter8Bit;
extern vu16 gVBlankRequestFlag;
extern u16 gInterruptCode[0x100];
extern struct RawOamData gOamData[160];
extern u8 gSRAMCorruptFlag;
extern u16 gButtonInput;
extern u16 gPreviousButtonInput;
extern u16 gChangedInput;
extern u8 gNextOAMSlot;
extern u16 gBG0XPosition;
extern u16 gBG0YPosition;
extern u16 gBG1XPosition;
extern u16 gBG1YPosition;
extern u16 gBG2XPosition;
extern u16 gBG2YPosition;
extern u16 gBG3XPosition;
extern u16 gBG3YPosition;
extern u8 gDemoState;
extern struct ButtonAssignments gButtonAssignments;
extern u8 gNonGameplayRAM[640]; // Weird type, subject to change
extern u8 gUnk_03004fc9;
extern struct HatchData gHatchData[16];
extern struct RawCoordsX gDoorPositionStart;
extern struct BG3Movement gBG3Movement;
extern struct BG0Movement gBG0Movement;
extern u16 gRainSoundEffect;
extern u8* gCurrentRoomScrollDataPointer;
extern ClipFunc_T gClipdataCodePointer;

extern void *sp_sys;
extern void *sp_irq;
extern Func_T intr_vector[13];
extern u16 (*intr_code_ptr)[0x100];
extern u16 (*intr_code_ptr)[0x100];

extern u16 unk_03007ff8;

// IO

extern struct DMA gRegDMA[4];
#endif /* GLOBALS_H */
