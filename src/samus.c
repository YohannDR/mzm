#include "samus.h"
#include "sprite.h"
#include "clipdata.h"
#include "globals.h"

void samus_check_screw_speedbooster_affecting_environment(struct samus_data* pData, struct samus_physics* pPhysics)
{
    
}

u8 samus_slope_related(u16 x_position, u16 y_position, u16* next_x_position, u16* next_y_position, enum slope_type* next_slope_type)
{

}

u8 unk_5604(struct samus_data* pData, struct samus_physics* pPhysics, u16 x_position, u16* next_x_position)
{

}

u8 unk_56B8(struct samus_data* pData, struct samus_physics* pPhysics, u16 x_position, u16* next_x_position)
{

}

u8 unk_5794(struct samus_data* pData, i16 x_offset)
{

}

u8 unk_57EC(struct samus_data* pData, i16 unk)
{

}

enum samus_pose samus_check_walking_sides_collision(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

enum samus_pose unk_5AD8(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

enum samus_pose samus_check_standing_on_ground_collision(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

enum samus_pose samus_check_landing_collision(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

enum samus_pose samus_check_top_collision(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

enum samus_pose samus_check_collisions(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

void samus_check_set_environmental_effect(struct samus_data* pData, u8 default_offset, enum ground_effect_wanted request)
{

}

void samus_update_environmental_effect(struct samus_data* pData)
{

}

void samus_update_jump_velocity(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon)
{

}

void samus_set_landing_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon)
{

}

void samus_change_to_hurt_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon)
{
    i16 new_x_velo; 
    i16 new_y_velo; 
    u8 y_pos_related;

    if (equipment.current_energy != 0x0)
    {
        y_pos_related = 0x0;
        switch (pCopy->pose)
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
                pData->pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            case SPOSE_CRAWLING_STOPPED:
            case SPOSE_STARTING_TO_CRAWL:
            case SPOSE_CRAWLING:
            case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            case SPOSE_SHOOTING_WHILE_CRAWLING:
                pData->pose = SPOSE_CRAWLING_STOPPED;
                pData->x_velocity = 0x0;
                break;

            default:
                y_pos_related = unk_57EC(pData, array_23a534[0x2]);
                pData->pose = SPOSE_GETTING_HURT;
        }

        if (y_pos_related != 0x0)
            pData->y_position |= 0x3F;

        if (pCopy->forced_movement == 0xFF)
            pData->forced_movement = 0x1;

        pData->y_velocity = 0x70;
        if (pCopy->standing_status == STANDING_MIDAIR)
            pData->y_velocity = 0x38;

        pData->arm_cannon_direction = pCopy->arm_cannon_direction;
        play_sound1(0x7C);
    }
    else
    {
        disable_scrolling = 0x1;
        bg_fading = 0x1;
        pData->pose = SPOSE_DYING;
        new_x_velo = ((bg1_x_position + 0x1E0) - pData->x_position);
        new_x_velo >>= 0x1;
        pData->x_velocity = new_x_velo;
        new_y_velo = ((bg1_y_position + 0x190) - pData->y_position);
        new_y_velo >>= 0x4;
        pData->y_velocity = new_y_velo;
        game_mode_sub1 = 0x5;
    }

    pData->invincibility_timer = 0x30;
    pData->shinespark_timer = 0x0;
    pData->standing_status = STANDING_MIDAIR;
    pWeapon->new_projectile = PROJECTILE_NONE;
    pWeapon->beam_release_palette_timer = 0x0;
}

void samus_change_to_knockback_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon)
{
    u8 y_pos_related;

    y_pos_related = 0x0;
    switch (pCopy->pose)
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
            pData->pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
            pData->pose = SPOSE_CRAWLING_STOPPED;
            break;

        default:
            y_pos_related = unk_57EC(pData, array_23a534[0x2]);
            pData->pose = SPOSE_GETTING_KNOCKED_BACK;
    }
    
    if (y_pos_related != 0x0)
        pData->y_position |= 0x3F;

    pData->y_velocity = 0x70;
    if (pCopy->standing_status == STANDING_MIDAIR)
        pData->y_velocity = 0x38;

    pData->arm_cannon_direction = pCopy->arm_cannon_direction;
    pData->shinespark_timer = 0x0;
    pData->standing_status = STANDING_MIDAIR;
    pWeapon->new_projectile = PROJECTILE_NONE;
    pWeapon->beam_release_palette_timer = 0x0;
}

void samus_turn_around_arm_cannon_start_shinespark(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon)
{

}

void samus_set_pose(enum samus_pose pose)
{
    struct weapon_info* pWeapon;
    struct samus_data* pData;
    struct samus_data* pCopy;

    pData = &samus_data;
    pCopy = &samus_data_copy;
    pWeapon = &samus_weapon_info;

    if ((u32)(pose * 0x1000000 + 0x7000000) >> 0x18 < 0x2)
        pData->turning = FALSE;

    samus_copy_data(pData);

    if (pCopy->arm_cannon_direction == ACD_NONE)
        pCopy->arm_cannon_direction = ACD_FORWARD;

    switch (pCopy->pose)
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
            samus_update_jump_velocity(pData, pCopy, pWeapon);
            return;
        case SPOSE_LANDING_REQUEST:
            samus_set_landing_pose(pData, pCopy, pWeapon);
            return;
        case SPOSE_HURT_REQUEST:
            samus_change_to_hurt_pose(pData, pCopy, pWeapon);
            return;
        case SPOSE_KNOCKBACK_REQUEST:
            samus_change_to_knockback_pose(pData, pCopy, pWeapon);
            return;
    }

    pData->pose = pose;
    samus_turn_around_arm_cannon_start_shinespark(pData, pCopy, pWeapon);
}

void samus_copy_data(struct samus_data* pData)
{
    struct samus_data* data;
    struct screw_speed_animation* screw;
    struct samus_data* data_copy;

    data = &samus_data;
    screw = &screw_speed_animation;
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
        screw->flag = FALSE;

    screw->anim_duration_counter = 0x0;
    screw->curr_anim_frame = 0x0;
}

void samus_update_physics(struct samus_data* pData)
{

}

i16 samus_change_velocity_on_slope(struct samus_data* pData)
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

void samus_update_hitbox_moving_direction(void)
{
    struct samus_data* pData;
    struct samus_physics* pPhysics;
    enum h_direction_moving* pDirection;

    pData = &samus_data;
    pPhysics = &samus_physics;

    pPhysics->touching_side_block = FALSE;
    pPhysics->touching_top_block = FALSE;
    pPhysics->unknown = 0x0;
    pDirection = &pPhysics->horizontal_moving_direction;
    *pDirection = HDMOVING_NONE;
    pPhysics->vertical_moving_direction = VDMOVING_NONE;
    
    if (pData->x_position > previous_x_position)
        *pDirection = HDMOVING_RIGHT;
    else if (pData->x_position < previous_x_position)
        *pDirection = HDMOVING_LEFT;

    if (unk_03004fc9 == 0x0)
    {
        if (pData->y_position > previous_y_position)
            pPhysics->vertical_moving_direction = VDMOVING_DOWN;
        else if (pData->y_position < previous_y_position)
            pPhysics->vertical_moving_direction = VDMOVING_UP;
    }

    pPhysics->standing_status = samus_visual_data_239464[pData->pose][0x2];
    pPhysics->hitbox_left_offset = samus_hitbox_data_23a554[pPhysics->hitbox_array_offset][0x0];
    pPhysics->hitbox_right_offset = samus_hitbox_data_23a554[pPhysics->hitbox_array_offset][0x1];
    pPhysics->hitbox_top_offset = samus_hitbox_data_23a554[pPhysics->hitbox_array_offset][0x2];
    if (pPhysics->standing_status == STANDING_NOT_IN_CONTROL)
        pPhysics->vertical_moving_direction = VDMOVING_DOWN;

    samus_check_collisions(pData, pPhysics);
    samus_update_draw_distance_and_standing_status(pData, pPhysics);
}

