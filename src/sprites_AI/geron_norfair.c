#include "sprites_AI/geron_norfair.h"
#include "data/sprites/geron_norfair.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/clipdata.h"
#include "structs/sprite.h"
#include "structs/clipdata.h"

/**
 * 40178 | b8 | Geron Norfair AI
 * 
 */
void GeronNorfair(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x30;

            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pOam = sGeronNorfairOAM_Idle;

            yPosition = gCurrentSprite.yPosition - 0x20;
            xPosition = gCurrentSprite.xPosition;

            caa = CAA_MAKE_NON_POWER_GRIP;
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition);
        }
    }
}