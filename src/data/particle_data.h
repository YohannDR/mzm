#ifndef PARTICLE_DATA_H
#define PARTICLE_DATA_H

#include "../types.h"
#include "../oam.h"

static const u16 sParticleShootingBeamHorizontalOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamHorizontalOAM_Frame1[10] = {
    0x3,
    0xfb, 0x1ff, 0x2182,
    0xf7, 0x1f9, 0x2182,
    0x1, 0x1f9, 0x2182
};

static const u16 sParticleShootingBeamHorizontalOAM_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

static const u16 sParticleShootingBeamHorizontalOAM_Frame3[7] = {
    0x2,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x2182,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x2182
};

static const u16 sParticleShootingBeamDiagonallyUpOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamDiagonallyUpOAM_Frame1[10] = {
    0x3,
    0x1, 0x1ff, 0x2182,
    0xf7, 0x1fe, 0x2182,
    0xfe, 0x1f6, 0x2182
};

static const u16 sParticleShootingBeamDiagonallyUpOAM_Frame2[4] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

static const u16 sParticleShootingBeamDiagonallyUpOAM_Frame3[7] = {
    0x2,
    0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1, 0x2182,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, 0x2182
};

static const u16 sParticleShootingBeamDiagonallyDownOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamDiagonallyDownOAM_Frame1[10] = {
    0x3,
    0xfb, 0x1ff, 0x2182,
    0xf9, 0x1f8, 0x2182,
    0x1, 0x0, 0x2182
};

static const u16 sParticleShootingBeamDiagonallyDownOAM_Frame2[4] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

static const u16 sParticleShootingBeamDiagonallyDownOAM_Frame3[7] = {
    0x2,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fa, 0x2182,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x2182
};

static const u16 sParticleShootingBeamUpOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamUpOAM_Frame1[10] = {
    0x3,
    0x0, 0x1fc, 0x2182,
    0xf9, 0x0, 0x2182,
    0xf9, 0x1f6, 0x2182
};

static const u16 sParticleShootingBeamUpOAM_Frame2[4] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamUpOAM_Frame3[7] = {
    0x2,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, 0x2182,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x2182
};

static const u16 sParticleShootingBeamDownOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamDownOAM_Frame1[10] = {
    0x3,
    0xf8, OBJ_Y_FLIP | 0x1fc, 0x2182,
    0xff, OBJ_Y_FLIP | 0x0, 0x2182,
    0xff, OBJ_Y_FLIP | 0x1f6, 0x2182
};

static const u16 sParticleShootingBeamDownOAM_Frame2[4] = {
    0x1,
    0xf6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

static const u16 sParticleShootingBeamDownOAM_Frame3[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x3, 0x2182,
    0xf8, OBJ_X_FLIP | 0x1f6, 0x2182
};

static const u16 sParticleBombOAM_Frame0[13] = {
    0x4,
    0xf8, 0x1f8, 0x3141,
    0xf8, OBJ_X_FLIP | 0x0, 0x3141,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x3141,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3141
};

static const u16 sParticleBombOAM_Frame1[13] = {
    0x4,
    0xf8, 0x1f8, 0x3142,
    0xf8, OBJ_X_FLIP | 0x0, 0x3142,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x3142,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3142
};

static const u16 sParticleBombOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3100,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3100,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3100,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3100
};

static const u16 sParticleBombOAM_Frame3[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3102,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3102,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3102,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3102
};

static const u16 sParticleBombOAM_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3104,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3104,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3104,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3104
};

static const u16 sParticleBombOAM_Frame5[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3106,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3106,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3106,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3106
};

static const u16 sParticleBeamTrailingOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20d7
};

static const u16 sParticleBeamTrailingOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20d9
};

static const u16 sParticleBeamTrailingOAM_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x20db
};

static const u16 sParticleBeamTrailingOAM_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x20fb
};

static const u16 sParticleBeamTrailingOAM_Frame4[4] = {
    0x1,
    0xfc, 0x1fc, 0x21a2
};

static const u16 sParticleChargingBeamBeginOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2097
};

static const u16 sParticleChargingBeamBeginOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2095
};

static const u16 sParticleChargingBeamBeginOAM_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x2166
};

static const u16 sParticleChargingBeamBeginOAM_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x21c8
};

static const u16 sParticleChargingBeamBeginOAM_Frame6[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2095,
    0xfc, 0x1fc, 0x2090
};

static const u16 sParticleChargingBeamBeginOAM_Frame10[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2097,
    0xfc, 0x1fc, 0x20b0
};

static const u16 sParticleChargingBeamBeginOAM_Frame16[16] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2099,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2099,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x2099,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2099,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2091
};

static const u16 sParticleChargingBeamChargedOAM_Frame1[16] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x209b,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x209b,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x209b,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x209b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2093
};

