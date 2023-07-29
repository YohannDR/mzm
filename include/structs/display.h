#ifndef DISPLAY_STRUCT_H
#define DISPLAY_STRUCT_H

#include "types.h"

struct IORegistersBackup {
    u16 Dispcnt_NonGameplay;
    u16 Bldcnt_NonGameplay;
    u8 BLDALPHA_NonGameplay_EVA;
    u8 BLDALPHA_NonGameplay_EVB;
    u8 BLDY_NonGameplay;
    u8 WININ_H;
    u8 WINOUT_L;
    u16 BG0CNT;
    u16 BG1CNT;
    u16 BG2CNT;
    u16 BG3CNT;
    u16 unk_12;
};

extern u16 gWrittenToWIN1H;
extern u16 gWrittenToWIN1V;
extern u16 gWrittenToBLDCNT;
extern u16 gWrittenToBLDCNT_Internal;

extern u16 gBackdropColor;

extern u16 gWrittenToBLDALPHA;
extern u16 gWrittenToBLDALPHA_H;
extern u16 gWrittenToBLDALPHA_L;
extern s8 gWrittenToBLDY;
extern u16 gWrittenToBLDY_NonGameplay;

extern u16 gWrittenToMOSAIC_H;
extern u16 gWrittenToMOSAIC_L;

extern u16 gDISPCNTBackup;
extern u16 gWrittenToDISPCNT;
extern u8 gWrittenToWININ_H;
extern u8 gWrittenToWINOUT_L;
extern struct IORegistersBackup gIoRegistersBackup;

#endif