#ifndef GBA_INPUT_H
#define GBA_INPUT_H

#include "gba_memory.h"
#define REG_KEYINPUT *(u16 *)(REG_BASE + 0x130)

void update_input(void);

#endif /* GBA_INPUT_H */