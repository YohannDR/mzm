#ifndef DESSGEEGA_AI_H
#define DESSGEEGA_AI_H

#include "../types.h"

u8 dessgeega_check_samus_near_left_right(void);
void dessgeega_init(void);
void dessgeega_jumping_gfx_init(void);
void dessgeega_before_jumping(void);
void dessgeega_before_landing(void);
void dessgeega_check_samus_in_range(void);
void dessgeega_bouncing_gfx_init(void);
void dessgeega_check_bouncing(void);
void dessgeega_check_before_jumping_ceiling_anim_ended(void);
void dessgeega_move_ground(void);
void dessgeega_move_ceiling(void);
void dessgeega_check_landing_anim_ended(void);
void dessgeega_jumping_ground_into_block(void);
void dessgeega_jumping_ceiling_into_block(void);
void dessgeega_ground_idle_anim(void);
void dessgeega_ceiling_idle_anim(void);
void dessgeega_death(void);
void dessgeega_long_beam_detect_samus(void);
void dessgeega_long_beam_spawning(void);
void dessgeega(void);

#endif /* DESSGEEGA_AI_H */