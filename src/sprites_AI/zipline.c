#include "sprites_AI/zipline.h"
#include "macros.h"

#include "data/sprites/zipline.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1d318 | 8c | Checks the collision for a stop block
 * 
 */
void ZiplineCheckColliding(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        // Set initial direction
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + ZIPLINE_BLOCK_X_RANGE);
        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - ZIPLINE_BLOCK_X_RANGE);
            if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
    else
    {
        // Check collision
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + ZIPLINE_BLOCK_X_RANGE);
        else
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - ZIPLINE_BLOCK_X_RANGE);
    }
}

/**
 * @brief 1d3a4 | c8 | Handles a zipline moving
 * 
 * @return u8 1 if releasing, 0 otherwise
 */
u8 ZiplineMoving(void)
{
    u8 releasing;
    u16 velocity;
    u8 samusGrabbing;

    releasing = FALSE;
    samusGrabbing = FALSE;

    // Get velocity
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        samusGrabbing = TRUE;
        velocity = PIXEL_SIZE * 3;
    }
    else
        velocity = QUARTER_BLOCK_SIZE;

    ZiplineCheckColliding();
    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
    {
        // Touched stop enemy block
        releasing++;
        gCurrentSprite.xPosition = (gCurrentSprite.xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
        if (samusGrabbing)
            gSamusData.xPosition = gCurrentSprite.xPosition;
    }
    else
    {
        // Move
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            gCurrentSprite.xPosition += velocity;
            if (samusGrabbing)
                gSamusData.xPosition += velocity;
        }
        else
        {
            gCurrentSprite.xPosition -= velocity;
            if (samusGrabbing)
                gSamusData.xPosition -= velocity;
        }
    }

    if (releasing && samusGrabbing)
    {
        // Release samus
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

        gCurrentSprite.ignoreSamusCollisionTimer = CONVERT_SECONDS(0.25f);

        SamusSetPose(SPOSE_MID_AIR_REQUEST);
    }

    return releasing;
}

/**
 * @brief 1d46c | 1dc | Updates the OAM of the zipline
 * 
 */
void ZiplineUpdateOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.work1)
            {
                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    gCurrentSprite.pOam = sZiplineOam_OnGrabbingSamus;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;

                    gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBED;
                        gCurrentSprite.health = ZIPLINE_HEALTH_MOVING;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    if (gCurrentSprite.pOam != sZiplineOam_OnSamusGrabbed)
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.work1)
            {
                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    gCurrentSprite.pOam = sZiplineOam_OffGrabbingSamus;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;

                    gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBED;
                    }
                    break;
                
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_GRABBED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    if (gCurrentSprite.pOam != sZiplineOam_OffSamusGrabbed)
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;
                    }
            }
        }
    }
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.work1)
            {
                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    gCurrentSprite.pOam = sZiplineOam_OnReleasingSamus;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;

                    gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;
                
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    if (gCurrentSprite.pOam != sZiplineOam_OnIdle)
                    {
                        gCurrentSprite.pOam = sZiplineOam_OnIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.work1)
            {
                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    gCurrentSprite.pOam = sZiplineOam_OffReleasingSamus;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;

                    gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;
                
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;

                        gCurrentSprite.work1 = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    if (gCurrentSprite.pOam != sZiplineOam_OffIdle)
                    {
                        gCurrentSprite.pOam = sZiplineOam_OffIdle;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;
                    }
            }
        }
    }
}

/**
 * @brief 1d648 | a4 | Initializes a zipline sprite
 * 
 */
void ZiplineInit(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.samusCollision = SSC_ZIPLINE;
    gCurrentSprite.health = ZIPLINE_HEALTH_NOT_MOVING;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = 1;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work0 = 0;
    gCurrentSprite.work1 = 0;

    // Set initial direction
    ZiplineCheckColliding();

    // Set OAM
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.pOam = sZiplineOam_OnIdle;
    else
        gCurrentSprite.pOam = sZiplineOam_OffIdle;

    gCurrentSprite.pose = ZIPLINE_POSE_IDLE;
}

/**
 * @brief 1d6ec | 84 | Handles a zipline being idle
 * 
 */