void samus_call_gfx_functions(void)
{
    /*struct samus_data* pData;
    u8 direction;

    pData = &samus_data;

    if (game_mode_sub1 == 0x2)
        samus_update_environmental_effect(pData);

    if ((pData->direction & DIRECTION_RIGHT) == 0x0)
        direction = 0x0;
    else
        direction = 0x1;
    
    samus_update_graphics_oam(pData, direction);
    samus_update_animation_timer_palette(pData);*/
}

void samus_call_check_low_health(void)
{
    samus_check_play_low_health_sound();
}

void samus_call_update_arm_cannon_position_offset(void)
{

}

void samus_bounce_bomb(u8 direction)
{
    /*u8 can_bounce;

    if (samus_physics.slowed_by_liquid)
        return;

    can_bounce = FALSE;
    if ((direction & 0x7F) > 0x9)
    {
        switch (samus_data.pose)
        {
            case SPOSE_MORPH_BALL_MIDAIR:
                if (samus_data.y_velocity <= 0x0 && (direction & 0x80) == 0x0)
                    can_bounce = TRUE;
            
            default:
                if (!can_bounce)
                    return;

            case SPOSE_ROLLING:
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
                samus_data.forced_movement = direction & 0x7F;
                samus_set_pose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
        }
    }*/
}

void samus_aim_cannon(struct samus_data* pData)
{
    /*struct weapon_info* pWeapon;
    enum input_flag direction;

    pWeapon = &samus_weapon_info;

    if (button_input & button_assignements.diagonal_aim)
    {
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
            case SPOSE_STANDING:
            case SPOSE_SHOOTING:
            case SPOSE_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_MIDAIR:
            case SPOSE_LANDING:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_UNCROUCHING_SUITLESS:
            case SPOSE_CROUCHING_SUITLESS:
                if (button_input & INPUT_DOWN)
                {
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                    pWeapon->diagonal_aim = DIAG_AIM_DOWN;
                }
                else if (DIAG_AIM_UP >= pWeapon->diagonal_aim || button_input & INPUT_UP)
                {
                    pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
                    pWeapon->diagonal_aim = DIAG_AIM_UP;
                }
                return;

            default:
                return;

            case SPOSE_ON_ZIPLINE:
                pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                pWeapon->diagonal_aim = DIAG_AIM_DOWN;
                return;            
        }
    }

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            if (button_input & INPUT_UP)
                pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
            else
            {
                direction = button_input & INPUT_DOWN;
                if (direction)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                else
                {
                    if (pData->arm_cannon_direction < ACD_NONE)
                        pData->arm_cannon_direction = direction;
                }
            }

            if (equipment.suit_type == SUIT_SUITLESS || pData->arm_cannon_direction != ACD_NONE || (pWeapon->weapon_highlighted == WH_NONE && pWeapon->charge_counter == 0x0))
                pWeapon->diagonal_aim = DIAG_AIM_NONE;
            else
                pData->arm_cannon_direction = ACD_FORWARD;

            break;
        
        case SPOSE_STANDING:
        case SPOSE_SHOOTING:
        case SPOSE_LANDING:
        case SPOSE_UNCROUCHING_SUITLESS:
            if (pData->speedbooster_timer == 0x0 && button_input & INPUT_UP)
                    pData->arm_cannon_direction = ACD_UP;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_SUITLESS:
            pData->arm_cannon_direction = ACD_FORWARD;
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_MIDAIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_AIMING_WHILE_HANGING:
            if (button_input & INPUT_UP)
            {
                if (pData->direction & button_input)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_UP;
                else
                    pData->arm_cannon_direction = ACD_UP;
            }
            else
            {
                direction = button_input & INPUT_DOWN;
                if (direction)
                {
                    if ((pData->direction & button_input) == 0x0)
                        pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                    else
                        pData->arm_cannon_direction = ACD_DOWN;
                }
                else
                {
                    if (pData->arm_cannon_direction & button_input)
                        pData->arm_cannon_direction = direction;
                    else
                    {
                        if ((u8)(pData->arm_cannon_direction - 0x3) > 0x2)
                            pData->arm_cannon_direction = pData->direction;
                    }
                }
            }
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;

        case SPOSE_ON_ZIPLINE:
            direction = button_input & INPUT_DOWN;
            if (direction)
            {
                if (pData->direction & button_input)
                    pData->arm_cannon_direction = ACD_DIAGONALLY_DOWN;
                else
                    pData->arm_cannon_direction = ACD_DOWN;
                pWeapon->diagonal_aim = DIAG_AIM_NONE;
            }
            else
            {
                if ((pData->direction & button_input) == 0x0 && pData->arm_cannon_direction != ACD_DOWN)
                    pWeapon->diagonal_aim = DIAG_AIM_NONE;
                else
                {
                    pData->arm_cannon_direction = direction;
                    pWeapon->diagonal_aim = DIAG_AIM_NONE;
                }
            }
        default:
            pWeapon->diagonal_aim = DIAG_AIM_NONE;
            break;
    }*/
}

u8 samus_fire_beam_missile(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment)
{
    /*u8 has_proj;
    enum projectile new_proj;

    has_proj = FALSE;
    if (pWeapon->cooldown == 0x0 && pWeapon->new_projectile == PROJECTILE_NONE && (buttons_changed & INPUT_B) != 0x0)
    {
        if ((pWeapon->weapon_highlighted & WH_MISSILE) != 0x0)
            pWeapon->new_projectile = PROJECTILE_MISSILE;
        else if ((pWeapon->weapon_highlighted & WH_SUPER_MISSILE) != 0x0)
            pWeapon->new_projectile = PROJECTILE_SUPER_MISSILE;
        else
            pWeapon->new_projectile = PROJECTILE_BEAM;
        has_proj++;
    }

    if (has_proj)
    {
        if (pData->arm_cannon_direction == ACD_NONE)
            pData->arm_cannon_direction = ACD_FORWARD;
        return has_proj;
    }

    if (pWeapon->weapon_highlighted == WH_NONE)
    {
        if ((button_input & INPUT_B) != 0x0)
        {
            if ((pEquipment->beam_bombs_activation & BBF_CHARGE_BEAM) == 0x0)
                pWeapon->charge_counter = 0x0;
            else
            {
                if (pWeapon->charge_counter < 0x4F)
                    pWeapon->charge_counter++;
                else
                    pWeapon->charge_counter = 0x40;
            }
        }
        else
        {
            if (pWeapon->charge_counter >= 0x40)
            {
                new_proj = PROJECTILE_CHARGED_BEAM;
                pWeapon->new_projectile = new_proj;
                has_proj = TRUE;
            }
            else
            {
                if (0x19 < pWeapon->charge_counter)
                {
                    new_proj = PROJECTILE_BEAM;
                    pWeapon->new_projectile = new_proj;
                    has_proj = TRUE;
                }
            }
            pWeapon->charge_counter = 0x0;
        }
    }
    else
        pWeapon->charge_counter = 0x0;

    if (has_proj)
    {
        if (pData->arm_cannon_direction == ACD_NONE)
            pData->arm_cannon_direction = ACD_FORWARD;
    }

    return has_proj;*/
}

