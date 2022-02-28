#include "zipline.h"
#include "../samus.h"
#include "../sprite_util.h"
#include "../event.h"
#include "../globals.h"

void zipline_check_colliding(void)
{
    u16 y_position;
    u16 x_position;

    y_position = current_sprite.y_position - 0x20;
    x_position = current_sprite.x_position;

    if (current_sprite.pose == 0x0)
    {
        sprite_util_check_collision_at_position(y_position, x_position + 0x2C);
        if (current_affecting_clipdata.movement == MOVEMENT_CLIPDATA_STOP_ENEMY_BLOCK_SOLID)
            current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
        {
            sprite_util_check_collision_at_position(y_position, x_position - 0x2C);
            if (current_affecting_clipdata.movement == MOVEMENT_CLIPDATA_STOP_ENEMY_BLOCK_SOLID)
                current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
    else
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
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
    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        samus_grabbing = TRUE;
        velocity = 0xC;
    }
    else
        velocity = 0x10;

    zipline_check_colliding();
    if (current_affecting_clipdata.hazard == MOVEMENT_CLIPDATA_STOP_ENEMY_BLOCK_SOLID)
    {
        releasing++;
        current_sprite.x_position = (current_sprite.x_position & 0xFFC0) + 0x20;
        if (samus_grabbing)
            samus_data.x_position = current_sprite.x_position;
    }
    else
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            current_sprite.x_position += velocity;
            if (samus_grabbing)
                samus_data.x_position += velocity;
        }
        else
        {
            current_sprite.x_position -= velocity;
            if (samus_grabbing)
                samus_data.x_position -= velocity;
        }
    }

    if (releasing && samus_grabbing)
    {
        current_sprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        current_sprite.ignore_samus_collision_timer = 0xF;
        samus_set_pose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
    }

    return releasing;
}

void zipline_gfx_update(void)
{
    enum sprite_status status;
    u32 check;

    status = current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING;
    if (status)
    {
        check = event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED);
        if (check)
        {
            switch (current_sprite.timer2)
            {
                case 0x0:
                    current_sprite.oam_pointer = zipline_oam_2ce9b0;
                    current_sprite.anim_duration_counter = 0x0;
                    current_sprite.curr_anim_frame = 0x0;
                    current_sprite.timer2 = 0x1;
                    break;

                case 0x1:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        current_sprite.oam_pointer = zipline_oam_2ce9d0;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.timer2 = 0x2;
                        current_sprite.health = 0x2;
                    }
                    break;

                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        current_sprite.oam_pointer = zipline_oam_2ce9d0;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.timer2 = 0x2;
                    }
                    break;

                case 0x2:
                    if (current_sprite.oam_pointer != zipline_oam_2ce9d0)
                    {
                        current_sprite.oam_pointer = zipline_oam_2ce9d0;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                    }
            }
        }
        else
        {
            switch (current_sprite.timer2)
            {
                case 0x0:
                    current_sprite.oam_pointer = zipline_oam_2ce928;
                    current_sprite.anim_duration_counter = check;
                    current_sprite.curr_anim_frame = check;
                    current_sprite.timer2 = 0x1;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        current_sprite.oam_pointer = zipline_oam_2cd948;
                        current_sprite.anim_duration_counter = check;
                        current_sprite.curr_anim_frame = check;
                        current_sprite.timer2 = 0x2;
                    }
                    break;

                case 0x2:
                    if (current_sprite.oam_pointer != zipline_oam_2ce948)
                    {
                        current_sprite.oam_pointer = zipline_oam_2ce948;
                        current_sprite.anim_duration_counter = check;
                        current_sprite.curr_anim_frame = check;
                    }
            }
        }
    }
    else
    {
        check = event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED);
        if (check)
        {
            switch (current_sprite.timer2)
            {
                case 0x2:
                    current_sprite.oam_pointer = zipline_oam_2cea08;
                    current_sprite.anim_duration_counter = status;
                    current_sprite.curr_anim_frame = status;
                    current_sprite.timer2 = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        current_sprite.oam_pointer = zipline_oam_activated_2ce978;
                        current_sprite.curr_anim_frame = check;
                        current_sprite.anim_duration_counter = 0x0;
                    }
                    break;

                case 0x0:
                    if (current_sprite.oam_pointer != zipline_oam_activated_2ce978)
                    {
                        current_sprite.oam_pointer = zipline_oam_activated_2ce978;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                    }
            }
        }
        else
        {
            switch (current_sprite.timer2)
            {
                case 0x2:
                    current_sprite.oam_pointer = zipline_oam_2ce958;
                    current_sprite.anim_duration_counter = check;
                    current_sprite.curr_anim_frame = check;
                    current_sprite.timer2 = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (sprite_util_check_end_current_sprite_anim())
                    {
                        current_sprite.oam_pointer = zipline_oam_deactivated_2ce918;
                        current_sprite.anim_duration_counter = check;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.timer2 = 0x0;
                    }
                    break;

                case 0x0:
                    if (current_sprite.oam_pointer != zipline_oam_deactivated_2ce918)
                    {
                        current_sprite.oam_pointer = zipline_oam_activated_2ce978;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                    }
            }
        }
    }
}

