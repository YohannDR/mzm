#include "data/particle_data.h"
#include "macros.h"

const u16 sParticleShootingBeamHorizontalOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamHorizontalOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfb, 0x1ff, 0x2182,
    0xf7, 0x1f9, 0x2182,
    0x1, 0x1f9, 0x2182
};

const u16 sParticleShootingBeamHorizontalOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

const u16 sParticleShootingBeamHorizontalOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x2182,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x2182
};

const u16 sParticleShootingBeamDiagonallyUpOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamDiagonallyUpOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0x1, 0x1ff, 0x2182,
    0xf7, 0x1fe, 0x2182,
    0xfe, 0x1f6, 0x2182
};

const u16 sParticleShootingBeamDiagonallyUpOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

const u16 sParticleShootingBeamDiagonallyUpOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1, 0x2182,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, 0x2182
};

const u16 sParticleShootingBeamDiagonallyDownOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamDiagonallyDownOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfb, 0x1ff, 0x2182,
    0xf9, 0x1f8, 0x2182,
    0x1, 0x0, 0x2182
};

const u16 sParticleShootingBeamDiagonallyDownOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1fa, 0x2180
};

const u16 sParticleShootingBeamDiagonallyDownOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fa, 0x2182,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x2182
};

const u16 sParticleShootingBeamUpOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamUpOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0x0, 0x1fc, 0x2182,
    0xf9, 0x0, 0x2182,
    0xf9, 0x1f6, 0x2182
};

const u16 sParticleShootingBeamUpOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamUpOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, 0x2182,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x2182
};

const u16 sParticleShootingBeamDownOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamDownOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_Y_FLIP | 0x1fc, 0x2182,
    0xff, OBJ_Y_FLIP | 0x0, 0x2182,
    0xff, OBJ_Y_FLIP | 0x1f6, 0x2182
};

const u16 sParticleShootingBeamDownOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x2180
};

const u16 sParticleShootingBeamDownOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x3, 0x2182,
    0xf8, OBJ_X_FLIP | 0x1f6, 0x2182
};

const u16 sParticleBombOam_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f8, 0x3141,
    0xf8, OBJ_X_FLIP | 0x0, 0x3141,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x3141,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3141
};

const u16 sParticleBombOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f8, 0x3142,
    0xf8, OBJ_X_FLIP | 0x0, 0x3142,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x3142,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3142
};

const u16 sParticleBombOam_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3100,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3100,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3100,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3100
};

const u16 sParticleBombOam_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3102,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3102,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3102,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3102
};

const u16 sParticleBombOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3104,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3104,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3104,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3104
};

const u16 sParticleBombOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3106,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3106,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3106,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3106
};

const u16 sParticleBeamTrailingOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20d7
};

const u16 sParticleBeamTrailingOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20d9
};

const u16 sParticleBeamTrailingOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20db
};

const u16 sParticleBeamTrailingOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20fb
};

const u16 sParticleBeamTrailingOam_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21a2
};

const u16 sParticleChargingBeamBeginOAM_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2097
};

const u16 sParticleChargingBeamBeginOAM_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2095
};

const u16 sParticleChargingBeamBeginOAM_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x2166
};

const u16 sParticleChargingBeamBeginOAM_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21c8
};

const u16 sParticleChargingBeamBeginOAM_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2095,
    0xfc, 0x1fc, 0x2090
};

const u16 sParticleChargingBeamBeginOAM_Frame10[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2097,
    0xfc, 0x1fc, 0x20b0
};

const u16 sParticleChargingBeamBeginOAM_Frame16[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2099,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2099,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x2099,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2099,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2091
};

const u16 sParticleChargingBeamChargedOAM_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x209b,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x209b,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x209b,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x209b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2093
};

