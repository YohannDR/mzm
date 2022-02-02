#include "sprite_util.h"
#include "globals.h"
#include "sprite_debris.h"
#include "particle.h"

void sprite_util_current_sprite_fall(void)
{

}

void sprite_util_choose_random_x_flip(void)
{
    if ((sprite_rng & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        current_sprite.status |= SPRITE_STATUS_XFLIP;
}

void sprite_util_choose_random_x_direction(void)
{
    if ((sprite_rng & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void sprite_util_choose_random_x_direction_room_slot(u8 room_slot)
{
    if ((current_sprite.room_slot & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void sprite_util_make_sprite_face_samus_x_flip(void)
{

}

void sprite_util_make_sprite_face_samus_direction(void)
{

}

void sprite_util_make_sprite_face_away_samus_x_flip(void)
{

}

void sprite_util_make_sprite_face_away_samus_direction(void)
{

}

void unk_f978(u8 unk)
{

}

void unk_f9e7(u8 unk)
{

}

u8 sprite_util_make_sprite_face_samus_rotation(u8 oam_rotation, u16 samus_y, u16 samus_x, u16 sprite_y, u16 sprite_x)
{

}

u8 sprite_util_check_end_current_sprite_anim(void)
{

}

u8 sprite_util_check_near_end_current_sprite_anim(void)
{

}

u8 sprite_util_check_end_sprite_anim(u8 ram_slot)
{

}

u8 sprite_util_check_near_end_sprite_anim(u8 ram_slot)
{

}

u8 sprite_util_check_end_sub_sprite1_anim(void)
{

}

u8 sprite_util_check_near_end_sub_sprite1_anim(void)
{

}

u8 sprite_util_check_end_sub_sprite2_anim(void)
{

}

u8 sprite_util_check_end_sub_sprite_anim(struct sub_sprite_data* ptr)
{

}

u8 sprite_util_check_near_end_sub_sprite_anim(struct sub_sprite_data* ptr)
{

}

u8 sprite_util_check_samus_near_sprite_left_right(u16 y_range, u8 x_range)
{

}

u8 sprite_util_check_samus_near_sprite_above_below(u16 y_range, u8 x_range)
{

}

u8 sprite_util_check_samus_near_sprite_front_behind(u16 y_range, u8 x_range_front, u8 x_range_behind)
{

}

u8 sprite_util_samus_standing_on_sprite(struct sprite_data* ptr)
{

}

void sprite_util_update_freeze_timer(void)
{
    /*u8 freeze_timer;

    if ((eight_bit_frame_counter & 0x1) != 0x0)
        current_sprite.freeze_timer--;

    freeze_timer = current_sprite.freeze_timer;

    if (freeze_timer == 0x0)
        current_sprite.anim_duration_counter--;
    
    if (freeze_timer < 0x2E && (freeze_timer & 0x1) != 0x0)
        current_sprite.palette_row = 0xF - (current_sprite.frozen_palette_row_offset + current_sprite.spriteset_gfx_slot);
    else
        current_sprite.palette_row = current_sprite.maybe_absolute_palette_row;*/
}

void sprite_util_update_secondary_sprite_freeze_timer(enum s_sprite_id sprite_id, u8 ram_slot)
{

}

void sprite_util_unfreeze_anim_eay(void)
{

}

void sprite_util_metroid_unfreeze_anim(void)
{

}

void sprite_util_update_primary_sprite_freeze_timer_of_current(void)
{

}

void sprite_util_unfreeze_secondary_sprites(enum s_sprite_id sprite_id, u8 ram_slot)
{

}

u8 sprite_util_refill_energy(void)
{

}

u8 sprite_util_refill_missile(void)
{

}

u8 sprite_util_refull_super_missiles(void)
{

}

u8 sprite_util_refill_power_bombs(void)
{

}

u8 sprite_util_check_crouching_or_morphed(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_crouching_or_crawling(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_morphed(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_stop_sprites_pose(void)
{
    if (prevent_movement_timer == 0x0)
    {
        switch (samus_data.pose)
        {
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_FACING_THE_FOREGROUND:
                return TRUE;
        }
    }
    else
        return TRUE;
    
    return FALSE;
}

enum damage_contact_type sprite_util_sprite_take_damage_from_samus_contact(struct sprite_data* sprite_ptr, struct samus_data* samus_ptr)
{

}

u8 sprite_util_check_pulling_self_up(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
           return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_on_zipline(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
           return TRUE;
    }

    return FALSE;
}

u8 sprite_util_count_primary_sprites(enum p_sprite_id sprite_id)
{
    u8 count;
    struct sprite_data* ptr;

    count = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) == 0x0 && ptr->sprite_id == sprite_id)
            count++;
        ptr++;
    }

    return count;
}

u8 sprite_util_count_secondary_sprites_with_current_sprite_ram_slot(enum s_sprite_id sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct sprite_data* ptr;

    count = 0x0;
    ram_slot = current_sprite.primary_sprite_ram_slot;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) != 0x0 && ptr->sprite_id == sprite_id && ptr->primary_sprite_ram_slot == ram_slot)
            count++;
        ptr++;
    }

    return count;
}

u8 sprite_util_count_secondary_sprites_with_current_sprite_ram_slot(enum p_sprite_id sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct sprite_data* ptr;

    count = 0x0;
    ram_slot = current_sprite.primary_sprite_ram_slot;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) == 0x0 && ptr->sprite_id == sprite_id && ptr->primary_sprite_ram_slot == ram_slot)
            count++;
        ptr++;
    }

    return count;
}

u8 sprite_util_find_primary(enum p_sprite_id sprite_id)
{
    u8 ram_slot;
    struct sprite_data* ptr;

    ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) == 0x0 && ptr->sprite_id == sprite_id)
            return ram_slot;
        ram_slot++;
        ptr++;
    }

    return 0xFF;
}

