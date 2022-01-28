#ifndef GBA_KEYS_H
#define GBA_KEYS_H

#include "gba/memory.h"
#include "types.h"

#define REG_KEY_INPUT (REG_BASE + 0x130)

enum keys {
    KEY_NONE   = 0,
    KEY_A      = 1 << 0,
    KEY_B      = 1 << 1,
    KEY_SELECT = 1 << 2,
    KEY_START  = 1 << 3,
    KEY_RIGHT  = 1 << 4,
    KEY_LEFT   = 1 << 5,
    KEY_UP     = 1 << 6,
    KEY_DOWN   = 1 << 7,
    KEY_R      = 1 << 8,
    KEY_L      = 1 << 9,
};

#endif /* GBA_KEYS_H */
