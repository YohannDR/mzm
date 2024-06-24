#include "sprites_AI/power_grip.h"
#include "macros.h"

#include "data/sprites/power_grip.h"

#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 132d4 | 13c | Power grip AI
 * 
 */
void PowerGrip(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (gEquipment.suitMisc & SMF_POWER_GRIP)
            {
                // Already has power grip, kill
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxBottomOffset = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxLeftOffset = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxRightOffset = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);

            gCurrentSprite.pOam = sPowerGripOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
            gCurrentSprite.health = 1;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.pose = POWER_GRIP_POSE_IDLE;

            // Spawn glow
            SpriteSpawnSecondary(SSPRITE_POWER_GRIP_GLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            break;

        case POWER_GRIP_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                gPreventMovementTimer = SAMUS_ITEM_PMT;
                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.ignoreSamusCollisionTimer = 1;
                gCurrentSprite.pose = POWER_GRIP_POSE_BEING_ACQUIRED;
                gCurrentSprite.work0 = 0;
                gEquipment.suitMisc |= SMF_POWER_GRIP;
                EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);

                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_POWER_GRIP, 6,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
            break;

        case POWER_GRIP_POSE_BEING_ACQUIRED:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

            // Flicker
            if (MOD_AND(gCurrentSprite.work0, 2) == 0)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            // Check message banner disappeared
            if (gPreventMovementTimer < SAMUS_ITEM_PMT - 1)
                gCurrentSprite.status = 0;
    }
}

/**
 * @brief 13410 | 88 | Power grip glow AI
 * 
 */
void PowerGripGlow(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = 0;
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = 0;
            gCurrentSprite.hitboxRightOffset = 0;

            gCurrentSprite.pOam = sPowerGripGlowOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = 9;
            gCurrentSprite.drawOrder = 5;
            break;

        case 9:
            if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose >= POWER_GRIP_POSE_BEING_ACQUIRED)
                gCurrentSprite.status = 0;
    }
}
