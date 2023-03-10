#include "gba.h"
#include "samus.h"
#include "block.h" // Necessary
#include "clipdata.h" // Necessary
#include "macros.h"
#include "temp_globals.h"

#include "data/samus_sprites_pointers.h"

#include "constants/clipdata.h"
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

const i16 samus_hitbox_data[4][4];
const i16 samus_visual_data[4][4];
const i16 samus_draw_distance_offsets[4][4];
const u16 SamusPullingSelfUp_velocity[8];
const struct FrameData* sSamusEnvEffectsFrameDataPointers[18];

void SamusCheckScrewSpeedboosterAffectingEnvironment(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    // https://decomp.me/scratch/GTfBG

    u16 action;
    u16 xLeft;
    u16 xRight;
    u16 yTop;
    u16 yBottom;
    u8 checkBlockBelow;

    action = DESTRUCTING_ACTION_NONE;

    if (pData->pose == SPOSE_SCREW_ATTACKING)
        action = DESTRUCTING_ACTION_SCREW;
    else if (pData->pose == SPOSE_STARTING_SPIN_JUMP && gEquipment.suitMiscActivation & SMF_SCREW_ATTACK)
        action = DESTRUCTING_ACTION_SCREW;

    if (pData->speedboostingShinesparking)
        action += DESTRUCTING_ACTION_SPEED;

    if (action != DESTRUCTING_ACTION_NONE)
    {
        xLeft = pData->xPosition + pPhysics->hitboxLeftOffset;
        xRight = pData->xPosition + pPhysics->hitboxRightOffset;
        yTop = pData->yPosition + pPhysics->hitboxTopOffset;
        yBottom = pData->yPosition;
        
        checkBlockBelow = FALSE;
        if (pPhysics->hitboxTopOffset < -0x40)
            checkBlockBelow = TRUE;

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yTop, action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yTop, action);

        if (pPhysics->horizontalMovingDirection == HDMOVING_RIGHT)
        {
            if (checkBlockBelow)
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yTop + BLOCK_SIZE, action);
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yBottom, action);
        }
        else
        {
            if (checkBlockBelow)
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yTop + BLOCK_SIZE, action);
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yBottom, action);
        }

        if (pPhysics->standingStatus == STANDING_GROUND)
        {
            yBottom++;
            action = DESTRUCTING_ACTION_SPEED_ON_GROUND;
        }

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xLeft, yBottom, action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(xRight, yBottom, action);
    }
}

u8 SamusSlopeRelated(u16 xPosition, u16 yPosition, u16* pXPosition, u16* pYPosition, u16* pSlope)
{
    // https://decomp.me/scratch/bv4B0

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

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            newY = ((yPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG) - (xPosition & SUB_PIXEL_POSITION_FLAG);
            newX = ((xPosition & BLOCK_POSITION_FLAG) + SUB_PIXEL_POSITION_FLAG) - (yPosition & SUB_PIXEL_POSITION_FLAG);
            slopeType = SLOPE_STEEP | KEY_RIGHT;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            newY = (yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) - SUB_PIXEL_POSITION_FLAG);
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
 * @param pData Samus Data Pointer
 * @param pPhysics Samus Physics Pointer
 * @param xPosition X Position
 * @param pPosition Result X Position
 * @return u8 Collision result
 */
u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition)
{
    u8 result;
    u16 yPosition;
    i32 clipdata;

    result = SAMUS_COLLISION_DETECTION_NONE;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
    else
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + SUB_PIXEL_POSITION_FLAG;

    yPosition = pData->yPosition + pPhysics->hitboxTopOffset;
    clipdata = ClipdataProcessForSamus(yPosition, xPosition);

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
                result += SAMUS_COLLISION_DETECTION_LEFT_MOST;
    }

    if (pPhysics->hitboxTopOffset >= -BLOCK_SIZE)
        return result;

    clipdata = ClipdataProcessForSamus(yPosition + BLOCK_SIZE, xPosition);


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

    return result;
}

/**
 * @brief 56b8 | dc | Checks for the top sides blocks when jumping
 * 
 * @param pData Samus Data Pointer
 * @param pPhysics Samus Physics Pointer
 * @param xPosition X Position
 * @param pPosition Pointer To X Position
 * @return u8 Collision result
 */
u8 SamusCheckTopSideCollisionMidAir(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition)
{
    u8 result;
    i32 clip;
    u16 y_pos;

    result = SAMUS_COLLISION_DETECTION_NONE;
    
    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxLeftOffset;
    else
        *pPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - pPhysics->hitboxRightOffset + 0x3F;

    y_pos = pData->yPosition;
    clip = ClipdataProcessForSamus(y_pos, xPosition);
    if (clip & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (clip & 0xFF)
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
        clip = ClipdataProcessForSamus(pData->yPosition, pData->xPosition);

        switch (clip & 0xFF)
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

    if (pPhysics->hitboxTopOffset < -0x40)
    {
        clip = ClipdataProcessForSamus(y_pos - 0x40, xPosition);

        switch (clip & 0xFF)
        {
            case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
                break;

            default:
                if (clip & CLIPDATA_TYPE_SOLID_FLAG)
                    result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;
        }
    }

    return result;
}

/**
 * @brief 5794 | 58 | Checks if samus is colliding with a slope when walking
 * 
 * @param pData Samus Data Pointer
 * @param xPosition X Position
 * @return u8 Collision result
 */
u8 SamusCheckWalkingOnSlope(struct SamusData* pData, u16 xPosition)
{
    u8 result;
    i32 clip;

    result = SAMUS_COLLISION_DETECTION_NONE;
    clip = ClipdataProcessForSamus(pData->yPosition, xPosition);
    if (clip & CLIPDATA_TYPE_SOLID_FLAG)
    {
        switch (clip & 0xFF)
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
        clip = ClipdataProcessForSamus(pData->yPosition, pData->xPosition);

        switch (clip & 0xFF)
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

u8 SamusCheckCollisionAbove(struct SamusData* pData, i16 hitbox)
{
    // https://decomp.me/scratch/ZW8uX

    u8 result;
    u16 yPosition;
    i32 clipdata;
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    result = SAMUS_COLLISION_DETECTION_NONE;

    yPosition = pData->yPosition + (i16)hitbox; // ?
    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + pPhysics->hitboxLeftOffset);
    
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_LEFT_MOST;

    // samus_hitbox_data pool probably inccorect
    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + samus_hitbox_data[0][0]);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_MIDDLE_LEFT;

    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + samus_hitbox_data[0][1]);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT;

    clipdata = ClipdataProcessForSamus(yPosition, pData->xPosition + pPhysics->hitboxRightOffset);
    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
        result += SAMUS_COLLISION_DETECTION_RIGHT_MOST;

    return result;
}

u8 SamusCheckWalkingSidesCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 unk_5AD8(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 SamusCheckStandingOnGroundCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

u8 SamusCheckLandingCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    // https://decomp.me/scratch/zWpei

    u16 resultXLeft;
    u16 resultYLeft;
    u16 resultSlopeLeft;

    u16 resultXRight;
    u16 resultYRight;
    u16 resultSlopeRight;

    u16 horizontalHitbox;
    u8 collisionLeft;
    u8 collisionRight;

    u16 currentSubpixelY;
    u16 previousSubpixelY;

    i16* pLeftHitbox;
    i16* pRightHitbox;
    i16* tempPtr;

    if (pPhysics->horizontalMovingDirection == HDMOVING_LEFT)
    {
        horizontalHitbox = pPhysics->hitboxLeftOffset;
        pLeftHitbox = &pPhysics->hitboxLeftOffset;
    }
    else
    {
        horizontalHitbox = pPhysics->hitboxRightOffset;
        pLeftHitbox = &pPhysics->hitboxLeftOffset;
    }

    if (unk_5604(pData, pPhysics, pData->xPosition + horizontalHitbox, &resultXLeft) != SAMUS_COLLISION_DETECTION_NONE)
    {
        pData->xPosition = resultXLeft;
        pPhysics->touchingSideBlock++;
    }

    if (pData->standingStatus == STANDING_ENEMY)
        return SPOSE_NONE;

    currentSubpixelY = pData->yPosition & BLOCK_POSITION_FLAG;
    previousSubpixelY = gPreviousYPosition;
    previousSubpixelY &= BLOCK_POSITION_FLAG;

    tempPtr = pLeftHitbox;
    collisionLeft = SamusSlopeRelated(pData->xPosition + *pLeftHitbox, pData->yPosition, &resultXLeft, &resultYLeft, &resultSlopeLeft);
    
    pRightHitbox = &pPhysics->hitboxRightOffset;
    collisionRight = SamusSlopeRelated(pData->xPosition + *pRightHitbox, pData->yPosition, &resultXRight, &resultYRight, &resultSlopeRight);

    if (currentSubpixelY > previousSubpixelY)
    {
        if (collisionLeft != CLIPDATA_TYPE_AIR)
        {
            if (resultSlopeLeft != SLOPE_NONE)
            {
                if (collisionRight != CLIPDATA_TYPE_AIR)
                    pData->yPosition = resultYRight - 1;
                else
                {
                    pData->currentSlope = resultSlopeLeft;
                    pData->yPosition = resultYLeft;
                }

                return SPOSE_LANDING_REQUEST;
            }

            SamusSlopeRelated(pData->xPosition + *tempPtr, pData->yPosition - BLOCK_SIZE,
                &resultXLeft, &resultYLeft, &resultSlopeLeft);

            pData->yPosition = resultYLeft;
            if (resultSlopeLeft == SLOPE_NONE)
                pData->yPosition += SUB_PIXEL_POSITION_FLAG;

            pData->currentSlope = resultSlopeLeft;
            return SPOSE_LANDING_REQUEST;
        }

        if (collisionRight == CLIPDATA_TYPE_AIR)
            return SPOSE_NONE;

        if (resultSlopeRight == SLOPE_NONE)
        {
            SamusSlopeRelated(pData->xPosition + *pRightHitbox, pData->yPosition - BLOCK_SIZE,
                &resultXLeft, &resultYLeft, &resultSlopeLeft);

            pData->yPosition = resultYLeft;
            if (resultSlopeLeft == SLOPE_NONE)
                pData->yPosition += SUB_PIXEL_POSITION_FLAG;

            pData->currentSlope = resultSlopeLeft;
            return SPOSE_LANDING_REQUEST;
        }
    
        pData->currentSlope = resultSlopeRight;
        pData->yPosition = resultYRight;
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

        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - *pLeftHitbox;
        pPhysics->touchingSideBlock++;
        return SPOSE_NONE;
    }

    if (collisionRight == CLIPDATA_TYPE_AIR)
        return SPOSE_NONE;

    if (resultSlopeLeft == SLOPE_NONE)
    {
        pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - *pRightHitbox + SUB_PIXEL_POSITION_FLAG;
        pPhysics->touchingSideBlock++;
        return SPOSE_NONE;
    }
    
    pData->currentSlope = resultSlopeLeft;
    pData->yPosition = resultYRight;
    return SPOSE_LANDING_REQUEST;
}

u8 SamusCheckTopCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

/**
 * @brief 5f38 | 2dc | Checks the collisions for Samus
 * 
 * @param pData Samus Data Pointer
 * @param pPhysics Samus Physics Pointer
 */
void SamusCheckCollisions(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 newPose;
    i32 xOffset;
    u32 blockPrevent;
    u32 blockGrabbing;
    u32 blockAbove;
    i32 movementBlock;

    if (pPhysics->standingStatus > STANDING_NOT_IN_CONTROL)
        return;

    SamusCheckScrewSpeedboosterAffectingEnvironment(pData, pPhysics);
    newPose = SPOSE_NONE;

    if (pPhysics->verticalMovingDirection == VDMOVING_UP)
        newPose = SamusCheckTopCollision(pData, pPhysics);
    else if (pPhysics->verticalMovingDirection == VDMOVING_DOWN)
        newPose = SamusCheckLandingCollision(pData, pPhysics);
    else
    {
        if (pPhysics->horizontalMovingDirection != VDMOVING_NONE)
        {
            if (pPhysics->standingStatus == STANDING_MIDAIR)
                newPose = SamusCheckLandingCollision(pData, pPhysics);
            else
            {
                newPose = SamusCheckWalkingSidesCollision(pData, pPhysics);
                if (newPose == SPOSE_NONE)
                    newPose = unk_5AD8(pData, pPhysics);

            }
        }
        else if (pPhysics->standingStatus == STANDING_GROUND)
            newPose = SamusCheckStandingOnGroundCollision(pData, pPhysics);
    }

    if (newPose == SPOSE_NONE)
    {
        if (gEquipment.suitMiscActivation & SMF_POWER_GRIP && gButtonInput & pData->direction && pData->yVelocity < 0x1)
        {
            if (pData->direction & KEY_RIGHT)
                xOffset = 0x1F;
            else
                xOffset = -0x1F;

            blockPrevent = ClipdataProcessForSamus(pData->yPosition + HALF_BLOCK_SIZE, pData->xPosition);
            if (blockPrevent == CLIPDATA_TYPE_AIR)
            {
                blockPrevent = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), pData->xPosition);
                blockPrevent &= CLIPDATA_TYPE_SOLID_FLAG;
                blockGrabbing = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE + 0x28), pData->xPosition + xOffset);
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
                        movementBlock = ClipdataCheckCurrentAffectingAtPosition(
                            pData->yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            pData->xPosition + xOffset);
                        movementBlock >>= 0x10;

                        if (!blockPrevent && blockGrabbing &&
                            movementBlock != CLIPDATA_MOVEMENT_NON_POWER_GRIP && !blockAbove)
                        {
                            if (gEquipment.suitType == SUIT_SUITLESS)
                            {
                                newPose = SPOSE_GRABBING_A_LEDGE_SUITLESS;
                                SoundPlay(0x9B);
                            }
                            else
                            {
                                newPose = SPOSE_HANGING_ON_LEDGE;
                                if (pPhysics->slowedByLiquid)
                                    SoundPlay(0x95);
                                else
                                    SoundPlay(0x7A);
                            }
                        }
                }
            }
        }
    }

    if (pPhysics->touchingSideBlock)
    {
        pData->xVelocity = 0x0;

        switch (pData->pose)
        {
            case SPOSE_RUNNING:
                if (gEquipment.suitType == SUIT_SUITLESS && gSamusDataCopy.timer == 0x1)
                    newPose = SPOSE_CROUCHING_TO_CRAWL;
                break;

            case SPOSE_SPINNING:
            case SPOSE_SCREW_ATTACKING:
                pData->walljumpTimer = 0x8;
                pData->lastWallTouchedMidAir = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
                break;

            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
            case SPOSE_TURNING_ON_ZIPLINE:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                newPose = SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
    }

    if (pPhysics->standingStatus != STANDING_INVALID)
    {
        if (newPose == SPOSE_UPDATE_JUMP_VELOCITY_REQUEST)
            pData->yPosition++;

        if (newPose != SPOSE_NONE)
            SamusSetPose(newPose);
    }
}

