#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"
#include "oam.h"

#define PE_SPRITE_SPLASH_WATER_SMALL 0x0
#define PE_SPRITE_SPLASH_WATER_BIG 0x1
#define PE_SPRITE_SPLASH_WATER_HUGE 0x2
#define PE_SPRITE_SPLASH_LAVA_SMALL 0x3
#define PE_SPRITE_SPLASH_LAVA_BIG 0x4
#define PE_SPRITE_SPLASH_LAVA_HUGE 0x5
#define PE_SPRITE_SPLASH_ACID_SMALL 0x6
#define PE_SPRITE_SPLASH_ACID_BIG 0x7
#define PE_SPRITE_SPLASH_ACID_HUGE 0x8
#define PE_SHOOTING_BEAM_LEFT 0x9
#define PE_SHOOTING_BEAM_DIAG_UP_LEFT 0xA
#define PE_SHOOTING_BEAM_DIAG_DOWN_LEFT 0xB
#define PE_SHOOTING_BEAM_UP_LEFT 0xC
#define PE_SHOOTING_BEAM_DOWN_LEFT 0xD
#define PE_SHOOTING_BEAM_RIGHT 0xE
#define PE_SHOOTING_BEAM_DIAG_UP_RIGHT 0xF
#define PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT 0x10
#define PE_SHOOTING_BEAM_UP_RIGHT 0x11
#define PE_SHOOTING_BEAM_DOWN_RIGHT 0x12
#define PE_BOMB 0x13
#define PE_MISSILE_TRAIL 0x14
#define PE_SUPER_MISSILE_TRAIL 0x15
#define PE_BEAM_TRAILING_RIGHT 0x16
#define PE_BEAM_TRAILING_LEFT 0x17
#define PE_CHARGED_LONG_BEAM_TRAIL 0x18
#define PE_CHARGED_ICE_BEAM_TRAIL 0x19
#define PE_CHARGED_WAVE_BEAM_TRAIL 0x1A
#define PE_CHARGED_PLASMA_BEAM_TRAIL 0x1B
#define PE_CHARGED_FULL_BEAM_TRAIL 0x1C
#define PE_CHARGED_PISTOL_TRAIL 0x1D
#define PE_SPRITE_EXPLOSION_HUGE 0x1E
#define PE_SPRITE_EXPLOSION_SMALL 0x1F
#define PE_SPRITE_EXPLOSION_MEDIUM 0x20
#define PE_SPRITE_EXPLOSION_BIG 0x21
#define PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG 0x22
#define PE_SCREW_ATTACK_DESTROYED 0x23
#define PE_SHINESPARK_DESTROYED 0x24
#define PE_SUDO_SCREW_DESTROYED 0x25
#define PE_SPEEDBOOSTER_DESTROYED 0x26
#define PE_MAIN_BOSS_DEATH 0x27
#define PE_FREEZING_SPRITE_WITH_ICE 0x28
#define PE_FREEZING_SPRITE_WITH_CHARGED_ICE 0x29
#define PE_HITTING_SOMETHING_WITH_BASE_BEAM 0x2A
#define PE_HITTING_SOMETHING_WITH_LONG_BEAM 0x2B
#define PE_HITTING_SOMETHING_WITH_ICE_BEAM 0x2C
#define PE_HITTING_SOMETHING_WITH_WAVE_BEAM 0x2D
#define PE_HITTING_SOMETHING_WITH_PLASMA_BEAM 0x2E
#define PE_HITTING_SOMETHING_INVINCIBLE 0x2F
#define PE_HITTING_SOMETHING_WITH_MISSILE 0x30
#define PE_HITTING_SOMETHING_WITH_SUPER_MISSILE 0x31
#define PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA 0x32
#define PE_HITTING_SOMETHING_WITH_FULL_BEAM 0x33
#define PE_SMALL_DUST 0x34
#define PE_MEDIUM_DUST 0x35
#define PE_TWO_MEDIUM_DUST 0x36
#define PE_SECOND_SMALL_DUST 0x37
#define PE_SECOND_MEDIUM_DUST 0x38
#define PE_SECOND_TWO_MEDIUM_DUST 0x39
#define PE_SAMUS_REFLECTION 0x3A
#define PE_CHARGING_BEAM 0x3B
#define PE_ESCAPE 0x3C

#define PARTICLE_STATUS_NONE 0x0
#define PARTICLE_STATUS_EXISTS 0x1
#define PARTICLE_STATUS_ONSCREEN 0x2
#define PARTICLE_STATUS_EXPLOSION 0x4
#define PARTICLE_STATUS_NOT_DRAWN 0x8
#define PARTICLE_STATUS_SPECIAL_EFFECT 0x10
#define PARTICLE_STATUS_LOW_PRIORITY 0x20
#define PARTICLE_STATUS_ABSOLUTE_POSITION 0x40
#define PARTICLE_STATUS_XFLIP 0x80

struct ParticleEffect {
    u8 status;
    u8 anim_duration_counter;
    u8 effect;
    u8 stage;
    u8 frame_counter;
    u16 curr_anim_frame;
    u16 y_position;
    u16 x_position;
};

