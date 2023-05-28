#include "sprites_AI/chozo_ball.h"
#include "sprites_AI/chozo_statue.h"

#include "data/sprites/chozo_statue.h"
#include "data/sprites/unknown_item_chozo_statue.h"

#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * 162b0 | 94 | Spawns an item banner depending on the chozo statue sprite ID
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoBallSpawnItemBanner(u8 spriteID)
{
    u8 text;

    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            text = MESSAGE_LONG_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_ICE:
            text = MESSAGE_ICE_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            text = MESSAGE_WAVE_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            text = MESSAGE_UKNOWN_ITEM_PLASMA;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            text = MESSAGE_BOMB;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            text = MESSAGE_SPEED_BOOSTER;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            text = MESSAGE_HIGH_JUMP;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            text = MESSAGE_SCREW_ATTACK;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            text = MESSAGE_VARIA_SUIT;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            text = MESSAGE_UNKNOWN_ITEM_SPACE_JUMP;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            text = MESSAGE_UNKNOWN_ITEM_GRAVITY;
            break;
    }

    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
}

/**
 * @brief 16344 | 64 | Sets the closed OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoBallSetClosedOAM(u8 spriteID)
{
    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownClosed;
            break;
        
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownClosed;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownClosed;
            break;
        
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOAM_NormalClosed;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOAM_NormalClosed;
    }
}

/**
 * @brief 163a8 | 64 | Sets the revealing OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoBallSetRevealingOAM(u8 spriteID)
{
    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealing;
            break;
        
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealing;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealing;
            break;
        
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOAM_NormalRevealing;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOAM_NormalRevealing;
    }
}

/**
 * @brief 1640c | 64 | Sets the revealed OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteID Chozo statue sprite ID
 */
void ChozoBallSetRevealedOAM(u8 spriteID)
{
    switch (spriteID)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealed;
            break;
        
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealed;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOAM_UnknownRevealed;
            break;
        
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOAM_NormalRevealed;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOAM_NormalRevealed;
    }
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
    gCurrentSprite.pose = CHOZO_BALL_POSE_DO_NOTHING;

    ChozoBallSetClosedOAM(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteID);
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
 * 164e8 | 70 | Initializes a chozo ball to be revealing
 * 
 */
void ChozoBallRevealingInit(void)
{
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.pose = CHOZO_BALL_POSE_REVEALING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    gCurrentSprite.invincibilityStunFlashTimer &= 0x80;

    ChozoBallSetRevealingOAM(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteID);
    SoundPlay(0x11D);
}

/**
 * 16558 | 3c | Checks if the revealing animation has ended
 * 
 */
void ChozoBallCheckRevealingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_BALL_POSE_IDLE;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        ChozoBallSetRevealedOAM(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteID);
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
        gCurrentSprite.pose = CHOZO_BALL_POSE_GETTING;
        gCurrentSprite.timer = 0x0;

        spriteID = gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteID;
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

        case CHOZO_BALL_POSE_DO_NOTHING:
            ChozoBallEmpty();
            break;

        case CHOZO_BALL_POSE_REVEALING:
            ChozoBallCheckRevealingAnimEnded();
            break;

        case CHOZO_BALL_POSE_IDLE:
            ChozoBallRegisterItem();
            break;

        case CHOZO_BALL_POSE_GETTING:
            ChozoBallFlashAnimation();
            break;

        default:
            ChozoBallRevealingInit();
    }
}
