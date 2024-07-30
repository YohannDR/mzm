#ifndef IMAGO_COCOON_DATA_H
#define IMAGO_COCOON_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum ImagoCocoonOam {
    IMAGO_COCOON_OAM_CEILING_VINE_MOTIONLESS,
    IMAGO_COCOON_OAM_CEILING_VINE_MOVING,
    IMAGO_COCOON_OAM_CEILING_VINE_BROKEN,
    IMAGO_COCOON_OAM_DECORATIVE_VINE_LEFT,
    IMAGO_COCOON_OAM_DECORATIVE_VINE_RIGHT,
    IMAGO_COCOON_OAM_VINE_LEFT_MIDDLE,
    IMAGO_COCOON_OAM_VINE_RIGHT_MIDDLE,
    IMAGO_COCOON_OAM_VINE_LEFT_RIGHT,
    IMAGO_COCOON_OAM_VINE_RIGT_RIGHT,
    IMAGO_COCOON_OAM_VINE_LEFT_LEFT,
    IMAGO_COCOON_OAM_VINE_RIGHT_LEFT,
    IMAGO_COCOON_OAM_IDLE,
    IMAGO_COCOON_OAM_2e0bb0,
    IMAGO_COCOON_OAM_STATIC,
    IMAGO_COCOON_OAM_SPORE_SPAWNING,
    IMAGO_COCOON_OAM_SPORE_NEST,
    IMAGO_COCOON_OAM_SPORE_MOVING,
    IMAGO_COCOON_OAM_SPORE_EXPLODING,
    IMAGO_COCOON_OAM_WINGED_RIPPER_MOVING,
    IMAGO_COCOON_OAM_WINGED_RIPPER_TURNING_AROUND,
    IMAGO_COCOON_OAM_DEFEATED_COCOON,

    IMAGO_COCOON_OAM_END
};

extern const struct MultiSpriteData sImagoCocoonMultiSpriteData_Idle[5];

extern const struct MultiSpriteData sImagoCocoonMultiSpriteData_Dying[10];

extern const s16 sImagoCocoon_ArrayUnused1[36];

extern const s16 sImagoCocoon_ArrayUnused2[48];

extern const u32 sImagoCocoonGfx[1758];
extern const u16 sImagoCocoonPal[96];

extern const struct FrameData sImagoCocoonOam_CeilingVineMotionless[5];

extern const struct FrameData sImagoCocoonOam_CeilingVineMoving[10];

extern const struct FrameData sImagoCocoonOam_CeilingVineBroken[2];

extern const struct FrameData sImagoCocoonOam_DecorativeVinesLeft[6];

extern const struct FrameData sImagoCocoonOam_DecorativeVinesRight[6];

extern const struct FrameData sImagoCocoonVineOam_LeftMiddle[5];

extern const struct FrameData sImagoCocoonVineOam_RightMiddle[5];

extern const struct FrameData sImagoCocoonVineOam_LeftRight[5];

extern const struct FrameData sImagoCocoonVineOam_RightRight[5];

extern const struct FrameData sImagoCocoonVineOam_LeftLeft[5];

extern const struct FrameData sImagoCocoonVineOam_RightLeft[5];

extern const struct FrameData sImagoCocoonOam_Idle[5];

extern const struct FrameData sImagoCocoonOam_2e0bb0[2];

extern const struct FrameData sImagoCocoonOam_Static[2];

extern const struct FrameData sImagoCocoonSporeOam_Spawning[5];

extern const struct FrameData sImagoCocoonSpore_Nest[4];

extern const struct FrameData sImagoCocoonSpore_Moving[4];

extern const struct FrameData sImagoCocoonSpore_Exploding[5];

extern const struct FrameData sWingedRipperOam_Moving[10];

extern const struct FrameData sWingedRipperOam_TurningAround[10];

extern const struct FrameData sDefeatedImagoCocoonOam[9];

#endif /* IMAGO_COCOON_DATA_H */
