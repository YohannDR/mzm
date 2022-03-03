#include "save_platform.h"
#include "../escape.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

u8 save_platform_detect_samus(void)
{
    u8 colliding;
    i32 samus_y;
    i32 samus_x;
    i32 sprite_y;
    i32 sprite_x;

    colliding = FALSE;
    samus_y = samus_data.y_position;
    samus_x = samus_data.x_position;
    sprite_y = current_sprite.y_position;
    sprite_x = current_sprite.x_position;

    if (samus_y == (sprite_y - 0x41) && (sprite_x - 0x40) < samus_x && (sprite_x + 0x40) > samus_x)
        colliding = TRUE;
    return colliding;
}

void save_platform_init(void)
{
    current_sprite.properties |= SP_ALWAYS_ACTIVE;
    current_sprite.y_position_spawn = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x28;
    current_sprite.hitbox_top_offset = -0x4;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    if (alarm_timer != 0x0)
        current_sprite.work_variable = 0x1;
    else
        current_sprite.work_variable = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.timer1 = 0xA;

    if (current_sprite.work_variable || escape_determine_timer() != ESCAPE_NONE)
    {
        current_sprite.oam_pointer = save_platform_oam_2d4df4;
        current_sprite.pose = 0x51;
    }
    else if (is_current_file_existing)
    {
        sprite_spawn_secondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
        current_sprite.oam_pointer = save_platform_oam_2d4dc4;
        current_sprite.pose = 0x28;
        current_sprite.y_position_spawn = 0x154;
    }
    else
    {
        current_sprite.oam_pointer = save_platform_oam_2d4cfc;
        current_sprite.pose = 0x9;
    }

    current_sprite.array_offset = sprite_spawn_secondary(SSPRITE_SAVE_PLATFORM_TOP, 0x3, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position - 0x200, current_sprite.x_position, 0x0);
}

void save_platform_samus_detection(void)
{
    u8 timer;

    if (save_platform_detect_samus() << 0x18 && !sprite_util_check_crouching_or_morphed())
    {
        timer = current_sprite.timer1 = current_sprite.timer1 - 0x1;
        if (timer == 0x0)
        {
            current_sprite.pose = 0x23;
            current_sprite.oam_pointer = save_platform_oam_2d4d34;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
            play_sound1(0x112);
        }
    }
    else
        current_sprite.timer1 = 0xA;
}

void save_platform_check_opening_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x25;
        current_sprite.oam_pointer = save_platform_oam_2d4d54;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

void save_platform_second_samus_detection(void)
{
    u8 colliding;

    colliding = save_platform_detect_samus();
    if (colliding)
    {
        if (!sprite_util_check_crouching_or_morphed())
        {
            current_sprite.pose = 0x42;
            current_sprite.timer1 = 0x4;
            samus_data.x_position = current_sprite.x_position;
            if (samus_data.invincibility_timer != 0x0)
                samus_data.invincibility_timer = 0x0;
            samus_set_pose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            samus_data.speedbooster_timer = 0x1;
            disable_pause = TRUE;
        }
    }
    else
    {
        current_sprite.pose = 0x27;
        current_sprite.oam_pointer = save_platform_oam_2d4dd4;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        play_sound1(0x113);
    }
}

void save_platform_check_closing_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x9;
        current_sprite.oam_pointer = save_platform_oam_2d4cfc;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.timer1 = 0xA;
    }
}

void save_platform_release_samus(void)
{
    if (current_sprite.y_position_spawn != 0x0)
        current_sprite.y_position_spawn--;
    else
    {
        current_sprite.pose = 0x29;
        samus_set_pose(SPOSE_FACING_THE_FOREGROUND);
        disable_pause = FALSE;
    }
}

void save_platform_samus_detection_out(void)
{
    u8 colliding;

    colliding = save_platform_detect_samus();
    if (!colliding)
    {
        current_sprite.pose = 0x27;
        current_sprite.oam_pointer = save_platform_oam_2d4dd4;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        play_sound1(0x113);
    }
}

