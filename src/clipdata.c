#include "clipdata.h"
#include "globals.h"

void clipdate_setup_code(void)
{

}

/**
 * @brief Gets information on the clipdata block at the position in parameters, only used for samus
 * 
 * @param y_position Y position (in sub-pixels)
 * @param x_position X position (in sub-pixels)
 * @return u32 Collision result
 */
u32 clipdata_process_for_samus(u16 y_position, u16 x_position)
{
    struct CollisionData collision;
    u32 result;

    // Get tile position
    collision.tile_y = y_position >> 0x6;
    collision.tile_x = x_position >> 0x6;

    if (collision.tile_x >= bg_pointers_and_dimensions.clipdata_width)
        result = CLIPDATA_TYPE_SOLID_FLAG | CLIPDATA_TYPE_SOLID;
    else
    {        
        if (collision.tile_y < bg_pointers_and_dimensions.clipdata_height)
        {
            // Get clip type at position
            collision.clipdata_type = tilemap_and_clip_pointers.clip_collisions[bg_pointers_and_dimensions.clipdata_decompressed[bg_pointers_and_dimensions.clipdata_width * collision.tile_y + collision.tile_x]];
            // Get sub pixel
            collision.sub_pixel_y = y_position & 0x3F;
            collision.sub_pixel_x = x_position & 0x3F;
            collision.actor_type = CLIPDATA_ACTOR_SAMUS;
            result = clipdata_code_pointer(&collision);
        }
        else
            result = CLIPDATA_TYPE_AIR;
    }

    return result;
}

u32 clipdata_process(u16 y_position, u16 x_position)
{

}

/**
 * @brief Returns the collision type for the current position
 * 
 * @param pCollision Pointer to a collision data structure
 * @return u32 Collision type (including solid flag)
 */
u32 clipdata_convert_to_collision(struct CollisionData* pCollision)
{
    u32 result;

    result = CLIPDATA_TYPE_AIR;

    switch (pCollision->clipdata_type)
    {
        case CLIPDATA_TYPE_SOLID:
            // No calculations needed, return type and add solid flag
            result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // The slope forms a rectangle triangle with the right angle being in the bottom left
            // For the subpixels coordinates, 0,0 is the top left, and 3F,3F the bottom right
            // So in order to determine whether it's colliding with the solid part or not, we simply check if Y > X
            if (pCollision->sub_pixel_y >= pCollision->sub_pixel_x)
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;
            
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, however since the slope is "flipped" in regards to the coordinates, we substract the X to 3F
            if (pCollision->sub_pixel_y >= 0x3F - pCollision->sub_pixel_x)
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, however the triangle hypotenuse is "larger" and extends on 2 block, with the angle being twice as big
            // Hence why the subpixel X is divided by 2, it's to compensate
            if (pCollision->sub_pixel_y >= pCollision->sub_pixel_x >> 1)
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic, we add 0x3F because it's the lower part of the slope
            if (pCollision->sub_pixel_y >= (pCollision->sub_pixel_x + 0x3F) >> 1)
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->sub_pixel_y >= 0x3F - (pCollision->sub_pixel_x >> 1))
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            // Checking if in the solid or air part of the slope
            // Same logic
            if (pCollision->sub_pixel_y >= (0x3F - pCollision->sub_pixel_x) >> 1)
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            else
                result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_AIR:
        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            // No calculations needed, return type
            result = pCollision->clipdata_type;
            break;

        case CLIPDATA_TYPE_ENEMY_ONLY:
            if (pCollision->actor_type > CLIPDATA_ACTOR_NON_SPRITE)
            {
                // Only for sprites
                pCollision->clipdata_type = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                // For non sprite
                pCollision->clipdata_type = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;

        case CLIPDATA_TYPE_DOOR:
            pCollision->clipdata_type = CLIPDATA_TYPE_SOLID;
            result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            break;

        case CLIPDATA_TYPE_STOP_ENEMY:
            if (pCollision->actor_type < CLIPDATA_ACTOR_SPRITE)
            {
                // For non sprite
                pCollision->clipdata_type = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                // For sprite
                pCollision->clipdata_type = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;

        case CLIPDATA_TYPE_TANK:
            if (pCollision->actor_type == CLIPDATA_ACTOR_SAMUS)
            {
                pCollision->clipdata_type = CLIPDATA_TYPE_AIR;
                result = CLIPDATA_TYPE_AIR;
            }
            else
            {
                pCollision->clipdata_type = CLIPDATA_TYPE_SOLID;
                result = pCollision->clipdata_type | CLIPDATA_TYPE_SOLID_FLAG;
            }
            break;
    }

    return result;
}

struct CurrentAffectingClip clipdata_check_current_affecting_at_position(u16 y_position, u16 x_position)
{

}

struct CurrentAffectingClip clipdata_check_current_affecting_hazard_and_very_special_clidpata(u16 y_position, u16 tile_y, u16 tile_x, u8 unk)
{

}

u8 clidpata_check_cant_use_elevator(void)
{

}

u32 clipdata_check_ground_effect(u16 y_position, u16 x_position)
{

}