#ifndef DATA_H
#define DATA_H

#include "../src/oam.h"
#include "../src/types.h"
#include "../src/samus.h"
#include "../src/particle.h"
#include "../src/projectile.h"
#include "../src/sprites_AI/unused_sprites.h"
#include "../src/sprites_AI/charge_beam.h"
#include "../src/sprites_AI/deorem.h"
#include "../src/sprites_AI/dragon.h"
#include "../src/sprites_AI/elevator_pad.h"
#include "../src/sprites_AI/enemy_drop.h"
#include "../src/sprites_AI/explosion_zebes_escape.h"
#include "../src/sprites_AI/geruta.h"
#include "../src/sprites_AI/hive.h"
#include "../src/sprites_AI/imago_cocoon.h"
#include "../src/sprites_AI/map_station.h"
#include "../src/sprites_AI/metroid.h"
#include "../src/sprites_AI/item_banner.h"
#include "../src/sprites_AI/zoomer.h"
#include "../src/sprites_AI/zeela.h"
#include "../src/sprites_AI/ripper.h"
#include "../src/sprites_AI/zeb.h"
#include "../src/sprites_AI/skree.h"
#include "../src/sprites_AI/morph_ball.h"
#include "../src/sprites_AI/chozo_statue.h"
#include "../src/sprites_AI/sova.h"
#include "../src/sprites_AI/multiviola.h"
#include "../src/sprites_AI/squeept.h"
#include "../src/sprites_AI/reo.h"
#include "../src/sprites_AI/gunship.h"
#include "../src/sprites_AI/skultera.h"
#include "../src/sprites_AI/dessgeega.h"
#include "../src/sprites_AI/waver.h"
#include "../src/sprites_AI/power_grip.h"
#include "../src/sprites_AI/imago_larva.h"
#include "../src/sprites_AI/morph_ball_launcher.h"
#include "../src/sprites_AI/space_pirate.h"
#include "../src/sprites_AI/gamet.h"
#include "../src/sprites_AI/zebbo.h"
#include "../src/sprites_AI/worker_robot.h"
#include "../src/sprites_AI/parasite.h"
#include "../src/sprites_AI/piston.h"
#include "../src/sprites_AI/ridley.h"
#include "../src/sprites_AI/security_gate.h"
#include "../src/sprites_AI/zipline_generator.h"
#include "../src/sprites_AI/polyp.h"
#include "../src/sprites_AI/rinka.h"
#include "../src/sprites_AI/viola.h"
#include "../src/sprites_AI/geron_norfair.h"
#include "../src/sprites_AI/holtz.h"
#include "../src/sprites_AI/gekitai_machine.h"
#include "../src/sprites_AI/ruins_test.h"
#include "../src/sprites_AI/save_platform.h"
#include "../src/sprites_AI/kraid.h"
#include "../src/sprites_AI/ripper2.h"
#include "../src/sprites_AI/mella.h"
#include "../src/sprites_AI/atomic.h"
#include "../src/sprites_AI/area_banner.h"
#include "../src/sprites_AI/mother_brain.h"
#include "../src/sprites_AI/acid_worm.h"
#include "../src/sprites_AI/escape_ship.h"
#include "../src/sprites_AI/sidehopper.h"
#include "../src/sprites_AI/geega.h"
#include "../src/sprites_AI/zebetite_and_cannon.h"
#include "../src/sprites_AI/zipline.h"
#include "../src/sprites_AI/imago_larva_right_side.h"
#include "../src/sprites_AI/tangle_vine.h"
#include "../src/sprites_AI/imago.h"
#include "../src/sprites_AI/crocomire.h"
#include "../src/sprites_AI/geron.h"
#include "../src/sprites_AI/glass_tube.h"
#include "../src/sprites_AI/save_platform_chozodia.h"
#include "../src/sprites_AI/baristute.h"
#include "../src/sprites_AI/elevator_statue.h"
#include "../src/sprites_AI/rising_chozo_pillar.h"
#include "../src/sprites_AI/security_laser.h"
#include "../src/sprites_AI/boss_statues.h"
#include "../src/sprites_AI/searchlight_eye.h"
#include "../src/sprites_AI/steam.h"
#include "../src/sprites_AI/unknown_item_block.h"
#include "../src/sprites_AI/unknown_item_chozo_statue.h"
#include "../src/sprites_AI/chozo_ball.h"
#include "../src/sprites_AI/gadora.h"
#include "../src/sprites_AI/searchlight.h"
#include "../src/sprites_AI/primary_sprite_B3.h"
#include "../src/sprites_AI/space_pirate_carrying_power_bomb.h"
#include "../src/sprites_AI/water_drop.h"
#include "../src/sprites_AI/falling_chozo_pillar.h"
#include "../src/sprites_AI/mecha_ridley.h"
#include "../src/sprites_AI/escape_gate.h"
#include "../src/sprites_AI/black_space_pirate.h"
#include "../src/sprites_AI/escape_ship_pirate.h"
#include "../src/sprites_AI/chozo_statue_movement.h"

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

/* tumbling_missile_speed_data.c */

extern i16 tumbling_missile_speed[48];

/* bomb_data.c */

extern u16 bomb_oam_normal1[4];
extern u16 bomb_oam_normal2[4];
extern u16 bomb_oam_normal3[4];
extern u16 bomb_oam_normal4[4];
extern u16 bomb_oam_fast1[4];
extern u16 bomb_oam_fast2[4];
extern u16 bomb_oam_fast3[4];
extern u16 bomb_oam_fast4[4];
extern u16 power_bomb_oam_normal1[4];
extern u16 power_bomb_oam_normal2[4];
extern u16 power_bomb_oam_normal3[4];
extern u16 power_bomb_oam_fast1[4];
extern u16 power_bomb_oam_fast2[4];
extern u16 power_bomb_oam_fast3[4];
extern struct FrameData bomb_oam_normal[5];
extern struct FrameData bomb_oam_fast[5];
extern struct FrameData power_bomb_oam_normal[4];
extern struct FrameData power_bomb_oam_fast[4];