const struct FrameData sParticleShootingBeamHorizontalOam[5] = {
    [0] = {
        .pFrame = sParticleShootingBeamHorizontalOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShootingBeamHorizontalOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShootingBeamHorizontalOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleShootingBeamHorizontalOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleShootingBeamDiagonallyUpOam[5] = {
    [0] = {
        .pFrame = sParticleShootingBeamDiagonallyUpOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShootingBeamDiagonallyUpOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShootingBeamDiagonallyUpOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleShootingBeamDiagonallyUpOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleShootingBeamDiagonallyDownOam[5] = {
    [0] = {
        .pFrame = sParticleShootingBeamDiagonallyDownOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShootingBeamDiagonallyDownOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShootingBeamDiagonallyDownOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleShootingBeamDiagonallyDownOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleShootingBeamUpOam[5] = {
    [0] = {
        .pFrame = sParticleShootingBeamUpOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShootingBeamUpOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShootingBeamUpOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleShootingBeamUpOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleShootingBeamDownOam[5] = {
    [0] = {
        .pFrame = sParticleShootingBeamDownOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShootingBeamDownOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShootingBeamDownOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleShootingBeamDownOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleBombOam[7] = {
    [0] = {
        .pFrame = sParticleBombOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleBombOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleBombOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleBombOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleBombOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleBombOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleBeamTrailingOam[6] = {
    [0] = {
        .pFrame = sParticleBeamTrailingOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleBeamTrailingOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleBeamTrailingOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleBeamTrailingOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleBeamTrailingOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargingBeamBeginOAM[23] = {
    [0] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [13] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [14] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [15] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [16] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [17] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [18] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [19] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [20] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [21] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [22] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargingBeamChargedOAM[3] = {
    [0] = {
        .pFrame = sParticleChargingBeamBeginOAM_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleChargingBeamChargedOAM_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const u16 sParticleHittingSomethingWithNormalBeamOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21c8
};

const u16 sParticleHittingSomethingWithNormalBeamOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21e8
};

const u16 sParticleHittingSomethingWithNormalBeamOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21c9
};

const u16 sParticleHittingSomethingWithNormalBeamOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x21e9
};

const u16 sParticleHittingSomethingWithLongBeamOam_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x2108,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x2108
};

const u16 sParticleHittingSomethingWithLongBeamOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x2109,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x2109
};

const u16 sParticleHittingSomethingWithIceBeamOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, 0x210a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x0, 0x210a
};

const u16 sParticleHittingSomethingWithIceBeamOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, 0x2145,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x2145,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_Y_FLIP | 0x1f4, 0x2145,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2145
};

const u16 sParticleHittingSomethingWithWaveBeamOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2143,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x2143,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x2143,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2143
};

const u16 sParticleHittingSomethingWithWaveBeamOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2149,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2149,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x2149,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2149
};

const u16 sParticleHittingSomethingWithPlasmaBeamOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x2147,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x2147
};

const u16 sParticleHittingSomethingInvincible_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x2115
};

const u16 sParticleHittingSomethingInvincible_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x2135
};

const u16 sParticleHittingSomethingInvincible_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2116
};

const u16 sParticleHittingSomethingInvincible_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2118
};

const u16 sParticleHittingSomethingInvincible_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x211a
};

const u16 sParticleHittingSomethingWithMissileOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x0, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f8, 0x30d2
};

const u16 sParticleHittingSomethingWithMissileOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x30d3
};

const u16 sParticleHittingSomethingWithMissileOam_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b
};

const u16 sParticleHittingSomethingWithMissileOam_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d
};

const u16 sParticleHittingSomethingWithMissileOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310f,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310f
};

const u16 sParticleHittingSomethingWithMissileOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3111,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3111
};

const u16 sParticleHittingSomethingWithMissileOam_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3113,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3113,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3113,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3113
};

const u16 sParticleHittingSomethingWithSuperMissileOam_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_16x32 | 0x1ec, 0x319a,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, 0x31ca,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x4, 0x319a,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1ff, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f9, 0x30d2
};

const u16 sParticleHittingSomethingWithSuperMissileOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1e8, 0x319c,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f8, 0x31ce,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x319c
};

const u16 sParticleHittingSomethingWithSuperMissileOam_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1e8, 0x319e,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f8, 0x31d6,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x319e
};

const u16 sParticleSpriteExplosionHugeOam_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155
};

const u16 sParticleSpriteExplosionHugeOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x3155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3155
};

const u16 sParticleSpriteExplosionHugeOam_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x3155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x3155
};

const u16 sParticleSpriteExplosionHugeOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3157,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, 0x3157,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, 0x3157,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3157
};

const u16 sParticleSpriteExplosionHugeOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf1, OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x3157,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3157
};

