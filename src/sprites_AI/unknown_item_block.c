#include "sprites_AI/unknown_item_block.h"
#include "data/sprites/unknown_item_block.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/sprite.h"

/**
 * @brief 4a930 | 70 | Updates the clipdata of the 4 blocks of the unknown item block
 * 
 * @param caa 
 */
void UnknownItemBlockChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
    xPosition = gCurrentSprite.xPosition - (HALF_BLOCK_SIZE);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition); // Top left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE); // Top right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition); // Bottom left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + BLOCK_SIZE); // Bottom right
}

/**
 * @brief 4a9a0 | 22c | Unknown item block AI
 * 
 */
void UnknownItemBlock(void)
{
    u32 spriteID;
    u8 activated;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    activated = FALSE;
    spriteID = gCurrentSprite.spriteID;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.drawOrder = 0x1;

            gCurrentSprite.hitboxTopOffset = -0x44;
            gCurrentSprite.hitboxBottomOffset = 0x44;
            gCurrentSprite.hitboxLeftOffset = -0x44;
            gCurrentSprite.hitboxRightOffset = 0x44;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.pOam = sUnknownItemBlockOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE;

            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.xPosition += (HALF_BLOCK_SIZE);
            UnknownItemBlockChangeCCAA(CAA_MAKE_SOLID_GRIPPABLE);

        case UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE:
            // Check activate block
            if (spriteID == PSPRITE_PLASMA_BEAM_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLASMA_BEAM_OBTAINED))
                    activated++;
            }
            else if (spriteID == PSPRITE_GRAVITY_SUIT_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
                    activated++;
            }
            else if (spriteID == PSPRITE_SPACE_JUMP_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_JUMP_OBTAINED))
                    activated++;
            }

            if (activated)
            {
                // Set activated behavior
                gCurrentSprite.pOam = sUnknownItemBlockOAM_Activated;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE;
            }
            break;

        case UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE:
            break; // No behavior (don't go to default)

        case UNKNOWN_ITEM_BLOCK_POSE_EXPLODING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
            else
            {
                // Update draw distances
                if (gCurrentSprite.currentAnimationFrame == 0x1)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x30;
                    gCurrentSprite.drawDistanceBottomOffset = 0x30;
                }
                else if (gCurrentSprite.currentAnimationFrame == 0x8)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x60;
                    gCurrentSprite.drawDistanceBottomOffset = 0x0;
                }
                else if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x2)
                {
                    // Spawn light
                    activated = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT, 0x0, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

                    if (activated < 0x18)
                    {
                        // Initialize light
                        gSpriteData[activated].status &= ~SPRITE_STATUS_NOT_DRAWN;
                        gSpriteData[activated].bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
                        gSpriteData[activated].drawOrder = 0x1;
                        
                        gSpriteData[activated].hitboxTopOffset = 0x0;
                        gSpriteData[activated].hitboxBottomOffset = 0x0;
                        gSpriteData[activated].hitboxLeftOffset = 0x0;
                        gSpriteData[activated].hitboxRightOffset = 0x0;

                        gSpriteData[activated].drawDistanceTopOffset = 0x0;
                        gSpriteData[activated].drawDistanceBottomOffset = 0x50;
                        gSpriteData[activated].drawDistanceHorizontalOffset = 0x60;

                        gSpriteData[activated].pOam = sUnknownItemBlockLightOAM_Idle;
                        gSpriteData[activated].animationDurationCounter = 0x0;
                        gSpriteData[activated].currentAnimationFrame = 0x0;

                        gSpriteData[activated].samusCollision = SSC_NONE;
                        gSpriteData[activated].pose = 0x9;
                    }
                }
            }
            break;

        default:
            // Hit by something, set exploding behavior
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_EXPLODING;
            gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;

            gCurrentSprite.pOam = sUnknownItemBlockOAM_Exploding;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            UnknownItemBlockChangeCCAA(CAA_REMOVE_SOLID); // Remove collision

            // Play sound, most likely planned to have a different sound for each block
            if (spriteID == PSPRITE_PLASMA_BEAM_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            else if (spriteID == PSPRITE_GRAVITY_SUIT_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            else if (spriteID == PSPRITE_SPACE_JUMP_BLOCK)
                SoundPlayNotAlreadyPlaying(0x13B);
            break;
    }
}

/**
 * @brief 4abcc | 34 | Unknown item block light AI
 * 
 */
void UnknownItemBlockLight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.currentAnimationFrame != 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x0;
        gCurrentSprite.drawDistanceBottomOffset = 0x60;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}