#include "hive.h"
#include "../globals.h"
#include "../particle.h"
#include "../event.h"
#include "../sprite_util.h"

void hive_spawn_particle(void)
{
    u16 x_pos;
    u16 y_pos;

    x_pos = current_sprite.x_position;
    y_pos = current_sprite.y_position;

    particle_set(current_sprite.y_position - 0x20, current_sprite.x_position, PE_MEDIUM_DUST);
    particle_set(y_pos + 0x60, x_pos, PE_TWO_MEDIUM_DUST);
}

void hive_init(void)
{
    u32 event_check;
    u8 room_slot;
    u8 gfx_slot;
    u16 y_position;
    u16 x_position;

    event_check = event_function(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED);
    if (event_check != 0x0)
        current_sprite.status = 0x0;
    else
    {
        current_sprite.draw_distance_top_offset = 0x28;
        current_sprite.draw_distance_bottom_offset = 0x28;
        current_sprite.draw_distance_horizontal_offset = 0x14;
        current_sprite.hitbox_top_offset = -0x80;
        current_sprite.hitbox_bottom_offset = 0x80;
        current_sprite.hitbox_left_offset = -0x30;
        current_sprite.hitbox_right_offset = 0x30;
        current_sprite.samus_collision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        current_sprite.frozen_palette_row_offset = 0x1;
        current_sprite.oam_pointer = hive_oam;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = event_check;
        current_sprite.draw_order = 0x5;
        current_sprite.health = primary_sprite_stats[current_sprite.sprite_id].spawn_health;
        current_sprite.pose = 0x9;
        current_sprite.timer1 = 0x0;
        
        y_position = current_sprite.y_position;
        x_position = current_sprite.x_position;
        gfx_slot = current_sprite.spriteset_gfx_slot;
        room_slot = current_sprite.room_slot;
        
        sprite_spawn_secondary(SSPRITE_HIVE_ROOTS, room_slot, gfx_slot, current_sprite.primary_sprite_ram_slot, y_position, x_position, 0x0);
        sprite_spawn_primary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position + 0x40, x_position - 0x1F, 0x0);
        sprite_spawn_primary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position + 0x20, x_position + 0x10, 0x0);
        sprite_spawn_primary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position - 0x48, x_position - 0x10, 0x0);
        sprite_spawn_primary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position - 0x60, x_position + 0x1F, 0x0);
    }
}

u8 hive_count_mellows(void)
{
    u8 count;
    u8 room_slot;
    enum sprite_samus_collision collision;
    struct sprite_data* ptr;

    count = 0x0;
    collision = SSC_MELLOW;
    room_slot = current_sprite.room_slot;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && ptr->samus_collision == collision && ptr->room_slot == room_slot)
            count++;
        ptr++;
    }

    return count;
}

void hive_phase1(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        sprite_spawn_primary(PSPRITE_MELLOW, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    
    if (current_sprite.health < primary_sprite_stats[current_sprite.sprite_id].spawn_health >> 0x1)
    {
        current_sprite.frozen_palette_row_offset = 0x2;
        current_sprite.oam_pointer = hive_oam_phase2;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x23;
        unk_2b20(0x160);
        hive_spawn_particle();
    }
}

void hive_phase2(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        sprite_spawn_primary(PSPRITE_MELLOW, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    
    if (current_sprite.health < primary_sprite_stats[current_sprite.sprite_id].spawn_health >> 0x2)
    {
        current_sprite.frozen_palette_row_offset = 0x2;
        current_sprite.oam_pointer = hive_oam_phase3;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x25;
        unk_2b20(0x160);
        hive_spawn_particle();
    }
}

void hive_phase3(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        sprite_spawn_primary(PSPRITE_MELLOW, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
}

void hive_dying(void)
{    
    u8 count;
    u8 room_slot;
    u8 pose;
    enum sprite_samus_collision collision;
    struct sprite_data* ptr;
    enum p_sprite_id hive_id;

    count = 0x0;
    hive_id = PSPRITE_HIVE;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && (ptr->properties & SP_SECONDARY_SPRITE) == 0x0 && ptr->sprite_id == hive_id && ptr->health != 0x0)
            count++;
        ptr++;
    }

    if (count == 0x0)
        event_function(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = 0x9;
    room_slot = current_sprite.room_slot;
    collision = SSC_MELLOW;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && ptr->samus_collision == collision && ptr->room_slot == room_slot && ptr->pose == pose)
        {
            ptr->pose = 0x25;
            ptr->properties |= SP_PROJECTILE;
        }
        ptr++;
    }

    if (current_sprite.pose < 0x63 && current_sprite.timer1 != 0x0)
        sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position + 0x48, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    else
    {
        current_sprite.pose = 0x67;
        current_sprite.oam_pointer = hive_oam_dying;
        current_sprite.anim_duration_counter = current_sprite.timer1;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        unk_2b20(0x161);
        hive_spawn_particle();
    }
}

void hive_ignore_samus_collision(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
}

void hive_roots_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_distance_top_offset = 0x0;
    current_sprite.draw_distance_bottom_offset = 0x20;
    current_sprite.draw_distance_horizontal_offset = 0x14;
    current_sprite.hitbox_top_offset = -0x4;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = hive_roots_oam;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.frozen_palette_row_offset = 0x1;
}