void zipline_init(void)
{
    current_sprite.hitbox_top_offset = -0x40;
    current_sprite.hitbox_bottom_offset = 0x10;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.samus_collision = SSC_ZIPLINE;
    current_sprite.health = 0x1;
    current_sprite.properties |= SP_SOLID_FOR_PROJECTILES;
    current_sprite.draw_order = 0x3;
    current_sprite.bg_priority = 0x1;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.timer1 = 0x0;
    current_sprite.timer2 = 0x0;
    zipline_check_colliding();
    if (event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        current_sprite.oam_pointer = zipline_oam_activated_2ce978;
    else
        current_sprite.oam_pointer = zipline_oam_deactivated_2ce918;
    current_sprite.pose = 0x9;
}

void zipline_update(void)
{
    if (!sprite_util_check_on_zipline() && current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        current_sprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        current_sprite.ignore_samus_collision_timer = 0xF;
    }

    zipline_gfx_update();
    if (current_sprite.health == 0x2)
    {
        if ((current_sprite.timer1 & 0xF) == 0x0)
            play_sound1(0x110);
        current_sprite.timer1++;
        if (zipline_moving() << 0x18)
        {
            current_sprite.health = 0x1;
            current_sprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            current_sprite.timer1 = 0x0;
            unk_2c80(0x110, 0x4);
        }
    }
}

void zipline_button_init(void)
{
    if (event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        current_sprite.oam_pointer = zipline_button_oam_activated_2cea38;
    else
        current_sprite.oam_pointer = zipline_button_oam_deactivated_2cea28;

    current_sprite.y_position -= 0x80;
    current_sprite.draw_distance_top_offset = 0x0;
    current_sprite.draw_distance_bottom_offset = 0x18;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.hitbox_top_offset = 0x0;
    current_sprite.hitbox_bottom_offset = 0x50;
    current_sprite.hitbox_left_offset = -0x14;
    current_sprite.hitbox_right_offset = 0x14;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.health = 0x1;
    current_sprite.properties |= SP_SOLID_FOR_PROJECTILES;
    current_sprite.pose = 0x1;
    current_sprite.draw_order = 0x3;
    current_sprite.bg_priority = 0x1;
}

void zipline_button_activated_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.oam_pointer = zipline_button_oam_activated_2cea38;
}

void zipline_button_spawn(void)
{
    u8 slot;

    slot = sprite_util_find_primary(PSPRITE_ZIPLINE);
    if (slot == 0xFF)
        current_sprite.status = 0x0;
    else
    {
        current_sprite.timer2 = slot;
        if (event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            zipline_button_activated_gfx_init();
        else
            current_sprite.pose = 0xF;
    }
}

void zipline_button_check_ziplines_activated(void)
{
    if (event_function(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        zipline_button_activated_gfx_init();
}

void zipline_button_idle(void)
{
    u8 moving;
    u8 slot;

    moving = FALSE;
    slot = current_sprite.timer2;
    if (current_sprite.invicibility_stun_flash_timer & 0x7F)
    {
        sprite_data[slot].health = 0x2;
        moving = TRUE;
        play_sound1(0x111);
    }
    else if (sprite_data[slot].health == 0x2)
        moving = TRUE;

    if (moving)
    {
        current_sprite.pose = 0x23;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = zipline_button_oam_2cea70;
    }
}

void zipline_button_zipline_moving(void)
{
    u8 slot;

    slot = current_sprite.timer2;

    if (sprite_data[slot].health == 0x1)
        zipline_button_activated_gfx_init();
}

void zipline(void)
{
    switch (current_sprite.pose)
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
    switch (current_sprite.pose)
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