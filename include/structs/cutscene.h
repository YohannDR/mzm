#ifndef CUTSCENE_STRUCT_H
#define CUTSCENE_STRUCT_H

#include "types.h"
#include "oam.h"

struct OamArray {
    const struct FrameData* const pOam;
    u8 preAction;
};

#define OAM_ARRAY_PRE_ACTION_NONE 0
#define OAM_ARRAY_PRE_ACTION_CHANGE_FRAME 1
#define OAM_ARRAY_PRE_ACTION_RESET_FRAME 2
#define OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME 3
#define OAM_ARRAY_PRE_ACTION_KILL_AFTER_END 4
#define OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END 5
#define OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END 7
#define OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME 8
#define OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING 9

// For some reason, 0x800 (0x200 * 4) is used as a 0 value for the backgrounds position during most of the non gameplay moments
// The hardware value is in pixel, ranging from 0 to 0x1FF, so a value of 0x800 equals to a value of 0 (0x800 / 4 & 0x1FF)
#define NON_GAMEPLAY_START_BG_POS (BLOCK_SIZE * 32)

#define MACRO_CUTSCENE_NEXT_STAGE() \
{                                   \
    struct CutsceneTimeInfo* ptr;   \
    ptr = &CUTSCENE_DATA.timeInfo;  \
    ptr->subStage = 0;              \
    ptr->timer = 0;                 \
}

typedef u8 (*CutsceneFunc_T)(void);

struct CutscenePageData {
    u8 graphicsPage;
    u8 tiletablePage;
    u8 priority;
    u16 bg;
    u16 screenSize;
};

struct CutsceneScreenShakeInfo {
    u8 type;
    u8 maxDelay;
    u16 set;
};

struct CutsceneScrollingInfo {
    u8 direction;
    s16 length;
    s8 speed;
    s8 maxDelay;
};

struct CutsceneInfo {
    u8 unk_0;
    u8 type:4;
    u8 isElevator:2;
    u8 skippable:2;
    u8 storyText;
    CutsceneFunc_T pFunction;
    u8 preBgFading;
    u16 fadingTimer;
    u8 bgFading;
    u8 event;
};

struct CutsceneSubroutineData {
    CutsceneFunc_T pFunction;
    u8 oamLength;
};

struct CutsceneScreenShake {
    u16 bg;
    s8 delay;
    s8 maxDelay;
    u8 set;
    u8 currentSubSet;
};

struct CutsceneScrolling {
    u16* pPosition;
    s16 lengthLeft;
    s8 delay;
    s8 speed;
    s8 maxDelay;
};

struct CutscenePaletteData {
    u8 active;
    u8 timer;
    u8 paletteRow;
    u8 maxTimer;
};

struct CutsceneGraphicsData {
    u8 active;
    s8 paletteStage;
    u8 maxTimer;
    u8 maxPaletteStage;
    u16 timer;
    u8 padding[6];
};

struct CutsceneSpecialEffect {
    u8 status;
    u8 s_WrittenToBLDY;
    u8 bg_WrittenToBLDALPHA_L;
    u8 bg_WrittenToBLDALPHA_H;
    u16 s_BLDCNT;
    u8 s_Intensity;
    u8 s_Interval;
    s8 s_Timer;
    u16 bg_WrittenToBLDCNT;
    u8 bg_Intensity;
    u8 bg_Interval;
    s8 bg_Timer;
};

struct CutsceneOamData {
    s16 yPosition;
    s16 xPosition;
    u8 unk_2;
    u8 padding_5[3];
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u8 oamID;
    u16 priority:2;
    u16 objMode:2;
    u16 ended:1;
    u16 notDrawn:1;
    u16 exists:2;
    u8 boundBackground:4;
    u8 rotationScaling:1;
    u8 actions;
    s16 xVelocity;
    s16 yVelocity;
    s16 unk_12;
    u16 timer;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u8 padding_1C[2];
    u8 unk_1E;
};

struct CutsceneTimeInfo {
    u8 stage;
    u16 timer;
    u8 subStage;
    u8 unk_5;
    u8 customTimer;
};

struct CutsceneData {
    struct CutsceneTimeInfo timeInfo;
    u8 unk_8; // TODO struct
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    struct CutscenePaletteData paletteData[4];
    u16 dispcnt;
    u16 bldcnt;
    u16 bgcnt[4];
    u16 bg0vofs;
    u16 bg1vofs;
    u16 bg2vofs;
    u16 bg3vofs;
    u16 bg0hofs;
    u16 bg1hofs;
    u16 bg2hofs;
    u16 bg3hofs;
    struct CutsceneScrolling bgScrolling[8];
    struct CutsceneScreenShake horizontalScreenShake;
    struct CutsceneScreenShake verticalScreenShake;
    struct CutsceneSpecialEffect specialEffect;
    s16 unk_B8;
    u8 fadingStage;
    u8 fadingColor;
    u8 unk_BC;
    u8 fadingIntensity;
    u8 unk_BE;
    u8 fadingType;
    struct CutsceneGraphicsData graphicsData[4];
    struct CutsceneOamData oam[30];
};

extern u8 gCutsceneToSkip;
extern s8 gCurrentCutscene;

extern s8 gOamXOffset_NonGameplay;
extern s8 gOamYOffset_NonGameplay;

#endif
