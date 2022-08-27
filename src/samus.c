#include "samus.h"
#include "sprite.h"
#include "clipdata.h"
#include "music.h"
#include "../data/data.h"
#include "globals.h"

void SamusCheckScrewSpeedboosterAffectingEnvironment(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    u8 unk_bool;
    u16 left_hitbox, right_hitbox, top_hitbox;
    u16 hitboxTopOffset;
    u16 y_pos;
    u16 action;

    action = DESTRUCTING_ACTION_NONE;
    if ((pData->pose == SPOSE_SCREW_ATTACKING) ||
        ((pData->pose == SPOSE_STARTING_SPIN_JUMP &&
        ((gEquipment.suitMiscActivation & SMF_SCREW_ATTACK) != 0x0))))
    {
        action = DESTRUCTING_ACTION_SCREW;
    }
    if (pData->speedboostingShinesparking)
    {
        action += DESTRUCTING_ACTION_SPEED;
    }
    
    if (action != DESTRUCTING_ACTION_NONE)
    {
#ifndef NONMATCHING
        register u16 tmp_y_pos asm("r3");
        register u16 tmp_top_hitbox asm("r0");
#endif // NONMATCHING

        left_hitbox = pData->xPosition + pPhysics->hitboxLeftOffset;
        right_hitbox = pData->xPosition + pPhysics->hitboxRightOffset;

        hitboxTopOffset = pPhysics->hitboxTopOffset;
#ifndef NONMATCHING
        tmp_y_pos = pData->yPosition;
        tmp_top_hitbox = tmp_y_pos + hitboxTopOffset;
        top_hitbox = tmp_top_hitbox;
#else // NONMATCHING
        top_hitbox = pData->yPosition + hitboxTopOffset;
#endif // NONMATCHING

        y_pos = (u16)pData->yPosition;
        unk_bool = hitboxTopOffset << 0x10 < -0x400000;

        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  top_hitbox,  action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  top_hitbox,  action);
        if (pPhysics->horizontalMovingDirection == HDMOVING_RIGHT)
        {
            if (unk_bool)
            {
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  top_hitbox + 0x40,  action);
            }
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox,  y_pos,  action);
        }
        else
        {
            if (unk_bool)
            {
                BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  top_hitbox + 0x40,  action);
            }
            BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox,  y_pos,  action);
        }
        if (pPhysics->standingStatus == STANDING_GROUND)
        {
            y_pos = y_pos + 1;
            action = 4;
        }
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(left_hitbox, y_pos, action);
        BlockSamusApplyScrewSpeedboosterDamageToEnvironment(right_hitbox, y_pos, action);
    }
}

u8 SamusSlopeRelated(u16 xPosition, u16 yPosition, u16* pXPosition, u16* pYPosition, u16* pSlope)
{
    u32 clipdata;
    u16 slope_type;
    u16 next_x_pos, next_y_pos;
    u8 collision;

    u32 x_slope_offset;
    u16 x_begin;

#ifndef NONMATCHING
    register vu16* x_ptr asm("r2");
    register i32 x_begin__ asm("r1");
    register i32 mask_FFC0 asm("r3");
    register i32 tmp_next_x_pos asm("r1");
#else
    i32 x_begin__;
    i32 mask_FFC0;
    i32 tmp_next_x_pos;
#endif // NONMATCHING

    clipdata = process_clipdata_for_samus(yPosition, xPosition);
    collision = (-(clipdata & 0x1000000) >> 0x1F);

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            next_y_pos = ((yPosition & BLOCK_POSITION_FLAG) + 0x3F) - (xPosition & SUB_PIXEL_POSITION_FLAG);
            next_x_pos = ((xPosition & BLOCK_POSITION_FLAG) + 0x3F) - (yPosition & SUB_PIXEL_POSITION_FLAG);

            slope_type = SLOPE_STEEP | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            next_y_pos = ((yPosition & BLOCK_POSITION_FLAG) + 0x3F) - ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            x_begin = xPosition & BLOCK_POSITION_FLAG;

            x_slope_offset = (yPosition & SUB_PIXEL_POSITION_FLAG) * 2 - 0x7E;
            tmp_next_x_pos = x_begin - x_slope_offset;
            next_x_pos = tmp_next_x_pos;

            slope_type = SLOPE_SLIGHT | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            next_y_pos = ((yPosition & BLOCK_POSITION_FLAG) + 0x1F) - ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            x_begin = xPosition & BLOCK_POSITION_FLAG;

            x_slope_offset = (yPosition & SUB_PIXEL_POSITION_FLAG) * 2 - 0x3E;
            tmp_next_x_pos = x_begin - x_slope_offset;
            next_x_pos = tmp_next_x_pos;

            slope_type = SLOPE_SLIGHT | SLOPE_LEFT;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            next_y_pos = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            next_x_pos = (xPosition & BLOCK_POSITION_FLAG) | (yPosition & SUB_PIXEL_POSITION_FLAG);

            slope_type = SLOPE_STEEP | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            mask_FFC0 = 0xFFC0;
            next_y_pos = (yPosition & mask_FFC0) | ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2 + 0x1F);
            x_begin__ = xPosition & mask_FFC0;

            x_slope_offset = (yPosition & SUB_PIXEL_POSITION_FLAG) * 2 + 0xFFC1;
            next_x_pos = x_begin__ +  x_slope_offset;

            slope_type = SLOPE_SLIGHT | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            mask_FFC0 = 0xFFC0;
            next_y_pos = (yPosition & mask_FFC0) | ((xPosition & SUB_PIXEL_POSITION_FLAG) / 2);
            x_begin__ = xPosition & mask_FFC0;

            x_slope_offset = (yPosition & SUB_PIXEL_POSITION_FLAG) * 2;
            next_x_pos = x_begin__ + x_slope_offset;

            slope_type = SLOPE_SLIGHT | SLOPE_RIGHT;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collision = COLLISION_PASS_THROUGH_BOTTOM;
        default:
            next_y_pos = yPosition & BLOCK_POSITION_FLAG;
            next_x_pos = xPosition & BLOCK_POSITION_FLAG;
            slope_type = SLOPE_NONE;
    }
    *pYPosition = next_y_pos;
#ifndef NONMATCHING
    x_ptr = pXPosition;
    *x_ptr =
#else // NONMATCHING
    *pX_position =
#endif // NONMATCHING
        next_x_pos;
    *pSlope = slope_type;
    return collision;
}

u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition)
{

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

}

u8 SamusCheckTopCollision(struct SamusData* pData, struct SamusPhysics* pPhysics)
{

}