/**
 * 6214 | 3dc | Checks if an environment effect for samus can/should spawn and spawns it
 * 
 * @param pData Samus Data Pointer
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

    if (defaultOffset == 0x0)
    {
        for (i = 0; i < 0x3; i++)
        {
            if (gSamusEnvironmentalEffects[i].type == ENV_EFFECT_NONE)
                break;
        }
        if (i > 0x2)
            canSpawn--;
    }
    else
        i = defaultOffset;

    switch (request)
    {
        case WANTING_RUNNING_EFFECT:
        case WANTING_RUNNING_EFFECT_:
            if (pData->direction & KEY_RIGHT)
                nextX = pData->xPosition + 4;
            else
                nextX = pData->xPosition - 4;

            affecting = ClipdataCheckGroundEffect(pData->yPosition + 1, nextX);
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(0xA1);
                    else
                        SoundPlay(0x68);
                }
                else
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(0xA2);
                    else
                        SoundPlay(0x69);
                }
            }
            else if (affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66);
                else
                    SoundPlay(0x67);
            }
            else if (affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66);
                else
                    SoundPlay(0x67);
            }

            xPosition = nextX;
            yPosition = pData->yPosition;
            break;

        case WANTING_LANDING_EFFECT:
            affecting = ClipdataCheckGroundEffect(pData->yPosition + 1, pData->xPosition);
            if (affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_WET_GROUND;
                found++;

                if (gEquipment.suitType == SUIT_SUITLESS)
                    SoundPlay(0xA3); // Suitless landing on wet ground
                else
                    SoundPlay(0x74); // Landing on wet ground
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
                SoundPlay(0x73); // Landing on very dusty ground
            }
            else if (affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND;
                found++;
                SoundPlay(0x73); // Landing on very dusty ground
            }
            else
            {
                if (pPhysics->slowedByLiquid)
                    SoundPlay(0x95);
                else if (gSamusDataCopy.lastWallTouchedMidAir != 0)
                    SoundPlay(0x72);
                else if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(0x71);
                else
                    SoundPlay(0x99);
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
                liquidCheckY -= QUARTER_BLOCK_SIZE;
                previousY -= QUARTER_BLOCK_SIZE;
            }

            affecting = ClipdataCheckCurrentAffectingAtPosition(liquidCheckY, pData->xPosition);
            affecting &= 0xFF;
            previousAffecting = ClipdataCheckCurrentAffectingAtPosition(previousY, pData->xPosition);
            previousAffecting &= 0xFF;

            if (liquidCheckY < previousY)
            {
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
            if (gEffectYPosition != 0)
                yPosition = gEffectYPosition;
            else
            {
                if (liquidCheckY < previousY)
                    yPosition = gPreviousYPosition & BLOCK_POSITION_FLAG;
                else
                    yPosition = pData->yPosition & BLOCK_POSITION_FLAG;
            }

            break;

        case WANTING_BREATHING_BUBBLES:
            if (pData->standingStatus != STANDING_MIDAIR)
            {
                effect = ENV_EFFECT_BREATHING_BUBBLES;
                found++;

                if (pData->direction & KEY_RIGHT)
                    xPosition = pData->xPosition + 12;
                else
                    xPosition = pData->xPosition - 12;

                yPosition = pData->yPosition + pPhysics->drawDistanceTopOffset + QUARTER_BLOCK_SIZE;
                SoundPlay(0x91); // Liquid bubbling
            }
            break;

        case WANTING_SKIDDING_EFFECT:
            affecting = ClipdataCheckGroundEffect(pData->yPosition + 1, pData->xPosition);
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
            affecting = ClipdataCheckGroundEffect(pData->yPosition + 1, pData->xPosition);
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
 * @param pData Samus Data Pointer
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

    if ((ClipdataCheckCurrentAffectingAtPosition(pData->yPosition - BLOCK_SIZE * 2, pData->xPosition) & 0xFF) == HAZARD_TYPE_WATER)
    {
        if (pEnv->breathingTimer < 220)
            pEnv->breathingTimer++;
        else
        {
            SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_BREATHING_BUBBLES);
            pEnv->breathingTimer = 0;
        }
    }

    pEnv += 4;
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
                yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
                break;

            default:
                yPosition = pData->yPosition;
        }

        affecting = ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition);
        affecting &= 0xFF;
        affectingTop = ClipdataCheckCurrentAffectingAtPosition(yPosition + pPhysics->drawDistanceTopOffset - 8, pData->xPosition);
        affectingTop &= 0xFF;

        if (pPhysics->drawDistanceTopOffset > -BLOCK_SIZE)
            liquidY = yPosition - BLOCK_SIZE;
        else
            liquidY = yPosition + pPhysics->drawDistanceTopOffset;

        affectingLiquid = ClipdataCheckCurrentAffectingAtPosition(liquidY, pData->xPosition);
        affectingLiquid &= 0xFF;

        subAnimEnded = FALSE;

        if (affecting == HAZARD_TYPE_STRONG_LAVA && affectingTop != HAZARD_TYPE_STRONG_LAVA)
        {
            if (!(gEquipment.suitMiscActivation & SMF_GRAVITY_SUIT))
            {
                effect = ENV_EFFECT_TAKING_DAMAGE_IN_LAVA;
                subAnimEnded++;
            }
        }
        else if (affecting == HAZARD_TYPE_WEAK_LAVA && affectingTop != HAZARD_TYPE_WEAK_LAVA)
        {
            if (!(gEquipment.suitMiscActivation & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)))
            {
                effect = ENV_EFFECT_TAKING_DAMAGE_IN_LAVA;
                subAnimEnded++;
            }
        }
        else if (affecting == HAZARD_TYPE_ACID && affectingTop != HAZARD_TYPE_ACID)
        {
            effect = ENV_EFFECT_TAKING_DAMAGE_IN_ACID;
            subAnimEnded++;
        }

        if (subAnimEnded)
        {
            pEnv->type = effect;
            pEnv->currentAnimationFrame = 0;
            pEnv->animationDurationCounter = 0;
            pEnv->xPosition = pData->xPosition;

            if (gEffectYPosition != 0)
                pEnv->yPosition = gEffectYPosition;
            else
            {
                if (affectingLiquid == HAZARD_TYPE_STRONG_LAVA || affectingLiquid == HAZARD_TYPE_WEAK_LAVA || affectingLiquid == HAZARD_TYPE_ACID)
                    pEnv->yPosition = liquidY & BLOCK_POSITION_FLAG;
                else
                    pEnv->yPosition = yPosition & BLOCK_POSITION_FLAG;
            }

            SoundPlay(0x7D);
        }
    }

    pEnv = gSamusEnvironmentalEffects;
    for (i = 0; i < 5;)
    {
        effect = pEnv->type;
        if (effect != ENV_EFFECT_NONE)
        {
            pEnv->animationDurationCounter++;

            pOam = sSamusEnvEffectsFrameDataPointers[effect - 1];
            pOam += pEnv->currentAnimationFrame;
            subAnimEnded = FALSE;
            
            if (pEnv->animationDurationCounter >= pOam->timer)
            {
                pEnv->animationDurationCounter = 0;
                pEnv->currentAnimationFrame++;
                pOam++;
                if (pOam->timer == 0)
                {
                    pEnv->type = ENV_EFFECT_NONE;
                    pEnv->currentAnimationFrame = 0;
                }

                subAnimEnded++;
            }

            pEnv->pOamFrame = pOam->pFrame;

            if (subAnimEnded)
            {
                switch (effect)
                {
                    case ENV_EFFECT_GOING_OUT_OF_WATER:
                    case ENV_EFFECT_GOING_OUT_OF_LAVA:
                    case ENV_EFFECT_GOING_OUT_OF_ACID:
                        if (pEnv->currentAnimationFrame == 1)
                            SoundPlay(0x75);
                        break;

                    case ENV_EFFECT_RUNNING_INTO_WATER:
                    case ENV_EFFECT_RUNNING_INTO_LAVA:
                    case ENV_EFFECT_RUNNING_INTO_ACID:
                        if (pEnv->currentAnimationFrame == 1)
                            SoundPlay(0x74);
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

        i++;
        pEnv++;
    }
}

/**
 * 6950 | 2dc | 
 * Updates the jump velocity of samus depending on the previous pose
 * 
 * @param pData Samus Data Pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus Weapon Info Pointer
 */
