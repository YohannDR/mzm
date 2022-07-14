#include "unused_sprites.h"
#include "../../data/data.h"
#include "../globals.h"

void unused_sprites(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x1;
        gCurrentSprite.draw_distance_top_offset = 0x8;
        gCurrentSprite.draw_distance_bottom_offset = 0x8;
        gCurrentSprite.draw_distance_horizontal_offset = 0x8;
        gCurrentSprite.hitbox_top_offset = -0x10;
        gCurrentSprite.hitbox_bottom_offset = 0x10;
        gCurrentSprite.hitbox_left_offset = -0x10;
        gCurrentSprite.hitbox_right_offset = 0x10;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = unused_sprites_oam;
        gCurrentSprite.bg_priority = 0x1;
    }
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
}