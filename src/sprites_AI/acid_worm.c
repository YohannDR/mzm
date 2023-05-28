#include "macros.h"
#include "sprites_AI/acid_worm.h"

#include "data/sprites/acid_worm.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/scroll.h"

/**
 * @brief 3d860 | 118 | Handles the rotation on the half-half circle of every part
 * 
 */
void AcidWormHandleRotation(void)
{
    i32 offset;
    u8 arrayOffset;
    i32 posOffset;
    i32 positionOffset;
    i32 position;
    i32 sine;
    i32 sine_;
    i32 temp;
    i32 c;
    u8 angle;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        angle = gCurrentSprite.oamRotation + PI;
    else
        angle = gCurrentSprite.oamRotation;

    if (gSubSpriteData1.workVariable3 == TRUE)
        offset = PI * 3;
    else
        offset = PI * 2;

    arrayOffset = gCurrentSprite.arrayOffset;
    sine = sAcidWormSwingingMovement[arrayOffset];
    if (sine == SHORT_MAX)
    {
        sine = sAcidWormSwingingMovement[0];
        arrayOffset = 0;
    }
    gCurrentSprite.arrayOffset = arrayOffset + 1;

    if (gCurrentSprite.health != 0)
        posOffset = (i16)(offset + (sine << 2) * ((gCurrentSprite.roomSlot / 4) + 1));
    else
        posOffset = (i16)(offset + (sine << 4));

    temp = sine_ = sin(angle);
    if (temp < 0)
    {
        temp = (i16)(-temp * posOffset >> 8);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition - temp;
    }
    else
    {
        temp = (i16)(sine_ * posOffset >> 8);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition + temp;
    }

    c = cos(angle);
    position = (i16)gSubSpriteData1.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        position = (i16)(position + offset);
    else
        position = (i16)(position - offset);

    if (c < 0)
    {
        c = (i16)(-c * posOffset >> 8);
        gCurrentSprite.xPosition = position - c;
    }
    else
    {
        c = (i16)(c * posOffset >> 8);
        gCurrentSprite.xPosition = position + c;
    }
}

/**
 * @brief 3d978 | 40 | Handles the horizontal semi-random movement of the acid worm head
 * 
 */
void AcidWormRandomXMovement(void)
{
    i32 movement;
    u8 offset;

    offset = gCurrentSprite.workVariable2;
    movement = sAcidWormHeadRandomXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAcidWormHeadRandomXVelocity[0x14]; // -1
        offset = 0x14;
    }

    gCurrentSprite.workVariable2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;
}

/**
 * @brief 3d9b8 | 48 | Updates the clipdata of the 2 blocks on the ground
 * 
 * @param caa Clipdata Affecting Action
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void AcidWormChangeTwoGroundCCAA(u8 caa, u16 yPosition, u16 xPosition)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 0x40, xPosition - 0x20); // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 0x40, xPosition + 0x20); // Right block
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the first 2 blocks of the big block on the ground
 * 
 * @param caa Clipdata Affecting Action
 */
void AcidWormChangeBigBlockDownCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    // Spawn position, corresponds to where the sprite is placed in the room (big block, bottom left)
    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gCurrentSprite.xPositionSpawn;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x20); // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x20); // Right block

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED)) // Play particle effect if acid worm is dying
        ParticleSet(yPosition - 0x40, xPosition - 0x10, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the 2 middle blocks of the big block on the ground
 * 
 * @param caa 
 */
void AcidWormChangeBigBlockMiddleCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - 0x40;
    xPosition = gCurrentSprite.xPositionSpawn;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x20);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x20);

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - 0x40, xPosition + 0x10, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3daa8 | e4 | Updates the clipdata of the 2 top blocks of the big block on the ground
 * 
 * @param caa 
 */
void AcidWormChangeBigBlockTopCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;
    u32 blockLeft;
    u32 blockRight;

    yPosition = gCurrentSprite.yPositionSpawn - 0x80;
    xPosition = gCurrentSprite.xPositionSpawn;
    gCurrentClipdataAffectingAction = caa;
    blockLeft = xPosition - 0x20;

    ClipdataProcess(yPosition, blockLeft); // Left block
    gCurrentClipdataAffectingAction = caa;
    blockRight = xPosition + 0x20;
    ClipdataProcess(yPosition, blockRight); // Right block

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        // If acid worm dying, play effects
        ParticleSet(yPosition - 0x40, xPosition - 0x8, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        yPosition -= 0x80;
        SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, blockLeft);
        SpriteDebrisInit(0x0, 0x12, yPosition, xPosition - 0x34);
        SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
        SpriteDebrisInit(0x0, 0x4, yPosition, blockLeft);
        SpriteDebrisInit(0x0, 0x11, yPosition - 0x24, xPosition + 0x52);
        SpriteDebrisInit(0x0, 0x12, yPosition - 0x4C, blockRight);
        SpriteDebrisInit(0x0, 0x13, yPosition, xPosition + 0x48);
        SpriteDebrisInit(0x0, 0x4, yPosition - 0x6C, xPosition + 0x34);
    }
}

