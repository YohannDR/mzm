#include "morph_ball.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void morph_ball_init(void)
{
    if (gEquipment.suit_misc & SMF_MORPH_BALL)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.hitbox_top_offset = -0x1C;
        gCurrentSprite.hitbox_bottom_offset = 0x1C;
        gCurrentSprite.hitbox_left_offset = -0x1C;
        gCurrentSprite.hitbox_right_offset = 0x1C;
        gCurrentSprite.draw_distance_top_offset = 0x8;
        gCurrentSprite.draw_distance_bottom_offset = 0x8;
        gCurrentSprite.draw_distance_horizontal_offset = 0x8;
        gCurrentSprite.oam_pointer = morph_ball_oam_2b2ba8;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.y_position -= 0x20;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.draw_order = 0x3;
        sprite_spawn_secondary(SSPRITE_MORPH_BALL_OUTSIDE, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void morph_ball_get(void)
{
    if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignore_samus_collision_timer = 0x1;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer1 = 0x0;
        gEquipment.suit_misc |= SMF_MORPH_BALL;
        sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x10, 0xC, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void morph_ball_flash_anim(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if ((gCurrentSprite.timer1 & 0x1) == 0x0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

void morph_ball_outside_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x4;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    gCurrentSprite.draw_distance_top_offset = 0x8;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.oam_pointer = morph_ball_outside_oam_2b2bd0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_order = 0x2;
    gCurrentSprite.pose = 0x9;
}

void morph_ball_outside_flash_anim(void)
{
    u8 ram_slot;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;

    gCurrentSprite.status = gSpriteData[ram_slot].status;
    if ((gSpriteData[ram_slot].properties & SP_ALWAYS_ACTIVE) != 0x0)
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
}

void morph_ball(void)
{
    switch (gCurrentSprite.pose)
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
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            morph_ball_outside_init();
        case 0x9:
            morph_ball_outside_flash_anim();
    }
}