#include "sprites_AI/unknown_item_block.h"
#include "macros.h"

#include "data/sprites/unknown_item_block.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/sprite.h"

/**
 * @brief 4a930 | 70 | Updates the clipdata of the 4 blocks of the unknown item block
 * 
 * @param caa Clipdata affecting action
 */
void UnknownItemBlockChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

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
    u32 spriteId;
    u8 activated;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    activated = FALSE;
    spriteId = gCurrentSprite.spriteId;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.drawOrder = 1;

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = (BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxRight = (BLOCK_SIZE + PIXEL_SIZE);

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.pOam = sUnknownItemBlockOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.health = 1;
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE;

            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.xPosition += (HALF_BLOCK_SIZE);

            UnknownItemBlockChangeCcaa(CAA_MAKE_SOLID_GRIPPABLE);

        case UNKNOWN_ITEM_BLOCK_POSE_CHECK_ACTIVATE:
            // Check activate block
            if (spriteId == PSPRITE_PLASMA_BEAM_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLASMA_BEAM_OBTAINED))
                    activated++;
            }
            else if (spriteId == PSPRITE_GRAVITY_SUIT_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
                    activated++;
            }
            else if (spriteId == PSPRITE_SPACE_JUMP_BLOCK)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_JUMP_OBTAINED))
                    activated++;
            }

            if (activated)
            {
                // Set activated behavior
                gCurrentSprite.pOam = sUnknownItemBlockOam_Activated;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE;
            }
            break;

        case UNKNOWN_ITEM_BLOCK_POSE_WAIT_FOR_PROJECITLE:
            break; // No behavior (don't go to default)

        case UNKNOWN_ITEM_BLOCK_POSE_EXPLODING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.status = 0;
                return;
            }

            // Update draw distances
            if (gCurrentSprite.currentAnimationFrame == 0x1)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            }
            else if (gCurrentSprite.currentAnimationFrame == 8)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            }
            else if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 2)
            {
                // Spawn light
                activated = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

                if (activated < MAX_AMOUNT_OF_SPRITES)
                {
                    // Initialize light
                    gSpriteData[activated].status &= ~SPRITE_STATUS_NOT_DRAWN;
                    gSpriteData[activated].bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
                    gSpriteData[activated].drawOrder = 1;
                    
                    gSpriteData[activated].hitboxTop = 0;
                    gSpriteData[activated].hitboxBottom = 0;
                    gSpriteData[activated].hitboxLeft = 0;
                    gSpriteData[activated].hitboxRight = 0;

                    gSpriteData[activated].drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
                    gSpriteData[activated].drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
                    gSpriteData[activated].drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);

                    gSpriteData[activated].pOam = sUnknownItemBlockLightOam_Idle;
                    gSpriteData[activated].animationDurationCounter = 0;
                    gSpriteData[activated].currentAnimationFrame = 0;

                    gSpriteData[activated].samusCollision = SSC_NONE;
                    gSpriteData[activated].pose = 9;
                }
            }
            break;

        default:
            // Hit by something, set exploding behavior
            gCurrentSprite.pose = UNKNOWN_ITEM_BLOCK_POSE_EXPLODING;
            gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);

            gCurrentSprite.pOam = sUnknownItemBlockOam_Exploding;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);

            UnknownItemBlockChangeCcaa(CAA_REMOVE_SOLID); // Remove collision

            // Play sound, most likely planned to have a different sound for each block
            if (spriteId == PSPRITE_PLASMA_BEAM_BLOCK)
                SoundPlayNotAlreadyPlaying(SOUND_UNKNOWN_ITEM_BLOCK_BREAKING);
            else if (spriteId == PSPRITE_GRAVITY_SUIT_BLOCK)
                SoundPlayNotAlreadyPlaying(SOUND_UNKNOWN_ITEM_BLOCK_BREAKING);
            else if (spriteId == PSPRITE_SPACE_JUMP_BLOCK)
                SoundPlayNotAlreadyPlaying(SOUND_UNKNOWN_ITEM_BLOCK_BREAKING);
            break;
    }
}

/**
 * @brief 4abcc | 34 | Unknown item block light AI
 * 
 */
void UnknownItemBlockLight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.currentAnimationFrame != 0)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0;
}
