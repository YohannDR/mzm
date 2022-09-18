#ifndef DATA_H
#define DATA_H

#include "../src/oam.h"
#include "../src/types.h"
#include "../src/samus.h"
#include "../src/particle.h"
#include "../src/projectile.h"
#include "../src/sprites_AI/sprites.h"

/* generic_data.c */

extern i16 sSineYValues[320];
extern u8 sRandomNumberTable[256];

/* blob_0x808ca9c_0x8239463.c */

extern u8 blob_0x808ca9c_0x8239463[1755592];

/* samus_visual_data.c */

extern u8 samus_visual_data[68][3];

/* blob_0x8239530_0x823a533.c */

extern u8 blob_0x8239530_0x823a533[4100];

/* samus_hitbox_draw_data.c */

extern u16 samus_draw_distance_offsets[4][4];
extern i16 samus_hitbox_data[4][3];
extern u8 samus_environmental_effects_oam_pointers[72];
extern u16 SamusPullingSelfUp_velocity[4];

/* blob_0x823a5bc_0x82b0cab.c */

extern u8 blob_0x823a5bc_0x82b0cab[485104];

/* sprite_stats.c */

extern u8 sRandomTable0_F[56];
extern i16 dessgeega_sidehopper_in_block_yVelocity[16];
extern i16 sSpritesFallingCeilingSpeed[16];
extern i16 sSpritesFallingSpeed[40];
extern i16 worker_robot_sleeping_falling_speed[10];
extern u16 sPrimarySpriteStats[206][9];
extern u16 sSecondarySpriteStats[77][9];

/* blob_0x82b214e_0x82b2523.c */

extern u8 blob_0x82b214e_0x82b2523[982];

/* blob_0x82cd604_0x82f7db3.c */

extern u8 blob_0x82cd604_0x82f7db3[174000];

/* area_banner_data.c */

extern u16 area_banner_location_text_pal[16];

/* blob_0x82f7dd4_0x82fd107.c */

extern u8 blob_0x82f7dd4_0x82fd107[21300];

/* geron_data.c */

/* blob_0x82fd79c_0x830d55b.c */

extern u8 blob_0x82fd79c_0x830d55b[64960];

/* blob_0x830df94_0x8312b97.c */

extern u8 blob_0x830df94_0x8312b97[19460];

/* blob_0x8313c4c_0x8326ca7.c */

extern u8 blob_0x8313c4c_0x8326ca7[77915];

/* blob_0x832b9e8_0x832ba07.c */

extern u8 blob_0x832b9e8_0x832ba07[32];

/* common_gSpriteData.c */

extern u16 common_sprites_pal[96];
extern u8 common_sprites_gfx[14336];

/* hud_data.c */


/* blob_0x8331348_0x8339aa7.c */

extern u8 blob_0x8331348_0x8339aa7[34656];

/* particle_beam_data.c */

extern struct FrameData particle_shooting_beam_left_right_oam[5];
extern struct FrameData particle_shooting_beam_diagonally_up_oam[5];
extern struct FrameData particle_shooting_beam_diagonally_down_oam[5];
extern struct FrameData particle_shooting_beam_up_oam[5];
extern struct FrameData particle_shooting_beam_down_oam[5];
extern struct FrameData particle_bomb_oam[7];
extern struct FrameData particle_beam_trailing_oam[6];
extern struct FrameData particle_charging_beam_oam_begin[23];
extern struct FrameData particle_charging_beam_oam_charged[3];

/* particle_misc_data.c */

extern struct FrameData particle_hitting_something_with_base_beam_oam[5];
extern struct FrameData particle_hitting_something_with_long_beam_oam[5];
extern struct FrameData particle_hitting_something_with_ice_beam_oam[6];
extern struct FrameData particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam[7];
extern struct FrameData particle_hitting_something_with_plasma_beam_full_beam_oam[8];
extern struct FrameData particle_hitting_something_invincible_oam[6];
extern struct FrameData particle_hitting_something_with_missile_oam[8];
extern struct FrameData particle_hitting_something_with_super_missile_oam[8];
extern struct FrameData particle_sprite_explosion_huge_oam[14];
extern struct FrameData particle_small_dust_oam[7];
extern struct FrameData particle_medium_dust_oam[10];
extern struct FrameData particle_two_medium_dust_oam[11];
extern struct FrameData particle_sprite_explosion_small_oam[12];
extern struct FrameData particle_sprite_explosion_medium_oam[18];
extern struct FrameData particle_sprite_explosion_big_oam[18];
extern struct FrameData particle_sprite_explosion_single_then_big_oam[17];
extern struct FrameData particle_screw_attack_destroyed_oam[9];
extern struct FrameData particle_shinespark_destroyed_oam[11];
extern struct FrameData particle_sudo_screw_destroyed_oam[9];
extern struct FrameData particle_speedbooster_destroyed_oam[9];
extern struct FrameData particle_freezing_sprite_with_ice_oam[17];
extern struct FrameData particle_freezing_sprite_with_charged_ice_oam[16];
extern struct FrameData particle_main_boss_death_oam[18];
extern struct FrameData WaterDrop_oam[8];
extern struct FrameData WaterDrop_oam_falling[2];
extern struct FrameData WaterDrop_oam_splashing[6];
const struct FrameData sprite_debris_oam[5];
extern struct FrameData sprite_debris_oam_unused[7];

/* blob_0x833bd34_0x833cbdf.c */

extern u8 blob_0x833bd34_0x833cbdf[3756];

/* particle_splash_data.c */

extern struct FrameData particle_sprite_splash_water_big_oam[10];
extern struct FrameData particle_sprite_splash_water_huge_oam[10];
extern struct FrameData particle_sprite_splash_water_small_oam[7];
extern struct FrameData particle_sprite_splash_lava_big_oam[10];
extern struct FrameData particle_sprite_splash_lava_huge_oam[10];
extern struct FrameData particle_sprite_splash_lava_small_oam[7];
extern struct FrameData particle_sprite_splash_acid_big_oam[10];
extern struct FrameData particle_sprite_splash_acid_huge_oam[10];
extern struct FrameData particle_sprite_splash_acid_small_oam[7];

/* blob_0x833d75c_0x8345cc8.c */

extern u8 blob_0x83d75c_0x8345cc8[34156];

/* bldalpha_data.c */

extern u16 bldalpha_values_for_clipdata[11];

/* blob_0x8345cde_0x875e6a7.c */

extern u8 blob_0x8345cde_0x875e6a7[4295113];

/* blob_0x875ebf8_0x875f1e7.c */

extern u8 blob_0x875ebf8_0x875f1e7[1520];

/* blob_0x875f31c_0x875f973.c */

extern u8 blob_0x875f31c_0x875f973[16234];

/* particle_pointers.c */

ParticleFunc_T process_particle_functions_pointer[61];

#endif /* DATA_H */