typedef void (*particle_t)(struct ParticleEffect*);

void particle_check_on_screen(struct ParticleEffect* pParticle);
void particle_draw(struct ParticleEffect* pParticle);
void particle_process_all(void);
void particle_set(u16 y_position, u16 x_position, u8 effect);
u8 particle_update_animation(struct ParticleEffect* pParticle, struct FrameData* pOam);
void particle_set_current_oam_frame_pointer(struct ParticleEffect* pParticle, struct FrameData* pOam);
void particle_sprite_splash_water_small(struct ParticleEffect* pParticle);
void particle_sprite_splash_water_big(struct ParticleEffect* pParticle);
void particle_sprite_splash_water_huge(struct ParticleEffect* pParticle);
void particle_sprite_splash_lava_small(struct ParticleEffect* pParticle);
void particle_sprite_splash_lava_big(struct ParticleEffect* pParticle);
void particle_sprite_splash_lava_huge(struct ParticleEffect* pParticle);
void particle_sprite_splash_acid_small(struct ParticleEffect* pParticle);
void particle_sprite_splash_acid_big(struct ParticleEffect* pParticle);
void particle_sprite_splash_acid_huge(struct ParticleEffect* pParticle);
void particle_shooting_beam_left(struct ParticleEffect* pParticle);
void particle_shooting_beam_right(struct ParticleEffect* pParticle);
void particle_shooting_beam_diag_up_left(struct ParticleEffect* pParticle);
void particle_shooting_beam_diag_up_right(struct ParticleEffect* pParticle);
void particle_shooting_beam_diag_down_left(struct ParticleEffect* pParticle);
void particle_shooting_beam_diag_down_right(struct ParticleEffect* pParticle);
void particle_shooting_beam_up_left(struct ParticleEffect* pParticle);
void particle_shooting_beam_up_right(struct ParticleEffect* pParticle);
void particle_shooting_beam_down_left(struct ParticleEffect* pParticle);
void particle_shooting_beam_down_right(struct ParticleEffect* pParticle);
void particle_bomb(struct ParticleEffect* pParticle);
void particle_missile_trail(struct ParticleEffect* pParticle);
void particle_super_missile_trail(struct ParticleEffect* pParticle);
void particle_beam_trailing_right(struct ParticleEffect* pParticle);
void particle_beam_trailing_left(struct ParticleEffect* pParticle);
void particle_charged_long_beam_trailing(struct ParticleEffect* pParticle);
void particle_charged_ice_beam_trailing(struct ParticleEffect* pParticle);
void particle_charged_wave_beam_trail(struct ParticleEffect* pParticle);
void particle_charged_plasma_beam_trail(struct ParticleEffect* pParticle);
void particle_charged_full_beam_trail(struct ParticleEffect* pParticle);
void particle_charged_pistol_trail(struct ParticleEffect* pParticle);
void particle_sprite_explosion_huge(struct ParticleEffect* pParticle);
void particle_sprite_explosion_small(struct ParticleEffect* pParticle);
void particle_sprite_explosion_medium(struct ParticleEffect* pParticle);
void particle_sprite_explosion_big(struct ParticleEffect* pParticle);
void particle_sprite_explosion_single_then_big(struct ParticleEffect* pParticle);
void particle_screw_attack_destroyed(struct ParticleEffect* pParticle);
void particle_shinespark_destroyed(struct ParticleEffect* pParticle);
void particle_sudo_screw_destroyed(struct ParticleEffect* pParticle);
void particle_speedbooster_destroyed(struct ParticleEffect* pParticle);
void particle_main_boss_death(struct ParticleEffect* pParticle);
void particle_freezing_sprite_with_ice(struct ParticleEffect* pParticle);
void particle_freezing_sprite_with_charged_ice(struct ParticleEffect* pParticle);
void particle_hitting_something_with_base_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_with_long_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_with_ice_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_with_wave_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_with_full_beam_no_plasma(struct ParticleEffect* pParticle);
void particle_hitting_something_with_plasma_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_with_full_beam(struct ParticleEffect* pParticle);
void particle_hitting_something_invicible(struct ParticleEffect* pParticle);
void particle_hitting_something_with_missile(struct ParticleEffect* pParticle);
void particle_hitting_something_with_super_missile(struct ParticleEffect* pParticle);
void particle_small_dust(struct ParticleEffect* pParticle);
void particle_medium_dust(struct ParticleEffect* pParticle);
void particle_two_medium_dust(struct ParticleEffect* pParticle);
void particle_second_small_dust(struct ParticleEffect* pParticle);
void particle_second_medium_dust(struct ParticleEffect* pParticle);
void particle_second_two_medium_dust(struct ParticleEffect* pParticle);
void particle_play_begin_to_charge_sound(void);
void particle_play_shooting_charged_beam_sound(void);
void particle_play_beam_fully_charged_sound(void);
void particle_charging_beam(struct ParticleEffect* pParticle);
void particle_escape(struct ParticleEffect* pParticle);
void particle_samus_reflection(struct ParticleEffect* pParticle);

#endif /* PARTICLE_H */