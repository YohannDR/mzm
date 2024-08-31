#include "gba.h"
#include "oam.h"
#include "sprite_util.h"
#include "clipdata.h"
#include "sprites_AI/parasite.h"
#include "sprites_AI/ridley.h"
#include "sprites_AI/acid_worm.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"
#include "constants/projectile.h"

#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/screen_shake.h"
#include "structs/sprite.h"


/**
 * @brief e498 | 7c | Initialize the first sprite to be a location text if necessary
 * 
 */
void SpriteUtilInitLocationText(void)
{
    u8 gfxSlot;

    gfxSlot = LocationTextGetGfxSlot();
    if (gfxSlot < 8)
    {
        gSpriteData[0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN |
            SPRITE_STATUS_UNKNOWN_10 | SPRITE_STATUS_IGNORE_PROJECTILES;

        gSpriteData[0].properties = SP_ABSOLUTE_POSITION;
        gSpriteData[0].spritesetGfxSlot = gfxSlot;
        gSpriteData[0].spriteId = PSPRITE_AREA_BANNER;
        gSpriteData[0].yPosition = gSamusData.yPosition;
        gSpriteData[0].xPosition = gSamusData.xPosition;
        gSpriteData[0].bgPriority = 0;
        gSpriteData[0].drawOrder = 1;
        gSpriteData[0].pose = SPRITE_POSE_UNINITIALIZED;
        gSpriteData[0].health = 0;
        gSpriteData[0].invincibilityStunFlashTimer = 0;
        gSpriteData[0].paletteRow = 0;
        gSpriteData[0].frozenPaletteRowOffset = 0;
        gSpriteData[0].absolutePaletteRow = 0;
        gSpriteData[0].ignoreSamusCollisionTimer = DELTA_TIME;
        gSpriteData[0].primarySpriteRamSlot = 0;
        gSpriteData[0].freezeTimer = 0;
        gSpriteData[0].standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
    }
}

/**
 * @brief e514 | 90 | Checks if samus should stop when colliding with a solid sprite from the left
 * 
 * @param samusY Samus Y Position
 * @param spriteX Sprite X Position
 */
void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 samusY, u16 spriteX)
{
    u16 xPosition;

    xPosition = spriteX - gSamusPhysics.drawDistanceRightOffset;

    SpriteUtilCheckCollisionAtPosition(samusY, xPosition + gSamusPhysics.drawDistanceLeftOffset);
    if (gPreviousCollisionCheck != COLLISION_AIR)
        return;

    SpriteUtilCheckCollisionAtPosition(samusY - BLOCK_SIZE, xPosition + gSamusPhysics.drawDistanceLeftOffset);
    if (gPreviousCollisionCheck == COLLISION_AIR || SpriteUtilCheckMorphed())
    {
        gSamusData.xPosition = xPosition;
        if (gSamusData.direction & KEY_RIGHT && gEquipment.currentEnergy != 0)
            gSamusData.xVelocity = 0;
    }
}

/**
 * @brief e5a4 | 90 | Checks if samus should stop when colliding with a solid sprite from the right
 * 
 * @param samusY Samus Y Position
 * @param spriteX Sprite X Position
 */
void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 samusY, u16 spriteX)
{
    u16 xPosition;

    xPosition = spriteX - gSamusPhysics.drawDistanceLeftOffset;

    SpriteUtilCheckCollisionAtPosition(samusY, xPosition + gSamusPhysics.drawDistanceRightOffset);
    if (gPreviousCollisionCheck != COLLISION_AIR)
        return;

    SpriteUtilCheckCollisionAtPosition(samusY - BLOCK_SIZE, xPosition + gSamusPhysics.drawDistanceRightOffset);
    if (gPreviousCollisionCheck == COLLISION_AIR || SpriteUtilCheckMorphed())
    {
        gSamusData.xPosition = xPosition + ONE_SUB_PIXEL;
        if (gSamusData.direction & KEY_LEFT && gEquipment.currentEnergy != 0)
            gSamusData.xVelocity = 0;
    }
}

/**
 * e634 | c4 | Calculates and applies the damage samus takes from a sprite
 * 
 * @param kbFlag 1 if getting knocked back, 0 otherwise
 * @param pSprite Sprite Data Pointer to the sprite hurting samus
 * @param dmgMultiplier Damage Multiplier
 * @return bool, samus alive
 */
u8 SpriteUtilTakeDamageFromSprite(u8 kbFlag, struct SpriteData* pSprite, u16 dmgMultiplier)
{
    u16 damage;
    u16 flags;

    // Get damage
    if (pSprite->properties & SP_SECONDARY_SPRITE)
        damage = GET_SSPRITE_DAMAGE(pSprite->spriteId);
    else
        damage = GET_PSPRITE_DAMAGE(pSprite->spriteId);

    // Apply multiplier
    damage *= dmgMultiplier;

    // Apply changes based on the current suit
    flags = gEquipment.suitMiscActivation;
    if ((flags & SMF_ALL_SUITS) == SMF_ALL_SUITS)
    {
        // Multiply damage by 0.5
        damage /= 2;
    }
    else if (flags & SMF_GRAVITY_SUIT)
    {
        // Multiply damage by 0.7
        damage = FLOAT_MUL(damage, .7f);
    }
    else if (flags & SMF_VARIA_SUIT)
    {
        // Multiply damage by 0.8
        damage = FLOAT_MUL(damage, .8f);
    }

    // Apply changes based on difficuly
    if (gDifficulty == DIFF_EASY)
        damage /= 2;
    else if (gDifficulty == DIFF_HARD)
        damage *= 2;

    // Force damage
    if (damage == 0)
        damage = 1;

    // Apply damage
    if (gEquipment.currentEnergy > damage)
    {
        gEquipment.currentEnergy -= damage;

        if (kbFlag)
            SamusSetPose(SPOSE_HURT_REQUEST);

        return TRUE;
    }
    else
    {
        gEquipment.currentEnergy = 0;
        SamusSetPose(SPOSE_HURT_REQUEST);
        return FALSE;
    }
}

/**
 * @brief e6f8 | 50 | Checks if two objects are touching
 * 
 * @param o1Top Object 1 Top
 * @param o1Bottom Object 1 Bottom
 * @param o1Left Object 1 Left
 * @param o1Right Object 1 Right
 * @param o2Top Object 2 Top
 * @param o2Bottom Object 2 Bottom
 * @param o2Left Object 2 Left
 * @param o2Right Object 2 Right
 * @return u32 bool, touching
 */