void SamusCheckCollisions(struct SamusData* pData, struct SamusPhysics* pPhysics)
{
    /*u8 new_pose;
    i16 offset;
    u32 block_prevent;
    u32 block_grabbing;
    u32 block_unk;
    struct CurrentAffectingClip clip;

    if (pPhysics->standingStatus > STANDING_NOT_IN_CONTROL)
        return;

    SamusCheckScrewSpeedboosterAffectingEnvironment(pData, pPhysics);

    new_pose = SPOSE_NONE;
    if (pPhysics->verticalMovingDirection == VDMOVING_UP)
        new_pose = SamusCheckTopCollision(pData, pPhysics);
    else if (pPhysics->verticalMovingDirection == VDMOVING_DOWN)
        new_pose = SamusCheckLandingCollision(pData, pPhysics);
    else if (pPhysics->horizontalMovingDirection == HDMOVING_NONE && pPhysics->standingStatus == STANDING_GROUND)
        new_pose = SamusCheckStandingOnGroundCollision(pData, pPhysics);
    else if (pPhysics->standingStatus == STANDING_MIDAIR)
        new_pose = SamusCheckLandingCollision(pData, pPhysics);
    else
    {
        new_pose = SamusCheckWalkingSidesCollision(pData, pPhysics);
        if (new_pose == SPOSE_NONE)
            new_pose = unk_5AD8(pData, pPhysics);
    }

    if (new_pose == SPOSE_NONE && gEquipment.suitMiscActivation & SMF_POWER_GRIP && gButtonInput & pData->direction && pData->yVelocity < 0x1)
    {
        // Power grip code
        if (pData->direction & KEY_RIGHT)
            offset = 0x1F;
        else
            offset = -0x1F;

        // Block right above
        block_prevent = ClipdataProcessForSamus(pData->yPosition + 0x20, pData->xPosition);
        if (block_prevent == 0x0)
        {
            // Block below samus
            block_prevent = ClipdataProcessForSamus(pData->yPosition - 0xA0, pData->xPosition);
            // Block that samus will try to grab
            block_grabbing = ClipdataProcessForSamus(pData->yPosition - 0x68, pData->xPosition + offset);
            // Not sure what this block is
            block_unk = ClipdataProcessForSamus(pData->yPosition - 0x80, pData->xPosition + offset);

            switch (pData->pose)
            {
                case SPOSE_MIDAIR:
                case SPOSE_STARTING_SPIN_JUMP:
                case SPOSE_SPINNING:
                case SPOSE_STARTING_WALL_JUMP:
                case SPOSE_SPACE_JUMPING:
                case SPOSE_SCREW_ATTACKING:
                    clip = ClipdataCheckCurrentAffectingAtPosition(pData->yPosition - 0x60, pData->xPosition + offset);
                    // Checks if can grab block
                    if (!(block_prevent & 0x1000000) && block_grabbing & 0x1000000 && clip.movement != CLIPDATA_MOVEMENT_NON_POWER_GRIP && !(block_unk & 0x1000000))
                    {
                        if (gEquipment.suitType == SUIT_SUITLESS)
                        {
                            new_pose = SPOSE_GRABBING_A_LEDGE_SUITLESS;
                            SoundPlay(0x9B); // Suitless grip
                        }
                        else
                        {
                            new_pose = SPOSE_HANGING_ON_LEDGE;
                            if (pPhysics->slowedByLiquid)
                                SoundPlay(0x95); // Underwater grip
                            else
                                SoundStop(0x7A); // Normal grip
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
                    new_pose = SPOSE_CROUCHING_TO_CRAWL;
                break;

            case SPOSE_SPINNING:
            case SPOSE_SCREW_ATTACKING:
                // Setup wall jump
                pData->walljumpTimer = 0x8;
                pData->lastWallTouchedMidAir = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
                break;

            case SPOSE_ON_ZIPLINE:
            case SPOSE_SHOOTING_ON_ZIPLINE:
            case SPOSE_TURNING_ON_ZIPLINE:
            case SPOSE_MORPH_BALL_ON_ZIPLINE:
                // Drop if on zipline
                new_pose = SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
    }

    if (pPhysics->standingStatus != STANDING_INVALID)
    {
        if (new_pose == SPOSE_UPDATE_JUMP_VELOCITY_REQUEST)
            pData->yPosition++;

        if (new_pose != SPOSE_NONE)
            SamusSetPose(new_pose);
    }*/
}

/**
 * 6214 | 3dc | 
 * Checks if an environment effect for samus can/should spawn and spawns it
 * 
 * @param pData Samus Data Pointer
 * @param default_offset Default offset in the global array (0 means auto)
 * @param request Environmental effect requested
 */
void SamusCheckSetEnvironmentalEffect(struct SamusData* pData, u32 default_offset, u32 request)
{
    u8 found;
    u8 can_spawn;
    u8 offset;
    u16 xPosition;
    u16 yPosition;
    u8 effect;
    u32 current_affecting;
    u32 previous_liquid;
    u16 previous_pos;
    u16 liquid_check_pos;
    u16 offset_x;
    struct SamusPhysics* pPhysics;

    pPhysics = &gSamusPhysics;

    found = FALSE;
    can_spawn = TRUE;

    if (default_offset == 0x0)
    {
        for (offset = 0; offset < 0x3; offset++)
        {
            if (gSamusEnvirnmentalEffects[offset].type == ENV_EFFECT_NONE)
                break;
        }
        if (offset > 0x2)
            can_spawn--;
    }
    else
        offset = default_offset;

    switch (request)
    {
        case WANTING_RUNNING_EFFECT:
        case WANTING_RUNNING_EFFECT_:
            if (pData->direction & KEY_RIGHT)
                offset_x = pData->xPosition + 0x4;
            else
                offset_x = pData->xPosition - 0x4;

            current_affecting = ClipdataCheckGroundEffect(pData->yPosition + 0x1, offset_x);

            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                found++;
                if (request == WANTING_RUNNING_EFFECT)
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(0xA1); // Suitless wet ground
                    else
                        SoundPlay(0x68); // Wet footsteps
                }
                else
                {
                    if (gEquipment.suitType == SUIT_SUITLESS)
                        SoundPlay(0xA2); // Suitless wet ground 2
                    else
                        SoundPlay(0x69); // Wet footsteps 2
                }
            }
            else if (current_affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_DUSTY_GROUND;
                found++;

                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66); // Dusty footstep
                else
                    SoundPlay(0x67); // Dusty footstep 2
            }
            else if (current_affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND;
                found++;
                if (request == WANTING_RUNNING_EFFECT)
                    SoundPlay(0x66); // Dusty footstep
                else
                    SoundPlay(0x67); // Dusty footstep 2
            }
            xPosition = offset_x;
            yPosition = pData->yPosition;
            break;

        case WANTING_LANDING_EFFECT:
            current_affecting = ClipdataCheckGroundEffect(pData->yPosition + 0x1, pData->xPosition);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_WET_GROUND;
                found++;
                if (gEquipment.suitType == SUIT_SUITLESS)
                    SoundPlay(0xA3); // Suitless landing on wet ground
                else
                    SoundPlay(0x74); // Landing on wet ground
            }
            else if (current_affecting == GROUND_EFFECT_BUBBLY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_BUBBLY_GROUND;
                found++;
            }
            else if (current_affecting == GROUND_EFFECT_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_DUSTY_GROUND;
                found++;
                SoundPlay(0x73); // Landing on dusty ground
            }
            else if (current_affecting == GROUND_EFFECT_VERY_DUSTY_GROUND)
            {
                effect = ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND;
                found++;
                SoundPlay(0x73); // Landing on dusty ground
            }
            else
            {
                if (pPhysics->slowedByLiquid)
                    SoundPlay(0x95); // Suitless landing/ledge grip underwater
                else if (gSamusDataCopy.lastWallTouchedMidAir != KEY_NONE)
                    SoundPlay(0x72); // Morphball drop bounce 2?
                else if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(0x71); // Landing
                else
                    SoundPlay(0x99); // Suitless landing
            }

            xPosition = pData->xPosition;
            yPosition = pData->yPosition;
            break;

        case WANTING_GOING_OUT_OF_LIQUID_EFFECT:
        case WANTING_RUNNING_OUT_OF_LIQUID_EFFECT:
            liquid_check_pos = pData->yPosition;
            previous_pos = gPreviousYPosition;
            if (effect == WANTING_GOING_OUT_OF_LIQUID_EFFECT)
            {
                liquid_check_pos -= 0x10;
                previous_pos -= 0x10;
            }

            current_affecting = ClipdataCheckCurrentAffectingAtPosition(liquid_check_pos, pData->xPosition) & 0xFF;
            previous_liquid = ClipdataCheckCurrentAffectingAtPosition(previous_pos, pData->xPosition) & 0xFF;

            if (liquid_check_pos < previous_pos)
            {
                if (current_affecting != HAZARD_TYPE_WATER && previous_liquid == HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_STRONG_LAVA && previous_liquid == HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_WEAK_LAVA && previous_liquid == HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting != HAZARD_TYPE_ACID && previous_liquid == HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
            }
            else
            {
                if (current_affecting == HAZARD_TYPE_WATER && previous_liquid != HAZARD_TYPE_WATER)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_WATER;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_STRONG_LAVA && previous_liquid != HAZARD_TYPE_STRONG_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_WEAK_LAVA && previous_liquid != HAZARD_TYPE_WEAK_LAVA)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
                else if (current_affecting == HAZARD_TYPE_ACID && previous_liquid != HAZARD_TYPE_ACID)
                {
                    effect = ENV_EFFECT_GOING_OUT_OF_LAVA;
                    found++;
                }
            }

            if (request == WANTING_RUNNING_OUT_OF_LIQUID_EFFECT)
                effect++;

            xPosition = pData->xPosition;
            if (gEffectYPosition != 0x0)
                yPosition = gEffectYPosition;
            else
            {
                if (previous_pos < liquid_check_pos)
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
                    xPosition = pData->xPosition + 0xC;
                else
                    xPosition = pData->xPosition - 0xC;

                yPosition = pData->yPosition + pPhysics->drawDistanceTopOffset + 0x10;
                SoundPlay(0x91); // Breathing bubbles
            }
            break;

        case WANTING_SKIDDING_EFFECT:
            current_affecting = ClipdataCheckGroundEffect(pData->yPosition + 0x1, pData->xPosition);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_SKIDDING_ON_WET_GROUND;
                found++;
            }
            else if (current_affecting - 0x2 < 0x2) // Both dusty and very dusty
            {
                effect = ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND;
                found++;
            }
            xPosition = pData->xPosition;
            yPosition = pData->yPosition;
            break;

        case WANTING_RUNNING_ON_WET_GROUND:
            current_affecting = ClipdataCheckGroundEffect(pData->yPosition + 0x1, pData->xPosition);
            if (current_affecting == GROUND_EFFECT_WET_GROUND)
            {
                effect = ENV_EFFECT_RUNNING_ON_WET_GROUND;
                xPosition = pData->xPosition;
                yPosition = pData->yPosition;
                found++;
            }
            break;
    }

    if (found & can_spawn)
    {
        gSamusEnvirnmentalEffects[offset].type = effect;
        gSamusEnvirnmentalEffects[offset].currentAnimationFrame = 0x0;
        gSamusEnvirnmentalEffects[offset].animationDurationCounter = 0x0;
        gSamusEnvirnmentalEffects[offset].xPosition = xPosition;
        gSamusEnvirnmentalEffects[offset].yPosition = yPosition;
    }
}

