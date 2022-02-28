#ifndef CLIPDATA_H
#define CLIPDATA_H

enum __attribute__((packed)) current_clipdata_affecting_action {
    CCAA_NONE = 0x0,
    CCAA_REMOVE_SOLID = 0x1,
    CCAA_MAYBE_MAKE_SOLID = 0x2,
    CCAA_UNKNOWN = 0x3,
    CCAA_MAKE_SOLID = 0x4,
    CCAA_BEAM = 0x7,
    CCAA_BOMB_PISTOL = 0x8,
    CCAA_MISSILE = 0x9,
    CCAA_SUPER_MISSILE = 0xA,
    CCAA_POWER_BOMB = 0xB,
    CCAA_SPEEDBOOSTER = 0xC,
    CCAA_SPEEDBOOSTER2 = 0xD,
    CCAA_SCREW_ATTACK = 0xE,
    CCAA_BOMB_CHAIN_RELATED = 0xF
};

enum __attribute__((packed)) movement_clipdata {
    MOVEMENT_CLIPDATA_NONE = 0x0,
    MOVEMENT_CLIPDATA_ELEVATOR_DOWN_BLOCK = 0x1,
    MOVEMENT_CLIPDATA_ELEVATOR_UP_BLOCK = 0x2,
    MOVEMENT_CLIPDATA_NON_POWER_GRIP = 0x6,
    MOVEMENT_CLIPDATA_STOP_ENEMY_BLOCK_SOLID = 0x7,
    MOVEMENT_CLIPDATA_SPACE_PIRATE_ZONELINE = 0x8,
    MOVEMENT_CLIPDATA_SPACE_PIRATE_WALLJUMP_POINT = 0x9,
    MOVEMENT_CLIPDATA_LIMIT = 0xFFFF
};

enum __attribute__((packed)) hazard_type {
    HAZARD_TYPE_NONE = 0x0,
    HAZARD_TYPE_WATER = 0x1,
    HAZARD_TYPE_STRONG_LAVA = 0x2,
    HAZARD_TYPE_WEAK_LAVA = 0x3,
    HAZARD_TYPE_ACID = 0x4,
    HAZARD_TYPE_HEAT = 0x5,
    HAZARD_TYPE_SNOWFLAKES_KNOCKBACK = 0x6,
    HAZARD_TYPE_COLD = 0x7,
    HAZARD_TYPE_LIMIT = 0xFFFF
};

enum __attribute__((packed)) ground_effect_clipdata {
    GROUND_EFFECT_NONE = 0x0,
    GROUND_EFFECT_WET_GROUND = 0x1,
    GROUND_EFFECT_DUSTY_GROUND = 0x2,
    GROUND_EFFECT_VERY_DUSTY_GROUND = 0x3,
    GROUND_EFFECT_UNKNOWN = 0x4,
    GROUND_EFFECT_BUBBLY_GROUND = 0x5
};

struct current_affecting_clipdata {
    enum movement_clipdata movement;
    enum hazard_type hazard;
};

struct collision_data {

};

void clipdate_setup_code(void);
u32 unk_57df8(u16 y_position, u16 x_position);
u32 clipdata_related(u16 y_position, u16 x_position);
u32 unk_57f7c(struct collision_data* pCollision);
enum hazard_type clipdata_check_hazard_at_position(u16 y_position, u16 x_position);
enum hazard_type clipdate_check_current_affecting_hazard_and_very_special_clidpata(u16 y_position, u16 tile_y, u16 tile_x, u8 unk);
u8 clidpata_check_cant_use_elevator(void);
enum ground_effect_clipdata clipdata_check_effect(u16 y_position, u16 x_position);

#endif /* CLIPDATA_H */