void SamusUpdateJumpVelocity(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    struct Equipment* pEquipment;

    pEquipment = &gEquipment;
    pData->xVelocity = pCopy->xVelocity;
    pData->armCannonDirection = pCopy->armCannonDirection;
    pData->speedboostingShinesparking = pCopy->speedboostingShinesparking;
    switch (pCopy->pose)
    {
        case SPOSE_RUNNING:
            if (pCopy->forcedMovement != 0x1)
                pData->pose = SPOSE_MIDAIR;
            else
            {
                pData->pose = SPOSE_STARTING_SPIN_JUMP;
                if (pEquipment->suitType == SUIT_SUITLESS)
                    pData->yVelocity = 0xD4;
                else if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                    pData->yVelocity = 0xE8;
                else
                    pData->yVelocity = 0xC0;
            }
            break;

        case SPOSE_STARTING_SPIN_JUMP:
        case SPOSE_SPINNING:
        case SPOSE_SPACE_JUMPING:
        case SPOSE_SCREW_ATTACKING:
            pData->pose = SPOSE_MIDAIR;
            pData->xVelocity = 0x0;
            if (pCopy->forcedMovement == 0x2)
                pData->yVelocity = pCopy->yVelocity;

            if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) )
                pData->yPosition += 0x20;
            break;

        case SPOSE_STARTING_WALL_JUMP:
            if (pCopy->forcedMovement == 0x0)
                pData->pose = SPOSE_MIDAIR;
            else
            {
                pData->pose = SPOSE_SPINNING;
                if (pCopy->forcedMovement == 0x1)
                {
                    if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                        pData->yVelocity = 0xE8;
                    else
                        pData->yVelocity = 0xC0;
                }
                if (gSamusPhysics.slowedByLiquid)
                {
                    pData->yVelocity = 0x74;
                    SoundPlay(0x95);
                }
                else
                {
                    if (gEquipment.suitType != SUIT_SUITLESS)
                        SoundPlay(0x76);
                    else
                        SoundPlay(0x9A);
                }
            }
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            if (pCopy->forcedMovement == 0xA)
            {
                pData->direction = KEY_RIGHT;
                pData->xVelocity = 0x30;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            else if (pCopy->forcedMovement == 0xB)
            {
                pData->xVelocity = 0x0;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            else if (pCopy->forcedMovement == 0xC)
            {
                pData->direction = KEY_LEFT;
                pData->xVelocity = -0x30;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            break;

        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
            pData->currentAnimationFrame = pCopy->currentAnimationFrame;
            pData->animationDurationCounter = pCopy->animationDurationCounter;
        case SPOSE_MORPHING:
            if (pCopy->forcedMovement == 0xA)
            {
                pData->direction = KEY_RIGHT;
                pData->xVelocity = 0x30;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            else if (pCopy->forcedMovement == 0xB)
            {
                pData->xVelocity = 0x0;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            else if (pCopy->forcedMovement == 0xC)
            {
                pData->direction = KEY_LEFT;
                pData->xVelocity = -0x30;
                pData->yVelocity = 0xA4;
                pData->forcedMovement = 0x1;
            }
            else
            {
                pData->xVelocity >>= 0x1;
                if (pCopy->forcedMovement == 0x1)
                    pData->yVelocity = 0xD4;
            }
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
        case SPOSE_BALLSPARK_COLLISION:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
            pData->pose = SPOSE_MORPH_BALL_MIDAIR;
            break;

        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
            if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) )
                pData->yPosition += 0x20;
        default:
            pData->pose = SPOSE_MIDAIR;
            if (pCopy->forcedMovement == 0x1)
            {
                if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
                    pData->pose = SPOSE_STARTING_SPIN_JUMP;
                else
                    pData->pose = SPOSE_MIDAIR;

                if (pEquipment->suitType == SUIT_SUITLESS)
                    pData->yVelocity = 0xD4;
                else if (pEquipment->suitMiscActivation & SMF_HIGH_JUMP)
                    pData->yVelocity = 0xE8;
                else
                    pData->yVelocity = 0xC0;
            }
            else if (pCopy->forcedMovement == 0x2)
                pData->yVelocity = pCopy->yVelocity;
    }

    if (pCopy->forcedMovement == 0x1)
    {
        if (pData->pose == SPOSE_MIDAIR)
        {
            if (!gSamusPhysics.slowedByLiquid)
            {
                if (pData->yVelocity == 0xC0)
                    SoundPlay(0x6E);
                else if (pData->yVelocity == 0xE8)
                    SoundPlay(0x6F);
                else if (pData->yVelocity == 0xD4)
                    SoundPlay(0x9D);
            }
            else
                SoundPlay(0x94);
        }
        else if (pData->pose == SPOSE_MORPH_BALL_MIDAIR)
        {
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(0x94);
            else
                SoundPlay(0x70);
        }
    }
}

/**
 * @brief 6c2c | 280 | Sets a landing pose for Samus
 * 
 * @param pData Samus Data Pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus Weapon Info Pointer
 */
void SamusSetLandingPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    u32 collision;

    pCopy->lastWallTouchedMidAir = KEY_NONE;

    switch (pCopy->pose)
    {
        case SPOSE_MIDAIR:
            collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            if (collision)
                // Blocks above, set crouched
                pData->pose = SPOSE_CROUCHING;
            else if (pCopy->xVelocity == 0x0)
                // No X movement, normal landing
                pData->pose = SPOSE_LANDING;
            else if (pCopy->speedboostingShinesparking)
            {
                // Landing from a fall with speedbooster activated
                pData->pose = SPOSE_RUNNING;
                pData->speedboostingShinesparking = TRUE;
                // Intended to keep speedbooster, however it's immediatly cancelled because of the velocity being too small
            }
            else
                pData->pose = SPOSE_STANDING;
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            pCopy->lastWallTouchedMidAir++;

            if (gButtonInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
            {
                // Check bounce from maintained A
                collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
                if (!(collision & (SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT)))
                    pData->forcedMovement = FORCED_MOVEMENT_MORPH_BALL_BOUNCE_BEFORE_JUMP;
            }
            else
            {
                if (pCopy->yVelocity < -0xC0 && !gSamusPhysics.slowedByLiquid &&
                    ClipdataCheckGroundEffect(pData->yPosition + 1, pData->xPosition) != GROUND_EFFECT_VERY_DUSTY_GROUND)
                {
                    // Morph ball bounce
                    pData->forcedMovement = 0x1;
                    pData->yVelocity = 0x32;
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
                    pData->pose = SPOSE_RUNNING;
                else
                {
                    pData->pose = SPOSE_ROLLING;
                    pData->shinesparkTimer = 0x6;
                }

                pData->speedboostingShinesparking = TRUE;
                pData->timer = 0xA0;
                SoundPlay(0x8B); // Speedbooster start
            }
            else
            {
                // Cancel shinespark
                ScreenShakeStartHorizontal(0x1E, 0x1);

                // Set collision behavior
                if (pCopy->pose == SPOSE_SHINESPARKING)
                    pData->pose = SPOSE_SHINESPARK_COLLISION;
                else
                    pData->pose = SPOSE_BALLSPARK_COLLISION;

                // Keep direction
                pData->forcedMovement = pCopy->forcedMovement;
                pData->currentAnimationFrame = 0x1;
                SoundPlay(0x90);
            }
            break;

        default:
            collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            if (collision)
                pData->pose = SPOSE_CROUCHING;
            else if (pCopy->xVelocity == 0x0)
                pData->pose = SPOSE_LANDING;
            else
                pData->pose = SPOSE_STANDING;
            break;
    }

    pData->armCannonDirection = pCopy->armCannonDirection;

    // Update ACD
    switch (pData->pose)
    {
        case SPOSE_LANDING:
            if (gSamusPhysics.hasNewProjectile)
                pData->currentAnimationFrame = 0x1;
            
            if (pCopy->armCannonDirection == ACD_DOWN)
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
            break;

        case SPOSE_RUNNING:
            if (pCopy->armCannonDirection == ACD_UP)
                pData->armCannonDirection = ACD_DIAGONALLY_UP;

        case SPOSE_STANDING:
            if (pCopy->armCannonDirection == ACD_DOWN)
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
            break;
    }

    // Check effect
    SamusCheckSetEnvironmentalEffect(pData, 0, WANTING_LANDING_EFFECT);
}

void SamusChangeToHurtPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    i16 new_x_velo; 
    i16 new_y_velo; 
    u8 y_pos_related;

    if (gEquipment.currentEnergy != 0x0)
    {
        y_pos_related = 0x0;
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
                pData->pose = SPOSE_GETTING_HURT_IN_MORPH_BALL;
                break;

            case SPOSE_CRAWLING_STOPPED:
            case SPOSE_STARTING_TO_CRAWL:
            case SPOSE_CRAWLING:
            case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            case SPOSE_SHOOTING_WHILE_CRAWLING:
                pData->pose = SPOSE_CRAWLING_STOPPED;
                pData->xVelocity = 0x0;
                break;

            default:
                y_pos_related = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
                pData->pose = SPOSE_GETTING_HURT;
        }

        if (y_pos_related != 0x0)
            pData->yPosition |= 0x3F;

        if (pCopy->forcedMovement == 0xFF)
            pData->forcedMovement = 0x1;

        pData->yVelocity = 0x70;
        if (pCopy->standingStatus == STANDING_MIDAIR)
            pData->yVelocity = 0x38;

        pData->armCannonDirection = pCopy->armCannonDirection;
        SoundPlay(0x7C);
    }
    else
    {
        gDisableScrolling = 0x1;
        gMonochromeBgFading = 0x1;
        pData->pose = SPOSE_DYING;
        new_x_velo = ((gBG1XPosition + 0x1E0) - pData->xPosition);
        new_x_velo >>= 0x1;
        pData->xVelocity = new_x_velo;
        new_y_velo = ((gBG1YPosition + 0x190) - pData->yPosition);
        new_y_velo >>= 0x4;
        pData->yVelocity = new_y_velo;
        gGameModeSub1 = 0x5;
    }

    pData->invincibilityTimer = 0x30;
    pData->shinesparkTimer = 0x0;
    pData->standingStatus = STANDING_MIDAIR;
    pWeapon->newProjectile = PROJECTILE_CATEGORY_NONE;
    pWeapon->beamReleasePaletteTimer = 0x0;
}

void SamusChangeToKnockbackPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    u8 y_pos_related;

    y_pos_related = 0x0;
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
            pData->pose = SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL;
            break;

        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
            pData->pose = SPOSE_CRAWLING_STOPPED;
            break;

        default:
            y_pos_related = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            pData->pose = SPOSE_GETTING_KNOCKED_BACK;
    }
    
    if (y_pos_related != 0x0)
        pData->yPosition |= 0x3F;

    pData->yVelocity = 0x70;
    if (pCopy->standingStatus == STANDING_MIDAIR)
        pData->yVelocity = 0x38;

    pData->armCannonDirection = pCopy->armCannonDirection;
    pData->shinesparkTimer = 0x0;
    pData->standingStatus = STANDING_MIDAIR;
    pWeapon->newProjectile = PROJECTILE_CATEGORY_NONE;
    pWeapon->beamReleasePaletteTimer = 0x0;
}

/**
 * @brief 7164 | 384 | Carries what should be carried from the samus data copy, also handles shinespark direction selection
 * 
 * @param pData Samus Data Pointer
 * @param pCopy Samus Data Copy Pointer
 * @param pWeapon Samus Weapon Info Pointer
 */
void SamusCheckCarryFromCopy(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    // https://decomp.me/scratch/1VwJS

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            if (gButtonInput & gButtonAssignments.diagonalAim || gButtonInput & gButtonAssignments.armMissiles)
                pData->armCannonDirection = pCopy->armCannonDirection;
            else
                pData->armCannonDirection = ACD_NONE;
            break;

        case SPOSE_STANDING:
            pData->armCannonDirection = pCopy->armCannonDirection;
            if (pCopy->pose == SPOSE_CROUCHING || pCopy->pose == SPOSE_SHOOTING_AND_CROUCHING)
                // Timer to ignore input for arm cannon direction, prevents immediatly aiming up after uncrouching
                pData->timer = 0x6;
            break;

        case SPOSE_CROUCHING:
            pData->armCannonDirection = pCopy->armCannonDirection;
            pData->currentAnimationFrame = 0x1;
            if (pData->armCannonDirection < ACD_UP)
                break;
            pData->armCannonDirection = ACD_FORWARD;
            break;

        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            pData->timer = gSamusPhysics.slowedByLiquid;
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(0x94); // Underwater mantling
            else if (gEquipment.suitType != SUIT_SUITLESS)
                SoundPlay(0x7B); // Mantling
            else
                SoundPlay(0x9C); // Suitless mantling
            
        case SPOSE_MORPH_BALL:
            if (pCopy->speedboostingShinesparking)
                pData->timer = 0x6;
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_SKIDDING:
            pData->xVelocity = pCopy->xVelocity;
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_SKIDDING_EFFECT);
            SoundPlay(0x8C); // Skidding
            break;


        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            pData->shinesparkTimer = 0x32;
            SoundPlay(0x8E); // Shinesparking
            break;

        case SPOSE_SHINESPARKING:
        case SPOSE_BALLSPARKING:
            if (pCopy->forcedMovement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
                pData->yVelocity = 0xC0;
            else
            {
                if (gButtonInput & gButtonAssignments.diagonalAim)
                {
                    pData->forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;
                    if (pData->direction & KEY_RIGHT)
                        pData->xVelocity = 0xA0;
                    else
                        pData->xVelocity = -0xA0;

                    pData->yVelocity = 0x60;
                }
                else if (gButtonInput & pData->direction)
                {
                    if (gButtonInput & KEY_UP)
                    {
                        pData->forcedMovement = FORCED_MOVEMENT_DIAGONAL_SHINESPARK;
                        if (pData->direction & KEY_RIGHT)
                            pData->xVelocity = 0xA0;
                        else
                            pData->xVelocity = -0xA0;
                        
                        pData->yVelocity = 0x60;
                    }
                    else
                    {
                        pData->forcedMovement += FORCED_MOVEMENT_SIDEWARDS_SHINESPARK;
                        if (pData->direction & KEY_RIGHT)
                            pData->xVelocity = 0xC0;
                        else
                            pData->xVelocity = -0xC0;
                    }
                }
                else
                {
                    pData->yVelocity = 0xC0;
                }
            }

            pData->speedboostingShinesparking++;
            pData->shinesparkTimer = 0x0;
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            break;

        case SPOSE_SHINESPARK_COLLISION:
            pData->forcedMovement = pCopy->forcedMovement;
            pData->currentAnimationFrame = 0x1;

        case SPOSE_BALLSPARK_COLLISION:
            pData->invincibilityTimer = 0x30;
            SoundPlay(0x90); // Shinespark collision
            break;

        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pCopy->forcedMovement == FORCED_MOVEMENT_LAUNCHED_BY_CANNON)
                pData->forcedMovement = FORCED_MOVEMENT_LAUNCHED_BY_CANNON;
            else
                gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_SHINESPARKING;
            SoundPlay(0x8F); // Ballspark
            break;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_GRABBING_A_LEDGE_SUITLESS:
            if ((pData->yPosition & SUB_PIXEL_POSITION_FLAG) < 0x1F)
                pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) + 0x8;
            else
                pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) + 0x48;
            pWeapon->diagonalAim = DIAG_AIM_NONE;

            gSamusEcho.active = FALSE;
            gSamusEcho.timer = 0x0;
            break;

        case SPOSE_USING_AN_ELEVATOR:
            pData->elevatorDirection = pCopy->elevatorDirection;
            if (pData->elevatorDirection & KEY_UP)
                pData->yVelocity = 0x8;
            else
                pData->yVelocity = -0x8;
            
            SoundPlay(0x10E); // Elevator
            break;

        case SPOSE_TURNING_FROM_FACING_THE_FOREGROUND:
            pData->elevatorDirection = pCopy->elevatorDirection;
            
            #ifndef NONMATCHING
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            #else
            goto DiagNone;
            #endif
            break;

        case SPOSE_ON_ZIPLINE:
            if ((u8)(pCopy->pose - 0x29) > 0x1)
            {
                pWeapon->diagonalAim = DIAG_AIM_NONE;
                if (gEquipment.suitType == SUIT_SUITLESS)
                    SoundPlay(0x9B);
                else
                    SoundPlay(0x7A);
            }
            else
                pData->armCannonDirection = pCopy->armCannonDirection;

            break;

        case SPOSE_SAVING_LOADING_GAME:
            pData->lastWallTouchedMidAir = pCopy->lastWallTouchedMidAir;
        
        case SPOSE_DOWNLOADING_MAP_DATA:
            pData->timer = 0x1;

        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_FACING_THE_FOREGROUND:
        case SPOSE_CROUCHING_TO_CRAWL:
            DiagNone:
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_CRAWLING_STOPPED:
            if (pCopy->pose == SPOSE_SHOOTING_WHILE_CRAWLING)
                pData->forcedMovement = FORCED_MOVEMENT_CROUCHING_ARM_CANNON_UP;
            break;

        case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
            pData->lastWallTouchedMidAir = 0x1;
            pData->armCannonDirection = pCopy->armCannonDirection;
            break;

        case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
            pData->turning = TRUE;
            break;
        
        case SPOSE_TURNING_AROUND_MIDAIR:
            pData->yVelocity = pCopy->yVelocity;

        case SPOSE_TURNING_AROUND:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
            pData->turning = TRUE;
            pData->armCannonDirection = pCopy->armCannonDirection;
            break;

        case SPOSE_IN_ESCAPE_SHIP:
            break;
        
        default:
            pData->armCannonDirection = pCopy->armCannonDirection;
    }
}