u8 sprite_util_find_secondary_with_room_slot(enum s_sprite_id sprite_id, u8 room_slot)
{
    u8 ram_slot;
    struct sprite_data* ptr;

    ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) != 0x0 && ptr->sprite_id == sprite_id && ptr->room_slot == room_slot)
            return ram_slot;
        ram_slot++;
        ptr++;
    }

    return 0xFF;
}

u8 sprite_util_check_has_drop(void)
{
    u8 ram_slot;
    struct sprite_data* ptr;
    enum sprite_samus_collision collision;

    ram_slot = current_sprite.primary_sprite_ram_slot;
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    ptr = sprite_data;

    while (ptr< sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && ptr->primary_sprite_ram_slot == ram_slot && ptr->samus_collision >= collision)
            return TRUE;
        ptr++;
    }

    return FALSE;
}

u8 sprite_util_count_drops(void)
{
    u8 count;
    struct sprite_data* ptr;

    count = 0x0;
    ptr = sprite_data;

    while (ptr< sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && ptr->samus_collision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
        ptr++;
    }

    return count;
}

void sprite_util_maybe_mecha_ridley_missile_move(u16 samus_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

void sprite_util_maybe_ridley_fireball_move(u16 sprite_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

void sprite_util_update_stun_timer(struct sprite_data* ptr)
{

}

void sprite_util_random_debris(u8 cloud_type, u8 number, u16 y_position, u16 x_position)
{
    /*switch (number)
    {
        case 0x1:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
                sprite_debris_init(cloud_type, 0x1, y_position + 0x8, x_position - 0x8);
            else
                sprite_debris_init(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
        case 0x2:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
            {
                sprite_debris_init(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position, x_position + 0x8);
            }
            else
            {
                sprite_debris_init(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
        case 0x3:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
            {
                sprite_debris_init(cloud_type, 0x2, y_position - 0x10, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position + 0x8, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x10, x_position - 0x8);
            }
            else
            {
                sprite_debris_init(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position - 0x10, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
    }*/
}

enum p_sprite_id sprite_util_get_ammo_drop(u8 rng)
{
    if (equipment.current_energy == equipment.max_energy)
    {
        if ((rng & 0x1) != 0x0 && equipment.max_missiles > equipment.current_missiles)
            return PSPRITE_MISSILE_DROP;
        if ((rng & 0x2) != 0x0 && equipment.max_super_missiles > equipment.current_super_missiles)
            return PSPRITE_SUPER_MISSILE_DROP;
        if ((rng & 0x4) != 0x0 && equipment.max_power_bombs > equipment.current_power_bombs)
            return PSPRITE_POWER_BOMB_DROP;
    }
    return PSPRITE_UNUSED0;
}

enum p_sprite_id sprite_util_determine_enemy_drop(void)
{

}

void sprite_util_sprite_death(enum death_type death_type, u16 y_position, u16 x_position, u8 play_sound, enum particle_effect_id effect)
{
    enum p_sprite_id drop;

    switch (current_sprite.pose)
    {
        case 0x63:
            particle_set(y_position, x_position, PE_SHINESPARK_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x131);
            break;
        case 0x64:
            particle_set(y_position, x_position, PE_SPEEDBOOSTER_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x133);
            break;
        case 0x65:
            particle_set(y_position, x_position, PE_SCREW_ATTACK_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x130);
            break;
        case 0x66:
            particle_set(y_position, x_position, PE_SUDO_SCREW_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x132);
            break;
        default:
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_SMALL);
                if (play_sound != FALSE)
                    play_sound1(0x12C);
            }
            else
            {
                if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
                {
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_MEDIUM);
                    if (play_sound != FALSE)
                        play_sound1(0x12D);
                }
                else
                {
                    if (effect == PE_SPRITE_EXPLOSION_BIG)
                    {
                        particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_BIG);
                        if (play_sound != FALSE)
                            play_sound1(0x12E);
                    }
                    else
                    {
                        if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
                        {
                            particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                            if (play_sound != FALSE)
                                play_sound1(0x12F);
                        }
                        else
                        {
                            if ((u8)(effect - 0x27) < 0x3)
                                particle_set(y_position, x_position, effect);
                        }
                    }
                }
            }
    }

    drop = sprite_util_determine_enemy_drop();
    if (drop != 0x0)
    {       
        if (death_type != DEATH_NORMAL)
        {
            if (death_type != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
                sprite_spawn_drop_followers(drop, current_sprite.room_slot, 0x0, current_sprite.primary_sprite_ram_slot, y_position, x_position, 0x0);
        }
        else
        {
            current_sprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            current_sprite.properties = 0x0;
            current_sprite.spriteset_gfx_slot = 0x0;
            current_sprite.sprite_id = drop;
            current_sprite.y_position = y_position;
            current_sprite.x_position = x_position;
            current_sprite.bg_priority = 0x2;
            current_sprite.draw_order = 0x4;
            current_sprite.pose = 0x0;
            current_sprite.health = 0x0;
            current_sprite.invicibility_stun_flash_timer = 0x0;
            current_sprite.palette_row = 0x0;
            current_sprite.frozen_palette_row_offset = 0x0;
            current_sprite.maybe_absolute_palette_row = 0x0;
            current_sprite.ignore_samus_collision_timer = 0x1;
            current_sprite.freeze_timer = 0x0;
        }
    }
    else
    {
        if (death_type == DEATH_NORMAL)
            current_sprite.status = 0x0;
    }
}

