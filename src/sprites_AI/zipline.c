#include "zipline.h"
#include "../samus.h"
#include "../sprite_util.h"
#include "../event.h"
#include "../globals.h"

void zipline_check_colliding(void)
{
    u16 y_position;
    u16 x_position;

    y_position = gCurrentSprite.y_position - 0x20;
    x_position = gCurrentSprite.x_position;

    if (gCurrentSprite.pose == 0x0)
    {
        sprite_util_check_collision_at_position(y_position, x_position + 0x2C);
        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
        {
            sprite_util_check_collision_at_position(y_position, x_position - 0x2C);
            if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            sprite_util_check_collision_at_position(y_position, x_position + 0x2C);
        else
            sprite_util_check_collision_at_position(y_position, x_position - 0x2C);
    }
}

u8 zipline_moving(void)
{
    u8 releasing;
    u16 velocity;
    u8 samus_grabbing;

    releasing = FALSE;
    samus_grabbing = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        samus_grabbing = TRUE;
        velocity = 0xC;
    }
    else
        velocity = 0x10;

    zipline_check_colliding();
    if (gCurrentAffectingClipdata.hazard == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
    {
        releasing++;
        gCurrentSprite.x_position = (gCurrentSprite.x_position & 0xFFC0) + 0x20;
        if (samus_grabbing)
            gSamusData.x_position = gCurrentSprite.x_position;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            gCurrentSprite.x_position += velocity;
            if (samus_grabbing)
                gSamusData.x_position += velocity;
        }
        else
        {
            gCurrentSprite.x_position -= velocity;
            if (samus_grabbing)
                gSamusData.x_position -= velocity;
        }
    }

    if (releasing && samus_grabbing)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.ignore_samus_collision_timer = 0xF;
        samus_set_pose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
    }

    return releasing;
}

void zipline_gfx_update(void)
{
    u16 status;
    u32 check;

    status = gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING;
    if (status)
    {
        check = EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED);
        if (check)
        {
            switch (gCurrentSprite.timer2)
            {
                case 0x0:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce9b0;
                    gCurrentSprite.anim_duration_counter = 0x0;
                    gCurrentSprite.curr_anim_frame = 0x0;
                    gCurrentSprite.timer2 = 0x1;
                    break;

                case 0x1:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.timer2 = 0x2;
                        gCurrentSprite.health = 0x2;
                    }
                    break;

                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.timer2 = 0x2;
                    }
                    break;

                case 0x2:
                    if (gCurrentSprite.oam_pointer != zipline_oam_2ce9d0)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.timer2)
            {
                case 0x0:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce928;
                    gCurrentSprite.anim_duration_counter = check;
                    gCurrentSprite.curr_anim_frame = check;
                    gCurrentSprite.timer2 = 0x1;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2cd948;
                        gCurrentSprite.anim_duration_counter = check;
                        gCurrentSprite.curr_anim_frame = check;
                        gCurrentSprite.timer2 = 0x2;
                    }
                    break;

                case 0x2:
                    if (gCurrentSprite.oam_pointer != zipline_oam_2ce948)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce948;
                        gCurrentSprite.anim_duration_counter = check;
                        gCurrentSprite.curr_anim_frame = check;
                    }
            }
        }
    }
    else
    {
        check = EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED);
        if (check)
        {
            switch (gCurrentSprite.timer2)
            {
                case 0x2:
                    gCurrentSprite.oam_pointer = zipline_oam_2cea08;
                    gCurrentSprite.anim_duration_counter = status;
                    gCurrentSprite.curr_anim_frame = status;
                    gCurrentSprite.timer2 = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.curr_anim_frame = check;
                        gCurrentSprite.anim_duration_counter = 0x0;
                    }
                    break;

                case 0x0:
                    if (gCurrentSprite.oam_pointer != zipline_oam_activated_2ce978)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.timer2)
            {
                case 0x2:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce958;
                    gCurrentSprite.anim_duration_counter = check;
                    gCurrentSprite.curr_anim_frame = check;
                    gCurrentSprite.timer2 = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_deactivated_2ce918;
                        gCurrentSprite.anim_duration_counter = check;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.timer2 = 0x0;
                    }
                    break;

                case 0x0:
                    if (gCurrentSprite.oam_pointer != zipline_oam_deactivated_2ce918)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                    }
            }
        }
    }
}

void zipline_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x40;
    gCurrentSprite.hitbox_bottom_offset = 0x10;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.samus_collision = SSC_ZIPLINE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = 0x1;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.timer1 = 0x0;
    gCurrentSprite.timer2 = 0x0;
    zipline_check_colliding();
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
    else
        gCurrentSprite.oam_pointer = zipline_oam_deactivated_2ce918;
    gCurrentSprite.pose = 0x9;
}

void zipline_update(void)
{
    if (!sprite_util_check_on_zipline() && gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.ignore_samus_collision_timer = 0xF;
    }

    zipline_gfx_update();
    if (gCurrentSprite.health == 0x2)
    {
        if ((gCurrentSprite.timer1 & 0xF) == 0x0)
            SoundPlay(0x110);
        gCurrentSprite.timer1++;
        if (zipline_moving() << 0x18)
        {
            gCurrentSprite.health = 0x1;
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.timer1 = 0x0;
            unk_2c80(0x110, 0x4);
        }
    }
}

void zipline_button_init(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.oam_pointer = zipline_button_oam_activated_2cea38;
    else
        gCurrentSprite.oam_pointer = zipline_button_oam_deactivated_2cea28;

    gCurrentSprite.y_position -= 0x80;
    gCurrentSprite.draw_distance_top_offset = 0x0;
    gCurrentSprite.draw_distance_bottom_offset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.hitbox_top_offset = 0x0;
    gCurrentSprite.hitbox_bottom_offset = 0x50;
    gCurrentSprite.hitbox_left_offset = -0x14;
    gCurrentSprite.hitbox_right_offset = 0x14;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.pose = 0x1;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = 0x1;
}

void zipline_button_activated_gfx_init(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.oam_pointer = zipline_button_oam_activated_2cea38;
}

void zipline_button_spawn(void)
{
    u8 slot;

    slot = sprite_util_find_primary(PSPRITE_ZIPLINE);
    if (slot == 0xFF)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.timer2 = slot;
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            zipline_button_activated_gfx_init();
        else
            gCurrentSprite.pose = 0xF;
    }
}

void zipline_button_check_ziplines_activated(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        zipline_button_activated_gfx_init();
}

void zipline_button_idle(void)
{
    u8 moving;
    u8 slot;

    moving = FALSE;
    slot = gCurrentSprite.timer2;
    if (gCurrentSprite.invicibility_stun_flash_timer & 0x7F)
    {
        gSpriteData[slot].health = 0x2;
        moving = TRUE;
        SoundPlay(0x111);
    }
    else if (gSpriteData[slot].health == 0x2)
        moving = TRUE;

    if (moving)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = zipline_button_oam_2cea70;
    }
}

void zipline_button_zipline_moving(void)
{
    u8 slot;

    slot = gCurrentSprite.timer2;

    if (gSpriteData[slot].health == 0x1)
        zipline_button_activated_gfx_init();
}

void zipline(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            zipline_init();
            break;
        case 0x9:
            zipline_update();
    }
}

void zipline_button(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            zipline_button_init();
            break;
        case 0x1:
            zipline_button_spawn();
            break;
        case 0x9:
            zipline_button_idle();
            break;
        case 0x23:
            zipline_button_zipline_moving();
            break;
        case 0xF:
            zipline_button_check_ziplines_activated();
    }
}