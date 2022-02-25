#ifndef POWER_BOMB_EXPLOSION_H
#define POWER_BOMB_EXPLOSION_H

#include "types.h"

void power_bomb_explosion_process(void);
void power_bomb_explosion(void);
void power_bomb_explosion_start(u16 x_position, u16 y_position, u8 zero);
void power_bomb_explosion_set_0x12_to_0(void);
void power_bomb_explosion_begin(void);
void power_bomb_explosion_end(void);

#endif /* POWER_BOMB_EXPLOSION_H */