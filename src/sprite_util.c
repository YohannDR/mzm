#include "sprite_util.h"
#include "sprite_debris.h"
#include "particle.h"
#include "samus.h"
#include "location_text.h"
#include "clipdata.h"
#include "music.h"
#include "sprites_AI/parasite.h"
#include "sprites_AI/ridley.h"
#include "../data/data.h"
#include "globals.h"

void SpriteUtilInitLocationText(void)
{
    u8 gfx_slot;

    gfx_slot = LocationTextGetGFXSlot();
    if (gfx_slot < 0x8)
    {
        gSpriteData[0x0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN | SPRITE_STATUS_UNKNOWN3;
        gSpriteData[0x0].properties = SP_ABSOLUTE_POSITION;
        gSpriteData[0x0].spriteset_gfx_slot = gfx_slot;
        gSpriteData[0x0].sprite_id = PSPRITE_AREA_BANNER;
        gSpriteData[0x0].y_position = gSamusData.y_position;
        gSpriteData[0x0].x_position = gSamusData.x_position;
        gSpriteData[0x0].bg_priority = 0x0;
        gSpriteData[0x0].draw_order = 0x1;
        gSpriteData[0x0].pose = 0x0;
        gSpriteData[0x0].health = 0x0;
        gSpriteData[0x0].invicibility_stun_flash_timer = 0x0;
        gSpriteData[0x0].palette_row = 0x0;
        gSpriteData[0x0].frozen_palette_row_offset = 0x0;
        gSpriteData[0x0].absolute_palette_row = 0x0;
        gSpriteData[0x0].ignore_samus_collision_timer = 0x1;
        gSpriteData[0x0].primary_sprite_ram_slot = 0x0;
        gSpriteData[0x0].freeze_timer = 0x0;
        gSpriteData[0x0].standing_on_sprite = FALSE;
    }
}

void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 y_position, u16 x_position)
{

}

void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 y_position, u16 x_position)
{

}

/**
 * e634 | c4 | 
 * Calculates and applies the damage samus takes from a sprite
 * 
 * @param kb_flag 1 if getting knocked back, 0 otherwise
 * @param pSprite Sprite Data Pointer to the sprite hurting samus
 * @param dmg_mulitplier Damage Multiplier
 * @return 1 if alive, 0 otherwise
 */