void SamusSetPose(u8 pose)
{
    struct WeaponInfo* pWeapon;
    struct SamusData* pData;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pCopy = &gSamusDataCopy;
    pWeapon = &gSamusWeaponInfo;

    if ((u8)(pose + 0x7) < 0x2)
        pData->turning = FALSE;

    SamusCopyData(pData);

    if (pCopy->armCannonDirection == ACD_NONE)
        pCopy->armCannonDirection = ACD_FORWARD;

    switch (pCopy->pose)
    {
        case SPOSE_DELAY_BEFORE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARKING)
                play_sound(0x8E);
            break;
        
        case SPOSE_SHINESPARKING:
            if (pose != SPOSE_SHINESPARK_COLLISION)
                play_sound(0x8E);
            break;
        
        case SPOSE_DELAY_BEFORE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARKING)
                SoundStop(0x8F);
            break;
        
        case SPOSE_BALLSPARKING:
            if (pose != SPOSE_BALLSPARK_COLLISION)
                SoundStop(0x8F);
            break;
    }

    switch (pose)
    {
        case SPOSE_UPDATE_JUMP_VELOCITY_REQUEST:
            SamusUpdateJumpVelocity(pData, pCopy, pWeapon);
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
            pData->pose = pose;
            SamusCheckCarryFromCopy(pData, pCopy, pWeapon);
    }
}

/**
 * 75bc | 60 | Copies samus data to the samus data copy and resets samus data 
 * 
 * @param pData_ Samus Data Pointer (unused)
 */
void SamusCopyData(struct SamusData* pData_)
{
    struct SamusData* pData;
    struct ScrewSpeedAnimation* pScrew;
    struct SamusData* pCopy;

    pData = &gSamusData;
    pScrew = &gScrewSpeedAnimation;
    pCopy = &gSamusDataCopy;

    *pCopy = *pData;
    if (pData->turning)
    {
        pData->direction ^= (KEY_LEFT | KEY_RIGHT);
        pData->turning = FALSE;
    }

    pData->armCannonDirection = ACD_FORWARD;
    pData->forcedMovement = 0x0;
    pData->speedboostingShinesparking = FALSE;
    pData->walljumpTimer = 0x0;
    pData->timer = 0x0;
    pData->lastWallTouchedMidAir = 0x0;
    pData->elevatorDirection = 0x0;
    pData->xVelocity = 0x0;
    pData->yVelocity = 0x0;
    pData->animationDurationCounter = 0x0;
    pData->currentAnimationFrame = 0x0;

    if (pData->shinesparkTimer != 0xB4)
        pScrew->flag = SCREW_SPEED_FLAG_NONE;

    pScrew->animationDurationCounter = 0x0;
    pScrew->currentAnimationFrame = 0x0;
}

/**
 * @brief 761c | 110 | Updates the physics of Samus
 * 
 * @param pData Samus Data Pointer (unused)
 */
void SamusUpdatePhysics(struct SamusData* pData)
{
    struct Equipment* pEquipment;
    struct SamusPhysics* pPhysics;
    u16 yPosition;
    u32 slowed;
    i32 affecting;
    
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
            yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
            break;

        default:
            yPosition = pData->yPosition;
    }

    slowed = FALSE;

    affecting = ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition);
    affecting &= 0xFF;

    switch (affecting)
    {
        case HAZARD_TYPE_WATER:
        case HAZARD_TYPE_STRONG_LAVA:
        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_ACID:
            if (!(pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT))
                slowed++;
            break;

        default:
        if (gEquipment.grabbedByMetroid)
            slowed++;
    }

    pPhysics->slowedByLiquid = slowed;

    if (slowed)
    {
        pPhysics->xAcceleration = SAMUS_X_ACCELERATION / 2;
        pPhysics->xVelocityCap = SAMUS_X_VELOCITY_CAP / 2;
        pPhysics->midairXVelocityCap = SAMUS_X_MID_AIR_VELOCITY_CAP / 2;
        pPhysics->midairXAcceleration = SAMUS_X_MID_AIR_ACCELERATION / 2;
        pPhysics->midairMorphedXVelocityCap = SAMUS_X_MID_AIR_MORPHED_VELOCITY_CAP / 2;

        pPhysics->yAcceleration = SAMUS_Y_ACCELERATION / 2;
        pPhysics->positiveYVelocityCap = SAMUS_Y_SLOWED_VELOCITY_CAP;
        pPhysics->negativeYVelocityCap = SAMUS_Y_SLOWED_VELOCITY_CAP;

        if (pData->speedboostingShinesparking)
            pData->speedboostingShinesparking = FALSE;
    }
    else
    {
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
        pData->currentSlope = SLOPE_NONE;
}

i16 SamusChangeVelocityOnSlope(struct SamusData* pData)
{
    i32 velocity, decreased_velocity;

    velocity = (i32)pData->xVelocity;
    if (pData->direction & pData->currentSlope)
    {
        if (pData->currentSlope & SLOPE_STEEP)
        {
            decreased_velocity = velocity * 3 / 5;
        }
        else
        {
            decreased_velocity = velocity * 4 / 5;
        }
        velocity = (i16)decreased_velocity;
    }
    else
    {
        if (velocity > 0xA0)
        {
            velocity = 0xA0;
        }
        else if (velocity < -0xA0)
        {
            velocity = -0xA0;
        }
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
void SamusCopyPalette(u16* src, i32 offset, i32 nbrColors)
{
    i32 i;

    for (i = offset; i < offset + nbrColors; i++)
        gSamusPalette[i] = *src++;
}

void SamusUpdate(void)
{
    u8 newPose;
    struct SamusData* pData;

    pData = &gSamusData;

    if (0x1 < gGameModeSub1)
        pData->animationDurationCounter++;
    
    SamusUpdatePhysics(pData);
    newPose = SamusExecutePoseSubroutine(pData);
    if (newPose != SPOSE_NONE)
        SamusSetPose(newPose);
    SamusUpdateDrawDistanceAndStandingStatus(pData, &gSamusPhysics);
    SamusUpdateVelocityPosition(pData);
}

void SamusUpdateHitboxMovingDirection(void)
{
    struct SamusData* pData;
    struct SamusPhysics* pPhysics;
    u8* pDirection;

    pData = &gSamusData;
    pPhysics = &gSamusPhysics;

    pPhysics->touchingSideBlock = FALSE;
    pPhysics->touchingTopBlock = FALSE;
    pPhysics->unknown = 0x0;
    pDirection = &pPhysics->horizontalMovingDirection;
    *pDirection = HDMOVING_NONE;
    pPhysics->verticalMovingDirection = VDMOVING_NONE;
    
    if (pData->xPosition > gPreviousXPosition)
        *pDirection = HDMOVING_RIGHT;
    else if (pData->xPosition < gPreviousXPosition)
        *pDirection = HDMOVING_LEFT;

    if (gUnk_03004fc9 == 0x0)
    {
        if (pData->yPosition > gPreviousYPosition)
            pPhysics->verticalMovingDirection = VDMOVING_DOWN;
        else if (pData->yPosition < gPreviousYPosition)
            pPhysics->verticalMovingDirection = VDMOVING_UP;
    }
    
    pPhysics->standingStatus = samus_visual_data[pData->pose][2];
    pPhysics->hitboxLeftOffset = samus_hitbox_data[pPhysics->hitboxType][0];
    pPhysics->hitboxRightOffset = samus_hitbox_data[pPhysics->hitboxType][1];
    pPhysics->hitboxTopOffset = samus_hitbox_data[pPhysics->hitboxType][2];
    if (pPhysics->standingStatus == STANDING_NOT_IN_CONTROL)
        pPhysics->verticalMovingDirection = VDMOVING_DOWN;

    SamusCheckCollisions(pData, pPhysics);
    SamusUpdateDrawDistanceAndStandingStatus(pData, pPhysics);
}

/**
 * 78e0 | 3c | Calls functions related to updating samus' graphics
 * 
 */
void SamusCallGFXFunctions(void)
{
    struct SamusData* pData;
    u8 direction;
    u16 flag;

    pData = &gSamusData;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
        SamusUpdateEnvironmentalEffect(pData);

    flag = pData->direction & KEY_RIGHT;
    direction = TRUE;
    if (flag)
        direction = FALSE;
    
    SamusUpdateGraphicsOAM(pData, direction);
    SamusUpdatePalette(pData);
}

void SamusCallCheckLowHealth(void)
{
    SamusCheckPlayLowHealthSound();
}

void SamusCallUpdateArmCannonPositionOffset(void)
{
    u8 flag;
    u8 direction;

    flag = gSamusData.direction & KEY_RIGHT;
    direction = TRUE;
    if (flag)
        direction = FALSE;
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

    if ((direction & (FORCED_MOVEMENT_BOMB_JUMP_ABOVE - 1)) > 0x9)
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
        gSamusData.forcedMovement = direction & (FORCED_MOVEMENT_BOMB_JUMP_ABOVE - 1);
        SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
    }
}

void SamusAimCannon(struct SamusData* pData)
{
    // https://decomp.me/scratch/25vTb

    struct WeaponInfo* pWeapon;

    pWeapon = &gSamusWeaponInfo;

    if (gButtonInput & gButtonAssignments.diagonalAim)
    {
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
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                    pWeapon->diagonalAim = DIAG_AIM_DOWN;
                }
                else if (pWeapon->diagonalAim > DIAG_AIM_UP && gButtonInput & KEY_UP)
                {
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                    pWeapon->diagonalAim = DIAG_AIM_UP;
                }
                break;

            case SPOSE_ON_ZIPLINE:
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                pWeapon->diagonalAim = DIAG_AIM_DOWN;
        }
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_RUNNING:
                if (gButtonInput & KEY_UP)
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                else if (gButtonInput & KEY_DOWN)
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                else if (pData->armCannonDirection < ACD_NONE)
                    pData->armCannonDirection = ACD_FORWARD;

                if (gEquipment.suitType == SUIT_SUITLESS)
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                else if (pData->armCannonDirection != ACD_NONE)
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                else if (pWeapon->weaponHighlighted == WH_NONE && pWeapon->chargeCounter == 0x0)
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                else
                {
                    pData->armCannonDirection = ACD_FORWARD;
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
                break;

            case SPOSE_STANDING:
            case SPOSE_SHOOTING:
            case SPOSE_LANDING:
            case SPOSE_UNCROUCHING_SUITLESS:
                if (pData->timer == 0x0 && gButtonInput & KEY_UP)
                {
                    pData->armCannonDirection = ACD_UP;
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
                else
                {
                    pData->armCannonDirection = ACD_FORWARD;
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
                break;

            case SPOSE_CROUCHING:
            case SPOSE_SHOOTING_AND_CROUCHING:
            case SPOSE_CROUCHING_SUITLESS:
                pData->armCannonDirection = ACD_FORWARD;
                pWeapon->diagonalAim = DIAG_AIM_NONE;
                break;

            case SPOSE_MIDAIR:
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
            case SPOSE_AIMING_WHILE_HANGING:
                if (gButtonInput & KEY_UP)
                {
                    if (gButtonInput & pData->direction)
                    {
                        pData->armCannonDirection = ACD_DIAGONALLY_UP;
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    }
                    else
                    {
                        pData->armCannonDirection = ACD_UP;
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    }
                }
                else if (gButtonInput & KEY_DOWN)
                {
                    if (gButtonInput & pData->direction)
                        pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                    else
                        pData->armCannonDirection = ACD_DOWN;

                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
                else
                {
                    if (gButtonInput & pData->direction)
                    {
                        pData->armCannonDirection = ACD_FORWARD;
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    }
                    else if (pData->armCannonDirection == ACD_UP || pData->armCannonDirection == ACD_DOWN)
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    else
                    {
                        pData->armCannonDirection = ACD_FORWARD;
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    }
                }
                break;

            case SPOSE_ON_ZIPLINE:
                if (gButtonInput & KEY_DOWN)
                {
                    if (gButtonInput & pData->direction)
                        pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                    else
                        pData->armCannonDirection = ACD_DOWN;

                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
                else
                {
                    if (!(gButtonInput & pData->direction) && pData->armCannonDirection == ACD_DOWN)
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    else
                    {
                        pData->armCannonDirection = ACD_FORWARD;
                        pWeapon->diagonalAim = DIAG_AIM_NONE;
                    }
                }
                break;

            default:
                pWeapon->diagonalAim = DIAG_AIM_NONE;
        }
    }
}

/**
 * @brief 7cf8 | bc | Checks if Samus is firing a beam/missile
 * 
 * @param pData Samus Data Pointer
 * @param pWeapon Samus Weapon Info Pointer
 * @param pEquipment Samus Equipment Pointer
 * @return u8 1 if fired, 0 otherwise
 */
u8 SamusCheckFireBeamMissile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    u8 hasProj;

    hasProj = FALSE;

    // Check fire
    if (pWeapon->cooldown == 0x0 && pWeapon->newProjectile == PROJECTILE_CATEGORY_NONE && gChangedInput & KEY_B)
    {
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
        // Update charge coutner
        if (pWeapon->weaponHighlighted == WH_NONE)
        {
            if (gButtonInput & KEY_B)
            {
                if (pEquipment->beamBombsActivation & BBF_CHARGE_BEAM)
                {
                    if (pWeapon->chargeCounter < 0x4F)
                        pWeapon->chargeCounter++;
                    else
                        pWeapon->chargeCounter = 0x40;
                }
                else
                    pWeapon->chargeCounter = 0x0;
            }
            else
            {
                if (pWeapon->chargeCounter > 0x3F)
                {
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;
                    hasProj++;
                }
                else if (pWeapon->chargeCounter > 0x19)
                {
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_BEAM;
                    hasProj++;
                }
                
                pWeapon->chargeCounter = 0x0;
            }
        }
        else
            pWeapon->chargeCounter = 0x0;
    }

    if (hasProj)
    {
        if (pData->armCannonDirection == ACD_NONE)
            pData->armCannonDirection = ACD_FORWARD;
    }

    return hasProj;
}

u8 SamusCheckFirePistol(struct SamusData* pData, struct WeaponInfo* pWeapon)
{
    u8 hasProj;

    hasProj = FALSE;

    if (pWeapon->chargeCounter < 0x7F)
        pWeapon->chargeCounter++;
    else
        pWeapon->chargeCounter = 0x70;

    if (pWeapon->cooldown == 0x0 && pWeapon->newProjectile == PROJECTILE_CATEGORY_NONE && gChangedInput & KEY_B)
    {
        if (pWeapon->chargeCounter >= 0x70)
        {
            pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;
            pWeapon->chargeCounter = 0x0;
            hasProj++;
        }
        else
            pWeapon->newProjectile = PROJECTILE_CATEGORY_BEAM;

        pWeapon->chargeCounter = 0x0;
        hasProj++;
    }

    if (hasProj != PROJECTILE_CATEGORY_NONE && pData->armCannonDirection == ACD_NONE)
        pData->armCannonDirection = ACD_FORWARD;

    return hasProj;
}

void SamusCheckNewProjectile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    pPhysics->hasNewProjectile = 0x0;

    if (pEquipment->suitType == SUIT_SUITLESS)
    {
        switch (pData->pose)
        {
            case SPOSE_FACING_THE_FOREGROUND:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_FACING_THE_BACKGROUND_SUITLESS:
                pWeapon->chargeCounter = 0x0;
                break;

            default:
                pPhysics->hasNewProjectile = SamusCheckFirePistol(pData, pWeapon);
                break;

            case SPOSE_GETTING_HURT:
            case SPOSE_GETTING_KNOCKED_BACK:
                pWeapon->chargeCounter = 0x0;
                break;
        }
    }
    else
    {
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
            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
                pPhysics->hasNewProjectile = SamusCheckFireBeamMissile(pData, pWeapon, pEquipment);
                break;

            case SPOSE_MORPH_BALL:
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL_MIDAIR:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                if (gChangedInput & KEY_B && pWeapon->cooldown == 0x0 && pEquipment->beamBombsActivation & BBF_BOMBS)
                {
                    if (pWeapon->weaponHighlighted & WH_POWER_BOMB)
                        pWeapon->newProjectile = PROJECTILE_CATEGORY_POWER_BOMB;
                    else
                        pWeapon->newProjectile = PROJECTILE_CATEGORY_BOMB;
                }
            case SPOSE_MORPHING:
                if (pWeapon->chargeCounter > 0x40)
                    pWeapon->newProjectile = PROJECTILE_CATEGORY_CHARGED_BEAM;
                pWeapon->chargeCounter = 0x0;
                break;
            
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_SAVING_LOADING_GAME:
            case SPOSE_DOWNLOADING_MAP_DATA:
            case SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA:
            case SPOSE_DYING:
            case SPOSE_IN_ESCAPE_SHIP:
            case SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP:
                pWeapon->chargeCounter = 0x0;
        }
    }
}

