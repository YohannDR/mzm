#include "projectile.h"
#include "sprite.h"
#include "sprite_util.h"
#include "power_bomb_explosion.h"
#include "globals.h"

void projectile_set_beam_particle_effect(void)
{
    /*enum particle_effect_id effect;
    u16 x_pos;
    u16 y_pos;
    u8 right;

    y_pos = arm_cannon_y;
    x_pos = arm_cannon_x;
    right = samus_data.direction & DIRECTION_RIGHT;

    switch (samus_data.arm_cannon_direction)
    {
        case ACD_DIAGONALLY_DOWN:
            effect = PE_SHOOTING_BEAM_DIAG_DOWN_LEFT;
            if (right != 0x0)
                effect = PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT;
            break;
        
        case ACD_DIAGONALLY_UP:
            effect = PE_SHOOTING_BEAM_DIAG_UP_LEFT;
            if (right != 0x0)
                effect = PE_SHOOTING_BEAM_DIAG_UP_RIGHT;
            break;

        case ACD_DOWN:
            effect = PE_SHOOTING_BEAM_DOWN_LEFT;
            if (right != 0x0)
                effect = PE_SHOOTING_BEAM_DOWN_RIGHT;
            break;

        case ACD_UP:
            effect = PE_SHOOTING_BEAM_UP_LEFT;
            if (right != 0x0)
                effect = PE_SHOOTING_BEAM_UP_RIGHT;
            break;
        
        case ACD_FORWARD:
            effect = PE_SHOOTING_BEAM_LEFT;
            if (right != 0x0)
                effect = PE_SHOOTING_BEAM_RIGHT;
            break;
    }

    particle_set(y_pos, x_pos, effect);*/
}

u8 projectile_check_number_of_projectiles(enum projectile_type type, u8 limit)
{
    u8 count;
    struct projectile_data* pProj;

    count = 0x0;
    pProj = projectile_data;

    while (pProj < projectile_data + 16)
    {
        if ((pProj->status & PROJ_STATUS_EXISTS) != 0x0 && pProj->type == type)
        {
            count++;
            if (count >= limit) return FALSE;
        }
        pProj++;
    }

    return TRUE;
}

u8 projectile_init(enum projectile_type type, u16 y_position, u16 x_position)
{
    /*struct projectile_data* pProj;
    enum projectile_status status;

    pProj = projectile_data;
    while (pProj < projectile_data + 24)
    {
        if ((pProj->status & PROJ_STATUS_EXISTS) == 0x0)
        {
            status = PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
            if (type > PROJ_TYPE_SUPER_MISSILE)
                status = PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN;
            if (samus_data.direction & DIRECTION_RIGHT)
                status |= PROJ_STATUS_XFLIP;

            pProj->status = status;
            pProj->type = type;
            pProj->y_position = y_position;
            pProj->x_position = x_position;
            pProj->hitbox_top_offset = -0x1;
            pProj->hitbox_bottom_offset = 0x1;
            pProj->hitbox_left_offset = -0x1;
            pProj->hitbox_right_offset = 0x1;
            pProj->movement_stage = 0x0;
            pProj->timer = 0x0;
            pProj->direction = samus_data.arm_cannon_direction;
            return TRUE;
        }
        pProj++;
    }
    return FALSE;*/
}

