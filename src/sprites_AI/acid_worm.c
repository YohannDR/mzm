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
    s32 offset;
    u8 arrayOffset;
    s32 posOffset;
    s32 positionOffset;
    s32 position;
    s32 sine;
    s32 sine_;
    s32 temp;
    s32 c;
    u8 angle;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        angle = gCurrentSprite.rotation + PI;
    else
        angle = gCurrentSprite.rotation;

    if (gSubSpriteData1.workVariable3 == TRUE)
        offset = PI * 3;
    else
        offset = PI * 2;

    arrayOffset = gCurrentSprite.work3;
    sine = sAcidWormSwingingMovement[arrayOffset];
    if (sine == SHORT_MAX)
    {
        sine = sAcidWormSwingingMovement[0];
        arrayOffset = 0;
    }
    gCurrentSprite.work3 = arrayOffset + 1;

    if (gCurrentSprite.health != 0)
        posOffset = (s16)(offset + MUL_SHIFT(sine, 4) * (gCurrentSprite.roomSlot / 4 + 1));
    else
        posOffset = (s16)(offset + sine * 16);

    temp = sine_ = sin(angle);
    if (temp < 0)
    {
        temp = Q_8_8_TO_SHORT(-temp * posOffset);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition - temp;
    }
    else
    {
        temp = Q_8_8_TO_SHORT(sine_ * posOffset);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition + temp;
    }

    c = cos(angle);
    position = (s16)gSubSpriteData1.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        position = (s16)(position + offset);
    else
        position = (s16)(position - offset);

    if (c < 0)
    {
        c = Q_8_8_TO_SHORT(-c * posOffset);
        gCurrentSprite.xPosition = position - c;
    }
    else
    {
        c = Q_8_8_TO_SHORT(c * posOffset);
        gCurrentSprite.xPosition = position + c;
    }
}

/**
 * @brief 3d978 | 40 | Handles the horizontal semi-random movement of the acid worm head
 * 
 */
void AcidWormRandomXMovement(void)
{
    s32 movement;
    u8 offset;

    offset = gCurrentSprite.work2;
    movement = sAcidWormHeadRandomXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAcidWormHeadRandomXVelocity[20]; // -1
        offset = 20;
    }

    gCurrentSprite.work2 = offset + 1;
    gCurrentSprite.xPosition += movement;
}

/**
 * @brief 3d9b8 | 48 | Updates the clipdata of the 2 blocks on the ground
 * 
 * @param caa Clipdata affecting action
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void AcidWormChangeTwoGroundCcaa(u8 caa, u16 yPosition, u16 xPosition)
{
    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the first 2 blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
void AcidWormChangeBigBlockDownCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    // Spawn position, corresponds to where the sprite is placed in the room (big block, bottom left)
    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    // Play particle effect if acid worm is dying
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - BLOCK_SIZE, xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the 2 middle blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
void AcidWormChangeBigBlockMiddleCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    // Play particle effect if acid worm is dying
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - BLOCK_SIZE, xPosition + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3daa8 | e4 | Updates the clipdata of the 2 top blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
void AcidWormChangeBigBlockTopCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2);
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        return;

    // If acid worm dying, play effects
    ParticleSet(yPosition - BLOCK_SIZE, xPosition - (PIXEL_SIZE * 2), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

    yPosition -= BLOCK_SIZE * 2;

    SpriteDebrisInit(0, 17, yPosition - (BLOCK_SIZE + ONE_SUB_PIXEL * 2), xPosition - HALF_BLOCK_SIZE);
    SpriteDebrisInit(0, 18, yPosition, xPosition - (QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE));

    SpriteDebrisInit(0, 19, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE), xPosition - (BLOCK_SIZE - ONE_SUB_PIXEL * 2));
    SpriteDebrisInit(0, 4, yPosition, xPosition - HALF_BLOCK_SIZE);

    SpriteDebrisInit(0, 17, yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE), xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL * 2));
    SpriteDebrisInit(0, 18, yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE), xPosition + HALF_BLOCK_SIZE);

    SpriteDebrisInit(0, 19, yPosition, xPosition + (BLOCK_SIZE + PIXEL_SIZE * 2));
    SpriteDebrisInit(0, 4, yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3 - PIXEL_SIZE), xPosition + (QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE));
}

/**
 * @brief 3db8c | 24 | Plays the retracting sound
 * 
 */