void SamusUpdateEnvironmentalEffect(struct SamusData* pData)
{

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
    /*struct Equipment* pEquipment;

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
    }*/
}

void SamusSetLandingPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon)
{
    /*u8 collision;
    
    pCopy->lastWallTouchedMidAir = KEY_NONE;

    switch (pCopy->pose)
    {
        case SPOSE_MIDAIR:
            collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
            if (collision)
                pData->pose = SPOSE_CROUCHING;
            else
            {
                if (pCopy->xVelocity == 0x0)
                    pData->pose = SPOSE_LANDING;
                else
                {
                    if (pCopy->speedboostingShinesparking)
                    {
                        pData->pose = SPOSE_RUNNING;
                        pData->speedboostingShinesparking = TRUE;
                    }
                    else
                        pData->pose = SPOSE_STANDING;
                }
            }
            break;

        case SPOSE_MORPH_BALL_MIDAIR:
            pCopy->lastWallTouchedMidAir++;

            if (gButtonInput & KEY_A && gEquipment.suitMiscActivation & SMF_HIGH_JUMP)
            {
                // /!\ Invalid cast
                collision = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
                collision &= SAMUS_COLLISION_DETECTION_MIDDLE_LEFT | SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT;
                if (!(collision))
                    pData->forcedMovement = 0x14;
            }
            else
            {
                if (pCopy->yVelocity < -0xC0 && !gSamusPhysics.slowedByLiquid && ClipdataCheckGroundEffect(pData->yPosition + 0x1, pData->xPosition) != GROUND_EFFECT_VERY_DUSTY_GROUND)
                {
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
                if (pData->direction & KEY_RIGHT)
                    pData->xVelocity = 0xA0;
                else
                    pData->xVelocity = -0xA0;

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
                ScreenShakeStartHorizontal(0x1E, 0x1);
                if (pCopy->pose == SPOSE_SHINESPARKING)
                    pData->pose = SPOSE_SHINESPARK_COLLISION;
                else
                    pData->pose = SPOSE_BALLSPARK_COLLISION;

                pData->forcedMovement = pCopy->forcedMovement;
                pData->currentAnimationFrame = 0x1;
                SoundPlay(0x90); // Shinespark collision
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
    }

    pData->armCannonDirection = pCopy->armCannonDirection;

    switch (pData->pose)
    {
        case SPOSE_LANDING:
            if (gSamusPhysics.hasNewProjectile != 0x0)
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


    SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_LANDING_EFFECT);*/
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
        gMonochromeBGFading = 0x1;
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
    pWeapon->newProjectile = PROJECTILE_NONE;
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
    pWeapon->newProjectile = PROJECTILE_NONE;
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

void SamusUpdatePhysics(struct SamusData* pData)
{

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

void SamusCopyPalette(u16* pSrc, i32 offset, i32 nbrColors)
{
    /*u16* pPalette;
    u32 size;

    if (offset < offset + nbrColors)
    {
        pPalette = gSamusPalette;
        pPalette += offset;
        size = nbrColors - offset;
        do {
           *pPalette++ = *src++;
            size--;
        } while (size != 0x0);
    }*/
}

void SamusUpdate(void)
{
    u8 new_pose;
    struct SamusData* pData;

    pData = &gSamusData;

    if (0x1 < gGameModeSub1)
        pData->animationDurationCounter++;
    
    SamusUpdatePhysics(pData);
    new_pose = SamusExecutePoseSubroutine(pData);
    if (new_pose != SPOSE_NONE)
        SamusSetPose(new_pose);
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

void SamusBombBounce(u8 direction)
{
    /*u8 can_bounce;

    if (gSamusPhysics.slowedByLiquid)
        return;

    can_bounce = FALSE;
    if ((direction & 0x7F) > 0x9)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_MORPH_BALL_MIDAIR:
                if (gSamusData.yVelocity <= 0x0 && (direction & 0x80) == 0x0)
                    can_bounce = TRUE;
            
            default:
                if (!can_bounce)
                    return;

            case SPOSE_ROLLING:
            case SPOSE_MORPHING:
            case SPOSE_MORPH_BALL:
                gSamusData.forcedMovement = direction & 0x7F;
                SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
        }
    }*/
}

void SamusAimCannon(struct SamusData* pData)
{
    /*struct WeaponInfo* pWeapon;
    u16 direction;

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
                else if (DIAG_AIM_UP >= pWeapon->diagonalAim || gButtonInput & KEY_UP)
                {
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                    pWeapon->diagonalAim = DIAG_AIM_UP;
                }
                return;

            default:
                return;

            case SPOSE_ON_ZIPLINE:
                pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                pWeapon->diagonalAim = DIAG_AIM_DOWN;
                return;            
        }
    }

    switch (pData->pose)
    {
        case SPOSE_RUNNING:
            if (gButtonInput & KEY_UP)
                pData->armCannonDirection = ACD_DIAGONALLY_UP;
            else
            {
                direction = gButtonInput & KEY_DOWN;
                if (direction)
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                else
                {
                    if (pData->armCannonDirection < ACD_NONE)
                        pData->armCannonDirection = direction;
                }
            }

            if (gEquipment.suitType == SUIT_SUITLESS || pData->armCannonDirection != ACD_NONE || (pWeapon->weaponHighlighted == WH_NONE && pWeapon->chargeCounter == 0x0))
                pWeapon->diagonalAim = DIAG_AIM_NONE;
            else
                pData->armCannonDirection = ACD_FORWARD;

            break;
        
        case SPOSE_STANDING:
        case SPOSE_SHOOTING:
        case SPOSE_LANDING:
        case SPOSE_UNCROUCHING_SUITLESS:
            if (pData->timer == 0x0 && gButtonInput & KEY_UP)
                    pData->armCannonDirection = ACD_UP;
            pWeapon->diagonalAim = DIAG_AIM_NONE;
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
                if (pData->direction & gButtonInput)
                    pData->armCannonDirection = ACD_DIAGONALLY_UP;
                else
                    pData->armCannonDirection = ACD_UP;
            }
            else
            {
                direction = gButtonInput & KEY_DOWN;
                if (direction)
                {
                    if ((pData->direction & gButtonInput) == 0x0)
                        pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                    else
                        pData->armCannonDirection = ACD_DOWN;
                }
                else
                {
                    if (pData->armCannonDirection & gButtonInput)
                        pData->armCannonDirection = direction;
                    else
                    {
                        if ((u8)(pData->armCannonDirection - 0x3) > 0x2)
                            pData->armCannonDirection = pData->direction;
                    }
                }
            }
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;

        case SPOSE_ON_ZIPLINE:
            direction = gButtonInput & KEY_DOWN;
            if (direction)
            {
                if (pData->direction & gButtonInput)
                    pData->armCannonDirection = ACD_DIAGONALLY_DOWN;
                else
                    pData->armCannonDirection = ACD_DOWN;
                pWeapon->diagonalAim = DIAG_AIM_NONE;
            }
            else
            {
                if ((pData->direction & gButtonInput) == 0x0 && pData->armCannonDirection != ACD_DOWN)
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                else
                {
                    pData->armCannonDirection = direction;
                    pWeapon->diagonalAim = DIAG_AIM_NONE;
                }
            }
        default:
            pWeapon->diagonalAim = DIAG_AIM_NONE;
            break;
    }*/
}

u8 SamusCheckFireBeamMissile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    /*u8 has_proj;
    u8 new_proj;

    has_proj = FALSE;
    if (pWeapon->cooldown == 0x0 && pWeapon->newProjectile == PROJECTILE_NONE && (gChangedInput & KEY_B) != 0x0)
    {
        if ((pWeapon->weaponHighlighted & WH_MISSILE) != 0x0)
            pWeapon->newProjectile = PROJECTILE_MISSILE;
        else if ((pWeapon->weaponHighlighted & WH_SUPER_MISSILE) != 0x0)
            pWeapon->newProjectile = PROJECTILE_SUPER_MISSILE;
        else
            pWeapon->newProjectile = PROJECTILE_BEAM;
        has_proj++;
    }

    if (has_proj)
    {
        if (pData->armCannonDirection == ACD_NONE)
            pData->armCannonDirection = ACD_FORWARD;
        return has_proj;
    }

    if (pWeapon->weaponHighlighted == WH_NONE)
    {
        if ((gButtonInput & KEY_B) != 0x0)
        {
            if ((pEquipment->beamBombsActivation & BBF_CHARGE_BEAM) == 0x0)
                pWeapon->chargeCounter = 0x0;
            else
            {
                if (pWeapon->chargeCounter < 0x4F)
                    pWeapon->chargeCounter++;
                else
                    pWeapon->chargeCounter = 0x40;
            }
        }
        else
        {
            if (pWeapon->chargeCounter >= 0x40)
            {
                new_proj = PROJECTILE_CHARGED_BEAM;
                pWeapon->newProjectile = new_proj;
                has_proj = TRUE;
            }
            else
            {
                if (0x19 < pWeapon->chargeCounter)
                {
                    new_proj = PROJECTILE_BEAM;
                    pWeapon->newProjectile = new_proj;
                    has_proj = TRUE;
                }
            }
            pWeapon->chargeCounter = 0x0;
        }
    }
    else
        pWeapon->chargeCounter = 0x0;

    if (has_proj)
    {
        if (pData->armCannonDirection == ACD_NONE)
            pData->armCannonDirection = ACD_FORWARD;
    }

    return has_proj;*/
}

u8 SamusCheckFirePistol(struct SamusData* pData, struct WeaponInfo* pWeapon)
{
    u8 new_proj;

    new_proj = 0x0;

    if (pWeapon->chargeCounter < 0x7F)
        pWeapon->chargeCounter++;
    else
        pWeapon->chargeCounter = 0x70;

    if (pWeapon->cooldown == 0x0 && pWeapon->newProjectile == PROJECTILE_NONE && (gChangedInput & KEY_B) != 0x0)
    {
        if (pWeapon->chargeCounter >= 0x70)
        {
            pWeapon->newProjectile = PROJECTILE_CHARGED_BEAM;
            pWeapon->chargeCounter = 0x0;
            new_proj++;
        }
        else
            pWeapon->newProjectile = PROJECTILE_BEAM;

        pWeapon->chargeCounter = 0x0;
        new_proj++;
    }

    if (new_proj != PROJECTILE_NONE && pData->armCannonDirection == ACD_NONE)
        pData->armCannonDirection = ACD_FORWARD;

    return new_proj;
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
                if ((gChangedInput & KEY_B) != 0x0 && pWeapon->cooldown == 0x0 && (pEquipment->beamBombsActivation & BBF_BOMBS) != 0x0)
                {
                    if ((pWeapon->weaponHighlighted & WH_POWER_BOMB) != 0x0)
                        pWeapon->newProjectile = PROJECTILE_POWER_BOMB;
                    else
                        pWeapon->newProjectile = PROJECTILE_BOMB;
                }
            case SPOSE_MORPHING:
                if (0x3F < pWeapon->chargeCounter)
                    pWeapon->newProjectile = PROJECTILE_CHARGED_BEAM;
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
    
    return_value = 0x0;
    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forcedMovement = 0x1;
        return_value = 0x1;
    }
    return return_value;
}

void SamusSetHighlightedWeapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment)
{
    /*u8 weapon_high;

    weapon_high = WH_NONE;
    if (pEquipment->currentSuperMissiles == 0x0)
        pWeapon->missilesSeleced = weapon_high;
    else if (pEquipment->currentMissiles == 0x0)
        pWeapon->missilesSeleced = TRUE;
    else if ((gChangedInput & KEY_SELECT) != 0x0)
    {
        pWeapon->missilesSeleced ^= 0x1;
        SoundPlay(0x85);
    }

    switch (pData->pose)
    {
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL:
            if ((gButtonInput & gButtonAssignments.armMissiles) == 0x0 || pEquipment->currentPowerBombs != 0x0)
            {
                weapon_high = WH_POWER_BOMB;
                if (pWeapon->weaponHighlighted == WH_NONE)
                {
                    pWeapon->chargeCounter = 0x0;
                    SoundPlay(0x84);
                }
            }
            else
            {
                if (weapon_high != WH_NONE)
                {
                    if (pWeapon->weaponHighlighted == WH_NONE)
                    {
                        pWeapon->chargeCounter = 0x0;
                        SoundPlay(0x84);
                    }
                }
            }
            break;
        
        default:
            if ((gButtonInput & gButtonAssignments.armMissiles) != 0x0)
            {
                if (pWeapon->missilesSeleced == TRUE)
                {
                    if (pEquipment->currentMissiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weaponHighlighted == WH_NONE)
                        {
                            pWeapon->chargeCounter = 0x0;
                            SoundPlay(0x84);
                        }
                    }
                }
                else
                {
                    weapon_high = WH_SUPER_MISSILE;
                    if (pEquipment->currentMissiles != 0x0)
                    {
                        weapon_high = WH_MISSILE;
                        if (pWeapon->weaponHighlighted == WH_NONE)
                        {
                            pWeapon->chargeCounter = 0x0;
                            SoundPlay(0x84);
                        }
                    }
                }
            }
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
            if (pWeapon->weaponHighlighted != WH_NONE)
            {
                if (pWeapon->weaponHighlighted == WH_NONE)
                {
                    pWeapon->chargeCounter = 0x0;
                    SoundPlay(0x84);
                }
            }

    }

    pWeapon->weaponHighlighted = weapon_high;*/
}