u8 SpriteUtilTakeDamageFromSprite(u8 kb_flag, struct SpriteData* pSprite, u16 dmg_mulitplier)
{
    u16 damage;
    u16 flags;

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        damage = secondary_sprite_stats[pSprite->sprite_id][0x1]; // Get Damage
    else
        damage = primary_sprite_stats[pSprite->sprite_id][0x1]; // Get Damage
    damage *= dmg_mulitplier; // Apply multiplier

    flags = gEquipment.suit_misc_activation;
    if ((flags & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
        damage /= 0x2;
    else if (flags & SMF_GRAVITY_SUIT)
        damage = (damage * 0x7) / 0xA;
    else if (flags & SMF_VARIA_SUIT)
        damage = (damage * 0x8) / 0xA;

    if (gDifficulty == DIFF_EASY)
        damage /= 0x2;
    else if (gDifficulty == DIFF_HARD)
        damage *= 0x2;

    if (damage == 0x0)
        damage = 0x1;

    if (gEquipment.current_energy > damage)
    {
        gEquipment.current_energy -= damage;
        if (kb_flag)
            SamusSetPose(SPOSE_HURT_REQUEST);
        return TRUE;
    }
    else
    {
        gEquipment.current_energy = 0x0;
        SamusSetPose(SPOSE_HURT_REQUEST);
        return FALSE;
    }
}

u8 SpriteUtilCheckObjectsTouching(u16 o1_top, u16 o1_bottom, u16 o1_left, u16 o1_right, u16 o2_top, u16 o2_bottom, u16 o2_left, u16 o2_right)
{
    if (o2_bottom >= o1_top && o2_top < o1_bottom && o2_right >= o1_left && o2_left < o1_right)
        return TRUE;
    else
        return FALSE;
}

void SpriteUtilSamusAndSpriteCollision(void)
{
    struct SamusData* pData;
    struct SpriteData* pSprite;
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

    pData = &gSamusData;
    dmg_multiplier = 0x0;
    samus_y = pData->y_position;
    samus_x = pData->x_position;
    previous_x = gPreviousXPosition;
    samus_top = samus_y + gSamusPhysics.draw_distance_top_offset;
    samus_bottom = samus_y + gSamusPhysics.draw_distance_bottom_offset;
    samus_left = samus_x + gSamusPhysics.draw_distance_left_offset;
    samus_right = samus_x + gSamusPhysics.draw_distance_right_offset;

    if (pData->pose == SPOSE_BALLSPARKING)
    {
        switch (gSamusData.forced_movement)
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

    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
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
                if (SpriteUtilCheckObjectsTouching(samus_top, samus_bottom, samus_left, samus_right, sprite_top, sprite_bottom, sprite_left, sprite_right))
                {
                    gCollisionRelated = isct;
                    // Weird calcul ?
                    if (pSprite->freeze_timer == 0x0)
                    {
                        switch (pSprite->samus_collision)
                        {
                            case SSC_IMAGO_EGG:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                gCollisionRelated = 0x1;
                            case SSC_SOLID:
                                if (!SpriteUtilCheckPullingSeftUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (samus_y - 0x18 < sprite_top)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(sprite_top + gSamusPhysics.draw_distance_top_offset + 0x1, samus_x);
                                        if (gPreviousCollisionCheck == 0x0 && pData->y_velocity < 0x0)
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
                                            SpriteUtilCheckCollisionAtPosition(sprite_bottom - gSamusPhysics.draw_distance_top_offset, samus_x);
                                            if (gPreviousCollisionCheck == 0x0)
                                            {
                                                pData->y_position = sprite_bottom - gSamusPhysics.draw_distance_top_offset;
                                                if (pData->y_velocity > 0x0 && gEquipment.current_energy != 0x0)
                                                    pData->y_velocity = 0x0;
                                            }
                                        }
                                        else if (samus_x < sprite_left || samus_x > sprite_right)
                                        {
                                            if (unk & 0x4)
                                                SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samus_y, sprite_left);
                                            else
                                                SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samus_y, sprite_right);
                                        }
                                    }
                                }
                                break;

                            case SSC_ESCAPE_SHIP:
                                if (!SpriteUtilCheckPullingSeftUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE && samus_x - 0x18 < sprite_top)
                                {
                                    SpriteUtilCheckCollisionAtPosition(sprite_top + gSamusPhysics.draw_distance_top_offset + 0x1, sprite_y);
                                    if (gPreviousCollisionCheck == 0x0 && pData->y_velocity < 0x1)
                                    {
                                        pData->y_position = sprite_top + 0x1;
                                        pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                        pSprite->standing_on_sprite = 0x2;
                                    }
                                }
                                break;

                            case 0x3:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (samus_y - 0x18 < sprite_top)
                                    {
                                        if (!SpriteUtilCheckPullingSeftUp() && pData->invincibility_timer < 0x27)
                                        {
                                            SpriteUtilCheckCollisionAtPosition(sprite_top + gSamusPhysics.draw_distance_top_offset + 0x1, samus_x);
                                            if (gPreviousCollisionCheck == 0x0 && pData->y_velocity < 0x10)
                                            {
                                                pData->y_position = sprite_top + 0x1;
                                                pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                                pSprite->standing_on_sprite = 0x2;
                                            }
                                        }
                                    }   
                                    else
                                    {
                                        if (pData->invincibility_timer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                        *pTimer = 0xF;
                                        gCollisionRelated = 0x1;
                                    }
                                }
                                break;

                            case SSC_KRAID_SPIKE:
                                if (samus_x > sprite_right)
                                {
                                    if (pData->invincibility_timer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x40;
                                        else
                                            pData->x_velocity = 0x40;
                                    }
                                    *pTimer = 0xF;
                                    gCollisionRelated = 0x1;
                                }
                                else
                                {
                                    if (samus_y - 0x18 <= sprite_top && !SpriteUtilCheckPullingSeftUp() && pData->invincibility_timer < 0x25)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(sprite_top + gSamusPhysics.draw_distance_top_offset + 0x1, samus_x);
                                        if (gPreviousCollisionCheck == 0x0 && pData->y_velocity < 0x0)
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
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibility_timer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x40;
                                        else
                                            pData->x_position = 0x40;
                                    }
                                    *pTimer = 0xF;
                                    gCollisionRelated = 0x1;
                                }
                                break;

                            case 0xF:
                                break;
                            case 0xE:
                                //
                            case SSC_IMAGO_STINGER:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibility_timer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (unk & 0x4)
                                            pData->x_velocity = -0x80;
                                        else
                                            pData->x_velocity = 0x80;
                                    }
                                    *pTimer = 0xF;
                                    gCollisionRelated = 0x1;
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
                                    SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1);
                                    if (gEquipment.current_energy != 0x0)
                                        pData->invincibility_timer = 0x8;
                                }
                                *pTimer = 0xF;
                                break;

                            case 0x10:
                                pSprite->pose = 0x42;
                            case 0x11:
                                SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1);
                                *pTimer = 0xF;
                                if (pData->invincibility_timer == 0x0)
                                    pData->invincibility_timer = 0x0;
                                gCollisionRelated = 0x1;
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
                                            gPreviousYPosition = pData->y_position;
                                            gPreviousXPosition = pData->x_position;
                                            SamusSetPose(SPOSE_ON_ZIPLINE);
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            break;

                                        case SPOSE_BALLSPARKING:
                                            SoundStop(0x8F);
                                        case SPOSE_MORPH_BALL_MIDAIR:
                                            pData->y_position = pSprite->y_position + 0x3C;
                                            pData->x_position = pSprite->x_position;
                                            gPreviousYPosition = pData->y_position;
                                            gPreviousXPosition = pData->x_position;
                                            SamusSetPose(SPOSE_MORPH_BALL_ON_ZIPLINE);
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            break;
                                    }
                                    *pTimer = 0xF;
                                    gCollisionRelated = 0x1;
                                }
                                break;

                            case SSC_ZEBETITE:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samus_y, sprite_left);
                                    else
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samus_y, sprite_right);
                                }
                                break;

                            case SSC_HURTS_SAMUS_NO_PASS_THROUGH:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samus_y, sprite_left);
                                    else
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samus_y, sprite_right);

                                    if (pData->invincibility_timer == 0x0)
                                    {
                                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1) && gPreviousCollisionCheck == 0x0)
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                        gCollisionRelated = 0x1;
                                    }
                                }
                                break;

                            case SSC_KRAID:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (unk & 0x4)
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samus_y, sprite_left);
                                    else
                                        SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samus_y, sprite_right);

                                    if (pData->invincibility_timer == 0x0)
                                    {
                                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1) && gPreviousCollisionCheck == 0x0)
                                        {
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                    }
                                    else if (gPreviousCollisionCheck == 0x0)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(samus_y + gSamusPhysics.draw_distance_top_offset + 0x1, samus_x);
                                        if (gPreviousCollisionCheck == 0x0)
                                        {
                                            SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                                            if (unk & 0x4)
                                                pData->x_velocity = -0x40;
                                            else
                                                pData->x_velocity = 0x40;
                                        }
                                    }
                                    gCollisionRelated = 0x1;
                                }
                                break;

                            case SSC_KNOCKS_BACK_SAMUS:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                                    if (unk & 0x4)
                                        pData->x_velocity = -0x20;
                                    else
                                        pData->x_position = 0x20;
                                }
                                gCollisionRelated = 0x1;
                                break;

                            case SSC_BUG:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibility_timer == 0x0 && (gEquipment.suit_misc_activation & (SMF_VARIA_SUIT & SMF_GRAVITY_SUIT)) == 0x0)
                                {
                                    if (ParasiteCount() && SpriteUtilTakeDamageFromSprite(FALSE, pSprite, dmg_multiplier >> 0x2))
                                    {
                                        pData->invincibility_timer = 0x10;
                                        unk_2b20(0x80);
                                        gSubSpriteData1.timer++;
                                        if ((gSubSpriteData1.timer & 0x3) == 0x0)
                                            SoundPlay(0x7C);
                                    }
                                }
                                *pTimer = 0xF;
                                break;

                            case SSC_METROID:
                                if (samus_y > sprite_y + 0x20)
                                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibility_timer == 0x0 && SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1))
                                {
                                    if (gEquipment.suit_misc_activation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT) == 0x0)
                                        pData->invincibility_timer = 0x2;
                                    else if ((gEquipment.suit_misc_activation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
                                        pData->invincibility_timer = 0x8;
                                    else
                                        pData->invincibility_timer = 0x4;
                                }
                                break;

                            case SSC_RIDLEY_CLAW:
                                if (!unk && RidleyCheckGrabbing(sprite_y, sprite_x))
                                {
                                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                    pSprite->samus_collision = SSC_NONE;
                                    gCollisionRelated = 0x1;
                                    SamusSetPose(SPOSE_MIDAIR);
                                    SoundPlay(0x1E3);
                                }
                                else 
                                {
                                    if (pData->invincibility_timer == 0x0 && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                        SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1);
                                    *pTimer = 0xF;
                                    gCollisionRelated = 0x1;
                                }
                                break;

                            case SSC_MECHA_RIDLEY:
                                dmg_multiplier = 0x1;
                                if (SpriteUtilGetFinalCompletionPercentage() == 0x64)
                                    dmg_multiplier = 0x2;
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, dmg_multiplier))
                                    pData->x_velocity = -0x80;
                                *pTimer = 0xF;
                                gCollisionRelated = 0x1;

                            case 0x8:
                            default:
                                *pTimer = 0xF;
                                gCollisionRelated = 0x1;
                        }

                        if (gCollisionRelated != 0x0)
                            break;
                    }
                }
            }
        }
        pSprite++;
    }

    pSprite = gSpriteData;
    while (pSprite < gSpriteData + 24)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->ignore_samus_collision_timer != 0x0)
            pSprite->ignore_samus_collision_timer--;
    }
}

