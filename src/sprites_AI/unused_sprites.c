#include "sprites_AI/unused_sprites.h"
#include "data/sprites/unused_sprites.c"
#include "globals.h"

/**
 * @brief 13024 | 5c | Unused sprites AI
 * 
 */
void UnusedSprites(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose++;
        
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
        
        gCurrentSprite.hitboxTopOffset = -0x10;
        gCurrentSprite.hitboxBottomOffset = 0x10;
        gCurrentSprite.hitboxLeftOffset = -0x10;
        gCurrentSprite.hitboxRightOffset = 0x10;
        
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sUnusedSpritesOAM_Idle;
        
        gCurrentSprite.bgPriority = 0x1;
    }
}