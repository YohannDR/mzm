#ifndef DATA_H
#define DATA_H

#include "../src/oam.h"
#include "../src/types.h"

/* generic_data.c */

i16 sine_y_values[320];
u8 random_number_table[256];

/* blob_0x808ca9c_0x82b0d67 */

u8 blob_0x808ca9c_0x82b0d67[2245324];

/* sprite_stats.c */

u16 primary_sprite_stats[206][9];
u16 secondary_sprite_stats[77][9];

/* blob_0x82b214e_0x82b25c7 */

u8 blob_0x82b214e_0x82b25c7[1146];

/* enemy_drop.c */

struct oam_frame small_energy_drop_oam1;
struct oam_frame small_energy_drop_oam2;
struct oam_frame small_energy_drop_oam3;
struct oam_frame small_energy_drop_oam4;
struct oam_frame large_energy_drop_oam1;
struct oam_frame large_energy_drop_oam2;
struct oam_frame large_energy_drop_oam3;
struct oam_frame large_energy_drop_oam4;
struct oam_frame missile_drop_oam1;
struct oam_frame missile_drop_oam2;
struct oam_frame super_missile_drop_oam1;
struct oam_frame super_missile_drop_oam2;
struct oam_frame power_bomb_drop_oam1;
struct oam_frame power_bomb_drop_oam2;
struct oam_frame multiple_large_energy_drop_slot1_oam1;
struct oam_frame multiple_large_energy_drop_slot1_oam2;
struct oam_frame multiple_large_energy_drop_slot1_oam3;
struct oam_frame multiple_large_energy_drop_slot1_oam4;
struct oam_frame multiple_large_energy_drop_slot3_oam1;
struct oam_frame multiple_large_energy_drop_slot3_oam2;
struct oam_frame multiple_large_energy_drop_slot3_oam3;
struct oam_frame multiple_large_energy_drop_slot3_oam4;
struct oam_frame multiple_large_energy_drop_slot2_oam1;
struct oam_frame multiple_large_energy_drop_slot2_oam2;
struct oam_frame multiple_large_energy_drop_slot2_oam3;
struct oam_frame multiple_large_energy_drop_slot2_oam4;
struct frame_data small_energy_drop_oam[5];
struct frame_data large_energy_drop_oam[5];
struct frame_data missile_drop_oam[3];
struct frame_data super_missile_drop_oam[3];
struct frame_data power_bomb_drop_oam[3];
struct frame_data multiple_large_energy_drop_slot1_oam[5];
struct frame_data multiple_large_energy_drop_slot3_oam[5];
struct frame_data multiple_large_energy_drop_slot2_oam[5];

/* unused_sprites_data.c */

struct oam_frame unused_sprites_oam1;
struct oam_frame unused_sprites_oam2;
struct oam_frame unused_sprites_oam4;
u8 unused_sprites_gfx[24];
u16 unused_sprites_pal[16];
struct frame_data unused_sprites_oam[5];

/* morph_ball_data.c */

u8 morph_ball_gfx[672];
u16 morph_ball_pal[16];
struct oam_frame morph_ball_oam1;
struct oam_frame morph_ball_oam2;
struct oam_frame morph_ball_oam3;
struct oam_frame morph_ball_oam4;
struct oam_frame morph_ball_outside_oam1;
struct oam_frame morph_ball_outside_oam2;
struct oam_frame morph_ball_outside_oam3;
struct oam_frame morph_ball_outside_oam4;
struct oam_frame morph_ball_outside_oam5;
struct frame_data morph_ball_oam[5];
struct frame_data morph_ball_outside_oam[6];

/* power_grip_data.c */

