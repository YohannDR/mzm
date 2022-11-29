#include "gba.h"
#include "oam.h"
#include "sprite_util.h"
#include "constants/particle.h"
#include "sprites_AI/parasite.h"
#include "sprites_AI/ridley.h"
#include "data/sprite_data.h"

#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite_util.h"
#include "constants/clipdata.h"

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

    gfxSlot = LocationTextGetGFXSlot();
    if (gfxSlot < 0x8)
    {
        gSpriteData[0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gSpriteData[0].properties = SP_ABSOLUTE_POSITION;
        gSpriteData[0].spritesetGFXSlot = gfxSlot;
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
        gSpriteData[0].primarySpriteRAMSlot = 0x0;
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
 * @brief e748 | c18 | 
 * Checks if the sprites are colliding with samus, applies said collision
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
    dmgMultiplier = 0x0;
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
                samusTop -= 0x20;
                samusBottom += 0x20;
                break;
            
            case FORCED_MOVEMENT_UPWARDS_SHINESPARK:
                samusLeft -= 0x20;
                samusRight += 0x20;
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
                samusLeft -= 0x20;
                samusRight += 0x20;
        }
    }

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        status = pSprite->status;
        if ((status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN))
        {
            if (pSprite->ignoreSamusCollisionTimer == 0x0)
            {
                register u16 a asm("r2"), b asm("r3");
                spriteY = a = pSprite->yPosition;
                spriteX = b = pSprite->xPosition;

                spriteTop = a + pSprite->hitboxTopOffset;
                spriteBottom = a + pSprite->hitboxBottomOffset;
                asm(""::"r"(a));
                spriteLeft = b + pSprite->hitboxLeftOffset;
                spriteRight = b + pSprite->hitboxRightOffset;
                asm(""::"r"(b));

                if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, spriteTop, spriteBottom, spriteLeft, spriteRight))
                {
                    gIgnoreSamusAndSpriteCollision = FALSE;

                    verticalCollisionOffset = spriteTop + ((spriteBottom - spriteTop) / 2);
                    horizontalCollisionOffset = ((spriteRight - spriteLeft) / 2) + spriteLeft;

                    collisionFlags = SPRITE_COLLISION_FLAG_NONE;

                    if ((i32)(verticalCollisionOffset - 0x4) > samusBottom)
                    {
                        if (pData->yVelocity <= 0x18)
                            collisionFlags = SPRITE_COLLISION_FLAG_ON_TOP;
                    }

                    if ((i32)(verticalCollisionOffset + 0x4) < samusTop)
                        collisionFlags |= SPRITE_COLLISION_FLAG_ON_BOTTOM;

                    if (horizontalCollisionOffset >= previousX)
                        collisionFlags |= SPRITE_COLLISION_FLAG_ON_LEFT;
                    else
                        collisionFlags |= SPRITE_COLLISION_FLAG_ON_RIGHT;

                    if (pSprite->freezeTimer != 0x0)
                    {
                        if (!SpriteUtilCheckPullingSeftUp() && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                        {
                            if (SpriteUtilCheckOnZipline())
                                SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
                            else
                            {
                                if ((samusY - 0x18) < spriteTop)
                                {
                                    SpriteUtilCheckCollisionAtPosition(spriteTop + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                    if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 0x1)
                                    {
                                        pData->yPosition = spriteTop + 0x1;
                                        pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                        pSprite->standingOnSprite = 0x2;
                                    }
                                }
                                else if ((samusTop + 0x10) > spriteBottom)
                                {
                                    SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTopOffset, samusX);
                                    if (gPreviousCollisionCheck == COLLISION_AIR)
                                    {
                                        pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTopOffset;
                                        if (pData->yVelocity > 0x0 && gEquipment.currentEnergy != 0x0)
                                            pData->yVelocity = 0x0;
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
                                    if ((i32)(samusY - 0x18) < spriteTop)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(spriteTop + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                        if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0x0)
                                        {
                                            pData->yPosition = spriteTop + 0x1;
                                            pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                            pSprite->standingOnSprite = 0x2;
                                        }
                                    }
                                    else if (samusTop + 0x10 > spriteBottom)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(spriteBottom - gSamusPhysics.drawDistanceTopOffset, samusX);
                                        if (gPreviousCollisionCheck == COLLISION_AIR)
                                        {
                                            pData->yPosition = spriteBottom - gSamusPhysics.drawDistanceTopOffset;
                                            if (pData->yVelocity > 0x0 && gEquipment.currentEnergy != 0x0)
                                                pData->yVelocity = 0x0;
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
                                    SpriteUtilCheckCollisionAtPosition(spriteTop + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                    if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity <= 0x0)
                                    {
                                        pData->yPosition = spriteTop + 0x1;
                                        pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                        pSprite->standingOnSprite = 0x2;
                                    }
                                }
                                break;

                            case SSC_HURTS_SAMUS_CAN_STAND_ON_TOP:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (samusY - 0x18 < spriteTop)
                                    {
                                        if (!SpriteUtilCheckPullingSeftUp() && pData->invincibilityTimer < 0x28)
                                        {
                                            SpriteUtilCheckCollisionAtPosition(spriteTop + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                            if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 0x1)
                                            {
                                                pData->yPosition = spriteTop + 0x1;
                                                pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                                pSprite->standingOnSprite = 0x2;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                        {
                                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                                pData->xVelocity = -0x40;
                                            else
                                                pData->xVelocity = 0x40;
                                        }
                                        pSprite->ignoreSamusCollisionTimer = 0xF;
                                        gIgnoreSamusAndSpriteCollision = TRUE;
                                    }
                                }
                                break;

                            case SSC_KRAID_SPIKE:
                                if (samusX > spriteRight)
                                {
                                    if (pData->invincibilityTimer == 0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x40;
                                        else
                                            pData->xVelocity = 0x40;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                else if ((i32)(samusY - 0x18) < spriteTop && !SpriteUtilCheckPullingSeftUp() && pData->invincibilityTimer < 0x26)
                                {
                                    SpriteUtilCheckCollisionAtPosition(spriteTop + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                    if (gPreviousCollisionCheck == COLLISION_AIR && pData->yVelocity < 0x1)
                                    {
                                        pData->yPosition = spriteTop + 0x1;
                                        pSprite->status |= SPRITE_STATUS_SAMUS_ON_TOP;
                                        pSprite->standingOnSprite = 0x2;

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
                                if (pSprite->pose == 0xF || pSprite->pose == 0x25)
                                {
                                    if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                                    {
                                        if ((u8)(pSprite->oamRotation - 0x21) <= 0x1E)
                                        {
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                                pData->xVelocity = -0x60;
                                            pSprite->ignoreSamusCollisionTimer = 0xF;
                                            gIgnoreSamusAndSpriteCollision = TRUE;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if ((u8)(pSprite->oamRotation + 0x3F) <= 0x1E)
                                        {
                                            pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                            if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                                pData->xVelocity = 0x60;
                                            pSprite->ignoreSamusCollisionTimer = 0xF;
                                            gIgnoreSamusAndSpriteCollision = TRUE;
                                            break;
                                        }
                                    }
                                }
                                    
                            case SSC_ACID_WORM:
                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                {
                                    if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                        pData->xVelocity = -0x40;
                                    else
                                        pData->xVelocity = 0x40;
                                }
                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;

                            case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT:
                            case SSC_SPACE_PIRATE_LASER:
                                pSprite->pose = 0x42;

                            case SSC_HURTS_SAMUS:
                            case SSC_MELLOW:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x40;
                                        else
                                            pData->xVelocity = 0x40;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case 0xF:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x40;
                                        else
                                            pData->xVelocity = 0x40;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_BIG_KNOCKBACK:
                                pSprite->pose = 0x42;

                            case SSC_IMAGO_STINGER:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x80;
                                        else
                                            pData->xVelocity = 0x80;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_ATOMIC_DISCHARGE:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x5))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x48;
                                        else
                                            pData->xVelocity = 0x48;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_SPACE_PIRATE:
                                if (SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                {
                                    if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1))
                                    {
                                        if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                            pData->xVelocity = -0x40;
                                        else
                                            pData->xVelocity = 0x40;
                                    }
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_HURTS_SAMUS_NO_KNOCKBACK:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibilityTimer < 0x8)
                                {
                                    SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1);
                                    if (gEquipment.currentEnergy != 0x0)
                                        pData->invincibilityTimer = 0x8;
                                }
                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;

                            case SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK:
                                pSprite->pose = 0x42;

                            case SSC_HURTS_SAMUS_NO_KNOCKBACK_NO_CONTACT_DAMAGE:
                                SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1);
                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                if (pData->invincibilityTimer == 0x0)
                                    pData->invincibilityTimer = 0x8;
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
                                pSprite->ignoreSamusCollisionTimer = 0xF;
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

                                    if (pData->invincibilityTimer == 0x0)
                                    {
                                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1) && gPreviousCollisionCheck == COLLISION_AIR)
                                        {
                                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                                pData->xVelocity = -0x40;
                                            else
                                                pData->xVelocity = 0x40;
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

                                    if (pData->invincibilityTimer == 0x0)
                                    {
                                        if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1) && gPreviousCollisionCheck == COLLISION_AIR)
                                        {
                                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                                pData->xVelocity = -0x40;
                                            else
                                                pData->xVelocity = 0x40;
                                        }
                                    }
                                    else if (gPreviousCollisionCheck == COLLISION_AIR)
                                    {
                                        SpriteUtilCheckCollisionAtPosition(samusY + 0x1 + gSamusPhysics.drawDistanceTopOffset, samusX);
                                        if (gPreviousCollisionCheck == COLLISION_AIR)
                                        {
                                            SamusSetPose(SPOSE_KNOCKBACK_REQUEST);
                                            if (collisionFlags & SPRITE_COLLISION_FLAG_ON_LEFT)
                                                pData->xVelocity = -0x40;
                                            else
                                                pData->xVelocity = 0x40;
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
                                        pData->xVelocity = -0x20;
                                    else
                                        pData->xVelocity = 0x20;

                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_BUG:
                                pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;
                                if (pData->invincibilityTimer == 0x0 && !(gEquipment.suitMiscActivation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)))
                                {
                                    if (!ParasiteCount())
                                        break;
                                    if (SpriteUtilTakeDamageFromSprite(FALSE, pSprite, dmgMultiplier >> 0x2))
                                    {
                                        pData->invincibilityTimer = 0x10;
                                        SoundPlayNotAlreadyPlaying(0x80); // Bug leeching
                                        gSubSpriteData1.workVariable2++;
                                        if (!(gSubSpriteData1.workVariable2 & 0x3))
                                            SoundPlay(0x7C); // Hurt
                                    }
                                }
                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                break;

                            case SSC_METROID:
                                if (samusY > (spriteY + 0x20))
                                    pSprite->status |= SPRITE_STATUS_SAMUS_COLLIDING;

                                if (pData->invincibilityTimer == 0x0 && SpriteUtilTakeDamageFromSprite(FALSE, pSprite, 0x1))
                                {
                                    dmgMultiplier = gEquipment.suitMiscActivation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT);
                                    if (!dmgMultiplier)
                                        pData->invincibilityTimer = 0x1;
                                    else if (dmgMultiplier == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
                                        pData->invincibilityTimer = 0x8;
                                    else
                                        pData->invincibilityTimer = 0x4;
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
                                    if (pData->invincibilityTimer == 0x0 && SpriteUtilSpriteTakeDamageFromSamusContact(pSprite, pData) == DCT_NONE)
                                        SpriteUtilTakeDamageFromSprite(TRUE, pSprite, 0x1);
                                    pSprite->ignoreSamusCollisionTimer = 0xF;
                                    gIgnoreSamusAndSpriteCollision = TRUE;
                                }
                                break;

                            case SSC_MECHA_RIDLEY:
                                if (SpriteUtilGetFinalCompletionPercentage() == 0x64)
                                    dmgMultiplier = 0x2;
                                else
                                    dmgMultiplier = 0x1;

                                if (SpriteUtilTakeDamageFromSprite(TRUE, pSprite, dmgMultiplier))
                                    pData->xVelocity = -0x80;

                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                break;

                            default:
                                pSprite->ignoreSamusCollisionTimer = 0xF;
                                gIgnoreSamusAndSpriteCollision = TRUE;
                                
                        }
                    }

                    if (gIgnoreSamusAndSpriteCollision)
                        break;
                }
            }
        }

    }

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->ignoreSamusCollisionTimer != 0x0)
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
            blockY = (i16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - 0x3f));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (i16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1) - 0x3F));
            gPreviousVerticalCollisionCheck = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (i16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 0x1) - 0x1F));
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
            blockY = (i16)((yPosition & 0xffc0) - ((xPosition & 0x3f) - 0x3f));
            collision = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            blockY = (i16)((yPosition & 0xFFC0) - (((xPosition & 0x3f) >> 0x1) - 0x3F));
            collision = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            blockY = (i16)((yPosition & 0xFFC0) - (((xPosition & 0x3f) >> 0x1) - 0x1F));
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
    i32 movement;
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
    if (gSpriteRNG & 0x1)
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
    if (gSpriteRNG & 0x1)
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