const u16 sParticleSpriteExplosionHugeOam_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xef, OBJ_SIZE_16x16 | 0x1f2, 0x3196,
    0xe9, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xe6, 0x1f7, 0x30d6,
    0xe0, OBJ_Y_FLIP | 0x1fd, 0x30d6,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xfb, OBJ_SIZE_16x16 | 0x0, 0x3196,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3196
};

const u16 sParticleSpriteExplosionHugeOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, 0x3196,
    0xe0, OBJ_SIZE_16x16 | 0x1fe, 0x3196,
    0xdc, OBJ_Y_FLIP | 0x1f7, 0x30d6,
    0xd7, 0x1fe, 0x30d6,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, 0x3198,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3198
};

const u16 sParticleSpriteExplosionHugeOam_Frame8[OAM_DATA_SIZE(7)] = {
    0x7,
    0xed, 0x1f4, 0x30d6,
    0xea, OBJ_Y_FLIP | 0x2, 0x30d6,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x3198,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3198,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3198,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x31a7,
    0xd0, OBJ_Y_FLIP | 0x1, 0x31a7
};

const u16 sParticleSpriteExplosionHugeOam_Frame9[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd9, 0x1f8, 0x31a7,
    0xf3, 0x1fd, 0x30d6,
    0xdc, 0x2, 0x30d6,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198
};

const u16 sParticleSpriteExplosionHugeOam_Frame10[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd5, 0x1f8, 0x31a7,
    0xd4, 0x4, 0x31a7,
    0xd7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3198,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x31a7
};

const u16 sParticleSpriteExplosionHugeOam_Frame11[OAM_DATA_SIZE(3)] = {
    0x3,
    0xd6, OBJ_Y_FLIP | 0x1fc, 0x31a7,
    0xda, 0x0, 0x31a7,
    0xe9, OBJ_X_FLIP | 0x1fc, 0x31a7
};

const u16 sParticleSpriteExplosionHugeOam_Frame12[OAM_DATA_SIZE(1)] = {
    0x1,
    0xd1, 0x1fc, 0x31a7
};

const u16 sParticleSmallDustOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188
};

const u16 sParticleSmallDustOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418a
};

const u16 sParticleSmallDustOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418c
};

const u16 sParticleSmallDustOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x418e
};

const u16 sParticleSmallDustOam_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

const u16 sParticleSmallDustOam_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4187
};

const u16 sParticleMediumDustOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f3, 0x4188
};

const u16 sParticleMediumDustOam_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x4188,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, 0x4188
};

const u16 sParticleMediumDustOam_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fb, 0x418a,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x4188,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, 0x4188
};

const u16 sParticleMediumDustOam_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1fc, 0x418c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, 0x418a,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x6, 0x4188
};

const u16 sParticleMediumDustOam_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x418e,
    0xec, OBJ_SIZE_16x16 | 0x1ed, 0x418c,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x418a
};

const u16 sParticleMediumDustOam_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xef, OBJ_SIZE_16x16 | 0x8, 0x418c,
    0xed, OBJ_SIZE_16x16 | 0x1fd, 0x41d4
};

const u16 sParticleMediumDustOam_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x6, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fd, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, 0x41d4
};

const u16 sParticleMediumDustOam_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1f6, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x5, 0x41d4
};

const u16 sParticleMediumDustOam_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x4, 0x4187
};

const u16 sParticleTwoMediumDustOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x418a
};

const u16 sParticleTwoMediumDustOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    0xec, OBJ_SIZE_16x16 | 0x1ec, 0x4188,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, 0x418a
};

const u16 sParticleTwoMediumDustOam_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xea, OBJ_SIZE_16x16 | 0x1ea, 0x418a,
    0xf1, OBJ_SIZE_16x16 | 0x2, 0x4188
};

const u16 sParticleTwoMediumDustOam_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xe4, OBJ_SIZE_16x16 | 0x1eb, 0x418c,
    0xec, OBJ_SIZE_16x16 | 0x4, 0x4188
};

const u16 sParticleTwoMediumDustOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe0, OBJ_SIZE_16x16 | 0x1ec, 0x418e,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x418a,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x4188,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

const u16 sParticleTwoMediumDustOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1, 0x418c,
    0xf0, OBJ_SIZE_16x16 | 0x1ee, 0x418a,
    0xda, OBJ_SIZE_16x16 | 0x1ed, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1fc, 0x4187
};

