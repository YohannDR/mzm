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
#include "../src/sprites_AI/unknown_item_chozo_statue.h"
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
#include "../src/sprites_AI/zebetite.h"
#include "../src/sprites_AI/cannon.h"
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
#include "../src/sprites_AI/chozo_ball.h"
#include "../src/sprites_AI/chozo_statue_movement.h"

/* generic_data.c */

i16 sSineYValues[320];
u8 random_number_table[256];

/* blob_0x808ca9c_0x8239463.c */

u8 blob_0x808ca9c_0x8239463[1755592];

/* samus_visual_data.c */

u8 samus_visual_data[68][3];

/* blob_0x8239530_0x823a533.c */

u8 blob_0x8239530_0x823a533[4100];

/* samus_hitbox_draw_data.c */

u16 samus_draw_distance_offsets[4][4];
i16 samus_hitbox_data[4][3];
u8 samus_environmental_effects_oam_pointers[72];
u16 SamusPullingSelfUp_velocity[4];

/* blob_0x823a5bc_0x82b0cab.c */

u8 blob_0x823a5bc_0x82b0cab[485104];

/* sprite_stats.c */

u8 sRandomTable0_F[56];
i16 dessgeega_sidehopper_in_block_yVelocity[16];
i16 sSpritesFallingSpeed[40];
i16 worker_robot_sleeping_falling_speed[10];
u16 sPrimarySpriteStats[206][9];
u16 sSecondarySpriteStats[77][9];

/* blob_0x82b214e_0x82b2523.c */

u8 blob_0x82b214e_0x82b2523[982];

/* sprite_debris_data.c */

i16 debris_bouncing_velocity[9];
i16 debris_11_velocity[9];
i16 debris_12_velocity[9];
i16 debris_13_velocity[9];
i16 debris_4_velocity[9];
i16 debris_5_velocity[9];
i16 debris_6_velocity[9];
i16 debris_7_velocity[9];
i16 debris_8_velocity[9];

/* enemy_drop_data.c */

u16 small_energy_drop_oam1[4];
u16 small_energy_drop_oam2[4];
u16 small_energy_drop_oam3[4];
u16 small_energy_drop_oam4[4];
u16 large_energy_drop_oam1[4];
u16 large_energy_drop_oam2[4];
u16 large_energy_drop_oam3[4];
u16 large_energy_drop_oam4[4];
u16 missile_drop_oam1[4];
u16 missile_drop_oam2[4];
u16 super_missile_drop_oam1[4];
u16 super_missile_drop_oam2[4];
u16 power_bomb_drop_oam1[4];
u16 power_bomb_drop_oam2[4];
u16 multiple_large_energy_drop_slot1_oam1[10];
u16 multiple_large_energy_drop_slot1_oam2[10];
u16 multiple_large_energy_drop_slot1_oam3[10];
u16 multiple_large_energy_drop_slot1_oam4[10];
u16 multiple_large_energy_drop_slot3_oam1[10];
u16 multiple_large_energy_drop_slot3_oam2[10];
u16 multiple_large_energy_drop_slot3_oam3[10];
u16 multiple_large_energy_drop_slot3_oam4[10];
u16 multiple_large_energy_drop_slot2_oam1[10];
u16 multiple_large_energy_drop_slot2_oam2[10];
u16 multiple_large_energy_drop_slot2_oam3[10];
u16 multiple_large_energy_drop_slot2_oam4[10];
struct FrameData small_energy_drop_oam[5];
struct FrameData large_energy_drop_oam[5];
struct FrameData missile_drop_oam[3];
struct FrameData super_missile_drop_oam[3];
struct FrameData power_bomb_drop_oam[3];
struct FrameData multiple_large_energy_drop_slot1_oam[5];
struct FrameData multiple_large_energy_drop_slot3_oam[5];
struct FrameData multiple_large_energy_drop_slot2_oam[5];

/* unused_sprites_data.c */

u16 unused_sprites_oam1[4];
u16 unused_sprites_oam2[4];
u16 unused_sprites_oam4[4];
struct FrameData unused_sprites_oam[5];
u8 unused_sprites_gfx[24];
u16 unused_sprites_pal[16];

/* morph_ball_data.c */

u8 morph_ball_gfx[672];
u16 morph_ball_pal[16];
u16 morph_ball_oam1[4];
u16 morph_ball_oam2[4];
u16 morph_ball_oam3[4];
u16 morph_ball_oam4[4];
u16 morph_ball_outside_oam1[4];
u16 morph_ball_outside_oam2[4];
u16 morph_ball_outside_oam3[4];
u16 morph_ball_outside_oam4[4];
u16 morph_ball_outside_oam5[4];
struct FrameData morph_ball_oam[5];
struct FrameData morph_ball_outside_oam[6];

/* PowerGrip_data.c */

u8 PowerGrip_gfx[1116];
u16 PowerGrip_pal[32];
u16 PowerGrip_oam1[4];
u16 PowerGrip_oam2[4];
u16 PowerGrip_oam3[4];
u16 PowerGrip_oam4[4];
u16 PowerGrip_glow_oam1[10];
u16 PowerGrip_glow_oam2[4];
u16 PowerGrip_glow_oam3[10];
u16 PowerGrip_glow_oam4[4];
u16 PowerGrip_glow_oam5[10];
u16 PowerGrip_glow_oam6[4];
u16 PowerGrip_glow_oam7[10];
u16 PowerGrip_glow_oam8[4];
u16 PowerGrip_glow_oam9[10];
u16 PowerGrip_glow_oam10[4];
u16 PowerGrip_glow_oam11[10];
u16 PowerGrip_glow_oam12[4];
u16 PowerGrip_glow_oam13[10];
u16 PowerGrip_glow_oam14[4];
struct FrameData PowerGrip_oam[5];
struct FrameData PowerGrip_glow_oam[15];

/* charge_beam_data.c */

i16 charge_beam_yPosition_offsets[66];
u8 charge_beam_gfx[972];
u16 charge_beam_pal[16];
u16 charge_beam_oam_visible1[4];
u16 charge_beam_oam_visible2[4];
u16 charge_beam_oam_visible3[7];
u16 charge_beam_oam_visible4[4];
u16 charge_beam_oam1[13];
u16 charge_beam_oam2[28];
u16 charge_beam_oam3[28];
u16 charge_beam_oam4[40];
u16 charge_beam_oam5[43];
u16 charge_beam_oam6[40];
u16 charge_beam_oam7[28];
u16 charge_beam_oam8[28];
u16 charge_beam_oam9[49];
u16 charge_beam_oam10[49];
u16 charge_beam_oam11[52];
u16 charge_beam_oam12[4];
u16 charge_beam_glow_oam1[10];
u16 charge_beam_glow_oam2[4];
u16 charge_beam_glow_oam3[10];
u16 charge_beam_glow_oam4[4];
u16 charge_beam_glow_oam5[10];
u16 charge_beam_glow_oam6[4];
u16 charge_beam_glow_oam7[10];
u16 charge_beam_glow_oam8[4];
u16 charge_beam_glow_oam9[10];
u16 charge_beam_glow_oam10[4];
u16 charge_beam_glow_oam11[10];
u16 charge_beam_glow_oam12[4];
u16 charge_beam_glow_oam13[10];
u16 charge_beam_glow_oam14[4];
struct FrameData charge_beam_oam_visible[5];
struct FrameData charge_beam_oam[13];
struct FrameData charge_beam_glow_oam[15];

/* skree_data.c */

