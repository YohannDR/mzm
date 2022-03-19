#ifndef DATA_H
#define DATA_H

#include "../src/oam.h"
#include "../src/types.h"
#include "../src/samus.h"
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
#include "../src/sprites_AI/zipline_button.h"
#include "../src/sprites_AI/reo.h"
#include "../src/sprites_AI/gunship.h"
#include "../src/sprites_AI/skultera.h"
#include "../src/sprites_AI/dessgeega.h"
#include "../src/sprites_AI/waver.h"
#include "../src/sprites_AI/mellow.h"
#include "../src/sprites_AI/power_grîp.h"
#include "../src/sprites_AI/imago_larva.h"
#include "../src/sprites_AI/morph_ball_launcher.h"
#include "../src/sprites_AI/space_pirate.h"
#include "../src/sprites_AI/gamet.h"
#include "../src/sprites_AI/unknown_item_chozo_statue.h"
#include "../src/sprites_AI/zebbo.h"
#include "../src/sprites_AI/worker_robor.h"
#include "../src/sprites_AI/parasite_multiple.h"
#include "../src/sprites_AI/parasite.h"
#include "../src/sprites_AI/piston.h"
#include "../src/sprites_AI/ridley.h"
#include "../src/sprites_AI/security_gate_default_close.h"
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
#include "../src/sprites_AI/imago_cocoon_after_fight.h"
#include "../src/sprites_AI/ripper2.h"
#include "../src/sprites_AI/mella.h"
#include "../src/sprites_AI/atomic.h"
#include "../src/sprites_AI/area_banner.h"
#include "../src/sprites_AI/mother_brain.h"
#include "../src/sprites_AI/fake_power_bomb_trigger.h"
#include "../src/sprites_AI/acid_worm.h"
#include "../src/sprites_AI/escape_ship.h"
#include "../src/sprites_AI/sidehopper.h"
#include "../src/sprites_AI/geega.h"
#include "../src/sprites_AI/rinka_mother_brain.h"
#include "../src/sprites_AI/zebetite.h"
#include "../src/sprites_AI/cannon.h"
#include "../src/sprites_AI/zipline.h"
#include "../src/sprites_AI/imago_larva_right_side.h"
#include "../src/sprites_AI/tangle_vine.h"
#include "../src/sprites_AI/mellow_swarm.h"
#include "../src/sprites_AI/imago.h"
#include "../src/sprites_AI/crocomire.h"
#include "../src/sprites_AI/imago_larva.h"
#include "../src/sprites_AI/geron.h"
#include "../src/sprites_AI/glass_tube.h"
#include "../src/sprites_AI/save_platform_chozodia.h"
#include "../src/sprites_AI/baristute.h"
#include "../src/sprites_AI/elevator_statue.h"
#include "../src/sprites_AI/rising_chozo_pillar.h"
#include "../src/sprites_AI/security_laser.h"
#include "../src/sprites_AI/kraid_statue.h"
#include "../src/sprites_AI/ridley_statue.h"
#include "../src/sprites_AI/searchlight_eye.h"
#include "../src/sprites_AI/steam.h"
#include "../src/sprites_AI/unkown_item_block.h"
#include "../src/sprites_AI/gadora.h"
#include "../src/sprites_AI/primary_sprite_B3.h"
#include "../src/sprites_AI/space_pirate_carrying_power_bomb.h"
#include "../src/sprites_AI/water_drop.h"
#include "../src/sprites_AI/falling_chozo_pillar.h"
#include "../src/sprites_AI/mecha_ridley.h"
#include "../src/sprites_AI/escape_gate.h"
#include "../src/sprites_AI/black_space_pirate.h"
#include "../src/sprites_AI/escape_ship_pirate.h"

/* generic_data.c */

i16 sine_y_values[320];
u8 random_number_table[256];

/* blob_0x808ca9c_0x8239463.c */

u8 blob_0x808ca9c_0x8239463[1755591];

/* samus_visual_data.c */

u8 samus_visual_data[68][3];

/* blob_0x8239530_0x823a533.c */

u8 blob_0x8239530_0x823a533[4099];

/* samus_hitbox_draw_data.c */

u16 samus_draw_distance_offsets[4][4];
i16 samus_hitbox_data[4][3];
u8 samus_environmental_effects_oam_pointers[72];
u16 samus_pulling_self_up_velocity[4];

/* blob_0x823a5bc_0x82b0d67.c */

u8 blob_0x823a5bc_0x82b0d67[485291];

/* sprite_stats.c */

u16 primary_sprite_stats[206][9];
u16 secondary_sprite_stats[77][9];

/* blob_0x82b214e_0x82b25c7.c */

u8 blob_0x82b214e_0x82b25c7[1146];

/* enemy_drop_data.c */

struct OamFrame small_energy_drop_oam1;
struct OamFrame small_energy_drop_oam2;
struct OamFrame small_energy_drop_oam3;
struct OamFrame small_energy_drop_oam4;
struct OamFrame large_energy_drop_oam1;
struct OamFrame large_energy_drop_oam2;
struct OamFrame large_energy_drop_oam3;
struct OamFrame large_energy_drop_oam4;
struct OamFrame missile_drop_oam1;
struct OamFrame missile_drop_oam2;
struct OamFrame super_missile_drop_oam1;
struct OamFrame super_missile_drop_oam2;
struct OamFrame power_bomb_drop_oam1;
struct OamFrame power_bomb_drop_oam2;
struct OamFrame multiple_large_energy_drop_slot1_oam1;
struct OamFrame multiple_large_energy_drop_slot1_oam2;
struct OamFrame multiple_large_energy_drop_slot1_oam3;
struct OamFrame multiple_large_energy_drop_slot1_oam4;
struct OamFrame multiple_large_energy_drop_slot3_oam1;
struct OamFrame multiple_large_energy_drop_slot3_oam2;
struct OamFrame multiple_large_energy_drop_slot3_oam3;
struct OamFrame multiple_large_energy_drop_slot3_oam4;
struct OamFrame multiple_large_energy_drop_slot2_oam1;
struct OamFrame multiple_large_energy_drop_slot2_oam2;
struct OamFrame multiple_large_energy_drop_slot2_oam3;
struct OamFrame multiple_large_energy_drop_slot2_oam4;
struct FrameData small_energy_drop_oam[5];
struct FrameData large_energy_drop_oam[5];
struct FrameData missile_drop_oam[3];
struct FrameData super_missile_drop_oam[3];
struct FrameData power_bomb_drop_oam[3];
struct FrameData multiple_large_energy_drop_slot1_oam[5];
struct FrameData multiple_large_energy_drop_slot3_oam[5];
struct FrameData multiple_large_energy_drop_slot2_oam[5];

/* unused_sprites_data.c */