void ZiplineUpdate(void)
{
    if (!SpriteUtilCheckOnZipline() && gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.ignoreSamusCollisionTimer = CONVERT_SECONDS(0.25f);
    }

    ZiplineUpdateOAM();
    if (gCurrentSprite.health == ZIPLINE_HEALTH_MOVING)
    {
        // Move
        // CONVERT_SECONDS(.25f) + DELTA_TIME
        if (MOD_AND(gCurrentSprite.work0, 16) == 0)
            SoundPlay(SOUND_ZIPLING_MOVING);

        APPLY_DELTA_TIME_INC(gCurrentSprite.work0);

        if (ZiplineMoving())
        {
            gCurrentSprite.health = ZIPLINE_HEALTH_NOT_MOVING;
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.work0 = 0;
            SoundFade(SOUND_ZIPLING_MOVING, CONVERT_SECONDS(1.f / 15));
        }
    }
}

/**
 * @brief 1d770 | 98 | Initializes a zipline button sprite
 * 
 */
void ZiplineButtonInit(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.pOam = sZiplineButtonOAM_OnIdle;
    else
        gCurrentSprite.pOam = sZiplineButtonOAM_OffIdle;

    gCurrentSprite.yPosition -= BLOCK_SIZE * 2;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE + PIXEL_SIZE);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = ZIPLINE_HEALTH_NOT_MOVING;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_BIND_ZIPLINE;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = 1;
}

/**
 * @brief 1d808 | 20 | Initializes a zipline button to be idle
 * 
 */
void ZiplineButtonIdleInit(void)
{
    gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_IDLE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sZiplineButtonOAM_OnIdle;
}

/**
 * @brief 1d828 | 4c | Binds the zipline of the room to the button
 * 
 */
void ZiplineButtonBindZipline(void)
{
    u8 ramSlot;

    // Find zipline
    ramSlot = SpriteUtilFindPrimary(PSPRITE_ZIPLINE);
    if (ramSlot == UCHAR_MAX)
    {
        // Couldn't find a zipline, destroy
        gCurrentSprite.status = 0;
        return;
    }

    // Bind
    gCurrentSprite.work1 = ramSlot;
    
    // Set behavior
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        ZiplineButtonIdleInit();
    else
        gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_OFF;
}

/**
 * @brief 1d874 | 18 | Handles a zipline button being off
 * 
 */
void ZiplineButtonOff(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        ZiplineButtonIdleInit(); // Set on
}

/**
 * @brief 1d88c | 78 | Handles a zipline button being idle
 * 
 */
void ZiplineButtonIdle(void)
{
    u8 moving;
    u8 ramSlot;

    moving = FALSE;
    ramSlot = gCurrentSprite.work1;

    if (SPRITE_GET_ISFT(gCurrentSprite))
    {
        // Button hit, set moving
        gSpriteData[ramSlot].health = ZIPLINE_HEALTH_MOVING;
        moving = TRUE;
        SoundPlay(SOUND_ZIPLING_CALLED);
    }
    else if (gSpriteData[ramSlot].health == ZIPLINE_HEALTH_MOVING)
        moving = TRUE; // Already moving

    if (moving)
    {
        gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_ACTIVATED;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sZiplineButtonOAM_Active;
    }
}

/**
 * @brief 1d904 | 28 | Handles a zipline button being active
 * 
 */
void ZiplineButtonZiplineMoving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;

    if (gSpriteData[ramSlot].health == ZIPLINE_HEALTH_NOT_MOVING)
        ZiplineButtonIdleInit(); // Set idle
}

/**
 * @brief 1d92c | 28 | Zipline AI
 * 
 */
void Zipline(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZiplineInit();
            break;

        case ZIPLINE_POSE_IDLE:
            ZiplineUpdate();
    }
}

/**
 * @brief 1d954 | d0 | Zipline button AI
 * 
 */
void ZiplineButton(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZiplineButtonInit();
            break;

        case ZIPLINE_BUTTON_POSE_BIND_ZIPLINE:
            ZiplineButtonBindZipline();
            break;

        case ZIPLINE_BUTTON_POSE_IDLE:
            ZiplineButtonIdle();
            break;
            
        case ZIPLINE_BUTTON_POSE_ACTIVATED:
            ZiplineButtonZiplineMoving();
            break;

        case ZIPLINE_BUTTON_POSE_OFF:
            ZiplineButtonOff();
    }
}
