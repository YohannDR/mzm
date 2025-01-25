#include "data/visual_effects_data.h"
#include "macros.h"

const u16 sEnvEffectOam_RunningOnDustyGround_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x4159
};

const u16 sEnvEffectOam_RunningOnDustyGround_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x415a
};

const u16 sEnvEffectOam_RunningOnDustyGround_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x415b
};

const u16 sEnvEffectOam_RunningOnDustyGround_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf5, 0x1fc, 0x415c
};

const u16 sEnvEffectOam_RunningOnDustyGround_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf4, 0x1fc, 0x415d
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1f8, 0x4159,
    0xf8, OBJ_X_FLIP | 0x0, 0x4159
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f6, 0x4159,
    0xfa, 0x1fa, 0x415b,
    0xf8, OBJ_X_FLIP | 0x2, 0x4159,
    0xfa, OBJ_X_FLIP | 0x1fe, 0x415b
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f2, 0x4159,
    0xfa, 0x1f8, 0x415b,
    0xf8, OBJ_X_FLIP | 0x6, 0x4159,
    0xfa, OBJ_X_FLIP | 0x0, 0x415b
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, 0x1f0, 0x415a,
    0xf7, 0x1f5, 0x415c,
    0xf7, OBJ_X_FLIP | 0x8, 0x415a,
    0xf7, OBJ_X_FLIP | 0x3, 0x415c
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, 0x1f0, 0x415b,
    0xf8, 0x1f4, 0x415d,
    0xf7, OBJ_X_FLIP | 0x8, 0x415b,
    0xf8, OBJ_X_FLIP | 0x4, 0x415d
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, 0x1f0, 0x415c,
    0xf5, OBJ_X_FLIP | 0x8, 0x415c
};

const u16 sEnvEffectOam_LandingOnDustyGround_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f0, 0x415d,
    0xf4, OBJ_X_FLIP | 0x8, 0x415d
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1f8, 0x3159,
    0xf8, OBJ_X_FLIP | 0x0, 0x3159
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, 0x1f6, 0x3159,
    0xfb, 0x1fa, 0x315b,
    0xfa, OBJ_X_FLIP | 0x2, 0x3159,
    0xfb, OBJ_X_FLIP | 0x1fe, 0x315b
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, 0x1fc, 0x3159,
    0xf9, 0x1f2, 0x3159,
    0xfa, 0x1f6, 0x315a,
    0xfc, 0x1f8, 0x315b,
    0xf9, OBJ_X_FLIP | 0x6, 0x3159,
    0xfa, OBJ_X_FLIP | 0x2, 0x315a,
    0xfc, OBJ_X_FLIP | 0x0, 0x315b
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf6, 0x1fc, 0x315a,
    0xf5, 0x1f1, 0x3159,
    0xf9, 0x1f2, 0x315a,
    0xfc, 0x1f5, 0x315b,
    0xf5, OBJ_X_FLIP | 0x7, 0x3159,
    0xf9, OBJ_X_FLIP | 0x6, 0x315a,
    0xfc, OBJ_X_FLIP | 0x3, 0x315b,
    0xfb, 0x1fc, 0x315b
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame4[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf5, 0x1fc, 0x315b,
    0xf3, 0x1f1, 0x315a,
    0xf9, 0x1f2, 0x315b,
    0xf9, 0x1f4, 0x315c,
    0xf3, OBJ_X_FLIP | 0x7, 0x315a,
    0xf9, OBJ_X_FLIP | 0x6, 0x315b,
    0xf9, OBJ_X_FLIP | 0x4, 0x315c,
    0xf7, 0x1fc, 0x315c
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf3, 0x1fc, 0x315c,
    0xf2, 0x1f1, 0x315b,
    0xf5, 0x1f2, 0x315c,
    0xfa, 0x1f5, 0x315d,
    0xf2, OBJ_X_FLIP | 0x7, 0x315b,
    0xf5, OBJ_X_FLIP | 0x6, 0x315c,
    0xfa, OBJ_X_FLIP | 0x3, 0x315d,
    0xf7, 0x1fc, 0x315d
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf1, 0x1fc, 0x315d,
    0xf1, 0x1f1, 0x315c,
    0xf5, 0x1f3, 0x315d,
    0xf1, OBJ_X_FLIP | 0x7, 0x315c,
    0xf5, OBJ_X_FLIP | 0x5, 0x315d
};