struct OamFrame unused_sprites_oam1;
struct OamFrame unused_sprites_oam2;
struct OamFrame unused_sprites_oam4;
u8 unused_sprites_gfx[24];
u16 unused_sprites_pal[16];
struct FrameData unused_sprites_oam[5];

/* morph_ball_data.c */

u8 morph_ball_gfx[672];
u16 morph_ball_pal[16];
struct OamFrame morph_ball_oam1;
struct OamFrame morph_ball_oam2;
struct OamFrame morph_ball_oam3;
struct OamFrame morph_ball_oam4;
struct OamFrame morph_ball_outside_oam1;
struct OamFrame morph_ball_outside_oam2;
struct OamFrame morph_ball_outside_oam3;
struct OamFrame morph_ball_outside_oam4;
struct OamFrame morph_ball_outside_oam5;
struct FrameData morph_ball_oam[5];
struct FrameData morph_ball_outside_oam[6];

/* power_grip_data.c */

u8 power_grip_gfx[1116];
u16 power_grip_pal[32];
struct OamFrame power_grip_oam1;
struct OamFrame power_grip_oam2;
struct OamFrame power_grip_oam3;
struct OamFrame power_grip_oam4;
struct OamFrame power_grip_glow_oam1;
struct OamFrame power_grip_glow_oam2;
struct OamFrame power_grip_glow_oam3;
struct OamFrame power_grip_glow_oam4;
struct OamFrame power_grip_glow_oam5;
struct OamFrame power_grip_glow_oam6;
struct OamFrame power_grip_glow_oam7;
struct OamFrame power_grip_glow_oam8;
struct OamFrame power_grip_glow_oam9;
struct OamFrame power_grip_glow_oam10;
struct OamFrame power_grip_glow_oam11;
struct OamFrame power_grip_glow_oam12;
struct OamFrame power_grip_glow_oam13;
struct OamFrame power_grip_glow_oam14;
struct FrameData power_grip_oam[5];
struct FrameData power_grip_glow_oam[15];

/* charge_beam_data.c */

i16 charge_beam_y_position_offsets[66];
u8 charge_beam_gfx[972];
u16 charge_beam_pal[16];
struct OamFrame charge_beam_oam_visible1;
struct OamFrame charge_beam_oam_visible2;
struct OamFrame charge_beam_oam_visible3;
struct OamFrame charge_beam_oam_visible4;
struct OamFrame charge_beam_oam1;
struct OamFrame charge_beam_oam2;
struct OamFrame charge_beam_oam3;
struct OamFrame charge_beam_oam4;
struct OamFrame charge_beam_oam5;
struct OamFrame charge_beam_oam6;
struct OamFrame charge_beam_oam7;
struct OamFrame charge_beam_oam8;
struct OamFrame charge_beam_oam9;
struct OamFrame charge_beam_oam10;
struct OamFrame charge_beam_oam11;
struct OamFrame charge_beam_oam12;
struct OamFrame charge_beam_glow_oam1;
struct OamFrame charge_beam_glow_oam2;
struct OamFrame charge_beam_glow_oam3;
struct OamFrame charge_beam_glow_oam4;
struct OamFrame charge_beam_glow_oam5;
struct OamFrame charge_beam_glow_oam6;
struct OamFrame charge_beam_glow_oam7;
struct OamFrame charge_beam_glow_oam8;
struct OamFrame charge_beam_glow_oam9;
struct OamFrame charge_beam_glow_oam10;
struct OamFrame charge_beam_glow_oam11;
struct OamFrame charge_beam_glow_oam12;
struct OamFrame charge_beam_glow_oam13;
struct OamFrame charge_beam_glow_oam14;
struct FrameData charge_beam_oam_visible[5];
struct FrameData charge_beam_oam[13];
struct FrameData charge_beam_glow_oam[15];

/* skree_data.c */

i16 skree_falling_speed[8];
u8 skree_gfx[1056];
u16 skree_pal[16];
u8 skree_blue_gfx[1056];
u16 skree_blue_pal[16];
struct OamFrame skree_oam_11;
struct OamFrame skree_oam_12;
struct OamFrame skree_oam_13;
struct OamFrame skree_oam_14;
struct OamFrame skree_oam_21;
struct OamFrame skree_oam_22;
struct OamFrame skree_oam_23;
struct OamFrame skree_oam_24;
struct OamFrame skree_oam_25;
struct OamFrame skree_oam_31;
struct OamFrame skree_oam_32;
struct OamFrame skree_oam_33;
struct OamFrame skree_oam_34;
struct OamFrame skree_oam_41;
struct OamFrame skree_oam_42;
struct OamFrame skree_oam_43;
struct OamFrame skree_oam_44;
struct OamFrame skree_oam_51;
struct OamFrame skree_oam_52;
struct OamFrame skree_oam_53;
struct OamFrame skree_oam_54;
struct OamFrame skree_oam_61;
struct OamFrame skree_oam_62;
struct OamFrame skree_oam_63;
struct OamFrame skree_oam_64;
struct OamFrame skree_oam_65;
struct OamFrame skree_oam_71;
struct OamFrame skree_oam_72;
struct OamFrame skree_oam_73;
struct OamFrame skree_oam_74;
struct OamFrame skree_oam_81;
struct OamFrame skree_oam_82;
struct OamFrame skree_oam_83;
struct OamFrame skree_oam_84;
struct OamFrame skree_oam_91;
struct OamFrame skree_oam_92;
struct OamFrame skree_oam_93;
struct OamFrame skree_oam_101;
struct OamFrame skree_oam_102;
struct OamFrame skree_oam_103;
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

/* blob_0x82f7dd4_0x8326ca7.c */

u8 blob_0x82f7dd4_0x8326ca7[192212];

/* tumbling_missile_speed_data.c */

i16 tumbling_missile_speed[48];

/* bomb_data.c */

struct OamFrame bomb_oam_normal1;
struct OamFrame bomb_oam_normal2;
struct OamFrame bomb_oam_normal3;
struct OamFrame bomb_oam_normal4;
struct OamFrame bomb_oam_fast1;
struct OamFrame bomb_oam_fast2;
struct OamFrame bomb_oam_fast3;
struct OamFrame bomb_oam_fast4;
struct OamFrame power_bomb_oam_normal1;
struct OamFrame power_bomb_oam_normal2;
struct OamFrame power_bomb_oam_normal3;
struct OamFrame power_bomb_oam_fast1;
struct OamFrame power_bomb_oam_fast2;
struct OamFrame power_bomb_oam_fast3;
struct FrameData bomb_oam_normal[5];
struct FrameData bomb_oam_fast[5];
struct FrameData power_bomb_oam_normal[4];
struct FrameData power_bomb_oam_fast[4];

/* missiles_data.c */