const u16 sParticleTwoMediumDustOam_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe7, OBJ_SIZE_16x16 | 0x0, 0x418e,
    0xeb, OBJ_SIZE_16x16 | 0x1ed, 0x418c,
    OBJ_SHAPE_VERTICAL | 0xd5, 0x1f1, 0x4187
};

const u16 sParticleTwoMediumDustOam_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xe4, OBJ_SIZE_16x16 | 0x1ff, 0x41d4
};

const u16 sParticleTwoMediumDustOam_Frame8[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x2, 0x4187,
    0xe2, OBJ_SIZE_16x16 | 0x1ef, 0x41d4
};

const u16 sParticleTwoMediumDustOam_Frame9[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f6, 0x4187
};

const u16 sParticleSpriteExplosionSmallOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3188
};

const u16 sParticleSpriteExplosionSmallOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3188
};

const u16 sParticleSpriteExplosionSmallOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x318a
};

const u16 sParticleSpriteExplosionSmallOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a
};

const u16 sParticleSpriteExplosionSmallOam_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x318c
};

const u16 sParticleSpriteExplosionSmallOam_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4188
};

const u16 sParticleSpriteExplosionSmallOam_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x418a
};

const u16 sParticleSpriteExplosionSmallOam_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418c
};

const u16 sParticleSpriteExplosionSmallOam_Frame8[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418e
};

const u16 sParticleSpriteExplosionSmallOam_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, 0x41d4
};

const u16 sParticleSpriteExplosionSmallOam_Frame10[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x4187
};

const u16 sParticleSpriteExplosionMediumOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x3188
};

const u16 sParticleSpriteExplosionMediumOam_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3188
};

const u16 sParticleSpriteExplosionMediumOam_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x0, 0x318a
};

const u16 sParticleSpriteExplosionMediumOam_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

const u16 sParticleSpriteExplosionMediumOam_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x0, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

const u16 sParticleSpriteExplosionMediumOam_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x0, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x0, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f2, 0x318a
};

const u16 sParticleSpriteExplosionMediumOam_Frame9[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x0, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x318a
};

const u16 sParticleSpriteExplosionMediumOam_Frame10[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x318c
};

const u16 sParticleSpriteExplosionMediumOam_Frame11[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xec, 0x4, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f2, 0x4188
};

const u16 sParticleSpriteExplosionMediumOam_Frame12[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x4, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x0, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f2, 0x418a
};

const u16 sParticleSpriteExplosionMediumOam_Frame13[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x4, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x418c
};

const u16 sParticleSpriteExplosionMediumOam_Frame14[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f6, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x418e
};

const u16 sParticleSpriteExplosionMediumOam_Frame15[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f6, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, 0x41d4
};

const u16 sParticleSpriteExplosionMediumOam_Frame16[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1f6, 0x4187
};

const u16 sParticleSpriteExplosionBigOam_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f6, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x318a,
    0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0x0, OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

const u16 sParticleSpriteExplosionBigOam_Frame7[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x3, 0x318c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3188,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

const u16 sParticleSpriteExplosionBigOam_Frame8[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fa, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x3, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x3, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f0, 0x318a,
    0xfe, OBJ_SIZE_16x16 | 0x1f9, 0x318a
};

const u16 sParticleSpriteExplosionBigOam_Frame9[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fa, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f6, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x418a,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x318a,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x318a
};

const u16 sParticleSpriteExplosionBigOam_Frame10[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fa, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x418c,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x318c,
    0xfc, OBJ_SIZE_16x16 | 0x1f9, 0x318c
};

const u16 sParticleSpriteExplosionBigOam_Frame11[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xec, 0x7, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x418e,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, 0x318e,
    0xec, OBJ_SIZE_16x16 | 0x1f0, 0x4188,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x318e,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x4188
};

const u16 sParticleSpriteExplosionBigOam_Frame12[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x7, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x3, 0x41d4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x31d4,
    0xeb, OBJ_SIZE_16x16 | 0x1f0, 0x418a,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x418c
};

const u16 sParticleSpriteExplosionBigOam_Frame13[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x7, 0x4187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x31d4,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x418c,
    0xf6, OBJ_X_FLIP | 0x1, 0x418f,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, 0x418f
};

const u16 sParticleSpriteExplosionBigOam_Frame14[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f4, 0x3187,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x1fd, 0x3187
};

const u16 sParticleSpriteExplosionBigOam_Frame15[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f4, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1f0, 0x41d4
};

const u16 sParticleSpriteExplosionBigOam_Frame16[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1f4, 0x4187
};

const u16 sParticleSpriteExplosionSingleThenBigOam_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x30d0
};

