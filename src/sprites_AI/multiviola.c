#include "multiviola.h"
#include "../sprite_util.h"
#include "../globals.h"

void multiviola_init(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x20;
    gCurrentSprite.draw_distance_bottom_offset = 0xC;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.oam_pointer = multiviola_oam_2d0520;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = gCurrentSprite.primary_sprite_ram_slot << 0x1;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    sprite_util_make_sprite_face_samus_x_flip();
    gCurrentSprite.pose = 0x9;
}

void multiviola_move(void)
{
    u8 is_bouncing;
    u16 y_movement;

    is_bouncing = 0x0;
    y_movement = 0x3;

    if ((gCurrentSprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        sprite_util_check_collision_at_position(gCurrentSprite.y_position, gCurrentSprite.hitbox_right_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position += 0x3;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }
    else
    {
        sprite_util_check_collision_at_position(gCurrentSprite.y_position, gCurrentSprite.hitbox_left_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position -= 0x3;
        else
        {
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }

    if ((gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) != 0x0)
    {
        sprite_util_check_collision_at_position(gCurrentSprite.hitbox_top_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position -= y_movement;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }
    else
    {
        sprite_util_check_collision_at_position(gCurrentSprite.hitbox_bottom_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position += y_movement;
        else
        {
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }

    if (is_bouncing != 0x0 && (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
        unk_2b20(0x152);
}

void multiviola_unused_empty1(void)
{
    return;
}

void multiviola_unused_empty2(void)
{
    return;
}

void multiviola(void)
{
    if ((gCurrentSprite.properties & SP_UNKNOWN) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x153);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
    {
        sprite_util_update_freeze_timer();
        sprite_util_update_secondary_sprite_freeze_timer_of_current(SSPRITE_MULTIVIOLA_UNUSED, gCurrentSprite.primary_sprite_ram_slot);
    }
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (gCurrentSprite.pose)
            {
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
                    break;
                case 0x0:
                    multiviola_init();
                    break;
                case 0x9:
                    multiviola_move();
            }
        }
    }
}

void multiviola_unused(void)
{
    return;
}