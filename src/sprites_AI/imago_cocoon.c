#include "imago_cocoon.h"
#include "../event.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../sprite_debris.h"
#include "../particle.h"
#include "../globals.h"

void imago_cocoon_update_position_and_anim(void)
{
    
}

void imago_cocoon_change_one_ccaa(enum current_clipdata_affecting_action ccaa)
{
    
}

void imago_cocoon_change_two_middle_ccaa(enum current_clipdata_affecting_action ccaa)
{
    
}

void imago_cocoon_change_two_around_ccaa(enum current_clipdata_affecting_action ccaa)
{
    
}

void imago_cocoon_change_two_blocking_ccaa(enum current_clipdata_affecting_action ccaa)
{
    
}

void imago_cocoon_change_oam_scaling(u16 limit, u16 value)
{
    
}

void imago_cocoon_init(void)
{
    
}

void imago_cocoon_falling_movement(void)
{
    
}

void imago_cocoon_spawning_dying(void)
{
    
}

void imago_cocoon_falling_before_blocks(void)
{
    
}

void imago_cocoon_falling_after_blocks(void)
{
    
}

void imago_cocoon_unlock_passage(void)
{
    
}

void imago_cocoon_in_ground_anim(void)
{
    
}

void imago_cocoon_vine_init(void)
{
    
}

void imago_cocoon_vine_play_sound(void)
{
    
}

void imago_cocoon_vine_death(void)
{
    
}

void imago_cocoon_vine_spawn_spore(void)
{
    
}

void imago_cocoon_vine_hanging_death(void)
{
    
}

void imago_cocoon_vine_hanging_death_anim(void)
{
    
}

void imago_cocoon_spore_sync_position(void)
{
    
}

void imago_cocoon_spore_init(void)
{
    
}

void imago_cocoon_spore_before_spawning(void)
{
    
}

void imago_cocoon_spore_spawning(void)
{
    
}

void imago_cocoon_spore_move(void)
{
    
}

void imago_cocoon_spore_exploding_gfx_init(void)
{
    
}

void imago_cocoon_spore_check_exploding_anim_ended(void)
{
    
}

// 27edc | c4 | Checks if the winged ripper and imago are colliding (only if imago is falling), sets the winged ripper to a killed pose if yes
// Returns : 1 if colliding, 0 otherwise
u8 winged_ripper_imago_collision(void)
{
    u8 colliding;
    u8 slot;
    struct sprite_data* pSprite;
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 imago_y;
    u16 imago_x;
    u16 imago_top;
    u16 imago_bottom;
    u16 imago_left;
    u16 imago_right;

    colliding = FALSE;
    pSprite = sprite_data + current_sprite.primary_sprite_ram_slot;
    if (pSprite->pose == 0x9 && pSprite->array_offset > 0x10)
    {
        sprite_y = current_sprite.y_position;
        sprite_x = current_sprite.x_position;
        sprite_top = sprite_y + current_sprite.hitbox_top_offset;
        sprite_bottom = sprite_y + current_sprite.hitbox_bottom_offset;
        sprite_left = sprite_x + current_sprite.hitbox_left_offset;
        sprite_right = sprite_x + current_sprite.hitbox_right_offset;
        
        imago_y = pSprite->y_position;
        imago_x = pSprite->x_position;
        imago_top = imago_y + pSprite->hitbox_top_offset;
        imago_bottom = imago_y + pSprite->hitbox_bottom_offset;
        imago_left = imago_x + pSprite->hitbox_left_offset;
        imago_right = imago_x + pSprite->hitbox_right_offset;

        if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, imago_top, imago_bottom, imago_left, imago_right))
        {
            current_sprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

// 27fa0 | a0 | Initializes a winged ripper sprite  
void winged_ripper_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.draw_distance_top_offset = 0xC;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x10,
    current_sprite.oam_pointer = winged_ripper_oam_2e0c60;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.health = secondary_sprite_stats_2b1be4[current_sprite.sprite_id][0x0];
    current_sprite.draw_order = 0x8;
    current_sprite.pose = 0x8;
    current_sprite.oam_scaling = 0xC0;
    current_sprite.timer2 = 0x80;
    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
    current_sprite.array_offset = 0x0;
    current_sprite.frozen_palette_row_offset = 0x4;
}

void winged_ripper_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = winged_ripper_oam_2e0c60;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
}

void winged_ripper_move(void)
{

}