i16 skree_falling_speed[8];
u8 skree_gfx[1056];
u16 skree_pal[16];
u8 skree_blue_gfx[1056];
u16 skree_blue_pal[16];
u16 skree_oam_11[13];
u16 skree_oam_12[7];
u16 skree_oam_13[13];
u16 skree_oam_14[7];
u16 skree_oam_21[13];
u16 skree_oam_22[13];
u16 skree_oam_23[13];
u16 skree_oam_24[13];
u16 skree_oam_25[13];
u16 skree_oam_31[13];
u16 skree_oam_32[7];
u16 skree_oam_33[13];
u16 skree_oam_34[7];
u16 skree_oam_41[13];
u16 skree_oam_42[7];
u16 skree_oam_43[13];
u16 skree_oam_44[7];
u16 skree_oam_51[13];
u16 skree_oam_52[7];
u16 skree_oam_53[13];
u16 skree_oam_54[7];
u16 skree_oam_61[13];
u16 skree_oam_62[13];
u16 skree_oam_63[13];
u16 skree_oam_64[13];
u16 skree_oam_65[13];
u16 skree_oam_71[13];
u16 skree_oam_72[7];
u16 skree_oam_73[13];
u16 skree_oam_74[7];
u16 skree_oam_81[13];
u16 skree_oam_82[7];
u16 skree_oam_83[13];
u16 skree_oam_84[7];
u16 skree_oam_91[10];
u16 skree_oam_92[7];
u16 skree_oam_93[4];
u16 skree_oam_101[10];
u16 skree_oam_102[10];
u16 skree_oam_103[7];
struct FrameData skree_oam_1[5];
struct FrameData skree_oam_2[6];
struct FrameData skree_oam_3[5];
struct FrameData skree_oam_4[5];
struct FrameData skree_oam_5[5];
struct FrameData skree_oam_6[6];
struct FrameData skree_oam_7[5];
struct FrameData skree_oam_8[5];
struct FrameData skree_oam_9[4];
struct FrameData skree_oam_10[4];

/* blob_0x82cd604_0x82f7db3.c */

u8 blob_0x82cd604_0x82f7db3[174000];

/* area_banner_data.c */

u16 area_banner_location_text_pal[16];

/* blob_0x82f7dd4_0x82fd107.c */

u8 blob_0x82f7dd4_0x82fd107[21300];

/* geron_data.c */

u16 GeronNorfair_oam1[43];
u16 GeronNorfair_oam2[43];
u16 GeronNorfair_oam3[43];
u16 GeronNorfair_oam4[43];
u16 GeronNorfair_oam5[43];
u16 GeronNorfair_oam6[46];
u16 GeronNorfair_oam7[46];
u16 GeronNorfair_oam8[40];
u16 GeronNorfair_oam9[43];
u16 GeronNorfair_oam10[43];
struct FrameData GeronNorfair_oam[11];
u8 geron_gfx[612];
u16 geron_pal[16];

/* blob_0x82fd79c_0x830d55b.c */

u8 blob_0x82fd79c_0x830d55b[64960];

/* glass_tube_data.c */

u16 glass_tube_oam1[37];
u16 glass_tube_oam_cracking1[37];
u16 glass_tube_oam_cracking2[49];
u16 glass_tube_oam_cracking3[55];
u16 glass_tube_oam_cracking4[73];
u16 glass_tube_oam_cracking5[85];
u16 glass_tube_oam_cracking6[106];
u16 glass_tube_oam_cracking7[115];
u16 glass_tube_oam_cracking8[127];
u16 glass_tube_oam_cracking9[142];
u16 glass_tube_oam_cracking10[157];
u16 glass_tube_oam_cracking11[172];
u16 glass_tube_oam_breaking1[172];
u16 glass_tube_oam_breaking2[172];
u16 glass_tube_oam_breaking3[172];
u16 glass_tube_oam_breaking4[172];
u16 glass_tube_oam_breaking5[172];
u16 glass_tube_oam_breaking6[172];
u16 glass_tube_oam_breaking7[172];
u16 glass_tube_oam_breaking8[163];
u16 glass_tube_oam_breaking9[157];
u16 glass_tube_oam_breaking10[139];
u16 glass_tube_oam_breaking11[133];
u16 glass_tube_oam_breaking12[115];
u16 glass_tube_oam_breaking13[94];
u16 glass_tube_oam_breaking14[85];
u16 glass_tube_oam_breaking15[70];
u16 glass_tube_oam_breaking16[52];
u16 glass_tube_oam_breaking17[31];
u16 glass_tube_oam_breaking18[25];
u16 glass_tube_oam_broken1[19];
struct FrameData glass_tube_oam[2];
struct FrameData glass_tube_oam_cracking[12];
struct FrameData glass_tube_oam_breaking[19];
struct FrameData glass_tube_oam_broken[2];
u8 glass_tube_gfx[2208];
u16 glass_tube_pal[64];

/* blob_0x830df94_0x8312b97.c */

u8 blob_0x830df94_0x8312b97[19460];

/* rising_chozo_pillar_data.c */

u8 rising_chozo_pillar_gfx[2684];
u16 rising_chozo_pillar_pal[64];
u16 chozo_pillar_platform_oam_spawning1[7];
u16 chozo_pillar_platform_oam_spawning2[7];
u16 chozo_pillar_platform_oam_spawning3[7];
u16 chozo_pillar_platform_oam_spawning4[7];
u16 chozo_pillar_platform_oam_spawning5[7];
u16 chozo_pillar_platform_oam_spawning6[10];
u16 chozo_pillar_platform_oam_spawning7[10];
u16 chozo_pillar_platform_oam_spawning8[10];
u16 chozo_pillar_platform_oam_spawning9[10];
u16 chozo_pillar_platform_oam_spawning10[10];
u16 chozo_pillar_platform_oam_spawning11[13];
u16 chozo_pillar_platform_oam_spawning12[10];
u16 chozo_pillar_platform_oam_spawning13[10];
u16 chozo_pillar_platform_oam_spawning14[10];
u16 chozo_pillar_platform_oam_spawning15[10];
u16 chozo_pillar_platform_oam_spawning16[13];
u16 chozo_pillar_platform_oam_spawning17[10];
u16 chozo_pillar_platform_oam_spawning18[10];
u16 chozo_pillar_platform_oam_spawning19[10];
u16 chozo_pillar_platform_oam_spawning20[10];
u16 chozo_pillar_platform_oam_spawning21[10];
u16 chozo_pillar_platform_oam_spawning22[7];
u16 chozo_pillar_platform_oam_spawning23[19];
u16 chozo_pillar_platform_oam_spawning24[19];
u16 chozo_pillar_platform_oam_spawning25[7];
u16 chozo_pillar_platform_slot1_oam_spawned1[7];
u16 chozo_pillar_platform_slot1_oam_spawning1[4];
u16 chozo_pillar_platform_slot1_oam_spawning2[4];
u16 chozo_pillar_platform_slot1_oam_spawning3[4];
u16 chozo_pillar_platform_slot1_oam_spawning4[4];
u16 chozo_pillar_platform_slot1_oam_spawning5[4];
u16 chozo_pillar_platform_slot1_oam_spawning6[7];
u16 chozo_pillar_platform_slot1_oam_spawning7[7];
u16 chozo_pillar_platform_slot1_oam_spawning8[7];
u16 chozo_pillar_platform_slot1_oam_spawning9[7];
u16 chozo_pillar_platform_slot1_oam_spawning10[7];
u16 chozo_pillar_platform_slot1_oam_spawning11[10];
u16 chozo_pillar_platform_slot1_oam_spawning12[7];
u16 chozo_pillar_platform_slot1_oam_spawning13[7];
u16 chozo_pillar_platform_slot1_oam_spawning14[7];
u16 chozo_pillar_platform_slot1_oam_spawning15[7];
u16 chozo_pillar_platform_slot1_oam_spawning16[10];
u16 chozo_pillar_platform_slot1_oam_spawning17[7];
u16 chozo_pillar_platform_slot1_oam_spawning18[7];
u16 chozo_pillar_platform_slot1_oam_spawning19[7];
u16 chozo_pillar_platform_slot1_oam_spawning20[7];
u16 chozo_pillar_platform_slot1_oam_spawning21[7];
u16 chozo_pillar_platform_slot1_oam_spawning22[4];
u16 chozo_pillar_platform_slot1_oam_spawning23[16];
u16 chozo_pillar_platform_slot1_oam_spawning24[16];
u16 chozo_pillar_platform_slot1_oam_spawning25[4];
u16 chozo_pillar_platform_slot1_oam_spawning26[4];
u16 chozo_pillar_platform_slot1_oam_spawning27[4];
u16 chozo_pillar_platform_oam_spawned1[4];
u16 ChozoPillarPlatformShadow_oam1[4];
u16 ChozoPillarPlatformShadow_oam2[4];
u16 ChozoPillarPlatformShadow_oam3[4];
struct FrameData chozo_pillar_platform_oam_spawning[25];
struct FrameData chozo_pillar_platform_slot1_oam_spawned[2];
struct FrameData chozo_pillar_platform_slot1_oam_spawning[28];
struct FrameData chozo_pillar_platform_oam_spawned[2];
struct FrameData ChozoPillarPlatformShadow_oam[4];

