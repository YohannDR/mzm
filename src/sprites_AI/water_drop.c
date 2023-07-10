#include "sprites_AI/water_drop.h"
#include "macros.h"

#include "data/particle_data.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

/**
 * @brief 12780 | 2c | Initializes a water drop sprite
 * 
 */
void WaterDropInit(void)
{
    gCurrentSprite.hitboxTopOffset = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottomOffset = PIXEL_SIZE;
    gCurrentSprite.hitboxLeftOffset = -PIXEL_SIZE;
    gCurrentSprite.hitboxRightOffset = PIXEL_SIZE;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 1;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 127ac | 288 | Water drop AI 
 * 
 */
void WaterDrop(void)
{
    u16 offset;
    u32 block;
    s32 movement;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            WaterDropInit();

            gCurrentSprite.yPosition -= BLOCK_SIZE;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sWaterDropOam_Spawning;

            gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
            gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = WATER_DROP_POSE_SPAWNING;
            gCurrentSprite.timer = gSpriteRng * 8;
            break;

        case WATER_DROP_POSE_CHECK_SPAWNING_ENDED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sWaterDropOam_Falling;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.workVariable = FALSE;
                gCurrentSprite.arrayOffset = 0;
                gCurrentSprite.pose = WATER_DROP_POSE_FALLING;
            }
            break;

        case WATER_DROP_POSE_FALLING:
            block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            {
                // Splashing on water
                if (gEffectYPosition != 0)
                {
                    // Splashing on room effect
                    gCurrentSprite.yPosition = gEffectYPosition;
                    gCurrentSprite.workVariable = TRUE;
                }
                else
                {
                    // Splashing on water clipdata
                    gCurrentSprite.yPosition = block;
                }

                gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING_INIT;
            }
            else
            {
                // Splashing on ground
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                {
                    gCurrentSprite.yPosition = block;
                    gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING_INIT;
                    break;
                }

                // Fall
                offset = gCurrentSprite.arrayOffset;
                movement = sSpritesFallingSpeed[offset]; 
                if (movement == SHORT_MAX)
                {
                    movement = sSpritesFallingSpeed[offset - 1];
                    gCurrentSprite.yPosition += movement;
                }
                else
                {
                    gCurrentSprite.arrayOffset++;
                    gCurrentSprite.yPosition += movement;
                }
            }
            break;

        case WATER_DROP_POSE_SPLASHING_INIT:
            gCurrentSprite.pOam = sWaterDropOam_Splashing;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = WATER_DROP_POSE_SPLASHING;

        case WATER_DROP_POSE_SPLASHING:
            if (gCurrentSprite.workVariable)
                gCurrentSprite.yPosition = gEffectYPosition;

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = WATER_DROP_POSE_SPAWNING;
                gCurrentSprite.timer = 100 + gSpriteRng * 8;
            }
            break;

        case WATER_DROP_POSE_SPAWNING:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.pOam = sWaterDropOam_Spawning;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.pose = WATER_DROP_POSE_CHECK_SPAWNING_ENDED;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
                gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

                if (MOD_AND(gSpriteRng, 2))
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + DIV_SHIFT(gSpriteRng + 1, 2);
                else
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - DIV_SHIFT(gSpriteRng + 1, 2);
            }
    }
}