u8 sprite_util_is_sprite_stunned(void)
{
    u8 is_stunned;
    u8 stun_timer;
    u8 diff;

    is_stunned = FALSE;
    diff = difficulty;
    
    stun_timer = 0xE;
    if (diff < 0x2)
        stun_timer = 0x9;

    if (((current_sprite.invicibility_stun_flash_timer & 0x7F) > stun_timer) && current_sprite.pose < 0x62)
    {
        if (current_sprite.anim_duration_counter != 0x0)
            current_sprite.anim_duration_counter--;
        is_stunned = TRUE;
    }

    return is_stunned;
}

u8 sprite_util_is_screen_on_screen_and_screen_shake(void)
{
    if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0 && (screen_shake_y.timer != 0x0 || screen_shake_x.timer != 0x0))
        return TRUE;
    else
        return FALSE;
}

void sprite_util_maybe_update_sub_sprite1_timer(void)
{
    /*u8 adc;
    u16 curr_anim_frame;
    u8 curr_anim;

    sub_sprite_data1.timer = 0x0;
    adc = (u8)(sub_sprite_data1.anim_duration_counter + 0x1);
    curr_anim_frame = sub_sprite_data1.curr_anim_frame;

    if ((u8)sub_sprite_data1.oam_pointer[curr_anim_frame].timer < adc)
        sub_sprite_data1.timer = (char)curr_anim_frame + 0x1;*/
}