/* blob_0x8313c4c_0x8326ca7.c */

u8 blob_0x8313c4c_0x8326ca7[77915];

/* tumbling_missile_speed_data.c */

i16 tumbling_missile_speed[48];

/* bomb_data.c */

u16 bomb_oam_normal1[4];
u16 bomb_oam_normal2[4];
u16 bomb_oam_normal3[4];
u16 bomb_oam_normal4[4];
u16 bomb_oam_fast1[4];
u16 bomb_oam_fast2[4];
u16 bomb_oam_fast3[4];
u16 bomb_oam_fast4[4];
u16 power_bomb_oam_normal1[4];
u16 power_bomb_oam_normal2[4];
u16 power_bomb_oam_normal3[4];
u16 power_bomb_oam_fast1[4];
u16 power_bomb_oam_fast2[4];
u16 power_bomb_oam_fast3[4];
struct FrameData bomb_oam_normal[5];
struct FrameData bomb_oam_fast[5];
struct FrameData power_bomb_oam_normal[4];
struct FrameData power_bomb_oam_fast[4];

/* missiles_data.c */

u16 missile_oam_forward1[7];
u16 missile_oam_forward2[7];
u16 missile_oam_diagonal1[7];
u16 missile_oam_diagonal2[7];
u16 missile_oam_up_down1[7];
u16 missile_oam_up_down2[7];
u16 super_missile_oam_forward1[7];
u16 super_missile_oam_forward2[7];
u16 super_missile_oam_diagonal1[7];
u16 super_missile_oam_diagonal2[7];
u16 super_missile_oam_up_down1[7];
u16 super_missile_oam_up_down2[7];
u16 missile_tumbling_oam1[4];
u16 missile_tumbling_oam2[4];
u16 missile_tumbling_oam3[4];
u16 missile_tumbling_oam4[4];
u16 missile_tumbling_oam5[4];
u16 missile_tumbling_oam6[4];
u16 missile_tumbling_oam7[4];
u16 missile_tumbling_oam8[4];
u16 super_missile_tumbling_oam1[4];
u16 super_missile_tumbling_oam2[4];
u16 super_missile_tumbling_oam3[4];
u16 super_missile_tumbling_oam4[4];
u16 super_missile_tumbling_oam5[4];
u16 super_missile_tumbling_oam6[4];
u16 super_missile_tumbling_oam7[4];
u16 super_missile_tumbling_oam8[4];
u16 particle_missile_trail_oam1[4];
u16 particle_missile_trail_oam2[4];
u16 particle_missile_trail_oam3[4];
u16 particle_missile_trail_oam4[4];
u16 particle_missile_trail_oam5[4];
u16 particle_missile_trail_oam6[4];
u16 particle_missile_trail_oam7[4];
u16 particle_super_missile_trail_oam1[4];
u16 particle_super_missile_trail_oam2[4];
u16 particle_super_missile_trail_oam3[4];
u16 particle_super_missile_trail_oam4[4];
u16 particle_super_missile_trail_oam5[4];
u16 particle_super_missile_trail_oam6[4];
u16 particle_super_missile_trail_oam7[4];
u16 particle_super_missile_trail_oam8[4];
struct FrameData missile_oam_forward[3];
struct FrameData missile_oam_diagonal[3];
struct FrameData missile_oam_up_down[3];
struct FrameData super_missile_oam_forward[3];
struct FrameData super_missile_oam_diagonal[3];
struct FrameData super_missile_oam_up_down[3];
struct FrameData missile_tumbling_oam[9];
struct FrameData super_missile_tumbling_oam[9];
struct FrameData particle_missile_trail_oam[8];
struct FrameData particle_super_missile_trail_oam[9];

/* beam_palette_data.c */

u16 beam_pal[96];

/* normal_beam_data.c */

u8 normal_beam_gfx[2048];
u16 normal_beam_oam_forward1[4];
u16 normal_beam_oam_forward2[4];
u16 normal_beam_oam_diagonal1[4];
u16 normal_beam_oam_diagonal2[4];
u16 normal_beam_oam_up_down1[4];
u16 normal_beam_oam_up_down2[4];
u16 normal_beam_oam_unused11[4];
u16 normal_beam_oam_unused12[4];
u16 normal_beam_oam_unused21[4];
u16 normal_beam_oam_unused22[4];
u16 normal_beam_oam_unused31[4];
u16 normal_beam_oam_unused32[4];
u16 charged_normal_beam_oam_forward1[7];
u16 charged_normal_beam_oam_forward2[10];
u16 charged_normal_beam_oam_diagonal1[7];
u16 charged_normal_beam_oam_diagonal2[10];
u16 charged_normal_beam_oam_up_down1[7];
u16 charged_normal_beam_oam_up_down2[10];
u16 normal_beam_oam_unused41[4];
u16 normal_beam_oam_unused42[4];
u16 normal_beam_oam_unused43[4];
u16 normal_beam_oam_unused44[4];
struct FrameData normal_beam_oam_forward[3];
struct FrameData normal_beam_oam_diagonal[3];
struct FrameData normal_beam_oam_up_down[3];
struct FrameData normal_beam_oam_unused1[3];
struct FrameData normal_beam_oam_unused2[3];
struct FrameData normal_beam_oam_unused3[3];
struct FrameData charged_normal_beam_oam_forward[3];
struct FrameData charged_normal_beam_oam_diagonal[3];
struct FrameData charged_normal_beam_oam_up_down[3];
struct FrameData normal_beam_oam_unused4[5];

/* long_beam_data.c */

u8 long_normal_beam_gfx[2048];
u16 long_beam_oam_forward1[4];
u16 long_beam_oam_forward2[4];
u16 long_beam_oam_diagonal1[4];
u16 long_beam_oam_diagonal2[4];
u16 long_beam_oam_up_down1[4];
u16 long_beam_oam_up_down2[4];
u16 charged_long_beam_oam_forward1[7];
u16 charged_long_beam_oam_forward2[10];
u16 charged_long_beam_oam_diagonal1[7];
u16 charged_long_beam_oam_diagonal2[10];
u16 charged_long_beam_oam_up_down1[7];
u16 charged_long_beam_oam_up_down2[10];
u16 particle_charged_long_beam_trail_oam1[4];
u16 particle_charged_long_beam_trail_oam2[4];
u16 particle_charged_long_beam_trail_oam3[4];
u16 particle_charged_long_beam_trail_oam4[4];
struct FrameData long_beam_oam_forward[3];
struct FrameData long_beam_oam_diagonal[3];
struct FrameData long_beam_oam_up_down[3];
struct FrameData charged_long_beam_oam_forward[3];
struct FrameData charged_long_beam_oam_diagonal[3];
struct FrameData charged_long_beam_oam_up_down[3];
struct FrameData particle_charged_long_beam_trail_oam[5];

/* ice_beam_data.c */

u8 ice_beam_gfx[2048];
u16 ice_beam_oam_forward1[4];
u16 ice_beam_oam_forward2[4];
u16 ice_beam_oam_diagonal1[4];
u16 ice_beam_oam_diagonal2[4];
u16 ice_beam_oam_up_down1[4];
u16 ice_beam_oam_up_down2[4];
u16 ice_beam_oam_unused11[4];
u16 ice_beam_oam_unused12[4];
u16 ice_beam_oam_unused21[4];
u16 ice_beam_oam_unused22[4];
u16 ice_beam_oam_unused31[4];
u16 ice_beam_oam_unused32[4];
u16 charged_ice_beam_oam_forward1[13];
u16 charged_ice_beam_oam_forward2[19];
u16 charged_ice_beam_oam_diagonal1[7];
u16 charged_ice_beam_oam_diagonal2[10];
u16 charged_ice_beam_oam_up_down1[13];
u16 charged_ice_beam_oam_up_down2[19];
u16 particle_charged_ice_beam_trail_oam1[4];
u16 particle_charged_ice_beam_trail_oam2[4];
u16 particle_charged_ice_beam_trail_oam3[4];
u16 particle_charged_ice_beam_trail_oam4[4];
u16 particle_charged_ice_beam_trail_oam5[4];
struct FrameData ice_beam_oam_forward[3];
struct FrameData ice_beam_oam_diagonal[3];
struct FrameData ice_beam_oam_up_down[3];
struct FrameData ice_beam_oam_unused1[3];
struct FrameData ice_beam_oam_unused2[3];
struct FrameData ice_beam_oam_unused3[3];
struct FrameData charged_ice_beam_oam_forward[3];
struct FrameData charged_ice_beam_oam_diagonal[3];
struct FrameData charged_ice_beam_oam_up_down[3];
struct FrameData particle_charged_ice_beam_trail_oam[5];

