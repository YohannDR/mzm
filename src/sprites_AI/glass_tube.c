#include "glass_tube.h"
#include "../sprite_util.h"
#include "../particle.h"
#include "../screen_shake.h"
#include "../music.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

void glass_tube_change_ccaa(void)
{

}

/**
 * 463dc | 90 | Initialize a glass tube sprite
 * 
 */
void glass_tube_init(void)
{
    current_sprite.draw_distance_top_offset = 0x30;
    current_sprite.draw_distance_bottom_offset = 0x30;
    current_sprite.draw_distance_horizontal_offset = 0x70;
    current_sprite.hitbox_top_offset = -0x80;
    current_sprite.hitbox_bottom_offset = 0x80;
    current_sprite.hitbox_left_offset = -0x100;
    current_sprite.hitbox_right_offset = 0x100;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    
    if (event_function(EVENT_ACTION_CHECKING, EVENT_GLASS_TUBE_BROKEN))
    {
        current_sprite.oam_pointer = glass_tube_oam_broken;
        current_sprite.pose = 0xF;
        glass_tube_change_ccaa();
    }
    else
    {
        current_sprite.oam_pointer = glass_tube_oam;
        current_sprite.pose = 0x9;
    }

    if (!event_function(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        sound_play1(0x122);
}

/**
 * 4646c | c0 | Checks for collision between a power bomb and the glass tube
 * 
 */
void glass_tube_check_power_bomb_collision(void)
{
    u16 bomb_y;
    u16 bomb_x;
    u16 bomb_top;
    u16 bomb_bottom;
    u16 bomb_left;
    u16 bomb_right;   
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;

    if (event_function(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED) && current_power_bomb.animation_state != 0x0 && equipment.max_power_bombs != 0x0)
    {
        bomb_y = current_power_bomb.y_position;
        bomb_x = current_power_bomb.x_position;
        bomb_top = current_power_bomb.hitbox_top_offset + bomb_y;
        bomb_bottom = current_power_bomb.hitbox_bottom_offset + bomb_y;
        bomb_left = current_power_bomb.hitbox_left_offset + bomb_x;
        bomb_right = current_power_bomb.hitbox_right_offset + bomb_x;
        
        sprite_y = current_sprite.y_position;
        sprite_x = current_sprite.x_position;
        sprite_top = current_sprite.hitbox_top_offset + sprite_y;
        sprite_bottom = current_sprite.hitbox_bottom_offset + sprite_y;
        sprite_left = current_sprite.hitbox_left_offset + sprite_x;
        sprite_right = current_sprite.hitbox_right_offset + sprite_x;

        if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, bomb_top, bomb_bottom, bomb_left, bomb_right))
        {
            current_sprite.pose = 0x23;
            current_sprite.timer1 = 0x78;
            event_function(EVENT_ACTION_SETTING, EVENT_GLASS_TUBE_BROKEN);
        }
    }
}

/**
 * 4652c | 3c | Delay before the glass tube starts cracking
*/
void glass_tube_delay_before_breaking(void)
{
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        current_sprite.pose = 0x25;
        current_sprite.oam_pointer = glass_tube_oam_cracking;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        sound_play1(0x27A);
    }
}

/**
 * 46568 | 8c | Checks if the cracking animation ended, spawn dust particles and starts a global screen shake
 * 
 */
void glass_tube_check_cracking_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x27;
        current_sprite.oam_pointer = glass_tube_oam_breaking;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        glass_tube_change_ccaa();
        particle_set(current_sprite.y_position - 0x1E, current_sprite.x_position - 0x12C, PE_MEDIUM_DUST);
        particle_set(current_sprite.y_position + 0xA0, current_sprite.x_position - 0x140, PE_TWO_MEDIUM_DUST);
        particle_set(current_sprite.y_position - 0x1E, current_sprite.x_position + 0x12C, PE_MEDIUM_DUST);
        particle_set(current_sprite.y_position + 0xA0, current_sprite.x_position + 0x140, PE_TWO_MEDIUM_DUST);
        screen_shake_start_vertical(0x1E, 0x81);
        screen_shake_start_horizontal(0x1E, 0x81);
    }
}

/**
 * 46568 | 8c | Checks if the breaking animation ended
 * 
 */
void glass_tube_check_breaking_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0xF;
        current_sprite.oam_pointer = glass_tube_oam_broken;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

/**
 * 46620 | e8 | Glass Tube AI
 * 
 */
void glass_tube(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            glass_tube_init();
            break;
        case 0x9:
            glass_tube_check_power_bomb_collision();
            break;
        case 0x23:
            glass_tube_delay_before_breaking();
            break;
        case 0x25:
            glass_tube_check_cracking_anim_ended();
            break;
        case 0x27:
            glass_tube_check_breaking_anim_ended();
    }
}