/**
 * @brief 3db8c | 24 | Plays a sound depending on gSubSpriteData1::0xF
 * 
 */
void AcidWormPlaySound(void)
{
    if (gSubSpriteData1.workVariable3 == 0x0)
        SoundPlay(0x1B0);
    else
        SoundPlay(0x1AC);
}

/**
 * @brief 3dbb0 | 44 | Checks if the acid worm is colliding with samus when extending
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 AcidWormCollidingWithSamusWhenExtending(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.pOam = sAcidWormOAM_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x27;
        AcidWormPlaySound();
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * @brief 3dbf4 | 224 | Initializes an acid worm sprite
 * 
 */
void AcidWormInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    gCurrentSprite.hitboxTopOffset = -0x30;
    gCurrentSprite.hitboxBottomOffset = 0x38;
    gCurrentSprite.hitboxLeftOffset = -0x38;
    gCurrentSprite.hitboxRightOffset = 0x38;

    gCurrentSprite.drawDistanceTopOffset = 0x1A;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x1A;

    gCurrentSprite.pOam = sAcidWormOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    
    gCurrentSprite.samusCollision = SSC_ACID_WORM_MOUTH;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE;
    gCurrentSprite.status |= (SPRITE_STATUS_UNKNOWN2 | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x14;

    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.xPosition += 0x20;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gSubSpriteData1.yPosition = yPosition;
    gSubSpriteData1.xPosition = xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gSubSpriteData1.workVariable3 = 0x0;
    gSubSpriteData1.workVariable2 = 0x0;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        // Acid worm killed, remove block and bring liquid down
        gEffectYPositionOffset = 0x260;
        AcidWormChangeBigBlockDownCCAA(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockMiddleCCAA(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockTopCCAA(CAA_REMOVE_SOLID);
        AcidWormChangeTwoGroundCCAA(CAA_REMOVE_SOLID, yPosition, xPosition);
        gCurrentSprite.status = 0x0;
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            gCurrentSprite.status = 0x0; // No ziplines, kill sprite
        else
        {
            gDoorUnlockTimer = 0x1; // Lock doors
            gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - 0x80; // Acid base position
            gCurrentSprite.roomSlot = 0x0;

            gfxSlot = gCurrentSprite.spritesetGfxSlot;
            ramSlot = gCurrentSprite.primarySpriteRamSlot;
            
            // Spawn body
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_AROUND_MOUTH, gfxSlot, ramSlot, yPosition + 0x40, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_WEAK_POINT, gfxSlot, ramSlot, yPosition + 0x80, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_BELOW_WEAK_POINT, gfxSlot, ramSlot, yPosition + 0xC0, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_ABOVE_SEGMENTS, gfxSlot, ramSlot, yPosition + 0x100, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT1, gfxSlot, ramSlot, yPosition + 0x140, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT2, gfxSlot, ramSlot, yPosition + 0x180, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT3, gfxSlot, ramSlot, yPosition + 0x1C0, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT4, gfxSlot, ramSlot, yPosition + 0x200, xPosition, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT5, gfxSlot, ramSlot, yPosition + 0x240, xPosition, 0x0);
        }
    }
}

/**
 * @brief 3de18 | 20 | Checks if samus is on a zipline
 * 
 */
void AcidWormCheckSamusOnZipline(void)
{
    if (SpriteUtilCheckOnZipline())
    {
        gCurrentSprite.pose = ACID_WORM_POSE_CHECK_SPAWN;
        FadeMusic(0x12);
    }
}

/**
 * @brief 3de38 | 84 | Checks if the acid worm should spawn
 * 
 */
void AcidWormSpawnStart(void)
{
    // On zipline, a little more than 2 blocks on each side, y position doesn't matter
    if (SpriteUtilCheckOnZipline() && gSamusData.xPosition > (i32)(gCurrentSprite.xPositionSpawn - (BLOCK_SIZE * 0x2 + 0xC))
        && gSamusData.xPosition < gCurrentSprite.xPositionSpawn + (BLOCK_SIZE * 0x2 + 0xC))
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gSubSpriteData1.workVariable2 = 0x1;
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_EXTEND;
        gCurrentSprite.timer = 0x0;
        // Destroy bottom
        AcidWormChangeBigBlockDownCCAA(CAA_REMOVE_SOLID);
        ScreenShakeStartVertical(0x3C, 0x81);
        ScreenShakeStartHorizontal(0x3C, 0x81);
        SoundPlay(0x1A7);
        SoundPlay(0x1A8);
        PlayMusic(MUSIC_WORMS_BATTLE, 0x0);
    }
}

/**
 * @brief 3debc | 90 | Handles the acid worm extending when spawning
 * 
 */
