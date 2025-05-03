#include "gba.h"
#include "clipdata.h"
#include "macros.h"
#include "block.h"
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
    DMA_SET(3, ClipdataConvertToCollision + 1, gNonGameplayRam.inGame, C_32_2_16(DMA_ENABLE, 0x140));

    // Set pointer
    gClipdataCodePointer = (ClipFunc_T)(gNonGameplayRam.inGame + 1);
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
    collision.tileY = SUB_PIXEL_TO_BLOCK(yPosition);
    collision.tileX = SUB_PIXEL_TO_BLOCK(xPosition);

    if (collision.tileX >= gBgPointersAndDimensions.clipdataWidth)
    {
        result = CLIPDATA_TYPE_SOLID_FLAG | CLIPDATA_TYPE_SOLID;
    }
    else
    {        
        if (collision.tileY < gBgPointersAndDimensions.clipdataHeight)
        {
            // Get clip type at position
            collision.clipdataType = gTilemapAndClipPointers.pClipCollisions[gBgPointersAndDimensions.pClipDecomp[
                gBgPointersAndDimensions.clipdataWidth * collision.tileY + collision.tileX]];

            // Get sub pixel
            collision.subPixelY = yPosition % BLOCK_SIZE;
            collision.subPixelX = xPosition % BLOCK_SIZE;
            collision.actorType = CLIPDATA_ACTOR_SAMUS;

            // Call convert function
            result = gClipdataCodePointer(&collision);
        }
        else
        {
            result = CLIPDATA_TYPE_AIR;
        }
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

    // Get tile position
    collision.tileY = SUB_PIXEL_TO_BLOCK(yPosition);
    collision.tileX = SUB_PIXEL_TO_BLOCK(xPosition);

    // Check in bounds
    if (collision.tileX >= gBgPointersAndDimensions.clipdataWidth || collision.tileY >= gBgPointersAndDimensions.clipdataHeight)
    {
        // Clear if out of bounds
        gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
        gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;
        gCurrentClipdataAffectingAction = CAA_NONE;
        return CLIPDATA_TYPE_AIR;
    }

    if (gCurrentClipdataAffectingAction == CAA_NONE)
    {
        // No Ccaa, then update current affecting
        collision.actorType = CLIPDATA_ACTOR_SPRITE;
        gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
        gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;
        ClipdataUpdateCurrentAffecting(yPosition, collision.tileY, collision.tileX, 0x2);
    }
    else if (gCurrentClipdataAffectingAction >= CAA_UNUSED)
    {
        // "Destructing" Ccaa (projectiles, samus, bomb chain), then it's a non sprite
        collision.actorType = CLIPDATA_ACTOR_NON_SPRITE;
        if (gCurrentClipdataAffectingAction == CAA_UNUSED)
            gCurrentClipdataAffectingAction = CAA_NONE;
    }
    else
    {
        collision.actorType = CLIPDATA_ACTOR_SPRITE;
    }

    // Get clip at position
    clipdata = gBgPointersAndDimensions.pClipDecomp[collision.tileY * gBgPointersAndDimensions.clipdataWidth + collision.tileX];
    if (gCurrentClipdataAffectingAction != CAA_NONE)
    {
        // Apply Ccaa if not none
        BlockApplyCcaa(collision.tileY, collision.tileX, clipdata);
        gCurrentClipdataAffectingAction = CAA_NONE;
    }

    // Get type and sub pixel, then call clipdata code
    collision.clipdataType = gTilemapAndClipPointers.pClipCollisions[clipdata];
    collision.subPixelY = yPosition % BLOCK_SIZE;
    collision.subPixelX = xPosition % BLOCK_SIZE;
    return clipdata = gClipdataCodePointer(&collision);
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
            if (pCollision->subPixelY >= SUB_PIXEL_POSITION_FLAG - pCollision->subPixelX)
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
            if (pCollision->subPixelY >= (pCollision->subPixelX + SUB_PIXEL_POSITION_FLAG) >> 1)
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->subPixelY >= SUB_PIXEL_POSITION_FLAG - (pCollision->subPixelX >> 1))
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdataType;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->subPixelY >= (SUB_PIXEL_POSITION_FLAG - pCollision->subPixelX) >> 1)
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
                // For samus
                pCollision->clipdataType = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                // For non samus
                pCollision->clipdataType = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdataType | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;
        
        default:
            break;
    }

    return result;
}

/**
 * @brief 58080 | 40 | Checks for the current affecting clipdata (movement and hazard) at the position
 * 
 * @param yPosition Y Position (subpixels)
 * @param xPosition X Position (subpixels)
 * @return u32 Affecting clipdata (movement << 16 | hazard)
 */
s32 ClipdataCheckCurrentAffectingAtPosition(u16 yPosition, u16 xPosition)
{
    u16 tileY;
    u16 tileX;

    // Reset
    gCurrentAffectingClipdata.movement = CLIPDATA_MOVEMENT_NONE;
    gCurrentAffectingClipdata.hazard = HAZARD_TYPE_NONE;

    // Get tile position
    tileY = SUB_PIXEL_TO_BLOCK(yPosition);
    tileX = SUB_PIXEL_TO_BLOCK(xPosition);

    if (tileY >= gBgPointersAndDimensions.clipdataHeight || tileX >= gBgPointersAndDimensions.clipdataWidth)
        return C_32_2_16(CLIPDATA_MOVEMENT_NONE, HAZARD_TYPE_NONE);

    return ClipdataUpdateCurrentAffecting(yPosition, tileY, tileX, FALSE);
}