struct OamFrame missile_oam_forward1;
struct OamFrame missile_oam_forward2;
struct OamFrame missile_oam_diagonal1;
struct OamFrame missile_oam_diagonal2;
struct OamFrame missile_oam_up_down1;
struct OamFrame missile_oam_up_down2;
struct OamFrame super_missile_oam_forward1;
struct OamFrame super_missile_oam_forward2;
struct OamFrame super_missile_oam_diagonal1;
struct OamFrame super_missile_oam_diagonal2;
struct OamFrame super_missile_oam_up_down1;
struct OamFrame super_missile_oam_up_down2;
struct OamFrame missile_tumbling_oam1;
struct OamFrame missile_tumbling_oam2;
struct OamFrame missile_tumbling_oam3;
struct OamFrame missile_tumbling_oam4;
struct OamFrame missile_tumbling_oam5;
struct OamFrame missile_tumbling_oam6;
struct OamFrame missile_tumbling_oam7;
struct OamFrame missile_tumbling_oam8;
struct OamFrame super_missile_tumbling_oam1;
struct OamFrame super_missile_tumbling_oam2;
struct OamFrame super_missile_tumbling_oam3;
struct OamFrame super_missile_tumbling_oam4;
struct OamFrame super_missile_tumbling_oam5;
struct OamFrame super_missile_tumbling_oam6;
struct OamFrame super_missile_tumbling_oam7;
struct OamFrame super_missile_tumbling_oam8;
struct OamFrame particle_missile_trail_oam1;
struct OamFrame particle_missile_trail_oam2;
struct OamFrame particle_missile_trail_oam3;
struct OamFrame particle_missile_trail_oam4;
struct OamFrame particle_missile_trail_oam5;
struct OamFrame particle_missile_trail_oam6;
struct OamFrame particle_missile_trail_oam7;
struct OamFrame particle_super_missile_trail_oam1;
struct OamFrame particle_super_missile_trail_oam2;
struct OamFrame particle_super_missile_trail_oam3;
struct OamFrame particle_super_missile_trail_oam4;
struct OamFrame particle_super_missile_trail_oam5;
struct OamFrame particle_super_missile_trail_oam6;
struct OamFrame particle_super_missile_trail_oam7;
struct OamFrame particle_super_missile_trail_oam8;
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
struct OamFrame normal_beam_oam_forward1;
struct OamFrame normal_beam_oam_forward2;
struct OamFrame normal_beam_oam_diagonal1;
struct OamFrame normal_beam_oam_diagonal2;
struct OamFrame normal_beam_oam_up_down1;
struct OamFrame normal_beam_oam_up_down2;
struct OamFrame normal_beam_oam_unused11;
struct OamFrame normal_beam_oam_unused12;
struct OamFrame normal_beam_oam_unused21;
struct OamFrame normal_beam_oam_unused22;
struct OamFrame normal_beam_oam_unused31;
struct OamFrame normal_beam_oam_unused32;
struct OamFrame charged_normal_beam_oam_forward1;
struct OamFrame charged_normal_beam_oam_forward2;
struct OamFrame charged_normal_beam_oam_diagonal1;
struct OamFrame charged_normal_beam_oam_diagonal2;
struct OamFrame charged_normal_beam_oam_up_down1;
struct OamFrame charged_normal_beam_oam_up_down2;
struct OamFrame normal_beam_oam_unused41;
struct OamFrame normal_beam_oam_unused42;
struct OamFrame normal_beam_oam_unused43;
struct OamFrame normal_beam_oam_unused44;
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
struct OamFrame long_beam_oam_forward1;
struct OamFrame long_beam_oam_forward2;
struct OamFrame long_beam_oam_diagonal1;
struct OamFrame long_beam_oam_diagonal2;
struct OamFrame long_beam_oam_up_down1;
struct OamFrame long_beam_oam_up_down2;
struct OamFrame charged_long_beam_oam_forward1;
struct OamFrame charged_long_beam_oam_forward2;
struct OamFrame charged_long_beam_oam_diagonal1;
struct OamFrame charged_long_beam_oam_diagonal2;
struct OamFrame charged_long_beam_oam_up_down1;
struct OamFrame charged_long_beam_oam_up_down2;
struct OamFrame particle_charged_long_beam_trail_oam1;
struct OamFrame particle_charged_long_beam_trail_oam2;
struct OamFrame particle_charged_long_beam_trail_oam3;
struct OamFrame particle_charged_long_beam_trail_oam4;
struct FrameData long_beam_oam_forward[3];
struct FrameData long_beam_oam_diagonal[3];
struct FrameData long_beam_oam_up_down[3];
struct FrameData charged_long_beam_oam_forward[3];
struct FrameData charged_long_beam_oam_diagonal[3];
struct FrameData charged_long_beam_oam_up_down[3];
struct FrameData particle_charged_long_beam_trail_oam[5];

/* ice_beam_data.c */