const u16 sEnvEffectOam_TakingDamageInLava_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, 0x1f1, 0x315d,
    0xf1, OBJ_X_FLIP | 0x7, 0x315d
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1f8, 0x5159,
    0xf8, OBJ_X_FLIP | 0x0, 0x5159
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, 0x1f6, 0x5159,
    0xfb, 0x1fa, 0x515b,
    0xfa, OBJ_X_FLIP | 0x2, 0x5159,
    0xfb, OBJ_X_FLIP | 0x1fe, 0x515b
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, 0x1fc, 0x5159,
    0xf9, 0x1f2, 0x5159,
    0xfa, 0x1f6, 0x515a,
    0xfc, 0x1f8, 0x515b,
    0xf9, OBJ_X_FLIP | 0x6, 0x5159,
    0xfa, OBJ_X_FLIP | 0x2, 0x515a,
    0xfc, OBJ_X_FLIP | 0x0, 0x515b
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf6, 0x1fc, 0x515a,
    0xf5, 0x1f1, 0x5159,
    0xf9, 0x1f2, 0x515a,
    0xfc, 0x1f5, 0x515b,
    0xf5, OBJ_X_FLIP | 0x7, 0x5159,
    0xf9, OBJ_X_FLIP | 0x6, 0x515a,
    0xfc, OBJ_X_FLIP | 0x3, 0x515b,
    0xfb, 0x1fc, 0x515b
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame4[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf5, 0x1fc, 0x515b,
    0xf3, 0x1f1, 0x515a,
    0xf9, 0x1f2, 0x515b,
    0xf9, 0x1f4, 0x515c,
    0xf3, OBJ_X_FLIP | 0x7, 0x515a,
    0xf9, OBJ_X_FLIP | 0x6, 0x515b,
    0xf9, OBJ_X_FLIP | 0x4, 0x515c,
    0xf7, 0x1fc, 0x515c
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf3, 0x1fc, 0x515c,
    0xf2, 0x1f1, 0x515b,
    0xf5, 0x1f2, 0x515c,
    0xfa, 0x1f5, 0x515d,
    0xf2, OBJ_X_FLIP | 0x7, 0x515b,
    0xf5, OBJ_X_FLIP | 0x6, 0x515c,
    0xfa, OBJ_X_FLIP | 0x3, 0x515d,
    0xf7, 0x1fc, 0x515d
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame6[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf1, 0x1fc, 0x515d,
    0xf1, 0x1f1, 0x515c,
    0xf5, 0x1f3, 0x515d,
    0xf1, OBJ_X_FLIP | 0x7, 0x515c,
    0xf5, OBJ_X_FLIP | 0x5, 0x515d
};

const u16 sEnvEffectOam_TakingDamageInAcid_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, 0x1f1, 0x515d,
    0xf1, OBJ_X_FLIP | 0x7, 0x515d
};

const u16 sEnvEffectOam_RunningOnWetGround_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x409d
};

const u16 sEnvEffectOam_RunningOnWetGround_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x409e
};

const u16 sEnvEffectOam_RunningOnWetGround_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x409f
};

const u16 sEnvEffectOam_RunningOnWetGround_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x40bd
};

const u16 sEnvEffectOam_RunningOnWetGround_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x40be
};

const u16 sEnvEffectOam_LandingOnWetGround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x409d,
    0xf8, 0x0, 0x409d
};

const u16 sEnvEffectOam_LandingOnWetGround_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x409e,
    0xf8, 0x1, 0x409e
};

const u16 sEnvEffectOam_LandingOnWetGround_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x409f,
    0xf8, 0x1, 0x409f
};

const u16 sEnvEffectOam_LandingOnWetGround_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x40bd,
    0xf8, 0x1, 0x40bd
};

const u16 sEnvEffectOam_LandingOnWetGround_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x40be,
    0xf8, 0x0, 0x40be
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x415f
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x415f,
    0xee, 0x1fc, 0x415e
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x409d,
    0xfa, OBJ_X_FLIP | 0x2, 0x409d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x415f,
    0xea, 0x1fc, 0x415e
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x409d,
    0xf9, OBJ_X_FLIP | 0x3, 0x409d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x415f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x415e
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x409e,
    0xf9, OBJ_X_FLIP | 0x4, 0x409e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x415f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x415e,
    0xf8, 0x1fc, 0x409d
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x409e,
    0xfa, OBJ_X_FLIP | 0x4, 0x409e,
    0xfa, 0x1fc, 0x409d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x415f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x415e
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xfa, 0x1f4, 0x409f,
    0xfa, OBJ_X_FLIP | 0x4, 0x409f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x415f,
    0xf9, 0x1fc, 0x40bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x418f
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x41d4,
    0xfa, 0x0, 0x415f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x415f,
    0xfa, 0x1f5, 0x40bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x40bd,
    0xf8, 0x1fc, 0x40be
};

