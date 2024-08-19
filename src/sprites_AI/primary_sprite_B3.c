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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = 9;

        TransparencyUpdateBldcnt(1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);

        if (gAlarmTimer != 0)
        {
            gCurrentSprite.work2 = FALSE;
            gCurrentSprite.work3 = 16;
        }
        else
        {
            gCurrentSprite.work2 = TRUE;
            gCurrentSprite.work3 = 8;
        }
    }

    if (gAlarmTimer != 0)
    {
        if (gCurrentSprite.work2)
        {
            gCurrentSprite.work2--;
            if (!gCurrentSprite.work2 && gCurrentSprite.work3 < 16)
            {
                gCurrentSprite.work3++;
                gCurrentSprite.work2 = TRUE;
            }
        }
    }

    else
    {
        if (gCurrentSprite.work3 != 8)
        {
            gCurrentSprite.work3 = 8;
            gCurrentSprite.work2 = TRUE;
        }
    }

    TransparencySpriteUpdateBLDALPHA(0, gCurrentSprite.work3, 0, 16);
}
