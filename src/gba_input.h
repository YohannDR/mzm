#ifndef GBA_INPUT_H
#define GBA_INPUT_H

#include "gba_memory.h"
#define REG_KEYINPUT *(u16 *)(REG_BASE + 0x130)

enum __attribute__((packed)) input_flag {
    INPUT_NONE = 0x0,
    INPUT_A = 0x1,
    INPUT_B = 0x2,
    INPUT_SELECT = 0x4,
    INPUT_START = 0x8,
    INPUT_RIGHT = 0x10,
    INPUT_LEFT = 0x20,
    INPUT_UP = 0x40,
    INPUT_DOWN = 0x80,
    INPUT_R = 0x100,
    INPUT_L = 0x200
};

struct button_assignements {
    enum input_flag arm_missiles;
    enum input_flag diagonal_aim;
    enum input_flag swap_missiles;
    enum input_flag pause;
};

void update_input(void);

#endif /* GBA_INPUT_H */