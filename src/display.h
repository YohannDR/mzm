#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

// Globals


// Structs

struct IORegistersBackup {
    u16 DISPCNT_NonGameplay;
    u16 BLDCNT_NonGameplay;
    u16 BLDALPHA_NonGameplay;
    u8 WININ_H_NonGameplay;
    u8 WINOUT_L_NonGameplay;
    u16 BG3CNT_WriteOnly;
    u16 BG3CNT;
    u16 BG1CNT;
    u16 BG2CNT;
    u16 BG3CNT;
};

// Functions

void IOWriteRegisters(void);
void IOWriteRegistersDuringTransition(void);
void IOUpdateDISPCNT(u8 operation, u16 value);

#endif /* DISPLAY_H */