/* missiles_data.c */

extern struct FrameData missile_oam_forward[3];
extern struct FrameData missile_oam_diagonal[3];
extern struct FrameData missile_oam_up_down[3];
extern struct FrameData super_missile_oam_forward[3];
extern struct FrameData super_missile_oam_diagonal[3];
extern struct FrameData super_missile_oam_up_down[3];
extern struct FrameData missile_tumbling_oam[9];
extern struct FrameData super_missile_tumbling_oam[9];
extern struct FrameData particle_missile_trail_oam[8];
extern struct FrameData particle_super_missile_trail_oam[9];

/* beam_palette_data.c */

extern u16 beam_pal[96];

/* normal_beam_data.c */

extern struct FrameData normal_beam_oam_forward[3];
extern struct FrameData normal_beam_oam_diagonal[3];
extern struct FrameData normal_beam_oam_up_down[3];
extern struct FrameData normal_beam_oam_unused1[3];
extern struct FrameData normal_beam_oam_unused2[3];
extern struct FrameData normal_beam_oam_unused3[3];
extern struct FrameData charged_normal_beam_oam_forward[3];
extern struct FrameData charged_normal_beam_oam_diagonal[3];
extern struct FrameData charged_normal_beam_oam_up_down[3];
extern struct FrameData normal_beam_oam_unused4[5];

/* long_beam_data.c */

extern struct FrameData long_beam_oam_forward[3];
extern struct FrameData long_beam_oam_diagonal[3];
extern struct FrameData long_beam_oam_up_down[3];
extern struct FrameData charged_long_beam_oam_forward[3];
extern struct FrameData charged_long_beam_oam_diagonal[3];
extern struct FrameData charged_long_beam_oam_up_down[3];
extern struct FrameData particle_charged_long_beam_trail_oam[5];

/* ice_beam_data.c */

extern struct FrameData ice_beam_oam_forward[3];
extern struct FrameData ice_beam_oam_diagonal[3];
extern struct FrameData ice_beam_oam_up_down[3];
extern struct FrameData ice_beam_oam_unused1[3];
extern struct FrameData ice_beam_oam_unused2[3];
extern struct FrameData ice_beam_oam_unused3[3];
extern struct FrameData charged_ice_beam_oam_forward[3];
extern struct FrameData charged_ice_beam_oam_diagonal[3];
extern struct FrameData charged_ice_beam_oam_up_down[3];
extern struct FrameData particle_charged_ice_beam_trail_oam[5];

/* wave_beam_data.c */

extern struct FrameData wave_beam_oam_forward[8];
extern struct FrameData wave_beam_oam_diagonal[8];
extern struct FrameData wave_beam_oam_up_down[8];
extern struct FrameData wave_beam_oam_unused1[8];
extern struct FrameData wave_beam_oam_unused2[8];
extern struct FrameData wave_beam_oam_unused3[8];
extern struct FrameData charged_wave_beam_oam_forward[8];
extern struct FrameData charged_wave_beam_oam_diagonal[8];
extern struct FrameData charged_wave_beam_oam_up_down[8];
extern struct FrameData particle_charged_wave_beam_trail_oam[5];

/* plasma_beam_data.c */


extern struct FrameData plasma_beam_no_wave_oam_forward[3];
extern struct FrameData plasma_beam_no_wave_oam_diagonal[3];
extern struct FrameData plasma_beam_no_wave_oam_up_down[3];
extern struct FrameData plasma_beam_no_wave_oam_unused1[3];
extern struct FrameData plasma_beam_no_wave_oam_unused2[3];
extern struct FrameData plasma_beam_no_wave_oam_unused3[3];
extern struct FrameData charged_plasma_beam_no_wave_oam_forward[3];
extern struct FrameData charged_plasma_beam_no_wave_oam_diagonal[3];
extern struct FrameData charged_plasma_beam_no_wave_oam_up_down[3];
extern struct FrameData plasma_beam_wave_oam_forward[8];
extern struct FrameData plasma_beam_wave_oam_diagonal[8];
extern struct FrameData plasma_beam_wave_oam_up_down[8];
extern struct FrameData plasma_beam_wave_oam_unused1[6];
extern struct FrameData plasma_beam_wave_oam_unused2[6];
extern struct FrameData plasma_beam_wave_oam_unused3[6];
extern struct FrameData charged_plasma_beam_wave_oam_forward[8];
extern struct FrameData charged_plasma_beam_wave_oam_diagonal[8];
extern struct FrameData charged_plasma_beam_wave_oam_up_down[8];
extern struct FrameData particle_charged_plasma_beam_trail_oam[5];
extern struct FrameData particle_charged_full_beam_trail_oam[9];

/* pistol_data.c */

extern struct FrameData pistol_oam_forward[3];
extern struct FrameData pistol_oam_diagonal[3];
extern struct FrameData pistol_oam_up_down[3];
extern struct FrameData charged_pistol_oam_forward[3];
extern struct FrameData charged_pistol_oam_diagonal[3];
extern struct FrameData charged_pistol_oam_up_down[3];
extern struct FrameData particle_charged_pistol_trail_oam[5];

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

/* projectile_pointers.c */

ProjFunc_T process_projectile_functions_pointers[16];

/* particle_pointers.c */

ParticleFunc_T process_particle_functions_pointer[61];

#endif /* DATA_H */