/* wave_beam_data.c */

u8 wave_beam_gfx[2048];
u16 wave_beam_oam_forward1[4];
u16 wave_beam_oam_forward2[10];
u16 wave_beam_oam_forward3[10];
u16 wave_beam_oam_forward4[7];
u16 wave_beam_oam_forward5[13];
u16 wave_beam_oam_forward6[13];
u16 wave_beam_oam_forward7[10];
u16 wave_beam_oam_diagonal1[4];
u16 wave_beam_oam_diagonal2[10];
u16 wave_beam_oam_diagonal3[10];
u16 wave_beam_oam_diagonal4[7];
u16 wave_beam_oam_diagonal5[13];
u16 wave_beam_oam_diagonal6[13];
u16 wave_beam_oam_diagonal7[10];
u16 wave_beam_oam_up_down1[4];
u16 wave_beam_oam_up_down2[10];
u16 wave_beam_oam_up_down3[10];
u16 wave_beam_oam_up_down4[7];
u16 wave_beam_oam_up_down5[13];
u16 wave_beam_oam_up_down6[13];
u16 wave_beam_oam_up_down7[10];
u16 wave_beam_oam_unused11[4];
u16 wave_beam_oam_unused12[4];
u16 wave_beam_oam_unused13[13];
u16 wave_beam_oam_unused14[13];
u16 wave_beam_oam_unused15[13];
u16 wave_beam_oam_unused16[13];
u16 wave_beam_oam_unused17[13];
u16 wave_beam_oam_unused21[4];
u16 wave_beam_oam_unused22[10];
u16 wave_beam_oam_unused23[13];
u16 wave_beam_oam_unused24[13];
u16 wave_beam_oam_unused25[13];
u16 wave_beam_oam_unused26[13];
u16 wave_beam_oam_unused27[13];
u16 wave_beam_oam_unused31[4];
u16 wave_beam_oam_unused32[10];
u16 wave_beam_oam_unused33[13];
u16 wave_beam_oam_unused34[13];
u16 wave_beam_oam_unused35[13];
u16 wave_beam_oam_unused36[13];
u16 wave_beam_oam_unused37[13];
u16 charged_wave_beam_oam_forward1[4];
u16 charged_wave_beam_oam_forward2[10];
u16 charged_wave_beam_oam_forward3[13];
u16 charged_wave_beam_oam_forward4[7];
u16 charged_wave_beam_oam_forward5[7];
u16 charged_wave_beam_oam_forward6[7];
u16 charged_wave_beam_oam_forward7[7];
u16 charged_wave_beam_oam_diagonal1[7];
u16 charged_wave_beam_oam_diagonal2[19];
u16 charged_wave_beam_oam_diagonal3[25];
u16 charged_wave_beam_oam_diagonal4[13];
u16 charged_wave_beam_oam_diagonal5[13];
u16 charged_wave_beam_oam_diagonal6[13];
u16 charged_wave_beam_oam_diagonal7[13];
u16 charged_wave_beam_oam_up_down1[4];
u16 charged_wave_beam_oam_up_down2[10];
u16 charged_wave_beam_oam_up_down3[13];
u16 charged_wave_beam_oam_up_down4[7];
u16 charged_wave_beam_oam_up_down5[7];
u16 charged_wave_beam_oam_up_down6[7];
u16 charged_wave_beam_oam_up_down7[7];
u16 particle_charged_wave_beam_trail_oam1[4];
u16 particle_charged_wave_beam_trail_oam2[7];
u16 particle_charged_wave_beam_trail_oam3[4];
u16 particle_charged_wave_beam_trail_oam4[7];
struct FrameData wave_beam_oam_forward[8];
struct FrameData wave_beam_oam_diagonal[8];
struct FrameData wave_beam_oam_up_down[8];
struct FrameData wave_beam_oam_unused1[8];
struct FrameData wave_beam_oam_unused2[8];
struct FrameData wave_beam_oam_unused3[8];
struct FrameData charged_wave_beam_oam_forward[8];
struct FrameData charged_wave_beam_oam_diagonal[8];
struct FrameData charged_wave_beam_oam_up_down[8];
struct FrameData particle_charged_wave_beam_trail_oam[5];

/* plasma_beam_data.c */

