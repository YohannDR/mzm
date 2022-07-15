#include "metroid.h"
#include "../event.h"
#include "../projectile.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 MetroidCheckAirCollision(u16 y_position, u16 x_position)
{
    u8 colliding;

    colliding = FALSE;
    if (gSamusPhysics.horizontal_moving_direction == HDMOVING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(y_position - 0x30, x_position + 0x3C);
        if (gPreviousCollisionCheck == 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(y_position + 0x10, x_position + 0x3C);
            if (gPreviousCollisionCheck != 0x0)
                colliding = TRUE;
        }
        else
            colliding = TRUE;
    }
    else
    {
        if (gSamusPhysics.horizontal_moving_direction == HDMOVING_LEFT)
        {
            SpriteUtilCheckCollisionAtPosition(y_position - 0x30, x_position - 0x3C);
            if (gPreviousCollisionCheck == 0x0)
            {
                SpriteUtilCheckCollisionAtPosition(y_position + 0x10, x_position - 0x3C);
                if (gPreviousCollisionCheck != 0x0)
                    colliding = TRUE;
            }
            else
                colliding = TRUE;
        }
    }

    return colliding;
}

void MetroidMove(u16 samus_y, u16 samus_x, u8 speed_y, u8 speed_x, u8 speed_divisor)
{

}

u8 MetroidBombDetection(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 proj_y;
    u16 proj_x;
    u16 proj_top;
    u16 proj_bottom;
    u16 proj_left;
    u16 proj_right;
    u8 count;
    u8 status;
    struct ProjectileData* pProj;

    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;
    sprite_top = sprite_y + gCurrentSprite.hitbox_top_offset;
    sprite_bottom = sprite_y + gCurrentSprite.hitbox_bottom_offset;
    sprite_left = sprite_x + gCurrentSprite.hitbox_left_offset;
    sprite_right = sprite_x + gCurrentSprite.hitbox_right_offset;
    status = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;
        if (pProj->type == PROJ_TYPE_BOMB && (pProj->status & status) == status)
        {
            proj_y = pProj->y_position;
            proj_x = pProj->x_position;
            proj_top = proj_y + pProj->hitbox_top_offset;
            proj_bottom = proj_y + pProj->hitbox_bottom_offset;
            proj_left = proj_x + pProj->hitbox_left_offset;
            proj_right = proj_x + pProj->hitbox_right_offset;

            if (SpriteUtilCheckObjectsTouching(sprite_top, sprite_bottom, sprite_left, sprite_right, proj_top, proj_bottom, proj_left, proj_right))
                return TRUE;
        }
        count++;
    }

    return FALSE;
}

void MetroidCheckBouncingOnMetroid(u16 movement)
{

}

u8 MetroidCheckSamusGrabbed(void)
{
    u8 count;

    count = 0x0;
    while (count <= 0x17)
    {
        if (gSpriteData[count].status & SPRITE_STATUS_EXISTS && gSpriteData[count].samus_collision == SSC_METROID && gSpriteData[count].pose != 0x9)
            return TRUE;
        count++;
    }
    return FALSE;
}

void MetroidPlaySound(void)
{
    if (gCurrentSprite.curr_anim_frame == 0x0 && gCurrentSprite.anim_duration_counter == 0x1 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x170);
}