u8 SamusCheckAButtonPressed(struct SamusData* pData)
{
    u8 return_value;
    
    return_value = FALSE;
    if (gChangedInput & KEY_A)
    {
        pData->forcedMovement = 0x1;
        return_value = TRUE;
    }
    return return_value;
}

/**
 * @brief 8080 | 140 | Sets the current highlighted weapon
 * 
 * @param pData Samus Data Pointer
 * @param pWeapon Samus Weapon Info Pointer
 * @param pEquipment Samus Equipment Pointer
 */
void SamusSetHighlightedWeapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    u8 weaponHigh;
    
    weaponHigh = WH_NONE;

    if (pEquipment->currentSuperMissiles == 0)
        pWeapon->missilesSelected = FALSE;
    else if (pEquipment->currentMissiles == 0)
        pWeapon->missilesSelected = TRUE;
    else if (gChangedInput & KEY_SELECT)
    {
        pWeapon->missilesSelected ^= TRUE;
        SoundPlay(0x85); // Selecting missiles
    }

    switch (pData->pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            if (gButtonInput & gButtonAssignments.armMissiles && pEquipment->currentPowerBombs != 0)
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
            break;

        default:
            if (gButtonInput & gButtonAssignments.armMissiles)
            {
                if (!pWeapon->missilesSelected)
                {
                    if (pEquipment->currentMissiles != 0)
                        weaponHigh = WH_MISSILE;
                }
                else
                    weaponHigh = WH_SUPER_MISSILE;
            }
            break;
    }

    if (weaponHigh != WH_NONE && pWeapon->weaponHighlighted == WH_NONE)
    {
        pWeapon->chargeCounter = 0;
        SoundPlay(0x84); // Arming missiles
    }
    pWeapon->weaponHighlighted = weaponHigh;
}

void SamusSetSpinningPose(struct SamusData* pData, struct Equipment* pEquipment)
{
    u8 flag;

    switch (pData->pose)
    {
        case SPOSE_SPINNING:
            if (gSamusPhysics.slowedByLiquid)
                break;

            if (!(pEquipment->suitMiscActivation & SMF_SCREW_ATTACK))
            {
                if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
                    pData->pose = SPOSE_SPACE_JUMPING;
                break;
            }
            pData->pose = SPOSE_SCREW_ATTACKING;
            break;

        case SPOSE_SPACE_JUMPING:
            if (pEquipment->suitMiscActivation & SMF_SCREW_ATTACK)
                pData->pose = SPOSE_SCREW_ATTACKING;
            else
            {
                if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP && !gSamusPhysics.slowedByLiquid)
                    break;
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = 0x0;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (gSamusPhysics.slowedByLiquid)
            {
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = 0x0;
            }
            else
            {
                if (!(pEquipment->suitMiscActivation & SMF_SCREW_ATTACK))
                {
                    if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
                        pData->pose = SPOSE_SPACE_JUMPING;
                    else
                        pData->pose = SPOSE_SPINNING;
                    pData->currentAnimationFrame = 0x0;
                }
            }
            gScrewSpeedAnimation.flag = FALSE;
    }
}

void SamusApplyXAcceleration(i32 acceleration, i32 velocity, struct SamusData* pData)
{
    // https://decomp.me/scratch/FkAya

    i32 xVelocity;
    i32 xAcceleration;
    i32 temp;

    xAcceleration = (i16)acceleration;
    xVelocity = (i16)velocity;

    if (pData->direction & KEY_RIGHT)
    {
        temp = (u16)pData->xVelocity + xAcceleration;
        pData->xVelocity = temp;
        if ((i16)temp > xVelocity)
            pData->xVelocity = xVelocity;
    }
    else
    {
        pData->xVelocity -= xAcceleration;
        if (pData->xVelocity < -xVelocity)
            pData->xVelocity = -xVelocity;
    }
}

/**
 * @brief 82b8 | 168 | Handles Samus taking hazard damage
 * 
 * @param pData Samus Data Pointer
 * @param pEquipment Samus Equipment Pointer
 * @param pHazard Hazard Damage Pointer
 * @return u8 1 if getting knocked back, 0 otherwise
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
            return FALSE;

        case SPOSE_HANGING_ON_LEDGE:
        case SPOSE_TURNING_TO_AIM_WHILE_HANGING:
        case SPOSE_HIDING_ARM_CANNON_WHILE_HANGING:
        case SPOSE_AIMING_WHILE_HANGING:
        case SPOSE_SHOOTING_WHILE_HANGING:
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
            yPosition = pData->yPosition - QUARTER_BLOCK_SIZE;
            break;

        default:
            yPosition = pData->yPosition;
    }

    pHazard->damageTimer++;
    damaged = FALSE;
    knockback = FALSE;
    damageType = 0;

    hazard = ClipdataCheckCurrentAffectingAtPosition(yPosition, pData->xPosition) & 0xFF;

    if (pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT)
    {
        if (hazard == HAZARD_TYPE_ACID)
        {
            damaged = TRUE;
            if (pHazard->damageTimer > 0x3)
                damageType = 0x1;
        }
    }
    else
    {
        if (pEquipment->suitMiscActivation & SMF_VARIA_SUIT)
        {
            if (hazard == HAZARD_TYPE_ACID)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x1)
                    damageType = 0x1;
            }
            else if (hazard == HAZARD_TYPE_STRONG_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x4)
                    damageType = 0x1;
            }
        }
        else
        {
            if (hazard == HAZARD_TYPE_ACID)
            {
                damaged = TRUE;
                damageType = 0x1;
            }
            else if (hazard == HAZARD_TYPE_COLD_KNOCKBACK)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x3)
                    damageType = 0xF;

                if (pHazard->knockbackTimer++ > 0x57)
                {
                    pHazard->knockbackTimer = 0x0;
                    knockback = TRUE;
                }
            }
            else if (hazard == HAZARD_TYPE_STRONG_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x2)
                    damageType = 0x1;
            }
            else if (hazard == HAZARD_TYPE_WEAK_LAVA)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x7)
                    damageType = 0x1;
            }
            else if (hazard == HAZARD_TYPE_HEAT)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x5)
                    damageType = 0xF;
            }
            else if (hazard == HAZARD_TYPE_COLD)
            {
                damaged = TRUE;
                if (pHazard->damageTimer > 0x5)
                    damageType = 0xF;
            }
        }
    }

    if (!damaged)
    {
        pHazard->damageTimer = 0x0;
        pHazard->knockbackTimer = 0x0;
        pHazard->paletteTimer = 0x0;
    }
    else
    {
        switch (pHazard->paletteTimer++)
        {
            case 0x1:
            case 0x21:
                if (hazard == HAZARD_TYPE_ACID || hazard == HAZARD_TYPE_STRONG_LAVA || hazard == HAZARD_TYPE_WEAK_LAVA)
                    SoundPlay(0x7E);
                break;
    
            case 0x40:
                pHazard->paletteTimer = 0x0;
        }
    
        if (damageType != 0x0)
        {
            pEquipment->currentEnergy--;
            pHazard->damageTimer = 0x0;
        }
    
        if (damageType == 0xF)
            SoundPlay(0x7F);
    }

    if (pEquipment->currentEnergy == 0x0 || knockback)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 8420 | 4c | Checks if Samus is shinesparking
 * 
 * @param pData 
 */
void SamusCheckShinesparking(struct SamusData* pData)
{
    u16 xVelocity;
    u8 pose = pData->pose;

    if (pose != SPOSE_DYING)
    {
        switch (pose)
        {
            case SPOSE_SHINESPARKING:
            case SPOSE_BALLSPARKING:
                pData->speedboostingShinesparking = TRUE;
                break;
            
            default:
                xVelocity = pData->xVelocity + 0x9F;
                if (xVelocity > 0x13E)
                {
                    if (!pData->speedboostingShinesparking && pose != SPOSE_SKIDDING)
                    {
                        pData->speedboostingShinesparking++;
                        SoundPlay(0x8B); // Speedbooster start
                    }
                }
                else if (pData->speedboostingShinesparking)
                    pData->speedboostingShinesparking = FALSE;
                break;
        }
    }
    else
        pData->speedboostingShinesparking = FALSE;

    if (!pData->speedboostingShinesparking)
        SoundStop(0x8B); // Speedbooster start
}

u8 SamusInactivity(struct SamusData* pData)
{
    return SPOSE_NONE;
}

u8 SamusUpdateAnimation(struct SamusData* pData, u8 slowed)
{

}

u8 SamusRunning(struct SamusData* pData)
{
    // https://decomp.me/scratch/g7GvE

    i32 xVelocity;
    u16 currVelocity;

    if (gChangedInput & KEY_A)
    {
        pData->forcedMovement = FORCED_MOVEMENT_STARTING_SPIN_RUNNING;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    xVelocity = gSamusPhysics.xVelocityCap;
    if (gEquipment.suitMiscActivation & SMF_SPEEDBOOSTER && !gSamusPhysics.slowedByLiquid)
    {
        if (pData->timer > 0x8B)
            xVelocity = 0xA0;
        else if (pData->timer > 0x77)
            xVelocity = 0x8C;
        
        currVelocity = pData->xVelocity + 0x5F;
        if (currVelocity > 0xBE)
        {
            if (pData->timer < 0xA0)
                pData->timer++;
        }
        else
            pData->timer = 0x0;
    }
    else
        pData->timer = 0x0;

    if (gButtonInput & pData->direction)
    {
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, xVelocity, pData);
        SamusAimCannon(pData);
        return SPOSE_NONE;
    }
    else
    {
        if (pData->speedboostingShinesparking)
            return SPOSE_SKIDDING;
        else if (gSamusPhysics.hasNewProjectile)
            return SPOSE_SHOOTING;
        else if (!check_samus_turning())
            return SPOSE_STANDING;
        else
            return SPOSE_TURNING_AROUND;
    }
}