void projectile_update(void)
{
    /*u8 checks;
    i32 count;
    struct particle_effect* pEffect;
    struct projectile_data* pProj;
    enum projectile_type type;
    enum beam_bombs_flags flag;
    u16 sound;
    u8 proj_limit;

    if (game_mode_sub1 != 0x2) return;

    samus_call_update_arm_cannon_position_offset();

    arm_cannon_y = ((samus_data.y_position >> 0x2) + samus_physics.arm_cannon_y_position_offset) * 0x4;
    arm_cannon_x = ((samus_data.x_position >> 0x2) + samus_physics.arm_cannon_x_position_offset) * 0x4;

    if (samus_weapon_info.charge_counter == 0x10 && equipment.suit_type != SUIT_SUITLESS)
    {
        checks = FALSE;
        count = 0x0;
        pEffect = particle_effects;
        do {
            if ((pEffect->status & PARTICLE_STATUS_EXISTS) != 0x0 && pEffect->effect == PE_CHARGING_BEAM)
            {
                checks++;
                break;
            }
            pEffect++;
            count++;
        } while (count < 0x10);

        if (!checks)
            particle_set(arm_cannon_y, arm_cannon_x, PE_CHARGING_BEAM);
    }

    switch (samus_weapon_info.new_projectile)
    {
        case PROJECTILE_CHARGED_BEAM:
            if (equipment.suit_type == SUIT_SUITLESS)
            {
                if (projectile_check_number_of_projectiles(PROJ_TYPE_CHARGED_PISTOL, 0x2) << 0x18 != FALSE && projectile_init(PROJ_TYPE_CHARGED_PISTOL, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
                {
                    samus_weapon_info.cooldown = 0x7;
                    projectile_set_beam_particle_effect();
                    samus_weapon_info.beam_release_palette_timer = 0x4;
                    play_sound1(0xA0);
                }
            }
            else
            {
                flag = equipment.beam_bombs_activation;
                if ((equipment.beam_bombs_activation & BBF_PLASMA_BEAM) != 0x0)
                {
                    type = PROJ_TYPE_CHARGED_PLASMA_BEAM;
                    if ((equipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                    {
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xF5;
                            if (flag != 0x0)
                                sound = 0xF7;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xF4;
                            if (flag != 0x0)
                                sound = 0xF6;
                        }
                    }
                    else
                    {
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xF1;
                            if (flag != 0x0)
                                sound = 0xF3;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xF0;
                            if (flag != 0x0)
                                sound = 0xF2;
                        }
                    }
                }
                else
                {
                    if ((equipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                    {
                        type = PROJ_TYPE_CHARGED_WAVE_BEAM;
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xED;
                            if (flag != 0x0)
                                sound = 0xEF;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xEC;
                            if (flag != 0x0)
                                sound = 0xEE;
                        }
                    }
                    else
                    {
                        if ((equipment.beam_bombs_activation & BBF_ICE_BEAM) != 0x0)
                        {
                            type = PROJ_TYPE_CHARGED_ICE_BEAM;                            
                            flag = equipment.beam_bombs_activation & BBF_LONG_BEAM;
                            sound = 0xEA;
                            if (flag != 0x0)
                                sound = 0xEB;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_LONG_BEAM;
                            if (flag != 0x0)
                            {
                                type = PROJ_TYPE_CHARGED_LONG_BEAM;
                                sound = 0xE9;
                            }
                            else
                            {
                                type = PROJ_TYPE_CHARGED_BEAM;
                                sound = 0xE8;
                            }
                        }
                    }
                }
                proj_limit = 0x2;

                if (projectile_check_number_of_projectiles(type, proj_limit) << 0x18 != FALSE && projectile_init(type, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
                {
                    samus_weapon_info.cooldown = 0x7;
                    projectile_set_beam_particle_effect();
                    samus_weapon_info.beam_release_palette_timer = 0x4;
                    play_sound1(sound);
                }
            }
            samus_weapon_info.new_projectile = PROJECTILE_NONE;
            break;
        
        case PROJECTILE_BEAM:
            if (equipment.suit_type == SUIT_SUITLESS)
            {
                if (projectile_check_number_of_projectiles(PROJ_TYPE_PISTOL, 0x2) << 0x18 != FALSE && projectile_init(PROJ_TYPE_PISTOL, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
                {
                    samus_weapon_info.cooldown = 0x7;
                    projectile_set_beam_particle_effect();
                    samus_weapon_info.beam_release_palette_timer = 0x4;
                    play_sound1(0x9F);
                }
            }
            else
            {
                flag = equipment.beam_bombs_activation;
                if ((equipment.beam_bombs_activation & BBF_PLASMA_BEAM) != 0x0)
                {
                    type = PROJ_TYPE_PLASMA_BEAM;
                    if ((equipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                    {
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xD5;
                            if (flag != 0x0)
                                sound = 0xD7;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xD4;
                            if (flag != 0x0)
                                sound = 0xD6;
                        }
                    }
                    else
                    {
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xD1;
                            if (flag != 0x0)
                                sound = 0xD3;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xD0;
                            if (flag != 0x0)
                                sound = 0xD2;
                        }
                    }
                }
                else
                {
                    if ((equipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                    {
                        type = PROJ_TYPE_WAVE_BEAM;
                        if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xCD;
                            if (flag != 0x0)
                                sound = 0xCF;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_ICE_BEAM;
                            sound = 0xCC;
                            if (flag != 0x0)
                                sound = 0xCE;
                        }
                    }
                    else
                    {
                        if ((equipment.beam_bombs_activation & BBF_ICE_BEAM) != 0x0)
                        {
                            type = PROJ_TYPE_ICE_BEAM;
                            flag = equipment.beam_bombs_activation & BBF_LONG_BEAM;
                            sound = 0xCA;
                            if (flag != 0x0)
                                sound = 0xCB;
                        }
                        else
                        {
                            flag = equipment.beam_bombs_activation & BBF_LONG_BEAM;
                            if (flag != 0x0)
                            {
                                type = PROJ_TYPE_LONG_BEAM;
                                sound = 0xC9;
                            }
                            else
                            {
                                type = PROJ_TYPE_BEAM;
                                sound = 0xC8;
                            }
                        }
                    }
                }
                proj_limit = 0x6;

                if (projectile_check_number_of_projectiles(type, proj_limit) << 0x18 != FALSE && projectile_init(type, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
                {
                    samus_weapon_info.cooldown = 0x7;
                    projectile_set_beam_particle_effect();
                    samus_weapon_info.beam_release_palette_timer = 0x4;
                    play_sound1(sound);
                }
            }
            samus_weapon_info.new_projectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_MISSILE:
            if (projectile_check_number_of_projectiles(PROJ_TYPE_MISSILE, 0x4) << 0x18 != FALSE && projectile_init(PROJ_TYPE_MISSILE, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
            {
                samus_weapon_info.cooldown = 0x9;
                play_sound1(0xF8);
                play_sound1(0xF9);
            }
            samus_weapon_info.new_projectile = PROJECTILE_NONE;
            break;
        
        case PROJECTILE_SUPER_MISSILE:
            if (projectile_check_number_of_projectiles(PROJ_TYPE_SUPER_MISSILE, 0x4) << 0x18 != FALSE && projectile_init(PROJ_TYPE_SUPER_MISSILE, arm_cannon_y, arm_cannon_x) << 0x18 != FALSE)
            {
                samus_weapon_info.cooldown = 0xB;
                play_sound1(0xFB);
                play_sound1(0xFC);
            }
            samus_weapon_info.new_projectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_BOMB:
            if (projectile_check_number_of_projectiles(PROJ_TYPE_BOMB, 0x4) << 0x18 != FALSE && projectile_init(PROJ_TYPE_BOMB, samus_data.y_position, samus_data.x_position) << 0x18 != FALSE)
                samus_weapon_info.cooldown = 0x7;
            samus_weapon_info.new_projectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_POWER_BOMB:
            if (projectile_check_number_of_projectiles(PROJ_TYPE_POWER_BOMB, 0x1) << 0x18 != FALSE && pProj->animation_state == 0x0 && projectile_init(PROJ_TYPE_POWER_BOMB, samus_data.y_position, samus_data.x_position) << 0x18 != FALSE)
                samus_weapon_info.cooldown = 0x5;
            samus_weapon_info.new_projectile = PROJECTILE_NONE;

        default:
            break;
    }

    projectile_check_hit_sprite();

    pProj = projectile_data;
    while (pProj < projectile_data + 16)
    {
        if ((pProj->status & PROJ_STATUS_EXISTS) != 0x0)
        {
            bx_r1(pProj, process_projectile_functions_pointers[pProj->type]);
            projectile_update_animation(pProj);
            projectile_check_despawn(pProj);
        }
        pProj++;
    }*/
}

void projectile_update_animation(struct projectile_data* pProj)
{
    u32 adc;

    adc = pProj->anim_duration_counter + 0x1;
    pProj->anim_duration_counter = adc;
    if ((u8)pProj->oam_pointer[pProj->curr_anim_frame].timer < (u8)adc)
    {
        pProj->anim_duration_counter = 0x1;
        pProj->curr_anim_frame++;
        if ((u8)pProj->oam_pointer[pProj->curr_anim_frame].timer == 0x0)
            pProj->curr_anim_frame = 0x0;
    }
}

void projectile_draw_all_status_false(void)
{

}

void projectile_draw_all_status_true(void)
{

}

void projectile_draw(struct projectile_data* pProj)
{

}

void projectile_check_despawn(struct projectile_data* pProj)
{
    /*u16 x_pos;
    u16 y_pos;
    u16 draw_distance;

    if ((pProj->status & PROJ_STATUS_EXISTS) == 0x0) return;

    y_pos = pProj->y_position;
    x_pos = pProj->x_position;
    draw_distance = pProj->draw_distance_offset;

    if ((bg1_x_position + 0x100) - draw_distance < x_pos + 0x100 &&
        (x_pos + 0x100 < bg1_x_position + 0x100 + draw_distance + 0x3C0) &&
        ((bg1_y_position + 0x100) - draw_distance < y_pos + 0x100) &&
        (y_pos + 0x100 < bg1_y_position + 0x100 + draw_distance + 0x280))
        pProj->status |= PROJ_STATUS_ON_SCREEN;
    else
    {
        pProj->status &= (PROJ_STATUS_EXISTS | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_HIGH_PRIORITY | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT | PROJ_STATUS_YFLIP | PROJ_STATUS_XFLIP | PROJ_STATUS_UNKNOWN);
        if (PROJ_TYPE_SUPER_MISSILE < pProj->type) return;

        draw_distance = samus_data.y_position - 0x48;
        if (draw_distance < y_pos)
            y_pos -= draw_distance;
        else
            y_pos = draw_distance - y_pos;
        
        if (samus_data.x_position < x_pos)
            x_pos -= samus_data.x_position;
        else
            x_pos = samus_data.x_position - x_pos;
        
        if (y_pos < 0x301 && x_pos < 0x281) return;

        pProj->status = 0x0;
    }*/
}

