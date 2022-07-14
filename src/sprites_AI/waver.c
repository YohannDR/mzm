#include "waver.h"
#include "../sprite_util.h"
#include "../globals.h"

void waver_init(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = -0x20;
    gCurrentSprite.oam_pointer = waver_oam_2d88ac;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    sprite_util_make_sprite_face_samus_x_flip();
    gCurrentSprite.pose = 0x9;
}

void waver_move(void)
{
    u16 speed;

    speed = 0x2;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        sprite_util_check_collision_at_position(gCurrentSprite.y_position, gCurrentSprite.hitbox_right_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position += 0x4;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        sprite_util_check_collision_at_position(gCurrentSprite.y_position, gCurrentSprite.hitbox_left_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position -= 0x4;
        else
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        sprite_util_check_collision_at_position(gCurrentSprite.hitbox_top_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position -= speed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    }
    else
    {
        sprite_util_check_collision_at_position(gCurrentSprite.hitbox_bottom_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position += speed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
    }
}

void waver(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x177);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (gCurrentSprite.pose)
            {
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    break;
                case 0x0:
                    waver_init();
                    break;
                case 0x9:
                    waver_move();
            }
        }
    }
}