u8 power_grip_gfx[1116];
u16 power_grip_pal[32];
struct oam_frame power_grip_oam1;
struct oam_frame power_grip_oam2;
struct oam_frame power_grip_oam3;
struct oam_frame power_grip_oam4;
struct oam_frame power_grip_glow_oam1;
struct oam_frame power_grip_glow_oam2;
struct oam_frame power_grip_glow_oam3;
struct oam_frame power_grip_glow_oam4;
struct oam_frame power_grip_glow_oam5;
struct oam_frame power_grip_glow_oam6;
struct oam_frame power_grip_glow_oam7;
struct oam_frame power_grip_glow_oam8;
struct oam_frame power_grip_glow_oam9;
struct oam_frame power_grip_glow_oam10;
struct oam_frame power_grip_glow_oam11;
struct oam_frame power_grip_glow_oam12;
struct oam_frame power_grip_glow_oam13;
struct oam_frame power_grip_glow_oam14;
struct frame_data power_grip_oam[5];
struct frame_data power_grip_glow_oam[15];

/* charge_beam_data.c */

i16 charge_beam_y_position_offsets[66];
u8 charge_beam_gfx[972];
u16 charge_beam_pal[16];
struct oam_frame charge_beam_oam_visible1;
struct oam_frame charge_beam_oam_visible2;
struct oam_frame charge_beam_oam_visible3;
struct oam_frame charge_beam_oam_visible4;
struct oam_frame charge_beam_oam1;
struct oam_frame charge_beam_oam2;
struct oam_frame charge_beam_oam3;
struct oam_frame charge_beam_oam4;
struct oam_frame charge_beam_oam5;
struct oam_frame charge_beam_oam6;
struct oam_frame charge_beam_oam7;
struct oam_frame charge_beam_oam8;
struct oam_frame charge_beam_oam9;
struct oam_frame charge_beam_oam10;
struct oam_frame charge_beam_oam11;
struct oam_frame charge_beam_oam12;
struct oam_frame charge_beam_glow_oam1;
struct oam_frame charge_beam_glow_oam2;
struct oam_frame charge_beam_glow_oam3;
struct oam_frame charge_beam_glow_oam4;
struct oam_frame charge_beam_glow_oam5;
struct oam_frame charge_beam_glow_oam6;
struct oam_frame charge_beam_glow_oam7;
struct oam_frame charge_beam_glow_oam8;
struct oam_frame charge_beam_glow_oam9;
struct oam_frame charge_beam_glow_oam10;
struct oam_frame charge_beam_glow_oam11;
struct oam_frame charge_beam_glow_oam12;
struct oam_frame charge_beam_glow_oam13;
struct oam_frame charge_beam_glow_oam14;
struct frame_data charge_beam_oam_visible[5];
struct frame_data charge_beam_oam[13];
struct frame_data charge_beam_glow_oam[15];

/* skree_data.c */

i16 skree_falling_speed[8];
u8 skree_gfx[1056];
u16 skree_pal[16];
u8 skree_blue_gfx[1056];
u16 skree_blue_pal[16];
struct oam_frame skree_oam_11;
struct oam_frame skree_oam_12;
struct oam_frame skree_oam_13;
struct oam_frame skree_oam_14;
struct oam_frame skree_oam_21;
struct oam_frame skree_oam_22;
struct oam_frame skree_oam_23;
struct oam_frame skree_oam_24;
struct oam_frame skree_oam_25;
struct oam_frame skree_oam_31;
struct oam_frame skree_oam_32;
struct oam_frame skree_oam_33;
struct oam_frame skree_oam_34;
struct oam_frame skree_oam_41;
struct oam_frame skree_oam_42;
struct oam_frame skree_oam_43;
struct oam_frame skree_oam_44;
struct oam_frame skree_oam_51;
struct oam_frame skree_oam_52;
struct oam_frame skree_oam_53;
struct oam_frame skree_oam_54;
struct oam_frame skree_oam_61;
struct oam_frame skree_oam_62;
struct oam_frame skree_oam_63;
struct oam_frame skree_oam_64;
struct oam_frame skree_oam_65;
struct oam_frame skree_oam_71;
struct oam_frame skree_oam_72;
struct oam_frame skree_oam_73;
struct oam_frame skree_oam_74;
struct oam_frame skree_oam_81;
struct oam_frame skree_oam_82;
struct oam_frame skree_oam_83;
struct oam_frame skree_oam_84;
struct oam_frame skree_oam_91;
struct oam_frame skree_oam_92;
struct oam_frame skree_oam_93;
struct oam_frame skree_oam_101;
struct oam_frame skree_oam_102;
struct oam_frame skree_oam_103;
struct frame_data skree_oam_1[5];
struct frame_data skree_oam_2[6];
struct frame_data skree_oam_3[5];
struct frame_data skree_oam_4[5];
struct frame_data skree_oam_5[5];
struct frame_data skree_oam_6[6];
struct frame_data skree_oam_7[5];
struct frame_data skree_oam_8[5];
struct frame_data skree_oam_9[4];
struct frame_data skree_oam_10[4];