u8 SamusRunningGFX(struct SamusData* pData)
{

}

/**
 * @brief 86d4 | 148 | Samus standing subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusStanding(struct SamusData* pData)
{
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A &&
        pData->shinesparkTimer && !SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2] - HALF_BLOCK_SIZE))
    {
        pData->yPosition -= HALF_BLOCK_SIZE;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }

    if (SamusCheckAButtonPressed(pData))
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

    if (gButtonInput & pData->direction)
        return SPOSE_RUNNING;

    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING;

    if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
        return SPOSE_TURNING_AROUND;

    if (gChangedInput & KEY_DOWN)
    {
        if (ClipdataCheckCurrentAffectingAtPosition(pData->yPosition + 0x4, pData->xPosition) >> 0x10 == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK)
        {
            pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
            pData->elevatorDirection = KEY_DOWN;
            return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
        }

        if (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN)
        {
            if (gEquipment.suitType != SUIT_SUITLESS)
                SoundPlay(0x79);
            
            if (gSamusPhysics.hasNewProjectile)
                return SPOSE_SHOOTING_AND_CROUCHING;
            
            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_CROUCHING_SUITLESS;

            return SPOSE_CROUCHING;
        }
    }
    else
    {
        if (gChangedInput & KEY_UP)
        {
            if (ClipdataCheckCurrentAffectingAtPosition(pData->yPosition + 0x4, pData->xPosition) >> 0x10 == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
            {
                pData->xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
                pData->elevatorDirection = KEY_UP;
                return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
            }
        }
    }

    if (pData->timer != 0x0)
        pData->timer--;

    SamusAimCannon(pData);
    return SPOSE_NONE;
}

u8 SamusStandingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningAround(struct SamusData* pData)
{
    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0x0 && !SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2] - HALF_BLOCK_SIZE))
    {
        pData->yPosition -= HALF_BLOCK_SIZE;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        if (SamusCheckAButtonPressed(pData))
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        else
        {
            if (gChangedInput & KEY_DOWN && (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
            {
                pData->pose = SPOSE_TURNING_AROUND_AND_CROUCHING;
                if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(0x79);
            }
            if (gSamusPhysics.hasNewProjectile)
            {
                if (pData->pose == SPOSE_TURNING_AROUND_AND_CROUCHING)
                    return SPOSE_SHOOTING_AND_CROUCHING;
                else
                    return SPOSE_SHOOTING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

u8 SamusTurningAroundGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
            return SPOSE_RUNNING;
        else if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

u8 SamusShootingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STANDING;
    else
        return SPOSE_NONE;
}

/**
 * @brief 895c | 1b8 | Samus crouching subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusCrouching(struct SamusData* pData)
{
    u16 xPosition;
    u8 collision;

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A &&
        pData->shinesparkTimer != 0x0 && !SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2] - HALF_BLOCK_SIZE))
    {
        pData->yPosition -= HALF_BLOCK_SIZE;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    
    collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
    if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - samus_hitbox_data[0][0];
    else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - samus_hitbox_data[0][0] + SUB_PIXEL_POSITION_FLAG;

    if (SamusCheckAButtonPressed(pData) && !(collision & (SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT)))
    {
        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
            pData->xPosition = xPosition;

        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (gChangedInput & KEY_UP && !(collision & (SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT)))
    {
        if  (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_UP)
        {
            if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
                pData->xPosition = xPosition;

            pData->lastWallTouchedMidAir = 0x6;
            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_UNCROUCHING_SUITLESS;
            else
                return SPOSE_STANDING;
        }
    }

    if (gChangedInput & KEY_DOWN && gEquipment.suitMiscActivation & SMF_MORPH_BALL &&
        (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
    {
        SoundPlay(0x77);
        return SPOSE_MORPHING;
    }

    SamusAimCannon(pData);
    if (pData->armCannonDirection == ACD_UP)
        pData->armCannonDirection = ACD_FORWARD;

    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_AND_CROUCHING;

    if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
        return SPOSE_TURNING_AROUND_AND_CROUCHING;

    if (gButtonInput & pData->direction)
    {
        if (!(collision & (SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT)) &&
            pData->timer++ > 0x5)
        {
            if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST || collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
                pData->xPosition = xPosition;

            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_UNCROUCHING_SUITLESS;
            else
                return SPOSE_STANDING;
        }
    }
    else
        pData->timer = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningAroundAndCrouching(struct SamusData* pData)
{
    u8 unk;
    u16 xPosition;

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gChangedInput & KEY_A && pData->shinesparkTimer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)samus_hitbox_data[0][2] - 0x20))  == 0x0)
    {
        pData->yPosition -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        unk = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
        if (unk == 0x1)
            xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - (u16)samus_hitbox_data[0][0];
        else if (unk == 0x8)
            xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - (u16)samus_hitbox_data[0][0] + 0x3F;

        if (SamusCheckAButtonPressed(pData)  && (unk & 0x6) == 0x0)
        {
            if (unk == 0x1 || unk == 0x8)
                pData->xPosition = xPosition;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            if (gChangedInput & KEY_UP && (unk & 0x6) == 0x0 && (gSamusWeaponInfo.diagonalAim == 0x0 || pData->armCannonDirection == ACD_DIAGONALLY_UP))
            {
                if (unk == 0x1 || unk == 0x8)
                    pData->xPosition = xPosition;
                pData->pose = SPOSE_TURNING_AROUND;

            }

            if (gSamusPhysics.hasNewProjectile)
            {
                if (pData->pose == SPOSE_TURNING_AROUND)
                    return SPOSE_SHOOTING;
                else
                    return SPOSE_SHOOTING_AND_CROUCHING;
            }
            else
                return SPOSE_NONE;
        }
    }
}

u8 SamusTurningAroundAndCrouchingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_CROUCHING_SUITLESS;
        else
            return SPOSE_CROUCHING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusShootingAndCrouchingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_CROUCHING;
    else
        return SPOSE_NONE;
}

u8 SamusSkidding(struct SamusData* pData)
{
    i32 velocity;

    if (gChangedInput & KEY_A)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    
    if (gButtonInput & pData->direction)
        return SPOSE_RUNNING;
    else
    {
        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN)) == KEY_DOWN)
        {
            pData->shinesparkTimer = 0xB4;
            gScrewSpeedAnimation.flag = 0x8;
            if (gEquipment.suitType == SUIT_SUITLESS)
                return SPOSE_CROUCHING_SUITLESS;
            else
                return SPOSE_CROUCHING;
        }

        if (pData->direction & KEY_RIGHT)
        {
            velocity = (u16)pData->xVelocity - 0xA;
            pData->xVelocity = velocity;
            if (0x0 >= (velocity << 0x10))
                return SPOSE_STANDING;
        }
        else
        {
            velocity = (u16)pData->xVelocity + 0xA;
            pData->xVelocity = velocity;
            if ((velocity << 0x10) >= 0x0)
                return SPOSE_STANDING;
        }
        
        return SPOSE_NONE;
    }
}

u8 SamusMidAir(struct SamusData* pData)
{
    // https://decomp.me/scratch/ZUxPm

    u8 turning;
    i32 xAcceleration;

    if (gChangedInput & KEY_DOWN && pData->armCannonDirection == ACD_DOWN && gEquipment.suitMiscActivation & SMF_MORPH_BALL)
    {
        SoundPlay(0x77);
        return SPOSE_MORPH_BALL_MIDAIR;
    }

    if (gChangedInput & KEY_A)
    {
        if (pData->shinesparkTimer != 0x0)
            return  SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            pData->pose = SPOSE_SPINNING;
            pData->currentAnimationFrame = 0x0;
            pData->animationDurationCounter = 0x0;
            return SPOSE_NONE;
        }
    }

    turning = FALSE;
    xAcceleration = gSamusPhysics.midairXAcceleration;
    if (gButtonInput & pData->direction)
        SamusApplyXAcceleration(xAcceleration, gSamusPhysics.midairXVelocityCap, pData);
    else
    {
        if (check_samus_turning())
            turning++;
        else
        {
            if (pData->xVelocity > 0x0)
            {
                pData->xVelocity -= xAcceleration;
                if (pData->xVelocity < 0x0)
                    pData->xVelocity = 0x0;
            }
            else if (pData->xVelocity < 0x0)
            {
                pData->xVelocity += xAcceleration;
                if (pData->xVelocity > 0x0)
                    pData->xVelocity = 0x0;
            }
        }
    }

    SamusAimCannon(pData);

    if (turning)
        return SPOSE_TURNING_AROUND_MIDAIR;

    if (!(gButtonInput & KEY_A) && pData->yVelocity > 0x0)
        pData->yVelocity = 0x0;

    return SPOSE_NONE;
}

u8 SamusMidAirGFX(struct SamusData* pData)
{
    if (pData->yVelocity >= 0x0)
    {
        if (pData->currentAnimationFrame == 0x2)
            pData->animationDurationCounter = 0x0;
    }
    else
    {
        if (pData->currentAnimationFrame < 0x2)
            pData->currentAnimationFrame = 0x2;
    }

    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x4;

    return SPOSE_NONE;
}

u8 SamusTurningAroundMidAir(struct SamusData* pData)
{
    if (gChangedInput & KEY_A)
    {
        if (pData->shinesparkTimer != 0x0)
            return SPOSE_DELAY_BEFORE_SHINESPARKING;

        if (!(gButtonInput & (KEY_UP | KEY_DOWN)))
        {
            pData->pose = SPOSE_SPINNING;
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            pData->currentAnimationFrame = 0x0;
            pData->animationDurationCounter = 0x0;
            pData->turning = FALSE;
            return SPOSE_NONE;
        }
    }

    if (gSamusPhysics.hasNewProjectile != 0x0)
    {
        pData->forcedMovement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (!(gButtonInput & KEY_A) && 0x0 < pData->yVelocity)
            pData->yVelocity = 0x0;
        return SPOSE_NONE;
    }
}

u8 SamusTurningAroundMidAirGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->forcedMovement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusStartingSpinJumpGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->pose = SPOSE_SPINNING;
        pData->currentAnimationFrame = 0x0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 8efc | 144 | Samus spinning subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusSpinning(struct SamusData* pData)
{
    i32 xAcceleration;
    i32 xOffset;

    if (gSamusPhysics.hasNewProjectile)
    {
        pData->forcedMovement = FORCED_MOVEMENT_SHOOTING_WHILE_SPINNING;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (!(gButtonInput & (KEY_RIGHT | KEY_LEFT)) && gButtonInput & (KEY_UP | KEY_DOWN))
    {
        pData->forcedMovement = FORCED_MOVEMENT_SPIN_BREAK;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    SamusAimCannon(pData);

    xAcceleration = gSamusPhysics.midairXAcceleration;

    if (gEquipment.suitMiscActivation & SMF_SPACE_JUMP && !gSamusPhysics.slowedByLiquid)
    {
        if (gChangedInput & KEY_A && pData->yVelocity <= -0x40)
        {
            if (gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
                pData->yVelocity = 0xE8;
            else
                pData->yVelocity = 0xC0;

            return SPOSE_NONE;
        }
    }
    else
    {
        if (pData->walljumpTimer != 0x0)
        {
            pData->walljumpTimer--;
            if (pData->direction & pData->lastWallTouchedMidAir)
            {
                if (gChangedInput & KEY_A)
                {
                    if (pData->lastWallTouchedMidAir & KEY_RIGHT)
                        xOffset = -0x28;
                    else
                        xOffset = 0x28;

                    // u16 cast
                    if (ClipdataProcessForSamus(pData->yPosition, pData->xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG)
                    {
                        pData->direction = pData->lastWallTouchedMidAir;
                        return SPOSE_STARTING_WALL_JUMP;
                    }
                }

                xAcceleration = 0x1;
            }
        }
    }

    if (gButtonInput & ((pData->direction ^ (KEY_RIGHT | KEY_LEFT))))
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT);
        pData->xVelocity = 0x0;
    }
    else
        SamusApplyXAcceleration(xAcceleration, gSamusPhysics.midairXVelocityCap, pData);

    if (!(gButtonInput & KEY_A) && pData->yVelocity > 0x0)
        pData->yVelocity = 0x0;

    return SPOSE_NONE;
}

u8 SamusSpinningGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    if (*(u16*)&pData->animationDurationCounter == 0x1)
    {
        if (gSamusPhysics.slowedByLiquid)
            SoundPlay(0x92);
        else if (gEquipment.suitType != SUIT_SUITLESS)
            SoundPlay(0x6A);
        else
            SoundPlay(0x98);
    }

    return SPOSE_NONE;
}

u8 SamusStartingWallJump(struct SamusData* pData)
{
    if (gSamusPhysics.hasNewProjectile)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else 
    {
        if (gButtonInput & (KEY_RIGHT | KEY_LEFT) == 0x0 && gButtonInput & (KEY_UP | KEY_DOWN))
        {
            pData->forcedMovement = 0x0;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
            return SPOSE_NONE;
    }
}

u8 SamusStartingWallJumpGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == 0x2)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusSpaceJumpingGFX(struct SamusData* pData)
{
    if (pData->animationDurationCounter == 0x1 && pData->currentAnimationFrame == 0x0)
    {
        if (gSamusPhysics.slowedByLiquid)
            SoundPlay(0x6B);
        else
            SoundPlay(0x6B);
    }

    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

u8 SamusScrewAttackingGFX(struct SamusData* pData)
{

}

u8 SamusMorphing(struct SamusData* pData)
{
    if (gChangedInput & KEY_UP)
        pData->pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

u8 SamusMorphingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
        return SPOSE_MORPH_BALL;
    else
        return SPOSE_NONE;
}

/**
 * @brief 924c | 170 | Samus morphball subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusMorphball(struct SamusData* pData)
{
    u8 collision;
    u16 xPosition;

    if (pData->forcedMovement > 0x15)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (pData->forcedMovement > 0x13)
    {
        pData->forcedMovement++;
        return SPOSE_NONE;
    }

    if (gChangedInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP &&
        pData->shinesparkTimer != 0x0 && !SamusCheckCollisionAbove(pData, samus_hitbox_data[1][4] - BLOCK_SIZE))
    {
        pData->yPosition -= HALF_BLOCK_SIZE;
        return SPOSE_DELAY_BEFORE_BALLSPARKING;
    }

    if (SamusCheckAButtonPressed(pData))
    {
        if (pData->forcedMovement != 0x1)
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

        if (gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

        pData->forcedMovement = 0x0;
    }

    if (gButtonInput & (KEY_RIGHT | KEY_LEFT))
    {
        pData->direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        return SPOSE_ROLLING;
    }

    if (gChangedInput & KEY_UP)
    {
        collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);

        if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
        {
            xPosition = pData->xPosition;
            xPosition += samus_hitbox_data[0][0];
            pData->xPosition = (xPosition & BLOCK_POSITION_FLAG) - samus_hitbox_data[0][0] + BLOCK_SIZE;
            gPreviousXPosition = pData->xPosition;

            collision = FALSE;
        }
        else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
        {
            xPosition = pData->xPosition;
            xPosition += samus_hitbox_data[0][1];

            pData->xPosition = (xPosition & BLOCK_POSITION_FLAG) - samus_hitbox_data[0][1] - 1;
            gPreviousXPosition = pData->xPosition;

            collision = FALSE;
        }

        if (!collision)
        {
            if (gSamusPhysics.slowedByLiquid)
                SoundPlay(0x78);
            else
                SoundPlay(0x78);

            return SPOSE_UNMORPHING;
        }
    }

    if (pData->timer != 0x0)
    {
        pData->timer--;
        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN)) == KEY_DOWN)
        {
            pData->shinesparkTimer = 0xB4;
            pData->timer = 0x0;
            gScrewSpeedAnimation.flag = SCREW_SPEED_FLAG_STORING_SHINESPARK;
        }
    }

    return SPOSE_NONE;
}

/**
 * @brief 93bc | cc | Samus rolling subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusRolling(struct SamusData* pData)
{
    i32 xVelocity;

    if (gChangedInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
    {
        pData->forcedMovement = FORCED_MOVEMENT_JUMPING_AFTER_ROLLING;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (!SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) && gChangedInput & KEY_UP)
    {
        if (gSamusPhysics.slowedByLiquid)
            SoundPlay(0x78);
        else
            SoundPlay(0x78);

        return SPOSE_UNMORPHING;
    }

    if (gButtonInput & pData->direction)
    {
        xVelocity = gSamusPhysics.xVelocityCap;
        if (pData->speedboostingShinesparking)
        {
            xVelocity = 0xA0;
            pData->shinesparkTimer = 0x6;
        }

        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, xVelocity, pData);
        return SPOSE_NONE;
    }

    if (check_samus_turning())
        pData->turning = TRUE;

    return SPOSE_MORPH_BALL;
}

u8 SamusRollingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;
    else if (animState == SAMUS_ANIM_STATE_SUB_ENDED && (pData->currentAnimationFrame == 0x1 || pData->currentAnimationFrame == 0x5))
        SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    return SPOSE_NONE;
}

u8 SamusUnmorphing(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) == 0x0)
    {
        if (gChangedInput & KEY_A)
        {
            pData->forcedMovement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        if (!(gChangedInput & KEY_DOWN))
            return SPOSE_NONE;
    }

    pData->pose = SPOSE_MORPHING;
    return SPOSE_NONE;
}

u8 SamusUnmorphingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
    {
        pData->unmorphPaletteTimer = 0xF;
        return SPOSE_CROUCHING;
    }
    return SPOSE_NONE;
}

/**
 * @brief 952c | d8 | Samus morphball midair subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusMorphballMidAir(struct SamusData* pData)
{
    if (gChangedInput & KEY_UP && !SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]))
    {
        if (gSamusPhysics.slowedByLiquid == TRUE)
            SoundPlay(0x78);
        else
            SoundPlay(0x78);

        pData->unmorphPaletteTimer= 0xF;
        return SPOSE_MIDAIR;
    }

    if (pData->forcedMovement == 0x0)
    {
        if (!(gButtonInput & KEY_A) && pData->yVelocity > 0x0)
            pData->yVelocity = 0x0;
    }
    else if (pData->yVelocity < 0x7)
        pData->forcedMovement = 0x0;

    if ((pData->yVelocity >= 0x0 && pData->xVelocity != 0x0) || gButtonInput & pData->direction)
    {
        SamusApplyXAcceleration(gSamusPhysics.midairXAcceleration, gSamusPhysics.midairMorphedXVelocityCap, pData);
    }
    else
    {
        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);

        pData->xVelocity = 0x0;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9604 | 16c | Samus hanging on ledge subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusHangingOnLedge(struct SamusData* pData)
{
    u16 xPosition;
    u32 sideBlock;
    u32 currentBlock;

    if (gScreenShakeX.timer > 0x1D)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (pData->direction & KEY_RIGHT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition);
    sideBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    currentBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition);
    currentBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & pData->direction)
        {
            if (!sideBlock && !currentBlock)
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
        }

        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
        {
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            pData->forcedMovement = 0x1;
        }
        else if (gButtonInput & KEY_DOWN)
        {
            pData->forcedMovement = 0x0;
        }
        else
        {
            pData->forcedMovement = 0x2;
            pData->yVelocity = 0x90;
        }
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (gSamusPhysics.hasNewProjectile)
        {
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            if (gButtonInput & KEY_DOWN)
                pData->armCannonDirection = ACD_DOWN;
            else
                pData->armCannonDirection = ACD_UP;

            return SPOSE_SHOOTING_WHILE_HANGING;
        }

        if (gEquipment.suitType != SUIT_SUITLESS && gSamusWeaponInfo.chargeCounter != 0x0)
        {
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            if (gButtonInput & KEY_DOWN)
                pData->armCannonDirection = ACD_DOWN;
            else
                pData->armCannonDirection = ACD_UP;

            return SPOSE_AIMING_WHILE_HANGING;
        }

        if (gButtonInput & gButtonAssignments.diagonalAim || gButtonInput & (KEY_UP | KEY_DOWN) || gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
        {
            pData->direction ^= (KEY_RIGHT | KEY_LEFT);
            return SPOSE_TURNING_TO_AIM_WHILE_HANGING;
        }
    }

    return SPOSE_NONE;
}

u8 SamusHangingOnLedgeGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

/**
 * @brief 9798 | c8 | Samus turning to aim while hanging subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusTurningToAimWhileHanging(struct SamusData* pData)
{
    u16 xPosition;
    u32 sideBlock;
    u32 currentBlock;

    if (gScreenShakeX.timer > 0x1D)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (pData->direction & KEY_LEFT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition);
    sideBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    currentBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition);
    currentBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
        {
            if (!sideBlock && !currentBlock)
            {
                pData->direction ^= (KEY_RIGHT | KEY_LEFT);
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                pData->direction ^= (KEY_RIGHT | KEY_LEFT);
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }
        }

        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_HANGING;

    return SPOSE_NONE;
}

u8 SamusTurningToAimWhileHangingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_AIMING_WHILE_HANGING;
    else
        return SPOSE_NONE;
}

u8 SamusHidingArmCannonWhileHangingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT);
        return SPOSE_HANGING_ON_LEDGE;
    }
    else
        return SPOSE_NONE;
}

/**
 * @brief 98b4 | 18c | Samus aiming while hanging subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusAimingWhileHanging(struct SamusData* pData)
{
    u16 xPosition;
    u32 sideBlock;
    u32 currentBlock;
    u32 aimingUp;

    if (gScreenShakeX.timer > 0x1D)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    SamusAimCannon(pData);
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_HANGING;

    if (pData->direction & KEY_LEFT)
        xPosition = pData->xPosition + HALF_BLOCK_SIZE;
    else
        xPosition = pData->xPosition - HALF_BLOCK_SIZE;

    sideBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), xPosition);
    sideBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    currentBlock = ClipdataProcessForSamus(pData->yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE), pData->xPosition);
    currentBlock &= CLIPDATA_TYPE_SOLID_FLAG;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & (pData->direction ^ (KEY_LEFT | KEY_RIGHT)))
        {
            if (!sideBlock && !currentBlock)
            {
                pData->direction ^= (KEY_LEFT | KEY_RIGHT);
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            }

            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                pData->direction ^= (KEY_LEFT | KEY_RIGHT);
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
            }
        }

        if (gButtonInput & pData->direction)
            pData->forcedMovement = 1;
        else
            pData->forcedMovement = 0;

        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        aimingUp = FALSE;
        if (!(gButtonInput & gButtonAssignments.diagonalAim))
        {
            if (gChangedInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
            {
                if (gEquipment.suitType == SUIT_SUITLESS || gSamusWeaponInfo.chargeCounter == 0x0)
                    return SPOSE_HIDING_ARM_CANNON_WHILE_HANGING;

                pData->armCannonDirection = ACD_UP;
            }

            if (gButtonInput & KEY_UP && !(gButtonInput & pData->direction))
                aimingUp++;
        }

        if (aimingUp)
        {
            if (pData->timer++ > 0x9)
            {
                if (!sideBlock && !currentBlock)
                {
                    pData->direction ^= (KEY_LEFT | KEY_RIGHT);
                    return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
                }

                if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                {
                    pData->direction ^= (KEY_LEFT | KEY_RIGHT);
                    return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
                }

                pData->timer = 0x0;
            }
        }
        else
            pData->timer = 0x0;
    }

    return SPOSE_NONE;
}

u8 SamusPullingSelfUp(struct SamusData* pData)
{
    u16 offset;

    offset = SamusPullingSelfUp_velocity[pData->currentAnimationFrame];
    if (pData->timer != 0x0)
        offset /= 0x1;

    pData->yPosition -= offset;
    return SPOSE_NONE;
}

u8 SamusPullingSelfUpGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, pData->timer) == SAMUS_ANIM_STATE_ENDED)
    {
        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - 0x1;
        return SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING;
    }
    
    return SPOSE_NONE;
}

u8 SamusPullingSelfForward(struct SamusData* pData)
{
    if (pData->direction & KEY_RIGHT)
        pData->xPosition += 0x4;
    else
        pData->xPosition -= 0x4;

    return SPOSE_NONE;
}

u8 SamusPullingSelfForwardGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
    {
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusPullingSelfIntoMorphballTunnelGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, pData->timer) == SAMUS_ANIM_STATE_SUB_ENDED)
    {
        if (pData->direction & KEY_RIGHT)
            pData->xPosition += 0x6;
        else
            pData->xPosition -= 0x6;

        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - 0x1;
        SoundPlay(0x77);
        return SPOSE_MORPH_BALL;
    }

    return SPOSE_NONE;
}

/**
 * @brief 9b28 | 8c | Samus using an elevator subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusUsingAnElevator(struct SamusData* pData)
{
    u8 stop;
    u32 currentBlock;
    u32 previousBlock;
    i16 newPosition;

    if (!pData->currentAnimationFrame)
    {
        stop = FALSE;

        pData->yPosition -= pData->yVelocity;

        currentBlock = ClipdataCheckCurrentAffectingAtPosition(pData->yPosition, pData->xPosition) >> 0x10;

        if (pData->elevatorDirection & KEY_UP)
        {
            previousBlock = ClipdataCheckCurrentAffectingAtPosition(gPreviousXPosition, pData->xPosition) >> 0x10;
            if (currentBlock != CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK && previousBlock == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK)
            {
                newPosition = pData->yPosition | SUB_PIXEL_POSITION_FLAG;
                pData->yPosition = newPosition;
                stop++;
            }
        }
        else if (pData->elevatorDirection & KEY_DOWN)
        {
            if (currentBlock == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
            {
                newPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - 1;
                pData->yPosition = newPosition;
                stop++;
            }
        }

        if (stop)
        {
            pData->currentAnimationFrame++;
            pData->animationDurationCounter = 0x0;
            pData->yVelocity = 0x0;
            SoundFade(0x10E, 0xA);
        }
    }

    return SPOSE_NONE;
}

u8 SamusUsingAnElevatorGFX(struct SamusData* pData)
{

}

u8 SamusFacingTheForeground(struct SamusData* pData)
{
    u16 direction;

    direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);

    if (direction != 0x0 && pData->lastWallTouchedMidAir == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_FOREGROUND;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningFromFacningForegroundGFX(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 0x2)
    {
        if (pData->elevatorDirection != 0x0)
            return SPOSE_USING_AN_ELEVATOR;
        else if (pData->timer != 0x0)
            return SPOSE_SAVING_LOADING_GAME;
        else if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusDelayBeforeShinesparkingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
    {
        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
            pData->turning = TRUE;
        return SPOSE_SHINESPARKING;
    }
    else
        return SPOSE_NONE;
}

/**
 * @brief 9ca0 | b0 | Samus shinesparking subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusShinesparking(struct SamusData* pData)
{
    u8 hittingSideBlock;
    u16 nextX;
    u16 nextY;
    u16 nextSlope;
    i32 xOffset;
    u8 stop;

    hittingSideBlock = FALSE;

    if (pData->forcedMovement == FORCED_MOVEMENT_UPWARDS_SHINESPARK)
    {
        if (pData->yVelocity == 0x0)
            stop = TRUE;
    }
    else if (pData->forcedMovement != FORCED_MOVEMENT_SIDEWARDS_SHINESPARK)
    {
        if (pData->yVelocity != 0x0)
        {
            if (pData->xVelocity == 0x0)
                hittingSideBlock++;
        }
        else
            stop = TRUE;
    }
    else
    {
        if (pData->xVelocity == 0x0)
            hittingSideBlock++;
        else
            stop = FALSE;
    }

    if (stop)
    {
        ScreenShakeStartVertical(0x1E, 0x1);
        return pData->pose + 1;
    }

    if (hittingSideBlock)
    {
        if (pData->direction & KEY_RIGHT)
            xOffset = 0x1C;
        else
            xOffset = -0x1C;

        if (SamusSlopeRelated(pData->xPosition + xOffset, pData->yPosition + 1, &nextX, &nextY, &nextSlope) && nextSlope)
        {
            pData->currentSlope = nextSlope;
            pData->yPosition = nextY;
            gUnk_03004fc9++;
            return SPOSE_LANDING_REQUEST;
        }

        ScreenShakeStartHorizontal(0x1E, 0x1);
        return pData->pose + 1;
    }

    return SPOSE_NONE;
}

u8 SamusShinesparkingGFX(struct SamusData* pData)
{

}

u8 SamusShinesparkCollisionGFX(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 0x11)
        return SPOSE_DELAY_AFTER_SHINESPARKING;
    else
        return SPOSE_NONE;
}

u8 SamusDelayAfterShinesparkingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

/**
 * @brief 9e0c | 28 | Delay before ballsparking subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusDelayBeforeBallsparking(struct SamusData* pData)
{
    if (gButtonInput & (pData->direction ^ (KEY_LEFT | KEY_RIGHT)))
        pData->direction ^= (KEY_LEFT | KEY_RIGHT);

    return SPOSE_NONE;
}

u8 SamusDelayBeforeBallsparkingGFX(struct SamusData* pData)
{

}

u8 SamusBallsparkingGFX(struct SamusData* pData)
{

}

u8 SamusBallsparkCollisionGFX(struct SamusData* pData)
{
    if (pData->animationDurationCounter >= 0x11)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

u8 SamusOnZipline(struct SamusData* pData)
{
    u16* input;

    if (gChangedInput & KEY_A)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_ON_ZIPLINE;
    else if (pData->pose != SPOSE_ON_ZIPLINE)
        return SPOSE_NONE;
    else
    {
        if (!(gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT))))
        {
            SamusAimCannon(pData);
            return SPOSE_NONE;
        }
        return SPOSE_TURNING_ON_ZIPLINE;
    }
}

u8 SamusShootingOnZiplineGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
        return SPOSE_ON_ZIPLINE;
    else
        return SPOSE_NONE;
}

u8 SamusMorphballOnZipline(struct SamusData* pData)
{
    u16 direction;

    if (gChangedInput & KEY_A)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
    {
        direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        if (direction != 0x0)
            pData->direction = direction;
        return SPOSE_NONE;
    }
}

u8 SamusSavingLoadingGame(struct SamusData* pData)
{
    if (pData->timer != 0x0)
    {
        pData->currentAnimationFrame = 0x0;
        pData->animationDurationCounter = 0x0;
    }

    return SPOSE_NONE;
}

u8 SamusTurningAroundToDownloadMapData(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_DOWNLOADING_MAP_DATA;
    else
        return SPOSE_NONE;
}

/**
 * @brief Subroutine for the getting hurt pose
 * 
 * @param pData Samus Data Pointer
 * @return u8 New Pose
 */
