#ifndef ROOM_H
#define ROOM_H

#include "types.h"
#include "sprite.h"
#include "event.h"

enum __attribute__((packed)) room_effect {
    EFFECT_NONE = 0x0,
    EFFECT_WATER = 0x1,
    EFFECT_STRONG_LAVA = 0x2,
    EFFECT_WEAK_LAVA = 0x3,
    EFFECT_STRONG_LAVA_HEAT_HAZE = 0x4,
    EFFECT_ACID = 0x5,
    EFFECT_SNOWFLAKES_COLD_KNOCKBACK = 0x6,
    EFFECT_SNOWFLAKES_COLD = 0x7,
    EFFECT_HEAT_BG3_HAZE = 0x8,
    EFFECT_HEAT_BG2_BG3_HAZE = 0x9,
    EFFECT_BG3_GRADIENT = 0xA,
    EFFECT_BG2_GRADIENT = 0xB
};

enum __attribute__((packed)) bg0_movement_type {
    BG0_MOVEMENT_NONE = 0x0,
    BG0_MOVEMENT_WATER_CLOUDS = 0x1,
    BG0_MOVEMENT_SNOWFLAKES = 0x4
};

struct room_entry {
    u8 tileset;
    u8 bg0_prop;
    u8 bg1_prop;
    u8 bg2_prop;
    u8 bg3_prop;
    u8 scrolls_flag;
    u8 bg3_scrolling;
    u8 transparency;
    struct enemy_room_data* enemy_room_data;
    enum event first_spriteset_event;
    enum event second_spriteset_event;
    u8 map_x;
    u8 map_y;
    enum room_effect effect;
    u16 effect_y;
    enum room_effect effect_clone;
    u16 music_track;
    u8 bg0_size;
    u8 bg3_size;
    u8 bg3_from_bottom_flag;
    u8 animated_tilset;
    u8 animated_palette;
};

struct room_entry_rom {
    u8 tileset;
    u8 bg0_prop;
    u8 bg1_prop;
    u8 bg2_prop;
    u8 bg3_prop;
    void* bg0_ptr;
    void* bg1_ptr;
    void* bg2_ptr;
    void* clip_ptr;
    void* bg3_ptr;
    u8 bg3_scrolling;
    u8 transparency;
    struct enemy_room_data* default_sprite_data_ptr;
    u8 default_spriteset;
    enum event first_spriteset_event;
    struct enemy_room_data* first_sprite_data_ptr;
    u8 first_spriteset;
    enum event second_spriteset_event;
    struct enemy_room_data* second_sprite_data_ptr;
    u8 second_spriteset;
    u8 map_x;
    u8 map_y;
    enum room_effect effect;
    u8 effect_y;
    u16 music_track;
};

struct background_positions {
    struct raw_coords_x bg[4];
    struct raw_coords_x door_transition;
};

struct bg0_movement {
    enum bg0_movement_type type;
    u8 y_offset;
    u16 unused;
    u16 x_offset;
    u16 snowflakes_related;
};

struct bg3_movement {
    struct sub1 {
        u8 direction;
        u8 counter;
    } sub1;
    struct sub2 {
        u16 x_offset;
    } sub2;
};

void room_load(void);
void room_load_tileset(void);
void room_load_entry(void);
void room_load_backgrounds(void);
void room_remove_never_reform_blocks_and_collected_tanks(void);
void room_reset(void);
void room_set_background_scrolling(void);
void room_maybe_set_initial_tilemap(u8 bg_number);
u8 room_rle_decompress(u8 mode, u8* src, u8* dst);
void room_unk56e28(void);
void room_maybe_check_update_animated_graphics_palette(void);
void room_unk56ef4(void);
void room_update(void);
void room_update_backgrounds_position(void);
void room_maybe_update_vertical_tilemap(u8 unk);
void room_maybe_update_horizontal_tilemap(u8 unk);
vodi room_check_dma3_ended(void);

#endif /* ROOM_H */