void projectile_load_graphics(void)
{

}

void projectile_call_load_graphics_and_clear_projectiles(void)
{
    struct projectile_data* pProj;

    projectile_load_graphics();

    if (pause_screen_flag == 0x0)
    {
        pProj = projectile_data;
        while (pProj < projectile_data + 16)
        {
            pProj->status = 0x0;
            pProj++;
        }
    }
}

void projectile_move(struct projectile_data* pProj, u8 distance)
{
    /*i16 x_velocity;
    i32 x_velocity_;
    
    switch (pProj->direction)
    {
        case ACD_UP:
            pProj->y_position -= distance;
            return;

        case ACD_DOWN:
            pProj->y_position += distance;
            return;

        case ACD_DIAGONALLY_UP:
            distance = divide_signed(distance * 0x7, 0xA);
            pProj->y_position -= distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->x_position += distance;
            else
                pProj->x_position -= distance;
            break;

        case ACD_DIAGONALLY_DOWN:
            distance = divide_signed(distance * 0x7, 0xA);
            pProj->y_position += distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->x_position += distance;
            else
                pProj->x_position -= distance;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->x_position += distance;
            else
                pProj->x_position -= distance;
    }

    x_velocity = (u16)samus_data.x_velocity;
    x_velocity_ = x_velocity >> 0x3;
    if (pProj->status & PROJ_STATUS_XFLIP)
    {
        if (x_velocity >= 0x1)
            pProj->x_position += x_velocity >> 0x3;
    }
    else
    {
        if (x_velocity < 0x0)
            pProj->x_position += x_velocity_;
    }*/
}

u8 projectile_collision_related(u16 y_position, u16 x_position)
{

}

u8 projectile_collision_related2(struct projectile_data* pProj)
{

}

/**
 * 4fc38 | a8 | 
 * Sets a trail for the projectile using the effect in parameter 
 * 
 * @param pProj Projectile Data Pointer to the projectile concerned
 * @param effect Particle effect to play
 * @param delay Delay between each particle
 */
void projectile_set_trail(struct projectile_data* pProj, enum particle_effect_id effect, u8 delay)
{
    /*u16 x_pos;
    u16 y_pos;
    u16 offset;
    enum projectile_status status;

    if (eight_bit_frame_counter & delay)
        return;

    offset = 0x20;
    y_pos = pProj->y_position;
    x_pos = pProj->x_position;

    switch (pProj->direction)
    {
        case ACD_UP:
            y_pos += 0x20;
            break;
        
        case ACD_DOWN:
            y_pos -= 0x20;
            break;

        case ACD_DIAGONALLY_UP:
            status = PROJ_STATUS_XFLIP; // /!\ Wrong registers
            y_pos += 0x18;
            if (pProj->status & status)
                x_pos -= 0x18;
            else
                x_pos += 0x18;
            break;

        case ACD_DIAGONALLY_DOWN:
            status = PROJ_STATUS_XFLIP; // /!\ Wrong registers
            y_pos -= 0x18;
            if (pProj->status & status)
                x_pos -= 0x18;
            else
                x_pos += 0x18;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                x_pos -= offset;
            else
                x_pos += offset;
    }*/

    particle_set(y_pos, x_pos, effect);
}

/**
 * 4fce0 | 68 | 
 * Handles a projectile moving when tumbling
 * 
 * @param pProj Projectile Data Pointer to the concerned projectile
 */
void projectile_move_tumbling(struct projectile_data* pProj)
{
    u8 timer;
    i16 movement;
    u32 new_pos;

    if ((pProj->status & PROJ_STATUS_ON_SCREEN) == 0x0)
        pProj->status = 0x0;
    else
    {
        timer = pProj->timer;
        movement = i16_array_326ca8[timer];
        if (movement == 0x7FFF)
            new_pos = i16_array_326ca8[timer - 1] + pProj->y_position;
        else
        {
            pProj->timer = timer + 1;
            new_pos = pProj->y_position + movement;
        }
        pProj->y_position = new_pos;

        if (pProj->status & PROJ_STATUS_XFLIP)
            new_pos = pProj->x_position + 0x4;
        else
            new_pos = pProj->x_position - 0x4;
        pProj->x_position = new_pos;
    }
}

void projectile_check_hit_block(struct projectile_data* pProj, enum current_clipdata_affecting_action ccaa, enum particle_effect_id effect)
{
    u16 proj_y;
    u16 proj_x;

    current_clipdata_affecting_action = ccaa;
    proj_y = pProj->y_position;
    proj_x = pProj->x_position;
    if (pProj->direction == ACD_FORWARD)
    {
        if (pProj->status & PROJ_STATUS_XFLIP)
            proj_x -= 0x8;
        else
            proj_x += 0x8;
    }

    if (projectile_collision_related(proj_y, proj_x))
    {
        pProj->status = 0x0;
        particle_set(pProj->y_position, pProj->x_position, effect);
    }
}