void unk_f978(i16 movement)
{

}

void unk_f9e7(i16 movement)
{

}

u8 SpriteUtilMakeSpriteFaceSamusRotation(i16 oamRotation, i16 samusY, i16 samusX, i16 spriteY, i16 spriteX)
{
    // https://decomp.me/scratch/QMDVm

    return oamRotation;
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

}

u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 yRange, u16 xRange)
{
    // https://decomp.me/scratch/0xhby

    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = NSLR_OUT_OF_RANGE;

    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
    samusX = gSamusData.xPosition;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    
    if ((spriteY > samusY ? spriteY - samusY : samusY - spriteY) >= yRange)
        return NSLR_OUT_OF_RANGE;
    else
    {
        if (spriteX > samusX)
        {
            if ((spriteX - samusX) < xRange)
                result = NSLR_LEFT;
        }
        else
        {
            if ((samusX - spriteX) < xRange)
                result = NSLR_RIGHT;
        }
    }

    return result;
}

u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 yRange, u16 xRange)
{

}

u32 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 yRange, u16 xRangeFront, u16 xRangeBehind)
{

}

/**
 * ff60 | 88 | 
 * Handles samus standing on a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
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
                gSamusData.yPosition = pSprite->yPosition + pSprite->hitboxTopOffset + 0x1;
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
            gCurrentSprite.paletteRow = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilUnfreezeAnimEasy(void)
{
    u8 freeze_timer;

    gCurrentSprite.freezeTimer--;

    freeze_timer = gCurrentSprite.freezeTimer;
    if (freeze_timer == 0x0)
        gCurrentSprite.animationDurationCounter--;
    if (freeze_timer < 0x5B && (freeze_timer & 0x1) == 0x0)
    {
        if ((freeze_timer & 0x2) != 0x0)
            gCurrentSprite.paletteRow = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilMetroidUnfreezeAnim(void)
{
    u8 freeze_timer;

    gCurrentSprite.freezeTimer -= 0x2;

    freeze_timer = gCurrentSprite.freezeTimer;
    if (freeze_timer == 0x0)
        gCurrentSprite.animationDurationCounter--;
    if (freeze_timer < 0x79 && (freeze_timer & 0x2) == 0x0)
    {
        if ((freeze_timer & 0x4) != 0x0)
            gCurrentSprite.paletteRow = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
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
                && gSpriteData[count].primarySpriteRAMSlot == ramSlot
                && gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer
                && (gSpriteData[count].properties & SP_DESTROYED) == 0x0)
            {
                gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
                gSpriteData[count].paletteRow = 0xF - (gSpriteData[count].spritesetGFXSlot + gSpriteData[count].frozenPaletteRowOffset);
            }
            count++;
        }
    }
}

void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void)
{
    if (gCurrentSprite.freezeTimer != 0) {
        u8 count = gCurrentSprite.primarySpriteRAMSlot;
        if (gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer && (gSpriteData[count].properties & SP_DESTROYED) == 0)
        {
            gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
            gSpriteData[count].paletteRow = 0xf - (gSpriteData[count].spritesetGFXSlot + gSpriteData[count].frozenPaletteRowOffset);
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
            && gSpriteData[count].primarySpriteRAMSlot == ramSlot
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

u8 SpriteUtilCountPrimarySprites(u8 spriteID)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteID == spriteID)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0x0;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->properties & SP_SECONDARY_SPRITE && pSprite->spriteID == spriteID && pSprite->primarySpriteRAMSlot == ramSlot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0x0;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE) && pSprite->spriteID == spriteID && pSprite->primarySpriteRAMSlot == ramSlot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilFindPrimary(u8 spriteID)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->spriteID == spriteID)
            return ramSlot;
        ramSlot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilFindSecondaryWithRoomSlot(u8 spriteID, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->spriteID == spriteID && pSprite->roomSlot == roomSlot)
            return ramSlot;
        ramSlot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilCheckHasDrops(void)
{
    u8 ramSlot;
    struct SpriteData* pSprite;
    u8 collision;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->primarySpriteRAMSlot == ramSlot && pSprite->samusCollision >= collision)
            return TRUE;
        pSprite++;
    }

    return FALSE;
}

u8 SpriteUtilCountDrops(void)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samusCollision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
        pSprite++;
    }

    return count;
}

void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{

}

void SpriteUtilRidleyFireballMove(u16 spriteY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{
    // https://decomp.me/scratch/slm8t

    /*u16 xPosition;
    u32 yPosition;
    u8 timerDone;

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

    timerDone = FALSE;
    
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.timer == 0x0)
        {
            if (gCurrentSprite.arrayOffset < ySpeed)
            {
                if (gCurrentSprite.yPosition <= (i32)(spriteY - 0x4))
                    gCurrentSprite.arrayOffset++;
                else
                {
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                    if (timerDone)
                    {
                        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
                        gCurrentSprite.arrayOffset = 0x1;
                    }
                    return;
                }
            }
            /!\ Branching issue?
            gCurrentSprite.yPosition += (gCurrentSprite.arrayOffset >> speedDivisor);
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.arrayOffset = 0x1;
            }
            else
                gCurrentSprite.yPosition += (gCurrentSprite.timer >> speedDivisor);
        }
    }
    else if (gCurrentSprite.timer == 0x0)
    {
        if (gCurrentSprite.arrayOffset < ySpeed)
        {
            if (gCurrentSprite.yPosition < (i32)(spriteY + 0x4))
                gCurrentSprite.arrayOffset++;
            else
            {
                gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                if (timerDone)
                {
                    gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.arrayOffset = 0x1;
                }
                return;
            }
        }
        gCurrentSprite.yPosition -= (gCurrentSprite.arrayOffset >> speedDivisor);
    }
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer != 0x0)
        {
            yPosition =  (u16)(gCurrentSprite.timer >> speedDivisor) - gCurrentSprite.yPosition;
            if (yPosition & 0x8000)
            {
                timerDone = TRUE;
                gCurrentSprite.timer = 0x0;
            }
            else
                gCurrentSprite.yPosition = yPosition;
        }
        else
            timerDone = TRUE;
    }

    if (timerDone)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        gCurrentSprite.arrayOffset = 0x1;
    }*/
}

