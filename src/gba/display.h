#ifndef GBA_DISPLAY_H
#define GBA_DISPLAY_H

#include "../types.h"

#define REG_DISPCNT (REG_BASE + 0x000)
#define REG_DISPSTAT (REG_BASE + 0x004)
#define REG_BLDCNT (REG_BASE + 0x050)
#define REG_BLDALPHA (REG_BASE + 0x052)
#define REG_BLDY (REG_BASE + 0x054)

#define PLTT_BASE 0x05000000
#define PLTT_BG ((vu16 *)(PLTT_BASE + 0x00))

#define DCNT_MODE_1 1,
#define DCNT_MODE_2 2,
#define DCNT_MODE_3 3,
#define DCNT_MODE_4 4,
#define DCNT_MODE_5 5,

#define DCNT_CGB (1 << 3)
#define DCNT_PAGE (1 << 4)
#define DCNT_OAM_HBL (1 << 5)
#define DCNT_OBJ_1D (1 << 6)
#define DCNT_BLANK (1 << 7)

#define DCNT_BG0 (1 << 8)
#define DCNT_BG1 (1 << 9)
#define DCNT_BG2 (1 << 10)
#define DCNT_BG3 (1 << 11)
#define DCNT_OBJ (1 << 12)
#define DCNT_WIN0 (1 << 13)
#define DCNT_WIN1 (1 << 14)
#define DCNT_WINOBJ (1 << 15)

#define DSTAT_IN_VBLANK (1 << 0)
#define DSTAT_IN_HBLANK (1 << 1)
#define DSTAT_VCOUNT_MATCH (1 << 2)
#define DSTAT_IF_VBLANK (1 << 3)
#define DSTAT_IF_HBLANK (1 << 4)
#define DSTAT_IF_VCOUNT (1 << 5)

#endif /* GBA_DISPLAY_H */
