#include "PowerGrip.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"
#include "../event.h"

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
                gCurrentSprite.pOam = PowerGrip_oam_2b310c;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
                gCurrentSprite.health = 0x1;
                gCurrentSprite.yPosition -= 0x40;
                gCurrentSprite.pose = 0x9;
                SpriteSpawnSecondary(SSPRITE_POWER_GRIP_GLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case 0x9:
            if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
            {
                gPreventMovementTimer = 0x3E8;
                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                gCurrentSprite.pose = 0x23;
                gCurrentSprite.timer = 0x0;
                gEquipment.suitMisc |= SMF_POWER_GRIP;
                EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);
                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x15,0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case 0x23:
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            if ((gCurrentSprite.timer & 0x1) == 0x0)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gPreventMovementTimer < 0x3E7)
                gCurrentSprite.status = 0x0;
    }
}

void PowerGrip_glow(void)
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
            gCurrentSprite.pOam = PowerGrip_glow_oam;
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