u8 ice_beam_gfx[2048];
struct OamFrame ice_beam_oam_forward1;
struct OamFrame ice_beam_oam_forward2;
struct OamFrame ice_beam_oam_diagonal1;
struct OamFrame ice_beam_oam_diagonal2;
struct OamFrame ice_beam_oam_up_down1;
struct OamFrame ice_beam_oam_up_down2;
struct OamFrame ice_beam_oam_unused11;
struct OamFrame ice_beam_oam_unused12;
struct OamFrame ice_beam_oam_unused21;
struct OamFrame ice_beam_oam_unused22;
struct OamFrame ice_beam_oam_unused31;
struct OamFrame ice_beam_oam_unused32;
struct OamFrame charged_ice_beam_oam_forward1;
struct OamFrame charged_ice_beam_oam_forward2;
struct OamFrame charged_ice_beam_oam_diagonal1;
struct OamFrame charged_ice_beam_oam_diagonal2;
struct OamFrame charged_ice_beam_oam_up_down1;
struct OamFrame charged_ice_beam_oam_up_down2;
struct OamFrame particle_charged_ice_beam_trail_oam1;
struct OamFrame particle_charged_ice_beam_trail_oam2;
struct OamFrame particle_charged_ice_beam_trail_oam3;
struct OamFrame particle_charged_ice_beam_trail_oam4;
struct OamFrame particle_charged_ice_beam_trail_oam5;
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
struct OamFrame wave_beam_oam_forward1;
struct OamFrame wave_beam_oam_forward2;
struct OamFrame wave_beam_oam_forward3;
struct OamFrame wave_beam_oam_forward4;
struct OamFrame wave_beam_oam_forward5;
struct OamFrame wave_beam_oam_forward6;
struct OamFrame wave_beam_oam_forward7;
struct OamFrame wave_beam_oam_diagonal1;
struct OamFrame wave_beam_oam_diagonal2;
struct OamFrame wave_beam_oam_diagonal3;
struct OamFrame wave_beam_oam_diagonal4;
struct OamFrame wave_beam_oam_diagonal5;
struct OamFrame wave_beam_oam_diagonal6;
struct OamFrame wave_beam_oam_diagonal7;
struct OamFrame wave_beam_oam_up_down1;
struct OamFrame wave_beam_oam_up_down2;
struct OamFrame wave_beam_oam_up_down3;
struct OamFrame wave_beam_oam_up_down4;
struct OamFrame wave_beam_oam_up_down5;
struct OamFrame wave_beam_oam_up_down6;
struct OamFrame wave_beam_oam_up_down7;
struct OamFrame wave_beam_oam_unused11;
struct OamFrame wave_beam_oam_unused12;
struct OamFrame wave_beam_oam_unused13;
struct OamFrame wave_beam_oam_unused14;
struct OamFrame wave_beam_oam_unused15;
struct OamFrame wave_beam_oam_unused16;
struct OamFrame wave_beam_oam_unused17;
struct OamFrame wave_beam_oam_unused21;
struct OamFrame wave_beam_oam_unused22;
struct OamFrame wave_beam_oam_unused23;
struct OamFrame wave_beam_oam_unused24;
struct OamFrame wave_beam_oam_unused25;
struct OamFrame wave_beam_oam_unused26;
struct OamFrame wave_beam_oam_unused27;
struct OamFrame wave_beam_oam_unused31;
struct OamFrame wave_beam_oam_unused32;
struct OamFrame wave_beam_oam_unused33;
struct OamFrame wave_beam_oam_unused34;
struct OamFrame wave_beam_oam_unused35;
struct OamFrame wave_beam_oam_unused36;
struct OamFrame wave_beam_oam_unused37;
struct OamFrame charged_wave_beam_oam_forward1;
struct OamFrame charged_wave_beam_oam_forward2;
struct OamFrame charged_wave_beam_oam_forward3;
struct OamFrame charged_wave_beam_oam_forward4;
struct OamFrame charged_wave_beam_oam_forward5;
struct OamFrame charged_wave_beam_oam_forward6;
struct OamFrame charged_wave_beam_oam_forward7;
struct OamFrame charged_wave_beam_oam_diagonal1;
struct OamFrame charged_wave_beam_oam_diagonal2;
struct OamFrame charged_wave_beam_oam_diagonal3;
struct OamFrame charged_wave_beam_oam_diagonal4;
struct OamFrame charged_wave_beam_oam_diagonal5;
struct OamFrame charged_wave_beam_oam_diagonal6;
struct OamFrame charged_wave_beam_oam_diagonal7;
struct OamFrame charged_wave_beam_oam_up_down1;
struct OamFrame charged_wave_beam_oam_up_down2;
struct OamFrame charged_wave_beam_oam_up_down3;
struct OamFrame charged_wave_beam_oam_up_down4;
struct OamFrame charged_wave_beam_oam_up_down5;
struct OamFrame charged_wave_beam_oam_up_down6;
struct OamFrame charged_wave_beam_oam_up_down7;
struct OamFrame particle_charged_wave_beam_trail_oam1;
struct OamFrame particle_charged_wave_beam_trail_oam2;
struct OamFrame particle_charged_wave_beam_trail_oam3;
struct OamFrame particle_charged_wave_beam_trail_oam4;
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
struct OamFrame plasma_beam_no_wave_oam_forward1;
struct OamFrame plasma_beam_no_wave_oam_forward2;
struct OamFrame plasma_beam_no_wave_oam_diagonal1;
struct OamFrame plasma_beam_no_wave_oam_diagonal2;
struct OamFrame plasma_beam_no_wave_oam_up_down1;
struct OamFrame plasma_beam_no_wave_oam_up_down2;
struct OamFrame plasma_beam_no_wave_oam_unused11;
struct OamFrame plasma_beam_no_wave_oam_unused12;
struct OamFrame plasma_beam_no_wave_oam_unused21;
struct OamFrame plasma_beam_no_wave_oam_unused22;
struct OamFrame plasma_beam_no_wave_oam_unused31;
struct OamFrame plasma_beam_no_wave_oam_unused32;
struct OamFrame charged_plasma_beam_no_wave_oam_forward1;
struct OamFrame charged_plasma_beam_no_wave_oam_forward2;
struct OamFrame charged_plasma_beam_no_wave_oam_diagonal1;
struct OamFrame charged_plasma_beam_no_wave_oam_diagonal2;
struct OamFrame charged_plasma_beam_no_wave_oam_up_down1;
struct OamFrame charged_plasma_beam_no_wave_oam_up_down2;
struct OamFrame plasma_beam_wave_oam_forward1;
struct OamFrame plasma_beam_wave_oam_forward2;
struct OamFrame plasma_beam_wave_oam_forward3;
struct OamFrame plasma_beam_wave_oam_forward4;
struct OamFrame plasma_beam_wave_oam_forward5;
struct OamFrame plasma_beam_wave_oam_forward6;
struct OamFrame plasma_beam_wave_oam_forward7;
struct OamFrame plasma_beam_wave_oam_diagonal1;
struct OamFrame plasma_beam_wave_oam_diagonal2;
struct OamFrame plasma_beam_wave_oam_diagonal3;
struct OamFrame plasma_beam_wave_oam_diagonal4;
struct OamFrame plasma_beam_wave_oam_diagonal5;
struct OamFrame plasma_beam_wave_oam_diagonal6;
struct OamFrame plasma_beam_wave_oam_diagonal7;
struct OamFrame plasma_beam_wave_oam_up_down1;
struct OamFrame plasma_beam_wave_oam_up_down2;
struct OamFrame plasma_beam_wave_oam_up_down3;
struct OamFrame plasma_beam_wave_oam_up_down4;
struct OamFrame plasma_beam_wave_oam_up_down5;
struct OamFrame plasma_beam_wave_oam_up_down6;
struct OamFrame plasma_beam_wave_oam_up_down7;
struct OamFrame plasma_beam_wave_oam_unused11;
struct OamFrame plasma_beam_wave_oam_unused12;
struct OamFrame plasma_beam_wave_oam_unused13;
struct OamFrame plasma_beam_wave_oam_unused14;
struct OamFrame plasma_beam_wave_oam_unused15;
struct OamFrame plasma_beam_wave_oam_unused21;
struct OamFrame plasma_beam_wave_oam_unused22;
struct OamFrame plasma_beam_wave_oam_unused23;
struct OamFrame plasma_beam_wave_oam_unused24;
struct OamFrame plasma_beam_wave_oam_unused25;
struct OamFrame plasma_beam_wave_oam_unused31;
struct OamFrame plasma_beam_wave_oam_unused32;
struct OamFrame plasma_beam_wave_oam_unused33;
struct OamFrame plasma_beam_wave_oam_unused34;
struct OamFrame plasma_beam_wave_oam_unused35;
struct OamFrame charged_plasma_beam_wave_oam_forward1;
struct OamFrame charged_plasma_beam_wave_oam_forward2;
struct OamFrame charged_plasma_beam_wave_oam_forward3;
struct OamFrame charged_plasma_beam_wave_oam_forward4;
struct OamFrame charged_plasma_beam_wave_oam_forward5;
struct OamFrame charged_plasma_beam_wave_oam_forward6;
struct OamFrame charged_plasma_beam_wave_oam_forward7;
struct OamFrame charged_plasma_beam_wave_oam_diagonal1;
struct OamFrame charged_plasma_beam_wave_oam_diagonal2;
struct OamFrame charged_plasma_beam_wave_oam_diagonal3;
struct OamFrame charged_plasma_beam_wave_oam_diagonal4;
struct OamFrame charged_plasma_beam_wave_oam_diagonal5;
struct OamFrame charged_plasma_beam_wave_oam_diagonal6;
struct OamFrame charged_plasma_beam_wave_oam_diagonal7;
struct OamFrame charged_plasma_beam_wave_oam_up_down1;
struct OamFrame charged_plasma_beam_wave_oam_up_down2;
struct OamFrame charged_plasma_beam_wave_oam_up_down3;
struct OamFrame charged_plasma_beam_wave_oam_up_down4;
struct OamFrame charged_plasma_beam_wave_oam_up_down5;
struct OamFrame charged_plasma_beam_wave_oam_up_down6;
struct OamFrame charged_plasma_beam_wave_oam_up_down7;
struct OamFrame particle_charged_plasma_beam_trail_oam1;
struct OamFrame particle_charged_plasma_beam_trail_oam2;
struct OamFrame particle_charged_plasma_beam_trail_oam3;
struct OamFrame particle_charged_plasma_beam_trail_oam4;
struct OamFrame particle_charged_full_beam_trail_oam1;
struct OamFrame particle_charged_full_beam_trail_oam2;
struct OamFrame particle_charged_full_beam_trail_oam3;
struct OamFrame particle_charged_full_beam_trail_oam4;
struct OamFrame particle_charged_full_beam_trail_oam5;
struct OamFrame particle_charged_full_beam_trail_oam6;
struct OamFrame particle_charged_full_beam_trail_oam7;
struct OamFrame particle_charged_full_beam_trail_oam8;
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
struct OamFrame pistol_oam_forward1;
struct OamFrame pistol_oam_forward2;
struct OamFrame pistol_oam_diagonal1;
struct OamFrame pistol_oam_diagonal2;
struct OamFrame pistol_oam_up_down1;
struct OamFrame pistol_oam_up_down2;
struct OamFrame charged_pistol_oam_forward1;
struct OamFrame charged_pistol_oam_forward2;
struct OamFrame charged_pistol_oam_diagonal1;
struct OamFrame charged_pistol_oam_diagonal2;
struct OamFrame charged_pistol_oam_up_down1;
struct OamFrame charged_pistol_oam_up_down2;
struct OamFrame particle_charged_pistol_trail_oam1;
struct OamFrame particle_charged_pistol_trail_oam2;
struct OamFrame particle_charged_pistol_trail_oam3;
struct OamFrame particle_charged_pistol_trail_oam4;
struct FrameData pistol_oam_forward[3];
struct FrameData pistol_oam_diagonal[3];
struct FrameData pistol_oam_up_down[3];
struct FrameData charged_pistol_oam_forward[3];
struct FrameData charged_pistol_oam_diagonal[3];
struct FrameData charged_pistol_oam_up_down[3];
struct FrameData particle_charged_pistol_trail_oam[5];

