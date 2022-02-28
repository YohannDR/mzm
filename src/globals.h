#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
#include "sprite.h"
#include "room.h"
#include "particle.h"
#include "oam.h"
#include "screen_shake.h"
#include "samus.h"
#include "gba_input.h"
#include "projectile.h"
#include "scroll.h"
#include "connection.h"
#include "bg_clip.h"
#include "io.h"
#include "escape.h"
#include "clipdata.h"

// EWRAM

extern u32 events_triggered[8];

// IWRAM

extern u16 sixteen_bit_frame_counter;
extern u16 written_to_dispcnt;
extern u8 bg_fading;
extern u8 which_bg_position_is_written_to_bg30fs;
extern u8 samus_on_top_backgrounds;
extern u8 difficulty;
extern u8 use_mother_ship_doors;
extern u8 disable_scrolling;
extern u8 skip_door_transition;
extern u8 softreset_disabled;
extern u8 disable_pause;
extern enum area current_area;
extern u8 current_room;
extern u8 last_door_used;
extern u8 bit_six_of_last_door_properties;
extern u16 effect_y_position;
extern u8 screen_shake_x_related;
extern u8 screen_shake_y_related;
extern u16 screen_shake_related;
extern u16 dispcnt_backup;
extern u8 spriteset;
extern enum current_clipdata_affecting_action current_clipdata_affecting_action;
extern u8 spriteset_entry_used;
extern i8 door_unlock_timer;
extern struct io_registers_backup io_registers_backup;
extern struct background_pointers_and_dimensions bg_pointers_and_dimensions;
extern struct room_entry current_room_entry;
extern struct current_affecting_clipdata current_affecting_clipdata;
extern struct background_positions background_positions;
extern struct raw_coords_x waiting_space_pirates_position;
extern struct screen_shake screen_shake_y;
extern struct screen_shake screen_shake_x;
extern struct current_scrolls current_scrolls;
extern struct power_bomb current_power_bomb;
extern struct screen_position_and_velocity screen_position_and_velocity;
extern u8 unk_0x30001A0;
extern u16 alarm_timer;
extern struct sprite_data sprite_data[24];
extern enum s_sprite_id spriteset_sprite_id[15];
extern u8 spriteset_sprite_gfx_slots[15];
extern struct sub_sprite_data sub_sprite_data1;
extern struct sub_sprite_data sub_sprite_data2;
extern u8 parasite_related;
extern struct sprite_data current_sprite;
extern struct sprite_debris sprite_debris[8];
extern u8 previous_vertical_collision_check;
extern u8 previous_collision_check;
extern u8 collision_related;
extern u8 sprite_draw_order[24];
extern u8 sprite_rng;
extern struct particle_effect particle_effects[16];
extern struct oam_frame* curr_particle_oam_frame_ptr;
extern enum escape_status current_escape_status;
extern u8 escape_timer_counter;
extern struct escape_digits escape_timer_digits;
extern u16 particle_escape_oam_frames[25];
extern struct projectile_data projectile_data[16];
extern u16 arm_cannon_y;
extern u16 arm_cannon_x;
extern i8 pause_screen_flag; // TODO enum
extern i8 is_current_file_existing;
extern u16 game_mode;
extern i16 game_mode_sub1;
extern i8 game_mode_sub2;
extern i8 game_mode_sub3;
extern i8 cleared_every_frame;
extern u8 eight_bit_frame_counter;
extern u16 vblank_request_flag;
extern u16 intr_code[0x100];
extern struct raw_oam_data oam_data[160];
extern u16 button_input;
extern u16 button_input_old;
extern u16 buttons_changed;
extern u8 next_oam_slot;
extern u16 bg0_x_position;
extern u16 bg0_y_position;
extern u16 bg1_x_position;
extern u16 bg1_y_position;
extern u16 bg2_x_position;
extern u16 bg2_y_position;
extern u16 bg3_x_position;
extern u16 bg3_y_position;
extern struct samus_data samus_data;
extern struct samus_data samus_data_copy;
extern struct weapon_info samus_weapon_info;
extern struct screw_speed_animation screw_speed_animation;
extern struct equipment equipment;
extern struct hazard_damage samus_hazard_damage;
extern struct samus_physics samus_physics;
extern u16 previous_x_position;
extern u16 previous_y_position;
extern u16 prevent_movement_timer;
extern struct button_assignements button_assignements;
extern callback_t vblank_callback;
extern callback_t hblank_callback;
extern callback_t vcount_callback;
extern callback_t serial_callback;
extern callback_t timer3_callback;
extern u8 unk_03004fc9;
extern u16 samus_palette[32];
extern struct hatch_data hatch_data[16];
extern struct raw_coords_x door_position_start;
extern struct bg3_movement bg3_movement;
extern struct bg0_movement bg0_movement;
extern i16 samus_door_position_offset;
extern struct scroll_data* current_room_scroll_data_pointer;

extern void *sp_sys;
extern void *sp_irq;
extern u16 unk_03007ff8;
extern u16 (*intr_code_ptr)[0x100];
extern void *intr_vector; // TODO: proper type


// IO

extern struct dma reg_dma[4];

#endif /* GLOBALS_H */