void AcidWormSpawnExtending(void)
{
    u16 oldY;

    oldY = gCurrentSprite.yPosition;

    // Check if extended 7 blocks
    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 0x7))
    {
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_ON_TOP;
        gCurrentSprite.pOam = sAcidWormOAM_SpawnOnTop;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x1AA);
    }
    else
    {
        // Go up and play going out of acid effect
        gCurrentSprite.yPosition -= 0x10;
        if (SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(0x1BB);

        // Lower acid
        gEffectYPositionOffset++;

        // Gradually destroy big block
        gCurrentSprite.timer++;
        if (gCurrentSprite.timer == 0x4)
            AcidWormChangeBigBlockMiddleCCAA(CAA_REMOVE_SOLID);
        else if (gCurrentSprite.timer == 0x8)
            AcidWormChangeBigBlockTopCCAA(CAA_REMOVE_SOLID);
    }
}

void AcidWormSpawnStayingOnTop(void)
{
    // Idle movement
    AcidWormRandomXMovement();

    // Go down if anim ended
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_RETRACT;
        gCurrentSprite.pOam = sAcidWormOAM_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x1A9);
    }
}

/**
 * @brief 3df84 | 80 | Handles the acid worm retracting when spawning
 * 
 */
void AcidWormSpawnRetracting(void)
{
    u16 oldY;

    // Idle movement
    AcidWormRandomXMovement();

    // Check has reached bottom
    if (gCurrentSprite.yPosition >= gCurrentSprite.yPositionSpawn)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
        // Enable rotation/scaling
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;
        // 0x100 = No scaling
        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.timer = 0x3C;
    }
    else
    {
        oldY = gCurrentSprite.yPosition;
        // Go down
        gCurrentSprite.yPosition += 0x10;
        if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(0x1BB);

        // Check should rise liquid
        if (gEffectYPosition > gSubSpriteData1.health)
            gEffectYPositionOffset--;
    }
}

/**
 * @brief 3e004 | 2c | Initializes the acid worm to be idle
 * 
 */
void AcidWormIdleInit(void)
{
    // Set idle
    gCurrentSprite.pOam = sAcidWormOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = ACID_WORM_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
}

/**
 * @brief 3e030 | c0 | 
 * 
 */
void AcidWormIdle(void)
{
    // https://decomp.me/scratch/5cYt2
    
    u32 samusY;
    u32 spritePos;

    do {
    if (gEffectYPosition > gSubSpriteData1.health)
        gEffectYPositionOffset--;
    }while(0);

    samusY = gSamusData.yPosition;
    spritePos = gCurrentSprite.yPosition;
    
    if (samusY > gEffectYPosition || samusY > spritePos)
    {
        gCurrentSprite.timer = 60;
        return;
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer != 0)
        return;

    if (spritePos - samusY - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + 1) >= 239)
        gSubSpriteData1.workVariable3 = TRUE;
    else if (gSamusData.xPosition <= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 7)
        gSubSpriteData1.workVariable3 = TRUE;
    else if (gSamusData.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 7)
        gSubSpriteData1.workVariable3 = FALSE;
    else
        gSubSpriteData1.workVariable3 = TRUE;

    gCurrentSprite.pOam = sAcidWormOAM_Warning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_WARNING_ENDED;
    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    SoundPlay(0x1B5);
}

/**
 * @brief 3e0f0 | 5c | Checks if the warning animation before extending has ended
 * 
 */
void AcidWormCheckWarningAnimEnded(void)
{
    AcidWormHandleRotation();
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Init extending
        gCurrentSprite.pOam = sAcidWormOAM_Moving;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = ACID_WORM_POSE_EXTENDING;
        gCurrentSprite.timer = 0x8;
        if (gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - 0xC0)
            gEffectYPositionOffset = -0x40;
        else
            gEffectYPositionOffset = 0x0;
    }
}

/**
 * @brief 3e14c | 35c | Handles the acid worm extending
 * 
 */
