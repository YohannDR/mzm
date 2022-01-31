#ifndef SPRITE_UTIL_H
#define SPRITE_UTIL_H

#include "sprite.h"
#include "types.h"
#include "particle.h"

enum __attribute__ ((packed)) damage_contact_type {
    DCT_NONE = 0x0,
    DCT_SHINESPARK = 0x1,
    DCT_SPEEDBOOSTER = 0x2,
    DCT_SCREW_ATTACK = 0x3,
    DCT_SUDO_SCREW = 0x4,
};

enum __attribute__ ((packed)) death_type {
    DEATH_NORMAL = 0x0,
    DEATH_RESPAWNING = 0x1,
    DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP = 0x2,
};

enum __attribute__ ((packed)) splash_size {
    SPLASH_NONE = 0x0,
    SPLASH_SMALL = 0x1,
    SPLASH_BIG = 0x2,
    SPLASH_HUGE = 0x3,
};

void sprite_util_current_sprite_fall(void);
void sprite_util_choose_random_x_flip(void);
void sprite_util_choose_random_x_direction(void);
void sprite_util_choose_random_x_direction_room_slot(u8 room_slot);
void sprite_util_make_sprite_face_samus_x_flip(void);
void sprite_util_make_sprite_face_samus_direction(void);
void sprite_util_make_sprite_face_away_samus_x_flip(void);
void sprite_util_make_sprite_face_away_samus_direction(void);
void unk_f978(u8 unk);
void unk_f9e7(u8 unk);
u8 sprite_util_make_sprite_face_samus_rotation(u8 oam_rotation, u16 samus_y, u16 samus_x, u16 sprite_y, u16 sprite_x);
u8 sprite_util_check_end_current_sprite_anim(void);
u8 sprite_util_check_near_end_current_sprite_anim(void);
u8 sprite_util_check_end_sprite_anim(u8 ram_slot);
u8 sprite_util_check_near_end_sprite_anim(u8 ram_slot);
u8 sprite_util_check_end_sub_sprite1_anim(void);
u8 sprite_util_check_near_end_sub_sprite1_anim(void);
u8 sprite_util_check_end_sub_sprite2_anim(void);
u8 sprite_util_check_end_sub_sprite_anim(struct sub_sprite_data* ptr);
u8 sprite_util_check_near_end_sub_sprite_anim(struct sub_sprite_data* ptr);
u8 sprite_util_check_samus_near_sprite_left_right(u16 y_range, u8 x_range);
u8 sprite_util_check_samus_near_sprite_above_below(u16 y_range, u8 x_range);
u8 sprite_util_check_samus_near_sprite_front_behind(u16 y_range, u8 x_range_front, u8 x_range_behind);
u8 sprite_util_samus_standing_on_sprite(struct sprite_data* ptr);
void sprite_util_update_freeze_timer(void);
void sprite_util_update_secondary_sprite_freeze_timer(enum s_sprite_id sprite_id, u8 ram_slot);
void sprite_util_unfreeze_anim_eay(void);
void sprite_util_metroid_unfreeze_anim(void);
void sprite_util_update_primary_sprite_freeze_timer_of_current(void);
void sprite_util_unfreeze_secondary_sprites(enum s_sprite_id sprite_id, u8 ram_slot);
u8 sprite_util_refill_energy(void);
u8 sprite_util_refill_missile(void);
u8 sprite_util_refull_super_missiles(void);
u8 sprite_util_refill_power_bombs(void);
u8 sprite_util_check_crouching_or_morphed(void);
u8 sprite_util_check_crouching_or_crawling(void);
u8 sprite_util_check_morphed(void);
u8 sprite_util_check_stop_sprites_pose(void);
enum damage_contact_type sprite_util_sprite_take_damage_from_samus_contact(struct sprite_data* sprite_ptr, struct samus_data* samus_ptr);
u8 sprite_util_check_pulling_self_up(void);
u8 sprite_util_check_on_zipline(void);
u8 sprite_util_count_primary_sprites(enum p_sprite_id sprite_id);
u8 sprite_util_count_secondary_sprites_with_current_sprite_ram_slot(enum s_sprite_id sprite_id);
u8 sprite_util_count_primary_sprites_with_current_sprite_ram_slot(enum p_sprite_id sprite_id);
u8 sprite_util_find_primary(enum p_sprite_id sprite_id);
u8 sprite_util_find_secondary_with_room_slot(enum s_sprite_id sprite_id, u8 room_slot);
u8 sprite_util_check_has_drop(void);
u8 sprite_util_count_drops(void);
void sprite_util_maybe_mecha_ridley_missile_move(u16 samus_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor);
void sprite_util_maybe_ridley_fireball_move(u16 sprite_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor);
void sprite_util_update_stun_timer(struct sprite_data* ptr);
void sprite_util_random_debris(u8 cloud_type, u8 number, u16 y_position, u16 x_position);
enum p_sprite_id sprite_util_get_ammo_drop(u8 rng);
enum p_sprite_id sprite_util_determine_enemy_drop(void);
void sprite_util_sprite_death(enum death_type death_type, u16 y_position, u16 x_position, u8 play_sound, enum particle_effect_id effect);
u8 sprite_util_is_sprite_stunned(void);
u8 sprite_util_is_screen_on_screen_and_screen_shake(void);
void sprite_util_maybe_update_sub_sprite1_timer(void);
void sprite_util_update_sub_sprite1_anim(void);
void sprite_util_sync_current_sprite_position_with_sub_sprite1_position(void);
void unk_113b0(void);
void sprite_util_update_sub_sprite2_anim(void);
void unk_1144c(void);
void sprite_util_update_sub_sprite_anim(struct sub_sprite_data* ptr);
void sprite_util_sync_current_sprite_position_with_sub_sprite_position(struct sub_sprite_data* ptr);
void unk_11520(struct sub_sprite_data* ptr);
u8 sprite_util_security_gate_samus_collision(void);
void sprite_util_set_splash_effect(u16 y_position, u16 x_position, enum splash_size size);
u8 sprite_util_check_out_of_room_effect(u16 old_y, u16 y_positoin, u16 x_position, enum splash_size size);
u8 sprite_util_check_in_room_effect(u16 old_y, u16 y_positoin, u16 x_position, enum splash_size size);
u16 sprite_util_get_final_completion_percentage(void);

#endif /* SPRITE_UTIL_H */