u32 SpriteUtilCheckObjectsTouching(u16 o1Top, u16 o1Bottom, u16 o1Left, u16 o1Right, u16 o2Top, u16 o2Bottom, u16 o2Left, u16 o2Right)
{
    if (o2Bottom >= o1Top && o2Top < o1Bottom && o2Right >= o1Left && o2Left < o1Right)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief e748 | c18 | Checks if the sprites are colliding with samus, applies said collision
 * 
 */
void SpriteUtilSamusAndSpriteCollision(void)
{
    struct SamusData* pData;
    struct SpriteData* pSprite;

    u16 dmgMultiplier;
    u16 samusY;
    u16 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;
    u16 previousX;

    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 status;
    u16 statusCheckFlags;

    u16 collisionCenterY;
    u16 collisionCenterX;
    u8 collisionFlags;

    pData = &gSamusData;
    dmgMultiplier = 0;

    samusY = pData->yPosition;
    samusX = pData->xPosition;
    previousX = gPreviousXPosition;

    samusTop = samusY + gSamusPhysics.drawDistanceTop;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottom;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    if (pData->pose == SPOSE_BALLSPARKING)
    {
        switch (pData->forcedMovement)
        {
            case FORCED_MOVEMENT_SIDEWARDS_SHINESPARK:
                // Extend hitbox vertically to make it look like the ballspark effect has a collision
                samusTop -= HALF_BLOCK_SIZE;
                samusBottom += HALF_BLOCK_SIZE;
                break;
            
            case FORCED_MOVEMENT_UPWARDS_SHINESPARK:
                // Extend hitbox horizontally to make it look like the ballspark effect has a collision
                samusLeft -= HALF_BLOCK_SIZE;
                samusRight += HALF_BLOCK_SIZE;
                break;

            default:
                // Diagonal ballsaprk
                samusLeft -= QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
                samusRight += QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
                samusTop -= QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
                samusBottom += QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        }
    }
    else if (pData->pose == SPOSE_SHINESPARKING)
    {
        switch (pData->forcedMovement)
        {
            case FORCED_MOVEMENT_UPWARDS_SHINESPARK:
                // Extend hitbox horizontally to make it look like the shinespark effect has a collision
                samusLeft -= HALF_BLOCK_SIZE;
                samusRight += HALF_BLOCK_SIZE;
        }
    }

    // Only check collision with sprites that exist, and are on screen
    statusCheckFlags = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        status = pSprite->status;
        if ((status & statusCheckFlags) != statusCheckFlags)
            continue;

        if (pSprite->ignoreSamusCollisionTimer != 0)
            continue;

        spriteY = pSprite->yPosition;
        spriteX = pSprite->xPosition;

        spriteTop = pSprite->yPosition + pSprite->hitboxTop;
        spriteBottom = pSprite->yPosition + pSprite->hitboxBottom;
        spriteLeft = pSprite->xPosition + pSprite->hitboxLeft;
        spriteRight = pSprite->xPosition + pSprite->hitboxRight;

        if (!SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, spriteTop, spriteBottom, spriteLeft, spriteRight))
            continue;

        gIgnoreSamusAndSpriteCollision = FALSE;

        // Get the center of the sprite hitbox
        collisionCenterY = spriteTop + (spriteBottom - spriteTop) / 2;
        collisionCenterX = spriteLeft + (spriteRight - spriteLeft) / 2;

        // Check where Samus is in regards to the hitbox
        collisionFlags = SPRITE_COLLISION_FLAG_NONE;

        // Check that the center Y is below Samus
        if (collisionCenterY - PIXEL_SIZE > samusBottom)
        {
            // Only register as being on top if Samus is falling
            if (pData->yVelocity <= SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE - ONE_SUB_PIXEL))
                collisionFlags = SPRITE_COLLISION_FLAG_ON_TOP;
        }

        // Check that the center Y is above Samus
        if (collisionCenterY + PIXEL_SIZE < samusTop)
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_BOTTOM;

        // Check on which side of Samus the center X is
        if (collisionCenterX >= previousX)
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_LEFT;
        else
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_RIGHT;

        if (pSprite->freezeTimer != 0)
        {
            // Sprite is freezed, handle as solid

            // If pulling self up, collision is ignored
            // Contact damage is checked
            if (!SpriteUtilCheckPullingSelfUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
            {
                if (SpriteUtilCheckOnZipline())
                {
                    // Simply make Samus fall from the zipline
                    SamusSetPose(SPOSE_MID_AIR_REQUEST);
                }
                else
                {
                    if (samusY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) < spriteTop)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                        {
                            // Make Samus stand on the sprite
                            pData->yPosition = spriteTop + ONE_SUB_PIXEL;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_ON;
                        }
                    }
                    else if (samusTop + QUARTER_BLOCK_SIZE > spriteBottom)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTop, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            // Put Samus right below the sprite
                            pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTop;

                            // If Samus was moving upwards, zero out velocity
                            if (pData->yVelocity > 0 && gEquipment.currentEnergy != 0)
                                pData->yVelocity = 0;
                        }
                    }
                    else if (samusX < spriteLeft || samusX > spriteRight)
                    {
                        // Try stop samus at the sides
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                        else
                            SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);
                    }
                }
            }
        }
        else
        {
            switch (pSprite->samusCollision)
            {
                case SSC_NONE:
                    break;
                
                case SSC_SOLID_CHECK_COLLIDING:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gIgnoreSamusAndSpriteCollision = TRUE;

                case SSC_SOLID:
                    if (!SpriteUtilCheckPullingSelfUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (samusY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) < spriteTop)
                        {
                            SpriteUtilCheckCollisionAtPosition(spriteTop + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                            {
                                // Make Samus stand on the sprite
                                pData->yPosition = spriteTop + ONE_SUB_PIXEL;
                                pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_ON;
                            }
                        }
                        else if (samusTop + QUARTER_BLOCK_SIZE > spriteBottom)
                        {
                            SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTop, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                // Put Samus right below the sprite
                                pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTop;
                                
                                // If Samus was moving upwards, zero out velocity
                                if (pData->yVelocity > 0 && gEquipment.currentEnergy != 0)
                                    pData->yVelocity = 0;
                            }
                        }
                        else if (samusX < spriteLeft || samusX > spriteRight)
                        {
                            // Try stop samus at the sides
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                            else
                                SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);
                        }
                    }
                    break;

                case SSC_CAN_STAND_ON_TOP:
                    // Only check to try and make samus stand on the sprite, no collision otherwise
                    if (!SpriteUtilCheckPullingSelfUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE &&
                        samusY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) < spriteTop)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                        {
                            // Make Samus stand on the sprite
                            pData->yPosition = spriteTop + ONE_SUB_PIXEL;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_ON;
                        }
                    }
                    break;

                case SSC_HURTS_SAMUS_CAN_STAND_ON_TOP:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (samusY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) < spriteTop)
                        {
                            if (!SpriteUtilCheckPullingSelfUp() && pData->invincibilityTimer < TWO_THIRD_SECOND)
                            {
                                SpriteUtilCheckCollisionAtPosition(spriteTop + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                                if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                                {
                                    // Make Samus stand on the sprite
                                    pData->yPosition = spriteTop + ONE_SUB_PIXEL;
                                    pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                    pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_ON;
                                }
                            }
                        }
                        else
                        {
                            if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                            {
                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                                else
                                    pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            }

                            pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                            gIgnoreSamusAndSpriteCollision = TRUE;
                        }
                    }
                    break;

                case SSC_HURTS_RIGHT_CAN_STAND_ON_TOP:
                    // Hurts, but only from the right, otherwise check stand on top
                    if (samusX > spriteRight)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                        }

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    else if (samusY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) < spriteTop && !SpriteUtilCheckPullingSelfUp() && pData->invincibilityTimer < 38)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                        {
                            // Make Samus stand on the sprite
                            pData->yPosition = spriteTop + ONE_SUB_PIXEL;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_ON;
                        }
                    }
                    break;

                case SSC_CHECK_COLLIDING:
                case SSC_SMALL_ENERGY_DROP:
                case SSC_LARGE_ENERGY_DROP:
                case SSC_MISSILE_DROP:
                case SSC_SUPER_MISSILE_DROP:
                case SSC_POWER_BOMB_DROP:
                case SSC_MULTIPLE_LARGE_ENERGY_DROP:
                    // Just set the colliding flag
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_ACID_WORM_MOUTH:
                    if (pSprite->pose == ACID_WORM_POSE_EXTENDED || pSprite->pose == ACID_WORM_POSE_EXTENDING)
                    {
                        if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                        {
                            if ((u8)(pSprite->rotation - 0x21) <= 0x1E)
                            {
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                                    pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + PIXEL_SIZE);

                                pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;
                            }
                        }
                        else
                        {
                            if ((u8)(pSprite->rotation + 0x3F) <= 0x1E)
                            {
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                                    pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + PIXEL_SIZE);

                                pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;
                            }
                        }
                    }

                case SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY_NO_CONTACT_DAMAGE:
                    // Always hurt, no matter the status of samus
                    if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                    {
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                        else
                            pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                    }

                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT:
                case SSC_SPACE_PIRATE_LASER:
                    // Set the stopped pose, then run the normal hurt code
                    pSprite->pose = SPRITE_POSE_STOPPED;

                case SSC_HURTS_SAMUS:
                case SSC_MELLOW:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                        }

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY:
                    // Hurts samus, ignore Samus' invincibility timer
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                        }

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_BIG_KNOCKBACK:
                    // Set the stopped pose, then run the normal hurt + big knockback code
                    pSprite->pose = SPRITE_POSE_STOPPED;

                case SSC_HURTS_BIG_KNOCKBACK:
                    // Same as hurt code, just bigger knockback
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE);
                        }

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_A_LOT:
                    // Same as hurt code, just has slightly bigger knockback and a 5x damage multiplier
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 5))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + ONE_SUB_PIXEL);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + ONE_SUB_PIXEL);
                        }
                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_SPACE_PIRATE:
                    // Same as hurt code
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            else
                                pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                        }

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_NO_KNOCKBACK:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    if (pData->invincibilityTimer < CONVERT_SECONDS(2.f / 15))
                    {
                        SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1);
                        if (gEquipment.currentEnergy != 0)
                            pData->invincibilityTimer = CONVERT_SECONDS(2.f / 15);
                    }

                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK:
                    pSprite->pose = SPRITE_POSE_STOPPED;

                case SSC_HURTS_SAMUS_NO_KNOCKBACK_NO_CONTACT_DAMAGE:
                    SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1);
                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);

                    if (pData->invincibilityTimer == 0)
                        pData->invincibilityTimer = CONVERT_SECONDS(2.f / 15);

                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_ZIPLINE:
                    if (collisionFlags & SPRITE_COLLISION_FLAG_ON_BOTTOM)
                    {
                        switch (pData->pose)
                        {
                            case SPOSE_SPINNING:
                            case SPOSE_MIDAIR:
                                pData->yPosition = pSprite->yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                                pData->xPosition = pSprite->xPosition;

                                gPreviousYPosition = pData->yPosition;
                                gPreviousXPosition = pData->xPosition;

                                SamusSetPose(SPOSE_ON_ZIPLINE);
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                break;

                            case SPOSE_BALLSPARKING:
                                SoundStop(SOUND_BALLSPARKING);

                            case SPOSE_MORPH_BALL_MIDAIR:
                                pData->yPosition = pSprite->yPosition + (BLOCK_SIZE - PIXEL_SIZE);
                                pData->xPosition = pSprite->xPosition;

                                gPreviousYPosition = pData->yPosition;
                                gPreviousXPosition = pData->xPosition;

                                SamusSetPose(SPOSE_MORPH_BALL_ON_ZIPLINE);
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                break;
                        }
                    }

                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_SOLID_SIDEWAYS:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        // Try stop samus at the sides
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                        else
                            SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);
                    }
                    break;

                case SSC_HURTS_SAMUS_SOLID:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        // Try stop samus at the sides
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                        else
                            SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);

                        // Also try to hurt
                        if (pData->invincibilityTimer == 0)
                        {
                            if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1) && gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                                else
                                    pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            }

                            gIgnoreSamusAndSpriteCollision = TRUE;
                        }
                    }
                    break;

                case SSC_HURTS_KNOCKBACK_IF_INVINCIBLE:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                        else
                            SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);

                        if (pData->invincibilityTimer == 0)
                        {
                            if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1) && gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                                else
                                    pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            }
                        }
                        else if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            SpriteUtilCheckCollisionAtPosition(samusY + ONE_SUB_PIXEL + gSamusPhysics.drawDistanceTop, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                SamusSetPose(SPOSE_KNOCKBACK_REQUEST);

                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                                else
                                    pData->xVelocity = SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE);
                            }
                        }

                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_KNOCKS_BACK_SAMUS:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        // Simply ask for a knockback
                        SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                        // Override standard knockback X velocity
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE);
                        else
                            pData->xVelocity = SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE);

                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_PARASITE:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;

                    if (pData->invincibilityTimer == 0 && !(gEquipment.suitMiscActivation & SMF_ALL_SUITS))
                    {
                        // Check if enought parasites are on Samus
                        if (!ParasiteCount())
                            break;

                        if (SpriteUtilTakeDamageFromSprite(FALSE, pSprite, dmgMultiplier / 4))
                        {
                            pData->invincibilityTimer = CONVERT_SECONDS(4.f / 15);

                            SoundPlayNotAlreadyPlaying(SOUND_BUG_LEECHING);
                            APPLY_DELTA_TIME_INC(gSubSpriteData1.workVariable2);

                            if (MOD_AND(gSubSpriteData1.workVariable2, CONVERT_SECONDS(1.f / 15)) == 0)
                                SoundPlay(SOUND_HURT);
                        }
                    }

                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    break;

                case SSC_METROID:
                    if (samusY > spriteY + HALF_BLOCK_SIZE)
                        pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;

                    if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1))
                    {
                        // Scale invincibilty timer depending on the amount of suits Samus has
                        dmgMultiplier = gEquipment.suitMiscActivation & SMF_ALL_SUITS;
                        if (dmgMultiplier == SMF_NONE)
                            pData->invincibilityTimer = DELTA_TIME;
                        else if (dmgMultiplier == SMF_ALL_SUITS)
                            pData->invincibilityTimer = CONVERT_SECONDS(2.f / 15);
                        else
                            pData->invincibilityTimer = CONVERT_SECONDS(1.f / 15);
                    }
                    break;

                case SSC_RIDLEY_CLAW:
                    if (collisionFlags & SPRITE_COLLISION_FLAG_ON_BOTTOM && RidleyCheckGrabbing(spriteY, spriteX))
                    {
                        pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                        pSprite->samusCollision = SSC_NONE;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                        SamusSetPose(SPOSE_MIDAIR);
                        SoundPlay(SOUND_RIDLEY_GRABBING_SAMUS);
                    }
                    else
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                            SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1);

                        pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_MECHA_RIDLEY:
                    // Double damage if 100% game completion
                    if (SpriteUtilGetFinalCompletionPercentage() == 100)
                        dmgMultiplier = 2;
                    else
                        dmgMultiplier = 1;

                    if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, dmgMultiplier))
                        pData->xVelocity = -SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE);

                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                default:
                    pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    
            }
        }

        if (gIgnoreSamusAndSpriteCollision)
            break;
    }

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->ignoreSamusCollisionTimer != 0)
            APPLY_DELTA_TIME_DEC(pSprite->ignoreSamusCollisionTimer);
    }
}

