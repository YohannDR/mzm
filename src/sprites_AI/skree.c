#include "skree.h"
#include "../sprite_debris.h"
#include "../sprite_util.h"
#include "../globals.h"

void skree_init(void)
{
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.draw_distance_top_offset = 0x0;
    current_sprite.draw_distance_bottom_offset = 0x20;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_top_offset = 0x0;
    current_sprite.hitbox_bottom_offset = 0x60;
    current_sprite.hitbox_left_offset = -0x18;
    current_sprite.hitbox_right_offset = 0x18;
    current_sprite.health = primary_sprites_stats[current_sprite.sprite_id].spawn_health;
    current_sprite.y_position -= 0x40;
}

void skree_gfx_init(void)
{
    current_sprite.oam_pointer = skree_oam_2cd474;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x9;
}

void skree_detect_samus(void)
{
    if (samus_data.y_position > current_sprite.y_position && samus_data.y_position - current_sprite.y_position < 0x284 && (current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0 && samus_data.x_position > current_sprite.x_position - 0x96 && samus_data.x_position < current_sprite.x_position + 0x96)
        current_sprite.pose = 0x22;
}

void skree_spin_gfx_init(void)
{
    current_sprite.oam_pointer = skree_oam_spinning_2cd49c;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x23;
}

void skree_check_spin_ended(void)
{
    if (sprite_util_check_near_end_current_sprite_anim())
        current_sprite.pose = 0x34;
}

void skree_start_going_down(void)
{
    current_sprite.oam_pointer = skree_going_down_2cd4cc;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.array_offset = 0x0;
    current_sprite.work_variable = 0x0;
    current_sprite.pose = 0x35;

    if (current_sprite.x_position > samus_data.x_position)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
        play_sound1(0x141);
}

void skree_go_down(void)
{
    u32 block;
    u32 x_movement;
    u32 y_movement;
    u32 array_offset;

    block = sprite_util_check_vertical_collision_at_position_slopes(current_sprite.hitbox_bottom_offset + current_sprite.y_position, current_sprite.x_position);
    if (previous_vertical_collision_check != 0x0)
    {
        current_sprite.y_position = block - current_sprite.hitbox_bottom_offset;
        current_sprite.pose = 0x37;
        current_sprite.timer1 = 0x0;
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            play_sound1(0x142);
    }
    else
    {
        x_movement = current_sprite.work_variable >> 0x2;
        array_offset = current_sprite.array_offset;
        y_movement = skree_falling_speed_2cca7c[array_offset];
        if (y_movement == 0x7FFF)
        {
            y_movement = skree_falling_speed_2cca7c[array_offset - 0x1];
            current_sprite.y_position += y_movement;
        }
        else
        {
            current_sprite.array_offset++;
            current_sprite.y_position += y_movement;
        }

        if ((current_sprite.status & SPRITE_STATUS_FACING_RIGHT) != 0x0)
        {
            sprite_util_check_collision_at_position(current_sprite.y_position + 0x40, current_sprite.x_position + 0x20);
            if (previous_collision_check == 0x11)
                return;
            current_sprite.x_position += x_movement;
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position + 0x40, current_sprite.x_position - 0x20);
            if (previous_collision_check == 0x11)
                return;
            current_sprite.x_position -= x_movement;
        }

        if (x_movement < 0x10)
            current_sprite.work_variable++;
    }
}