u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 y_position, u16 x_position)
{

}

u32 SpriteUtilCheckVerticalCollisionAtPosition_slopes(u16 y_position, u16 x_position)
{

}

void unk_f594(void)
{

}

void unk_f608(void)
{

}

/**
 * f688 | 98 | 
 * Checks the collision at the given parameters and updates the gPreviousCollisionCheck global variable
 * 
 * @param y_position Y Position
 * @param x_position X Position
 */
void SpriteUtilCheckCollisionAtPosition(u16 y_position, u16 x_position)
{
    u32 collision;

    collision = ClipdataProcess(y_position, x_position);
    if (collision & 0x1000000)
        gPreviousCollisionCheck = COLLISION_SOLID;
    else
        gPreviousCollisionCheck = COLLISION_AIR;
    
    switch (collision & 0xFF)
    {
        case 0x3:
            gPreviousCollisionCheck = COLLISION_STEEP_RIGHT_FLOOR_SLOPE;
            break;
        case 0x6:
            gPreviousCollisionCheck = COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE;
            break;
        case 0x7:
            gPreviousCollisionCheck = COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE;
            break;
        case 0x2:
            gPreviousCollisionCheck = COLLISION_STEEP_LEFT_FLOOR_SLOPE;
            break;
        case 0x5:
            gPreviousCollisionCheck = COLLISION_SLIGHT_LEFT_FLOOR_SLOPE;
            break;
        case 0x4:
            gPreviousCollisionCheck = COLLISION_SLIGHT_LEFT_FLOOR_SLOPE;
            break;
        case 0xC:
            gPreviousCollisionCheck = COLLISION_PASS_THROUGH_BOTTOM;
    }
}

u32 SpriteUtilGetCollisionAtPosition(u16 y_position, u16 x_position)
{

}

void SpriteUtilCurrentSpriteFall(void)
{

}

/**
 * f80c | 38 | Chooses a random X flip for the current sprite
 * 
 */