void projectile_check_hit_sprite(void)
{
    /*struct equipment* pEquipment;
    struct sprite_data* pSprite;
    struct sprite_data* pSprite_next;
    struct projectile_data* pProj;
    enum sprite_status status;
    enum projectile_status status_proj;
    u16 proj_y;
    u16 proj_x;
    u16 proj_top;
    u16 proj_bottom;
    u16 proj_left;
    u16 proj_right;
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u8 count;
    u8 draw_order;
    u32 draw_order_next;

    pEquipment = &equipment;

    if (current_power_bomb.animation_state != 0x0 && pEquipment->max_power_bombs != 0x0)
    {
        proj_y = current_power_bomb.y_position;
        proj_x = current_power_bomb.x_position;
        proj_top = proj_y + current_power_bomb.hitbox_top_offset;
        proj_bottom = proj_y + current_power_bomb.hitbox_bottom_offset;
        proj_left = proj_x + current_power_bomb.hitbox_left_offset;
        proj_right = proj_x + current_power_bomb.hitbox_right_offset;
        status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_UNKNOWN3);
        pSprite = sprite_data;
        while (pSprite < sprite_data + 24)
        {
            if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0 && (pSprite->invicibility_stun_flash_timer & 0x80) == 0x0)
            {
                sprite_y = pSprite->y_position;
                sprite_x = pSprite->x_position;
                sprite_top = sprite_y + pSprite->hitbox_top_offset;
                sprite_bottom = sprite_y + pSprite->hitbox_bottom_offset;
                sprite_left = sprite_x + pSprite->hitbox_left_offset;
                sprite_right = sprite_x + pSprite->hitbox_right_offset;
                if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, proj_top, proj_bottom, proj_left, proj_right))
                    projectile_power_bomb_deal_damage(pSprite);
            }
            pSprite++;
        }
    }

    status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_UNKNOWN3);
    count = 0x0;
    pSprite = sprite_data;
    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0)
            sprite_draw_order[count] = pSprite->draw_order;
        else
            sprite_draw_order[count] = 0x0;
        count++;
        pSprite++;
    }

    draw_order = 0x1;
    do {
        count = 0x0;
        pSprite = sprite_data;
        draw_order_next = draw_order + 0x1;

        while (pSprite < sprite_data + 24)
        {
            pSprite_next = pSprite + 0x1;

            if (sprite_draw_order[count] == draw_order)
            {
                sprite_y = pSprite->y_position;
                sprite_x = pSprite->x_position;
                sprite_top = sprite_x + pSprite->hitbox_top_offset;
                sprite_bottom = sprite_x + pSprite->hitbox_bottom_offset;
                sprite_left = sprite_y + pSprite->hitbox_left_offset;
                sprite_right = sprite_y + pSprite->hitbox_right_offset;

                status_proj = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                pProj = projectile_data;
                while (pProj < projectile_data + 16)
                {
                    if ((pProj->status & status_proj) == status_proj)
                    {
                        proj_y = pProj->y_position;
                        proj_x = pProj->x_position;
                        proj_top = proj_y + pProj->hitbox_top_offset;
                        proj_bottom = proj_y + pProj->hitbox_bottom_offset;
                        proj_left = proj_x + pProj->hitbox_left_offset;
                        proj_right = proj_x + pProj->hitbox_right_offset;
                        if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, proj_top, proj_bottom, proj_left, proj_right))
                        {
                            switch (pProj->type)
                            {
                                case PROJ_TYPE_BEAM:
                                    projectile_hit_sprite(pSprite, proj_y, proj_x, 0x2, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_LONG_BEAM:
                                    projectile_hit_sprite(pSprite, proj_y, proj_x, 0x3, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_ICE_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                        projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x3, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_WAVE_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                            projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            projectile_hit_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                            projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            projectile_hit_sprite(pSprite, proj_y, proj_x, 0x3, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_PLASMA_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x6, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_hit_sprite(pSprite, proj_y, proj_x, 0x5, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                projectile_hit_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                projectile_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_hit_sprite(pSprite, proj_y, proj_x, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                projectile_hit_sprite(pSprite, proj_y, proj_x, 0x3, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_PISTOL:
                                    projectile_hit_sprite_immune_to_projectiles(pSprite);
                                    particle_set(proj_y, proj_x, PE_HITTING_SOMETHING_INVINCIBLE);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_BEAM:
                                    projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0x8, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_LONG_BEAM:
                                    projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_ICE_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                        projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x10, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                            projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0x10, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                            projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x10, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                                    if (pEquipment->beam_bombs_activation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x18, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0x14, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beam_bombs_activation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                projectile_charged_ice_beam_hitting_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beam_bombs_activation & BBF_WAVE_BEAM)
                                                projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_CHARGED_PISTOL:
                                    if (pSprite->samus_collision == SSC_SPACE_PIRATE)
                                    {
                                        pSprite->standing_on_sprite = FALSE;
                                        pSprite->freeze_timer = 0x3C;
                                        pSprite->palette_row = 0x1;
                                        pSprite->maybe_absolute_palette_row = 0x1;
                                        particle_set(proj_y, proj_x, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    }
                                    else
                                        projectile_non_ice_charged_hit_sprite(pSprite, proj_y, proj_x, 0xC, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_MISSILE:
                                    projectile_missile_hit_sprite(pSprite, pProj, proj_y, proj_x);
                                    break;

                                case PROJ_TYPE_SUPER_MISSILE:
                                    projectile_super_missile_hit_sprite(pSprite, pProj, proj_y, proj_x);
                                    break;

                                case PROJ_TYPE_BOMB:
                                    projectile_bomb_hit_sprite(pSprite, proj_y, proj_x);
                            }
                        }
                    }

                    pProj++;
                }
            }

            count++;
            pSprite = pSprite_next;
        }
        draw_order = draw_order_next;
    } while (draw_order <= 0x10);*/
}

/**
 * 50370 | 30 | 
 * Gets the weakness for the sprite given in parameter
 * 
 * @param pSprite The sprite concerned
 * @return The weakness of the sprite
 */
enum sprite_weakness_flags projectile_get_sprite_weakness(struct sprite_data* pSprite)
{
    if (pSprite->properties & SP_SECONDARY_SPRITE) // Check wheter secondary or primary
        return primary_sprite_stats_2b0d68[pSprite->sprite_id][0x2]; // Offset 2 is weakness
    else
        return secondary_sprite_stats_2b1be4[pSprite->sprite_id][0x2];
}

/**
 * 503a0 | 84 | Handles the ice beam dealing damage to a sprite
 * 
 * @param pSprite The sprite concerned
 * @param damage Damage to inflict
 * @return The freeze timer
 */
u8 projectile_ice_beam_deal_damage(struct sprite_data* pSprite, u16 damage)
{
    u8 freeze_timer;

    freeze_timer = 0x0;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
        freeze_timer = 0xF0;
    }
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_MAYBE_DESTROYED;
        pSprite->freeze_timer = 0x0;
        pSprite->palette_row = 0x0;
        if (pSprite->standing_on_sprite != FALSE && samus_data.standing_status == STANDING_ENEMY)
        {
            samus_data.standing_status = STANDING_MIDAIR;
            pSprite->standing_on_sprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignore_samus_collision_timer = 0x1;
    }

    pSprite->invicibility_stun_flash_timer = pSprite->invicibility_stun_flash_timer & 0x80 | 0x11;
    pSprite->properties |= SP_UNKNOWN;
    return freeze_timer;
}

/**
 * 50424 | 88 | 
 * Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param damage Damage to inflict 
 * @return 1 if dead, 0 otherwise
 */
u8 projectile_deal_damage(struct sprite_data* pSprite, u16 damage)
{
    u8 is_dead;

    is_dead = FALSE;
    if (pSprite->health > damage)
        pSprite->health -= damage;
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_MAYBE_DESTROYED;
        pSprite->freeze_timer = 0x0;
        pSprite->palette_row = 0x0;
        if (pSprite->standing_on_sprite && samus_data.standing_status == STANDING_ENEMY)
        {
            samus_data.standing_status = STANDING_MIDAIR;
            pSprite->standing_on_sprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignore_samus_collision_timer = 0x1;
        is_dead++;
    }

    pSprite->invicibility_stun_flash_timer &= 0x80; 
    pSprite->invicibility_stun_flash_timer |= 0x11;
    pSprite->properties |= SP_UNKNOWN;
    return is_dead;
}

/**
 * 504ac | 20 | Handles a projectile hitting a sprite immune to projectiles
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 * @return The parameter
 */
struct sprite_data* projectile_hit_sprite_immune_to_projectiles(struct sprite_data* pSprite)
{
    u8 isft;

