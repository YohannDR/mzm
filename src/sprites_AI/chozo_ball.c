#include "chozo_ball.h"
#include "chozo_statue.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../music.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 162b0 | 94 | 
 * Spawns an item banner depending on the chozo statue sprite ID
 * 
 * @param sprite_id Chozo statue sprite ID
 */
void chozo_ball_spawn_item_banner(u8 sprite_id)
{
    u8 text;

    switch (sprite_id)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            text = 0x8;
            break;
        case PSPRITE_CHOZO_STATUE_ICE:
            text = 0xA;
            break;
        case PSPRITE_CHOZO_STATUE_WAVE:
            text = 0xB;
            break;
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            text = 0xC;
            break;
        case PSPRITE_CHOZO_STATUE_BOMB:
            text = 0xD;
            break;
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            text = 0x11;
            break;
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            text = 0x12;
            break;
        case PSPRITE_CHOZO_STATUE_SCREW:
            text = 0x13;
            break;
        case PSPRITE_CHOZO_STATUE_VARIA:
            text = 0xE;
            break;
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            text = 0x14;
            break;
        case PSPRITE_CHOZO_STATUE_GRAVITY:
            text = 0xF;
            break;
    }

    sprite_spawn_primary(PSPRITE_ITEM_BANNER, text, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
}

void chozo_ball_set_oam_pointer(u8 sprite_id)
{

}

void chozo_ball_revealing_set_oam_pointer(u8 sprite_id)
{

}

void chozo_ball_revealed_set_oam_pointer(u8 sprite_id)
{

}

/**
 * 16470 | 74 | Initializes a chozo ball sprite
 * 
 */
void chozo_ball_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.hitbox_top_offset = -0x1C;
    current_sprite.hitbox_bottom_offset = 0x1C;
    current_sprite.hitbox_left_offset = -0x1C;
    current_sprite.hitbox_right_offset = 0x1C;
    current_sprite.draw_distance_top_offset = 0xC;
    current_sprite.draw_distance_bottom_offset = 0xC;
    current_sprite.draw_distance_horizontal_offset = 0xC;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_SOLID;
    current_sprite.health = 0x1;
    current_sprite.pose = 0x8;
    chozo_ball_set_oam_pointer(sprite_data[current_sprite.primary_sprite_ram_slot].sprite_id);
}

/**
 * 164e4 | 4 | Empty function
 * 
 */
void chozo_ball_empty(void)
{
    return;
}

/**
 * 164e8 | 70 | Called before the chozo ball reveals, calls chozo_ball_revealing_set_oam_pointer and updates the sprite data
 * 
 */
void chozo_ball_revealing(void)
{
    current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    current_sprite.health = 0x1;
    current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    current_sprite.pose = 0x67;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.palette_row = current_sprite.absolute_palette_row;
    current_sprite.invicibility_stun_flash_timer &= 0x80;
    chozo_ball_revealing_set_oam_pointer(sprite_data[current_sprite.primary_sprite_ram_slot].sprite_id);
    sound_play1(0x11D);
}

/**
 * 16558 | 3c | Checks if the revealing animation has ended, calls chozo_ball_revealed_set_oam_pointer
 * 
 */
void chozo_ball_check_revealing_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x9;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        chozo_ball_revealed_set_oam_pointer(sprite_data[current_sprite.primary_sprite_ram_slot].sprite_id);
    }
}

/**
 * 16594 | 1c | Registers the item grabbed and calls chozo_ball_spawn_item_banner
 * 
 */
void chozo_ball_register_item(void)
{
    u8 sprite_id;

    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        prevent_movement_timer = 0x3E8;
        current_sprite.properties |= SP_ALWAYS_ACTIVE;
        current_sprite.ignore_samus_collision_timer = 0x1;
        current_sprite.pose = 0x23;
        current_sprite.timer1 = 0x0;
        sprite_id = sprite_data[current_sprite.primary_sprite_ram_slot].sprite_id;
        chozo_statue_register_item(sprite_id);
        chozo_ball_spawn_item_banner(sprite_id);
    }
}

/**
 * 16600 | 3c | Handles the flashing animation when the item gets grabbed 
 * 
 */
void chozo_ball_flash_animation(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;

    if (!(current_sprite.timer1 & 0x1))
        current_sprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        
    if (prevent_movement_timer < 0x3E7)
        current_sprite.status = 0x0;
}

/**
 * 1663c | 58 | Chozo ball AI
 * 
 */
void chozo_ball(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            chozo_ball_init();
            break;
        case 0x8:
            chozo_ball_empty();
            break;
        case 0x67:
            chozo_ball_check_revealing_anim_ended();
            break;
        case 0x9:
            chozo_ball_register_item();
            break;
        case 0x23:
            chozo_ball_flash_animation();
            break;
        default:
            chozo_ball_revealing();
    }
}