const u16 sParticleScrewAttackDestroyedOam_Frame1[OAM_DATA_SIZE(8)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame2[OAM_DATA_SIZE(12)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame3[OAM_DATA_SIZE(16)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame4[OAM_DATA_SIZE(16)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame5[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleScrewAttackDestroyedOam_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xd4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d4, 0x418e,
    0xd4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c, 0x418e,
    0x1c, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d4, 0x418e,
    0x1c, OBJ_SIZE_16x16 | 0x1c, 0x418e,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

const u16 sParticleScrewAttackDestroyedOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x41d4,
    0xd2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e, 0x41d4,
    0x1e, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x41d4,
    0x1e, OBJ_SIZE_16x16 | 0x1e, 0x41d4,
    0xf6, 0x1f6, 0x41a7,
    0x5, 0x1fc, 0x41a7,
    0xf9, OBJ_X_FLIP | 0x5, 0x41a7
};

const u16 sParticleShinesparkDestroyedOam_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, 0x3188,
    0xfc, OBJ_SIZE_16x16 | 0x1f5, 0x3188
};

const u16 sParticleShinesparkDestroyedOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xed, OBJ_SIZE_16x16 | 0x1f1, 0x3188,
    0xf9, OBJ_SIZE_16x16 | 0x4, 0x3188,
    0x0, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, 0x3188
};

const u16 sParticleShinesparkDestroyedOam_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, 0x3188,
    0xfb, OBJ_SIZE_16x16 | 0xe, 0x3188,
    0xc, OBJ_SIZE_16x16 | 0x1ed, 0x3188,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x3188,
    0xf9, OBJ_SIZE_16x16 | 0x1, 0x3188,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x3188
};

const u16 sParticleShinesparkDestroyedOam_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleShinesparkDestroyedOam_Frame4[OAM_DATA_SIZE(10)] = {
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

const u16 sParticleShinesparkDestroyedOam_Frame5[OAM_DATA_SIZE(10)] = {
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

const u16 sParticleShinesparkDestroyedOam_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xdc, OBJ_SIZE_16x16 | 0x1e3, 0x3196,
    0xfd, OBJ_SIZE_16x16 | 0x1c, 0x3196,
    0x1a, OBJ_SIZE_16x16 | 0x1e4, 0x3196,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x41d4,
    0xfb, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xe, 0x41d4,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, 0x41d4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

const u16 sParticleShinesparkDestroyedOam_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xdb, OBJ_SIZE_16x16 | 0x1e2, 0x418a,
    0xfd, OBJ_SIZE_16x16 | 0x1d, 0x418a,
    0x1b, OBJ_SIZE_16x16 | 0x1e3, 0x418a,
    0xf6, 0x1f6, 0x41a7,
    0x5, 0x1fc, 0x41a7,
    0xf9, OBJ_X_FLIP | 0x5, 0x41a7
};

const u16 sParticleShinesparkDestroyedOam_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    0xda, OBJ_SIZE_16x16 | 0x1e1, 0x418c,
    0xfd, OBJ_SIZE_16x16 | 0x1e, 0x418c,
    0x1c, OBJ_SIZE_16x16 | 0x1e2, 0x418c
};

const u16 sParticleShinesparkDestroyedOam_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    0xd9, OBJ_SIZE_16x16 | 0x1e0, 0x418e,
    0xfd, OBJ_SIZE_16x16 | 0x1f, 0x418e,
    0x1d, OBJ_SIZE_16x16 | 0x1e1, 0x418e
};

const u16 sParticleSudoScrewDestroyedOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x3188
};

const u16 sParticleSudoScrewDestroyedOam_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1eb, 0x3188,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, 0x3188,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x3155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x3155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x3155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x3155
};