    isft = 0x2; // Needed to force a bcs
    if ((pSprite->invicibility_stun_flash_timer & 0x7F) < isft)
    {
        pSprite->invicibility_stun_flash_timer &= 0x80;
        pSprite->invicibility_stun_flash_timer |= 0x2;
    } // Return is implicit
}

/**
 * 504cc | 20 | Handles a projectile hitting a solid sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @return The parameter
 */
struct sprite_data* projectile_hit_solid_sprite(struct sprite_data* pSprite)
{
    u8 isft;

    isft = 0x3; // Needed to force a bcs
    if ((pSprite->invicibility_stun_flash_timer & 0x7F) < isft)
    {
        pSprite->invicibility_stun_flash_timer &= 0x80;
        pSprite->invicibility_stun_flash_timer |= 0x3;
    } // Return is implicit
}

/**
 * 504ec | c0 | Handles a power bomb dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 */
void projectile_power_bomb_deal_damage(struct sprite_data* pSprite)
{
    u8 isft;

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
        projectile_hit_sprite_immune_to_projectiles(pSprite);
    else
    {
        if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
            projectile_hit_solid_sprite(pSprite);
        else
        {
            if (projectile_get_sprite_weakness(pSprite) & WEAKNESS_POWER_BOMB)
            {
                if (pSprite->health > 0x32)
                    pSprite->health -= 0x32;
                else
                {
                    pSprite->health = 0x0;
                    pSprite->properties |= SP_MAYBE_DESTROYED;
                    pSprite->freeze_timer = 0x0;
                    pSprite->palette_row = 0x0;
                    if (pSprite->standing_on_sprite && samus_data.standing_status == STANDING_ENEMY)
                    {
                        samus_data.standing_status = STANDING_MIDAIR;
                        pSprite->standing_on_sprite = FALSE;
                    }
                    pSprite->pose = 0x62;
                    pSprite->ignore_samus_collision_timer = 0x1;
                }
                isft = 0x11;
            }
            else
                isft = 0x3;

            if ((pSprite->invicibility_stun_flash_timer & 0x7F) < isft)
                pSprite->invicibility_stun_flash_timer = isft | 0x80;
            else
                pSprite->invicibility_stun_flash_timer |= 0x80;
            pSprite->properties |= SP_UNKNOWN;
        }
    }
}

/**
 * 505ac | a8 | Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 * @param y_position Y Position of the projectile
 * @param x_position X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void projectile_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect)
{
    enum sprite_weakness_flags weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        projectile_hit_solid_sprite(pSprite);
        particle_set(y_position, x_position, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            projectile_hit_sprite_immune_to_projectiles(pSprite);
            particle_set(y_position, x_position, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = projectile_get_sprite_weakness(pSprite);
            if ((weakness & WEAKNESS_BEAM_BOMBS) != 0x0)
            {
                projectile_deal_damage(pSprite, damage);
                particle_set(y_position, x_position, effect);
            }
            else
            {
                projectile_hit_solid_sprite(pSprite);
                particle_set(y_position, x_position, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 50654 | a8 | 
 * Handles a charged beam (without ice) dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param y_position Y Position of the projectile
 * @param x_position X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void projectile_non_ice_charged_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect)
{
    enum sprite_weakness_flags weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        projectile_hit_solid_sprite(pSprite);
        particle_set(y_position, x_position, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            projectile_hit_sprite_immune_to_projectiles(pSprite);
            particle_set(y_position, x_position, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = projectile_get_sprite_weakness(pSprite);
            if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
            {
                projectile_deal_damage(pSprite, damage);
                particle_set(y_position, x_position, effect);
            }
            else
            {
                projectile_hit_solid_sprite(pSprite);
                particle_set(y_position, x_position, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 506fc | 28 | 
 * Freezes the sprite with the parameters
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param freeze_timer Freeze timer to apply
 */
void projectile_freeze_sprite(struct sprite_data* pSprite, u8 freeze_timer)
{
    pProj->freeze_timer = freeze_timer;
    pProj->palette_row = 0xF - (pProj->spriteset_gfx_slot + pProj->frozen_palette_row_offset);
    unk_2b20(0x140);
}

void projectile_ice_beam_hitting_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect)
{

}

void projectile_charged_ice_beam_hitting_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect)
{

}

/**
 * 50914 | 60 | 
 * Sets the projectile to a tumbling state (reserved for missile and super missile)
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 * @param pProj Projectile Data Pointer to the concerned projectile
 * @param type The type of the projectile
 */
void projectile_start_tumbling_missile(struct sprite_data* pSprite, struct projectile_data* pProj, enum projectile_type type)
{
    pProj->movement_stage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->anim_duration_counter = 0x0;
    pProj->curr_anim_frame = 0x0;
    if (pProj->x_position > pSprite->x_position)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->oam_pointer = super_missile_oam_327018; // Spinning/tumbling
        play_sound2(0xFC);
    }
    else
    {
        pProj->oam_pointer = missile_oam_326fd0; // Spinning/tumbling
        play_sound2(0xF9);
    }
}

/**
 * 50974 | 68 | 
 * Sets the projectile to a tumbling state (reserved for missile and super missile, uses the current sprite)
 * 
 * @param pProj Projectile Data Pointer to the concerned projectile
 * @param type The type of the projectile
 */
void projectile_start_tumbling_missile_current_sprite(struct projectile_data* pProj, enum projectile_type type)
{    
    pProj->movement_stage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->anim_duration_counter = 0x0;
    pProj->curr_anim_frame = 0x0;
    if (pProj->x_position > current_sprite.x_position)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->oam_pointer = super_missile_oam_327018; // Spinning/tumbling
        play_sound2(0xFC);
    }
    else
    {
        pProj->oam_pointer = missile_oam_326fd0; // Spinning/tumbling
        play_sound2(0xF9);
    }
}

void projectile_missile_hit_sprite(struct sprite_data* pSprite, struct projectile_data* pProj , u16 y_position, u16 x_position)
{
    /*if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        projectile_hit_solid_sprite(pSprite);
        particle_set(y_position, x_position, PE_HITTING_SOMETHING_WITH_MISSILE);
        if (pProj->movement_stage == 0x0)
            projectile_decrement_missile_counter(pProj);
        pProj->status = 0x0;
        return;
    }
    else
    {
        if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
            projectile_hit_sprite_immune_to_projectiles(pSprite);
        else
        {
            if (projectile_get_sprite_weakness(pSprite) & WEAKNESS_MISSILES)
            {
                projectile_deal_damage(pSprite, 0x14);
                particle_set(y_position, x_position, PE_HITTING_SOMETHING_WITH_MISSILE);
                if (pProj->movement_stage == 0x0)
                    projectile_decrement_missile_counter(pProj);
                pProj->status = 0x0;
                return;
            }
            else
            {
                projectile_hit_solid_sprite(pSprite);
            }
        }
        particle_set(y_position, x_position, PE_HITTING_SOMETHING_INVINCIBLE);
        projectile_start_tumbling_missile(pSprite, pProj, PROJ_TYPE_MISSILE);
    }*/
}

