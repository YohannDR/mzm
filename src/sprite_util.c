#include "sprite_util.h"
#include "sprite_debris.h"
#include "particle.h"
#include "samus.h"
#include "location_text.h"
#include "sprites_AI/parasite.h"
#include "globals.h"

void sprite_util_init_location_text(void)
{
    u8 gfx_slot;

    gfx_slot = location_text_get_gfx_slot();
    if (gfx_slot < 0x8)
    {
        sprite_data[0x0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN | SPRITE_STATUS_UNKNOWN3;
        sprite_data[0x0].properties = SP_MESSAGE_BANNER;
        sprite_data[0x0].spriteset_gfx_slot = gfx_slot;
        sprite_data[0x0].sprite_id = PSPRITE_AREA_BANNER;
        sprite_data[0x0].y_position = samus_data.y_position;
        sprite_data[0x0].x_position = samus_data.x_position;
        sprite_data[0x0].bg_priority = 0x0;
        sprite_data[0x0].draw_order = 0x1;
        sprite_data[0x0].pose = 0x0;
        sprite_data[0x0].health = 0x0;
        sprite_data[0x0].invicibility_stun_flash_timer = 0x0;
        sprite_data[0x0].palette_row = 0x0;
        sprite_data[0x0].frozen_palette_row_offset = 0x0;
        sprite_data[0x0].maybe_absolute_palette_row = 0x0;
        sprite_data[0x0].ignore_samus_collision_timer = 0x1;
        sprite_data[0x0].primary_sprite_ram_slot = 0x0;
        sprite_data[0x0].freeze_timer = 0x0;
        sprite_data[0x0].standing_on_sprite = FALSE;
    }
}

void unk_e514(u16 y_position, u16 x_position)
{

}

void unk_e5a4(u16 y_position, u16 x_position)
{

}

u8 sprite_util_take_damage_from_sprite(u8 kb_flag, struct sprite_data* pSprite, u16 dmg_mulitplier)
{
    /*u32 damage;
    u32 dmg_reduction;
    struct equipment* pEquipment;
    u16 sprite_dmg;

    if ((pSprite->properties & SP_SECONDARY_SPRITE) != 0x0)
        sprite_dmg = secondary_sprite_stats_2b1be4[pSprite->sprite_id][0x1] * dmg_mulitplier;
    else if ((pSprite->properties & SP_SECONDARY_SPRITE) == 0x0)
        sprite_dmg = primary_sprite_stats_2b0d68[pSprite->sprite_id][0x1] * dmg_mulitplier;

    damage = (u16)sprite_dmg;

    pEquipment = &equipment;
    if ((pEquipment->suit_misc_activation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
        damage = sprite_dmg >> 0x11;
    else
    {
        if ((pEquipment->suit_misc_activation & SMF_GRAVITY_SUIT) != 0x0)
        {
            dmg_reduction = damage * 0x7;
            damage = (u16)(dmg_reduction / 0xA);
        }
        else if ((pEquipment->suit_misc_activation & SMF_VARIA_SUIT) != 0x0)
        {
            dmg_reduction = damage << 0x3;
            damage = (u16)(dmg_reduction / 0xA);
        }
    }

    if (difficulty == 0x0)
        damage >>= 0x1;
    else if (difficulty == 0x2)
        damage = (u16)(damage << 0x1);

    if (damage == 0x0)
        damage = 0x1;

    if (pEquipment->current_energy > damage)
    {
        pEquipment->current_energy -= damage;
        if (kb_flag)
            samus_set_pose(SPOSE_HURT_REQUEST);
        return TRUE;
    }
    else
    {
        pEquipment->current_energy = 0x0;
        samus_set_pose(SPOSE_HURT_REQUEST);
        return FALSE;
    }*/
}

u8 sprite_util_check_objects_touching(u16 o1_top, u16 o1_bottom, u16 o1_left, u16 o1_right, u16 o2_top, u16 o2_bottom, u16 o2_left, u16 o2_right)
{
    if (o2_bottom >= o1_top && o2_top < o1_bottom && o2_right >= o1_left && o2_left < o1_right)
        return TRUE;
    else
        return FALSE;
}

void sprite_util_samus_and_sprite_collision(void)
{
    struct samus_data* pData;
    struct sprite_data* pSprite;
    u16 samus_y;
    u16 samus_x;
    u16 previous_x;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u8 isct;
    u8 unk;
    u8* pTimer;
    u8 dmg_multiplier;
    u8 invincibility;

    pData = &samus_data;
    dmg_multiplier = 0x0;
    samus_y = pData->y_position;
    samus_x = pData->x_position;
    previous_x = previous_x_position;
    samus_top = samus_y + samus_physics.draw_distance_top_offset;
    samus_bottom = samus_y + samus_physics.draw_distance_bottom_offset;
    samus_left = samus_x + samus_physics.draw_distance_left_offset;
    samus_right = samus_x + samus_physics.draw_distance_right_offset;

    if (pData->pose == SPOSE_BALLSPARKING)
    {
        switch (samus_data.forced_movement)
        {
            case 0x0:
                samus_left -= 0x20;
                samus_right += 0x20;
                break;
            case 0x1:
                samus_top -= 0x20;
                samus_bottom += 0x20;
                break;
            default:
                samus_left -= 0x18;
                samus_right += 0x18;
                samus_top -= 0x18;
                samus_bottom += 0x18;
        }
    }
    else if (pData->pose == SPOSE_SHINESPARKING && pData->forced_movement == 0x0)
    {
        samus_left -= 0x20;
        samus_right += 0x20;
    }

    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN))
        {
            isct = pSprite->ignore_samus_collision_timer;
            pTimer = &pSprite->ignore_samus_collision_timer;
            if (isct == 0x0)
            {
                sprite_y = pSprite->y_position;
                sprite_x = pSprite->x_position;
                sprite_top = sprite_y + pSprite->hitbox_top_offset;
                sprite_bottom = sprite_y + pSprite->hitbox_bottom_offset;
                sprite_left = sprite_x + pSprite->hitbox_left_offset;
                sprite_right = sprite_x + pSprite->hitbox_right_offset;
                if (sprite_util_check_objects_touching(samus_top, samus_bottom, samus_left, samus_right, sprite_top, sprite_bottom, sprite_left, sprite_right))
                {
                    collision_related = isct;
                    // Weird calcul ?
                    if (pSprite->freeze_timer == 0x0)
                    {
                        switch (pSprite->samus_collision)
                        {
                            case SSC_IMAGO_EGG:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                collision_related = 0x1;
                            case SSC_SOLID:
                                if (!sprite_util_check_pulling_self_up() && sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (samus_y - 0x18 < sprite_top)
                                    {
                                        sprite_util_check_collision_at_position(sprite_top + samus_physics.draw_distance_top_offset + 0x1, samus_x);
                                        if (previous_collision_check == 0x0 && pData->y_velocity < 0x0)
                                        {
                                            pData->y_position = sprite_top + 0x1;
                                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                            pSprite->standing_on_sprite = 0x2;
                                        }
                                    }
                                    else
                                    {
                                        if (samus_top + 0x10 > sprite_bottom)
                                        {
                                            sprite_util_check_collision_at_position(sprite_bottom - samus_physics.draw_distance_top_offset, samus_x);
                                            if (previous_collision_check == 0x0)
                                            {
                                                pData->y_position = sprite_bottom - samus_physics.draw_distance_top_offset;
                                                if (pData->y_velocity > 0x0 && equipment.current_energy != 0x0)
                                                    pData->y_velocity = 0x0;
                                            }
                                        }
                                        else if (samus_x < sprite_left || samus_x > sprite_right)
                                        {
                                            if (unk & 0x4)
                                                unk_e514(samus_y, sprite_left);
                                            else
                                                unk_e5a4(samus_y, sprite_right);
                                        }
                                    }
                                }
                                break;

                            case SSC_ESCAPE_SHIP:
                                if (!sprite_util_check_pulling_self_up() && sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE && samus_x - 0x18 < sprite_top)
                                {
                                    sprite_util_check_collision_at_position(sprite_top + samus_physics.draw_distance_top_offset + 0x1, sprite_y);
                                    if (previous_collision_check == 0x0 && pData->y_velocity < 0x1)
                                    {
                                        pData->y_position = sprite_top + 0x1;
                                        pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                        pSprite->standing_on_sprite = 0x2;
                                    }
                                }
                                break;

                            case 0x3:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (samus_y - 0x18 < sprite_top)
                                    {
                                        if (!sprite_util_check_pulling_self_up() && pData->invincibility_timer < 0x27)
                                        {
                                            sprite_util_check_collision_at_position(sprite_top + samus_physics.draw_distance_top_offset + 0x1, samus_x);
                                            if (previous_collision_check == 0x0 && pData->y_velocity < 0x10)
                                            {
                                                pData->y_position = sprite_top + 0x1;
                                                pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                                pSprite->standing_on_sprite = 0x2;
                                            }
                                        }
                                    }   
                                    else
                                    {
                                        if (pData->invincibility_timer == 0x0 && sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1))
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                        *pTimer = 0xF;
                                        collision_related = 0x1;
                                    }
                                }
                                break;

                            case SSC_KRAID_SPIKE:
                                if (samus_x > sprite_right)
                                {
                                    if (pData->invincibility_timer == 0x0 && sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x40;
                                        else
                                            pData->x_velocity = 0x40;
                                    }
                                    *pTimer = 0xF;
                                    collision_related = 0x1;
                                }
                                else
                                {
                                    if (samus_y - 0x18 <= sprite_top && !sprite_util_check_pulling_self_up() && pData->invincibility_timer < 0x25)
                                    {
                                        sprite_util_check_collision_at_position(sprite_top + samus_physics.draw_distance_top_offset + 0x1, samus_x);
                                        if (previous_collision_check == 0x0 && pData->y_velocity < 0x0)
                                        {
                                            pData->y_position = sprite_top + 0x1;
                                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                            pSprite->standing_on_sprite = 0x2;
                                        }
                                    }
                                }
                                break;

                            case SSC_ABILITY_LASER_SEARCHLIGHT:
                            case SSC_SMALL_ENERGY_DROP:
                            case SSC_LARGE_ENERGY_DROP:
                            case SSC_MISSILE_DROP:
                            case SSC_SUPER_MISSILE_DROP:
                            case SSC_POWER_BOMB_DROP:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                break;

                            case SSC_ACID_WORM_MOUTH:
                                break;

                            case SSC_ACID_WORM:
                                break;

                            case SSC_SPACE_PIRATE_LASER:
                            case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT:
                                pSprite->pose = 0x42; // Set destroyed pose
                            case SSC_MELLOW:
                            case SSC_HURTS_SAMUS:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibility_timer == 0x0 && sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x40;
                                        else
                                            pData->x_position = 0x40;
                                    }
                                    *pTimer = 0xF;
                                    collision_related = 0x1;
                                }
                                break;

                            case 0xF:
                                break;
                            case 0xE:
                                //
                            case SSC_IMAGO_STINGER:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibility_timer == 0x0 && sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x80;
                                        else
                                            pData->x_velocity = 0x80;
                                    }
                                    *pTimer = 0xF;
                                    collision_related = 0x1;
                                }
                                break;

                            case SSC_ATOMIC_DISCHARGE:
                                break;

                            case SSC_SPACE_PIRATE:
                                break;
                    
                            case 0x9:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibility_timer < 0x8)
                                {
                                    sprite_util_take_damage_from_sprite(FALSE, pSprite, 0x1);
                                    if (equipment.current_energy != 0x0)
                                        pData->invincibility_timer = 0x8;
                                }
                                *pTimer = 0xF;
                                break;

                            case 0x10:
                                pSprite->pose = 0x42;
                            case 0x11:
                                sprite_util_take_damage_from_sprite(FALSE, pSprite, 0x1);
                                *pTimer = 0xF;
                                if (pData->invincibility_timer == 0x0)
                                    pData->invincibility_timer = 0x0;
                                collision_related = 0x1;
                                break;

                            case SSC_ZIPLINE:
                                if (unk & 0x2)
                                {
                                    switch (pData->pose)
                                    {
                                        case SPOSE_MIDAIR:
                                        case SPOSE_SPINNING:
                                            pData->y_position = pSprite->y_position + 0xA8;
                                            pData->x_position = pSprite->x_position;
                                            previous_y_position = pData->y_position;
                                            previous_x_position = pData->x_position;
                                            samus_set_pose(SPOSE_ON_ZIPLINE);
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            break;

                                        case SPOSE_BALLSPARKING:
                                            play_sound2(0x8F);
                                        case SPOSE_MORPH_BALL_MIDAIR:
                                            pData->y_position = pSprite->y_position + 0x3C;
                                            pData->x_position = pSprite->x_position;
                                            previous_y_position = pData->y_position;
                                            previous_x_position = pData->x_position;
                                            samus_set_pose(SPOSE_MORPH_BALL_ON_ZIPLINE);
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            break;
                                    }
                                    *pTimer = 0xF;
                                    collision_related = 0x1;
                                }
                                break;

                            case SSC_ZEBETITE:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        unk_e514(samus_y, sprite_left);
                                    else
                                        unk_e5a4(samus_y, sprite_right);
                                }
                                break;

                            case SSC_HURTS_SAMUS_NO_PASS_THROUGH:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        unk_e514(samus_y, sprite_left);
                                    else
                                        unk_e5a4(samus_y, sprite_right);

                                    if (pData->invincibility_timer == 0x0)
                                    {
                                        if (sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1) && previous_collision_check == 0x0)
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                        collision_related = 0x1;
                                    }
                                }
                                break;

                            case SSC_KRAID:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        unk_e514(samus_y, sprite_left);
                                    else
                                        unk_e5a4(samus_y, sprite_right);

                                    if (pData->invincibility_timer == 0x0)
                                    {
                                        if (sprite_util_take_damage_from_sprite(TRUE, pSprite, 0x1) && previous_collision_check == 0x0)
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                    }
                                    else if (previous_collision_check == 0x0)
                                    {
                                        sprite_util_check_collision_at_position(samus_y + samus_physics.draw_distance_top_offset + 0x1, samus_x);
                                        if (previous_collision_check == 0x0)
                                        {
                                            samus_set_pose(SPOSE_KNOCKBACK_REQUEST);
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                    }
                                    collision_related = 0x1;
                                }
                                break;

                            case SSC_KNOCKS_BACK_SAMUS:
                                if (sprite_util_sprite_take_damage_from_samus_contact(pSprite, pData) == DCT_NONE)
                                {
                                    samus_set_pose(SPOSE_KNOCKBACK_REQUEST);
                                    if (unk & 0x4)
                                        pData->x_velocity = -0x20;
                                    else
                                        pData->x_position = 0x20;
                                }
                                collision_related = 0x1;
                                break;

                            case SSC_BUG:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibility_timer == 0x0 && (equipment.suit_misc_activation & (SMF_VARIA_SUIT & SMF_GRAVITY_SUIT)) == 0x0)
                                {
                                    if (parasite_count() && sprite_util_take_damage_from_sprite(FALSE, pSprite, dmg_multiplier >> 0x2))
                                    {
                                        pData->invincibility_timer = 0x10;
                                        unk_2b20(0x80);
                                        sub_sprite_data1.timer++;
                                        if ((sub_sprite_data1.timer & 0x3) == 0x0)
                                            play_sound1(0x7C);
                                    }
                                }
                                *pTimer = 0xF;
                                break;

                            case SSC_METROID:
                                if (samus_y > sprite_y + 0x20)
                                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibility_timer == 0x0 && sprite_util_take_damage_from_sprite(FALSE, pSprite, 0x1))
                                {
                                    if (equipment.suit_misc_activation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT) == 0x0)
                                        pData->invincibility_timer = 0x2;
                                    else if ((equipment.suit_misc_activation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
                                        pData->invincibility_timer = 0x8;
                                    else
                                        pData->invincibility_timer = 0x4;
                                }
                                break;

                            case SSC_RIDLEY_CLAW:
                                break;

                            case SSC_MECHA_RIDLEY:
                                dmg_multiplier = 0x1;
                                if (sprite_util_get_final_completion_percentage() == 0x64)
                                    dmg_multiplier = 0x2;
                                if (sprite_util_take_damage_from_sprite(TRUE, pSprite, dmg_multiplier))
                                    pData->x_velocity = -0x80;
                                *pTimer = 0xF;
                                collision_related = 0x1;

                            case 0x8:
                            default:
                                *pTimer = 0xF;
                                collision_related = 0x1;
                        }

                        if (collision_related != 0x0)
                            break;
                    }
                }
            }
        }
        pSprite++;
    }

    pSprite = sprite_data;
    while (pSprite < sprite_data + 24)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->ignore_samus_collision_timer != 0x0)
            pSprite->ignore_samus_collision_timer--;
    }
}

