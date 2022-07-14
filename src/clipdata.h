#ifndef CLIPDATA_H
#define CLIPDATA_H

#include "types.h"
#include "block.h"
#include "gba.h"

#define CCAA_NONE 0x0
#define CCAA_REMOVE_SOLID 0x1
#define CCAA_MAKE_SOLID1 0x2
#define CCAA_MAKE_SOLID2 0x3
#define CCAA_MAKE_SOLID3 0x4
#define CCAA_BOMB_CHAIN_UNUSED 0x5
#define CCAA_UNUSED 0x6
#define CCAA_BEAM 0x7
#define CCAA_BOMB_PISTOL 0x8
#define CCAA_MISSILE 0x9
#define CCAA_SUPER_MISSILE 0xA
#define CCAA_POWER_BOMB 0xB
#define CCAA_SPEEDBOOSTER 0xC
#define CCAA_SPEEDBOOSTER2 0xD
#define CCAA_SCREW_ATTACK 0xE
#define CCAA_BOMB_CHAIN 0xF

#define COLLISION_AIR 0x0
#define COLLISION_SLIGHT_LEFT_FLOOR_SLOPE 0x2
#define COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE 0x3
#define COLLISION_STEEP_LEFT_FLOOR_SLOPE 0x4
#define COLLISION_STEEP_RIGHT_FLOOR_SLOPE 0x5
#define COLLISION_PASS_THROUGH_BOTTOM 0x10
#define COLLISION_SOLID 0x11

#define CLIPDATA_MOVEMENT_NONE 0x0
#define CLIPDATA_MOVEMENT_ELEVATOR_DOWN_BLOCK 0x1
#define CLIPDATA_MOVEMENT_ELEVATOR_UP_BLOCK 0x2
#define CLIPDATA_MOVEMENT_NON_POWER_GRIP 0x6
#define CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID 0x7
#define CLIPDATA_MOVEMENT_SPACE_PIRATE_ZONELINE 0x8
#define CLIPDATA_MOVEMENT_SPACE_PIRATE_WALLJUMP_POINT 0x9

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

#define CLIPDATA_ACTOR_SAMUS 0x0
#define CLIPDATA_ACTOR_NON_SPRITE 0x1
#define CLIPDATA_ACTOR_SPRITE 0x2

#define CLIPDATA_TYPE_AIR 0x0
#define CLIPDATA_TYPE_SOLID 0x1
#define CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE 0x2
#define CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE 0x3
#define CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE 0x4
#define CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE 0x5
#define CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE 0x6
#define CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE 0x7
#define CLIPDATA_TYPE_ENEMY_ONLY 0x8
#define CLIPDATA_TYPE_STOP_ENEMY 0x9
#define CLIPDATA_TYPE_TANK 0xA
#define CLIPDATA_TYPE_DOOR 0xB
#define CLIPDATA_TYPE_PASS_THROUGH_BOTTOM 0xC
#define CLIPDATA_TYPE_SOLID_FLAG 0x1000000

struct CurrentAffectingClip {
    u16 movement;
    u16 hazard;
};

struct CollisionData {
    i32 clipdata_type;
    i32 sub_pixel_x;
    i32 sub_pixel_y;
    i32 actor_type;
    u16 tile_x;
    u16 tile_y;
};

struct TilemapAndClipPointers {
    u16* tilemap;
    u8* clip_collisions;
    u16* clip_behaviors;
};

typedef u32 (*ClipFunc_T)(struct CollisionData*);

void clipdate_setup_code(void);
u32 clipdata_process_for_samus(u16 y_position, u16 x_position);
u32 clipdata_process(u16 y_position, u16 x_position);
u32 clipdata_convert_to_collision(struct CollisionData* pCollision);
u32 clipdata_check_current_affecting_at_position(u16 y_position, u16 x_position);
u32 clipdata_update_current_affecting(u16 y_position, u16 tile_y, u16 tile_x, u8 unk);
u8 clidpata_check_cant_use_elevator(void);
u32 clipdata_check_ground_effect(u16 y_position, u16 x_position);

#endif /* CLIPDATA_H */