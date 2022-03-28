#ifndef CLIPDATA_H
#define CLIPDATA_H

#include "types.h"

#define CCAA_NONE 0x0
#define CCAA_REMOVE_SOLID 0x1
#define CCAA_MAYBE_MAKE_SOLID 0x2
#define CCAA_UNKNOWN 0x3
#define CCAA_MAKE_SOLID 0x4
#define CCAA_BEAM 0x7
#define CCAA_BOMB_PISTOL 0x8
#define CCAA_MISSILE 0x9
#define CCAA_SUPER_MISSILE 0xA
#define CCAA_POWER_BOMB 0xB
#define CCAA_SPEEDBOOSTER 0xC
#define CCAA_SPEEDBOOSTER2 0xD
#define CCAA_SCREW_ATTACK 0xE
#define CCAA_BOMB_CHAIN_RELATED 0xF

#define COLLISION_AIR 0x0
#define COLLISION_SLIGHT_LEFT_FLOOR_SLOPE 0x2
#define COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE 0x3
#define COLLISION_STEEP_LEFT_FLOOR_SLOPE 0x4
#define COLLISION_STEEP_RIGHT_FLOOR_SLOPE 0x5
#define COLLISION_PASS_THROUGH_BOTTOM 0x10
#define COLLISION_SOLID 0x11

#define MOVEMENT_CLIPDATA_NONE 0x0
#define MOVEMENT_CLIPDATA_ELEVATOR_DOWN_BLOCK 0x1
#define MOVEMENT_CLIPDATA_ELEVATOR_UP_BLOCK 0x2
#define MOVEMENT_CLIPDATA_NON_POWER_GRIP 0x6
#define MOVEMENT_CLIPDATA_STOP_ENEMY_BLOCK_SOLID 0x7
#define MOVEMENT_CLIPDATA_SPACE_PIRATE_ZONELINE 0x8
#define MOVEMENT_CLIPDATA_SPACE_PIRATE_WALLJUMP_POINT 0x9

#define HAZARD_TYPE_NONE 0x0
#define HAZARD_TYPE_WATER 0x1
#define HAZARD_TYPE_STRONG_LAVA 0x2
#define HAZARD_TYPE_WEAK_LAVA 0x3
#define HAZARD_TYPE_ACID 0x4
#define HAZARD_TYPE_HEAT 0x5
#define HAZARD_TYPE_SNOWFLAKES_KNOCKBACK 0x6
#define HAZARD_TYPE_COLD 0x7

#define GROUND_EFFECT_NONE 0x0
#define GROUND_EFFECT_WET_GROUND 0x1
#define GROUND_EFFECT_DUSTY_GROUND 0x2
#define GROUND_EFFECT_VERY_DUSTY_GROUND 0x3
#define GROUND_EFFECT_UNKNOWN 0x4
#define GROUND_EFFECT_BUBBLY_GROUND 0x5

struct CurrentAffectingClip {
    u16 movement;
    u16 hazard;
};

struct CollisionData {
    u32 clipdata_type;
    i32 x_position;
    i32 y_position;
    i32 unk;
};

void clipdate_setup_code(void);
u32 unk_57df8(u16 y_position, u16 x_position);
u32 clipdata_related(u16 y_position, u16 x_position);
u32 unk_57f7c(struct CollisionData* pCollision);
u16 clipdata_check_hazard_at_position(u16 y_position, u16 x_position);
u16 clipdate_check_current_affecting_hazard_and_very_special_clidpata(u16 y_position, u16 tile_y, u16 tile_x, u8 unk);
u8 clidpata_check_cant_use_elevator(void);
u8 clipdata_check_ground_effect(u16 y_position, u16 x_position);

#endif /* CLIPDATA_H */