void AcidWormExtend(void)
{
    u16 spawnHealth;
    u16 xPosition;
    u16 yPosition;
    u8 speed;
    u8 checks;

    spawnHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
    if (gCurrentSprite.timer != 0x0)
    {
        // Delay before moving
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            if (!gSubSpriteData1.workVariable3)
            {
                if (gCurrentSprite.health <= spawnHealth >> 0x2)
                    SoundPlay(0x1AF);
                else if (gCurrentSprite.health <= spawnHealth >> 0x1)
                    SoundPlay(0x1AE);
                else
                    SoundPlay(0x1AD);
            }
            else
                SoundPlay(0x1AB);
        }
    }
    else
    {
        gEffectYPositionOffset++;
        // Get speed based on destination or health
        if (!gSubSpriteData1.workVariable3)
        {
            if (gCurrentSprite.health <= spawnHealth >> 0x2)
                speed = 0x4;
            else if (gCurrentSprite.health <= spawnHealth >> 0x1)
                speed = 0x3;
            else
                speed = 0x2;
        }
        else
            speed = 0x2;

        checks = 0x0;
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.oamRotation >= 0x3F)
                checks = 0x1; // Fully rotated
            else
                gCurrentSprite.oamRotation += speed;

            if (gSubSpriteData1.xPosition < (i32)(gCurrentSprite.xPositionSpawn + 0x40))
                gSubSpriteData1.xPosition += speed;
            else
                checks++; // X Movement done
        }
        else
        {
            if ((u8)(gCurrentSprite.oamRotation - 0x1) <= 0xBF)
                checks = 0x1; // Fully rotated
            else
                gCurrentSprite.oamRotation -= speed;

            if (gSubSpriteData1.xPosition > (i32)(gCurrentSprite.xPositionSpawn - 0x40))
                gSubSpriteData1.xPosition -= speed;
            else
                checks++; // X Movement done
        }
        
        if (gSubSpriteData1.yPosition > (i32)(gCurrentSprite.yPositionSpawn - 0x30))
            gSubSpriteData1.yPosition -= speed;
        else
            checks++; // Y Movement done

        yPosition = gCurrentSprite.yPosition;
        AcidWormHandleRotation();

        if (SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(0x1BB);

        if (!AcidWormCollidingWithSamusWhenExtending() && checks == 0x3) // Everything done
        {
            // Extend done
            gCurrentSprite.pose = ACID_WORM_POSE_EXTENDED;
            if (!gSubSpriteData1.workVariable3) // If not spitting
            {
                yPosition = gCurrentSprite.yPosition;
                xPosition = gCurrentSprite.xPosition;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    xPosition += 0x40;
                else
                    xPosition -= 0x40;

                // Set effects depending on health
                if (gCurrentSprite.health <= spawnHealth >> 0x2)
                {
                    ScreenShakeStartVertical(0x28, 0x81);
                    ScreenShakeStartHorizontal(0x28, 0x81);
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, xPosition - 0x20);
                    SpriteDebrisInit(0x0, 0x4, yPosition, xPosition);
                    SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0x34);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
                    SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                    SpriteDebrisInit(0x0, 0x12, yPosition + 0x40, xPosition);
                    ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    gCurrentSprite.timer = 0x78; // Timer to stay
                    SoundPlay(0x1B3);
                }
                else if (gCurrentSprite.health <= spawnHealth >> 0x1)
                {
                    ScreenShakeStartVertical(0x14, 0x81);
                    ScreenShakeStartHorizontal(0x14, 0x81);
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, xPosition - 0x20);
                    SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0x34);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
                    SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                    ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_BIG);
                    gCurrentSprite.timer = 0x8C; // Timer to stay
                    SoundPlay(0x1B2);
                }
                else
                {
                    ScreenShakeStartVertical(0xA, 0x81);
                    ScreenShakeStartHorizontal(0xA, 0x81);
                    SpriteDebrisInit(0x0, 0x12, yPosition - 0x42, xPosition - 0x20);
                    SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                    ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    gCurrentSprite.timer = 0xA0; // Timer to stay
                    SoundPlay(0x1B1);
                }

                // Update timer based on difficulty
                if (gDifficulty == DIFF_EASY)
                    gCurrentSprite.timer += 0x3c;
                else if (gDifficulty == DIFF_HARD)
                    gCurrentSprite.timer -= 0x14;

                gCurrentSprite.pOam = sAcidWormOAM_MouthClosed;
                gCurrentSprite.workVariable = 0x0;
            }
            else
                gCurrentSprite.pOam = sAcidWormOAM_Spitting;

            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}

/**
 * @brief 3e4a8 | 210 | Handles the acid worm being fully extended (hooked to block or spitting)
 * 
 */
void AcidWormExtended(void)
{
    u8 finishedThrowing;

    finishedThrowing = FALSE;
    AcidWormHandleRotation();

    if (!gSubSpriteData1.workVariable3)
    {
        // Hooked to block
        if (!AcidWormCollidingWithSamusWhenExtending())
        {
            if (!(gCurrentSprite.workVariable & 0x1F))
                SoundPlay(0x1B4);

            gCurrentSprite.workVariable++;
            gCurrentSprite.timer--; // Timer until retracting
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
                AcidWormPlaySound();
            }
        }
    }
    else
    {
        // Not hooked
        if (gSamusData.xPosition > (i32)(gCurrentSprite.xPositionSpawn - 0x1C0) && gSamusData.xPosition < (i32)(gCurrentSprite.xPositionSpawn + 0x1C0))
            finishedThrowing = TRUE;
        else if (SpriteUtilCheckEndCurrentSpriteAnim())
            finishedThrowing++;

        if (gCurrentSprite.currentAnimationFrame == 0x1 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x1B6);
        else if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x1B7);
        else if (gCurrentSprite.currentAnimationFrame == 0x5 && gCurrentSprite.animationDurationCounter == 0x1)
        {
            // First spit
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_XFLIP);
            else
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x30, 0x0);
        }
        else if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x1)
        {
            // Second spit
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_XFLIP);
            else
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x30, 0x0);
        }
        else if (gCurrentSprite.currentAnimationFrame == 0x9 && gCurrentSprite.animationDurationCounter == 0x1)
        {
            // Third spit
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_XFLIP);
            else
                SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x30, 0x0);
        }

        if (finishedThrowing)
        {
            gCurrentSprite.pOam = sAcidWormOAM_MouthClosed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
            AcidWormPlaySound();
        }
    }
}

