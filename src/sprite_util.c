#include "gba.h"
#include "oam.h"
#include "sprite_util.h"
#include "constants/particle.h"
#include "sprites_AI/parasite.h"
#include "sprites_AI/ridley.h"
#include "sprites_AI/acid_worm.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

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
    if (gfxSlot < 0x8)
    {
        gSpriteData[0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gSpriteData[0].properties = SP_ABSOLUTE_POSITION;
        gSpriteData[0].spritesetGfxSlot = gfxSlot;
        gSpriteData[0].spriteID = PSPRITE_AREA_BANNER;
        gSpriteData[0].yPosition = gSamusData.yPosition;
        gSpriteData[0].xPosition = gSamusData.xPosition;
        gSpriteData[0].bgPriority = 0x0;
        gSpriteData[0].drawOrder = 0x1;
        gSpriteData[0].pose = 0x0;
        gSpriteData[0].health = 0x0;
        gSpriteData[0].invincibilityStunFlashTimer = 0x0;
        gSpriteData[0].paletteRow = 0x0;
        gSpriteData[0].frozenPaletteRowOffset = 0x0;
        gSpriteData[0].absolutePaletteRow = 0x0;
        gSpriteData[0].ignoreSamusCollisionTimer = 0x1;
        gSpriteData[0].primarySpriteRamSlot = 0x0;
        gSpriteData[0].freezeTimer = 0x0;
        gSpriteData[0].standingOnSprite = FALSE;
    }
}

/**
 * @brief e514 | 90 | Checks if samus should stop when colliding with a solid sprite from the left
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 yPosition, u16 xPosition)
{
    u16 xPos;

    xPos = xPosition - gSamusPhysics.drawDistanceRightOffset;

    SpriteUtilCheckCollisionAtPosition(yPosition, xPos + gSamusPhysics.drawDistanceLeftOffset);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x40, xPos + gSamusPhysics.drawDistanceLeftOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR || SpriteUtilCheckMorphed())
        {
            gSamusData.xPosition = xPos;
            if (gSamusData.direction & KEY_RIGHT && gEquipment.currentEnergy != 0x0)
                gSamusData.xVelocity = 0x0;
        }
    }
}

/**
 * @brief e5a4 | 90 | Checks if samus should stop when colliding with a solid sprite from the right
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 yPosition, u16 xPosition)
{
    u16 xPos;

    xPos = xPosition - gSamusPhysics.drawDistanceLeftOffset;

    SpriteUtilCheckCollisionAtPosition(yPosition, xPos + gSamusPhysics.drawDistanceRightOffset);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x40, xPos + gSamusPhysics.drawDistanceRightOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR || SpriteUtilCheckMorphed())
        {
            gSamusData.xPosition = xPos + 0x1;
            if (gSamusData.direction & KEY_LEFT && gEquipment.currentEnergy != 0x0)
                gSamusData.xVelocity = 0x0;
        }
    }
}

/**
 * e634 | c4 | 
 * Calculates and applies the damage samus takes from a sprite
 * 
 * @param kbFlag 1 if getting knocked back, 0 otherwise
 * @param pSprite Sprite Data Pointer to the sprite hurting samus
 * @param dmgMultiplier Damage Multiplier
 * @return 1 if alive, 0 otherwise
 */
