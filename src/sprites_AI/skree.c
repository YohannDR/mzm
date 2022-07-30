#include "skree.h"
#include "../data/data.h"
#include "../sprite_debris.h"
#include "../sprite_util.h"
#include "../globals.h"

void SkreeInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x60;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= 0x40;
}

void SkreeGFXInit(void)
{
    gCurrentSprite.pOam = skree_oam_2cd474;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_DETECTING_SAMUS;
}

void SkreeDetectSamus(void)
{
    if (gSamusData.yPosition > gCurrentSprite.yPosition && gSamusData.yPosition - gCurrentSprite.yPosition < 0x284 && (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0 && gSamusData.xPosition > gCurrentSprite.xPosition - 0x96 && gSamusData.xPosition < gCurrentSprite.xPosition + 0x96)
        gCurrentSprite.pose = SKREE_POSE_SPINNING_INIT;
}

void SkreeSpinGFXInit(void)
{
    gCurrentSprite.pOam = skree_oam_spinning_2cd49c;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_SPINNING;
}

void SkreeCheckSpinAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SKREE_POSE_GOING_DOWN_INIT;
}

void SkreeStartGoingDown(void)
{
    gCurrentSprite.pOam = skree_going_down_2cd4cc;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = SKREE_POSE_GOING_DOWN;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x141);
}

void SkreeGoDown(void)
{
    u32 block;
    u32 xMovement;
    u32 yMovement;
    u32 arrayOffset;

    block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != 0x0)
    {
        gCurrentSprite.yPosition = block - gCurrentSprite.hitboxBottomOffset;
        gCurrentSprite.pose = SKREE_POSE_CRASHING;
        gCurrentSprite.timer = 0x0;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            SoundPlay(0x142);
    }
    else
    {
        xMovement = gCurrentSprite.workVariable2 >> 0x2;
        arrayOffset = gCurrentSprite.arrayOffset;
        yMovement = skree_falling_speed_2cca7c[arrayOffset];
        if (yMovement == SPRITE_ARRAY_TERMINATOR)
        {
            yMovement = skree_falling_speed_2cca7c[arrayOffset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }

        if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) != 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x40, gCurrentSprite.xPosition + 0x20);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition += xMovement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x40, gCurrentSprite.xPosition - 0x20);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition -= xMovement;
        }

        if (xMovement < 0x10)
            gCurrentSprite.workVariable2++;
    }
}

void SkreeCrashGround(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 spriteID;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentSprite.timer++;

    switch (gCurrentSprite.timer)
    {
        case 0x1:
            yPosition += 0x48;
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1E);
            break;

        case 0x28:
            gCurrentSprite.pOam = skree_oam_crashing_2cd4f4;
            break;

        case 0x3C:
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.primarySpriteRAMSlot;

            if (gCurrentSprite.spriteID == PSPRITE_SKREE_BLUE)
                spriteID = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                spriteID = SSPRITE_SKREE_EXPLOSION;
            
            SpriteSpawnSecondary(spriteID, 0x0, gfxSlot, ramSlot, yPosition - 0x8, xPosition, 0x0);
            SpriteSpawnSecondary(spriteID, 0x0, gfxSlot, ramSlot, yPosition - 0x8, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(spriteID, 0x1, gfxSlot, ramSlot, yPosition + 0x8, xPosition - 0xC, 0x0);
            SpriteSpawnSecondary(spriteID, 0x1, gfxSlot, ramSlot, yPosition + 0x8, xPosition + 0xC, SPRITE_STATUS_XFLIP);
            gCurrentSprite.status = 0x0;
            ParticleSet(yPosition + 0x24, xPosition, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x134);
    }
}

void SkreeExplosionInit(void)
{
    u16 status;

    status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN | (SPRITE_STATUS_UNKNOWN3 | SPRITE_STATUS_NONE);
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.hitboxTopOffset = -0xC;
    gCurrentSprite.hitboxBottomOffset = 0xC;
    gCurrentSprite.hitboxLeftOffset = -0xC;
    gCurrentSprite.hitboxRightOffset = 0xC;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.yPosition += 0x28;
    gCurrentSprite.status = (status | SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING);
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.oamRotation = 0x0;

    if (gCurrentSprite.roomSlot != 0x0)
        gCurrentSprite.pOam = skree_explosion_oam_going_down_2cd5c4;
    else
        gCurrentSprite.pOam = skree_explosion_oam_going_up_2cd5e4;
}

void SkreeExplosionMove(void)
{
    if (gCurrentSprite.currentAnimationFrame > 0x1)
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if ((gCurrentSprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        gCurrentSprite.xPosition += 0x8;
        gCurrentSprite.oamRotation += 0x20;
    }
    else
    {
        gCurrentSprite.xPosition -= 0x8;
        gCurrentSprite.oamRotation -= 0x20;
    }

    if (gCurrentSprite.roomSlot != 0x0)
        gCurrentSprite.yPosition += 0x4;
    else
        gCurrentSprite.yPosition -= 0x4;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void Skree(void)
{
    if ((gCurrentSprite.properties & SP_DAMAGED) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            SoundPlayNotAlreadyPlaying(0x143);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    SkreeInit();
                case 0x8:
                    SkreeGFXInit();
                case SKREE_POSE_DETECTING_SAMUS:
                    SkreeDetectSamus();
                    break;
                case SKREE_POSE_SPINNING_INIT:
                    SkreeSpinGFXInit();
                case SKREE_POSE_SPINNING:
                    SkreeCheckSpinAnimEnded();
                    break;
                case SKREE_POSE_GOING_DOWN_INIT:
                    SkreeStartGoingDown();
                case SKREE_POSE_GOING_DOWN:
                    SkreeGoDown();
                    break;
                case SKREE_POSE_CRASHING:
                    SkreeCrashGround();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x34, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}

void SkreeExplosion(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SkreeExplosionInit();

        case 0x9:
            SkreeExplosionMove();
    }
}