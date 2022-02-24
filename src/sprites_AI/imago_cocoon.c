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

void winged_ripper_imago_collision(void)
{
    
}

void winged_ripper_init(void)
{
    
}

void winged_ripper_gfx_init(void)
{
    
}

void winged_ripper_move(void)
{
    
}

void winged_ripper_death(void)
{
    
}

void imago_cocoon(void)
{
    
}

void imago_cocoon_vine(void)
{
    
}

void imago_cocoon_spore(void)
{
    
}

void winged_ripper(void)
{
    
}

void defeated_imago_cocoon(void)
{
    /*current_sprite.ignore_samus_collision_timer = 0x1;
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
    }*/
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