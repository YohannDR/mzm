#include "gba.h"
#include "samus.h"
#include "block.h" // Necessary
#include "clipdata.h" // Necessary
#include "macros.h"
#include "temp_globals.h"

#include "data/samus_sprites_pointers.h"
#include "data/samus/samus_palette_data.h"
#include "data/samus/samus_animation_pointers.h"
#include "data/samus/samus_graphics.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/color_fading.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/projectile.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/visual_effects.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"
#include "structs/scroll.h"

/**
 * @brief 5368 | 10c | Checks for screw attack and speedbooster damage to the environment
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 */
void SamusCheckScrewSpeedboosterAffectingEnvironment(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u16 action;
    u16 hitboxLeft;
    u16 hitboxRight;
    u16 hitboxTop;
    u16 hitboxBottom;
    u8 checkBlockBelow;

    action = DESTRUCTING_ACTION_NONE;

    if (pData->pose == SPOSE_SCREW_ATTACKING)
        action = DESTRUCTING_ACTION_SCREW;
    else if (pData->pose == SPOSE_STARTING_SPIN_JUMP && gEquipment.suitMiscActivation & SMF_SCREW_ATTACK)
        action = DESTRUCTING_ACTION_SCREW;

    if (pData->speedboostingShinesparking)
        action += DESTRUCTING_ACTION_SPEED;

    if (action == DESTRUCTING_ACTION_NONE)
        return;

    hitboxLeft = pData->xPosition + pPhysics->hitboxLeftOffset;
    hitboxRight = pData->xPosition + pPhysics->hitboxRightOffset;
    hitboxTop = pData->yPosition + pPhysics->hitboxTopOffset;
    hitboxBottom = pData->yPosition;
    
    checkBlockBelow = FALSE;
    if (pPhysics->hitboxTopOffset < -BLOCK_SIZE)
        checkBlockBelow = TRUE;

    BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxLeft, hitboxTop, action);
    BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxRight, hitboxTop, action);

    if (pPhysics->horizontalMovingDirection == HDMOVING_RIGHT)
    {
        if (checkBlockBelow)
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxRight, hitboxTop + BLOCK_SIZE, action);

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxRight, hitboxBottom, action);
    }
    else
    {
        if (checkBlockBelow)
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxLeft, hitboxTop + BLOCK_SIZE, action);

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxLeft, hitboxBottom, action);
    }

    if (pPhysics->standingStatus == STANDING_GROUND)
    {
        hitboxBottom += ONE_SUB_PIXEL;
        action = DESTRUCTING_ACTION_SPEED_ON_GROUND;
    }

    BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxLeft, hitboxBottom, action);
    BlockSamusApplyScrewSpeedboosterDamageToEnvironment(hitboxRight, hitboxBottom, action);
}

/**
 * @brief 5474 | 190 | Checks the collision at the position for samus
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @param pXPosition X position result pointer
 * @param pYPosition Y position result pointer
 * @param pSlope Slope result pointer
 * @return u8 Collision result
 */
u8 SamusCheckCollisionAtPosition(u16 xPosition, u16 yPosition, u16* pXPosition, u16* pYPosition, u16* pSlope)
{
    u32 clipdata;
    u8 collision;
    u16 newX;
    u16 newY;
    u16 slopeType;

    clipdata = ClipdataProcessForSamus(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        collision = CLIPDATA_TYPE_SOLID;
    else
        collision = CLIPDATA_TYPE_AIR;

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            newY = ((yPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG) - (xPosition & SUB_PIXEL_POSITION_FLAG);
            newX = ((xPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG) - (yPosition & SUB_PIXEL_POSITION_FLAG);
            slopeType = SLOPE_STEEP | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG - ((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1);
            newX = (xPosition & BLOCK_POSITION_FLAG) - ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2 - (SUB_PIXEL_POSITION_FLAG - 1 + BLOCK_SIZE));
            slopeType = SLOPE_SLIGHT | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) + (SUB_PIXEL_POSITION_FLAG - HALF_BLOCK_SIZE) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1));
            newX = (xPosition & BLOCK_POSITION_FLAG) - ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2 - SUB_PIXEL_POSITION_FLAG + 1);
            slopeType = SLOPE_SLIGHT | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            newX = (xPosition & BLOCK_POSITION_FLAG) | (yPosition & SUB_PIXEL_POSITION_FLAG);
            slopeType = SLOPE_STEEP | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) | (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) + (SUB_PIXEL_POSITION_FLAG - HALF_BLOCK_SIZE));
            newX = (xPosition & BLOCK_POSITION_FLAG) + ((yPosition & SUB_PIXEL_POSITION_FLAG) * 2 - SUB_PIXEL_POSITION_FLAG);
            slopeType = SLOPE_SLIGHT | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) | ((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1);
            newX = (xPosition & BLOCK_POSITION_FLAG) + (yPosition & SUB_PIXEL_POSITION_FLAG) * 2;
            slopeType = SLOPE_SLIGHT | KEY_LEFT;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;

        default:
            newY = yPosition & BLOCK_POSITION_FLAG;
            newX = xPosition & BLOCK_POSITION_FLAG;
            slopeType = SLOPE_NONE;
    }

    *pYPosition = newY;
    *pXPosition = newX;
    *pSlope = slopeType;
    return collision;
}

/**
 * @brief 5604 | b4 | To document
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus Physics Pointer
 * @param xPosition X Position
 * @param pPosition Result X Position
 * @return u8 Collision result
 */
u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition)
{
    u8 result;
    u16 yPosition;
    s32 clipdata;

    result = SAMUS_COLLISION_DETECTION_NONE;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
    else
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;

    yPosition = pData->yPosition + pPhysics->hitboxTopOffset;
    clipdata = ClipdataProcessForSamus(yPosition, xPosition);

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            break;

        default:
            if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
    }

    if (pPhysics->hitboxTopOffset >= -BLOCK_SIZE)
        return result;

    clipdata = ClipdataProcessForSamus(yPosition + BLOCK_SIZE, xPosition);

    switch (LOW_BYTE(clipdata))
    {
        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            break;

        default:
            if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;
    }

    return result;
}

/**
 * @brief 56b8 | dc | Checks for the top sides blocks when jumping
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus Physics Pointer
 * @param xPosition X Position
 * @param pPosition Pointer To X Position
 * @return u8 Collision result
 */
u8 SamusCheckTopSideCollisionMidAir(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition)
{
    u8 result;
    s32 clipdata;
    u16 yPosition;

    result = SAMUS_COLLISION_DETECTION_NONE;
    
    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
    else
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;

    yPosition = pData->yPosition;
    clipdata = ClipdataProcessForSamus(yPosition, xPosition);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (LOW_BYTE(clipdata))
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_SLOPE;
                break;

            default:
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
        }
    }

    if (result == SAMUS_COLLISION_DETECTION_LEFT_MOST)
    {
        clipdata = ClipdataProcessForSamus(pData->yPosition, pData->xPosition);

        switch (LOW_BYTE(clipdata))
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_LEFT_MOST | SAMUS_COLLISION_DETECTION_SLOPE;
        }
    }

    if (pPhysics->hitboxTopOffset < -BLOCK_SIZE)
    {
        clipdata = ClipdataProcessForSamus(yPosition - BLOCK_SIZE, xPosition);

        switch (clipdata & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                break;

            default:
                if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                    result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;
        }
    }

    return result;
}

/**
 * @brief 5794 | 58 | Checks if samus is colliding with a slope when walking
 * 
 * @param pData Samus data pointer
 * @param xPosition X Position
 * @return u8 Collision result
 */
u8 SamusCheckWalkingOnSlope(struct SamusData* pData, u16 xPosition)
{
    u8 result;
    s32 clipdata;

    result = SAMUS_COLLISION_DETECTION_NONE;
    clipdata = ClipdataProcessForSamus(pData->yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (LOW_BYTE(clipdata))
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_SLOPE;
                break;

            default:
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
        }
    }

    if (result == SAMUS_COLLISION_DETECTION_LEFT_MOST)
    {
        clipdata = ClipdataProcessForSamus(pData->yPosition, pData->xPosition);

        switch (LOW_BYTE(clipdata))
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                result = SAMUS_COLLISION_DETECTION_LEFT_MOST | SAMUS_COLLISION_DETECTION_SLOPE;
                break;
        }
    }

    return result;
}

/**
 * @brief 57ec | b4 | Checks for the collision on the 4 blocks above samus
 * 
 * @param pData Samus data pointer
 * @param hitbox Hitbox
 * @return u8 Collision result
 */
u8 SamusCheckCollisionAbove(struct SamusData* pData, s32 hitbox)
{
    u8 result;
    u16 yPosition;
    s32 clipdata;
    struct SamusPhysics* pPhysics;

    hitbox = (s16)hitbox;
    pPhysics = &gSamusPhysics;

    result = SAMUS_COLLISION_DETECTION_NONE;

    yPosition = pData->yPosition + hitbox;
    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + pPhysics->hitboxLeftOffset);
    
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_LEFT_MOST;

    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + sSamusHitboxData_Above[SAMUS_HITBOX_LEFT]);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;

    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + sSamusHitboxData_Above[SAMUS_HITBOX_RIGHT]);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT;

    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + pPhysics->hitboxRightOffset);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_RIGHT_MOST;

    return result;
}

/**
 * @brief 58a0 | 238 | Checks for the sides collisions when walking
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 * @return u8 New pose
 */
u8 SamusCheckWalkingSidesCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u16 frontHitbox;
    u16 backHitbox;
    u16 slope;

    u16 nextX;
    u16 nextY;
    u16 nextSlope;

    u8 result;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
    {
        slope = KEY_LEFT;
        frontHitbox = pPhysics->hitboxLeftOffset;
        backHitbox = pPhysics->hitboxRightOffset;
    }
    else
    {
        slope = KEY_RIGHT;
        frontHitbox = pPhysics->hitboxRightOffset;
        backHitbox = pPhysics->hitboxLeftOffset;
    }

    result = unk_5604(pData, pPhysics, pData->xPosition + frontHitbox, &nextX);

    if (result != SAMUS_COLLISION_DETECTION_NONE)
    {
        pData->xPosition = nextX;
        pPhysics->touchingSideBlock++;
    }

    gSamusDataCopy.timer = result;

    if (pData->currentSlope == 0)
    {
        result = SamusCheckWalkingOnSlope(pData, pData->xPosition + frontHitbox);
        
        if (result == SAMUS_COLLISION_DETECTION_SLOPE)
        {
            SamusCheckCollisionAtPosition(pData->xPosition + frontHitbox, pData->yPosition,
                &nextX, &nextY, &nextSlope);

            pData->yPosition = nextY;
            pData->currentSlope = nextSlope;
            pData->standingStatus = STANDING_GROUND;
        }
        else if (result == (SAMUS_COLLISION_DETECTION_SLOPE | SAMUS_COLLISION_DETECTION_LEFT_MOST))
        {
            SamusCheckCollisionAtPosition(pData->xPosition + frontHitbox, pData->yPosition - BLOCK_SIZE,
                &nextX, &nextY, &nextSlope);

            pData->yPosition = nextY;
            if (nextSlope == 0)
                pData->yPosition = nextY + SUB_PIXEL_POSITION_FLAG;

            pData->currentSlope = nextSlope;
            pData->standingStatus = STANDING_GROUND;
        }
        else
        {
            if (result != SAMUS_COLLISION_DETECTION_NONE)
            {
                pData->xPosition = nextX;
                pPhysics->touchingSideBlock++;
            }

            if (pData->standingStatus == STANDING_ENEMY)
                return SPOSE_NONE;

            if (SamusCheckCollisionAtPosition(pData->xPosition + frontHitbox, pData->yPosition + ONE_SUB_PIXEL,
                &nextX, &nextY, &nextSlope) == CLIPDATA_TYPE_AIR)
            {
                result = SamusCheckCollisionAtPosition(pData->xPosition + backHitbox, pData->yPosition + ONE_SUB_PIXEL,
                    &nextX, &nextY, &nextSlope);

                if (nextSlope == 0)
                {
                    if (result == CLIPDATA_TYPE_AIR)
                        return SPOSE_MID_AIR_REQUEST;
                }
                else
                {
                    pData->yPosition = nextY;
                    pData->currentSlope = nextSlope;
                }
            }

            pData->standingStatus = STANDING_GROUND;
        }
    }
    else if (pData->currentSlope & slope)
    {
        result = SamusCheckWalkingOnSlope(pData, pData->xPosition + frontHitbox);

        if (result == SAMUS_COLLISION_DETECTION_SLOPE)
        {
            SamusCheckCollisionAtPosition(pData->xPosition + frontHitbox, pData->yPosition,
                &nextX, &nextY, &nextSlope);

            pData->yPosition = nextY;
            pData->currentSlope = nextSlope;
            pData->standingStatus = STANDING_GROUND;
        }
        else if (result != SAMUS_COLLISION_DETECTION_NONE)
        {
            SamusCheckCollisionAtPosition(pData->xPosition + frontHitbox, pData->yPosition - BLOCK_SIZE,
                &nextX, &nextY, &nextSlope);

            pData->yPosition = nextY;
            if (nextSlope == 0)
                pData->yPosition = nextY + (BLOCK_SIZE - 1);

            pData->currentSlope = nextSlope;
            pData->standingStatus = STANDING_GROUND;
        }
    }
    else
    {
        result = SamusCheckCollisionAtPosition(pData->xPosition + backHitbox, pData->yPosition,
            &nextX, &nextY, &nextSlope);
        
        if (nextSlope != 0)
        {
            pData->yPosition = nextY;
            return SPOSE_NONE;
        }

        if (result == SAMUS_COLLISION_DETECTION_NONE)
        {
            result = SamusCheckCollisionAtPosition(pData->xPosition + backHitbox, pData->yPosition + BLOCK_SIZE,
                &nextX, &nextY, &nextSlope);

            pData->currentSlope = nextSlope;
        
            if (nextSlope != 0)
            {
                pData->yPosition = nextY;
                return SPOSE_NONE;
            }

            if (result != SAMUS_COLLISION_DETECTION_NONE)
            {
                if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
                    pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
                else
                    pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;

                pData->yPosition = nextY - ONE_SUB_PIXEL;
            }
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 5ad8 | b4 | To document
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 * @return u8 New pose
 */
u8 unk_5AD8(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u16 yPosition;
    u16 xPosition;
    u16 slope;

    if ((pData->xPosition & BLOCK_POSITION_FLAG) == (gPreviousXPosition & BLOCK_POSITION_FLAG) &&
        pData->currentSlope == 0 && pData->standingStatus == STANDING_GROUND)
    {
        if (SamusCheckCollisionAtPosition(pData->xPosition, pData->yPosition + 1,
            &xPosition, &yPosition, &slope) == CLIPDATA_TYPE_AIR && slope == 0)
        {
            if (pPhysics->horizontalMovingDirection == HDMOVING_RIGHT)
            {
                if ((pData->xPosition & SUB_PIXEL_POSITION_FLAG) > 0x1D && (gPreviousXPosition & SUB_PIXEL_POSITION_FLAG) < 0x1F)
                {
                    pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + 0x1E;
                    return SPOSE_MID_AIR_REQUEST;
                }
            }
            else if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
            {
                if ((pData->xPosition & SUB_PIXEL_POSITION_FLAG) < 0x22 && (gPreviousXPosition & SUB_PIXEL_POSITION_FLAG) > 0x20)
                {
                    pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + 0x21;
                    return SPOSE_MID_AIR_REQUEST;
                }
            }
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 5b8c | c0 | Checks for block collision when not moving on the ground
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 * @return u8 New pose
 */
u8 SamusCheckStandingOnGroundCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 above;
    u16 yPosition;
    u16 xPosition;
    u16 slope;

    above = SamusCheckCollisionAbove(pData, pPhysics->hitboxTopOffset);
    if (above == SAMUS_COLLISION_DETECTION_LEFT_MOST ||
        above == (SAMUS_COLLISION_DETECTION_LEFT_MOST | SAMUS_COLLISION_DETECTION_MIDDLE_LEFT))
    {
        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
    }
    else if (above == SAMUS_COLLISION_DETECTION_RIGHT_MOST ||
        above == (SAMUS_COLLISION_DETECTION_RIGHT_MOST | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT))
    {
        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;
    }

    if (pData->standingStatus != STANDING_ENEMY)
    {
        if (SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxLeftOffset, pData->yPosition + 1,
            &xPosition, &yPosition, &slope) == CLIPDATA_TYPE_AIR)
        {
            if (SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxRightOffset, pData->yPosition + 1,
                &xPosition, &yPosition, &slope) == CLIPDATA_TYPE_AIR)
                return SPOSE_MID_AIR_REQUEST;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 5c4c | 1d0 | Checks for a block collision to land
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 * @return u8 New pose
 */
u8 SamusCheckLandingCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u16 hHitbox;
    u16 blockY;
    u16 prevBlockY;

    u16 resultXLeft;
    u16 resultYLeft;
    u16 resultSlopeLeft;
    u16 resultXRight;
    u16 resultYRight;
    u16 resultSlopeRight;

    u8 collisionRight;
    u8 collisionLeft;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
    {
        hHitbox = pPhysics->hitboxLeftOffset;
    }
    else
    {
        hHitbox = pPhysics->hitboxLeftOffset;
        hHitbox = pPhysics->hitboxRightOffset;
    }

    if (unk_5604(pData, pPhysics, pData->xPosition + hHitbox, &resultXLeft) != SAMUS_COLLISION_DETECTION_NONE)
    {
        pData->xPosition = resultXLeft;
        pPhysics->touchingSideBlock++;
    }

    if (pData->standingStatus == STANDING_ENEMY)
        return SPOSE_NONE;

    blockY = pData->yPosition & BLOCK_POSITION_FLAG;
    prevBlockY = gPreviousYPosition & BLOCK_POSITION_FLAG;

    collisionLeft = SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxLeftOffset, pData->yPosition,
        &resultXLeft, &resultYLeft, &resultSlopeLeft);

    collisionRight = SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxRightOffset, pData->yPosition,
        &resultXRight, &resultYRight, &resultSlopeRight);

    if (blockY > prevBlockY)
    {
        if (collisionLeft != CLIPDATA_TYPE_AIR)
        {
            if (resultSlopeLeft != SLOPE_NONE)
            {
                if (collisionRight != CLIPDATA_TYPE_AIR)
                {
                    pData->yPosition = resultYRight - 1;
                }
                else
                {
                    pData->currentSlope = resultSlopeLeft;
                    pData->yPosition = resultYLeft;
                }
            }
            else
            {
                u16 tmpResultSlopeLeft;

                SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxLeftOffset, pData->yPosition - BLOCK_SIZE,
                    &resultXLeft, &resultYLeft, &resultSlopeLeft);

                pData->yPosition = resultYLeft;
                if (resultSlopeLeft == SLOPE_NONE)
                    pData->yPosition = resultYLeft + SUB_PIXEL_POSITION_FLAG;

                tmpResultSlopeLeft = resultSlopeLeft; // Needed to produce matching ASM.
                pData->currentSlope = (tmpResultSlopeLeft = resultSlopeLeft);
            }
        }
        else if (collisionRight != CLIPDATA_TYPE_AIR)
        {
            if (resultSlopeRight != SLOPE_NONE)
            {
                pData->currentSlope = resultSlopeRight;
                pData->yPosition = resultYRight;
            }
            else
            {
                SamusCheckCollisionAtPosition(pData->xPosition + pPhysics->hitboxRightOffset, pData->yPosition - BLOCK_SIZE,
                    &resultXLeft, &resultYLeft, &resultSlopeLeft);

                pData->yPosition = resultYLeft;

                if (resultSlopeLeft == SLOPE_NONE)
                    pData->yPosition = resultYLeft + SUB_PIXEL_POSITION_FLAG;

                pData->currentSlope = resultSlopeLeft;
            }
        }
        else
        {
            return SPOSE_NONE;
        }

        return SPOSE_LANDING_REQUEST;
    }

    if (collisionLeft != CLIPDATA_TYPE_AIR)
    {
        if (resultSlopeLeft != SLOPE_NONE)
        {
            pData->currentSlope = resultSlopeLeft;
            pData->yPosition = resultYLeft;
            return SPOSE_LANDING_REQUEST;
        }

        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
        pPhysics->touchingSideBlock++;
    }
    else if (collisionRight != CLIPDATA_TYPE_AIR)
    {
        if (resultSlopeRight != SLOPE_NONE)
        {
            pData->currentSlope = resultSlopeRight;
            pData->yPosition = resultYRight;
            return SPOSE_LANDING_REQUEST;
        }

        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;
        pPhysics->touchingSideBlock++;
    }

    return SPOSE_NONE;
}

/**
 * @brief 5e1c | 11c | Checks for top collision
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 * @return u8 New pose
 */
u8 SamusCheckTopCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u16 hitbox;
    u8 result;
    u16 topOffset;
    u16* pLeftHitbox;

    u16 nextX;
    u16 nextY;
    u16 nextSlope;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
        hitbox = pPhysics->hitboxLeftOffset;
    else
        hitbox = pPhysics->hitboxRightOffset;
    pLeftHitbox = &pPhysics->hitboxLeftOffset;

    result = SamusCheckTopSideCollisionMidAir(pData, pPhysics, pData->xPosition + hitbox, &nextX);

    if (result & SAMUS_COLLISION_DETECTION_SLOPE)
    {
        if (result & SAMUS_COLLISION_DETECTION_LEFT_MOST)
            pData->xPosition = nextX;

        SamusCheckCollisionAtPosition(pData->xPosition + hitbox, pData->yPosition, &nextX, &nextY, &nextSlope);
        pData->yPosition = nextY;
        pData->currentSlope = nextSlope;

        return SPOSE_LANDING_REQUEST;
    }
    
    if (result != SAMUS_COLLISION_DETECTION_NONE)
    {
        pData->xPosition = nextX;
        pPhysics->touchingSideBlock++;
    }

    result = SamusCheckCollisionAbove(pData, pPhysics->hitboxTopOffset);
    
    if (result == SAMUS_COLLISION_DETECTION_LEFT_MOST)
    {
        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - *pLeftHitbox;
        gPreviousXPosition = pData->xPosition;
    }
    else if (result == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
    {
        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;
        gPreviousXPosition = pData->xPosition;
    }
    else if (result & SAMUS_COLLISION_DETECTION_MIDDILE)
    {
        topOffset = pData->yPosition + pPhysics->hitboxTopOffset;
        pData->yPosition = (topOffset & BLOCK_POSITION_FLAG) - pPhysics->hitboxTopOffset + BLOCK_SIZE;
        pData->yVelocity = 0;
        pPhysics->touchingTopBlock++;
    }

    return SPOSE_NONE;
}

/**
 * @brief 5f38 | 2dc | Checks the collisions for Samus
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus Physics Pointer
 */
void SamusCheckCollisions(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 newPose;
    s32 xOffset;
    u32 blockPrevent;
    u32 blockGrabbing;
    u32 blockAbove;
    s32 movementBlock;

    if (pPhysics->standingStatus > STANDING_NOT_IN_CONTROL)
        return;

    // Apply speedbooster/screw damage
    SamusCheckScrewSpeedboosterAffectingEnvironment(pData, pPhysics);

    newPose = SPOSE_NONE;

    if (pPhysics->verticalMovingDirection == VDMOVING_UP)
    {
        newPose = SamusCheckTopCollision(pData, pPhysics);
    }
    else if (pPhysics->verticalMovingDirection == VDMOVING_DOWN)
    {
        newPose = SamusCheckLandingCollision(pData, pPhysics);
    }
    else if (pPhysics->horizontalMovingDirection != VDMOVING_NONE)
    {
        if (pPhysics->standingStatus == STANDING_MIDAIR)
        {
            newPose = SamusCheckLandingCollision(pData, pPhysics);
        }
        else
        {
            newPose = SamusCheckWalkingSidesCollision(pData, pPhysics);
            if (newPose == SPOSE_NONE)
                newPose = unk_5AD8(pData, pPhysics);
        }
    }
    else
    {
        if (pPhysics->standingStatus == STANDING_GROUND)
            newPose = SamusCheckStandingOnGroundCollision(pData, pPhysics);
    }

    if (newPose == SPOSE_NONE && gEquipment.suitMiscActivation & SMF_POWER_GRIP && gButtonInput & pData->direction && pData->yVelocity < 1)
    {
        if (pData->direction & KEY_RIGHT)
            xOffset = (HALF_BLOCK_SIZE - ONE_SUB_PIXEL);
        else
            xOffset = -(HALF_BLOCK_SIZE - ONE_SUB_PIXEL);

        blockPrevent = ClipdataProcessForSamus(pData->yPosition + HALF_BLOCK_SIZE, pData->xPosition);
        if (blockPrevent == CLIPDATA_TYPE_AIR)
        {
            blockPrevent = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), pData->xPosition);
            blockPrevent &= CLIPDATA_TYPE_SOLID_FLAG;

            blockGrabbing = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                pData->xPosition + xOffset);
            blockGrabbing &= CLIPDATA_TYPE_SOLID_FLAG;

            blockAbove = ClipdataProcessForSamus(pData->yPosition - BLOCK_SIZE * 2, pData->xPosition + xOffset);
            blockAbove &= CLIPDATA_TYPE_SOLID_FLAG;

            switch (pData->pose)
            {
                case SPOSE_MIDAIR:
                case SPOSE_STARTING_SPIN_JUMP:
                case SPOSE_SPINNING:
                case SPOSE_STARTING_WALL_JUMP:
                case SPOSE_SPACE_JUMPING:
                case SPOSE_SCREW_ATTACKING:
                    movementBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(pData->yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        pData->xPosition + xOffset));

                    if (!blockPrevent && blockGrabbing && movementBlock != CLIPDATA_MOVEMENT_NON_POWER_GRIP && !blockAbove)
                    {
                        if (gEquipment.suitType == SUIT_SUITLESS)
                        {
                            newPose = SPOSE_GRABBING_A_LEDGE_SUITLESS;
                            SoundPlay(SOUND_SUITLESS_GRAB_LEDGE);
                        }
                        else
                        {
                            newPose = SPOSE_HANGING_ON_LEDGE;
                            if (pPhysics->slowedByLiquid)
                                SoundPlay(SOUND_WATER_MOVEMENT_WALL_JUMP);
                            else
                                SoundPlay(SOUND_GRAB_LEDGE);
                        }
                    }
            }
        }
    }

    if (pPhysics->touchingSideBlock)
    {
        pData->xVelocity = 0;

        switch (pData->pose)
        {
            case SPOSE_RUNNING:
                if (gEquipment.suitType == SUIT_SUITLESS && gSamusDataCopy.timer == 1)
                    newPose = SPOSE_CROUCHING_TO_CRAWL;
                break;

            case SPOSE_SPINNING:
            case SPOSE_SCREW_ATTACKING:
                pData->walljumpTimer = 8;
                pData->lastWallTouchedMidAir = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
                break;

            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
            case SPOSE_TURNING_ON_ZIPLINE:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                newPose = SPOSE_MID_AIR_REQUEST;
        }
    }

    if (pPhysics->standingStatus != STANDING_INVALID)
    {
        if (newPose == SPOSE_MID_AIR_REQUEST)
            pData->yPosition++;

        if (newPose != SPOSE_NONE)
            SamusSetPose(newPose);
    }
}