void save_platform_spawn_sprites(void)
{
    u8 offset;

    if (current_sprite.timer1 != 0x0)
    {
        current_sprite.timer1--;
        if (current_sprite.timer1 == 0x0)
            current_sprite.timer2 = sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x16, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
    else
    {
        offset = current_sprite.timer2;
        if (sprite_data[offset].pose == 0x25)
        {
            if (sprite_data[offset].timer2 == 0x1)
            {
                current_sprite.oam_pointer = save_platform_oam_2d4d8c;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.curr_anim_frame = 0x0;
                current_sprite.pose = 0x43;
                sprite_spawn_secondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
                sprite_data[current_sprite.array_offset].pose = 0x44;
                samus_data.invincibility_timer = 0x0;
                play_sound1(0x114);
            }
            else
            {
                current_sprite.pose = 0x4B;
                current_sprite.timer1 = 0xA;
            }
        }
    }
}

void save_platform_flashing_anim(void)
{
    u8 offset;

    offset = current_sprite.array_offset;
    if (current_sprite.curr_anim_frame & 0x1)
    {
        current_sprite.palette_row = 0x0;
        sprite_data[offset].palette_row = current_sprite.palette_row;
    }
    else
    {
        current_sprite.palette_row = 0x2;
        sprite_data[offset].palette_row = current_sprite.palette_row;
    }
}

void save_platform_flashing_anim_end(void)
{
    current_sprite.oam_pointer = save_platform_oam_2d4dc4;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x47;
    current_sprite.timer1 = 0x3C;
    current_sprite.palette_row = 0x0;
    sprite_data[current_sprite.array_offset].palette_row = 0x0;
}

void save_platform_text_timer(void)
{
    u8 timer;

    timer = current_sprite.timer1 = current_sprite.timer1 - 0x1;
    if (timer == 0x0)
    {
        current_sprite.pose = 0x49;
        current_sprite.timer2 = sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x17, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void save_platform_check_message_banner_out(void)
{
    u8 offset;

    offset = current_sprite.timer2;
    if (sprite_data[offset].pose == 0x25)
    {
        current_sprite.pose = 0x4B;
        current_sprite.timer1 = 0xA;
    }
}

void save_platform_message_banner_disappearing_timer(void)
{
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
        current_sprite.pose = 0x28;
}

void save_platform_top_init(void)
{
    u8 offset;

    offset = current_sprite.primary_sprite_ram_slot;
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.properties |= SP_ALWAYS_ACTIVE;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.hitbox_top_offset = -0x4;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;

    switch (current_sprite.room_slot)
    {
        case 0x0:
            current_sprite.draw_distance_top_offset = 0x50;
            current_sprite.draw_distance_bottom_offset = 0x0;
            current_sprite.draw_distance_horizontal_offset = 0x18;
            if (sprite_data[offset].pose == 0x28)
            {
                current_sprite.oam_pointer = save_platform_top_oam_2d5024;
                current_sprite.y_position_spawn = 0x136;
                current_sprite.pose = 0x25;
            }
            else
            {
                current_sprite.oam_pointer = save_platform_top_oam_2d4e84;
                current_sprite.pose = 0x9;
            }
            break;

        case 0x1:
            current_sprite.draw_order = 0xC;
            current_sprite.oam_pointer = save_platform_top_oam_2d4fbc;
            current_sprite.draw_distance_top_offset = 0x50;
            current_sprite.draw_distance_bottom_offset = 0x0;
            current_sprite.draw_distance_horizontal_offset = 0x18;
            current_sprite.pose = 0x29;
            break;

        case 0x2:
            current_sprite.draw_order = 0x5;
            current_sprite.oam_pointer = save_platform_top_oam_2d50ec;
            current_sprite.draw_distance_top_offset = 0x8;
            current_sprite.draw_distance_bottom_offset = 0x0;
            current_sprite.draw_distance_horizontal_offset = 0x18;
            current_sprite.pose = 0x2B;
            current_sprite.timer1 = 0x60;
            break;

        case 0x3:
            current_sprite.draw_order = 0x3;
            current_sprite.draw_distance_top_offset = 0x20;
            current_sprite.draw_distance_bottom_offset = 0x40;
            current_sprite.draw_distance_horizontal_offset = 0x20;
            current_sprite.pose = 0x43;
            if (sprite_data[offset].pose == 0x28)
                current_sprite.oam_pointer = save_platform_top_oam_2d4e44;
            else
                current_sprite.oam_pointer = save_platform_top_oam_2d4e04;
            break;

        default:
            current_sprite.status = 0x0;
    }
}

void save_platform_top_empty(void)
{
    return;
}

void save_platform_top_extend_gfx_init(void)
{
    current_sprite.oam_pointer = save_platform_top_oam_2d4e14;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x45;
}

void save_platform_top_check_extending_ended(void)
{
    if (sprite_util_check_end_sprite_anim())
    {
        current_sprite.pose = 0x43;
        current_sprite.oam_pointer = save_platform_top_oam_2d4e44;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

void save_platform_top_retract_gfx_init(void)
{
    current_sprite.oam_pointer = save_platform_top_oam_2d4e54;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x47;
    samus_data.speedbooster_timer = 0x1;
    play_sound1(0x115);
}

void save_platform_top_check_retracting_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x43;
        current_sprite.oam_pointer = save_platform_top_oam_2d4e04;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

void save_platform_top_check_tube_anim_spawn_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x23;
        current_sprite.oam_pointer = save_platform_top_oam_2d5024;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.timer2 = sprite_spawn_secondary(SSPRITE_SAVE_PLATFORM_TOP, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void save_platform_top_spawn_big_light(void)
{
    u8 offset;

    offset = current_sprite.timer2;
    if (sprite_data[offset].status == 0x0)
    {
        current_sprite.pose = 0x25;
        current_sprite.y_position_spawn = 0x78;
        sprite_spawn_secondary(SSPRITE_SAVE_PLATFORM_TOP, 0x2, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void save_platform_top_check_tube_anim_ended(void)
{
    current_sprite.y_position_spawn--;
    if (current_sprite.y_position_spawn == 0x0)
    {
        current_sprite.pose = 0x27;
        current_sprite.oam_pointer = save_platform_top_oam_2d5064;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

void save_platform_top_check_tube_anim_despawn_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.status = 0x0;
        sprite_data[sprite_data[current_sprite.primary_sprite_ram_slot].array_offset].pose = 0x46;
    }
}

void save_platform_top_check_tube_around_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
        current_sprite.status = 0x0;
}

void save_platform_top_tube_down_up_anim(void)
{
    current_sprite.y_position -= 0x4;
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        sprite_data[current_sprite.primary_sprite_ram_slot].pose = 0x45;
        current_sprite.status = 0x0;
    }
}

void save_platform(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            save_platform_init();
            break;
        case 0x9:
            save_platform_samus_detection();
            break;
        case 0x23:
            save_platform_check_opening_anim_ended();
            break;
        case 0x25:
            save_platform_second_samus_detection();
            break;
        case 0x27:
            save_platform_check_closing_anim_ended();
            break;
        case 0x28:
            save_platform_release_samus();
            break;
        case 0x29:
            save_platform_samus_detection_out();
            break;
        case 0x42:
            save_platform_spawn_sprites();
            break;
        case 0x43:
            save_platform_flashing_anim();
            break;
        case 0x45:
            save_platform_flashing_anim_end();
            break;
        case 0x47:
            save_platform_text_timer();
            break;
        case 0x49:
            save_platform_check_message_banner_out();
            break;
        case 0x4B:
            save_platform_message_banner_disappearing_timer();
    }
}

void save_platform_top(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            save_platform_top_init();
            break;
        case 0x9:
            save_platform_top_check_tube_anim_spawn_ended();
            break;
        case 0x23:
            save_platform_top_spawn_big_light();
            break;
        case 0x25:
            save_platform_top_check_tube_anim_ended();
            break;
        case 0x27:
            save_platform_top_check_tube_anim_despawn_ended();
            break;
        case 0x29:
            save_platform_top_check_tube_around_anim_ended();
            break;
        case 0x2B:
            save_platform_top_tube_down_up_anim();
            break;
        case 0x43:
            save_platform_top_empty();
            break;
        case 0x44:
            save_platform_top_extend_gfx_init();
            break;
        case 0x45:
            save_platform_top_check_extending_ended();
            break;
        case 0x46:
            save_platform_top_retract_gfx_init();
            break;
        case 0x47:
            save_platform_top_check_retracting_ended();
    }
}