u8 plasma_beam_gfx[2048];
u16 plasma_beam_no_wave_oam_forward1[4];
u16 plasma_beam_no_wave_oam_forward2[4];
u16 plasma_beam_no_wave_oam_diagonal1[4];
u16 plasma_beam_no_wave_oam_diagonal2[4];
u16 plasma_beam_no_wave_oam_up_down1[4];
u16 plasma_beam_no_wave_oam_up_down2[4];
u16 plasma_beam_no_wave_oam_unused11[13];
u16 plasma_beam_no_wave_oam_unused12[10];
u16 plasma_beam_no_wave_oam_unused21[13];
u16 plasma_beam_no_wave_oam_unused22[10];
u16 plasma_beam_no_wave_oam_unused31[13];
u16 plasma_beam_no_wave_oam_unused32[10];
u16 charged_plasma_beam_no_wave_oam_forward1[10];
u16 charged_plasma_beam_no_wave_oam_forward2[16];
u16 charged_plasma_beam_no_wave_oam_diagonal1[13];
u16 charged_plasma_beam_no_wave_oam_diagonal2[19];
u16 charged_plasma_beam_no_wave_oam_up_down1[13];
u16 charged_plasma_beam_no_wave_oam_up_down2[19];
u16 plasma_beam_wave_oam_forward1[4];
u16 plasma_beam_wave_oam_forward2[10];
u16 plasma_beam_wave_oam_forward3[13];
u16 plasma_beam_wave_oam_forward4[10];
u16 plasma_beam_wave_oam_forward5[16];
u16 plasma_beam_wave_oam_forward6[13];
u16 plasma_beam_wave_oam_forward7[10];
u16 plasma_beam_wave_oam_diagonal1[4];
u16 plasma_beam_wave_oam_diagonal2[10];
u16 plasma_beam_wave_oam_diagonal3[13];
u16 plasma_beam_wave_oam_diagonal4[10];
u16 plasma_beam_wave_oam_diagonal5[16];
u16 plasma_beam_wave_oam_diagonal6[13];
u16 plasma_beam_wave_oam_diagonal7[10];
u16 plasma_beam_wave_oam_up_down1[4];
u16 plasma_beam_wave_oam_up_down2[10];
u16 plasma_beam_wave_oam_up_down3[13];
u16 plasma_beam_wave_oam_up_down4[10];
u16 plasma_beam_wave_oam_up_down5[16];
u16 plasma_beam_wave_oam_up_down6[13];
u16 plasma_beam_wave_oam_up_down7[10];
u16 plasma_beam_wave_oam_unused11[13];
u16 plasma_beam_wave_oam_unused12[13];
u16 plasma_beam_wave_oam_unused13[13];
u16 plasma_beam_wave_oam_unused14[19];
u16 plasma_beam_wave_oam_unused15[13];
u16 plasma_beam_wave_oam_unused21[13];
u16 plasma_beam_wave_oam_unused22[19];
u16 plasma_beam_wave_oam_unused23[13];
u16 plasma_beam_wave_oam_unused24[19];
u16 plasma_beam_wave_oam_unused25[13];
u16 plasma_beam_wave_oam_unused31[13];
u16 plasma_beam_wave_oam_unused32[10];
u16 plasma_beam_wave_oam_unused33[16];
u16 plasma_beam_wave_oam_unused34[16];
u16 plasma_beam_wave_oam_unused35[10];
u16 charged_plasma_beam_wave_oam_forward1[4];
u16 charged_plasma_beam_wave_oam_forward2[13];
u16 charged_plasma_beam_wave_oam_forward3[16];
u16 charged_plasma_beam_wave_oam_forward4[10];
u16 charged_plasma_beam_wave_oam_forward5[13];
u16 charged_plasma_beam_wave_oam_forward6[13];
u16 charged_plasma_beam_wave_oam_forward7[13];
u16 charged_plasma_beam_wave_oam_diagonal1[7];
u16 charged_plasma_beam_wave_oam_diagonal2[19];
u16 charged_plasma_beam_wave_oam_diagonal3[25];
u16 charged_plasma_beam_wave_oam_diagonal4[19];
u16 charged_plasma_beam_wave_oam_diagonal5[19];
u16 charged_plasma_beam_wave_oam_diagonal6[19];
u16 charged_plasma_beam_wave_oam_diagonal7[13];
u16 charged_plasma_beam_wave_oam_up_down1[7];
u16 charged_plasma_beam_wave_oam_up_down2[19];
u16 charged_plasma_beam_wave_oam_up_down3[25];
u16 charged_plasma_beam_wave_oam_up_down4[19];
u16 charged_plasma_beam_wave_oam_up_down5[19];
u16 charged_plasma_beam_wave_oam_up_down6[19];
u16 charged_plasma_beam_wave_oam_up_down7[13];
u16 particle_charged_plasma_beam_trail_oam1[4];
u16 particle_charged_plasma_beam_trail_oam2[13];
u16 particle_charged_plasma_beam_trail_oam3[13];
u16 particle_charged_plasma_beam_trail_oam4[4];
u16 particle_charged_full_beam_trail_oam1[13];
u16 particle_charged_full_beam_trail_oam2[13];
u16 particle_charged_full_beam_trail_oam3[13];
u16 particle_charged_full_beam_trail_oam4[13];
u16 particle_charged_full_beam_trail_oam5[4];
u16 particle_charged_full_beam_trail_oam6[4];
u16 particle_charged_full_beam_trail_oam7[4];
u16 particle_charged_full_beam_trail_oam8[4];
struct FrameData plasma_beam_no_wave_oam_forward[3];
struct FrameData plasma_beam_no_wave_oam_diagonal[3];
struct FrameData plasma_beam_no_wave_oam_up_down[3];
struct FrameData plasma_beam_no_wave_oam_unused1[3];
struct FrameData plasma_beam_no_wave_oam_unused2[3];
struct FrameData plasma_beam_no_wave_oam_unused3[3];
struct FrameData charged_plasma_beam_no_wave_oam_forward[3];
struct FrameData charged_plasma_beam_no_wave_oam_diagonal[3];
struct FrameData charged_plasma_beam_no_wave_oam_up_down[3];
struct FrameData plasma_beam_wave_oam_forward[8];
struct FrameData plasma_beam_wave_oam_diagonal[8];
struct FrameData plasma_beam_wave_oam_up_down[8];
struct FrameData plasma_beam_wave_oam_unused1[6];
struct FrameData plasma_beam_wave_oam_unused2[6];
struct FrameData plasma_beam_wave_oam_unused3[6];
struct FrameData charged_plasma_beam_wave_oam_forward[8];
struct FrameData charged_plasma_beam_wave_oam_diagonal[8];
struct FrameData charged_plasma_beam_wave_oam_up_down[8];
struct FrameData particle_charged_plasma_beam_trail_oam[5];
struct FrameData particle_charged_full_beam_trail_oam[9];

/* pistol_data.c */

u8 pistol_gfx[2048];
u16 pistol_oam_forward1[4];
u16 pistol_oam_forward2[4];
u16 pistol_oam_diagonal1[4];
u16 pistol_oam_diagonal2[4];
u16 pistol_oam_up_down1[4];
u16 pistol_oam_up_down2[4];
u16 charged_pistol_oam_forward1[7];
u16 charged_pistol_oam_forward2[10];
u16 charged_pistol_oam_diagonal1[7];
u16 charged_pistol_oam_diagonal2[10];
u16 charged_pistol_oam_up_down1[7];
u16 charged_pistol_oam_up_down2[10];
u16 particle_charged_pistol_trail_oam1[4];
u16 particle_charged_pistol_trail_oam2[4];
u16 particle_charged_pistol_trail_oam3[4];
u16 particle_charged_pistol_trail_oam4[4];
struct FrameData pistol_oam_forward[3];
struct FrameData pistol_oam_diagonal[3];
struct FrameData pistol_oam_up_down[3];
struct FrameData charged_pistol_oam_forward[3];
struct FrameData charged_pistol_oam_diagonal[3];
struct FrameData charged_pistol_oam_up_down[3];
struct FrameData particle_charged_pistol_trail_oam[5];

/* blob_0x832b9e8_0x832ba07.c */

u8 blob_0x832b9e8_0x832ba07[32];

/* common_gSpriteData.c */

u16 common_sprites_pal[96];
u8 common_sprites_gfx[14336];

/* hud_data.c */

u8 missile_digits_gfx[2304];
u8 power_bomb_digits_gfx[2304];
u8 missile_hud_inactive_gfx[64];
u8 missile_hud_selected_gfx[64];
u8 missile_hud_active_gfx[64];
u8 missile_hud_refill1_gfx[64];
u8 missile_hud_refill2_gfx[64];
u8 missile_hud_refill3_gfx[64];
u8 super_missile_hud_inactive_gfx[64];
u8 super_missile_hud_selected_gfx[64];
u8 super_missile_hud_active_gfx[64];
u8 super_missile_hud_refill1_gfx[64];
u8 super_missile_hud_refill2_gfx[64];
u8 super_missile_hud_refill3_gfx[64];
u8 power_bomb_hud_inactive_gfx[64];
u8 power_bomb_hud_selected_gfx[64];
u8 power_bomb_hud_active_gfx[64];
u8 power_bomb_hud_refill1_gfx[64];
u8 power_bomb_hud_refill2_gfx[64];
u8 power_bomb_hud_refill3_gfx[64];
u8 energy_digits_tens_gfx[10][32];
u8 energy_digits_ones_gfx[10][32];
u8 energy_digits_refill1_tens_gfx[10][32];
u8 energy_digits_refill1_ones_gfx[10][32];
u8 energy_digits_refill2_tens_gfx[10][32];
u8 energy_digits_refill2_ones_gfx[10][32];
u8 energy_digits_refill3_tens_gfx[10][32];
u8 energy_digits_refill3_ones_gfx[10][32];

/* blob_0x8331348_0x8339aa7.c */

u8 blob_0x8331348_0x8339aa7[34656];

/* particle_beam_data.c */

