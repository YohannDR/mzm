#include "sprites_AI/crocomire.h"
#include "macros.h"

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
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
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

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

    gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxRightOffset = BLOCK_SIZE * 2;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

    gSubSpriteData1.pMultiOam = sCrocomireMultiSpriteData_Screaming;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gSubSpriteData1.workVariable2 = 0;
    gSubSpriteData1.workVariable1 = 0;

    gCurrentSprite.pose = CROCOMIRE_POSE_IDLE;
    gCurrentSprite.frozenPaletteRowOffset = 2;
    gCurrentSprite.roomSlot = CROCOMIRE_PART_HEAD;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_LEGS, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_BODY, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_TONGUE, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_CROCOMIRE_PART, CROCOMIRE_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);
}

/**
 * @brief 43f10 | 24 | Initializes Crocomire to be idle
 * 
 */
void CrocomireIdleInit(void)
{
    gSubSpriteData1.pMultiOam = sCrocomireMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

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
    gCurrentSprite.health = 1;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = CROCOMIRE_PART_POSE_IDLE;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case CROCOMIRE_PART_RIGHT_ARM:
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottomOffset = PIXEL_SIZE;
            gCurrentSprite.hitboxLeftOffset = -PIXEL_SIZE;
            gCurrentSprite.hitboxRightOffset = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 2;
            break;

        case CROCOMIRE_PART_LEGS:
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

            gCurrentSprite.drawOrder = 3;
            break;

        case CROCOMIRE_PART_BODY:
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

            gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            break;

        case CROCOMIRE_PART_TONGUE:
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = 0;
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = 0;
            gCurrentSprite.hitboxRightOffset = 0;

            gCurrentSprite.drawOrder = 6;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case CROCOMIRE_PART_LEFT_ARM:
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottomOffset = PIXEL_SIZE;
            gCurrentSprite.hitboxLeftOffset = -PIXEL_SIZE;
            gCurrentSprite.hitboxRightOffset = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 6;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

void Crocomire(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose > 0x61 && gCurrentSprite.pose < 0x62)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = CROCOMIRE_PART_POSE_DYING;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        CrocomirePartInit();

    CrocomireSyncSubSprites();
}
