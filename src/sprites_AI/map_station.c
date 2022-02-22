#include "map_station.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

void map_station_init(void)
{
    current_sprite.y_position += 0x80;
    current_sprite.draw_distance_top_offset = 0x80;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x1C;
    current_sprite.hitbox_top_offset = -0x200;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_order = 0x4;
    current_sprite.bg_priority = 0x1;
    current_sprite.health = 0x1;
    current_sprite.properties |= SP_SOLID_FOR_PROJECTILES;

    if ((equipment.downloaded_map_status >> current_area) & 0x1 || alarm_timer != 0x0)
    {
        current_sprite.hitbox_bottom_offset = -0x40;
        current_sprite.pose = 0xF;
        current_sprite.oam_pointer = map_station_oam_2d3788;
        current_sprite.curr_anim_frame = 0x13;
        current_sprite.anim_duration_counter = 0x0;
    }
    else
    {
        current_sprite.hitbox_bottom_offset = 0x40;
        current_sprite.pose = 0x9;
        current_sprite.oam_pointer = map_station_oam_2d36f8;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void map_station_samus_detection(void)
{
    i32 samus_y;
    i32 samus_x;
    u16 sprite_y;
    u16 sprite_x;

    samus_y = samus_data.y_position;
    samus_x = samus_data.x_position;
    sprite_y = (u16)(current_sprite.y_position + 0x80);
    sprite_x = (u16)(current_sprite.x_position + 0x60);

    if (!sprite_util_check_crouching_or_morphed() && samus_y == sprite_y - 0x1 && sprite_x - 0x40 < samus_x && sprite_x + 0x40 > samus_x)
    {
        current_sprite.oam_pointer = map_station_oam_2d3708;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.pose = 0x23;
        samus_data.x_position = sprite_x;
        if (samus_data.invincibility_timer != 0x0)
            samus_data.invincibility_timer = 0x0;

        if (samus_data.direction & DIRECTION_RIGHT)
            samus_set_pose(SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA);
        else
            samus_set_pose(SPOSE_DOWNLOADING_MAP_DATA);
        play_sound1(0x123);
    }
}

void map_station_check_samus_grabbed_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.oam_pointer = map_station_oam_2d3758;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.pose = 0x25;
        current_sprite.timer1 = 0x46;
        samus_data.speedbooster_timer = 0x0;
    }
}

void map_station_downloading_anim(void)
{
    u32 timer;

    timer = current_sprite.timer1 - 0x1;
    current_sprite.timer1 = timer;
    if ((u8)timer == 0x0)
    {
        current_sprite.oam_pointer = map_station_oam_2d3778;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.pose = 0x27;
        current_sprite.timer1 = 0xA;
    }
    else if (timer == 0xA)
        pause_screen_flag = 0x5;
}

void map_station_spawn_message(void)
{
    u8 room_slot;

    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        switch (current_area)
        {
            case AREA_BRINSTAR:
                room_slot = 0x1B;
                break;
            case AREA_KRAID:
                room_slot = 0x1C;
                break;
            case AREA_NORFAIR:
                room_slot = 0x1D;
                break;
            case AREA_RIDLEY:
                room_slot = 0x1E;
                break;
            case AREA_CHOZODIA:
                room_slot = 0x1F;
                break;
            default:
                room_slot = 0x23;
        }

        current_sprite.timer2 = sprite_spawn_primary(PSPRITE_ITEM_BANNER, room_slot, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
        current_sprite.hitbox_top_offset = -0x40;
        current_sprite.pose = 0x29;
        samus_data.curr_anim_frame = 0x0;
        samus_data.speedbooster_timer = 0x1;
        call_sound_function(0x123, 0xA);
    }
}

void map_station_after_download(void)
{
    u8 slot;

    slot = current_sprite.timer2;
    if (sprite_data[slot].pose == 0x25)
    {
        current_sprite.pose = 0x2B;
        current_sprite.timer1 = 0xA;
    }
}

void map_station_before_retraction(void)
{
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
        current_sprite.pose = 0x2D;
}

void map_station_retraction(void)
{
    current_sprite.pose = 0x2F;
    current_sprite.oam_pointer = map_station_oam_2d3788;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    samus_set_pose(SPOSE_STANDING);
    play_sound1(0x124);
}

void map_station(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            map_station_init();
            break;
        case 0x9:
            map_station_samus_detection();
            break;
        case 0x23:
            map_station_check_samus_grabbed_anim_ended();
            break;
        case 0x25:
            map_station_downloading_anim();
            break;
        case 0x27:
            map_station_spawn_message();
            break;
        case 0x29:
            map_station_after_download();
            break;
        case 0x2B:
            map_station_before_retraction();
            break;
        case 0x2D:
            map_station_retraction();
    }
}

void map_station_screen(void)
{

}