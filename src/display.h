#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

struct IORegistersBackup {
    u16 dispcnt_non_gameplay;
    u16 bldcnt_non_gameplay;
    u16 bldalpha_non_gameplay;
    u8 winin_h_non_gameplay;
    u8 winout_l_non_gameplay;
    u16 bg0cnt_write_only;
    u16 bg1cnt;
    u16 bg2cnt;
    u16 bg3cnt;
    u16 bg0cnt;
};

void IOWriteRegisters(void);
void IOWriteRegistersDuringTransition(void);
void IOUpdateDISPCNT(u8 operation, u16 value);

#endif /* DISPLAY_H */
