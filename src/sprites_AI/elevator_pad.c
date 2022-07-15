#include "ElevatorPad.h"
#include "../samus.h"
#include "../globals.h"

void ElevatorPad(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.y_position -= 0x8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.draw_distance_top_offset = 0x1;
        gCurrentSprite.draw_distance_bottom_offset = 0x8;
        gCurrentSprite.draw_distance_horizontal_offset = 0x10;
        gCurrentSprite.hitbox_top_offset = -0x4;
        gCurrentSprite.hitbox_bottom_offset = 0x4;
        gCurrentSprite.hitbox_left_offset = -0x4;
        gCurrentSprite.hitbox_right_offset = -0x4;
        gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fe8;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }

    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        gCurrentSprite.y_position = gSamusData.y_position;
        gCurrentSprite.x_position = gSamusData.x_position;
        if (gCurrentSprite.oam_pointer == elevator_pad_oam_2e0fe8)
        {
            gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fc0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.oam_pointer == elevator_pad_oam_2e0fc0)
        {
            gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fe8;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
        }
    }
}