void skree_crash_ground(void)
{
    u16 y_position;
    u16 x_position;
    u8 gfx_slot;
    u8 ram_slot;
    enum s_sprite_id sprite_id;

    y_position = current_sprite.y_position;
    x_position = current_sprite.x_position;

    current_sprite.timer1++;

    switch (current_sprite.timer1)
    {
        case 0x1:
            y_position += 0x48;
            sprite_debris_init(0x0, 0x11, y_position - 0x10, x_position);
            sprite_debris_init(0x0, 0x12, y_position, x_position + 0xC);
            sprite_debris_init(0x0, 0x13, y_position - 0x2A, x_position + 0x14);
            sprite_debris_init(0x0, 0x4, y_position - 0x18, x_position - 0x1E);
            break;

        case 0x28:
            current_sprite.oam_pointer = skree_oam_crashing_2cd4f4;
            break;

        case 0x3C:
            gfx_slot = current_sprite.spriteset_gfx_slot;
            ram_slot = current_sprite.primary_sprite_ram_slot;

            if (current_sprite.sprite_id == PSPRITE_SKREE_BLUE)
                sprite_id = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                sprite_id = SSPRITE_SKREE_EXPLOSION;
            
            sprite_spawn_secondary(sprite_id, 0x0, gfx_slot, ram_slot, y_position - 0x8, x_position, 0x0);
            sprite_spawn_secondary(sprite_id, 0x0, gfx_slot, ram_slot, y_position - 0x8, x_position, SPRITE_STATUS_XFLIP);
            sprite_spawn_secondary(sprite_id, 0x1, gfx_slot, ram_slot, y_position + 0x8, x_position - 0xC, 0x0);
            sprite_spawn_secondary(sprite_id, 0x1, gfx_slot, ram_slot, y_position + 0x8, x_position + 0xC, SPRITE_STATUS_XFLIP);
            current_sprite.status = 0x0;
            particle_set(y_position + 0x24, x_position, PE_SPRITE_EXPLOSION_HUGE);
            play_sound1(0x134);
    }
}

void skree_explosion_init(void)
{
    enum sprite_status status;

    status = current_sprite.status & ~SPRITE_STATUS_NOT_DRAWN | (SPRITE_STATUS_UNKNOWN3 | SPRITE_STATUS_NONE);
    current_sprite.properties |= SP_PROJECTILE;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_top_offset = -0xC;
    current_sprite.hitbox_bottom_offset = 0xC;
    current_sprite.hitbox_left_offset = -0xC;
    current_sprite.hitbox_right_offset = 0xC;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x9;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.draw_order = 0x3;
    current_sprite.bg_priority = io_registers_backup.bg2cnt & 0x3;
    current_sprite.y_position += 0x28;
    current_sprite.status = (status | SPRITE_STATUS_UNKNOWN4 | SPRITE_STATUS_ROTATION_SCALING);
    current_sprite.oam_scaling = 0x100;
    current_sprite.oam_rotation = 0x0;

    if (current_sprite.room_slot != 0x0)
        current_sprite.oam_pointer = skree_explosion_oam_going_down_2cd5c4;
    else
        current_sprite.oam_pointer = skree_explosion_oam_going_up_2cd5e4;
}

void skree_explosion_move(void)
{
    if (current_sprite.curr_anim_frame > 0x1)
        current_sprite.ignore_samus_collision_timer = 0x1;

    if ((current_sprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        current_sprite.x_position += 0x8;
        current_sprite.oam_rotation += 0x20;
    }
    else
    {
        current_sprite.x_position -= 0x8;
        current_sprite.oam_rotation -= 0x20;
    }

    if (current_sprite.room_slot != 0x0)
        current_sprite.y_position += 0x4;
    else
        current_sprite.y_position -= 0x4;

    if (sprite_util_check_end_current_sprite_anim())
        current_sprite.status = 0x0;
}

void skree(void)
{
    if ((current_sprite.properties & SP_UNKNOWN) != 0x0)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x143);
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
                    skree_init();
                case 0x8:
                    skree_gfx_init();
                case 0x9:
                    skree_detect_samus();
                    break;
                case 0x22:
                    skree_spin_gfx_init();
                case 0x23:
                    skree_check_spin_ended();
                    break;
                case 0x34:
                    skree_start_going_down();
                case 0x35:
                    skree_go_down();
                    break;
                case 0x37:
                    skree_crash_ground();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position + 0x34, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}

void skree_explosion(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            skree_explosion_init();

        case 0x9:
            skree_explosion_move();
    }
}