#include "sprites_AI/unused_sprites.h"
#include "globals.h"

void unused_sprites(void)
{
    if (current_sprite.pose == 0x0)
    {
        current_sprite.pose = 0x1;
        current_sprite.draw_distance_top_offset = 0x8;
        current_sprite.draw_distance_bottom_offset = 0x8;
        current_sprite.draw_distance_horizontal_offset = 0x8;
        current_sprite.hitbox_top_offset = -0x10;
        current_sprite.hitbox_bottom_offset = 0x10;
        current_sprite.hitbox_left_offset = -0x10;
        current_sprite.hitbox_right_offset = 0x10;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = unused_sprites_oam_data;
        current_sprite.bg_priority = 0x1;
    }
    current_sprite.ignore_samus_collision_timer = 0x1;
}