/**
 * @brief f360 | 11c | Checks the collision at the given parameters and updates the gPreviousVerticalCollisionCheck global variable
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u32 Block Top Edge Y Position
 */
u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 yPosition, u16 xPosition)
{
    u32 clipdata;
    u16 blockY;

    clipdata = ClipdataProcess(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        gPreviousVerticalCollisionCheck = COLLISION_SOLID;
    else
        gPreviousVerticalCollisionCheck = COLLISION_AIR;

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - SUB_PIXEL_POSITION_FLAG));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) - SUB_PIXEL_POSITION_FLAG));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) - SUB_PIXEL_POSITION_FLAG / 2));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            gPreviousVerticalCollisionCheck = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) + SUB_PIXEL_POSITION_FLAG / 2); 
            gPreviousVerticalCollisionCheck = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2); 
            gPreviousVerticalCollisionCheck = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;


        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            gPreviousVerticalCollisionCheck = COLLISION_PASS_THROUGH_BOTTOM;
            
        default:
            blockY = yPosition & BLOCK_POSITION_FLAG;
    }

    return blockY;
}

/**
 * @brief f47c | 118 | Checks the vertical collision at the position, accouts for slopes
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u32 Block top Y position
 */
u32 SpriteUtilCheckVerticalCollisionAtPositionSlopes(u16 yPosition, u16 xPosition)
{
    u32 clipdata;
    u8 collision;
    u16 blockY;

    clipdata = ClipdataProcess(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        collision = COLLISION_SOLID;
    else
        collision = COLLISION_AIR;

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - SUB_PIXEL_POSITION_FLAG));
            collision = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) - SUB_PIXEL_POSITION_FLAG));
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) - SUB_PIXEL_POSITION_FLAG / 2));
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            collision = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2) + SUB_PIXEL_POSITION_FLAG / 2); 
            collision = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | DIV_SHIFT(xPosition & SUB_PIXEL_POSITION_FLAG, 2); 
            collision = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;


        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;
            
        default:
            blockY = yPosition & BLOCK_POSITION_FLAG;
    }

    if (yPosition >= blockY)
        gPreviousVerticalCollisionCheck = collision;
    else
        gPreviousVerticalCollisionCheck = COLLISION_AIR;

    return blockY;
}

/**
 * @brief f594 | 74 | Unknown function
 * 
 */
void unk_f594(void)
{
    u16 yPosition;
    u16 xPosition;
    u32 blockTop;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gCurrentSprite.yPosition = blockTop;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gCurrentSprite.yPosition = blockTop;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        gCurrentSprite.yPosition = blockTop;
}

/**
 * @brief f608 | 80 | Unknown function
 * 
 */
void unk_f608(void)
{
    u16 yPosition;
    u16 xPosition;
    u32 blockTop;

    yPosition = gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom;
    xPosition = gCurrentSprite.xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottom;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottom;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottom;
}

/**
 * f688 | 98 | Checks the collision at the given parameters and updates the gPreviousCollisionCheck global variable
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilCheckCollisionAtPosition(u32 yPosition, u32 xPosition)
{
    u32 collision;

    collision = ClipdataProcess(yPosition, xPosition);

    if (collision & CLIPDATA_TYPE_SOLID_FLAG)
        gPreviousCollisionCheck = COLLISION_SOLID;
    else
        gPreviousCollisionCheck = COLLISION_AIR;
    
    switch (LOW_BYTE(collision))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            gPreviousCollisionCheck = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            gPreviousCollisionCheck = COLLISION_PASS_THROUGH_BOTTOM;
    }
}

/**
 * @brief f720 | 7c | Gets the collision at the position
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u32 Collision check
 */
u32 SpriteUtilGetCollisionAtPosition(u16 yPosition, u16 xPosition)
{
    u32 clipdata;
    u32 collision;

    clipdata = ClipdataProcess(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        collision = COLLISION_SOLID;
    else
        collision = COLLISION_AIR;

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            collision = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            collision = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            collision = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;
    }

    return collision;
}

/**
 * @brief f79c | 70 | Handles the current sprite falling
 * 
 */
void SpriteUtilCurrentSpriteFall(void)
{
    u32 blockTopEdge;
    s32 movement;
    u32 offset;

    blockTopEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTopEdge;
        gCurrentSprite.pose = 0xE;
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3 = offset + 1;
            gCurrentSprite.yPosition -= -movement;
        }
    }
}

/**
 * f80c | 38 | Chooses a random X flip for the current sprite
 * 
 */
void SpriteUtilChooseRandomXFlip(void)
{
    if (MOD_AND(gSpriteRng, 2))
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
}

/**
 * f844 | 3C | Chooses a random X direction for the current sprite
 * 
 */
void SpriteUtilChooseRandomXDirection(void)
{
    if (MOD_AND(gSpriteRng, 2))
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f880 | 38 | Chooses a random X direction for the current sprite using its room slot
 * 
 */
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 roomSlot)
{
    if (MOD_AND(gCurrentSprite.roomSlot, 2))
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f8b0 | 30 | Makes the sprite face samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceSamusXFlip(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
}

/**
 * f8e0 | 30 | Makes the sprite face samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceSamusDirection(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f914 | 30 | Makes the sprite face away from samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceAwayFromSamusXFlip(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
}

/**
 * f944 | 34 | Makes the sprite face away from samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceAwayFromSamusDirection(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
}

/**
 * @brief f978 | 6c | To document
 * 
 * @param movement Movement
 */
void unk_f978(s16 movement)
{
    s32 velocity;

    velocity = movement;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gPreviousCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 2, 3);
    }
    else
    {
        if (gPreviousCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 2, 3);
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += velocity;
    else
        gCurrentSprite.xPosition -= velocity;
}

/**
 * @brief f9e4 | 98 | To document
 * 
 * @param movement Movement
 */
void unk_f9e4(s16 movement)
{
    s32 velocity;

    velocity = movement;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gPreviousCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 2, 3);
        else if (gPreviousCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 3, 4);
    }
    else
    {
        if (gPreviousCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 2, 3);
        else if (gPreviousCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
            velocity = (s16)FRACT_MUL(velocity, 3, 4);
    }

    if (velocity == 0)
        velocity = 1;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += velocity;
    else
        gCurrentSprite.xPosition -= velocity;
}

/**
 * @brief fa78 | 150 | Calcultes the new oam rotation to rotate a sprite towards a target
 * 
 * @param rotation Current rotation
 * @param targetY Target Y
 * @param targetX Target X
 * @param spriteY Current Y
 * @param spriteX Current X
 * @return u8 New rotation
 */