/**
 * @brief 3e6b8 | 1ac | Handles the acid worm retracting
 * 
 */
void AcidWormRetracting(void)
{
    u16 spriteY;
    u16 samusY;
    u8 checks;
    u16 speed;

    speed = 0x2;
    checks = 0x0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.oamRotation < 0x3)
        {
            // Finished rotation
            checks = 0x1;
            gCurrentSprite.oamRotation = 0x0;
        }
        else
            gCurrentSprite.oamRotation -= 0x2;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn)
            gSubSpriteData1.xPosition -= speed;
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }
    else
    {
        if (gCurrentSprite.oamRotation < 0x3)
        {
            // Finished rotation
            checks = 0x1;
            gCurrentSprite.oamRotation = 0x0;
        }
        else
            gCurrentSprite.oamRotation += 0x2;

        if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
            gSubSpriteData1.xPosition -= -speed;
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
        gSubSpriteData1.yPosition += 0x2;
    else
    {
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        checks++;
    }

    if (gEffectYPosition > gSubSpriteData1.health)
        gEffectYPositionOffset--;

    spriteY = gCurrentSprite.yPosition;
    AcidWormHandleRotation();
    if (SpriteUtilCheckInRoomEffect(spriteY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
        SoundPlay(0x1BB);

    samusY = gSamusData.yPosition;
    spriteY = gCurrentSprite.yPosition;
    if (checks == 0x3) // Check everything done
    {
        if (gCurrentSprite.health <= GET_PSPRITE_HEALTH(gCurrentSprite.spriteID) >> 0x1 && gDifficulty != DIFF_EASY)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_MOSAIC;

            // Check should raise acid
            if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC && (u32)(spriteY - samusY - 0x51) < 0xEF && gSamusData.xPosition > (i32)(gCurrentSprite.xPositionSpawn - 0x1C0) && gSamusData.xPosition < (i32)(gCurrentSprite.xPositionSpawn + 0x1C0))
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RAISING_ACID;
                gCurrentSprite.pOam = sAcidWormOAM_Moving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.timer = 0x28;
                SoundPlay(0x1B9);
            }
            else
            {
                gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
                gCurrentSprite.timer = (gSpriteRNG & 0x7) * 0x8 + 0x3C;
            }
        }
        else
        {
            gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
            gCurrentSprite.timer = (gSpriteRNG & 0x7) * 0x8 + 0x50;
        }
    }
}

/**
 * @brief 3e864 | 68 | Handles the acid worm bringing the acid up
 * 
 */
void AcidWormRaiseAcid(void)
{
    // Check start screen shake
    if (!(gFrameCounter8Bit & 0xF))
        ScreenShakeStartHorizontal(0xA, 0x81);

    // Delay before starting
    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        // Offset up
        gEffectYPositionOffset--;
        // Check reached max
        if ((i32)(gCurrentSprite.yPositionSpawn - 0x140) > gEffectYPosition)
        {
            gCurrentSprite.pose = ACID_WORM_POSE_BRINGING_DOWN_ACID;
            SoundPlay(0x1BA);
        }
    }
}

/**
 * @brief 3e8cc | 70 | Handles the acid worm bringing the acid down
 * 
 */
void AcidWormAcidGoDown(void)
{
    // Offset down
    gEffectYPositionOffset++;
    
    // Check start screen shake
    if (!(gFrameCounter8Bit & 0xF))
        ScreenShakeStartHorizontal(0xA, 0x81);

    // Check reached min
    if (gEffectYPosition > gCurrentSprite.yPositionSpawn - 0xC0)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
        gCurrentSprite.timer = 0x1;
        gEffectYPositionOffset = -0x40;
        if(gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - 0x80)
            gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - 0xC0;
    }
}

/**
 * @brief 3e93c | 24 | Initializes the acid worm to be dying
 * 
 */
void AcidWormDeathGfxInit(void)
{
    gCurrentSprite.pOam = sAcidWormOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = ACID_WORM_POSE_DYING_ANIM;
    gCurrentSprite.invincibilityStunFlashTimer = 0x50;
}

/**
 * @brief 3e960 | 88 | Handles the flashing animation when the acid worm is dying
 * 
 */