void SamusSetSpinningPose(struct SamusData* pData, struct Equipment* pEquipment)
{
    u8 flag;

    switch (pData->pose)
    {
        case SPOSE_SPINNING:
            if (gSamusPhysics.slowedByLiquid != FALSE)
                break;

            if ((pEquipment->suitMiscActivation & SMF_SCREW_ATTACK) == 0x0)
            {
                if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP)
                    pData->pose = SPOSE_SPACE_JUMPING;
                break;
            }
            pData->pose = SPOSE_SCREW_ATTACKING;
            break;

        case SPOSE_SPACE_JUMPING:
            flag = pEquipment->suitMiscActivation & SMF_SCREW_ATTACK;
            if (flag != 0x0)
                pData->pose = SPOSE_SCREW_ATTACKING;
            else
            {
                if (pEquipment->suitMiscActivation & SMF_SPACE_JUMP && !gSamusPhysics.slowedByLiquid)
                    break;
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = flag;
            }
            break;

        case SPOSE_SCREW_ATTACKING:
            if (gSamusPhysics.slowedByLiquid != FALSE)
            {
                pData->pose = SPOSE_SPINNING;
                pData->currentAnimationFrame = 0x0;
            }
            else
            {
                if ((pEquipment->suitMiscActivation & SMF_SCREW_ATTACK) == 0x0)
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

void SamusApplyXAcceleration(i16 acceleration, i16 velocity, struct SamusData* pData)
{

}

u8 SamusTakeHazardDamage(struct SamusData* pData, struct Equipment* pEquipment, struct HazardDamage* pHazard)
{

}

void SamusCheckShinesparking(struct SamusData* pData)
{
    /*u8 pose;

    pose = pData->pose;

    switch (pose)
    {
        case SPOSE_SHINESPARKING:
            pData->speedboostingShinesparking = TRUE;
            break;
        case SPOSE_BALLSPARKING:
            pData->speedboostingShinesparking = TRUE;
            break;
        default:
            if ((u16)(pData->xVelocity + 0x9F) >= 0x13F)
            {
                if (pData->speedboostingShinesparking != FALSE) return;
                if (pose != SPOSE_SKIDDING)
                {
                    pData->speedboostingShinesparking = TRUE;
                    SoundPlay(0x8B);
                }
                break;
            }
            else
            {
                if (pData->speedboostingShinesparking == FALSE)
                    SoundStop(0x8B);
                return;
            }

        case SPOSE_DYING:
            pData->speedboostingShinesparking = FALSE;
    }

    if (pData->speedboostingShinesparking == FALSE)
        SoundStop(0x8B);*/
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
    /*u8 new_pose;
    i32 xVelocity;

    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    xVelocity = gSamusPhysics.xVelocityCap;
    if ((gEquipment.suitMiscActivation & SMF_SPEEDBOOSTER) != 0x0 && gSamusPhysics.slowedByLiquid == FALSE)
    {
        if (pData->timer >= 0x8C)
            xVelocity = 0xA0;
        else
        {
            if (0x77 < pData->timer)
                xVelocity = 0x8C;
        }

        if ((u16)((u16)pData->xVelocity + 0x5F) >= 0xBF)
        {
            if (0x9F >= (u8)pData->timer)
                pData->timer++;
        }
    }
    else
        pData->timer = 0x0;


    if ((gButtonInput & pData->direction) != 0x0)
    {
        SamusApplyXAcceleration(gSamusPhysics.xAcceleration, xVelocity, pData);
        SamusAimCannon(pData);
        return SPOSE_NONE;
    }
    else
    {
        if (pData->speedboostingShinesparking != FALSE)
            return SPOSE_SKIDDING;
        else if (gSamusPhysics.hasNewProjectile != 0x0)
            return SPOSE_SHOOTING;
        else if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) == 0x0)
            return SPOSE_STANDING;
        else
            return SPOSE_TURNING_AROUND;
    }*/
}

u8 SamusRunningGFX(struct SamusData* pData)
{

}

u8 SamusStanding(struct SamusData* pData)
{

}

u8 SamusStandingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningAround(struct SamusData* pData)
{
    u8 new_pose;

    if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gChangedInput & KEY_A) != 0x0 && pData->shinesparkTimer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)samus_hitbox_data[0][2] - 0x20))  == 0x0)
    {
        pData->yPosition -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }
    else
    {
        if (SamusCheckAButtonPressed(pData)  != FALSE)
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        else
        {
            if ((gChangedInput & KEY_DOWN) != 0x0 && (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
            {
                pData->pose = SPOSE_TURNING_AROUND_AND_CROUCHING;
                if (gEquipment.suitType != SUIT_SUITLESS)
                    SoundPlay(0x79);
            }
            if (gSamusPhysics.hasNewProjectile != 0x0)
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
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            return SPOSE_RUNNING;
        else if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }

    return SPOSE_NONE;
}

u8 samus_shooting_gfx(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_STANDING;
    else
        return SPOSE_NONE;
}

u8 SamusCrouching(struct SamusData* pData)
{
    /*u8 unk;
    u16 xPosition;
    struct WeaponInfo* pWeapon;
    u16* input;
    u32 timer;

    if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gChangedInput & KEY_A) != 0x0 && pData->shinesparkTimer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)array_23a554[2] - 0x20))  == 0x0)
    {
        pData->yPosition -= 0x20;
        return SPOSE_DELAY_BEFORE_SHINESPARKING;
    }

    unk = SamusCheckCollisionAbove(pData, array_23a554[2]);
    if (unk == 0x1)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - (u16)array_23a554[0];
    else if (unk == 0x8)
        xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) - (u16)array_23a554[0] + 0x3F;

    if (SamusCheckAButtonPressed(pData)  != FALSE && (unk & 0x6) == 0x0)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->xPosition = xPosition;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if ((gChangedInput & KEY_UP) == 0x0 || (unk & 0x6) != 0x0 || gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_UP)
    {
        if (unk == 0x1 || unk == 0x8)
            pData->xPosition = xPosition;
        pData->lastWallTouchedMidAir = 0x6;
        
        if (gEquipment.suitType == SUIT_SUITLESS)
            return SPOSE_UNCROUCHING_SUITLESS;
        else
            return SPOSE_STANDING;
    }
    else
    {
        if ((gChangedInput & KEY_DOWN) != 0x0 && (gEquipment.suitMiscActivation & SMF_MORPH_BALL) != 0x0 && (gSamusWeaponInfo.diagonalAim == DIAG_AIM_NONE || pData->armCannonDirection == ACD_DIAGONALLY_DOWN))
        {
            SoundPlay(0x77);
            return SPOSE_MORPHING;
        }

        SamusAimCannon(pData);
        if (pData->armCannonDirection == ACD_UP)
            pData->armCannonDirection = ACD_FORWARD;

        if (gSamusPhysics.hasNewProjectile != PROJECTILE_NONE)
            return SPOSE_SHOOTING_AND_CROUCHING;
        
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            return SPOSE_TURNING_AROUND_AND_CROUCHING;

        if ((gButtonInput & pData->direction) != 0x0)
        {
            if ((unk & 0x6) == 0x0)
            {
                timer = pData->timer;
                pData->timer = timer + 1;
                if (0x5 < (u8)timer)
                {
                    if (unk == 0x1 || unk == 0x8)
                        pData->xPosition = xPosition;

                    if (gEquipment.suitType == SUIT_SUITLESS)
                        return SPOSE_UNCROUCHING_SUITLESS;
                    else
                        return SPOSE_STANDING; 
                }
            }
        }
        else
            pData->timer = 0x0;

        return SPOSE_NONE;
    }*/
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
            if ((gChangedInput & KEY_UP) != 0x0 && (unk & 0x6) == 0x0 && (gSamusWeaponInfo.diagonalAim == 0x0 || pData->armCannonDirection == ACD_DIAGONALLY_UP))
            {
                if (unk == 0x1 || unk == 0x8)
                    pData->xPosition = xPosition;
                pData->pose = SPOSE_TURNING_AROUND;

            }

            if (gSamusPhysics.hasNewProjectile != 0x0)
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

    if ((gChangedInput & KEY_A) != 0x0)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    
    if ((gButtonInput & pData->direction) != 0x0)
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

        if ((pData->direction & KEY_RIGHT) != 0x0)
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

}

u8 SamusMidAirGFX(struct SamusData* pData)
{
    u8 unk;

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

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
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
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        pData->forcedMovement = 0x2;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusStartingSpinJumpGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
    {
        pData->pose = SPOSE_SPINNING;
        pData->currentAnimationFrame = 0x0;
    }

    return SPOSE_NONE;
}

u8 SamusSpinning(struct SamusData* pData)
{
    /*i32 acceleration;
    u16 direction;
    u16* input;

    if (gSamusPhysics.hasNewProjectile != 0x0)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) == 0x0 && (gButtonInput & (KEY_UP | KEY_DOWN)) != 0x0)
        {
            pData->forcedMovement = 0x2;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
        {
            SamusAimCannon(pData);
            acceleration = gSamusPhysics.midairXAcceleration;
            if ((gEquipment.suitMiscActivation & SMF_SPACE_JUMP) != 0x0 && gSamusPhysics.slowedByLiquid == FALSE)
            {
                if ((gChangedInput & KEY_A) != 0x0 && pData->yVelocity <= -0x40)
                {
                    if ((gEquipment.suitMiscActivation & SMF_HIGH_JUMP) != 0x0)
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
                    if ((pData->direction & pData->lastWallTouchedMidAir) != 0x0)
                    {
                        if ((gChangedInput & KEY_A) != 0x0)
                        {
                            
                            if ((pData->lastWallTouchedMidAir & KEY_RIGHT) != 0x0)
                                acceleration = -0x28;
                            else
                                acceleration = 0x28;
                            
                            if ((ClipdataProcessForSamus(pData->yPosition, (u16)(pData->xPosition + acceleration)) & 0x1000000) != 0x0)
                            {
                                pData->direction = pData->lastWallTouchedMidAir;
                                return SPOSE_STARTING_WALL_JUMP;
                            }
                        }
                        acceleration = 0x1;
                    }
                }
            }

            input = &gButtonInput;
            direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
            if ((direction & *input) != 0x0)
            {
                pData->direction = direction;
                pData->xVelocity = 0x0;
            }
            else
                SamusApplyXAcceleration(acceleration, gSamusPhysics.midairXVelocityCap, pData);

            if ((gButtonInput & KEY_A) == 0x0 && 0x0 < pData->yVelocity)
                pData->yVelocity = 0x0;

            return SPOSE_NONE;
        }
    }*/
}

u8 SamusSpinningGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid);
    if (unk == 0x2)
        pData->currentAnimationFrame = 0x0;

    if (*(u16*)&pData->animationDurationCounter == 0x1)
    {
        if (gSamusPhysics.slowedByLiquid != FALSE)
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
    u16 input;

    if (gSamusPhysics.hasNewProjectile != 0x0)
    {
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else 
    {
        input = gButtonInput & (KEY_RIGHT | KEY_LEFT);
        if (input == 0x0 && (gButtonInput & (KEY_UP | KEY_DOWN)) != 0x0)
        {
            pData->forcedMovement = input;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        else
            return SPOSE_NONE;
    }
}

u8 SamusStartingWallJumpGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
        return SPOSE_NONE;
}

u8 SamusSpaceJumpingGFX(struct SamusData* pData)
{
    u8 unk;

    if (*(u16*)&pData->animationDurationCounter == 0x1)
    {
        if (gSamusPhysics.slowedByLiquid != FALSE)
            SoundPlay(0x6B);
        else
            SoundPlay(0x6B);
    }

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid);
    if (unk == 0x2)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

u8 SamusCrewAttackingGFX(struct SamusData* pData)
{

}

u8 SamusMorphing(struct SamusData* pData)
{
    if ((gChangedInput & KEY_UP) != 0x0)
        pData->pose = SPOSE_UNMORPHING;

    return SPOSE_NONE;
}

u8 SamusMorphingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_MORPH_BALL;
    else
        return SPOSE_NONE;
}

u8 SamusMorphball(struct SamusData* pData)
{
    /*u8 forcedMovement;

    forcedMovement = pData->forcedMovement;
    if (0x15 < forcedMovement)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (forcedMovement >= 0x14)
        pData->forcedMovement = forcedMovement + 0x1;
    else
    {
        if ((gChangedInput & KEY_A) != 0x0 && (gEquipment.suitMiscActivation & SMF_HIGH_JUMP) != 0x0 & pData->shinesparkTimer != 0x0 && SamusCheckCollisionAbove(pData, (i16)((u16)array_23a554[5] - 0x40))  == 0x0)
        {
            pData->yPosition -= 0x20;
            return SPOSE_DELAY_BEFORE_BALLSPARKING;
        }

        if (SamusCheckAButtonPressed(pData)  != FALSE)
        {
            if (pData->forcedMovement != 0x1)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            if ((gEquipment.suitMiscActivation & SMF_HIGH_JUMP) != 0x0)
                return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;

            pData->forcedMovement = 0x0;
        }

        if ((gButtonInput & (KEY_RIGHT | KEY_LEFT)) != 0x0)
        {
            pData->direction = gButtonInput & (KEY_RIGHT | KEY_LEFT);
            return SPOSE_ROLLING;
        }

        if ((gChangedInput & KEY_UP) != 0x0)
        {
            forcedMovement = SamusCheckCollisionAbove(pData, array_23a554[2]);
            if (forcedMovement == 0x1)
            {
                pData->xPosition = (u16)(pData->xPosition + array_23a554[0] & BLOCK_POSITION_FLAG) - array_23a554[0] + 0x40;
                gPreviousXPosition = pData->xPosition;

                if (gSamusPhysics.slowedByLiquid != FALSE)
                    SoundPlay(0x78);
                else
                    SoundPlay(0x78);

                return SPOSE_UNMORPHING;
            }

            if (forcedMovement == 0x8)
            {
                pData->xPosition = (u16)(pData->xPosition + array_23a554[0] & BLOCK_POSITION_FLAG) - array_23a554[0] + 0x40;
                gPreviousXPosition = pData->xPosition;
                forcedMovement = 0x0;
            }

            if (forcedMovement == 0x0)
            {
                if (gSamusPhysics.slowedByLiquid != FALSE)
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
    }

    return SPOSE_NONE;*/
}

u8 SamusRolling(struct SamusData* pData)
{
    /*i32 velocity;

    if ((gChangedInput & KEY_A) != 0x0 && (gEquipment.suitMiscActivation & SMF_HIGH_JUMP) != 0x0)
    {
        pData->forcedMovement = 0x1;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }
    else
    {
        if (SamusCheckCollisionAbove(pData, array_23a554[2])  == 0x0 && (gChangedInput & KEY_UP) != 0x0)
        {
            if (gSamusPhysics.slowedByLiquid != FALSE)
                SoundPlay(0x78);
            else
                SoundPlay(0x78);

            return SPOSE_UNMORPHING;
        }
        else
        {
            if ((gButtonInput & pData->direction) != 0x0)
            {
                velocity = gSamusPhysics.xVelocityCap;
                if (pData->speedboostingShinesparking != FALSE)
                {
                    velocity = 0xA0;
                    pData->shinesparkTimer = 0x6;
                }
                SamusApplyXAcceleration(gSamusPhysics.xAcceleration, velocity, pData);
                return SPOSE_NONE;
            }
            else
            {
                if ((((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) << 0x10) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_MORPH_BALL;
            }
        }
    }*/
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
    u8 unk;

    unk = SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2]);
    if (unk == 0x0)
    {
        if ((gChangedInput & KEY_A) != 0x0)
        {
            pData->forcedMovement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }
        if ((gChangedInput & KEY_DOWN) == 0x0)
            return SPOSE_NONE;
    }
    pData->pose = SPOSE_MORPHING;
    return SPOSE_NONE;
}

