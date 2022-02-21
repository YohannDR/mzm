#include "map_station.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

void map_station_init(void)
{

}

void map_station_samus_detection(void)
{

}

void map_station_check_samus_grabbed_anim_ended(void)
{

}

void map_station_downloading_anim(void)
{

}

void map_station_spawn_message(void)
{

}

void map_station_after_download(void)
{

}

void map_station_before_retraction(void)
{
    if ((current_sprite.timer1 - 0x1) == 0x0)
        current_sprite.pose = 0x2D;
    current_sprite.timer1--;
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