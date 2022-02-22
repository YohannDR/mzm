#include "dragon.h"
#include "../sprite_util.h"
#include "../globals.h"

void dragon_y_movement(void)
{
    u16 old_y;
    u16 y_spawn;

    old_y = current_sprite.y_position;
    y_spawn = current_sprite.y_position_spawn;

    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if ((i32)(y_spawn - 0x7F) < current_sprite.y_position)
            current_sprite.y_position -= 0x2;
        sprite_util_check_out_of_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_SMALL);
    }
    else
    {
        if ((i32)(y_spawn - 0x2) > current_sprite.y_position)
            current_sprite.y_position += 0x2;
        sprite_util_check_in_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_SMALL);
    }
}

void dragon_init(void)
{
    current_sprite.hitbox_top_offset = -0x40;
    current_sprite.hitbox_bottom_offset = 0x50;
    current_sprite.hitbox_left_offset = -0x18;
    current_sprite.hitbox_right_offset = 0x18;
    current_sprite.draw_distance_top_offset = 0x18;
    current_sprite.draw_distance_bottom_offset = 0x18;
    current_sprite.draw_distance_horizontal_offset = 0x18;
    current_sprite.oam_pointer = dragon_oam_2d5ad8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    sprite_util_make_sprite_face_samus_x_flip();
    current_sprite.pose = 0x8;
    current_sprite.y_position_spawn = current_sprite.y_position;
}

void dragon_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = dragon_oam_2d5ad8;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.timer1 = 0x64;
}

void dragon_go_up(void)
{
    /*enum near_sprite_left_right nslr;
    u16 x_position;
    u16 y_position;

    if (current_sprite.timer1 != 0x0)
        current_sprite.timer1--;

    dragon_y_movement();
    current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    if (samus_data.y_position <= current_sprite.y_position)
    {
        nslr = sprite_util_check_samus_near_sprite_left_right(0x180, 0x180);
        if (nslr != NSLR_OUT_OF_RANGE)
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
        
        if (nslr == NSLR_RIGHT)
        {
            if (current_sprite.status & SPRITE_STATUS_XFLIP)
            {
                if (current_sprite.timer1 == 0x0)
                {
                    y_position = current_sprite.y_position - 0x88;
                    x_position = current_sprite.x_position + 0x48;
                    sprite_util_check_collision_at_position(y_position, x_position);
                    if (previous_collision_check == 0x0)
                        current_sprite.pose = 0x34;
                }
            }
        }
        else if (nslr == NSLR_LEFT)
        {
            if (current_sprite.status & SPRITE_STATUS_XFLIP)
                current_sprite.pose = 0xA;
            else
            {
                if (current_sprite.timer1 == 0x0)
                {
                    y_position = current_sprite.y_position - 0x88;
                    x_position = current_sprite.x_position - 0x48;
                    sprite_util_check_collision_at_position(y_position, x_position);
                    if (previous_collision_check == 0x0)
                        current_sprite.pose = 0x34;
                }
            }
        }
    }*/
}

void dragon_turning_turning_around_gfx_init(void)
{
    current_sprite.pose = 0xB;
    current_sprite.oam_pointer = dragon_oam_2d5b28;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
}

void dragon_check_turning_around_first_half_anim_ended(void)
{
    dragon_y_movement();
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0xC;
        current_sprite.oam_pointer = dragon_oam_2d5b40;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.status ^= SPRITE_STATUS_XFLIP;
    }
}

void dragon_check_turning_around_second_half_anim_ended(void)
{
    dragon_y_movement();
    if (sprite_util_check_end_current_sprite_anim())
        current_sprite.pose = 0x34;
}

void dragon_spitting_gfx_init(void)
{
    current_sprite.pose = 0x35;
    current_sprite.oam_pointer = dragon_oam_2d5af8;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.timer1 = 0x1E;
}

void dragon_spitting_anim(void)
{
    dragon_y_movement();
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        current_sprite.pose = 0x37;
        current_sprite.oam_pointer = dragon_oam_2d5b10;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.timer1 = 0x8;
    }
}