u8 SpriteUtilTakeDamageFromSprite(u8 kbFlag, struct SpriteData* pSprite, u16 dmgMultiplier)
{
    u16 damage;
    u16 flags;

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        damage = sSecondarySpriteStats[pSprite->spriteID][1]; // Get Damage
    else
        damage = sPrimarySpriteStats[pSprite->spriteID][1]; // Get Damage
    damage *= dmgMultiplier; // Apply multiplier

    // Apply changes based on the current suit
    flags = gEquipment.suitMiscActivation;
    if ((flags & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
        damage /= 0x2;
    else if (flags & SMF_GRAVITY_SUIT)
        damage = (damage * 0x7) / 0xA;
    else if (flags & SMF_VARIA_SUIT)
        damage = (damage * 0x8) / 0xA;

    // Apply changes based on difficuly
    if (gDifficulty == DIFF_EASY)
        damage /= 0x2;
    else if (gDifficulty == DIFF_HARD)
        damage *= 0x2;

    if (damage == 0x0)
        damage = 0x1;

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
        gEquipment.currentEnergy = 0x0;
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
 * @return u32 1 if touching, 0 otherwise
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
    // https://decomp.me/scratch/Bu0kh
    
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

    u16 verticalCollisionOffset;
    u16 horizontalCollisionOffset;
    u8 collisionFlags;

    pData = &gSamusData;
    dmgMultiplier = 0;

    samusY = pData->yPosition;
    samusX = pData->xPosition;
    previousX = gPreviousXPosition;

    samusTop = samusY + gSamusPhysics.drawDistanceTopOffset;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottomOffset;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    if (pData->pose == SPOSE_BALLSPARKING)
    {
        switch (pData->forcedMovement)
        {
            case FORCED_MOVEMENT_SIDEWARDS_SHINESPARK:
                samusTop -= HALF_BLOCK_SIZE;
                samusBottom += HALF_BLOCK_SIZE;
                break;
            
            case FORCED_MOVEMENT_UPWARDS_SHINESPARK:
                samusLeft -= HALF_BLOCK_SIZE;
                samusRight += HALF_BLOCK_SIZE;
                break;

            default:
                samusLeft -= 0x18;
                samusRight += 0x18;
                samusTop -= 0x18;
                samusBottom += 0x18;
        }
    }
    else if (pData->pose == SPOSE_SHINESPARKING)
    {
        switch (pData->forcedMovement)
        {
            case FORCED_MOVEMENT_UPWARDS_SHINESPARK:
                samusLeft -= HALF_BLOCK_SIZE;
                samusRight += HALF_BLOCK_SIZE;
        }
    }

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        status = pSprite->status;
        if ((status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN)) != (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN))
            continue;

        if (pSprite->ignoreSamusCollisionTimer != 0)
            continue;

        spriteY = pSprite->yPosition;
        spriteX = pSprite->xPosition;

        spriteTop = pSprite->yPosition + pSprite->hitboxTopOffset;
        spriteBottom = pSprite->yPosition + pSprite->hitboxBottomOffset;
        spriteLeft = pSprite->xPosition + pSprite->hitboxLeftOffset;
        spriteRight = pSprite->xPosition + pSprite->hitboxRightOffset;

        if (!SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, spriteTop, spriteBottom, spriteLeft, spriteRight))
            continue;

        gIgnoreSamusAndSpriteCollision = FALSE;

        verticalCollisionOffset = spriteTop + ((spriteBottom - spriteTop) / 2);
        horizontalCollisionOffset = ((spriteRight - spriteLeft) / 2) + spriteLeft;

        collisionFlags = SPRITE_COLLISION_FLAG_NONE;

        if (verticalCollisionOffset - 4 > samusBottom)
        {
            if (pData->yVelocity <= 24)
                collisionFlags = SPRITE_COLLISION_FLAG_ON_TOP;
        }

        if (verticalCollisionOffset + 4 < samusTop)
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_BOTTOM;

        if (horizontalCollisionOffset >= previousX)
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_LEFT;
        else
            collisionFlags |= SPRITE_COLLISION_FLAG_ON_RIGHT;

        if (pSprite->freezeTimer != 0)
        {
            if (!SpriteUtilCheckPullingSeftUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
            {
                if (SpriteUtilCheckOnZipline())
                    SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
                else
                {
                    if ((samusY - 0x18) < spriteTop)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + 1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 1)
                        {
                            pData->yPosition = spriteTop + 1;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = 0x2;
                        }
                    }
                    else if (samusTop + QUARTER_BLOCK_SIZE > spriteBottom)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTopOffset, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTopOffset;
                            if (pData->yVelocity > 0 && gEquipment.currentEnergy != 0)
                                pData->yVelocity = 0;
                        }
                    }
                    else if (samusX < spriteLeft || samusX > spriteRight)
                    {
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
                
                case SSC_IMAGO_EGG:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gIgnoreSamusAndSpriteCollision = TRUE;

                case SSC_SOLID:
                    if (!SpriteUtilCheckPullingSelfUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (samusY - 0x18 < spriteTop)
                        {
                            SpriteUtilCheckCollisionAtPosition(spriteTop + 1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                            {
                                pData->yPosition = spriteTop + 1;
                                pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                pSprite->standingOnSprite = 2;
                            }
                        }
                        else if (samusTop + 0x10 > spriteBottom)
                        {
                            SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTopOffset, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTopOffset;
                                if (pData->yVelocity > 0 && gEquipment.currentEnergy != 0)
                                    pData->yVelocity = 0;
                            }
                        }
                        else if (samusX < spriteLeft || samusX > spriteRight)
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                            else
                                SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);
                        }
                    }
                    break;

                case SSC_ESCAPE_SHIP:
                    if (!SpriteUtilCheckPullingSeftUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE && samusY - 0x18 < spriteTop)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + 1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0)
                        {
                            pData->yPosition = spriteTop + 1;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = 2;
                        }
                    }
                    break;

                case SSC_HURTS_SAMUS_CAN_STAND_ON_TOP:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (samusY - 0x18 < spriteTop)
                        {
                            if (!SpriteUtilCheckPullingSeftUp() && pData->invincibilityTimer < 40)
                            {
                                SpriteUtilCheckCollisionAtPosition(spriteTop + 1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 1)
                                {
                                    pData->yPosition = spriteTop + 1;
                                    pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                    pSprite->standingOnSprite = 2;
                                }
                            }
                        }
                        else
                        {
                            if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                            {
                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -BLOCK_SIZE;
                                else
                                    pData->xVelocity = BLOCK_SIZE;
                            }

                            pSprite->ignoreSamusCollisionTimer = 15;
                            gIgnoreSamusAndSpriteCollision = TRUE;
                        }
                    }
                    break;

                case SSC_KRAID_SPIKE:
                    if (samusX > spriteRight)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -BLOCK_SIZE;
                            else
                                pData->xVelocity = BLOCK_SIZE;
                        }
                        pSprite->ignoreSamusCollisionTimer = 0xF;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    else if (samusY - 0x18 < spriteTop && !SpriteUtilCheckPullingSeftUp() && pData->invincibilityTimer < 38)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteTop + 1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 1)
                        {
                            pData->yPosition = spriteTop + 1;
                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                            pSprite->standingOnSprite = 2;

                        }
                    }
                    break;

                case SSC_ABILITY_LASER_SEARCHLIGHT:
                case SSC_SMALL_ENERGY_DROP:
                case SSC_LARGE_ENERGY_DROP:
                case SSC_MISSILE_DROP:
                case SSC_SUPER_MISSILE_DROP:
                case SSC_POWER_BOMB_DROP:
                case SSC_MULTIPLE_LARGE_ENERGY_DROP:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_ACID_WORM_MOUTH:
                    if (pSprite->pose == ACID_WORM_POSE_EXTENDED || pSprite->pose == ACID_WORM_POSE_EXTENDING)
                    {
                        if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                        {
                            if ((u8)(pSprite->oamRotation - 0x21) <= 0x1E)
                            {
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                                    pData->xVelocity = -(BLOCK_SIZE + HALF_BLOCK_SIZE);

                                pSprite->ignoreSamusCollisionTimer = 15;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;
                            }
                        }
                        else
                        {
                            if ((u8)(pSprite->oamRotation + 0x3F) <= 0x1E)
                            {
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                                    pData->xVelocity = BLOCK_SIZE + HALF_BLOCK_SIZE;

                                pSprite->ignoreSamusCollisionTimer = 15;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;
                            }
                        }
                    }
                        
                case SSC_ACID_WORM:
                    if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                    {
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            pData->xVelocity = -BLOCK_SIZE;
                        else
                            pData->xVelocity = BLOCK_SIZE;
                    }

                    pSprite->ignoreSamusCollisionTimer = 15;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT:
                case SSC_SPACE_PIRATE_LASER:
                    pSprite->pose = 0x42;

                case SSC_HURTS_SAMUS:
                case SSC_MELLOW:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -BLOCK_SIZE;
                            else
                                pData->xVelocity = BLOCK_SIZE;
                        }

                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case 0xF:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -BLOCK_SIZE;
                            else
                                pData->xVelocity = BLOCK_SIZE;
                        }

                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_BIG_KNOCKBACK:
                    pSprite->pose = 0x42;

                case SSC_IMAGO_STINGER:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -(BLOCK_SIZE * 2);
                            else
                                pData->xVelocity = (BLOCK_SIZE * 2);
                        }

                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_ATOMIC_DISCHARGE:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 5))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -0x48;
                            else
                                pData->xVelocity = 0x48;
                        }
                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_SPACE_PIRATE:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1))
                        {
                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                pData->xVelocity = -BLOCK_SIZE;
                            else
                                pData->xVelocity = BLOCK_SIZE;
                        }

                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_HURTS_SAMUS_NO_KNOCKBACK:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    if (pData->invincibilityTimer < 8)
                    {
                        SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1);
                        if (gEquipment.currentEnergy != 0)
                            pData->invincibilityTimer = 8;
                    }
                    pSprite->ignoreSamusCollisionTimer = 15;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK:
                    pSprite->pose = 0x42;

                case SSC_HURTS_SAMUS_NO_KNOCKBACK_NO_CONTACT_DAMAGE:
                    SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1);
                    pSprite->ignoreSamusCollisionTimer = 15;

                    if (pData->invincibilityTimer == 0)
                        pData->invincibilityTimer = 8;

                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_ZIPLINE:
                    if (collisionFlags & SPRITE_COLLISION_FLAG_ON_BOTTOM)
                    {
                        switch (pData->pose)
                        {
                            case SPOSE_SPINNING:
                            case SPOSE_MIDAIR:
                                pData->yPosition = pSprite->yPosition + 0xA8;
                                pData->xPosition = pSprite->xPosition;

                                gPreviousYPosition = pData->yPosition;
                                gPreviousXPosition = pData->xPosition;

                                SamusSetPose(SPOSE_ON_ZIPLINE);
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                break;

                            case SPOSE_BALLSPARKING:
                                SoundStop(0x8F);
                            case SPOSE_MORPH_BALL_MIDAIR:
                                pData->yPosition = pSprite->yPosition + 0x3C;
                                pData->xPosition = pSprite->xPosition;

                                gPreviousYPosition = pData->yPosition;
                                gPreviousXPosition = pData->xPosition;

                                SamusSetPose(SPOSE_MORPH_BALL_ON_ZIPLINE);
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                break;
                        }
                    }
                    pSprite->ignoreSamusCollisionTimer = 15;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                case SSC_ZEBETITE:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(samusY, spriteLeft);
                        else
                            SpriteUtilCheckStopSamusAgainstSolidSpriteRight(samusY, spriteRight);
                    }
                    break;

                case SSC_HURTS_SAMUS_NO_PASS_THROUGH:
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
                                    pData->xVelocity = -BLOCK_SIZE;
                                else
                                    pData->xVelocity = BLOCK_SIZE;
                            }

                            gIgnoreSamusAndSpriteCollision = TRUE;
                        }
                    }
                    break;

                case SSC_KRAID:
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
                                    pData->xVelocity = -BLOCK_SIZE;
                                else
                                    pData->xVelocity = BLOCK_SIZE;
                            }
                        }
                        else if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            SpriteUtilCheckCollisionAtPosition(samusY + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                            if (gPreviousCollisionCheck == COLLISION_AIR)
                            {
                                SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                                if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                    pData->xVelocity = -BLOCK_SIZE;
                                else
                                    pData->xVelocity = BLOCK_SIZE;
                            }
                        }
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_KNOCKS_BACK_SAMUS:
                    if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                    {
                        SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                            pData->xVelocity = -(HALF_BLOCK_SIZE);
                        else
                            pData->xVelocity = (HALF_BLOCK_SIZE);

                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_BUG:
                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;

                    if (pData->invincibilityTimer == 0 && !(gEquipment.suitMiscActivation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)))
                    {
                        if (!ParasiteCount())
                            break;

                        if (SpriteUtilTakeDamageFromSprite(FALSE, pSprite, dmgMultiplier / 4))
                        {
                            pData->invincibilityTimer = 16;

                            SoundPlayNotAlreadyPlaying(0x80); // Bug leeching
                            gSubSpriteData1.workVariable2++;

                            if (!(gSubSpriteData1.workVariable2 & 3))
                                SoundPlay(0x7C); // Hurt
                        }
                    }

                    pSprite->ignoreSamusCollisionTimer = 15;
                    break;

                case SSC_METROID:
                    if (samusY > spriteY + HALF_BLOCK_SIZE)
                        pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;

                    if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 1))
                    {
                        dmgMultiplier = gEquipment.suitMiscActivation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT);
                        if (!dmgMultiplier)
                            pData->invincibilityTimer = 1;
                        else if (dmgMultiplier == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
                            pData->invincibilityTimer = 8;
                        else
                            pData->invincibilityTimer = 4;
                    }
                    break;

                case SSC_RIDLEY_CLAW:
                    if (collisionFlags & SPRITE_COLLISION_FLAG_ON_BOTTOM && RidleyCheckGrabbing(spriteY, spriteX))
                    {
                        pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                        pSprite->samusCollision = SSC_NONE;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                        SamusSetPose(SPOSE_MIDAIR);
                        SoundPlay(0x1E3);
                    }
                    else
                    {
                        if (pData->invincibilityTimer == 0 && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                            SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 1);

                        pSprite->ignoreSamusCollisionTimer = 15;
                        gIgnoreSamusAndSpriteCollision = TRUE;
                    }
                    break;

                case SSC_MECHA_RIDLEY:
                    if (SpriteUtilGetFinalCompletionPercentage() == 100)
                        dmgMultiplier = 2;
                    else
                        dmgMultiplier = 1;

                    if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, dmgMultiplier))
                        pData->xVelocity = -(BLOCK_SIZE * 2);

                    pSprite->ignoreSamusCollisionTimer = 15;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    break;

                default:
                    pSprite->ignoreSamusCollisionTimer = 15;
                    gIgnoreSamusAndSpriteCollision = TRUE;
                    
            }
        }

        if (gIgnoreSamusAndSpriteCollision)
            break;
    }

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->ignoreSamusCollisionTimer != 0)
            pSprite->ignoreSamusCollisionTimer--;
    }
}

