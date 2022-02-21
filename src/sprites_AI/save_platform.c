#include "save_platform.h"
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
        current_sprite.timer2 = sprite_util_spawn_primary(PSPRITE_ITEM_BANNER, 0x17, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
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

}

void save_platform_top_empty(void)
{
    return;
}

void save_platform_top_extend_gfx_init(void)
{

}

void save_platform_top_check_extending_ended(void)
{

}

void save_platform_top_retract_gfx_init(void)
{

}

void save_platform_top_check_retracting_ended(void)
{

}

void save_platform_top_check_tube_anim_spawn_ended(void)
{

}

void save_platform_top_spawn_big_light(void)
{

}

void save_platform_top_check_tube_anim_ended(void)
{

}

void save_platform_top_check_tubeanim_despawn_ended(void)
{

}

void save_platform_top_check_tube_around_anim_ended(void)
{

}

void save_platform_top_tube_down_up_anim(void)
{

}

void save_platform(void)
{

}

void save_platform_top(void)
{

}