u8 samus_fire_check_fully_charged_pistol(struct samus_data* pData, struct weapon_info* pWeapon)
{
    u8 new_proj;

    new_proj = 0x0;

    if (pWeapon->charge_counter < 0x7F)
        pWeapon->charge_counter++;
    else
        pWeapon->charge_counter = 0x70;

    if (pWeapon->cooldown == 0x0 && pWeapon->new_projectile == PROJECTILE_NONE && (buttons_changed & INPUT_B) != 0x0)
    {
        if (pWeapon->charge_counter >= 0x70)
        {
            pWeapon->new_projectile = PROJECTILE_CHARGED_BEAM;
            pWeapon->charge_counter = 0x0;
            new_proj++;
        }
        else
            pWeapon->new_projectile = PROJECTILE_BEAM;

        pWeapon->charge_counter = 0x0;
        new_proj++;
    }

    if (new_proj != PROJECTILE_NONE && pData->arm_cannon_direction == ACD_NONE)
        pData->arm_cannon_direction = ACD_FORWARD;

    return new_proj;
}

void samus_check_new_projectile(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment)
{
    struct samus_physics* pPhysics;

    pPhysics = &samus_physics;

    pPhysics->has_new_projectile = 0x0;

    if (pEquipment->suit_type == SUIT_SUITLESS)
    {
        switch (pData->pose)
        {
            case SPOSE_FACING_THE_FOREGROUND:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
                pWeapon->charge_counter = 0x0;
                break;

            default:
                pPhysics->has_new_projectile = samus_fire_check_fully_charged_pistol(pData, pWeapon);
                break;

            case SPOSE_GETTING_HURT:
            case SPOSE_GETTING_KNOCKED_BACK:
                pWeapon->charge_counter = 0x0;
                break;
        }
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
            case SPOSE_STANDING:
            case SPOSE_TURNING_AROUND:
            case SPOSE_SHOOTING:
            case SPOSE_CROUCHING:
            case SPOSE_TURNING_AROUND_AND_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_MIDAIR:
            case SPOSE_TURNING_AROUND_MIDAIR:
            case SPOSE_LANDING:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_HANGING_ON_LEDGE:
            case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
                pPhysics->has_new_projectile = samus_fire_beam_missile(pData, pWeapon, pEquipment);
                break;

            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                if ((buttons_changed & INPUT_B) != 0x0 && pWeapon->cooldown == 0x0 && (pEquipment->beam_bombs_activation & BBF_BOMBS) != 0x0)
                {
                    if ((pWeapon->weapon_highlighted & WH_POWER_BOMB) != 0x0)
                        pWeapon->new_projectile = PROJECTILE_POWER_BOMB;
                    else
                        pWeapon->new_projectile = PROJECTILE_BOMB;
                }
            case SPOSE_MORPHING:
                if (0x3F < pWeapon->charge_counter)
                    pWeapon->new_projectile = PROJECTILE_CHARGED_BEAM;
                pWeapon->charge_counter = 0x0;
                break;
            
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_IN_ESCAPE_SHIP:
            case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
                pWeapon->charge_counter = 0x0;
        }
    }
}

u8 samus_check_a_pressed(struct samus_data* pData)
{
    u8 return_value;
    
    return_value = 0x0;
    if ((buttons_changed & INPUT_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return_value = 0x1;
    }
    return return_value;
}

void samus_set_highlighted_weapon(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment)
{
    /*enum weapon_highlighted weapon_high;

    weapon_high = WH_NONE;
    if (pEquipment->current_super_missiles == 0x0)
        pWeapon->missiles_selected = weapon_high;
    else if (pEquipment->current_missiles == 0x0)
        pWeapon->missiles_selected = TRUE;
    else if ((buttons_changed & INPUT_SELECT) != 0x0)
    {
        pWeapon->missiles_selected ^= 0x1;
        play_sound1(0x85);
    }

    switch (pData->pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            if ((button_input & button_assignements.arm_missiles) == 0x0 || pEquipment->current_power_bombs != 0x0)
            {
                weapon_high = WH_POWER_BOMB;
                if (pWeapon->weapon_highlighted == WH_NONE)
                {
                    pWeapon->charge_counter = 0x0;
                    play_sound1(0x84);
                }
            }
            else
            {
                if (weapon_high != WH_NONE)
                {
                    if (pWeapon->weapon_highlighted == WH_NONE)
                    {
                        pWeapon->charge_counter = 0x0;
                        play_sound1(0x84);
                    }
                }
            }
            break;
        
        default:
            if ((button_input & button_assignements.arm_missiles) != 0x0)
            {
                if (pWeapon->missiles_selected == TRUE)
                {
                    if (pEquipment->current_missiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weapon_highlighted == WH_NONE)
                        {
                            pWeapon->charge_counter = 0x0;
                            play_sound1(0x84);
                        }
                    }
                }
                else
                {
                    weapon_high = WH_SUPER_MISSILE;
                    if (pEquipment->current_missiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weapon_highlighted == WH_NONE)
                        {
                            pWeapon->charge_counter = 0x0;
                            play_sound1(0x84);
                        }
                    }
                }
            }
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_USING_AN_ELEVATOR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
        case SPOSE_GRABBED_BY_CHOZO_STATUE:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
        case SPOSE_SHINESPARK_COLLISION:
        case SPOSE_DELAY_AFTER_SHINESPARKING:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_SAVING_LOADING_GAME:
            if (pWeapon->weapon_highlighted != WH_NONE)
            {
                if (pWeapon->weapon_highlighted == WH_NONE)
                {
                    pWeapon->charge_counter = 0x0;
                    play_sound1(0x84);
                }
            }

    }

    pWeapon->weapon_highlighted = weapon_high;*/
}

void samus_set_spinning_pose(struct samus_data* pData, struct equipment* pEquipment)
{
    u8 flag;

    switch (pData->pose)
    {
        case SPOSE_SPINNING:
            if (samus_physics.slowed_by_liquid != FALSE)
                break;

            if ((pEquipment->suit_misc_activation & SMF_SCREW_ATTACK) == 0x0)
            {
                if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP)
                    pData->pose = SPOSE_SPACE_JUMPING;
                break;
            }
            pData->pose = SPOSE_SCREW_ATTACKING;
            break;

        case SPOSE_SPACE_JUMPING:
            flag = pEquipment->suit_misc_activation & SMF_SCREW_ATTACK;
            if (flag != 0x0)
                pData->pose = SPOSE_SCREW_ATTACKING;
            else
            {
                if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP && !samus_physics.slowed_by_liquid)
                    break;
                pData->pose = SPOSE_SPINNING;
                pData->curr_anim_frame = flag;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (samus_physics.slowed_by_liquid != FALSE)
            {
                pData->pose = SPOSE_SPINNING;
                pData->curr_anim_frame = 0x0;
            }
            else
            {
                if ((pEquipment->suit_misc_activation & SMF_SCREW_ATTACK) == 0x0)
                {
                    if (pEquipment->suit_misc_activation & SMF_SPACE_JUMP)
                        pData->pose = SPOSE_SPACE_JUMPING;
                    else
                        pData->pose = SPOSE_SPINNING;
                    pData->curr_anim_frame = 0x0;
                }
            }
            screw_speed_animation.flag = FALSE;
    }
}