/* normal_beam_data.c */

u8 normal_beam_gfx[2048];
struct oam_frame normal_beam_oam_forward1;
struct oam_frame normal_beam_oam_forward2;
struct oam_frame normal_beam_oam_diagonal1;
struct oam_frame normal_beam_oam_diagonal2;
struct oam_frame normal_beam_oam_up_down1;
struct oam_frame normal_beam_oam_up_down2;
struct oam_frame normal_beam_oam_unused11;
struct oam_frame normal_beam_oam_unused12;
struct oam_frame normal_beam_oam_unused21;
struct oam_frame normal_beam_oam_unused22;
struct oam_frame normal_beam_oam_unused31;
struct oam_frame normal_beam_oam_unused32;
struct oam_frame charged_normal_beam_oam_forward1;
struct oam_frame charged_normal_beam_oam_forward2;
struct oam_frame charged_normal_beam_oam_diagonal1;
struct oam_frame charged_normal_beam_oam_diagonal2;
struct oam_frame charged_normal_beam_oam_up_down1;
struct oam_frame charged_normal_beam_oam_up_down2;
struct oam_frame normal_beam_oam_unused41;
struct oam_frame normal_beam_oam_unused42;
struct oam_frame normal_beam_oam_unused43;
struct oam_frame normal_beam_oam_unused44;
struct frame_data normal_beam_oam_forward[3];
struct frame_data normal_beam_oam_diagonal[3];
struct frame_data normal_beam_oam_up_down[3];
struct frame_data normal_beam_oam_unused1[3];
struct frame_data normal_beam_oam_unused2[3];
struct frame_data normal_beam_oam_unused3[3];
struct frame_data charged_normal_beam_oam_forward[3];
struct frame_data charged_normal_beam_oam_diagonal[3];
struct frame_data charged_normal_beam_oam_up_down[3];
struct frame_data normal_beam_oam_unused4[5];

/* long_beam_data.c */

u8 long_normal_beam_gfx[2048];
struct oam_frame long_beam_oam_forward1;
struct oam_frame long_beam_oam_forward2;
struct oam_frame long_beam_oam_diagonal1;
struct oam_frame long_beam_oam_diagonal2;
struct oam_frame long_beam_oam_up_down1;
struct oam_frame long_beam_oam_up_down2;
struct oam_frame charged_long_beam_oam_forward1;
struct oam_frame charged_long_beam_oam_forward2;
struct oam_frame charged_long_beam_oam_diagonal1;
struct oam_frame charged_long_beam_oam_diagonal2;
struct oam_frame charged_long_beam_oam_up_down1;
struct oam_frame charged_long_beam_oam_up_down2;
struct oam_frame particle_charged_long_beam_trail_oam1;
struct oam_frame particle_charged_long_beam_trail_oam2;
struct oam_frame particle_charged_long_beam_trail_oam3;
struct oam_frame particle_charged_long_beam_trail_oam4;
struct frame_data long_beam_oam_forward[3];
struct frame_data long_beam_oam_diagonal[3];
struct frame_data long_beam_oam_up_down[3];
struct frame_data charged_long_beam_oam_forward[3];
struct frame_data charged_long_beam_oam_diagonal[3];
struct frame_data charged_long_beam_oam_up_down[3];
struct frame_data particle_charged_long_beam_trail_oam[5];