u8 SamusUnmorphingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        pData->unmorphPaletteTimer = 0xF;
        return SPOSE_CROUCHING;
    }
    return SPOSE_NONE;
}

u8 SamusMorphballMidAir(struct SamusData* pData)
{
    /*u16 direction;

    if ((gChangedInput & KEY_UP) != 0x0 && SamusCheckCollisionAbove(pData, array_23a554[2])  == 0x0)
    {
        if (gSamusPhysics.slowedByLiquid == TRUE)
            SoundPlay(0x78);
        else
            SoundPlay(0x78);
        
        pData->unmorphPaletteTimer = 0xF;
        return SPOSE_MIDAIR;
    }

    if (pData->forcedMovement == 0x0)
    {
        if ((gButtonInput & KEY_A) == 0x0 && 0x0 < pData->yVelocity)
            pData->yVelocity = 0x0;
    }
    else
    {
        if (pData->yVelocity < 0x7)
            pData->forcedMovement = 0x0;
    }

    if (pData->yVelocity >= 0x0 && (pData->xVelocity != 0x0 || (gButtonInput & pData->direction) != 0x0))
        SamusApplyXAcceleration(gSamusPhysics.midairXAcceleration, gSamusPhysics.midairMorphedXVelocityCap, pData);
    else
    {
        direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT);
        if ((direction & gButtonInput) != 0x0)
            pData->direction = direction;
        pData->xVelocity = 0x0;
    }

    return SPOSE_NONE;*/
}