void samus_apply_x_acceleration(i16 acceleration, i16 velocity, struct samus_data* pData)
{

}

u8 samus_take_hazard_damage(struct samus_data* pData, struct equipment* pEquipment, struct hazard_damage* pHazard)
{
    u32 hazard;
    u16 y_position;
    u8 damaged;
    u8 knocked_back;
    u8 damage_type;
    u16 kb_timer;
    u32 palette_timer;

    switch (pData->pose)
    {
        case SPOSE_GRABBED_BY_CHOZO_STATUE:
        case SPOSE_DYING:
            return FALSE;
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_TURNING_TO_AIM_WHILE_HANGING:
        case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            y_position = pData->y_position - 0x10;
            break;

        default:
            y_position = pData->y_position;
    }

    pHazard->damage_timer++;
    damaged = FALSE;
    knocked_back = FALSE;
    damage_type = 0x0;
    hazard = clipdata_check_hazard_at_position(y_position, pData->x_position) & 0xFF;

    if (pEquipment->suit_misc_activation & SMF_GRAVITY_SUIT)
    {
        if (hazard == HAZARD_TYPE_ACID)
        {
            damaged = TRUE;
            if (pHazard->damage_timer > 0x4)
                damage_type = 0x1;
        }
    }
    else
    {
        if (pEquipment->suit_misc_activation & SMF_VARIA_SUIT)
        {
            if (hazard == HAZARD_TYPE_ACID)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x1)
                    damage_type = 0x1;
            }
            else if (hazard == HAZARD_TYPE_STRONG_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x4)
                    damage_type = 0x1;
            }
        }
        else
        {
            if (hazard == HAZARD_TYPE_ACID)
            {
                damaged = TRUE;
                damage_type = 0x1;
            }
            else if (hazard == HAZARD_TYPE_SNOWFLAKES_KNOCKBACK)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x3)
                    damage_type = 0xF;
                kb_timer = pHazard->knockback_timer = pHazard->knockback_timer + 0x1;
                if (kb_timer >= 0x57)
                {
                    pHazard->knockback_timer = 0x0;
                    knocked_back = TRUE;
                }
            }
            else if (hazard == HAZARD_TYPE_STRONG_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x2)
                    damage_type = 0x1;
            }
            else if (hazard == HAZARD_TYPE_WEAK_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x7)
                    damage_type = 0x1;
            }
            else if (hazard == HAZARD_TYPE_HEAT || hazard == HAZARD_TYPE_COLD)
            {
                damaged = TRUE;
                if (pHazard->damage_timer > 0x5)
                    damage_type = 0xF;
            }
        }
    }

    if (!damaged)
    {
        pHazard->damage_timer = 0x0;
        pHazard->knockback_timer = 0x0;
        pHazard->palette_timer = 0x0;
    }
    else
    {
        pHazard->palette_timer++;
        switch (pHazard->palette_timer - 0x1)
        {
            case 0x1:
            case 0x21:
                if (hazard == HAZARD_TYPE_ACID || hazard == HAZARD_TYPE_STRONG_LAVA || hazard == HAZARD_TYPE_WEAK_LAVA)
                    play_sound1(0x7E);
                break;
            
            case 0x40:
                pHazard->palette_timer = 0x0;
        }

        if (damage_type != 0x0)
        {
            pEquipment->current_energy--;
            pHazard->damage_timer = 0x0;
        }
        if (damage_type == 0xF)
            play_sound1(0x7F);
    }

    if (pEquipment->current_energy == 0x0 || knocked_back)
        return TRUE;
    return FALSE;
}

void samus_check_shinesparking(struct samus_data* pData)
{
    /*enum samus_pose pose;

    pose = pData->pose;

    switch (pose)
    {
        case SPOSE_SHINESPARKING:
            pData->speedboosting_shinesparking = TRUE;
            break;
        case SPOSE_BALLSPARKING:
            pData->speedboosting_shinesparking = TRUE;
            break;
        default:
            if ((u16)(pData->x_velocity + 0x9F) >= 0x13F)
            {
                if (pData->speedboosting_shinesparking != FALSE) return;
                if (pose != SPOSE_SKIDDING)
                {
                    pData->speedboosting_shinesparking = TRUE;
                    play_sound1(0x8B);
                }
                break;
            }
            else
            {
                if (pData->speedboosting_shinesparking == FALSE)
                    play_sound2(0x8B);
                return;
            }

        case SPOSE_DYING:
            pData->speedboosting_shinesparking = FALSE;
    }

    if (pData->speedboosting_shinesparking == FALSE)
        play_sound2(0x8B);*/
}

enum samus_pose samus_inactivity(struct samus_data* pData)
{
    return SPOSE_NONE;
}

u8 unk_847C(struct samus_data* pData, u8 unk)
{

}

enum samus_pose samus_running(struct samus_data* pData)
{
    /*enum samus_pose new_pose;
    i32 x_velocity;

    if ((buttons_changed & INPUT_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    x_velocity = samus_physics.x_velocity_cap;
    if ((equipment.suit_misc_activation & SMF_SPEED_BOOSTER) != 0x0 && samus_physics.slowed_by_liquid == FALSE)
    {
        if (pData->speedbooster_timer >= 0x8C)
            x_velocity = 0xA0;
        else
        {
            if (0x77 < pData->speedbooster_timer)
                x_velocity = 0x8C;
        }

        if ((u16)((u16)pData->x_velocity + 0x5F) >= 0xBF)
        {
            if (0x9F >= (u8)pData->speedbooster_timer)
                pData->speedbooster_timer++;
        }
    }
    else
        pData->speedbooster_timer = 0x0;


    if ((button_input & pData->direction) != 0x0)
    {
        samus_apply_x_acceleration(samus_physics.x_acceleration, x_velocity, pData);
        samus_aim_cannon(pData);
        return SPOSE_NONE;
    }
    else
    {
        if (pData->speedboosting_shinesparking != FALSE)
            return SPOSE_SKIDDING;
        else if (samus_physics.has_new_projectile != 0x0)
            return SPOSE_SHOOTING;
        else if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & button_input) == 0x0)
            return SPOSE_STANDING;
        else
            return SPOSE_TURNING_AROUND;
    }*/
}

enum samus_pose samus_running_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_standing(struct samus_data* pData)
{

}

enum samus_pose samus_standing_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;

    return SPOSE_NONE;
}

enum samus_pose samus_turning_around(struct samus_data* pData)
{
    enum samus_pose new_pose;