static const struct FrameData sParticleShootingBeamHorizontalOAM[5] = {
    sParticleShootingBeamHorizontalOAM_Frame0,
    0x1,
    sParticleShootingBeamHorizontalOAM_Frame1,
    0x1,
    sParticleShootingBeamHorizontalOAM_Frame2,
    0x1,
    sParticleShootingBeamHorizontalOAM_Frame3,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sParticleShootingBeamDiagonallyUpOAM[5] = {
    sParticleShootingBeamDiagonallyUpOAM_Frame0,
    0x1,
    sParticleShootingBeamDiagonallyUpOAM_Frame1,
    0x1,
    sParticleShootingBeamDiagonallyUpOAM_Frame2,
    0x1,
    sParticleShootingBeamDiagonallyUpOAM_Frame3,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sParticleShootingBeamDiagonallyDownOAM[5] = {
    sParticleShootingBeamDiagonallyDownOAM_Frame0,
    0x1,
    sParticleShootingBeamDiagonallyDownOAM_Frame1,
    0x1,
    sParticleShootingBeamDiagonallyDownOAM_Frame2,
    0x1,
    sParticleShootingBeamDiagonallyDownOAM_Frame3,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sParticleShootingBeamUpOAM[5] = {
    sParticleShootingBeamUpOAM_Frame0,
    0x1,
    sParticleShootingBeamUpOAM_Frame1,
    0x1,
    sParticleShootingBeamUpOAM_Frame2,
    0x1,
    sParticleShootingBeamUpOAM_Frame3,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sParticleShootingBeamDownOAM[5] = {
    sParticleShootingBeamDownOAM_Frame0,
    0x1,
    sParticleShootingBeamDownOAM_Frame1,
    0x1,
    sParticleShootingBeamDownOAM_Frame2,
    0x1,
    sParticleShootingBeamDownOAM_Frame3,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sParticleBombOAM[7] = {
    sParticleBombOAM_Frame0,
    0x2,
    sParticleBombOAM_Frame1,
    0x2,
    sParticleBombOAM_Frame2,
    0x2,
    sParticleBombOAM_Frame3,
    0x2,
    sParticleBombOAM_Frame4,
    0x2,
    sParticleBombOAM_Frame5,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleBeamTrailingOAM[6] = {
    sParticleBeamTrailingOAM_Frame0,
    0x4,
    sParticleBeamTrailingOAM_Frame1,
    0x4,
    sParticleBeamTrailingOAM_Frame2,
    0x4,
    sParticleBeamTrailingOAM_Frame3,
    0x4,
    sParticleBeamTrailingOAM_Frame4,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParticleChargingBeamBeginOAM[23] = {
    sParticleChargingBeamBeginOAM_Frame0,
    0x2,
    sParticleChargingBeamBeginOAM_Frame1,
    0x2,
    sParticleChargingBeamBeginOAM_Frame2,
    0x3,
    sParticleChargingBeamBeginOAM_Frame3,
    0x3,
    sParticleChargingBeamBeginOAM_Frame2,
    0x3,
    sParticleChargingBeamBeginOAM_Frame3,
    0x3,
    sParticleChargingBeamBeginOAM_Frame6,
    0x3,
    sParticleChargingBeamBeginOAM_Frame3,
    0x3,
    sParticleChargingBeamBeginOAM_Frame6,
    0x3,
    sParticleChargingBeamBeginOAM_Frame3,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    sParticleChargingBeamBeginOAM_Frame6,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    sParticleChargingBeamBeginOAM_Frame6,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    sParticleChargingBeamBeginOAM_Frame6,
    0x3,
    sParticleChargingBeamBeginOAM_Frame16,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    sParticleChargingBeamBeginOAM_Frame16,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    sParticleChargingBeamBeginOAM_Frame16,
    0x3,
    sParticleChargingBeamBeginOAM_Frame10,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sParticleChargingBeamChargedOAM[3] = {
    sParticleChargingBeamBeginOAM_Frame16,
    0x2,
    sParticleChargingBeamChargedOAM_Frame1,
    0x2,
    NULL,
    0x0
};

static const u16 sParticleHittingSomethingWithNormalBeamOAM_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x21c8
};

static const u16 sParticleHittingSomethingWithNormalBeamOAM_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x21e8
};

static const u16 sParticleHittingSomethingWithNormalBeamOAM_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x21c9
};

static const u16 sParticleHittingSomethingWithNormalBeamOAM_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x21e9
};

static const u16 sParticleHittingSomethingWithLongBeamOAM_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x2108,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x2108
};

static const u16 sParticleHittingSomethingWithLongBeamOAM_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x2109,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x2109
};

static const u16 sParticleHittingSomethingWithIceBeamOAM_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x210a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x210a
};

static const u16 sParticleHittingSomethingWithIceBeamOAM_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, 0x2145,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x2145,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_Y_FLIP | 0x1f4, 0x2145,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2145
};

static const u16 sParticleHittingSomethingWithWaveBeamOAM_Frame4[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2143,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2143,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x2143,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2143
};

static const u16 sParticleHittingSomethingWithWaveBeamOAM_Frame5[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2149,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2149,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x2149,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2149
};

static const u16 sParticleHittingSomethingWithPlasmaBeamOAM_Frame5[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147
};

static const u16 sParticleHittingSomethingInvincible_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x2115
};

static const u16 sParticleHittingSomethingInvincible_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x2135
};

static const u16 sParticleHittingSomethingInvincible_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2116
};

static const u16 sParticleHittingSomethingInvincible_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2118
};

static const u16 sParticleHittingSomethingInvincible_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x211a
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f8, 0x30d2
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x30d3
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame3[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame5[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111
};

static const u16 sParticleHittingSomethingWithMissileOAM_Frame6[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3113,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3113,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3113,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3113
};

static const u16 sParticleHittingSomethingWithSuperMissileOAM_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_16x32 | 0x1ec, 0x319a,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x4, 0x319a,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1ff, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f9, 0x30d2
};

static const u16 sParticleHittingSomethingWithSuperMissileOAM_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1e8, 0x319c,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x319c
};