u8 SpriteUtilMakeSpriteFaceSamusRotation(s32 rotation, s32 targetY, s32 targetX, s32 spriteY, s32 spriteX)
{
    s32 targetRotation;
    s32 intensity;

    s32 _rotation;
    s32 dstY;
    s32 dstX;
    s32 y;
    s32 x;
    
    _rotation = (s16)rotation;
    dstY = (s16)targetY;
    dstX = (s16)targetX;
    y = (s16)spriteY;
    x = (s16)spriteX;

    intensity = Q_8_8(.01f);

    if (dstY < y)
    {
        if (x - BLOCK_SIZE < dstX && x + BLOCK_SIZE > dstX)
        {
            targetRotation = PI + PI / 2;
        }
        else if (dstX > x)
        {
            if (y - dstY < BLOCK_SIZE)
                targetRotation = 0;
            else
                targetRotation = PI + 3 * PI / 4;
        }
        else if (y - dstY < BLOCK_SIZE)
        {
            targetRotation = PI;
        }
        else
        {
            targetRotation = PI + PI / 4;
        }
    }
    else
    {
        if (x - BLOCK_SIZE < dstX && x + BLOCK_SIZE > dstX)
        {
            targetRotation = PI / 2;
        }
        else if (dstX > x)
        {
            if (dstY - y < BLOCK_SIZE)
                targetRotation = 0;
            else
                targetRotation = PI / 4;
        }
        else if (dstY - y < BLOCK_SIZE)
        {
            targetRotation = PI;
        }
        else
        {
            targetRotation = 3 * PI / 4;
        }
    }

    if (targetRotation == 0)
    {
        if ((u16)(_rotation - 1) < PI - 1)
            _rotation = (s16)(_rotation - intensity);
        else if (_rotation >= PI)
            _rotation = (s16)(_rotation + intensity);
    }
    else if (targetRotation == PI / 4)
    {
        if ((u16)(_rotation - PI / 4 - 1) < PI - 1)
            _rotation = (s16)(_rotation - intensity);
        else if ((u16)(_rotation - PI / 4) >= PI)
            _rotation = (s16)(_rotation + intensity);
    }
    else if (targetRotation == PI / 2)
    {
        if ((u16)(_rotation - PI / 2 - 1) < PI - 1)
            _rotation = (s16)(_rotation - intensity);
        else if ((u16)(_rotation - PI / 2) >= PI)
            _rotation = (s16)(_rotation + intensity);
    }
    else if (targetRotation == 3 * PI / 4)
    {
        if ((u16)(_rotation - 3 * PI / 4 - 1) < PI - 1)
            _rotation = (s16)(_rotation - intensity);
        else if ((u16)(_rotation - 3 * PI / 4) >= PI)
            _rotation = (s16)(_rotation + intensity);
    }
    else if (targetRotation == PI)
    {
        if ((u16)(_rotation - 1) < PI - 1)
            _rotation = (s16)(_rotation + intensity);
        else if (_rotation > PI)
            _rotation = (s16)(_rotation - intensity);
    }
    else if (targetRotation == PI + PI / 4)
    {
        if ((u16)(_rotation - PI / 4 - 1) < PI - 1)
            _rotation = (s16)(_rotation + intensity);
        else if ((u16)(_rotation - PI / 4 - 1) >= PI)
            _rotation = (s16)(_rotation - intensity);
    }
    else if (targetRotation == PI + PI / 2)
    {
        if ((u16)(_rotation - PI / 2 - 1) < PI - 1)
            _rotation = (s16)(_rotation + intensity);
        else if ((u16)(_rotation - PI / 2 - 1) >= PI)
            _rotation = (s16)(_rotation - intensity);
    }
    else if (targetRotation == PI + 3 * PI / 4)
    {
        if ((u16)(_rotation - 3 * PI / 4 - 1) < PI - 1)
            _rotation = (s16)(_rotation + intensity);
        else if ((u16)(_rotation - 3 * PI / 4 - 1) >= PI)
            _rotation = (s16)(_rotation - intensity);
    }

    return _rotation;
}

/**
 * @brief fbc8 | 38 | Checks if the animation of the current sprite has ended
 * 
 * @return u32 bool, ended
 */
u32 SpriteUtilCheckEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 caf;

    adc = gCurrentSprite.animationDurationCounter;
    caf = gCurrentSprite.currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);

    if (gCurrentSprite.pOam[caf].timer < adc && gCurrentSprite.pOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fc00 | 3c | Checks if the animation of the current sprite has nearly ended
 * 
 * @return u32 bool, nearly ended
 */
u32 SpriteUtilCheckNearEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 caf;

    adc = gCurrentSprite.animationDurationCounter;
    caf = gCurrentSprite.currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);
    APPLY_DELTA_TIME_INC(adc);

    if (gCurrentSprite.pOam[caf].timer < adc && gCurrentSprite.pOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fc3c | 48 | Checks if the animation of a sprite has ended
 * 
 * @param ramSlot Sprite slot
 * @return u32 bool, ended
 */
u32 SpriteUtilCheckEndSpriteAnim(u8 ramSlot)
{
    u8 adc;
    u16 caf;

    adc = gSpriteData[ramSlot].animationDurationCounter;
    caf = gSpriteData[ramSlot].currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);

    if (gSpriteData[ramSlot].pOam[caf].timer < adc && gSpriteData[ramSlot].pOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fc84 | 4c | Checks if the animation of a sprite has nearly ended
 * 
 * @param ramSlot Sprite slot
 * @return u32 bool, nearly ended
 */
u32 SpriteUtilCheckNearEndSpriteAnim(u8 ramSlot)
{
    u8 adc;
    u16 caf;

    adc = gSpriteData[ramSlot].animationDurationCounter;
    caf = gSpriteData[ramSlot].currentAnimationFrame;
    
    APPLY_DELTA_TIME_INC(adc);
    APPLY_DELTA_TIME_INC(adc);
    
    if (gSpriteData[ramSlot].pOam[caf].timer < adc && gSpriteData[ramSlot].pOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fcd0 | 38 | Checks if the animation of the sub sprite data 1 has ended
 * 
 * @return u8 bool, ended
 */
u8 SpriteUtilCheckEndSubSprite1Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData1.animationDurationCounter;
    caf = gSubSpriteData1.currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);

    if (gSubSpriteData1.pMultiOam[caf].timer < adc && gSubSpriteData1.pMultiOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fd08 | 3c | Checks if the animation of the sub sprite data 1 has nearly ended
 * 
 * @return u32 bool, nearly ended
 */
u8 SpriteUtilCheckNearEndSubSprite1Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData1.animationDurationCounter;
    caf = gSubSpriteData1.currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);
    APPLY_DELTA_TIME_INC(adc);

    if (gSubSpriteData1.pMultiOam[caf].timer < adc && gSubSpriteData1.pMultiOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fd44 | 38 | Checks if the animation of the sub sprite data 2 has ended
 * 
 * @return u32 bool, ended
 */
u32 SpriteUtilCheckEndSubSprite2Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData2.animationDurationCounter;
    caf = gSubSpriteData2.currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);

    if (gSubSpriteData2.pMultiOam[caf].timer < adc && gSubSpriteData2.pMultiOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fd7c | 34 | Checks if the animation of a sub sprite data has ended
 * 
 * @param pSub Sub sprite data pointer
 * @return u8 bool, ended
 */
u32 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub)
{
    u8 adc;
    u16 caf;

    adc = pSub->animationDurationCounter;
    caf = pSub->currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);

    if (pSub->pMultiOam[caf].timer < adc && pSub->pMultiOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fdac | 34 | Checks if the animation of a sub sprite data has nearly ended
 * 
 * @param pSub Sub sprite data Pointer
 * @return u32 bool, nearly ended
 */
u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub)
{
    u8 adc;
    u16 caf;

    adc = pSub->animationDurationCounter;
    caf = pSub->currentAnimationFrame;

    APPLY_DELTA_TIME_INC(adc);
    APPLY_DELTA_TIME_INC(adc);

    if (pSub->pMultiOam[caf].timer < adc && pSub->pMultiOam[++caf].timer == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fde0 | 68 | Checks if samus is in range of the current sprite horizontally
 * 
 * @param yRange Y range
 * @param xRange X range
 * @return u8 Result (NSLR enum)
 */
u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 yRange, u16 xRange)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = NSLR_OUT_OF_RANGE;

    // Get samus middle position visually
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop / 2;
    samusX = gSamusData.xPosition;

    // Get sprite position
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    
    // Check Y position
    if (spriteY > samusY)
    {
        // Sprite is below
        if (spriteY - samusY >= yRange)
            return NSLR_OUT_OF_RANGE;
    }
    else
    {
        // Sprite is above
        if (samusY - spriteY >= yRange)
            return NSLR_OUT_OF_RANGE;
    }
   
    // Check X position
    if (spriteX > samusX)
    {
        // Sprite is on left
        if (spriteX - samusX < xRange)
            result = NSLR_LEFT;
    }
    else
    {
        // Sprite is on right
        if (samusX - spriteX < xRange)
            result = NSLR_RIGHT;
    }

    return result;
}

/**
 * @brief fe48 | 68 | Checks if samus is in range of the current sprite vertically
 * 
 * @param yRange Y range
 * @param xRange X range
 * @return u8 Result (NSLR enum)
 */
u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 yRange, u16 xRange)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = NSAB_OUT_OF_RANGE;

    // Get samus middle position visually
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop / 2;
    samusX = gSamusData.xPosition;

    // Get sprite position
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    
    // Check X position
    if (spriteX > samusX)
    {
        // Sprite is on left
        if (spriteX - samusX >= xRange)
            return NSAB_OUT_OF_RANGE;
    }
    else
    {
        // Sprite is on right
        if (samusX - spriteX >= xRange)
            return NSAB_OUT_OF_RANGE;
    }
   
    // Check Y position
    if (spriteY > samusY)
    {
        // Sprite is below
        if (spriteY - samusY < yRange)
            result = NSAB_ABOVE;
    }
    else
    {
        // Sprite is above
        if (samusY - spriteY < yRange)
            result = NSAB_BELOW;
    }

    return result;
}

/**
 * @brief feb0 | b0 | Checks if samus is in front or behind the current sprite 
 * 
 * @param yRange Y range
 * @param xRangeFront X range (in front)
 * @param xRangeBehind X range (behind)
 * @return u32 Result (NSFB enum)
 */
u32 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 yRange, u16 xRangeFront, u16 xRangeBehind)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;
    u8 xFlip;

    result = NSFB_OUT_OF_RANGE;
    xFlip = FALSE;

    // Get samus middle position visually
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop / 2;
    samusX = gSamusData.xPosition;

    // Get sprite position
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    
    // Check Y position
    if (spriteY > samusY)
    {
        // Sprite is below
        if (spriteY - samusY >= yRange)
            return NSFB_OUT_OF_RANGE;
    }
    else
    {
        // Sprite is above
        if (samusY - spriteY >= yRange)
            return NSFB_OUT_OF_RANGE;
    }

    // Get is flipped, this assume that when flipped the sprite faced right
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xFlip = TRUE;
    
    // Check X position
    if (spriteX > samusX)
    {
        // Sprite is on right
        if (xFlip)
        {
            // Sprite is facing right
            if (spriteX - samusX < xRangeBehind)
                result = NSFB_BEHIND;
        }
        else
        {
            // Sprite is facing left
            if (spriteX - samusX < xRangeFront)
                result = NSFB_IN_FRONT;
        }
    }
    else
    {
        // Sprite is on left
        if (xFlip)
        {
            // Sprite is facing right
            if (samusX - spriteX < xRangeFront)
                result = NSFB_IN_FRONT;
        }
        else
        {
            // Sprite is facing left
            if (samusX - spriteX < xRangeBehind)
                result = NSFB_BEHIND;
        }
    }

    return result;
}