void projectile_super_missile_hit_sprite(struct sprite_data* pSprite, struct projectile_data* pProj , u16 y_position, u16 x_position)
{

}

void projectile_bomb_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position)
{
    if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
    {
        projectile_hit_sprite_immune_to_projectiles(pSprite);
    }
    else
    {
        if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
        {
            projectile_hit_solid_sprite(pSprite);
        }
        else
        {
            if ((projectile_get_sprite_weakness(pSprite) & WEAKNESS_BEAM_BOMBS) != 0x0)
                projectile_deal_damage(pSprite, 0x8);
            else
                projectile_hit_solid_sprite(pSprite);
        }
    }
}

/**
 * 50b64 | f8 | Subroutine for the normal beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned normal beam
 */
void projectile_process_normal_beam(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_BEAM;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
            return;
        }
        else
        {
            projectile_move(pProj, 0x14);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_BEAM;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
            return;
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = beam_oam_327aa8;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = beam_oam_327ac0;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = beam_oam_327a90;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0x8;
        pProj->hitbox_bottom_offset = 0x8;
        pProj->hitbox_left_offset = -0x8;
        pProj->hitbox_right_offset = 0x8;
        pProj->movement_stage = 0x1;
        projectile_check_hit_block(pProj, CCAA_BEAM, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
    }

    pProj->timer++;
    if (pProj->timer > 0xC) // Check if projectile should be killed when going further enough
        pProj->status = 0x0;
}

/**
 * 50c5c | ec | Subroutine for the long beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned long beam
 */
void projectile_process_long_beam(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
   if (pProj->movement_stage == 0x2)
   {
       current_clipdata_affecting_action = CCAA_BEAM;
       if (projectile_collision_related2(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           projectile_move(pProj, 0x18);
           pProj->timer++;
       }
   }
   else if (pProj->movement_stage == 0x1)
   {
       current_clipdata_affecting_action = CCAA_BEAM;
       if (projectile_collision_related2(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           pProj->movement_stage++;
           projectile_move(pProj, 0x10);
           pProj->timer++;
       }
   }
   else
   {
       switch (pProj->direction) // Set OAM/Flip depending on direction
       {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = beam_oam_328460;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = beam_oam_328478;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = beam_oam_328448;
       }

       pProj->draw_distance_offset = 0x40;
       pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
       pProj->anim_duration_counter = 0x0;
       pProj->curr_anim_frame = 0x0;
       pProj->hitbox_top_offset = -0xC;
       pProj->hitbox_bottom_offset = 0xC;
       pProj->hitbox_left_offset = -0xC;
       pProj->hitbox_right_offset = 0xC;
       pProj->movement_stage = 0x1;
       projectile_check_hit_block(pProj, CCAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       pProj->timer++;
   }
}

/**
 * 50d48 | 124 | Subroutine for the ice beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned ice beam
 */
void projectile_process_ice_beam(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_BEAM;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            projectile_move(pProj, 0x1A);
            if (pProj->status & PROJ_STATUS_XFLIP)
                projectile_set_trail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                projectile_set_trail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_BEAM;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = beam_oam_328e44;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = beam_oam_328e5c;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = beam_oam_328e2c;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0x14;
        pProj->hitbox_bottom_offset = 0x14;
        pProj->hitbox_left_offset = -0x14;
        pProj->hitbox_right_offset = 0x14;
        pProj->movement_stage = 0x1;
        projectile_check_hit_block(pProj, CCAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    pProj->timer++;
    if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC)
        pProj->status = 0x0;
}

u32 projectile_check_wave_beam_hitting_blocks(struct projectile_data* pProj)
{

}

/**
 * 51068 | 130 | Subroutine for the wave beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned wave beam
 */
void projectile_process_wave_beam(struct projectile_data* pProj)
{
    projectile_check_wave_beam_hitting_blocks(pProj); // Check collision
    if (pProj->movement_stage == 0x2)
    {
        projectile_move(pProj, 0x1C);
        if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                projectile_set_trail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                projectile_set_trail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        pProj->movement_stage++;
        projectile_move(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip/Hitbox depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = beam_oam_329cac;
                pProj->hitbox_top_offset = -0x10;
                pProj->hitbox_bottom_offset = 0x40;
                pProj->hitbox_left_offset = -0x28;
                pProj->hitbox_right_offset = 0x28;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = beam_oam_329cec;
                pProj->hitbox_top_offset = -0x14;
                pProj->hitbox_bottom_offset = 0x14;
                pProj->hitbox_left_offset = -0x40;
                pProj->hitbox_right_offset = 0x40;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = beam_oam_329c6c;
                pProj->hitbox_top_offset = -0x40;
                pProj->hitbox_bottom_offset = 0x40;
                pProj->hitbox_left_offset = -0x14;
                pProj->hitbox_right_offset = 0x14;
        }

        pProj->draw_distance_offset = 0xA0;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->movement_stage = 0x1;
    }

    pProj->timer++;
    if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC) // Check despawn
        pProj->status = 0x0;
}

/**
 * 51198 | 1bc | Subroutine for the plasma beam projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned plasma beam
 */
void projectile_process_plasma_beam(struct projectile_data* pProj)
{
    u8 has_wave;

    has_wave = equipment.beam_bombs_activation & BBF_WAVE_BEAM;
    if (!has_wave)
    {
        current_clipdata_affecting_action = CCAA_BEAM;
        if (projectile_collision_related2(pProj) != 0x0)
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
        else
            projectile_check_wave_beam_hitting_blocks(pProj);
    }

    if (pProj->movement_stage == 0x2)
    {
        projectile_move(pProj, 0x20);
        if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                projectile_set_trail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                projectile_set_trail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        pProj->movement_stage++;
        projectile_move(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                if (has_wave)
                {
                    pProj->oam_pointer = beam_oam_32ae38;
                    pProj->hitbox_top_offset = -0x10;
                    pProj->hitbox_bottom_offset = 0x40;
                    pProj->hitbox_left_offset = -0x30;
                    pProj->hitbox_right_offset = 0x30;
                }
                else
                    pProj->oam_pointer = beam_oam_32ad38;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                if (has_wave)
                {
                    pProj->oam_pointer = beam_oam_32ae78;
                    pProj->hitbox_top_offset = -0x20;
                    pProj->hitbox_bottom_offset = 0x20;
                    pProj->hitbox_left_offset = -0x40;
                    pProj->hitbox_right_offset = 0x40;
                }
                else
                    pProj->oam_pointer = beam_oam_32ad50;
                break;

            case ACD_FORWARD:
                if (has_wave)
                {
                    pProj->oam_pointer = beam_oam_32adf8;
                    pProj->hitbox_top_offset = -0x40;
                    pProj->hitbox_bottom_offset = 0x40;
                    pProj->hitbox_left_offset = -0x20;
                    pProj->hitbox_right_offset = 0x20;
                }
                else
                    pProj->oam_pointer = beam_oam_32ad20;
        }

        if (has_wave)
        {
            pProj->draw_distance_offset = 0xA0;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->draw_distance_offset = 0x50;
            pProj->hitbox_top_offset = -0x14;
            pProj->hitbox_bottom_offset = 0x14;
            pProj->hitbox_left_offset = -0x14;
            pProj->hitbox_right_offset = 0x14;
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->movement_stage = 0x1;
    }

    pProj->timer++;
    if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
* 51354 | ec | Subroutine for the pistol projectile, further detail is commented in the function
*
* @param pProj Projectile Data Pointer to the concerned pistol
*/
void projectile_process_pistol(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        }
        else
        {
            projectile_move(pProj, 0x16);
            pProj->timer++;
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = pistol_oam_32b948;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = pistol_oam_32b960;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = pistol_oam_32b930;
        }

        pProj->draw_distance_offset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0x4;
        pProj->hitbox_bottom_offset = 0x4;
        pProj->hitbox_left_offset = -0x4;
        pProj->hitbox_right_offset = 0x4;
        pProj->movement_stage = 0x1;
        projectile_check_hit_block(pProj, CCAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_BASE_BEAM);
        pProj->timer++;
    }
}

void projectile_process_charged_normal_beam(struct projectile_data* pProj)
{

}

void projectile_process_charged_long_beam(struct projectile_data* pProj)
{

}

void projectile_process_charged_ice_beam(struct projectile_data* pProj)
{

}

void projectile_process_charged_wave_beam(struct projectile_data* pProj)
{

}

void projectile_process_charged_plasma_beam(struct projectile_data* pProj)
{

}

/**
 * 51a7c | f8 | Subroutine for the charged pistol projectile, further detail is commented in the function
 * 
 * @param pProj Projectile Data Pointer to the concerned charged pistol
 */
void projectile_process_charged_pistol(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            projectile_move(pProj, 0x16);
            projectile_set_trail(pProj, PE_CHARGED_PISTOL_TRAIL, 0x7);
            pProj->timer++;
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = charged_pistol_oam_32b990;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = charged_pistol_oam_32b9a8;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = charged_pistol_oam_32b978;
        }

        pProj->draw_distance_offset = 0x80;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0xC;
        pProj->hitbox_bottom_offset = 0xC;
        pProj->hitbox_left_offset = -0xC;
        pProj->hitbox_right_offset = 0xC;
        pProj->movement_stage = 0x1;
        projectile_check_hit_block(pProj, CCAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        pProj->timer++;
    }
}

void projectile_decrement_missile_counter(struct projectile_data* pProj)
{
    if (equipment.current_missiles != 0x0)
    {
        equipment.current_missiles--;
        if (equipment.current_missiles == 0x0)
            samus_weapon_info.weapon_highlighted ^= WH_MISSILE;
    }

    pProj->draw_distance_offset = 0x40;
    pProj->status &= 0xFB;
}

/**
* 51bac | 118 | Subroutine for the missile projectile, further detail is commented in the function
* @param pProj Projectile Data Pointer to the concerned missile
*/
void projectile_process_missile(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_MISSILE;
        if (projectile_collision_related2(pProj) == 0x0) // Check for collision
        {
            projectile_move(pProj, pProj->timer + 0x8);
            if (pProj->timer < 0xC)
                pProj->timer++;
            projectile_set_trail(pProj, PE_MISSILE_TRAIL, 0x7);
        }
        else
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_MISSILE;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x30);
        }
    }
    else if (pProj->movement_stage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = missile_oam_326f58;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = missile_oam_326f70;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = missile_oam_326f40;
        }

        projectile_decrement_missile_counter(pProj);
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0x8;
        pProj->hitbox_bottom_offset = 0x8;
        pProj->hitbox_left_offset = -0x8;
        pProj->hitbox_right_offset = 0x8;
        pProj->movement_stage++;
        projectile_check_hit_block(pProj, CCAA_MISSILE, PE_HITTING_SOMETHING_WITH_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            projectile_decrement_missile_counter(pProj); // Not sure why this is here ?
        projectile_move_tumbling(pProj);
    }
}