const u16 sParticleSudoScrewDestroyedOam_Frame2[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleSudoScrewDestroyedOam_Frame3[OAM_DATA_SIZE(8)] = {
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

const u16 sParticleSudoScrewDestroyedOam_Frame4[OAM_DATA_SIZE(8)] = {
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

const u16 sParticleSudoScrewDestroyedOam_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1d6, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1a, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196
};

const u16 sParticleSudoScrewDestroyedOam_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1d4, 0x418c,
    0xf8, OBJ_SIZE_16x16 | 0x1c, 0x418c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198
};

const u16 sParticleSudoScrewDestroyedOam_Frame7[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1d2, 0x418e,
    0xf8, OBJ_SIZE_16x16 | 0x1e, 0x418e,
    0x2, OBJ_Y_FLIP | 0x1f6, 0x41a7,
    0xf6, OBJ_Y_FLIP | 0x1fc, 0x41a7,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x41a7
};

const u16 sParticleSpeedboosterDestroyedOam_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, OBJ_SIZE_16x16 | 0x1f3, 0x3188,
    0xf4, OBJ_SIZE_16x16 | 0x1fd, 0x3188,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x3188,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3188
};

const u16 sParticleSpeedboosterDestroyedOam_Frame1[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleSpeedboosterDestroyedOam_Frame2[OAM_DATA_SIZE(13)] = {
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

const u16 sParticleSpeedboosterDestroyedOam_Frame3[OAM_DATA_SIZE(12)] = {
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

const u16 sParticleSpeedboosterDestroyedOam_Frame4[OAM_DATA_SIZE(12)] = {
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

const u16 sParticleSpeedboosterDestroyedOam_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xb, OBJ_SIZE_16x16 | 0x1e5, 0x418a,
    0xe5, OBJ_SIZE_16x16 | 0xb, 0x418a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3196,
    0xb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, 0x418a,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e5, 0x418a
};

const u16 sParticleSpeedboosterDestroyedOam_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xc, OBJ_SIZE_16x16 | 0x1e4, 0x418c,
    0xe4, OBJ_SIZE_16x16 | 0xc, 0x418c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3198,
    0xc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, 0x418c,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e4, 0x418c
};

const u16 sParticleSpeedboosterDestroyedOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0xd, OBJ_SIZE_16x16 | 0x1e3, 0x418e,
    0xe3, OBJ_SIZE_16x16 | 0xd, 0x418e,
    0x2, OBJ_Y_FLIP | 0x1f6, 0x41a7,
    0xf6, OBJ_Y_FLIP | 0x1fc, 0x41a7,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x41a7,
    0xd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x418e,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e3, 0x418e
};

const u16 sParticleFreezingSpriteWithIceOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x718a
};

const u16 sParticleFreezingSpriteWithIceOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x0, 0x718a
};

const u16 sParticleFreezingSpriteWithIceOam_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x1f2, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x0, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x7188
};

const u16 sParticleFreezingSpriteWithIceOam_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x0, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x1f2, 0x718a
};

const u16 sParticleFreezingSpriteWithIceOam_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fc, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x718a
};

const u16 sParticleFreezingSpriteWithIceOam_Frame10[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, 0x7187,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x718c
};

const u16 sParticleFreezingSpriteWithIceOam_Frame11[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x4, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, 0x718e
};

const u16 sParticleFreezingSpriteWithIceOam_Frame12[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x4, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, 0x71d4
};

const u16 sParticleFreezingSpriteWithIceOam_Frame13[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x71d4
};

const u16 sParticleFreezingSpriteWithIceOam_Frame14[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f6, 0x7187
};