/**
 * 6214 | 3dc | Checks if an environment effect for samus can/should spawn and spawns it
 * 
 * @param pData Samus data pointer
 * @param defaultOffset Default offset in the global array (0 means auto)
 * @param request Environmental effect requested
 */
void SamusCheckSetEnvironmentalEffect(struct SamusData* pData, u32 defaultOffset, u32 request)
{
    u8 found;
    u8 effect;
    u8 canSpawn;
    u8 i;
    u16 yPosition;
    u16 xPosition;
    u16 nextX;
    u32 affecting;
    u32 previousAffecting;
    u16 liquidCheckY;
    u16 previousY;
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;
    found = FALSE;
    canSpawn = TRUE;

    if (defaultOffset == 0)
    {
        for (i = 0; i < 3; i++)
        {
            if (gSamusEnvironmentalEffects[i].type == ENV_EFFECT_NONE)
                break;
        }

        if (i > 2)
            canSpawn--;
    }
    else
        i = defaultOffset;

    switch (request)
    {
        case WANTING_RUNNING_EFFECT:
        case WANTING_RUNNING_EFFECT_:
            // Check forward
            if (pData->direction & KEY_RIGHT)
                nextX = pData->xPosition + PIXEL_SIZE;
            else
                nextX = pData->xPosition - PIXEL_SIZE;

            // Analyze block directly below
            affecting = ClipdataCheckGroundEffect(pData->yPosition + ONE_SUB_PIXEL, nextX);

            // Apply ground effect
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(SOUND_SUITLESS_FOOTSTEPS_WET_GROUND_1);
                    else
                        SoundPlay(SOUND_FOOTSTEPS_WET_GROUND_1);
                }
                else
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(SOUND_SUITLESS_FOOTSTEPS_WET_GROUND_2);
                    else
                        SoundPlay(SOUND_FOOTSTEPS_WET_GROUND_2);
                }
            }
            else if (affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(SOUND_FOOTSTEPS_DUSTY_GROUND_1);
                else
                    SoundPlay(SOUND_FOOTSTEPS_DUSTY_GROUND_2);
            }
            else if (affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(SOUND_FOOTSTEPS_DUSTY_GROUND_1);
                else
                    SoundPlay(SOUND_FOOTSTEPS_DUSTY_GROUND_2);
            }

            xPosition = nextX;
            yPosition = pData->yPosition;
            break;

        case WANTING_LANDING_EFFECT:
            // Analyze block directly below
            affecting = ClipdataCheckGroundEffect(pData->yPosition + ONE_SUB_PIXEL, pData->xPosition);

            // Apply ground effect
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_WET_GROUND;
                found++;

                if (gEquipment.suitType == SUIT_SUITLESS)
                    SoundPlay(SOUND_SUITLESS_LANDING_ON_WET_GROUND);
                else
                    SoundPlay(SOUND_GOING_IN_LIQUID);
            }
            else if (affecting == GROUND_EFFECT_BUBBLY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_BUBBLY_GROUND;
                found++;
            }
            else if (affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_DUSTY_GROUND;
                found++;
                SoundPlay(SOUND_LANDING_ON_DUSTY_GROUND);
            }
            else if (affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND;
                found++;
                SoundPlay(SOUND_LANDING_ON_DUSTY_GROUND);
            }
            else
            {
                if (pPhysics->slowedByLiquid)
                    SoundPlay(SOUND_WATER_MOVEMENT_WALL_JUMP);
                else if (gSamusDataCopy.lastWallTouchedMidAir != 0)
                    SoundPlay(SOUND_MORPH_BALL_LANDING);
                else if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(SOUND_LANDING);
                else
                    SoundPlay(SOUND_SUITLESS_LANDING);
            }

            xPosition = pData->xPosition;
            yPosition = pData->yPosition;
            break;

        case WANTING_GOING_OUT_OF_LIQUID_EFFECT:
        case WANTING_RUNNING_OUT_OF_LIQUID_EFFECT:
            liquidCheckY = pData->yPosition;
            previousY = gPreviousYPosition;

            if (request == WANTING_GOING_OUT_OF_LIQUID_EFFECT)
            {
                // Offset check slightly up
                liquidCheckY -= QUARTER_BLOCK_SIZE;
                previousY -= QUARTER_BLOCK_SIZE;
            }

            // Got current and previous liquid state
            affecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(liquidCheckY, pData->xPosition));
            previousAffecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(previousY, pData->xPosition));

            if (liquidCheckY < previousY)
            {
                // Currently moving up, check if the liquid state changed
                if (affecting != HAZARD_TYPE_WATER && previousAffecting == HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (affecting != HAZARD_TYPE_STRONG_LAVA && previousAffecting == HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (affecting != HAZARD_TYPE_WEAK_LAVA && previousAffecting == HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (affecting != HAZARD_TYPE_ACID && previousAffecting == HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_ACID;
                    found++;
                }
            }
            else
            {
                // Currently moving down, check if the liquid state changed
                if (affecting == HAZARD_TYPE_WATER && previousAffecting != HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (affecting == HAZARD_TYPE_STRONG_LAVA && previousAffecting != HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (affecting == HAZARD_TYPE_WEAK_LAVA && previousAffecting != HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (affecting == HAZARD_TYPE_ACID && previousAffecting != HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_ACID;
                    found++;
                }
            }

            if (request == WANTING_RUNNING_OUT_OF_LIQUID_EFFECT)
                effect++;

            xPosition = pData->xPosition;

            // Get Y position
            if (gEffectYPosition != 0)
            {
                // Snap to effect position
                yPosition = gEffectYPosition;
            }
            else
            {
                // Use block position
                if (liquidCheckY < previousY)
                    yPosition = gPreviousYPosition & BLOCK_POSITION_FLAG;
                else
                    yPosition = pData->yPosition & BLOCK_POSITION_FLAG;
            }

            break;

        case WANTING_BREATHING_BUBBLES:
            if (pData->standingStatus == STANDING_MIDAIR)
            {
                // Spawn bubbles only on ground
                break;
            }

            effect = ENV_EFFECT_BREATHING_BUBBLES;
            found++;

            if (pData->direction & KEY_RIGHT)
                xPosition = pData->xPosition + (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
            else
                xPosition = pData->xPosition - (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

            // Spawn near head
            yPosition = pData->yPosition + pPhysics->drawDistanceTopOffset + QUARTER_BLOCK_SIZE;
            SoundPlay(SOUND_WATER_BUBBLES);
            break;

        case WANTING_SKIDDING_EFFECT:
            // Analyze block directly below
            affecting = ClipdataCheckGroundEffect(pData->yPosition + ONE_SUB_PIXEL, pData->xPosition);

            // Apply ground effect
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_SKIDDING_ON_WET_GROUND;
                found++;
            }
            else if (affecting == GROUND_EFFECT_DUSTY_GROUND || affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND;
                found++;
            }

            xPosition = pData->xPosition;
            yPosition = pData->yPosition;
            break;

        case WANTING_RUNNING_ON_WET_GROUND:
            // Analyze block directly below
            affecting = ClipdataCheckGroundEffect(pData->yPosition + ONE_SUB_PIXEL, pData->xPosition);

            // Apply ground effect
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                xPosition = pData->xPosition;
                yPosition = pData->yPosition;
                found++;
            }
            break;
    }

    if (found & canSpawn)
    {
        // Register effect
        gSamusEnvironmentalEffects[i].type = effect;
        gSamusEnvironmentalEffects[i].currentAnimationFrame = 0;
        gSamusEnvironmentalEffects[i].animationDurationCounter = 0;
        gSamusEnvironmentalEffects[i].xPosition = xPosition;
        gSamusEnvironmentalEffects[i].yPosition = yPosition;
    }
}

/**
 * @brief 65f0 | 360 | Updates the environmental effects
 * 
 * @param pData Samus data pointer
 */
void SamusUpdateEnvironmentalEffect(struct SamusData* pData)
{
    u32 affecting;
    u32 affectingTop;
    u32 affectingLiquid;
    u8 effect;
    u8 i;
    u8 subAnimEnded;
    u16 yPosition;
    u16 liquidY;
    const struct FrameData* pOam;
    struct SamusPhysics* pPhysics;
    struct EnvironmentalEffect* pEnv;

    if (pData->pose == SPOSE_DYING)
        return;

    pPhysics = &gSamusPhysics;
    pEnv = gSamusEnvironmentalEffects;

    // Check set out of liquid effects
    switch (pData->pose)
    {
        case SPOSE_MIDAIR:
        case SPOSE_TURNING_AROUND_MIDAIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
        case SPOSE_GETTING_HURT:
        case SPOSE_GETTING_KNOCKED_BACK:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            SamusCheckSetEnvironmentalEffect(pData, 3, WANTING_GOING_OUT_OF_LIQUID_EFFECT);
            break;

        case SPOSE_RUNNING:
        case SPOSE_ROLLING:
            SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_RUNNING_OUT_OF_LIQUID_EFFECT);
    }

    // Check for breathing bubbles
    if (LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(pData->yPosition - BLOCK_SIZE * 2, pData->xPosition)) == HAZARD_TYPE_WATER)
    {
        // Head of samus is in water, update timer
        if (pEnv->breathingTimer < 220)
        {
            pEnv->breathingTimer++;
        }
        else
        {
            // Try to spawn bubbles
            SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_BREATHING_BUBBLES);
            pEnv->breathingTimer = 0;
        }
    }

    // Use last slot, reserved for the taking damage in liquid effects
    pEnv += ARRAY_SIZE(gSamusEnvironmentalEffects) - 1;

    // Check is available
    if (pEnv->type == ENV_EFFECT_NONE)
    {
        switch (pData->pose)
        {
            case SPOSE_HANGING_ON_LEDGE:
            case SPOSE_TURNING_TO_AIM_WHILE_HANGING:
            case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_SHOOTING_WHILE_HANGING:
            case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
            case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
            case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
                // Offset position slightly up when hanging to not take into account the feets
                yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
                break;

            default:
                // Use normal position
                yPosition = pData->yPosition;
        }

        // Get liquid at the current position and above samus
        affecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition));
        affectingTop = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(yPosition + pPhysics->drawDistanceTopOffset - PIXEL_SIZE * 2,
            pData->xPosition));

        if (pPhysics->drawDistanceTopOffset > -BLOCK_SIZE)
            liquidY = yPosition - BLOCK_SIZE;
        else
            liquidY = yPosition + pPhysics->drawDistanceTopOffset;

        affectingLiquid = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(liquidY, pData->xPosition));

        subAnimEnded = FALSE;

        // Check is only half-way in a liquid and can be damaged by said liquid
        if (affecting == HAZARD_TYPE_STRONG_LAVA && affectingTop != HAZARD_TYPE_STRONG_LAVA)
        {
            // Strong lava, check has gravity
            if (!(gEquipment.suitMiscActivation & SMF_GRAVITY_SUIT))
            {
                effect = ENV_EFFECT_TAKING_DAMAGE_IN_LAVA;
                subAnimEnded++;
            }
        }
        else if (affecting == HAZARD_TYPE_WEAK_LAVA && affectingTop != HAZARD_TYPE_WEAK_LAVA)
        {
            // Weak lava, check has varia or gravity
            if (!(gEquipment.suitMiscActivation & SMF_ALL_SUITS))
            {
                effect = ENV_EFFECT_TAKING_DAMAGE_IN_LAVA;
                subAnimEnded++;
            }
        }
        else if (affecting == HAZARD_TYPE_ACID && affectingTop != HAZARD_TYPE_ACID)
        {
            // Acid, always
            effect = ENV_EFFECT_TAKING_DAMAGE_IN_ACID;
            subAnimEnded++;
        }

        if (subAnimEnded)
        {
            // Setup effect
            pEnv->type = effect;
            pEnv->currentAnimationFrame = 0;
            pEnv->animationDurationCounter = 0;
            pEnv->xPosition = pData->xPosition;

            if (gEffectYPosition != 0)
            {
                // Use effect position if it exists
                pEnv->yPosition = gEffectYPosition;
            }
            else
            {
                if (affectingLiquid == HAZARD_TYPE_STRONG_LAVA || affectingLiquid == HAZARD_TYPE_WEAK_LAVA ||
                    affectingLiquid == HAZARD_TYPE_ACID)
                {
                    // Is a valid liquid, use its position
                    pEnv->yPosition = liquidY & BLOCK_POSITION_FLAG;
                }
                else
                {
                    // Fail safe?
                    pEnv->yPosition = yPosition & BLOCK_POSITION_FLAG;
                }
            }

            SoundPlay(SOUND_LIQUID_DAMAGE);
        }
    }

    // Update every effect
    for (pEnv = gSamusEnvironmentalEffects, i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++, pEnv++)
    {
        effect = pEnv->type;
        if (effect == ENV_EFFECT_NONE)
            continue;

        // Update animation
        pEnv->animationDurationCounter++;

        pOam = sSamusEnvEffectsFrameDataPointers[effect - 1];
        pOam += pEnv->currentAnimationFrame;

        subAnimEnded = FALSE;
        
        if (pEnv->animationDurationCounter >= pOam->timer)
        {
            // Sub anim ended
            pEnv->animationDurationCounter = 0;
            pEnv->currentAnimationFrame++;
            pOam++;

            if (pOam->timer == 0)
            {
                // Animation ended, kill
                pEnv->type = ENV_EFFECT_NONE;
                pEnv->currentAnimationFrame = 0;
            }

            subAnimEnded++;
        }

        // Set oam frame pointer
        pEnv->pOamFrame = pOam->pFrame;

        if (subAnimEnded)
        {
            // Sub anim ended, check play sounds
            switch (effect)
            {
                case ENV_EFFECT_GOING_OUT_OF_WATER:
                case ENV_EFFECT_GOING_OUT_OF_LAVA:
                case ENV_EFFECT_GOING_OUT_OF_ACID:
                    if (pEnv->currentAnimationFrame == 1)
                        SoundPlay(SOUND_GOING_OUT_OF_LIQUID);
                    break;

                case ENV_EFFECT_RUNNING_INTO_WATER:
                case ENV_EFFECT_RUNNING_INTO_LAVA:
                case ENV_EFFECT_RUNNING_INTO_ACID:
                    if (pEnv->currentAnimationFrame == 1)
                        SoundPlay(SOUND_GOING_IN_LIQUID);
                    break;

                case ENV_EFFECT_TAKING_DAMAGE_IN_LAVA:
                case ENV_EFFECT_TAKING_DAMAGE_IN_ACID:
                    pEnv->xPosition = pData->xPosition;
                    break;

                case ENV_EFFECT_SKIDDING_ON_WET_GROUND:
                case ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND:
                    if (i == 0 && pEnv->currentAnimationFrame == 3)
                        SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_SKIDDING_EFFECT);
            }
        }
    }
}

/**
 * 6950 | 2dc | Sets a mid air pose for samus based on the previous pose
 * 
 * @param pData Samus data pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus weapon info pointer
 */
void SamusSetMidAir(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    struct Equipment* pEquipment;

    pEquipment = &gEquipment;

    // Carry X velocity, ACD and speedboost status
    pData->xVelocity = pCopy->xVelocity;
    pData->armCannonDirection = pCopy->armCannonDirection;
    pData->speedboostingShinesparking = pCopy->speedboostingShinesparking;

    switch (pCopy->pose)
    {
        case SPOSE_RUNNING:
            if (pCopy->forcedMovement != FORCED_MOVEMENT_MID_AIR_JUMP)
            {
                // Not a jump, just set mid air
                pData->pose = SPOSE_MIDAIR;
                break;
            }

            // Starting a jump, always a spin jump because running implies a direction was held
            pData->pose = SPOSE_STARTING_SPIN_JUMP;

            // Set jump velocity
            if (pEquipment->suitType == SUIT_SUITLESS)
                pData->yVelocity = SAMUS_SUITLESS_JUMP_VELOCITY;
            else if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                pData->yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
            else
                pData->yVelocity = SAMUS_LOW_JUMP_VELOCITY;
            break;

        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            // Trigger a spin break

            // Set mid air, cancel X momentum
            pData->pose = SPOSE_MIDAIR;
            pData->xVelocity = 0;

            // Check carry Y velocity
            if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_CARRY)
                pData->yVelocity = pCopy->yVelocity;

            // Offset down if there's a ceiling to prevent going into the ceiling
            if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) != SAMUS_COLLISION_DETECTION_NONE)
                pData->yPosition += HALF_BLOCK_SIZE;
            break;

        case SPOSE_STARTING_WALL_JUMP:
            if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_FALL)
            {
                // Cancel wall jump, drop samus
                pData->pose = SPOSE_MIDAIR;
                break;
            }

            // Perform wall jump, set spinning
            pData->pose = SPOSE_SPINNING;

            if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
            {
                if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                    pData->yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
                else
                    pData->yVelocity = SAMUS_LOW_JUMP_VELOCITY;
            }

            // Play sounds and set slowed velocity
            if (gSamusPhysics.slowedByLiquid)
            {
                pData->yVelocity = SAMUS_HIGH_JUMP_VELOCITY / 2;
                SoundPlay(SOUND_WATER_MOVEMENT_WALL_JUMP);
            }
            else if (gEquipment.suitType != SUIT_SUITLESS)
            {
                SoundPlay(SOUND_WALL_JUMP);
            }
            else
            {
                SoundPlay(SOUND_SUITLESS_WALL_JUMP);
            }
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            // Check perform bomb jump
            if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
            {
                // Set direction and velocity
                pData->direction = KEY_RIGHT;

                pData->xVelocity = SAMUS_BOMB_BOUNCE_X_VELOCITY;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_UP)
            {
                // Set velocity
                pData->xVelocity = 0;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_LEFT)
            {
                // Set direction and velocity
                pData->direction = KEY_LEFT;

                pData->xVelocity = -SAMUS_BOMB_BOUNCE_X_VELOCITY;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
            // Keep CAF and ADC to smoothly transition between the animations (the morph ball spin)
            pData->currentAnimationFrame = pCopy->currentAnimationFrame;
            pData->animationDurationCounter = pCopy->animationDurationCounter;

        case SPOSE_MORPHING:
            // Check perform bomb jump
            if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
            {
                // Set direction and velocity
                pData->direction = KEY_RIGHT;

                pData->xVelocity = SAMUS_BOMB_BOUNCE_X_VELOCITY;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_UP)
            {
                // Set velocity
                pData->xVelocity = 0;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else if (pCopy->forcedMovement == FORCED_MOVEMENT_BOMB_JUMP_LEFT)
            {
                // Set direction and velocity
                pData->direction = KEY_LEFT;

                pData->xVelocity = -SAMUS_BOMB_BOUNCE_X_VELOCITY;
                pData->yVelocity = SAMUS_BOMB_BOUNCE_Y_VELOCITY;

                pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            }
            else
            {
                // Performs a morph ball jump

                // Half the X velocity
                pData->xVelocity = DIV_SHIFT(pData->xVelocity, 2);

                // Check jump
                if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
                    pData->yVelocity = SAMUS_MORPH_BALL_JUMP_VELOCITY;
            }

        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
            // Set morph ball mid air
            pData->pose = SPOSE_MORPH_BALL_MIDAIR;
            break;

        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
            if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) != SAMUS_COLLISION_DETECTION_NONE)
                pData->yPosition += HALF_BLOCK_SIZE;

        default:
            // Set mid air
            pData->pose = SPOSE_MIDAIR;

            if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
            {
                // Set mid air pose, spinning if holding a sideways direction
                if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
                    pData->pose = SPOSE_STARTING_SPIN_JUMP;
                else
                    pData->pose = SPOSE_MIDAIR;

                // Set Y velocity
                if (pEquipment->suitType == SUIT_SUITLESS)
                    pData->yVelocity = SAMUS_SUITLESS_JUMP_VELOCITY;
                else if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                    pData->yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
                else
                    pData->yVelocity = SAMUS_LOW_JUMP_VELOCITY;
            }
            else if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_CARRY)
            {
                // Carry Y velocity
                pData->yVelocity = pCopy->yVelocity;
            }
    }

    // Play jumping sounds
    if (pCopy->forcedMovement == FORCED_MOVEMENT_MID_AIR_JUMP)
    {
        if (pData->pose == SPOSE_MIDAIR)
        {
            if (!gSamusPhysics.slowedByLiquid)
            {
                if (pData->yVelocity == SAMUS_LOW_JUMP_VELOCITY)
                    SoundPlay(SOUND_LOW_JUMP);
                else if (pData->yVelocity == SAMUS_HIGH_JUMP_VELOCITY)
                    SoundPlay(SOUND_HIGH_JUMP);
                else if (pData->yVelocity == SAMUS_SUITLESS_JUMP_VELOCITY)
                    SoundPlay(SOUND_SUITLESS_JUMP);
            }
            else
                SoundPlay(SOUND_WATER_MOVEMENT_GRABBING_LEDGE);
        }
        else if (pData->pose == SPOSE_MORPH_BALL_MIDAIR)
        {
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(SOUND_WATER_MOVEMENT_GRABBING_LEDGE);
            else
                SoundPlay(SOUND_MORPH_BALL_JUMP);
        }
    }
}

/**
 * @brief 6c2c | 280 | Sets a landing pose for Samus
 * 
 * @param pData Samus data pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus weapon info pointer
 */
void SamusSetLandingPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    u32 collision;

    // Reset mid air wall
    pCopy->lastWallTouchedMidAir = KEY_NONE;

    switch (pCopy->pose)
    {
        case SPOSE_MIDAIR:
            collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);
            if (collision != SAMUS_COLLISION_DETECTION_NONE)
            {
                // Blocks above, set crouched
                pData->pose = SPOSE_CROUCHING;
                break;
            }
            
            if (pCopy->xVelocity == 0)
            {
                // No X movement, normal landing
                pData->pose = SPOSE_LANDING;
                break;
            }
            
            if (pCopy->speedboostingShinesparking)
            {
                // Landing from a fall with speedbooster activated
                pData->pose = SPOSE_RUNNING;

                // Intended to keep speedbooster, however it's immediatly cancelled because of the velocity being too small
                pData->speedboostingShinesparking = TRUE;
                break;
            }

            pData->pose = SPOSE_STANDING;
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            pCopy->lastWallTouchedMidAir++; // 1

            if (gButtonInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
            {
                // Check bounce from maintained A
                collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

                if (!(collision & SAMUS_COLLISION_DETECTION_MIDDILE))
                    pData->forcedMovement = FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP;
            }
            else
            {
                if (pCopy->yVelocity < -SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) && !gSamusPhysics.slowedByLiquid &&
                    ClipdataCheckGroundEffect(pData->yPosition + ONE_SUB_PIXEL, pData->xPosition) != GROUND_EFFECT_VERY_DUSTY_GROUND)
                {
                    // Morph ball bounce
                    pData->forcedMovement = FORCED_MOVEMENT_MORPH_BALL_BOUNCE_AFTER_FALL;
                    pData->yVelocity = SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE + PIXEL_SIZE / 2 + ONE_SUB_PIXEL / 4.f);
                    break;
                }
            }

        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            pData->pose = SPOSE_MORPH_BALL;
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (gButtonInput & pData->direction)
            {
                // Carry shinespark
                if (pData->direction & KEY_RIGHT)
                    pData->xVelocity = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
                else
                    pData->xVelocity = -SAMUS_X_SPEEDBOOST_VELOCITY_CAP;

                if (pCopy->pose == SPOSE_SHINESPARKING)
                {
                    pData->pose = SPOSE_RUNNING;
                }
                else
                {
                    pData->pose = SPOSE_ROLLING;
                    pData->shinesparkTimer = 6;
                }

                pData->speedboostingShinesparking = TRUE;
                pData->timer = 160;
                SoundPlay(SOUND_SPEEDBOOSTER_START);
            }
            else
            {
                // Horizontal screen shake
                ScreenShakeStartHorizontal(30, 1);

                // Set collision behavior
                if (pCopy->pose == SPOSE_SHINESPARKING)
                    pData->pose = SPOSE_SHINESPARK_COLLISION;
                else
                    pData->pose = SPOSE_BALLSPARK_COLLISION;

                // Keep direction
                pData->forcedMovement = pCopy->forcedMovement;
                pData->currentAnimationFrame = 1;
                SoundPlay(SOUND_SHINESPARK_COLLISION);
            }
            break;

        default:
            collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);
            if (collision != SAMUS_COLLISION_DETECTION_NONE)
            {
                // Blocks above, set crouched
                pData->pose = SPOSE_CROUCHING;
                break;
            }
            
            if (pCopy->xVelocity == 0)
            {
                // No X movement, normal landing
                pData->pose = SPOSE_LANDING;
                break;
            }

            pData->pose = SPOSE_STANDING;
            break;
    }

    // Carry ACD
    pData->armCannonDirection = pCopy->armCannonDirection;

    // Update ACD, convert up and down to diagonal variations
    switch (pData->pose)
    {
        case SPOSE_LANDING:
            if (gSamusPhysics.hasNewProjectile)
                pData->currentAnimationFrame = 1;

            if (pCopy->armCannonDirection == ACD_DOWN)
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
            break;

        case SPOSE_RUNNING:
            if (pCopy->armCannonDirection == ACD_UP)
                pData->armCannonDirection = ACD_DIAGONALLY_UP;

        case SPOSE_STANDING:
            if (pCopy->armCannonDirection == ACD_DOWN)
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
    }

    // Check effect
    SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_LANDING_EFFECT);
}

void SamusChangeToHurtPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    s16 xVelocity; 
    s16 yVelocity; 
    u8 collision;

    if (gEquipment.currentEnergy != 0)
    {
        collision = SAMUS_COLLISION_DETECTION_NONE;
        switch (pCopy->pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            case SPOSE_DELAY_BEFORE_BALLSPARKING:
            case SPOSE_BALLSPARK_COLLISION:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
            case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
                // Set hurt
                pData->pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            case SPOSE_CRAWLING_STOPPED:
            case SPOSE_STARTING_TO_CRAWL:
            case SPOSE_CRAWLING:
            case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            case SPOSE_SHOOTING_WHILE_CRAWLING:
                // Stop crawling if getting hurt
                pData->pose = SPOSE_CRAWLING_STOPPED;
                pData->xVelocity = 0;
                break;

            default:
                // Get collision above
                collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

                // Set hurt
                pData->pose = SPOSE_GETTING_HURT;
        }

        if (collision != SAMUS_COLLISION_DETECTION_NONE)
            pData->yPosition |= SUB_PIXEL_POSITION_FLAG;

        if (pCopy->forcedMovement == FORCED_MOVEMENT_DAMAGED_BY_RUINS_TEST)
            pData->forcedMovement = 0x1;

        // Set upwards velocity
        pData->yVelocity = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2);
        if (pCopy->standingStatus == STANDING_MIDAIR)
            pData->yVelocity = SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE * 2 - ONE_SUB_PIXEL);

        pData->armCannonDirection = pCopy->armCannonDirection;
        SoundPlay(SOUND_HURT);
    }
    else
    {
        // Disable scrolling and fade screen to black
        gDisableScrolling = TRUE;
        gMonochromeBgFading = MONOCHROME_FADING_BLACK;
        pData->pose = SPOSE_DYING;

        // Set velocity to go to the center of the screen
        xVelocity = gBg1XPosition + SCREEN_SIZE_X * 2 - pData->xPosition;
        xVelocity = DIV_SHIFT(xVelocity, 2);
        pData->xVelocity = xVelocity;

        yVelocity = gBg1YPosition + SCREEN_SIZE_Y * 2 + SCREEN_SIZE_Y / 2 - pData->yPosition;
        yVelocity = DIV_SHIFT(yVelocity, 16);
        pData->yVelocity = yVelocity;

        // Change sub game move
        gGameModeSub1 = SUB_GAME_MODE_DYING;
    }

    // Set invincible
    pData->invincibilityTimer = 48;

    // Cancel shinespark/speedboost
    pData->shinesparkTimer = 0;

    // Set mid air
    pData->standingStatus = STANDING_MIDAIR;

    // Cancel any projectile
    pWeapon->newProjectile = PROJECTILE_CATEGORY_NONE;
    pWeapon->beamReleasePaletteTimer = 0;
}

void SamusChangeToKnockbackPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    u8 collision;

    collision = SAMUS_COLLISION_DETECTION_NONE;
    switch (pCopy->pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            // Set knocked back
            pData->pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
            // Stop crawling if getting knocked back
            pData->pose = SPOSE_CRAWLING_STOPPED;
            break;

        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            break;

        default:
            // Get collision above
            collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

            // Set knocked back
            pData->pose = SPOSE_GETTING_KNOCKED_BACK;
    }

    if (collision != SAMUS_COLLISION_DETECTION_NONE)
        pData->yPosition |= SUB_PIXEL_POSITION_FLAG;

    // Set upwards velocity
    pData->yVelocity = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2);
    if (pCopy->standingStatus == STANDING_MIDAIR)
        pData->yVelocity = SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE * 2 - ONE_SUB_PIXEL);

    pData->armCannonDirection = pCopy->armCannonDirection;
    pData->shinesparkTimer = 0;
    pData->standingStatus = STANDING_MIDAIR;
    pWeapon->newProjectile = PROJECTILE_CATEGORY_NONE;
    pWeapon->beamReleasePaletteTimer = 0;
}

/**
 * @brief 7164 | 384 | Carries what should be carried from the samus data copy, also handles shinespark direction selection
 * 
 * @param pData Samus data pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus weapon info pointer
 */
void SamusCheckCarryFromCopy(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            // Carry aim if diagonal or weapon is armed, otherwise default to none
            if (gButtonInput & gButtonAssignments.diagonalAim || gButtonInput & gButtonAssignments.armWeapon)
                pData->armCannonDirection = pCopy->armCannonDirection;
            else
                pData->armCannonDirection = ACD_NONE;
            break;

        case SPOSE_STANDING:
            pData->armCannonDirection = pCopy->armCannonDirection;
            if (pCopy->pose == SPOSE_CROUCHING || pCopy->pose == SPOSE_SHOOTING_AND_CROUCHING)
            {
                // Timer to ignore input for arm cannon direction, prevents immediatly aiming up after uncrouching
                pData->timer = 6;
            }
            break;

        case SPOSE_CROUCHING:
            // Carry ACD
            pData->armCannonDirection = pCopy->armCannonDirection;
            pData->currentAnimationFrame = 1;

            if (pData->armCannonDirection != ACD_FORWARD && pData->armCannonDirection != ACD_DIAGONALLY_UP &&
                pData->armCannonDirection != ACD_DIAGONALLY_DOWN)
            {
                pData->armCannonDirection = ACD_FORWARD;
            }
            break;

        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            // Copy slowed flag
            pData->timer = gSamusPhysics.slowedByLiquid;

            // Play grabbing ledge sound effect
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(SOUND_WATER_MOVEMENT_GRABBING_LEDGE);
            else if (gEquipment.suitType != SUIT_SUITLESS)
                SoundPlay(SOUND_GRABBING_LEDGE);
            else
                SoundPlay(SOUND_SUITLESS_GRABBING_LEDGE);
            
        case SPOSE_MORPH_BALL:
            if (pCopy->speedboostingShinesparking)
            {
                // Timer for shinespark carry
                pData->timer = 6;
            }

            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_SKIDDING:
            // Carry x velocity
            pData->xVelocity = pCopy->xVelocity;
            pWeapon->diagonalAim = DIAG_AIM_NONE;

            // Set skidding effect
            SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_SKIDDING_EFFECT);
            SoundPlay(SOUND_SKIDDING);
            break;


        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            pData->shinesparkTimer = 50;
            SoundPlay(SOUND_SHINESPARKING);
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (pCopy->forcedMovement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
            {
                // Force upwards shinespark
                pData->yVelocity = SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
            }
            else if (gButtonInput & gButtonAssignments.diagonalAim)
            {
                // Pressed diagonal input, do a diagonal shinespark
                pData->forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;

                // Input direction
                if (pData->direction & KEY_RIGHT)
                    pData->xVelocity = SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
                else
                    pData->xVelocity = -SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;

                // Set Y velocity
                pData->yVelocity = SAMUS_DIAGONAL_SHINESPARK_Y_VELOCITY;
            }
            else if (gButtonInput & pData->direction)
            {
                // Inputted a sideways direction
                if (gButtonInput & KEY_UP)
                {
                    // Pressed up, do a diagonal spark
                    pData->forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;

                    // Input direction
                    if (pData->direction & KEY_RIGHT)
                        pData->xVelocity = SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
                    else
                        pData->xVelocity = -SAMUS_DIAGONAL_SHINESPARK_X_VELOCITY;
                    
                    // Set Y velocity
                    pData->yVelocity = SAMUS_DIAGONAL_SHINESPARK_Y_VELOCITY;
                }
                else
                {
                    // Performs a sidewards spark
                    pData->forcedMovement += FORCED_MOVEMENT_SIDEWARDS_SHINESPARK;

                    // Input direction
                    if (pData->direction & KEY_RIGHT)
                        pData->xVelocity = SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
                    else
                        pData->xVelocity = -SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
                }
            }
            else
            {
                // Go up by default
                pData->yVelocity = SAMUS_SIDEWARD_SHINESPARK_X_VELOCITY;
            }

            pData->speedboostingShinesparking++;
            pData->shinesparkTimer = 0;

            pWeapon->diagonalAim = DIAG_AIM_NONE;
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            break;

        case SPOSE_SHINESPARK_COLLISION:
            pData->forcedMovement = pCopy->forcedMovement;
            pData->currentAnimationFrame = 1;

        case SPOSE_BALLSPARK_COLLISION:
            pData->invincibilityTimer = 48;
            SoundPlay(SOUND_SHINESPARK_COLLISION);
            break;

        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            // Check is launched by cannon
            if (pCopy->forcedMovement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
                pData->forcedMovement = FORCED_MOVEMENT_LAUNCHED_BY_CANNON;
            else
                gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            SoundPlay(SOUND_BALLSPARKING);
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_GRABBING_A_LEDGE_SUITLESS:
            if ((pData->yPosition & SUB_PIXEL_POSITION_FLAG) < SUB_PIXEL_POSITION_FLAG / 2)
                pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) + EIGHTH_BLOCK_SIZE;
            else
                pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            pWeapon->diagonalAim = DIAG_AIM_NONE;

            gSamusEcho.active = FALSE;
            gSamusEcho.timer = 0;
            break;

        case SPOSE_USING_AN_ELEVATOR:
            // Carry elevator direction
            pData->elevatorDirection = pCopy->elevatorDirection;

            // Set velocity
            if (pData->elevatorDirection & KEY_UP)
                pData->yVelocity = SAMUS_ELEVATOR_SPEED;
            else
                pData->yVelocity = -SAMUS_ELEVATOR_SPEED;
            
            SoundPlay(SOUND_ELEVATOR);
            break;

        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
            SAMUS_CARRY_ELEVATOR_DIR();
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_ON_ZIPLINE:
            if (pCopy->pose != SPOSE_SHOOTING_ON_ZIPLINE && pCopy->pose != SPOSE_TURNING_ON_ZIPLINE)
            {
                // Entered zipline, reset diagonal aim
                pWeapon->diagonalAim = DIAG_AIM_NONE;

                // Play zipline sound
                if (gEquipment.suitType == SUIT_SUITLESS)
                    SoundPlay(SOUND_SUITLESS_GRAB_LEDGE);
                else
                    SoundPlay(SOUND_GRAB_LEDGE);
            }
            else
            {
                // Was already on zipline, carry ACD
                pData->armCannonDirection = pCopy->armCannonDirection;
            }

            break;

        case SPOSE_SAVING_LOADING_GAME:
            pData->lastWallTouchedMidAir = pCopy->lastWallTouchedMidAir;
        
        case SPOSE_DOWNLOADING_MAP_DATA:
            pData->timer = 1;

        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_CROUCHING_TO_CRAWL:
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_CRAWLING_STOPPED:
            // Check set the forced movement to have the frame of samus holding the pistol up when stopped
            if (pCopy->pose == SPOSE_SHOOTING_WHILE_CRAWLING)
                pData->forcedMovement = FORCED_MOVEMENT_CROUCHING_ARM_CANNON_UP;
            break;

        case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
            pData->lastWallTouchedMidAir = 1;
            pData->armCannonDirection = pCopy->armCannonDirection;
            break;

        case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
            // Set turning
            pData->turning = TRUE;
            break;
        
        case SPOSE_TURNING_AROUND_MIDAIR:
            // Carry Y velocity
            pData->yVelocity = pCopy->yVelocity;

        case SPOSE_TURNING_AROUND:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            // Set turning
            pData->turning = TRUE;

            // Carry arm cannon direction
            pData->armCannonDirection = pCopy->armCannonDirection;
            break;

        case SPOSE_IN_ESCAPE_SHIP:
            break;
        
        default:
            // Carry arm cannon direction
            pData->armCannonDirection = pCopy->armCannonDirection;
    }
}

/**
 * @brief 74e8 | d4 | Changes the current pose of Samus
 * 
 * @param pose New pose
 */
void SamusSetPose(u8 pose)
{
    struct WeaponInfo* pWeapon;
    struct SamusData* pData;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pCopy = &gSamusDataCopy;
    pWeapon = &gSamusWeaponInfo;

    if (pose == SPOSE_KNOCKBACK_REQUEST || pose == SPOSE_HURT_REQUEST)
        pData->turning = FALSE;

    // Backup samus data
    SamusCopyData(pData);

    // Remove no ACD
    if (pCopy->armCannonDirection == ACD_NONE)
        pCopy->armCannonDirection = ACD_FORWARD;

    // Check cancel speedbooster sounds
    switch (pCopy->pose)
    {
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARKING)
                SoundStop(SOUND_SHINESPARKING);
            break;
        
        case SPOSE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARK_COLLISION)
                SoundStop(SOUND_SHINESPARKING);
            break;
        
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARKING)
                SoundStop(SOUND_BALLSPARKING);
            break;
        
        case SPOSE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARK_COLLISION)
                SoundStop(SOUND_BALLSPARKING);
            break;
    }

    // Handle sub frame poses
    switch (pose)
    {
        case SPOSE_MID_AIR_REQUEST:
            SamusSetMidAir(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_LANDING_REQUEST:
            SamusSetLandingPose(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_HURT_REQUEST:
            SamusChangeToHurtPose(pData, pCopy, pWeapon);
            break;
        
        case SPOSE_KNOCKBACK_REQUEST:
            SamusChangeToKnockbackPose(pData, pCopy, pWeapon);
            break;

        default:
            // Normal pose, set hit and process carry
            pData->pose = pose;
            SamusCheckCarryFromCopy(pData, pCopy, pWeapon);
    }
}

/**
 * 75bc | 60 | Copies samus data to the samus data copy and resets samus data 
 * 
 * @param pData_ Samus data pointer (unused)
 */
void SamusCopyData(struct SamusData* pData_)
{
    struct SamusData* pData;
    struct ScrewSpeedAnimation* pScrew;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pScrew = &gScrewSpeedAnimation;
    pCopy = &gSamusDataCopy;

    // Backup data before doing any change
    *pCopy = *pData;

    // Apply turning
    if (pData->turning)
    {
        pData->direction ^= KEY_LEFT | KEY_RIGHT;
        pData->turning = FALSE;
    }

    // Reset most fields
    pData->armCannonDirection = ACD_FORWARD;
    pData->forcedMovement = 0;
    pData->speedboostingShinesparking = FALSE;
    pData->walljumpTimer = 0;
    pData->timer = 0;
    pData->lastWallTouchedMidAir = 0;
    pData->elevatorDirection = 0;
    pData->xVelocity = 0;
    pData->yVelocity = 0;
    pData->animationDurationCounter = 0;
    pData->currentAnimationFrame = 0;

    if (pData->shinesparkTimer != SHINESPARK_TIMER_MAX)
        pScrew->flag = SCREW_SPEED_FLAG_NONE;

    pScrew->animationDurationCounter = 0;
    pScrew->currentAnimationFrame = 0;
}

/**
 * @brief 761c | 110 | Updates the physics of Samus
 * 
 * @param pData Samus data pointer (unused)
 */
void SamusUpdatePhysics(struct SamusData* pData)
{
    struct Equipment* pEquipment;
    struct SamusPhysics* pPhysics;
    u16 yPosition;
    u32 slowed;
    s32 affecting;
    
    pData = &gSamusData;
    pEquipment = &gEquipment;
    pPhysics = &gSamusPhysics;

    gUnk_03004fc9 = FALSE;

    switch (pData->pose)
    {
        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_TURNING_TO_AIM_WHILE_HANGING:
        case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
        case SPOSE_GRABBING_A_LEDGE_SUITLESS:
            // Offset position slightly up when hanging to not take into account the feets
            yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
            break;

        default:
            // Use normal position
            yPosition = pData->yPosition;
    }

    slowed = FALSE;
    // Get effect affecting samus
    affecting = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition));

    switch (affecting)
    {
        case HAZARD_TYPE_WATER:
        case HAZARD_TYPE_STRONG_LAVA:
        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_ACID:
            // In liquid, check has gravity to see if slowed
            if (!(pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT))
                slowed++;
            break;

        default:
            // Check grabbed by metroid
            if (gEquipment.grabbedByMetroid)
                slowed++;
    }

    // Set slowed
    pPhysics->slowedByLiquid = slowed;

    if (slowed)
    {
        // Set slowed physics values
        pPhysics->xAcceleration = SAMUS_X_ACCELERATION / 2;
        pPhysics->xVelocityCap = SAMUS_X_VELOCITY_CAP / 2;
        pPhysics->midairXVelocityCap = SAMUS_X_MID_AIR_VELOCITY_CAP / 2;
        pPhysics->midairXAcceleration = SAMUS_X_MID_AIR_ACCELERATION / 2;
        pPhysics->midairMorphedXVelocityCap = SAMUS_X_MID_AIR_MORPHED_VELOCITY_CAP / 2;

        pPhysics->yAcceleration = SAMUS_Y_ACCELERATION / 2;
        pPhysics->positiveYVelocityCap = SAMUS_Y_SLOWED_VELOCITY_CAP;
        pPhysics->negativeYVelocityCap = SAMUS_Y_SLOWED_VELOCITY_CAP;

        // Cancel shinespark/speedboost
        if (pData->speedboostingShinesparking)
            pData->speedboostingShinesparking = FALSE;
    }
    else
    {
        // Set normal physics values
        pPhysics->xAcceleration = SAMUS_X_ACCELERATION;
        pPhysics->xVelocityCap = SAMUS_X_VELOCITY_CAP;
        pPhysics->midairXVelocityCap = SAMUS_X_MID_AIR_VELOCITY_CAP;
        pPhysics->midairXAcceleration = SAMUS_X_MID_AIR_ACCELERATION;
        pPhysics->midairMorphedXVelocityCap = SAMUS_X_MID_AIR_MORPHED_VELOCITY_CAP;

        pPhysics->yAcceleration = SAMUS_Y_ACCELERATION;
        pPhysics->positiveYVelocityCap = SAMUS_Y_POSITIVE_VELOCITY_CAP;
        pPhysics->negativeYVelocityCap = SAMUS_Y_NEGATIVE_VELOCITY_CAP;

        if (pData->speedboostingShinesparking)
        {
            pPhysics->midairXVelocityCap = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
            pPhysics->xVelocityCap = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
        }
    }

    if (pData->standingStatus == STANDING_MIDAIR || pData->standingStatus == STANDING_ENEMY)
    {
        // No slope if mid air or on an enemy
        pData->currentSlope = SLOPE_NONE;
    }
}

/**
 * @brief 772c | 44 | Changes the velocity of samus based on the slope status
 * 
 * @param pData Samus data pointer
 * @return s16 New velocity
 */
s16 SamusChangeVelocityOnSlope(struct SamusData* pData)
{
    s32 velocity;
    s32 decreasedVelocity;

    velocity = pData->xVelocity;
    
    if (pData->direction & pData->currentSlope)
    {
        if (pData->currentSlope & SLOPE_STEEP)
        {
            // Steep slope, multiply by 0.6
            velocity = (s16)FRACT_MUL(velocity, 3, 5);
        }
        else
        {
            // Slight slope, multiply by 0x8
            velocity = (s16)FRACT_MUL(velocity, 4, 5);
        }
    }
    else
    {
        // Clamp velocity
        CLAMP(velocity, -0xA0, 0xA0);
    }
    
    return velocity;
}

/**
 * @brief 7770 | 2c | Copies the provided palette to Samus's palette
 * 
 * @param src Source Palette Pointer
 * @param offset Destination offset
 * @param nbrColors Number of colors to copy
 */
void SamusCopyPalette(const u16* src, s32 offset, s32 nbrColors)
{
    s32 i;

    for (i = offset; i < offset + nbrColors; i++)
        gSamusPalette[i] = *src++;
}

/**
 * @brief 779c | 4c | Updates samus
 * 
 */
void SamusUpdate(void)
{
    u8 newPose;
    struct SamusData* pData;

    pData = &gSamusData;

    // Update ADC
    if (gGameModeSub1 >= SUB_GAME_MODE_PLAYING)
        pData->animationDurationCounter++;

    // Update physics
    SamusUpdatePhysics(pData);

    // Execute pose subroutine
    newPose = SamusExecutePoseSubroutine(pData);
    if (newPose != SPOSE_NONE)
    {
        // Set new pose if it changed
        SamusSetPose(newPose);
    }

    // Update draw distance
    SamusUpdateDrawDistanceAndStandingStatus(pData, &gSamusPhysics);

    // Update position
    SamusUpdateVelocityPosition(pData);
}

/**
 * @brief 77e8 | f8 | Updates the hitbox and the moving direction of Samus
 * 
 */