u8 SamusGettingHurt(struct SamusData* pData)
{
    u8 forcedMovement;

    forcedMovement = 0x0;
    if (pData->forcedMovement != 0x0 && (u16)(pData->yVelocity + 0x7) < 0xF && pData->lastWallTouchedMidAir++ < 0xA)
    {
        gSamusPhysics.yAcceleration = 0x0;
        forcedMovement = 0x1;
    }

    if (forcedMovement == 0x0 && pData->timer++ > 0xC && pData->yVelocity < -0x10)
    {
        pData->forcedMovement = forcedMovement;

        if (pData->pose == SPOSE_GETTING_HURT) // Set mid air pose
            return SPOSE_MIDAIR;

        return SPOSE_MORPH_BALL_MIDAIR;
    }
    return SPOSE_NONE;
}

u8 SamusGettingHurtGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame--; // Alternate between last frames

    return SPOSE_NONE;
}

u8 SamusGettingKnockedBack(struct SamusData* pData)
{
    if (pData->timer >= 0xD)
    {
        if (pData->yVelocity < -0x20)
        {
            if (pData->pose == SPOSE_GETTING_KNOCKED_BACK)
                return SPOSE_MIDAIR;
        }
        return SPOSE_MORPH_BALL_MIDAIR;
    }
    else
        pData->timer++;
    return SPOSE_NONE;
}

