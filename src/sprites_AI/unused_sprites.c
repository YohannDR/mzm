#include "sprites_AI/unused_sprites.h"
#include "macros.h"
#include "data/sprites/unused_sprites.h"
#include "constants/sprite.h"
#include "structs/sprite.h"

/**
 * @brief 13024 | 5c | Unused sprites AI
 * 
 */
void UnusedSprites(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.pose++;
        
        gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        
        gCurrentSprite.hitboxTopOffset = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = QUARTER_BLOCK_SIZE;
        
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sUnusedSpritesOAM_Idle;
        
        gCurrentSprite.bgPriority = 1;
    }
}