/**
 * ff60 | 88 | Handles samus standing on a sprite
 * 
 * @param pSprite Sprite Data Pointer
 */
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite)
{
    if (pSprite->status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Check set Samus standing on an enemy
        if (gSamusData.standingStatus != STANDING_ENEMY)
        {
            if (gSamusData.standingStatus == STANDING_MIDAIR)
            {
                // Samus was midair, land on the enemy
                SamusSetPose(SPOSE_LANDING_REQUEST);
            }

            gSamusData.standingStatus = STANDING_ENEMY;
        }

        // This is called after the collision check and the AI, the flag is always cleared
        // but next frame the collision checks will set it again if Samus is still on top
        pSprite->status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
        return;
    }

    // Samus is no longer on top of the enemy
    switch (pSprite->standingOnSprite)
    {
        case SAMUS_STANDING_ON_SPRITE_ON:
            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_RELEASING;

            if (gSamusDataCopy.yPosition <= gSamusData.yPosition)
            {
                // Set Samus above the sprite
                gSamusData.yPosition = pSprite->yPosition + pSprite->hitboxTop + ONE_SUB_PIXEL;
            }
            break;

        case SAMUS_STANDING_ON_SPRITE_RELEASING:
            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;

            // Set Samus mid air
            if (gSamusData.standingStatus == STANDING_ENEMY)
                gSamusData.standingStatus = STANDING_MIDAIR;
    }
}

/**
 * ffe8 | 64 | Updates the freeze timer of the current sprite
 * 
 */
void SpriteUtilUpdateFreezeTimer(void)
{
    u8 freezeTimer;

    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(1.f / 30)))
        APPLY_DELTA_TIME_DEC(gCurrentSprite.freezeTimer);

    freezeTimer = gCurrentSprite.freezeTimer;
    
    if (freezeTimer == 0)
    {
        // Decrement animation timer once the freeze timer is done
        APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
    }

    // Flicker lasts for 1.5 seconds, but the freeze timer decrements every 2 frames, which is why the time is halved
    if (freezeTimer <= CONVERT_SECONDS(1.5f) / 2)
    {
        // Flicker
        if (MOD_BLOCK_AND(freezeTimer, CONVERT_SECONDS(1.f / 60)))
            gCurrentSprite.paletteRow = NBR_OF_PALETTE_ROWS - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 1004c | 58 | Updates the freeze timer of the current sprite (easy mode)
 * 
 */
void SpriteUtilUnfreezeAnimEasy(void)
{
    u8 freezeTimer;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.freezeTimer);

    freezeTimer = gCurrentSprite.freezeTimer;
    
    if (freezeTimer == 0)
    {
        // Decrement animation timer once the freeze timer is done
        APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
    }

    if (freezeTimer <= CONVERT_SECONDS(1.5f) && MOD_AND(freezeTimer, CONVERT_SECONDS(1.f / 30)) == 0)
    {
        // Flicker
        if (MOD_BLOCK_AND(freezeTimer, CONVERT_SECONDS(1.f / 30)))
            gCurrentSprite.paletteRow = NBR_OF_PALETTE_ROWS - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 100a4 | 58 | Updates the freeze timer of the current sprite (metroid)
 * 
 */
void SpriteUtilMetroidUnfreezeAnim(void)
{
    u8 freezeTimer;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.freezeTimer);
    APPLY_DELTA_TIME_DEC(gCurrentSprite.freezeTimer);

    freezeTimer = gCurrentSprite.freezeTimer;
    
    if (freezeTimer == 0)
    {
        // Decrement animation timer once the freeze timer is done
        APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
    }

    // Flicker lasts for 1 second, but the freeze timer decrements twice as fast, which is why the time is doubled
    if (freezeTimer <= CONVERT_SECONDS(1.f) * 2 && MOD_BLOCK_AND(freezeTimer, CONVERT_SECONDS(1.f / 30)) == 0)
    {
        if (MOD_BLOCK_AND(freezeTimer, CONVERT_SECONDS(1.f / 15)))
            gCurrentSprite.paletteRow = NBR_OF_PALETTE_ROWS - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 100fc | 9c | Updates the freeze timer of the secondary sprites of the specified primary sprite
 * 
 * @param spriteId Sprite id
 * @param ramSlot Primary sprite slot
 */
void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 spriteId, u8 ramSlot)
{
    u8 i;

    if (gCurrentSprite.freezeTimer == 0)
        return;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (!(gSpriteData[i].properties & SP_SECONDARY_SPRITE))
            continue;

        if (gSpriteData[i].spriteId == spriteId && gSpriteData[i].primarySpriteRamSlot == ramSlot &&
            gSpriteData[i].freezeTimer < gCurrentSprite.freezeTimer)
        {
            if (gSpriteData[i].properties & SP_DESTROYED)
                continue;

            gSpriteData[i].freezeTimer = gCurrentSprite.freezeTimer;
            gSpriteData[i].paletteRow = NBR_OF_PALETTE_ROWS - (gSpriteData[i].spritesetGfxSlot + gSpriteData[i].frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
        }
    }
}

/**
 * @brief 10198 | 5c | Updates the freeze timer of the primary sprite of the current secondary sprite
 * 
 */
void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void)
{
    u8 ramSlot;

    if (gCurrentSprite.freezeTimer == 0)
        return;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].freezeTimer < gCurrentSprite.freezeTimer && !(gSpriteData[ramSlot].properties & SP_DESTROYED))
    {
        gSpriteData[ramSlot].freezeTimer = gCurrentSprite.freezeTimer;
        gSpriteData[ramSlot].paletteRow = NBR_OF_PALETTE_ROWS - (gSpriteData[ramSlot].spritesetGfxSlot + gSpriteData[ramSlot].frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
    } 
}

/**
 * @brief 101f4 | 68 | Unfreezes all of the secondary sprites of the specified type
 * 
 * @param spriteId Sprite ID
 * @param ramSlot Ram slot
 */
void SpriteUtilUnfreezeSecondarySprites(u8 spriteId, u8 ramSlot)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (!(gSpriteData[i].properties & SP_SECONDARY_SPRITE))
            continue;

        if (gSpriteData[i].spriteId == spriteId && gSpriteData[i].primarySpriteRamSlot == ramSlot && gSpriteData[i].freezeTimer != 0)
        {
            gSpriteData[i].freezeTimer = 0;
            gSpriteData[i].paletteRow = 0;
        }
    }
}

/**
 * @brief 1025c | 44 | Gradual refill of samus' energy
 * 
 * @return u8 bool, ongoing
 */
