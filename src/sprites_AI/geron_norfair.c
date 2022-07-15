#include "GeronNorfair.h"
#include "../clipdata.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 40178 | b8 | Geron Norfair AI
 * 
 */
void GeronNorfair(void)
{
    u8 caa;
    u16 y_position;
    u16 x_position;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.draw_distance_top_offset = 0x30;
            gCurrentSprite.draw_distance_bottom_offset = 0x0;
            gCurrentSprite.draw_distance_horizontal_offset = 0x14;
            gCurrentSprite.hitbox_top_offset = -0xC0;
            gCurrentSprite.hitbox_bottom_offset = 0x0;
            gCurrentSprite.hitbox_left_offset = -0x30;
            gCurrentSprite.hitbox_right_offset = 0x30;
            gCurrentSprite.draw_order = 0x5;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.oam_pointer = GeronNorfair_oam;
            y_position = gCurrentSprite.y_position - 0x20;
            x_position = gCurrentSprite.x_position;
            caa = CCAA_MAKE_SOLID3
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(y_position, x_position);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(y_position - 0x40, x_position);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(y_position - 0x80, x_position);
        }
    }
}