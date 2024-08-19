#include "sprites_AI/geron_norfair.h"
#include "macros.h"

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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE * 3);
        gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE * 3);

        gCurrentSprite.drawOrder = 5;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.health = 1;
        gCurrentSprite.pOam = sGeronNorfairOAM_Idle;

        yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
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