/**
 * 10cf0 | 78 | 
 * Updates the stun timer of the sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
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
                    pSprite->paletteRow = 0xE - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
            }
            else
            {
                if (pSprite->health != 0x0)
                {
                    if (pSprite->freezeTimer != 0x0)
                        pSprite->paletteRow = 0xF - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
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

u8 SpriteUtilDetermineEnemyDrop(void)
{
    // https://decomp.me/scratch/94Ohs

    /*u8 fullLife;
    u32 rng;
    u8 spriteID;
    u16 energyProb;
    u16 largeEnergyProb;
    u16 missileProb;
    u16 superProb;
    u16 powerProb;
    u16 nonProb;
    u16 currentProb;
    u8 drop;
    u32 limit;

    drop = PSPRITE_UNUSED0;

    fullLife = FALSE;
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
        fullLife = TRUE;
    
    rng = gSpriteRNG;
    rng *= 0x100;
    rng = (u16)(rng + (gFrameCounter8Bit + gFrameCounter16Bit) << 0x6) >> 0x6;
    
    if (rng == 0x0)
        rng = 0x1;

    spriteID = gCurrentSprite.spriteID;
    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        energyProb = sSecondarySpriteStats[spriteID][4];
        largeEnergyProb = sSecondarySpriteStats[spriteID][5];
        missileProb = sSecondarySpriteStats[spriteID][6];
        superProb = sSecondarySpriteStats[spriteID][7];
        powerProb = sSecondarySpriteStats[spriteID][8];
    }
    else
    {
        energyProb = sPrimarySpriteStats[spriteID][4];
        largeEnergyProb = sPrimarySpriteStats[spriteID][5];
        missileProb = sPrimarySpriteStats[spriteID][6];
        superProb = sPrimarySpriteStats[spriteID][7];
        powerProb = sPrimarySpriteStats[spriteID][8];
    }

    if (powerProb != 0x0)
    {
        nonProb = 0x400 - powerProb;
        if (rng <= 0x400 && rng > powerProb)
        {
            if (gEquipment.maxPowerBombs <= gEquipment.currentPowerBombs)
            {
                if (fullLife)
                {
                    if (gEquipment.maxPowerBombs != 0x0)
                        drop = PSPRITE_POWER_BOMB_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }
            else
                drop = PSPRITE_POWER_BOMB_DROP;

            return drop;
        }
    }
    else
        nonProb = 0x400;

    if (superProb != 0x0)
    {
        currentProb = nonProb - superProb;
        if (nonProb >= rng && rng > currentProb)
        {
            if (gEquipment.maxSuperMissiles <= gEquipment.currentSuperMissiles)
            {
                if (fullLife)
                {
                    if (gEquipment.maxSuperMissiles != 0x0)
                        drop = PSPRITE_SUPER_MISSILE_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }
            else
                drop = PSPRITE_SUPER_MISSILE_DROP;

            return drop;
        }
        nonProb = currentProb;
    }

    if (missileProb != 0x0)
    {
        currentProb = nonProb - missileProb;
        if (nonProb >= rng && rng > currentProb)
        {
            if (gEquipment.maxMissiles <= gEquipment.currentMissiles)
            {
                if (fullLife)
                {
                    if (gEquipment.maxMissiles != 0x0)
                        drop = PSPRITE_MISSILE_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }
            else
                drop = PSPRITE_MISSILE_DROP;

            return drop;
        }
        nonProb = currentProb;
    }

    if (largeEnergyProb != 0x0)
    {
        currentProb = nonProb - largeEnergyProb;
        if (nonProb >= rng && rng > currentProb)
        {
            drop = PSPRITE_LARGE_ENERGY_DROP;
            if (fullLife)
            {
                if (gEquipment.maxMissiles > gEquipment.currentMissiles)
                    drop = PSPRITE_MISSILE_DROP;
            }

            return drop;
        }
        nonProb = currentProb;
    }

    if (energyProb != 0x0)
    {
        currentProb = nonProb - energyProb;
        if (nonProb >= rng && rng > currentProb)
        {
            drop = PSPRITE_SMALL_ENERGY_DROP;
            if (fullLife)
            {
                if (gEquipment.maxMissiles > gEquipment.currentMissiles)
                    drop = PSPRITE_MISSILE_DROP;
            }

            return drop;
        }
    }

    return drop;*/
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
                SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0);
        }
        else
        {
            // Init data for drop
            gCurrentSprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            gCurrentSprite.properties = 0x0;
            gCurrentSprite.spritesetGFXSlot = 0x0;
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
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(struct SubSpriteData* pSub)
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
u32 SpriteUtilGetCurrentCompletionPercentage(void)
{
    u32 result;
    u32 part1;
    u8 part2;
    u32 part3;
    u32 part4;
    u32 part5;

    u32 pen = GetPercentAndEndingNumber();

    // TODO figure out how PEN is structured
    part1 = pen >> 0x18;
    part2 = (pen >> 0x10);

    part3 = (pen >> 0xC) & 0xF;
    part4 = (pen >> 0x8) & 0xF;
    part5 = (pen >> 0x4) & 0xF;

    result = part1 + part2 + part3 + part4 + part5;

    return result;
}