u16 sprite_util_check_vertical_collision_at_position(u16 y_position, u16 x_position)
{

}

u16 sprite_util_check_vertical_collision_at_position_slopes(u16 y_position, u16 x_position)
{

}

void unk_f594(void)
{

}

void unk_f608(void)
{

}

void sprite_util_check_collision_at_position(u16 y_position, u16 x_position)
{

}

u8 sprite_util_check_collision_at_position_no_global(u16 y_position, u16 x_position)
{

}

void sprite_util_current_sprite_fall(void)
{

}

void sprite_util_choose_random_x_flip(void)
{
    if ((sprite_rng & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        current_sprite.status |= SPRITE_STATUS_XFLIP;
}

void sprite_util_choose_random_x_direction(void)
{
    if ((sprite_rng & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void sprite_util_choose_random_x_direction_room_slot(u8 room_slot)
{
    if ((current_sprite.room_slot & 0x1) != 0x0)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void sprite_util_make_sprite_face_samus_x_flip(void)
{
    if (current_sprite.x_position > samus_data.x_position)
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        current_sprite.status |= SPRITE_STATUS_XFLIP;
}

void sprite_util_make_sprite_face_samus_direction(void)
{
    if (current_sprite.x_position > samus_data.x_position)
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void sprite_util_make_sprite_face_away_samus_x_flip(void)
{
    if (current_sprite.x_position > samus_data.x_position)
        current_sprite.status |= SPRITE_STATUS_XFLIP;
    else
        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
}

void sprite_util_make_sprite_face_away_samus_direction(void)
{
    if (current_sprite.x_position > samus_data.x_position)
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
}

void unk_f978(i16 movement)
{

}

void unk_f9e7(i16 movement)
{

}

u8 sprite_util_make_sprite_face_samus_rotation(u8 oam_rotation, u16 samus_y, u16 samus_x, u16 sprite_y, u16 sprite_x)
{

}

u8 sprite_util_check_end_current_sprite_anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = current_sprite.anim_duration_counter;
    curr_anim = current_sprite.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)current_sprite.oam_pointer[curr_anim].timer < adc && (u8)current_sprite.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 sprite_util_check_near_end_current_sprite_anim(void)
{
    /*u32 adc;
    u16 curr_anim;
    
    adc = current_sprite.anim_duration_counter;
    curr_anim = current_sprite.curr_anim_frame;
    adc = ((adc << 0x18) + 0x2000000) >> 0x18;

    if ((u8)current_sprite.oam_pointer[curr_anim].timer < adc &&
    (u8)current_sprite.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;*/
}

u8 sprite_util_check_end_sprite_anim(u8 ram_slot)
{
    u8 adc;
    u16 curr_anim;

    adc = sprite_data[ram_slot].anim_duration_counter;
    curr_anim = sprite_data[ram_slot].curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)sprite_data[ram_slot].oam_pointer[curr_anim].timer < adc && (u8)sprite_data[ram_slot].oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 sprite_util_check_near_end_sprite_anim(u8 ram_slot)
{

}

u8 sprite_util_check_end_sub_sprite1_anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = sub_sprite_data1.anim_duration_counter;
    curr_anim = sub_sprite_data1.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)sub_sprite_data1.oam_pointer[curr_anim].timer < adc && (u8)sub_sprite_data1.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 sprite_util_check_near_end_sub_sprite1_anim(void)
{

}

u8 sprite_util_check_end_sub_sprite2_anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = sub_sprite_data2.anim_duration_counter;
    curr_anim = sub_sprite_data2.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)sub_sprite_data2.oam_pointer[curr_anim].timer < adc && (u8)sub_sprite_data2.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 sprite_util_check_end_sub_sprite_anim(struct sub_sprite_data* pSub)
{
    u8 adc;
    u16 curr_anim;

    adc = pSub->anim_duration_counter;
    curr_anim = pSub->curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)pSub->oam_pointer[curr_anim].timer < adc && (u8)pSub->oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 sprite_util_check_near_end_sub_sprite_anim(struct sub_sprite_data* pSub)
{

}

enum near_sprite_left_right sprite_util_check_samus_near_sprite_left_right(u16 y_range, u16 x_range)
{
    /*struct samus_data* pData;
    enum near_sprite_left_right result;
    u16 samus_y;
    u16 samus_x;
    u16 sprite_y;
    u16 sprite_x;
    i32 difference;

    result = NSLR_OUT_OF_RANGE;
    pData = &samus_data;
    samus_y = (samus_physics.draw_distance_top_offset / 0x2) + pData->y_position;
    samus_x = pData->x_position;
    sprite_y = current_sprite.y_position;
    sprite_x = current_sprite.x_position;

    if (sprite_y > samus_y)
        difference = sprite_x - sprite_y;
    else
        difference = sprite_y - samus_y;

    if (difference >= y_range)
        return NSLR_OUT_OF_RANGE;
    else
    {
        if (sprite_x > samus_x)
        {
            if ((i32)(sprite_x - samus_x) < x_range)
                result = NSLR_LEFT;
        }
        else
        {
            if ((i32)(samus_x - sprite_x) < x_range)
                result = NSLR_RIGHT;
        }
    }

    return result;*/
}

enum near_sprite_above_below sprite_util_check_samus_near_sprite_above_below(u16 y_range, u16 x_range)
{

}

u8 sprite_util_check_samus_near_sprite_front_behind(u16 y_range, u16 x_range_front, u16 x_range_behind)
{

}

void sprite_util_samus_standing_on_sprite(struct sprite_data* pSprite)
{
    u8 standing;

    if ((pSprite->status & SPRITE_STATUS_SAMUS_ON_TOP) != 0x0)
    {
        if (samus_data.standing_status != STANDING_ENEMY)
        {
            if (samus_data.standing_status == STANDING_MIDAIR)
                samus_set_pose(SPOSE_LANDING_REQUEST);
            samus_data.standing_status = STANDING_ENEMY;
        }
        pSprite->status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
        return;
    }

    standing = pSprite->standing_on_sprite;
    if (standing != 0x1)
    {            
        if (standing == 0x2)
        {
            pSprite->standing_on_sprite = TRUE;
            if (samus_data_copy.y_position <= samus_data.y_position)
                samus_data.y_position = pSprite->y_position + pSprite->hitbox_top_offset + 0x1;
        }
    }
    else
    {
        pSprite->standing_on_sprite = FALSE;
        if (samus_data.standing_status == STANDING_ENEMY)
            samus_data.standing_status = STANDING_MIDAIR;
    }
}

void sprite_util_update_freeze_timer(void)
{
    /*u8 freeze_timer;

    if ((eight_bit_frame_counter & 0x1) != 0x0)
        current_sprite.freeze_timer--;

    freeze_timer = current_sprite.freeze_timer;

    if (freeze_timer == 0x0)
        current_sprite.anim_duration_counter--;
    
    if (freeze_timer < 0x2E && (freeze_timer & 0x1) != 0x0)
        current_sprite.palette_row = 0xF - (current_sprite.spriteset_gfx_slot + current_sprite.frozen_palette_row_offset);
    else
        current_sprite.palette_row = current_sprite.maybe_absolute_palette_row;*/
}

void sprite_util_unfreeze_anim_easy(void)
{
    u8 freeze_timer;

    current_sprite.freeze_timer--;

    freeze_timer = current_sprite.freeze_timer;
    if (freeze_timer == 0x0)
        current_sprite.anim_duration_counter--;
    if (freeze_timer < 0x5B && (freeze_timer & 0x1) == 0x0)
    {
        if ((freeze_timer & 0x2) != 0x0)
            current_sprite.palette_row = 0xF - (current_sprite.spriteset_gfx_slot + current_sprite.frozen_palette_row_offset);
        else
            current_sprite.palette_row = current_sprite.maybe_absolute_palette_row;
    }
}

void sprite_util_metroid_unfreeze_anim(void)
{
    u8 freeze_timer;

    current_sprite.freeze_timer -= 0x2;

    freeze_timer = current_sprite.freeze_timer;
    if (freeze_timer == 0x0)
        current_sprite.anim_duration_counter--;
    if (freeze_timer < 0x79 && (freeze_timer & 0x2) == 0x0)
    {
        if ((freeze_timer & 0x4) != 0x0)
            current_sprite.palette_row = 0xF - (current_sprite.spriteset_gfx_slot + current_sprite.frozen_palette_row_offset);
        else
            current_sprite.palette_row = current_sprite.maybe_absolute_palette_row;
    }
}

void sprite_util_update_secondary_sprite_freeze_timer_of_current(enum s_sprite_id sprite_id, u8 ram_slot)
{
    u8 count;

    if (current_sprite.freeze_timer != 0x0)
    {
        count = 0x0;
        while (count < 0x18)
        {
            if ((sprite_data[count].status & SPRITE_STATUS_EXISTS) != 0x0
                && (sprite_data[count].properties & SP_SECONDARY_SPRITE) != 0x0
                && sprite_data[count].sprite_id == sprite_id
                && sprite_data[count].primary_sprite_ram_slot == ram_slot
                && sprite_data[count].freeze_timer < current_sprite.freeze_timer
                && (sprite_data[count].properties & SP_MAYBE_DESTROYED) == 0x0)
            {
                sprite_data[count].freeze_timer = current_sprite.freeze_timer;
                sprite_data[count].palette_row = 0xF - (sprite_data[count].spriteset_gfx_slot + sprite_data[count].frozen_palette_row_offset);
            }
            count++;
        }
    }
}

void sprite_util_update_primary_sprite_freeze_timer_of_current(void)
{
    if (current_sprite.freeze_timer != 0) {
        u8 count = current_sprite.primary_sprite_ram_slot;
        if (sprite_data[count].freeze_timer < current_sprite.freeze_timer && (sprite_data[count].properties & SP_MAYBE_DESTROYED) == 0)
        {
            sprite_data[count].freeze_timer = current_sprite.freeze_timer;
            sprite_data[count].palette_row = 0xf - (sprite_data[count].spriteset_gfx_slot + sprite_data[count].frozen_palette_row_offset);
        } 
    }
}

void sprite_util_unfreeze_secondary_sprites(enum s_sprite_id sprite_id, u8 ram_slot)
{
    u8 count = 0;
    do
    {
        if ((sprite_data[count].status & SPRITE_STATUS_EXISTS) != 0x0
            && (sprite_data[count].properties & SP_SECONDARY_SPRITE) != 0x0
            && sprite_data[count].sprite_id == sprite_id
            && sprite_data[count].primary_sprite_ram_slot == ram_slot
            && sprite_data[count].freeze_timer != 0x0)
        {
            sprite_data[count].freeze_timer = 0x0;
            sprite_data[count].palette_row = 0x0;
        }
        count++;
    }
    while (count < 0x18);
}

u8 sprite_util_refill_energy(void)
{
    /*u16 increment;

    if (equipment.max_energy > equipment.current_energy)
    {
        increment = (u16)(equipment.max_energy - equipment.current_energy);
        increment >>= 0x5;
        if (increment == 0x0)
            increment = 0x1;
        else if (0xA < increment)
            increment = 0xB;
        
        equipment.current_energy += increment;
        if ((u16)equipment.current_energy > equipment.max_energy)
            equipment.current_energy = equipment.max_energy;
        
        return TRUE;
    }
    else
        return FALSE;*/
}

u8 sprite_util_refill_missile(void)
{
    u16 increment;
    u16 max;
    u32 energy;
    
    energy = equipment.current_missiles;
    max = equipment.max_missiles;

    if (energy < max)
    {
        increment = (u16)((equipment.max_missiles - equipment.current_missiles) >> 0x5);
        if (increment == 0x0)
            increment = 0x1;
        else if (0x5 < increment)
            increment = 0x6;
        
        energy = equipment.current_missiles;
        equipment.current_missiles = (energy + increment);
        if ((u16)(increment + energy) > equipment.max_missiles)
            equipment.current_missiles = equipment.max_missiles;
        
        return TRUE;
    }
    else
        return FALSE;
}

u8 sprite_util_refull_super_missiles(void)
{
    u16 increment;
    u16 max;
    u32 energy;
    
    energy = equipment.current_super_missiles;
    max = equipment.max_super_missiles;

    if (energy < max)
    {
        increment = (u16)((equipment.max_super_missiles - equipment.current_super_missiles) >> 0x5);
        if (increment == 0x0)
            increment = 0x1;
        else if (0x3 < increment)
            increment = 0x4;
        
        energy = equipment.current_super_missiles;
        equipment.current_super_missiles = (energy + increment);
        if ((u16)(increment + energy) > equipment.max_super_missiles)
            equipment.current_super_missiles = equipment.max_super_missiles;
        
        return TRUE;
    }
    else
        return FALSE;
}

u8 sprite_util_refill_power_bombs(void)
{
    u16 increment;
    u16 max;
    u32 energy;
    
    energy = equipment.current_power_bombs;
    max = equipment.max_power_bombs;

    if (energy < max)
    {
        increment = (u16)((equipment.max_power_bombs - equipment.current_power_bombs) >> 0x5);
        if (increment == 0x0)
            increment = 0x1;
        else if (0x3 < increment)
            increment = 0x4;
        
        energy = equipment.current_power_bombs;
        equipment.current_power_bombs = (energy + increment);
        if ((u16)(increment + energy) > equipment.max_power_bombs)
            equipment.current_power_bombs = equipment.max_power_bombs;
        
        return TRUE;
    }
    else
        return FALSE;
}

u8 sprite_util_check_crouching_or_morphed(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_crouching_or_crawling(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_morphed(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_stop_sprites_pose(void)
{
    if (prevent_movement_timer == 0x0)
    {
        switch (samus_data.pose)
        {
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_FACING_THE_FOREGROUND:
                return TRUE;
        }
    }
    else
        return TRUE;
    
    return FALSE;
}

/**
 * 104f8 | 1b0 | 
 * Handles a sprite taking damage from a contact with samus
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param pData Samus Data Pointer
 * @return The damage contact type
 */
enum damage_contact_type sprite_util_sprite_take_damage_from_samus_contact(struct sprite_data* pSprite, struct samus_data* pData)
{
    enum damage_contact_type dct;
    enum sprite_properties* pProps;
    struct equipment* pEquipment;
    enum sprite_weakness_flags weakness;
    enum beam_bombs_flags bbf;
    u32 damage;
    u8 is_dead;
    u8 isft;

    dct = DCT_NONE;
    if (equipment.suit_type == SUIT_SUITLESS)
        return DCT_NONE;

    pProps = &pSprite->properties;
    if ((pSprite->properties & (SP_SOLID_FOR_PROJECTILES | SP_IMMUNE_TO_PROJECTILES)) != 0x0)
        return DCT_NONE;

    if ((pSprite->status & SPRITE_STATUS_UNKNOWN3) != 0x0)
        return DCT_NONE;

    if (pData->speedboosting_shinesparking != FALSE)
    {
        if (pData->pose == SPOSE_SHINESPARKING || pData->pose == SPOSE_BALLSPARKING)
            dct = DCT_SHINESPARK;
        else
            dct = DCT_SPEEDBOOSTER;
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_SCREW_ATTACKING:
                dct = DCT_SCREW_ATTACK;
                break;
            
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_STARTING_WALL_JUMP:
            case SPOSE_SPACE_JUMPING:
                if (0x3F < samus_weapon_info.charge_counter)
                    dct = DCT_SUDO_SCREW;
            
            default:
                if (dct == DCT_NONE)
                    return DCT_NONE;
        }
    }

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        weakness = secondary_sprite_stats_2b1be4[pSprite->sprite_id][0x2];
    else if ((pSprite->properties & SP_SECONDARY_SPRITE) == 0x0)
        weakness = primary_sprite_stats_2b0d68[pSprite->sprite_id][0x2];

    if (dct >= DCT_SUDO_SCREW)
    {
        if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
        {
            samus_weapon_info.charge_counter = 0x0;
            damage = 0x2;
            bbf = equipment.beam_bombs_activation;
            if ((equipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                damage = 0x3;
            if ((equipment.beam_bombs_activation & BBF_ICE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((equipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((bbf & BBF_PLASMA_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);

            damage = (u16)(damage << 0x2);
            is_dead = projectile_deal_damage(pSprite, damage);
            if (is_dead != FALSE)
            {
                pSprite->pose = 0x66;
                return dct;
            }
            pSprite->ignore_samus_collision_timer = 0x0;
            dct = DCT_NONE;
        }
    }
    else
    {
        if ((weakness & WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK) != 0x0)
        {
            pSprite->health = 0x0;
            pSprite->properties |= SP_MAYBE_DESTROYED;
            pSprite->freeze_timer = 0x0;
            pSprite->palette_row = 0x0;
            if (pSprite->standing_on_sprite != FALSE && pData->standing_status == STANDING_ENEMY)
            {
                pData->standing_status = STANDING_MIDAIR;
                pSprite->standing_on_sprite = FALSE;
            }

            if (dct == DCT_SHINESPARK)
                pSprite->pose = 0x63;
            else if (dct == DCT_SPEEDBOOSTER)
                pSprite->pose = 0x64;
            else
                pSprite->pose = 0x65;

            pSprite->ignore_samus_collision_timer = 0x1;
            pSprite->invicibility_stun_flash_timer = pSprite->invicibility_stun_flash_timer & 0x80 | 0x11;
            pSprite->properties |= SP_UNKNOWN;
            return dct;
        }

        isft = 0x3;
        if ((pSprite->invicibility_stun_flash_timer & 0x7F) < isft)
            pSprite->invicibility_stun_flash_timer = pSprite->invicibility_stun_flash_timer & 0x80 | 0x3;
        dct = DCT_NONE;
    }

    return dct;
}

u8 sprite_util_check_pulling_self_up(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
           return TRUE;
    }

    return FALSE;
}

u8 sprite_util_check_on_zipline(void)
{
    switch (samus_data.pose)
    {
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
           return TRUE;
    }

    return FALSE;
}

u8 sprite_util_count_primary_sprites(enum p_sprite_id sprite_id)
{
    u8 count;
    struct sprite_data* pSprite;

    count = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id)
            count++;
        pSprite++;
    }

    return count;
}

u8 sprite_util_count_secondary_sprites_with_current_sprite_ram_slot(enum s_sprite_id sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct sprite_data* pSprite;

    count = 0x0;
    ram_slot = current_sprite.primary_sprite_ram_slot;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->sprite_id == sprite_id && pSprite->primary_sprite_ram_slot == ram_slot)
            count++;
        pSprite++;
    }

    return count;
}

u8 sprite_util_count_secondary_sprites_with_current_sprite_ram_slot(enum p_sprite_id sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct sprite_data* pSprite;

    count = 0x0;
    ram_slot = current_sprite.primary_sprite_ram_slot;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id && pSprite->primary_sprite_ram_slot == ram_slot)
            count++;
        pSprite++;
    }

    return count;
}

u8 sprite_util_find_primary(enum p_sprite_id sprite_id)
{
    u8 ram_slot;
    struct sprite_data* pSprite;

    ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id)
            return ram_slot;
        ram_slot++;
        pSprite++;
    }

    return 0xFF;
}

u8 sprite_util_find_secondary_with_room_slot(enum s_sprite_id sprite_id, u8 room_slot)
{
    u8 ram_slot;
    struct sprite_data* pSprite;

    ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->sprite_id == sprite_id && pSprite->room_slot == room_slot)
            return ram_slot;
        ram_slot++;
        pSprite++;
    }

    return 0xFF;
}

u8 sprite_util_check_has_drop(void)
{
    u8 ram_slot;
    struct sprite_data* pSprite;
    enum sprite_samus_collision collision;

    ram_slot = current_sprite.primary_sprite_ram_slot;
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    pSprite = sprite_data;

    while (pSprite< sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->primary_sprite_ram_slot == ram_slot && pSprite->samus_collision >= collision)
            return TRUE;
        pSprite++;
    }

    return FALSE;
}

u8 sprite_util_count_drops(void)
{
    u8 count;
    struct sprite_data* pSprite;

    count = 0x0;
    pSprite = sprite_data;

    while (pSprite< sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
        pSprite++;
    }

    return count;
}

void sprite_util_maybe_mecha_ridley_missile_move(u16 samus_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

void sprite_util_maybe_ridley_fireball_move(u16 sprite_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

void sprite_util_update_stun_timer(struct sprite_data* pSprite)
{

}

void sprite_util_random_debris(u8 cloud_type, u8 number, u16 y_position, u16 x_position)
{
    switch (number)
    {
        case 0x1:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
                sprite_debris_init(cloud_type, 0x1, y_position + 0x8, x_position - 0x8);
            else
                sprite_debris_init(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
            break;
        case 0x2:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
            {
                sprite_debris_init(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position, x_position + 0x8);
            }
            else
            {
                sprite_debris_init(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
            break;
        case 0x3:
            if ((eight_bit_frame_counter & 0x1) == 0x0)
            {
                sprite_debris_init(cloud_type, 0x2, y_position - 0x10, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position + 0x8, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x10, x_position - 0x8);
            }
            else
            {
                sprite_debris_init(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                sprite_debris_init(cloud_type, 0x3, y_position - 0x10, x_position + 0x8);
                sprite_debris_init(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
    }
}

enum p_sprite_id sprite_util_get_ammo_drop(u8 rng)
{
    if (equipment.current_energy == equipment.max_energy)
    {
        if ((rng & 0x1) != 0x0 && equipment.max_missiles > equipment.current_missiles)
            return PSPRITE_MISSILE_DROP;
        if ((rng & 0x2) != 0x0 && equipment.max_super_missiles > equipment.current_super_missiles)
            return PSPRITE_SUPER_MISSILE_DROP;
        if ((rng & 0x4) != 0x0 && equipment.max_power_bombs > equipment.current_power_bombs)
            return PSPRITE_POWER_BOMB_DROP;
    }
    return PSPRITE_UNUSED0;
}

enum p_sprite_id sprite_util_determine_enemy_drop(void)
{
    /*u16 small_health_prob;
    u16 large_health_prob;
    u16 missile_prob;
    u16 super_missile_prob;
    u16 power_bomb_drop;
    u16 non_power_bomb_drop;
    u16 non_drop;
    u32 is_full;
    u32 rng;
    u16 sprite_id;
    enum p_sprite_id drop;

    drop = 0x0;
    is_full = FALSE;
    if (equipment.current_energy == equipment.max_energy)
        is_full = TRUE;

    rng = sprite_rng;
    rng *= 0x100;
    rng = (u16)(rng + (eight_bit_frame_counter + sixteen_bit_frame_counter) << 0x6) >> 0x6;
    if (rng == 0x0)
        rng = 0x1;

    sprite_id = current_sprite.sprite_id;
    if (current_sprite.properties & SP_SECONDARY_SPRITE)
    {
        small_health_prob = secondary_sprite_stats_2b1be4[sprite_id][0x4];
        large_health_prob = secondary_sprite_stats_2b1be4[sprite_id][0x5];
        missile_prob = secondary_sprite_stats_2b1be4[sprite_id][0x6];
        super_missile_prob = secondary_sprite_stats_2b1be4[sprite_id][0x7];
        power_bomb_drop = secondary_sprite_stats_2b1be4[sprite_id][0x8];
    }
    else
    {
        small_health_prob = primary_sprite_stats_2b0d68[sprite_id][0x4];
        large_health_prob = primary_sprite_stats_2b0d68[sprite_id][0x5];
        missile_prob = primary_sprite_stats_2b0d68[sprite_id][0x6];
        super_missile_prob = primary_sprite_stats_2b0d68[sprite_id][0x7];
        power_bomb_drop = primary_sprite_stats_2b0d68[sprite_id][0x8];
    }

    if (power_bomb_drop != 0x0)
    {
        non_power_bomb_drop = 0x400 - power_bomb_drop;
        if (rng < 0x401 && rng > non_power_bomb_drop)
        {
            if (equipment.max_power_bombs <= equipment.current_power_bombs)
            {
                if (!is_full)
                {
                    if (equipment.max_power_bombs != 0x0)
                        drop = PSPRITE_POWER_BOMB_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }
            else
                drop = PSPRITE_POWER_BOMB_DROP;
        }
    }
    else
    {
        non_power_bomb_drop = 0x400;
        if (super_missile_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - super_missile_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (equipment.max_super_missiles <= equipment.current_super_missiles)
                    {
                        if (is_full)
                            drop = PSPRITE_LARGE_ENERGY_DROP;
                        else if (equipment.max_super_missiles == 0x0)
                            drop = PSPRITE_SMALL_ENERGY_DROP;
                    }
                    else
                        drop = PSPRITE_SUPER_MISSILE_DROP;
                }
            }
        }
        else if (missile_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - missile_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (equipment.max_missiles <= equipment.current_missiles)
                    {
                        if (!is_full)
                        {
                            if (equipment.max_missiles != 0x0)
                                drop = PSPRITE_MISSILE_DROP;
                            else
                                drop = PSPRITE_SMALL_ENERGY_DROP;
                        }
                        else
                            drop = PSPRITE_LARGE_ENERGY_DROP;
                    }
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
            }
        }
        else if (large_health_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - large_health_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (is_full)
                        drop = PSPRITE_LARGE_ENERGY_DROP;
                    else if (equipment.max_missiles <= equipment.current_missiles)
                        drop = PSPRITE_LARGE_ENERGY_DROP;
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
            }
        }
        else if (small_health_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - small_health_prob;
            if (non_power_bomb_drop >= rng && rng > non_drop)
            {
                if (!is_full)
                {
                    if (equipment.max_missiles <= equipment.current_missiles)
                        drop = 0x0;
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
                else
                    drop = PSPRITE_SMALL_ENERGY_DROP;
            }
        }
    }
   
    return drop;*/
}

void sprite_util_sprite_death(enum death_type death_type, u16 y_position, u16 x_position, u8 play_sound, enum particle_effect_id effect)
{
    enum p_sprite_id drop;

    switch (current_sprite.pose)
    {
        case 0x63:
            particle_set(y_position, x_position, PE_SHINESPARK_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x131);
            break;
        case 0x64:
            particle_set(y_position, x_position, PE_SPEEDBOOSTER_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x133);
            break;
        case 0x65:
            particle_set(y_position, x_position, PE_SCREW_ATTACK_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x130);
            break;
        case 0x66:
            particle_set(y_position, x_position, PE_SUDO_SCREW_DESTROYED);
            sprite_util_random_debris(0x0, 0x3, y_position, x_position);
            play_sound1(0x132);
            break;
        default:
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_SMALL);
                if (play_sound != FALSE)
                    play_sound1(0x12C);
            }
            else
            {
                if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
                {
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_MEDIUM);
                    if (play_sound != FALSE)
                        play_sound1(0x12D);
                }
                else
                {
                    if (effect == PE_SPRITE_EXPLOSION_BIG)
                    {
                        particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_BIG);
                        if (play_sound != FALSE)
                            play_sound1(0x12E);
                    }
                    else
                    {
                        if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
                        {
                            particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                            if (play_sound != FALSE)
                                play_sound1(0x12F);
                        }
                        else
                        {
                            if ((u8)(effect - 0x27) < 0x3)
                                particle_set(y_position, x_position, effect);
                        }
                    }
                }
            }
    }

    drop = sprite_util_determine_enemy_drop();
    if (drop != 0x0)
    {       
        if (death_type != DEATH_NORMAL)
        {
            if (death_type != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
                sprite_spawn_drop_followers(drop, current_sprite.room_slot, 0x0, current_sprite.primary_sprite_ram_slot, y_position, x_position, 0x0);
        }
        else
        {
            current_sprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            current_sprite.properties = 0x0;
            current_sprite.spriteset_gfx_slot = 0x0;
            current_sprite.sprite_id = drop;
            current_sprite.y_position = y_position;
            current_sprite.x_position = x_position;
            current_sprite.bg_priority = 0x2;
            current_sprite.draw_order = 0x4;
            current_sprite.pose = 0x0;
            current_sprite.health = 0x0;
            current_sprite.invicibility_stun_flash_timer = 0x0;
            current_sprite.palette_row = 0x0;
            current_sprite.frozen_palette_row_offset = 0x0;
            current_sprite.maybe_absolute_palette_row = 0x0;
            current_sprite.ignore_samus_collision_timer = 0x1;
            current_sprite.freeze_timer = 0x0;
        }
    }
    else
    {
        if (death_type == DEATH_NORMAL)
            current_sprite.status = 0x0;
    }
}

u8 sprite_util_is_sprite_stunned(void)
{
    u8 is_stunned;
    u8 stun_timer;
    u8 diff;

    is_stunned = FALSE;
    diff = difficulty;
    
    stun_timer = 0xE;
    if (diff < 0x2)
        stun_timer = 0x9;

    if (((current_sprite.invicibility_stun_flash_timer & 0x7F) > stun_timer) && current_sprite.pose < 0x62)
    {
        if (current_sprite.anim_duration_counter != 0x0)
            current_sprite.anim_duration_counter--;
        is_stunned = TRUE;
    }

    return is_stunned;
}

u8 sprite_util_is_sprite_on_screen_and_screen_shake(void)
{
    if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0 && (screen_shake_y.timer != 0x0 || screen_shake_x.timer != 0x0))
        return TRUE;
    else
        return FALSE;
}

void sprite_util_maybe_update_sub_sprite1_timer(void)
{
    /*u8 adc;
    u32 caf;
    u8 timer;
    
    sub_sprite_data1.timer = 0x0;
    adc = (u8)(sub_sprite_data1.anim_duration_counter + 0x1);
    caf = sub_sprite_data1.curr_anim_frame;
    if ((u8)sub_sprite_data1.oam_pointer[caf].timer < adc)
    {
        timer = caf + 0x1;
        sub_sprite_data1.timer = timer;
    }*/
}

void sprite_util_update_sub_sprite1_anim(void)
{
    u32 adc;

    adc = sub_sprite_data1.anim_duration_counter + 0x1;
    sub_sprite_data1.anim_duration_counter = adc;
    if ((u8)sub_sprite_data1.oam_pointer[sub_sprite_data1.curr_anim_frame].timer < (u8)adc)
    {
        sub_sprite_data1.anim_duration_counter = 0x1;
        sub_sprite_data1.curr_anim_frame++;
        if ((u8)sub_sprite_data1.oam_pointer[sub_sprite_data1.curr_anim_frame].timer == 0x0)
            sub_sprite_data1.curr_anim_frame = 0x0;
    }
}

void sprite_util_sync_current_sprite_position_with_sub_sprite1_position(void)
{

}

void unk_113b0(void)
{

}

void sprite_util_update_sub_sprite2_anim(void)
{
    u32 adc;

    adc = sub_sprite_data2.anim_duration_counter + 0x1;
    sub_sprite_data2.anim_duration_counter = adc;
    if ((u8)sub_sprite_data2.oam_pointer[sub_sprite_data2.curr_anim_frame].timer < (u8)adc)
    {
        sub_sprite_data2.anim_duration_counter = 0x1;
        sub_sprite_data2.curr_anim_frame++;
        if ((u8)sub_sprite_data2.oam_pointer[sub_sprite_data2.curr_anim_frame].timer == 0x0)
            sub_sprite_data2.curr_anim_frame = 0x0;
    }
}

void unk_1144c(void)
{

}

void sprite_util_update_sub_sprite_anim(struct sub_sprite_data* pSub)
{
    u32 adc;

    adc = pSub->anim_duration_counter + 0x1;
    pSub->anim_duration_counter = adc;
    if ((u8)pSub->oam_pointer[pSub->curr_anim_frame].timer < (u8)adc)
    {
        pSub->anim_duration_counter = 0x1;
        pSub->curr_anim_frame++;
        if ((u8)pSub->oam_pointer[pSub->curr_anim_frame].timer == 0x0)
            pSub->curr_anim_frame = 0x0;
    }
}

void sprite_util_sync_current_sprite_position_with_sub_sprite_position(struct sub_sprite_data* pSub)
{

}

void unk_11520(struct sub_sprite_data* pSub)
{

}

u8 sprite_check_colliding_with_samus_drawing(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 samus_y;
    u16 samus_x;
    u16 o1_top;
    u16 o1_bottom;
    u16 o1_left;
    u16 o1_right;
    u16 o2_top;
    u16 o2_bottom;
    u16 o2_left;
    u16 o2_right;

    sprite_y = current_sprite.y_position;
    sprite_x = current_sprite.x_position;

    o1_top = sprite_y + current_sprite.hitbox_top_offset;
    o1_bottom = sprite_y + current_sprite.hitbox_bottom_offset;
    o1_left = sprite_x + current_sprite.hitbox_left_offset;
    o1_right = sprite_x + current_sprite.hitbox_right_offset;

    samus_y = samus_data.y_position;
    samus_x = samus_data.x_position;

    o2_top = samus_physics.draw_distance_top_offset + samus_data.y_position;
    o2_bottom = samus_data.y_position + samus_physics.draw_distance_bottom_offset;
    o2_left = samus_physics.draw_distance_left_offset + samus_data.x_position;
    o2_right = samus_data.x_position + samus_physics.draw_distance_right_offset;

    if (sprite_util_check_objects_touching(o1_top, o1_bottom, o1_left, o1_right, o2_top, o2_bottom, o2_left, o2_right))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11620 | ac | 
 * Sets a sprite splash particle effect depending on the parameters and the current hazard
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param size Splash Size
 */
void sprite_util_set_splash_effect(u16 y_position, u16 x_position, enum splash_size size)
{
    switch (current_affecting_clipdata.hazard) // Switch on current hazard
    {
        case HAZARD_TYPE_WATER:
            if (size == SPLASH_SMALL)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_WATER_SMALL);
            else if (size == SPLASH_BIG)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_WATER_BIG);
            else
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_WATER_HUGE);
            break;

        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_STRONG_LAVA:
            if (size == SPLASH_SMALL)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_LAVA_SMALL);
            else if (size == SPLASH_BIG)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_LAVA_BIG);
            else
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_LAVA_HUGE);
            break;
        
        case HAZARD_TYPE_ACID:            
            if (size == SPLASH_SMALL)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_ACID_SMALL);
            else if (size == SPLASH_BIG)
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_ACID_BIG);
            else
                particle_set(y_position, x_position, PE_SPRITE_SPLASH_ACID_HUGE);
            break;
    }
}