void SamusUpdateHitboxMovingDirection(void)
{
    struct SamusData* pData;
    struct SamusPhysics* pPhysics;

    pData = &gSamusData;
    pPhysics = &gSamusPhysics;

    // Reset collision info
    pPhysics->touchingSideBlock = FALSE;
    pPhysics->touchingTopBlock = FALSE;
    pPhysics->unk_5A = 0;

    pPhysics->horizontalMovingDirection = HDMOVING_NONE;
    pPhysics->verticalMovingDirection = VDMOVING_NONE;

    // Update horizontal moving direction
    if (pData->xPosition > gPreviousXPosition)
        pPhysics->horizontalMovingDirection = HDMOVING_RIGHT;
    else if (pData->xPosition < gPreviousXPosition)
        pPhysics->horizontalMovingDirection = HDMOVING_LEFT;

    // Update vertical moving direction
    if (gUnk_03004fc9 == 0)
    {
        if (pData->yPosition > gPreviousYPosition)
            pPhysics->verticalMovingDirection = VDMOVING_DOWN;
        else if (pData->yPosition < gPreviousYPosition)
            pPhysics->verticalMovingDirection = VDMOVING_UP;
    }

    // Update standing status
    pPhysics->standingStatus = sSamusVisualData[pData->pose][2];

    // Update hitbox
    pPhysics->hitboxLeftOffset = sSamusHitboxData[pPhysics->hitboxType][SAMUS_HITBOX_LEFT];
    pPhysics->hitboxRightOffset = sSamusHitboxData[pPhysics->hitboxType][SAMUS_HITBOX_RIGHT];
    pPhysics->hitboxTopOffset = sSamusHitboxData[pPhysics->hitboxType][SAMUS_HITBOX_TOP];

    if (pPhysics->standingStatus == STANDING_NOT_IN_CONTROL)
        pPhysics->verticalMovingDirection = VDMOVING_DOWN;

    SamusCheckCollisions(pData, pPhysics);
    SamusUpdateDrawDistanceAndStandingStatus(pData, pPhysics);
}

/**
 * 78e0 | 3c | Calls functions related to updating samus' graphics
 * 
 */
void SamusCallGfxFunctions(void)
{
    struct SamusData* pData;
    u8 direction;

    pData = &gSamusData;

    // Update env effects if playing
    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
        SamusUpdateEnvironmentalEffect(pData);

    // Get direction
    if (pData->direction & KEY_RIGHT)
        direction = FALSE;
    else
        direction = TRUE;

    // Update samus graphics
    SamusUpdateGraphicsOam(pData, direction);
    SamusUpdatePalette(pData);
}

/**
 * @brief 791c | e | Calls the function that checks for the low health beep
 * 
 */
void SamusCallCheckLowHealth(void)
{
    SamusCheckPlayLowHealthSound();
}

/**
 * @brief 7928 | 20 | Calls the handler that updates the arm cannon offset
 * 
 */
void SamusCallUpdateArmCannonPositionOffset(void)
{
    u8 direction;

    // Get direction
    if (gSamusData.direction & KEY_RIGHT)
        direction = FALSE;
    else
        direction = TRUE;

    // Call function
    SamusUpdateArmCannonPositionOffset(direction);
}

/**
 * @brief 7948 | 5c | Makes Samus bounce on a bomb
 * 
 * @param direction 
 */
void SamusBombBounce(u8 direction)
{
    u8 canBounce;

    if (gSamusPhysics.slowedByLiquid)
        return;

    canBounce = FALSE;

    // Check has a direction
    if (MOD_AND(direction, FORCED_MOVEMENT_BOMB_JUMP_ABOVE) >= FORCED_MOVEMENT_BOMB_JUMP_RIGHT)
    {
        // Check pose
        switch (gSamusData.pose)
        {
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
                canBounce = TRUE;
                break;

            case SPOSE_MORPH_BALL_MIDAIR:
                // Check when falling
                if (gSamusData.yVelocity <= 0 && !(direction & FORCED_MOVEMENT_BOMB_JUMP_ABOVE))
                    canBounce = TRUE;
                break;
        }
    }

    if (canBounce)
    {
        // Make bounce
        gSamusData.forcedMovement = MOD_AND(direction, FORCED_MOVEMENT_BOMB_JUMP_ABOVE);
        SamusSetPose(SPOSE_MID_AIR_REQUEST);
    }
}

/**
 * @brief 79a4 | 354 | Sets the aim of the cannon
 * 
 * @param pData Samus data pointer
 */
void SamusAimCannon(struct SamusData* pData)
{
    struct WeaponInfo* pWeapon;

    pWeapon = &gSamusWeaponInfo;

    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
        // Process diagonal aim button
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
            case SPOSE_STANDING:
            case SPOSE_SHOOTING:
            case SPOSE_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_MIDAIR:
            case SPOSE_LANDING:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_AIMING_WHILE_HANGING:
            case SPOSE_UNCROUCHING_SUITLESS:
            case SPOSE_CROUCHING_SUITLESS:
                if (gButtonInput & KEY_DOWN)
                {
                    // Down pressed, aim diagonally down
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                    pWeapon->diagonalAim = DIAG_AIM_DOWN;
                }
                else if (pWeapon->diagonalAim == DIAG_AIM_NONE || pWeapon->diagonalAim == DIAG_AIM_UP || gButtonInput & KEY_UP)
                {
                    // Up pressed, aim diagonally up
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                    pWeapon->diagonalAim = DIAG_AIM_UP;
                }
                break;

            case SPOSE_ON_ZIPLINE:
                // On zipline, force aim down
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                pWeapon->diagonalAim = DIAG_AIM_DOWN;
        }

        return;
    }

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            // Check simple inputs
            if (gButtonInput & KEY_UP)
            {
                // Pressed up, aim diagonally up
                pData->armCannonDirection = ACD_DIAGONALLY_UP;
            }
            else if (gButtonInput & KEY_DOWN)
            {
                // Pressed down, aim diagonally down
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
            }
            else if (pData->armCannonDirection == ACD_FORWARD || pData->armCannonDirection == ACD_DIAGONALLY_UP ||
                    pData->armCannonDirection == ACD_DIAGONALLY_DOWN || pData->armCannonDirection == ACD_UP ||
                    pData->armCannonDirection == ACD_DOWN)
            {
                // If was aiming and not pressing either up or down, default to aiming forward
                pData->armCannonDirection = ACD_FORWARD;
            }

            if (gEquipment.suitType != SUIT_SUITLESS && pData->armCannonDirection == ACD_NONE)
            {
                // If not currently aiming and a weapon is selected, or the beam is being charged, then aim forward
                if (pWeapon->weaponHighlighted != WH_NONE || pWeapon->chargeCounter != 0)
                    pData->armCannonDirection = ACD_FORWARD;
            }
            break;

        case SPOSE_STANDING:
        case SPOSE_SHOOTING:
        case SPOSE_LANDING:
        case SPOSE_UNCROUCHING_SUITLESS:
            // Check for up aim, timer is used to not directly aim up after uncrouching
            if (pData->timer == 0 && gButtonInput & KEY_UP)
            {
                pData->armCannonDirection = ACD_UP;
            }
            else
            {
                pData->armCannonDirection = ACD_FORWARD;
            }
            break;

        case SPOSE_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_SUITLESS:
            // Force forward aim
            pData->armCannonDirection = ACD_FORWARD;
            break;

        case SPOSE_MIDAIR:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_AIMING_WHILE_HANGING:
            if (gButtonInput & KEY_UP)
            {
                // Check should aim up or diagonally up
                if (gButtonInput & pData->direction)
                {
                    // Holding up and foward
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                }
                else
                {
                    // Simply holding up
                    pData->armCannonDirection = ACD_UP;
                }
            }
            else if (gButtonInput & KEY_DOWN)
            {
                // Check should aim down or diagonally down
                if (gButtonInput & pData->direction)
                {
                    // Holding down and foward
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                }
                else
                {
                    // Simply holding down
                    pData->armCannonDirection = ACD_DOWN;
                }
            }
            else if (gButtonInput & pData->direction)
            {
                // Holding forward
                pData->armCannonDirection = ACD_FORWARD;
            }
            else if (pData->armCannonDirection != ACD_UP && pData->armCannonDirection != ACD_DOWN)
            {
                // If aiming diagonally and nothing is pressed, default to forward
                pData->armCannonDirection = ACD_FORWARD;
            }
            break;

        case SPOSE_ON_ZIPLINE:
            if (gButtonInput & KEY_DOWN)
            {
                // Check should aim down or diagonally down
                if (gButtonInput & pData->direction)
                {
                    // Holding down and foward
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                }
                else
                {
                    // Simply holding down
                    pData->armCannonDirection = ACD_DOWN;
                }
            }
            else
            {
                // Check holding forward or not aiming down, then aim forward
                if (gButtonInput & pData->direction || pData->armCannonDirection != ACD_DOWN)
                    pData->armCannonDirection = ACD_FORWARD;
            }
            break;
    }

    // Diagonal aim input not pressed
    pWeapon->diagonalAim = DIAG_AIM_NONE;
}

/**
 * @brief 7cf8 | bc | Checks if Samus is firing a beam/missile
 * 
 * @param pData Samus data pointer
 * @param pWeapon Samus weapon info pointer
 * @param pEquipment Samus equipment pointer
 * @return u8 bool, fired
 */
u8 SamusCheckFireBeamMissile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    u8 hasProj;

    hasProj = FALSE;

    // Check fire
    if (pWeapon->cooldown == 0 && pWeapon->newProjectile == PROJECTILE_CATEGORY_NONE && gChangedInput & KEY_B)
    {
        // Based on currently selected weapon
        if (pWeapon->weaponHighlighted & WH_MISSILE)
            pWeapon->newProjectile = PROJECTILE_CATEGORY_MISSILE;
        else if (pWeapon->weaponHighlighted & WH_SUPER_MISSILE)
            pWeapon->newProjectile = PROJECTILE_CATEGORY_SUPER_MISSILE;
        else
            pWeapon->newProjectile = PROJECTILE_CATEGORY_BEAM;

        hasProj++;
    }

    if (!hasProj)
    {
        if (pWeapon->weaponHighlighted == WH_NONE)
        {
            if (gButtonInput & KEY_B)
            {
                // B is held, update charge counter
                if (pEquipment->beamBombsActivation & BBF_CHARGE_BEAM)
                {
                    if (pWeapon->chargeCounter < CHARGE_BEAM_MAX_THRESHOLD)
                        pWeapon->chargeCounter++;
                    else
                        pWeapon->chargeCounter = CHARGE_BEAM_THRESHOLD;
                }
                else
                {
                    // Can't charge
                    pWeapon->chargeCounter = 0;
                }
            }
            else
            {
                // B was released, check which beam to fire
                if (pWeapon->chargeCounter >= CHARGE_BEAM_THRESHOLD)
                {
                    // Fully charged
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;
                    hasProj++;
                }
                else if (pWeapon->chargeCounter > CHARGE_BEAM_UNCHARGED_THRESHOLD)
                {
                    // Charged a little
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_BEAM;
                    hasProj++;
                }
                
                pWeapon->chargeCounter = 0;
            }
        }
        else
        {
            // A weapon is armed, prevent charge beam
            pWeapon->chargeCounter = 0;
        }
    }

    // Check set forward ACD if firing and not aiming
    if (hasProj && pData->armCannonDirection == ACD_NONE)
        pData->armCannonDirection = ACD_FORWARD;

    return hasProj;
}

/**
 * @brief 7db4 | 6c | Updates the pistol
 * 
 * @param pData Samus data pointer
 * @param pWeapon Samus weapon info pointer
 * @return u8 bool, fired
 */
u8 SamusCheckFirePistol(struct SamusData* pData, struct WeaponInfo* pWeapon)
{
    u8 hasProj;

    hasProj = FALSE;

    // Update charge counter
    if (pWeapon->chargeCounter < CHARGE_PISTOL_MAX_THRESHOLD)
        pWeapon->chargeCounter++;
    else
        pWeapon->chargeCounter = CHARGE_PISTOL_THRESHOLD;

    // Check can fire
    if (pWeapon->cooldown == 0 && pWeapon->newProjectile == PROJECTILE_CATEGORY_NONE && gChangedInput & KEY_B)
    {
        if (pWeapon->chargeCounter >= CHARGE_PISTOL_THRESHOLD)
        {
            // Counter threshold reached, fire charged beam
            pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;

            // Repeated useless code, is this an error?
            pWeapon->chargeCounter = 0;
            hasProj++;
        }
        else
        {
            // Counter threshold not reached, fire beam
            pWeapon->newProjectile = PROJECTILE_CATEGORY_BEAM;
        }

        // Clear charge counter and mark firing
        pWeapon->chargeCounter = 0;
        hasProj++;
    }

    // Check set forward ACD if firing and not aiming
    if (hasProj && pData->armCannonDirection == ACD_NONE)
        pData->armCannonDirection = ACD_FORWARD;

    return hasProj;
}

/**
 * @brief 7e20 | 23c | Checks if a new projectile should spawn
 * 
 * @param pData Samus data pointer
 * @param pWeapon Samus weapon info pointer
 * @param pEquipment Samus equipment pointer
 */
void SamusCheckNewProjectile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    pPhysics->hasNewProjectile = FALSE;

    if (pEquipment->suitType == SUIT_SUITLESS)
    {
        switch (pData->pose)
        {
            case SPOSE_FACING_THE_FOREGROUND:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
                // Reset counter
                pWeapon->chargeCounter = 0;
                break;

            default:
                // Update pistol
                pPhysics->hasNewProjectile = SamusCheckFirePistol(pData, pWeapon);
                break;

            case SPOSE_GETTING_HURT:
            case SPOSE_GETTING_KNOCKED_BACK:
                // Stop updating if getting hurt/knocked back
                break;
        }

        return;
    }

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
        case SPOSE_STANDING:
        case SPOSE_TURNING_AROUND:
        case SPOSE_SHOOTING:
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_MIDAIR:
        case SPOSE_TURNING_AROUND_MIDAIR:
        case SPOSE_LANDING:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
            // Check fire beam or missiles
            pPhysics->hasNewProjectile = SamusCheckFireBeamMissile(pData, pWeapon, pEquipment);
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
            // Check for bombs
            if (gChangedInput & KEY_B && pWeapon->cooldown == 0 && pEquipment->beamBombsActivation & BBF_BOMBS)
            {
                // Check if power bombs selected
                if (pWeapon->weaponHighlighted & WH_POWER_BOMB)
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_POWER_BOMB;
                else
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_BOMB;
            }

        case SPOSE_MORPHING:
            // Check fire charged shot in morph ball
            if (pWeapon->chargeCounter >= CHARGE_BEAM_THRESHOLD)
                pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;

            // Reset counter
            pWeapon->chargeCounter = 0;
            break;
        
        case SPOSE_USING_AN_ELEVATOR:
        case SPOSE_SAVING_LOADING_GAME:
        case SPOSE_DOWNLOADING_MAP_DATA:
        case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
        case SPOSE_DYING:
        case SPOSE_IN_ESCAPE_SHIP:
        case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
            // Reset counter
            pWeapon->chargeCounter = 0;
    }
}

/**
 * @brief 805c | 24 | Checks if samus is jumping
 * 
 * @param pData Samus data pointer
 * @return u8 bool, jumping
 */
u8 SamusCheckJumping(struct SamusData* pData)
{
    u8 jumping;
    
    jumping = FALSE;
    if (gChangedInput & KEY_A)
    {
        // Prepare forced movement
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        jumping = TRUE;
    }

    return jumping;
}

/**
 * @brief 8080 | 140 | Sets the current highlighted weapon
 * 
 * @param pData Samus data pointer
 * @param pWeapon Samus weapon info pointer
 * @param pEquipment Samus equipment pointer
 */
void SamusSetHighlightedWeapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    u8 weaponHigh;
    
    weaponHigh = WH_NONE;

    if (pEquipment->currentSuperMissiles == 0)
    {
        // No missiles left, select super missiles
        pWeapon->missilesSelected = FALSE;
    }
    else if (pEquipment->currentMissiles == 0)
    {
        // No super missiles left, select missiles
        pWeapon->missilesSelected = TRUE;
    }
    else if (gChangedInput & KEY_SELECT)
    {
        // Toggle
        pWeapon->missilesSelected ^= TRUE;
        SoundPlay(SOUND_MISSILE_TOGGLE); // Selecting missiles
    }

    switch (pData->pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            // Check select power bombs
            if (gButtonInput & gButtonAssignments.armWeapon && pEquipment->currentPowerBombs != 0)
                weaponHigh = WH_POWER_BOMB;
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_USING_AN_ELEVATOR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
        case SPOSE_GRABBED_BY_CHOZO_STATUE:
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
        case SPOSE_SHINESPARKING:
        case SPOSE_SHINESPARK_COLLISION:
        case SPOSE_DELAY_AFTER_SHINESPARKING:
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_SAVING_LOADING_GAME:
            // Can't select a weapon in these poses
            break;

        default:
            // Try to arm missiles or super missiles
            if (gButtonInput & gButtonAssignments.armWeapon)
            {
                if (!pWeapon->missilesSelected)
                {
                    // Missiles are select, check again because by default missiles are selected in any case
                    if (pEquipment->currentMissiles != 0)
                        weaponHigh = WH_MISSILE;
                }
                else
                {
                    // Super missiles are selected
                    weaponHigh = WH_SUPER_MISSILE;
                }
            }
            break;
    }

    if (weaponHigh != WH_NONE && pWeapon->weaponHighlighted == WH_NONE)
    {
        // Armed a new weapon
        pWeapon->chargeCounter = 0;
        SoundPlay(SOUND_ARMING_WEAPON);
    }

    // Set new highlighted weapon
    pWeapon->weaponHighlighted = weaponHigh;
}

/**
 * @brief 81c0 | b8 | Updates the spinning pose accordingly
 * 
 * @param pData Samus data pointer
 * @param pEquipment Samus equipment pointer
 */
void SamusSetSpinningPose(struct SamusData* pData, struct Equipment* pEquipment)
{
    switch (pData->pose)
    {
        case SPOSE_SPINNING:
            if (gSamusPhysics.slowedByLiquid)
            {
                // No change needed if slowed
                break;
            }

            if (pEquipment->suitMiscActivation & SMF_SCREW_ATTACK)
            {
                // Set screw attacking
                pData->pose = SPOSE_SCREW_ATTACKING;
                break;
            }

            if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
            {
                // Set space jumping
                pData->pose = SPOSE_SPACE_JUMPING;
            }
            break;

        case SPOSE_SPACE_JUMPING:
            if (pEquipment->suitMiscActivation & SMF_SCREW_ATTACK)
            {
                // Screw attacking takes priority
                pData->pose = SPOSE_SCREW_ATTACKING;
                break;
            }

            if (!(pEquipment->suitMiscActivation & SMF_SPACE_JUMP) || gSamusPhysics.slowedByLiquid)
            {
                // Set spinning if doesn't have space jump or is slowed
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = 0;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (gSamusPhysics.slowedByLiquid)
            {
                // Set spinning if slowed
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = 0;
            }
            else if (!(pEquipment->suitMiscActivation & SMF_SCREW_ATTACK))
            {
                // Screw attack was disabled, set new spinning pose
                if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
                    pData->pose = SPOSE_SPACE_JUMPING;
                else
                    pData->pose = SPOSE_SPINNING;

                pData->currentAnimationFrame = 0;
            }

            // Cancel effect
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_NONE;
    }
}

/**
 * @brief 8278 | 40 | Applies an X acceleration
 * 
 * @param acceleration Acceleration
 * @param velocity Max velocity
 * @param pData Samus data pointer
 */
void SamusApplyXAcceleration(s32 acceleration, s32 velocityCap, struct SamusData* pData)
{
    s32 cap;
    s32 xAcceleration;
    s32 temp;

    xAcceleration = (s16)acceleration;
    cap = (s16)velocityCap;

    // Apply acceleration and cap
    if (pData->direction & KEY_RIGHT)
    {
        temp = xAcceleration + (u16)pData->xVelocity;
        pData->xVelocity = temp;
        if ((s16)temp > cap)
            pData->xVelocity = cap;
    }
    else
    {
        pData->xVelocity -= xAcceleration;
        if (pData->xVelocity < -cap)
            pData->xVelocity = -cap;
    }
}

/**
 * @brief 82b8 | 168 | Handles Samus taking hazard damage
 * 
 * @param pData Samus data pointer
 * @param pEquipment Samus equipment pointer
 * @param pHazard Hazard Damage Pointer
 * @return u8 bool, getting knocked back
 */
u8 SamusTakeHazardDamage(struct SamusData* pData, struct Equipment* pEquipment, struct HazardDamage* pHazard)
{
    u16 yPosition;
    u8 damaged;
    u8 knockback;
    u8 damageType;
    u32 hazard;

    switch (pData->pose)
    {
        case SPOSE_GRABBED_BY_CHOZO_STATUE:
        case SPOSE_DYING:
            // Can't take hazard damage in these poses
            return FALSE;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_TURNING_TO_AIM_WHILE_HANGING:
        case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            // Offset position slightly up when hanging to not take into account the feets
            yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
            break;

        default:
            // Use normal position
            yPosition = pData->yPosition;
    }

    // Update damage timer
    pHazard->damageTimer++;

    damaged = FALSE;
    knockback = FALSE;
    damageType = SAMUS_HAZARD_DAMAGE_TYPE_NONE;

    // Get hazard at the current position
    hazard = LOW_BYTE(ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition));

    if (pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT)
    {
        // Has gravity, only check for acid
        if (hazard == HAZARD_TYPE_ACID)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 3)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
    }
    else if (pEquipment->suitMiscActivation & SMF_VARIA_SUIT)
    {
        // Has varia, only check for acid and strong lava
        if (hazard == HAZARD_TYPE_ACID)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 1)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
        else if (hazard == HAZARD_TYPE_STRONG_LAVA)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 4)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
    }
    else
    {
        // Has no suit, check for everything
        if (hazard == HAZARD_TYPE_ACID)
        {
            damaged = TRUE;
            damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
        else if (hazard == HAZARD_TYPE_COLD_KNOCKBACK)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 3)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_ROOM;

            // Check for knockback
            if (pHazard->knockbackTimer++ > 87)
            {
                pHazard->knockbackTimer = 0;
                knockback = TRUE;
            }
        }
        else if (hazard == HAZARD_TYPE_STRONG_LAVA)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 2)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
        else if (hazard == HAZARD_TYPE_WEAK_LAVA)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 7)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_LIQUID;
        }
        else if (hazard == HAZARD_TYPE_HEAT)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 5)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_ROOM;
        }
        else if (hazard == HAZARD_TYPE_COLD)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 5)
                damageType = SAMUS_HAZARD_DAMAGE_TYPE_ROOM;
        }
    }

    if (!damaged)
    {
        // Not damaged, reset timers
        pHazard->damageTimer = 0;
        pHazard->knockbackTimer = 0;
        pHazard->paletteTimer = 0;
    }
    else
    {
        // Update palette
        switch (pHazard->paletteTimer++)
        {
            case 1:
            case 33:
                if (hazard == HAZARD_TYPE_ACID || hazard == HAZARD_TYPE_STRONG_LAVA || hazard == HAZARD_TYPE_WEAK_LAVA)
                    SoundPlay(SOUND_LIQUID_DAMAGE_SUBMERGED);
                break;
    
            case 64:
                pHazard->paletteTimer = 0;
        }

        // Check do damage
        if (damageType != SAMUS_HAZARD_DAMAGE_TYPE_NONE)
        {
            pEquipment->currentEnergy--;
            pHazard->damageTimer = 0;
        }

        // Check play room damage sound
        if (damageType == SAMUS_HAZARD_DAMAGE_TYPE_ROOM)
            SoundPlay(SOUND_ROOM_DAMAGE);
    }

    // Check died or knockback
    if (pEquipment->currentEnergy == 0 || knockback)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 8420 | 4c | Checks if Samus is shinesparking
 * 
 * @param pData Samus data pointer
 */
void SamusCheckShinesparking(struct SamusData* pData)
{
    u16 xVelocity;
    u8 pose;

    pose = pData->pose;
    if (pose != SPOSE_DYING)
    {
        switch (pose)
        {
            case SPOSE_SHINESPARKING:
            case SPOSE_BALLSPARKING:
                // Set shinesparking
                pData->speedboostingShinesparking = TRUE;
                break;
            
            default:
                // Velocity threshold
                xVelocity = pData->xVelocity + SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + PIXEL_SIZE) - 1;
                if (xVelocity >= SUB_PIXEL_TO_VELOCITY(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) - 1)
                {
                    // Check not already speedboosting and not skidding
                    if (!pData->speedboostingShinesparking && pose != SPOSE_SKIDDING)
                    {
                        pData->speedboostingShinesparking++;
                        SoundPlay(SOUND_SPEEDBOOSTER_START);
                    }
                }
                else
                {
                    // Cancel shinespark
                    if (pData->speedboostingShinesparking)
                        pData->speedboostingShinesparking = FALSE;
                }
                break;
        }
    }
    else
    {
        // Can't speedboost if dead
        pData->speedboostingShinesparking = FALSE;
    }

    // Check stop speedbooster sound
    if (!pData->speedboostingShinesparking)
        SoundStop(SOUND_SPEEDBOOSTER_START);
}