u8 SpriteUtilRefillEnergy(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentEnergy;

    if (gEquipment.currentEnergy < gEquipment.maxEnergy)
    {
        current = (gEquipment.maxEnergy - gEquipment.currentEnergy);
        current /= 32;

        if (current == 0)
            current = 1;
        else if (current >= 11)
            current = 11;

        gEquipment.currentEnergy += current;
        if (gEquipment.currentEnergy > gEquipment.maxEnergy)
            gEquipment.currentEnergy = gEquipment.maxEnergy;
        
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 102a0 | 44 | Gradual refill of samus' missiles
 * 
 * @return u8 bool, ongoing
 */
u8 SpriteUtilRefillMissiles(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentMissiles;

    if (gEquipment.currentMissiles < gEquipment.maxMissiles)
    {
        current = (gEquipment.maxMissiles - gEquipment.currentMissiles);
        current /= 32;

        if (current == 0)
            current = 1;
        else if (current >= 6)
            current = 6;

        gEquipment.currentMissiles += current;
        if (gEquipment.currentMissiles > gEquipment.maxMissiles)
            gEquipment.currentMissiles = gEquipment.maxMissiles;
        
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 102ea | 44 | Gradual refill of samus' super missiles
 * 
 * @return u8 bool, ongoing
 */
u8 SpriteUtilRefillSuperMissiles(void)
{
    u16 current;

    current = gEquipment.currentSuperMissiles;

    if (current < gEquipment.maxSuperMissiles)
    {
        current = (gEquipment.maxSuperMissiles - gEquipment.currentSuperMissiles);
        current /= 16;

        if (current == 0)
            current = 1;
        else if (current >= 4)
            current = 4;

        gEquipment.currentSuperMissiles += current;
        if (gEquipment.currentSuperMissiles > gEquipment.maxSuperMissiles)
            gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;
        
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 10328 | 44 | Gradual refill of samus' power bombs
 * 
 * @return u8 bool, ongoing
 */
u8 SpriteUtilRefillPowerBombs(void)
{
    u16 current;

    current = gEquipment.currentPowerBombs;

    if (current < gEquipment.maxPowerBombs)
    {
        current = (gEquipment.maxPowerBombs - gEquipment.currentPowerBombs);
        current /= 16;

        if (current == 0)
            current = 1;
        else if (current >= 4)
            current = 4;

        gEquipment.currentPowerBombs += current;
        if (gEquipment.currentPowerBombs > gEquipment.maxPowerBombs)
            gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;
        
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 1036c | 110 | Checks if samus is crouching or morphed
 * 
 * @return u8 bool, crouching or morphed
 */
u8 SpriteUtilCheckCrouchingOrMorphed(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 1047c | 2c | Checks if samus is crouching or crawling
 * 
 * @return u8 bool, crouching or crawling
 */
u8 SpriteUtilCheckCrouchingOrCrawling(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 104a8 | 24 | Checks if samus is morphed
 * 
 * @return u32 bool, morphed
 */
u32 SpriteUtilCheckMorphed(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 104cc | 2c | Checks if samus is in a state that requires sprite behavior to be stopped
 * 
 * @return u32 bool, stop sprites
 */
u32 SpriteUtilCheckStopSpritesPose(void)
{
    // Movement is prevented
    if (gPreventMovementTimer != 0)
        return TRUE;

    // Using an elevator or facing the foreground (after an elevator)
    switch (gSamusData.pose)
    {
        case SPOSE_USING_AN_ELEVATOR:
        case SPOSE_FACING_THE_FOREGROUND:
            return TRUE;
    }
    
    return FALSE;
}

/**
 * 104f8 | 1b0 | Handles a sprite taking damage from a contact with samus
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param pData Samus data pointer
 * @return The damage contact type
 */
u32 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData)
{
    u8 dct;
    struct Equipment* pEquipment;
    u16 weakness;
    u16 bbf;
    u16 damage;
    u8 isDead;
    u8 isft;

    dct = DCT_NONE;

    // Abort if suitless
    if (gEquipment.suitType == SUIT_SUITLESS)
        return DCT_NONE;

    // Not affected by projectiles, abort
    if (pSprite->properties & (SP_SOLID_FOR_PROJECTILES | SP_IMMUNE_TO_PROJECTILES))
        return DCT_NONE;

    // Ignoring projectiles, abort
    if (pSprite->status & SPRITE_STATUS_IGNORE_PROJECTILES)
        return DCT_NONE;

    if (pData->speedboostingShinesparking != FALSE)
    {
        // Check shinesparking or speedboosting
        if (pData->pose == SPOSE_SHINESPARKING || pData->pose == SPOSE_BALLSPARKING)
            dct = DCT_SHINESPARK;
        else
            dct = DCT_SPEEDBOOSTER;
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_SCREW_ATTACKING:
                // Screw attacking
                dct = DCT_SCREW_ATTACK;
                break;
            
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_STARTING_WALL_JUMP:
            case SPOSE_SPACE_JUMPING:
                // Check beam is charged
                if (gSamusWeaponInfo.chargeCounter >= CHARGE_BEAM_THRESHOLD)
                    dct = DCT_SUDO_SCREW;

            default:
                if (dct == DCT_NONE)
                    return DCT_NONE;
        }
    }

    // Get weakness
    if (pSprite->properties & SP_SECONDARY_SPRITE)
        weakness = GET_SSPRITE_WEAKNESS(pSprite->spriteId);
    else
        weakness = GET_PSPRITE_WEAKNESS(pSprite->spriteId);

    if (dct >= DCT_SUDO_SCREW)
    {
        // Sudo screw, check is weak
        if (weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS))
        {
            // Destroy charge
            gSamusWeaponInfo.chargeCounter = 0;

            // Get damage
            damage = 2;
            bbf = gEquipment.beamBombsActivation;

            // Increment by one for each beam
            if (bbf & BBF_LONG_BEAM)
                damage++;

            if (bbf & BBF_ICE_BEAM)
                damage++;

            if (bbf & BBF_WAVE_BEAM)
                damage++;

            if (bbf & BBF_PLASMA_BEAM)
                damage++;

            // Multiply by 4 and apply
            damage *= 4;
            isDead = ProjectileDealDamage(pSprite, damage);
            if (isDead)
            {
                // Set dead and abort
                pSprite->pose = SPRITE_POSE_SUDO_SCREW_DESTROYED;
                return dct;
            }

            // Reset collision timer, if the enemy wasn't killed by the sudo screw then samus will immediately take damage
            pSprite->ignoreSamusCollisionTimer = 0;
        }

        dct = DCT_NONE;
    }
    else
    {
        if (weakness & WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK)
        {
            // Destroy the sprite
            pSprite->health = 0;
            pSprite->properties |= SP_DESTROYED;
            pSprite->freezeTimer = 0;
            pSprite->paletteRow = 0;

            // Update samus if she was standing on it
            if (pSprite->standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && pData->standingStatus == STANDING_ENEMY)
            {
                pData->standingStatus = STANDING_MIDAIR;
                pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
            }

            // Set destructed pose
            if (dct == DCT_SHINESPARK)
                pSprite->pose = SPRITE_POSE_SHINESPARK_DESTROYED;
            else if (dct == DCT_SPEEDBOOSTER)
                pSprite->pose = SPRITE_POSE_SPEEDBOOSTER_DESTROYED;
            else
                pSprite->pose = SPRITE_POSE_SCREW_ATTACK_DESTROYED;

            pSprite->ignoreSamusCollisionTimer = DELTA_TIME;
            SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(.29f));
            pSprite->properties |= SP_DAMAGED;
        }
        else
        {
            isft = CONVERT_SECONDS(.05f);
            if (SPRITE_GET_ISFT(*pSprite) < isft)
            {
                SPRITE_CLEAR_AND_SET_ISFT(*pSprite, isft);
            }
            dct = DCT_NONE;
        }
    }
    
    return dct;
}

/**
 * @brief 106a8 | 20 | Checks if samus is pulling herself up
 * 
 * @return u32 bool, pulling self up
 */
u32 SpriteUtilCheckPullingSelfUp(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
           return TRUE;
    }

    return FALSE;
}

/**
 * @brief 106c8 | 20 | Checks if samus is on a zipline
 * 
 * @return u32 bool, on zipline
 */
u32 SpriteUtilCheckOnZipline(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
           return TRUE;
    }

    return FALSE;
}

/**
 * @brief 106e8 | 50 | Counts the number of primary sprites
 * 
 * @param spriteId Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountPrimarySprites(u8 spriteId)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteId == spriteId)
            count++;
    }

    return count;
}

/**
 * @brief 10738 | 60 | Counts the number of secondary sprites the current sprite ram slot
 * 
 * @param spriteId Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 spriteId)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->properties & SP_SECONDARY_SPRITE &&
            pSprite->spriteId == spriteId && pSprite->primarySpriteRamSlot == ramSlot)
        {
            count++;
        }
    }

    return count;
}

/**
 * @brief 10798 | 60 | Counts the number of primary sprites the current sprite ram slot
 * 
 * @param spriteId Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 spriteId)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pSprite->properties & SP_SECONDARY_SPRITE)
            continue;

        if (pSprite->spriteId == spriteId && pSprite->primarySpriteRamSlot == ramSlot)
            count++;
    }

    return count;
}

/**
 * @brief 107f8 | 58 | Finds the ram slot of a primary sprite
 * 
 * @param spriteId Sprite ID
 * @return u8 Ram slot
 */
u8 SpriteUtilFindPrimary(u8 spriteId)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteId == spriteId)
            return ramSlot;

        ramSlot++;
    }

    return UCHAR_MAX;
}

/**
 * @brief 10850 | 60 | Finds the ram slot of a secondary sprite
 * 
 * @param spriteId Sprite ID
 * @param roomSlot Room slot/part number
 * @return u8 Ram slot
 */
u8 SpriteUtilFindSecondaryWithRoomSlot(u8 spriteId, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->properties & SP_SECONDARY_SPRITE &&
            pSprite->spriteId == spriteId && pSprite->roomSlot == roomSlot)
        {
            return ramSlot;
        }

        ramSlot++;
    }

    return UCHAR_MAX;
}

/**
 * @brief 108b0 | 50 | Checks if the current sprite has a drop
 * 
 * @return u8 bool, has drop
 */
u8 SpriteUtilCheckHasDrops(void)
{
    u8 ramSlot;
    u8 collision;
    struct SpriteData* pSprite;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    collision = SSC_SMALL_ENERGY_DROP;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->primarySpriteRamSlot == ramSlot && pSprite->samusCollision >= collision)
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 10900 | 44 | Counts the number of drops currently existing
 * 
 * @return u8 Number of drops
 */
u8 SpriteUtilCountDrops(void)
{
    u8 count;
    u8 spriteId;
    struct SpriteData* pSprite;

    count = 0;
    spriteId = SSC_SMALL_ENERGY_DROP;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision >= spriteId)
            count++;
    }

    return count;
}

/**
 * @brief 10944 | 254 | Handles a Mecha Ridley missile moving
 * 
 * @param samusY Samus Y position
 * @param samusX Samus X position
 * @param ySpeed Missile Y speed
 * @param xSpeed Missile X speed
 * @param speedDivisor Speed Divisor
 */
void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{
    u32 flip;
    u16 speed;
    u32 newPos;

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition > samusX - PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < xSpeed)
                    gCurrentSprite.work2++;

                gCurrentSprite.xPosition += (gCurrentSprite.work2 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
                gCurrentSprite.xPosition += (gCurrentSprite.work1 >> speedDivisor);
            else
                flip++;
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition < samusX + PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < xSpeed)
                    gCurrentSprite.work2++;

                speed = gCurrentSprite.work2 >> speedDivisor;
                newPos = gCurrentSprite.xPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition = newPos;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                speed = gCurrentSprite.work1 >> speedDivisor;
                newPos = gCurrentSprite.xPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition = newPos;
                }
            }
            else
            {
                flip++;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work2 = 1;
    }

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition > samusY - PIXEL_SIZE)
            {
                gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                if (gCurrentSprite.work3 < ySpeed)
                    gCurrentSprite.work3++;

                gCurrentSprite.yPosition += (gCurrentSprite.work3 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work0 != 0)
                gCurrentSprite.yPosition += gCurrentSprite.work0 >> speedDivisor;
            else
                flip++;
        }
    }
    else
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition < samusY + PIXEL_SIZE)
            {
                gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                if (gCurrentSprite.work3 < ySpeed)
                    gCurrentSprite.work3++;

                speed = gCurrentSprite.work3 >> speedDivisor;
                newPos = gCurrentSprite.yPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.work0 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition = newPos;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work0 != 0)
            {
                speed = gCurrentSprite.work0 >> speedDivisor;
                newPos = gCurrentSprite.yPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.work0 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition = newPos;
                }
            }
            else
            {
                flip++;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work3 = 1;
    }
}
/**
 * @brief 10b98 | 158 | Handles a ridley fireball moving (TODO rename to a more general name)
 * 
 * @param spriteY Destination Y
 * @param samusX Destination X (unused)
 * @param ySpeed Y speed
 * @param xSpeed X speed
 * @param speedDivisor Speed divisor
 */
