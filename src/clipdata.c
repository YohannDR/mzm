#include "gba.h"
#include "clipdata.h"
#include "macros.h"
#include "temp_globals.h"

#include "data/clipdata_data.h"

#include "constants/clipdata.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/room.h"
#include "structs/samus.h"

/**
 * @brief 57dcc | 2c | Transfers the clipdata code to RAM and sets the pointer to it
 * 
 */
void ClipdataSetupCode(void)
{
    // Copy code to RAM
    dma_set(3, ClipdataConvertToCollision + 1, gNonGameplayRAM.inGame, (DMA_ENABLE << 0x10) | 0x140);
    // Set pointer
    gClipdataCodePointer = (ClipFunc_T)(gNonGameplayRAM.inGame + 1);
}

/**
 * @brief Gets information on the clipdata block at the position in parameters, only used for samus
 * 
 * @param yPosition Y position (in sub-pixels)
 * @param xPosition X position (in sub-pixels)
 * @return u32 Clipdata type (including solid flag)
 */
u32 ClipdataProcessForSamus(u16 yPosition, u16 xPosition)
{
    struct CollisionData collision;
    u32 result;

    // Get tile position
    collision.tileY = yPosition >> 0x6;
    collision.tileX = xPosition >> 0x6;

    if (collision.tileX >= gBGPointersAndDimensions.clipdataWidth)
        result = CLIPDATA_TYPE_SOLID_FLAG | CLIPDATA_TYPE_SOLID;
    else
    {        
        if (collision.tileY < gBGPointersAndDimensions.clipdataHeight)
        {
            // Get clip type at position
            collision.clipdataType = gTilemapAndClipPointers.pClipCollisions[gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * collision.tileY + collision.tileX]];
            // Get sub pixel
            collision.subPixelY = yPosition & SUB_PIXEL_POSITION_FLAG;
            collision.subPixelX = xPosition & SUB_PIXEL_POSITION_FLAG;
            collision.actorType = CLIPDATA_ACTOR_SAMUS;
            result = gClipdataCodePointer(&collision);
        }
        else
            result = CLIPDATA_TYPE_AIR;
    }

    return result;
}

/**
 * @brief 57e7c | 100 | Processes the clipdata at the position (hazard, movement, destruction, modification...) and gets the type of said clipdata
 * 
 * @param yPosition Y Position (subpixels)
 * @param xPosition X Position (subpixels)
 * @return u32 Clipdata type (including solid flag)
 */
u32 ClipdataProcess(u16 yPosition, u16 xPosition)
{
    struct CollisionData collision;
    u32 clipdata;

    collision.tileY = yPosition >> 6;
    collision.tileX = xPosition >> 6;

    // Check in bounds
    if (collision.tileX >= gBGPointersAndDimensions.clipdataWidth || collision.tileY >= gBGPointersAndDimensions.clipdataHeight)
    {
        // Clear if out of bounds
        gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
        gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;
        gCurrentClipdataAffectingAction = CAA_NONE;
        return CLIPDATA_TYPE_AIR;
    }
    else
    {
        if (gCurrentClipdataAffectingAction == CAA_NONE)
        {
            // No CCAA, then update current affecting
            collision.actorType = CLIPDATA_ACTOR_SPRITE;
            gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
            gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;
            ClipdataUpdateCurrentAffecting(yPosition, collision.tileY, collision.tileX, 0x2);
        }
        else if (gCurrentClipdataAffectingAction >= CAA_UNUSED)
        {
            // "Destructing" CCAA (projectiles, samus, bomb chain), then it's a non sprite
            collision.actorType = CLIPDATA_ACTOR_NON_SPRITE;
            if (gCurrentClipdataAffectingAction == CAA_UNUSED)
                gCurrentClipdataAffectingAction = CAA_NONE;
        }
        else
            collision.actorType = CLIPDATA_ACTOR_SPRITE;

        // Get clip at position
        clipdata = gBGPointersAndDimensions.pClipDecomp[collision.tileY * gBGPointersAndDimensions.clipdataWidth + collision.tileX];
        if (gCurrentClipdataAffectingAction != CAA_NONE)
        {
            // Apply CCAA if not none
            BlockApplyCCAA(collision.tileY, collision.tileX, clipdata);
            gCurrentClipdataAffectingAction = CAA_NONE;
        }

        // Get type and sub pixel, then call clipdata code
        collision.clipdataType = gTilemapAndClipPointers.pClipCollisions[clipdata];
        collision.subPixelY = yPosition & SUB_PIXEL_POSITION_FLAG;
        collision.subPixelX = xPosition & SUB_PIXEL_POSITION_FLAG;
        return clipdata = gClipdataCodePointer(&collision);
    }
}