void projectile_decrement_super_missile(struct projectile_data* pProj)
{
    if (equipment.current_super_missiles != 0x0)
    {
        equipment.current_super_missiles--;
        if (equipment.current_super_missiles == 0x0)
            samus_weapon_info.weapon_highlighted ^= WH_SUPER_MISSILE;
    }

    pProj->draw_distance_offset = 0x40;
    pProj->status &= 0xFB;
}

void projectile_process_super_missile(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movement_stage == 0x2)
    {
        current_clipdata_affecting_action = CCAA_SUPER_MISSILE;
        if (projectile_collision_related2(pProj) == 0x0) // Check for collision
        {
            projectile_move(pProj, pProj->timer + 0xC);
            if (pProj->timer < 0x10)
                pProj->timer++;
            projectile_set_trail(pProj, PE_SUPER_MISSILE_TRAIL, 0x3);
        }
        else
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
    }
    else if (pProj->movement_stage == 0x1)
    {
        current_clipdata_affecting_action = CCAA_SUPER_MISSILE;
        if (projectile_collision_related2(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            particle_set(pProj->y_position, pProj->x_position, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
        else
        {
            pProj->movement_stage++;
            projectile_move(pProj, 0x30);
        }
    }
    else if (pProj->movement_stage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->oam_pointer = super_missile_oam_326fa0;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->oam_pointer = super_missile_oam_326fb8;
                break;
            default:
            case ACD_FORWARD:
                pProj->oam_pointer = super_missile_oam_326f88;
        }

        projectile_decrement_super_missile(pProj);
        pProj->anim_duration_counter = 0x0;
        pProj->curr_anim_frame = 0x0;
        pProj->hitbox_top_offset = -0xC;
        pProj->hitbox_bottom_offset = 0xC;
        pProj->hitbox_left_offset = -0xC;
        pProj->hitbox_right_offset = 0xC;
        pProj->movement_stage++;
        projectile_check_hit_block(pProj, CCAA_SUPER_MISSILE, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            projectile_decrement_super_missile(pProj); // Not sure why this is here ?
        projectile_move_tumbling(pProj);
    }
}

/**
 * 51e14 | b8 | Checks if samus is in place to be launched by the morph ball launcher, if yes sets pose to Delay before ballsparking 
 * 
 * @param pProj Projectile Data Pointer to the concerned bomb
 */
void projectile_morphball_launcher_launch_samus(struct projectile_data* pProj)
{
    u16 samus_y;
    u16 samus_x;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;
    u16 proj_y;
    u16 proj_x;
    u16 proj_top;
    u16 proj_bottom;
    u16 proj_left;
    u16 proj_right;

    samus_y = samus_data.y_position;
    samus_x = samus_data.x_position;
    samus_top = samus_y + samus_physics.draw_distance_top_offset;
    samus_bottom = samus_y + samus_physics.draw_distance_bottom_offset;
    samus_left = samus_x + samus_physics.draw_distance_left_offset;
    samus_right = samus_x + samus_physics.draw_distance_right_offset;

    proj_y = pProj->y_position;
    proj_x = pProj->x_position;
    proj_top = proj_y + pProj->hitbox_top_offset;
    proj_bottom = proj_y + pProj->hitbox_bottom_offset;
    proj_left = proj_x + pProj->hitbox_left_offset;
    proj_right = proj_x + pProj->hitbox_right_offset;

    if (sprite_util_check_objects_touching(samus_top, samus_bottom, samus_left, samus_right, proj_top, proj_bottom, proj_left, proj_right) && samus_data.invincibility_timer != 0x0)
    {
        switch (samus_data.pose)
        {
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL:
                samus_data.forced_movement = 0xF0;
                samus_set_pose(SPOSE_DELAY_BEFORE_BALLSPARKING);
        }
    }
}

void projectile_check_samus_bomb_bounce(struct projectile_data* pProj)
{

}

/**
* 51ff8 | 1f8 | Subroutine for the bomb projectile, further detail is commented in the function
*
* @param pProj Projectile Data Pointer to the concerned bomb
*/
void projectile_process_bomb(struct projectile_data* pProj)
{
    u32 timer;

    /*
    Movement Stage :
      0x0 = Initialization
      0x1,0x5 = Check first timer ended (bomb spinning at normal speed)
      0x2,0x6 = Check second timer ended (bomb spinning fast)
      0x3 = Bomb exploding
      0x4 = Bomb placed on launcher (set in morph_ball_launcher::morph_ball_launcher_detect_bomb)
      0x7 = Bomb exploding on launcher
    */
    switch (pProj->movement_stage)
    {
        case 0x0:
            pProj->oam_pointer = bomb_oam_326d40; // Bomb spinning at normal speed
            pProj->anim_duration_counter = 0x0;
            pProj->curr_anim_frame = 0x0;
            pProj->draw_distance_offset = 0x20;
            pProj->hitbox_top_offset = -0x3C;
            pProj->hitbox_bottom_offset = 0x30;
            pProj->hitbox_left_offset = -0x30;
            pProj->hitbox_right_offset = 0x30;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP); // Clear Not Drawn and X Flip status, X Flip is cleared to make it always face the same way, cancelling the automatic X Flip if samus is facing right
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x10; // Timer before the bomb starts spinning faster
            pProj->movement_stage++;
            play_sound1(0xFE); // Placing bomb sound
            break;

        case 0x3: // Bomb Exploding
            timer = pProj->timer - 0x1;
            pProj->timer = timer;
            
            if (pProj->timer != 0x0)
            {
                // /!\ u8 cast missing in asm
                if (timer == 0xF)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x8, pProj->x_position); // Block center
                    projectile_check_samus_bomb_bounce(pProj); // Checks if samus can bounce
                    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT; // Clear Can Affect Environement status
                }
                else if (timer == 0xE)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position + 0x38, pProj->x_position); // Block bottom middle
                }
                else if (timer == 0xD)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x8, pProj->x_position + 0x30); // Block right middle
                }
                else if (timer == 0xC)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x8, pProj->x_position - 0x30); // Block left middle
                }
                else if (timer == 0xB)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position + 0x38, pProj->x_position + 0x24); // Block right bottom
                }
                else if (timer == 0xA)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position + 0x38, pProj->x_position - 0x24); // Block left bottom
                }
                else if (timer == 0x9)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x48, pProj->x_position); // Block top middle
                }
                else if (timer == 0x8)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x48, pProj->x_position + 0x24); // Block right top
                }
                else if (timer == 0x7)
                {
                    current_clipdata_affecting_action = CCAA_BOMB_PISTOL;
                    clipdata_related(pProj->y_position - 0x48, pProj->x_position - 0x24); // Block left top
                }
            }
            else
                pProj->status = 0x0;
            break;

        case 0x4:
            pProj->oam_pointer = bomb_oam_326d40; // Bomb spinning at normal speed
            pProj->anim_duration_counter = 0x0;
            pProj->curr_anim_frame = 0x0;
            pProj->timer = 0x10;
            pProj->movement_stage++;
            break;

        case 0x1:
        case 0x5:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->oam_pointer = bomb_oam_326d68; // Bomb spinning fast
                pProj->anim_duration_counter = 0x0;
                pProj->curr_anim_frame = 0x0;
                pProj->timer = 0x10;
                pProj->movement_stage++;
            }
            break;

        case 0x2:
        case 0x6:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->timer = 0x10;
                pProj->movement_stage++;
                pProj->status |= (PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT);
                particle_set(pProj->y_position - 0x10, pProj->x_position, PE_BOMB);
            }
            break;

        case 0x7:
            projectile_morphball_launcher_launch_samus(pProj); // Calls the launching samus handler
            pProj->status = 0x0;
    }
}

