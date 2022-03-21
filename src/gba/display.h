#ifndef GBA_DISPLAY_H
#define GBA_DISPLAY_H

#include "types.h"

#define REG_DISPCNT (REG_BASE + 0x000)
#define REG_DISPSTAT (REG_BASE + 0x004)
#define REG_BLDCNT (REG_BASE + 0x050)
#define REG_BLDALPHA (REG_BASE + 0x052)
#define REG_BLDY (REG_BASE + 0x054)

#define PLTT_BASE 0x05000000
#define PLTT_BG ((vu16 *)(PLTT_BASE + 0x00))

enum display_mode {
    /* Bits 0-2 */
    DCNT_MODE_1 = 1,
    DCNT_MODE_2 = 2,
    DCNT_MODE_3 = 3,
    DCNT_MODE_4 = 4,
    DCNT_MODE_5 = 5,

    DCNT_CGB     = 1 << 3,
    DCNT_PAGE    = 1 << 4,
    DCNT_OAM_HBL = 1 << 5,
    DCNT_OBJ_1D  = 1 << 6,
    DCNT_BLANK   = 1 << 7,

    DCNT_BG0    = 1 << 8,
    DCNT_BG1    = 1 << 9,
    DCNT_BG2    = 1 << 10,
    DCNT_BG3    = 1 << 11,
    DCNT_OBJ    = 1 << 12,
    DCNT_WIN0   = 1 << 13,
    DCNT_WIN1   = 1 << 14,
    DCNT_WINOBJ = 1 << 15,
};

enum display_status {
    DSTAT_IN_VBLANK    = 1 << 0,
    DSTAT_IN_HBLANK    = 1 << 1,
    DSTAT_VCOUNT_MATCH = 1 << 2,
    DSTAT_IF_VBLANK    = 1 << 3,
    DSTAT_IF_HBLANK    = 1 << 4,
    DSTAT_IF_VCOUNT    = 1 << 5,
};

#endif /* GBA_DISPLAY_H */
