#include "zipline.h"
#include "../../data/data.h"
#include "../data/sprites/zipline.c"
#include "../globals.h"

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

    if (gCurrentSprite.pose == 0x0)
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
        velocity = 0xC;
    }
    else
        velocity = 0x10;

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
        gCurrentSprite.ignoreSamusCollisionTimer = 0xF;
        SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
    }

    return releasing;
}

void ZiplineUpdateOAM(void)
{
    // https://decomp.me/scratch/x2aM6

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.workVariable)
            {
                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    gCurrentSprite.pOam = sZiplineOAM_OnGrabbingSamus;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;

                    gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_GRABBING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;

                        gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_GRABBED;
                        gCurrentSprite.health = 0x2;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;

                        gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_GRABBED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    if (gCurrentSprite.pOam != sZiplineOAM_OnSamusGrabbed)
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.workVariable)
            {
                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    gCurrentSprite.pOam = sZiplineOAM_OffGrabbingSamus;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;

                    gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_GRABBING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OffSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;

                        gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_GRABBED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    if (gCurrentSprite.pOam != sZiplineOAM_OffSamusGrabbed)
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OffSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
    }
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.workVariable)
            {
                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    gCurrentSprite.pOam = sZiplineOAM_OnReleasingSamus;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;

                    gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_RELEASING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OnIdle;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;

                        gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    if (gCurrentSprite.pOam != sZiplineOAM_OnSamusGrabbed)
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OnSamusGrabbed;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.workVariable)
            {
                case ZIPLINE_ANIMATION_STATE_GRABBED:
                    gCurrentSprite.pOam = sZiplineOAM_OffReleasingSamus;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;

                    gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_RELEASING;
                    break;

                case ZIPLINE_ANIMATION_STATE_GRABBING:
                case ZIPLINE_ANIMATION_STATE_RELEASING:
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OffIdle;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;

                        gCurrentSprite.workVariable = ZIPLINE_ANIMATION_STATE_RELEASED;
                    }
                    break;

                case ZIPLINE_ANIMATION_STATE_RELEASED:
                    if (gCurrentSprite.pOam != sZiplineOAM_OffIdle)
                    {
                        gCurrentSprite.pOam = sZiplineOAM_OffIdle;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
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
    gCurrentSprite.hitboxTopOffset = -0x40;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.samusCollision = SSC_ZIPLINE;
    gCurrentSprite.health = ZIPLINE_HEALTH_NOT_MOVING;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = 0x1;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.timer = 0x0;
    gCurrentSprite.workVariable = 0x0;

    // Set initial direction
    ZiplineCheckColliding();

    // Set OAM
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.pOam = sZiplineOAM_OnIdle;
    else
        gCurrentSprite.pOam = sZiplineOAM_OffIdle;

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
        gCurrentSprite.ignoreSamusCollisionTimer = 0xF;
    }

    ZiplineUpdateOAM();
    if (gCurrentSprite.health == ZIPLINE_HEALTH_MOVING)
    {
        // Move
        if (!(gCurrentSprite.timer & 0xF))
            SoundPlay(0x110);

        gCurrentSprite.timer++;
        if (ZiplineMoving())
        {
            gCurrentSprite.health = ZIPLINE_HEALTH_NOT_MOVING;
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.timer = 0x0;
            SoundFade(0x110, 0x4);
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

    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x50;
    gCurrentSprite.hitboxLeftOffset = -0x14;
    gCurrentSprite.hitboxRightOffset = 0x14;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_BIND_ZIPLINE;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = 0x1;
}

/**
 * @brief 1d808 | 20 | Initializes a zipline button to be idle
 * 
 */
void ZiplineButtonIdleInit(void)
{
    gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_IDLE;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
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
    if (ramSlot == 0xFF)
        gCurrentSprite.status = 0x0;
    else
    {
        // Bind
        gCurrentSprite.workVariable = ramSlot;
        
        // Set behavior
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            ZiplineButtonIdleInit();
        else
            gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_OFF;
    }
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
    ramSlot = gCurrentSprite.workVariable;
    if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
    {
        // Button hit, set moving
        gSpriteData[ramSlot].health = ZIPLINE_HEALTH_MOVING;
        moving = TRUE;
        SoundPlay(0x111);
    }
    else if (gSpriteData[ramSlot].health == ZIPLINE_HEALTH_MOVING)
        moving = TRUE; // Already moving

    if (moving)
    {
        gCurrentSprite.pose = ZIPLINE_BUTTON_POSE_ACTIVATED;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
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

    ramSlot = gCurrentSprite.workVariable;

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
        case 0x0:
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
        case 0x0:
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