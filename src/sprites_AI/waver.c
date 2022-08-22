#include "waver.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sWaverGFX[289];
const u16 sWaverPAL[16];

const u16 sWaverOAM_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x216
};

const u16 sWaverOAM_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x204
};

const u16 sWaverOAM_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x207
};

const u16 sWaverOAM_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20b
};

const u16 sWaverOAM_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x236
};

const u16 sWaverOAM_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x21a
};

const struct FrameData sWaverOAM[7] = {
    sWaverOAM_Frame0,
    0x6,
    sWaverOAM_Frame1,
    0x6,
    sWaverOAM_Frame2,
    0x6,
    sWaverOAM_Frame3,
    0x6,
    sWaverOAM_Frame4,
    0x6,
    sWaverOAM_Frame5,
    0x6,
    NULL,
    0x0
};

/**
 * @brief 2483c | 68 | Initializes a waver sprite
 * 
 */
void WaverInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = -0x20;

    gCurrentSprite.pOam = sWaverOAM;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = WAVER_POSE_MOVING;
}

/**
 * @brief 248a4 | e0 | Handles a waver moving
 * 
 */
void WaverMove(void)
{
    u16 speed;

    speed = 0x2;
    // Move horizontaly
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRightOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeftOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    }

    // Move vertically
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTopOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= speed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
}

/**
 * @brief 2498c | 84 | Waver AI
 * 
 */
void Waver(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x177);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;
        switch (gCurrentSprite.pose)
        {
            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;
            case 0x0:
                WaverInit();
                break;
            case WAVER_POSE_MOVING:
                WaverMove();
        }
    }
}