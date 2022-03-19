#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"
#include "oam.h"
#include "particle.h"
#include "sprite.h"
#include "clipdata.h"
#include "samus.h"

#define PROJECTILE_NONE 0x0
#define PROJECTILE_BEAM 0x1
#define PROJECTILE_MISSILE 0x2
#define PROJECTILE_SUPER_MISSILE 0x3
#define PROJECTILE_BOMB 0x4
#define PROJECTILE_POWER_BOMB 0x5
#define PROJECTILE_CHARGED_BEAM 0x6

#define PROJ_STATUS_NONE 0x0
#define PROJ_STATUS_EXISTS 0x1
#define PROJ_STATUS_ON_SCREEN 0x2
#define PROJ_STATUS_NOT_DRAWN 0x4
#define PROJ_STATUS_HIGH_PRIORITY 0x8
#define PROJ_STATUS_CAN_AFFECT_ENVIRONMENT 0x10
#define PROJ_STATUS_YFLIP 0x20
#define PROJ_STATUS_XFLIP 0x40
#define PROJ_STATUS_UNKNOWN 0x80

#define PROJ_TYPE_BEAM 0x0
#define PROJ_TYPE_LONG_BEAM 0x1
#define PROJ_TYPE_ICE_BEAM 0x2
#define PROJ_TYPE_WAVE_BEAM 0x3
#define PROJ_TYPE_PLASMA_BEAM 0x4
#define PROJ_TYPE_PISTOL 0x5
#define PROJ_TYPE_CHARGED_BEAM 0x6
#define PROJ_TYPE_CHARGED_LONG_BEAM 0x7
#define PROJ_TYPE_CHARGED_ICE_BEAM 0x8
#define PROJ_TYPE_CHARGED_WAVE_BEAM 0x9
#define PROJ_TYPE_CHARGED_PLASMA_BEAM 0xA
#define PROJ_TYPE_CHARGED_PISTOL 0xB
#define PROJ_TYPE_MISSILE 0xC
#define PROJ_TYPE_SUPER_MISSILE 0xD
#define PROJ_TYPE_BOMB 0xE
#define PROJ_TYPE_POWER_BOMB 0xF

struct ProjectileData {
    u8 status;
    struct FrameData* oam_pointer;
    u16 y_position;
    u16 x_position;
    u16 curr_anim_frame;
    u8 anim_duration_counter;
    u8 type;
    u8 direction;
    u8 movement_stage;
    u8 draw_distance_offset;
    u8 timer;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
};
struct PowerBomb {
    u8 animation_state;
    u8 stage;
    u8 semi_minor_axis;
    u8 unknown;
    u16 x_position;
    u16 y_position;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    u8 power_bomb_placed;
    u8 always_zero;
    u8 also_always_zero;
};

void projectile_set_beam_particle_effect(void);
u8 projectile_check_number_of_projectiles(u8 type, u8 limit);
u8 projectile_init(u8 type, u16 y_position, u16 x_position);
void projectile_update(void);
void projectile_update_animation(struct ProjectileData* pProj);
void projectile_draw_all_status_false(void);
void projectile_draw_all_status_true(void);
void projectile_draw(struct ProjectileData* pProj);
void projectile_check_despawn(struct ProjectileData* pProj);
void projectile_load_graphics(void);
void projectile_call_load_graphics_and_clear_projectiles(void);
void projectile_move(struct ProjectileData* pProj, u8 distance);
u8 projectile_collision_related(u16 y_position, u16 x_position);
u8 projectile_collision_related2(struct ProjectileData* pProj);
void projectile_set_trail(struct ProjectileData* pProj, u8 effect, u8 delay);
void projectile_move_tumbling(struct ProjectileData* pProj);
void projectile_check_hit_block(struct ProjectileData* pProj, u8 ccaa, u8 effect);
void projectile_check_hit_sprite(void);
u16 projectile_get_sprite_weakness(struct SpriteData* pSprite);
u8 projectile_ice_beam_deal_damage(struct SpriteData* pSprite, u16 damage);
u8 projectile_deal_damage(struct SpriteData* pSprite, u16 damage);
struct SpriteData* projectile_hit_sprite_immune_to_projectiles(struct SpriteData* pSprite);
struct SpriteData* projectile_hit_solid_sprite(struct SpriteData* pSprite);
void projectile_power_bomb_deal_damage(struct SpriteData* pSprite);
void projectile_hit_sprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void projectile_non_ice_charged_hit_sprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void projectile_freeze_sprite(struct SpriteData* pSprite, u8 freeze_timer);
void projectile_ice_beam_hitting_sprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void projectile_charged_ice_beam_hitting_sprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void projectile_start_tumbling_missile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type);
void projectile_start_tumbling_missile_current_sprite(struct ProjectileData* pProj, u8 type);
void projectile_missile_hit_sprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 y_position, u16 x_position);
void projectile_missile_hit_sprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 y_position, u16 x_position);
void projectile_bomb_hit_sprite(struct SpriteData* pSprite, u16 y_position, u16 x_position);
void projectile_process_normal_beam(struct ProjectileData* pProj);
void projectile_process_long_beam(struct ProjectileData* pProj);
void projectile_process_ice_beam(struct ProjectileData* pProj);
u32 projectile_check_wave_beam_hitting_blocks(struct ProjectileData* pProj);
void projectile_process_wave_beam(struct ProjectileData* pProj);
void projectile_process_plasma_beam(struct ProjectileData* pProj);
void projectile_process_pistol(struct ProjectileData* pProj);
void projectile_process_charged_normal_beam(struct ProjectileData* pProj);
void projectile_process_charged_long_beam(struct ProjectileData* pProj);
void projectile_process_charged_ice_beam(struct ProjectileData* pProj);
void projectile_process_charged_wave_beam(struct ProjectileData* pProj);
void projectile_process_charged_plasma_beam(struct ProjectileData* pProj);
void projectile_process_charged_pistol(struct ProjectileData* pProj);
void projectile_decrement_missile_counter(struct ProjectileData* pProj);
void projectile_process_missile(struct ProjectileData* pProj);
void projectile_decrement_super_missile(struct ProjectileData* pProj);
void projectile_process_super_missile(struct ProjectileData* pProj);
void projectile_morphball_launcher_check_launch_samus(struct ProjectileData* pProj);
void projectile_check_samus_bomb_bounce(struct ProjectileData* pProj);
void projectile_process_bomb(struct ProjectileData* pProj);
void projectile_process_empty(struct ProjectileData* pProj);
void projectile_process_power_bomb(struct ProjectileData* pProj);

#endif /* PROJECTILE_H */