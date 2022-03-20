#ifndef ACID_WORM_AI_H
#define ACID_WORM_AI_H

#include "../types.h"

void acid_worm_sync_head_position(void);
void acid_worm_random_x_movement(void);
void acid_worm_change_two_ground_ccaa(u8 caa, u16 y_position, u16 x_position);
void acid_worm_change_big_block_down_ccaa(u8 caa);
void acid_worm_change_big_block_middle_ccaa(u8 caa);
void acid_worm_change_big_block_top_ccaa(u8 caa);
void acid_worm_play_sound(void);
u8 acid_worm_colliding_with_samus_when_extending(void);
void acid_worm_init(void);
void acid_worm_check_samus_on_zipline(void);
void acid_worm_spawn_start(void);
void acid_worm_spawn_extending(void);
void acid_worm_spawn_staying_on_top(void);
void acid_worm_spawn_retracting(void);
void acid_worm_gfx_init(void);
void acid_worm_idle(void);
void acid_worm_check_warning_anim_ended(void);
void acid_worm_extend(void);
void acid_worm_hooked_to_block(void);
void acid_worm_retracting(void);
void acid_worm_raise_acid(void);
void acid_worm_acid_go_down(void);
void acid_worm_death_gfx_init(void);
void acid_worm_death_flashing_anim(void);
void acid_worm_dying(void);
void acid_worm_body_init(void);
void acid_worm_body_move(void);
void acid_worm_body_main_loop(void);
void acid_worm_body_death(void);
void acid_worm_spit_init(void);
void acid_worm_spit_move(void);
void acid_worm_spit_exploding_gfx_init(void);
void acid_worm_spit_check_exploding_anim_ended(void);
void acid_worm_spit_check_exploding_on_acid_anim_ended(void);
void acid_worm(void);
void acid_worm_body(void);
void acid_worm_spit(void);

#endif /* ACID_WORM_AI_H */