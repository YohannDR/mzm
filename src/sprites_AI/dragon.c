#include "dragon.h"
#include "../sprite_util.h"
#include "../globals.h"

void DragonYMovement(void)
{
    u16 oldY;
    u16 y_spawn;

    oldY = gCurrentSprite.yPosition;
    y_spawn = gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if ((i32)(y_spawn - 0x7F) < gCurrentSprite.yPosition)
            gCurrentSprite.yPosition -= 0x2;
        SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if ((i32)(y_spawn - 0x2) > gCurrentSprite.yPosition)
            gCurrentSprite.yPosition += 0x2;
        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
}

void DragonInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x40;
    gCurrentSprite.hitboxBottomOffset = 0x50;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
    gCurrentSprite.pOam = dragon_oam_2d5ad8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = 0x8;
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

void DragonGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = dragon_oam_2d5ad8;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.timer = 0x64;
}

void DragonGoUp(void)
{
    /*u8 nslr;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;

    DragonYMovement();
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    if (gSamusData.yPosition <= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(0x180, 0x180);
        if (nslr != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
        
        if (nslr == NSLR_RIGHT)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (gCurrentSprite.timer == 0x0)
                {
                    yPosition = gCurrentSprite.yPosition - 0x88;
                    xPosition = gCurrentSprite.xPosition + 0x48;
                    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
                    if (gPreviousCollisionCheck == 0x0)
                        gCurrentSprite.pose = 0x34;
                }
            }
        }
        else if (nslr == NSLR_LEFT)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.pose = 0xA;
            else
            {
                if (gCurrentSprite.timer == 0x0)
                {
                    yPosition = gCurrentSprite.yPosition - 0x88;
                    xPosition = gCurrentSprite.xPosition - 0x48;
                    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
                    if (gPreviousCollisionCheck == 0x0)
                        gCurrentSprite.pose = 0x34;
                }
            }
        }
    }*/
}

void DragonTurningAroundGFXInit(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.pOam = dragon_oam_2d5b28;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void DragonCheckTurningAroundFirstHalfAnimEnded(void)
{
    DragonYMovement();
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.pOam = dragon_oam_2d5b40;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
    }
}

void DragonCheckTurningAroundSecondHalfAnimEnded(void)
{
    DragonYMovement();
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x34;
}

void DragonSpittingGFXInit(void)
{
    gCurrentSprite.pose = 0x35;
    gCurrentSprite.pOam = dragon_oam_2d5af8;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.timer = 0x1E;
}

void DragonSpittingAnim(void)
{
    DragonYMovement();
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.pOam = dragon_oam_2d5b10;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.timer = 0x8;
    }
}

void DragonSpawnFireball(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        DragonGFXInit();
        yPosition = gCurrentSprite.yPosition - 0x48;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition = gCurrentSprite.xPosition + 0x28;
        else
            xPosition = gCurrentSprite.xPosition - 0x28;
        SpriteSpawnSecondary(SSPRITE_DRAGON_FIREBALL, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
    }
}

void DragonFireballInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_PROJECTILE;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.hitboxTopOffset = -0x10;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x10;
    gCurrentSprite.hitboxRightOffset = 0x10;
    gCurrentSprite.pOam = dragon_fireball_oam_2d5b58;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0x0];
    
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oamRotation = 0x40;
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
        gCurrentSprite.oamRotation = 0x0;

    gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.arrayOffset = 0x0;
    SoundPlay(0x14C);
}

void DragonFireballMove(void)
{
    /*u16 xSpeed;
    u16 oldY;
    u8 offset;
    i16 movement;
    i16 rotation;

    xSpeed = 0xC;
    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.arrayOffset;
    movement = dragon_array_2d5134[offset];
    rotation = dragon_array_2d5184[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = dragon_array_2d5134[offset - 0x1];
        rotation = dragon_array_2d5184[offset - 0x1];
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        gCurrentSprite.arrayOffset = offset + 0x1;
        gCurrentSprite.yPosition += movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.xPosition += xSpeed;
        gCurrentSprite.oamRotation = rotation + 0x40;
    }
    else
    {
        gCurrentSprite.xPosition -= xSpeed;
        gCurrentSprite.oamRotation = -rotation;
    }

    if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_NONE))
        gCurrentSprite.pose = 0x42;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
            gCurrentSprite.pose = 0x42;
    }*/
}

void DragonFireballExplodingGFXInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.pOam = dragon_fireball_oam_2d5b78;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_YFLIP);
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
}

void DragonFireballCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void Dragon(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x14D);
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
                    DragonInit();
                    break;
                case 0x8:
                    dDragonGFXInit();
                case 0x9:
                    DragonGoUp();
                    break;
                case 0xA:
                    DragonTurningAroundGFXInit();
                case 0xB:
                    DragonCheckTurningAroundFirstHalfAnimEnded();
                    break;
                case 0xC:
                    DragonCheckTurningAroundSecondHalfAnimEnded();
                    break;
                case 0x34:
                    DragonSpittingGFXInit();
                case 0x35:
                    DragonSpittingAnim();
                    break;
                case 0x37:
                    DragonSpawnFireball();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}

void DragonFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DragonFireballInit();
        case 0x9:
            DragonFireballMove();
            break;
        case 0x42:
            DragonFireballExplodingGFXInit();
            break;
        case 0x43:
            DragonFireballCheckExplodingAnimEnded();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}