/* blob_0x832b9e8_0x832ba07.c */

u8 blob_0x832b9e8_0x832ba07[32];

/* common_sprite_data.c */

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

struct OamFrame particle_shooting_beam_left_right_oam1;
struct OamFrame particle_shooting_beam_left_right_oam2;
struct OamFrame particle_shooting_beam_left_right_oam3;
struct OamFrame particle_shooting_beam_left_right_oam4;
struct OamFrame particle_shooting_beam_diagonally_up_oam1;
struct OamFrame particle_shooting_beam_diagonally_up_oam2;
struct OamFrame particle_shooting_beam_diagonally_up_oam3;
struct OamFrame particle_shooting_beam_diagonally_up_oam4;
struct OamFrame particle_shooting_beam_diagonally_down_oam1;
struct OamFrame particle_shooting_beam_diagonally_down_oam2;
struct OamFrame particle_shooting_beam_diagonally_down_oam3;
struct OamFrame particle_shooting_beam_diagonally_down_oam4;
struct OamFrame particle_shooting_beam_up_oam1;
struct OamFrame particle_shooting_beam_up_oam2;
struct OamFrame particle_shooting_beam_up_oam3;
struct OamFrame particle_shooting_beam_up_oam4;
struct OamFrame particle_shooting_beam_down_oam1;
struct OamFrame particle_shooting_beam_down_oam2;
struct OamFrame particle_shooting_beam_down_oam3;
struct OamFrame particle_shooting_beam_down_oam4;
struct OamFrame particle_bomb_oam1;
struct OamFrame particle_bomb_oam2;
struct OamFrame particle_bomb_oam3;
struct OamFrame particle_bomb_oam4;
struct OamFrame particle_bomb_oam5;
struct OamFrame particle_bomb_oam6;
struct OamFrame particle_beam_trailing_oam1;
struct OamFrame particle_beam_trailing_oam2;
struct OamFrame particle_beam_trailing_oam3;
struct OamFrame particle_beam_trailing_oam4;
struct OamFrame particle_beam_trailing_oam5;
struct OamFrame particle_charging_beam_oam_begin1;
struct OamFrame particle_charging_beam_oam_begin2;
struct OamFrame particle_charging_beam_oam_begin3;
struct OamFrame particle_charging_beam_oam_begin4;
struct OamFrame particle_charging_beam_oam_begin5;
struct OamFrame particle_charging_beam_oam_begin6;
struct OamFrame particle_charging_beam_oam_begin7;
struct OamFrame particle_charging_beam_oam_begin8;
struct OamFrame particle_charging_beam_oam_begin9;
struct OamFrame particle_charging_beam_oam_begin10;
struct OamFrame particle_charging_beam_oam_begin11;
struct OamFrame particle_charging_beam_oam_begin12;
struct OamFrame particle_charging_beam_oam_begin13;
struct OamFrame particle_charging_beam_oam_begin14;
struct OamFrame particle_charging_beam_oam_begin15;
struct OamFrame particle_charging_beam_oam_begin16;
struct OamFrame particle_charging_beam_oam_begin17;
struct OamFrame particle_charging_beam_oam_begin18;
struct OamFrame particle_charging_beam_oam_begin19;
struct OamFrame particle_charging_beam_oam_begin20;
struct OamFrame particle_charging_beam_oam_begin21;
struct OamFrame particle_charging_beam_oam_begin22;
struct OamFrame particle_charging_beam_oam_charged1;
struct OamFrame particle_charging_beam_oam_charged2;
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