/**
 * @brief 
 * Checks the collision at the given parameters and updates the gPreviousVerticalCollisionCheck global variable
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

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - 0x3f));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1) - 0x3F));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1) - 0x1F));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            gPreviousVerticalCollisionCheck = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1) + 0x1F); 
            gPreviousVerticalCollisionCheck = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1; 
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

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            blockY = (s16)((yPosition & 0xffc0) - ((xPosition & 0x3f) - 0x3f));
            collision = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & 0xFFC0) - (((xPosition & 0x3f) >> 0x1) - 0x3F));
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (s16)((yPosition & 0xFFC0) - (((xPosition & 0x3f) >> 0x1) - 0x1F));
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            blockY = (yPosition & 0xFFC0) | (xPosition & 0x3F);
            collision = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & 0xFFC0) | (((xPosition & 0x3f) >> 0x1) + 0x1F); 
            collision = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (yPosition & 0xFFC0) | (xPosition & 0x3f) >> 0x1; 
            collision = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;


        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;
            
        default:
            blockY = yPosition & 0xFFC0;
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

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 0x4, xPosition);
    if ((gPreviousVerticalCollisionCheck & (0x1 | COLLISION_LEFT_SLIGHT_FLOOR_SLOPE | COLLISION_LEFT_STEEP_FLOOR_SLOPE | 0x8)) > 0x1)
        gCurrentSprite.yPosition = blockTop;
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & (0x1 | COLLISION_LEFT_SLIGHT_FLOOR_SLOPE | COLLISION_LEFT_STEEP_FLOOR_SLOPE | 0x8)) > 0x1)
            gCurrentSprite.yPosition = blockTop;
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 0x4, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                gCurrentSprite.yPosition = blockTop;
        }
    }
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

    yPosition = gCurrentSprite.yPosition + gCurrentSprite.hitboxBottomOffset;
    xPosition = gCurrentSprite.xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 0x4, xPosition);
    if ((gPreviousVerticalCollisionCheck & (0x1 | COLLISION_LEFT_SLIGHT_FLOOR_SLOPE | COLLISION_LEFT_STEEP_FLOOR_SLOPE | 0x8)) > 0x1)
        gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottomOffset;
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & (0x1 | COLLISION_LEFT_SLIGHT_FLOOR_SLOPE | COLLISION_LEFT_STEEP_FLOOR_SLOPE | 0x8)) > 0x1)
            gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottomOffset;
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 0x4, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottomOffset;
        }
    }
}

/**
 * f688 | 98 | 
 * Checks the collision at the given parameters and updates the gPreviousCollisionCheck global variable
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
    
    switch (collision & 0xFF)
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
u32 SpriteUtilGetCollisionAtPosition(u32 yPosition, u32 xPosition)
{
    u32 clipdata;
    u32 collision;

    clipdata = ClipdataProcess(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        collision = COLLISION_SOLID;
    else
        collision = COLLISION_AIR;

    switch (clipdata & 0xFF)
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
        offset = gCurrentSprite.arrayOffset;
        movement = sSpritesFallingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 0x1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 0x1;
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
    if (gSpriteRng & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
}

/**
 * f844 | 3C | Chooses a random X direction for the current sprite
 * 
 */