/**
 * 521f0 | 4 | Empty function, purpose unknown (most likely a cancelled projectile)
 * 
 * @param pProj Projectile Data Pointer
 */
void projectile_process_empty(struct projectile_data* pProj)
{
    return;
}

/**
* 521f4 | 114 | Subroutine for the power bomb projectile, further detail is commented in the function
* @param pProj Projectile Data Pointer to the concerned power bomb
*/
void projectile_process_power_bomb(struct projectile_data* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Check first timer ended (power bomb spinning at normal speed)
      0x2 = Check second timer ended and starts the explosion (power bomb spinning fast)
    */
    struct sprite_data* pSprite;
    enum sprite_status status;
    u8 isft;

    switch (pProj->movement_stage)
    {
        case 0x0:
            if (equipment.current_power_bombs != 0x0)
            {
                equipment.current_power_bombs--;
                if (equipment.current_power_bombs == 0x0)
                    samus_weapon_info.weapon_highlighted ^= WH_POWER_BOMB;
            }
            pProj->oam_pointer = power_bomb_oam_326d90;
            pProj->anim_duration_counter = 0x0;
            pProj->curr_anim_frame = 0x0;
            pProj->draw_distance_offset = 0x20;
            pProj->hitbox_top_offset = -0x10;
            pProj->hitbox_bottom_offset = 0x10;
            pProj->hitbox_left_offset = -0x10;
            pProj->hitbox_right_offset = 0x10;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP);
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x36;
            pProj->movement_stage++;

            pSprite = sprite_data;
            while (pSprite < sprite_data + 24)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS)
                    pSprite->invicibility_stun_flash_timer &= 0x7F;
                pSprite++;
            }
            play_sound1(0x100);
            current_power_bomb.power_bomb_placed = TRUE;
            break;

        case 0x1:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->oam_pointer = power_bomb_oam_326db0;
                pProj->anim_duration_counter = 0x0;
                pProj->curr_anim_frame = 0x0;
                pProj->timer = 0x28;
                pProj->movement_stage++;
            }
            break;

        case 0x2:
            if (game_mode_sub1 == 0x2)
            {
                pProj->timer--;
                if (pProj->timer == 0x0)
                {
                    power_bomb_explosion_start(pProj->x_position, pProj->y_position, 0x0);
                    pProj->status = 0x0;
                }
            }
    }
}