u16 particle_shooting_beam_left_right_oam1[4];
u16 particle_shooting_beam_left_right_oam2[10];
u16 particle_shooting_beam_left_right_oam3[4];
u16 particle_shooting_beam_left_right_oam4[7];
u16 particle_shooting_beam_diagonally_up_oam1[4];
u16 particle_shooting_beam_diagonally_up_oam2[10];
u16 particle_shooting_beam_diagonally_up_oam3[4];
u16 particle_shooting_beam_diagonally_up_oam4[7];
u16 particle_shooting_beam_diagonally_down_oam1[4];
u16 particle_shooting_beam_diagonally_down_oam2[10];
u16 particle_shooting_beam_diagonally_down_oam3[4];
u16 particle_shooting_beam_diagonally_down_oam4[7];
u16 particle_shooting_beam_up_oam1[4];
u16 particle_shooting_beam_up_oam2[10];
u16 particle_shooting_beam_up_oam3[4];
u16 particle_shooting_beam_up_oam4[7];
u16 particle_shooting_beam_down_oam1[4];
u16 particle_shooting_beam_down_oam2[10];
u16 particle_shooting_beam_down_oam3[4];
u16 particle_shooting_beam_down_oam4[7];
u16 particle_bomb_oam1[13];
u16 particle_bomb_oam2[13];
u16 particle_bomb_oam3[13];
u16 particle_bomb_oam4[13];
u16 particle_bomb_oam5[13];
u16 particle_bomb_oam6[13];
u16 particle_beam_trailing_oam1[4];
u16 particle_beam_trailing_oam2[4];
u16 particle_beam_trailing_oam3[4];
u16 particle_beam_trailing_oam4[4];
u16 particle_beam_trailing_oam5[4];
u16 particle_charging_beam_oam_begin1[4];
u16 particle_charging_beam_oam_begin2[4];
u16 particle_charging_beam_oam_begin3[4];
u16 particle_charging_beam_oam_begin4[4];
u16 particle_charging_beam_oam_begin5[4];
u16 particle_charging_beam_oam_begin6[4];
u16 particle_charging_beam_oam_begin7[7];
u16 particle_charging_beam_oam_begin8[4];
u16 particle_charging_beam_oam_begin9[7];
u16 particle_charging_beam_oam_begin10[4];
u16 particle_charging_beam_oam_begin11[7];
u16 particle_charging_beam_oam_begin12[7];
u16 particle_charging_beam_oam_begin13[7];
u16 particle_charging_beam_oam_begin14[7];
u16 particle_charging_beam_oam_begin15[7];
u16 particle_charging_beam_oam_begin16[7];
u16 particle_charging_beam_oam_begin17[16];
u16 particle_charging_beam_oam_begin18[7];
u16 particle_charging_beam_oam_begin19[16];
u16 particle_charging_beam_oam_begin20[7];
u16 particle_charging_beam_oam_begin21[16];
u16 particle_charging_beam_oam_begin22[7];
u16 particle_charging_beam_oam_charged1[16];
u16 particle_charging_beam_oam_charged2[16];
struct FrameData particle_shooting_beam_left_right_oam[5];
struct FrameData particle_shooting_beam_diagonally_up_oam[5];
struct FrameData particle_shooting_beam_diagonally_down_oam[5];
struct FrameData particle_shooting_beam_up_oam[5];
struct FrameData particle_shooting_beam_down_oam[5];
struct FrameData particle_bomb_oam[7];
struct FrameData particle_beam_trailing_oam[6];
struct FrameData particle_charging_beam_oam_begin[23];
struct FrameData particle_charging_beam_oam_charged[3];

/* particle_misc_data.c */