u8 SamusHangingOnLedge(struct SamusData* pData)
{
    /*
    // /!\ Wrong code order
    u16 xPosition;
    u32 block_above;
    u32 block_above_offset;
    u8 acd;
    u8 forcedMovement;
    u16 direction;

    if (gScreenShakeX.timer > 0x1D)
    {
        // Release if screen shake active
        pData->forcedMovement = 0x0;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (pData->direction & KEY_RIGHT)
        xPosition = pData->xPosition + 0x20;
    else
        xPosition = pData->xPosition - 0x20;

    // Check blocks above samus, and with solid flag
    block_above_offset = ClipdataProcessForSamus(pData->yPosition - 0xD0, xPosition) & 0x1000000;
    block_above = ClipdataProcessForSamus(pData->yPosition - 0xD0, pData->xPosition) & 0x1000000;

    if (gChangedInput & KEY_A)
    {
        if (gButtonInput & pData->direction)
        {
            if (!block_above_offset && !block_above)
                return SPOSE_PULLING_YOURSELF_UP_FROM_HANGING;
            
            if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                return SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL;
        }

        direction = pData->direction ^ (KEY_RIGHT | KEY_LEFT); // Get opposite direction
        if (direction & gButtonInput)
        {
            pData->direction = direction;
            pData->forcedMovement = 0x1;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }

        if (gButtonInput & KEY_DOWN)
        {
            pData->forcedMovement = 0x0;
            return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
        }

        pData->forcedMovement = 0x2;
        pData->yVelocity = 0x90;
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    }

    if (gSamusPhysics.hasNewProjectile != 0x0)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        if (gButtonInput & KEY_DOWN)
            pData->armCannonDirection = ACD_DOWN;
        else
            pData->armCannonDirection = ACD_UP;

        return SPOSE_SHOOTING_WHILE_HANGING;
    }

    if (gEquipment.suitType != SUIT_SUITLESS && gSamusWeaponInfo.chargeCounter != 0x0)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        if (gButtonInput & KEY_DOWN)
            pData->armCannonDirection = ACD_DOWN;
        else
            pData->armCannonDirection = ACD_UP;
            
        return SPOSE_AIMING_WHILE_HANGING;
    }

    if (gButtonInput & gButtonAssignments.diagonalAim || gButtonInput & (KEY_UP | KEY_DOWN) || (pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT); // Set opposite direction
        return SPOSE_TURNING_TO_AIM_WHILE_HANGING;
    }

    return SPOSE_NONE;*/
}

