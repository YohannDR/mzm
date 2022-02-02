#include "samus.h"
#include "globals.h"

void samus_check_screw_speedbooster_affecting_environment(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{
    
}

u8 samus_slope_related(u16 x_position, u16 y_position, u16* next_x_position, u16* next_y_position, enum slope_type* next_slope_type)
{

}

u8 unk_5604(struct samus_data* data_ptr, struct samus_physics* physics_ptr, u16 x_position, u16* next_x_position)
{

}

u8 unk_56B8(struct samus_data* data_ptr, struct samus_physics* physics_ptr, u16 x_position, u16* next_x_position)
{

}

u8 unk_5794(struct samus_data* data_ptr, i16 x_offset)
{

}

u8 unk_57EC(struct samus_data* data_ptr, i16 unk)
{

}

enum samus_pose unk_58A0(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

enum samus_pose unk_5AD8(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

enum samus_pose unk_5B8C(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

enum samus_pose samus_check_landing_collision(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

enum samus_pose samus_check_top_collision(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

enum samus_pose samus_check_collisions(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

void samus_check_set_environmental_effect(struct samus_data* data_ptr, u8 default_offset, enum ground_effect_wanted request)
{

}

void samus_update_environmental_effect(struct samus_data* data_ptr)
{

}

void samus_update_jump_velocity(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_set_landing_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr)
{

}

void samus_change_to_hurt_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_change_to_knockback_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_turn_around_arm_cannon_start_shinespark(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_set_pose(enum samus_pose pose)
{

}

void samus_copy_data(void)
{

}

void samus_update_physics(void)
{

}

i16 samus_change_velocity_on_slope(struct samus_data* data_ptr)
{

}

void samus_copy_palette(u16* src, i32 offset, i32 nbr_colors)
{

}

void samus_update(void)
{

}

void samus_update_physics_hitbox_position(void)
{

}

void samus_call_gfx_functions(void)
{

}

void samus_call_check_low_health(void)
{

}

void samus_call_update_arm_cannon_position_offset(void)
{

}

void samus_bounce_bomb(u8 direction)
{

}

void samus_aim_cannon(struct samus_data* data_ptr)
{

}

u8 samus_fire_beam_missile(struct samus_data* data_ptr, struct weapon_info* weapon_ptr, struct equipment* equipment_ptr)
{

}

u8 samus_fire_check_fully_charged_pistol(struct samus_data* data_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_spawn_new_projectile(struct samus_data* data_ptr, struct weapon_info* weapon_ptr, struct equipment* equipment_ptr)
{

}

u8 samus_check_a_pressed(struct samus_data* data_ptr)
{
    u8 return_value;
    
    return_value = 0x0;
    if ((buttons_changed & 0x1) != 0x0)
    {
        data_ptr->forced_movement = 0x1;
        return_value = 0x1;
    }
    return return_value;
}

void samus_set_highlighted_weapon(struct samus_data* data_ptr, struct weapon_info* weapon_ptr, struct equipment* equipment_ptr)
{

}

void samus_set_spinning_pose(struct samus_data* data_ptr, struct equipment* equipment_ptr)
{

}

void samus_apply_x_acceleration(i16 acceleration, i16 velocity, struct samus_data* data_ptr)
{

}

u8 samus_hazard_damage(struct samus_data* data_ptr, struct equipment* equipment_ptr*, struct samus_hazard_damage* hazard_ptr)
{

}

void samus_check_shinesparking(struct samus_data* data_ptr)
{

}

enum samus_pose samus_inactivity(struct samus_data* data_ptr)
{

}

u8 unk_847C(struct samus_data* data_ptr, u8 unk)
{

}

enum samus_pose samus_running(struct samus_data* data_ptr)
{

}

enum samus_pose samus_running_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_standing(struct samus_data* data_ptr)
{

}

enum samus_pose samus_standing_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shooting_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_crouching(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_and_crouching(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_and_crouching_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shooting_and_crouching_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_skidding(struct samus_data* data_ptr)
{

}

enum samus_pose samus_midair(struct samus_data* data_ptr)
{

}

enum samus_pose samus_midair_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_midair(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_midair_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_starting_spin_jump_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_spinning(struct samus_data* data_ptr)
{

}

enum samus_pose samus_spinning_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_starting_wall_jump(struct samus_data* data_ptr)
{

}

enum samus_pose samus_starting_wall_jump_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_space_jumping_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_screw_attacking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_morphing(struct samus_data* data_ptr)
{

}

enum samus_pose samus_morphing_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_morphball(struct samus_data* data_ptr)
{

}

enum samus_pose samus_rolling(struct samus_data* data_ptr)
{

}

enum samus_pose samus_rolling_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_unmorphing(struct samus_data* data_ptr)
{

}

enum samus_pose samus_unmorphing_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_morphball_midair(struct samus_data* data_ptr)
{

}

enum samus_pose samus_hanging_on_ledge(struct samus_data* data_ptr)
{

}

enum samus_pose samus_hanging_on_ledge_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_to_aim_while_hanging(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_to_aim_while_hanging_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_hiding_arm_cannon_while_hanging_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_aiming_while_hanging(struct samus_data* data_ptr)
{

}

enum samus_pose samus_pulling_self_up(struct samus_data* data_ptr)
{

}

enum samus_pose samus_pulling_self_up_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_pulling_self_forward(struct samus_data* data_ptr)
{

}

enum samus_pose samus_pulling_self_forward_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_pulling_self_into_morphball_tunnel_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_using_an_elevator(struct samus_data* data_ptr)
{

}

enum samus_pose samus_using_an_elevator_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_facing_the_foreground(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_from_facing_foreground_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_delay_before_shinesparking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shinesparking(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shinesparking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shinespark_collision_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_delay_after_shinesparking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_delay_before_ballsparking(struct samus_data* data_ptr)
{

}

enum samus_pose samus_delay_before_ballsparking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_ballsparking_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_ballspark_collision_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_on_zipline(struct samus_data* data_ptr)
{

}

enum samus_pose samus_shooting_on_zipline_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_morphball_on_zipline(struct samus_data* data_ptr)
{

}

enum samus_pose samus_saving_loading_game(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_to_download_map_data_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_getting_hurt(struct samus_data* data_ptr)
{

}

enum samus_pose samus_getting_hurt_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_getting_knocked_back(struct samus_data* data_ptr)
{

}

enum samus_pose samus_dying(struct samus_data* data_ptr)
{

}

enum samus_pose samus_getting_knocked_back_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_crawling_stopped(struct samus_data* data_ptr)
{

}

enum samus_pose samus_getting_knocked_back_in_morphball_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_crawling(struct samus_data* data_ptr)
{

}

enum samus_pose samus_dying_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_around_while_crawling(struct samus_data* data_ptr)
{

}

enum samus_pose samus_crawling_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_uncrouching_suitless_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_facing_the_background(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_from_facing_the_background_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_turning_to_enter_escape_ship_gfx(struct samus_data* data_ptr)
{

}

enum samus_pose samus_excute_pose_subroutine(struct samus_data* data_ptr)
{

}

void samus_update_velocity_position(struct samus_data* data_ptr)
{

}

void samus_update_graphics_oam(struct samus_data* data_ptr, u8 direction)
{

}

void samus_update_animation_timer_palette(struct samus_data* data_ptr)
{

}

void samus_check_play_low_health_sound(void)
{

}

void samus_gfx_related(struct samus_data* data_ptr, struct samus_physics* physics_ptr)
{

}

void samus_update_arm_cannon_oam(u8 direction)
{

}

void samus_init(void)
{

}

void samus_draw(void)
{

}