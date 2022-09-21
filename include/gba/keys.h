#ifndef GBA_KEYS_H
#define GBA_KEYS_H

#include "memory.h"
#include "types.h"

#define REG_KEY_INPUT (REG_BASE + 0x130)

#define KEY_NONE 0
#define KEY_A (1 << 0)
#define KEY_B (1 << 1)
#define KEY_SELECT (1 << 2)
#define KEY_START (1 << 3)
#define KEY_RIGHT (1 << 4)
#define KEY_LEFT (1 << 5)
#define KEY_UP (1 << 6)
#define KEY_DOWN (1 << 7)
#define KEY_R (1 << 8)
#define KEY_L (1 << 9)
#define KEY_MASK 0x3ff

#endif /* GBA_KEYS_H */
