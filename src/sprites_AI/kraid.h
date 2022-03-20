#ifndef KRAID_AI_H
#define KRAID_AI_H

#include "../types.h"

void kraid_mouth_determine_spike_position(void);
void kraid_check_projectiles_colliding_with_belly(void);
void kraid_open_close_routine_and_projectile_collision(void);
void kraid_random_sprite_debris_on_ceiling(u8 rng);
void kraid_mouth_hitbox_change1_unused(void);
void kraid_mouth_update_arm_idling_hitbox(void);
void kraid_mouth_update_arm_attacking_hitbox(void);
void kraid_mouth_hitbox_change2_unused(void);
void kraid_mouth_update_left_arm_idling_hitbox(void);
void kraid_mouth_maybe_update_arm_dying_hitbox(void);
void kraid_mouth_update_left_arm_attacking_hitbox(void);
void kraid_BG2_horizontal_movement_related_maybe_perhaps(u8 movement);
void kraid_init(void);
u8 kraid_is_fully_up(void);
void kraid_go_up(void);
void kraid_check_fully_up(void);
u8 kraid_move_feet(void);
void kraid_feet_movement_same_direction_as_position_update(void);
void kraid_move_feet_to_opposite_direction_as_position(void);
void kraid_feet_movement_opposite_direction_as_position_update(void);
void kraid_end_two_steps(void);
void kraid_before_start_moving_feet_same_direction_as_position(void);
void kraid_after_moving_feet_same_direction_as_position(void);
void kraid_before_start_start_moving_feet_opposite_direction_as_position(void);
void kraid_prevent_samus_going_through(void);
void kraid_death(void);
void kraid_dying(void);
void kraid_before_death(void);
void kraid_mouth_init(void);
void kraid_mouth_throw_nails(void);
void kraid_mouth_check_samus_near(void);
void kraid_mouth_call_kraid_check_projectiles_colliding_with_belly(void);
void kraid_mouth_check_should_spawn_spikes(void);
void kraid_mouth_spawn_spike(void);
void kraid_mouth_despawn_secondary_sprites(void);
void kraid_mouth_arm_movement_dying(void);
void kraid_mouth_arm_movement_dying_stationary(void);
void kraid_nail_movement(void);
void kraid(void);
void kraid_mouth(void);
void kraid_spike(void);
void kraid_nail(void);

#endif /* KRAID_AI_H */