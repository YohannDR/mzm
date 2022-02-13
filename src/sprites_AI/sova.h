#ifndef SOVA_AI_H
#define SOVA_AI_H

#include "../types.h"

u8 sova_check_colliding_with_air(void);
void sova_hitbox_update(void);
void sova_gfx_update(void);
void sova_init(void);
void sova_gfx_init(void);
void sova_move(void);
void sova_turning_around_gfx_update(void);
void sova_turning_around(void);
void sova_back_on_ground(void);
void sova_check_back_on_ground_anim_ended(void);
void sova_start_falling(void);
void sova_falling(void);
void sova_death(void);
void sova(void);

#endif /* SOVA_AI_H */