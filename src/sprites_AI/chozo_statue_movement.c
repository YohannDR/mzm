#include "sprites_AI/chozo_statue_movement.h"
#include "macros.h"

#include "structs/sprite.h"
#include "constants/sprite.h"

/**
 * @brief 125e8 | 160 | Spawns a new chozo statue movement secondary sprite
 * 
 * @param stage Movement stage
 */
void SpawnChozoStatueMovement(u8 stage)
{
    u8 i;
    u16 status;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS)
            continue;

        if (MOD_AND(stage, 2))
        {
            gSpriteData[i].status = ((gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_IGNORE_PROJECTILES));
        }
        else
        {
            gSpriteData[i].status = ((gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES));
        }

        if (gCurrentSprite.drawOrder < 8)
            gSpriteData[i].drawOrder = gCurrentSprite.drawOrder + 9;
        else
            gSpriteData[i].drawOrder = gCurrentSprite.drawOrder + 1;

        gSpriteData[i].properties = SP_ALWAYS_ACTIVE | SP_SECONDARY_SPRITE;
        gSpriteData[i].spritesetGfxSlot = gCurrentSprite.spritesetGfxSlot;
        gSpriteData[i].spriteID = SSPRITE_CHOZO_STATUE_MOVEMENT;

        gSpriteData[i].yPosition = gCurrentSprite.yPosition;
        gSpriteData[i].xPosition = gCurrentSprite.xPosition;

        gSpriteData[i].roomSlot = 0;
        gSpriteData[i].bgPriority = gCurrentSprite.bgPriority;

        gSpriteData[i].pose = SPRITE_POSE_UNINITIALIZED;
        gSpriteData[i].health = 0;
        gSpriteData[i].invincibilityStunFlashTimer = 0;

        gSpriteData[i].paletteRow = gCurrentSprite.paletteRow;
        gSpriteData[i].frozenPaletteRowOffset = gCurrentSprite.frozenPaletteRowOffset;
        gSpriteData[i].absolutePaletteRow = gCurrentSprite.absolutePaletteRow;

        gSpriteData[i].ignoreSamusCollisionTimer = 1;
        gSpriteData[i].primarySpriteRamSlot = i;
        gSpriteData[i].freezeTimer = 0;
        gSpriteData[i].timer = 32;

        gSpriteData[i].samusCollision = SSC_NONE;
        gSpriteData[i].pOam = gCurrentSprite.pOam;
        gSpriteData[i].animationDurationCounter = 0;

        gSpriteData[i].currentAnimationFrame = gCurrentSprite.currentAnimationFrame;
        gSpriteData[i].drawDistanceTopOffset = gCurrentSprite.drawDistanceTopOffset;
        gSpriteData[i].drawDistanceBottomOffset = gCurrentSprite.drawDistanceBottomOffset;
        gSpriteData[i].drawDistanceHorizontalOffset = gCurrentSprite.drawDistanceHorizontalOffset;
        break;
    }
}

/**
 * @brief 12748 | 38 | Chozo statue movement AI
 * 
 */
void ChozoStatueMovement(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.animationDurationCounter--;
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0)
        gCurrentSprite.status = 0;
}
