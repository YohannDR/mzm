#include "metroid.h"
#include "../event.h"
#include "../projectile.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 MetroidCheckAirCollision(u16 yPosition, u16 xPosition)
{
    u8 colliding;

    colliding = FALSE;
    if (gSamusPhysics.horizontalMovingDirection == HDMOVING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition + 0x3C);
        if (gPreviousCollisionCheck == 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition + 0x3C);
            if (gPreviousCollisionCheck != 0x0)
                colliding = TRUE;
        }
        else
            colliding = TRUE;
    }
    else
    {
        if (gSamusPhysics.horizontalMovingDirection == HDMOVING_LEFT)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition - 0x3C);
            if (gPreviousCollisionCheck == 0x0)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition - 0x3C);
                if (gPreviousCollisionCheck != 0x0)
                    colliding = TRUE;
            }
            else
                colliding = TRUE;
        }
    }

    return colliding;
}

void MetroidMove(u16 samusY, u16 samusX, u8 speed_y, u8 speed_x, u8 speedDivisor)
{

}

u8 MetroidBombDetection(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    u8 count;
    u8 status;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
    status = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;
        if (pProj->type == PROJ_TYPE_BOMB && (pProj->status & status) == status)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            projTop = projY + pProj->hitboxTopOffset;
            projBottom = projY + pProj->hitboxBottomOffset;
            projLeft = projX + pProj->hitboxLeftOffset;
            projRight = projX + pProj->hitboxRightOffset;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
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
        if (gSpriteData[count].status & SPRITE_STATUS_EXISTS && gSpriteData[count].samusCollision == SSC_METROID && gSpriteData[count].pose != 0x9)
            return TRUE;
        count++;
    }
    return FALSE;
}

void MetroidPlaySound(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
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
        gCurrentSprite.oamScaling = 0x40;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.drawDistanceTopOffset = 0x6;
        gCurrentSprite.drawDistanceBottomOffset = 0x6;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x5;
        gCurrentSprite.hitboxTopOffset = -0x28;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x28;
        gCurrentSprite.hitboxRightOffset = 0x28;
        gCurrentSprite.pOam = metroid_oam_2edd20;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
        gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
        gCurrentSprite.samusCollision = SSC_NONE;
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.pose = 0x1;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.drawOrder = 0xC;

        slot = SpriteSpawnSecondary(SSPRITE_METROID_SHELL, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        if (slot == 0xFF)
            gCurrentSprite.status = 0x0;
        gCurrentSprite.paletteRow = 0x3;
    }
}

void MetroidCheckSpawn(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        gCurrentSprite.pose = 0x2;
        gCurrentSprite.drawDistanceTopOffset = 0x18;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x14;
        gCurrentSprite.timer = (gSpriteRNG << 0x2) + 0x1;
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
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.arrayOffset = 0x1;
    gCurrentSprite.pOam = metroid_oam_2edc20;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
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
    MetroidMove((u16)(gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset), gSamusData.xPosition, 0x1E, 0x28, 0x2);
}

void MetroidGrabSamusGFXInit(void)
{
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.pOam = metroid_oam_2edca8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0x4;
    gCurrentSprite.workVariable = 0x4;
    gCurrentSprite.frozenPaletteRowOffset = 0x4;
    gCurrentSprite.oamRotation = 0x0;
    gEquipment.grabbedByMetroid = TRUE;
}

void MetroidSamusGrabbed(void)
{

}

void MetroidDeath(void)
{
    struct SpriteData* pSprite;
    u8 is_metroid_alive;
    u8 rng;
    u16 yPosition;
    u16 xPosition;
    u8 metroid_id;
    u8 frozen_id;
    u16 exists;
    u8 secondary;
    u8 pose;

    rng = gSpriteRNG;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        yPosition += rng;
    else 
        yPosition -= rng;

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition + 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);

    metroid_id = PSPRITE_METROID;
    frozen_id = PSPRITE_FROZEN_METROID;
    pose = 0x62;
    exists = SPRITE_STATUS_EXISTS;
    secondary = SP_SECONDARY_SPRITE;
    is_metroid_alive = FALSE;
    pSprite = gSpriteData;
    while (pSprite < gSpriteData + 24)
    {
        if (pSprite->status & exists && (pSprite->properties & secondary) == 0x0 && (pSprite->spriteID == metroid_id || pSprite->spriteID == frozen_id) && pSprite->pose < pose)
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
        if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x2)
        {
            if (gCurrentSprite.health == gCurrentSprite.yPositionSpawn)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    unk_2b20(0x171);
            }
            else
                gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
        }
    }

    if (gCurrentSprite.freezeTimer != 0x0)
    {
        gCurrentSprite.hitboxTopOffset = -0x30;
        gCurrentSprite.hitboxBottomOffset = 0x28;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x40;
        MetroidCheckBouncingOnMetroid(0x1);
        if (gDifficulty == 0x0)
            SpriteUtilUnfreezeAnimEasy();
        else
            SpriteUtilMetroidUnfreezeAnim();
        gCurrentSprite.spriteID = PSPRITE_FROZEN_METROID;
    }
    else 
    {
        if (gCurrentSprite.spriteID == PSPRITE_FROZEN_METROID)
        {
            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x28;
            gCurrentSprite.hitboxRightOffset = 0x28;
            gCurrentSprite.spriteID = PSPRITE_METROID;
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
    u16 yPosition;
    u16 xPosition;

    slot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.paletteRow = gSpriteData[slot].paletteRow;
    if (gSpriteData[slot].health == 0x0)
    {
        rng = gSpriteRNG;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        if (gSpriteData[slot].status & SPRITE_STATUS_XFLIP)
            yPosition -= rng;
        else
            yPosition += rng;

        gCurrentSprite.spriteID = PSPRITE_METROID;
        gCurrentSprite.properties &= ~SP_SECONDARY_SPRITE;
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition - 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
    else
    {
        if (gCurrentSprite.pose == 0x0)
        {
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0xA;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = metroid_shell_oam_2edc08;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN && (gSpriteData[slot].status & SPRITE_STATUS_YFLIP) == 0x0)
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.yPosition = gSpriteData[slot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[slot].xPosition;
    }
}

void MetroidDoorLock(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x1;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = large_energy_oam_2b2750;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

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