#include "primary_sprite_B3.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * @brief 49dcc | ec | Primary Sprite B3 AI, the purpose of this sprite is unknown but it's related to the searchlights in Chozodia
 * 
 */
void PrimarySpriteB3(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x1;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x9;
        TransparencyUpdateBLDCNT(0x1, 0xC41); // TODO BLDCNT values
        if (gAlarmTimer == 0x0)
        {
            gCurrentSprite.workVariable2 = 0x1;
            gCurrentSprite.arrayOffset = 0x10;
        }
        else
        {
            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.arrayOffset = 0x8;
        }
    }

    if (gAlarmTimer == 0x0)
    {
        if (gCurrentSprite.arrayOffset != 0x8)
        {
            gCurrentSprite.arrayOffset = 0x8;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }
    else if (gCurrentSprite.workVariable2 != 0x0)
    {
        gCurrentSprite.workVariable2--;
        if (gCurrentSprite.workVariable2 == 0x0 && gCurrentSprite.arrayOffset < 0x10)
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }

    TransparencySpriteUpdateBLDALPHA(0x0, gCurrentSprite.arrayOffset, 0x0, 0x10);
}