static const u16 sParticleHittingSomethingWithSuperMissileOAM_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1e8, 0x319e,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x319e
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame0[13] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame1[13] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame4[13] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3157,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x3157,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3157
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame5[13] = {
    0x4,
    0xf1, OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame6[22] = {
    0x7,
    0xef, OBJ_SIZE_16x16 | 0x1f2, 0x3196,
    0xe9, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xe6, 0x1f7, 0x30d6,
    0xe0, OBJ_Y_FLIP | 0x1fd, 0x30d6,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xfb, OBJ_SIZE_16x16 | 0x0, 0x3196,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3196
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame7[22] = {
    0x7,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, 0x3196,
    0xe0, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xdc, OBJ_Y_FLIP | 0x1f7, 0x30d6,
    0xd7, 0x1fe, 0x30d6,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, 0x3198,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3198
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame8[22] = {
    0x7,
    0xed, 0x1f4, 0x30d6,
    0xea, OBJ_Y_FLIP | 0x2, 0x30d6,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x3198,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3198,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3198,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x31a7,
    0xd0, OBJ_Y_FLIP | 0x1, 0x31a7
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame9[13] = {
    0x4,
    0xd9, 0x1f8, 0x31a7,
    0xf3, 0x1fd, 0x30d6,
    0xdc, 0x2, 0x30d6,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame10[13] = {
    0x4,
    0xd5, 0x1f8, 0x31a7,
    0xd4, 0x4, 0x31a7,
    0xd7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x31a7
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame11[10] = {
    0x3,
    0xd6, OBJ_Y_FLIP | 0x1fc, 0x31a7,
    0xda, 0x0, 0x31a7,
    0xe9, OBJ_X_FLIP | 0x1fc, 0x31a7
};

static const u16 sParticleSpriteExplosionHugeOAM_Frame12[4] = {
    0x1,
    0xd1, 0x1fc, 0x31a7
};

static const u16 sParticleSmallDustOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188
};

static const u16 sParticleSmallDustOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418a
};

static const u16 sParticleSmallDustOAM_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418c
};

static const u16 sParticleSmallDustOAM_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418e
};

static const u16 sParticleSmallDustOAM_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

static const u16 sParticleSmallDustOAM_Frame5[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4187
};

static const u16 sParticleMediumDustOAM_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f3, 0x4188
};

static const u16 sParticleMediumDustOAM_Frame1[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x4188,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, 0x4188
};

static const u16 sParticleMediumDustOAM_Frame2[10] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fb, 0x418a,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x4188,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, 0x4188
};

static const u16 sParticleMediumDustOAM_Frame3[10] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1fc, 0x418c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, 0x418a,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x6, 0x4188
};

static const u16 sParticleMediumDustOAM_Frame4[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x418e,
    0xec, OBJ_SIZE_16x16 | 0x1ed, 0x418c,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x418a
};

static const u16 sParticleMediumDustOAM_Frame5[10] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xef, OBJ_SIZE_16x16 | 0x8, 0x418c,
    0xed, OBJ_SIZE_16x16 | 0x1fd, 0x41d4
};

static const u16 sParticleMediumDustOAM_Frame6[10] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x6, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fd, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, 0x41d4
};

static const u16 sParticleMediumDustOAM_Frame7[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1f6, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x5, 0x41d4
};

static const u16 sParticleMediumDustOAM_Frame8[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x4, 0x4187
};

static const u16 sParticleTwoMediumDustOAM_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x418a
};

static const u16 sParticleTwoMediumDustOAM_Frame1[10] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    0xec, OBJ_SIZE_16x16 | 0x1ec, 0x4188,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, 0x418a
};

static const u16 sParticleTwoMediumDustOAM_Frame2[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xea, OBJ_SIZE_16x16 | 0x1ea, 0x418a,
    0xf1, OBJ_SIZE_16x16 | 0x2, 0x4188
};

static const u16 sParticleTwoMediumDustOAM_Frame3[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xe4, OBJ_SIZE_16x16 | 0x1eb, 0x418c,
    0xec, OBJ_SIZE_16x16 | 0x4, 0x4188
};

static const u16 sParticleTwoMediumDustOAM_Frame4[13] = {
    0x4,
    0xe0, OBJ_SIZE_16x16 | 0x1ec, 0x418e,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x418a,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x4188,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

static const u16 sParticleTwoMediumDustOAM_Frame5[13] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1, 0x418c,
    0xf0, OBJ_SIZE_16x16 | 0x1ee, 0x418a,
    0xda, OBJ_SIZE_16x16 | 0x1ed, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1fc, 0x4187
};

static const u16 sParticleTwoMediumDustOAM_Frame6[10] = {
    0x3,
    0xe7, OBJ_SIZE_16x16 | 0x0, 0x418e,
    0xeb, OBJ_SIZE_16x16 | 0x1ed, 0x418c,
    OBJ_SHAPE_VERTICAL | 0xd5, 0x1f1, 0x4187
};

static const u16 sParticleTwoMediumDustOAM_Frame7[7] = {
    0x2,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xe4, OBJ_SIZE_16x16 | 0x1ff, 0x41d4
};

static const u16 sParticleTwoMediumDustOAM_Frame8[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x2, 0x4187,
    0xe2, OBJ_SIZE_16x16 | 0x1ef, 0x41d4
};