struct OamFrame particle_hitting_something_with_base_beam_oam1;
struct OamFrame particle_hitting_something_with_base_beam_oam2;
struct OamFrame particle_hitting_something_with_base_beam_oam3;
struct OamFrame particle_hitting_something_with_base_beam_oam4;
struct OamFrame particle_hitting_something_with_long_beam_oam1;
struct OamFrame particle_hitting_something_with_long_beam_oam2;
struct OamFrame particle_hitting_something_with_long_beam_oam3;
struct OamFrame particle_hitting_something_with_long_beam_oam4;
struct OamFrame particle_hitting_something_with_ice_beam_oam1;
struct OamFrame particle_hitting_something_with_ice_beam_oam2;
struct OamFrame particle_hitting_something_with_ice_beam_oam3;
struct OamFrame particle_hitting_something_with_ice_beam_oam4;
struct OamFrame particle_hitting_something_with_ice_beam_oam5;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam1;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam2;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam3;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam4;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam5;
struct OamFrame particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam6;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam1;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam2;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam3;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam4;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam5;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam6;
struct OamFrame particle_hitting_something_with_plasma_beam_full_beam_oam7;
struct OamFrame particle_hitting_something_invincible_oam1;
struct OamFrame particle_hitting_something_invincible_oam2;
struct OamFrame particle_hitting_something_invincible_oam3;
struct OamFrame particle_hitting_something_invincible_oam4;
struct OamFrame particle_hitting_something_invincible_oam5;
struct OamFrame particle_hitting_something_with_missile_oam1;
struct OamFrame particle_hitting_something_with_missile_oam2;
struct OamFrame particle_hitting_something_with_missile_oam3;
struct OamFrame particle_hitting_something_with_missile_oam4;
struct OamFrame particle_hitting_something_with_missile_oam5;
struct OamFrame particle_hitting_something_with_missile_oam6;
struct OamFrame particle_hitting_something_with_missile_oam7;
struct OamFrame particle_hitting_something_with_super_missile_oam1;
struct OamFrame particle_hitting_something_with_super_missile_oam2;
struct OamFrame particle_hitting_something_with_super_missile_oam3;
struct OamFrame particle_hitting_something_with_super_missile_oam4;
struct OamFrame particle_hitting_something_with_super_missile_oam5;
struct OamFrame particle_hitting_something_with_super_missile_oam6;
struct OamFrame particle_hitting_something_with_super_missile_oam7;
struct OamFrame particle_sprite_explosion_huge_oam1;
struct OamFrame particle_sprite_explosion_huge_oam2;
struct OamFrame particle_sprite_explosion_huge_oam3;
struct OamFrame particle_sprite_explosion_huge_oam4;
struct OamFrame particle_sprite_explosion_huge_oam5;
struct OamFrame particle_sprite_explosion_huge_oam6;
struct OamFrame particle_sprite_explosion_huge_oam7;
struct OamFrame particle_sprite_explosion_huge_oam8;
struct OamFrame particle_sprite_explosion_huge_oam9;
struct OamFrame particle_sprite_explosion_huge_oam10;
struct OamFrame particle_sprite_explosion_huge_oam11;
struct OamFrame particle_sprite_explosion_huge_oam12;
struct OamFrame particle_sprite_explosion_huge_oam13;
struct OamFrame particle_small_dust_oam1;
struct OamFrame particle_small_dust_oam2;
struct OamFrame particle_small_dust_oam3;
struct OamFrame particle_small_dust_oam4;
struct OamFrame particle_small_dust_oam5;
struct OamFrame particle_small_dust_oam6;
struct OamFrame particle_medium_dust_oam1;
struct OamFrame particle_medium_dust_oam2;
struct OamFrame particle_medium_dust_oam3;
struct OamFrame particle_medium_dust_oam4;
struct OamFrame particle_medium_dust_oam5;
struct OamFrame particle_medium_dust_oam6;
struct OamFrame particle_medium_dust_oam7;
struct OamFrame particle_medium_dust_oam8;
struct OamFrame particle_medium_dust_oam9;
struct OamFrame particle_two_medium_dust_oam1;
struct OamFrame particle_two_medium_dust_oam2;
struct OamFrame particle_two_medium_dust_oam3;
struct OamFrame particle_two_medium_dust_oam4;
struct OamFrame particle_two_medium_dust_oam5;
struct OamFrame particle_two_medium_dust_oam6;
struct OamFrame particle_two_medium_dust_oam7;
struct OamFrame particle_two_medium_dust_oam8;
struct OamFrame particle_two_medium_dust_oam9;
struct OamFrame particle_two_medium_dust_oam10;
struct OamFrame particle_sprite_explosion_small_oam1;
struct OamFrame particle_sprite_explosion_small_oam2;
struct OamFrame particle_sprite_explosion_small_oam3;
struct OamFrame particle_sprite_explosion_small_oam4;
struct OamFrame particle_sprite_explosion_small_oam5;
struct OamFrame particle_sprite_explosion_small_oam6;
struct OamFrame particle_sprite_explosion_small_oam7;
struct OamFrame particle_sprite_explosion_small_oam8;
struct OamFrame particle_sprite_explosion_small_oam9;
struct OamFrame particle_sprite_explosion_small_oam10;
struct OamFrame particle_sprite_explosion_small_oam11;
struct OamFrame particle_sprite_explosion_medium_oam1;
struct OamFrame particle_sprite_explosion_medium_oam2;
struct OamFrame particle_sprite_explosion_medium_oam3;
struct OamFrame particle_sprite_explosion_medium_oam4;
struct OamFrame particle_sprite_explosion_medium_oam5;
struct OamFrame particle_sprite_explosion_medium_oam6;
struct OamFrame particle_sprite_explosion_medium_oam7;
struct OamFrame particle_sprite_explosion_medium_oam8;
struct OamFrame particle_sprite_explosion_medium_oam9;
struct OamFrame particle_sprite_explosion_medium_oam10;
struct OamFrame particle_sprite_explosion_medium_oam11;
struct OamFrame particle_sprite_explosion_medium_oam12;
struct OamFrame particle_sprite_explosion_medium_oam13;
struct OamFrame particle_sprite_explosion_medium_oam14;
struct OamFrame particle_sprite_explosion_medium_oam15;
struct OamFrame particle_sprite_explosion_medium_oam16;
struct OamFrame particle_sprite_explosion_medium_oam17;
struct OamFrame particle_sprite_explosion_big_oam1;
struct OamFrame particle_sprite_explosion_big_oam2;
struct OamFrame particle_sprite_explosion_big_oam3;
struct OamFrame particle_sprite_explosion_big_oam4;
struct OamFrame particle_sprite_explosion_big_oam5;
struct OamFrame particle_sprite_explosion_big_oam6;
struct OamFrame particle_sprite_explosion_big_oam7;
struct OamFrame particle_sprite_explosion_big_oam8;
struct OamFrame particle_sprite_explosion_big_oam9;
struct OamFrame particle_sprite_explosion_big_oam10;
struct OamFrame particle_sprite_explosion_big_oam11;
struct OamFrame particle_sprite_explosion_big_oam12;
struct OamFrame particle_sprite_explosion_big_oam13;
struct OamFrame particle_sprite_explosion_big_oam14;
struct OamFrame particle_sprite_explosion_big_oam15;
struct OamFrame particle_sprite_explosion_big_oam16;
struct OamFrame particle_sprite_explosion_big_oam17;
struct OamFrame particle_sprite_explosion_single_then_big_oam1;
struct OamFrame particle_sprite_explosion_single_then_big_oam2;
struct OamFrame particle_sprite_explosion_single_then_big_oam3;
struct OamFrame particle_sprite_explosion_single_then_big_oam4;
struct OamFrame particle_sprite_explosion_single_then_big_oam5;
struct OamFrame particle_sprite_explosion_single_then_big_oam6;
struct OamFrame particle_sprite_explosion_single_then_big_oam7;
struct OamFrame particle_sprite_explosion_single_then_big_oam8;
struct OamFrame particle_sprite_explosion_single_then_big_oam9;
struct OamFrame particle_sprite_explosion_single_then_big_oam10;
struct OamFrame particle_sprite_explosion_single_then_big_oam11;
struct OamFrame particle_sprite_explosion_single_then_big_oam12;
struct OamFrame particle_sprite_explosion_single_then_big_oam13;
struct OamFrame particle_sprite_explosion_single_then_big_oam14;
struct OamFrame particle_sprite_explosion_single_then_big_oam15;
struct OamFrame particle_sprite_explosion_single_then_big_oam16;
struct OamFrame particle_screw_attack_destroyed_oam1;
struct OamFrame particle_screw_attack_destroyed_oam2;
struct OamFrame particle_screw_attack_destroyed_oam3;
struct OamFrame particle_screw_attack_destroyed_oam4;
struct OamFrame particle_screw_attack_destroyed_oam5;
struct OamFrame particle_screw_attack_destroyed_oam6;
struct OamFrame particle_screw_attack_destroyed_oam7;
struct OamFrame particle_screw_attack_destroyed_oam8;
struct OamFrame particle_shinespark_destroyed_oam1;
struct OamFrame particle_shinespark_destroyed_oam2;
struct OamFrame particle_shinespark_destroyed_oam3;
struct OamFrame particle_shinespark_destroyed_oam4;
struct OamFrame particle_shinespark_destroyed_oam5;
struct OamFrame particle_shinespark_destroyed_oam6;
struct OamFrame particle_shinespark_destroyed_oam7;
struct OamFrame particle_shinespark_destroyed_oam8;
struct OamFrame particle_shinespark_destroyed_oam9;
struct OamFrame particle_shinespark_destroyed_oam10;
struct OamFrame particle_sudo_screw_destroyed_oam1;
struct OamFrame particle_sudo_screw_destroyed_oam2;
struct OamFrame particle_sudo_screw_destroyed_oam3;
struct OamFrame particle_sudo_screw_destroyed_oam4;
struct OamFrame particle_sudo_screw_destroyed_oam5;
struct OamFrame particle_sudo_screw_destroyed_oam6;
struct OamFrame particle_sudo_screw_destroyed_oam7;
struct OamFrame particle_sudo_screw_destroyed_oam8;
struct OamFrame particle_speedbooster_destroyed_oam1;
struct OamFrame particle_speedbooster_destroyed_oam2;
struct OamFrame particle_speedbooster_destroyed_oam3;
struct OamFrame particle_speedbooster_destroyed_oam4;
struct OamFrame particle_speedbooster_destroyed_oam5;
struct OamFrame particle_speedbooster_destroyed_oam6;
struct OamFrame particle_speedbooster_destroyed_oam7;
struct OamFrame particle_speedbooster_destroyed_oam8;
struct OamFrame particle_freezing_sprite_with_ice_oam1;
struct OamFrame particle_freezing_sprite_with_ice_oam2;
struct OamFrame particle_freezing_sprite_with_ice_oam3;
struct OamFrame particle_freezing_sprite_with_ice_oam4;
struct OamFrame particle_freezing_sprite_with_ice_oam5;
struct OamFrame particle_freezing_sprite_with_ice_oam6;
struct OamFrame particle_freezing_sprite_with_ice_oam7;
struct OamFrame particle_freezing_sprite_with_ice_oam8;
struct OamFrame particle_freezing_sprite_with_ice_oam9;
struct OamFrame particle_freezing_sprite_with_ice_oam10;
struct OamFrame particle_freezing_sprite_with_ice_oam11;
struct OamFrame particle_freezing_sprite_with_ice_oam12;
struct OamFrame particle_freezing_sprite_with_ice_oam13;
struct OamFrame particle_freezing_sprite_with_ice_oam14;
struct OamFrame particle_freezing_sprite_with_ice_oam15;
struct OamFrame particle_freezing_sprite_with_ice_oam16;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam1;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam2;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam3;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam4;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam5;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam6;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam7;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam8;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam9;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam10;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam11;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam12;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam13;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam14;
struct OamFrame particle_freezing_sprite_with_charged_ice_oam15;
struct OamFrame particle_main_boss_death_oam1;
struct OamFrame particle_main_boss_death_oam2;
struct OamFrame particle_main_boss_death_oam3;
struct OamFrame particle_main_boss_death_oam4;
struct OamFrame particle_main_boss_death_oam5;
struct OamFrame particle_main_boss_death_oam6;
struct OamFrame particle_main_boss_death_oam7;
struct OamFrame particle_main_boss_death_oam8;
struct OamFrame particle_main_boss_death_oam9;
struct OamFrame particle_main_boss_death_oam10;
struct OamFrame particle_main_boss_death_oam11;
struct OamFrame particle_main_boss_death_oam12;
struct OamFrame particle_main_boss_death_oam13;
struct OamFrame particle_main_boss_death_oam14;
struct OamFrame particle_main_boss_death_oam15;
struct OamFrame particle_main_boss_death_oam16;
struct OamFrame particle_main_boss_death_oam17;
struct OamFrame water_drop_oam1;
struct OamFrame water_drop_oam2;
struct OamFrame water_drop_oam3;
struct OamFrame water_drop_oam4;
struct OamFrame water_drop_oam5;
struct OamFrame water_drop_oam6;
struct OamFrame water_drop_oam7;
struct OamFrame water_drop_oam_falling1;
struct OamFrame water_drop_oam_splashing1;
struct OamFrame water_drop_oam_splashing2;
struct OamFrame water_drop_oam_splashing3;
struct OamFrame water_drop_oam_splashing4;
struct OamFrame water_drop_oam_splashing5;
struct OamFrame sprite_debris_oam1;
struct OamFrame sprite_debris_oam2;
struct OamFrame sprite_debris_oam3;
struct OamFrame sprite_debris_oam4;
struct OamFrame sprite_debris_oam6;
struct OamFrame sprite_debris_oam7;
struct OamFrame sprite_debris_oam8;
struct OamFrame sprite_debris_oam9;
struct OamFrame sprite_debris_oam10;
struct OamFrame sprite_debris_oam11;
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
struct FrameData water_drop_oam[8];
struct FrameData water_drop_oam_falling[2];
struct FrameData water_drop_oam_splashing[6];
struct FrameData sprite_debris_oam[12];

