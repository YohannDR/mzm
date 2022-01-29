#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"
#include "oam.h"

enum __attribute__ ((packed)) particle_effect_id {
    PE_SPRITE_SPLASH_WAER_SMALL = 0x0,
    PE_SPRITE_SPLASH_WATER_BIG = 0x1,
    PE_SPRITE_SPLASH_WATER_HUGE = 0x2,
    PE_SPRITE_SPLASH_LAVA_SMALL = 0x3,
    PE_SPRITE_SPLASH_LAVA_BIG = 0x4,
    PE_SPRITE_SPLASH_LAVA_HUGE = 0x5,
    PE_SPRITE_SPLASH_ACID_SMALL = 0x6,
    PE_SPRITE_SPLASH_ACID_BIG = 0x7,
    PE_SPRITE_SPLASH_ACID_HUGE = 0x8,
    PE_SHOOTING_BEAM_LEFT = 0x9,
    PE_SHOOTING_BEAM_DIAG_UP_LEFT = 0xA,
    PE_SHOOTING_BEAM_DIAG_DOWN_LEFT = 0xB,
    PE_SHOOTING_BEAM_UP_LEFT = 0xC,
    PE_SHOOTING_BEAM_DOWN_LEFT = 0xD,
    PE_SHOOTING_BEAM_RIGHT = 0xE,
    PE_SHOOTING_BEAM_DIAG_UP_RIGHT = 0xF,
    PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT = 0x10,
    PE_SHOOTING_BEAM_UP_RIGHT = 0x11,
    PE_SHOOTING_BEAM_DOWN_RIGHT = 0x12,
    PE_BOMB = 0x13,
    PE_MISSILE_TRAIL = 0x14,
    PE_SUPER_MISSILE_TRAIL = 0x15,
    PE_BEAM_TRAILING_RIGHT = 0x16,
    PE_BEAM_TRAILING_LEFT = 0x17,
    PE_CHARGED_LONG_BEAM_TRAIL = 0x18,
    PE_CHARGED_ICE_BEAM_TRAIL = 0x19,
    PE_CHARGED_WAVE_BEAM_TRAIL = 0x1A,
    PE_CHARGED_PLASMA_BEAM_TRAIL = 0x1B,
    PE_CHARGED_FULL_BEAM_TRAIL = 0x1C,
    PE_CHARGED_PISTOL_TRAIL = 0x1D,
    PE_SPRITE_EXPLOSION_HUGE = 0x1E,
    PE_SPRITE_EXPLOSION_SMALL = 0x1F,
    PE_SPRITE_EXPLOSION_MEDIUM = 0x20,
    PE_SPRITE_EXPLOSION_BIG = 0x21,
    PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG = 0x22,
    PE_SCREW_ATTACK_DESTROYED = 0x23,
    PE_SHINESPARK_DESTROYED = 0x24,
    PE_SUDO_SCREW_DESTROYED = 0x25,
    PE_SPEEDBOOSTER_DESTROYED = 0x26,
    PE_MAIN_BOSS_DEATH = 0x27,
    PE_FREEZING_SPRITE_WITH_ICE = 0x28,
    PE_FREEZING_SPRITE_WITH_CHARGED_ICE = 0x29,
    PE_HTTING_SOMETHING_WITH_BASE = 0x2A,
    PE_HTTING_SOMETHING_WITH_LONG = 0x2B,
    PE_HTTING_SOMETHING_WITH_ICE_BEAM = 0x2C,
    PE_HTTING_SOMETHING_WITH_WAVE_BEAM = 0x2D,
    PE_HTTING_SOMETHING_WITH_PLASMA_BEAM = 0x2E,
    PE_HTTING_SOMETHING_INVINCIBLE = 0x2F,
    PE_HTTING_SOMETHING_WITH_MISSILE = 0x30,
    PE_HTTING_SOMETHING_WITH_SUPER_MISSILE = 0x31,
    PE_HTTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA = 0x32,
    PE_HTTING_SOMETHING_WITH_FULL_BEAM = 0x33,
    PE_SMALL_DUST = 0x34,
    PE_MEDIUM_DUST = 0x35,
    PE_TWO_MEDIUM_DUST = 0x36,
    PE_SECOND_SMALL_DUST = 0x37,
    PE_SECOND_MEDIUM_DUST = 0x38,
    PE_SECOND_TWO_MEDIUM_DUST = 0x39,
    PE_SAMUS_REFLECTION = 0x3A,
    PE_CHARCHING_BEAM = 0x3B,
    PE_ESCAPE = 0x3C,
};

struct particle_effect {
    u8 status;
    u8 anim_frame_counter;
    enum particle_effect_id effect;
    u8 stage;
    u8 frame_counter;
    u16 anim_state;
    u16 y_position;
    u16 x_position;
};

void particle_check_on_screen(struct particle_effect* ptr);
void particle_draw(struct particle_effect* ptr);
void particle_process_all(void);
void particle_set(u16 y_position, u16 x_position, enum particle_effect_id effect);
u32 particle_update_animation(struct particle_effect* ptr, struct frame_data* oam_ptr);
void particle_set_current_oam_frame_pointer(struct particle_effect* ptr, struct frame_data* oam_ptr);
void particle_sprite_splash_water_small(struct particle_effect* ptr);
void particle_sprite_splash_water_big(struct particle_effect* ptr);
void particle_sprite_splash_water_huge(struct particle_effect* ptr);
void particle_sprite_splash_lava_small(struct particle_effect* ptr);
void particle_sprite_splash_lava_big(struct particle_effect* ptr);
void particle_sprite_splash_lava_huge(struct particle_effect* ptr);
void particle_sprite_splash_acid_small(struct particle_effect* ptr);
void particle_sprite_splash_acid_big(struct particle_effect* ptr);
void particle_sprite_splash_acid_huge(struct particle_effect* ptr);
void particle_shooting_beam_left(struct particle_effect* ptr);
void particle_shooting_beam_right(struct particle_effect* ptr);
void particle_

#endif /* PARTICLE_H */