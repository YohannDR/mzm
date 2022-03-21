#include "geron_norfair.h"
#include "../clipdata.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 40178 | b8 | Geron Norfair AI
 * 
 */
void geron_norfair(void)
{
    u8 caa;
    u16 y_position;
    u16 x_position;

    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            current_sprite.status = 0x0;
        else
        {
            current_sprite.draw_distance_top_offset = 0x30;
            current_sprite.draw_distance_bottom_offset = 0x0;
            current_sprite.draw_distance_horizontal_offset = 0x14;
            current_sprite.hitbox_top_offset = -0xC0;
            current_sprite.hitbox_bottom_offset = 0x0;
            current_sprite.hitbox_left_offset = -0x30;
            current_sprite.hitbox_right_offset = 0x30;
            current_sprite.draw_order = 0x5;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.pose = 0x9;
            current_sprite.health = 0x1;
            current_sprite.oam_pointer = geron_norfair_oam;
            y_position = current_sprite.y_position - 0x20;
            x_position = current_sprite.x_position;
            caa = CCAA_MAKE_SOLID;
            current_clipdata_affecting_action = caa;
            clipdata_related(y_position, x_position);
            current_clipdata_affecting_action = caa;
            clipdata_related(y_position - 0x40, x_position);
            current_clipdata_affecting_action = caa;
            clipdata_related(y_position - 0x80, x_position);
        }
    }
}