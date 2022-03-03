#ifndef DEOREM_AI_H
#define DEOREM_AI_H

#include "../types.h"
#include "../clipdata.h"

void deorem_change_left_ccaa(enum current_clipdata_affecting_action caa);
void deorem_change_right_ccaa(enum current_clipdata_affecting_action caa);
void deorem_20d90(u8 unk, u16 unk2);
void deorem_random_sprite_debris(u8 rng);
void deorem_sprite_debris_spawn(u16 y_position, u16 x_position, u8 timer);
u8 deorem_check_leaving(u8 ram_slot);
void deorem_spawn_charge_beam(u16 y_position, u16 x_position);
void deorem_set_eye_opening_timer(void);
void deorem_call_spawn_charge_beam(void);
void deorem_init(void);
void deorem_spawn_going_down(void);
void deorem_spawn_going_down_anim(void);
void deorem_spawn_going_up(void);
void deorem_spawn_going_up_anim(void);
void deorem_spawn_head_body(void);
void deorem_after_spawn(void);
void deorem_main_loop(void);
void deorem_retracting(void);
void deorem_throwing_thorns(void);
void deorem_after_thorns(void);
void deorem_dying(void);
void deorem_dying_going_down(void);
void deorem_death(void);
void deorem_check_leaving_ceiling_anim_ended(void);
void deorem_leaving(void);
void deorem_leaving_anim(void);
void deorem_leaving_in_ground_debris(void);
void deorem_segment_init(void);
void deorem_segment_spawn_going_down(void);
void deorem_segment_spawn_going_down_after(void);
void deorem_segment_spawn_going_up(void);
void deorem_segment_spawn_going_up_after(void);
void deorem_segment_right_idle_anim(void);
void deorem_segment_left_idle_anim(void);
void deorem_segment_going_down(void);
void deorem_segment_going_up(void);
void deorem_segment_above_head_movement(void);
void deorem_segment_left_leaving(void);
void deorem_segment_left_leaving_end(void);
void deorem_segment_middle_leaving_end(void);
void deorem_segment_middle_leaving(void);
void deorem_segment_right_leaving(void);
void deorem_segment_right_leaving_end(void);
void deorem_segment_set_timer_dying(void);
void deorem_segment_dying(void);
void deorem_eye_init(void);
void deorem_eye_set_pose9(void);
void deorem_eye_move(void);
void deorem_eye_230d4(void);
void deorem_eye_dying_gfx_init(void);
void deorem_eye_dying_spinning_anim(void);
void deorem_eye_dying_moving_anim(void);
void deorem_thorn_init(void);
void deorem_thorn_spawning(void);
void deorem_thorn_movement(void);
void deorem(void);
void deorem_segment(void);
void deorem_eye(void);
void deorem_thorn(void);

#endif /* DEOREM_AI_H */