const u16 sEnvEffectOam_GoingOutOfWater_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x40be,
    0xf8, OBJ_X_FLIP | 0x1, 0x40be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x4187,
    0xf7, 0x1fc, 0x41a7
};

const u16 sEnvEffectOam_RunningIntoWater_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x409d,
    0xf9, 0x0, 0x409d
};

const u16 sEnvEffectOam_RunningIntoWater_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x409e,
    0xf9, 0x1, 0x409e,
    0xf6, 0x1fc, 0x415e
};

const u16 sEnvEffectOam_RunningIntoWater_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x409f,
    0xf8, 0x1, 0x409f,
    0xf3, 0x1fc, 0x415e
};

const u16 sEnvEffectOam_RunningIntoWater_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x40bd,
    0xf8, 0x1, 0x40bd,
    0xf1, 0x1fc, 0x415e
};

const u16 sEnvEffectOam_RunningIntoWater_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x40be,
    0xf8, 0x0, 0x40be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x415e
};

const u16 sEnvEffectOam_RunningIntoWater_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x40be,
    0xf9, 0x0, 0x40be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x415e,
    0xf5, 0x1f8, 0x41a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x41a7
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x315f
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x315f,
    0xee, 0x1fc, 0x315e
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x309d,
    0xfa, OBJ_X_FLIP | 0x2, 0x309d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x315f,
    0xea, 0x1fc, 0x315e
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x309d,
    0xf9, OBJ_X_FLIP | 0x3, 0x309d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x315f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x315e
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x309e,
    0xf9, OBJ_X_FLIP | 0x4, 0x309e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x315f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x315e,
    0xf8, 0x1fc, 0x309d
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x309e,
    0xfa, OBJ_X_FLIP | 0x4, 0x309e,
    0xfa, 0x1fc, 0x309d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x315f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x315e
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xfa, 0x1f4, 0x309f,
    0xfa, OBJ_X_FLIP | 0x4, 0x309f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x315f,
    0xf9, 0x1fc, 0x30bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x318f
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xfa, 0x0, 0x315f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x315f,
    0xfa, 0x1f5, 0x30bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x30bd,
    0xf8, 0x1fc, 0x30be
};

const u16 sEnvEffectOam_GoingOutOfLava_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x30be,
    0xf8, OBJ_X_FLIP | 0x1, 0x30be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x3187,
    0xf7, 0x1fc, 0x31a7
};

const u16 sEnvEffectOam_RunningIntoLava_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x309d,
    0xf9, 0x0, 0x309d
};

const u16 sEnvEffectOam_RunningIntoLava_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x309e,
    0xf9, 0x1, 0x309e,
    0xf6, 0x1fc, 0x315e
};

const u16 sEnvEffectOam_RunningIntoLava_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x309f,
    0xf8, 0x1, 0x309f,
    0xf3, 0x1fc, 0x315e
};

const u16 sEnvEffectOam_RunningIntoLava_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x30bd,
    0xf8, 0x1, 0x30bd,
    0xf1, 0x1fc, 0x315e
};

const u16 sEnvEffectOam_RunningIntoLava_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x30be,
    0xf8, 0x0, 0x30be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x315e
};

const u16 sEnvEffectOam_RunningIntoLava_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x30be,
    0xf9, 0x0, 0x30be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x315e,
    0xf5, 0x1f8, 0x31a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x31a7
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x5188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x515f
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x5188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x515f,
    0xee, 0x1fc, 0x515e
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x509d,
    0xfa, OBJ_X_FLIP | 0x2, 0x509d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x515f,
    0xea, 0x1fc, 0x515e
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x509d,
    0xf9, OBJ_X_FLIP | 0x3, 0x509d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x515f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x515e
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x509e,
    0xf9, OBJ_X_FLIP | 0x4, 0x509e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x515f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x518c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x515e,
    0xf8, 0x1fc, 0x509d
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x509e,
    0xfa, OBJ_X_FLIP | 0x4, 0x509e,
    0xfa, 0x1fc, 0x509d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x515f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x515e
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518e,
    0xfa, 0x1f4, 0x509f,
    0xfa, OBJ_X_FLIP | 0x4, 0x509f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x515f,
    0xf9, 0x1fc, 0x50bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x518f
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x51d4,
    0xfa, 0x0, 0x515f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x515f,
    0xfa, 0x1f5, 0x50bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x50bd,
    0xf8, 0x1fc, 0x50be
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x50be,
    0xf8, OBJ_X_FLIP | 0x1, 0x50be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x5187,
    0xf7, 0x1fc, 0x51a7
};

const u16 sEnvEffectOam_GoingOutOfAcid_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x509d,
    0xf9, 0x0, 0x509d
};

