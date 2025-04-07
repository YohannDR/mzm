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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.pose++;
        
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        
        gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;
        
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sUnusedSpritesOAM_Idle;
        
        gCurrentSprite.bgPriority = 1;
    }
}
