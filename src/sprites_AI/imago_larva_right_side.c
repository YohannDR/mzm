#include "sprites_AI/imago_larva_right_side.h"
#include "data/sprites/imago_larva_right_side.h"
#include "constants/sprite.h"
#include "structs/sprite.h"

/**
 * @brief 412a8 | 11c | Imago larva (right side) AI
 * 
 */
void ImagoLarvaRightSide(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.hitboxTop = -0x4;
        gCurrentSprite.hitboxBottom = 0x4;
        gCurrentSprite.hitboxLeft = -0x4;
        gCurrentSprite.hitboxRight = 0x4;

        gCurrentSprite.drawDistanceTop = 0x30;
        gCurrentSprite.drawDistanceBottom = 0x8;
        gCurrentSprite.drawDistanceHorizontal = 0x30;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pOam = sImagoLarvaRightSideOAM;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x0:
                SoundPlay(0xB1);
                break;

            case 0xB:
            case 0xF:
            case 0x13:
            case 0x17:
            case 0x1B:
            case 0x1F:
                SoundPlay(0xB2);
        }
    }
}