void SpriteUtilRidleyFireballMove(u16 dstY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{
    u16 xPosition;
    u16 speed;
    u8 flip;
    u8 updatePos;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work2 < xSpeed)
            gCurrentSprite.work2++;

        gCurrentSprite.xPosition += gCurrentSprite.work2 >> speedDivisor;
    }
    else
    {
        if (gCurrentSprite.work2 < xSpeed)
            gCurrentSprite.work2++;

        gCurrentSprite.xPosition -= gCurrentSprite.work2 >> speedDivisor;
    }

    flip = FALSE;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.work0 == 0)
        {
            updatePos = FALSE;
            if (gCurrentSprite.work3 < ySpeed)
            {
                if (gCurrentSprite.yPosition <= dstY - PIXEL_SIZE)
                {
                    gCurrentSprite.work3++;
                    updatePos = TRUE;
                }
                else
                {
                    gCurrentSprite.work0 = gCurrentSprite.work3;
                    updatePos = FALSE;
                }
            }
            else
            {
                updatePos = TRUE;
            }

            if (updatePos)
                gCurrentSprite.yPosition += (gCurrentSprite.work3 >> speedDivisor);
        }
        else
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                flip = TRUE;
            }
            else
                gCurrentSprite.yPosition += (gCurrentSprite.work0 >> speedDivisor);
        }
    }
    else
    {
         if (gCurrentSprite.work0 == 0)
        {
            updatePos = FALSE;
            if (gCurrentSprite.work3 < ySpeed)
            {
                if (gCurrentSprite.yPosition >= dstY + PIXEL_SIZE)
                {
                    gCurrentSprite.work3++;
                    updatePos = TRUE;
                }
                else
                {
                    gCurrentSprite.work0 = gCurrentSprite.work3;
                    updatePos = FALSE;
                }
            }
            else
            {
                updatePos = TRUE;
            }
            
            if (updatePos)
                gCurrentSprite.yPosition -= (gCurrentSprite.work3 >> speedDivisor);
        }
        else
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 != 0)
            {
                speed = gCurrentSprite.work0 >> speedDivisor;
                if ((gCurrentSprite.yPosition - speed) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work0 = 0;
                }
                else
                    gCurrentSprite.yPosition -= speed;
            }
            else
                flip = TRUE;
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work3 = 1;
    }
}

/**
 * 10cf0 | 78 | Updates the stun timer of the sprite
 * 
 * @param pSprite Sprite data pointer
 */
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite)
{
    u8 isft;

    if (SPRITE_GET_ISFT(*pSprite) == 0)
        return;

    isft = APPLY_DELTA_TIME_DEC(pSprite->invincibilityStunFlashTimer);

    if (MOD_AND(isft, CONVERT_SECONDS(1.f / 15)) != 0)
        return;

    if (MOD_BLOCK_AND(isft, CONVERT_SECONDS(1.f / 15)))
    {
        if (pSprite->health != 0)
            pSprite->paletteRow = NBR_OF_PALETTE_ROWS - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset) - SPRITE_STUN_PALETTE_OFFSET;
    }
    else
    {
        if (pSprite->health != 0)
        {
            if (pSprite->freezeTimer != 0)
                pSprite->paletteRow = NBR_OF_PALETTE_ROWS - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
            else
                pSprite->paletteRow = pSprite->absolutePaletteRow;
        }
    }
}

/**
 * 10d68 | 126 | Spawns a set of random sprite debris depending on the parameters
 * 
 * @param cloudType Cloud Type
 * @param number Number Of Debris to spawn
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilRandomSpriteDebris(u8 cloudType, u8 number, u16 yPosition, u16 xPosition)
{
    switch (number)
    {
        case 1:
            if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(1.f / 30)))
                SpriteDebrisInit(cloudType, 2, yPosition - EIGHTH_BLOCK_SIZE, xPosition + EIGHTH_BLOCK_SIZE);
            else
                SpriteDebrisInit(cloudType, 1, yPosition + EIGHTH_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
            break;

        case 2:
            if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(1.f / 30)))
            {
                SpriteDebrisInit(cloudType, 2, yPosition - EIGHTH_BLOCK_SIZE, xPosition + EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 4, yPosition + EIGHTH_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
            }
            else
            {
                SpriteDebrisInit(cloudType, 1, yPosition - EIGHTH_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 3, yPosition, xPosition + EIGHTH_BLOCK_SIZE);
            }
            break;

        case 3:
            if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(1.f / 30)))
            {
                SpriteDebrisInit(cloudType, 1, yPosition - EIGHTH_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 3, yPosition - QUARTER_BLOCK_SIZE, xPosition + EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 4, yPosition + EIGHTH_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
            }
            else
            {
                SpriteDebrisInit(cloudType, 2, yPosition - QUARTER_BLOCK_SIZE, xPosition + EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 3, yPosition + EIGHTH_BLOCK_SIZE, xPosition + EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(cloudType, 4, yPosition + QUARTER_BLOCK_SIZE, xPosition - EIGHTH_BLOCK_SIZE);
            }
    }
}

u8 SpriteUtilGetAmmoDrop(u8 rng)
{
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
    {
        if (rng & 1 && gEquipment.maxMissiles > gEquipment.currentMissiles)
            return PSPRITE_MISSILE_DROP;

        if (rng & 2 && gEquipment.maxSuperMissiles > gEquipment.currentSuperMissiles)
            return PSPRITE_SUPER_MISSILE_DROP;

        if (rng & 4 && gEquipment.maxPowerBombs > gEquipment.currentPowerBombs)
            return PSPRITE_POWER_BOMB_DROP;
    }

    return PSPRITE_UNUSED0;
}

/**
 * @brief 10eec | 198 | Determines the enemy drop for the current sprite
 * 
 * @return u8 Drop sprite ID
 */
u8 SpriteUtilDetermineEnemyDrop(void)
{
    u8 drop;
    u8 fullLife;
    u16 rng;
    u8 spriteId;

    u16 smallEnergyProb;
    u16 largeEnergyProb;
    u16 missileProb;
    u16 superProb;
    u16 powerProb;

    drop = PSPRITE_UNUSED0;

    fullLife = FALSE;
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
        fullLife = TRUE;

    rng = gSpriteRng;
    rng *= 256;
    rng = (gFrameCounter8Bit + gFrameCounter16Bit + rng);
    rng = rng % SPRITE_DROP_MAX_PROB;

    if (rng == 0)
        rng = 1;

    spriteId = gCurrentSprite.spriteId;

    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        smallEnergyProb = sSecondarySpriteStats[spriteId][4];
        largeEnergyProb = sSecondarySpriteStats[spriteId][5];
        missileProb = sSecondarySpriteStats[spriteId][6];
        superProb = sSecondarySpriteStats[spriteId][7];
        powerProb = sSecondarySpriteStats[spriteId][8];
    }
    else
    {
        smallEnergyProb = sPrimarySpriteStats[spriteId][4];
        largeEnergyProb = sPrimarySpriteStats[spriteId][5];
        missileProb = sPrimarySpriteStats[spriteId][6];
        superProb = sPrimarySpriteStats[spriteId][7];
        powerProb = sPrimarySpriteStats[spriteId][8];
    }

    if (powerProb != 0)
    {
        powerProb = SPRITE_DROP_MAX_PROB - powerProb;

        if (SPRITE_DROP_MAX_PROB >= rng && rng > powerProb)
        {
            if (gEquipment.maxPowerBombs > gEquipment.currentPowerBombs)
            {
                // Not at full power bombs, drop them
                drop = PSPRITE_POWER_BOMB_DROP;
            }
            else
            {
                // At full power bombs, try to drop something else
                if (fullLife)
                {
                    // As default, either a small energy or a power bomb if the player unlocked them
                    if (gEquipment.maxPowerBombs != 0)
                        drop = PSPRITE_POWER_BOMB_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                {
                    // Not full life, so large energy
                    drop = PSPRITE_LARGE_ENERGY_DROP;
                }
            }

            return drop;
        }
    }
    else
    {
        powerProb = SPRITE_DROP_MAX_PROB;
    }

    if (superProb != 0)
    {
        superProb = powerProb - superProb;

        if (powerProb >= rng && rng > superProb)
        {
            // Same logic as power bombs, but for super missiles
            if (gEquipment.maxSuperMissiles > gEquipment.currentSuperMissiles)
            {
                drop = PSPRITE_SUPER_MISSILE_DROP;
            }
            else
            {
                if (fullLife)
                {
                    if (gEquipment.maxSuperMissiles != 0)
                        drop = PSPRITE_SUPER_MISSILE_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                {
                    drop = PSPRITE_LARGE_ENERGY_DROP;
                }
            }

            return drop;
        }
    }
    else
    {
        superProb = powerProb;
    }

    if (missileProb != 0)
    {
        missileProb = superProb - missileProb;

        if (superProb >= rng && rng > missileProb)
        {
            // Same logic as power bombs, but for missiles
            if (gEquipment.maxMissiles > gEquipment.currentMissiles)
            {
                drop = PSPRITE_MISSILE_DROP;
            }
            else
            {
                if (fullLife)
                {
                    if (gEquipment.maxMissiles != 0)
                        drop = PSPRITE_MISSILE_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                {
                    drop = PSPRITE_LARGE_ENERGY_DROP;
                }
            }

            return drop;
        }
    }
    else
    {
        missileProb = superProb;
    }

    if (largeEnergyProb != 0)
    {
        largeEnergyProb = missileProb - largeEnergyProb;

        if (missileProb >= rng && rng > largeEnergyProb)
        {
            // Default to large energy
            drop = PSPRITE_LARGE_ENERGY_DROP;

            // However, if full life and missiles are unlocked, drop them
            if (fullLife && gEquipment.maxMissiles > gEquipment.currentMissiles)
                drop = PSPRITE_MISSILE_DROP;

            return drop;
        }
    }
    else
    {
        largeEnergyProb = missileProb;
    }

    if (smallEnergyProb != 0)
    {
        smallEnergyProb = largeEnergyProb - smallEnergyProb;

        if (largeEnergyProb >= rng && rng > smallEnergyProb)
        {
            // Default to small energy
            drop = PSPRITE_SMALL_ENERGY_DROP;

            // However, if full life and missiles are unlocked, drop them
            if (fullLife && gEquipment.maxMissiles > gEquipment.currentMissiles)
                drop = PSPRITE_MISSILE_DROP;

            return drop;
        }
    }

    return drop;
}

/**
 * 11084 | 1fc | Handles the death of a sprite, replaces it with a drop if necessary
 * 
 * @param deathType Death Type (0 spawns a drop)
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param playSound Play Sound flag
 * @param effect Particle Effect if not killed by damage contact
 */
void SpriteUtilSpriteDeath(u8 deathType, u16 yPosition, u16 xPosition, u8 playSound, u8 effect)
{
    u8 drop;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_SHINESPARK_DESTROYED:
            ParticleSet(yPosition, xPosition, PE_SHINESPARK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0, 3, yPosition, xPosition);
            SoundPlay(SOUND_SHINESPARK_DESTROYED);
            break;

        case SPRITE_POSE_SPEEDBOOSTER_DESTROYED:
            ParticleSet(yPosition, xPosition, PE_SPEEDBOOSTER_DESTROYED);
            SpriteUtilRandomSpriteDebris(0, 3, yPosition, xPosition);
            SoundPlay(SOUND_SPEEDBOOSTER_DESTROYED);
            break;

        case SPRITE_POSE_SCREW_ATTACK_DESTROYED:
            ParticleSet(yPosition, xPosition, PE_SCREW_ATTACK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0, 3, yPosition, xPosition);
            SoundPlay(SOUND_SCREW_ATTACK_DESTROYED);
            break;

        case SPRITE_POSE_SUDO_SCREW_DESTROYED:
            ParticleSet(yPosition, xPosition, PE_SUDO_SCREW_DESTROYED);
            SpriteUtilRandomSpriteDebris(0, 3, yPosition, xPosition);
            SoundPlay(SOUND_SUDO_SCREW_DESTROYED);
            break;

        default:
            // Check play sprite explosion effects
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (playSound)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);
            }
            else if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                if (playSound)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_MEDIUM);
            }
            else if (effect == PE_SPRITE_EXPLOSION_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_BIG);
                if (playSound)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_BIG);
            }
            else if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                if (playSound)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            }
            else if (effect == PE_MAIN_BOSS_DEATH || effect == PE_FREEZING_SPRITE_WITH_ICE || effect == PE_FREEZING_SPRITE_WITH_CHARGED_ICE)
                ParticleSet(yPosition, xPosition, effect);
    }

    drop = SpriteUtilDetermineEnemyDrop();
    if (drop != PSPRITE_UNUSED0)
    {       
        if (deathType != DEATH_NORMAL)
        {
            if (deathType != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
            {
                SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
            }
        }
        else
        {
            // Init data for drop
            gCurrentSprite.status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties = 0;
            gCurrentSprite.spritesetGfxSlot = 0;
            gCurrentSprite.spriteId = drop;
            gCurrentSprite.yPosition = yPosition;
            gCurrentSprite.xPosition = xPosition;
            gCurrentSprite.bgPriority = 2;
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pose = SPRITE_POSE_UNINITIALIZED;
            gCurrentSprite.health = 0;
            gCurrentSprite.invincibilityStunFlashTimer = 0;
            gCurrentSprite.paletteRow = 0;
            gCurrentSprite.frozenPaletteRowOffset = 0;
            gCurrentSprite.absolutePaletteRow = 0;
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            gCurrentSprite.freezeTimer = 0;
        }
    }
    else
    {
        if (deathType == DEATH_NORMAL)
            gCurrentSprite.status = 0;
    }
}