void MetroidInit(void)
{
    u8 metroid_state;
    u8 slot;

    metroid_state = 0x0;
    switch (gCurrentRoom)
    {
        case 0xE:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIRST_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x1:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_THIRD_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x2:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIFTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0xF:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SECOND_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x10:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SIXTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x13:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FOURTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        default:
            metroid_state = 0x2;
    }

    if (metroid_state == 0x0)
        gCurrentSprite.status = 0x0;
    else
    {
        if (metroid_state == 0x1)
            gDoorUnlockTimer = 0x1;
        
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
        gCurrentSprite.oam_scaling = 0x40;
        gCurrentSprite.oam_rotation = 0x0;
        gCurrentSprite.draw_distance_top_offset = 0x6;
        gCurrentSprite.draw_distance_bottom_offset = 0x6;
        gCurrentSprite.draw_distance_horizontal_offset = 0x5;
        gCurrentSprite.hitbox_top_offset = -0x28;
        gCurrentSprite.hitbox_bottom_offset = 0x20;
        gCurrentSprite.hitbox_left_offset = -0x28;
        gCurrentSprite.hitbox_right_offset = 0x28;
        gCurrentSprite.oam_pointer = metroid_oam_2edd20;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
        gCurrentSprite.y_position_spawn = gCurrentSprite.health;
        gCurrentSprite.samus_collision = SSC_NONE;
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.pose = 0x1;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.array_offset = 0x0;
        gCurrentSprite.draw_order = 0xC;

        slot = SpriteSpawnSecondary(SSPRITE_METROID_SHELL, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
        if (slot == 0xFF)
            gCurrentSprite.status = 0x0;
        gCurrentSprite.palette_row = 0x3;
    }
}

void MetroidCheckSpawn(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        gCurrentSprite.pose = 0x2;
        gCurrentSprite.draw_distance_top_offset = 0x18;
        gCurrentSprite.draw_distance_bottom_offset = 0x18;
        gCurrentSprite.draw_distance_horizontal_offset = 0x14;
        gCurrentSprite.timer1 = (gSpriteRNG << 0x2) + 0x1;
    }
}

void MetroidSpawning(void)
{

}

void MetroidSpawnedGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0x1;
    gCurrentSprite.timer1 = 0x0;
    gCurrentSprite.array_offset = 0x1;
    gCurrentSprite.oam_pointer = metroid_oam_2edc20;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void MetroidMovement(void)
{
    MetroidPlaySound();
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (MetroidCheckSamusGrabbed() << 0x18)
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            gCurrentSprite.pose = 0x42;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
            return;
        }
    }
    MetroidCheckBouncingOnMetroid(0x1);
    MetroidMove((u16)(gSamusData.y_position + gSamusPhysics.draw_distance_top_offset), gSamusData.x_position, 0x1E, 0x28, 0x2);
}

void MetroidGrabSamusGFXInit(void)
{
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.oam_pointer = metroid_oam_2edca8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.timer1 = 0x4;
    gCurrentSprite.workVariable = 0x4;
    gCurrentSprite.frozen_palette_row_offset = 0x4;
    gCurrentSprite.oam_rotation = 0x0;
    gEquipment.grabbed_by_metroid = TRUE;
}

void MetroidSamusGrabbed(void)
{

}

void MetroidDeath(void)
{
    struct SpriteData* pSprite;
    u8 is_metroid_alive;
    u8 rng;
    u16 y_position;
    u16 x_position;
    u8 metroid_id;
    u8 frozen_id;
    u16 exists;
    u8 secondary;
    u8 pose;

    rng = gSpriteRNG;
    y_position = gCurrentSprite.y_position;
    x_position = gCurrentSprite.x_position;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        y_position += rng;
    else 
        y_position -= rng;

    SpriteUtilSpriteDeath(DEATH_NORMAL, y_position, x_position + 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);

    metroid_id = PSPRITE_METROID;
    frozen_id = PSPRITE_FROZEN_METROID;
    pose = 0x62;
    exists = SPRITE_STATUS_EXISTS;
    secondary = SP_SECONDARY_SPRITE;
    is_metroid_alive = FALSE;
    pSprite = gSpriteData;
    while (pSprite < gSpriteData + 24)
    {
        if (pSprite->status & exists && (pSprite->properties & secondary) == 0x0 && (pSprite->sprite_id == metroid_id || pSprite->sprite_id == frozen_id) && pSprite->pose < pose)
        {
            is_metroid_alive++;
            break;
        }
        pSprite++;
    }

    if (!is_metroid_alive)
    {
        switch (gCurrentRoom)
        {
            case 0xE:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FIRST_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x1:
                EventFunction(EVENT_ACTION_SETTING, EVENT_THIRD_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x2:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FIFTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0xF:
                EventFunction(EVENT_ACTION_SETTING, EVENT_SECOND_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x10:
                EventFunction(EVENT_ACTION_SETTING, EVENT_SIXTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x13:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FOURTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
        }
    }
}

void Metroid(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x172);
    }
    else
    {
        if ((gCurrentSprite.invicibility_stun_flash_timer & 0x7F) == 0x2)
        {
            if (gCurrentSprite.health == gCurrentSprite.y_position_spawn)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    unk_2b20(0x171);
            }
            else
                gCurrentSprite.y_position_spawn = gCurrentSprite.health;
        }
    }

    if (gCurrentSprite.freeze_timer != 0x0)
    {
        gCurrentSprite.hitbox_top_offset = -0x30;
        gCurrentSprite.hitbox_bottom_offset = 0x28;
        gCurrentSprite.hitbox_left_offset = -0x40;
        gCurrentSprite.hitbox_right_offset = 0x40;
        MetroidCheckBouncingOnMetroid(0x1);
        if (gDifficulty == 0x0)
            SpriteUtilUnfreezeAnimEasy();
        else
            SpriteUtilMetroidUnfreezeAnim();
        gCurrentSprite.sprite_id = PSPRITE_FROZEN_METROID;
    }
    else 
    {
        if (gCurrentSprite.sprite_id == PSPRITE_FROZEN_METROID)
        {
            gCurrentSprite.hitbox_top_offset = -0x28;
            gCurrentSprite.hitbox_bottom_offset = 0x20;
            gCurrentSprite.hitbox_left_offset = -0x28;
            gCurrentSprite.hitbox_right_offset = 0x28;
            gCurrentSprite.sprite_id = PSPRITE_METROID;
            if (gCurrentSprite.pose < 0x62)
                gCurrentSprite.pose = 0x8;
        }

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                MetroidInit();
                break;
            case 0x1:
                MetroidCheckSpawn();
                break;
            case 0x2:
                MetroidSpawning();
                break;
            case 0x8:
                MetroidSpawnedGFXInit();
            case 0x9:
                MetroidMovement();
                break;
            case 0x42:
                MetroidGrabSamusGFXInit();
            case 0x43:
                MetroidSamusGrabbed();
                break;
            case 0x62:
                MetroidDeath();
        }

        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    }
}