u8 SamusHangingOnLedgeGFX(struct SamusData* pData)
{
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
        pData->currentAnimationFrame = 0x0;

    return SPOSE_NONE;
}

u8 SamusTurningToAimWhileHanging(struct SamusData* pData)
{

}

u8 SamusTurningToAimWhileHangingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid);
    if (unk == 0x2)
        return SPOSE_AIMING_WHILE_HANGING;
    else
        return SPOSE_NONE;
}

u8 SamusHidingArmCannonWhileHangingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, gSamusPhysics.slowedByLiquid);
    if (unk == 0x2)
    {
        pData->direction ^= (KEY_RIGHT | KEY_LEFT);
        return SPOSE_HANGING_ON_LEDGE;
    }
    else
        return SPOSE_NONE;
}

u8 SamusAimingWhileHanging(struct SamusData* pData)
{

}

u8 SamusPullingSelfUp(struct SamusData* pData)
{
    u16 offset;

    offset = SamusPullingSelfUp_velocity[pData->currentAnimationFrame];
    if (pData->timer != 0x0)
        offset >>= 0x1;

    pData->yPosition -= offset;
    return SPOSE_NONE;
}

u8 SamusPullingSelfUpGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, pData->timer);
    if (unk == 0x2)
    {
        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - 0x1;
        return SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusPullingSelfForward(struct SamusData* pData)
{
    if ((pData->direction & KEY_RIGHT) != 0x0)
        pData->xPosition += 0x4;
    else
        pData->xPosition -= 0x4;

    return SPOSE_NONE;
}

u8 SamusPullingSelfForwardGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);

    if (unk == 0x2)
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
    u8 unk;

    unk = SamusUpdateAnimation(pData, pData->timer);
    if (unk == 0x2)
    {
        if ((pData->direction & KEY_RIGHT) != 0x0)
            pData->xPosition += 0x6;
        else
            pData->xPosition -= 0x6;

        pData->yPosition = (pData->yPosition & BLOCK_POSITION_FLAG) - 0x1;
        play_sound(0x77);
        return SPOSE_MORPH_BALL;
    }
    else
        return SPOSE_NONE;
}