void SpriteUtilChooseRandomXFlip(void)
{
    if (gSpriteRNG & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
}

/**
 * f844 | 3C | Chooses a random X direction for the current sprite
 * 
 */
void SpriteUtilChooseRandomXDirection(void)
{
    if (gSpriteRNG & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f880 | 38 | Chooses a random X direction for the current sprite using its room slot
 * 
 */
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 room_slot)
{
    if (gCurrentSprite.room_slot & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f8b0 | 30 | Makes the sprite face samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceSamusXFlip(void)
{
    if (gCurrentSprite.x_position > gSamusData.x_position)
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
}

/**
 * f8e0 | 30 | Makes the sprite face samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceSamusDirection(void)
{
    if (gCurrentSprite.x_position > gSamusData.x_position)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f914 | 30 | Makes the sprite face away from samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceAwawFromSamusXFlip(void)
{
    if (gCurrentSprite.x_position > gSamusData.x_position)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
}

/**
 * f944 | 34 | Makes the sprite face away from samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceAwawFromSamusDirection(void)
{
    if (gCurrentSprite.x_position > gSamusData.x_position)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
}

void unk_f978(i16 movement)
{

}

void unk_f9e7(i16 movement)
{

}

u8 SpriteUtilMakeSpriteFaceSamusRotation(u8 oam_rotation, u16 samus_y, u16 samus_x, u16 sprite_y, u16 sprite_x)
{

}

u8 SpriteUtillCheckEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gCurrentSprite.anim_duration_counter;
    curr_anim = gCurrentSprite.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)gCurrentSprite.oam_pointer[curr_anim].timer < adc && (u8)gCurrentSprite.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndCurrentSpriteAnim(void)
{
    /*u32 adc;
    u16 curr_anim;
    
    adc = gCurrentSprite.anim_duration_counter;
    curr_anim = gCurrentSprite.curr_anim_frame;
    adc = ((adc << 0x18) + 0x2000000) >> 0x18;

    if ((u8)gCurrentSprite.oam_pointer[curr_anim].timer < adc &&
    (u8)gCurrentSprite.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;*/
}

u8 SpriteUtilCheckEndSpriteAnim(u8 ram_slot)
{
    u8 adc;
    u16 curr_anim;

    adc = gSpriteData[ram_slot].anim_duration_counter;
    curr_anim = gSpriteData[ram_slot].curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSpriteData[ram_slot].oam_pointer[curr_anim].timer < adc && (u8)gSpriteData[ram_slot].oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndSpriteAnim(u8 ram_slot)
{

}

u8 SpriteUtilCheckEndSubSprite1Anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gSubSpriteData1.anim_duration_counter;
    curr_anim = gSubSpriteData1.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSubSpriteData1.oam_pointer[curr_anim].timer < adc && (u8)gSubSpriteData1.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndSubSprite1Anim(void)
{

}

u8 SpriteUtilCheckEndSubSprite2Anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gSubSpriteData2.anim_duration_counter;
    curr_anim = gSubSpriteData2.curr_anim_frame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSubSpriteData2.oam_pointer[curr_anim].timer < adc && (u8)gSubSpriteData2.oam_pointer[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub)
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

u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub)
{

}

u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 y_range, u16 x_range)
{
    /*struct SamusData* pData;
    u8 result;
    u16 samus_y;
    u16 samus_x;
    u16 sprite_y;
    u16 sprite_x;
    i32 difference;

    result = NSLR_OUT_OF_RANGE;
    pData = &gSamusData;
    samus_y = (gSamusPhysics.draw_distance_top_offset / 0x2) + pData->y_position;
    samus_x = pData->x_position;
    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;

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

u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 y_range, u16 x_range)
{

}

u8 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 y_range, u16 x_range_front, u16 x_range_behind)
{

}

/**
 * ff60 | 88 | 
 * Handles samus standing on a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite)
{
    u8 standing;

    if (pSprite->status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        if (gSamusData.standing_status != STANDING_ENEMY)
        {
            if (gSamusData.standing_status == STANDING_MIDAIR)
                SamusSetPose(SPOSE_LANDING_REQUEST);
            gSamusData.standing_status = STANDING_ENEMY;
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
            if (gSamusDataCopy.y_position <= gSamusData.y_position)
                gSamusData.y_position = pSprite->y_position + pSprite->hitbox_top_offset + 0x1;
        }
    }
    else
    {
        pSprite->standing_on_sprite = FALSE;
        if (gSamusData.standing_status == STANDING_ENEMY)
            gSamusData.standing_status = STANDING_MIDAIR;
    }
}

/**
 * ffe8 | 64 | Updates the freeze timer of the current sprite
 * 
 */
void SpriteUtilUpdateFreezeTimer(void)
{
    u8 timer;

    if (gFrameCounter8Bit & 0x1)
        gCurrentSprite.freeze_timer--;

    timer = gCurrentSprite.freeze_timer;
    if (!timer)
        gCurrentSprite.anim_duration_counter--;

    if (timer < 0x2E)
    {
        if (timer & 0x1)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spriteset_gfx_slot + gCurrentSprite.frozen_palette_row_offset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolute_palette_row;
    }
}

void SpriteUtilUnfreezeAnimEasy(void)
{
    u8 freeze_timer;

    gCurrentSprite.freeze_timer--;

    freeze_timer = gCurrentSprite.freeze_timer;
    if (freeze_timer == 0x0)
        gCurrentSprite.anim_duration_counter--;
    if (freeze_timer < 0x5B && (freeze_timer & 0x1) == 0x0)
    {
        if ((freeze_timer & 0x2) != 0x0)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spriteset_gfx_slot + gCurrentSprite.frozen_palette_row_offset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolute_palette_row;
    }
}

void SpriteUtilMetroidUnfreezeAnim(void)
{
    u8 freeze_timer;

    gCurrentSprite.freeze_timer -= 0x2;

    freeze_timer = gCurrentSprite.freeze_timer;
    if (freeze_timer == 0x0)
        gCurrentSprite.anim_duration_counter--;
    if (freeze_timer < 0x79 && (freeze_timer & 0x2) == 0x0)
    {
        if ((freeze_timer & 0x4) != 0x0)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spriteset_gfx_slot + gCurrentSprite.frozen_palette_row_offset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolute_palette_row;
    }
}

void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 sprite_id, u8 ram_slot)
{
    u8 count;

    if (gCurrentSprite.freeze_timer != 0x0)
    {
        count = 0x0;
        while (count < 0x18)
        {
            if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
                && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
                && gSpriteData[count].sprite_id == sprite_id
                && gSpriteData[count].primary_sprite_ram_slot == ram_slot
                && gSpriteData[count].freeze_timer < gCurrentSprite.freeze_timer
                && (gSpriteData[count].properties & SP_MAYBE_DESTROYED) == 0x0)
            {
                gSpriteData[count].freeze_timer = gCurrentSprite.freeze_timer;
                gSpriteData[count].palette_row = 0xF - (gSpriteData[count].spriteset_gfx_slot + gSpriteData[count].frozen_palette_row_offset);
            }
            count++;
        }
    }
}

void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void)
{
    if (gCurrentSprite.freeze_timer != 0) {
        u8 count = gCurrentSprite.primary_sprite_ram_slot;
        if (gSpriteData[count].freeze_timer < gCurrentSprite.freeze_timer && (gSpriteData[count].properties & SP_MAYBE_DESTROYED) == 0)
        {
            gSpriteData[count].freeze_timer = gCurrentSprite.freeze_timer;
            gSpriteData[count].palette_row = 0xf - (gSpriteData[count].spriteset_gfx_slot + gSpriteData[count].frozen_palette_row_offset);
        } 
    }
}

