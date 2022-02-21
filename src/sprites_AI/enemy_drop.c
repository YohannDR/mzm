#include "enemy_drop.h"
#include "../sprite.h"
#include "../globals.h"
#include "../oam.h"

void enemy_drop_init(void)
{
    current_sprite.ignore_samus_collision_timer = 0x14;
    current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
    current_sprite.pose = 0x9;
    current_sprite.y_position_spawn = 0xC8;
    current_sprite.x_position_spawn = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.draw_distance_top_offset = 0x8;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.bg_priority = (u8)io_registers_backup.bg2_cnt & 0x3
    current_sprite.draw_order = 0x1;

    switch (current_sprite.sprite_id)
    {
        case PSPRITE_POWER_BOMB_DROP:
            current_sprite.oam_pointer = power_bomb_drop_oam;
            current_sprite.samus_collision = SSC_POWER_BOMB_DROP;
            break;
        case PSPRITE_SUPER_MISSILE_DROP:
            current_sprite.oam_pointer = super_missile_drop_oam;
            current_sprite.samus_collision = SSC_SUPER_MISSILE_DROP;
            break;
        case PSPRITE_MISSILE_DROP:
            current_sprite.oam_pointer = missile_drop_oam;
            current_sprite.samus_collision = SSC_MISSILE_DROP;
            break;
        case PSPRITE_LARGE_ENERGY_DROP:
            current_sprite.oam_pointer = large_energy_oam;
            current_sprite.samus_collision = SSC_LARGE_ENERGY_DROP;
            break;
        case PSPRITE_MULTIPLE_LARGE_ENERGY:
            if (current_sprite.room_slot == 0x1)
                current_sprite.oam_pointer = multiple_large_energy_oam1;
            else if (current_sprite.room_slot == 0x2)
                current_sprite.oam_pointer = multiple_large_energy_oam2;
            else
                current_sprite.oam_pointer = multiple_large_energy_oam3;

            current_sprite.samus_collision = SSC_MULTIPLE_LARGE_ENERGY_DROP;
            break;
        default:
            current_sprite.oam_pointer = small_energy_oam;
            current_sprite.samus_collision = SSC_SMALL_ENERGY_DROP;
    }

    current_sprite.hitbox_top_offset = -0x24;
    current_sprite.hitbox_bottom_offset = 0x24;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
}

void enemy_drop_get(void)
{
    enum sprite_status status;
    struct sprite_data* pSprite;
    u32 timer;

    pSprite = &current_sprite;
    if (pSpriteignore_samus_collision_timer != 0x0)
    {
        if (pSprite->ignore_samus_collision_timer < 0x2)
            status = pSprite->status & ~SPRITE_STATUS_NOT_DRAWN;
        else
            return;
    }
    else
    {
        if ((pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
        {
            switch (pSprite->samus_collision)
            {
                case SSC_SMALL_ENERGY_DROP:
                    equipment.current_energy += 0x5;
                    if (equipment.current_energy > equipment.max_energy)
                        equipment.current_energy = equipment.max_energy;
                    play_sound1(0x86);
                    break;

                case SSC_LARGE_ENERGY_DROP:
                    equipment.current_energy += 0x14;
                    if (equipment.current_energy > equipment.max_energy)
                        equipment.current_energy = equipment.max_energy;
                    play_sound1(0x87);
                    break;

                case SSC_MISSILE_DROP:
                    equipment.current_missiles += 0x2;
                    if (equipment.current_missiles > equipment.max_missiles)
                        equipment.current_missiles = equipment.max_missiles;
                    play_sound1(0x88);
                    break;

                case SSC_SUPER_MISSILE_DROP:
                    equipment.current_super_missiles += 0x2;
                    if (equipment.current_super_missiles > equipment.max_super_missiles)
                        equipment.current_super_missiles = equipment.max_super_missiles;
                    play_sound1(0x89);
                    break;

                case SSC_POWER_BOMB_DROP:
                    equipment.current_power_bombs += 0x1;
                    if (equipment.current_power_bombs > equipment.max_power_bombs)
                        equipment.current_power_bombs = equipment.max_power_bombs;
                    play_sound1(0x8A);
                    break;

                case SSC_MULTIPLE_LARGE_ENERGY_DROP:
                    equipment.current_energy += 0x3C;
                    if (equipment.current_energy > equipment.max_energy)
                        equipment.current_energy = equipment.max_energy;
                    play_sound1(0x87);
                    break;
            }
            current_sprite.status = 0x0;
            return;
        }
        else
        {
            if (((u8)pSprite->x_position_spawn & 0x1) != 0x0)
            {
                pSprite->y_position_spawn--;
                timer = (u8)pSprite->y_position_spawn;
                status = timer;
                if (timer != 0x0)
                {
                    if (timer < 0x50)
                        status = pSprite->status ^ SPRITE_STATUS_NOT_DRAWN;
                    else
                        return;
                }
            }
            else
                return;
        }
    }
    pSprite->status = status;
}

void enemy_drop(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            enemy_drop_init();
            break;
        case 0x9:
            enemy_drop_get();
    }
    current_sprite.x_position_spawn++;
}