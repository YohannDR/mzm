#ifndef DATA_H
#define DATA_H

#include "oam.h"
#include "types.h"
#include "samus.h"
#include "particle.h"
#include "projectile.h"
#include "sprites_AI/sprites.h"

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

/* blob_0x82b214e_0x82b2523.c */

extern u8 blob_0x82b214e_0x82b2523[982];

/* blob_0x82cd604_0x82f7db3.c */

extern u8 blob_0x82cd604_0x82f7db3[174000];

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

/* blob_0x8331348_0x8339aa7.c */

extern u8 blob_0x8331348_0x8339aa7[34656];

/* blob_0x833bd34_0x833cbdf.c */

extern u8 blob_0x833bd34_0x833cbdf[3756];

/* particle_splash_data.c */

extern struct FrameData ParticleSpriteSplashWaterBig_oam[10];
extern struct FrameData ParticleSpriteSplashWaterHuge_oam[10];
extern struct FrameData ParticleSpriteSplashWaterSmall_oam[7];
extern struct FrameData ParticleSpriteSplashLavaBig_oam[10];
extern struct FrameData ParticleSpriteSplashLavaHuge_oam[10];
extern struct FrameData ParticleSpriteSplashLavaSmall_oam[7];
extern struct FrameData ParticleSpriteSplashAcidBig_oam[10];
extern struct FrameData ParticleSpriteSplashAcidHuge_oam[10];
extern struct FrameData ParticleSpriteSplashAcidSmall_oam[7];

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

#endif /* DATA_H */