void SpriteUtilUnfreezeSecondarySprites(u8 sprite_id, u8 ram_slot)
{
    u8 count = 0;
    do
    {
        if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
            && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
            && gSpriteData[count].sprite_id == sprite_id
            && gSpriteData[count].primary_sprite_ram_slot == ram_slot
            && gSpriteData[count].freeze_timer != 0x0)
        {
            gSpriteData[count].freeze_timer = 0x0;
            gSpriteData[count].palette_row = 0x0;
        }
        count++;
    }
    while (count < 0x18);
}

u8 SpriteUtilRefillEnergy(void)
{

}

u8 SpriteUtilRefillMissiles(void)
{
    /*u16 increment;
    u16 max;
    u16 current;

    current = gEquipment.current_missiles;
    max = gEquipment.max_missiles;

    if (current < max)
    {
        increment = (u16)((gEquipment.max_missiles - gEquipment.current_missiles));
        increment >>= 5;
        if (increment == 0x0)
            increment = 0x1;
        else if (0x5 < increment)
            increment = 0x6;
        
        gEquipment.current_missiles += increment;
        if ((u16)(increment + gEquipment.current_missiles) > gEquipment.max_missiles)
            gEquipment.current_missiles = gEquipment.max_missiles;
        
        return TRUE;
    }
    else
        return FALSE;*/
}

u8 SpriteUtilRefillSuperMissiles(void)
{

}

u8 SpriteUtilRefillPowerBombs(void)
{

}