/**
 * @brief a0dc | 10c | Samus dying subroutine
 * 
 * @param pData Samus Data Pointer
 * @return u8 New pose
 */
u8 SamusDying(struct SamusData* pData)
{
    u32 bgX;
    u32 bgY;

    if (pData->lastWallTouchedMidAir == 0)
    {
        pData->lastWallTouchedMidAir++;
        StopAllMusicsAndSounds(); // Undefined
    }
    else if (pData->lastWallTouchedMidAir == 1)
    {
        pData->lastWallTouchedMidAir++;
        SoundPlay(0x83); // Death
    }

    pData->invincibilityTimer = 0x40;

    if (pData->xVelocity != 0x0 || pData->yVelocity != 0x0)
    {
        bgX = gBG1XPosition + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
        bgY = gBG1YPosition + BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE;

        if (pData->xVelocity > 0)
        {
            if (pData->xPosition >= bgX)
                pData->xVelocity = 0x0;
        }
        else if (pData->xVelocity < 0)
        {
            if (pData->xPosition <= bgX)
                pData->xVelocity = 0x0;
        }

        if (pData->yVelocity > 0)
        {
            if (pData->yPosition >= bgY)
                pData->yVelocity = 0x0;
        }
        else if (pData->yVelocity < 0)
        {
            if (pData->yPosition <= bgY)
                pData->yVelocity = 0x0;
        }

        pData->yPosition += pData->yVelocity;
    }

    if (pData->currentAnimationFrame > 0x17)
    {
        switch (pData->timer++)
        {
            case 0x4:
                gMonochromeBgFading = 0x2;
            
            case 0xC:
            case 0x14:
            case 0x1C:
            case 0x24:
            case 0x2C:
            case 0x34:
            case 0x50:
                pData->walljumpTimer++;
                break;

            case 0x78:
                gMainGameMode = GM_GAMEOVER;
                gGameModeSub1 = 0;
        }
    }

    return SPOSE_NONE;
}

u8 SamusCrouchingToCrawlGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
    {
        if (pData->direction & KEY_RIGHT)
            pData->xPosition += 0x4;
        else
            pData->xPosition -= 0x4;
        
        return SPOSE_STARTING_TO_CRAWL;
    }
    else
        return SPOSE_NONE;
}

u8 SamusCrawlingStopped(struct SamusData* pData)
{
    pData->xVelocity = 0x0;
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else if (gButtonInput & pData->direction)
        return SPOSE_CRAWLING;
    else if (!((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput))
        return SPOSE_NONE;
    else
        return SPOSE_TURNING_AROUND_WHILE_CRAWLING;
}

u8 SamusStartingToCrawlGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_SUB_ENDED)
        return SPOSE_CRAWLING_STOPPED;
    else
        return SPOSE_NONE;
}

u8 SamusCrawling(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]) == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else
    {
        if (gSamusPhysics.hasNewProjectile)
            return SPOSE_SHOOTING_WHILE_CRAWLING;
        else
        {
            if (gButtonInput & pData->direction)
            {
                SamusApplyXAcceleration(gSamusPhysics.xAcceleration, 0x20, pData);
                return SPOSE_NONE;
            }
            else
            {
                if ((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput)
                    pData->turning = TRUE;

                return SPOSE_CRAWLING_STOPPED;
            }
        }
    }
}

u8 SamusDyingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;
    else if (animState == SAMUS_ANIM_STATE_SUB_ENDED && (pData->currentAnimationFrame == 0x1 || pData->currentAnimationFrame == 0x4))
        SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    if (pData->animationDurationCounter == 0x1 && pData->currentAnimationFrame == 0x0)
        SoundPlay(0x9E);

    return SPOSE_NONE;
}

u8 SamusTurningAroundWhileCrawling(struct SamusData* pData)
{
    if (gSamusPhysics.hasNewProjectile)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else
        return SPOSE_NONE;
}

u8 SamusCrawlingGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STARTING_TO_CRAWL;
    else
        return SPOSE_NONE;
}

u8 SamusGrabbingALedgeSuitlessGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == 0x2)
        return SPOSE_HANGING_ON_LEDGE;
    else
        return SPOSE_NONE;
}

u8 SamusFacingTheBackground(struct SamusData* pData)
{
    u16 direction;

    direction = (gButtonInput & (KEY_RIGHT | KEY_LEFT));
    if (direction != 0x0 && pData->lastWallTouchedMidAir == 0x0)
    {
        pData->direction = direction;
        return SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningFromFacingTheBackgroundGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
    {
        if (gButtonInput & (pData->direction ^ (KEY_RIGHT | KEY_LEFT)))
            return SPOSE_RUNNING;
        else if (pData->lastWallTouchedMidAir != 0x0)
            return SPOSE_FACING_THE_BACKGROUND_SUITLESS;
        else if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusTurningToEnterEscapeShipGFX(struct SamusData* pData)
{
    if (SamusUpdateAnimation(pData, FALSE) == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_IN_ESCAPE_SHIP;
    else
        return SPOSE_NONE;
}

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

    if (SamusTakeHazardDamage(pData, pEquipment, pHazard) )
        return SPOSE_HURT_REQUEST;
    else
    {
        if (pWeapon->cooldown != 0x0)
            pWeapon->cooldown--;

        if (pData->shinesparkTimer != 0x0 && pData->pose != SPOSE_DELAY_BEFORE_SHINESPARKING && pData->pose != SPOSE_DELAY_BEFORE_BALLSPARKING)
        {
            timer = pData->shinesparkTimer;
            if (!(timer & 0xF))
                play_sound(0x8D);
            pData->shinesparkTimer--;
        }
        if (pEquipment->suitType != SUIT_SUITLESS)
            SamusSetHighlightedWeapon(pData, pWeapon, pEquipment);

        SamusSetSpinningPose(pData, pEquipment);
        samus_spawn_newProjectile(pData, pWeapon, pEquipment);
        pose = sSamusPoseFunctionPointers[pData->pose](pData);
        if (pose == SPOSE_NONE)
            sSamusPoseGFXFunctionPointers[pData->pose](pData);
        SamusCheckShinesparking(pData);
    }

    return pose;
}

/**
 * @brief Updates the position and the vecolity of samus
 * 
 * @param pData Samus Data Pointer
 */
void SamusUpdateVelocityPosition(struct SamusData* pData)
{

}

void SamusUpdateGraphicsOAM(struct SamusData* pData, u8 direction)
{

}

void SamusUpdatePalette(struct SamusData* pData)
{

}

void SamusCheckPlayLowHealthSound(void)
{
    struct SamusData* pData;
    struct Equipment* pEquipment;

    pData = &gSamusData;
    pEquipment = &gEquipment;

    if (pEquipment->lowHealth && pData->pose != SPOSE_DYING && gPreventMovementTimer == 0x0 && !(gFrameCounter8Bit & 0xF))
        SoundPlay(0x82);
}

void SamusUpdateDrawDistanceAndStandingStatus(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 offset;
    u8 standing;
    
    offset = samus_visual_data[pData->pose][0];
    pPhysics->drawDistanceLeftOffset = samus_draw_distance_offsets[offset][0];
    pPhysics->drawDistanceTopOffset = samus_draw_distance_offsets[offset][1];
    pPhysics->drawDistanceRightOffset = samus_draw_distance_offsets[offset][2];
    pPhysics->drawDistanceBottomOffset = samus_draw_distance_offsets[offset][3];
    standing = samus_visual_data[pData->pose][2];
    if (pData->standingStatus != STANDING_ENEMY)
        pData->standingStatus = standing;
}

void SamusUpdateArmCannonPositionOffset(u8 direction)
{

}

void SamusInit(void)
{

}

void SamusDraw(void)
{

}