/* ice_beam_data.c */

u8 ice_beam_gfx[2048];
struct oam_frame ice_beam_oam_forward1;
struct oam_frame ice_beam_oam_forward2;
struct oam_frame ice_beam_oam_diagonal1;
struct oam_frame ice_beam_oam_diagonal2;
struct oam_frame ice_beam_oam_up_down1;
struct oam_frame ice_beam_oam_up_down2;
struct oam_frame ice_beam_oam_unused11;
struct oam_frame ice_beam_oam_unused12;
struct oam_frame ice_beam_oam_unused21;
struct oam_frame ice_beam_oam_unused22;
struct oam_frame ice_beam_oam_unused31;
struct oam_frame ice_beam_oam_unused32;
struct oam_frame charged_ice_beam_oam_forward1;
struct oam_frame charged_ice_beam_oam_forward2;
struct oam_frame charged_ice_beam_oam_diagonal1;
struct oam_frame charged_ice_beam_oam_diagonal2;
struct oam_frame charged_ice_beam_oam_up_down1;
struct oam_frame charged_ice_beam_oam_up_down2;
struct oam_frame particle_charged_ice_beam_trail_oam1;
struct oam_frame particle_charged_ice_beam_trail_oam2;
struct oam_frame particle_charged_ice_beam_trail_oam3;
struct oam_frame particle_charged_ice_beam_trail_oam4;
struct oam_frame particle_charged_ice_beam_trail_oam5;
struct frame_data ice_beam_oam_forward[3];
struct frame_data ice_beam_oam_diagonal[3];
struct frame_data ice_beam_oam_up_down[3];
struct frame_data ice_beam_oam_unused1[3];
struct frame_data ice_beam_oam_unused2[3];
struct frame_data ice_beam_oam_unused3[3];
struct frame_data charged_ice_beam_oam_forward[3];
struct frame_data charged_ice_beam_oam_diagonal[3];
struct frame_data charged_ice_beam_oam_up_down[3];
struct frame_data particle_charged_ice_beam_trail_oam[5];

/* wave_beam_data.c */

