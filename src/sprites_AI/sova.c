#include "sova.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 sova_check_colliding_with_air(void)
{

}

void sova_hitbox_update(void)
{
    if (current_sprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
        {
            current_sprite.hitbox_top_offset = -0x1C;
            current_sprite.hitbox_bottom_offset = 0x1C;
            current_sprite.hitbox_left_offset = -0x34;
            current_sprite.hitbox_right_offset = 0x4;
        }
        else
        {
            current_sprite.hitbox_top_offset = -0x1C;
            current_sprite.hitbox_bottom_offset = 0x1C;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x34;
        }
    }
    else
    {
        if (current_sprite.maybe_variable != 0x0)
        {
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x34;
        }
        else
        {
            current_sprite.hitbox_top_offset = -0x34;
            current_sprite.hitbox_bottom_offset = 0x4;
        }
        current_sprite.hitbox_left_offset = -0x1C;
        current_sprite.hitbox_right_offset = 0x1C;
    }
}

void sova_gfx_update(void)
{

}

void sova_init(void)
{
    current_sprite.maybe_variable = 0x0;
    current_sprite.pose = 0x9;
    sprite_util_choose_random_x_direction();
    sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position);
    if (previous_collision_check & 0xF0)
        current_sprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position - 0x44, current_sprite.x_position);
        if (previous_collision_check & 0xF0)
        {
            current_sprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            current_sprite.y_position -= 0x40;
            current_sprite.maybe_variable = 0x1;
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position - 0x24);
            if (previous_collision_check & 0xF0)
            {
                current_sprite.status |= SPRITE_STATUS_UNKNOWN2;
                current_sprite.y_position -= 0x20;
                current_sprite.x_position -= 0x20;
            }
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position + 0x20);
                if ((previous_collision_check & 0xF0) == 0x0)
                {
                    current_sprite.status = previous_collision_check & 0xF0;
                    return;
                }
                else
                {
                    current_sprite.status |= SPRITE_STATUS_UNKNOWN2;
                    current_sprite.status |= SPRITE_STATUS_XFLIP;                    
                    current_sprite.y_position -= 0x20;
                    current_sprite.x_position += 0x20;
                }
            }
        }
    }

    if (!(current_sprite.status & SPRITE_STATUS_UNKNOWN2))
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            current_sprite.status |= SPRITE_STATUS_XFLIP;
        else
            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    sova_gfx_update();
    sova_hitbox_update();
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id].spawn_health;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    if (current_sprite.sprite_id == PSPRITE_SOVA_ORANGE)
    {
        current_sprite.maybe_absolute_palette_row = 0x1;
        current_sprite.palette_row = 0x1;
    }
}

void sova_gfx_init(void)
{
    sova_gfx_update();
    current_sprite.pose = 0x9;
}

void sova_move(void)
{

}

void sova_turning_around_gfx_update(void)
{

}

void sova_turning_around(void)
{

}

void sova_back_on_ground(void)
{
    current_sprite.pose = 0xF;
    current_sprite.oam_pointer = sova_oam_falling_2cfd68;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    sprite_util_choose_random_x_flip();
    if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
        current_sprite.status |= SPRITE_STATUS_XFLIP;
    else
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
}

void sova_check_back_on_ground_anim_ended(void)
{
    if (sova_check_colliding_with_air() << 0x18 != 0x0)
        current_sprite.pose = 0x1E;
    else
    {
        if (sprite_util_check_near_end_current_sprite_anim())
            current_sprite.pose = 0x8;
    }
}

void sova_start_falling(void)
{
    if (current_sprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
            current_sprite.x_position -= 0x20;
        else
            current_sprite.x_position += 0x20;
    }
    else if (current_sprite.maybe_variable != 0x0)
        current_sprite.y_position += 0x28;

    current_sprite.pose = 0x1F;
    current_sprite.array_offset = 0x0;
    current_sprite.maybe_variable = 0x0;
    current_sprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_UNKNOWN2);
    sova_hitbox_update();
    current_sprite.oam_pointer = sova_oam_falling_2cfd68;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void sova_falling(void)
{

}

void sova_death(void)
{
    u16 y_position;
    u16 x_position;

    y_position = current_sprite.y_position;
    x_position = current_sprite.x_position;

    if (current_sprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
            x_position -= 0x28;
        else
            x_position += 0x28;
    }
    else
    {
        if (current_sprite.maybe_variable != 0x0)
            y_position += 0x28;
        else
            y_position -= 0x28;
    }

    sprite_util_sprite_death(DEATH_NORMAL, y_position, x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void sova(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= 0xFD;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x154);
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
                    sova_init();
                    break;
                case 0x8:
                    sova_gfx_init();
                case 0x9:
                    sova_move();
                    break;
                case 0xA:
                    sova_turning_around_gfx_update();
                case 0xB:
                    sova_turning_around();
                    break;
                case 0xE:
                    sova_back_on_ground();
                case 0xF:
                    sova_check_back_on_ground_anim_ended();
                    break;
                case 0x1E:
                    sova_start_falling();
                case 0x1F:
                    sova_falling();
                    break;
                default:
                    sova_death();
            }
        }
    }
}