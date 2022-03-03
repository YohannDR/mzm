#include "hive.h"
#include "../particle.h"
#include "../event.h"
#include "../sprite_util.h"
#include "../globals.h"

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
        current_sprite.oam_pointer = hive_oam_2da8ec;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = event_check;
        current_sprite.draw_order = 0x5;
        current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
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
    struct sprite_data* pSprite;

    count = 0x0;
    collision = SSC_MELLOW;
    room_slot = current_sprite.room_slot;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision == collision && pSprite->room_slot == room_slot)
            count++;
        pSprite++;
    }

    return count;
}

void hive_phase1(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        sprite_spawn_primary(PSPRITE_MELLOW, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    
    if (current_sprite.health < primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0] >> 0x1)
    {
        current_sprite.frozen_palette_row_offset = 0x2;
        current_sprite.oam_pointer = hive_oam_2da9a4;
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
    
    if (current_sprite.health < primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0] >> 0x2)
    {
        current_sprite.frozen_palette_row_offset = 0x3;
        current_sprite.oam_pointer = hive_oam_2daa04;
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
    struct sprite_data* pSprite;
    enum p_sprite_id hive_id;

    count = 0x0;
    hive_id = PSPRITE_HIVE;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == hive_id && pSprite->health != 0x0)
            count++;
        pSprite++;
    }

    if (count == 0x0)
        event_function(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = 0x9;
    room_slot = current_sprite.room_slot;
    collision = SSC_MELLOW;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision == collision && pSprite->room_slot == room_slot && pSprite->pose == pose)
        {
            pSprite->pose = 0x25;
            pSprite->properties |= SP_PROJECTILE;
        }
        pSprite++;
    }

    if (current_sprite.pose < 0x63 && current_sprite.timer1 != 0x0)
        sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position + 0x48, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    else
    {
        current_sprite.pose = 0x67;
        current_sprite.oam_pointer = hive_oam_2daa6c;
        current_sprite.anim_duration_counter = 0x0;
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

void hive_mellow_init(struct sprite_data* pSprite)
{
    if (event_function(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        pSprite->status = 0x0;
    else
    {
        pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;
        pSprite->draw_distance_top_offset = 0x8;
        pSprite->draw_distance_bottom_offset = 0x8;
        pSprite->draw_distance_horizontal_offset = 0xC;
        pSprite->hitbox_top_offset = -0xC;
        pSprite->hitbox_bottom_offset = 0xC;
        pSprite->hitbox_left_offset = -0x20;
        pSprite->hitbox_right_offset = 0x20;
        pSprite->anim_duration_counter = 0x0;
        pSprite->curr_anim_frame = 0x0;
        pSprite->samus_collision = SSC_MELLOW;
        pSprite->health = primary_sprite_stats_2b0d68[pSprite->sprite_id][0x0];
        if (pSprite->room_slot != 0x88)
        {
            pSprite->oam_pointer = mellow_oam_2da88c;
            pSprite->pose = 0x9;
            pSprite->array_offset = sprite_rng << 0x2;
            if (sprite_rng & 0x1)
                pSprite->work_variable = 0x14;
            else
                pSprite->work_variable = 0x3C;
            
            if (pSprite->x_position & 0x1)
                pSprite->draw_order = 0x3;
            else
                pSprite->draw_order = 0x6;
        }
        else
        {
            pSprite->oam_pointer = mellow_oam_2da8bc;
            pSprite->bg_priority = io_registers_backup.bg2cnt & 0x3;
            pSprite->draw_order = 0x3;
            pSprite->timer2 = 0x0;
            pSprite->work_variable = 0x1;
            pSprite->timer1 = 0x0;
            pSprite->array_offset = 0x1;
            pSprite->x_position_spawn = sprite_rng & 0x3;
            pSprite->pose = 0x23;
            pSprite->oam_scaling = 0x20;
            sprite_util_make_sprite_face_samus_direction();
            if (pSprite->y_position > samus_data.y_position + samus_physics.draw_distance_top_offset)
                pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            else
                pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
        }
    }
}

void hive_mellow_idle_anim(struct sprite_data* pSprite)
{

}

void hive_mellow_fleeing(struct sprite_data* pSprite)
{
    u8 rng;
    u16 movement;

    rng = sprite_rng >> 0x2;
    movement = rng + 0x8;
    if (pSprite->work_variable < 0x28)
        pSprite->x_position -= -movement;
    else
        pSprite->x_position -= movement;

    movement = rng + 0x4;
    if (pSprite->array_offset < 0x20)
        pSprite->y_position -= -movement;
    else
        pSprite->y_position -= movement;
}

void hive_mellow_samus_detected(struct sprite_data* pSprite)
{
    pSprite->timer2 = 0x0;
    pSprite->work_variable = 0x1;
    pSprite->timer1 = 0x0;
    pSprite->array_offset = 0x1;
    pSprite->x_position_spawn = 0x0;
    pSprite->pose = 0x23;
    pSprite->oam_scaling = 0x20;
    sprite_util_make_sprite_face_samus_direction();
    if (pSprite->y_position > samus_data.y_position + samus_physics.draw_distance_top_offset)
        pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    else
        pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
}

void hive_mellow_move(struct sprite_data* pSprite)
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
    u8 ram_slot;
    struct sprite_data* pSprite;

    ram_slot = current_sprite.primary_sprite_ram_slot;
    current_sprite.ignore_samus_collision_timer = 0x1;
    pSprite = sprite_data + ram_slot;
    if (pSprite->sprite_id == PSPRITE_HIVE)
    {
        current_sprite.palette_row = pSprite->palette_row;
        if (pSprite->health < primary_sprite_stats_2b0d68[pSprite->sprite_id][0x0] >> 0x1 && pSprite->freeze_timer == 0x0)
            current_sprite.status = 0x0;
        else
        {
            if (pSprite->status == 0x0)
                current_sprite.status = 0x0;
            else
            {
                if (current_sprite.freeze_timer != 0x0)
                    sprite_util_update_freeze_timer();
                else
                {
                    if (current_sprite.pose == 0x0)
                        hive_roots_init();
                    hive_roots_move();
                }
            }
        }
    }
    else
        current_sprite.status = 0x0;
}

void hive_mellow(void)
{
    struct sprite_data* pSprite;

    pSprite = &current_sprite;

    if ((pSprite->properties & SP_UNKNOWN) != 0x0)
    {
        pSprite->properties &= ~SP_UNKNOWN;
        if ((pSprite->status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x15F);
    }
    
    if (pSprite->freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (0x9 < (pSprite->invicibility_stun_flash_timer & 0x7F) && pSprite->pose < 0x62)
        {
            if (pSprite->anim_duration_counter == 0x0)
                return;
            pSprite->anim_duration_counter--;
        }
        else
        {
            switch (pSprite->pose)
            {
                case 0x0:
                    hive_mellow_init(pSprite);
                    break;
                case 0x9:
                    hive_mellow_idle_anim(pSprite);
                    break;
                case 0x22:
                    hive_mellow_samus_detected(pSprite);
                case 0x23:
                    mellow_move(pSprite);
                    break;
                case 0x25:
                    mellow_fleeing(pSprite);
                    break;
                default:
                    sprite_util_sprite_death(0x0, pSprite->y_position, pSprite->x_position, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            }
        }
    }
}

void hive_mellow_swarm(void)
{
    u8 count;
    struct sprite_data* pSprite;
    enum sprite_samus_collision collision;
    u16 x_pos;
    u16 y_pos;

    count = 0x0;
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
            current_sprite.status = 0x0;
        else
        {
            current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x4;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x4;
            current_sprite.draw_distance_top_offset = 0x1;
            current_sprite.draw_distance_bottom_offset = 0x1;
            current_sprite.draw_distance_horizontal_offset = 0x1;
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.oam_pointer = mellow_oam_2da88c;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.pose = 0x9;
            if (0x78 < (samus_data.x_position >> 0x2) -( bg1_x_position >> 0x2))
                current_sprite.status |= SPRITE_STATUS_XFLIP;
            current_sprite.y_position_spawn = 0xF0;

            if (current_sprite.sprite_id == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
            {
                if (equipment.current_energy >= 0x190)
                    current_sprite.work_variable = 0xF;
                else
                {
                    if (equipment.current_energy >= 0x12C)
                        current_sprite.work_variable = 0xC;
                    else
                    {
                        if (equipment.current_energy >= 0xC8)
                            current_sprite.work_variable = 0x9;
                        else
                        {
                            if (equipment.current_energy >= 0x64)
                                current_sprite.work_variable = 0x6;
                            else
                                current_sprite.work_variable = 0x3;
                        }
                    }
                }
            }
            else
                current_sprite.work_variable = 0x5;
        }
    }
    else
    {
        if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL && current_sprite.y_position_spawn != 0x0)
            current_sprite.y_position_spawn--;
        else
        {
            collision = SSC_MELLOW;
            pSprite = sprite_data;
            while (pSprite < sprite_data + 24)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samus_collision == collision)
                    count++;
                pSprite++;
            }

            if ((current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) == 0x0)
            {
                if (count >= current_sprite.work_variable)
                {
                    current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                    return;
                }
            }
            else
            {
                if (count <= 0x13)
                    current_sprite.y_position_spawn = 0xF0;
                else
                    return;
            }

            if (current_sprite.status & SPRITE_STATUS_XFLIP)
                x_pos = samus_data.x_position + (sprite_rng * 0x20);
            else
                x_pos = samus_data.x_position + (sprite_rng * -0x20);
            if (x_pos & 0x8000)
                x_pos = 0x0;
            y_pos = (u16)(bg1_y_position - ((sprite_rng * 0x2) + 0x10));
            sprite_spawn_primary(PSPRITE_MELLOW, 0x88, current_sprite.spriteset_gfx_slot, y_pos, x_pos, 0x0);
        }
    }
}