void AcidWormDeathFlashingAnim(void)
{
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    AcidWormHandleRotation();

    if (gCurrentSprite.invincibilityStunFlashTimer & 0x7f)
    {
        isft = --gCurrentSprite.invincibilityStunFlashTimer;
        
        if (!(isft & 0x3))
        {
            if (isft & 0x4)
                gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
            else
            {
                gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
                if (isft == 0x0)
                {
                    ParticleSet(gCurrentSprite.yPosition,gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    gCurrentSprite.pose = 0x68;
                    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                    gCurrentSprite.timer = 0x1;
                }
            }    
        }
    }
}

/**
 * @brief 3e9e8 | d0 | Handles the acid worm death
 * 
 */
void AcidWormDying(void)
{
    // Check acid reached bottom 
    if (gEffectYPosition > (i32)(gCurrentSprite.yPositionSpawn + 0x1E0))
    {
        if (gSubSpriteData1.workVariable2 == 0x0)
        {
            gCurrentSprite.status = 0x0;
            PlayMusic(MUSIC_BOSS_KILLED, 0x0);
        }
    }
    else
    {
        if (gSubSpriteData1.workVariable2 == 0x0)
        {
            if (gEffectYPosition < gCurrentSprite.yPositionSpawn)
            {
                if (!(gFrameCounter8Bit & 0x1F))
                    ParticleSet(gCurrentSprite.yPositionSpawn + 0x48 + gSpriteRNG * 0x8, gCurrentSprite.xPositionSpawn, PE_SECOND_TWO_MEDIUM_DUST);
            }
            else
                gEffectYPositionOffset++;
        }

        //Check play effects
        if (gCurrentSprite.timer != 0x0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
                SoundPlay(0x1BE);
        }
        else
        {
            gEffectYPositionOffset++;
            if (!(gFrameCounter8Bit & 0xF))
            {
                ScreenShakeStartVertical(0xA, 0x81);
                ScreenShakeStartHorizontal(0xA, 0x81);
            }
        }
    }
}

/**
 * @brief 3eab8 | 258 | Initializes an acid worm body sprite
 * 
 */
void AcidWormBodyInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_ACID_WORM;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 0x400;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.workVariable2 = (gCurrentSprite.roomSlot * 0x2) + 0x14;

    switch (gCurrentSprite.roomSlot)
    {
        case ACID_WORM_BODY_PART_AROUND_MOUTH:
            gCurrentSprite.hitboxTopOffset = -0x10;
            gCurrentSprite.hitboxBottomOffset = 0x10;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = sAcidWormBodyOAM_AroundMouth;
            gCurrentSprite.timer = 0x8;
            gCurrentSprite.arrayOffset = 0x8;
            break;

        case ACID_WORM_BODY_PART_WEAK_POINT:
            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x30;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x30;
            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.pOam = sAcidWormBodyOAM_WeakPoint;
            gCurrentSprite.timer = 0x10;
            gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.arrayOffset = 0x10;
            break;

        case ACID_WORM_BODY_PART_BELOW_WEAK_POINT:
            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x30;
            gCurrentSprite.hitboxLeftOffset = -0x28;
            gCurrentSprite.hitboxRightOffset = 0x28;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = sAcidWormBodyOAM_BelowWeakPoint;
            gCurrentSprite.timer = 0x18;
            gCurrentSprite.arrayOffset = 0x18;
            break;

        case ACID_WORM_BODY_PART_ABOVE_SEGMENTS:
            gCurrentSprite.hitboxTopOffset = -0x24;
            gCurrentSprite.hitboxBottomOffset = 0x24;
            gCurrentSprite.hitboxLeftOffset = -0x24;
            gCurrentSprite.hitboxRightOffset = 0x24;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pOam = sAcidWormBodyOAM_AboveSegments;
            gCurrentSprite.timer = 0x20;
            gCurrentSprite.arrayOffset = 0x20;
            break;

        case ACID_WORM_BODY_PART_SEGMENT1:
            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOAM_Segment;
            gCurrentSprite.timer = 0x28;
            gCurrentSprite.arrayOffset = 0x0;
            break;
            
        case ACID_WORM_BODY_PART_SEGMENT2:
            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOAM_Segment;
            gCurrentSprite.timer = 0x30;
            gCurrentSprite.arrayOffset = 0x8;
            break;

        case ACID_WORM_BODY_PART_SEGMENT3:
            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOAM_Segment;
            gCurrentSprite.timer = 0x38;
            gCurrentSprite.arrayOffset = 0x10;
            break;

        case ACID_WORM_BODY_PART_SEGMENT4:
            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOAM_Segment;
            gCurrentSprite.timer = 0x40;
            gCurrentSprite.arrayOffset = 0x18;
            break;

        case ACID_WORM_BODY_PART_SEGMENT5:
            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOAM_Segment;
            gCurrentSprite.timer = 0x48;
            gCurrentSprite.arrayOffset = 0x20;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 3ed10 | 10c | Handles the movement of the acid worm body
 * 
 */
void AcidWormBodyMove(void) {
    u32 slot;
    u16 y;
    u16 health;
    
    slot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[slot].pose == 0x43) 
    {
        y = gCurrentSprite.yPosition;
        gCurrentSprite.yPosition -= 0x10;
        if ((gCurrentSprite.roomSlot & 0x1) == 0x0)
            SpriteUtilCheckOutOfRoomEffect(y, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
    }
    else if (gSpriteData[slot].pose == 0x47)
    {
        AcidWormRandomXMovement();
        y = gCurrentSprite.yPosition;
        gCurrentSprite.yPosition += 0x10;
        if ((gCurrentSprite.roomSlot & 0x1) == 0x0)
            SpriteUtilCheckInRoomEffect(y, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
    }
    else if (gSpriteData[slot].pose == 0x45)
            AcidWormRandomXMovement();
    else if (gSpriteData[slot].pose == 0x8)
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.oamRotation = 0x0;
    }
    if (0x42 < gSpriteData[slot].pose)
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

    if ((gCurrentSprite.roomSlot == 0x2) && (gCurrentSprite.health < 0x400))
    {
        gSpriteData[slot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;
        gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
        health = 0x400 - gCurrentSprite.health;
        if (gSpriteData[slot].health > health)
        {
            gSpriteData[slot].health -= health;
            gCurrentSprite.health = 0x400;
        }
    }
}

/**
 * @brief 3ee1c | 1fc | Main loop for the acid worm body
 * 
 */
void AcidWormBodyMainLoop(void)
{
    u32 slot;
    u8 pose;
    u16 oldY;
    u8 timer;
    u16 health, health2;

    slot = gCurrentSprite.primarySpriteRamSlot;
    timer = gCurrentSprite.timer;
    health = gSpriteData[slot].health;
    if (health == 0x0)
    {
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        if (gSpriteData[slot].status & SPRITE_STATUS_FACING_RIGHT)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.oamRotation = gSpriteData[slot].oamRotation - timer;
        }
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.oamRotation = timer + gSpriteData[slot].oamRotation;
        }
        if ((gSpriteData[slot].status & SPRITE_STATUS_UNKNOWN2) == 0x0)
        {
            oldY = gCurrentSprite.yPosition;
            AcidWormHandleRotation();
            pose = gSpriteData[slot].pose;
            if (pose == 0x25)
            {
                if ((gCurrentSprite.roomSlot & 0x1) == 0x0)
                    SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
            }
            else if ((pose == 0x27) && ((gCurrentSprite.roomSlot & 0x1) == 0x0))
            {
                SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
            }
        }
        if (gCurrentSprite.roomSlot != 0x2)
            return;
        if (gCurrentSprite.health < 0x400)
        {
            gSpriteData[slot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;
            gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
            health2 = 0x400 - gCurrentSprite.health;
            health = gSpriteData[slot].health;
            if (gSpriteData[slot].health > health2)
            {
                gSpriteData[slot].health -= health2;
                gCurrentSprite.health = 0x400;
                
                if (gSpriteData[slot].health <= (u32)(GET_PSPRITE_HEALTH(gSpriteData[slot].spriteID) / 0x4))
                    gSpriteData[slot].absolutePaletteRow = 0x2;
                else if (gSpriteData[slot].health <= GET_PSPRITE_HEALTH(gSpriteData[slot].spriteID) >> 0x1)
                    gSpriteData[slot].absolutePaletteRow = 0x1;
                SoundPlay(0x1BC);
            }
            else
            {
                gSpriteData[slot].pose = ACID_WORM_POSE_DYING_INIT;
                gSpriteData[slot].health = 0x0;
                gSpriteData[slot].samusCollision = SSC_NONE;
                gCurrentSprite.health = 0x0;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                SoundPlay(0x1BD);
                return;
            }
        }
        if (gSpriteData[slot].oamRotation != 0x0)
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        else
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

/**
 * @brief 3f018 | c8 | Handles the death of an acid worm body
 * 
 */
void AcidWormBodyDeath(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 effect;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1; // Remove collision
    AcidWormHandleRotation();

    if (gSpriteData[ramSlot].invincibilityStunFlashTimer != 0x0)
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow; // Flashing effect
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            roomSlot = gCurrentSprite.roomSlot;
            effect = PE_SPRITE_EXPLOSION_BIG;
            if (roomSlot != ACID_WORM_BODY_PART_WEAK_POINT)
            {
                effect = PE_SPRITE_EXPLOSION_MEDIUM;
                if (roomSlot == ACID_WORM_BODY_PART_SEGMENT5)
                {
                    // Last segment
                    gSubSpriteData1.workVariable2 = 0x0;
                    ParticleSet(gSpriteData[ramSlot].yPositionSpawn + 0x60, gSpriteData[ramSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);
                    ParticleSet(gSpriteData[ramSlot].yPositionSpawn + 0x40, gSpriteData[ramSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);
                    // Open path
                    AcidWormChangeTwoGroundCCAA(CAA_REMOVE_SOLID, gSpriteData[ramSlot].yPositionSpawn, gSpriteData[ramSlot].xPositionSpawn);
                    // Set event and open door
                    EventFunction(EVENT_ACTION_SETTING, EVENT_ACID_WORM_KILLED);
                    gDoorUnlockTimer = -0x14;
                    FadeMusic(0x10E);
                }
            }

            // Kill sprite
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, FALSE, effect);
        }
    }
}

/**
 * @brief 3f0e0 | 8c | Initialize an acid worm spit sprite
 * 
 */
void AcidWormSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.hitboxTopOffset = -0x10;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x10;
    gCurrentSprite.hitboxRightOffset = 0x10;

    gCurrentSprite.pOam = sAcidWormSpitOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteID);

    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
}

/**
 * @brief 3f16c | 118 | Handles the movement of an acid worm spit
 * 
 */
void AcidWormSpitMove(void)
{
    u32 offset;
    i32 yMovement;
    u16 xMovement;

    if (gCurrentSprite.roomSlot == 0x2)
    {
        xMovement = 0x2;
        offset = gCurrentSprite.arrayOffset;
        yMovement = sAcidWormSpitTwoYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitTwoYVelocity[offset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else if (gCurrentSprite.roomSlot == 0x1)
    {
        xMovement = 0xA;
        offset = gCurrentSprite.arrayOffset;
        yMovement = sAcidWormSpitOneYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitOneYVelocity[offset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else
    {
        xMovement = 0x7;
        offset = gCurrentSprite.arrayOffset;
        yMovement = sAcidWormSpitThreeYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitThreeYVelocity[offset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    if (gCurrentSprite.yPosition >= gEffectYPosition)
    {
        gCurrentSprite.yPosition = gEffectYPosition;
        gCurrentSprite.pOam = sAcidWormSpitOAM_Exploding;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x45;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
            gCurrentSprite.pose = 0x42;
    }
}

/**
 * @brief 3f284 | 48 | Initializes an acid worm spit sprite to be exploding
 * 
 */
void AcidWormSpitExplodingGfxInit(void)
{
    gCurrentSprite.pOam = sAcidWormSpitOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = 0x43;
    gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    SoundPlay(0x1B8);
}

/**
 * @brief 3f2cc | 24 | Checks if the explosion animation has ended
 * 
 */
void AcidWormSpitCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 3f2f0 | 2c | Checks if the explosion animation has ended (on acid)
 * 
 */
void AcidWormSpitCheckExplodingOnAcidAnimEnded(void)
{
    gCurrentSprite.yPosition = gEffectYPosition; // Sync position
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 3f31c | 264 | Acid worm AI
 * 
 */
void AcidWorm(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AcidWormInit();
            break;

        case ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE:
            AcidWormCheckSamusOnZipline();
            break;

        case ACID_WORM_POSE_CHECK_SPAWN:
            AcidWormSpawnStart();
            break;

        case ACID_WORM_POSE_SPAWN_EXTEND:
            AcidWormSpawnExtending();
            break;

        case ACID_WORM_POSE_SPAWN_ON_TOP:
            AcidWormSpawnStayingOnTop();
            break;

        case ACID_WORM_POSE_SPAWN_RETRACT:
            AcidWormSpawnRetracting();
            break;

        case ACID_WORM_POSE_IDLE_INIT:
            AcidWormIdleInit();

        case ACID_WORM_POSE_IDLE:
            AcidWormIdle();
            break;

        case ACID_WORM_POSE_CHECK_WARNING_ENDED:
            AcidWormCheckWarningAnimEnded();
            break;

        case ACID_WORM_POSE_EXTENDING:
            AcidWormExtend();
            break;

        case ACID_WORM_POSE_RETRACTING:
            AcidWormRetracting();
            break;

        case ACID_WORM_POSE_EXTENDED:
            AcidWormExtended();
            break;

        case ACID_WORM_POSE_RAISING_ACID:
            AcidWormRaiseAcid();
            break;

        case ACID_WORM_POSE_BRINGING_DOWN_ACID:
            AcidWormAcidGoDown();
            break;

        case ACID_WORM_POSE_DYING_INIT:
            AcidWormDeathGfxInit();
            break;

        case ACID_WORM_POSE_DYING_ANIM:
            AcidWormDeathFlashingAnim();
            break;

        case ACID_WORM_POSE_DYING:
            AcidWormDying();
            break;
    }

    // Lock screen if not dead
    if (gSubSpriteData1.workVariable2 != 0x0)
    {
        gLockScreen.lock = 0x2;
        gLockScreen.yPositionCenter = gCurrentSprite.yPositionSpawn - 0x100;
        gLockScreen.xPositionCenter = gCurrentSprite.xPositionSpawn;
    }
    else
        gLockScreen.lock = FALSE;
}

/**
 * @brief 3f580 | a4 | Acid worm body AI
 * 
 */
void AcidWormBody(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Sync palette
    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    if (gSpriteData[ramSlot].paletteRow == 0xE - (gSpriteData[ramSlot].spritesetGfxSlot + gSpriteData[ramSlot].frozenPaletteRowOffset))
    {
        gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        gCurrentSprite.animationDurationCounter++;
    }
    else if (gSpriteData[ramSlot].paletteRow == gSpriteData[ramSlot].absolutePaletteRow)
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AcidWormBodyInit();
            break;

        case 0x43:
            AcidWormBodyMove();
            break;

        case 0x9:
            AcidWormBodyMainLoop();
            break;

        case 0x67:
            AcidWormBodyDeath();
    }
}

/**
 * @brief 3f624 | 60 | Acid worm spit AI
 * 
 */
void AcidWormSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AcidWormSpitInit();
            break;

        case 0x9:
            AcidWormSpitMove();
            break;

        case 0x42:
            AcidWormSpitExplodingGfxInit();

        case 0x43:
            AcidWormSpitCheckExplodingAnimEnded();
            break;

        case 0x45:
            AcidWormSpitCheckExplodingOnAcidAnimEnded();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}