#include "sprites_AI/primary_sprite_B3.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/enemy_drop.h"

#include "constants/sprite.h"

#include "structs/sprite.h"

/**
 * @brief 49dcc | ec | Primary Sprite B3 AI, the purpose of this sprite is unknown but it's related to the searchlights in Chozodia
 * 
 */
void PrimarySpriteB3(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

        gCurrentSprite.hitboxTopOffset = 0;
        gCurrentSprite.hitboxBottomOffset = 0;
        gCurrentSprite.hitboxLeftOffset = 0;
        gCurrentSprite.hitboxRightOffset = 0;

        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = 9;

        TransparencyUpdateBLDCNT(1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);

        if (gAlarmTimer != 0)
        {
            gCurrentSprite.workVariable2 = FALSE;
            gCurrentSprite.arrayOffset = 16;
        }
        else
        {
            gCurrentSprite.workVariable2 = TRUE;
            gCurrentSprite.arrayOffset = 8;
        }
    }

    if (gAlarmTimer != 0)
    {
        if (gCurrentSprite.workVariable2)
        {
            gCurrentSprite.workVariable2--;
            if (!gCurrentSprite.workVariable2 && gCurrentSprite.arrayOffset < 16)
            {
                gCurrentSprite.arrayOffset++;
                gCurrentSprite.workVariable2 = TRUE;
            }
        }
    }

    else
    {
        if (gCurrentSprite.arrayOffset != 8)
        {
            gCurrentSprite.arrayOffset = 8;
            gCurrentSprite.workVariable2 = TRUE;
        }
    }

    TransparencySpriteUpdateBLDALPHA(0, gCurrentSprite.arrayOffset, 0, 16);
}
