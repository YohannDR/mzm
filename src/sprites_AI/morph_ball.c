#include "morph_ball.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void morph_ball_init(void)
{
    if (equipment.suit_misc & SMF_MORPH_BALL)
        current_sprite.status = 0x0;
    else
    {
        current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        current_sprite.hitbox_top_offset = -0x1C;
        current_sprite.hitbox_bottom_offset = 0x1C;
        current_sprite.hitbox_left_offset = -0x1C;
        current_sprite.hitbox_right_offset = 0x1C;
        current_sprite.draw_distance_top_offset = 0x8;
        current_sprite.draw_distance_bottom_offset = 0x8;
        current_sprite.draw_distance_horizontal_offset = 0x8;
        current_sprite.oam_pointer = morph_ball_oam_2b2ba8;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        current_sprite.health = 0x1;
        current_sprite.y_position -= 0x20;
        current_sprite.pose = 0x9;
        current_sprite.draw_order = 0x3;
        sprite_spawn_secondary(SSPRITE_MORPH_BALL_OUTSIDE, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void morph_ball_get(void)
{
    if ((current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        prevent_movement_timer = 0x3E8;
        current_sprite.properties |= SP_ALWAYS_ACTIVE;
        current_sprite.ignore_samus_collision_timer = 0x1;
        current_sprite.pose = 0x23;
        current_sprite.timer1 = 0x0;
        equipment.suit_misc |= SMF_MORPH_BALL;
        sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x10, 0xC, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void morph_ball_flash_anim(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if ((current_sprite.timer1 & 0x1) == 0x0)
        current_sprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (prevent_movement_timer < 0x3E7)
        current_sprite.status = 0x0;
}

void morph_ball_outside_init(void)
{
    current_sprite.hitbox_top_offset = -0x4;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    current_sprite.draw_distance_top_offset = 0x8;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.oam_pointer = morph_ball_outside_oam_2b2bd0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_order = 0x2;
    current_sprite.pose = 0x9;
}

void morph_ball_outside_flash_anim(void)
{
    u8 ram_slot;

    ram_slot = current_sprite.primary_sprite_ram_slot;

    current_sprite.status = sprite_data[ram_slot].status;
    if ((sprite_data[ram_slot].properties & SP_ALWAYS_ACTIVE) != 0x0)
        current_sprite.properties |= SP_ALWAYS_ACTIVE;
}

void morph_ball(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            morph_ball_init();
            break;
        case 0x9:
            morph_ball_get();
            break;
        case 0x23:
            morph_ball_flash_anim();
    }
}

void morph_ball_outside(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    
    switch (current_sprite.pose)
    {
        case 0x0:
            morph_ball_outside_init();
        case 0x9:
            morph_ball_outside_flash_anim();
    }
}