/**
 * @brief 8478 | 4 | Samus inactivity subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusInactivity(struct SamusData* pData)
{
    return SPOSE_NONE;
}

/**
 * @brief 847c | 60 | Updates the animation of samus
 * 
 * @param pData Samus data pointer
 * @param slowed Slowed flag
 * @return u8 Animation state
 */
u8 SamusUpdateAnimation(struct SamusData* pData, u8 slowed)
{
    const struct SamusAnimationData* pAnim;
    u8 timer;

    // Get current animation pointer
    if (gEquipment.suitType == SUIT_SUITLESS)
        pAnim = sSamusAnimPointers_Suitless[pData->pose][0];
    else
        pAnim = sSamusAnimPointers_PowerSuit[pData->pose][0];

    // Get for current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Get time of current frame
    timer = pAnim->timer;

    // Make frame twice as long if slowed
    if (slowed)
        timer *= 2;

    // Check ended
    if (pData->animationDurationCounter >= timer)
    {
        // Ended, set next frame
        pData->animationDurationCounter = 0;
        pData->currentAnimationFrame++;

        // Next animation frame    
        pAnim++;

        // Check if there's another frame after
        if (pAnim->timer == 0)
            return SAMUS_ANIM_STATE_ENDED;
        else
            return SAMUS_ANIM_STATE_SUB_ENDED;
    }

    return SAMUS_ANIM_STATE_NONE;
}