u8 wave_beam_gfx[2048];
struct oam_frame wave_beam_oam_forward1;
struct oam_frame wave_beam_oam_forward2;
struct oam_frame wave_beam_oam_forward3;
struct oam_frame wave_beam_oam_forward4;
struct oam_frame wave_beam_oam_forward5;
struct oam_frame wave_beam_oam_forward6;
struct oam_frame wave_beam_oam_forward7;
struct oam_frame wave_beam_oam_diagonal1;
struct oam_frame wave_beam_oam_diagonal2;
struct oam_frame wave_beam_oam_diagonal3;
struct oam_frame wave_beam_oam_diagonal4;
struct oam_frame wave_beam_oam_diagonal5;
struct oam_frame wave_beam_oam_diagonal6;
struct oam_frame wave_beam_oam_diagonal7;
struct oam_frame wave_beam_oam_up_down1;
struct oam_frame wave_beam_oam_up_down2;
struct oam_frame wave_beam_oam_up_down3;
struct oam_frame wave_beam_oam_up_down4;
struct oam_frame wave_beam_oam_up_down5;
struct oam_frame wave_beam_oam_up_down6;
struct oam_frame wave_beam_oam_up_down7;
struct oam_frame wave_beam_oam_unused11;
struct oam_frame wave_beam_oam_unused12;
struct oam_frame wave_beam_oam_unused13;
struct oam_frame wave_beam_oam_unused14;
struct oam_frame wave_beam_oam_unused15;
struct oam_frame wave_beam_oam_unused16;
struct oam_frame wave_beam_oam_unused17;
struct oam_frame wave_beam_oam_unused21;
struct oam_frame wave_beam_oam_unused22;
struct oam_frame wave_beam_oam_unused23;
struct oam_frame wave_beam_oam_unused24;
struct oam_frame wave_beam_oam_unused25;
struct oam_frame wave_beam_oam_unused26;
struct oam_frame wave_beam_oam_unused27;
struct oam_frame wave_beam_oam_unused31;
struct oam_frame wave_beam_oam_unused32;
struct oam_frame wave_beam_oam_unused33;
struct oam_frame wave_beam_oam_unused34;
struct oam_frame wave_beam_oam_unused35;
struct oam_frame wave_beam_oam_unused36;
struct oam_frame wave_beam_oam_unused37;
struct oam_frame charged_wave_beam_oam_forward1;
struct oam_frame charged_wave_beam_oam_forward2;
struct oam_frame charged_wave_beam_oam_forward3;
struct oam_frame charged_wave_beam_oam_forward4;
struct oam_frame charged_wave_beam_oam_forward5;
struct oam_frame charged_wave_beam_oam_forward6;
struct oam_frame charged_wave_beam_oam_forward7;
struct oam_frame charged_wave_beam_oam_diagonal1;
struct oam_frame charged_wave_beam_oam_diagonal2;
struct oam_frame charged_wave_beam_oam_diagonal3;
struct oam_frame charged_wave_beam_oam_diagonal4;
struct oam_frame charged_wave_beam_oam_diagonal5;
struct oam_frame charged_wave_beam_oam_diagonal6;
struct oam_frame charged_wave_beam_oam_diagonal7;
struct oam_frame charged_wave_beam_oam_up_down1;
struct oam_frame charged_wave_beam_oam_up_down2;
struct oam_frame charged_wave_beam_oam_up_down3;
struct oam_frame charged_wave_beam_oam_up_down4;
struct oam_frame charged_wave_beam_oam_up_down5;
struct oam_frame charged_wave_beam_oam_up_down6;
struct oam_frame charged_wave_beam_oam_up_down7;
struct oam_frame particle_charged_wave_beam_trail_oam1;
struct oam_frame particle_charged_wave_beam_trail_oam2;
struct oam_frame particle_charged_wave_beam_trail_oam3;
struct oam_frame particle_charged_wave_beam_trail_oam4;
struct frame_data wave_beam_oam_forward[8];
struct frame_data wave_beam_oam_diagonal[8];
struct frame_data wave_beam_oam_up_down[8];
struct frame_data wave_beam_oam_unused1[8];
struct frame_data wave_beam_oam_unused2[8];
struct frame_data wave_beam_oam_unused3[8];
struct frame_data charged_wave_beam_oam_forward[8];
struct frame_data charged_wave_beam_oam_diagonal[8];
struct frame_data charged_wave_beam_oam_up_down[8];
struct frame_data particle_charged_wave_beam_trail_oam[5];

/* plasma_beam_data.c */