void SpriteUtilChooseRandomXDirection(void)
{
    if (gSpriteRng & 0x1)
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
    if (gCurrentSprite.roomSlot & 0x1)
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
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
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
void SpriteUtilMakeSpriteFaceAwawFromSamusXFlip(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
}

/**
 * f944 | 34 | Makes the sprite face away from samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceAwawFromSamusDirection(void)
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
            velocity = (s16)(velocity * 2 / 3);
    }
    else
    {
        if (gPreviousCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
            velocity = (s16)(velocity * 2 / 3);
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
void unk_f9e7(s16 movement)
{
    s32 velocity;

    velocity = movement;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        if (gPreviousCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
            velocity = (s16)(velocity * 2 / 3);
        else if (gPreviousCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
            velocity = (s16)(velocity * 3 / 4);
    }
    else
    {
        if (gPreviousCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
            velocity = (s16)(velocity * 2 / 3);
        else if (gPreviousCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
            velocity = (s16)(velocity * 3 / 4);
    }

    if (velocity == 0)
        velocity = 1;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition += velocity;
    else
        gCurrentSprite.xPosition -= velocity;
}

/**
 * @brief fa78 | 150 | Calcultes the new oam rotation to rotate a sprite towards a target
 * 
 * @param oamRotation Current rotation
 * @param targetY Target Y
 * @param targetX Target X
 * @param spriteY Current Y
 * @param spriteX Current X
 * @return u8 New rotation
 */
u8 SpriteUtilMakeSpriteFaceSamusRotation(s32 oamRotation, s32 targetY, s32 targetX, s32 spriteY, s32 spriteX)
{
    s32 var_0;
    u16 var_1;
    s32 intensity;

    s32 rotation;
    s32 dstY;
    s32 dstX;
    s32 y;
    s32 x;
    
    rotation = (s16)oamRotation;
    dstY = (s16)targetY;
    dstX = (s16)targetX;
    y = (s16)spriteY;
    x = (s16)spriteX;

    intensity = 2;

    if (dstY < y)
    {
        if (x - BLOCK_SIZE < dstX && x + BLOCK_SIZE > dstX)
        {
            var_0 = BLOCK_SIZE * 3;
        }
        else if (dstX > x)
        {
            if (y - dstY < BLOCK_SIZE)
                var_0 = 0;
            else
                var_0 = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
        }
        else if (y - dstY < BLOCK_SIZE)
        {
            var_0 = BLOCK_SIZE * 2;
        }
        else
        {
            var_0 = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
        }
    }
    else
    {
        if (x - BLOCK_SIZE < dstX && x + BLOCK_SIZE > dstX)
        {
            var_0 = BLOCK_SIZE;
        }
        else if (dstX > x)
        {
            if (dstY - y < BLOCK_SIZE)
                var_0 = 0;
            else
                var_0 = HALF_BLOCK_SIZE;
        }
        else if (dstY - y < BLOCK_SIZE)
        {
            var_0 = BLOCK_SIZE * 2;
        }
        else
        {
            var_0 = BLOCK_SIZE * 1 + HALF_BLOCK_SIZE;
        }
    }

    if (var_0 == 0)
    {
        if ((u16)(rotation - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
        else if (rotation >+ BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
    }
    else if (var_0 == HALF_BLOCK_SIZE)
    {
        if ((u16)(rotation - HALF_BLOCK_SIZE - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
        else if ((u16)(rotation - HALF_BLOCK_SIZE) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
    }
    else if (var_0 == BLOCK_SIZE)
    {
        if ((u16)(rotation - BLOCK_SIZE - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
        else if ((u16)(rotation - BLOCK_SIZE) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
    }
    else if (var_0 == BLOCK_SIZE + HALF_BLOCK_SIZE)
    {
        if ((u16)(rotation - (BLOCK_SIZE + HALF_BLOCK_SIZE) - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
        else if ((u16)(rotation - (BLOCK_SIZE + HALF_BLOCK_SIZE)) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
    }
    else if (var_0 == BLOCK_SIZE * 2)
    {
        if ((u16)(rotation - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
        else if (rotation > BLOCK_SIZE * 2)
            rotation = (s16)(rotation - intensity);
    }
    else if (var_0 == BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
    {
        if ((u16)(rotation - HALF_BLOCK_SIZE - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
        else if ((u16)(rotation - HALF_BLOCK_SIZE - 1) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
    }
    else if (var_0 == BLOCK_SIZE * 3)
    {
        if ((u16)(rotation - BLOCK_SIZE - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
        else if ((u16)(rotation - BLOCK_SIZE - 1) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
    }
    else if (var_0 == BLOCK_SIZE * 3 + HALF_BLOCK_SIZE)
    {
        if ((u16)(rotation - (BLOCK_SIZE + HALF_BLOCK_SIZE) - 1) < BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation + intensity);
        else if ((u16)(rotation - (BLOCK_SIZE + HALF_BLOCK_SIZE) - 1) > BLOCK_SIZE * 2 - 1)
            rotation = (s16)(rotation - intensity);
    }

    return rotation;
}

u32 SpriteUtilCheckEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 caf;

    adc = gCurrentSprite.animationDurationCounter;
    caf = gCurrentSprite.currentAnimationFrame;
   
    adc++;

    if (gCurrentSprite.pOam[caf].timer < adc && gCurrentSprite.pOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fc00 | 3c | Checks if the animation of the current sprite has nearly ended
 * 
 * @return u32 1 if nearly ended, 0 otherwise
 */
u32 SpriteUtilCheckNearEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 caf;

    adc = gCurrentSprite.animationDurationCounter;
    caf = gCurrentSprite.currentAnimationFrame;
    
    adc++;
    adc++;
    
    if (gCurrentSprite.pOam[caf].timer < adc && gCurrentSprite.pOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSpriteAnim(u8 ramSlot)
{
    u8 adc;
    u16 caf;

    adc = gSpriteData[ramSlot].animationDurationCounter;
    caf = gSpriteData[ramSlot].currentAnimationFrame;
    
    adc++;

    if (gSpriteData[ramSlot].pOam[caf].timer < adc && gSpriteData[ramSlot].pOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fc84 | 4c | Checks if the animation of a sprite has nearly ended
 * 
 * @param ramSlot Sprite RAM slot
 * @return u8 1 if nearly ended, 0 otherwise
 */
u8 SpriteUtilCheckNearEndSpriteAnim(u8 ramSlot)
{
    u8 adc;
    u16 caf;

    adc = gSpriteData[ramSlot].animationDurationCounter;
    caf = gSpriteData[ramSlot].currentAnimationFrame;
    
    adc++;
    adc++;
    
    if (gSpriteData[ramSlot].pOam[caf].timer < adc && gSpriteData[ramSlot].pOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSubSprite1Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData1.animationDurationCounter;
    caf = gSubSpriteData1.currentAnimationFrame;
    adc++;

    if (gSubSpriteData1.pMultiOam[caf].timer < adc && gSubSpriteData1.pMultiOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fd08 | 3c | Checks if the animation of the sub sprite data 1 has nearly ended
 * 
 * @return u32 1 if nearly ended, 0 otherwise
 */
u8 SpriteUtilCheckNearEndSubSprite1Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData1.animationDurationCounter;
    caf = gSubSpriteData1.currentAnimationFrame;

    adc++;
    adc++;

    if (gSubSpriteData1.pMultiOam[caf].timer < adc && gSubSpriteData1.pMultiOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSubSprite2Anim(void)
{
    u8 adc;
    u16 caf;

    adc = gSubSpriteData2.animationDurationCounter;
    caf = gSubSpriteData2.currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSubSpriteData2.pMultiOam[caf].timer < adc && (u8)gSubSpriteData2.pMultiOam[(u16)(caf + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub)
{
    u8 adc;
    u16 caf;

    adc = pSub->animationDurationCounter;
    caf = pSub->currentAnimationFrame;
    adc++;

    if (pSub->pMultiOam[caf].timer < adc && (u8)pSub->pMultiOam[++caf].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief fdac | 34 | Checks if the animation of a sub sprite data has nearly ended
 * 
 * @param pSub Sub Sprite Data Pointer
 * @return u32 1 if nearly ended, 0 otherwise
 */
u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub)
{
    u8 adc;
    u16 caf;

    adc = pSub->animationDurationCounter;
    caf = pSub->currentAnimationFrame;
    adc++;
    adc++;

    if (pSub->pMultiOam[caf].timer < adc && (u8)pSub->pMultiOam[++caf].timer == 0x0)
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
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
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
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
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
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
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
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
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
    u8 standing;

    if (pSprite->status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        if (gSamusData.standingStatus != STANDING_ENEMY)
        {
            if (gSamusData.standingStatus == STANDING_MIDAIR)
                SamusSetPose(SPOSE_LANDING_REQUEST);

            gSamusData.standingStatus = STANDING_ENEMY;
        }

        pSprite->status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
        return;
    }

    standing = pSprite->standingOnSprite;
    if (standing != 0x1)
    {            
        if (standing == 0x2)
        {
            pSprite->standingOnSprite = TRUE;
            if (gSamusDataCopy.yPosition <= gSamusData.yPosition)
                gSamusData.yPosition = pSprite->yPosition + pSprite->hitboxTopOffset + 1;
        }
    }
    else
    {
        pSprite->standingOnSprite = FALSE;
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
    u8 timer;

    if (gFrameCounter8Bit & 0x1)
        gCurrentSprite.freezeTimer--;

    timer = gCurrentSprite.freezeTimer;
    if (!timer)
        gCurrentSprite.animationDurationCounter--;

    if (timer < 0x2E)
    {
        if (timer & 0x1)
            gCurrentSprite.paletteRow = 0xF - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilUnfreezeAnimEasy(void)
{
    u8 freezeTimer;

    gCurrentSprite.freezeTimer--;

    freezeTimer = gCurrentSprite.freezeTimer;
    if (freezeTimer == 0)
        gCurrentSprite.animationDurationCounter--;
    if (freezeTimer < 0x5B && !(freezeTimer & 1))
    {
        if (freezeTimer & 2)
            gCurrentSprite.paletteRow = 15 - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilMetroidUnfreezeAnim(void)
{
    u8 freezeTimer;

    gCurrentSprite.freezeTimer -= 2;

    freezeTimer = gCurrentSprite.freezeTimer;
    if (freezeTimer == 0)
        gCurrentSprite.animationDurationCounter--;
    if (freezeTimer < 121 && !(freezeTimer & 2))
    {
        if (freezeTimer & 4)
            gCurrentSprite.paletteRow = 15 - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 spriteID, u8 ramSlot)
{
    u8 count;

    if (gCurrentSprite.freezeTimer != 0x0)
    {
        count = 0x0;
        while (count < 0x18)
        {
            if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
                && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
                && gSpriteData[count].spriteID == spriteID
                && gSpriteData[count].primarySpriteRamSlot == ramSlot
                && gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer
                && (gSpriteData[count].properties & SP_DESTROYED) == 0x0)
            {
                gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
                gSpriteData[count].paletteRow = 0xF - (gSpriteData[count].spritesetGfxSlot + gSpriteData[count].frozenPaletteRowOffset);
            }
            count++;
        }
    }
}

void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void)
{
    if (gCurrentSprite.freezeTimer != 0) {
        u8 count = gCurrentSprite.primarySpriteRamSlot;
        if (gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer && (gSpriteData[count].properties & SP_DESTROYED) == 0)
        {
            gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
            gSpriteData[count].paletteRow = 0xf - (gSpriteData[count].spritesetGfxSlot + gSpriteData[count].frozenPaletteRowOffset);
        } 
    }
}

void SpriteUtilUnfreezeSecondarySprites(u8 spriteID, u8 ramSlot)
{
    u8 count = 0;
    do
    {
        if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
            && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
            && gSpriteData[count].spriteID == spriteID
            && gSpriteData[count].primarySpriteRamSlot == ramSlot
            && gSpriteData[count].freezeTimer != 0x0)
        {
            gSpriteData[count].freezeTimer = 0x0;
            gSpriteData[count].paletteRow = 0x0;
        }
        count++;
    }
    while (count < 0x18);
}

/**
 * @brief 1025c | 44 | Gradual refill of samus' energy
 * 
 * @return u8 1 if didn't end, 0 otherwise
 */
u8 SpriteUtilRefillEnergy(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentEnergy;

    if (gEquipment.currentEnergy < gEquipment.maxEnergy)
    {
        current = (gEquipment.maxEnergy - gEquipment.currentEnergy);
        current >>= 0x5;
        if (current == 0x0)
            current = 0x1;
        else if (current > 0xA)
            current = 0xB;

        gEquipment.currentEnergy += current;
        if (gEquipment.currentEnergy > gEquipment.maxEnergy)
            gEquipment.currentEnergy = gEquipment.maxEnergy;
        
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * @brief 102a0 | 44 | Gradual refill of samus' missiles
 * 
 * @return u8 1 if didn't end, 0 otherwise
 */
u8 SpriteUtilRefillMissiles(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentMissiles;

    if (gEquipment.currentMissiles < gEquipment.maxMissiles)
    {
        current = (gEquipment.maxMissiles - gEquipment.currentMissiles);
        current >>= 0x5;
        if (current == 0x0)
            current = 0x1;
        else if (current > 0x5)
            current = 0x6;

        gEquipment.currentMissiles += current;
        if (gEquipment.currentMissiles > gEquipment.maxMissiles)
            gEquipment.currentMissiles = gEquipment.maxMissiles;
        
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * @brief 102ea | 44 | Gradual refill of samus' super missiles
 * 
 * @return u8 1 if didn't end, 0 otherwise
 */
u8 SpriteUtilRefillSuperMissiles(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentSuperMissiles;
    max = gEquipment.maxSuperMissiles;

    if (gEquipment.currentSuperMissiles < max)
    {
        current = (max - gEquipment.currentSuperMissiles);
        current >>= 0x4;
        if (current == 0x0)
            current = 0x1;
        else if (current > 0x3)
            current = 0x4;

        gEquipment.currentSuperMissiles += current;
        if (gEquipment.currentSuperMissiles > gEquipment.maxSuperMissiles)
            gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;
        
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * @brief 10328 | 44 | Gradual refill of samus' power bombs
 * 
 * @return u8 1 if didn't end, 0 otherwise
 */
u8 SpriteUtilRefillPowerBombs(void)
{
    u16 current;
    u16 max;

    current = gEquipment.currentPowerBombs;
    max = gEquipment.maxPowerBombs;

    if (gEquipment.currentPowerBombs < max)
    {
        current = (max - gEquipment.currentPowerBombs);
        current >>= 0x4;
        if (current == 0x0)
            current = 0x1;
        else if (current > 0x3)
            current = 0x4;

        gEquipment.currentPowerBombs += current;
        if (gEquipment.currentPowerBombs > gEquipment.maxPowerBombs)
            gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;
        
        return TRUE;
    }
    else
        return FALSE;
}

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

u32 SpriteUtilCheckStopSpritesPose(void)
{
    if (gPreventMovementTimer == 0x0)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_FACING_THE_FOREGROUND:
                return TRUE;
        }
    }
    else
        return TRUE;
    
    return FALSE;
}

/**
 * 104f8 | 1b0 | 
 * Handles a sprite taking damage from a contact with samus
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param pData Samus Data Pointer
 * @return The damage contact type
 */
u32 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData)
{
    u8 dct;
    u8* pProps;
    struct Equipment* pEquipment;
    u16 weakness;
    u16 bbf;
    u16 damage;
    u8 isDead;
    u8 isft;

    dct = DCT_NONE;
    if (gEquipment.suitType == SUIT_SUITLESS)
        return DCT_NONE;

    pProps = &pSprite->properties;
    if (pSprite->properties & (SP_SOLID_FOR_PROJECTILES | SP_IMMUNE_TO_PROJECTILES))
        return DCT_NONE;

    if (pSprite->status & SPRITE_STATUS_IGNORE_PROJECTILES)
        return DCT_NONE;

    if (pData->speedboostingShinesparking != FALSE)
    {
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
                dct = DCT_SCREW_ATTACK;
                break;
            
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_STARTING_WALL_JUMP:
            case SPOSE_SPACE_JUMPING:
                if (0x3F < gSamusWeaponInfo.chargeCounter)
                    dct = DCT_SUDO_SCREW;
            
            default:
                if (dct == DCT_NONE)
                    return DCT_NONE;
        }
    }

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        weakness = sSecondarySpriteStats[pSprite->spriteID][2];
    else if ((pSprite->properties & SP_SECONDARY_SPRITE) == 0x0)
        weakness = sPrimarySpriteStats[pSprite->spriteID][2];

    if (dct >= DCT_SUDO_SCREW)
    {
        if (weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS))
        {
            gSamusWeaponInfo.chargeCounter = 0x0;
            damage = 0x2;
            bbf = gEquipment.beamBombsActivation;
            if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                damage++;
            if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                damage++;
            if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
                damage++;
            if (bbf & BBF_PLASMA_BEAM)
                damage++;

            damage *= 4;
            isDead = ProjectileDealDamage(pSprite, damage);
            if (isDead)
            {
                pSprite->pose = 0x66;
                return dct;
            }
            pSprite->ignoreSamusCollisionTimer = 0x0;
            dct = DCT_NONE;
        }
    }
    else
    {
        if (weakness & WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK)
        {
            pSprite->health = 0x0;
            pSprite->properties |= SP_DESTROYED;
            pSprite->freezeTimer = 0x0;
            pSprite->paletteRow = 0x0;
            if (pSprite->standingOnSprite && pData->standingStatus == STANDING_ENEMY)
            {
                pData->standingStatus = STANDING_MIDAIR;
                pSprite->standingOnSprite = FALSE;
            }

            if (dct == DCT_SHINESPARK)
                pSprite->pose = 0x63;
            else if (dct == DCT_SPEEDBOOSTER)
                pSprite->pose = 0x64;
            else
                pSprite->pose = 0x65;

            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->invincibilityStunFlashTimer = pSprite->invincibilityStunFlashTimer & 0x80 | 0x11;
            pSprite->properties |= SP_DAMAGED;
            return dct;
        }

        isft = 0x3;
        if ((pSprite->invincibilityStunFlashTimer & 0x7F) < isft)
            pSprite->invincibilityStunFlashTimer = pSprite->invincibilityStunFlashTimer & 0x80 | 0x3;
        dct = DCT_NONE;
    }

    return dct;
}

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
 * @param spriteID Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountPrimarySprites(u8 spriteID)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteID == spriteID)
            count++;
    }

    return count;
}

/**
 * @brief 10738 | 60 | Counts the number of secondary sprites the current sprite ram slot
 * 
 * @param spriteID Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->properties & SP_SECONDARY_SPRITE &&
            pSprite->spriteID == spriteID && pSprite->primarySpriteRamSlot == ramSlot)
            count++;
    }

    return count;
}

/**
 * @brief 10798 | 60 | Counts the number of primary sprites the current sprite ram slot
 * 
 * @param spriteID Sprite ID
 * @return u8 Count
 */
u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) &&
            pSprite->spriteID == spriteID && pSprite->primarySpriteRamSlot == ramSlot)
            count++;
    }

    return count;
}

/**
 * @brief 107f8 | 58 | Finds the ram slot of a primary sprite
 * 
 * @param spriteID Sprite ID
 * @return u8 Ram slot
 */
u8 SpriteUtilFindPrimary(u8 spriteID)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteID == spriteID)
            return ramSlot;

        ramSlot++;
    }

    return UCHAR_MAX;
}

/**
 * @brief 10850 | 60 | Finds the ram slot of a secondary sprite
 * 
 * @param spriteID Sprite ID
 * @param roomSlot Room slot/part number
 * @return u8 Ram slot
 */
u8 SpriteUtilFindSecondaryWithRoomSlot(u8 spriteID, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->properties & SP_SECONDARY_SPRITE &&
            pSprite->spriteID == spriteID && pSprite->roomSlot == roomSlot)
            return ramSlot;

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
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;

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
    struct SpriteData* pSprite;

    count = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
    }

    return count;
}

void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{
    // https://decomp.me/scratch/6NT7r
    
    u32 flip;
    u16 speed;
    u32 newPos;

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.xPosition > samusX - 4)
            {
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                if (gCurrentSprite.workVariable2 < xSpeed)
                    gCurrentSprite.workVariable2++;

                gCurrentSprite.xPosition += (gCurrentSprite.workVariable2 >> speedDivisor);
            }
        }
        else
        {
            gCurrentSprite.workVariable--;
            if (gCurrentSprite.workVariable != 0)
            {
                gCurrentSprite.xPosition += (gCurrentSprite.workVariable >> speedDivisor);
            }
            else
                flip++;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.xPosition < samusX + 4)
            {
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                if (gCurrentSprite.workVariable2 < xSpeed)
                    gCurrentSprite.workVariable2++;

                speed = gCurrentSprite.workVariable2 >> speedDivisor;
                newPos = gCurrentSprite.xPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.workVariable = 0;
                }
                else
                {
                    gCurrentSprite.xPosition = newPos;
                }
            }
        }
        else
        {
            gCurrentSprite.workVariable--;
            if (gCurrentSprite.workVariable != 0)
            {
                speed = gCurrentSprite.workVariable >> speedDivisor;
                newPos = gCurrentSprite.xPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.workVariable = 0;
                }
                else
                {
                    gCurrentSprite.xPosition = newPos;
                }
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.workVariable2 = 1;
    }

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.timer == 0)
        {
            if (gCurrentSprite.yPosition > samusY - 4)
            {
                gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            }
            else
            {
                if (gCurrentSprite.arrayOffset < ySpeed)
                    gCurrentSprite.arrayOffset++;

                gCurrentSprite.yPosition += (gCurrentSprite.arrayOffset >> speedDivisor);
            }
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer != 0)
            {
                gCurrentSprite.yPosition += (gCurrentSprite.timer >> speedDivisor);
            }
            else
                flip++;
        }
    }
    else
    {
        if (gCurrentSprite.timer == 0)
        {
            if (gCurrentSprite.yPosition < samusY + 4)
            {
                gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            }
            else
            {
                if (gCurrentSprite.arrayOffset < ySpeed)
                    gCurrentSprite.arrayOffset++;

                speed = gCurrentSprite.arrayOffset >> speedDivisor;
                newPos = gCurrentSprite.yPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.timer = 0;
                }
                else
                {
                    gCurrentSprite.yPosition = newPos;
                }
            }
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer != 0)
            {
                speed = gCurrentSprite.timer >> speedDivisor;
                newPos = gCurrentSprite.yPosition - speed;
                if (newPos & 0x8000)
                {
                    flip++;
                    gCurrentSprite.timer = 0;
                }
                else
                {
                    gCurrentSprite.yPosition = newPos;
                }
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        gCurrentSprite.arrayOffset = 1;
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
        if (gCurrentSprite.workVariable2 < xSpeed)
            gCurrentSprite.workVariable2++;

        gCurrentSprite.xPosition += gCurrentSprite.workVariable2 >> speedDivisor;
    }
    else
    {
        if (gCurrentSprite.workVariable2 < xSpeed)
            gCurrentSprite.workVariable2++;

        gCurrentSprite.xPosition -= gCurrentSprite.workVariable2 >> speedDivisor;
    }

    flip = FALSE;
    
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.timer == 0)
        {
            updatePos = FALSE;
            if (gCurrentSprite.arrayOffset < ySpeed)
            {
                if (gCurrentSprite.yPosition <= dstY - 4)
                {
                    gCurrentSprite.arrayOffset++;
                    updatePos = TRUE;
                }
                else
                {
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                    updatePos = FALSE;
                }
            }
            else
            {
                updatePos = TRUE;
            }

            if (updatePos)
                gCurrentSprite.yPosition += (gCurrentSprite.arrayOffset >> speedDivisor);
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                flip = TRUE;
            }
            else
                gCurrentSprite.yPosition += (gCurrentSprite.timer >> speedDivisor);
        }
    }
    else
    {
         if (gCurrentSprite.timer == 0)
        {
            updatePos = FALSE;
            if (gCurrentSprite.arrayOffset < ySpeed)
            {
                if (gCurrentSprite.yPosition >= dstY + 4)
                {
                    gCurrentSprite.arrayOffset++;
                    updatePos = TRUE;
                }
                else
                {
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                    updatePos = FALSE;
                }
            }
            else
            {
                updatePos = TRUE;
            }
            
            if (updatePos)
                gCurrentSprite.yPosition -= (gCurrentSprite.arrayOffset >> speedDivisor);
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer != 0)
            {
                speed = gCurrentSprite.timer >> speedDivisor;
                if ((gCurrentSprite.yPosition - speed) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.timer = 0;
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
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        gCurrentSprite.arrayOffset = 1;
    }
}

/**
 * 10cf0 | 78 | 
 * Updates the stun timer of the sprite
 * 
 * @param pSprite Sprite Data Pointer
 */
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->invincibilityStunFlashTimer & 0x7F)
    {
        isft = pSprite->invincibilityStunFlashTimer = pSprite->invincibilityStunFlashTimer - 0x1;
        if (!(isft & 0x3))
        {
            if (isft & 0x4)
            {
                if (pSprite->health != 0x0)
                    pSprite->paletteRow = 0xE - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset);
            }
            else
            {
                if (pSprite->health != 0x0)
                {
                    if (pSprite->freezeTimer != 0x0)
                        pSprite->paletteRow = 0xF - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset);
                    else
                        pSprite->paletteRow = pSprite->absolutePaletteRow;
                }
            }
        }
    }
}

/**
 * 10d68 | 126 | 
 * Spawns a set of random sprite debris depending on the parameters
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
        case 0x1:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
                SpriteDebrisInit(cloudType, 0x1, yPosition + 0x8, xPosition - 0x8);
            else
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x8, xPosition + 0x8);
            break;
        case 0x2:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloudType, 0x1, yPosition - 0x8, xPosition - 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition, xPosition + 0x8);
            }
            else
            {
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x8, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x8, xPosition - 0x8);
            }
            break;
        case 0x3:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x10, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition + 0x8, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x10, xPosition - 0x8);
            }
            else
            {
                SpriteDebrisInit(cloudType, 0x1, yPosition - 0x8, xPosition - 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition - 0x10, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x8, xPosition - 0x8);
            }
    }
}

u8 SpriteUtilGetAmmoDrop(u8 rng)
{
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
    {
        if (rng & 0x1 && gEquipment.maxMissiles > gEquipment.currentMissiles)
            return PSPRITE_MISSILE_DROP;
        if (rng & 0x2 && gEquipment.maxSuperMissiles > gEquipment.currentSuperMissiles)
            return PSPRITE_SUPER_MISSILE_DROP;
        if (rng & 0x4 && gEquipment.maxPowerBombs > gEquipment.currentPowerBombs)
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
    u8 spriteID;

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
    rng = rng * 64;
    rng = rng / 64;

    if (rng == 0)
        rng = 1;

    spriteID = gCurrentSprite.spriteID;

    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        smallEnergyProb = sSecondarySpriteStats[spriteID][4];
        largeEnergyProb = sSecondarySpriteStats[spriteID][5];
        missileProb = sSecondarySpriteStats[spriteID][6];
        superProb = sSecondarySpriteStats[spriteID][7];
        powerProb = sSecondarySpriteStats[spriteID][8];
    }
    else
    {
        smallEnergyProb = sPrimarySpriteStats[spriteID][4];
        largeEnergyProb = sPrimarySpriteStats[spriteID][5];
        missileProb = sPrimarySpriteStats[spriteID][6];
        superProb = sPrimarySpriteStats[spriteID][7];
        powerProb = sPrimarySpriteStats[spriteID][8];
    }

    if (powerProb != 0)
    {
        powerProb = 0x400 - powerProb;

        if (rng <= 0x400 && rng > powerProb)
        {
            if (gEquipment.maxPowerBombs > gEquipment.currentPowerBombs)
            {
                drop = PSPRITE_POWER_BOMB_DROP;
            }
            else
            {
                if (fullLife)
                {
                    if (gEquipment.maxPowerBombs != 0)
                        drop = PSPRITE_POWER_BOMB_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }

            return drop;
        }
    }
    else
    {
        powerProb = 0x400;
    }

    if (superProb != 0)
    {
        superProb = powerProb - superProb;

        if (powerProb >= rng && rng > superProb)
        {
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
                    drop = PSPRITE_LARGE_ENERGY_DROP;
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
                    drop = PSPRITE_LARGE_ENERGY_DROP;
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

        if (missileProb >= rng  && rng > largeEnergyProb)
        {
            drop = PSPRITE_LARGE_ENERGY_DROP;
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

        if (largeEnergyProb >= rng  && rng > smallEnergyProb)
        {
            drop = PSPRITE_SMALL_ENERGY_DROP;
            if (fullLife && gEquipment.maxMissiles > gEquipment.currentMissiles)
                drop = PSPRITE_MISSILE_DROP;

            return drop;
        }
    }

    return drop;
}

/**
 * 11084 | 1fc | 
 * Handles the death of a sprite, replaces it with a drop if necessary
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
        case 0x63: // Check for damage contact
            ParticleSet(yPosition, xPosition, PE_SHINESPARK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x131);
            break;
        case 0x64:
            ParticleSet(yPosition, xPosition, PE_SPEEDBOOSTER_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x133);
            break;
        case 0x65:
            ParticleSet(yPosition, xPosition, PE_SCREW_ATTACK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x130);
            break;
        case 0x66:
            ParticleSet(yPosition, xPosition, PE_SUDO_SCREW_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x132);
            break;
        default: // Check play sprite explosion effects
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (playSound)
                    SoundPlay(0x12C);
            }
            else if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                if (playSound)
                    SoundPlay(0x12D);
            }
            else if (effect == PE_SPRITE_EXPLOSION_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_BIG);
                if (playSound)
                    SoundPlay(0x12E);
            }
            else if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                if (playSound)
                    SoundPlay(0x12F);
            }
            else if ((u8)(effect - 0x27) < 0x3) // Default behavior
                ParticleSet(yPosition, xPosition, effect);
    }

    drop = SpriteUtilDetermineEnemyDrop();
    if (drop != 0x0)
    {       
        if (deathType != DEATH_NORMAL)
        {
            if (deathType != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
                SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0x0);
        }
        else
        {
            // Init data for drop
            gCurrentSprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            gCurrentSprite.properties = 0x0;
            gCurrentSprite.spritesetGfxSlot = 0x0;
            gCurrentSprite.spriteID = drop;
            gCurrentSprite.yPosition = yPosition;
            gCurrentSprite.xPosition = xPosition;
            gCurrentSprite.bgPriority = 0x2;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = 0x0;
            gCurrentSprite.health = 0x0;
            gCurrentSprite.invincibilityStunFlashTimer = 0x0;
            gCurrentSprite.paletteRow = 0x0;
            gCurrentSprite.frozenPaletteRowOffset = 0x0;
            gCurrentSprite.absolutePaletteRow = 0x0;
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            gCurrentSprite.freezeTimer = 0x0;
        }
    }
    else
    {
        if (deathType == DEATH_NORMAL)
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 11280 | 48 | 
 * Checks if the current sprite is stunned
 * 
 * @return 1 if stunned, 0 otherwise
 */
u8 SpriteUtilIsSpriteStunned(void)
{
    u8 isStunned;
    u8 stunTimer;
    u8 diff;

    isStunned = FALSE;
    diff = gDifficulty;
    
    stunTimer = 0xE;
    if (diff < DIFF_HARD)
        stunTimer = 0x9;

    if (((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) > stunTimer) && gCurrentSprite.pose < 0x62)
    {
        if (gCurrentSprite.animationDurationCounter != 0x0)
            gCurrentSprite.animationDurationCounter--;
        isStunned = TRUE;
    }

    return isStunned;
}

/**
 * 112c8 | 38 | 
 * Checks if a sprite is on screen with a screen shake occuring
 * 
 * @return 1 if conditions met, 0 otherwise
 */
u8 SpriteUtilIsSpriteOnScreenAndScreenShake(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gScreenShakeY.timer != 0x0 || gScreenShakeX.timer != 0x0))
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
    u32 adc;
    u8 timer;

    gSubSpriteData1.workVariable2 = 0x0;
    adc = (u8)(gSubSpriteData1.animationDurationCounter + 0x1);
    caf = gSubSpriteData1.currentAnimationFrame;

    if (gSubSpriteData1.pMultiOam[caf].timer < adc)
    {
        timer = (u8)caf;
        gSubSpriteData1.workVariable2 = timer + 0x1;
    }
}

void SpriteUtilUpdateSubSprite1Anim(void)
{
    u32 adc;

    adc = gSubSpriteData1.animationDurationCounter + 0x1;
    gSubSpriteData1.animationDurationCounter = adc;
    if ((u8)gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer < (u8)adc)
    {
        gSubSpriteData1.animationDurationCounter = 0x1;
        gSubSpriteData1.currentAnimationFrame++;
        if ((u8)gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer == 0x0)
            gSubSpriteData1.currentAnimationFrame = 0x0;
    }
}

/**
 * 1136c | 44 | Updates the current sprite position with the sub sprite data 1 position and the X/Y position of its OAM data
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void)
{
    const u16* pOam;

    pOam = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM(void)
{
    const u16* pOam;

    pOam = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

/**
 * @brief 113b0 | 60 | Syncronises the current sprite position with the sub sprite 1 (X/Y coords and X/Y OAM offsets)
 * 
 */
void SpriteUtilUpdateSubSprite2Anim(void)
{
    u32 adc;

    adc = gSubSpriteData2.animationDurationCounter + 0x1;
    gSubSpriteData2.animationDurationCounter = adc;
    if ((u8)gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].timer < (u8)adc)
    {
        gSubSpriteData2.animationDurationCounter = 0x1;
        gSubSpriteData2.currentAnimationFrame++;
        if ((u8)gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].timer == 0x0)
            gSubSpriteData2.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 1144c | 60 | Syncronises the current sprite position with the sub sprite 2 (X/Y coords and X/Y OAM offsets)
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void)
{
    const u16* pOam;

    pOam = gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].pFrame;

    gCurrentSprite.yPosition = gSubSpriteData2.yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition - pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
    else
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub)
{
    u32 adc;

    adc = pSub->animationDurationCounter + 0x1;
    pSub->animationDurationCounter = adc;
    if ((u8)pSub->pMultiOam[pSub->currentAnimationFrame].timer < (u8)adc)
    {
        pSub->animationDurationCounter = 0x1;
        pSub->currentAnimationFrame++;
        if ((u8)pSub->pMultiOam[pSub->currentAnimationFrame].timer == 0x0)
            pSub->currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 114e4 | 3c | Updates the current sprite position with the sub sprite data in parameter position and the X/Y position of its OAM data
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub)
{
    const u16* pOam;

    pOam = pSub->pMultiOam[pSub->currentAnimationFrame].pFrame;

    gCurrentSprite.yPosition = pSub->yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];
    gCurrentSprite.xPosition = pSub->xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

/**
 * @brief 11520 | 5c | Syncronises the current sprite position with the sub sprite in parameter (X/Y coords and X/Y OAM offsets)
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam(struct SubSpriteData* pSub)
{
    const u16* pOam;

    pOam = pSub->pMultiOam[pSub->currentAnimationFrame].pFrame;

    gCurrentSprite.yPosition = pSub->yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = pSub->xPosition - pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
    else
        gCurrentSprite.xPosition = pSub->xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

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

    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;

    samusTop = gSamusPhysics.drawDistanceTopOffset + gSamusData.yPosition;
    samusBottom = gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset;
    samusLeft = gSamusPhysics.drawDistanceLeftOffset + gSamusData.xPosition;
    samusRight = gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset;

    if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, samusTop, samusBottom, samusLeft, samusRight))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11620 | ac | 
 * Sets a sprite splash particle effect depending on the parameters and the current hazard
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
 * 116cc | 4c | 
 * Checks if the sprite is out of the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return 1 if out of effect, 0 otherwise 
 */
u32 SpriteUtilCheckOutOfRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size)
{
    if (oldY > gEffectYPosition && yPosition <= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition((u16)(yPosition + 0x40), xPosition);
            SpriteUtilSetSplashEffect(yPosition, xPosition, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * 11718 | 4c | 
 * Checks if the sprite is in the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return u8 1 if in the effect, 0 otherwise 
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
    else
        return FALSE;
}

/**
 * @brief 1175c | 2c | Gets the current completion percentage
 * 
 * @return u32 
 */
u32 SpriteUtilGetFinalCompletionPercentage(void)
{
    u32 result;
    u32 part1;
    u8 part2;
    u32 part3;
    u32 part4;
    u32 part5;

    u32 pen = ChozodiaEscapeGetItemCountAndEndingNumber();

    // TODO figure out how PEN is structured
    part1 = pen >> 0x18;
    part2 = (pen >> 0x10);

    part3 = (pen >> 0xC) & 0xF;
    part4 = (pen >> 0x8) & 0xF;
    part5 = (pen >> 0x4) & 0xF;

    result = part1 + part2 + part3 + part4 + part5;

    return result;
}