void dragon_spawn_fireball(void)
{
    u16 y_position;
    u16 x_position;

    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        dragon_gfx_init();
        y_position = current_sprite.y_position - 0x48;
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
            x_position = current_sprite.x_position + 0x28;
        else
            x_position = current_sprite.x_position - 0x28;
        sprite_spawn_secondary(SSPRITE_DRAGON_FIREBALL, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position, x_position, current_sprite.status & SPRITE_STATUS_XFLIP);
    }
}

void dragon_fireball_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.properties |= SP_PROJECTILE;
    current_sprite.draw_distance_top_offset = 0x8;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.hitbox_top_offset = -0x10;
    current_sprite.hitbox_bottom_offset = 0x10;
    current_sprite.hitbox_left_offset = -0x10;
    current_sprite.hitbox_right_offset = 0x10;
    current_sprite.oam_pointer = dragon_fireball_oam_2d5b58;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x9;
    current_sprite.samus_collision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    current_sprite.draw_order = 0x3;
    current_sprite.bg_priority = io_registers_backup.bg2cnt & 0x3;
    current_sprite.health = secondary_sprite_stats_2b1be4[current_sprite.sprite_id][0x0];
    
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
    {
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
        current_sprite.oam_rotation = 0x40;
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
        current_sprite.oam_rotation = 0x0;

    current_sprite.status |= SPRITE_STATUS_YFLIP;
    current_sprite.oam_scaling = 0x100;
    current_sprite.array_offset = 0x0;
    play_sound1(0x14C);
}

void dragon_fireball_move(void)
{
    /*u16 x_speed;
    u16 old_y;
    u8 offset;
    i16 movement;
    i16 rotation;

    x_speed = 0xC;
    old_y = current_sprite.y_position;
    offset = current_sprite.array_offset;
    movement = dragon_array_2d5134[offset];
    rotation = dragon_array_2d5184[offset];
    if (movement == 0x7FFF)
    {
        movement = dragon_array_2d5134[offset - 0x1];
        rotation = dragon_array_2d5184[offset - 0x1];
        current_sprite.y_position += movement;
    }
    else
    {
        current_sprite.array_offset = offset + 0x1;
        current_sprite.y_position += movement;
    }

    if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        current_sprite.x_position += x_speed;
        current_sprite.oam_rotation = rotation + 0x40;
    }
    else
    {
        current_sprite.x_position -= x_speed;
        current_sprite.oam_rotation = -rotation;
    }

    if (sprite_util_check_in_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_NONE))
        current_sprite.pose = 0x42;
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position);
        if (previous_collision_check & 0xF0)
            current_sprite.pose = 0x42;
    }*/
}

void dragon_fireball_exploding_gfx_init(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.oam_pointer = dragon_fireball_oam_2d5b78;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x43;
    current_sprite.status = (current_sprite.status & ~SPRITE_STATUS_YFLIP);
    current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
}

void dragon_fireball_check_exploding_anim_ended(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (sprite_util_check_end_current_sprite_anim())
        current_sprite.status = 0x0;
}

void dragon_void(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x14D);
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
                    dragon_init();
                    break;
                case 0x8:
                    ddragon_gfx_init();
                case 0x9:
                    dragon_go_up();
                    break;
                case 0xA:
                    dragon_turning_turning_around_gfx_init();
                case 0xB:
                    dragon_check_turning_around_first_half_anim_ended();
                    break;
                case 0xC:
                    dragon_check_turning_around_second_half_anim_ended();
                    break;
                case 0x34:
                    dragon_spitting_gfx_init();
                case 0x35:
                    dragon_spitting_anim();
                    break;
                case 0x37:
                    dragon_spawn_fireball();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}

void dragon_fireball(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            dragon_fireball_init();
        case 0x9:
            dragon_fireball_move();
            break;
        case 0x42:
            dragon_fireball_exploding_gfx_init();
            break;
        case 0x43:
            dragon_fireball_check_exploding_anim_ended();
            break;
        default:
            sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}