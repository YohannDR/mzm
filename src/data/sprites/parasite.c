#include "data/sprites/parasite.h"
#include "macros.h"

const u32 sParasiteGfx[309] = INCBIN_U32("data/sprites/Parasite.gfx.lz");
const u16 sParasitePal[16] = INCBIN_U16("data/sprites/Parasite.pal");

const u16 sParasiteOAM_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

const u16 sParasiteOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x201
};

const u16 sParasiteOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x202
};

const u16 sParasiteOAM_Idle_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x203
};

const u16 sParasiteOAM_LandingAfterFalling_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x220
};

const u16 sParasiteOAM_LandingAfterFalling_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x221
};

const u16 sParasiteOAM_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x222
};

const u16 sParasiteOAM_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x223
};

const u16 sParasiteOAM_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x204
};

const u16 sParasiteOAM_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x200
};

const u16 sParasiteOAM_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x205
};

const u16 sParasiteOAM_TurningBackOnFeet_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x224
};

const u16 sParasiteOAM_TurningBackOnFeet_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x225
};

const u16 sParasiteOAM_TurningBackOnFeet_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x224,
};

const u16 sParasiteOAM_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

const u16 sParasiteOAM_JumpingUp_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x207
};

const u16 sParasiteOAM_JumpingUp_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x208
};

const u16 sParasiteOAM_JumpingUp_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x209
};

const u16 sParasiteOAM_JumpingUp_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fe, OBJ_SPRITE_OAM | 0x20a
};

const u16 sParasiteOAM_JumpingUp_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

const u16 sParasiteOAM_JumpingDown_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x227
};

const u16 sParasiteOAM_JumpingDown_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x228
};

const u16 sParasiteOAM_JumpingDown_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x229
};

const u16 sParasiteOAM_JumpingDown_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x22a
};

const u16 sParasiteOAM_Attached_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

const u16 sParasiteOAM_Attached_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sParasiteOAM_Attached_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

const u16 sParasiteOAM_Attached_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sParasiteOAM_Attached_Unused_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sParasiteOAM_Attached_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22b
};

const u16 sParasiteOAM_Attached_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22c
};

const u16 sParasiteOAM_Attached_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22d
};

const u16 sParasiteOAM_Attached_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22e
};

const u16 sParasiteOAM_Attached_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22f
};

const u16 sParasiteOAM_Expulsed_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x210
};

const u16 sParasiteOAM_Expulsed_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x211
};

const u16 sParasiteOAM_Expulsed_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x212
};

const u16 sParasiteOAM_Expulsed_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x213
};

const u16 sParasiteOAM_Expulsed_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x214
};

const u16 sParasiteOAM_Expulsed_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x215
};

const u16 sParasiteOAM_Expulsed_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x216
};

const u16 sParasiteOAM_Dying_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x230
};

const u16 sParasiteOAM_Dying_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x231
};

const u16 sParasiteOAM_Dying_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x232
};

const u16 sParasiteOAM_Dying_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x233
};

const u16 sParasiteOAM_Dying_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x217
};

const u16 sParasiteOAM_Dying_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x217
};

const u16 sParasiteOAM_Dying_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sParasiteOAM_Dying_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sParasiteOAM_Dying_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x237
};

const u16 sParasiteOAM_Dying_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

const u16 sParasiteOAM_Dying_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x239
};

const u16 sParasiteOAM_Dying_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf6, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x23a
};

const u16 sParasiteOAM_Dying_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const u16 sParasiteOAM_Dying_Frame9[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const struct FrameData sParasiteOAM_Idle[7] = {
    [0] = {
        .pFrame = sParasiteOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOAM_Idle_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_LandingAfterFalling[5] = {
    [0] = {
        .pFrame = sParasiteOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_LandingAfterFalling_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_LandingAfterFalling_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_LandingAfterFalling_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Landing[4] = {
    [0] = {
        .pFrame = sParasiteOAM_Landing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_Landing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Tumbling[5] = {
    [0] = {
        .pFrame = sParasiteOAM_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_TurningBackOnFeet[8] = {
    [0] = {
        .pFrame = sParasiteOAM_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_TurningBackOnFeet_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_TurningBackOnFeet_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_TurningBackOnFeet_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOAM_Landing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOAM_Landing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_TurningAround[2] = {
    [0] = {
        .pFrame = sParasiteOAM_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_JumpingUp_Unused[7] = {
    [0] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_JumpingDown_Unused[7] = {
    [0] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOAM_JumpingDown_Unused_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_JumpingUp[3] = {
    [0] = {
        .pFrame = sParasiteOAM_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_JumpingUp_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Attached_Unused[9] = {
    [0] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParasiteOAM_Attached_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Attached[9] = {
    [0] = {
        .pFrame = sParasiteOAM_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_Attached_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_Attached_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_Attached_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOAM_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOAM_Attached_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOAM_Attached_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParasiteOAM_Attached_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Expulsed[9] = {
    [0] = {
        .pFrame = sParasiteOAM_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParasiteOAM_Expulsed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParasiteOAM_Expulsed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParasiteOAM_Expulsed_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParasiteOAM_Expulsed_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParasiteOAM_Expulsed_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParasiteOAM_Expulsed_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParasiteOAM_Expulsed_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Dying_Unused[5] = {
    [0] = {
        .pFrame = sParasiteOAM_Dying_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOAM_Dying_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOAM_Dying_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOAM_Dying_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOAM_Dying[11] = {
    [0] = {
        .pFrame = sParasiteOAM_Dying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParasiteOAM_Dying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParasiteOAM_Dying_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParasiteOAM_Dying_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParasiteOAM_Dying_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParasiteOAM_Dying_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParasiteOAM_Dying_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParasiteOAM_Dying_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParasiteOAM_Dying_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sParasiteOAM_Dying_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};