void MetroidShell(void)
{
    u8 slot;
    u8 rng;
    u16 y_position;
    u16 x_position;

    slot = gCurrentSprite.primary_sprite_ram_slot;
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.palette_row = gSpriteData[slot].palette_row;
    if (gSpriteData[slot].health == 0x0)
    {
        rng = gSpriteRNG;
        y_position = gCurrentSprite.y_position;
        x_position = gCurrentSprite.x_position;
        if (gSpriteData[slot].status & SPRITE_STATUS_XFLIP)
            y_position -= rng;
        else
            y_position += rng;

        gCurrentSprite.sprite_id = PSPRITE_METROID;
        gCurrentSprite.properties &= ~SP_SECONDARY_SPRITE;
        SpriteUtilSpriteDeath(DEATH_NORMAL, y_position, x_position - 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
    else
    {
        if (gCurrentSprite.pose == 0x0)
        {
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.draw_distance_top_offset = 0x14;
            gCurrentSprite.draw_distance_bottom_offset = 0xA;
            gCurrentSprite.draw_distance_horizontal_offset = 0x18;
            gCurrentSprite.hitbox_top_offset = -0x4;
            gCurrentSprite.hitbox_bottom_offset = 0x4;
            gCurrentSprite.hitbox_left_offset = -0x4;
            gCurrentSprite.hitbox_right_offset = 0x4;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.draw_order = 0x3;
            gCurrentSprite.oam_pointer = metroid_shell_oam_2edc08;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN && (gSpriteData[slot].status & SPRITE_STATUS_YFLIP) == 0x0)
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.y_position = gSpriteData[slot].y_position;
        gCurrentSprite.x_position = gSpriteData[slot].x_position;
    }
}

void MetroidDoorLock(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.draw_distance_top_offset = 0x1;
        gCurrentSprite.draw_distance_bottom_offset = 0x1;
        gCurrentSprite.draw_distance_horizontal_offset = 0x1;
        gCurrentSprite.hitbox_top_offset = 0x0;
        gCurrentSprite.hitbox_bottom_offset = 0x0;
        gCurrentSprite.hitbox_left_offset = 0x0;
        gCurrentSprite.hitbox_right_offset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.oam_pointer = large_energy_oam_2b2750;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;

        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) != 0x0)
            gDoorUnlockTimer = 0x1;
        else
            gCurrentSprite.status = 0x0;
    }
    else
    {
        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) == 0x0 && SpriteUtilCountPrimarySprites(PSPRITE_FROZEN_METROID) == 0x0)
        {
            gCurrentSprite.status = 0x0;
            gDoorUnlockTimer = -0x14;
        }
    }
}