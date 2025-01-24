#include "sprites_AI/power_grip.h"
#include "macros.h"

#include "data/sprites/power_grip.h"

#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define POWER_GRIP_POSE_IDLE 0x9
#define POWER_GRIP_POSE_BEING_ACQUIRED 0x23

#define POWER_GRIP_GLOW_POSE_IDLE 0x9

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

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxBottom = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
            gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);

            gCurrentSprite.pOam = sPowerGripOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
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
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
                gCurrentSprite.pose = POWER_GRIP_POSE_BEING_ACQUIRED;
                gCurrentSprite.work0 = 0;
                gEquipment.suitMisc |= SMF_POWER_GRIP;
                EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);

                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_POWER_GRIP, 6,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
            break;

        case POWER_GRIP_POSE_BEING_ACQUIRED:
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

            // Flicker
            if (MOD_AND(gCurrentSprite.work0, 2) == 0)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            // Check message banner disappeared
            if (gPreventMovementTimer < SAMUS_ITEM_PMT - 1 * DELTA_TIME)
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

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sPowerGripGlowOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = POWER_GRIP_GLOW_POSE_IDLE;
            gCurrentSprite.drawOrder = 5;
            break;

        case POWER_GRIP_GLOW_POSE_IDLE:
            if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose >= POWER_GRIP_POSE_BEING_ACQUIRED)
                gCurrentSprite.status = 0;
    }
}
