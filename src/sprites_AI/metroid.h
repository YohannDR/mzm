#ifndef METROID_AI_H
#define METROID_AI_H

#include "../types.h"

u8 metroid_check_air_collision(u16 y_position, u16 x_position);
void metroid_move(u16 samus_y, u16 samus_x, u8 speed_y, u8 speed_x, u8 speed_divisor);
u8 metroid_bomb_detection(void);
void metroid_check_bouncing_on_metroid(u16 movement);
u8 metroid_check_samus_grabbed(void);
void metroid_play_sound(void);
void metroid_init(void);
void metroid_check_spawn(void);
void metroid_spawning(void);
void metroid_spawned_gfx_init(void);
void metroid_movement(void);
void metroid_grab_samus_gfx_init(void);
void metroid_samus_grabbed(void);
void metroid_death(void);
void metroid(void);
void metroid_shell(void);
void metroid_door_lock(void);

#endif /* METROID_AI_H */