void sprite_util_update_sub_sprite1_anim(void)
{
    u32 adc;

    adc = sub_sprite_data1.anim_duration_counter + 0x1;
    sub_sprite_data1.anim_duration_counter = adc;
    if ((u8)sub_sprite_data1.oam_pointer[sub_sprite_data1.curr_anim_frame].timer < (u8)adc)
    {
        sub_sprite_data1.anim_duration_counter = 0x1;
        sub_sprite_data1.curr_anim_frame++;
        if ((u8)sub_sprite_data1.oam_pointer[sub_sprite_data1.curr_anim_frame].timer == 0x0)
            sub_sprite_data1.curr_anim_frame = 0x0;
    }
}

void sprite_util_sync_current_sprite_position_with_sub_sprite1_position(void)
{

}

void unk_113b0(void)
{

}

void sprite_util_update_sub_sprite2_anim(void)
{
    u32 adc;

    adc = sub_sprite_data2.anim_duration_counter + 0x1;
    sub_sprite_data2.anim_duration_counter = adc;
    if ((u8)sub_sprite_data2.oam_pointer[sub_sprite_data2.curr_anim_frame].timer < (u8)adc)
    {
        sub_sprite_data2.anim_duration_counter = 0x1;
        sub_sprite_data2.curr_anim_frame++;
        if ((u8)sub_sprite_data2.oam_pointer[sub_sprite_data2.curr_anim_frame].timer == 0x0)
            sub_sprite_data2.curr_anim_frame = 0x0;
    }
}

void unk_1144c(void)
{

}

void sprite_util_update_sub_sprite_anim(struct sub_sprite_data* ptr)
{
    u32 adc;

    adc = ptr->anim_duration_counter + 0x1;
    ptr->anim_duration_counter = adc;
    if ((u8)ptr->oam_pointer[ptr->curr_anim_frame].timer < (u8)adc)
    {
        ptr->anim_duration_counter = 0x1;
        ptr->curr_anim_frame++;
        if ((u8)ptr->oam_pointer[ptr->curr_anim_frame].timer == 0x0)
            ptr->curr_anim_frame = 0x0;
    }
}

void sprite_util_sync_current_sprite_position_with_sub_sprite_position(struct sub_sprite_data* ptr)
{

}

void unk_11520(struct sub_sprite_data* ptr)
{

}

u8 sprite_util_security_gate_samus_collision(void)
{

}

void sprite_util_set_splash_effect(u16 y_position, u16 x_position, enum splash_size size)
{

}

u8 sprite_util_check_out_of_room_effect(u16 old_y, u16 y_positoin, u16 x_position, enum splash_size size)
{

}

u8 sprite_util_check_in_room_effect(u16 old_y, u16 y_positoin, u16 x_position, enum splash_size size)
{

}

u16 sprite_util_get_final_completion_percentage(void)
{

}