#include "chozo_ball.h"
#include "chozo_statue.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../music.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 162b0 | 94 | 
 * Spawns an item banner depending on the chozo statue sprite ID
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoBallSpawnItemBanner(u8 spriteID)
{
    u8 text;

    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            text = 0x8;
            break;
        case PSPRITE_CHOZO_STATUE_ICE:
            text = 0xA;
            break;
        case PSPRITE_CHOZO_STATUE_WAVE:
            text = 0xB;
            break;
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            text = 0xC;
            break;
        case PSPRITE_CHOZO_STATUE_BOMB:
            text = 0xD;
            break;
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            text = 0x11;
            break;
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            text = 0x12;
            break;
        case PSPRITE_CHOZO_STATUE_SCREW:
            text = 0x13;
            break;
        case PSPRITE_CHOZO_STATUE_VARIA:
            text = 0xE;
            break;
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            text = 0x14;
            break;
        case PSPRITE_CHOZO_STATUE_GRAVITY:
            text = 0xF;
            break;
    }

    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
}

void ChozoBallSetOAMPointer(u8 spriteID)
{

}

void ChozoBallRevealingSetOAMPointer(u8 spriteID)
{

}

void ChozoBallRevealedSetOAMPointer(u8 spriteID)
{

}

/**
 * 16470 | 74 | Initializes a chozo ball sprite
 * 
 */
void ChozoBallInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.hitboxTopOffset = -0x1C;
    gCurrentSprite.hitboxBottomOffset = 0x1C;
    gCurrentSprite.hitboxLeftOffset = -0x1C;
    gCurrentSprite.hitboxRightOffset = 0x1C;
    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0xC;
    gCurrentSprite.drawDistanceHorizontalOffset = 0xC;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.pose = 0x8;
    ChozoBallSetOAMPointer(gSpriteData[gCurrentSprite.primarySpriteRAMSlot].spriteID);
}

/**
 * 164e4 | 4 | Empty function
 * 
 */
void ChozoBallEmpty(void)
{
    return;
}

/**
 * 164e8 | 70 | Called before the chozo ball reveals, calls ChozoBallRevealingSetOAMPointer and updates the sprite data
 * 
 */
void ChozoBallRevealing(void)
{
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.pose = 0x67;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.palette_row = gCurrentSprite.absolutePaletteRow;
    gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
    ChozoBallRevealingSetOAMPointer(gSpriteData[gCurrentSprite.primarySpriteRAMSlot].spriteID);
    SoundPlay(0x11D);
}

/**
 * 16558 | 3c | Checks if the revealing animation has ended, calls ChozoBallRevealedSetOAMPointer
 * 
 */
void ChozoBallCheckRevealingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        ChozoBallRevealedSetOAMPointer(gSpriteData[gCurrentSprite.primarySpriteRAMSlot].spriteID);
    }
}

/**
 * 16594 | 1c | Registers the item grabbed and calls ChozoBallSpawnItemBanner
 * 
 */
void ChozoBallRegisterItem(void)
{
    u8 spriteID;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x0;
        spriteID = gSpriteData[gCurrentSprite.primarySpriteRAMSlot].spriteID;
        ChozoStatueRegisterItem(spriteID);
        ChozoBallSpawnItemBanner(spriteID);
    }
}

/**
 * 16600 | 3c | Handles the flashing animation when the item gets grabbed 
 * 
 */
void ChozoBallFlashAnimation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (!(gCurrentSprite.timer & 0x1))
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

/**
 * 1663c | 58 | Chozo ball AI
 * 
 */
void ChozoBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChozoBallInit();
            break;
        case 0x8:
            ChozoBallEmpty();
            break;
        case 0x67:
            ChozoBallCheckRevealingAnimEnded();
            break;
        case 0x9:
            ChozoBallRegisterItem();
            break;
        case 0x23:
            ChozoBallFlashAnimation();
            break;
        default:
            ChozoBallRevealing();
    }
}