void AcidWormPlayRetractingSound(void)
{
    if (gSubSpriteData1.workVariable3 == FALSE)
    {
        // Extended into block
        SoundPlay(0x1B0);
    }
    else
    {
        // Extended above block
        SoundPlay(0x1AC);
    }
}

/**
 * @brief 3dbb0 | 44 | Checks if the acid worm is colliding with samus when extending
 * 
 * @return u8 bool, colliding
 */
u8 AcidWormCollidingWithSamusWhenExtending(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = 0x27;

        AcidWormPlayRetractingSound();
        return TRUE;
    }

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

    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

    gCurrentSprite.pOam = sAcidWormOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.samusCollision = SSC_ACID_WORM_MOUTH;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.work3 = 0;
    gCurrentSprite.work2 = 20;

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gSubSpriteData1.yPosition = yPosition;
    gSubSpriteData1.xPosition = xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gSubSpriteData1.workVariable3 = FALSE;
    gSubSpriteData1.workVariable2 = 0x0;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        // Acid worm killed, remove block and bring liquid down
        gEffectYPositionOffset = BLOCK_SIZE * 9 + HALF_BLOCK_SIZE;

        AcidWormChangeBigBlockDownCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockMiddleCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockTopCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeTwoGroundCcaa(CAA_REMOVE_SOLID, yPosition, xPosition);

        gCurrentSprite.status = 0;
        return;
    }

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
    {
        gCurrentSprite.status = 0; // No ziplines, kill sprite
        return;
    }

    LOCK_DOORS(); // Lock doors
    gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2); // Acid base position
    gCurrentSprite.roomSlot = 0;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    // Spawn body
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_AROUND_MOUTH,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 1, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_WEAK_POINT,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 2, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_BELOW_WEAK_POINT,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 3, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_ABOVE_SEGMENTS,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 4, xPosition, 0);

    // Spawn segments
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT1,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 5, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT2,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 6, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT3,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 7, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT4,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 8, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, ACID_WORM_BODY_PART_SEGMENT5,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 9, xPosition, 0);
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
    // On zipline
    if (!SpriteUtilCheckOnZipline())
        return;

    // In range
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn - ACID_WORM_SPAWN_RANGE && 
        gSamusData.xPosition < gCurrentSprite.xPositionSpawn + ACID_WORM_SPAWN_RANGE)
    {
        // Set ignore projectiles
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gSubSpriteData1.workVariable2 = 0x1;
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_EXTEND;
        gCurrentSprite.work0 = 0;

        // Destroy bottom
        AcidWormChangeBigBlockDownCcaa(CAA_REMOVE_SOLID);

        ScreenShakeStartVertical(60, 0x80 | 1);
        ScreenShakeStartHorizontal(60, 0x80 | 1);

        SoundPlay(0x1A7);
        SoundPlay(0x1A8);

        PlayMusic(MUSIC_WORMS_BATTLE, 0);
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
    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 7))
    {
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_ON_TOP;
        gCurrentSprite.pOam = sAcidWormOam_SpawnOnTop;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(0x1AA);
    }
    else
    {
        // Go up and play going out of acid effect
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;
        if (SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(0x1BB);

        // Lower acid
        gEffectYPositionOffset++;

        // Gradually destroy big block
        gCurrentSprite.work0++;
        if (gCurrentSprite.work0 == 4)
            AcidWormChangeBigBlockMiddleCcaa(CAA_REMOVE_SOLID);
        else if (gCurrentSprite.work0 == 8)
            AcidWormChangeBigBlockTopCcaa(CAA_REMOVE_SOLID);
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
        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
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

        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work0 = 60;
    }
    else
    {
        oldY = gCurrentSprite.yPosition;

        // Go down
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
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
    gCurrentSprite.pOam = sAcidWormOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ACID_WORM_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 3e030 | c0 | Handles the idle animation and Samus detection
 * 
 */
void AcidWormIdle(void)
{
    u32 samusY;
    u32 spritePos;

    if (gEffectYPosition > gSubSpriteData1.health)
        gEffectYPositionOffset--;

    samusY = gSamusData.yPosition;
    spritePos = gCurrentSprite.yPosition;
    
    if (samusY > gEffectYPosition || samusY > spritePos)
    {
        gCurrentSprite.work0 = 60;
        return;
    }

    do {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 != 0)
            return;
    
        if (spritePos - samusY - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL) >= BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE - ONE_SUB_PIXEL)
            gSubSpriteData1.workVariable3 = TRUE;
        else if (gSamusData.xPosition <= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 7)
            gSubSpriteData1.workVariable3 = TRUE;
        else if (gSamusData.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 7)
            gSubSpriteData1.workVariable3 = FALSE;
        else
            gSubSpriteData1.workVariable3 = TRUE;
    
        gSubSpriteData1.health += 0; // This is needed for the code to match :shrug:
    } while(0);

    gCurrentSprite.pOam = sAcidWormOam_Warning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_WARNING_ENDED;
    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
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
        gCurrentSprite.pOam = sAcidWormOam_Moving;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_POSE_EXTENDING;
        gCurrentSprite.work0 = 8;

        if (gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 3))
            gEffectYPositionOffset = -BLOCK_SIZE;
        else
            gEffectYPositionOffset = 0;
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

    spawnHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    if (gCurrentSprite.work0 != 0)
    {
        // Delay before moving
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
        {
            if (!gSubSpriteData1.workVariable3)
            {
                if (gCurrentSprite.health <= spawnHealth / 4)
                    SoundPlay(0x1AF);
                else if (gCurrentSprite.health <= spawnHealth / 2)
                    SoundPlay(0x1AE);
                else
                    SoundPlay(0x1AD);
            }
            else
                SoundPlay(0x1AB);
        }

        return;
    }

    // Make liquid go down
    gEffectYPositionOffset += ONE_SUB_PIXEL;

    // Get speed based on destination or health
    if (!gSubSpriteData1.workVariable3)
    {
        // Normal extend

        if (gCurrentSprite.health <= spawnHealth / 4)
            speed = 4;
        else if (gCurrentSprite.health <= spawnHealth / 2)
            speed = 3;
        else
            speed = 2;
    }
    else
    {
        // Extending to spit 
        speed = 2;
    }

    checks = 0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.rotation >= PI / 2 - 1)
            checks++; // Fully rotated
        else
            gCurrentSprite.rotation += speed;

        if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE)
            gSubSpriteData1.xPosition += speed;
        else
            checks++; // X Movement done
    }
    else
    {
        if ((u8)(gCurrentSprite.rotation - 1) <= PI + PI / 2 - 1)
            checks++; // Fully rotated
        else
            gCurrentSprite.rotation -= speed;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn - BLOCK_SIZE)
            gSubSpriteData1.xPosition -= speed;
        else
            checks++; // X Movement done
    }
    
    if (gSubSpriteData1.yPosition > gCurrentSprite.yPositionSpawn - (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE))
        gSubSpriteData1.yPosition -= speed;
    else
        checks++; // Y Movement done

    yPosition = gCurrentSprite.yPosition;
    AcidWormHandleRotation();

    if (SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
        SoundPlay(0x1BB);

    if (!AcidWormCollidingWithSamusWhenExtending() && checks == 3) // Everything done
    {
        // Extend done
        gCurrentSprite.pose = ACID_WORM_POSE_EXTENDED;

        if (!gSubSpriteData1.workVariable3) // If not spitting
        {
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                xPosition += BLOCK_SIZE;
            else
                xPosition -= BLOCK_SIZE;

            // Set effects depending on health
            if (gCurrentSprite.health <= spawnHealth / 4)
            {
                ScreenShakeStartVertical(40, 0x80 | 1);
                ScreenShakeStartHorizontal(40, 0x80 | 1);

                SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, xPosition - 0x20);
                SpriteDebrisInit(0x0, 0x4, yPosition, xPosition);
                SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0x34);
                SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
                SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                SpriteDebrisInit(0x0, 0x12, yPosition + 0x40, xPosition);
                ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                gCurrentSprite.work0 = 0x78; // Timer to stay
                SoundPlay(0x1B3);
            }
            else if (gCurrentSprite.health <= spawnHealth / 2)
            {
                ScreenShakeStartVertical(0x14, 0x81);
                ScreenShakeStartHorizontal(0x14, 0x81);
                SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, xPosition - 0x20);
                SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0x34);
                SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
                SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_BIG);
                gCurrentSprite.work0 = 0x8C; // Timer to stay
                SoundPlay(0x1B2);
            }
            else
            {
                ScreenShakeStartVertical(0xA, 0x81);
                ScreenShakeStartHorizontal(0xA, 0x81);
                SpriteDebrisInit(0x0, 0x12, yPosition - 0x42, xPosition - 0x20);
                SpriteDebrisInit(0x0, 0x4, yPosition + 0x20, xPosition + 0x20);
                ParticleSet(yPosition + 0x20, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                gCurrentSprite.work0 = 0xA0; // Timer to stay
                SoundPlay(0x1B1);
            }

            // Update timer based on difficulty
            if (gDifficulty == DIFF_EASY)
                gCurrentSprite.work0 += 60;
            else if (gDifficulty == DIFF_HARD)
                gCurrentSprite.work0 -= 20;

            gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
            gCurrentSprite.work1 = 0;
        }
        else
        {
            // Set spitting
            gCurrentSprite.pOam = sAcidWormOam_Spitting;
        }

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
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
            if (MOD_AND(gCurrentSprite.work1, 32) == 0)
                SoundPlay(0x1B4);

            gCurrentSprite.work1++;

            gCurrentSprite.work0--; // Timer until retracting
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
                AcidWormPlayRetractingSound();
            }
        }

        return;
    }

    // Not hooked
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn - (BLOCK_SIZE * 7) &&
        gSamusData.xPosition < gCurrentSprite.xPositionSpawn + (BLOCK_SIZE * 7))
        finishedThrowing++;
    else if (SpriteUtilCheckEndCurrentSpriteAnim())
        finishedThrowing++;

    if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(0x1B6);
    else if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(0x1B7);
    else if (gCurrentSprite.currentAnimationFrame == 5 && gCurrentSprite.animationDurationCounter == 1)
    {
        // First spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3), 0);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 1)
    {
        // Second spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3), 0);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 9 && gCurrentSprite.animationDurationCounter == 1)
    {
        // Third spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, 0x2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3), 0);
        }
    }

    if (finishedThrowing)
    {
        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
        AcidWormPlayRetractingSound();
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
        if (gCurrentSprite.rotation < 0x3)
        {
            // Finished rotation
            checks++;
            gCurrentSprite.rotation = 0x0;
        }
        else
            gCurrentSprite.rotation -= 0x2;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn)
        {
            gSubSpriteData1.xPosition -= speed;
        }
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }
    else
    {
        if (gCurrentSprite.rotation < 0x3)
        {
            // Finished rotation
            checks++;
            gCurrentSprite.rotation = 0x0;
        }
        else
        {
            gCurrentSprite.rotation += 0x2;
        }

        if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
        {
            gSubSpriteData1.xPosition -= -speed;
        }
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        gSubSpriteData1.yPosition += 0x2;
    }
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

    if (checks == 3) // Check everything done
    {
        if (gCurrentSprite.health <= GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 2 && gDifficulty != DIFF_EASY)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_MOSAIC;

            // Check should raise acid
            if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC && (u32)(spriteY - samusY - 0x51) < 0xEF &&
                gSamusData.xPosition > gCurrentSprite.xPositionSpawn - (BLOCK_SIZE * 7) &&
                gSamusData.xPosition < gCurrentSprite.xPositionSpawn + (BLOCK_SIZE * 7))
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RAISING_ACID;
                gCurrentSprite.pOam = sAcidWormOam_Moving;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work0 = 40;
                SoundPlay(0x1B9);
            }
            else
            {
                gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
                gCurrentSprite.work0 = 60 + MOD_AND(gSpriteRng, 8) * 8;
            }
        }
        else
        {
            gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
            gCurrentSprite.work0 = 80 + MOD_AND(gSpriteRng, 8) * 8;
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
    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        ScreenShakeStartHorizontal(10, 0x80 | 1);

    // Delay before starting
    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        return;
    }

    // Offset up
    gEffectYPositionOffset--;

    // Check reached max
    if (gEffectYPosition < gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 5)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_BRINGING_DOWN_ACID;
        SoundPlay(0x1BA);
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
    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        ScreenShakeStartHorizontal(10, 0x80 | 1);

    // Check reached min
    if (gEffectYPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 3)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
        gCurrentSprite.work0 = 1;
        gEffectYPositionOffset = -BLOCK_SIZE;

        if (gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 3;
    }
}

