#ifndef MELLA_AI_H
#define MELLA_AI_H

#include "../types.h"

u8 mella_y_movement(u16 movement);
u8 mella_x_movement(u16 movement);
void mella_init(void);
void mella_gfx_init(void);
void mella_idle_animation(void);
void mella_going_down_gfx_init(void);
void mella_going_down(void);
void mella_going_up(void);
void mella(void);

#endif /* MELLA_AI_H */