#include "bg_clip.h"
#include "globals.h"

void bg_clip_mother_brain_update_glass(u8 unk, u16 unk2, u16 unk3, u16 unk4)
{

}

void bg_clip_set_bg1_block_value(u16 value, u16 y_position, u16 x_position)
{

}

void bg_clip_set_raw_bg1_block_value(u16 value, u16 y_position, u16 x_position)
{
    bg_pointers_and_dimensions.backgrounds[0x1].decompressed[bg_pointers_and_dimensions.backgrounds[0x1].width * y_position + x_position] = value;
}

void bg_clip_set_clipdata_block_value(u16 value, u16 y_position, u16 x_position)
{
    bg_pointers_and_dimensions.clipdata_decompressed[bg_pointers_and_dimensions.clipdata_width * y_position + x_position] = value;
}

void bg_clip_check_touching_special_clipdata(void)
{

}

void bg_clip_apply_clipdata_changing_transparency(void)
{

}

u16 bg_clip_get_new_bldalpha_value(u16 clip)
{
    u16 bldalpha;
    u16 offset;

    offset = (u16)(clip - 0x44);
    if (offset < 0xB)
        return bldalpha_values_for_clipdata_345cc8[offset];
    else
    {
        bldalpha = 0x0;
        if (clip == 0x4F)
            return 0xFFFF;
    }
    return bldalpha;
}

void bg_clip_check_walking_on_crumble_block(void)
{

}

void bg_clip_check_touching_transition_on_elevator(void)
{

}

void bg_clip_check_touching_transition_or_tank(void)
{

}

void bg_clip_finish_collecting_tank(void)
{

}

void bg_clip_finish_collecting_ability(void)
{
    bg_clip_set_item_as_collected(samus_data.x_position >> 0x6, samus_data.y_position >> 0x6, 0x80);
    update_minimap_square_for_collected_items((u8)(samus_data.x_position >> 0x6), (u8)(samus_data.y_position >> 0x6))
}

void bg_clip_check_grabbing_crumble_block(u8 false)
{

}

u8 bg_clip_check_opening_hatch(u16 x_position, u16 y_position)
{

}

void bg_clip_set_item_as_collected(u8 x_position, u8 y_position, u8 type)
{

}

void bg_clip_remove_collected_tanks(void)
{

}

void bg_clip_call_mother_brain_update_glass(u8 stage)
{

}