/**
 * @brief 580c0 | dc | Checks for the current affecting clipdata
 * 
 * @param yPosition Y position
 * @param tileY Tile Y position
 * @param tileX Tile X position
 * @param dontCheckForElevator Don't check for elevator flag
 * @return u32 Affecting clipdata (movement << 16 | hazard)
 */
u32 ClipdataUpdateCurrentAffecting(u16 yPosition, u16 tileY, u16 tileX, u8 dontCheckForElevator)
{
    u32 behavior;
    u32 specialClip;

    // Get clipdata behavior of the current tile
    behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[
        tileY * gBgPointersAndDimensions.clipdataWidth + tileX]];

    // Check for movement clipdata
    if (behavior != CLIP_BEHAVIOR_NONE)
    {
        if ((s32)behavior < ARRAY_SIZE(sMovementClipdataValues))
            specialClip = sMovementClipdataValues[behavior];
        else
            specialClip = CLIPDATA_MOVEMENT_NONE;
    }
    else
    {
        specialClip = CLIPDATA_MOVEMENT_NONE;
    }

    // Check prevent use elevator
    if (!dontCheckForElevator && (specialClip == CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK || specialClip == CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK)
        && gSamusData.pose != SPOSE_USING_AN_ELEVATOR && ClipdataCheckCantUseElevator(specialClip))
    {
        specialClip = CLIPDATA_MOVEMENT_NONE;
    }

    gCurrentAffectingClipdata.movement = specialClip;
    specialClip = HAZARD_TYPE_NONE;

    // Check for hazard behavior (tile based)
    if ((u32)BEHAVIOR_TO_HAZARD(behavior) <= BEHAVIOR_TO_HAZARD(CLIP_BEHAVIOR_ACID))
    {
        // Directly get from the table
        specialClip = sHazardClipdataValues[BEHAVIOR_TO_HAZARD(behavior)];
    }
    else
    {
        // Check for hazard behavior (effect based)
        if (gCurrentRoomEntry.Bg0Prop != 0 && gCurrentRoomEntry.damageEffect != 0)
        {
            if (gCurrentRoomEntry.damageEffect < ARRAY_SIZE(sHazardsDefinitions))
            {
                // Check has an hazard below the effect
                if (sHazardsDefinitions[gCurrentRoomEntry.damageEffect][1] == HAZARD_TYPE_NONE)
                {
                    // No hazard below, return the one above
                    specialClip = sHazardsDefinitions[gCurrentRoomEntry.damageEffect][0];
                }
                else
                {
                    // Get above or below hazard based on position
                    if (gEffectYPosition <= yPosition)
                        specialClip = sHazardsDefinitions[gCurrentRoomEntry.damageEffect][1];
                    else
                        specialClip = sHazardsDefinitions[gCurrentRoomEntry.damageEffect][0];
                }
            }
        }
    }

    gCurrentAffectingClipdata.hazard = specialClip;

    // Return formatted clipdata
    return C_32_2_16(gCurrentAffectingClipdata.movement, gCurrentAffectingClipdata.hazard);
}

/**
 * @brief 5819c | c4 | Checks if Samus can or can't use the current elevator
 * 
 * @param movementClip Movement clipdata (unused)
 * @return u32 TRUE if can't use, FALSE otherwise
 */
u32 ClipdataCheckCantUseElevator(u32 movementClip)
{
    s32 direction;
    s32 i;

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
 * @return s32 Ground Effect Clipdata
 */
u32 ClipdataCheckGroundEffect(u16 yPosition, u16 xPosition)
{
    s32 tileY;
    s32 tileX;
    u32 clipdata;

    tileY = SUB_PIXEL_TO_BLOCK(yPosition);
    tileX = SUB_PIXEL_TO_BLOCK(xPosition);

    if (tileY >= gBgPointersAndDimensions.clipdataHeight || tileX >= gBgPointersAndDimensions.clipdataWidth)
        return GROUND_EFFECT_NONE;

    clipdata = gBgPointersAndDimensions.pClipDecomp[tileY * gBgPointersAndDimensions.clipdataWidth + tileX];
    if (clipdata & CLIPDATA_TILEMAP_FLAG)
        clipdata = CLIP_BEHAVIOR_NONE;
    else
        clipdata = gTilemapAndClipPointers.pClipBehaviors[clipdata];

    if (BEHAVIOR_TO_GROUND_EFFECT(clipdata) < BEHAVIOR_TO_GROUND_EFFECT(CLIP_BEHAVIOR_GROUND_EFFECT_UNUSED1))
        clipdata = sGroundEffectsClipdataValues[BEHAVIOR_TO_GROUND_EFFECT(clipdata)];
    else
        clipdata = GROUND_EFFECT_NONE;
    
    return clipdata;
}