u8 SamusUsingAnElevator(struct SamusData* pData)
{
    // https://decomp.me/scratch/ZYuqG
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
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
            pData->turning = TRUE;
        return SPOSE_SHINESPARKING;
    }
    else
        return SPOSE_NONE;
}

u8 SamusShinesparking(struct SamusData* pData)
{

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
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else
        return SPOSE_NONE;
}

u8 SamusDelayBeforeBallsparking(struct SamusData* pData)
{

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

    if ((gChangedInput & KEY_A) != 0x0)
        return SPOSE_UPDATE_JUMP_VELOCITY_REQUEST;
    else if (gSamusPhysics.hasNewProjectile != 0x0)
        return SPOSE_SHOOTING_ON_ZIPLINE;
    else if (pData->pose != SPOSE_ON_ZIPLINE)
        return SPOSE_NONE;
    else
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) == 0x0)
        {
            SamusAimCannon(pData);
            return SPOSE_NONE;
        }
        return SPOSE_TURNING_ON_ZIPLINE;
    }
}

u8 SamusShootingOnZiplineGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_ON_ZIPLINE;
    else
        return SPOSE_NONE;
}

u8 SamusMorphballOnZipline(struct SamusData* pData)
{
    u16 direction;

    if ((gChangedInput & KEY_A) != 0x0)
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

u8 SamusTurningAround_to_download_map_data_gfx(struct SamusData* pData)
{
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, FALSE);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_DOWNLOADING_MAP_DATA; // Set downloading if turning around ended
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
    u8 anim_state;

    anim_state = SamusUpdateAnimation(pData, FALSE);
    if (anim_state == SAMUS_ANIM_STATE_ENDED)
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

u8 SamusDying(struct SamusData* pData)
{

}

u8 SamusCrouchingToCrawlGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        if ((pData->direction & KEY_RIGHT) != 0x0)
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
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2])  == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else if (gSamusPhysics.hasNewProjectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else if ((gButtonInput & pData->direction) != 0x0)
        return SPOSE_CRAWLING;
    else if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) == 0x0)
        return SPOSE_NONE;
    else
        return SPOSE_TURNING_AROUND_WHILE_CRAWLING;
}

u8 SamusStartingToCrawlGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_CRAWLING_STOPPED;
    else
        return SPOSE_NONE;
}

u8 SamusCrawling(struct SamusData* pData)
{
    if (SamusCheckCollisionAbove(pData, samus_hitbox_data[0][2])  == 0x0)
        return SPOSE_UNCROUCHING_FROM_CRAWLING;
    else
    {
        if (gSamusPhysics.hasNewProjectile != 0x0)
            return SPOSE_SHOOTING_WHILE_CRAWLING;
        else
        {
            if ((gButtonInput & pData->direction) != 0x0)
            {
                SamusApplyXAcceleration(gSamusPhysics.xAcceleration, 0x20, pData);
                return SPOSE_NONE;
            }
            else
            {
                if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput) != 0x0)
                    pData->turning = TRUE;

                return SPOSE_CRAWLING_STOPPED;
            }
        }
    }
}

u8 SamusDyingGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        pData->currentAnimationFrame = 0x0;
    else if (unk == 0x1 && (pData->currentAnimationFrame == 0x1 || pData->currentAnimationFrame == 0x4))
        SamusCheckSetEnvironmentalEffect(pData, 0x0, WANTING_RUNNING_ON_WET_GROUND);

    if (*(u16*)&pData->animationDurationCounter == 0x1)
        SoundPlay(0x9E);

    return SPOSE_NONE;
}

u8 SamusTurningAroundWhileCrawling(struct SamusData* pData)
{
    if (gSamusPhysics.hasNewProjectile != 0x0)
        return SPOSE_SHOOTING_WHILE_CRAWLING;
    else
        return SPOSE_NONE;
}

u8 SamusCrawlingGFX(struct SamusData* pData)
{
    u8 animState;

    animState = SamusUpdateAnimation(pData, FALSE);
    if (animState == SAMUS_ANIM_STATE_ENDED)
        return SPOSE_STARTING_TO_CRAWL;
    else
        return SPOSE_NONE;
}

u8 SamusGrabbingALedgeSuitlessGFX(struct SamusData* pData)
{
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
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
    u8 unk;
    u16* input;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
    {
        input = &gButtonInput;
        if (((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & *input) != 0x0)
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
    u8 unk;

    unk = SamusUpdateAnimation(pData, FALSE);
    if (unk == 0x2)
        return SPOSE_IN_ESCAPE_SHIP;
    else
        return SP_NONE;
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
            if ((timer & 0xF) == 0x4)
                play_sound(0x8D);
            pData->shinesparkTimer--;
        }
        if (pEquipment->suitType != SUIT_SUITLESS)
            SamusSetHighlightedWeapon(pData, pWeapon, pEquipment);

        SamusSetSpinningPose(pData, pEquipment);
        samus_spawn_newProjectile(pData, pWeapon, pEquipment);
        samus_pose_functions_pointers[pData->pose](pData);
        if (pose == SPOSE_NONE)
            samus_pose_gfx_functions_pointers[pData->pose](pData);
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
