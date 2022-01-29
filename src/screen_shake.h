#ifndef SCREEN_SHAKE_H
#define SCREEN_SHAKE_H

#include "types.h"

struct screen_shake {
    u8 timer;
    u8 loop_counter;
    u8 unknown; // intensity ?
    u8 unknown2;
};

u8 screen_shake_start_vertical(u8 duration, u8 unk);
u8 screen_shake_start_horizontal(u8 duration, u8 unk);
u8 screen_shake_start_horizontal_unused(u8 duration);
i32 screen_shake_update_vertical(void);
i32 screen_shake_update_horizontal(void);

#endif /* SCREEN_SHAKE_H */