void hive_roots_move(void)
{
    u8 ram_slot;

    ram_slot = current_sprite.primary_sprite_ram_slot;

    current_sprite.y_position = sprite_data[ram_slot].y_position;
    current_sprite.x_position = sprite_data[ram_slot].x_position;
}

void hive_mellow_init(struct sprite_data* ptr)
{

}

void hive_mellow_idle_anim(struct sprite_data* ptr)
{

}

void hive_mellow_fleeing(struct sprite_data* ptr)
{

}

void hive_mellow_samus_detected(struct sprite_data* ptr)
{

}

void hive_mellow_move(struct sprite_data* ptr)
{

}

void hive(void)
{
    if (current_sprite.freeze_timer != 0x0)
    {
        sprite_util_update_freeze_timer();
        sprite_util_unfreeze_secondary_sprites(SSPRITE_HIVE_ROOTS, current_sprite.primary_sprite_ram_slot);
        current_sprite.timer1 = current_sprite.freeze_timer;
    }
    else
    {
        if (sprite_util_is_sprite_stunned() == FALSE)
        {
            switch (current_sprite.pose)
            {
                case 0x0:
                    hive_init();
                    break;
                case 0x9:
                    hive_phase1();
                    break;
                case 0x23:
                    hive_phase2();
                    break;
                case 0x25:
                    hive_phase3();
                    break;
                case 0x67:
                    hive_ignore_samus_collision();
                    break;
                default:
                    hive_dying();
            }
        }
    }
}

void hive_roots(void)
{

}

void hive_mellow(void)
{
    if ((current_sprite.properties & SP_UNKNOWN) != 0x0)
    {
        current_sprite.properties &= (SP_ALWAYS_ACTIVE | SP_PROJECTILE | SP_SOLID_FOR_PROJECTILES | SP_MAYBE_DESTROYED | SP_MESSAGE_BANNER | SP_IMMUNE_TO_PROJECTILES | SP_SECONDARY_SPRITE);
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x15F);
    }
    
    if (current_sprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (0x9 < (current_sprite.invicibility_stun_flash_timer & 0x7F) && current_sprite.pose < 0x62)
        {
            if (current_sprite.anim_duration_counter == 0x0)
                return;
            current_sprite.anim_duration_counter--;
        }
        else
        {
            switch (current_sprite.pose)
            {
                case 0x0:
                    hive_mellow_init(&current_sprite);
                    break;
                case 0x9:
                    hive_mellow_idle_anim(&current_sprite);
                    break;
                case 0x22:
                    hive_mellow_samus_detected(&current_sprite);
                    break;
                case 0x23:
                    mellow_move(&current_sprite);
                    break;
                case 0x25:
                    mellow_fleeing(&current_sprite);
                    break;
                default:
                    sprite_util_sprite_death(0x0, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            }
        }
    }
}

void hive_mellow_swarm(void)
{
    u8 count;
    i16 rng;
    struct sprite_data* ptr;

    count = 0x0;

    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED) != 0x0)
            current_sprite.status = 0x0;
        else
        {
            current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN2);
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x4;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x4;
            current_sprite.draw_distance_top_offset = 0x1;
            current_sprite.draw_distance_bottom_offset = 0x1;
            current_sprite.draw_distance_horizontal_offset = 0x1;
            current_sprite.oam_pointer = mellow_swarm_oam;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.pose = 0x9;

            // TODO if

            current_sprite.maybe_y_position_spawn = 0xF0;
            if (current_sprite.sprite_id == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
            {
                if (equipment.current_energy < 0x190)
                {
                    if (equipment.current_energy < 0x12C)
                    {
                        if (equipment.current_energy < 0xC8)
                        {
                            if (equipment.current_energy < 0x64)
                                current_sprite.maybe_variable = 0x3;
                            else
                                current_sprite.maybe_variable = 0x6;
                        }
                        else
                            current_sprite.maybe_variable = 0x9;
                    }
                    else
                        current_sprite.maybe_variable = 0xC;
                }
                else
                    current_sprite.maybe_variable = 0xF;
            }
            else
                current_sprite.maybe_variable = 0x5;
        }
    }
    else
    {
        if ((current_sprite.status & SPRITE_STATUS_UNKNOWN) == 0x0 || current_sprite.maybe_y_position_spawn == 0x0)
        {
            ptr = sprite_data;
            while (ptr < sprite_data + 24)
            {
                if ((ptr->status & SPRITE_STATUS_EXISTS) != 0x0 && ptr->samus_collision == SSC_MELLOW)
                    count++;
                ptr++;
            }

            if ((current_sprite.status & SPRITE_STATUS_UNKNOWN) == 0x0)
            {
                if (current_sprite.maybe_variable <= count)
                {
                    current_sprite.status |= SPRITE_STATUS_UNKNOWN;
                    current_sprite.ignore_samus_collision_timer = 0x0;
                    return;
                }
            }
            else
            {
                if (0x13 < count)
                {
                    current_sprite.ignore_samus_collision_timer = 0x1;
                    return;
                }
                current_sprite.maybe_y_position_spawn = 0xF0;
            }

            if ((current_sprite.status & SPRITE_STATUS_XFLIP) == 0x0)
                rng = sprite_rng * -0x20;
            else 
                rng = sprite_rng * 0x20;

            // TODO if
            sprite_spawn_primary(PSPRITE_MELLOW, 0x88, current_sprite.spriteset_gfx_slot, bg1_y_position - (sprite_rng * 0x2 + 0x10), current_sprite.x_positin, 0x0);
        }
    }
}