const u16 sEnvEffectOam_RunningIntoAcid_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x509e,
    0xf9, 0x1, 0x509e,
    0xf6, 0x1fc, 0x515e
};

const u16 sEnvEffectOam_RunningIntoAcid_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x509f,
    0xf8, 0x1, 0x509f,
    0xf3, 0x1fc, 0x515e
};

const u16 sEnvEffectOam_RunningIntoAcid_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x50bd,
    0xf8, 0x1, 0x50bd,
    0xf1, 0x1fc, 0x515e
};

const u16 sEnvEffectOam_RunningIntoAcid_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x50be,
    0xf8, 0x0, 0x50be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x515e
};

const u16 sEnvEffectOam_RunningIntoAcid_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x50be,
    0xf9, 0x0, 0x50be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x515e,
    0xf5, 0x1f8, 0x51a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x51a7
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfa, 0x1fc, 0x417d,
    0xfa, 0x1f8, 0x417e
};

const u16 sEnvEffectOam_FrameUnused[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, 0x1f5, 0x4179,
    0xf9, 0x0, 0x417e,
    0xfb, 0x1fb, 0x417a
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf6, 0x1f4, 0x417a,
    0xf6, 0x1, 0x4179,
    0xf8, 0x1fc, 0x417b,
    0xfa, 0x1f7, 0x4179
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, 0x1f4, 0x417b,
    0xf5, 0x2, 0x417a,
    0xf6, 0x1fb, 0x417c,
    0xf6, 0x1f7, 0x417a
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, 0x3, 0x417b,
    0xf2, 0x1f3, 0x417c,
    0xf3, 0x1f8, 0x417b
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, 0x3, 0x417c,
    0xf1, 0x1f8, 0x417c
};

const u16 sEnvEffectOam_LandingOnBubblyGround_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xee, 0x2, 0x417c,
    0xf0, 0x1f8, 0x417c
};

const u16 sEnvEffectOam_BreathingBubbles_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fb, 0x4179
};

const u16 sEnvEffectOam_BreathingBubbles_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, 0x1fc, 0x417a,
    0xfe, 0x1fc, 0x4179
};

const u16 sEnvEffectOam_BreathingBubbles_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, 0x1fc, 0x417b,
    0xfd, 0x1fc, 0x417e
};

const u16 sEnvEffectOam_BreathingBubbles_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1fb, 0x417c,
    0xfb, 0x1fc, 0x4179
};

const u16 sEnvEffectOam_BreathingBubbles_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, 0x1fe, 0x417a,
    0xf2, 0x1fb, 0x417c
};

const u16 sEnvEffectOam_BreathingBubbles_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, 0x1fe, 0x417b
};

const u16 sEnvEffectOam_BreathingBubbles_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf4, 0x1fd, 0x417c
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, 0x418a
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x418c
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x418e
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_X_FLIP | 0x1fd, 0x418f,
    0xf7, 0x1f9, 0x418f,
    0xfb, OBJ_Y_FLIP | 0x1fe, 0x418f
};

