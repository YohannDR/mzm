#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"
#include "oam.h"
#include "particle.h"
#include "sprite.h"
#include "clipdata.h"
#include "samus.h"

enum __attribute__((packed)) projectile {
    PROJECTILE_NONE = 0x0,
    PROJECTILE_BEAM = 0x1,
    PROJECTILE_MISSILE = 0x2,
    PROJECTILE_SUPER_MISSILE = 0x3,
    PROJECTILE_BOMB = 0x4,
    PROJECTILE_POWER_BOMB = 0x5,
    PROJECTILE_CHARGED_BEAM = 0x6
};

enum __attribute__((packed)) projectile_status {
    PROJ_STATUS_NONE = 0x0,
    PROJ_STATUS_EXISTS = 0x1,
    PROJ_STATUS_ON_SCREEN = 0x2,
    PROJ_STATUS_NOT_DRAWN = 0x4,
    PROJ_STATUS_HIGH_PRIORITY = 0x8,
    PROJ_STATUS_CAN_AFFECT_ENVIRONMENT = 0x10,
    PROJ_STATUS_YFLIP = 0x20,
    PROJ_STATUS_XFLIP = 0x40,
    PROJ_STATUS_UNKNOWN = 0x80
};

enum __attribute__((packed)) projectile_type {
    PROJ_TYPE_BEAM = 0x0,
    PROJ_TYPE_LONG_BEAM = 0x1,
    PROJ_TYPE_ICE_BEAM = 0x2,
    PROJ_TYPE_WAVE_BEAM = 0x3,
    PROJ_TYPE_PLASMA_BEAM = 0x4,
    PROJ_TYPE_PISTOL = 0x5,
    PROJ_TYPE_CHARGED_BEAM = 0x6,
    PROJ_TYPE_CHARGED_LONG_BEAM = 0x7,
    PROJ_TYPE_CHARGED_ICE_BEAM = 0x8,
    PROJ_TYPE_CHARGED_WAVE_BEAM = 0x9,
    PROJ_TYPE_CHARGED_PLASMA_BEAM = 0xA,
    PROJ_TYPE_CHARGED_PISTOL = 0xB,
    PROJ_TYPE_MISSILE = 0xC,
    PROJ_TYPE_SUPER_MISSILE = 0xD,
    PROJ_TYPE_BOMB = 0xE,
    PROJ_TYPE_POWER_BOMB = 0xF
};
struct projectile_data {
    enum projectile_status status;
    struct frame_data* oam_pointer;
    u16 y_position;
    u16 x_position;
    u16 curr_anim_frame;
    u8 anim_duration_counter;
    enum projectile_type type;
    enum arm_cannon_direction direction;
    u8 movement_stage;
    u8 draw_distance_offset;
    u8 timer;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
};
struct power_bomb {
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
u8 projectile_check_number_of_projectiles(enum projectile_type type, u8 limit);
u8 projectile_init(enum projectile_type type, u16 y_position, u16 x_position);
void projectile_update(void);
void projectile_update_animation(struct projectile_data* pProj);
void projectile_draw_all_status_false(void);
void projectile_draw_all_status_true(void);
void projectile_draw(struct projectile_data* pProj);
void projectile_check_despawn(struct projectile_data* pProj);
void projectile_load_graphics(void);
void projectile_call_load_graphics_and_clear_projectiles(void);
void projectile_move(struct projectile_data* pProj, u8 distance);
u8 projectile_collision_related(u16 y_position, u16 x_position);
u8 projectile_collision_related2(struct projectile_data* pProj);
void projectile_set_trail(struct projectile_data* pProj, enum particle_effect_id effect, u8 delay);
void projectile_move_tumbling(struct projectile_data* pProj);
void projectile_check_hit_block(struct projectile_data* pProj, enum current_clipdata_affecting_action ccaa, enum particle_effect_id effect);
void projectile_check_hit_sprite(void);
enum sprite_weakness_flags projectile_get_sprite_weakness(struct sprite_data* pSprite);
u8 projectile_ice_beam_deal_damage(struct sprite_data* pSprite, u16 damage);
u8 projectile_deal_damage(struct sprite_data* pSprite, u16 damage);
struct sprite_data* projectile_hit_sprite_immune_to_projectiles(struct sprite_data* pSprite);
struct sprite_data* projectile_hit_solid_sprite(struct sprite_data* pSprite);
void projectile_power_bomb_deal_damage(struct sprite_data* pSprite);
void projectile_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect);
void projectile_non_ice_charged_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect);
void projectile_freeze_sprite(struct sprite_data* pSprite, u8 freeze_timer);
void projectile_ice_beam_hitting_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect);
void projectile_charged_ice_beam_hitting_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage, enum particle_effect_id effect);
void projectile_start_tumbling_missile(struct sprite_data* pSprite, struct projectile_data* pProj, enum projectile_type type);
void projectile_start_tumbling_missile_current_sprite(struct projectile_data* pProj, enum projectile_type type);
void projectile_missile_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage);
void projectile_super_missile_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position, u16 damage);
void projectile_bomb_hit_sprite(struct sprite_data* pSprite, u16 y_position, u16 x_position);
void projectile_process_normal_beam(struct projectile_data* pProj);
void projectile_process_long_beam(struct projectile_data* pProj);
void projectile_process_ice_beam(struct projectile_data* pProj);
u32 projectile_check_wave_beam_hitting_blocks(struct projectile_data* pProj);
void projectile_process_wave_beam(struct projectile_data* pProj);
void projectile_process_plasma_beam(struct projectile_data* pProj);
void projectile_process_pistol(struct projectile_data* pProj);
void projectile_process_charged_normal_beam(struct projectile_data* pProj);
void projectile_process_charged_long_beam(struct projectile_data* pProj);
void projectile_process_charged_ice_beam(struct projectile_data* pProj);
void projectile_process_charged_wave_beam(struct projectile_data* pProj);
void projectile_process_charged_plasma_beam(struct projectile_data* pProj);
void projectile_process_charged_pistol(struct projectile_data* pProj);
void projectile_decrement_missile_counter(struct projectile_data* pProj);
void projectile_process_missile(struct projectile_data* pProj);
void projectile_decrement_super_missile(struct projectile_data* pProj);
void projectile_process_super_missile(struct projectile_data* pProj);
void projectile_morphball_launcher_launch_samus(struct projectile_data* pProj);
void projectile_check_samus_bomb_bounce(struct projectile_data* pProj);
void projectile_process_bomb(struct projectile_data* pProj);
void projectile_process_empty(struct projectile_data* pProj);
void projectile_process_power_bomb(struct projectile_data* pProj);

#endif /* PROJECTILE_H */