static const u16 sParticleTwoMediumDustOAM_Frame9[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f6, 0x4187
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3188
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3188
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame2[4] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x318a
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame3[4] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame4[4] = {
    0x1,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x318c
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame5[7] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4188
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame6[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x418a
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame7[7] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418c
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame8[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418e
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame9[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

static const u16 sParticleSpriteExplosionSmallOAM_Frame10[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x4187
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame3[7] = {
    0x2,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x3188
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame4[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3188
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame5[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x0, 0x318a
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame6[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame7[13] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x0, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame8[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x0, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x0, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f2, 0x318a
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame9[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x0, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x318a
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame10[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x318c
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame11[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xec, 0x4, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f2, 0x4188
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame12[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x4, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x0, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f2, 0x418a
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame13[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x4, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x418c
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame14[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f6, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x418e
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame15[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f6, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, 0x41d4
};

static const u16 sParticleSpriteExplosionMediumOAM_Frame16[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1f6, 0x4187
};

static const u16 sParticleSpriteExplosionBigOAM_Frame6[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f6, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0x0, OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

static const u16 sParticleSpriteExplosionBigOAM_Frame7[16] = {
    0x5,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x3, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

static const u16 sParticleSpriteExplosionBigOAM_Frame8[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fa, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x3, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x3, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f0, 0x318a,
    0xfe, OBJ_SIZE_16x16 | 0x1f9, 0x318a
};

static const u16 sParticleSpriteExplosionBigOAM_Frame9[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fa, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f6, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x318a,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x318a
};

static const u16 sParticleSpriteExplosionBigOAM_Frame10[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fa, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x318c,
    0xfc, OBJ_SIZE_16x16 | 0x1f9, 0x318c
};

static const u16 sParticleSpriteExplosionBigOAM_Frame11[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xec, 0x7, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f0, 0x4188,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x318e,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x4188
};

static const u16 sParticleSpriteExplosionBigOAM_Frame12[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x7, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x3, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f0, 0x418a,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x418c
};

static const u16 sParticleSpriteExplosionBigOAM_Frame13[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x7, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x418c,
    0xf6, OBJ_X_FLIP | 0x1, 0x418f,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, 0x418f
};

static const u16 sParticleSpriteExplosionBigOAM_Frame14[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f4, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x1fd, 0x3187
};

static const u16 sParticleSpriteExplosionBigOAM_Frame15[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f4, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f0, 0x41d4
};

static const u16 sParticleSpriteExplosionBigOAM_Frame16[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1f4, 0x4187
};

static const u16 sParticleSpriteExplosionSingleThenBigOAM_Frame3[28] = {
    0x9,
    0xeb, OBJ_SIZE_16x16 | 0x1eb, 0x3155,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, 0x3155,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1eb, 0x3155,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, 0x3155,
    0xea, OBJ_SIZE_16x16 | 0x1f6, 0x3155,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, 0x3155,
    0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x3155,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3155,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, 0x3188
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x30d0
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame1[25] = {
    0x8,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155,
    0xec, OBJ_SIZE_16x16 | 0x1ec, 0x3188,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, 0x3188,
    0x4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x3188,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, 0x3188
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame2[37] = {
    0xc,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3188,
    0xe0, OBJ_SIZE_16x16 | 0x10, 0x3188,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3188,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x3188,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x318a,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, 0x318a
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame3[49] = {
    0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d8, 0x3188,
    0xd8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, 0x3188,
    0x18, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, 0x3188,
    0x18, OBJ_SIZE_16x16 | 0x18, 0x3188,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x318a,
    0xe0, OBJ_SIZE_16x16 | 0x10, 0x318a,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x318a,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x318a,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x418c,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x418c,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x418c,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, 0x418c
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame4[49] = {
    0x10,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d8, 0x318a,
    0xd8, OBJ_SIZE_16x16 | 0x18, 0x318a,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d8, 0x318a,
    0x18, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, 0x318a,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x418c,
    0xe0, OBJ_SIZE_16x16 | 0x10, 0x418c,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x418c,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x418c,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x418e,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x418e,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x418e,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, 0x418e,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3157,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x3157,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3157
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame5[25] = {
    0x9,
    0xd6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d6, 0x418c,
    0xd6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1a, 0x418c,
    0x1a, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d6, 0x418c,
    0x1a, OBJ_SIZE_16x16 | 0x1a, 0x418c,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x418e,
    0xe0, OBJ_SIZE_16x16 | 0x10, 0x418e,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x418e,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x418e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame6[16] = {
    0x5,
    0xd4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d4, 0x418e,
    0xd4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c, 0x418e,
    0x1c, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d4, 0x418e,
    0x1c, OBJ_SIZE_16x16 | 0x1c, 0x418e,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

static const u16 sParticleScrewAttackDestroyedOAM_Frame7[22] = {
    0x7,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x41d4,
    0xd2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e, 0x41d4,
    0x1e, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x41d4,
    0x1e, OBJ_SIZE_16x16 | 0x1e, 0x41d4,
    0xf6, 0x1f6, 0x41a7,
    0x5, 0x1fc, 0x41a7,
    0xf9, OBJ_X_FLIP | 0x5, 0x41a7
};

static const u16 sParticleShinesparkDestroyedOAM_Frame0[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, 0x3188,
    0xfc, OBJ_SIZE_16x16 | 0x1f5, 0x3188
};

static const u16 sParticleShinesparkDestroyedOAM_Frame1[13] = {
    0x4,
    0xed, OBJ_SIZE_16x16 | 0x1f1, 0x3188,
    0xf9, OBJ_SIZE_16x16 | 0x4, 0x3188,
    0x0, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

static const u16 sParticleShinesparkDestroyedOAM_Frame2[19] = {
    0x6,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, 0x3188,
    0xfb, OBJ_SIZE_16x16 | 0xe, 0x3188,
    0xc, OBJ_SIZE_16x16 | 0x1ed, 0x3188,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x3188,
    0xf9, OBJ_SIZE_16x16 | 0x1, 0x3188,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

static const u16 sParticleShinesparkDestroyedOAM_Frame3[28] = {
    0x9,
    0xe1, OBJ_SIZE_16x16 | 0x1e8, 0x3188,
    0xfc, OBJ_SIZE_16x16 | 0x16, 0x3188,
    0x15, OBJ_SIZE_16x16 | 0x1e9, 0x3188,
    0xe9, OBJ_SIZE_16x16 | 0x1ee, 0x3188,
    0xfa, OBJ_SIZE_16x16 | 0x9, 0x3188,
    0xb, OBJ_SIZE_16x16 | 0x1ee, 0x3188,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f4, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x318c,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f4, 0x318c
};

static const u16 sParticleShinesparkDestroyedOAM_Frame4[31] = {
    0xa,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3188,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1a, 0x3188,
    0x17, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e7, 0x3188,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, 0x318a,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x318a,
    0xe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, 0x318a,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x318e,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x318e,
    0x6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x318e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196
};

static const u16 sParticleShinesparkDestroyedOAM_Frame5[31] = {
    0xa,
    0xdd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e4, 0x318a,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1c, 0x318a,
    0x19, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e5, 0x318a,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x318e,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x318e,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, 0x318e,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x41d4,
    0xfa, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, 0x41d4,
    0x8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x41d4,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

static const u16 sParticleShinesparkDestroyedOAM_Frame6[22] = {
    0x7,
    0xdc, OBJ_SIZE_16x16 | 0x1e3, 0x3196,
    0xfd, OBJ_SIZE_16x16 | 0x1c, 0x3196,
    0x1a, OBJ_SIZE_16x16 | 0x1e4, 0x3196,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x41d4,
    0xfb, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xe, 0x41d4,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, 0x41d4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

static const u16 sParticleShinesparkDestroyedOAM_Frame7[19] = {
    0x6,
    0xdb, OBJ_SIZE_16x16 | 0x1e2, 0x418a,
    0xfd, OBJ_SIZE_16x16 | 0x1d, 0x418a,
    0x1b, OBJ_SIZE_16x16 | 0x1e3, 0x418a,
    0xf6, 0x1f6, 0x41a7,
    0x5, 0x1fc, 0x41a7,
    0xf9, OBJ_X_FLIP | 0x5, 0x41a7
};

static const u16 sParticleShinesparkDestroyedOAM_Frame8[10] = {
    0x3,
    0xda, OBJ_SIZE_16x16 | 0x1e1, 0x418c,
    0xfd, OBJ_SIZE_16x16 | 0x1e, 0x418c,
    0x1c, OBJ_SIZE_16x16 | 0x1e2, 0x418c
};

static const u16 sParticleShinesparkDestroyedOAM_Frame9[10] = {
    0x3,
    0xd9, OBJ_SIZE_16x16 | 0x1e0, 0x418e,
    0xfd, OBJ_SIZE_16x16 | 0x1f, 0x418e,
    0x1d, OBJ_SIZE_16x16 | 0x1e1, 0x418e
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x3188
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame1[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1eb, 0x3188,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame2[28] = {
    0x9,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1df, 0x3188,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x11, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1ed, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x3, 0x318a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame3[25] = {
    0x8,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1da, 0x318a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, 0x318a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x318c,
    0xf8, OBJ_SIZE_16x16 | 0x8, 0x318c,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame4[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1d8, 0x3196,
    0xf8, OBJ_SIZE_16x16 | 0x18, 0x3196,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3157,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x3157,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3157,
    0xf8, OBJ_SIZE_16x16 | 0x1e8, 0x418e,
    0xf8, OBJ_SIZE_16x16 | 0x8, 0x418e
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame5[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1d6, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1a, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame6[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1d4, 0x418c,
    0xf8, OBJ_SIZE_16x16 | 0x1c, 0x418c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

static const u16 sParticleSudoScrewDestroyedOAM_Frame7[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1d2, 0x418e,
    0xf8, OBJ_SIZE_16x16 | 0x1e, 0x418e,
    0x2, OBJ_Y_FLIP | 0x1f6, 0x41a7,
    0xf6, OBJ_Y_FLIP | 0x1fc, 0x41a7,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x41a7
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame0[13] = {
    0x4,
    0xfc, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf4, OBJ_SIZE_16x16 | 0x1fd, 0x3188,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3188,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3188
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame1[28] = {
    0x9,
    0x0, OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x3188,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3188,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame2[40] = {
    0xd,
    0x6, OBJ_SIZE_16x16 | 0x1ea, 0x3188,
    0xea, OBJ_SIZE_16x16 | 0x6, 0x3188,
    0x2, OBJ_SIZE_16x16 | 0x1ee, 0x318a,
    0xee, OBJ_SIZE_16x16 | 0x2, 0x318a,
    0x6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, 0x3188,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x3188,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x318a,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, 0x318a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame3[37] = {
    0xc,
    0x8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x318a,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x318c,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x318c,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x318a,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x318c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x318c,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame4[37] = {
    0xc,
    0xa, OBJ_SIZE_16x16 | 0x1e6, 0x3196,
    0xe6, OBJ_SIZE_16x16 | 0xa, 0x3196,
    0x2, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xee, OBJ_SIZE_16x16 | 0x2, 0x418e,
    0xa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, 0x3196,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3196,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x418e,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3157,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x3157,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3157
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame5[16] = {
    0x5,
    0xb, OBJ_SIZE_16x16 | 0x1e5, 0x418a,
    0xe5, OBJ_SIZE_16x16 | 0xb, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, 0x418a,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e5, 0x418a
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame6[16] = {
    0x5,
    0xc, OBJ_SIZE_16x16 | 0x1e4, 0x418c,
    0xe4, OBJ_SIZE_16x16 | 0xc, 0x418c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198,
    0xc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, 0x418c,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e4, 0x418c
};

static const u16 sParticleSpeedboosterDestroyedOAM_Frame7[22] = {
    0x7,
    0xd, OBJ_SIZE_16x16 | 0x1e3, 0x418e,
    0xe3, OBJ_SIZE_16x16 | 0xd, 0x418e,
    0x2, OBJ_Y_FLIP | 0x1f6, 0x41a7,
    0xf6, OBJ_Y_FLIP | 0x1fc, 0x41a7,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x41a7,
    0xd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x418e,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e3, 0x418e
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame1[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame2[4] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x718a
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame3[7] = {
    0x2,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame4[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame5[7] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x0, 0x718a
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame6[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x1f2, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame7[10] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x0, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x7188
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame8[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x0, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x1f2, 0x718a
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame9[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x718a
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame10[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x7187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x718c
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame11[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x4, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, 0x718e
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame12[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x4, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, 0x71d4
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame13[4] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x71d4
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame14[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f6, 0x7187
};

static const u16 sParticleFreezingSpriteWithIceOAM_Frame15[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f6, 0x7187
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame0[13] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x7155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x7155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x7155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x7155
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame1[13] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x7155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x7155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x7155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x7155
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x7155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x7155
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame3[28] = {
    0x9,
    0xeb, OBJ_SIZE_16x16 | 0x1eb, 0x7155,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, 0x7155,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1eb, 0x7155,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, 0x7155,
    0xea, OBJ_SIZE_16x16 | 0x1f6, 0x7155,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, 0x7155,
    0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x7155,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x7155,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, 0x7188
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x7155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x7155
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame5[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x7188,
    0x0, OBJ_SIZE_16x16 | 0x1f9, 0x7188
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame6[13] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x3, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7188,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x7188
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame7[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fa, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x3, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x1f0, 0x718a,
    0xfe, OBJ_SIZE_16x16 | 0x1f9, 0x718a
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame8[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fa, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x718a,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x718a
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame9[10] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x718c,
    0xfc, OBJ_SIZE_16x16 | 0x1f9, 0x718c
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame10[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x7, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, 0x718e,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x718e
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame11[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x7, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x71d4
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame12[4] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x71d4
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame13[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f4, 0x7187,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x1fd, 0x7187
};

static const u16 sParticleFreezingSpritewithChargedIceBeamOAM_Frame14[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f4, 0x7187
};

static const u16 sParticleMainBossDeathOAM_Frame2[19] = {
    0x6,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x10, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, 0x30d2
};

static const u16 sParticleMainBossDeathOAM_Frame3[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x30d3
};

static const u16 sParticleMainBossDeathOAM_Frame4[31] = {
    0xa,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x310b,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, 0x310b,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x310b,
    OBJ_SHAPE_VERTICAL | 0x4, 0x1f6, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | 0x1ee, 0x30d2
};

static const u16 sParticleMainBossDeathOAM_Frame5[49] = {
    0x10,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x310d,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, 0x310d,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x310d,
    0x4, OBJ_SIZE_16x16 | 0x1ee, 0x30d3,
    0x0, OBJ_SIZE_16x16 | 0x8, 0x3188,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x1f4, 0x30d2
};

static const u16 sParticleMainBossDeathOAM_Frame6[53] = {
    0x11,
    0xf8, OBJ_SIZE_16x16 | 0x1e8, 0x3188,
    0xee, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1fc, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x1fc, 0x319a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x4, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x14, 0x319a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xf, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x9, 0x30d2,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x310b,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310b,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x310b,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, 0x3188,
    0xe0, OBJ_SIZE_16x16 | 0x1f4, 0x30d3
};

static const u16 sParticleMainBossDeathOAM_Frame7[55] = {
    0x12,
    0xe8, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xf7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x319c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, 0x319c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x3188,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x310d,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310d,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x310d,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310d,
    0xfe, OBJ_SIZE_16x16 | 0x8, 0x318a,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x310b,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310b,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x310b,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310b
};

static const u16 sParticleMainBossDeathOAM_Frame8[64] = {
    0x15,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x310d,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310d,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x310d,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310d,
    0xe5, OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x319e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, 0x319e,
    0xf6, OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x310f,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310f,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x310f,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x310f,
    0xf9, OBJ_SIZE_16x16 | 0x5, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x14, 0x3155,
    0x8, OBJ_Y_FLIP | 0x5, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_Y_FLIP | 0xd, 0x3155
};

static const u16 sParticleMainBossDeathOAM_Frame9[61] = {
    0x14,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x310f,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310f,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x310f,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x310f,
    0xe3, OBJ_SIZE_16x16 | 0x1f2, 0x3196,
    0xdd, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xda, 0x1f7, 0x30d6,
    0xd4, OBJ_Y_FLIP | 0x1fd, 0x30d6,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xef, OBJ_SIZE_16x16 | 0x0, 0x3196,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3196,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x318a,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x3111,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3111,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3111,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3111,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, 0x3155
};

static const u16 sParticleMainBossDeathOAM_Frame10[58] = {
    0x13,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x3111,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3111,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x3111,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3111,
    0xdc, OBJ_SIZE_16x16 | 0x1f4, 0x3196,
    0xd8, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xd4, OBJ_Y_FLIP | 0x1f7, 0x30d6,
    0xcf, 0x1fe, 0x30d6,
    0xea, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x3198,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3198,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x3113,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3113,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3113,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3113,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xf, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xe, 0x3155
};

static const u16 sParticleMainBossDeathOAM_Frame11[55] = {
    0x12,
    0xe9, 0x1f4, 0x30d6,
    0xe6, OBJ_Y_FLIP | 0x2, 0x30d6,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x3198,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3198,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3198,
    0xd4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x31a7,
    0xcc, OBJ_Y_FLIP | 0x1, 0x31a7,
    0xf2, OBJ_SIZE_16x16 | 0x1e8, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1e8, 0x4188,
    0xec, OBJ_SIZE_16x16 | 0x2, 0x31d4,
    0xe7, OBJ_SIZE_16x16 | 0x2, 0x418a,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xf, 0x318a,
    0xf4, OBJ_SIZE_16x16 | 0x1fc, 0x3188,
    0xfc, OBJ_SIZE_16x16 | 0x5, 0x3188,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x3113,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3113,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x3113,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3113
};

static const u16 sParticleMainBossDeathOAM_Frame12[37] = {
    0xc,
    0xd9, 0x1f8, 0x31a7,
    0xf3, 0x1fd, 0x30d6,
    0xdc, 0x2, 0x30d6,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1e8, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0xa, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x6, 0x41d4,
    0xec, OBJ_SIZE_16x16 | 0xf, 0x31d4,
    0xe7, OBJ_SIZE_16x16 | 0xf, 0x418a,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x318a,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x5, 0x318a
};

static const u16 sParticleMainBossDeathOAM_Frame13[37] = {
    0xc,
    0xd5, 0x1f8, 0x31a7,
    0xd4, 0x4, 0x31a7,
    0xd7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x31a7,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1e8, 0x418c,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x13, 0x3187,
    0xe5, OBJ_SIZE_16x16 | 0xf, 0x418e,
    0xee, OBJ_SIZE_16x16 | 0x1fc, 0x318e,
    0xe8, OBJ_SIZE_16x16 | 0x1fc, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x5, 0x318e,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x4188
};

static const u16 sParticleMainBossDeathOAM_Frame14[31] = {
    0xa,
    0xd6, OBJ_Y_FLIP | 0x1fc, 0x31a7,
    0xda, 0x0, 0x31a7,
    0xe9, OBJ_X_FLIP | 0x1fc, 0x31a7,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1ec, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1e8, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x13, 0x4187,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x31d4,
    0xe5, OBJ_SIZE_16x16 | 0x1fc, 0x418c,
    0xf2, OBJ_X_FLIP | 0xd, 0x418f,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x418f
};

static const u16 sParticleMainBossDeathOAM_Frame15[19] = {
    0x6,
    0xd1, 0x1fc, 0x31a7,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1ec, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1e8, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1ff, 0x3187,
    0xe2, OBJ_SIZE_16x16 | 0x1fb, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x8, 0x3187
};

static const u16 sParticleMainBossDeathOAM_Frame16[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1ec, 0x4187,
    0xdd, OBJ_SIZE_16x16 | 0x1fc, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_X_FLIP | 0x0, 0x3187
};

static const u16 sWaterDropOAM_Spawning_Frame0[4] = {
    0x1,
    0xfe, 0x1fc, 0x2161
};

static const u16 sWaterDropOAM_Spawning_Frame1[4] = {
    0x1,
    0xff, 0x1fc, 0x2161
};

static const u16 sWaterDropOAM_Spawning_Frame2[4] = {
    0x1,
    0x0, 0x1fc, 0x2161
};

static const u16 sWaterDropOAM_Spawning_Frame3[4] = {
    0x1,
    0x0, 0x1fc, 0x2162
};

static const u16 sWaterDropOAM_Falling_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x2160
};

static const u16 sWaterDropOAM_Splashing_Frame0[7] = {
    0x2,
    0xf8, 0x1fe, 0x409d,
    0xf8, 0x1fa, 0x409d
};

static const u16 sWaterDropOAM_Splashing_Frame1[7] = {
    0x2,
    0xf8, 0x1fe, 0x409e,
    0xf8, 0x1fa, 0x409e
};

static const u16 sWaterDropOAM_Splashing_Frame2[7] = {
    0x2,
    0xf8, 0x1fe, 0x409f,
    0xf8, 0x1fa, 0x409f
};

static const u16 sWaterDropOAM_Splashing_Frame3[7] = {
    0x2,
    0xf8, 0x1fe, 0x40bd,
    0xf8, 0x1fa, 0x40bd
};

static const u16 sWaterDropOAM_Splashing_Frame4[7] = {
    0x2,
    0xf8, 0x1fe, 0x40be,
    0xf8, 0x1fa, 0x40be
};

static const u16 sSpriteDebrisOAM_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x3170
};

static const u16 sSpriteDebrisOAM_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x316f
};

static const u16 sSpriteDebrisOAM_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x316e
};

static const u16 sSpriteDebrisOAM_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x316d
};

static const u16 sParticleHittingSomethingWithPlasmaBeamOAM_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, 0x2192,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1ec, 0x2192,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x4, 0x2192,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, 0x2192
};

static const u16 sSpriteDebrisOAM_Unused_Frame4[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2143,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2143,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x2143,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2143
};

static const u16 sSpriteDebrisOAM_Unused_Frame5[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1e8, 0x2151,
    0xea, OBJ_SIZE_16x16 | 0x1ea, 0x2192,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, 0x2153,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, 0x2192,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x2151,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x2192,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x2153,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x6, 0x2192
};

static const struct FrameData sParticleHittingSomethingWithNormalBeamOAM[5] = {
    sParticleHittingSomethingWithNormalBeamOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame2,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame3,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithLongBeamOAM[5] = {
    sParticleHittingSomethingWithNormalBeamOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithLongBeamOAM_Frame2,
    0x2,
    sParticleHittingSomethingWithLongBeamOAM_Frame3,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithIceBeamOAM[6] = {
    sParticleHittingSomethingWithNormalBeamOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithLongBeamOAM_Frame2,
    0x1,
    sParticleHittingSomethingWithIceBeamOAM_Frame3,
    0x2,
    sParticleHittingSomethingWithIceBeamOAM_Frame4,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithWaveBeamOAM[7] = {
    sParticleHittingSomethingWithNormalBeamOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithLongBeamOAM_Frame2,
    0x1,
    sParticleHittingSomethingWithIceBeamOAM_Frame3,
    0x1,
    sParticleHittingSomethingWithWaveBeamOAM_Frame4,
    0x2,
    sParticleHittingSomethingWithWaveBeamOAM_Frame5,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithPlasmaBeamOAM[8] = {
    sParticleHittingSomethingWithNormalBeamOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithNormalBeamOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithLongBeamOAM_Frame2,
    0x1,
    sParticleHittingSomethingWithIceBeamOAM_Frame3,
    0x1,
    sParticleHittingSomethingWithWaveBeamOAM_Frame4,
    0x1,
    sParticleHittingSomethingWithPlasmaBeamOAM_Frame5,
    0x2,
    sParticleHittingSomethingWithPlasmaBeamOAM_Frame6,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingInvincibleOAM[6] = {
    sParticleHittingSomethingInvincible_Frame0,
    0x1,
    sParticleHittingSomethingInvincible_Frame1,
    0x1,
    sParticleHittingSomethingInvincible_Frame2,
    0x1,
    sParticleHittingSomethingInvincible_Frame3,
    0x2,
    sParticleHittingSomethingInvincible_Frame4,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithMissileOAM[8] = {
    sParticleHittingSomethingWithMissileOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame2,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame3,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame4,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame5,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame6,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleHittingSomethingWithSuperMissileOAM[8] = {
    sParticleHittingSomethingWithMissileOAM_Frame0,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame1,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame2,
    0x2,
    sParticleHittingSomethingWithMissileOAM_Frame3,
    0x2,
    sParticleHittingSomethingWithSuperMissileOAM_Frame4,
    0x3,
    sParticleHittingSomethingWithSuperMissileOAM_Frame5,
    0x3,
    sParticleHittingSomethingWithSuperMissileOAM_Frame6,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sParticleSpriteExplosionHugeOAM[14] = {
    sParticleSpriteExplosionHugeOAM_Frame0,
    0x1,
    sParticleSpriteExplosionHugeOAM_Frame1,
    0x2,
    sParticleSpriteExplosionHugeOAM_Frame2,
    0x2,
    sParticleSpriteExplosionHugeOAM_Frame0,
    0x1,
    sParticleSpriteExplosionHugeOAM_Frame4,
    0x2,
    sParticleSpriteExplosionHugeOAM_Frame5,
    0x2,
    sParticleSpriteExplosionHugeOAM_Frame6,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame7,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame8,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame9,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame10,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame11,
    0x3,
    sParticleSpriteExplosionHugeOAM_Frame12,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParticleSmallDustOAM[7] = {
    sParticleSmallDustOAM_Frame0,
    0x4,
    sParticleSmallDustOAM_Frame1,
    0x4,
    sParticleSmallDustOAM_Frame2,
    0x4,
    sParticleSmallDustOAM_Frame3,
    0x4,
    sParticleSmallDustOAM_Frame4,
    0x4,
    sParticleSmallDustOAM_Frame5,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParticleMediumDustOAM[10] = {
    sParticleMediumDustOAM_Frame0,
    0x3,
    sParticleMediumDustOAM_Frame1,
    0x3,
    sParticleMediumDustOAM_Frame2,
    0x3,
    sParticleMediumDustOAM_Frame3,
    0x3,
    sParticleMediumDustOAM_Frame4,
    0x3,
    sParticleMediumDustOAM_Frame5,
    0x3,
    sParticleMediumDustOAM_Frame6,
    0x3,
    sParticleMediumDustOAM_Frame7,
    0x3,
    sParticleMediumDustOAM_Frame8,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sParticleTwoMediumDustOAM[11] = {
    sParticleTwoMediumDustOAM_Frame0,
    0x4,
    sParticleTwoMediumDustOAM_Frame1,
    0x4,
    sParticleTwoMediumDustOAM_Frame2,
    0x4,
    sParticleTwoMediumDustOAM_Frame3,
    0x4,
    sParticleTwoMediumDustOAM_Frame4,
    0x4,
    sParticleTwoMediumDustOAM_Frame5,
    0x4,
    sParticleTwoMediumDustOAM_Frame6,
    0x4,
    sParticleTwoMediumDustOAM_Frame7,
    0x4,
    sParticleTwoMediumDustOAM_Frame8,
    0x4,
    sParticleTwoMediumDustOAM_Frame9,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParticleSpriteExplosionSmallOAM[12] = {
    sParticleSpriteExplosionSmallOAM_Frame0,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame1,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame2,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame3,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame4,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame5,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame6,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame7,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame8,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame9,
    0x2,
    sParticleSpriteExplosionSmallOAM_Frame10,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleSpriteExplosionMediumOAM[18] = {
    sParticleSpriteExplosionSmallOAM_Frame0,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame1,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame2,
    0x1,
    sParticleSpriteExplosionMediumOAM_Frame3,
    0x1,
    sParticleSpriteExplosionMediumOAM_Frame4,
    0x1,
    sParticleSpriteExplosionMediumOAM_Frame5,
    0x1,
    sParticleSpriteExplosionMediumOAM_Frame6,
    0x1,
    sParticleSpriteExplosionMediumOAM_Frame7,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame8,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame9,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame10,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame11,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame12,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame13,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame14,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame15,
    0x2,
    sParticleSpriteExplosionMediumOAM_Frame16,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleSpriteExplosionBigOAM[18] = {
    sParticleSpriteExplosionSmallOAM_Frame0,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame1,
    0x1,
    sParticleSpriteExplosionSmallOAM_Frame2,
    0x1,
    sParticleSpriteExplosionHugeOAM_Frame0,
    0x1,
    sParticleSpriteExplosionHugeOAM_Frame1,
    0x2,
    sParticleSpriteExplosionHugeOAM_Frame2,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame6,
    0x1,
    sParticleSpriteExplosionBigOAM_Frame7,
    0x1,
    sParticleSpriteExplosionBigOAM_Frame8,
    0x1,
    sParticleSpriteExplosionBigOAM_Frame9,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame10,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame11,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame12,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame13,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame14,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame15,
    0x2,
    sParticleSpriteExplosionBigOAM_Frame16,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParticleSpriteExplosionSingleThenBigOAM[17] = {

};

#endif