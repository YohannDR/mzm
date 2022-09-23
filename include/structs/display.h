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
    u16 BG0CNT_WriteOnly;
    u16 BG0CNT;
    u16 BG1CNT;
    u16 BG2CNT;
    u16 BG3CNT;
};

extern struct IORegistersBackup gIORegistersBackup;

#endif