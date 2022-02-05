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

void samus_set_landing_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_change_to_hurt_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{
    i16 new_x_velo; 
    i16 new_y_velo; 
    u8 y_pos_related;

    if (equipment.current_energy != 0x0)
    {
        y_pos_related = 0x0;
        switch (copy_ptr->pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            case SPOSE_DELAY_BEFORE_BALLSPARKING:
            case SPOSE_BALLSPARK_COLLISION:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
            case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
                data_ptr->pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            case SPOSE_CRAWLING_STOPPED:
            case SPOSE_STARTING_TO_CRAWL:
            case SPOSE_CRAWLING:
            case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            case SPOSE_SHOOTING_WHILE_CRAWLING:
                data_ptr->pose = SPOSE_CRAWLING_STOPPED;
                data_ptr->x_velocity = 0x0;
                break;

            default:
                y_pos_related = unk_57EC(data_ptr, array_23a534[0x2]);
                data_ptr->pose = SPOSE_GETTING_HURT;
        }

        if (y_pos_related != 0x0)
            data_ptr->y_position |= 0x3F;

        if (copy_ptr->forced_movement == 0xFF)
            data_ptr->forced_movement = 0x1;

        data_ptr->y_velocity = 0x70;
        if (copy_ptr->standing_status == STANDING_MIDAIR)
            data_ptr->y_velocity = 0x38;

        data_ptr->arm_cannon_direction = copy_ptr->arm_cannon_direction;
        play_sound1(0x7C);
    }
    else
    {
        disable_scrolling = 0x1;
        bg_fading = 0x1;
        data_ptr->pose = SPOSE_DYING;
        new_x_velo = ((bg1_x_position + 0x1E0) - data_ptr->x_position);
        new_x_velo >>= 0x1;
        data_ptr->x_velocity = new_x_velo;
        new_y_velo = ((bg1_y_position + 0x190) - data_ptr->y_position);
        new_y_velo >>= 0x4;
        data_ptr->y_velocity = new_y_velo;
        game_mode_sub1 = 0x5;
    }

    data_ptr->invincibility_timer = 0x30;
    data_ptr->shinespark_timer = 0x0;
    data_ptr->standing_status = STANDING_MIDAIR;
    weapon_ptr->new_projectile = NEW_PROJ_NONE;
    weapon_ptr->beam_release_palette_timer = 0x0;
}

void samus_change_to_knockback_pose(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{
    u8 y_pos_related;

    y_pos_related = 0x0;
    switch (copy_ptr->pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            data_ptr->pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
            data_ptr->pose = SPOSE_CRAWLING_STOPPED;
            break;

        default:
            y_pos_related = unk_57EC(data_ptr, array_23a534[0x2]);
            data_ptr->pose = SPOSE_GETTING_KNOCKED_BACK;
    }
    
    if (y_pos_related != 0x0)
        data_ptr->y_position |= 0x3F;

    data_ptr->y_velocity = 0x70;
    if (copy_ptr->standing_status == STANDING_MIDAIR)
        data_ptr->y_velocity = 0x38;

    data_ptr->arm_cannon_direction = copy_ptr->arm_cannon_direction;
    data_ptr->shinespark_timer = 0x0;
    data_ptr->standing_status = STANDING_MIDAIR;
    weapon_ptr->new_projectile = NEW_PROJ_NONE;
    weapon_ptr->beam_release_palette_timer = 0x0;
}

void samus_turn_around_arm_cannon_start_shinespark(struct samus_data* data_ptr, struct samus_data* copy_ptr, struct weapon_info* weapon_ptr)
{

}

void samus_set_pose(enum samus_pose pose)
{
    struct weapon_info* pWeapon;
    struct samus_data* pData;
    struct samus_data* pData_copy;

    pData = &samus_data;
    pData_copy = &samus_data_copy;
    pWeapon = &samus_weapon_info;

    if ((u32)(pose * 0x1000000 + 0x7000000) >> 0x18 < 0x2)
        pData->turning = FALSE;

    samus_copy_data(pData);

    if (pData_copy->arm_cannon_direction == ACD_NONE)
        pData_copy->arm_cannon_direction = ACD_FORWARD;

    switch (pData_copy->pose)
    {
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            if (pose == SPOSE_SHINESPARKING) break;
            play_sound(0x8E);
            break;
        case SPOSE_SHINESPARKING:
            if (pose == SPOSE_SHINESPARK_COLLISION) break;
            play_sound(0x8E);
            break;
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARKING)
                play_sound2(0x8F);
            break;
        case SPOSE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARK_COLLISION)
                play_sound2(0x8F);
    }

    switch (pose)
    {
        case SPOSE_UPDATE_JUMP_VELOCITY_REQUEST:
            samus_update_jump_velocity(pData, pData_copy, pWeapon);
            return;
        case SPOSE_LANDING_REQUEST:
            samus_set_landing_pose(pData, pData_copy, pWeapon);
            return;
        case SPOSE_HURT_REQUEST:
            samus_change_to_hurt_pose(pData, pData_copy, pWeapon);
            return;
        case SPOSE_KNOCKBACK_REQUEST:
            samus_change_to_knockback_pose(pData, pData_copy, pWeapon);
            return;
    }

    pData->pose = pose;
    samus_turn_around_arm_cannon_start_shinespark(pData, pData_copy, pWeapon);
}

