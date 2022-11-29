#include "sprites_AI/crocomire.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/crocomire.h"
#include "data/sprite_data.h"

#include "constants/sprite.h"

#include "structs/sprite.h"

/**
 * @brief 43d88 | 68 | Synchronize the sub sprites of Crocomire
 * 
 */
void CrocomireSyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sCrocomireFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sCrocomireFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 43df0 | 120 | Initializes a Crocomire sprite
 * 
 */
void CrocomireInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;

    gCurrentSprite.xPositionSpawn = xPosition;

    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

    gCurrentSprite.hitboxTopOffset = -0x40;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0xA0;
    gCurrentSprite.hitboxRightOffset = 0x80;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

    gSubSpriteData1.pMultiOam = sCrocomireMultiSpriteData_Screaming;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gSubSpriteData1.workVariable2 = 0x0;
    gSubSpriteData1.workVariable1 = 0x0;

    gCurrentSprite.pose = CROCOMIRE_POSE_IDLE;
    gCurrentSprite.frozenPaletteRowOffset = 0x2;
    gCurrentSprite.roomSlot = CROCOMIRE_PART_HEAD;

    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_LEGS, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_BODY, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_TONGUE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
}

/**
 * @brief 43f10 | 24 | Initializes Crocomire to be idle
 * 
 */
void CrocomireIdleInit(void)
{
    gSubSpriteData1.pMultiOam = sCrocomireMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = CROCOMIRE_POSE_IDLE;
}

void Crocomire_Empty(void)
{
    return;
}

/**
 * @brief 43f38 | 160 | Initializes a crocomire part sprite
 * 
 */
void CrocomirePartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = 0x1;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = CROCOMIRE_PART_POSE_IDLE;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case CROCOMIRE_PART_RIGHT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x2C;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0x2;
            break;

        case CROCOMIRE_PART_LEGS:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0xC0;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.drawOrder = 0x3;
            break;

        case CROCOMIRE_PART_BODY:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = 0xA0;

            gCurrentSprite.drawOrder = 0x5;
            break;

        case CROCOMIRE_PART_TONGUE:
            gCurrentSprite.drawDistanceTopOffset = 0xA;
            gCurrentSprite.drawDistanceBottomOffset = 0xA;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.drawOrder = 0x6;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case CROCOMIRE_PART_LEFT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x2A;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0x6;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

void Crocomire(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            CrocomireInit();
            break;

        case CROCOMIRE_POSE_IDLE_INIT:
            CrocomireIdleInit();

        case CROCOMIRE_POSE_IDLE:
            Crocomire_Empty();
    }

    SpriteUtilUpdateSubSprite1Anim();
    CrocomireSyncSubSprites();
}

/**
 * @brief 440dc | 6c | Crocomire part AI
 * 
 */
void CrocomirePart(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose > 0x61 && gCurrentSprite.pose < 0x62)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = CROCOMIRE_PART_POSE_DYING;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
    }

    if (gCurrentSprite.pose == 0x0)
        CrocomirePartInit();

    CrocomireSyncSubSprites();
}