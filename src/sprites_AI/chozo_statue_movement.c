#include "chozo_statue_movement.h"

#include "../../data/data.h"
#include "../globals.h"

/**
 * @brief 125e8 | 160 | Spawns a new chozo statue movement secondary sprite
 * 
 * @param stage Movement stage
 */
void SpawnChozoStatueMovement(u8 stage)
{
    u8 ramSlot;
    u16 status;

    for (ramSlot = 0x0; ramSlot < 0x18; ramSlot++)
    {
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS))
        {
            if (stage & 0x1)
            {
                gSpriteData[ramSlot].status = ((gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_IGNORE_PROJECTILES));
            }
            else
            {
                gSpriteData[ramSlot].status = ((gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES));
            }

            if (gCurrentSprite.drawOrder < 0x8)
                gSpriteData[ramSlot].drawOrder = gCurrentSprite.drawOrder + 0x9;
            else
                gSpriteData[ramSlot].drawOrder = gCurrentSprite.drawOrder + 0x1;

            // Initialize sprite
            gSpriteData[ramSlot].properties = (SP_ALWAYS_ACTIVE | SP_SECONDARY_SPRITE);
            gSpriteData[ramSlot].spritesetGFXSlot = gCurrentSprite.spritesetGFXSlot;
            gSpriteData[ramSlot].spriteID = SSPRITE_CHOZO_STATUE_MOVEMENT;
            gSpriteData[ramSlot].yPosition = gCurrentSprite.yPosition;
            gSpriteData[ramSlot].xPosition = gCurrentSprite.xPosition;
            gSpriteData[ramSlot].roomSlot = 0x0;
            gSpriteData[ramSlot].bgPriority = gCurrentSprite.bgPriority;
            gSpriteData[ramSlot].pose = 0x0;
            gSpriteData[ramSlot].health = 0x0;
            gSpriteData[ramSlot].invicibilityStunFlashTimer = 0x0;
            gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
            gSpriteData[ramSlot].frozenPaletteRowOffset = gCurrentSprite.frozenPaletteRowOffset;
            gSpriteData[ramSlot].absolutePaletteRow = gCurrentSprite.absolutePaletteRow;
            gSpriteData[ramSlot].ignoreSamusCollisionTimer = 0x1;
            gSpriteData[ramSlot].primarySpriteRAMSlot = ramSlot;
            gSpriteData[ramSlot].freezeTimer = 0x0;
            gSpriteData[ramSlot].timer = 0x20;
            gSpriteData[ramSlot].samusCollision = SSC_NONE;
            gSpriteData[ramSlot].pOam = gCurrentSprite.pOam;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = gCurrentSprite.currentAnimationFrame;
            gSpriteData[ramSlot].drawDistanceTopOffset = gCurrentSprite.drawDistanceTopOffset;
            gSpriteData[ramSlot].drawDistanceBottomOffset = gCurrentSprite.drawDistanceBottomOffset;
            gSpriteData[ramSlot].drawDistanceHorizontalOffset = gCurrentSprite.drawDistanceHorizontalOffset;
            break;
        }
    }
}

/**
 * @brief 12748 | 38 | Chozo statue movement AI
 * 
 */
void ChozoStatueMovement(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.animationDurationCounter--;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.status = 0x0;
}