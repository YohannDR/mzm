#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
#include "sprite.h"
#include "room.h"

// EWRAM

extern u32 events_triggered[8];

// IWRAM

extern u8 softreset_disabled;
extern u8 current_area;
extern u8 current_room;
extern u16 effect_y_position;
extern u8 spriteset;
extern u8 spriteset_entry_used;
extern struct room_entry current_room_entry;
extern struct raw_coords_x waiting_space_pirates_position;
extern u16 alarm_timer;
extern struct sprite_data sprite_data[24];
extern enum s_sprite_id spriteset_sprite_id[15];
extern u8 spriteset_sprite_gfx_slots[15];
extern u8 parasite_related;
extern struct sprite_debris sprite_debris[8];
extern u8 previous_vertical_collision_check;
extern u8 sprite_draw_order[24];
extern i8 pause_screen_flag; // TODO enum
extern i8 is_current_file_existing;
extern u16 game_mode;
extern i16 game_mode_sub1;
extern i8 game_mode_sub2;
extern i8 game_mode_sub3;
extern i8 cleared_every_frame;
extern u16 vblank_request_flag;
extern u16 intr_code[0x100];
extern u16 button_input;
extern u16 button_input_old;
extern u16 buttons_changed;
extern u16 bg1_x_position;
extern u16 bg1_y_position;
extern callback_t vblank_callback;
extern callback_t hblank_callback;
extern callback_t vcount_callback;
extern callback_t serial_callback;
extern callback_t timer3_callback;

extern void *sp_sys;
extern void *sp_irq;
extern u16 unk_03007ff8;
extern u16 (*intr_code_ptr)[0x100];
extern void *intr_vector; // TODO: proper type


// IO

extern struct dma reg_dma[4];

#endif /* GLOBALS_H */