/**
 * @brief 3e93c | 24 | Initializes the acid worm to be dying
 * 
 */
void AcidWormDeathGfxInit(void)
{
    gCurrentSprite.pOam = sAcidWormOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ACID_WORM_POSE_DYING_ANIM;
    gCurrentSprite.invincibilityStunFlashTimer = 80;
}

/**
 * @brief 3e960 | 88 | Handles the flashing animation when the acid worm is dying
 * 
 */
void AcidWormDeathFlashingAnim(void)
{
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    AcidWormHandleRotation();

    if (!SPRITE_GET_ISFT(gCurrentSprite))
        return;

    isft = --gCurrentSprite.invincibilityStunFlashTimer;
    
    if (!(isft & 0x3))
    {
        if (isft & 0x4)
        {
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (isft == 0)
            {
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

                gCurrentSprite.pose = ACID_WORM_POSE_DYING;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.work0 = 1;
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
    if (gEffectYPosition > gCurrentSprite.yPositionSpawn + 0x1E0)
    {
        if (gSubSpriteData1.workVariable2 == 0)
        {
            gCurrentSprite.status = 0;
            PlayMusic(MUSIC_BOSS_KILLED, 0);
        }

        return;
    }

    if (gSubSpriteData1.workVariable2 == 0)
    {
        if (gEffectYPosition < gCurrentSprite.yPositionSpawn)
        {
            if (MOD_AND(gFrameCounter8Bit, 32) == 0)
                ParticleSet(gCurrentSprite.yPositionSpawn + 0x48 + gSpriteRng * 8, gCurrentSprite.xPositionSpawn, PE_SECOND_TWO_MEDIUM_DUST);
        }
        else
        {
            gEffectYPositionOffset++;
        }
    }

    // Check play effects
    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;

        if (gCurrentSprite.work0 == 0)
            SoundPlay(0x1BE);
    }
    else
    {
        gEffectYPositionOffset++;
        if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        {
            ScreenShakeStartVertical(10, 0x80 | 1);
            ScreenShakeStartHorizontal(10, 0x80 | 1);
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
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY_NO_CONTACT_DAMAGE;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 0x400;
    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0x10;
    gCurrentSprite.drawDistanceHorizontal = 0x10;
    gCurrentSprite.work2 = 0x14 - (gCurrentSprite.roomSlot * 0x2);

    switch (gCurrentSprite.roomSlot)
    {
        case ACID_WORM_BODY_PART_AROUND_MOUTH:
            gCurrentSprite.hitboxTop = -0x10;
            gCurrentSprite.hitboxBottom = 0x10;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x10;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = sAcidWormBodyOam_AroundMouth;
            gCurrentSprite.work0 = 0x8;
            gCurrentSprite.work3 = 0x8;
            break;

        case ACID_WORM_BODY_PART_WEAK_POINT:
            gCurrentSprite.hitboxTop = -0x30;
            gCurrentSprite.hitboxBottom = 0x30;
            gCurrentSprite.hitboxLeft = -0x30;
            gCurrentSprite.hitboxRight = 0x30;
            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.pOam = sAcidWormBodyOam_WeakPoint;
            gCurrentSprite.work0 = 0x10;
            gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.work3 = 0x10;
            break;

        case ACID_WORM_BODY_PART_BELOW_WEAK_POINT:
            gCurrentSprite.hitboxTop = -0x30;
            gCurrentSprite.hitboxBottom = 0x30;
            gCurrentSprite.hitboxLeft = -0x28;
            gCurrentSprite.hitboxRight = 0x28;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = sAcidWormBodyOam_BelowWeakPoint;
            gCurrentSprite.work0 = 0x18;
            gCurrentSprite.work3 = 0x18;
            break;

        case ACID_WORM_BODY_PART_ABOVE_SEGMENTS:
            gCurrentSprite.hitboxTop = -0x24;
            gCurrentSprite.hitboxBottom = 0x24;
            gCurrentSprite.hitboxLeft = -0x24;
            gCurrentSprite.hitboxRight = 0x24;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pOam = sAcidWormBodyOam_AboveSegments;
            gCurrentSprite.work0 = 0x20;
            gCurrentSprite.work3 = 0x20;
            break;

        case ACID_WORM_BODY_PART_SEGMENT1:
            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOam_Segment;
            gCurrentSprite.work0 = 0x28;
            gCurrentSprite.work3 = 0x0;
            break;
            
        case ACID_WORM_BODY_PART_SEGMENT2:
            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOam_Segment;
            gCurrentSprite.work0 = 0x30;
            gCurrentSprite.work3 = 0x8;
            break;

        case ACID_WORM_BODY_PART_SEGMENT3:
            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOam_Segment;
            gCurrentSprite.work0 = 0x38;
            gCurrentSprite.work3 = 0x10;
            break;

        case ACID_WORM_BODY_PART_SEGMENT4:
            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOam_Segment;
            gCurrentSprite.work0 = 0x40;
            gCurrentSprite.work3 = 0x18;
            break;

        case ACID_WORM_BODY_PART_SEGMENT5:
            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sAcidWormBodyOam_Segment;
            gCurrentSprite.work0 = 0x48;
            gCurrentSprite.work3 = 0x20;
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
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.rotation = 0x0;
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
    timer = gCurrentSprite.work0;

    health = gSpriteData[slot].health;
    if (health == 0)
    {
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        return;
    }

    if (gSpriteData[slot].status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = gSpriteData[slot].rotation - timer;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = timer + gSpriteData[slot].rotation;
    }

    if (!(gSpriteData[slot].status & SPRITE_STATUS_FACING_DOWN))
    {
        oldY = gCurrentSprite.yPosition;
        AcidWormHandleRotation();

        pose = gSpriteData[slot].pose;

        if (pose == ACID_WORM_POSE_EXTENDING)
        {
            if (MOD_AND(gCurrentSprite.roomSlot, 2) == 0)
                SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
        }
        else if (pose == ACID_WORM_POSE_RETRACTING && (MOD_AND(gCurrentSprite.roomSlot, 2) == 0))
        {
            SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
        }
    }
    if (gCurrentSprite.roomSlot != 0x2)
        return;
    if (gCurrentSprite.health < 0x400)
    {
        gSpriteData[slot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;

        SPRITE_CLEAR_ISFT(gCurrentSprite);

        health2 = 0x400 - gCurrentSprite.health;
        health = gSpriteData[slot].health;

        if (gSpriteData[slot].health > health2)
        {
            gSpriteData[slot].health -= health2;
            gCurrentSprite.health = 0x400;
            
            if (gSpriteData[slot].health <= GET_PSPRITE_HEALTH(gSpriteData[slot].spriteId) / 4)
                gSpriteData[slot].absolutePaletteRow = 2;
            else if (gSpriteData[slot].health <= DIV_SHIFT(GET_PSPRITE_HEALTH(gSpriteData[slot].spriteId), 2))
                gSpriteData[slot].absolutePaletteRow = 1;

            SoundPlay(0x1BC);
        }
        else
        {
            gSpriteData[slot].pose = ACID_WORM_POSE_DYING_INIT;
            gSpriteData[slot].health = 0;
            gSpriteData[slot].samusCollision = SSC_NONE;

            gCurrentSprite.health = 0;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

            SoundPlay(0x1BD);
            return;
        }
    }

    if (gSpriteData[slot].rotation != 0)
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    else
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME; // Remove collision

    AcidWormHandleRotation();

    if (gSpriteData[ramSlot].invincibilityStunFlashTimer != 0)
    {
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow; // Flashing effect
        return;
    }

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 != 0)
        return;

    roomSlot = gCurrentSprite.roomSlot;
    effect = PE_SPRITE_EXPLOSION_BIG;

    if (roomSlot != ACID_WORM_BODY_PART_WEAK_POINT)
    {
        effect = PE_SPRITE_EXPLOSION_MEDIUM;
        if (roomSlot == ACID_WORM_BODY_PART_SEGMENT5)
        {
            // Last segment
            gSubSpriteData1.workVariable2 = 0;

            ParticleSet(gSpriteData[ramSlot].yPositionSpawn + BLOCK_SIZE + HALF_BLOCK_SIZE,
                gSpriteData[ramSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);

            ParticleSet(gSpriteData[ramSlot].yPositionSpawn + BLOCK_SIZE, gSpriteData[ramSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);

            // Open path
            AcidWormChangeTwoGroundCcaa(CAA_REMOVE_SOLID, gSpriteData[ramSlot].yPositionSpawn, gSpriteData[ramSlot].xPositionSpawn);

            // Set event and open door
            EventFunction(EVENT_ACTION_SETTING, EVENT_ACID_WORM_KILLED);
            gDoorUnlockTimer = -20;
            FadeMusic(0x10E);
        }
    }

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, FALSE, effect);
}

/**
 * @brief 3f0e0 | 8c | Initialize an acid worm spit sprite
 * 
 */
void AcidWormSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

    gCurrentSprite.pOam = sAcidWormSpitOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.work3 = 0;
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
    s32 yMovement;
    u16 xMovement;

    if (gCurrentSprite.roomSlot == 0x2)
    {
        xMovement = 2;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitTwoYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitTwoYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else if (gCurrentSprite.roomSlot == 0x1)
    {
        xMovement = 10;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitOneYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitOneYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else
    {
        xMovement = 7;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitThreeYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitThreeYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    if (gCurrentSprite.yPosition >= gEffectYPosition)
    {
        gCurrentSprite.yPosition = gEffectYPosition;
        gCurrentSprite.pOam = sAcidWormSpitOAM_Exploding;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x45;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
}

/**
 * @brief 3f284 | 48 | Initializes an acid worm spit sprite to be exploding
 * 
 */
void AcidWormSpitExplodingGfxInit(void)
{
    gCurrentSprite.pOam = sAcidWormSpitOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x43;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    SoundPlay(0x1B8);
}

/**
 * @brief 3f2cc | 24 | Checks if the explosion animation has ended
 * 
 */
void AcidWormSpitCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3f2f0 | 2c | Checks if the explosion animation has ended (on acid)
 * 
 */
void AcidWormSpitCheckExplodingOnAcidAnimEnded(void)
{
    gCurrentSprite.yPosition = gEffectYPosition; // Sync position

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3f31c | 264 | Acid worm AI
 * 
 */
void AcidWorm(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
        gLockScreen.lock = LOCK_SCREEN_TYPE_MIDDLE;
        gLockScreen.yPositionCenter = gCurrentSprite.yPositionSpawn - 0x100;
        gLockScreen.xPositionCenter = gCurrentSprite.xPositionSpawn;
    }
    else
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
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
        case SPRITE_POSE_UNINITIALIZED:
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
        case SPRITE_POSE_UNINITIALIZED:
            AcidWormSpitInit();
            break;

        case 0x9:
            AcidWormSpitMove();
            break;

        case SPRITE_POSE_STOPPED:
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
