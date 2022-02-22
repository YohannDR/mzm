#ifndef DRAGON_AI_H
#define DRAGON_AI_H

#include "../types.h"

void dragon_y_movement(void);
void dragon_init(void);
void dragon_gfx_init(void);
void dragon_go_up(void);
void dragon_turning_turning_around_gfx_init(void);
void dragon_check_turning_around_first_half_anim_ended(void);
void dragon_check_turning_around_second_half_anim_ended(void);
void dragon_spitting_gfx_init(void);
void dragon_spitting_anim(void);
void dragon_spawn_fireball(void);
void dragon_fireball_init(void);
void dragon_fireball_move(void);
void dragon_fireball_exploding_gfx_init(void);
void dragon_fireball_check_exploding_anim_ended(void);
void dragon_void(void);
void dragon_fireball(void);

#endif /* DRAGON_AI_H */