/* blob_0x833bd34_0x833cbdf.c */

u8 blob_0x833bd34_0x833cbdf[3756];

/* particle_splash_data.c */

struct OamFrame particle_sprite_splash_water_big_oam1;
struct OamFrame particle_sprite_splash_water_big_oam2;
struct OamFrame particle_sprite_splash_water_big_oam3;
struct OamFrame particle_sprite_splash_water_big_oam4;
struct OamFrame particle_sprite_splash_water_big_oam5;
struct OamFrame particle_sprite_splash_water_big_oam6;
struct OamFrame particle_sprite_splash_water_big_oam7;
struct OamFrame particle_sprite_splash_water_big_oam8;
struct OamFrame particle_sprite_splash_water_big_oam9;
struct OamFrame particle_sprite_splash_water_huge_oam1;
struct OamFrame particle_sprite_splash_water_huge_oam2;
struct OamFrame particle_sprite_splash_water_huge_oam3;
struct OamFrame particle_sprite_splash_water_huge_oam4;
struct OamFrame particle_sprite_splash_water_huge_oam5;
struct OamFrame particle_sprite_splash_water_huge_oam6;
struct OamFrame particle_sprite_splash_water_huge_oam7;
struct OamFrame particle_sprite_splash_water_huge_oam8;
struct OamFrame particle_sprite_splash_water_huge_oam9;
struct OamFrame particle_sprite_splash_water_small_oam1;
struct OamFrame particle_sprite_splash_water_small_oam2;
struct OamFrame particle_sprite_splash_water_small_oam3;
struct OamFrame particle_sprite_splash_water_small_oam4;
struct OamFrame particle_sprite_splash_water_small_oam5;
struct OamFrame particle_sprite_splash_water_small_oam6;
struct OamFrame particle_sprite_splash_lava_big_oam1;
struct OamFrame particle_sprite_splash_lava_big_oam2;
struct OamFrame particle_sprite_splash_lava_big_oam3;
struct OamFrame particle_sprite_splash_lava_big_oam4;
struct OamFrame particle_sprite_splash_lava_big_oam5;
struct OamFrame particle_sprite_splash_lava_big_oam6;
struct OamFrame particle_sprite_splash_lava_big_oam7;
struct OamFrame particle_sprite_splash_lava_big_oam8;
struct OamFrame particle_sprite_splash_lava_big_oam9;
struct OamFrame particle_sprite_splash_lava_huge_oam1;
struct OamFrame particle_sprite_splash_lava_huge_oam2;
struct OamFrame particle_sprite_splash_lava_huge_oam3;
struct OamFrame particle_sprite_splash_lava_huge_oam4;
struct OamFrame particle_sprite_splash_lava_huge_oam5;
struct OamFrame particle_sprite_splash_lava_huge_oam6;
struct OamFrame particle_sprite_splash_lava_huge_oam7;
struct OamFrame particle_sprite_splash_lava_huge_oam8;
struct OamFrame particle_sprite_splash_lava_huge_oam9;
struct OamFrame particle_sprite_splash_lava_small_oam1;
struct OamFrame particle_sprite_splash_lava_small_oam2;
struct OamFrame particle_sprite_splash_lava_small_oam3;
struct OamFrame particle_sprite_splash_lava_small_oam4;
struct OamFrame particle_sprite_splash_lava_small_oam5;
struct OamFrame particle_sprite_splash_lava_small_oam6;
struct OamFrame particle_sprite_splash_acid_big_oam1;
struct OamFrame particle_sprite_splash_acid_big_oam2;
struct OamFrame particle_sprite_splash_acid_big_oam3;
struct OamFrame particle_sprite_splash_acid_big_oam4;
struct OamFrame particle_sprite_splash_acid_big_oam5;
struct OamFrame particle_sprite_splash_acid_big_oam6;
struct OamFrame particle_sprite_splash_acid_big_oam7;
struct OamFrame particle_sprite_splash_acid_big_oam8;
struct OamFrame particle_sprite_splash_acid_big_oam9;
struct OamFrame particle_sprite_splash_acid_huge_oam1;
struct OamFrame particle_sprite_splash_acid_huge_oam2;
struct OamFrame particle_sprite_splash_acid_huge_oam3;
struct OamFrame particle_sprite_splash_acid_huge_oam4;
struct OamFrame particle_sprite_splash_acid_huge_oam5;
struct OamFrame particle_sprite_splash_acid_huge_oam6;
struct OamFrame particle_sprite_splash_acid_huge_oam7;
struct OamFrame particle_sprite_splash_acid_huge_oam8;
struct OamFrame particle_sprite_splash_acid_huge_oam9;
struct OamFrame particle_sprite_splash_acid_small_oam1;
struct OamFrame particle_sprite_splash_acid_small_oam2;
struct OamFrame particle_sprite_splash_acid_small_oam3;
struct OamFrame particle_sprite_splash_acid_small_oam4;
struct OamFrame particle_sprite_splash_acid_small_oam5;
struct OamFrame particle_sprite_splash_acid_small_oam6;
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

SamusFunc_t samus_pose_functions_pointers[67];
SamusFunc_t samus_pose_gfx_functions_pointers[67];

/* sprite_pointers.c */

Func_t primary_sprite_ai_pointers[206];

/* blob_0x875e8c0_0x87fffff.c */

u8 blob_0x875e8c0_0x87fffff[661311];

#endif /* DATA_H */
