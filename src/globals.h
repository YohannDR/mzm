#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
#include "oam.h"
#include "gba/keys.h"
#include "io.h"

// EWRAM

extern u32 events_triggered[8];

// IWRAM

enum pause_screen_flags {
    PAUSE_SCREEN_NONE,
    PAUSE_SCREEN_UNKNOWN_1,
    PAUSE_SCREEN_PAUSE_OR_CUTSCENE,
    PAUSE_SCREEN_UNKNOWN_3,
    PAUSE_SCREEN_CHOZO_HINT,
    PAUSE_SCREEN_MAP_DOWNLOAD,
    PAUSE_SCREEN_ITEM_ACQUISITION,
    PAUSE_SCREEN_SUITLESS_ITEMS,
    PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS,
    PAUSE_SCREEN_UNKNOWN_9,
};

enum difficulty {
    DIFF_EASY = 0x0,
    DIFF_NORMAL = 0x1,
    DIFF_HARD = 0x2
};

extern u8 unk_02038000[];

extern u8 debug_flag;
extern u16 frame_counter_16bit;
extern u16 written_to_dispcnt;
extern u8 stereo_enabled;
extern u32 curr_demo; /* XXX: type */
extern u8 bg_fading;
extern u8 which_bg_position_is_written_to_bg30fs;
extern u8 samus_on_top_backgrounds;
extern u8 difficulty;
extern u8 use_mother_ship_doors;
extern u8 reset_game;
extern u8 disable_scrolling;
extern u8 skip_door_transition;
extern u8 softreset_disabled;
extern u8 disable_pause;
extern u8 current_area;
extern u8 current_room;
extern u8 last_door_used;
extern u8 bit_six_of_last_door_properties;
extern u16 effect_y_position;
extern u8 screen_shake_x_related;
extern u8 screen_shake_y_related;
extern u16 screen_shake_related;
extern u16 dispcnt_backup;
extern u8 spriteset;
extern u8 current_clipdata_affecting_action;
extern u8 spriteset_entry_used;
extern i8 door_unlock_timer;
extern i8 curr_cutscene;
extern i8 unk_0300007e;
extern u8 unk_0x30001A0;
extern u16 alarm_timer;
extern struct SpriteData sprite_data[24];
extern u8 spriteset_sprite_id[15];
extern u8 spriteset_sprite_gfx_slots[15];
extern struct SubSpriteData sub_sprite_data1;
extern struct SubSpriteData sub_sprite_data2;
extern u8 parasite_related;
extern struct SpriteData current_sprite;
extern struct SpriteDebris sprite_debris[8];
extern u8 previous_vertical_collision_check;
extern u8 previous_collision_check;
extern u8 collision_related;
extern u8 sprite_draw_order[24];
extern u8 sprite_rng;
extern u16* curr_particle_oam_frame_ptr;
extern u8 current_escape_status;
extern u8 escape_timer_counter;
extern u16 particle_escape_oam_frames[25];
extern u16 particle_samus_reflection_oam_frames[73];
extern i8 is_current_file_existing;
extern u16 arm_cannon_y;
extern u16 arm_cannon_x;
extern i8 unk_03000c76;
extern u8 frame_counter_8bit;
extern vu16 vblank_request_flag;
extern u16 intr_code[0x100];
extern struct RawOamData oam_data[160];
extern u8 pause_screen_flag;
extern u8 unk_03000c1c;
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
extern u8 unk_030013d2;
extern struct SamusData samus_data;
extern struct SamusData samus_data_copy;
extern struct WeaponInfo samus_weapon_info;
extern struct ScrewSpeedAnimation screw_speed_animation;
extern struct Equipment equipment;
extern struct HazardDamage samus_hazard_damage;
extern struct EnvironmentalEffect samus_environmental_effects[5];
extern struct SamusPhysics samus_physics;
extern u16 previous_x_position;
extern u16 previous_y_position;
extern u16 prevent_movement_timer;
extern u8 unk_03004fc9;
extern u16 samus_palette[32];
extern i16 samus_door_position_offset;
extern u8* current_room_scroll_data_pointer;

extern void *sp_sys;
extern void *sp_irq;
extern Func_t intr_vector[13];
extern u16 (*intr_code_ptr)[0x100];
extern i8 unk_03000c75;
extern i8 unk_03000c76;
extern u8 frame_counter_8bit;
extern vu16 vblank_request_flag;
extern u16 unk_03007ff8;
extern u16 (*intr_code_ptr)[0x100];

// IO

extern struct dma reg_dma[4];
#endif /* GLOBALS_H */