/**
 * @brief 84dc | d4 | Samus running subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusRunning(struct SamusData* pData)
{
    s32 xVelocityCap;
    u16 currVelocity;

    // Check jumping
    if (gChangedInput & KEY_A)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    xVelocityCap = gSamusPhysics.xVelocityCap;

    // Update velocity cap for speedbooster
    if (gEquipment.suitMiscActivation & SMF_SPEEDBOOSTER && !gSamusPhysics.slowedByLiquid)
    {
        // Smoothly increase velocity cap for speedbooster activation 
        if (pData->timer >= 140)
            xVelocityCap = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        else if (pData->timer >= 120)
            xVelocityCap = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL + ONE_SUB_PIXEL / 2.f);
        
        currVelocity = pData->xVelocity + SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE * 3) - 1;
        if (currVelocity < SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) - 1)
        {
            pData->timer = 0;
        }
        else
        {
            if (pData->timer < 160)
                pData->timer++;
        }
    }
    else
    {
        // Reset timer
        pData->timer = 0;
    }

    if (gButtonInput & pData->direction)
    {
        // Move
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, xVelocityCap, pData);

        // Update aim
        SamusAimCannon(pData);
        return SPOSE_NONE;
    }

    // Check start skidding
    if (pData->speedboostingShinesparking)
        return SPOSE_SKIDDING;

    // Check shooting
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING;

    // Check stop or turn around
    if (!(OPPOSITE_DIRECTION(pData->direction) & gButtonInput))
        return SPOSE_STANDING;
    else
        return SPOSE_TURNING_AROUND;
}

/**
 * @brief 85b0 | 124 | Samus running gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusRunningGfx(struct SamusData* pData)
{
    const struct SamusAnimationData* pAnim;
    struct ScrewSpeedAnimation* pScrew;
    struct SamusPhysics* pPhysics;
    u8 timer;

    pScrew = &gScrewSpeedAnimation;
    pPhysics = &gSamusPhysics;

    // Get animation pointer
    if (!pData->speedboostingShinesparking)
    {
        pAnim = sSamusAnimPointers_PowerSuit_Running[0][0];
        pScrew->flag = SCREW_SPEED_FLAG_NONE;
    }
    else
    {
        pAnim = sSamusAnimPointers_PowerSuit_Running_Speedboosting[0][0];
        pScrew->flag = SCREW_SPEED_FLAG_SPEEDBOOSTING;
    }

    // Get for current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Get time of current frame
    timer = pAnim->timer;

    // Make frame twice as long if slowed
    if (pPhysics->slowedByLiquid)
        timer *= 2;

    // Update animation
    if (pData->animationDurationCounter >= timer)
    {
        // Next frame
        pData->animationDurationCounter = 0;
        pData->currentAnimationFrame++;

        pAnim++;

        if (pAnim->timer == 0)
        {
            // Loop if ended
            pData->currentAnimationFrame = 0;
        }

        // Play sounds and effects
        switch (pData->currentAnimationFrame)
        {
            case 1:
                if (pPhysics->slowedByLiquid)
                    SoundPlay(SOUND_WATER_MOVEMENT_RUNNING);
                else if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(SOUND_FOOTSTEPS_1);
                else
                    SoundPlay(SOUND_SUITLESS_FOOTSTEPS_1);
                break;

            case 2:
                SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_RUNNING_EFFECT);
                break;

            case 7:
                SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_RUNNING_EFFECT_);
                break;

            case 6:
                if (pPhysics->slowedByLiquid)
                    SoundPlay(SOUND_WATER_MOVEMENT_RUNNING);
                else if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(SOUND_FOOTSTEPS_2);
                else
                    SoundPlay(SOUND_SUITLESS_FOOTSTEPS_2);
                break;
        }
    }

    if (pScrew->flag != SCREW_SPEED_FLAG_NONE)
    {
        // Update effect animation
        pScrew->animationDurationCounter++;
        if (pScrew->animationDurationCounter >= sSamusEffectAnim_Left_Speedboosting[pScrew->currentAnimationFrame].timer)
        {
            pScrew->animationDurationCounter = 0;
            pScrew->currentAnimationFrame++;

            if (sSamusEffectAnim_Left_Speedboosting[pScrew->currentAnimationFrame].timer == 0)
                pScrew->currentAnimationFrame = 0;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 86d4 | 148 | Samus standing subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStanding(struct SamusData* pData)
{
    u32 clipdata;
    s16 hitbox;

    // Check shinesparking
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0)
    {
        hitbox = sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(pData, hitbox) == SAMUS_COLLISION_DETECTION_NONE)
        {
            pData->yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    // Check jumping
    if (SamusCheckJumping(pData))
        return SPOSE_MID_AIR_REQUEST;

    // Check running
    if (gButtonInput & pData->direction)
        return SPOSE_RUNNING;

    // Check shooting
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING;

    // Check turning around
    if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
        return SPOSE_TURNING_AROUND;

    if (gChangedInput & KEY_DOWN)
    {
        // Check for elevator down block
        clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(pData->yPosition + PIXEL_SIZE, pData->xPosition));
        if (clipdata == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK)
        {
            // Set position to the middle of the current block
            pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
            
            // Enter elevator
            pData->elevatorDirection = KEY_DOWN;
            return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
        }

        // Check crouching
        if (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN)
        {
            if (gEquipment.suitType != SUIT_SUITLESS)
                SoundPlay(SOUND_CROUCHING);

            if (gSamusPhysics.hasNewProjectile)
                return SPOSE_SHOOTING_AND_CROUCHING;

            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_CROUCHING_SUITLESS;

            return SPOSE_CROUCHING;
        }
    }
    else if (gChangedInput & KEY_UP)
    {
        // Check for elevator up block
        clipdata = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(pData->yPosition + PIXEL_SIZE, pData->xPosition));
        if (clipdata == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
        {
            // Set position to the middle of the current block
            pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;

            // Enter elevator
            pData->elevatorDirection = KEY_UP;
            return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
        }
    }

    if (pData->timer != 0)
        pData->timer--;

    // Update aim
    SamusAimCannon(pData);

    return SPOSE_NONE;
}

/**
 * @brief 881c | 20 | Samus standing gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStandingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Loop animation
        pData->currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 883c | bc | Samus turning around subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAround(struct SamusData* pData)
{
    s16 hitbox;

    // Check shinesparking
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0)
    {
        hitbox = sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(pData, hitbox) == SAMUS_COLLISION_DETECTION_NONE)
        {
            pData->yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    // Check jumping
    if (SamusCheckJumping(pData))
        return SPOSE_MID_AIR_REQUEST;

    if (gChangedInput & KEY_DOWN && (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
    {
        // Don't return the value to smootly transition between the 2 turning around animations
        // otherwise the crouching turning animation would start from the beginning 
        pData->pose = SPOSE_TURNING_AROUND_AND_CROUCHING;

        if (gEquipment.suitType != SUIT_SUITLESS)
            SoundPlay(SOUND_CROUCHING);
    }

    if (gSamusPhysics.hasNewProjectile)
    {
        // Set shooting
        if (pData->pose == SPOSE_TURNING_AROUND_AND_CROUCHING)
            return SPOSE_SHOOTING_AND_CROUCHING;
        else
            return SPOSE_SHOOTING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 88f8 | 48 | Samus turning around gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Check set running
        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
            return SPOSE_RUNNING;

        // Set standing
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8940 | 1c | Samus shooting gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusShootingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STANDING;

    return SPOSE_NONE;
}

/**
 * @brief 895c | 1b8 | Samus crouching subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusCrouching(struct SamusData* pData)
{
    u16 xPosition;
    u8 collision;
    s16 hitbox;

    // Check start shinespark
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0)
    {
        hitbox = sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(pData, hitbox) == SAMUS_COLLISION_DETECTION_NONE)
        {
            pData->yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

    // Smooth clamp the X position
    if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT];
    else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT] + SUB_PIXEL_POSITION_FLAG;

    // Check can jump
    if (SamusCheckJumping(pData) && !(collision & SAMUS_COLLISION_DETECTION_MIDDILE))
    {
        // Check apply clamped position
        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
            pData->xPosition = xPosition;

        // Jump
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check getting up
    if (gChangedInput & KEY_UP && !(collision & SAMUS_COLLISION_DETECTION_MIDDILE))
    {
        // Not aiming diagonally or aiming diagonally up
        if (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_UP)
        {
            // Check apply clamped position
            if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
                pData->xPosition = xPosition;

            // Does nothing, probably a leftover
            pData->lastWallTouchedMidAir = 6;

            // Set standing
            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_UNCROUCHING_SUITLESS;
            else
                return SPOSE_STANDING;
        }
    }

    // Check morphing
    if (gChangedInput & KEY_DOWN && gEquipment.suitMiscActivation & SMF_MORPH_BALL &&
        (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
    {
        SoundPlay(SOUND_MORPHING);
        return SPOSE_MORPHING;
    }

    // Update aim
    SamusAimCannon(pData);

    // Prevent aiming up
    if (pData->armCannonDirection == ACD_UP)
        pData->armCannonDirection = ACD_FORWARD;

    // Check shooting
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_AND_CROUCHING;

    // Check turning around
    if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
        return SPOSE_TURNING_AROUND_AND_CROUCHING;

    // Check stand up if holding forward
    if (gButtonInput & pData->direction)
    {
        // No ceiling and held for long enough
        if (!(collision & SAMUS_COLLISION_DETECTION_MIDDILE) && pData->timer++ > 5)
        {
            // Check apply clamped position
            if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
                pData->xPosition = xPosition;

            // Set standing
            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_UNCROUCHING_SUITLESS;
            else
                return SPOSE_STANDING;
        }
    }
    else
    {
        // Reset timer
        pData->timer = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8b14 | 110 | Samus turning around and crouching subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundAndCrouching(struct SamusData* pData)
{
    u8 collision;
    u16 xPosition;
    s16 hitbox;

    // Check start shinespark
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0)
    {
        hitbox = sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP] - HALF_BLOCK_SIZE;
        if (SamusCheckCollisionAbove(pData, hitbox) == SAMUS_COLLISION_DETECTION_NONE)
        {
            pData->yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }
    }

    collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

    // Smooth clamp the X position
    if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT];
    else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT] + SUB_PIXEL_POSITION_FLAG;

    // Check can jump
    if (SamusCheckJumping(pData) && !(collision & SAMUS_COLLISION_DETECTION_MIDDILE))
    {
        // Check apply clamped position
        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
            pData->xPosition = xPosition;

        // Jump
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check getting up
    if (gChangedInput & KEY_UP && !(collision & SAMUS_COLLISION_DETECTION_MIDDILE) &&
        (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_UP))
    {
        // Check apply clamped position
        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
            pData->xPosition = xPosition;

        // Don't return the value to smootly transition between the 2 turning around animations
        // otherwise the standing turning animation would start from the beginning 
        pData->pose = SPOSE_TURNING_AROUND;
    }

    if (gSamusPhysics.hasNewProjectile)
    {
        // Set shooting pose (standing or crouched version)
        if (pData->pose == SPOSE_TURNING_AROUND)
            return SPOSE_SHOOTING;
        else
            return SPOSE_SHOOTING_AND_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8c24 | 2c | Samus turning around and crouching gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundAndCrouchingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Set crouching pose
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_CROUCHING_SUITLESS;
        else
            return SPOSE_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8c50 | 1c | Samus shooting and crouching gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusShootingAndCrouchingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_CROUCHING;

    return SPOSE_NONE;
}

/**
 * @brief 8c6c | 8c | Samus skidding subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusSkidding(struct SamusData* pData)
{
    // Check jump
    if (gChangedInput & KEY_A)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check running
    if (gButtonInput & pData->direction)
        return SPOSE_RUNNING;

    // Check store shinespark
    if ((gButtonInput & KEY_ALL_DIRECTIONS) == KEY_DOWN)
    {
        pData->shinesparkTimer = SHINESPARK_TIMER_MAX;
        gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_STORING_SHINESPARK;

        // Set crouching pose
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_CROUCHING_SUITLESS;
        else
            return SPOSE_CROUCHING;
    }

    // Handle velocity decrease
    if (pData->direction & KEY_RIGHT)
    {
        pData->xVelocity -= SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL + ONE_SUB_PIXEL / 4.f);
        if (pData->xVelocity <= 0)
            return SPOSE_STANDING;
    }
    else
    {
        pData->xVelocity += SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL + ONE_SUB_PIXEL / 4.f);
        if (pData->xVelocity >= 0)
            return SPOSE_STANDING;
    }
    
    return SPOSE_NONE;
}

/**
 * @brief 8cf8 | 100 | Samus mid air subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusMidAir(struct SamusData* pData)
{
    u8 turning;
    s32 xAcceleration;
    u16 currVelocity;
    u32 newVelocity;

    // Check morph, pressing down while aiming down
    if (gChangedInput & KEY_DOWN && pData->armCannonDirection == ACD_DOWN && gEquipment.suitMiscActivation & SMF_MORPH_BALL)
    {
        SoundPlay(SOUND_MORPHING);
        return SPOSE_MORPH_BALL_MIDAIR;
    }

    // Check start spin or shinespark
    if (gChangedInput & KEY_A)
    {
        if (pData->shinesparkTimer != 0)
        {
            // Has a shinespark stored, start it
            return SPOSE_DELAY_BEFORE_SHINESPARKING;
        }

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            // Set spinning
            pData->pose = SPOSE_SPINNING;
            pData->currentAnimationFrame = 0;
            pData->animationDurationCounter = 0;
            return SPOSE_NONE;
        }
    }

    turning = FALSE;
    xAcceleration = gSamusPhysics.midairXAcceleration;
    if (gButtonInput & pData->direction)
    {
        // Move forward
        SamusApplyXAcceleration(xAcceleration, gSamusPhysics.midairXVelocityCap, pData);
    }
    else
    {
        if (OPPOSITE_DIRECTION(pData->direction) & gButtonInput)
        {
            turning++;
        }
        else
        {
            // Apply deceleration
            currVelocity = pData->xVelocity;
            if (pData->xVelocity > 0)
            {
                pData->xVelocity -= xAcceleration;
                if (pData->xVelocity < 0)
                    pData->xVelocity = 0;
            }
            else if (pData->xVelocity < 0)
            {
                newVelocity = xAcceleration + currVelocity;
                pData->xVelocity = newVelocity;
                if (pData->xVelocity > 0)
                    pData->xVelocity = 0;
            }
        }
    }

    // Update aim
    SamusAimCannon(pData);

    // Check turning
    if (turning)
        return SPOSE_TURNING_AROUND_MIDAIR;

    // Check terminate Y velocity if not pressing A and going up
    if (!(gButtonInput & KEY_A) && pData->yVelocity > 0)
        pData->yVelocity = 0;

    return SPOSE_NONE;
}

u8 SamusMidAirGfx(struct SamusData* pData)
{
    // Handle leg animation
    if (pData->yVelocity >= 0)
    {
        // Loop first 3 frames
        if (pData->currentAnimationFrame == 2)
            pData->animationDurationCounter = 0;
    }
    else
    {
        // Start animation from frame 3
        if (pData->currentAnimationFrame < 2)
            pData->currentAnimationFrame = 2;
    }

    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Lock on last frame
        pData->currentAnimationFrame = 4;
    }

    return SPOSE_NONE;
}

u8 SamusTurningAroundMidAir(struct SamusData* pData)
{
    if (gChangedInput & KEY_A)
    {
        if (pData->shinesparkTimer != 0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            pData->pose = SPOSE_SPINNING;
            pData->direction ^= KEY_RIGHT | KEY_LEFT;
            pData->currentAnimationFrame = 0;
            pData->animationDurationCounter = 0;
            pData->turning = FALSE;
            return SPOSE_NONE;
        }
    }

    // Check shooting
    if (gSamusPhysics.hasNewProjectile)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check terminate Y velocity if not pressing A and going up
    if (!(gButtonInput & KEY_A) && pData->yVelocity > 0)
        pData->yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 8eb8 | 20 | Samus turning around mid air gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundMidAirGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
        return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8ed8 | 24 | Samus starting spin jump gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStartingSpinJumpGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->pose = SPOSE_SPINNING;
        pData->currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8efc | 144 | Samus spinning subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusSpinning(struct SamusData* pData)
{
    s32 xAcceleration;
    s32 xOffset;

    // Check for projectile
    if (gSamusPhysics.hasNewProjectile)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check for spin break
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gButtonInput & (KEY_UP | KEY_DOWN))
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Aim cannon
    SamusAimCannon(pData);

    xAcceleration = gSamusPhysics.midairXAcceleration;

    if (gEquipment.suitMiscActivation & SMF_SPACE_JUMP && !gSamusPhysics.slowedByLiquid)
    {
        // Check can space jump
        if (gChangedInput & KEY_A && pData->yVelocity <= -SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE))
        {
            if (gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
                pData->yVelocity = SAMUS_HIGH_JUMP_VELOCITY;
            else
                pData->yVelocity = SAMUS_LOW_JUMP_VELOCITY;

            return SPOSE_NONE;
        }
    }
    else
    {
        // Check can wall jump
        if (pData->walljumpTimer != 0)
        {
            pData->walljumpTimer--;

            // Holding correct direction and pressed A
            if (pData->direction & pData->lastWallTouchedMidAir)
            {
                if (gChangedInput & KEY_A)
                {
                    // Get check offset
                    if (pData->lastWallTouchedMidAir & KEY_RIGHT)
                        xOffset = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                    else
                        xOffset = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

                    // Check has block
                    if (ClipdataProcessForSamus(pData->yPosition, pData->xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG)
                    {
                        pData->direction = pData->lastWallTouchedMidAir;
                        return SPOSE_STARTING_WALL_JUMP;
                    }
                }

                xAcceleration = 1;
            }
        }
    }

    // Check turn
    if (gButtonInput & (OPPOSITE_DIRECTION(pData->direction)))
    {
        pData->direction ^= KEY_RIGHT | KEY_LEFT;

        // Cancel all X velocity, allows to directly turn around and not have to cancel the momentum manually
        pData->xVelocity = 0;
    }
    else
    {
        // Move
        SamusApplyXAcceleration(xAcceleration, gSamusPhysics.midairXVelocityCap, pData);
    }

    // Check terminate Y velocity if not pressing A and going up
    if (!(gButtonInput & KEY_A) && pData->yVelocity > 0)
        pData->yVelocity = 0;

    return SPOSE_NONE;
}

/**
 * @brief 9040 | 5c | Samus spinning gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusSpinningGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
    {
        // Loop animation
        pData->currentAnimationFrame = 0;
    }

    if (pData->currentAnimationFrame == 0 && pData->animationDurationCounter == 1)
    {
        // Play spinning sound
        if (gSamusPhysics.slowedByLiquid)
            SoundPlay(SOUND_WATER_SPIN_JUMP);
        else if (gEquipment.suitType != SUIT_SUITLESS)
            SoundPlay(SOUND_SPIN_JUMP);
        else
            SoundPlay(SOUND_SUITLESS_SPIN_JUMP);
    }

    return SPOSE_NONE;
}

/**
 * @brief 909c | 44 | Samus starting wall jump subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStartingWallJump(struct SamusData* pData)
{
    if (gSamusPhysics.hasNewProjectile)
    {
        // Cancel all momentum and fall
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gButtonInput & (KEY_UP | KEY_DOWN))
    {
        // Cancel all momentum and fall
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 90e0 | 24 | Samus starting wall jump gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStartingWallJumpGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9104 | 48 | Samus space jumping gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusSpaceJumpingGfx(struct SamusData* pData)
{
    if (pData->animationDurationCounter == 1 && pData->currentAnimationFrame == 0)
    {
        if (gSamusPhysics.slowedByLiquid)
            SoundPlay(SOUND_SPACE_JUMP);
        else
            SoundPlay(SOUND_SPACE_JUMP);
    }

    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0;

    return SPOSE_NONE;
}

/**
 * @brief 9150 | c0 | Samus screw attacking gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusScrewAttackingGfx(struct SamusData* pData)
{
    const struct SamusAnimationData* pAnim;
    u8 timer;

    // Get animation pointer and play sound
    if (gEquipment.suitMiscActivation & SMF_SPACE_JUMP)
    {
        pAnim = sSamusAnimPointers_PowerSuit_ScrewAttacking[1][0];

        if (pData->animationDurationCounter == 1 && pData->currentAnimationFrame == 0)
            SoundPlay(SOUND_SPACE_SCREW_ATTACK);
    }
    else
    {
        pAnim = sSamusAnimPointers_PowerSuit_ScrewAttacking[0][0];

        if (pData->animationDurationCounter == 1 && pData->currentAnimationFrame == 0)
            SoundPlay(SOUND_SCREW_ATTACK);
    }

    // Get current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Scale timer with slowed
    timer = pAnim->timer;
    if (gSamusPhysics.slowedByLiquid)
        timer *= 2;

    // Update samus animation
    if (pData->animationDurationCounter >= timer)
    {
        pData->animationDurationCounter = 0;
        pData->currentAnimationFrame++;

        if (pAnim[1].timer == 0)
            pData->currentAnimationFrame = 0;
    }

    gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SCREW_ATTACKING;

    // Update effect animation
    gScrewSpeedAnimation.animationDurationCounter++;
    if (gScrewSpeedAnimation.animationDurationCounter >= sSamusEffectAnim_ScrewAttacking[gScrewSpeedAnimation.currentAnimationFrame].timer)
    {
        gScrewSpeedAnimation.animationDurationCounter = 0;
        gScrewSpeedAnimation.currentAnimationFrame++;

        if (sSamusEffectAnim_ScrewAttacking[gScrewSpeedAnimation.currentAnimationFrame].timer == 0)
            gScrewSpeedAnimation.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9150 | c0 | Samus morphing subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusMorphing(struct SamusData* pData)
{
    // Check cancel morphing
    if (gChangedInput & KEY_UP)
        pData->pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

/**
 * @brief 9230 | 1c | Samus morphing gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusMorphingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_MORPH_BALL;

    return SPOSE_NONE;
}

/**
 * @brief 924c | 170 | Samus morphball subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusMorphball(struct SamusData* pData)
{
    u8 collision;
    u16 xPosition;
    s16 hitbox;

    // Check for morphball bounce
    if (pData->forcedMovement > FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP + 1)
    {
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (pData->forcedMovement >= FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP)
    {
        pData->forcedMovement++;
        return SPOSE_NONE;
    }

    // Check start ballsparking
    if (gChangedInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP && pData->shinesparkTimer != 0)
    {
        hitbox = sSamusHitboxData[SAMUS_HITBOX_TYPE_MORPHED][SAMUS_HITBOX_TOP] - BLOCK_SIZE;
        if (SamusCheckCollisionAbove(pData, hitbox) == SAMUS_COLLISION_DETECTION_NONE)
        {
            pData->yPosition -= HALF_BLOCK_SIZE;
            return SPOSE_DELAY_BEFORE_BALLSPARKING;
        }
    }

    if (SamusCheckJumping(pData))
    {
        if (pData->forcedMovement != FORCED_MOVEMENT_MID_AIR_JUMP)
            return SPOSE_MID_AIR_REQUEST;

        if (gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
            return SPOSE_MID_AIR_REQUEST;

        pData->forcedMovement = 0;
    }

    // Check start rolling
    if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
    {
        pData->direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        return SPOSE_ROLLING;
    }

    // Check unmorphing
    if (gChangedInput & KEY_UP)
    {
        collision = SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]);

        // Check for smooth unmorph if only slightly in a block

        // First clamp the position under to the block by adding the hitbox
        // Then remove the hitbox to have the position where samus would be against the wall
        // Then if the block was on the left, add a single block to the position to put samus in the correct block
        // Or if the block was on the right, remove one sub pixel
        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
        {
            xPosition = pData->xPosition;
            xPosition += sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT];

            pData->xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_LEFT] + BLOCK_SIZE;
            gPreviousXPosition = pData->xPosition;

            collision = SAMUS_COLLISION_DETECTION_NONE;
        }
        else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
        {
            xPosition = pData->xPosition;
            xPosition += sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_RIGHT];

            pData->xPosition = (xPosition & BLOCK_POSITION_FLAG) - sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_RIGHT] - ONE_SUB_PIXEL;
            gPreviousXPosition = pData->xPosition;

            collision = SAMUS_COLLISION_DETECTION_NONE;
        }

        if (collision == SAMUS_COLLISION_DETECTION_NONE)
        {
            // Unmorph
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(SOUND_UNMORPHING);
            else
                SoundPlay(SOUND_UNMORPHING);

            return SPOSE_UNMORPHING;
        }
    }

    // Check store shinepsark
    if (pData->timer != 0)
    {
        pData->timer--;

        // Only pressing down
        if ((gButtonInput & KEY_ALL_DIRECTIONS) == KEY_DOWN)
        {
            pData->shinesparkTimer = SHINESPARK_TIMER_MAX;
            pData->timer = 0;
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_STORING_SHINESPARK;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 93bc | cc | Samus rolling subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusRolling(struct SamusData* pData)
{
    s32 velocityCap;

    // Check jumping
    if (gChangedInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
    {
        // Request jump
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Check unmorph, no block above
    if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) == SAMUS_COLLISION_DETECTION_NONE)
    {
        // Pressed up
        if (gChangedInput & KEY_UP)
        {
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(SOUND_UNMORPHING);
            else
                SoundPlay(SOUND_UNMORPHING);

            return SPOSE_UNMORPHING;
        }
    }

    // Check moving
    if (gButtonInput & pData->direction)
    {
        velocityCap = gSamusPhysics.xVelocityCap;

        if (pData->speedboostingShinesparking)
        {
            // Speedboosting in morph ball, change velocity cap
            velocityCap = SAMUS_X_SPEEDBOOST_VELOCITY_CAP;
            pData->shinesparkTimer = 6;
        }

        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, velocityCap, pData);
        return SPOSE_NONE;
    }

    // Check turning
    if ((OPPOSITE_DIRECTION(pData->direction) & gButtonInput))
        pData->turning = TRUE;

    // Set in morph ball (not moving)
    return SPOSE_MORPH_BALL;
}

/**
 * @brief 9488 | 38 | Samus rolling gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusRollingGfx(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        // Loop animation
        pData->currentAnimationFrame = 0;
    }
    else if (animState == SAMUS_ANIM_STATE_SUB_ENDED && (pData->currentAnimationFrame == 1 || pData->currentAnimationFrame == 5))
    {
        // Check set wet ground effect
        SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_RUNNING_ON_WET_GROUND);
    }

    return SPOSE_NONE;
}

/**
 * @brief 94c0 | 48 | Samus unmorphing subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusUnmorphing(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) == SAMUS_COLLISION_DETECTION_NONE)
    {
        // Check force jump
        if (gChangedInput & KEY_A)
        {
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
            return SPOSE_MID_AIR_REQUEST;
        }

        // Check re-morphing
        if (!(gChangedInput & KEY_DOWN))
            return SPOSE_NONE;
    }

    // There's a block above samus or the down key was pressed, set morphing
    pData->pose = SPOSE_MORPHING;
    return SPOSE_NONE;
}

/**
 * @brief 9508 | 24 | Samus morphball midair subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusUnmorphingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->unmorphPaletteTimer = 15;
        return SPOSE_CROUCHING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 952c | d8 | Samus morphball midair subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusMorphballMidAir(struct SamusData* pData)
{
    // Check unmorph, pressing up
    if (gChangedInput & KEY_UP)
    {
        // Check no block on where samus' head should be
        if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) == SAMUS_COLLISION_DETECTION_NONE)
        {
            if (gSamusPhysics.slowedByLiquid == TRUE)
                SoundPlay(SOUND_UNMORPHING);
            else
                SoundPlay(SOUND_UNMORPHING);

            pData->unmorphPaletteTimer = 15;
            return SPOSE_MIDAIR;
        }
    }

    if (pData->forcedMovement == 0)
    {
        // Check terminate Y velocity if not holding A and going up
        if (!(gButtonInput & KEY_A) && pData->yVelocity > 0)
            pData->yVelocity = 0;
    }
    else
    {
        // Morph ball bounce after landing
        if (pData->yVelocity < SUB_PIXEL_TO_VELOCITY(ONE_SUB_PIXEL) - 1)
            pData->forcedMovement = 0;
    }

    if ((pData->yVelocity >= 0 && pData->xVelocity != 0) || gButtonInput & pData->direction)
    {
        // Move horizontally
        SamusApplyXAcceleration(gSamusPhysics.midairXAcceleration, gSamusPhysics.midairMorphedXVelocityCap, pData);
    }
    else
    {
        // Check turning
        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
            pData->direction ^= KEY_RIGHT | KEY_LEFT;

        // Terminate velocity if not holding forward
        pData->xVelocity = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9604 | 16c | Samus hanging on ledge subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusHangingOnLedge(struct SamusData* pData)
{
    u16 xPosition;
    u32 blockAbove;
    u32 sideBlock;

    if (gScreenShakeX.timer >= 30)
    {
        // Drop if horizontal screen shake active
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Get position offset into the block samus is hanging
    if (pData->direction & KEY_RIGHT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    // Check if there's blocks above samus
    // sideBlock is either the block on the top left or top right, depending on which samus samus is hanging
    // blockAbove is the block directly above the block samus is currently grabbing
    // 
    // O O O
    // 
    // S O S

    // Offset by 3.25 blocks because samus position is at her feets
    blockAbove = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition) & CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & pData->direction)
        {
            if (!blockAbove && !sideBlock)
            {
                // No blocks above samus, set pulling self up
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            // Blocks above samus, check has morph ball
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                // Set pulling into a morph ball tunnel
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }
        }

        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
        {
            // Change direction and spin jump
            pData->direction ^= KEY_RIGHT | KEY_LEFT;
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        }
        else if (gButtonInput & KEY_DOWN)
        {
            // Drop down
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        }
        else
        {
            // Drop block and do small vertical jump
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_CARRY;
            pData->yVelocity = SUB_PIXEL_TO_VELOCITY(QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2);
        }

        return SPOSE_MID_AIR_REQUEST;
    }

    if (gSamusPhysics.hasNewProjectile)
    {
        // Change direction to face outside the block
        pData->direction ^= KEY_RIGHT | KEY_LEFT;

        // Set ACD, up by default, or down if holding it
        if (gButtonInput & KEY_DOWN)
            pData->armCannonDirection = ACD_DOWN;
        else
            pData->armCannonDirection = ACD_UP;

        return SPOSE_SHOOTING_WHILE_HANGING;
    }

    // Check was charging beam (exclude pistol)
    if (gEquipment.suitType != SUIT_SUITLESS && gSamusWeaponInfo.chargeCounter != 0)
    {
        // Change direction to face outside the block
        pData->direction ^= KEY_RIGHT | KEY_LEFT;

        // Set ACD, up by default, or down if holding it
        if (gButtonInput & KEY_DOWN)
            pData->armCannonDirection = ACD_DOWN;
        else
            pData->armCannonDirection = ACD_UP;

        return SPOSE_AIMING_WHILE_HANGING;
    }

    // Check either pressing the diagonal aim, up, down or the direction opposite to the block
    if (gButtonInput & gButtonAssignments.diagonalAim || gButtonInput & (KEY_UP | KEY_DOWN) || gButtonInput & OPPOSITE_DIRECTION(pData->direction))
    {
        // Change direction to face outside the block
        pData->direction ^= KEY_RIGHT | KEY_LEFT;

        // Set aiming
        return SPOSE_TURNING_TO_AIM_WHILE_HANGING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9770 | 28 | Samus hanging on ledge gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusHangingOnLedgeGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0;

    return SPOSE_NONE;
}

/**
 * @brief 9798 | c8 | Samus turning to aim while hanging subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningToAimWhileHanging(struct SamusData* pData)
{
    u16 xPosition;
    u32 blockAbove;
    u32 sideBlock;

    if (gScreenShakeX.timer >= 30)
    {
        // Drop if horizontal screen shake active
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Get position offset into the block samus is hanging
    if (pData->direction & KEY_LEFT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    // Check if there's blocks above samus
    // sideBlock is either the block on the top left or top right, depending on which samus samus is hanging
    // blockAbove is the block directly above the block samus is currently grabbing
    // 
    // O O O
    // 
    // S O S

    // Offset by 3.25 blocks because samus position is at her feets
    blockAbove = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition) & CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
        {
            // Holding opposite direction, so trying to climb
            if (!blockAbove && !sideBlock)
            {
                // No blocks above samus, change direction and set pulling self up
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            // Blocks above samus, check has morph ball
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                // Set pulling into a morph ball tunnel
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }
        }

        // Force mid air jump
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        return SPOSE_MID_AIR_REQUEST;
    }

    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_HANGING;

    return SPOSE_NONE;
}

/**
 * @brief 9860 | 24 | Samus turning to aim while hanging gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningToAimWhileHangingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_AIMING_WHILE_HANGING;

    return SPOSE_NONE;
}

/**
 * @brief 9884 | 30 | Samus hiding arm cannon while hanging gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusHidingArmCannonWhileHangingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->direction ^= KEY_RIGHT | KEY_LEFT;
        return SPOSE_HANGING_ON_LEDGE;
    }

    return SPOSE_NONE;
}

/**
 * @brief 98b4 | 18c | Samus aiming while hanging subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusAimingWhileHanging(struct SamusData* pData)
{
    u16 xPosition;
    u32 blockAbove;
    u32 sideBlock;
    u32 aimingUp;

    if (gScreenShakeX.timer >= 30)
    {
        // Drop if horizontal screen shake active
        pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;
        return SPOSE_MID_AIR_REQUEST;
    }

    // Update aim
    SamusAimCannon(pData);

    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_HANGING;

    // Get position offset into the block samus is hanging
    if (pData->direction & KEY_LEFT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    // Check if there's blocks above samus
    // sideBlock is either the block on the top left or top right, depending on which samus samus is hanging
    // blockAbove is the block directly above the block samus is currently grabbing
    // 
    // O O O
    // 
    // S O S

    // Offset by 3.25 blocks because samus position is at her feets
    blockAbove = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG;
    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition) & CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & (OPPOSITE_DIRECTION(pData->direction)))
        {
            // Holding opposite direction, so trying to climb
            if (!blockAbove && !sideBlock)
            {
                // No blocks above samus, change direction and set pulling self up
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            // Blocks above samus, check has morph ball
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                // Set pulling into a morph ball tunnel
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }
        }

        // Check if should spin jump out or simply fall
        if (gButtonInput & pData->direction)
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_JUMP;
        else
            pData->forcedMovement = FORCED_MOVEMENT_MID_AIR_FALL;

        return SPOSE_MID_AIR_REQUEST;
    }

    aimingUp = FALSE;
    if (!(gButtonInput & gButtonAssignments.diagonalAim))
    {
        if (gChangedInput & OPPOSITE_DIRECTION(pData->direction))
        {
            // Holding the samus direction as the block, try to hide arm cannon
            if (gEquipment.suitType == SUIT_SUITLESS || gSamusWeaponInfo.chargeCounter == 0)
                return SPOSE_HIDING_ARM_CANNON_WHILE_HANGING;

            // Aim up if charging
            pData->armCannonDirection = ACD_UP;
        }

        // Check only holding up
        if (gButtonInput & KEY_UP && !(gButtonInput & pData->direction))
            aimingUp++;
    }

    if (aimingUp)
    {
        // Timer before trying to climb up if aiming up
        if (pData->timer++ > 9)
        {
            if (!blockAbove && !sideBlock)
            {
                // No blocks above samus, change direction and set pulling self up
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            // Blocks above samus, check has morph ball
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                // Set pulling into a morph ball tunnel
                pData->direction ^= KEY_LEFT | KEY_RIGHT;
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }

            // Clear timer
            pData->timer = 0;
        }
    }
    else
    {
        // Reset timer
        pData->timer = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9a40 | 28 | Samus pulling self up subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusPullingSelfUp(struct SamusData* pData)
{
    u16 offset;

    offset = sSamusPullingSelfUpVelocity[pData->currentAnimationFrame];

    // Timer holds a copy of the slowed by liquid flag
    if (pData->timer)
    {
        // Move twice as slow if slowed
        offset /= 2;
    }

    // Move
    pData->yPosition -= offset;
    return SPOSE_NONE;
}

/**
 * @brief 9a68 | 2c | Samus pulling self up gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusPullingSelfUpGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, pData->timer) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;
        return SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING;
    }
    
    return SPOSE_NONE;
}

/**
 * @brief 9a94 | 20 | Samus pulling self forward subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusPullingSelfForward(struct SamusData* pData)
{
    // Move one pixel forward each frame
    if (pData->direction & KEY_RIGHT)
        pData->xPosition += PIXEL_SIZE;
    else
        pData->xPosition -= PIXEL_SIZE;

    return SPOSE_NONE;
}

/**
 * @brief 9ab4 | 2c | Samus pulling self forward gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusPullingSelfForwardGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;

        return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9ae0 | 48 | Samus pulling self into morph ball tunnel gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusPullingSelfIntoMorphballTunnelGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, pData->timer) == SAMUS_ANIM_STATE_ENDED)
    {
        if (pData->direction & KEY_RIGHT)
            pData->xPosition += (PIXEL_SIZE + PIXEL_SIZE / 2);
        else
            pData->xPosition -= (PIXEL_SIZE + PIXEL_SIZE / 2);

        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;
        SoundPlay(SOUND_MORPHING);

        return SPOSE_MORPH_BALL;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9b28 | 8c | Samus using an elevator subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusUsingAnElevator(struct SamusData* pData)
{
    u8 stop;
    u32 currentBlock;
    u32 previousBlock;
    s16 newPosition;

    if (pData->currentAnimationFrame != 0)
        return SPOSE_NONE;

    stop = FALSE;

    // Manually move
    pData->yPosition -= pData->yVelocity;

    currentBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(pData->yPosition, pData->xPosition));

    if (pData->elevatorDirection & KEY_UP)
    {
        previousBlock = HIGH_SHORT(ClipdataCheckCurrentAffectingAtPosition(gPreviousYPosition, pData->xPosition));

        // Check hitting an elevator down block
        if (currentBlock != CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK && previousBlock == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK)
        {
            // Snap to block
            newPosition = pData->yPosition | SUB_PIXEL_POSITION_FLAG;
            pData->yPosition = newPosition;
            stop++;
        }
    }
    else if (pData->elevatorDirection & KEY_DOWN)
    {
        // Check hitting an elevator up block
        if (currentBlock == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
        {
            // Snap to block
            newPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - ONE_SUB_PIXEL;
            pData->yPosition = newPosition;
            stop++;
        }
    }

    if (stop)
    {
        pData->currentAnimationFrame++;
        pData->animationDurationCounter = 0;
        pData->yVelocity = 0;
        SoundFade(0x10E, 10);
    }

    return SPOSE_NONE;
}

/**
 * @brief 9bb4 | 50 | Using an elevator Gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusUsingAnElevatorGfx(struct SamusData* pData)
{
    const struct SamusAnimationData* pAnim;

    // Get animation for direction
    if (pData->elevatorDirection & KEY_DOWN)
        pAnim = sSamusAnimPointers_PowerSuit_UsingAnElevator[0][0];
    else
        pAnim = sSamusAnimPointers_PowerSuit_UsingAnElevator[1][0];

    // Get current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Update samus animation
    if (pData->animationDurationCounter >= pAnim->timer)
    {
        if (pData->currentAnimationFrame != 0)
        {
            pData->animationDurationCounter = 0;
            pData->currentAnimationFrame++;

            pAnim++;
        }

        if (pAnim->timer == 0)
            return SPOSE_FACING_THE_FOREGROUND;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9c04 | 28 | Samus facing the foreground subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusFacingTheForeground(struct SamusData* pData)
{
    u16 direction;

    // Get side direction
    direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);

    // Holding a direction and allowed to change
    if (direction != 0 && pData->lastWallTouchedMidAir == 0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9c2c | 3c | Samus turning from facing the foreground gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningFromFacningForegroundGfx(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 2)
    {
        if (pData->elevatorDirection != 0)
        {
            // Is on an elevator
            return SPOSE_USING_AN_ELEVATOR;
        }

        if (pData->timer)
        {
            // Is on a save platform
            return SPOSE_SAVING_LOADING_GAME;
        }

        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;

        return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9c68 | 38 | Samus delay before shinesparking gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusDelayBeforeShinesparkingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
            pData->turning = TRUE;

        return SPOSE_SHINESPARKING;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9ca0 | b0 | Samus shinesparking subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusShinesparking(struct SamusData* pData)
{
    u8 hittingSideBlock;
    u16 nextX;
    u16 nextY;
    u16 nextSlope;
    s32 xOffset;
    u8 stop;

    hittingSideBlock = FALSE;

    if (pData->forcedMovement == FORCED_MOVEMENT_UPWARDS_SHINESPARK)
    {
        // Check still moving upwards
        if (pData->yVelocity == 0)
            stop = TRUE;
    }
    else if (pData->forcedMovement != FORCED_MOVEMENT_SIDEWARDS_SHINESPARK)
    {
        // Moving diagonally
        if (pData->yVelocity != 0)
        {
            // Check hit a block from the side
            if (pData->xVelocity == 0)
                hittingSideBlock++;
        }
        else
            stop = TRUE;
    }
    else
    {
        // Check stopped
        if (pData->xVelocity == 0)
            hittingSideBlock++;
        else
            stop = FALSE;
    }

    if (stop)
    {
        ScreenShakeStartVertical(30, 1);
        return pData->pose + 1;
    }

    if (hittingSideBlock)
    {
        // Get check offset
        if (pData->direction & KEY_RIGHT)
            xOffset = (HALF_BLOCK_SIZE - PIXEL_SIZE);
        else
            xOffset = -(HALF_BLOCK_SIZE - PIXEL_SIZE);

        // Check if hit a slope
        if (SamusCheckCollisionAtPosition(pData->xPosition + xOffset, pData->yPosition + ONE_SUB_PIXEL,
            &nextX, &nextY, &nextSlope) != COLLISION_AIR)
        {
            if (nextSlope != SLOPE_NONE)
            {
                // Detected a slope, register it 
                pData->currentSlope = nextSlope;
                pData->yPosition = nextY;

                gUnk_03004fc9++;

                // Give control to the landing code that handles carrying a shinespark
                return SPOSE_LANDING_REQUEST;
            }
        }

        ScreenShakeStartHorizontal(30, 1);
        return pData->pose + 1;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9d50 | 8c | Samus shinesparking Gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusShinesparkingGfx(struct SamusData* pData)
{
    const struct SamusAnimationData* pAnim;
    u8 loopFrame;

    if (pData->forcedMovement == FORCED_MOVEMENT_UPWARDS_SHINESPARK)
    {
        pAnim = sSamusAnimPointers_PowerSuit_Shinesparking[0][0];
        loopFrame = 1;
    }
    else
    {
        pAnim = sSamusAnimPointers_PowerSuit_Shinesparking[1][0];
        loopFrame = 2;
    }

    // Get current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Update samus animation
    if (pData->animationDurationCounter >= pAnim->timer)
    {
        pData->animationDurationCounter = 0;
        pData->currentAnimationFrame++;

        if (pAnim[1].timer == 0)
            pData->currentAnimationFrame = loopFrame;
    }

    // Update effect animation
    gScrewSpeedAnimation.animationDurationCounter++;
    if (gScrewSpeedAnimation.animationDurationCounter >=
        sSamusEffectAnim_Left_Sidewards_Shinesparking[gScrewSpeedAnimation.currentAnimationFrame].timer)
    {
        gScrewSpeedAnimation.animationDurationCounter = 0;
        gScrewSpeedAnimation.currentAnimationFrame++;

        if (sSamusEffectAnim_Left_Sidewards_Shinesparking[gScrewSpeedAnimation.currentAnimationFrame].timer == 0)
            gScrewSpeedAnimation.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

u8 SamusShinesparkCollisionGfx(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 17)
        return SPOSE_DELAY_AFTER_SHINESPARKING;

    return SPOSE_NONE;
}

u8 SamusDelayAfterShinesparkingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_MID_AIR_REQUEST;

    return SPOSE_NONE;
}

/**
 * @brief 9e0c | 28 | Delay before ballsparking subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusDelayBeforeBallsparking(struct SamusData* pData)
{
    if (gButtonInput & (pData->direction ^ (KEY_LEFT | KEY_RIGHT)))
        pData->direction ^= KEY_LEFT | KEY_RIGHT;

    return SPOSE_NONE;
}

/**
 * @brief 9e34 | 88 | Delay before ballsparking Gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusDelayBeforeBallsparkingGfx(struct SamusData* pData)
{
    u8 animState;

    // Check start ballsparking
    if (pData->timer >= 60)
        return SPOSE_BALLSPARKING;

    // Check to small jump at the beginning
    if (pData->timer == 0 && pData->forcedMovement != FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
        pData->yPosition -= HALF_BLOCK_SIZE;

    // Increase timer
    pData->timer++;

    // Loop animation
    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0;

    if (pData->forcedMovement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
        return SPOSE_NONE;

    // Update effect animation
    gScrewSpeedAnimation.animationDurationCounter++;
    if (gScrewSpeedAnimation.animationDurationCounter >=
        sSamusEffectAnim_DelayBeforeBallsparking[gScrewSpeedAnimation.currentAnimationFrame].timer)
    {
        gScrewSpeedAnimation.animationDurationCounter = 0;
        gScrewSpeedAnimation.currentAnimationFrame++;

        if (sSamusEffectAnim_DelayBeforeBallsparking[gScrewSpeedAnimation.currentAnimationFrame].timer == 0)
            gScrewSpeedAnimation.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9ebc | 7c | Ballsparking Gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusBallsparkingGfx(struct SamusData* pData)
{
    const struct SamusAnimationData* pAnim;

    pAnim = sSamusAnimPointers_PowerSuit[pData->pose][0];
    pAnim = &pAnim[pData->currentAnimationFrame];

    // Update samus animation
    if (pData->animationDurationCounter >= pAnim->timer)
    {
        pData->animationDurationCounter = 0;
        pData->currentAnimationFrame++;

        pAnim++;
        if (pAnim->timer == 0)
            pData->currentAnimationFrame = 0;
    }

    // Update effect animation
    gScrewSpeedAnimation.animationDurationCounter++;
    if (gScrewSpeedAnimation.animationDurationCounter >=
        sSamusEffectAnim_Left_Sidewards_Shinesparking[gScrewSpeedAnimation.currentAnimationFrame].timer)
    {
        gScrewSpeedAnimation.animationDurationCounter = 0;
        gScrewSpeedAnimation.currentAnimationFrame++;

        if (sSamusEffectAnim_Left_Sidewards_Shinesparking[gScrewSpeedAnimation.currentAnimationFrame].timer == 0)
            gScrewSpeedAnimation.currentAnimationFrame = 0;
    }

    return SPOSE_NONE;
}

u8 SamusBallsparkCollisionGfx(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 17)
        return SPOSE_MID_AIR_REQUEST;

    return SPOSE_NONE;
}

/**
 * @brief 9f4c | 58 | Samus on zipline subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusOnZipline(struct SamusData* pData)
{
    if (gChangedInput & KEY_A)
    {
        // Request to leave zipline
        return SPOSE_MID_AIR_REQUEST;
    }
    
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_ON_ZIPLINE;
    
    if (pData->pose != SPOSE_ON_ZIPLINE)
        return SPOSE_NONE;

    if (!(gButtonInput & OPPOSITE_DIRECTION(pData->direction)))
    {
        // Not turning, update aim
        SamusAimCannon(pData);
        return SPOSE_NONE;
    }

    return SPOSE_TURNING_ON_ZIPLINE;
}

/**
 * @brief 9fa4 | 1c | Samus shooting on zipline gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusShootingOnZiplineGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_ON_ZIPLINE;

    return SPOSE_NONE;
}

/**
 * @brief 9fc0 | 30 | Samus morph ball on zipline subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusMorphballOnZipline(struct SamusData* pData)
{
    u16 direction;

    if (gChangedInput & KEY_A)
    {
        // Request to leave zipline
        return SPOSE_MID_AIR_REQUEST;
    }

    // Update direction
    direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
    if (direction != 0)
        pData->direction = direction;

    return SPOSE_NONE;
}

/**
 * @brief 9ff0 | 18 | Samus saving/loading game subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusSavingLoadingGame(struct SamusData* pData)
{
    if (pData->timer != 0)
    {
        pData->currentAnimationFrame = 0;
        pData->animationDurationCounter = 0;
    }

    return SPOSE_NONE;
}

/**
 * @brief a008 | 1c | Samus turning around to download map data gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusTurningAroundToDownloadMapDataGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_DOWNLOADING_MAP_DATA;

    return SPOSE_NONE;
}

/**
 * @brief a024 | 68 | Samus getting hurt subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New Pose
 */
