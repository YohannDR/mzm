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
u32 process_clipdata_for_samus(u16 y_position, u16 x_position)
{
    struct CollisionData collision;
    u32 result;

    collision.tile_y = y_position >> 0x6;
    collision.tile_x = x_position >> 0x6;

    if (collision.tile_x >= bg_pointers_and_dimensions.clipdata_width)
        result = 0x1000001;
    else
    {        
        if (collision.tile_y < bg_pointers_and_dimensions.clipdata_height)
        {
            collision.clipdata_type = tilemap_and_clip_pointers.clip_collisions[bg_pointers_and_dimensions.clipdata_decompressed[bg_pointers_and_dimensions.clipdata_width * collision.tile_y + collision.tile_x]];
            collision.sub_pixel_y = y_position & 0x3F;
            collision.sub_pixel_x = x_position & 0x3F;
            collision.unk = 0x0;
            result = clipdata_code_pointer(&collision);
        }
        else
            result = 0x0;
    }

    return result;
}

u32 clipdata_related(u16 y_position, u16 x_position)
{

}

u32 unk_57f7c(struct CollisionData* pCollision)
{

}

struct CurrentAffectingClip clipdata_check_current_affecting_at_position(u16 y_position, u16 x_position)
{

}

struct CurrentAffectingClip clipdate_check_current_affecting_hazard_and_very_special_clidpata(u16 y_position, u16 tile_y, u16 tile_x, u8 unk)
{

}

u8 clidpata_check_cant_use_elevator(void)
{

}

u32 clipdata_check_ground_effect(u16 y_position, u16 x_position)
{

}