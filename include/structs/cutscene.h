#ifndef CUTSCENE_STRUCT_H
#define CUTSCENE_STRUCT_H

#include "types.h"
#include "oam.h"

// Temp place
struct OamArray {
    const struct FrameData* pOam;
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


struct CutsceneUnk {
    u8 unk_0;
    u8 dstPage;
    u8 unk_2;
    u8 unk_3;
    u16 bg;
    u8 unk_6;
    u8 unk_7;
};

struct CutsceneInfo {
    u8 unk_0;
    u8 type; // Bit flag
    u8 storyText;
    CutsceneFunc_T pFunction;
    u8 unk_8;
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
    i8 loopCounter;
    i8 unk_3;
    u8 unk_4;
    u8 unk_5;
};

struct CutsceneScrolling {
    u16* pPosition;
    i16 unk_4;
    i8 unk_6;
    i8 unk_7;
    i8 unk_8;
};

struct CutsceneGraphicsData {
    u8 active;
    u8 paletteStage;
    u8 paletteRow;
    u8 maxPaletteStage;
    u16 timer;
    u8 padding[10];
};

struct CutsceneSpecialEffect {
    u8 status;
    u8 s_WrittenToBLDY;
    u8 bg_WrittenToBLDALPHA_L;
    u8 bg_WrittenToBLDALPHA_H;
    u16 s_BLDCNT;
    u8 s_Intensity;
    u8 s_Interval;
    i8 s_Timer;
    u16 bg_WrittenToBLDCNT;
    u8 bg_Intensity;
    u8 bg_Interval;
    i8 bg_Timer;
};

struct CutsceneOamData {
    i16 yPosition;
    i16 xPosition;
    u8 unk_2;
    u8 padding_5[3];
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u8 oamID;
    u8 status; // Bit field probably
    u8 unk_C;
    u8 unk_D;
    i16 unk_E;
    i16 unk_10;
    i16 unk_12;
    u16 timer;
    i16 unk_16;
    i16 unk_18;
    u16 unk_1A;
    u8 padding_1C[2];
    u8 unk_1E;
};

struct CutsceneData {
    u8 stage;
    u16 timer;
    u8 subStage;
    u8 padding_5;
    u8 unk_6;
    u8 padding_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    struct CutsceneGraphicsData graphicsData1;
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
    u16 unk_B8;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    u8 unk_BE;
    u8 unk_BF;
    struct CutsceneGraphicsData graphicsData2[3];
    struct CutsceneOamData oam[30];
};

typedef u8 (*CutsceneFunc_T)(void);

extern u8 gCutsceneToSkip;
extern i8 gCurrentCutscene;

#endif