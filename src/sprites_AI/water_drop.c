#include "water_drop.h"
#include "../../data/data.h"
#include "../data/particle_data.c"
#include "../data/sprite_data.c"
#include "../globals.h"

/**
 * @brief 12780 | 2c | Initializes a water drop sprite
 * 
 */
void WaterDropInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 127ac | 288 | Water drop AI 
 * 
 */
void WaterDrop(void)
{
    u16 offset;
    u32 block;
    i32 movement;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WaterDropInit();
            gCurrentSprite.yPosition -= 0x40;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pOam = sWaterDropOAM_Spawning;

            gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
            gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = WATER_DROP_POSE_SPAWNING;
            gCurrentSprite.timer = gSpriteRNG << 0x3;
            break;

        case WATER_DROP_POSE_CHECK_SPAWNING_ENDED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sWaterDropOAM_Falling;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;

                gCurrentSprite.workVariable = FALSE;
                gCurrentSprite.arrayOffset = 0x0;
                gCurrentSprite.pose = WATER_DROP_POSE_FALLING;
            }
            break;

        case WATER_DROP_POSE_FALLING:
            block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            {
                // Splashing on water
                if (gEffectYPosition != 0x0)
                {
                    gCurrentSprite.yPosition = gEffectYPosition;
                    gCurrentSprite.workVariable = TRUE;
                }
                else
                    gCurrentSprite.yPosition = block;
                gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING_INIT;
            }
            else
            {
                // Splashing on ground
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                {
                    gCurrentSprite.yPosition = block;
                    gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING_INIT;
                }
                else
                {
                    // Fall
                    offset = gCurrentSprite.arrayOffset;
                    movement = sSpritesFallingSpeed[offset]; 
                    if (movement == SHORT_MAX)
                    {
                        movement = sSpritesFallingSpeed[offset - 0x1];
                        gCurrentSprite.yPosition += movement;
                    }
                    else
                    {
                        gCurrentSprite.arrayOffset++;
                        gCurrentSprite.yPosition += movement;
                    }
                }
            }
            break;

        case WATER_DROP_POSE_SPLASHING_INIT:
            gCurrentSprite.pOam = sWaterDropOAM_Splashing;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING;

        case WATER_DROP_POSE_SPLASHING:
            if (gCurrentSprite.workVariable)
                gCurrentSprite.yPosition = gEffectYPosition;

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = WATER_DROP_POSE_SPAWNING;
                gCurrentSprite.timer = (gSpriteRNG << 0x3) + 0x64;
            }
            break;

        case WATER_DROP_POSE_SPAWNING:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.pOam = sWaterDropOAM_Spawning;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;

                gCurrentSprite.pose = WATER_DROP_POSE_CHECK_SPAWNING_ENDED;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
                gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

                if (gSpriteRNG & 0x1)
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + ((i32)(gSpriteRNG + 0x1) >> 1);
                else
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - ((i32)(gSpriteRNG + 0x1) >> 1);
            }
    }
}