const u16 sParticleFreezingSpriteWithIceOam_Frame15[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f6, 0x7187
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x7155,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x7155,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x7155,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x7155
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1f3, 0x7155,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x7155,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x7155,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x7155
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x7155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x7155
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x7155,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x7155,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7155,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x7155
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x718a,
    0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x7188,
    0x0, OBJ_SIZE_16x16 | 0x1f9, 0x7188
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x3, 0x718c,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x7188,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x7188
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fa, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x3, 0x718e,
    0xf6, OBJ_SIZE_16x16 | 0x1f0, 0x718a,
    0xfe, OBJ_SIZE_16x16 | 0x1f9, 0x718a
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1fa, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x71d4,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x718a,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x718a
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x71d4,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x718c,
    0xfc, OBJ_SIZE_16x16 | 0x1f9, 0x718c
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame10[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xec, 0x7, 0x7187,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, 0x718e,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x718e
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame11[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x7, 0x7187,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x71d4
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame12[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x71d4
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame13[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f4, 0x7187,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x1fd, 0x7187
};

const u16 sParticleFreezingSpritewithChargedIceBeamOam_Frame14[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1f4, 0x7187
};

const u16 sParticleMainBossDeathOam_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310b,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x10, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, 0x30d2
};

const u16 sParticleMainBossDeathOam_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x310d,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x310d,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x30d3
};

const u16 sParticleMainBossDeathOam_Frame4[OAM_DATA_SIZE(10)] = {
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

const u16 sParticleMainBossDeathOam_Frame5[OAM_DATA_SIZE(16)] = {
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

const u16 sParticleMainBossDeathOam_Frame6[OAM_DATA_SIZE(17)] = {
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

const u16 sParticleMainBossDeathOam_Frame7[OAM_DATA_SIZE(18)] = {
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

const u16 sParticleMainBossDeathOam_Frame8[OAM_DATA_SIZE(21)] = {
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

const u16 sParticleMainBossDeathOam_Frame9[OAM_DATA_SIZE(20)] = {
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

const u16 sParticleMainBossDeathOam_Frame10[OAM_DATA_SIZE(19)] = {
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

const u16 sParticleMainBossDeathOam_Frame11[OAM_DATA_SIZE(18)] = {
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

const u16 sParticleMainBossDeathOam_Frame12[OAM_DATA_SIZE(12)] = {
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

const u16 sParticleMainBossDeathOam_Frame13[OAM_DATA_SIZE(12)] = {
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

const u16 sParticleMainBossDeathOam_Frame14[OAM_DATA_SIZE(10)] = {
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

const u16 sParticleMainBossDeathOam_Frame15[OAM_DATA_SIZE(6)] = {
    0x6,
    0xd1, 0x1fc, 0x31a7,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x1ec, 0x3187,
    0xe6, OBJ_SIZE_16x16 | 0x1e8, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1ff, 0x3187,
    0xe2, OBJ_SIZE_16x16 | 0x1fb, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x8, 0x3187
};

const u16 sParticleMainBossDeathOam_Frame16[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1ec, 0x4187,
    0xdd, OBJ_SIZE_16x16 | 0x1fc, 0x41d4,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_X_FLIP | 0x0, 0x3187
};

const u16 sWaterDropOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfe, 0x1fc, 0x2161
};

const u16 sWaterDropOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xff, 0x1fc, 0x2161
};

const u16 sWaterDropOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1fc, 0x2161
};

const u16 sWaterDropOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1fc, 0x2162
};

const u16 sWaterDropOam_Falling_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x2160
};

const u16 sWaterDropOam_Splashing_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fe, 0x409d,
    0xf8, 0x1fa, 0x409d
};

const u16 sWaterDropOam_Splashing_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fe, 0x409e,
    0xf8, 0x1fa, 0x409e
};

const u16 sWaterDropOam_Splashing_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fe, 0x409f,
    0xf8, 0x1fa, 0x409f
};

const u16 sWaterDropOam_Splashing_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fe, 0x40bd,
    0xf8, 0x1fa, 0x40bd
};

const u16 sWaterDropOam_Splashing_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fe, 0x40be,
    0xf8, 0x1fa, 0x40be
};

const u16 sSpriteDebrisOAM_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3170
};

const u16 sSpriteDebrisOAM_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x316f
};

const u16 sSpriteDebrisOAM_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x316e
};

const u16 sSpriteDebrisOAM_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x316d
};

const u16 sParticleHittingSomethingWithPlasmaBeamOam_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1ec, 0x2192,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1ec, 0x2192,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x4, 0x2192,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, 0x2192
};