/**
 * 11280 | 48 | Checks if the current sprite is stunned
 * 
 * @return bool, stunned
 */
u8 SpriteUtilIsSpriteStunned(void)
{
    u8 isStunned;
    u8 stunTimer;

    isStunned = FALSE;

    // Get low threshold for which the sprite is no longer considered stunned
    if (gDifficulty == DIFF_EASY || gDifficulty == DIFF_NORMAL)
        stunTimer = CONVERT_SECONDS(.15f);
    else
        stunTimer = CONVERT_SECONDS(.24f);

    if (SPRITE_GET_ISFT(gCurrentSprite) > stunTimer && gCurrentSprite.pose < SPRITE_POSE_DESTROYED)
    {
        if (gCurrentSprite.animationDurationCounter != 0)
            APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);

        isStunned = TRUE;
    }

    return isStunned;
}

/**
 * 112c8 | 38 | Checks if a sprite should fall
 * 
 * @return bool, should fall
 */
u8 SpriteUtilShouldFall(void)
{
    // On screen and any screen shake active
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gScreenShakeY.timer != 0 || gScreenShakeX.timer != 0))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11300 | 30 | Updates the sub sprite data 1 timer field (used by chozo statues for the echo when sitting)
 * 
 */
void SpriteUtilUpdateSubSprite1Timer(void)
{
    u32 caf;
    u8 adc;
    u8 timer;

    gSubSpriteData1.workVariable2 = 0;

    adc = gSubSpriteData1.animationDurationCounter;
    APPLY_DELTA_TIME_INC(adc);
    caf = gSubSpriteData1.currentAnimationFrame;

    if (gSubSpriteData1.pMultiOam[caf].timer < adc)
    {
        timer = caf;
        gSubSpriteData1.workVariable2 = timer + 1;
    }
}

/**
 * @brief 11330 | 3c | Updates the sub sprite data 1 animation
 * 
 */
void SpriteUtilUpdateSubSprite1Anim(void)
{
    APPLY_DELTA_TIME_INC(gSubSpriteData1.animationDurationCounter);

    if (gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer < gSubSpriteData1.animationDurationCounter)
    {
        gSubSpriteData1.animationDurationCounter = DELTA_TIME;
        gSubSpriteData1.currentAnimationFrame++;
        
        if (gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer == 0)
            gSubSpriteData1.currentAnimationFrame = 0;
    }
}

/**
 * 1136c | 44 | Updates the current sprite position with the sub sprite data 1 position and the X/Y position of its OAM data
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void)
{
    MultiSpriteDataInfo_T pData;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam(void)
{
    MultiSpriteDataInfo_T pData;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 113b0 | 60 | Syncronises the current sprite position with the sub sprite 1 (X/Y coords and X/Y OAM offsets)
 * 
 */
void SpriteUtilUpdateSubSprite2Anim(void)
{
    APPLY_DELTA_TIME_INC(gSubSpriteData2.animationDurationCounter);

    if (gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].timer < gSubSpriteData2.animationDurationCounter)
    {
        gSubSpriteData2.animationDurationCounter = DELTA_TIME;
        gSubSpriteData2.currentAnimationFrame++;
        
        if (gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].timer == 0)
            gSubSpriteData2.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1144c | 60 | Syncronises the current sprite position with the sub sprite 2 (X/Y coords and X/Y OAM offsets)
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void)
{
    MultiSpriteDataInfo_T pData;

    pData = gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].pData;

    gCurrentSprite.yPosition = gSubSpriteData2.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 114ac | 38 | Updates the animation of a sub sprite data
 * 
 * @param pSub Sub sprite data pointer
 */
void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub)
{
    APPLY_DELTA_TIME_INC(pSub->animationDurationCounter);

    if (pSub->pMultiOam[pSub->currentAnimationFrame].timer < pSub->animationDurationCounter)
    {
        pSub->animationDurationCounter = DELTA_TIME;
        pSub->currentAnimationFrame++;

        if (pSub->pMultiOam[pSub->currentAnimationFrame].timer == 0)
            pSub->currentAnimationFrame = 0;
    }
}

/**
 * @brief 114e4 | 3c | Updates the current sprite position with the sub sprite data in parameter position and the X/Y position of its OAM data
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub)
{
    MultiSpriteDataInfo_T pData;

    pData = pSub->pMultiOam[pSub->currentAnimationFrame].pData;

    gCurrentSprite.yPosition = pSub->yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = pSub->xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 11520 | 5c | Syncronises the current sprite position with the sub sprite in parameter (X/Y coords and X/Y OAM offsets)
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam(struct SubSpriteData* pSub)
{
    MultiSpriteDataInfo_T pData;

    pData = pSub->pMultiOam[pSub->currentAnimationFrame].pData;

    gCurrentSprite.yPosition = pSub->yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = pSub->xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = pSub->xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 1157c | a4 | Checks if the current sprite is colliding with Samus visually (using the draw distances)
 * 
 * @return u8 bool, colliding
 */
u8 SpriteCheckCollidingWithSamusDrawing(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;

    samusTop = samusY + gSamusPhysics.drawDistanceTop;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottom;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, samusTop, samusBottom, samusLeft, samusRight))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11620 | ac | Sets a sprite splash particle effect depending on the parameters and the current hazard
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param size Splash Size
 */
void SpriteUtilSetSplashEffect(u16 yPosition, u16 xPosition, u8 size)
{
    switch (gCurrentAffectingClipdata.hazard)
    {
        case HAZARD_TYPE_WATER:
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_HUGE);
            break;

        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_STRONG_LAVA:
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_HUGE);
            break;
        
        case HAZARD_TYPE_ACID:            
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_HUGE);
            break;
    }
}

/**
 * 116cc | 4c | Checks if the sprite is out of the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return u8 bool, out of effect
 */
u32 SpriteUtilCheckOutOfRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size)
{
    if (oldY > gEffectYPosition && yPosition <= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
            SpriteUtilSetSplashEffect(yPosition, xPosition, size);
        }

        return TRUE;
    }

    return FALSE;
}

/**
 * 11718 | 4c | Checks if the sprite is in the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return u8 bool, in effect
 */
u32 SpriteUtilCheckInRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size)
{
    if (oldY < gEffectYPosition && yPosition >= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition(yPosition, xPosition);
            SpriteUtilSetSplashEffect(yPosition, xPosition, size);
        }

        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 1175c | 2c | Gets the current completion percentage
 * 
 * @return u32 Completion percentage
 */
u32 SpriteUtilGetFinalCompletionPercentage(void)
{
    u32 result;
    u8 energy;
    u8 missile;
    u8 superMissile;
    u8 powerBomb;
    u8 ability;
    u32 pen;

    pen = ChozodiaEscapeGetItemCountAndEndingNumber();

    energy = PEN_GET_ENERGY(pen);
    missile = PEN_GET_MISSILE(pen);
    superMissile = PEN_GET_SUPER_MISSILE(pen);
    powerBomb = PEN_GET_POWER_BOMB(pen);
    ability = PEN_GET_ABILITY(pen);

    result = energy + missile + superMissile + powerBomb + ability;

    return result;
}
