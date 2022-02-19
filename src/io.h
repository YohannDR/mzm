#ifndef IO_H
#define IO_H

#include "types.h"

struct io_registers_backup {
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

void unk_57a24(void);
void unk_57af8(void);
void io_update_dispcnt(u8 operation, u16 value);

#endif /* IO_H */