const u16 sSpriteDebrisOAM_Unused_Frame4[OAM_DATA_SIZE(8)] = {
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

const u16 sSpriteDebrisOAM_Unused_Frame5[OAM_DATA_SIZE(8)] = {
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

const struct FrameData sParticleHittingSomethingWithNormalBeamOam[5] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithLongBeamOam[5] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithIceBeamOam[6] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithIceBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingWithIceBeamOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithWaveBeamOam[7] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithIceBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingWithWaveBeamOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleHittingSomethingWithWaveBeamOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithPlasmaBeamOam[8] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithIceBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingWithWaveBeamOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sParticleHittingSomethingWithPlasmaBeamOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleHittingSomethingWithPlasmaBeamOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingInvincibleOam[6] = {
    [0] = {
        .pFrame = sParticleHittingSomethingInvincible_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingInvincible_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingInvincible_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingInvincible_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingInvincible_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithMissileOam[8] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleHittingSomethingWithSuperMissileOam[8] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleHittingSomethingWithSuperMissileOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleHittingSomethingWithSuperMissileOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleHittingSomethingWithSuperMissileOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteExplosionHugeOam[14] = {
    [0] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame11,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSmallDustOam[7] = {
    [0] = {
        .pFrame = sParticleSmallDustOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleSmallDustOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleSmallDustOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSmallDustOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleSmallDustOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleSmallDustOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleMediumDustOam[10] = {
    [0] = {
        .pFrame = sParticleMediumDustOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleMediumDustOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleMediumDustOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleMediumDustOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleMediumDustOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleMediumDustOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleMediumDustOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleMediumDustOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleMediumDustOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleTwoMediumDustOam[11] = {
    [0] = {
        .pFrame = sParticleTwoMediumDustOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleTwoMediumDustOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleTwoMediumDustOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleTwoMediumDustOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleTwoMediumDustOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleTwoMediumDustOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParticleTwoMediumDustOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParticleTwoMediumDustOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sParticleTwoMediumDustOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sParticleTwoMediumDustOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteExplosionSmallOam[12] = {
    [0] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteExplosionMediumOam[18] = {
    [0] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame15,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [16] = {
        .pFrame = sParticleSpriteExplosionMediumOam_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteExplosionBigOam[18] = {
    [0] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleSpriteExplosionSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame15,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [16] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteExplosionSingleThenBigOam[17] = {
    [0] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleSpriteExplosionSingleThenBigOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteExplosionHugeOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame15,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sParticleSpriteExplosionBigOam_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleScrewAttackDestroyedOam[9] = {
    [0] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleScrewAttackDestroyedOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleShinesparkDestroyedOam[11] = {
    [0] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sParticleShinesparkDestroyedOam_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSudoScrewDestroyedOam[9] = {
    [0] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSudoScrewDestroyedOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpeedboosterDestroyedOam[9] = {
    [0] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpeedboosterDestroyedOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleFreezingSpriteWithIceOam[17] = {
    [0] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sParticleFreezingSpriteWithIceOam_Frame15,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleFreezingSpritewithChargedIceBeamOam[16] = {
    [0] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sParticleFreezingSpritewithChargedIceBeamOam_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleMainBossDeathOam[18] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithMissileOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleMainBossDeathOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleMainBossDeathOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParticleMainBossDeathOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParticleMainBossDeathOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParticleMainBossDeathOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParticleMainBossDeathOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleMainBossDeathOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sParticleMainBossDeathOam_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sParticleMainBossDeathOam_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sParticleMainBossDeathOam_Frame11,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sParticleMainBossDeathOam_Frame12,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [13] = {
        .pFrame = sParticleMainBossDeathOam_Frame13,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [14] = {
        .pFrame = sParticleMainBossDeathOam_Frame14,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [15] = {
        .pFrame = sParticleMainBossDeathOam_Frame15,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [16] = {
        .pFrame = sParticleMainBossDeathOam_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Spawning[8] = {
    [0] = {
        .pFrame = sWaterDropOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sWaterDropOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sWaterDropOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sWaterDropOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sWaterDropOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sWaterDropOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sWaterDropOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Falling[2] = {
    [0] = {
        .pFrame = sWaterDropOam_Falling_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaterDropOam_Splashing[6] = {
    [0] = {
        .pFrame = sWaterDropOam_Splashing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sWaterDropOam_Splashing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sWaterDropOam_Splashing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sWaterDropOam_Splashing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sWaterDropOam_Splashing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSpriteDebrisOAM[5] = {
    [0] = {
        .pFrame = sSpriteDebrisOAM_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSpriteDebrisOAM_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSpriteDebrisOAM_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSpriteDebrisOAM_Frame3,
        .timer = UCHAR_MAX
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSpriteDebrisOAM_Unused[7] = {
    [0] = {
        .pFrame = sParticleHittingSomethingWithNormalBeamOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sParticleHittingSomethingWithLongBeamOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParticleHittingSomethingWithIceBeamOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParticleHittingSomethingWithWaveBeamOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSpriteDebrisOAM_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSpriteDebrisOAM_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

// 33bd34