/**
 * @brief 57f7c | 104 | Returns the collision type for the current position
 * 
 * @param pCollision Pointer to a collision data structure
 * @return u32 Clipdata type (including solid flag)
 */
u32 ClipdataConvertToCollision(struct CollisionData* pCollision)
{
    u32 result;

    result = CLIPDATA_TYPE_AIR;

    switch (pCollision->clipdataType)
    {
        case CLIPDATA_TYPE_SOLID:
            // No calculations needed, return type and add solid flag
            result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // The slope forms a rectangle triangle with the right angle being in the bottom left
            // For the subpixels coordinates, 0,0 is the top left, and 3F,3F the bottom right
            // So in order to determine whether it's colliding with the solid part or not, we simply check if Y > X
            if (pCollision->subPixelY >= pCollision->subPixelX)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;
            
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, however since the slope is "flipped" in regards to the coordinates, we substract the X to 3F
            if (pCollision->subPixelY >= 0x3F - pCollision->subPixelX)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, however the triangle hypotenuse is "larger" and extends on 2 block, with the angle being twice as big
            // Hence why the subpixel X is divided by 2, it's to compensate
            if (pCollision->subPixelY >= pCollision->subPixelX >> 1)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, we add 0x3F because it's the lower part of the slope
            if (pCollision->subPixelY >= (pCollision->subPixelX + 0x3F) >> 1)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->subPixelY >= 0x3F - (pCollision->subPixelX >> 1))
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->subPixelY >= (0x3F - pCollision->subPixelX) >> 1)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_AIR:
        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            // No calculations needed, return type
            result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_ENEMY_ONLY:
            if (pCollision->actorType > CLIPDATA_ACTOR_NON_SPRITE)
            {
                // Only for sprites
                pCollision->clipdataType = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                // For non sprite
                pCollision->clipdataType = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;

        case CLIPDATA_TYPE_DOOR:
            pCollision->clipdataType = CLIPDATA_TYPE_SOLID;
            result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            break;

        case CLIPDATA_TYPE_STOP_ENEMY:
            if (pCollision->actorType < CLIPDATA_ACTOR_SPRITE)
            {
                // For non sprite
                pCollision->clipdataType = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                // For sprite
                pCollision->clipdataType = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;

        case CLIPDATA_TYPE_TANK:
            if (pCollision->actorType == CLIPDATA_ACTOR_SAMUS)
            {
                pCollision->clipdataType = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                pCollision->clipdataType = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;
    }

    return result;
}

/**
 * @brief 58080 | 40 | Checks for the current affecting clipdata (movement and hazard) at the position
 * 
 * @param yPosition Y Position (subpixels)
 * @param xPosition X Position (subpixels)
 * @return i32 Current affecting clipdata, first 16 bits are hazard, last 16 bits are movement
 */
u32 ClipdataCheckCurrentAffectingAtPosition(u16 yPosition, u16 xPosition)
{
    u16 tileY;
    u16 tileX;

    gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
    gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;

    tileY = yPosition >> 0x6;
    tileX = xPosition >> 0x6;

    if (tileY >= gBGPointersAndDimensions.clipdataHeight || tileX >= gBGPointersAndDimensions.clipdataWidth)
        return 0x0;
    else
        return ClipdataUpdateCurrentAffecting(yPosition, tileY, tileX, 0x0);
}

u32 ClipdataUpdateCurrentAffecting(u16 yPosition, u16 tileY, u16 tileX, u8 unk)
{
    // https://decomp.me/scratch/DEj3d

    u32 behavior;
    u32 specialClip;
    u32 hazardClip;
    u32 effect;

    behavior = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.pClipDecomp[tileY * gBGPointersAndDimensions.clipdataWidth + tileX]];

    if (behavior != CLIP_BEHAVIOR_NONE)
    {
        if ((i32)behavior <= 0xF)
            specialClip = sMovementClipdataValues[behavior];
        else
            specialClip = CLIPDATA_MOVEMENT_NONE;
    }
    else
        specialClip = CLIPDATA_MOVEMENT_NONE;

    if (!unk && (specialClip == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK || specialClip == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
        && gSamusData.pose != SPOSE_USING_AN_ELEVATOR && ClipdataCheckCantUseElevator(specialClip))
        specialClip = CLIPDATA_MOVEMENT_NONE;

    gCurrentAffectingClipdata.movement = specialClip;
    hazardClip = HAZARD_TYPE_NONE;

    if ((u32)BEHAVIOR_TO_HAZARD(behavior) <= BEHAVIOR_TO_HAZARD(CLIP_BEHAVIOR_ACID))
        hazardClip = sHazardClipdataValues[BEHAVIOR_TO_HAZARD(behavior)];
    else
    {
        if (gCurrentRoomEntry.BG0Prop != 0)
        {
            effect = gCurrentRoomEntry.damageEffect;
            if (effect != 0)
            {
                if (effect < 8)
                {
                    if (sHazardsDefinitions[effect][1] != HAZARD_TYPE_NONE)
                    {
                        if (gEffectYPosition <= yPosition)
                            hazardClip = sHazardsDefinitions[effect][1];
                    }
                    else
                        hazardClip = sHazardsDefinitions[effect][0];
                }
            }
        }
    }

    gCurrentAffectingClipdata.hazard = hazardClip;

    return gCurrentAffectingClipdata.movement << 16 | gCurrentAffectingClipdata.hazard;
}

/**
 * @brief 5819c | c4 | Checks if Samus can or can't use the current elevator
 * 
 * @param movementClip Movement clipdata (unused)
 * @return u32 TRUE if can't use, FALSE otherwise
 */
u32 ClipdataCheckCantUseElevator(u32 movementClip)
{
    i32 direction;
    i32 i;

    gLastElevatorUsed.route = ELEVATOR_ROUTE_NONE;
    gLastElevatorUsed.unused = 0;
    gLastElevatorUsed.direction = 0;

    direction = 0;
    
    for (i = 8; i > 0; i--)
    {
        // Get direction
        if (gCurrentArea == sElevatorRoomPairs[i].area1 && gCurrentRoom == sElevatorRoomPairs[i].room1)
            direction = ELEVATOR_DIRECTION_DOWN;
        else if (gCurrentArea == sElevatorRoomPairs[i].area2 && gCurrentRoom == sElevatorRoomPairs[i].room2)
            direction = ELEVATOR_DIRECTION_UP;

        if (direction)
        {
            // Check escaped zebes
            if (i == ELEVATOR_ROUTE_CRATERIA_TO_TOURIAN_2)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
                    i = ELEVATOR_ROUTE_CRATERIA_TO_TOURIAN;
                else
                    direction = 0;
            }
        }

        // Set last used
        if (direction)
        {
            gLastElevatorUsed.route = i;
            gLastElevatorUsed.direction = direction;
            break;
        }
    }

    // Return can/can't be used
    direction = direction == 0;
    return direction;
}

