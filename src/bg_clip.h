#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

struct background_pointers_and_dimensions {
    struct sub_bg_ptr {
        u16* decompressed;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* clipdata_decompressed;
    u16 clipdata_width;
    u16 clipdata_height;
};

void bg_clip_mother_brain_update_glass(u8 unk, u16 unk2, u16 unk3, u16 unk4);
void bg_clip_set_bg1_block_value(u16 value, u16 y_position, u16 x_position);
void bg_clip_set_raw_bg1_block_value(u16 value, u16 y_position, u16 x_position);
void bg_clip_set_clipdata_block_value(u16 value, u16 y_position, u16 x_position);
void bg_clip_check_touching_special_clipdata(void);
void bg_clip_apply_clipdata_changing_transparency(void);
u16 bg_clip_get_new_bldalpha_value(u16 clip);
void bg_clip_check_walking_on_crumble_block(void);
void bg_clip_check_touching_transition_on_elevator(void);
void bg_clip_check_touching_transition_or_tank(void);
void bg_clip_finish_collecting_tank(void);
void bg_clip_finish_collecting_ability(void);
void bg_clip_check_grabbing_crumble_block(u8 false);
u8 bg_clip_check_opening_hatch(u16 x_position, u16 y_position);
void bg_clip_set_item_as_collected(u8 x_position, u8 y_position, u8 type);
void bg_clip_remove_collected_tanks(void);
void bg_clip_call_mother_brain_update_glass(u8 stage);

#endif /* BG_CLIP_H */