void winged_ripper_death(void)
{
    if (current_sprite.standing_on_sprite)
    {
        if (samus_data.standing_status == STANDING_ENEMY)
            samus_data.standing_status = STANDING_MIDAIR;
        current_sprite.standing_on_sprite = FALSE;
    }
    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position + 0x8, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void imago_cocoon(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_init();
            break;
        case 0x8:
            imago_cocoon_spawning_dying();
            break;
        case 0x9:
            imago_cocoon_falling_before_blocks();
            break;
        case 0x23:
            imago_cocoon_falling_after_blocks();
            break;
        case 0x25:
            imago_cocoon_unlock_passage();
            break;
        case 0x27:
            imago_cocoon_in_ground_anim();
    }

    if (current_sprite.pose > 0x24)
        sprite_util_sync_current_sprite_position_with_sub_sprite1_position();
    else
        imago_cocoon_update_position_and_anim();
}

void imago_cocoon_vine(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_vine_init();
            break;
        case 0x62:
            imago_cocoon_vine_death();
        case 0x8:
            imago_cocoon_vine_play_sound();
            break;
        case 0xE:
            imago_cocoon_vine_spawn_spore();
            break;
        case 0x42:
            imago_cocoon_vine_hanging_death();
            break;
        case 0x43:
            imago_cocoon_vine_hanging_death_anim();
    }

    if (current_sprite.pose == 0x67)
        sprite_util_sync_current_sprite_position_with_sub_sprite1_position();
    else
        imago_cocoon_update_position_and_anim();
}

void imago_cocoon_spore(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_spore_init();
            break;
        case 0x9:
            imago_cocoon_spore_before_spawning();
            break;
        case 0x23:
            imago_cocoon_spore_spawning();
            break;
        case 0x25:
            imago_cocoon_spore_move();
            break;
        case 0x42:
            imago_cocoon_spore_exploding_gfx_init();
            break;
        case 0x43:
            imago_cocoon_spore_check_exploding_anim_ended();
            break;
        default:
            sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            if (current_sprite.status & SPRITE_STATUS_EXISTS && sprite_util_count_drops() > 0x1)
                current_sprite.status = 0x0; // Anti lag measure
    }
}

void winged_ripper(void)
{
    if (current_sprite.freeze_timer != 0x0)
    {
        sprite_util_unfreeze_anim_easy();
        if (!(winged_ripper_imago_collision() << 0x18))
            return;
    }
    if (!sprite_util_is_sprite_stunned())
    {
        switch (current_sprite.pose)
        {
            case 0x0:
                winged_ripper_init();
                break;
            case 0x8:
                winged_ripper_gfx_init();
            case 0x9:
                winged_ripper_move();
                break;
            default:
                winged_ripper_death();
        }

        current_sprite.array_offset++;
    }
}

void defeated_imago_cocoon(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.draw_distance_top_offset = 0xC;
        current_sprite.draw_distance_bottom_offset = 0x28;
        current_sprite.draw_distance_horizontal_offset = 0x30;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_cocoon_oam_2e0d00;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x9;
        current_sprite.frozen_palette_row_offset = 0x5;
    }
}

void imago_ceiling_vine(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.draw_distance_top_offset = 0xC;
        current_sprite.draw_distance_bottom_offset = 0x28;
        current_sprite.draw_distance_horizontal_offset = 0x30;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_ceiling_vine_oam_2e0a28;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.draw_order = 0x5;
        current_sprite.pose = 0x9;
        current_sprite.frozen_palette_row_offset = 0x5;
    }
}

void event_trigger_discovered_imago_passage(void)
{
    if (current_sprite.pose == 0x0)
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            current_sprite.status = 0x0;
            return;
        }
        current_sprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3;
        current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        current_sprite.draw_distance_top_offset = 0x10;
        current_sprite.draw_distance_bottom_offset = 0x0;
        current_sprite.draw_distance_horizontal_offset = 0x8;
        current_sprite.hitbox_top_offset = -0x40;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = -0x20;
        current_sprite.hitbox_right_offset = 0x20;
        current_sprite.pose = 0x8;
        current_sprite.oam_pointer = large_energy_oam_2b2750;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }

    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        current_sprite.status = 0x0;
        event_function(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

void imago_cocoon_after_fight(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.draw_distance_top_offset = 0x30;
        current_sprite.draw_distance_bottom_offset = 0x10;
        current_sprite.draw_distance_horizontal_offset = 0x20;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_cocoon_oam_2e0d00;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x9;
    }

    if (current_sprite.anim_duration_counter == 0x1)
    {
        switch (current_sprite.curr_anim_frame)
        {
            case 0x1:
            case 0x4:
                play_sound1(0x212);
        }
    }
}