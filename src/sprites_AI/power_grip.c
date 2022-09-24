#include "sprites_AI/power_grip.h"
#include "sprites_AI/item_banner.h"
#include "data/sprites/power_grip.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"
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
        case 0x0:
            if (gEquipment.suitMisc & SMF_POWER_GRIP)
                gCurrentSprite.status = 0x0;
            else
            {
                gCurrentSprite.drawDistanceTopOffset = 0x8;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

                gCurrentSprite.hitboxTopOffset = -0x1C;
                gCurrentSprite.hitboxBottomOffset = 0x1C;
                gCurrentSprite.hitboxLeftOffset = -0x1C;
                gCurrentSprite.hitboxRightOffset = 0x1C;

                gCurrentSprite.pOam = sPowerGripOAM_Idle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
                gCurrentSprite.health = 0x1;
                gCurrentSprite.yPosition -= 0x40;
                gCurrentSprite.pose = POWER_GRIP_POSE_IDLE;
                SpriteSpawnSecondary(SSPRITE_POWER_GRIP_GLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case POWER_GRIP_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                gPreventMovementTimer = 0x3E8;
                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                gCurrentSprite.pose = POWER_GRIP_POSE_BEING_ACQUIRED;
                gCurrentSprite.timer = 0x0;
                gEquipment.suitMisc |= SMF_POWER_GRIP;
                EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);
                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_POWER_GRIP, 0x6,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case POWER_GRIP_POSE_BEING_ACQUIRED:
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            if (!(gCurrentSprite.timer & 0x1))
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gPreventMovementTimer < 0x3E7)
                gCurrentSprite.status = 0x0;
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
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sPowerGripGlowOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.drawOrder = 0x5;
            break;

        case 0x9:
            if (0x22 < gSpriteData[gCurrentSprite.primarySpriteRAMSlot].pose)
                gCurrentSprite.status = 0x0;
    }
}