u8 SamusGettingHurt(struct SamusData* pData)
{
    u8 forcedMovement;

    forcedMovement = 0;
    if (pData->forcedMovement != 0 && (u16)(pData->yVelocity + 7) < 15 && pData->lastWallTouchedMidAir++ < 10)
    {
        gSamusPhysics.yAcceleration = 0;
        forcedMovement = 0x1;
    }

    if (forcedMovement == 0 && pData->timer++ > 12 && pData->yVelocity < -SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE / 2))
    {
        pData->forcedMovement = forcedMovement;

        // Set correct mid air pose
        if (pData->pose == SPOSE_GETTING_HURT)
            return SPOSE_MIDAIR;

        return SPOSE_MORPH_BALL_MIDAIR;
    }

    return SPOSE_NONE;
}

/**
 * @brief a08c | 20 Samus getting hurt gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusGettingHurtGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame--; // Alternate between last frames

    return SPOSE_NONE;
}

/**
 * @brief a0ac | 30 | Samus getting knocked back subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusGettingKnockedBack(struct SamusData* pData)
{
    if (pData->timer >= 13)
    {
        // Samus starts to go down after 13 frames

        // Wait for y velocity to be going at least one pixel down
        if (pData->yVelocity >= -SUB_PIXEL_TO_VELOCITY(PIXEL_SIZE))
            return SPOSE_NONE;

        // Set correct mid air pose
        if (pData->pose == SPOSE_GETTING_KNOCKED_BACK)
            return SPOSE_MIDAIR;

        return SPOSE_MORPH_BALL_MIDAIR;
    }

    pData->timer++;

    return SPOSE_NONE;
}

/**
 * @brief a0dc | 10c | Samus dying subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusDying(struct SamusData* pData)
{
    u32 dstX;
    u32 dstY;

    if (pData->lastWallTouchedMidAir == 0)
    {
        pData->lastWallTouchedMidAir++;
        StopAllMusicsAndSounds();
    }
    else if (pData->lastWallTouchedMidAir == 1)
    {
        pData->lastWallTouchedMidAir++;
        SoundPlay(SOUND_DYING);
    }

    pData->invincibilityTimer = 64;

    if (pData->xVelocity != 0 || pData->yVelocity != 0)
    {
        // Center of the screen
        dstX = gBg1XPosition + PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_X / 2);
        dstY = gBg1YPosition + PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_Y / 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE);

        // Update X velocity
        if (pData->xVelocity > 0)
        {
            if (pData->xPosition >= dstX)
                pData->xVelocity = 0;
        }
        else if (pData->xVelocity < 0)
        {
            if (pData->xPosition <= dstX)
                pData->xVelocity = 0;
        }

        // Update Y velocity
        if (pData->yVelocity > 0)
        {
            if (pData->yPosition >= dstY)
                pData->yVelocity = 0;
        }
        else if (pData->yVelocity < 0)
        {
            if (pData->yPosition <= dstY)
                pData->yVelocity = 0;
        }

        // Update y position
        pData->yPosition += pData->yVelocity;
    }

    if (pData->currentAnimationFrame > 23)
    {
        switch (pData->timer++)
        {
            case 4:
                gMonochromeBgFading = MONOCHROME_FADING_WHITE;
            
            case 12:
            case 20:
            case 28:
            case 36:
            case 44:
            case 52:
            case 80:
                pData->walljumpTimer++;
                break;

            case 120:
                gMainGameMode = GM_GAMEOVER;
                gGameModeSub1 = 0;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief a1e8 | 34 | Samus crouching to crawl gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusCrouchingToCrawlGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Move slightly
        if (pData->direction & KEY_RIGHT)
            pData->xPosition += PIXEL_SIZE;
        else
            pData->xPosition -= PIXEL_SIZE;
        
        return SPOSE_STARTING_TO_CRAWL;
    }

    return SPOSE_NONE;
}

/**
 * @brief a21c | 68 | Samus crawling stopped subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusCrawlingStopped(struct SamusData* pData)
{
    // Keep x velocity at 0
    pData->xVelocity = 0;

    if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) == 0)
    {
        // No collision above, exit crawl
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    }
    
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    
    if (gButtonInput & pData->direction)
    {
        // Holding the correct direction, continue crawling
        return SPOSE_CRAWLING;
    }

    // Check turning around
    if (OPPOSITE_DIRECTION(pData->direction) & gButtonInput)
        return SPOSE_TURNING_AROUND_WHILE_CRAWLING;

    return SPOSE_NONE;
}

/**
 * @brief a284 | 1c | Samus starting to crawl gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusStartingToCrawlGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_CRAWLING_STOPPED;

    return SPOSE_NONE;
}

/**
 * @brief a2a0 | 74 | Samus crawling subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusCrawling(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, sSamusHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_HITBOX_TOP]) == SAMUS_COLLISION_DETECTION_NONE)
    {
        // No collision above, exit crawl
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    }

    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_CRAWLING;

    if (gButtonInput & pData->direction)
    {
        // Move
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, HALF_BLOCK_SIZE, pData);
        return SPOSE_NONE;
    }

    // Check turning
    if (OPPOSITE_DIRECTION(pData->direction) & gButtonInput)
        pData->turning = TRUE;

    return SPOSE_CRAWLING_STOPPED;
}

/**
 * @brief a314 | 44 | Samus crawling gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusCrawlingGfx(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        // Loop animation
        pData->currentAnimationFrame = 0;
    }
    else if (animState == SAMUS_ANIM_STATE_SUB_ENDED && (pData->currentAnimationFrame == 1 || pData->currentAnimationFrame == 4))
    {
        // Check start water splash effects
        SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_RUNNING_ON_WET_GROUND);
    }

    // Play crawling sound
    if (pData->animationDurationCounter == 1 && pData->currentAnimationFrame == 0)
        SoundPlay(SOUND_SUITLESS_CRAWL);

    return SPOSE_NONE;
}

/**
 * @brief a358 | 1c | Samus turning around while crawling subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundWhileCrawling(struct SamusData* pData)
{
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_CRAWLING;

    return SPOSE_NONE;
}

/**
 * @brief a374 | 1c | Samus turning around while crawling gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningAroundWhileCrawlingGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STARTING_TO_CRAWL;

    return SPOSE_NONE;
}

/**
 * @brief a390 | 1c | Samus grabbing a ledge (suitless) gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusGrabbingALedgeSuitlessGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_HANGING_ON_LEDGE;

    return SPOSE_NONE;
}

/**
 * @brief a3ac | 28 | Samus facing the background subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusFacingTheBackground(struct SamusData* pData)
{
    u16 direction;

    // Get side direction
    direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);

    // Holding a direction and allowed to change
    if (direction != 0 && pData->lastWallTouchedMidAir == 0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS;
    }

    return SPOSE_NONE;
}

/**
 * @brief a3d4 | 54 | Samus turning from facing the background gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningFromFacingTheBackgroundGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        // Check already running
        if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
            return SPOSE_RUNNING;

        if (pData->lastWallTouchedMidAir != 0)
            return SPOSE_FACING_THE_BACKGROUND_SUITLESS;
        
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;

        return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

/**
 * @brief a428 | 1c | Samus turning to enter escape ship gfx subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusTurningToEnterEscapeShipGfx(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_IN_ESCAPE_SHIP;

    return SPOSE_NONE;
}

/**
 * @brief a444 | bc | Executes the current samus pose subroutine
 * 
 * @param pData Samus data pointer
 * @return u8 New pose
 */
u8 SamusExecutePoseSubroutine(struct SamusData* pData)
{
    u8 pose;
    u8 timer;
    struct WeaponInfo* pWeapon;
    struct Equipment* pEquipment;
    struct HazardDamage* pHazard;

    pWeapon = &gSamusWeaponInfo;
    pEquipment = &gEquipment;
    pHazard = &gSamusHazardDamage;

    // Update hazard damage
    if (SamusTakeHazardDamage(pData, pEquipment, pHazard))
    {
        // Getting knocked back or died, abort
        return SPOSE_HURT_REQUEST;
    }

    // Update weapon cooldown
    if (pWeapon->cooldown != 0)
        pWeapon->cooldown--;

    // Check play speedbooster charge sound
    if (pData->shinesparkTimer != 0 && pData->pose != SPOSE_DELAY_BEFORE_SHINESPARKING && pData->pose != SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        timer = pData->shinesparkTimer;

        if (MOD_AND(timer, 16) == 4)
            SoundPlay(SOUND_SPEEDBOOSTER_CHARGE);

        pData->shinesparkTimer--;
    }

    // Update weapon highlight
    if (pEquipment->suitType != SUIT_SUITLESS)
        SamusSetHighlightedWeapon(pData, pWeapon, pEquipment);

    // Update spinning
    SamusSetSpinningPose(pData, pEquipment);

    // Check spawn projectile
    SamusCheckNewProjectile(pData, pWeapon, pEquipment);

    // Call pose subroutine
    pose = sSamusPoseFunctionPointers[pData->pose](pData);

    if (pose == SPOSE_NONE)
    {
        // No new pose, call pose grahical update
        pose = sSamusPoseGfxFunctionPointers[pData->pose](pData);
    }

    // Check shinesparking
    SamusCheckShinesparking(pData);

    return pose;
}

/**
 * @brief a500 | 188 | Updates the position and the velocity of samus
 * 
 * @param pData Samus data pointer
 */
void SamusUpdateVelocityPosition(struct SamusData* pData)
{
    s32 velocity;
    s32 yVelocity;

    gSamusPhysics.hitboxType = sSamusVisualData[pData->pose][1];

    switch (pData->pose)
    {
        case SPOSE_MIDAIR:
        case SPOSE_TURNING_AROUND_MIDAIR:
        case SPOSE_SPINNING:
        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT:
        case SPOSE_GETTING_KNOCKED_BACK:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            // Apply Y velocity
            if (pData->yVelocity > gSamusPhysics.positiveYVelocityCap)
            {
                velocity = DIV_SHIFT(gSamusPhysics.positiveYVelocityCap, 8);
            }
            else if (pData->yVelocity < -gSamusPhysics.negativeYVelocityCap)
            {
                velocity = DIV_SHIFT(-gSamusPhysics.negativeYVelocityCap, 8);
            }
            else
            {
                velocity = DIV_SHIFT(pData->yVelocity, 8);
            }

            if (pData->yVelocity >= -231)
            {
                pData->yVelocity -= gSamusPhysics.yAcceleration;
            }

            pData->yPosition -= velocity;
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (!(pData->forcedMovement & FORCED_MOVEMENT_SIDEWARDS_SHINESPARK))
            {
                velocity = DIV_SHIFT(pData->yVelocity, 8);
                pData->yPosition -= velocity;
            }
            break;
    }

    // Apply X velocity
    if (pData->standingStatus == STANDING_GROUND)
    {
        velocity = DIV_SHIFT(SamusChangeVelocityOnSlope(pData), 8);

        if (pData->pose == SPOSE_RUNNING)
        {
            if (pData->direction & KEY_RIGHT)
            {
                if (velocity < 0)
                    velocity = 0;
            }
            else
            {
                if (velocity > 0)
                    velocity = 0;
            }
        }
    }
    else
        velocity = DIV_SHIFT(pData->xVelocity, 8);

    pData->xPosition += velocity;
}

/**
 * @brief a688 | de4 | Updates the graphics and OAM of samus
 * 
 * @param pData Samus data pointer
 * @param direction Facing direction
 */