/**
 * @brief 58260 | 64 | Gets the ground effect clipdata at the position
 * 
 * @param yPosition Y Position (subpixels)
 * @param xPosition X Position (subpixels)
 * @return i32 Ground Effect Clipdata
 */
u32 ClipdataCheckGroundEffect(u16 yPosition, u16 xPosition)
{
    i32 tileY;
    i32 tileX;
    u32 clipdata;

    tileY = yPosition >> 0x6;
    tileX = xPosition >> 0x6;

    if (tileY >= gBGPointersAndDimensions.clipdataHeight || tileX >= gBGPointersAndDimensions.clipdataWidth)
        return GROUND_EFFECT_NONE;
    else
    {
        clipdata = gBGPointersAndDimensions.pClipDecomp[tileY * gBGPointersAndDimensions.clipdataWidth + tileX];
        if (clipdata & 0x400)
            clipdata = 0x0;
        else
            clipdata = gTilemapAndClipPointers.pClipBehaviors[clipdata];

        if (BEHAVIOR_TO_GROUND_EFFECT(clipdata) < BEHAVIOR_TO_GROUND_EFFECT(CLIP_BEHAVIOR_GROUND_EFFECT_UNUSED1))
            clipdata = sGroundEffectsClipdataValues[BEHAVIOR_TO_GROUND_EFFECT(clipdata)];
        else
            clipdata = GROUND_EFFECT_NONE;
        
        return clipdata;
    }
}