    if ((button_input & (INPUT_RIGHT | INPUT_LEFT)) == 0x0 && (buttons_changed & INPUT_A) != 0x0 && pData->shinespark_timer != 0x0 && unk_57EC(pData, (i16)((u16)array_23a558[0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        if (samus_check_a_pressed(pData) << 0x18 != FALSE)
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        else
        {
            if ((buttons_changed & INPUT_DOWN) != 0x0 && (samus_weapon_info.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_DOWN))
            {
                pData->pose = SPOSE_TURNING_AROUND_AND_CROUCHING;
                if (equipment.suit_type != SUIT_SUITLESS)
                    play_sound1(0x79);
            }
            if (samus_physics.has_new_projectile != 0x0)
            {
                if (pData->pose == SPOSE_TURNING_AROUND_AND_CROUCHING)
                    return SPOSE_SHOOTING_AND_CROUCHING;
                else
                    return SPOSE_SHOOTING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

enum samus_pose samus_turning_around_gfx(struct samus_data* pData)
{
    u8 unk;
    enum input_flag* input;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        input = &button_input;
        if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & *input) != 0x0)
            return SPOSE_RUNNING;
        else if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

enum samus_pose samus_shooting_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_STANDING;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_crouching(struct samus_data* pData)
{
    /*u8 unk;
    u16 x_position;
    struct weapon_info* pWeapon;
    enum input_flag* input;
    u32 timer;

    if ((button_input & (INPUT_RIGHT | INPUT_LEFT)) == 0x0 && (buttons_changed & INPUT_A) != 0x0 && pData->shinespark_timer != 0x0 && unk_57EC(pData, (i16)((u16)array_23a554[0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }

    unk = unk_57EC(pData, array_23a554[0x2]);
    if (unk == 0x1)
        x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0];
    else if (unk == 0x8)
        x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0] + 0x3F;

    if (samus_check_a_pressed(pData) << 0x18 != FALSE && (unk & 0x6) == 0x0)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->x_position = x_position;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if ((buttons_changed & INPUT_UP) == 0x0 || (unk & 0x6) != 0x0 || samus_weapon_info.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_UP)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->x_position = x_position;
        pData->last_wall_touched_midair = 0x6;
        
        if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
    {
        if ((buttons_changed & INPUT_DOWN) != 0x0 && (equipment.suit_misc_activation & SMF_MORPH_BALL) != 0x0 && (samus_weapon_info.diagonal_aim == DIAG_AIM_NONE || pData->arm_cannon_direction == ACD_DIAGONALLY_DOWN))
        {
            play_sound1(0x77);
            return SPOSE_MORPHING;
        }

        samus_aim_cannon(pData);
        if (pData->arm_cannon_direction == ACD_UP)
            pData->arm_cannon_direction = ACD_FORWARD;

        if (samus_physics.has_new_projectile != PROJECTILE_NONE)
            return SPOSE_SHOOTING_AND_CROUCHING;
        
        input = &button_input;
        if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & *input) != 0x0)
            return SPOSE_TURNING_AROUND_AND_CROUCHING;

        if ((button_input & pData->direction) != 0x0)
        {
            if ((unk & 0x6) == 0x0)
            {
                timer = pData->speedbooster_timer;
                pData->speedbooster_timer = timer + 1;
                if (0x5 < (u8)timer)
                {
                    if (unk == 0x1 || unk == 0x8)
                        pData->x_position = x_position;

                    if (equipment.suit_type == SUIT_SUITLESS)
                        return SPOSE_UNCROUCHING_SUITLESS;
                    else
                        return SPOSE_STANDING; 
                }
            }
        }
        else
            pData->speedbooster_timer = 0x0;

        return SPOSE_NONE;
    }*/
}

enum samus_pose samus_turning_around_and_crouching(struct samus_data* pData)
{
    u8 unk;
    u16 x_position;

    if ((button_input & (INPUT_RIGHT | INPUT_LEFT)) == 0x0 && (buttons_changed & INPUT_A) != 0x0 && pData->shinespark_timer != 0x0 && unk_57EC(pData, (i16)((u16)array_23a554[0x2] - 0x20)) << 0x18 == 0x0)
    {
        pData->y_position -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        unk = unk_57EC(pData, array_23a554[0x2]);
        if (unk == 0x1)
            x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0x0];
        else if (unk == 0x8)
            x_position = (pData->x_position & 0xFFC0) - (u16)array_23a554[0x0] + 0x3F;

        if (samus_check_a_pressed(pData) << 0x18 != FALSE && (unk & 0x6) == 0x0)
        {
            if (unk == 0x1 || unk == 0x8)
                pData->x_position = x_position;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            if ((buttons_changed & INPUT_UP) != 0x0 && (unk & 0x6) == 0x0 && (samus_weapon_info.diagonal_aim == 0x0 || pData->arm_cannon_direction == ACD_DIAGONALLY_UP))
            {
                if (unk == 0x1 || unk == 0x8)
                    pData->x_position = x_position;
                pData->pose = SPOSE_TURNING_AROUND;

            }

            if (samus_physics.has_new_projectile != 0x0)
            {
                if (pData->pose == SPOSE_TURNING_AROUND)
                    return SPOSE_SHOOTING;
                else
                    return SPOSE_SHOOTING_AND_CROUCHING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

enum samus_pose samus_turning_around_and_crouching_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_CROUCHING_SUITLESS;
        else
            return SPOSE_CROUCHING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_shooting_and_crouching_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_CROUCHING;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_skidding(struct samus_data* pData)
{
    i32 velocity;

    if ((buttons_changed & INPUT_A) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    
    if ((button_input & pData->direction) != 0x0)
        return SPOSE_RUNNING;
    else
    {
        if ((button_input & (INPUT_RIGHT | INPUT_LEFT | INPUT_UP | INPUT_DOWN)) == INPUT_DOWN)
        {
            pData->shinespark_timer = 0xB4;
            screw_speed_animation.flag = 0x8;
            if (equipment.suit_type == SUIT_SUITLESS)
                return SPOSE_CROUCHING_SUITLESS;
            else
                return SPOSE_CROUCHING;
        }

        if ((pData->direction & DIRECTION_RIGHT) != 0x0)
        {
            velocity = (u16)pData->x_velocity - 0xA;
            pData->x_velocity = velocity;
            if (0x0 >= (velocity << 0x10))
                return SPOSE_STANDING;
        }
        else
        {
            velocity = (u16)pData->x_velocity + 0xA;
            pData->x_velocity = velocity;
            if ((velocity << 0x10) >= 0x0)
                return SPOSE_STANDING;
        }
        
        return SPOSE_NONE;
    }
}

enum samus_pose samus_midair(struct samus_data* pData)
{

}

enum samus_pose samus_midair_gfx(struct samus_data* pData)
{
    u8 unk;

    if (pData->y_velocity >= 0x0)
    {
        if (pData->curr_anim_frame == 0x2)
            pData->anim_duration_counter = 0x0;
    }
    else
    {
        if (pData->curr_anim_frame < 0x2)
            pData->curr_anim_frame = 0x2;
    }

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x4;

    return SPOSE_NONE;
}

enum samus_pose samus_turning_around_midair(struct samus_data* pData)
{
    if ((buttons_changed & INPUT_A) != 0x0)
    {
        if (pData->shinespark_timer != 0x0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if ((button_input & (INPUT_UP | INPUT_DOWN)) == 0x0)
        {
            pData->pose = SPOSE_SPINNING;
            pData->direction ^= (DIRECTION_RIGHT | DIRECTION_LEFT);
            pData->curr_anim_frame = 0x0;
            pData->anim_duration_counter = 0x0;
            pData->turning = FALSE;
            return SPOSE_NONE;
        }
    }

    if (samus_physics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if ((button_input & INPUT_A) == 0x0 && 0x0 < pData->y_velocity)
            pData->y_velocity = 0x0;
        return SPOSE_NONE;
    }
}

enum samus_pose samus_turning_around_midair_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        pData->forced_movement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_starting_spin_jump_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        pData->pose = SPOSE_SPINNING;
        pData->curr_anim_frame = 0x0;
    }

    return SPOSE_NONE;
}

enum samus_pose samus_spinning(struct samus_data* pData)
{
    /*i32 acceleration;
    enum samus_direction direction;
    enum input_flag* input;

    if (samus_physics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if ((button_input & (INPUT_RIGHT | INPUT_LEFT)) == 0x0 && (button_input & (INPUT_UP | INPUT_DOWN)) != 0x0)
        {
            pData->forced_movement = 0x2;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            samus_aim_cannon(pData);
            acceleration = samus_physics.midair_x_acceleration;
            if ((equipment.suit_misc_activation & SMF_SPACE_JUMP) != 0x0 && samus_physics.slowed_by_liquid == FALSE)
            {
                if ((buttons_changed & INPUT_A) != 0x0 && pData->y_velocity <= -0x40)
                {
                    if ((equipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
                        pData->y_velocity = 0xE8;
                    else
                        pData->y_velocity = 0xC0;
                    
                    return SPOSE_NONE;
                }
            }
            else
            {
                if (pData->walljump_timer != 0x0)
                {
                    pData->walljump_timer--;
                    if ((pData->direction & pData->last_wall_touched_midair) != 0x0)
                    {
                        if ((buttons_changed & INPUT_A) != 0x0)
                        {
                            
                            if ((pData->last_wall_touched_midair & DIRECTION_RIGHT) != 0x0)
                                acceleration = -0x28;
                            else
                                acceleration = 0x28;
                            
                            if ((unk_57DF8(pData->y_position, (u16)(pData->x_position + acceleration)) & 0x1000000) != 0x0)
                            {
                                pData->direction = pData->last_wall_touched_midair;
                                return SPOSE_STARTING_WALL_JUMP;
                            }
                        }
                        acceleration = 0x1;
                    }
                }
            }

            input = &button_input;
            direction = pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT);
            if ((direction & *input) != 0x0)
            {
                pData->direction = direction;
                pData->x_velocity = 0x0;
            }
            else
                samus_apply_x_acceleration(acceleration, samus_physics.midair_x_velocity_cap, pData);

            if ((button_input & INPUT_A) == 0x0 && 0x0 < pData->y_velocity)
                pData->y_velocity = 0x0;

            return SPOSE_NONE;
        }
    }*/
}

enum samus_pose samus_spinning_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, samus_physics.slowed_by_liquid);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;

    if (*(u16*)&pData->anim_duration_counter == 0x1)
    {
        if (samus_physics.slowed_by_liquid != FALSE)
            play_sound1(0x92);
        else if (equipment.suit_type != SUIT_SUITLESS)
            play_sound1(0x6A);
        else
            play_sound1(0x98);
    }

    return SPOSE_NONE;
}

enum samus_pose samus_starting_wall_jump(struct samus_data* pData)
{
    enum input_flag input;

    if (samus_physics.has_new_projectile != 0x0)
    {
        pData->forced_movement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else 
    {
        input = button_input & (INPUT_RIGHT | INPUT_LEFT);
        if (input == 0x0 && (button_input & (INPUT_UP | INPUT_DOWN)) != 0x0)
        {
            pData->forced_movement = input;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
            return SPOSE_NONE;
    }
}

enum samus_pose samus_starting_wall_jump_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_space_jumping_gfx(struct samus_data* pData)
{
    u8 unk;

    if (*(u16*)&pData->anim_duration_counter == 0x1)
    {
        if (samus_physics.slowed_by_liquid != FALSE)
            play_sound1(0x6B);
        else
            play_sound1(0x6B);
    }

    unk = unk_847C(pData, samus_physics.slowed_by_liquid);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;

    return SPOSE_NONE;
}

enum samus_pose samus_flag_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_morphing(struct samus_data* pData)
{
    if ((buttons_changed & INPUT_UP) != 0x0)
        pData->pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

enum samus_pose samus_morphing_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_MORPH_BALL;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_morphball(struct samus_data* pData)
{
    /*u8 forced_movement;

    forced_movement = pData->forced_movement;
    if (0x15 < forced_movement)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (forced_movement >= 0x14)
        pData->forced_movement = forced_movement + 0x1;
    else
    {
        if ((buttons_changed & INPUT_A) != 0x0 && (equipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0 & pData->shinespark_timer != 0x0 && unk_57EC(pData, (i16)((u16)array_23a554[0x5] - 0x40)) << 0x18 == 0x0)
        {
            pData->y_position -= 0x20;
            return SPOSE_DELAY_BEFORE_BALLSPARKING;
        }

        if (samus_check_a_pressed(pData) << 0x18 != FALSE)
        {
            if (pData->forced_movement != 0x1)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            if ((equipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            pData->forced_movement = 0x0;
        }

        if ((button_input & (INPUT_RIGHT | INPUT_LEFT)) != 0x0)
        {
            pData->direction = button_input & (INPUT_RIGHT | INPUT_LEFT);
            return SPOSE_ROLLING;
        }

        if ((buttons_changed & INPUT_UP) != 0x0)
        {
            forced_movement = unk_57EC(pData, array_23a554[0x2]);
            if (forced_movement == 0x1)
            {
                pData->x_position = (u16)(pData->x_position + array_23a554[0x0] & 0xFFC0) - array_23a554[0x0] + 0x40;
                previous_x_position = pData->x_position;

                if (samus_physics.slowed_by_liquid != FALSE)
                    play_sound1(0x78);
                else
                    play_sound1(0x78);

                return SPOSE_UNMORPHING;
            }

            if (forced_movement == 0x8)
            {
                pData->x_position = (u16)(pData->x_position + array_23a554[0x0] & 0xFFC0) - array_23a554[0x0] + 0x40;
                previous_x_position = pData->x_position;
                forced_movement = 0x0;
            }

            if (forced_movement == 0x0)
            {
                if (samus_physics.slowed_by_liquid != FALSE)
                    play_sound1(0x78);
                else
                    play_sound1(0x78);

                return SPOSE_UNMORPHING;
            }
        }

        if (pData->speedbooster_timer != 0x0)
        {
            pData->speedbooster_timer--;
            if ((button_input & (INPUT_RIGHT | INPUT_LEFT | INPUT_UP | INPUT_DOWN)) == INPUT_DOWN)
            {
                pData->shinespark_timer = 0xB4;
                pData->speedbooster_timer = 0x0;
                screw_speed_animation.flag = 0x8;
            }
        }
    }

    return SPOSE_NONE;*/
}

enum samus_pose samus_rolling(struct samus_data* pData)
{
    /*i32 velocity;

    if ((buttons_changed & INPUT_A) != 0x0 && (equipment.suit_misc_activation & SMF_HIGH_JUMP) != 0x0)
    {
        pData->forced_movement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (unk_57EC(pData, array_23a554[0x2]) << 0x18 == 0x0 && (buttons_changed & INPUT_UP) != 0x0)
        {
            if (samus_physics.slowed_by_liquid != FALSE)
                play_sound1(0x78);
            else
                play_sound1(0x78);

            return SPOSE_UNMORPHING;
        }
        else
        {
            if ((button_input & pData->direction) != 0x0)
            {
                velocity = samus_physics.x_velocity_cap;
                if (pData->speedboosting_shinesparking != FALSE)
                {
                    velocity = 0xA0;
                    pData->shinespark_timer = 0x6;
                }
                samus_apply_x_acceleration(samus_physics.x_acceleration, velocity, pData);
                return SPOSE_NONE;
            }
            else
            {
                if ((((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & button_input) << 0x10) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_MORPH_BALL;
            }
        }
    }*/
}

enum samus_pose samus_rolling_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;
    else if (unk == 0x1 && (pData->curr_anim_frame == 0x1 || pData->curr_anim_frame == 0x5))
        samus_check_set_environmental_effect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    return SPOSE_NONE;
}

enum samus_pose samus_unmorphing(struct samus_data* pData)
{
    u8 unk;

    unk = unk_57EC(pData, array_23a554[0x2]);
    if (unk == 0x0)
    {
        if ((buttons_changed & INPUT_A) != 0x0)
        {
            pData->forced_movement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        if ((buttons_changed & INPUT_DOWN) == 0x0)
            return SPOSE_NONE;
    }
    pData->pose = SPOSE_MORPHING;
    return SPOSE_NONE;
}

enum samus_pose samus_unmorphing_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        pData->unmroph_palette_timer = 0xF;
        return SPOSE_CROUCHING;
    }
    return SPOSE_NONE;
}

enum samus_pose samus_morphball_midair(struct samus_data* pData)
{
    /*enum input_flag direction;

    if ((buttons_changed & INPUT_UP) != 0x0 && unk_57EC(pData, array_23a554[0x2]) << 0x18 == 0x0)
    {
        if (samus_physics.slowed_by_liquid == TRUE)
            play_sound1(0x78);
        else
            play_sound1(0x78);
        
        pData->unmroph_palette_timer = 0xF;
        return SPOSE_MIDAIR;
    }

    if (pData->forced_movement == 0x0)
    {
        if ((button_input & INPUT_A) == 0x0 && 0x0 < pData->y_velocity)
            pData->y_velocity = 0x0;
    }
    else
    {
        if (pData->y_velocity < 0x7)
            pData->forced_movement = 0x0;
    }

    if (pData->y_velocity >= 0x0 && (pData->x_velocity != 0x0 || (button_input & pData->direction) != 0x0))
        samus_apply_x_acceleration(samus_physics.midair_x_acceleration, samus_physics.midair_morphed_x_velocity_cap, pData);
    else
    {
        direction = pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT);
        if ((direction & button_input) != 0x0)
            pData->direction = direction;
        pData->x_velocity = 0x0;
    }

    return SPOSE_NONE;*/
}

enum samus_pose samus_hanging_on_ledge(struct samus_data* pData)
{

}

enum samus_pose samus_hanging_on_ledge_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, samus_physics.slowed_by_liquid);
    if (unk == 0x2)
        pData->curr_anim_frame= 0x0;

    return SPOSE_NONE;
}

enum samus_pose samus_turning_to_aim_while_hanging(struct samus_data* pData)
{

}

enum samus_pose samus_turning_to_aim_while_hanging_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, samus_physics.slowed_by_liquid);
    if (unk == 0x2)
        return SPOSE_AIMING_WHILE_HANGING;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_hiding_arm_cannon_while_hanging_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, samus_physics.slowed_by_liquid);
    if (unk == 0x2)
    {
        pData->direction ^= (DIRECTION_RIGHT | DIRECTION_LEFT);
        return SPOSE_HANGING_ON_LEDGE;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_aiming_while_hanging(struct samus_data* pData)
{

}

enum samus_pose samus_pulling_self_up(struct samus_data* pData)
{
    u16 offset;

    offset = samus_pulling_self_up_velocity_23a5b4[pData->curr_anim_frame];
    if (pData->speedbooster_timer != 0x0)
        offset >>= 0x1;

    pData->y_position -= offset;
    return SPOSE_NONE;
}

enum samus_pose samus_pulling_self_up_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, pData->speedbooster_timer);
    if (unk == 0x2)
    {
        pData->y_position = (pData->y_position & 0xFFC0) - 0x1;
        return SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_pulling_self_forward(struct samus_data* pData)
{
    if ((pData->direction & DIRECTION_RIGHT) != 0x0)
        pData->x_position += 0x4;
    else
        pData->x_position -= 0x4;

    return SPOSE_NONE;
}

enum samus_pose samus_pulling_self_forward_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);

    if (unk == 0x2)
    {
        if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_pulling_self_into_morphball_tunnel_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, pData->speedbooster_timer);
    if (unk == 0x2)
    {
        if ((pData->direction & DIRECTION_RIGHT) != 0x0)
            pData->x_position += 0x6;
        else
            pData->x_position -= 0x6;

        pData->y_position = (pData->y_position & 0xFFC0) - 0x1;
        play_sound(0x77);
        return SPOSE_MORPH_BALL;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_using_an_elevator(struct samus_data* pData)
{

}

enum samus_pose samus_using_an_elevator_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_facing_the_foreground(struct samus_data* pData)
{
    enum input_flag direction;

    direction = button_input & (INPUT_RIGHT | INPUT_LEFT);

    if (direction != 0x0 && pData->last_wall_touched_midair == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_turning_from_facing_foreground_gfx(struct samus_data* pData)
{
    if (pData->anim_duration_counter >= 0x2)
    {
        if (pData->elevator_direction != 0x0)
            return SPOSE_USING_AN_ELEVATOR;
        else if (pData->speedbooster_timer != 0x0)
            return SPOSE_SAVING_LOADING_GAME;
        else if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_delay_before_shinesparking_gfx(struct samus_data* pData)
{
    u8 unk;
    enum input_flag* input;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        input = &button_input;
        if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & *input) != 0x0)
            pData->turning = TRUE;
        return SPOSE_SHINESPARKING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_shinesparking(struct samus_data* pData)
{

}

enum samus_pose samus_shinesparking_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_shinespark_collision_gfx(struct samus_data* pData)
{
    if (pData->anim_duration_counter >= 0x11)
        return SPOSE_DELAY_AFTER_SHINESPARKING;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_delay_after_shinesparking_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_delay_before_ballsparking(struct samus_data* pData)
{

}

enum samus_pose samus_delay_before_ballsparking_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_ballsparking_gfx(struct samus_data* pData)
{

}

enum samus_pose samus_ballspark_collision_gfx(struct samus_data* pData)
{
    if (pData->anim_duration_counter >= 0x11)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_on_zipline(struct samus_data* pData)
{
    enum input_flag* input;

    if ((buttons_changed & INPUT_A) != 0x0)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else if (samus_physics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_ON_ZIPLINE;
    else if (pData->pose != SPOSE_ON_ZIPLINE)
        return SPOSE_NONE;
    else
    {
        input = &button_input;
        if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & *input) == 0x0)
        {
            samus_aim_cannon(pData);
            return SPOSE_NONE;
        }
        return SPOSE_TURNING_ON_ZIPLINE;
    }
}

enum samus_pose samus_shooting_on_zipline_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_ON_ZIPLINE;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_morphball_on_zipline(struct samus_data* pData)
{
    enum input_flag direction;

    if ((buttons_changed & INPUT_A) != 0x0)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
    {
        direction = button_input & (INPUT_RIGHT | INPUT_LEFT);
        if (direction != 0x0)
            pData->direction = direction;
        return SPOSE_NONE;
    }
}

enum samus_pose samus_saving_loading_game(struct samus_data* pData)
{
    if (pData->speedbooster_timer != 0x0)
    {
        pData->curr_anim_frame = 0x0;
        pData->anim_duration_counter = 0x0;
    }

    return SPOSE_NONE;
}

enum samus_pose samus_turning_around_to_download_map_data_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_DOWNLOADING_MAP_DATA;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_getting_hurt(struct samus_data* pData)
{

}

enum samus_pose samus_getting_hurt_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame--;

    return SPOSE_NONE;
}

enum samus_pose samus_getting_knocked_back(struct samus_data* pData)
{
    if (pData->speedbooster_timer >= 0xD)
    {
        if (pData->y_velocity < -0x20)
        {
            if (pData->pose == SPOSE_GETTING_KNOCKED_BACK)
                return SPOSE_MIDAIR;
        }
        return SPOSE_MORPH_BALL_MIDAIR;
    }
    else
        pData->speedbooster_timer++;
    return SPOSE_NONE;
}

enum samus_pose samus_dying(struct samus_data* pData)
{

}

enum samus_pose samus_crouching_to_crawl_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        if ((pData->direction & DIRECTION_RIGHT) != 0x0)
            pData->x_position += 0x4;
        else
            pData->x_position -= 0x4;
        
        return SPOSE_STARTING_TO_CRAWL;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_crawling_stopped(struct samus_data* pData)
{
    pData->x_velocity = 0x0;
    if (unk_57EC(pData, array_23a554[0x2]) << 0x18 == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else if (samus_physics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else if ((button_input & pData->direction) != 0x0)
        return SPOSE_CRAWLING;
    else if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & button_input) == 0x0)
        return SPOSE_NONE;
    else
        return SPOSE_TURNING_AROUND_WHILE_CRAWLING;
}

enum samus_pose samus_starting_to_crawl_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_CRAWLING_STOPPED;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_crawling(struct samus_data* pData)
{
    if (unk_5794(pData, array_23a554[0x2]) << 0x18 == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else
    {
        if (samus_physics.has_new_projectile != 0x0)
            return SPOSE_SHOOTING_WHILE_CRAWLING;
        else
        {
            if ((button_input & pData->direction) != 0x0)
            {
                samus_apply_x_acceleration(samus_physics.x_acceleration, 0x20, pData);
                return SPOSE_NONE;
            }
            else
            {
                if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & button_input) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_CRAWLING_STOPPED;
            }
        }
    }
}

enum samus_pose samus_dying_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        pData->curr_anim_frame = 0x0;
    else if (unk == 0x1 && (pData->curr_anim_frame == 0x1 || pData->curr_anim_frame == 0x4))
        samus_check_set_environmental_effect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    if (*(u16*)&pData->anim_duration_counter == 0x1)
        play_sound1(0x9E);

    return SPOSE_NONE;
}

enum samus_pose samus_turning_around_while_crawling(struct samus_data* pData)
{
    if (samus_physics.has_new_projectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_crawling_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_STARTING_TO_CRAWL;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_grabbing_a_ledge_suitless_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_HANGING_ON_LEDGE;
    else
        return SPOSE_NONE;
}

enum samus_pose samus_facing_the_background(struct samus_data* pData)
{
    enum input_flag direction;

    direction = (button_input & (INPUT_RIGHT | INPUT_LEFT));
    if (direction != 0x0 && pData->last_wall_touched_midair == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_turning_from_facing_the_background_gfx(struct samus_data* pData)
{
    u8 unk;
    enum input_flag* input;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
    {
        input = &button_input;
        if (((pData->direction ^ (DIRECTION_RIGHT | DIRECTION_LEFT)) & *input) != 0x0)
            return SPOSE_RUNNING;
        else if (pData->last_wall_touched_midair != 0x0)
            return SPOSE_FACING_THE_BACKGROUND_SUITLESS;
        else if (equipment.suit_type == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

enum samus_pose samus_turning_to_enter_escape_ship_gfx(struct samus_data* pData)
{
    u8 unk;

    unk = unk_847C(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_IN_ESCAPE_SHIP;
    else
        return SP_NONE;
}

enum samus_pose samus_execute_pose_subroutine(struct samus_data* pData)
{
    enum samus_pose pose;
    u8 timer;
    struct weapon_info* pWeapon;
    struct equipment* pEquipment;
    struct hazard_damage* pHazard;

    pWeapon = &samus_weapon_info;
    pEquipment = &equipment;
    pHazard = &samus_hazard_damage;

    if (samus_take_hazard_damage(pData, pEquipment, pHazard) << 0x18 != FALSE)
        return SPOSE_HURT_REQUEST;
    else
    {
        if (pWeapon->cooldown != 0x0)
            pWeapon->cooldown--;

        if (pData->shinespark_timer != 0x0 && pData->pose != SPOSE_DELAY_BEFORE_SHINESPARKING && pData->pose != SPOSE_DELAY_BEFORE_BALLSPARKING)
        {
            timer = pData->shinespark_timer;
            if ((timer & 0xF) == 0x4)
                play_sound(0x8D);
            pData->shinespark_timer--;
        }
        if (pEquipment->suit_type != SUIT_SUITLESS)
            samus_set_highlighted_weapon(pData, pWeapon, pEquipment);

        samus_set_spinning_pose(pData, pEquipment);
        samus_spawn_new_projectile(pData, pWeapon, pEquipment);
        pose = bx_r1(pData, samus_pose_functions_pointers[pData->pose]);
        if (pose == SPOSE_NONE)
            pose = bx_r1(pData, samus_pose_gfx_functions_pointers[pData->pose]);
        samus_check_shinesparking(pData);
    }

    return pose;
}

void samus_update_velocity_position(struct samus_data* pData)
{

}

void samus_update_graphics_oam(struct samus_data* pData, u8 direction)
{

}

void samus_update_animation_timer_palette(struct samus_data* pData)
{

}

void samus_check_play_low_health_sound(void)
{
    struct samus_data* pData;
    struct equipment* pEquipment;

    pData = &samus_data;
    pEquipment = &equipment;

    if (pEquipment->low_health != FALSE && pData->pose != SPOSE_DYING && prevent_movement_timer == 0x0 && (eight_bit_frame_counter & 0xF) == 0x0)
        play_sound1(0x82);
}

void samus_update_draw_distance_and_standing_status(struct samus_data* pData, struct samus_physics* pPhysics)
{

}

void samus_update_arm_cannon_position_offset(u8 direction)
{

}

void samus_init(void)
{

}

void samus_draw(void)
{

}