void SamusUpdateGraphicsOam(struct SamusData* pData, u8 direction)
{
    struct WeaponInfo* pWeapon;
    struct Equipment* pEquipment;
    struct SamusPhysics* pPhysics;
    struct SamusEcho* pEcho;
    struct ScrewSpeedAnimation* pScrew;
    const struct SamusAnimationData* pAnim;
    const struct ArmCannonAnimationData* pArmCannonAnim;
    const struct SamusEffectAnimationData* pEffectAnim;
    const u8* pGraphics;
    u8 pose;
    u8 acd;
    u16 ppc;

    pWeapon = &gSamusWeaponInfo;
    pEquipment = &gEquipment;
    pPhysics = &gSamusPhysics;
    pEcho = &gSamusEcho;
    pScrew = &gScrewSpeedAnimation;

    pose = pData->pose;
    acd = pData->armCannonDirection;

    // Check enable echo
    switch (pose)
    {
        case SPOSE_MIDAIR:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
        case SPOSE_MORPH_BALL_MIDAIR:
            // Not slowed and Y velocity of at least 2 blocks
            if (!pPhysics->slowedByLiquid && pData->yVelocity > SUB_PIXEL_TO_VELOCITY(EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2))
            {
                pEcho->active = TRUE;
                pEcho->timer = 6;
                pEcho->distance = 2;
            }
    }

    if (pData->speedboostingShinesparking)
    {
        // Enable echo if using speedbooster
        pEcho->active = TRUE;
        pEcho->timer = 16;
        pEcho->distance = 4;
    }
    else
    {
        // Update echo timer
        if (pEcho->timer != 0)
            pEcho->timer--;
        else
            pEcho->active = FALSE;
    }

    // Prevent buffer overflow
    ppc = MOD_AND(pEcho->previousPositionCounter, ARRAY_SIZE(pEcho->previous64XPositions));

    // Fetch previous position
    pEcho->previous64XPositions[ppc] = gPreviousXPosition;
    pEcho->previous64YPositions[ppc] = gPreviousYPosition;

    if (pEcho->previousPositionCounter++ > 0x100)
        pEcho->previousPositionCounter -= 0x80;

    if (pEcho->previousPositionCounter >= ARRAY_SIZE(pEcho->previous64XPositions))
        pEcho->unknown = TRUE;

    // Replace downloading map data with standing graphics if not actually downloading
    if (pData->pose == SPOSE_DOWNLOADING_MAP_DATA && pData->timer != 0)
        pose = SPOSE_STANDING;

    // Fetch current main body graphics and OAM based on the current pose
    // It's dependant on whether the pose has multiple versions, whatever the parameter may be
    // For most of them, the parameter is the arm cannon direction, but it can also be the forced movement flag
    switch (pose)
    {
        case SPOSE_RUNNING:
            // Check for no ACD
            if (acd > ACD_DOWN)
                acd -= 2;

            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_Running[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_Running[acd][direction];
            }
            else if (!pData->speedboostingShinesparking)
            {
                // Normal running graphics
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Running[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Running[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Running[acd][direction];
            }
            else
            {
                // Speedboosting graphics
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Running_Speedboosting[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Running_Speedboosting[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Running_Speedboosting[acd][direction];
            }
            break;

        case SPOSE_STANDING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_Standing[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_Standing[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Standing[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Standing[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Standing[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_TurningAround[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_TurningAround[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_TurningAround[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_TurningAround[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_TurningAround[acd][direction];
            }
            break;

        case SPOSE_SHOOTING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_Shooting[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_Shooting[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Shooting[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Shooting[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Shooting[acd][direction];
            }
            break;

        case SPOSE_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_Crouching[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_Crouching[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Crouching[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Crouching[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Crouching[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND_AND_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_TurningAroundAndCrouching[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_TurningAroundAndCrouching[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_TurningAroundAndCrouching[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_TurningAroundAndCrouching[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_TurningAroundAndCrouching[acd][direction];
            }
            break;

        case SPOSE_SHOOTING_AND_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_ShootingAndCrouching[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_ShootingAndCrouching[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_ShootingAndCrouching[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_ShootingAndCrouching[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_ShootingAndCrouching[acd][direction];
            }
            break;

        case SPOSE_SKIDDING:
            // Versions non armed and armed
            if (pWeapon->weaponHighlighted & (WH_MISSILE | WH_SUPER_MISSILE))
                acd++;

            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_Skidding[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_Skidding[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_All[pose][direction];
            break;

        case SPOSE_MIDAIR:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_MidAir[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_MidAir[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_MidAir[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_MidAir[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_MidAir[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND_MIDAIR:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_TurningAroundMidAir[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_TurningAroundMidAir[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_TurningAroundMidAir[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_TurningAroundMidAir[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_TurningAroundMidAir[acd][direction];
            }
            break;

        case SPOSE_LANDING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_Landing[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_Landing[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_Landing[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_Landing[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_Landing[acd][direction];
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
            {
                // Space jumping graphics
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_ScrewAttacking[1][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_ScrewAttacking[1][direction];
            }
            else
            {
                // Screw attack graphics
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_ScrewAttacking[0][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_ScrewAttacking[0][direction];
            }

            pArmCannonAnim = sArmCannonAnimPointers_Suit_All[pose][direction];
            break;

        case SPOSE_AIMING_WHILE_HANGING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_AimingWhileHanging[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_AimingWhileHanging[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_AimingWhileHanging[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_AimingWhileHanging[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_AimingWhileHanging[acd][direction];
            }
            break;

        case SPOSE_SHOOTING_WHILE_HANGING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless_ShootingWhileHanging[acd][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_ShootingWhileHanging[acd][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit_ShootingWhileHanging[acd][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit_ShootingWhileHanging[acd][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_ShootingWhileHanging[acd][direction];
            }
            break;

        case SPOSE_USING_AN_ELEVATOR:
            // Versions going down and going up
            if (pData->elevatorDirection & KEY_UP)
                acd++;

            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_UsingAnElevator[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_UsingAnElevator[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_UsingAnElevator[acd][direction];
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_SHINESPARK_COLLISION:
            // Versions based on the shinesparking direction
            acd = pData->forcedMovement;

            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_Shinesparking[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_Shinesparking[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_Shinesparking[acd][direction];
            break;

        case SPOSE_ON_ZIPLINE:
            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_OnZipline[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_OnZipline[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_OnZipline[acd][direction];
            break;

        case SPOSE_SHOOTING_ON_ZIPLINE:
            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_ShootingOnZipline[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_ShootingOnZipline[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_ShootingOnZipline[acd][direction];
            break;

        case SPOSE_TURNING_ON_ZIPLINE:
            if (pEquipment->suitType != SUIT_NORMAL)
                pAnim = sSamusAnimPointers_FullSuit_TurningOnZipline[acd][direction];
            else
                pAnim = sSamusAnimPointers_PowerSuit_TurningOnZipline[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suit_TurningOnZipline[acd][direction];
            break;

        case SPOSE_CRAWLING_STOPPED:
            acd = pData->forcedMovement;

            pAnim = sSamusAnimPointers_Suitless_CrawlingStopped[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suitless_CrawlingStopped[acd][direction];
            break;

        case SPOSE_UNCROUCHING_SUITLESS:
            pAnim = sSamusAnimPointers_Suitless_UncrouchingSuitless[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suitless_UncrouchingSuitless[acd][direction];
            break;

        case SPOSE_CROUCHING_SUITLESS:
            pAnim = sSamusAnimPointers_Suitless_CrouchingSuitless[acd][direction];

            pArmCannonAnim = sArmCannonAnimPointers_Suitless_CrouchingSuitless[acd][direction];
            break;

        case SPOSE_SAVING_LOADING_GAME:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                if (pData->lastWallTouchedMidAir)
                    pAnim = sSamusAnim_2b0bf4;
                else
                    pAnim = sSamusAnimPointers_Suitless[pose][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suitless_All[pose][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                {
                    if (pData->lastWallTouchedMidAir)
                        pAnim = sSamusAnim_27f430;
                    else
                        pAnim = sSamusAnimPointers_FullSuit[pose][direction];
                }
                else
                {
                    if (pData->lastWallTouchedMidAir)
                        pAnim = sSamusAnim_256484;
                    else
                        pAnim = sSamusAnimPointers_PowerSuit[pose][direction];
                }

                pArmCannonAnim = sArmCannonAnimPointers_Suit_All[pose][direction];
            }
            break;
        
        default:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sSamusAnimPointers_Suitless[pose][direction];
                pArmCannonAnim = sArmCannonAnimPointers_Suitless_All[pose][direction];
            }
            else
            {
                if (pEquipment->suitType != SUIT_NORMAL)
                    pAnim = sSamusAnimPointers_FullSuit[pose][direction];
                else
                    pAnim = sSamusAnimPointers_PowerSuit[pose][direction];

                pArmCannonAnim = sArmCannonAnimPointers_Suit_All[pose][direction];
            }
            break;
    }

    // Offset by current frame
    pAnim = &pAnim[pData->currentAnimationFrame];

    pPhysics->pBodyOam = pAnim->pOam;

    // Offset by current frame
    pGraphics = pAnim->pTopGfx;
    pPhysics->shoulderGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    pPhysics->torsoGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    pPhysics->pShouldersGfx = pGraphics;
    pPhysics->pTorsoGfx = &pGraphics[pPhysics->shoulderGfxSize];

    // Update legs and body
    pGraphics = pAnim->pBottomGfx;
    pPhysics->legsGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    pPhysics->bodyLowerHalfGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    pPhysics->pLegsGfx = pGraphics;
    pPhysics->pBodyLowerHalfGfx = &pGraphics[pPhysics->legsGfxSize];

    pPhysics->unk_22 = 0;

    // Set arm cannon graphics size
    if (pose == SPOSE_DYING)
    {
        pPhysics->armCannonGfxUpperSize = 0;
        pPhysics->armCannonGfxLowerSize = 0;
    }
    else
    {
        pPhysics->armCannonGfxUpperSize = 2 * SAMUS_GFX_PART_SIZE;
        pPhysics->armCannonGfxLowerSize = 2 * SAMUS_GFX_PART_SIZE;
    }

    // Update arm cannon OAM
    pArmCannonAnim = &pArmCannonAnim[pData->currentAnimationFrame];

    pPhysics->pArmCannonOam = pArmCannonAnim->pOam;
    pPhysics->unk_22 = *pPhysics->pArmCannonOam;

    // Fetch current arm cannon graphics based on the current pose and arm cannon direction
    switch (pose)
    {
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
            if (pWeapon->weaponHighlighted & (WH_MISSILE | WH_SUPER_MISSILE))
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_Armed_Hanging[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_Armed_Hanging[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Armed_Hanging[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Armed_Hanging[acd];
                }
            }
            else
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_Hanging[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_Hanging[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Hanging[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Hanging[acd];
                }
            }
            break;

        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
            if (pWeapon->weaponHighlighted & (WH_MISSILE | WH_SUPER_MISSILE))
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_Armed_OnZipline[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_Armed_OnZipline[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Armed_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Armed_Default[acd];
                }
            }
            else
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_OnZipline[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_OnZipline[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Default[acd];
                }
            }
            break;

        case SPOSE_RUNNING:
            if (pData->direction & KEY_RIGHT)
            {
                if (pWeapon->weaponHighlighted & (WH_MISSILE | WH_SUPER_MISSILE))
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Armed_Standing[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Armed_Standing[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Standing[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Standing[acd];
                }
                break;
            }

        default:
            if (pWeapon->weaponHighlighted & (WH_MISSILE | WH_SUPER_MISSILE))
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_Armed_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_Armed_Default[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Armed_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Armed_Default[acd];
                }
            }
            else
            {
                if (pData->direction & KEY_RIGHT)
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Right_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Right_Default[acd];
                }
                else
                {
                    pPhysics->pArmCannonGfxUpper = sArmCannonGfxPointers_Upper_Left_Default[acd];
                    pPhysics->pArmCannonGfxLower = sArmCannonGfxPointers_Lower_Left_Default[acd];
                }
            }
    }

    // Reset effect graphics info
    pPhysics->unk_36 = 0;
    pPhysics->screwSpeedGfxSize = 0;
    pPhysics->screwShinesparkGfxSize = 0;

    // Update storing shinespark animation if necessary
    if (pScrew->flag == SCREW_SPEED_FLAG_STORING_SHINESPARK)
    {
        pScrew->animationDurationCounter++;
        if (pScrew->animationDurationCounter >=
            sSamusEffectAnim_StoringShinespark[pScrew->currentAnimationFrame].timer)
        {
            pScrew->animationDurationCounter = 0;
            pScrew->currentAnimationFrame++;

            if (sSamusEffectAnim_StoringShinespark[pScrew->currentAnimationFrame].timer == 0)
            {
                pScrew->flag = 0;
            }
        }
    }

    if (pScrew->flag == 0)
        return;

    pPhysics->unk_36 = 1 * SAMUS_GFX_PART_SIZE;

    // Fetch current effect graphics and OAM based on the current pose and the effect flag
    switch (pose)
    {
        case SPOSE_SCREW_ATTACKING:
            pEffectAnim = sSamusEffectAnim_ScrewAttacking;
            break;

        case SPOSE_SHINESPARKING:
            pEffectAnim = sSamusEffectAnimPointers_Shinesparking[pData->forcedMovement][direction];
            break;
    
        case SPOSE_BALLSPARKING:
            pEffectAnim = sSamusEffectAnimPointers_Ballsparking[pData->forcedMovement][direction];
            break;

        case SPOSE_RUNNING:
            pEffectAnim = sSamusEffectAnimPointers_Speedboosting[0][direction];
            break;

        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pData->forcedMovement != FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
            {
                pEffectAnim = sSamusEffectAnim_DelayBeforeBallsparking;
                break;
            }

        default:
            if (pScrew->flag == SCREW_SPEED_FLAG_STORING_SHINESPARK)
                pEffectAnim = sSamusEffectAnim_StoringShinespark;
            break;
    }

    // Offset by current frame
    pEffectAnim = &pEffectAnim[pScrew->currentAnimationFrame];

    // Update OAM
    pPhysics->pScrewSpeedOam = pEffectAnim->pOam;

    // Update graphics
    pGraphics = pEffectAnim->pGraphics;
    pPhysics->screwSpeedGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;
    pPhysics->screwShinesparkGfxSize = *pGraphics++ * SAMUS_GFX_PART_SIZE;

    pPhysics->pScrewSpeedGfx = pGraphics;
    pPhysics->pScrewShinesparkGfx = &pGraphics[pPhysics->screwSpeedGfxSize];
}

/**
 * @brief b46c | 3fc | Updates the palette of Samus
 * 
 * @param pData Samus data pointer
 */
void SamusUpdatePalette(struct SamusData* pData)
{
    const u16* pDefaultPal;
    const u16* pReleasePal;
    const u16* pFlashingPal;
    const u16* pSpeedboostPal;
    const u16* pUnmorphPal;
    const u16* pChargingPal;
    const u16* pSavingPal;
    const u16* pDyingPal;
    const u16* pMapDownloadPal;
    const u16* pBufferPal;
    struct Equipment* pEquipment;
    struct WeaponInfo* pWeapon;
    u16 caf;
    u32 offset;
    s32 rng;
    u8 chargeCounter;
    u8 limit;

    pWeapon = &gSamusWeaponInfo;
    pEquipment = &gEquipment;

    gSamusPaletteSize = 4 * 16;

    if (pWeapon->beamReleasePaletteTimer != 0)
        pWeapon->beamReleasePaletteTimer--;

    if (pData->unmorphPaletteTimer != 0)
        pData->unmorphPaletteTimer--;

    if (pEquipment->suitType == SUIT_FULLY_POWERED)
    {
        if (pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT)
        {
            pDefaultPal = sSamusPal_GravitySuit_Default;
            pReleasePal = sSamusPal_GravitySuit_BeamRelease;
            pFlashingPal = sSamusPal_GravitySuit_Flashing;
            pSpeedboostPal = sSamusPal_GravitySuit_Speedboost;
            pUnmorphPal = sSamusPal_GravitySuit_Unmorph;
            pChargingPal = sSamusPal_GravitySuit_ChargingBeam;
            pSavingPal = sSamusPal_GravitySuit_SavingPointers[pData->currentAnimationFrame];
            pDyingPal = sSamusPal_GravitySuit_Dying;
            pMapDownloadPal = sSamusPal_GravitySuit_DownloadingMapPointers[pData->currentAnimationFrame];
        }
        else
        {
            pDefaultPal = sSamusPal_FullSuit_Default;
            pReleasePal = sSamusPal_FullSuit_BeamRelease;
            pFlashingPal = sSamusPal_FullSuit_Flashing;
            pSpeedboostPal = sSamusPal_FullSuit_Speedboost;
            pUnmorphPal = sSamusPal_FullSuit_Unmorph;
            pChargingPal = sSamusPal_FullSuit_ChargingBeam;
            pSavingPal = sSamusPal_FullSuit_SavingPointers[pData->currentAnimationFrame];
            pDyingPal = sSamusPal_FullSuit_Dying;
            pMapDownloadPal = sSamusPal_FullSuit_DownloadingMapPointers[pData->currentAnimationFrame];
        }
    }
    else if (pEquipment->suitType == SUIT_NORMAL)
    {

        if (pEquipment->suitMiscActivation & SMF_VARIA_SUIT)
        {
            pDefaultPal = sSamusPal_VariaSuit_Default;
            pReleasePal = sSamusPal_VariaSuit_BeamRelease;
            pFlashingPal = sSamusPal_VariaSuit_Flashing;
            pSpeedboostPal = sSamusPal_VariaSuit_Speedboost;
            pUnmorphPal = sSamusPal_VariaSuit_Unmorph;
            pChargingPal = sSamusPal_VariaSuit_ChargingBeam;
            pSavingPal = sSamusPal_VariaSuit_SavingPointers[pData->currentAnimationFrame];
            pDyingPal = sSamusPal_VariaSuit_Dying;
            pMapDownloadPal = sSamusPal_VariaSuit_DownloadingMapPointers[pData->currentAnimationFrame];
        }
        else
        {
            pDefaultPal = sSamusPal_PowerSuit_Default;
            pReleasePal = sSamusPal_PowerSuit_BeamRelease;
            pFlashingPal = sSamusPal_PowerSuit_Flashing;
            pSpeedboostPal = sSamusPal_PowerSuit_Speedboost;
            pUnmorphPal = sSamusPal_PowerSuit_Unmorph;
            pChargingPal = sSamusPal_PowerSuit_ChargingBeam;
            pSavingPal = sSamusPal_PowerSuit_SavingPointers[pData->currentAnimationFrame];
            pDyingPal = sSamusPal_PowerSuit_Dying;
            pMapDownloadPal = sSamusPal_PowerSuit_DownloadingMapPointers[pData->currentAnimationFrame];
        }
    }
    else
    {
        pDefaultPal = sSamusPal_Suitless_Default;
        pReleasePal = sSamusPal_Suitless_BeamRelease;
        pFlashingPal = sSamusPal_Suitless_Flashing;
        pSpeedboostPal = sSamusPal_PowerSuit_Speedboost;
        pUnmorphPal = sSamusPal_PowerSuit_Unmorph;
        pChargingPal = sSamusPal_Suitless_ChargingBeam;
        pSavingPal = sSamusPal_Suitless_SavingPointers[pData->currentAnimationFrame];
        pDyingPal = sSamusPal_Generic_Dying;
        pMapDownloadPal = sSamusPal_Suitless_DownloadingMapPointers[pData->currentAnimationFrame];
    }

    if (pData->pose == SPOSE_DYING)
    {
        pBufferPal = sSamusPal_PowerSuit_Dying;
        SamusCopyPalette(pBufferPal, 0, 16);

        if (pData->walljumpTimer == 0)
        {
            caf = pData->currentAnimationFrame;

            if (caf == 11 || caf == 15)
                pBufferPal += 16 * 2;
            else if (caf == 12 || caf == 14)
                pBufferPal += 16 * 4;
            else if (caf == 13)
                pBufferPal += 16 * 6;
            else if (caf > 10)
                pBufferPal += 16 * 1;
            else
                pBufferPal = pDyingPal;
        }
        else
        {
            pBufferPal += pData->walljumpTimer * 16;
        }

        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->invincibilityTimer != 0)
    {
        pData->invincibilityTimer--;

        do {
            if ((gFrameCounter8Bit & 3) <= 1)
                pBufferPal = pFlashingPal;
            else
                pBufferPal = pFlashingPal + 16;
        } while (0);
    
        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (gSamusHazardDamage.paletteTimer != 0 && (gSamusHazardDamage.paletteTimer & 15) > 7)
    {
        pBufferPal = pFlashingPal + 16;
        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->speedboostingShinesparking != 0 || pData->shinesparkTimer != 0)
    {
        rng = gFrameCounter8Bit % 6;
        
        if (rng >= 0)
            if (rng <= 1)
                pBufferPal = pSpeedboostPal;
            else if (rng > 3)
                goto speedboostPal_extern_else; // Needed to produce matching ASM.
            else
                pBufferPal = pSpeedboostPal + 16;
        else
        {
            speedboostPal_extern_else:
            pBufferPal = pSpeedboostPal + 16 * 2;
        }

        SamusCopyPalette(pBufferPal, 0, 16);
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->pose == SPOSE_SCREW_ATTACKING)
    {
        if (pData->currentAnimationFrame & 1)
            pBufferPal = pFlashingPal + 16;
        else
            pBufferPal = pDefaultPal;
        
        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->pose == SPOSE_SAVING_LOADING_GAME)
    {
        pBufferPal = pSavingPal;
        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16 * 2;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->pose == SPOSE_DOWNLOADING_MAP_DATA)
    {
        if (pData->timer)
            pBufferPal = pDefaultPal;
        else
            pBufferPal = pMapDownloadPal;

        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16 * 2;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pWeapon->beamReleasePaletteTimer != 0)
    {
        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
            pBufferPal = pReleasePal + 16 * 2;
        else if (pEquipment->beamBombsActivation & BBF_PLASMA_BEAM)
            pBufferPal = pReleasePal + 16 * 4;
        else if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
            pBufferPal = pReleasePal + 16 * 3;
        else if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
            pBufferPal = pReleasePal + 16 * 1;
        else
            pBufferPal = pReleasePal;

        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    if (pData->unmorphPaletteTimer)
    {
        if ((u8)(pData->unmorphPaletteTimer - 5) > 4)
            pBufferPal = pUnmorphPal;
        else
            pBufferPal = pUnmorphPal + 16;

        SamusCopyPalette(pBufferPal, 0, 16);
        pBufferPal = pDefaultPal + 16;
        SamusCopyPalette(pBufferPal, 16, 16);
        return;
    }
    
    pBufferPal = pDefaultPal;
    if (pEquipment->suitType != SUIT_SUITLESS)
    {
        s32 tmp; // Needed to produce matching ASM.

        chargeCounter = (tmp = pWeapon->chargeCounter);
        limit = 64;
        if (chargeCounter >= limit)
        {
            offset = (chargeCounter - limit) >> 2;
    
            if (offset != 3)
            {
                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                    pBufferPal = pChargingPal + 16 * 4;
                else if (pEquipment->beamBombsActivation & BBF_PLASMA_BEAM)
                    pBufferPal = pChargingPal + 16 * 8;
                else if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                    pBufferPal = pChargingPal + 16 * 6;
                else if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                    pBufferPal = pChargingPal + 16 * 2;
                else
                    pBufferPal = pChargingPal;
    
                pBufferPal += (offset & 1) * 16;
            }
        }
    }

    SamusCopyPalette(pBufferPal, 0, 16 * 2);
}

/**
 * @brief b868 | 40 | Checks if the low health sound should be played
 * 
 */
void SamusCheckPlayLowHealthSound(void)
{
    struct SamusData* pData;
    struct Equipment* pEquipment;

    pData = &gSamusData;
    pEquipment = &gEquipment;

    if (pEquipment->lowHealth && pData->pose != SPOSE_DYING && gPreventMovementTimer == 0 && MOD_AND(gFrameCounter8Bit, 16) == 0)
        SoundPlay(SOUND_LOW_HEALTH_BEEP);
}

/**
 * @brief b8a8 | 68 | Updates the draw distances and the standing status
 * 
 * @param pData Samus data pointer
 * @param pPhysics Samus physics pointer
 */
void SamusUpdateDrawDistanceAndStandingStatus(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 offset;
    u8 standing;
    
    offset = sSamusVisualData[pData->pose][0];
    pPhysics->drawDistanceLeftOffset = sSamusDrawDistanceOffsets[offset][0];
    pPhysics->drawDistanceTopOffset = sSamusDrawDistanceOffsets[offset][1];
    pPhysics->drawDistanceRightOffset = sSamusDrawDistanceOffsets[offset][2];
    pPhysics->drawDistanceBottomOffset = sSamusDrawDistanceOffsets[offset][3];

    standing = sSamusVisualData[pData->pose][2];
    if (pData->standingStatus != STANDING_ENEMY)
        pData->standingStatus = standing;
}

/**
 * @brief b910 | 3a8 | Updates the arm cannon position offset
 * 
 * @param direction Facing direction
 */
void SamusUpdateArmCannonPositionOffset(u8 direction)
{
    struct SamusData* pData;
    struct Equipment* pEquipment;
    struct SamusPhysics* pPhysics;
    u8 acd;
    u32 pose;
    const struct ArmCannonAnimationData* pAnim;
    const struct ArmCannonOffset* pOffset;
    s32 offset;

    pData = &gSamusData;
    pEquipment = &gEquipment;
    pPhysics = &gSamusPhysics;

    pose = pData->pose;
    acd = pData->armCannonDirection;

    // Get pointer to current arm cannon animation, some poses use their own arrays while the rest have a default one
    switch (pose)
    {
        case SPOSE_RUNNING:
            if (acd > ACD_DOWN)
                acd -= 2;

            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_Running[acd][direction];
            }
            else if (!pData->speedboostingShinesparking)
            {
                pAnim = sArmCannonAnimPointers_Suit_Running[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_Running_Speedboosting[acd][direction];
            }
            break;

        case SPOSE_STANDING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_Standing[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_Standing[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_TurningAround[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_TurningAround[acd][direction];
            }
            break;

        case SPOSE_SHOOTING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_Shooting[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_Shooting[acd][direction];
            }
            break;

        case SPOSE_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_Crouching[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_Crouching[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND_AND_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_TurningAroundAndCrouching[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_TurningAroundAndCrouching[acd][direction];
            }
            break;

        case SPOSE_SHOOTING_AND_CROUCHING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_ShootingAndCrouching[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_ShootingAndCrouching[acd][direction];
            }
            break;

        case SPOSE_MIDAIR:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_MidAir[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_MidAir[acd][direction];
            }
            break;

        case SPOSE_TURNING_AROUND_MIDAIR:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_TurningAroundMidAir[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_TurningAroundMidAir[acd][direction];
            }
            break;

        case SPOSE_LANDING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_Landing[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_Landing[acd][direction];
            }
            break;

        case SPOSE_AIMING_WHILE_HANGING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_AimingWhileHanging[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_AimingWhileHanging[acd][direction];
            }
            break;

        case SPOSE_SHOOTING_WHILE_HANGING:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_ShootingWhileHanging[acd][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_ShootingWhileHanging[acd][direction];
            }
            break;

        case SPOSE_USING_AN_ELEVATOR:
            if (pData->elevatorDirection & KEY_UP)
                acd++;

            pAnim = sArmCannonAnimPointers_Suit_UsingAnElevator[acd][direction];
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_SHINESPARK_COLLISION:
            acd = pData->forcedMovement;
            pAnim = sArmCannonAnimPointers_Suit_Shinesparking[acd][direction];
            break;

        case SPOSE_ON_ZIPLINE:
            pAnim = sArmCannonAnimPointers_Suit_OnZipline[acd][direction];
            break;

        case SPOSE_SHOOTING_ON_ZIPLINE:
            pAnim = sArmCannonAnimPointers_Suit_ShootingOnZipline[acd][direction];
            break;

        case SPOSE_TURNING_ON_ZIPLINE:
            pAnim = sArmCannonAnimPointers_Suit_TurningOnZipline[acd][direction];
            break;

        case SPOSE_CRAWLING_STOPPED:
            acd = pData->forcedMovement;
            pAnim = sArmCannonAnimPointers_Suitless_CrawlingStopped[acd][direction];
            break;

        case SPOSE_UNCROUCHING_SUITLESS:
            pAnim = sArmCannonAnimPointers_Suitless_UncrouchingSuitless[acd][direction];
            break;

        case SPOSE_CROUCHING_SUITLESS:
            pAnim = sArmCannonAnimPointers_Suitless_CrouchingSuitless[acd][direction];
            break;

        default:
            if (pEquipment->suitType == SUIT_SUITLESS)
            {
                pAnim = sArmCannonAnimPointers_Suitless_All[pose][direction];
            }
            else
            {
                pAnim = sArmCannonAnimPointers_Suit_All[pose][direction];
            }
    }

    // Get current animation
    pAnim = &pAnim[pData->currentAnimationFrame];

    pOffset = pAnim->pOffset;

    // Update Y offset
    // Check sign bit set (8-bit)
    offset = pOffset->y;
    if (offset & 0x80)
        pPhysics->armCannonYPositionOffset = offset - 0x80 * 2;
    else
        pPhysics->armCannonYPositionOffset = offset;
    pPhysics->armCannonYPositionOffset++;

    // Update X offset
    // Check sign bit set (9-bit)
    offset = pOffset->x;
    if (offset & 0x100)
        pPhysics->armCannonXPositionOffset = offset - 0x100 * 2;
    else
        pPhysics->armCannonXPositionOffset = offset;
}

/**
 * @brief bcb8 | 130 | Initializes samus data
 * 
 */
void SamusInit(void)
{
    u8 i;
    u32 buffer;

    if (gPauseScreenFlag == 0)
    {
        // Restart echo?
        gSamusEcho.previousPositionCounter = 0;
        gSamusEcho.unknown = 0;

        // Clear env effects
        for (i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++)
            gSamusEnvironmentalEffects[i] = sEnvironmentalEffect_Empty;
    }

    if (gGameModeSub3 == 0)
    {
        if (!gIsLoadingFile)
        {
            // Zero out most of samus's data
            buffer = 0;
            DMA_SET(3, &buffer, &gSamusData,
                C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gSamusData) / sizeof(u32)));
            
            buffer = 0;
            DMA_SET(3, &buffer, &gEquipment,
                C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gEquipment) / sizeof(u32)));
            
            buffer = 0;
            DMA_SET(3, &buffer, &gSamusWeaponInfo,
                C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gSamusWeaponInfo) / sizeof(u32)));
            
            buffer = 0;
            DMA_SET(3, &buffer, &gScrewSpeedAnimation,
                C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gScrewSpeedAnimation) / sizeof(u32)));

            // Clear env effects
            for (i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++)
                gSamusEnvironmentalEffects[i] = sEnvironmentalEffect_Empty;

            // Set starting info
            gSamusData.pose = SPOSE_FACING_THE_FOREGROUND;
            gSamusData.direction = KEY_LEFT;

            gEquipment.maxEnergy = 99;
            gEquipment.currentEnergy = 99;
        }
        else
        {
            // Clear physics
            buffer = 0;
            DMA_SET(3, &buffer, &gSamusPhysics, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gSamusPhysics) / sizeof(u32)));
        }
    }
}

/**
 * @brief bde8 | 4f0 | Draws samus
 * 
 */
void SamusDraw(void)
{
    u8 priority;
    s32 i;
    u16* dst;
    const u16* src;
    u16 nextSlot;
    u16 currSlot;
    s32 j;
    u32 xPosition;
    u32 yPosition;
    u16 part1;
    u16 part2;
    s32 ppc;
    s32 futureSlot;

    priority = 2;

    if (gSamusData.pose == SPOSE_DYING)
    {
        priority = 0;
        gNextOamSlot = 0;

        for (i = 0; i < ARRAY_SIZE(gSamusEnvironmentalEffects); i++)
            gSamusEnvironmentalEffects[i].type = 0;
    }
    else if (gSamusOnTopOfBackgrounds)
        priority = 1;

    if (gNextOamSlot > 0x6A)
        gNextOamSlot = 0x6A;

    dst = (u16*)(gOamData + gNextOamSlot);
    nextSlot = gNextOamSlot;
    currSlot = gNextOamSlot;

    // Draw environmental effects
    for (j = 0; j < ARRAY_SIZE(gSamusEnvironmentalEffects); j = (s16)(j + 1))
    {
        if (gSamusEnvironmentalEffects[j].type == ENV_EFFECT_NONE)
            continue;

        // Get oam pointer
        src = gSamusEnvironmentalEffects[j].pOamFrame;

        // Update next oam slot
        part1 = *src++;
        nextSlot += LOW_BYTE(part1);

        // Get position
        xPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusEnvironmentalEffects[j].xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition));
        yPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusEnvironmentalEffects[j].yPosition) -
            SUB_PIXEL_TO_PIXEL(gBg1YPosition) + SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2));

        // Write data
        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    // Get position
    xPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusData.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition));
    yPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusData.yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition) + SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2));

    if (gSamusPhysics.unk_36 & 0x20)
    {
        // Draw screw/speed oam
        src = gSamusPhysics.pScrewSpeedOam;
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    if (gSamusPhysics.unk_22 & ARM_CANNON_OAM_ORDER_BEHIND)
    {
        // Draw arm cannon oam
        src = gSamusPhysics.pArmCannonOam;
        part1 = *src++;
        nextSlot += LOW_BYTE(part1);

        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    // Draw body oam (always)
    src = gSamusPhysics.pBodyOam;
    nextSlot += *src++;

    for (; currSlot < nextSlot; currSlot++)
    {
        part1 = *src++;
        *dst++ = part1;

        gOamData[currSlot].split.y = part1 + yPosition;

        part2 = *src++;
        *dst++ = part2;

        gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

        *dst++ = *src++;

        gOamData[currSlot].split.priority = priority;
        
        dst++;
    }

    if (gSamusPhysics.unk_22 & ARM_CANNON_OAM_ORDER_IN_FRONT)
    {
        src = gSamusPhysics.pArmCannonOam;
        part1 = *src++;
        nextSlot += LOW_BYTE(part1);

        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    if (gSamusPhysics.unk_36 & 0x10)
    {
        src = gSamusPhysics.pScrewSpeedOam;
        part1 = *src++;
        futureSlot = nextSlot + LOW_BYTE(part1);

        if (futureSlot > OAM_BUFFER_DATA_SIZE)
        {
            gNextOamSlot = nextSlot;
            return;
        }

        nextSlot = futureSlot;

        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            
            dst++;
        }
    }

    // Draw echo
    if (gSamusEcho.active)
    {
        ppc = (s16)(gSamusEcho.previousPositionCounter - (gSamusEcho.distance * gSamusEcho.position) - 3);

        if (gSamusEcho.unknown == 0 && ppc < 0)
        {
            gNextOamSlot = nextSlot;
            return;
        }

        // Use body oam
        src = gSamusPhysics.pBodyOam;
        part1 = *src++;
        futureSlot = nextSlot + LOW_BYTE(part1);

        if (futureSlot > OAM_BUFFER_DATA_SIZE)
        {
            gNextOamSlot = nextSlot;
            return;
        }

        nextSlot = futureSlot;

        ppc = MOD_AND(ppc, ARRAY_SIZE(gSamusEcho.previous64XPositions));
        
        xPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusEcho.previous64XPositions[ppc]) - SUB_PIXEL_TO_PIXEL(gBg1XPosition));
        yPosition = (s16)(SUB_PIXEL_TO_PIXEL(gSamusEcho.previous64YPositions[ppc]) -
            SUB_PIXEL_TO_PIXEL(gBg1YPosition) + SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 2));

        for (; currSlot < nextSlot; currSlot++)
        {
            part1 = *src++;
            *dst++ = part1;

            gOamData[currSlot].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;

            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 512);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = priority;
            gOamData[currSlot].split.paletteNum = 1;
            
            dst++;
        }

        gSamusEcho.position = MOD_AND(gSamusEcho.position + 1, 4);
    }

    gNextOamSlot = nextSlot;
}