u8 plasma_beam_gfx[2048];
struct oam_frame plasma_beam_no_wave_oam_forward1;
struct oam_frame plasma_beam_no_wave_oam_forward2;
struct oam_frame plasma_beam_no_wave_oam_diagonal1;
struct oam_frame plasma_beam_no_wave_oam_diagonal2;
struct oam_frame plasma_beam_no_wave_oam_up_down1;
struct oam_frame plasma_beam_no_wave_oam_up_down2;
struct oam_frame plasma_beam_no_wave_oam_unused11;
struct oam_frame plasma_beam_no_wave_oam_unused12;
struct oam_frame plasma_beam_no_wave_oam_unused21;
struct oam_frame plasma_beam_no_wave_oam_unused22;
struct oam_frame plasma_beam_no_wave_oam_unused31;
struct oam_frame plasma_beam_no_wave_oam_unused32;
struct oam_frame charged_plasma_beam_no_wave_oam_forward1;
struct oam_frame charged_plasma_beam_no_wave_oam_forward2;
struct oam_frame charged_plasma_beam_no_wave_oam_diagonal1;
struct oam_frame charged_plasma_beam_no_wave_oam_diagonal2;
struct oam_frame charged_plasma_beam_no_wave_oam_up_down1;
struct oam_frame charged_plasma_beam_no_wave_oam_up_down2;
struct oam_frame plasma_beam_wave_oam_forward1;
struct oam_frame plasma_beam_wave_oam_forward2;
struct oam_frame plasma_beam_wave_oam_forward3;
struct oam_frame plasma_beam_wave_oam_forward4;
struct oam_frame plasma_beam_wave_oam_forward5;
struct oam_frame plasma_beam_wave_oam_forward6;
struct oam_frame plasma_beam_wave_oam_forward7;
struct oam_frame plasma_beam_wave_oam_diagonal1;
struct oam_frame plasma_beam_wave_oam_diagonal2;
struct oam_frame plasma_beam_wave_oam_diagonal3;
struct oam_frame plasma_beam_wave_oam_diagonal4;
struct oam_frame plasma_beam_wave_oam_diagonal5;
struct oam_frame plasma_beam_wave_oam_diagonal6;
struct oam_frame plasma_beam_wave_oam_diagonal7;
struct oam_frame plasama_beam_wave_oam_up_down1;
struct oam_frame plasama_beam_wave_oam_up_down2;
struct oam_frame plasama_beam_wave_oam_up_down3;
struct oam_frame plasama_beam_wave_oam_up_down4;
struct oam_frame plasama_beam_wave_oam_up_down5;
struct oam_frame plasama_beam_wave_oam_up_down6;
struct oam_frame plasama_beam_wave_oam_up_down7;
struct oam_frame plasma_beam_wave_oam_unused11;
struct oam_frame plasma_beam_wave_oam_unused12;
struct oam_frame plasma_beam_wave_oam_unused13;
struct oam_frame plasma_beam_wave_oam_unused14;
struct oam_frame plasma_beam_wave_oam_unused15;
struct oam_frame plasma_beam_wave_oam_unused21;
struct oam_frame plasma_beam_wave_oam_unused22;
struct oam_frame plasma_beam_wave_oam_unused23;
struct oam_frame plasma_beam_wave_oam_unused24;
struct oam_frame plasma_beam_wave_oam_unused25;
struct oam_frame plasma_beam_wave_oam_unused31;
struct oam_frame plasma_beam_wave_oam_unused32;
struct oam_frame plasma_beam_wave_oam_unused33;
struct oam_frame plasma_beam_wave_oam_unused34;
struct oam_frame plasma_beam_wave_oam_unused35;
struct oam_frame charged_plasma_beam_wave_oam_forward1;
struct oam_frame charged_plasma_beam_wave_oam_forward2;
struct oam_frame charged_plasma_beam_wave_oam_forward3;
struct oam_frame charged_plasma_beam_wave_oam_forward4;
struct oam_frame charged_plasma_beam_wave_oam_forward5;
struct oam_frame charged_plasma_beam_wave_oam_forward6;
struct oam_frame charged_plasma_beam_wave_oam_forward7;
struct oam_frame charged_plasma_beam_wave_oam_diagonal1;
struct oam_frame charged_plasma_beam_wave_oam_diagonal2;
struct oam_frame charged_plasma_beam_wave_oam_diagonal3;
struct oam_frame charged_plasma_beam_wave_oam_diagonal4;
struct oam_frame charged_plasma_beam_wave_oam_diagonal5;
struct oam_frame charged_plasma_beam_wave_oam_diagonal6;
struct oam_frame charged_plasma_beam_wave_oam_diagonal7;
struct oam_frame charged_plasma_beam_wave_oam_up_down1;
struct oam_frame charged_plasma_beam_wave_oam_up_down2;
struct oam_frame charged_plasma_beam_wave_oam_up_down3;
struct oam_frame charged_plasma_beam_wave_oam_up_down4;
struct oam_frame charged_plasma_beam_wave_oam_up_down5;
struct oam_frame charged_plasma_beam_wave_oam_up_down6;
struct oam_frame charged_plasma_beam_wave_oam_up_down7;
struct oam_frame particle_charged_plasma_beam_trail_oam1;
struct oam_frame particle_charged_plasma_beam_trail_oam2;
struct oam_frame particle_charged_plasma_beam_trail_oam3;
struct oam_frame particle_charged_plasma_beam_trail_oam4;
struct oam_frame particle_charged_full_beam_trail_oam1;
struct oam_frame particle_charged_full_beam_trail_oam2;
struct oam_frame particle_charged_full_beam_trail_oam3;
struct oam_frame particle_charged_full_beam_trail_oam4;
struct oam_frame particle_charged_full_beam_trail_oam5;
struct oam_frame particle_charged_full_beam_trail_oam6;
struct oam_frame particle_charged_full_beam_trail_oam7;
struct oam_frame particle_charged_full_beam_trail_oam8;
struct frame_data plasma_beam_no_wave_oam_forward[3];
struct frame_data plasma_beam_no_wave_oam_diagonal[3];
struct frame_data plasma_beam_no_wave_oam_up_down[3];
struct frame_data plasma_beam_no_wave_oam_unused1[3];
struct frame_data plasma_beam_no_wave_oam_unused2[3];
struct frame_data plasma_beam_no_wave_oam_unused3[3];
struct frame_data charged_plasma_beam_no_wave_oam_forward[3];
struct frame_data charged_plasma_beam_no_wave_oam_diagonal[3];
struct frame_data charged_plasma_beam_no_wave_oam_up_down[3];
struct frame_data plasma_beam_wave_oam_forward[8];
struct frame_data plasma_beam_wave_oam_diagonal[8];
struct frame_data plasama_beam_wave_oam_up_down[8];
struct frame_data plasma_beam_wave_oam_unused1[6];
struct frame_data plasma_beam_wave_oam_unused2[6];
struct frame_data plasma_beam_wave_oam_unused3[6];
struct frame_data charged_plasma_beam_wave_oam_forward[8];
struct frame_data charged_plasma_beam_wave_oam_diagonal[8];
struct frame_data charged_plasma_beam_wave_oam_up_down[8];
struct frame_data particle_charged_plasma_beam_trail_oam[5];
struct frame_data particle_charged_full_beam_trail_oam[9];