/**
 * 116cc | 4c | 
 * Checks if the sprite is out of the current room effect, if yes sets a splash effect
 * 
 * @param old_y Old Y position, before movement
 * @param y_position Current Y position
 * @param x_position Current X position
 * @param size Size of the splash
 * @return 1 if out of effect, 0 otherwise 
 */
u8 sprite_util_check_out_of_room_effect(u16 old_y, u16 y_position, u16 x_position, enum splash_size size)
{
    if (old_y > effect_y_position && y_position <= effect_y_position)
    {
        if (size != SPLASH_NONE)
        {
            sprite_util_check_collision_at_position_no_global((u16)(y_position + 0x40), x_position);
            sprite_util_set_splash_effect(y_position, x_position, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * 11718 | 4c | 
 * Checks if the sprite is in the current room effect, if yes sets a splash effect
 * 
 * @param old_y Old Y position, before movement
 * @param y_position Current Y position
 * @param x_position Current X position
 * @param size Size of the splash
 * @return 1 if in the effect, 0 otherwise 
 */
u8 sprite_util_check_in_room_effect(u16 old_y, u16 y_position, u16 x_position, enum splash_size size)
{
    if (old_y < effect_y_position && y_position >= effect_y_position)
    {
        if (size != SPLASH_NONE)
        {
            sprite_util_check_collision_at_position_no_global(y_position, x_position);
            sprite_util_set_splash_effect(y_position, x_position, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

u16 sprite_util_get_final_completion_percentage(void)
{

}