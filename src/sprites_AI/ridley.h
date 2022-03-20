#ifndef RIDLEY_AI_H
#define RIDLEY_AI_H

#include "../types.h"

void unk_31aa4(void);
void unk_31b40(void);
void unk_31bc8(void);
void unk_31c0c(void);
void ridley_maybe_check_dead(void);
u8 ridley_check_grabbing(u16 y_position, u16 x_position);
void ridley_samus_grabbed(u8 ram_slot);
void ridley_maybe_hitting_tail(void);
u8 ridley_tail_attacks_x_move(u16 movement);
void ridley_tail_attacks_y_move(u16 movement);
void ridley_spawn_fireballs_start(u8 room_slot);
void ridley_check_spawn(void);
void ridley_play_cutscene(void);
void ridley_spawning(void);
void ridley_flying_gfx_init(void);
void ridley_maybe_determine_new_attack(void);
void ridley_turning_around_gfx_init(void);
void ridley_check_turning_around_anim_near_ended(void);
void ridley_check_turning_around_second_part_anim_ended(void);
void unk_334a4(void);
void unk_3350c(void);
void unk_3383c(void);
void ridley_empty(void);
void unk_338b8(void);
void ridley_big_fireballs_attack(void);
void ridley_dying(void);
void ridley_body_init(void);
void unk_33e5c(u8 slot);
void unk_33ecc(void);
void unk_33f04(u8 slot);
void unk_33f48(void);
void ridley_tail_dead(void);
void ridley_tail_init(void);
void unk_34154(void);
void unk_341c8(void);
void unk_341f8(void);
void unk_34278(void);
void unk_343a0(void);
void unk_34420(void);
void unk_3450c(void);
void unk_345b4(void);
void unk_3463c(void);
void unk_346c0(void);
void ridley_fireballs_init(void);
void ridley_fireball_small_move(void);
void ridley_fireball_big_move(void);
void ridley_fireball_medium_move(void);
void unk_34994(void);
void unk_349e4(void);
void unk_349fc(void);
void ridley(void);
void ridley_tail(void);
void ridley_body(void);
void ridley_fireball(void);

#endif /* RIDLEY_AI_H */