const u16 sEnvEffectOam_RunningOnVeryDustyGround_Frame10[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, OBJ_Y_FLIP | 0x1fb, 0x41a7,
    0xfa, 0x1fd, 0x41a7
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    0xf6, OBJ_SIZE_16x16 | 0x1f3, 0x4188
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x4188,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, 0x4188
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fb, 0x418a,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x4188,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x4188
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1fc, 0x418c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, 0x418a,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, 0x4188
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x418e,
    0xec, OBJ_SIZE_16x16 | 0x1ed, 0x418c,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x418a
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame10[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x1ee, 0x418e,
    0xef, OBJ_SIZE_16x16 | 0x4, 0x418c,
    0xed, OBJ_SIZE_16x16 | 0x1fd, 0x41d4
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame12[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fd, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, 0x41d4
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame14[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1f6, 0x4187,
    0xe6, OBJ_SIZE_16x16 | 0x2, 0x41d4
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame16[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x4, 0x4187
};

const u16 sEnvEffectOam_LandingOnVeryDustyGround_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x4140
};

const struct FrameData sEnvEffectOam_RunningOnDustyGround[6] = {
    [0] = {
        .pFrame = sEnvEffectOam_RunningOnDustyGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_RunningOnDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningOnDustyGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_RunningOnDustyGround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningOnDustyGround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_LandingOnDustyGround[8] = {
    [0] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_LandingOnDustyGround_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_TakingDamageInLava[9] = {
    [0] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_TakingDamageInLava_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_TakingDamageInAcid[9] = {
    [0] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_TakingDamageInAcid_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_RunningOnWetGround[6] = {
    [0] = {
        .pFrame = sEnvEffectOam_RunningOnWetGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_RunningOnWetGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningOnWetGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_RunningOnWetGround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningOnWetGround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_LandingOnWetGround[6] = {
    [0] = {
        .pFrame = sEnvEffectOam_LandingOnWetGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_LandingOnWetGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_LandingOnWetGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_LandingOnWetGround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_LandingOnWetGround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_GoingOutOfWater[10] = {
    [0] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sEnvEffectOam_GoingOutOfWater_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_RunningIntoWater[7] = {
    [0] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sEnvEffectOam_RunningIntoWater_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_GoingOutOfLava[10] = {
    [0] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sEnvEffectOam_GoingOutOfLava_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_RunningIntoLava[7] = {
    [0] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sEnvEffectOam_RunningIntoLava_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_GoingOutOfAcid[11] = {
    [0] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_RunningIntoAcid[7] = {
    [0] = {
        .pFrame = sEnvEffectOam_GoingOutOfAcid_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_RunningIntoAcid_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningIntoAcid_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_RunningIntoAcid_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningIntoAcid_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sEnvEffectOam_RunningIntoAcid_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_LandingOnBubblyGround[7] = {
    [0] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sEnvEffectOam_LandingOnBubblyGround_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_BreathingBubbles[8] = {
    [0] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sEnvEffectOam_BreathingBubbles_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_RunningOnVeryDustyGround[12] = {
    [0] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sEnvEffectOam_RunningOnVeryDustyGround_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnvEffectOam_LandingOnVeryDustyGround[18] = {
    [0] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sEnvEffectOam_LandingOnVeryDustyGround_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const u16 sParticleSpriteSplashWaterBigOam_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x415f
};

const u16 sParticleSpriteSplashWaterBigOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x4188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x415f,
    0xee, 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterBigOam_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x409d,
    0xfa, OBJ_X_FLIP | 0x2, 0x409d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x415f,
    0xea, 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterBigOam_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x409d,
    0xf9, OBJ_X_FLIP | 0x3, 0x409d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x415f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterBigOam_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x409e,
    0xf9, OBJ_X_FLIP | 0x4, 0x409e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x415f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x418c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x415e,
    0xf8, 0x1fc, 0x409d
};

const u16 sParticleSpriteSplashWaterBigOam_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x409e,
    0xfa, OBJ_X_FLIP | 0x4, 0x409e,
    0xfa, 0x1fc, 0x409d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x415f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterBigOam_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x418e,
    0xfa, 0x1f4, 0x409f,
    0xfa, OBJ_X_FLIP | 0x4, 0x409f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x415f,
    0xf9, 0x1fc, 0x40bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x418f
};

const u16 sParticleSpriteSplashWaterBigOam_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x41d4,
    0xfa, 0x0, 0x415f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x415f,
    0xfa, 0x1f5, 0x40bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x40bd,
    0xf8, 0x1fc, 0x40be
};

const u16 sParticleSpriteSplashWaterBigOam_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x40be,
    0xf8, OBJ_X_FLIP | 0x1, 0x40be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x4187,
    0xf7, 0x1fc, 0x41a7
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf9, 0x1f3, 0x409d,
    0xf9, OBJ_X_FLIP | 0x5, 0x409d,
    0xfe, OBJ_SIZE_16x16 | 0x1f5, 0x418a,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f9, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1ff, 0x415f,
    0xea, 0x1fa, 0x415e,
    0xea, OBJ_X_FLIP | 0x1ff, 0x415e
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, 0x1f2, 0x409d,
    0xf8, OBJ_X_FLIP | 0x6, 0x409d,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x418a,
    0xfe, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x418a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x415f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x415e,
    0xe7, OBJ_Y_FLIP | 0x0, 0x415e
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame4[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf8, 0x1f0, 0x409e,
    0xf8, OBJ_X_FLIP | 0x8, 0x409e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f6, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x2, 0x415f,
    0x1, OBJ_SIZE_16x16 | 0x1f2, 0x418c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x418c,
    0xea, OBJ_X_FLIP | 0x1f7, 0x415e,
    0xf8, 0x1fc, 0x409d,
    0xea, 0x1, 0x415e
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame5[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf9, 0x1ef, 0x409e,
    0xf9, OBJ_X_FLIP | 0x9, 0x409e,
    0xfa, 0x1fc, 0x409d,
    0x4, OBJ_SIZE_16x16 | 0x1f1, 0x418e,
    0x1, OBJ_SIZE_16x16 | 0x0, 0x418e,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1f5, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x3, 0x415f,
    0xf2, OBJ_X_FLIP | 0x1f4, 0x415e,
    0xf2, 0x4, 0x415e
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame6[OAM_DATA_SIZE(8)] = {
    0x8,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x418e,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, 0x418e,
    0xfa, 0x1ef, 0x409f,
    0xfa, OBJ_X_FLIP | 0x9, 0x409f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f4, 0x415f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x4, 0x415f,
    0xf9, 0x1fc, 0x40bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x418f
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0x8, OBJ_SIZE_16x16 | 0x1ef, 0x41d4,
    0xfa, 0x1ef, 0x40bd,
    0xfa, OBJ_X_FLIP | 0x9, 0x40bd,
    0xfa, 0x3, 0x415f,
    0xfa, OBJ_X_FLIP | 0x1f5, 0x415f,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x41d4,
    0xf8, 0x1fc, 0x40be
};

const u16 sParticleSpriteSplashWaterHugeOam_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, 0x1f2, 0x40be,
    0xf8, OBJ_X_FLIP | 0x6, 0x40be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1f2, 0x4187,
    OBJ_SHAPE_VERTICAL | 0x7, OBJ_X_FLIP | 0x8, 0x4187,
    0xf7, 0x1fc, 0x41a7
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x409d,
    0xf9, 0x0, 0x409d
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x409e,
    0xf9, 0x1, 0x409e,
    0xf6, 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x409f,
    0xf8, 0x1, 0x409f,
    0xf3, 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x40bd,
    0xf8, 0x1, 0x40bd,
    0xf1, 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x40be,
    0xf8, 0x0, 0x40be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x415e
};

const u16 sParticleSpriteSplashWaterSmallOam_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x40be,
    0xf9, 0x0, 0x40be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x415e,
    0xf5, 0x1f8, 0x41a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x41a7
};

const u16 sParticleSpriteSplashLavaBigOam_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x315f
};

const u16 sParticleSpriteSplashLavaBigOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x315f,
    0xee, 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaBigOam_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x309d,
    0xfa, OBJ_X_FLIP | 0x2, 0x309d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x315f,
    0xea, 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaBigOam_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x309d,
    0xf9, OBJ_X_FLIP | 0x3, 0x309d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x315f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaBigOam_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x309e,
    0xf9, OBJ_X_FLIP | 0x4, 0x309e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x315f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x318c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x315e,
    0xf8, 0x1fc, 0x309d
};

const u16 sParticleSpriteSplashLavaBigOam_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x309e,
    0xfa, OBJ_X_FLIP | 0x4, 0x309e,
    0xfa, 0x1fc, 0x309d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x315f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaBigOam_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x318e,
    0xfa, 0x1f4, 0x309f,
    0xfa, OBJ_X_FLIP | 0x4, 0x309f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x315f,
    0xf9, 0x1fc, 0x30bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x318f
};

const u16 sParticleSpriteSplashLavaBigOam_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x31d4,
    0xfa, 0x0, 0x315f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x315f,
    0xfa, 0x1f5, 0x30bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x30bd,
    0xf8, 0x1fc, 0x30be
};

const u16 sParticleSpriteSplashLavaBigOam_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x30be,
    0xf8, OBJ_X_FLIP | 0x1, 0x30be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x3187,
    0xf7, 0x1fc, 0x31a7
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf9, 0x1f3, 0x309d,
    0xf9, OBJ_X_FLIP | 0x5, 0x309d,
    0xfe, OBJ_SIZE_16x16 | 0x1f5, 0x318a,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f9, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1ff, 0x315f,
    0xea, 0x1fa, 0x315e,
    0xea, OBJ_X_FLIP | 0x1ff, 0x315e
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, 0x1f2, 0x309d,
    0xf8, OBJ_X_FLIP | 0x6, 0x309d,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x318a,
    0xfe, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x318a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x315f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x315e,
    0xe7, OBJ_Y_FLIP | 0x0, 0x315e
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame4[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf8, 0x1f0, 0x309e,
    0xf8, OBJ_X_FLIP | 0x8, 0x309e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f6, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x2, 0x315f,
    0x1, OBJ_SIZE_16x16 | 0x1f2, 0x318c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x318c,
    0xea, OBJ_X_FLIP | 0x1f7, 0x315e,
    0xf8, 0x1fc, 0x309d,
    0xea, 0x1, 0x315e
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame5[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf9, 0x1ef, 0x309e,
    0xf9, OBJ_X_FLIP | 0x9, 0x309e,
    0xfa, 0x1fc, 0x309d,
    0x4, OBJ_SIZE_16x16 | 0x1f1, 0x318e,
    0x1, OBJ_SIZE_16x16 | 0x0, 0x318e,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1f5, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x3, 0x315f,
    0xf2, OBJ_X_FLIP | 0x1f4, 0x315e,
    0xf2, 0x4, 0x315e
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame6[OAM_DATA_SIZE(8)] = {
    0x8,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x318e,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, 0x318e,
    0xfa, 0x1ef, 0x309f,
    0xfa, OBJ_X_FLIP | 0x9, 0x309f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f4, 0x315f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x4, 0x315f,
    0xf9, 0x1fc, 0x30bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x318f
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0x8, OBJ_SIZE_16x16 | 0x1ef, 0x31d4,
    0xfa, 0x1ef, 0x30bd,
    0xfa, OBJ_X_FLIP | 0x9, 0x30bd,
    0xfa, 0x3, 0x315f,
    0xfa, OBJ_X_FLIP | 0x1f5, 0x315f,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x31d4,
    0xf8, 0x1fc, 0x30be
};

const u16 sParticleSpriteSplashLavaHugeOam_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, 0x1f2, 0x30be,
    0xf8, OBJ_X_FLIP | 0x6, 0x30be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1f2, 0x3187,
    OBJ_SHAPE_VERTICAL | 0x7, OBJ_X_FLIP | 0x8, 0x3187,
    0xf7, 0x1fc, 0x31a7
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x309d,
    0xf9, 0x0, 0x309d
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x309e,
    0xf9, 0x1, 0x309e,
    0xf6, 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x309f,
    0xf8, 0x1, 0x309f,
    0xf3, 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x30bd,
    0xf8, 0x1, 0x30bd,
    0xf1, 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x30be,
    0xf8, 0x0, 0x30be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x315e
};

const u16 sParticleSpriteSplashLavaSmallOam_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x30be,
    0xf9, 0x0, 0x30be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x315e,
    0xf5, 0x1f8, 0x31a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x31a7
};

const u16 sParticleSpriteSplashAcidBigOam_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x5188,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fb, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_X_FLIP | 0x1fd, 0x515f
};

const u16 sParticleSpriteSplashAcidBigOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x5188,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fa, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fe, 0x515f,
    0xee, 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidBigOam_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, 0x1f6, 0x509d,
    0xfa, OBJ_X_FLIP | 0x2, 0x509d,
    0xfe, OBJ_SIZE_16x16 | 0x1f8, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x515f,
    0xea, 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidBigOam_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf9, 0x1f5, 0x509d,
    0xf9, OBJ_X_FLIP | 0x3, 0x509d,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x515f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidBigOam_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf9, 0x1f4, 0x509e,
    0xf9, OBJ_X_FLIP | 0x4, 0x509e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x0, 0x515f,
    0x2, OBJ_SIZE_16x16 | 0x1f8, 0x518c,
    0xea, OBJ_X_FLIP | 0x1fc, 0x515e,
    0xf8, 0x1fc, 0x509d
};

const u16 sParticleSpriteSplashAcidBigOam_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xfa, 0x1f4, 0x509e,
    0xfa, OBJ_X_FLIP | 0x4, 0x509e,
    0xfa, 0x1fc, 0x509d,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, 0x515f,
    0xf2, OBJ_X_FLIP | 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidBigOam_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0x6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x518e,
    0xfa, 0x1f4, 0x509f,
    0xfa, OBJ_X_FLIP | 0x4, 0x509f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x0, 0x515f,
    0xf9, 0x1fc, 0x50bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x518f
};

const u16 sParticleSpriteSplashAcidBigOam_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0x8, OBJ_SIZE_16x16 | 0x1f8, 0x51d4,
    0xfa, 0x0, 0x515f,
    0xfa, OBJ_X_FLIP | 0x1f8, 0x515f,
    0xfa, 0x1f5, 0x50bd,
    0xfa, OBJ_X_FLIP | 0x3, 0x50bd,
    0xf8, 0x1fc, 0x50be
};

const u16 sParticleSpriteSplashAcidBigOam_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f7, 0x50be,
    0xf8, OBJ_X_FLIP | 0x1, 0x50be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1fc, 0x5187,
    0xf7, 0x1fc, 0x51a7
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf9, 0x1f3, 0x509d,
    0xf9, OBJ_X_FLIP | 0x5, 0x509d,
    0xfe, OBJ_SIZE_16x16 | 0x1f5, 0x518a,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1f9, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1ff, 0x515f,
    0xea, 0x1fa, 0x515e,
    0xea, OBJ_X_FLIP | 0x1ff, 0x515e
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, 0x1f2, 0x509d,
    0xf8, OBJ_X_FLIP | 0x6, 0x509d,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x518a,
    0xfe, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x518a,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x1f8, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, 0x515f,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x515e,
    0xe7, OBJ_Y_FLIP | 0x0, 0x515e
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame4[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf8, 0x1f0, 0x509e,
    0xf8, OBJ_X_FLIP | 0x8, 0x509e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f6, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xee, 0x2, 0x515f,
    0x1, OBJ_SIZE_16x16 | 0x1f2, 0x518c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x518c,
    0xea, OBJ_X_FLIP | 0x1f7, 0x515e,
    0xf8, 0x1fc, 0x509d,
    0xea, 0x1, 0x515e
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame5[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf9, 0x1ef, 0x509e,
    0xf9, OBJ_X_FLIP | 0x9, 0x509e,
    0xfa, 0x1fc, 0x509d,
    0x4, OBJ_SIZE_16x16 | 0x1f1, 0x518e,
    0x1, OBJ_SIZE_16x16 | 0x0, 0x518e,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1f5, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x3, 0x515f,
    0xf2, OBJ_X_FLIP | 0x1f4, 0x515e,
    0xf2, 0x4, 0x515e
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame6[OAM_DATA_SIZE(8)] = {
    0x8,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x518e,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, 0x518e,
    0xfa, 0x1ef, 0x509f,
    0xfa, OBJ_X_FLIP | 0x9, 0x509f,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f4, 0x515f,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | 0x4, 0x515f,
    0xf9, 0x1fc, 0x50bd,
    0xf4, OBJ_X_FLIP | 0x1fb, 0x518f
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    0x8, OBJ_SIZE_16x16 | 0x1ef, 0x51d4,
    0xfa, 0x1ef, 0x50bd,
    0xfa, OBJ_X_FLIP | 0x9, 0x50bd,
    0xfa, 0x3, 0x515f,
    0xfa, OBJ_X_FLIP | 0x1f5, 0x515f,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, 0x51d4,
    0xf8, 0x1fc, 0x50be
};

const u16 sParticleSpriteSplashAcidHugeOam_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, 0x1f2, 0x50be,
    0xf8, OBJ_X_FLIP | 0x6, 0x50be,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1f2, 0x5187,
    OBJ_SHAPE_VERTICAL | 0x7, OBJ_X_FLIP | 0x8, 0x5187,
    0xf7, 0x1fc, 0x51a7
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x509d,
    0xf9, 0x0, 0x509d
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_X_FLIP | 0x1f7, 0x509e,
    0xf9, 0x1, 0x509e,
    0xf6, 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x509f,
    0xf8, 0x1, 0x509f,
    0xf3, 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f7, 0x50bd,
    0xf8, 0x1, 0x50bd,
    0xf1, 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x1f8, 0x50be,
    0xf8, 0x0, 0x50be,
    0xf4, OBJ_X_FLIP | 0x1fc, 0x515e
};

const u16 sParticleSpriteSplashAcidSmallOam_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x1f8, 0x50be,
    0xf9, 0x0, 0x50be,
    0xf9, OBJ_X_FLIP | 0x1fc, 0x515e,
    0xf5, 0x1f8, 0x51a7,
    0xf5, OBJ_X_FLIP | 0x0, 0x51a7
};

const struct FrameData sParticleSpriteSplashWaterBigOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashWaterHugeOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashWaterBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashWaterHugeOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashWaterSmallOam[7] = {
    [0] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashWaterSmallOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashLavaBigOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashLavaHugeOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashLavaBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashLavaHugeOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashLavaSmallOam[7] = {
    [0] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashLavaSmallOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashAcidBigOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashAcidHugeOam[10] = {
    [0] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashAcidBigOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sParticleSpriteSplashAcidHugeOam_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSpriteSplashAcidSmallOam[7] = {
    [0] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleSpriteSplashAcidSmallOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const u8 sEscapeTimerDigitsGfx[1024 * 2] = INCBIN_U8("data/EscapeTimerDigits.gfx");

const u16 sParticleEscapeOam[34] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0x0, 0x0, 0x33c0,
    OBJ_SHAPE_VERTICAL | 0x0, 0x8, 0x33c0,
    OBJ_SHAPE_VERTICAL | 0x0, 0x10, 0x33ca,
    OBJ_SHAPE_VERTICAL | 0x0, 0x18, 0x33c0,
    OBJ_SHAPE_VERTICAL | 0x0, 0x20, 0x33c0,
    OBJ_SHAPE_VERTICAL | 0x0, 0x28, 0x33ca,
    OBJ_SHAPE_VERTICAL | 0x0, 0x30, 0x33c0,
    OBJ_SHAPE_VERTICAL | 0x0, 0x38, 0x33c0,
    0x0, 0xdf94, 0x833,
    0xff, 0x0, 0x0,
    0x0, 0x0, 0x0
};