u16 particle_hitting_something_with_base_beam_oam1[4];
u16 particle_hitting_something_with_base_beam_oam2[4];
u16 particle_hitting_something_with_base_beam_oam3[4];
u16 particle_hitting_something_with_base_beam_oam4[4];
u16 particle_hitting_something_with_long_beam_oam1[4];
u16 particle_hitting_something_with_long_beam_oam2[4];
u16 particle_hitting_something_with_long_beam_oam3[7];
u16 particle_hitting_something_with_long_beam_oam4[7];
u16 particle_hitting_something_with_ice_beam_oam1[4];
u16 particle_hitting_something_with_ice_beam_oam2[4];
u16 particle_hitting_something_with_ice_beam_oam3[7];
u16 particle_hitting_something_with_ice_beam_oam4[7];
u16 particle_hitting_something_with_ice_beam_oam5[13];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam1[4];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam2[4];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam3[7];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam4[7];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam5[13];
u16 particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam6[13];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam1[4];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam2[4];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam3[7];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam4[7];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam5[13];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam6[13];
u16 particle_hitting_something_with_plasma_beam_full_beam_oam7[13];
u16 particle_hitting_something_invincible_oam1[4];
u16 particle_hitting_something_invincible_oam2[4];
u16 particle_hitting_something_invincible_oam3[4];
u16 particle_hitting_something_invincible_oam4[4];
u16 particle_hitting_something_invincible_oam5[4];
u16 particle_hitting_something_with_missile_oam1[7];
u16 particle_hitting_something_with_missile_oam2[4];
u16 particle_hitting_something_with_missile_oam3[13];
u16 particle_hitting_something_with_missile_oam4[13];
u16 particle_hitting_something_with_missile_oam5[13];
u16 particle_hitting_something_with_missile_oam6[13];
u16 particle_hitting_something_with_missile_oam7[13];
u16 particle_hitting_something_with_super_missile_oam1[7];
u16 particle_hitting_something_with_super_missile_oam2[4];
u16 particle_hitting_something_with_super_missile_oam3[13];
u16 particle_hitting_something_with_super_missile_oam4[13];
u16 particle_hitting_something_with_super_missile_oam5[19];
u16 particle_hitting_something_with_super_missile_oam6[13];
u16 particle_hitting_something_with_super_missile_oam7[13];
u16 particle_sprite_explosion_huge_oam1[13];
u16 particle_sprite_explosion_huge_oam2[13];
u16 particle_sprite_explosion_huge_oam3[13];
u16 particle_sprite_explosion_huge_oam4[13];
u16 particle_sprite_explosion_huge_oam5[13];
u16 particle_sprite_explosion_huge_oam6[13];
u16 particle_sprite_explosion_huge_oam7[22];
u16 particle_sprite_explosion_huge_oam8[22];
u16 particle_sprite_explosion_huge_oam9[22];
u16 particle_sprite_explosion_huge_oam10[13];
u16 particle_sprite_explosion_huge_oam11[13];
u16 particle_sprite_explosion_huge_oam12[10];
u16 particle_sprite_explosion_huge_oam13[4];
u16 particle_small_dust_oam1[4];
u16 particle_small_dust_oam2[4];
u16 particle_small_dust_oam3[4];
u16 particle_small_dust_oam4[4];
u16 particle_small_dust_oam5[4];
u16 particle_small_dust_oam6[4];
u16 particle_medium_dust_oam1[7];
u16 particle_medium_dust_oam2[7];
u16 particle_medium_dust_oam3[10];
u16 particle_medium_dust_oam4[10];
u16 particle_medium_dust_oam5[10];
u16 particle_medium_dust_oam6[10];
u16 particle_medium_dust_oam7[10];
u16 particle_medium_dust_oam8[7];
u16 particle_medium_dust_oam9[4];
u16 particle_two_medium_dust_oam1[7];
u16 particle_two_medium_dust_oam2[10];
u16 particle_two_medium_dust_oam3[10];
u16 particle_two_medium_dust_oam4[10];
u16 particle_two_medium_dust_oam5[13];
u16 particle_two_medium_dust_oam6[13];
u16 particle_two_medium_dust_oam7[10];
u16 particle_two_medium_dust_oam8[7];
u16 particle_two_medium_dust_oam9[7];
u16 particle_two_medium_dust_oam10[4];
u16 particle_sprite_explosion_small_oam1[4];
u16 particle_sprite_explosion_small_oam2[4];
u16 particle_sprite_explosion_small_oam3[4];
u16 particle_sprite_explosion_small_oam4[4];
u16 particle_sprite_explosion_small_oam5[4];
u16 particle_sprite_explosion_small_oam6[7];
u16 particle_sprite_explosion_small_oam7[7];
u16 particle_sprite_explosion_small_oam8[7];
u16 particle_sprite_explosion_small_oam9[7];
u16 particle_sprite_explosion_small_oam10[7];
u16 particle_sprite_explosion_small_oam11[4];
u16 particle_sprite_explosion_medium_oam1[4];
u16 particle_sprite_explosion_medium_oam2[4];
u16 particle_sprite_explosion_medium_oam3[4];
u16 particle_sprite_explosion_medium_oam4[7];
u16 particle_sprite_explosion_medium_oam5[7];
u16 particle_sprite_explosion_medium_oam6[10];
u16 particle_sprite_explosion_medium_oam7[13];
u16 particle_sprite_explosion_medium_oam8[13];
u16 particle_sprite_explosion_medium_oam9[16];
u16 particle_sprite_explosion_medium_oam10[16];
u16 particle_sprite_explosion_medium_oam11[13];
u16 particle_sprite_explosion_medium_oam12[13];
u16 particle_sprite_explosion_medium_oam13[13];
u16 particle_sprite_explosion_medium_oam14[10];
u16 particle_sprite_explosion_medium_oam15[7];
u16 particle_sprite_explosion_medium_oam16[7];
u16 particle_sprite_explosion_medium_oam17[4];
u16 particle_sprite_explosion_big_oam1[4];
u16 particle_sprite_explosion_big_oam2[4];
u16 particle_sprite_explosion_big_oam3[4];
u16 particle_sprite_explosion_big_oam4[13];
u16 particle_sprite_explosion_big_oam5[13];
u16 particle_sprite_explosion_big_oam6[13];
u16 particle_sprite_explosion_big_oam7[16];
u16 particle_sprite_explosion_big_oam8[16];
u16 particle_sprite_explosion_big_oam9[19];
u16 particle_sprite_explosion_big_oam10[19];
u16 particle_sprite_explosion_big_oam11[16];
u16 particle_sprite_explosion_big_oam12[19];
u16 particle_sprite_explosion_big_oam13[16];
u16 particle_sprite_explosion_big_oam14[16];
u16 particle_sprite_explosion_big_oam15[10];
u16 particle_sprite_explosion_big_oam16[7];
u16 particle_sprite_explosion_big_oam17[4];
u16 particle_sprite_explosion_single_then_big_oam1[13];
u16 particle_sprite_explosion_single_then_big_oam2[13];
u16 particle_sprite_explosion_single_then_big_oam3[13];
u16 particle_sprite_explosion_single_then_big_oam4[28];
u16 particle_sprite_explosion_single_then_big_oam5[13];
u16 particle_sprite_explosion_single_then_big_oam6[16];
u16 particle_sprite_explosion_single_then_big_oam7[16];
u16 particle_sprite_explosion_single_then_big_oam8[19];
u16 particle_sprite_explosion_single_then_big_oam9[19];
u16 particle_sprite_explosion_single_then_big_oam10[16];
u16 particle_sprite_explosion_single_then_big_oam11[19];
u16 particle_sprite_explosion_single_then_big_oam12[16];
u16 particle_sprite_explosion_single_then_big_oam13[16];
u16 particle_sprite_explosion_single_then_big_oam14[10];
u16 particle_sprite_explosion_single_then_big_oam15[7];
u16 particle_sprite_explosion_single_then_big_oam16[4];
u16 particle_screw_attack_destroyed_oam1[4];
u16 particle_screw_attack_destroyed_oam2[25];
u16 particle_screw_attack_destroyed_oam3[37];
u16 particle_screw_attack_destroyed_oam4[49];
u16 particle_screw_attack_destroyed_oam5[49];
u16 particle_screw_attack_destroyed_oam6[28];
u16 particle_screw_attack_destroyed_oam7[16];
u16 particle_screw_attack_destroyed_oam8[22];
u16 particle_shinespark_destroyed_oam1[10];
u16 particle_shinespark_destroyed_oam2[13];
u16 particle_shinespark_destroyed_oam3[19];
u16 particle_shinespark_destroyed_oam4[28];
u16 particle_shinespark_destroyed_oam5[31];
u16 particle_shinespark_destroyed_oam6[31];
u16 particle_shinespark_destroyed_oam7[22];
u16 particle_shinespark_destroyed_oam8[19];
u16 particle_shinespark_destroyed_oam9[10];
u16 particle_shinespark_destroyed_oam10[10];
u16 particle_sudo_screw_destroyed_oam1[7];
u16 particle_sudo_screw_destroyed_oam2[22];
u16 particle_sudo_screw_destroyed_oam3[28];
u16 particle_sudo_screw_destroyed_oam4[25];
u16 particle_sudo_screw_destroyed_oam5[25];
u16 particle_sudo_screw_destroyed_oam6[10];
u16 particle_sudo_screw_destroyed_oam7[10];
u16 particle_sudo_screw_destroyed_oam8[16];
u16 particle_speedbooster_destroyed_oam1[13];
u16 particle_speedbooster_destroyed_oam2[28];
u16 particle_speedbooster_destroyed_oam3[40];
u16 particle_speedbooster_destroyed_oam4[37];
u16 particle_speedbooster_destroyed_oam5[37];
u16 particle_speedbooster_destroyed_oam6[16];
u16 particle_speedbooster_destroyed_oam7[16];
u16 particle_speedbooster_destroyed_oam8[22];
u16 particle_freezing_sprite_with_ice_oam1[4];
u16 particle_freezing_sprite_with_ice_oam2[4];
u16 particle_freezing_sprite_with_ice_oam3[4];
u16 particle_freezing_sprite_with_ice_oam4[7];
u16 particle_freezing_sprite_with_ice_oam5[7];
u16 particle_freezing_sprite_with_ice_oam6[7];
u16 particle_freezing_sprite_with_ice_oam7[10];
u16 particle_freezing_sprite_with_ice_oam8[10];
u16 particle_freezing_sprite_with_ice_oam9[10];
u16 particle_freezing_sprite_with_ice_oam10[10];
u16 particle_freezing_sprite_with_ice_oam11[10];
u16 particle_freezing_sprite_with_ice_oam12[7];
u16 particle_freezing_sprite_with_ice_oam13[7];
u16 particle_freezing_sprite_with_ice_oam14[4];
u16 particle_freezing_sprite_with_ice_oam15[4];
u16 particle_freezing_sprite_with_ice_oam16[4];
u16 particle_freezing_sprite_with_charged_ice_oam1[13];
u16 particle_freezing_sprite_with_charged_ice_oam2[13];
u16 particle_freezing_sprite_with_charged_ice_oam3[13];
u16 particle_freezing_sprite_with_charged_ice_oam4[28];
u16 particle_freezing_sprite_with_charged_ice_oam5[13];
u16 particle_freezing_sprite_with_charged_ice_oam6[13];
u16 particle_freezing_sprite_with_charged_ice_oam7[13];
u16 particle_freezing_sprite_with_charged_ice_oam8[13];
u16 particle_freezing_sprite_with_charged_ice_oam9[13];
u16 particle_freezing_sprite_with_charged_ice_oam10[10];
u16 particle_freezing_sprite_with_charged_ice_oam11[10];
u16 particle_freezing_sprite_with_charged_ice_oam12[7];
u16 particle_freezing_sprite_with_charged_ice_oam13[4];
u16 particle_freezing_sprite_with_charged_ice_oam14[7];
u16 particle_freezing_sprite_with_charged_ice_oam15[4];
u16 particle_main_boss_death_oam1[7];
u16 particle_main_boss_death_oam2[4];
u16 particle_main_boss_death_oam3[19];
u16 particle_main_boss_death_oam4[16];
u16 particle_main_boss_death_oam5[31];
u16 particle_main_boss_death_oam6[49];
u16 particle_main_boss_death_oam7[52];
u16 particle_main_boss_death_oam8[55];
u16 particle_main_boss_death_oam9[64];
u16 particle_main_boss_death_oam10[61];
u16 particle_main_boss_death_oam11[58];
u16 particle_main_boss_death_oam12[55];
u16 particle_main_boss_death_oam13[37];
u16 particle_main_boss_death_oam14[37];
u16 particle_main_boss_death_oam15[31];
u16 particle_main_boss_death_oam16[19];
u16 particle_main_boss_death_oam17[10];
u16 WaterDrop_oam1[4];
u16 WaterDrop_oam2[4];
u16 WaterDrop_oam3[4];
u16 WaterDrop_oam4[4];
u16 WaterDrop_oam5[4];
u16 WaterDrop_oam6[4];
u16 WaterDrop_oam7[4];
u16 WaterDrop_oam_falling1[4];
u16 WaterDrop_oam_splashing1[7];
u16 WaterDrop_oam_splashing2[7];
u16 WaterDrop_oam_splashing3[7];
u16 WaterDrop_oam_splashing4[7];
u16 WaterDrop_oam_splashing5[7];
u16 sprite_debris_oam1[4];
u16 sprite_debris_oam2[4];
u16 sprite_debris_oam3[4];
u16 sprite_debris_oam4[4];
u16 sprite_debris_oam_unused1[4];
u16 sprite_debris_oam_unused2[7];
u16 sprite_debris_oam_unused3[7];
u16 sprite_debris_oam_unused4[13];
u16 sprite_debris_oam_unused5[25];
u16 sprite_debris_oam_unused6[25];
struct FrameData particle_hitting_something_with_base_beam_oam[5];
struct FrameData particle_hitting_something_with_long_beam_oam[5];
struct FrameData particle_hitting_something_with_ice_beam_oam[6];
struct FrameData particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam[7];
struct FrameData particle_hitting_something_with_plasma_beam_full_beam_oam[8];
struct FrameData particle_hitting_something_invincible_oam[6];
struct FrameData particle_hitting_something_with_missile_oam[8];
struct FrameData particle_hitting_something_with_super_missile_oam[8];
struct FrameData particle_sprite_explosion_huge_oam[14];
struct FrameData particle_small_dust_oam[7];
struct FrameData particle_medium_dust_oam[10];
struct FrameData particle_two_medium_dust_oam[11];
struct FrameData particle_sprite_explosion_small_oam[12];
struct FrameData particle_sprite_explosion_medium_oam[18];
struct FrameData particle_sprite_explosion_big_oam[18];
struct FrameData particle_sprite_explosion_single_then_big_oam[17];
struct FrameData particle_screw_attack_destroyed_oam[9];
struct FrameData particle_shinespark_destroyed_oam[11];
struct FrameData particle_sudo_screw_destroyed_oam[9];
struct FrameData particle_speedbooster_destroyed_oam[9];
struct FrameData particle_freezing_sprite_with_ice_oam[17];
struct FrameData particle_freezing_sprite_with_charged_ice_oam[16];
struct FrameData particle_main_boss_death_oam[18];
struct FrameData WaterDrop_oam[8];
struct FrameData WaterDrop_oam_falling[2];
struct FrameData WaterDrop_oam_splashing[6];
struct FrameData sprite_debris_oam[5];
struct FrameData sprite_debris_oam_unused[7];