void samus_copy_data(struct samus_data* data_ptr)
{
    struct samus_data* data;
    struct screw_attack_animation* screw;
    struct samus_data* data_copy;

    data = &samus_data;
    screw = &screw_attack_animation;
    data_copy = &samus_data_copy;

    *data_copy = *data;
    if (data->turning != FALSE)
    {
        data->direction ^= (DIRECTION_LEFT | DIRECTION_RIGHT);
        data->turning = FALSE;
    }

    data->arm_cannon_direction = ACD_FORWARD;
    data->forced_movement = 0x0;
    data->speedboosting_shinesparking = FALSE;
    data->walljump_timer = 0x0;
    data->speedbooster_timer = 0x0;
    data->last_wall_touched_midair = 0x0;
    data->unknown = 0x0;
    data->x_velocity = 0x0;
    data->y_velocity = 0x0;
    data->anim_duration_counter = 0x0;
    data->curr_anim_frame = 0x0;

    if (data->shinespark_timer != 0xB4)
        screw->screw_attacking = FALSE;

    screw->anim_duration_counter = 0x0;
    screw->curr_anim_frame = 0x0;
}

void samus_update_physics(struct samus_data* data_ptr)
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
    enum samus_pose new_pose;
    struct samus_data* pData;

    pData = &samus_data;

    if (0x1 < game_mode_sub1)
        pData->anim_duration_counter++;
    
    samus_update_physics(pData);
    new_pose = samus_execute_pose_subroutine(pData);
    if (new_pose != SPOSE_NONE)
        samus_set_pose(new_pose);
    samus_gfx_related(pData, &samus_physics);
    samus_update_velocity_position(pData);
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
    /*enum suit_misc_flags suit_misc;
    u8 flag;

    switch (data_ptr->pose)
    {
        case SPOSE_SPINNING:
            if (samus_physics.slowed_by_liquid != FALSE)
                break;

            suit_misc = equipment_ptr->suit_misc_activation;
            if ((suit_misc & SMF_SCREW_ATTACK) == 0x0)
            {
                if ((suit_misc & SMF_SPACE_JUMP) == 0x0)
                    break;
                data_ptr->pose = SPOSE_SPACE_JUMPING;
                break;
            }
            data_ptr->pose = SPOSE_SCREW_ATTACKING;
            break;

        case SPOSE_SPACE_JUMPING:
            suit_misc = equipment_ptr->suit_misc_activation;
            flag = suit_misc & SMF_SCREW_ATTACK;
            if (flag == 0x0)
            {
                if ((suit_misc & SMF_SPACE_JUMP) != 0x0 && samus_physics.slowed_by_liquid == FALSE)
                    break;
                data_ptr->pose = SPOSE_SPINNING;
                data_ptr->curr_anim_frame = flag;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (samus_physics.slowed_by_liquid == FALSE)
            {
                suit_misc = equipment_ptr->suit_misc_activation;
                if ((suit_misc & SMF_SCREW_ATTACK) == 0x0)
                {
                    if ((suit_misc & SPOSE_SPACE_JUMPING) == 0x0)
                        data_ptr->pose = SPOSE_SPINNING;
                    else
                        data_ptr->pose = SPOSE_SPACE_JUMPING;
                        data_ptr->curr_anim_frame = 0x0;
                }
            }
            else
            {
                data_ptr->pose = SPOSE_SPINNING;
                data_ptr->curr_anim_frame = 0x0;
            }
            screw_attack_animation.screw_attacking = FALSE;
    }*/
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
    return SPOSE_NONE;
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

enum samus_pose samus_execute_pose_subroutine(struct samus_data* data_ptr)
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