#ifndef DISPLAY_STRUCT_H
#define DISPLAY_STRUCT_H

#include "types.h"

struct IORegistersBackup {
    u16 DISPCNT_NonGameplay;
    u16 BLDCNT_NonGameplay;
    u8 BLDALPHA_NonGameplay_EVA;
    u8 BLDALPHA_NonGameplay_EVB;
    u8 WININ_H_NonGameplay;
    u8 WINOUT_L_NonGameplay;
    u8 WINOUT_H_NonGameplay;
    u16 BG0CNT;
    u16 BG1CNT;
    u16 BG2CNT;
    u16 BG3CNT;
    u16 unknown_12;
};

struct SuitFlashEffect {
    u8 left;
    u8 right;
    u8 top;
    u8 bottom;
    u8 timer;
};

// Temp
struct InGameCutscene {
    u16 timer;
    u8 stage;
    u8 cutsceneNumber;
    u8 cutsceneNumber_Copy;
    u8 unknown;
    Func_T pSubroutine;
};
extern struct InGameCutscene gInGameCutscene;


extern struct SuitFlashEffect gSuitFlashEffect;

extern u16 gWrittenToWINH;
extern u16 gWrittenToWINV;
extern u16 gWrittenToBLDCNT;

extern u16 gWrittenToBLDALPHA;
extern u16 gWrittenToBLDALPHA_H;
extern u16 gWrittenToBLDALPHA_L;
extern i8 gWrittenToBLDY;
extern u16 gWrittenToBLDY_NonGameplay;

extern u16 gDISPCNTBackup;
extern u16 gWrittenToDISPCNT;
extern struct IORegistersBackup gIORegistersBackup;

#endif