/* blob_0x833bd34_0x833cbdf.c */

u8 blob_0x833bd34_0x833cbdf[3756];

/* particle_splash_data.c */

u16 particle_sprite_splash_water_big_oam1[10];
u16 particle_sprite_splash_water_big_oam2[13];
u16 particle_sprite_splash_water_big_oam3[19];
u16 particle_sprite_splash_water_big_oam4[19];
u16 particle_sprite_splash_water_big_oam5[22];
u16 particle_sprite_splash_water_big_oam6[22];
u16 particle_sprite_splash_water_big_oam7[22];
u16 particle_sprite_splash_water_big_oam8[19];
u16 particle_sprite_splash_water_big_oam9[13];
u16 particle_sprite_splash_water_huge_oam1[10];
u16 particle_sprite_splash_water_huge_oam2[13];
u16 particle_sprite_splash_water_huge_oam3[25];
u16 particle_sprite_splash_water_huge_oam4[25];
u16 particle_sprite_splash_water_huge_oam5[28];
u16 particle_sprite_splash_water_huge_oam6[28];
u16 particle_sprite_splash_water_huge_oam7[25];
u16 particle_sprite_splash_water_huge_oam8[22];
u16 particle_sprite_splash_water_huge_oam9[16];
u16 particle_sprite_splash_water_small_oam1[7];
u16 particle_sprite_splash_water_small_oam2[10];
u16 particle_sprite_splash_water_small_oam3[10];
u16 particle_sprite_splash_water_small_oam4[10];
u16 particle_sprite_splash_water_small_oam5[10];
u16 particle_sprite_splash_water_small_oam6[16];
u16 particle_sprite_splash_lava_big_oam1[10];
u16 particle_sprite_splash_lava_big_oam2[13];
u16 particle_sprite_splash_lava_big_oam3[19];
u16 particle_sprite_splash_lava_big_oam4[19];
u16 particle_sprite_splash_lava_big_oam5[22];
u16 particle_sprite_splash_lava_big_oam6[22];
u16 particle_sprite_splash_lava_big_oam7[22];
u16 particle_sprite_splash_lava_big_oam8[19];
u16 particle_sprite_splash_lava_big_oam9[13];
u16 particle_sprite_splash_lava_huge_oam1[10];
u16 particle_sprite_splash_lava_huge_oam2[13];
u16 particle_sprite_splash_lava_huge_oam3[25];
u16 particle_sprite_splash_lava_huge_oam4[25];
u16 particle_sprite_splash_lava_huge_oam5[28];
u16 particle_sprite_splash_lava_huge_oam6[28];
u16 particle_sprite_splash_lava_huge_oam7[25];
u16 particle_sprite_splash_lava_huge_oam8[22];
u16 particle_sprite_splash_lava_huge_oam9[16];
u16 particle_sprite_splash_lava_small_oam1[7];
u16 particle_sprite_splash_lava_small_oam2[10];
u16 particle_sprite_splash_lava_small_oam3[10];
u16 particle_sprite_splash_lava_small_oam4[10];
u16 particle_sprite_splash_lava_small_oam5[10];
u16 particle_sprite_splash_lava_small_oam6[16];
u16 particle_sprite_splash_acid_big_oam1[10];
u16 particle_sprite_splash_acid_big_oam2[13];
u16 particle_sprite_splash_acid_big_oam3[19];
u16 particle_sprite_splash_acid_big_oam4[19];
u16 particle_sprite_splash_acid_big_oam5[22];
u16 particle_sprite_splash_acid_big_oam6[22];
u16 particle_sprite_splash_acid_big_oam7[22];
u16 particle_sprite_splash_acid_big_oam8[19];
u16 particle_sprite_splash_acid_big_oam9[13];
u16 particle_sprite_splash_acid_huge_oam1[10];
u16 particle_sprite_splash_acid_huge_oam2[13];
u16 particle_sprite_splash_acid_huge_oam3[25];
u16 particle_sprite_splash_acid_huge_oam4[25];
u16 particle_sprite_splash_acid_huge_oam5[28];
u16 particle_sprite_splash_acid_huge_oam6[28];
u16 particle_sprite_splash_acid_huge_oam7[25];
u16 particle_sprite_splash_acid_huge_oam8[22];
u16 particle_sprite_splash_acid_huge_oam9[16];
u16 particle_sprite_splash_acid_small_oam1[7];
u16 particle_sprite_splash_acid_small_oam2[10];
u16 particle_sprite_splash_acid_small_oam3[10];
u16 particle_sprite_splash_acid_small_oam4[10];
u16 particle_sprite_splash_acid_small_oam5[10];
u16 particle_sprite_splash_acid_small_oam6[16];
struct FrameData particle_sprite_splash_water_big_oam[10];
struct FrameData particle_sprite_splash_water_huge_oam[10];
struct FrameData particle_sprite_splash_water_small_oam[7];
struct FrameData particle_sprite_splash_lava_big_oam[10];
struct FrameData particle_sprite_splash_lava_huge_oam[10];
struct FrameData particle_sprite_splash_lava_small_oam[7];
struct FrameData particle_sprite_splash_acid_big_oam[10];
struct FrameData particle_sprite_splash_acid_huge_oam[10];
struct FrameData particle_sprite_splash_acid_small_oam[7];

/* blob_0x833d75c_0x8345cc8.c */

u8 blob_0x83d75c_0x8345cc8[34156];

/* bldalpha_data.c */

u16 bldalpha_values_for_clipdata[11];

/* blob_0x8345cde_0x875e6a7.c */

u8 blob_0x8345cde_0x875e6a7[4295113];

/* samus_pointers_data.c */

SamusFunc_T samus_pose_functions_pointers[67];
SamusFunc_T samus_pose_gfx_functions_pointers[67];

/* primary_sprite_pointers.c */

Func_T sPrimarySpritesAIPointers[206];

/* blob_0x875ebf8_0x875f1e7.c */

u8 blob_0x875ebf8_0x875f1e7[1520];

/* secondary_sprites_pointers.c */

Func_T sSecondarySpritesAIPointers[77];

/* blob_0x875f31c_0x875f973.c */

u8 blob_0x875f31c_0x875f973[16234];

/* projectile_pointers.c */

ProjFunc_T process_projectile_functions_pointers[16];

/* particle_pointers.c */

ParticleFunc_T process_particle_functions_pointer[61];

#endif /* DATA_H */