u8 SpriteUtilCheckCrouchinOrMorphed(void)
{
    switch (gSamusData.pose)
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

u8 SpriteUtilCheckCrouchinOrCrawling(void)
{
    switch (gSamusData.pose)
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

u8 SpriteUtilCheckMorphed(void)
{
    switch (gSamusData.pose)
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

u8 SpriteUtilCheckStopSpritesPose(void)
{
    if (gPreventMovementTimer == 0x0)
    {
        switch (gSamusData.pose)
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
u8 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData)
{
    u8 dct;
    u8* pProps;
    struct Equipment* pEquipment;
    u16 weakness;
    u16 bbf;
    u32 damage;
    u8 is_dead;
    u8 isft;

    dct = DCT_NONE;
    if (gEquipment.suit_type == SUIT_SUITLESS)
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
                if (0x3F < gSamusWeaponInfo.charge_counter)
                    dct = DCT_SUDO_SCREW;
            
            default:
                if (dct == DCT_NONE)
                    return DCT_NONE;
        }
    }

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        weakness = secondary_sprite_stats[pSprite->sprite_id][0x2];
    else if ((pSprite->properties & SP_SECONDARY_SPRITE) == 0x0)
        weakness = primary_sprite_stats[pSprite->sprite_id][0x2];

    if (dct >= DCT_SUDO_SCREW)
    {
        if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
        {
            gSamusWeaponInfo.charge_counter = 0x0;
            damage = 0x2;
            bbf = gEquipment.beam_bombs_activation;
            if ((gEquipment.beam_bombs_activation & BBF_LONG_BEAM) != 0x0)
                damage = 0x3;
            if ((gEquipment.beam_bombs_activation & BBF_ICE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((gEquipment.beam_bombs_activation & BBF_WAVE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((bbf & BBF_PLASMA_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);

            damage = (u16)(damage << 0x2);
            is_dead = ProjectileDealDamage(pSprite, damage);
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
            pSprite->properties |= SP_DAMAGED;
            return dct;
        }

        isft = 0x3;
        if ((pSprite->invicibility_stun_flash_timer & 0x7F) < isft)
            pSprite->invicibility_stun_flash_timer = pSprite->invicibility_stun_flash_timer & 0x80 | 0x3;
        dct = DCT_NONE;
    }

    return dct;
}

u8 SpriteUtilCheckPullingSeftUp(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
           return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCheckOnZipline(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
           return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCountPrimarySprites(u8 sprite_id)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct SpriteData* pSprite;

    count = 0x0;
    ram_slot = gCurrentSprite.primary_sprite_ram_slot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->sprite_id == sprite_id && pSprite->primary_sprite_ram_slot == ram_slot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 sprite_id)
{
    u8 count;
    u8 ram_slot;
    struct SpriteData* pSprite;

    count = 0x0;
    ram_slot = gCurrentSprite.primary_sprite_ram_slot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id && pSprite->primary_sprite_ram_slot == ram_slot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilFindPrimary(u8 sprite_id)
{
    u8 ram_slot;
    struct SpriteData* pSprite;

    ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == sprite_id)
            return ram_slot;
        ram_slot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilFindSecondaryWithRoomSlot(u8 sprite_id, u8 room_slot)
{
    u8 ram_slot;
    struct SpriteData* pSprite;

    ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->sprite_id == sprite_id && pSprite->room_slot == room_slot)
            return ram_slot;
        ram_slot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilCheckHasDrops(void)
{
    u8 ram_slot;
    struct SpriteData* pSprite;
    u8 collision;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->primary_sprite_ram_slot == ram_slot && pSprite->samus_collision >= collision)
            return TRUE;
        pSprite++;
    }

    return FALSE;
}

u8 SpriteUtilCountDrops(void)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
        pSprite++;
    }

    return count;
}

void SpriteUtilMoveSpriteTowardsSamus(u16 samus_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

void SpriteUtilRidleyFireballMove(u16 sprite_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor)
{

}

/**
 * 10cf0 | 78 | 
 * Updates the stun timer of the sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->invicibility_stun_flash_timer & 0x7F)
    {
        isft = pSprite->invicibility_stun_flash_timer = pSprite->invicibility_stun_flash_timer - 0x1;
        if (!(isft & 0x3))
        {
            if (isft & 0x4)
            {
                if (pSprite->health != 0x0)
                    pSprite->palette_row = 0xE - (pSprite->spriteset_gfx_slot + pSprite->frozen_palette_row_offset);
            }
            else
            {
                if (pSprite->health != 0x0)
                {
                    if (pSprite->freeze_timer != 0x0)
                        pSprite->palette_row = 0xF - (pSprite->spriteset_gfx_slot + pSprite->frozen_palette_row_offset);
                    else
                        pSprite->palette_row = pSprite->absolute_palette_row;
                }
            }
        }
    }
}

/**
 * 10d68 | 126 | 
 * Spawns a set of random sprite debris depending on the parameters
 * 
 * @param cloud_type Cloud Type
 * @param number Number Of Debris to spawn
 * @param y_position Y Position
 * @param x_position X Position
 */
void SpriteUtilRandomSpriteDebris(u8 cloud_type, u8 number, u16 y_position, u16 x_position)
{
    switch (number)
    {
        case 0x1:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
                SpriteDebrisInit(cloud_type, 0x1, y_position + 0x8, x_position - 0x8);
            else
                SpriteDebrisInit(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
            break;
        case 0x2:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                SpriteDebrisInit(cloud_type, 0x3, y_position, x_position + 0x8);
            }
            else
            {
                SpriteDebrisInit(cloud_type, 0x2, y_position - 0x8, x_position + 0x8);
                SpriteDebrisInit(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
            break;
        case 0x3:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloud_type, 0x2, y_position - 0x10, x_position + 0x8);
                SpriteDebrisInit(cloud_type, 0x3, y_position + 0x8, x_position + 0x8);
                SpriteDebrisInit(cloud_type, 0x4, y_position + 0x10, x_position - 0x8);
            }
            else
            {
                SpriteDebrisInit(cloud_type, 0x1, y_position - 0x8, x_position - 0x8);
                SpriteDebrisInit(cloud_type, 0x3, y_position - 0x10, x_position + 0x8);
                SpriteDebrisInit(cloud_type, 0x4, y_position + 0x8, x_position - 0x8);
            }
    }
}

u8 SpriteUtilGetAmmoDrop(u8 rng)
{
    if (gEquipment.current_energy == gEquipment.max_energy)
    {
        if ((rng & 0x1) != 0x0 && gEquipment.max_missiles > gEquipment.current_missiles)
            return PSPRITE_MISSILE_DROP;
        if ((rng & 0x2) != 0x0 && gEquipment.max_super_missiles > gEquipment.current_super_missiles)
            return PSPRITE_SUPER_MISSILE_DROP;
        if ((rng & 0x4) != 0x0 && gEquipment.max_power_bombs > gEquipment.gCurrentPowerBombs)
            return PSPRITE_POWER_BOMB_DROP;
    }
    return PSPRITE_UNUSED0;
}

u8 SpriteUtilDetermineEnemyDrop(void)
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
    u8 drop;

    drop = 0x0;
    is_full = FALSE;
    if (gEquipment.current_energy == gEquipment.max_energy)
        is_full = TRUE;

    rng = gSpriteRNG;
    rng *= 0x100;
    rng = (u16)(rng + (gFrameCounter8Bit + sixteen_bit_frame_counter) << 0x6) >> 0x6;
    if (rng == 0x0)
        rng = 0x1;

    sprite_id = gCurrentSprite.sprite_id;
    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        small_health_prob = secondary_sprite_stats[sprite_id][0x4];
        large_health_prob = secondary_sprite_stats[sprite_id][0x5];
        missile_prob = secondary_sprite_stats[sprite_id][0x6];
        super_missile_prob = secondary_sprite_stats[sprite_id][0x7];
        power_bomb_drop = secondary_sprite_stats[sprite_id][0x8];
    }
    else
    {
        small_health_prob = primary_sprite_stats[sprite_id][0x4];
        large_health_prob = primary_sprite_stats[sprite_id][0x5];
        missile_prob = primary_sprite_stats[sprite_id][0x6];
        super_missile_prob = primary_sprite_stats[sprite_id][0x7];
        power_bomb_drop = primary_sprite_stats[sprite_id][0x8];
    }

    if (power_bomb_drop != 0x0)
    {
        non_power_bomb_drop = 0x400 - power_bomb_drop;
        if (rng < 0x401 && rng > non_power_bomb_drop)
        {
            if (gEquipment.max_power_bombs <= gEquipment.gCurrentPowerBombs)
            {
                if (!is_full)
                {
                    if (gEquipment.max_power_bombs != 0x0)
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
                    if (gEquipment.max_super_missiles <= gEquipment.current_super_missiles)
                    {
                        if (is_full)
                            drop = PSPRITE_LARGE_ENERGY_DROP;
                        else if (gEquipment.max_super_missiles == 0x0)
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
                    if (gEquipment.max_missiles <= gEquipment.current_missiles)
                    {
                        if (!is_full)
                        {
                            if (gEquipment.max_missiles != 0x0)
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
                    else if (gEquipment.max_missiles <= gEquipment.current_missiles)
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
                    if (gEquipment.max_missiles <= gEquipment.current_missiles)
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

/**
 * 11084 | 1fc | 
 * Handles the death of a sprite, replaces it with a drop if necessary
 * 
 * @param death_type Death Type (0 spawns a drop)
 * @param y_position Y Position
 * @param x_position X Position
 * @param play_sound Play Sound flag
 * @param effect Particle Effect if not killed by damage contact
 */
void SpriteUtilSpriteDeath(u8 death_type, u16 y_position, u16 x_position, u8 play_sound, u8 effect)
{
    u8 drop;

    switch (gCurrentSprite.pose)
    {
        case 0x63: // Check for damage contact
            ParticleSet(y_position, x_position, PE_SHINESPARK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, y_position, x_position);
            SoundPlay(0x131);
            break;
        case 0x64:
            ParticleSet(y_position, x_position, PE_SPEEDBOOSTER_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, y_position, x_position);
            SoundPlay(0x133);
            break;
        case 0x65:
            ParticleSet(y_position, x_position, PE_SCREW_ATTACK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, y_position, x_position);
            SoundPlay(0x130);
            break;
        case 0x66:
            ParticleSet(y_position, x_position, PE_SUDO_SCREW_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, y_position, x_position);
            SoundPlay(0x132);
            break;
        default: // Check play sprite explosion effects
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_SMALL);
                if (play_sound != FALSE)
                    SoundPlay(0x12C);
            }
            else if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
            {
                ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_MEDIUM);
                if (play_sound != FALSE)
                    SoundPlay(0x12D);
            }
            else if (effect == PE_SPRITE_EXPLOSION_BIG)
            {
                ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_BIG);
                if (play_sound != FALSE)
                    SoundPlay(0x12E);
            }
            else if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
            {
                ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                if (play_sound != FALSE)
                    SoundPlay(0x12F);
            }
            else if ((u8)(effect - 0x27) < 0x3) // Default behavior
                ParticleSet(y_position, x_position, effect);
    }

    drop = SpriteUtilDetermineEnemyDrop();
    if (drop != 0x0)
    {       
        if (death_type != DEATH_NORMAL)
        {
            if (death_type != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
                SpriteSpawnDropFollowers(drop, gCurrentSprite.room_slot, 0x0, gCurrentSprite.primary_sprite_ram_slot, y_position, x_position, 0x0);
        }
        else
        {
            // Init data for drop
            gCurrentSprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            gCurrentSprite.properties = 0x0;
            gCurrentSprite.spriteset_gfx_slot = 0x0;
            gCurrentSprite.sprite_id = drop;
            gCurrentSprite.y_position = y_position;
            gCurrentSprite.x_position = x_position;
            gCurrentSprite.bg_priority = 0x2;
            gCurrentSprite.draw_order = 0x4;
            gCurrentSprite.pose = 0x0;
            gCurrentSprite.health = 0x0;
            gCurrentSprite.invicibility_stun_flash_timer = 0x0;
            gCurrentSprite.palette_row = 0x0;
            gCurrentSprite.frozen_palette_row_offset = 0x0;
            gCurrentSprite.absolute_palette_row = 0x0;
            gCurrentSprite.ignore_samus_collision_timer = 0x1;
            gCurrentSprite.freeze_timer = 0x0;
        }
    }
    else
    {
        if (death_type == DEATH_NORMAL)
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 11280 | 48 | 
 * Checks if the current sprite is stunned
 * 
 * @return 1 if stunned, 0 otherwise
 */
u8 SpriteUtilIsSpriteStunned(void)
{
    u8 is_stunned;
    u8 stun_timer;
    u8 diff;

    is_stunned = FALSE;
    diff = gDifficulty;
    
    stun_timer = 0xE;
    if (diff < 0x2)
        stun_timer = 0x9;

    if (((gCurrentSprite.invicibility_stun_flash_timer & 0x7F) > stun_timer) && gCurrentSprite.pose < 0x62)
    {
        if (gCurrentSprite.anim_duration_counter != 0x0)
            gCurrentSprite.anim_duration_counter--;
        is_stunned = TRUE;
    }

    return is_stunned;
}

/**
 * 112c8 | 38 | 
 * Checks if a sprite is on screen with a screen shake occuring
 * 
 * @return 1 if conditions met, 0 otherwise
 */
u8 SpriteUtilIsSpriteOnScreenAndScreenShake(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gScreenShakeY.timer != 0x0 || gScreenShakeX.timer != 0x0))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11300 | 30 | Updates the sub sprite data 1 timer field (used by chozo statues for the echo when sitting)
 * 
 */
void SpriteUtilUpdateSubSprite1Timer(void)
{
    u32 caf;
    u32 adc;
    u8 timer;

    gSubSpriteData1.timer = 0x0;
    adc = (u8)(gSubSpriteData1.anim_duration_counter + 0x1);
    caf = gSubSpriteData1.curr_anim_frame;

    if (gSubSpriteData1.oam_pointer[caf].timer < adc)
    {
        timer = (u8)caf;
        gSubSpriteData1.timer = timer + 0x1;
    }
}

void SpriteUtilUpdateSubSprite1Anim(void)
{
    u32 adc;

    adc = gSubSpriteData1.anim_duration_counter + 0x1;
    gSubSpriteData1.anim_duration_counter = adc;
    if ((u8)gSubSpriteData1.oam_pointer[gSubSpriteData1.curr_anim_frame].timer < (u8)adc)
    {
        gSubSpriteData1.anim_duration_counter = 0x1;
        gSubSpriteData1.curr_anim_frame++;
        if ((u8)gSubSpriteData1.oam_pointer[gSubSpriteData1.curr_anim_frame].timer == 0x0)
            gSubSpriteData1.curr_anim_frame = 0x0;
    }
}

/**
 * 1136c | 44 | Updates the current sprite position with the sub sprite data 1 position and the X/Y position of its OAM data
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void)
{
    u16* pOam;

    pOam = gSubSpriteData1.oam_pointer[gSubSpriteData1.curr_anim_frame].oam_frame_ptr;

    gCurrentSprite.y_position = gSubSpriteData1.y_position + pOam[gCurrentSprite.room_slot * 0x3 + 0x1];
    gCurrentSprite.x_position = gSubSpriteData1.x_position + pOam[gCurrentSprite.room_slot * 0x3 + 0x2];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM(void)
{

}

void SpriteUtilUpdateSubSprite2Anim(void)
{
    u32 adc;

    adc = gSubSpriteData2.anim_duration_counter + 0x1;
    gSubSpriteData2.anim_duration_counter = adc;
    if ((u8)gSubSpriteData2.oam_pointer[gSubSpriteData2.curr_anim_frame].timer < (u8)adc)
    {
        gSubSpriteData2.anim_duration_counter = 0x1;
        gSubSpriteData2.curr_anim_frame++;
        if ((u8)gSubSpriteData2.oam_pointer[gSubSpriteData2.curr_anim_frame].timer == 0x0)
            gSubSpriteData2.curr_anim_frame = 0x0;
    }
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void)
{

}

void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub)
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

/**
 * @brief 114e4 | 3c | Updates the current sprite position with the sub sprite data in parameter position and the X/Y position of its OAM data
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub)
{
    u16* pOam;

    pOam = pSub->oam_pointer[pSub->curr_anim_frame].oam_frame_ptr;

    gCurrentSprite.y_position = pSub->y_position + pOam[gCurrentSprite.room_slot * 0x3 + 0x1];
    gCurrentSprite.x_position = pSub->x_position + pOam[gCurrentSprite.room_slot * 0x3 + 0x2];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(struct SubSpriteData* pSub)
{

}

u8 SpriteCheckCollidingWithSamusDrawing(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 samus_y;
    u16 samus_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;

    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;

    sprite_top = sprite_y + gCurrentSprite.hitbox_top_offset;
    sprite_bottom = sprite_y + gCurrentSprite.hitbox_bottom_offset;
    sprite_left = sprite_x + gCurrentSprite.hitbox_left_offset;
    sprite_right = sprite_x + gCurrentSprite.hitbox_right_offset;

    samus_y = gSamusData.y_position;
    samus_x = gSamusData.x_position;

    samus_top = gSamusPhysics.draw_distance_top_offset + gSamusData.y_position;
    samus_bottom = gSamusData.y_position + gSamusPhysics.draw_distance_bottom_offset;
    samus_left = gSamusPhysics.draw_distance_left_offset + gSamusData.x_position;
    samus_right = gSamusData.x_position + gSamusPhysics.draw_distance_right_offset;

    if (SpriteUtilCheckObjectsTouching(sprite_top, sprite_bottom, sprite_left, sprite_right, samus_top, samus_bottom, samus_left, samus_right))
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
void SpriteUtilSetSplashEffect(u16 y_position, u16 x_position, u8 size)
{
    switch (gCurrentAffectingClipdata.hazard) // Switch on current hazard
    {
        case HAZARD_TYPE_WATER:
            if (size == SPLASH_SMALL)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_WATER_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_WATER_BIG);
            else
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_WATER_HUGE);
            break;

        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_STRONG_LAVA:
            if (size == SPLASH_SMALL)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_LAVA_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_LAVA_BIG);
            else
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_LAVA_HUGE);
            break;
        
        case HAZARD_TYPE_ACID:            
            if (size == SPLASH_SMALL)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_ACID_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_ACID_BIG);
            else
                ParticleSet(y_position, x_position, PE_SPRITE_SPLASH_ACID_HUGE);
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
u8 SpriteUtilCheckOutOfRoomEffect(u16 old_y, u16 y_position, u16 x_position, u8 size)
{
    if (old_y > gEffectYPosition && y_position <= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition((u16)(y_position + 0x40), x_position);
            SpriteUtilSetSplashEffect(y_position, x_position, size);
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
u8 SpriteUtilCheckInRoomEffect(u16 old_y, u16 y_position, u16 x_position, u8 size)
{
    if (old_y < gEffectYPosition && y_position >= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition(y_position, x_position);
            SpriteUtilSetSplashEffect(y_position, x_position, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

u16 SpriteUtilGetFinalCompletionPercentage(void)
{

}