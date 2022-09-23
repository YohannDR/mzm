#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
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

union TileData {
    struct {
        u32 tile:10;
        u32 flip:2;
        u32 palette:4;
    } split;

    u16 all;
};

///

extern u8 unk_02038000[];

extern u16 gWrittenToDISPCNT;
extern u32 gCurrentDemo; /* XXX: type */
extern u8 gMonochromeBGFading;
extern u8 gWhichBGPositionIsWrittenToBG3OFS;
extern u8 gSamusOnTopOfBackgrounds;
extern u8 gUseMotherShip;
extern u8 gDisableSoftreset;
extern u8 gDisableDoorAndTanks;
extern u8 gDisableClipdataChangingTransparency;
extern u8 gScreenShakeXRelated;
extern u8 gScreenShakeYRelated;
extern u16 gScreenShakeRelated;
extern u16 gDISPCNTBackup;
extern u8 gSpriteset;
extern u8 gSpritesetEntryUsed;
extern i8 gCurrentCutscene;
extern i8 gTourianEscapeCutsceneStage;

extern struct RawCoordsX gWaitingSpacePiratesPosition;
extern struct BG2Movement gBG2Movement;
extern struct ScreenShake gScreenShakeY;
extern struct ScreenShake gScreenShakeX;
extern struct LastElevatorUsed gLastElevatorUsed;
extern vu16 gVBlankRequestFlag;
extern u16 gInterruptCode[0x100];
extern u8 gSRAMCorruptFlag;
extern u8 gNextOAMSlot;
extern u8 gDemoState;
extern struct ButtonAssignments gButtonAssignments;
extern u8 gNonGameplayRAM[640]; // Weird type, subject to change
extern u8 gUnk_03004fc9;
extern struct RawCoordsX gDoorPositionStart;
extern struct BG3Movement gBG3Movement;
extern struct BG0Movement gBG0Movement;
extern u16 gRainSoundEffect;

extern void *sp_sys;
extern void *sp_irq;
extern Func_T intr_vector[13];
extern u16 (*intr_code_ptr)[0x100];
extern u16 (*intr_code_ptr)[0x100];

extern u16 unk_03007ff8;

// IO

extern volatile struct DMA gRegDMA[4];
#endif /* GLOBALS_H */
