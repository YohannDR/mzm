#include "ripper2.h"
#include "../sprite_util.h"
#include "../globals.h"

void ripper2_init(void)
{
    current_sprite.hitbox_top_offset = -0x24;
    current_sprite.hitbox_bottom_offset = 0x8;
    current_sprite.hitbox_left_offset = -0x28;
    current_sprite.hitbox_right_offset = 0x28;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x28;
    current_sprite.oam_pointer = ripper2_oam_2cc458;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.y_position -= 0x8;
    sprite_util_choose_random_x_flip();
    current_sprite.pose = 0x8;
}

void ripper2_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = ripper2_oam_2cc458;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
}

void ripper2_move(void)
{
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
    {
        sprite_util_check_collision_at_position(current_sprite.y_position - 0x10, current_sprite.x_position + 0x2C);
        if (previous_collision_check != 0x11)
            current_sprite.x_position += 0x8;
        else
            current_sprite.pose = 0xA;
    }
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position - 0x10, current_sprite.x_position - 0x2C);
        if (previous_collision_check == 0x11)
            current_sprite.pose = 0xA;
        else
            current_sprite.x_position -= 0x8;
    }
}

void ripper2_turn_around_gfx_init(void)
{
    current_sprite.pose = 0xB;
    current_sprite.oam_pointer = ripper2_oam_2cc480;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x267);
}

void ripper2_turn_around_begin(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.status ^= SPRITE_STATUS_XFLIP;
        current_sprite.pose = 0xC;
        current_sprite.oam_pointer = ripper2_oam_2cc498;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }
}

void ripper2_check_turned_around(void)
{
    if (sprite_util_check_near_end_current_sprite_anim())
        current_sprite.pose = 0x8;
}

void ripper2(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x268);
    }

    if (current_sprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (current_sprite.pose)
            {
                case 0x0:
                    ripper2_init();
                    break;
                case 0x8:
                    ripper2_gfx_init();
                case 0x9:
                    ripper2_move();
                    break;
                case 0xA:
                    ripper2_turn_around_gfx_init();
                case 0xB:
                    ripper2_turn_around_begin();
                    break;
                case 0xC:
                    ripper2_check_turned_around();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position - 0x18, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}