/* pistol_data.c */

u8 pistol_gfx[2048];
struct oam_frame pistol_oam_forward1;
struct oam_frame pistol_oam_forward2;
struct oam_frame pistol_oam_diagonal1;
struct oam_frame pistol_oam_diagonal2;
struct oam_frame pistol_oam_up_down1;
struct oam_frame pistol_oam_up_down2;
struct oam_frame charged_pistol_oam_forward1;
struct oam_frame charged_pistol_oam_forward2;
struct oam_frame charged_pistol_oam_diagonal1;
struct oam_frame charged_pistol_oam_diagonal2;
struct oam_frame charged_pistol_oam_up_down1;
struct oam_frame charged_pistol_oam_up_down2;
struct oam_frame particle_charged_pistol_trail1;
struct oam_frame particle_charged_pistol_trail2;
struct oam_frame particle_charged_pistol_trail3;
struct oam_frame particle_charged_pistol_trail4;
struct frame_data pistol_oam_forward[3];
struct frame_data pistol_oam_diagonal[3];
struct frame_data pistol_oam_up_down[3];
struct frame_data charged_pistol_oam_forward[3];
struct frame_data charged_pistol_oam_diagonal[3];
struct frame_data charged_pistol_oam_up_down[3];
struct frame_data particle_charged_pistol_trail[5];

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

/* blob_0x83313e8_0x87fffff.c */

u8 blob_0x83362a8_0x87fffff[5041176];

#endif /* DATA_H */
