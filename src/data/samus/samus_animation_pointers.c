#include "data/samus/samus_animation_pointers.h"

#include "data/samus/samus_graphics.h"
#include "data/samus/arm_cannon_data.h"
#include "data/samus/samus_palette_data.h"
#include "data/visual_effects_data.h"

#include "constants/samus.h"

const struct EnvironmentalEffect sEnvironmentalEffect_Empty = {
    .type = ENV_EFFECT_NONE,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .breathingTimer = 0,
    .xPosition = 0,
    .yPosition = 0,
    .pOamFrame = NULL
};

// Power suit

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit[SPOSE_END][2] = {
    [SPOSE_RUNNING] = {
        sSamusAnim_PowerSuit_Right_Running,
        sSamusAnim_PowerSuit_Left_Running
    },
    [SPOSE_STANDING] = {
        sSamusAnim_PowerSuit_Right_Standing,
        sSamusAnim_PowerSuit_Left_Standing
    },
    [SPOSE_TURNING_AROUND] = {
        sSamusAnim_PowerSuit_Right_TurningAround,
        sSamusAnim_PowerSuit_Left_TurningAround
    },
    [SPOSE_SHOOTING] = {
        sSamusAnim_PowerSuit_Right_Shooting,
        sSamusAnim_PowerSuit_Left_Shooting
    },
    [SPOSE_CROUCHING] = {
        sSamusAnim_PowerSuit_Right_Crouching,
        sSamusAnim_PowerSuit_Left_Crouching
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        sSamusAnim_PowerSuit_Right_TurningAroundAndCrouching,
        sSamusAnim_PowerSuit_Left_TurningAroundAndCrouching
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        sSamusAnim_PowerSuit_Right_ShootingAndCrouching,
        sSamusAnim_PowerSuit_Left_ShootingAndCrouching
    },
    [SPOSE_SKIDDING] = {
        sSamusAnim_PowerSuit_Right_Skidding,
        sSamusAnim_PowerSuit_Left_Skidding
    },
    [SPOSE_MIDAIR] = {
        sSamusAnim_PowerSuit_Right_MidAir,
        sSamusAnim_PowerSuit_Left_MidAir
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        sSamusAnim_PowerSuit_Right_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_TurningAroundMidAir
    },
    [SPOSE_LANDING] = {
        sSamusAnim_PowerSuit_Right_Landing,
        sSamusAnim_PowerSuit_Left_Landing
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        sSamusAnim_PowerSuit_Right_StartingSpinJump,
        sSamusAnim_PowerSuit_Left_StartingSpinJump
    },
    [SPOSE_SPINNING] = {
        sSamusAnim_PowerSuit_Right_Spinning,
        sSamusAnim_PowerSuit_Left_Spinning
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        sSamusAnim_PowerSuit_Right_StartingWallJump,
        sSamusAnim_PowerSuit_Left_StartingWallJump
    },
    [SPOSE_SPACE_JUMPING] = {
        sSamusAnim_PowerSuit_Right_SpaceJumping,
        sSamusAnim_PowerSuit_Left_SpaceJumping
    },
    [SPOSE_SCREW_ATTACKING] = {
        sSamusAnim_PowerSuit_Right_ScrewAttacking,
        sSamusAnim_PowerSuit_Left_ScrewAttacking
    },
    [SPOSE_MORPHING] = {
        sSamusAnim_PowerSuit_Right_Morphing,
        sSamusAnim_PowerSuit_Left_Morphing
    },
    [SPOSE_MORPH_BALL] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_ROLLING] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_UNMORPHING] = {
        sSamusAnim_PowerSuit_Right_Unmorphing,
        sSamusAnim_PowerSuit_Left_Unmorphing
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        sSamusAnim_PowerSuit_Right_HangingOnLedge,
        sSamusAnim_PowerSuit_Left_HangingOnLedge
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        sSamusAnim_PowerSuit_Right_TurningToAimWhileHanging,
        sSamusAnim_PowerSuit_Left_TurningToAimWhileHanging
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        sSamusAnim_PowerSuit_Right_TurningToAimWhileHanging,
        sSamusAnim_PowerSuit_Left_TurningToAimWhileHanging
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        sSamusAnim_PowerSuit_Right_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_AimingWhileHanging
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        sSamusAnim_PowerSuit_Right_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_ShootingWhileHanging
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        sSamusAnim_PowerSuit_Right_PullingYourselfUpFromHanging,
        sSamusAnim_PowerSuit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        sSamusAnim_PowerSuit_Right_PullingYourselfForwardFromHanging,
        sSamusAnim_PowerSuit_Left_PullingYourselfForwardFromHanging
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        sSamusAnim_PowerSuit_Right_PullingYourselfUpFromHanging,
        sSamusAnim_PowerSuit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        sSamusAnim_PowerSuit_UsingAnElevator,
        sSamusAnim_PowerSuit_UsingAnElevator
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        sSamusAnim_PowerSuit_FacingTheForeground,
        sSamusAnim_PowerSuit_FacingTheForeground
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        sSamusAnim_PowerSuit_Right_TurningFromFacingTheForeground,
        sSamusAnim_PowerSuit_Left_TurningFromFacingTheForeground
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        sSamusAnim_PowerSuit_MorphballMotioness,
        sSamusAnim_PowerSuit_MorphballMotioness
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        sSamusAnim_PowerSuit_Right_DelayBeforeShinesparking,
        sSamusAnim_PowerSuit_Left_DelayBeforeShinesparking
    },
    [SPOSE_SHINESPARKING] = {
        sSamusAnim_PowerSuit_Right_Shinesparking,
        sSamusAnim_PowerSuit_Left_Shinesparking
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        sSamusAnim_PowerSuit_Right_Shinesparking,
        sSamusAnim_PowerSuit_Left_Shinesparking
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        sSamusAnim_PowerSuit_Right_DelayAfterShinesparking,
        sSamusAnim_PowerSuit_Left_DelayAfterShinesparking
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        sSamusAnim_PowerSuit_MorphballMotioness,
        sSamusAnim_PowerSuit_MorphballMotioness
    },
    [SPOSE_BALLSPARKING] = {
        sSamusAnim_PowerSuit_Right_Ballsparking,
        sSamusAnim_PowerSuit_Left_Ballsparking
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_ON_ZIPLINE] = {
        sSamusAnim_PowerSuit_Right_OnZipline,
        sSamusAnim_PowerSuit_Left_OnZipline
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        sSamusAnim_PowerSuit_Right_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_ShootingOnZipline
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        sSamusAnim_PowerSuit_Right_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_TurningOnZipline
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        sSamusAnim_PowerSuit_MorphballMotioness,
        sSamusAnim_PowerSuit_MorphballMotioness
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        sSamusAnim_PowerSuit_SavingLoadingGame,
        sSamusAnim_PowerSuit_SavingLoadingGame
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        sSamusAnim_PowerSuit_DownloadingMapData,
        sSamusAnim_PowerSuit_DownloadingMapData
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        sSamusAnim_PowerSuit_Right_TurningAround,
        sSamusAnim_PowerSuit_Left_TurningAround
    },
    [SPOSE_GETTING_HURT] = {
        sSamusAnim_PowerSuit_Right_GettingKnockedBack,
        sSamusAnim_PowerSuit_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        sSamusAnim_PowerSuit_Right_GettingKnockedBack,
        sSamusAnim_PowerSuit_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        sSamusAnim_PowerSuit_Right_Morphball,
        sSamusAnim_PowerSuit_Left_Morphball
    },
    [SPOSE_DYING] = {
        sSamusAnim_PowerSuit_Right_Dying,
        sSamusAnim_PowerSuit_Left_Dying
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_CrouchingToCrawl,
        sSamusAnim_Suitless_Left_CrouchingToCrawl
    },
    [SPOSE_CRAWLING_STOPPED] = {
        sSamusAnim_Suitless_Right_CrawlingStopped,
        sSamusAnim_Suitless_Left_CrawlingStopped
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_StartingToCrawl,
        sSamusAnim_Suitless_Left_StartingToCrawl
    },
    [SPOSE_CRAWLING] = {
        sSamusAnim_Suitless_Right_Crawling,
        sSamusAnim_Suitless_Left_Crawling
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        sSamusAnim_Suitless_Right_UncrouchingFromCrawling,
        sSamusAnim_Suitless_Left_UncrouchingFromCrawling
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_TurningAroundWhileCrawling,
        sSamusAnim_Suitless_Left_TurningAroundWhileCrawling
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_ShootingWhileCrawling,
        sSamusAnim_Suitless_Left_ShootingWhileCrawling
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_UncrouchingSuitless
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_CrouchingSuitless,
        sSamusAnim_Suitless_Left_CrouchingSuitless
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        sSamusAnim_Suitless_Right_HangingOnLedgeSuitless,
        sSamusAnim_Suitless_Left_HangingOnLedgeSuitless
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_FacingTheBackground,
        sSamusAnim_Suitless_FacingTheBackground
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_Right_TurningFromFacingTheBackground,
        sSamusAnim_Suitless_Left_TurningFromFacingTheBackground
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        sSamusAnim_PowerSuit_MorphballMotioness,
        sSamusAnim_PowerSuit_MorphballMotioness
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        sSamusAnim_PowerSuit_Right_Crouching,
        sSamusAnim_PowerSuit_Left_Crouching
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        sSamusAnim_PowerSuit_Right_TurningAround,
        sSamusAnim_PowerSuit_Left_TurningAround
    }
};


const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Running[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Forward_Running,
        sSamusAnim_PowerSuit_Left_Forward_Running
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Running,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Running
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Running,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Running
    },
    [ACD_NONE - 2] = {
        sSamusAnim_PowerSuit_Right_Running,
        sSamusAnim_PowerSuit_Left_Running
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Running_Speedboosting[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Forward_Running_Speedboosting,
        sSamusAnim_PowerSuit_Left_Forward_Running_Speedboosting
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Running_Speedboosting,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Running_Speedboosting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Running_Speedboosting,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Running_Speedboosting
    },
    [ACD_NONE - 2] = {
        sSamusAnim_PowerSuit_Right_Running_Speedboosting,
        sSamusAnim_PowerSuit_Left_Running_Speedboosting
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Standing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Standing,
        sSamusAnim_PowerSuit_Left_Standing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Standing,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Standing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Standing,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Standing
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_Standing,
        sSamusAnim_PowerSuit_Left_Up_Standing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAround[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_TurningAround,
        sSamusAnim_PowerSuit_Left_TurningAround
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAround,
        sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAround
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAround,
        sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAround
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_TurningAround,
        sSamusAnim_PowerSuit_Left_Up_TurningAround
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Shooting[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Shooting,
        sSamusAnim_PowerSuit_Left_Shooting
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Shooting,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Shooting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Shooting,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Shooting
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_Shooting,
        sSamusAnim_PowerSuit_Left_Up_Shooting
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Crouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Crouching,
        sSamusAnim_PowerSuit_Left_Crouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Crouching,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Crouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Crouching,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Crouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAroundAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_TurningAroundAndCrouching,
        sSamusAnim_PowerSuit_Left_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAroundAndCrouching,
        sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAroundAndCrouching,
        sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAroundAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_ShootingAndCrouching,
        sSamusAnim_PowerSuit_Left_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_ShootingAndCrouching,
        sSamusAnim_PowerSuit_Left_DiagonalUp_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingAndCrouching,
        sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Skidding[2][2] = {
    [FALSE] = {
        sSamusAnim_PowerSuit_Right_Skidding,
        sSamusAnim_PowerSuit_Left_Skidding
    },
    [TRUE] = {
        sSamusAnim_PowerSuit_Right_Armed_Skidding,
        sSamusAnim_PowerSuit_Left_Armed_Skidding
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_MidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_MidAir,
        sSamusAnim_PowerSuit_Left_MidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_MidAir,
        sSamusAnim_PowerSuit_Left_DiagonalUp_MidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_MidAir,
        sSamusAnim_PowerSuit_Left_DiagonalDown_MidAir
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_MidAir,
        sSamusAnim_PowerSuit_Left_Up_MidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_MidAir,
        sSamusAnim_PowerSuit_Left_Down_MidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAroundMidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAroundMidAir
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_Up_TurningAroundMidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_TurningAroundMidAir,
        sSamusAnim_PowerSuit_Left_Down_TurningAroundMidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Landing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_Landing,
        sSamusAnim_PowerSuit_Left_Landing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_Landing,
        sSamusAnim_PowerSuit_Left_DiagonalUp_Landing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_Landing,
        sSamusAnim_PowerSuit_Left_DiagonalDown_Landing
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_Landing,
        sSamusAnim_PowerSuit_Left_Up_Landing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ScrewAttacking[2][2] = {
    [FALSE] = {
        sSamusAnim_PowerSuit_Right_ScrewAttacking,
        sSamusAnim_PowerSuit_Left_ScrewAttacking
    },
    [TRUE] = {
        sSamusAnim_PowerSuit_Right_SpaceJumping,
        sSamusAnim_PowerSuit_Left_SpaceJumping
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_AimingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_AimingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_DiagonalUp_AimingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_DiagonalDown_AimingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_Up_AimingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_AimingWhileHanging,
        sSamusAnim_PowerSuit_Left_Down_AimingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_DiagonalUp_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_DiagonalUp_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_Up_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_Up_ShootingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_ShootingWhileHanging,
        sSamusAnim_PowerSuit_Left_Down_ShootingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_UsingAnElevator[2][2] = {
    [FALSE] = {
        sSamusAnim_PowerSuit_UsingAnElevator,
        sSamusAnim_PowerSuit_UsingAnElevator
    },
    [TRUE] = {
        sSamusAnim_PowerSuit_GoingUp_UsingAnElevator,
        sSamusAnim_PowerSuit_GoingUp_UsingAnElevator
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Shinesparking[3][2] = {
    [FORCED_MOVEMENT_UPWARDS_SHINESPARK] = {
        sSamusAnim_PowerSuit_Right_Shinesparking,
        sSamusAnim_PowerSuit_Left_Shinesparking
    },
    [FORCED_MOVEMENT_SIDEWARDS_SHINESPARK] = {
        sSamusAnim_PowerSuit_Right_Sidewards_Shinesparking,
        sSamusAnim_PowerSuit_Left_Sidewards_Shinesparking
    },
    [FORCED_MOVEMENT_DIAGONAL_SHINESPARK] = {
        sSamusAnim_PowerSuit_Right_Sidewards_Shinesparking,
        sSamusAnim_PowerSuit_Left_Sidewards_Shinesparking
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_OnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_OnZipline,
        sSamusAnim_PowerSuit_Left_OnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_OnZipline,
        sSamusAnim_PowerSuit_Left_OnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_OnZipline,
        sSamusAnim_PowerSuit_Left_DiagonalDown_OnZipline
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_OnZipline,
        sSamusAnim_PowerSuit_Left_OnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_OnZipline,
        sSamusAnim_PowerSuit_Left_Down_OnZipline
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingOnZipline
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_ShootingOnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_ShootingOnZipline,
        sSamusAnim_PowerSuit_Left_Down_ShootingOnZipline
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_PowerSuit_Right_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_PowerSuit_Right_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_PowerSuit_Right_DiagonalDown_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_DiagonalDown_TurningOnZipline
    },
    [ACD_UP] = {
        sSamusAnim_PowerSuit_Right_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_TurningOnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_PowerSuit_Right_Down_TurningOnZipline,
        sSamusAnim_PowerSuit_Left_Down_TurningOnZipline
    }
};


const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_All[SPOSE_END][2] = {
    [SPOSE_RUNNING] = {
        sArmCannonAnim_Suit_Right_None_Running,
        sArmCannonAnim_Suit_Left_None_Running
    },
    [SPOSE_STANDING] = {
        sArmCannonAnim_Suit_Right_Standing,
        sArmCannonAnim_Suit_Left_Standing
    },
    [SPOSE_TURNING_AROUND] = {
        sArmCannonAnim_Suit_Right_TurningAround,
        sArmCannonAnim_Suit_Left_TurningAround
    },
    [SPOSE_SHOOTING] = {
        sArmCannonAnim_Suit_Right_Shooting,
        sArmCannonAnim_Suit_Left_Shooting
    },
    [SPOSE_CROUCHING] = {
        sArmCannonAnim_Suit_Right_Crouching,
        sArmCannonAnim_Suit_Left_Crouching
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        sArmCannonAnim_Suit_Right_TurningAroundAndCrouching,
        sArmCannonAnim_Suit_Left_TurningAroundAndCrouching
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        sArmCannonAnim_Suit_Right_ShootingAndCrouching,
        sArmCannonAnim_Suit_Left_ShootingAndCrouching
    },
    [SPOSE_SKIDDING] = {
        sArmCannonAnim_Suit_Right_Skidding,
        sArmCannonAnim_Suit_Left_Skidding
    },
    [SPOSE_MIDAIR] = {
        sArmCannonAnim_Suit_Right_MidAir,
        sArmCannonAnim_Suit_Left_MidAir
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        sArmCannonAnim_Suit_Right_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_TurningAroundMidAir
    },
    [SPOSE_LANDING] = {
        sArmCannonAnim_Suit_Right_Landing,
        sArmCannonAnim_Suit_Left_Landing
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        sArmCannonAnim_Suit_Right_StartingSpinJump,
        sArmCannonAnim_Suit_Left_StartingSpinJump
    },
    [SPOSE_SPINNING] = {
        sArmCannonAnim_Suit_Right_Spinning,
        sArmCannonAnim_Suit_Left_Spinning
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        sArmCannonAnim_Suit_Right_StartingWallJump,
        sArmCannonAnim_Suit_Left_StartingWallJump
    },
    [SPOSE_SPACE_JUMPING] = {
        sArmCannonAnim_Suit_Right_SpaceJumping,
        sArmCannonAnim_Suit_Left_SpaceJumping
    },
    [SPOSE_SCREW_ATTACKING] = {
        sArmCannonAnim_Suit_Right_ScrewAttacking,
        sArmCannonAnim_Suit_Left_ScrewAttacking
    },
    [SPOSE_MORPHING] = {
        sArmCannonAnim_Suit_Right_Morphing,
        sArmCannonAnim_Suit_Left_Morphing
    },
    [SPOSE_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_ROLLING] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_UNMORPHING] = {
        sArmCannonAnim_Suit_Right_Unmorphing,
        sArmCannonAnim_Suit_Left_Unmorphing
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        sArmCannonAnim_Suit_Right_HangingOnLedge,
        sArmCannonAnim_Suit_Left_HangingOnLedge
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        sArmCannonAnim_Suit_Right_TurningToAimWhileHanging,
        sArmCannonAnim_Suit_Left_TurningToAimWhileHanging
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        sArmCannonAnim_Suit_Right_TurningToAimWhileHanging,
        sArmCannonAnim_Suit_Left_TurningToAimWhileHanging
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        sArmCannonAnim_Suit_Right_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_AimingWhileHanging
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        sArmCannonAnim_Suit_Right_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_ShootingWhileHanging
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        sArmCannonAnim_Suit_Right_PullingYourselfUpFromHanging,
        sArmCannonAnim_Suit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        sArmCannonAnim_Suit_Right_PullingYourselfForwardFromHanging,
        sArmCannonAnim_Suit_Left_PullingYourselfForwardFromHanging
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        sArmCannonAnim_Suit_Right_PullingYourselfUpFromHanging,
        sArmCannonAnim_Suit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        sArmCannonAnim_Suit_UsingAnElevator,
        sArmCannonAnim_Suit_UsingAnElevator
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        sArmCannonAnim_Suit_FacingTheForeground,
        sArmCannonAnim_Suit_FacingTheForeground
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        sArmCannonAnim_Suit_Right_TurningFromFacingTheForeground,
        sArmCannonAnim_Suit_Left_TurningFromFacingTheForeground
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_DelayBeforeShinesparking,
        sArmCannonAnim_Suit_Left_DelayBeforeShinesparking
    },
    [SPOSE_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_Shinesparking,
        sArmCannonAnim_Suit_Left_Shinesparking
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        sArmCannonAnim_Suit_Right_Shinesparking,
        sArmCannonAnim_Suit_Left_Shinesparking
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_DelayAfterShinesparking,
        sArmCannonAnim_Suit_Left_DelayAfterShinesparking
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_BALLSPARKING] = {
        sArmCannonAnim_Suit_Right_Ballsparking,
        sArmCannonAnim_Suit_Left_Ballsparking
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_OnZipline,
        sArmCannonAnim_Suit_Left_OnZipline
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_ShootingOnZipline
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_TurningOnZipline,
        sArmCannonAnim_Suit_Left_TurningOnZipline
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        sArmCannonAnim_Suit_SavingLoadingGame,
        sArmCannonAnim_Suit_SavingLoadingGame
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        sArmCannonAnim_Suit_DownloadingMapData,
        sArmCannonAnim_Suit_DownloadingMapData
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        sArmCannonAnim_Suit_Right_TurningAround,
        sArmCannonAnim_Suit_Left_TurningAround
    },
    [SPOSE_GETTING_HURT] = {
        sArmCannonAnim_Suit_Right_GettingHurt,
        sArmCannonAnim_Suit_Left_GettingHurt
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        sArmCannonAnim_Suit_Right_GettingHurt,
        sArmCannonAnim_Suit_Left_GettingHurt
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_DYING] = {
        sArmCannonAnim_Suit_Dying,
        sArmCannonAnim_Suit_Dying
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        sArmCannonAnim_Suitless_Right_CrouchingToCrawl,
        sArmCannonAnim_Suitless_Left_CrouchingToCrawl
    },
    [SPOSE_CRAWLING_STOPPED] = {
        sArmCannonAnim_Suitless_Right_CrawlingStopped,
        sArmCannonAnim_Suitless_Left_CrawlingStopped
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        sArmCannonAnim_Suitless_Right_StartingToCrawl,
        sArmCannonAnim_Suitless_Left_StartingToCrawl
    },
    [SPOSE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_Crawling,
        sArmCannonAnim_Suitless_Left_Crawling
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_UncrouchingFromCrawling,
        sArmCannonAnim_Suitless_Left_UncrouchingFromCrawling
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_TurningAroundWhileCrawling,
        sArmCannonAnim_Suitless_Left_TurningAroundWhileCrawling
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_ShootingWhileCrawling,
        sArmCannonAnim_Suitless_Left_ShootingWhileCrawling
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_UncrouchingSuitless
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_CrouchingSuitless,
        sArmCannonAnim_Suitless_Left_CrouchingSuitless
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_HangingOnLedgeSuitless,
        sArmCannonAnim_Suitless_Left_HangingOnLedgeSuitless
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        sArmCannonAnim_Suitless_FacingTheBackground,
        sArmCannonAnim_Suitless_FacingTheBackground
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_TurningFromFacingTheBackground,
        sArmCannonAnim_Suitless_Left_TurningFromFacingTheBackground
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        sArmCannonAnim_Suit_Right_Crouching,
        sArmCannonAnim_Suit_Left_Crouching
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        sArmCannonAnim_Suit_Right_TurningAround,
        sArmCannonAnim_Suit_Left_TurningAround
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Running[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Forward_Running,
        sArmCannonAnim_Suit_Left_Forward_Running
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Running,
        sArmCannonAnim_Suit_Left_DiagonalUp_Running
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Running,
        sArmCannonAnim_Suit_Left_DiagonalDown_Running
    },
    [ACD_NONE - 2] = {
        sArmCannonAnim_Suit_Right_None_Running,
        sArmCannonAnim_Suit_Left_None_Running
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Running_Speedboosting[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Forward_Running_Speedboosting,
        sArmCannonAnim_Suit_Left_Forward_Running_Speedboosting
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Running_Speedboosting,
        sArmCannonAnim_Suit_Left_DiagonalUp_Running_Speedboosting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Running_Speedboosting,
        sArmCannonAnim_Suit_Left_DiagonalDown_Running_Speedboosting
    },
    [ACD_NONE - 2] = {
        sArmCannonAnim_Suit_Right_None_Running_Speedboosting,
        sArmCannonAnim_Suit_Left_None_Running_Speedboosting
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Standing[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Standing,
        sArmCannonAnim_Suit_Left_Standing
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Standing,
        sArmCannonAnim_Suit_Left_DiagonalUp_Standing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Standing,
        sArmCannonAnim_Suit_Left_DiagonalDown_Standing
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_Standing,
        sArmCannonAnim_Suit_Left_Up_Standing
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_TurningAround[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_TurningAround,
        sArmCannonAnim_Suit_Left_TurningAround
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_TurningAround,
        sArmCannonAnim_Suit_Left_DiagonalUp_TurningAround
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_TurningAround,
        sArmCannonAnim_Suit_Left_DiagonalDown_TurningAround
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_TurningAround,
        sArmCannonAnim_Suit_Left_Up_TurningAround
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Shooting[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Shooting,
        sArmCannonAnim_Suit_Left_Shooting
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Shooting,
        sArmCannonAnim_Suit_Left_DiagonalUp_Shooting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Shooting,
        sArmCannonAnim_Suit_Left_DiagonalDown_Shooting
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_Shooting,
        sArmCannonAnim_Suit_Left_Up_Shooting
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Crouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Crouching,
        sArmCannonAnim_Suit_Left_Crouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Crouching,
        sArmCannonAnim_Suit_Left_DiagonalUp_Crouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Crouching,
        sArmCannonAnim_Suit_Left_DiagonalDown_Crouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_TurningAroundAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_TurningAroundAndCrouching,
        sArmCannonAnim_Suit_Left_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_TurningAroundAndCrouching,
        sArmCannonAnim_Suit_Left_DiagonalUp_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_TurningAroundAndCrouching,
        sArmCannonAnim_Suit_Left_DiagonalDown_TurningAroundAndCrouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_ShootingAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_ShootingAndCrouching,
        sArmCannonAnim_Suit_Left_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_ShootingAndCrouching,
        sArmCannonAnim_Suit_Left_DiagonalUp_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_ShootingAndCrouching,
        sArmCannonAnim_Suit_Left_DiagonalDown_ShootingAndCrouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Skidding[2][2] = {
    [FALSE] = {
        sArmCannonAnim_Suit_Right_Skidding,
        sArmCannonAnim_Suit_Left_Skidding
    },
    [TRUE] = {
        sArmCannonAnim_Suit_Right_Armed_Skidding,
        sArmCannonAnim_Suit_Left_Armed_Skidding
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_MidAir[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_MidAir,
        sArmCannonAnim_Suit_Left_MidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_MidAir,
        sArmCannonAnim_Suit_Left_DiagonalUp_MidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_MidAir,
        sArmCannonAnim_Suit_Left_DiagonalDown_MidAir
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_MidAir,
        sArmCannonAnim_Suit_Left_Up_MidAir
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_MidAir,
        sArmCannonAnim_Suit_Left_Down_MidAir
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_TurningAroundMidAir[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_DiagonalUp_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_DiagonalDown_TurningAroundMidAir
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_Up_TurningAroundMidAir
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_TurningAroundMidAir,
        sArmCannonAnim_Suit_Left_Down_TurningAroundMidAir
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Landing[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_Landing,
        sArmCannonAnim_Suit_Left_Landing
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_Landing,
        sArmCannonAnim_Suit_Left_DiagonalUp_Landing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_Landing,
        sArmCannonAnim_Suit_Left_DiagonalDown_Landing
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_Landing,
        sArmCannonAnim_Suit_Left_Up_Landing
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_AimingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_AimingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_DiagonalUp_AimingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_DiagonalDown_AimingWhileHanging
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_Up_AimingWhileHanging
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_AimingWhileHanging,
        sArmCannonAnim_Suit_Left_Down_AimingWhileHanging
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_ShootingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_DiagonalUp_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_DiagonalUp_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_DiagonalDown_ShootingWhileHanging
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_Up_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_Up_ShootingWhileHanging
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_ShootingWhileHanging,
        sArmCannonAnim_Suit_Left_Down_ShootingWhileHanging
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_UsingAnElevator[2][2] = {
    [FALSE] = {
        sArmCannonAnim_Suit_UsingAnElevator,
        sArmCannonAnim_Suit_UsingAnElevator
    },
    [TRUE] = {
        sArmCannonAnim_Suit_GoingUp_UsingAnElevator,
        sArmCannonAnim_Suit_GoingUp_UsingAnElevator
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_Shinesparking[3][2] = {
    [FORCED_MOVEMENT_UPWARDS_SHINESPARK] = {
        sArmCannonAnim_Suit_Right_Shinesparking,
        sArmCannonAnim_Suit_Left_Shinesparking
    },
    [FORCED_MOVEMENT_SIDEWARDS_SHINESPARK] = {
        sArmCannonAnim_Suit_Right_Sidewards_Shinesparking,
        sArmCannonAnim_Suit_Left_Sidewards_Shinesparking
    },
    [FORCED_MOVEMENT_DIAGONAL_SHINESPARK] = {
        sArmCannonAnim_Suit_Right_Sidewards_Shinesparking,
        sArmCannonAnim_Suit_Left_Sidewards_Shinesparking
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_OnZipline[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_OnZipline,
        sArmCannonAnim_Suit_Left_OnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_OnZipline,
        sArmCannonAnim_Suit_Left_OnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_OnZipline,
        sArmCannonAnim_Suit_Left_DiagonalDown_OnZipline
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_OnZipline,
        sArmCannonAnim_Suit_Left_OnZipline
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_OnZipline,
        sArmCannonAnim_Suit_Left_Down_OnZipline
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_ShootingOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_DiagonalDown_ShootingOnZipline
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_ShootingOnZipline
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_Down_ShootingOnZipline
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suit_TurningOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suit_Right_TurningOnZipline,
        sArmCannonAnim_Suit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suit_Right_TurningOnZipline,
        sArmCannonAnim_Suit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suit_Right_DiagonalDown_TurningOnZipline,
        sArmCannonAnim_Suit_Left_DiagonalDown_TurningOnZipline
    },
    [ACD_UP] = {
        sArmCannonAnim_Suit_Right_TurningOnZipline,
        sArmCannonAnim_Suit_Left_TurningOnZipline
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suit_Right_Down_TurningOnZipline,
        sArmCannonAnim_Suit_Left_Down_TurningOnZipline
    }
};


const u8 sSamusVisualData[SPOSE_END][3] = {
    [SPOSE_RUNNING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_STANDING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_TURNING_AROUND] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_SHOOTING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_CROUCHING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_GROUND
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_GROUND
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_GROUND
    },
    [SPOSE_SKIDDING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_MIDAIR] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_LANDING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_MIDAIR
    },
    [SPOSE_SPINNING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_MIDAIR
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_MIDAIR
    },
    [SPOSE_SPACE_JUMPING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_MIDAIR
    },
    [SPOSE_SCREW_ATTACKING] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_MIDAIR
    },
    [SPOSE_MORPHING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_MORPH_BALL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_ROLLING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_UNMORPHING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_MIDAIR
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_FORCED_POSE
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_FORCED_POSE
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_SHINESPARKING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_MIDAIR
    },
    [SPOSE_BALLSPARKING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_MIDAIR
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_FORCED_POSE
    },
    [SPOSE_ON_ZIPLINE] = {
        SAMUS_HITBOX_TYPE_ZIPLINE, SAMUS_HITBOX_TYPE_STANDING, STANDING_NOT_IN_CONTROL
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        SAMUS_HITBOX_TYPE_ZIPLINE, SAMUS_HITBOX_TYPE_STANDING, STANDING_NOT_IN_CONTROL
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        SAMUS_HITBOX_TYPE_ZIPLINE, SAMUS_HITBOX_TYPE_STANDING, STANDING_NOT_IN_CONTROL
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_NOT_IN_CONTROL
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_GETTING_HURT] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_MIDAIR
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_MIDAIR
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_MIDAIR
    },
    [SPOSE_DYING] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_CRAWLING_STOPPED] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_CRAWLING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_GROUND
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_HANGING
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_GROUND
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        SAMUS_HITBOX_TYPE_MORPHED, SAMUS_HITBOX_TYPE_MORPHED, STANDING_GROUND
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        SAMUS_HITBOX_TYPE_STANDING, SAMUS_HITBOX_TYPE_STANDING, STANDING_FORCED_POSE
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        SAMUS_HITBOX_TYPE_CROUCHED, SAMUS_HITBOX_TYPE_CROUCHED, STANDING_FORCED_POSE
    }
};



// Full suit

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit[SPOSE_END][2] = {
    [SPOSE_RUNNING] = {
        sSamusAnim_FullSuit_Right_Running,
        sSamusAnim_FullSuit_Left_Running
    },
    [SPOSE_STANDING] = {
        sSamusAnim_FullSuit_Right_Standing,
        sSamusAnim_FullSuit_Left_Standing
    },
    [SPOSE_TURNING_AROUND] = {
        sSamusAnim_FullSuit_Right_TurningAround,
        sSamusAnim_FullSuit_Left_TurningAround
    },
    [SPOSE_SHOOTING] = {
        sSamusAnim_FullSuit_Right_Shooting,
        sSamusAnim_FullSuit_Left_Shooting
    },
    [SPOSE_CROUCHING] = {
        sSamusAnim_FullSuit_Right_Crouching,
        sSamusAnim_FullSuit_Left_Crouching
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        sSamusAnim_FullSuit_Right_TurningAroundAndCrouching,
        sSamusAnim_FullSuit_Left_TurningAroundAndCrouching
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        sSamusAnim_FullSuit_Right_ShootingAndCrouching,
        sSamusAnim_FullSuit_Left_ShootingAndCrouching
    },
    [SPOSE_SKIDDING] = {
        sSamusAnim_FullSuit_Right_Skidding,
        sSamusAnim_FullSuit_Left_Skidding
    },
    [SPOSE_MIDAIR] = {
        sSamusAnim_FullSuit_Right_MidAir,
        sSamusAnim_FullSuit_Left_MidAir
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        sSamusAnim_FullSuit_Right_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_TurningAroundMidAir
    },
    [SPOSE_LANDING] = {
        sSamusAnim_FullSuit_Right_Landing,
        sSamusAnim_FullSuit_Left_Landing
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        sSamusAnim_FullSuit_Right_StartingSpinJump,
        sSamusAnim_FullSuit_Left_StartingSpinJump
    },
    [SPOSE_SPINNING] = {
        sSamusAnim_FullSuit_Right_Spinning,
        sSamusAnim_FullSuit_Left_Spinning
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        sSamusAnim_FullSuit_Right_StartingWallJump,
        sSamusAnim_FullSuit_Left_StartingWallJump
    },
    [SPOSE_SPACE_JUMPING] = {
        sSamusAnim_FullSuit_Right_SpaceJumping,
        sSamusAnim_FullSuit_Left_SpaceJumping
    },
    [SPOSE_SCREW_ATTACKING] = {
        sSamusAnim_FullSuit_Right_ScrewAttacking,
        sSamusAnim_FullSuit_Left_ScrewAttacking
    },
    [SPOSE_MORPHING] = {
        sSamusAnim_FullSuit_Right_Morphing,
        sSamusAnim_FullSuit_Left_Morphing
    },
    [SPOSE_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_ROLLING] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_UNMORPHING] = {
        sSamusAnim_FullSuit_Right_Unmorphing,
        sSamusAnim_FullSuit_Left_Unmorphing
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        sSamusAnim_FullSuit_Right_HangingOnLedge,
        sSamusAnim_FullSuit_Left_HangingOnLedge
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        sSamusAnim_FullSuit_Right_TurningToAimWhileHanging,
        sSamusAnim_FullSuit_Left_TurningToAimWhileHanging
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        sSamusAnim_FullSuit_Right_TurningToAimWhileHanging,
        sSamusAnim_FullSuit_Left_TurningToAimWhileHanging
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        sSamusAnim_FullSuit_Right_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_AimingWhileHanging
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        sSamusAnim_FullSuit_Right_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_ShootingWhileHanging
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        sSamusAnim_FullSuit_Right_PullingYourselfUpFromHanging,
        sSamusAnim_FullSuit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        sSamusAnim_FullSuit_Right_PullingYourselfForwardFromHanging,
        sSamusAnim_FullSuit_Left_PullingYourselfForwardFromHanging
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        sSamusAnim_FullSuit_Right_PullingYourselfUpFromHanging,
        sSamusAnim_FullSuit_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        sSamusAnim_FullSuit_UsingAnElevator,
        sSamusAnim_FullSuit_UsingAnElevator
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        sSamusAnim_FullSuit_FacingTheForeground,
        sSamusAnim_FullSuit_FacingTheForeground
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        sSamusAnim_FullSuit_Right_TurningFromFacingTheForeground,
        sSamusAnim_FullSuit_Left_TurningFromFacingTheForeground
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_DelayBeforeShinesparking,
        sSamusAnim_FullSuit_Left_DelayBeforeShinesparking
    },
    [SPOSE_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_Shinesparking,
        sSamusAnim_FullSuit_Left_Shinesparking
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        sSamusAnim_FullSuit_Right_Shinesparking,
        sSamusAnim_FullSuit_Left_Shinesparking
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_DelayAfterShinesparking,
        sSamusAnim_FullSuit_Left_DelayAfterShinesparking
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_BALLSPARKING] = {
        sSamusAnim_FullSuit_Right_Ballsparking,
        sSamusAnim_FullSuit_Left_Ballsparking
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_OnZipline,
        sSamusAnim_FullSuit_Left_OnZipline
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_ShootingOnZipline
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_TurningOnZipline,
        sSamusAnim_FullSuit_Left_TurningOnZipline
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        sSamusAnim_FullSuit_SavingLoadingGame,
        sSamusAnim_FullSuit_SavingLoadingGame
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        sSamusAnim_FullSuit_DownloadingMapData,
        sSamusAnim_FullSuit_DownloadingMapData
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        sSamusAnim_FullSuit_Right_TurningAround,
        sSamusAnim_FullSuit_Left_TurningAround
    },
    [SPOSE_GETTING_HURT] = {
        sSamusAnim_FullSuit_Right_GettingKnockedBack,
        sSamusAnim_FullSuit_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        sSamusAnim_FullSuit_Right_GettingKnockedBack,
        sSamusAnim_FullSuit_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_DYING] = {
        sSamusAnim_FullSuit_Right_Dying,
        sSamusAnim_FullSuit_Left_Dying
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_CrouchingToCrawl,
        sSamusAnim_Suitless_Left_CrouchingToCrawl
    },
    [SPOSE_CRAWLING_STOPPED] = {
        sSamusAnim_Suitless_Right_CrawlingStopped,
        sSamusAnim_Suitless_Left_CrawlingStopped
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_StartingToCrawl,
        sSamusAnim_Suitless_Left_StartingToCrawl
    },
    [SPOSE_CRAWLING] = {
        sSamusAnim_Suitless_Right_Crawling,
        sSamusAnim_Suitless_Left_Crawling
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        sSamusAnim_Suitless_Right_UncrouchingFromCrawling,
        sSamusAnim_Suitless_Left_UncrouchingFromCrawling
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_TurningAroundWhileCrawling,
        sSamusAnim_Suitless_Left_TurningAroundWhileCrawling
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_ShootingWhileCrawling,
        sSamusAnim_Suitless_Left_ShootingWhileCrawling
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_UncrouchingSuitless
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_CrouchingSuitless,
        sSamusAnim_Suitless_Left_CrouchingSuitless
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        sSamusAnim_Suitless_Right_HangingOnLedgeSuitless,
        sSamusAnim_Suitless_Left_HangingOnLedgeSuitless
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_FacingTheBackground,
        sSamusAnim_Suitless_FacingTheBackground
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_Right_TurningFromFacingTheBackground,
        sSamusAnim_Suitless_Left_TurningFromFacingTheBackground
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        sSamusAnim_FullSuit_Right_Crouching,
        sSamusAnim_FullSuit_Left_Crouching
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        sSamusAnim_FullSuit_Right_TurningAround,
        sSamusAnim_FullSuit_Left_TurningAround
    }
};



const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Running[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Forward_Running,
        sSamusAnim_FullSuit_Left_Forward_Running
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Running,
        sSamusAnim_FullSuit_Left_DiagonalUp_Running
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Running,
        sSamusAnim_FullSuit_Left_DiagonalDown_Running
    },
    [ACD_NONE - 2] = {
        sSamusAnim_FullSuit_Right_Running,
        sSamusAnim_FullSuit_Left_Running
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Running_Speedboosting[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Forward_Running_Speedboosting,
        sSamusAnim_FullSuit_Left_Forward_Running_Speedboosting
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Running_Speedboosting,
        sSamusAnim_FullSuit_Left_DiagonalUp_Running_Speedboosting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Running_Speedboosting,
        sSamusAnim_FullSuit_Left_DiagonalDown_Running_Speedboosting
    },
    [ACD_NONE - 2] = {
        sSamusAnim_FullSuit_Right_Running_Speedboosting,
        sSamusAnim_FullSuit_Left_Running_Speedboosting
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Standing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Standing,
        sSamusAnim_FullSuit_Left_Standing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Standing,
        sSamusAnim_FullSuit_Left_DiagonalUp_Standing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Standing,
        sSamusAnim_FullSuit_Left_DiagonalDown_Standing
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_Standing,
        sSamusAnim_FullSuit_Left_Up_Standing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAround[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_TurningAround,
        sSamusAnim_FullSuit_Left_TurningAround
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_TurningAround,
        sSamusAnim_FullSuit_Left_DiagonalUp_TurningAround
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_TurningAround,
        sSamusAnim_FullSuit_Left_DiagonalDown_TurningAround
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_TurningAround,
        sSamusAnim_FullSuit_Left_Up_TurningAround
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Shooting[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Shooting,
        sSamusAnim_FullSuit_Left_Shooting
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Shooting,
        sSamusAnim_FullSuit_Left_DiagonalUp_Shooting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Shooting,
        sSamusAnim_FullSuit_Left_DiagonalDown_Shooting
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_Shooting,
        sSamusAnim_FullSuit_Left_Up_Shooting
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Crouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Crouching,
        sSamusAnim_FullSuit_Left_Crouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Crouching,
        sSamusAnim_FullSuit_Left_DiagonalUp_Crouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Crouching,
        sSamusAnim_FullSuit_Left_DiagonalDown_Crouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAroundAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_TurningAroundAndCrouching,
        sSamusAnim_FullSuit_Left_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_TurningAroundAndCrouching,
        sSamusAnim_FullSuit_Left_DiagonalUp_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_TurningAroundAndCrouching,
        sSamusAnim_FullSuit_Left_DiagonalDown_TurningAroundAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_ShootingAndCrouching,
        sSamusAnim_FullSuit_Left_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_ShootingAndCrouching,
        sSamusAnim_FullSuit_Left_DiagonalUp_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_ShootingAndCrouching,
        sSamusAnim_FullSuit_Left_DiagonalDown_ShootingAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Skidding[2][2] = {
    [FALSE] = {
        sSamusAnim_FullSuit_Right_Skidding,
        sSamusAnim_FullSuit_Left_Skidding
    },
    [TRUE] = {
        sSamusAnim_FullSuit_Right_Armed_Skidding,
        sSamusAnim_FullSuit_Left_Armed_Skidding
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_MidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_MidAir,
        sSamusAnim_FullSuit_Left_MidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_MidAir,
        sSamusAnim_FullSuit_Left_DiagonalUp_MidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_MidAir,
        sSamusAnim_FullSuit_Left_DiagonalDown_MidAir
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_MidAir,
        sSamusAnim_FullSuit_Left_Up_MidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_MidAir,
        sSamusAnim_FullSuit_Left_Down_MidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAroundMidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_DiagonalUp_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_DiagonalDown_TurningAroundMidAir
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_Up_TurningAroundMidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_Down_TurningAroundMidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Landing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_Landing,
        sSamusAnim_FullSuit_Left_Landing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_Landing,
        sSamusAnim_FullSuit_Left_DiagonalUp_Landing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_Landing,
        sSamusAnim_FullSuit_Left_DiagonalDown_Landing
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_Landing,
        sSamusAnim_FullSuit_Left_Up_Landing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ScrewAttacking[2][2] = {
    [FALSE] = {
        sSamusAnim_FullSuit_Right_ScrewAttacking,
        sSamusAnim_FullSuit_Left_ScrewAttacking
    },
    [TRUE] = {
        sSamusAnim_FullSuit_Right_SpaceJumping,
        sSamusAnim_FullSuit_Left_SpaceJumping
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_AimingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_AimingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_DiagonalUp_AimingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_DiagonalDown_AimingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_Up_AimingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_AimingWhileHanging,
        sSamusAnim_FullSuit_Left_Down_AimingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_DiagonalUp_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_DiagonalUp_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_DiagonalDown_ShootingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_Up_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_Up_ShootingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_ShootingWhileHanging,
        sSamusAnim_FullSuit_Left_Down_ShootingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_UsingAnElevator[2][2] = {
    [FALSE] = {
        sSamusAnim_FullSuit_UsingAnElevator,
        sSamusAnim_FullSuit_UsingAnElevator
    },
    [TRUE] = {
        sSamusAnim_FullSuit_GoingUp_UsingAnElevator,
        sSamusAnim_FullSuit_GoingUp_UsingAnElevator
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Shinesparking[3][2] = {
    [FORCED_MOVEMENT_UPWARDS_SHINESPARK] = {
        sSamusAnim_FullSuit_Right_Shinesparking,
        sSamusAnim_FullSuit_Left_Shinesparking
    },
    [FORCED_MOVEMENT_SIDEWARDS_SHINESPARK] = {
        sSamusAnim_FullSuit_Right_Sidewards_Shinesparking,
        sSamusAnim_FullSuit_Left_Sidewards_Shinesparking
    },
    [FORCED_MOVEMENT_DIAGONAL_SHINESPARK] = {
        sSamusAnim_FullSuit_Right_Sidewards_Shinesparking,
        sSamusAnim_FullSuit_Left_Sidewards_Shinesparking
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_OnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_OnZipline,
        sSamusAnim_FullSuit_Left_OnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_OnZipline,
        sSamusAnim_FullSuit_Left_OnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_OnZipline,
        sSamusAnim_FullSuit_Left_DiagonalDown_OnZipline
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_OnZipline,
        sSamusAnim_FullSuit_Left_OnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_OnZipline,
        sSamusAnim_FullSuit_Left_Down_OnZipline
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_ShootingOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_DiagonalDown_ShootingOnZipline
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_ShootingOnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_Down_ShootingOnZipline
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningOnZipline[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_FullSuit_Right_TurningOnZipline,
        sSamusAnim_FullSuit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_FullSuit_Right_TurningOnZipline,
        sSamusAnim_FullSuit_Left_TurningOnZipline
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_FullSuit_Right_DiagonalDown_TurningOnZipline,
        sSamusAnim_FullSuit_Left_DiagonalDown_TurningOnZipline
    },
    [ACD_UP] = {
        sSamusAnim_FullSuit_Right_TurningOnZipline,
        sSamusAnim_FullSuit_Left_TurningOnZipline
    },
    [ACD_DOWN] = {
        sSamusAnim_FullSuit_Right_Down_TurningOnZipline,
        sSamusAnim_FullSuit_Left_Down_TurningOnZipline
    }
};




// Suitless

const struct SamusAnimationData* const sSamusAnimPointers_Suitless[SPOSE_END][2] = {
    [SPOSE_RUNNING] = {
        sSamusAnim_Suitless_Right_Running,
        sSamusAnim_Suitless_Left_Running
    },
    [SPOSE_STANDING] = {
        sSamusAnim_Suitless_Right_Standing,
        sSamusAnim_Suitless_Left_Standing
    },
    [SPOSE_TURNING_AROUND] = {
        sSamusAnim_Suitless_Right_TurningAround,
        sSamusAnim_Suitless_Left_TurningAround
    },
    [SPOSE_SHOOTING] = {
        sSamusAnim_Suitless_Right_Shooting,
        sSamusAnim_Suitless_Left_Shooting
    },
    [SPOSE_CROUCHING] = {
        sSamusAnim_Suitless_Right_Crouching,
        sSamusAnim_Suitless_Left_Crouching
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        sSamusAnim_Suitless_Right_TurningAroundAndCrouching,
        sSamusAnim_Suitless_Left_TurningAroundAndCrouching
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        sSamusAnim_Suitless_Right_ShootingAndCrouching,
        sSamusAnim_Suitless_Left_ShootingAndCrouching
    },
    [SPOSE_SKIDDING] = {
        sSamusAnim_FullSuit_Right_Skidding,
        sSamusAnim_FullSuit_Left_Skidding
    },
    [SPOSE_MIDAIR] = {
        sSamusAnim_Suitless_Right_MidAir,
        sSamusAnim_Suitless_Left_MidAir
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        sSamusAnim_FullSuit_Right_TurningAroundMidAir,
        sSamusAnim_FullSuit_Left_TurningAroundMidAir
    },
    [SPOSE_LANDING] = {
        sSamusAnim_Suitless_Right_Landing,
        sSamusAnim_Suitless_Left_Landing
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        sSamusAnim_Suitless_Right_StartingSpinJump,
        sSamusAnim_Suitless_Left_StartingSpinJump
    },
    [SPOSE_SPINNING] = {
        sSamusAnim_Suitless_Right_Spinning,
        sSamusAnim_Suitless_Left_Spinning
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        sSamusAnim_Suitless_Left_StartingWallJump,
        sSamusAnim_Suitless_Right_StartingWallJump
    },
    [SPOSE_SPACE_JUMPING] = {
        sSamusAnim_FullSuit_Right_SpaceJumping,
        sSamusAnim_FullSuit_Left_SpaceJumping
    },
    [SPOSE_SCREW_ATTACKING] = {
        sSamusAnim_FullSuit_Right_ScrewAttacking,
        sSamusAnim_FullSuit_Left_ScrewAttacking
    },
    [SPOSE_MORPHING] = {
        sSamusAnim_FullSuit_Right_Morphing,
        sSamusAnim_FullSuit_Left_Morphing
    },
    [SPOSE_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_ROLLING] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_UNMORPHING] = {
        sSamusAnim_FullSuit_Right_Unmorphing,
        sSamusAnim_FullSuit_Left_Unmorphing
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        sSamusAnim_Suitless_Right_HangingOnLedge,
        sSamusAnim_Suitless_Left_HangingOnLedge
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        sSamusAnim_Suitless_Right_TurningToAimWhileHanging,
        sSamusAnim_Suitless_Left_TurningToAimWhileHanging
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        sSamusAnim_Suitless_Right_TurningToAimWhileHanging,
        sSamusAnim_Suitless_Left_TurningToAimWhileHanging
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        sSamusAnim_Suitless_Right_AimingWhileHanging,
        sSamusAnim_Suitless_Left_AimingWhileHanging
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        sSamusAnim_Suitless_Right_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_ShootingWhileHanging
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        sSamusAnim_Suitless_Right_PullingYourselfUpFromHanging,
        sSamusAnim_Suitless_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        sSamusAnim_Suitless_Right_PullingYourselfForwardFromHanging,
        sSamusAnim_Suitless_Left_PullingYourselfForwardFromHanging
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        sSamusAnim_Suitless_Right_PullingYourselfUpFromHanging,
        sSamusAnim_Suitless_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        sSamusAnim_FullSuit_UsingAnElevator,
        sSamusAnim_FullSuit_UsingAnElevator
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        sSamusAnim_Suitless_FacingTheForeground,
        sSamusAnim_Suitless_FacingTheForeground
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        sSamusAnim_Suitless_Right_TurningFromFacingTheForeground,
        sSamusAnim_Suitless_Left_TurningFromFacingTheForeground
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_DelayBeforeShinesparking,
        sSamusAnim_FullSuit_Left_DelayBeforeShinesparking
    },
    [SPOSE_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_Shinesparking,
        sSamusAnim_FullSuit_Left_Shinesparking
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        sSamusAnim_FullSuit_Right_Shinesparking,
        sSamusAnim_FullSuit_Left_Shinesparking
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        sSamusAnim_FullSuit_Right_DelayAfterShinesparking,
        sSamusAnim_FullSuit_Left_DelayAfterShinesparking
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_BALLSPARKING] = {
        sSamusAnim_FullSuit_Right_Ballsparking,
        sSamusAnim_FullSuit_Left_Ballsparking
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_OnZipline,
        sSamusAnim_FullSuit_Left_OnZipline
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_ShootingOnZipline,
        sSamusAnim_FullSuit_Left_ShootingOnZipline
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_Right_TurningOnZipline,
        sSamusAnim_FullSuit_Left_TurningOnZipline
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        sSamusAnim_Suitless_SavingLoadingGame,
        sSamusAnim_Suitless_SavingLoadingGame
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        sSamusAnim_Suitless_DownloadingMapData,
        sSamusAnim_Suitless_DownloadingMapData
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        sSamusAnim_Suitless_Right_TurningAround,
        sSamusAnim_Suitless_Left_TurningAround
    },
    [SPOSE_GETTING_HURT] = {
        sSamusAnim_Suitless_Right_GettingKnockedBack,
        sSamusAnim_Suitless_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        sSamusAnim_Suitless_Right_GettingKnockedBack,
        sSamusAnim_Suitless_Left_GettingKnockedBack
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        sSamusAnim_FullSuit_Right_Morphball,
        sSamusAnim_FullSuit_Left_Morphball
    },
    [SPOSE_DYING] = {
        sSamusAnim_Suitless_Right_Dying,
        sSamusAnim_Suitless_Left_Dying
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_CrouchingToCrawl,
        sSamusAnim_Suitless_Left_CrouchingToCrawl
    },
    [SPOSE_CRAWLING_STOPPED] = {
        sSamusAnim_Suitless_Right_CrawlingStopped,
        sSamusAnim_Suitless_Left_CrawlingStopped
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        sSamusAnim_Suitless_Right_StartingToCrawl,
        sSamusAnim_Suitless_Left_StartingToCrawl
    },
    [SPOSE_CRAWLING] = {
        sSamusAnim_Suitless_Right_Crawling,
        sSamusAnim_Suitless_Left_Crawling
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        sSamusAnim_Suitless_Right_UncrouchingFromCrawling,
        sSamusAnim_Suitless_Left_UncrouchingFromCrawling
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_TurningAroundWhileCrawling,
        sSamusAnim_Suitless_Left_TurningAroundWhileCrawling
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        sSamusAnim_Suitless_Right_ShootingWhileCrawling,
        sSamusAnim_Suitless_Left_ShootingWhileCrawling
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_UncrouchingSuitless
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        sSamusAnim_Suitless_Right_CrouchingSuitless,
        sSamusAnim_Suitless_Left_CrouchingSuitless
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        sSamusAnim_Suitless_Right_HangingOnLedgeSuitless,
        sSamusAnim_Suitless_Left_HangingOnLedgeSuitless
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_FacingTheBackground,
        sSamusAnim_Suitless_FacingTheBackground
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        sSamusAnim_Suitless_Right_TurningFromFacingTheBackground,
        sSamusAnim_Suitless_Left_TurningFromFacingTheBackground
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        sSamusAnim_FullSuit_MorphballMotioness,
        sSamusAnim_FullSuit_MorphballMotioness
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        sSamusAnim_FullSuit_Right_Crouching,
        sSamusAnim_FullSuit_Left_Crouching
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        sSamusAnim_FullSuit_Right_TurningAround,
        sSamusAnim_FullSuit_Left_TurningAround
    }
};


const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Running[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_Forward_Running,
        sSamusAnim_Suitless_Left_Forward_Running
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_Running,
        sSamusAnim_Suitless_Left_DiagonalUp_Running
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_Running,
        sSamusAnim_Suitless_Left_DiagonalDown_Running
    },
    [ACD_NONE - 2] = {
        sSamusAnim_Suitless_Right_Running,
        sSamusAnim_Suitless_Left_Running
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Standing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_Standing,
        sSamusAnim_Suitless_Left_Standing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_Standing,
        sSamusAnim_Suitless_Left_DiagonalUp_Standing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_Standing,
        sSamusAnim_Suitless_Left_DiagonalDown_Standing
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_Standing,
        sSamusAnim_Suitless_Left_Up_Standing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAround[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_TurningAround,
        sSamusAnim_Suitless_Left_TurningAround
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_TurningAround,
        sSamusAnim_Suitless_Left_DiagonalUp_TurningAround
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_TurningAround,
        sSamusAnim_Suitless_Left_DiagonalDown_TurningAround
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_TurningAround,
        sSamusAnim_Suitless_Left_Up_TurningAround
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Shooting[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_Shooting,
        sSamusAnim_Suitless_Left_Shooting
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_Shooting,
        sSamusAnim_Suitless_Left_DiagonalUp_Shooting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_Shooting,
        sSamusAnim_Suitless_Left_DiagonalDown_Shooting
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_Shooting,
        sSamusAnim_Suitless_Left_Up_Shooting
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Crouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_Crouching,
        sSamusAnim_Suitless_Left_Crouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_Crouching,
        sSamusAnim_Suitless_Left_DiagonalUp_Crouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_Crouching,
        sSamusAnim_Suitless_Left_DiagonalDown_Crouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAroundAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_TurningAroundAndCrouching,
        sSamusAnim_Suitless_Left_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_TurningAroundAndCrouching,
        sSamusAnim_Suitless_Left_DiagonalUp_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_TurningAroundAndCrouching,
        sSamusAnim_Suitless_Left_DiagonalDown_TurningAroundAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_ShootingAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_ShootingAndCrouching,
        sSamusAnim_Suitless_Left_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_ShootingAndCrouching,
        sSamusAnim_Suitless_Left_DiagonalUp_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_ShootingAndCrouching,
        sSamusAnim_Suitless_Left_DiagonalDown_ShootingAndCrouching
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_MidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_MidAir,
        sSamusAnim_Suitless_Left_MidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_MidAir,
        sSamusAnim_Suitless_Left_DiagonalUp_MidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_MidAir,
        sSamusAnim_Suitless_Left_DiagonalDown_MidAir
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_MidAir,
        sSamusAnim_Suitless_Left_Up_MidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_Suitless_Right_Down_MidAir,
        sSamusAnim_Suitless_Left_Down_MidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAroundMidAir[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_TurningAroundMidAir,
        sSamusAnim_Suitless_Left_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_TurningAroundMidAir,
        sSamusAnim_Suitless_Left_DiagonalUp_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_TurningAroundMidAir,
        sSamusAnim_Suitless_Left_DiagonalDown_TurningAroundMidAir
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_TurningAroundMidAir,
        sSamusAnim_Suitless_Left_Up_TurningAroundMidAir
    },
    [ACD_DOWN] = {
        sSamusAnim_Suitless_Right_Down_TurningAroundMidAir,
        sSamusAnim_Suitless_Left_Down_TurningAroundMidAir
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Landing[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_Landing,
        sSamusAnim_Suitless_Left_Landing
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_Landing,
        sSamusAnim_Suitless_Left_DiagonalUp_Landing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_Landing,
        sSamusAnim_Suitless_Left_DiagonalDown_Landing
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_Landing,
        sSamusAnim_Suitless_Left_Up_Landing
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_AimingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_AimingWhileHanging,
        sSamusAnim_Suitless_Left_AimingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_AimingWhileHanging,
        sSamusAnim_Suitless_Left_DiagonalUp_AimingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_AimingWhileHanging,
        sSamusAnim_Suitless_Left_DiagonalDown_AimingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_AimingWhileHanging,
        sSamusAnim_Suitless_Left_Up_AimingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_Suitless_Right_Down_AimingWhileHanging,
        sSamusAnim_Suitless_Left_Down_AimingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_ShootingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_DiagonalUp_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_DiagonalDown_ShootingWhileHanging
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_Up_ShootingWhileHanging
    },
    [ACD_DOWN] = {
        sSamusAnim_Suitless_Right_Down_ShootingWhileHanging,
        sSamusAnim_Suitless_Left_Down_ShootingWhileHanging
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_UncrouchingSuitless[4][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_UncrouchingSuitless
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_DiagonalUp_UncrouchingSuitless
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_DiagonalDown_UncrouchingSuitless
    },
    [ACD_UP] = {
        sSamusAnim_Suitless_Right_Up_UncrouchingSuitless,
        sSamusAnim_Suitless_Left_Up_UncrouchingSuitless
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_CrouchingSuitless[3][2] = {
    [ACD_FORWARD] = {
        sSamusAnim_Suitless_Right_CrouchingSuitless,
        sSamusAnim_Suitless_Left_CrouchingSuitless
    },
    [ACD_DIAGONALLY_UP] = {
        sSamusAnim_Suitless_Right_DiagonalUp_CrouchingSuitless,
        sSamusAnim_Suitless_Left_DiagonalUp_CrouchingSuitless
    },
    [ACD_DIAGONALLY_DOWN] = {
        sSamusAnim_Suitless_Right_DiagonalDown_CrouchingSuitless,
        sSamusAnim_Suitless_Left_DiagonalDown_CrouchingSuitless
    }
};

const struct SamusAnimationData* const sSamusAnimPointers_Suitless_CrawlingStopped[3][2] = {
    [FALSE] = {
        sSamusAnim_Suitless_Right_CrawlingStopped,
        sSamusAnim_Suitless_Left_CrawlingStopped
    },
    [TRUE] = {
        sSamusAnim_Suitless_Right_PistolUp_CrawlingStopped,
        sSamusAnim_Suitless_Left_PistolUp_CrawlingStopped
    },
    [2] = { // ?
        NULL,
        NULL
    }
};


const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_All[SPOSE_END][2] = {
    [SPOSE_RUNNING] = {
        sArmCannonAnim_Suitless_Right_None_Running,
        sArmCannonAnim_Suitless_Left_None_Running
    },
    [SPOSE_STANDING] = {
        sArmCannonAnim_Suitless_Right_Standing,
        sArmCannonAnim_Suitless_Left_Standing
    },
    [SPOSE_TURNING_AROUND] = {
        sArmCannonAnim_Suitless_Right_TurningAround,
        sArmCannonAnim_Suitless_Left_TurningAround
    },
    [SPOSE_SHOOTING] = {
        sArmCannonAnim_Suitless_Right_Shooting,
        sArmCannonAnim_Suitless_Left_Shooting
    },
    [SPOSE_CROUCHING] = {
        sArmCannonAnim_Suitless_Right_Crouching,
        sArmCannonAnim_Suitless_Left_Crouching
    },
    [SPOSE_TURNING_AROUND_AND_CROUCHING] = {
        sArmCannonAnim_Suitless_Right_TurningAroundAndCrouching,
        sArmCannonAnim_Suitless_Left_TurningAroundAndCrouching
    },
    [SPOSE_SHOOTING_AND_CROUCHING] = {
        sArmCannonAnim_Suitless_Right_ShootingAndCrouching,
        sArmCannonAnim_Suitless_Left_ShootingAndCrouching
    },
    [SPOSE_SKIDDING] = {
        sArmCannonAnim_Suit_Right_Skidding,
        sArmCannonAnim_Suit_Left_Skidding
    },
    [SPOSE_MIDAIR] = {
        sArmCannonAnim_Suitless_Right_MidAir,
        sArmCannonAnim_Suitless_Left_MidAir
    },
    [SPOSE_TURNING_AROUND_MIDAIR] = {
        sArmCannonAnim_Suitless_Right_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_TurningAroundMidAir
    },
    [SPOSE_LANDING] = {
        sArmCannonAnim_Suitless_Right_Landing,
        sArmCannonAnim_Suitless_Left_Landing
    },
    [SPOSE_STARTING_SPIN_JUMP] = {
        sArmCannonAnim_Suitless_Right_StartingSpinJump,
        sArmCannonAnim_Suitless_Left_StartingSpinJump
    },
    [SPOSE_SPINNING] = {
        sArmCannonAnim_Suitless_Right_Spinning,
        sArmCannonAnim_Suitless_Left_Spinning
    },
    [SPOSE_STARTING_WALL_JUMP] = {
        sArmCannonAnim_Suitless_Left_StartingWallJump,
        sArmCannonAnim_Suitless_Right_StartingWallJump
    },
    [SPOSE_SPACE_JUMPING] = {
        sArmCannonAnim_Suit_Right_SpaceJumping,
        sArmCannonAnim_Suit_Left_SpaceJumping
    },
    [SPOSE_SCREW_ATTACKING] = {
        sArmCannonAnim_Suit_Right_ScrewAttacking,
        sArmCannonAnim_Suit_Left_ScrewAttacking
    },
    [SPOSE_MORPHING] = {
        sArmCannonAnim_Suit_Right_Morphing,
        sArmCannonAnim_Suit_Left_Morphing
    },
    [SPOSE_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_ROLLING] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_UNMORPHING] = {
        sArmCannonAnim_Suit_Right_Unmorphing,
        sArmCannonAnim_Suit_Left_Unmorphing
    },
    [SPOSE_MORPH_BALL_MIDAIR] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_HANGING_ON_LEDGE] = {
        sArmCannonAnim_Suitless_Right_HangingOnLedge,
        sArmCannonAnim_Suitless_Left_HangingOnLedge
    },
    [SPOSE_TURNING_TO_AIM_WHILE_HANGING] = {
        sArmCannonAnim_Suitless_Right_TurningToAimWhileHanging,
        sArmCannonAnim_Suitless_Left_TurningToAimWhileHanging
    },
    [SPOSE_HIDING_ARM_CANNON_WHILE_HANGING] = {
        sArmCannonAnim_Suitless_Right_TurningToAimWhileHanging,
        sArmCannonAnim_Suitless_Left_TurningToAimWhileHanging
    },
    [SPOSE_AIMING_WHILE_HANGING] = {
        sArmCannonAnim_Suitless_Right_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_AimingWhileHanging
    },
    [SPOSE_SHOOTING_WHILE_HANGING] = {
        sArmCannonAnim_Suitless_Right_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_ShootingWhileHanging
    },
    [SPOSE_PULLING_YOURSELF_UP_FROM_HANGING] = {
        sArmCannonAnim_Suitless_Right_PullingYourselfUpFromHanging,
        sArmCannonAnim_Suitless_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING] = {
        sArmCannonAnim_Suitless_Right_PullingYourselfForwardFromHanging,
        sArmCannonAnim_Suitless_Left_PullingYourselfForwardFromHanging
    },
    [SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL] = {
        sArmCannonAnim_Suitless_Right_PullingYourselfUpFromHanging,
        sArmCannonAnim_Suitless_Left_PullingYourselfUpFromHanging
    },
    [SPOSE_USING_AN_ELEVATOR] = {
        sArmCannonAnim_Suit_UsingAnElevator,
        sArmCannonAnim_Suit_UsingAnElevator
    },
    [SPOSE_FACING_THE_FOREGROUND] = {
        sArmCannonAnim_Suitless_FacingTheForeground,
        sArmCannonAnim_Suitless_FacingTheForeground
    },
    [SPOSE_TURNING_FROM_FACING_THE_FOREGROUND] = {
        sArmCannonAnim_Suitless_Right_TurningFromFacingTheForeground,
        sArmCannonAnim_Suitless_Left_TurningFromFacingTheForeground
    },
    [SPOSE_GRABBED_BY_CHOZO_STATUE] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_DELAY_BEFORE_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_DelayBeforeShinesparking,
        sArmCannonAnim_Suit_Left_DelayBeforeShinesparking
    },
    [SPOSE_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_Shinesparking,
        sArmCannonAnim_Suit_Left_Shinesparking
    },
    [SPOSE_SHINESPARK_COLLISION] = {
        sArmCannonAnim_Suit_Right_Shinesparking,
        sArmCannonAnim_Suit_Left_Shinesparking
    },
    [SPOSE_DELAY_AFTER_SHINESPARKING] = {
        sArmCannonAnim_Suit_Right_DelayAfterShinesparking,
        sArmCannonAnim_Suit_Left_DelayAfterShinesparking
    },
    [SPOSE_DELAY_BEFORE_BALLSPARKING] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_BALLSPARKING] = {
        sArmCannonAnim_Suit_Right_Ballsparking,
        sArmCannonAnim_Suit_Left_Ballsparking
    },
    [SPOSE_BALLSPARK_COLLISION] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_OnZipline,
        sArmCannonAnim_Suit_Left_OnZipline
    },
    [SPOSE_SHOOTING_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_ShootingOnZipline,
        sArmCannonAnim_Suit_Left_ShootingOnZipline
    },
    [SPOSE_TURNING_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_Right_TurningOnZipline,
        sArmCannonAnim_Suit_Left_TurningOnZipline
    },
    [SPOSE_MORPH_BALL_ON_ZIPLINE] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_SAVING_LOADING_GAME] = {
        sArmCannonAnim_Suitless_SavingLoadingGame,
        sArmCannonAnim_Suitless_SavingLoadingGame
    },
    [SPOSE_DOWNLOADING_MAP_DATA] = {
        sArmCannonAnim_Suitless_DownloadingMapData,
        sArmCannonAnim_Suitless_DownloadingMapData
    },
    [SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA] = {
        sArmCannonAnim_Suitless_Right_TurningAround,
        sArmCannonAnim_Suitless_Left_TurningAround
    },
    [SPOSE_GETTING_HURT] = {
        sArmCannonAnim_Suit_Right_GettingHurt,
        sArmCannonAnim_Suit_Left_GettingHurt
    },
    [SPOSE_GETTING_KNOCKED_BACK] = {
        sArmCannonAnim_Suit_Right_GettingHurt,
        sArmCannonAnim_Suit_Left_GettingHurt
    },
    [SPOSE_GETTING_HURT_IN_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL] = {
        sArmCannonAnim_Suit_Right_Morphball,
        sArmCannonAnim_Suit_Left_Morphball
    },
    [SPOSE_DYING] = {
        sArmCannonAnim_Suit_Dying,
        sArmCannonAnim_Suit_Dying
    },
    [SPOSE_CROUCHING_TO_CRAWL] = {
        sArmCannonAnim_Suitless_Right_CrouchingToCrawl,
        sArmCannonAnim_Suitless_Left_CrouchingToCrawl
    },
    [SPOSE_CRAWLING_STOPPED] = {
        sArmCannonAnim_Suitless_Right_CrawlingStopped,
        sArmCannonAnim_Suitless_Left_CrawlingStopped
    },
    [SPOSE_STARTING_TO_CRAWL] = {
        sArmCannonAnim_Suitless_Right_StartingToCrawl,
        sArmCannonAnim_Suitless_Left_StartingToCrawl
    },
    [SPOSE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_Crawling,
        sArmCannonAnim_Suitless_Left_Crawling
    },
    [SPOSE_UNCROUCHING_FROM_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_UncrouchingFromCrawling,
        sArmCannonAnim_Suitless_Left_UncrouchingFromCrawling
    },
    [SPOSE_TURNING_AROUND_WHILE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_TurningAroundWhileCrawling,
        sArmCannonAnim_Suitless_Left_TurningAroundWhileCrawling
    },
    [SPOSE_SHOOTING_WHILE_CRAWLING] = {
        sArmCannonAnim_Suitless_Right_ShootingWhileCrawling,
        sArmCannonAnim_Suitless_Left_ShootingWhileCrawling
    },
    [SPOSE_UNCROUCHING_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_UncrouchingSuitless
    },
    [SPOSE_CROUCHING_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_CrouchingSuitless,
        sArmCannonAnim_Suitless_Left_CrouchingSuitless
    },
    [SPOSE_GRABBING_A_LEDGE_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_HangingOnLedgeSuitless,
        sArmCannonAnim_Suitless_Left_HangingOnLedgeSuitless
    },
    [SPOSE_FACING_THE_BACKGROUND_SUITLESS] = {
        sArmCannonAnim_Suitless_FacingTheBackground,
        sArmCannonAnim_Suitless_FacingTheBackground
    },
    [SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS] = {
        sArmCannonAnim_Suitless_Right_TurningFromFacingTheBackground,
        sArmCannonAnim_Suitless_Left_TurningFromFacingTheBackground
    },
    [SPOSE_ACTIVATING_ZIPLINES] = {
        sArmCannonAnim_Suit_MorphballMotionless,
        sArmCannonAnim_Suit_MorphballMotionless
    },
    [SPOSE_IN_ESCAPE_SHIP] = {
        sArmCannonAnim_Suit_Right_Crouching,
        sArmCannonAnim_Suit_Left_Crouching
    },
    [SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP] = {
        sArmCannonAnim_Suit_Right_TurningAround,
        sArmCannonAnim_Suit_Left_TurningAround
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Running[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_Forward_Running,
        sArmCannonAnim_Suitless_Left_Forward_Running
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_Running,
        sArmCannonAnim_Suitless_Left_DiagonalUp_Running
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_Running,
        sArmCannonAnim_Suitless_Left_DiagonalDown_Running
    },
    [ACD_NONE - 2] = {
        sArmCannonAnim_Suitless_Right_None_Running,
        sArmCannonAnim_Suitless_Left_None_Running
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Standing[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_Standing,
        sArmCannonAnim_Suitless_Left_Standing
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_Standing,
        sArmCannonAnim_Suitless_Left_DiagonalUp_Standing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_Standing,
        sArmCannonAnim_Suitless_Left_DiagonalDown_Standing
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_Standing,
        sArmCannonAnim_Suitless_Left_Up_Standing
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAround[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_TurningAround,
        sArmCannonAnim_Suitless_Left_TurningAround
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAround,
        sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAround
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAround,
        sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAround
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_TurningAround,
        sArmCannonAnim_Suitless_Left_Up_TurningAround
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Shooting[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_Shooting,
        sArmCannonAnim_Suitless_Left_Shooting
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_Shooting,
        sArmCannonAnim_Suitless_Left_DiagonalUp_Shooting
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_Shooting,
        sArmCannonAnim_Suitless_Left_DiagonalDown_Shooting
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_Shooting,
        sArmCannonAnim_Suitless_Left_Up_Shooting
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Crouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_Crouching,
        sArmCannonAnim_Suitless_Left_Crouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_Crouching,
        sArmCannonAnim_Suitless_Left_DiagonalUp_Crouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_Crouching,
        sArmCannonAnim_Suitless_Left_DiagonalDown_Crouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAroundAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_TurningAroundAndCrouching,
        sArmCannonAnim_Suitless_Left_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAroundAndCrouching,
        sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAroundAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAroundAndCrouching,
        sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAroundAndCrouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_ShootingAndCrouching[3][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_ShootingAndCrouching,
        sArmCannonAnim_Suitless_Left_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_ShootingAndCrouching,
        sArmCannonAnim_Suitless_Left_DiagonalUp_ShootingAndCrouching
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_ShootingAndCrouching,
        sArmCannonAnim_Suitless_Left_DiagonalDown_ShootingAndCrouching
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_MidAir[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_MidAir,
        sArmCannonAnim_Suitless_Left_MidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_MidAir,
        sArmCannonAnim_Suitless_Left_DiagonalUp_MidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_MidAir,
        sArmCannonAnim_Suitless_Left_DiagonalDown_MidAir
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_MidAir,
        sArmCannonAnim_Suitless_Left_Up_MidAir
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suitless_Right_Down_MidAir,
        sArmCannonAnim_Suitless_Left_Down_MidAir
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAroundMidAir[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAroundMidAir
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAroundMidAir
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_Up_TurningAroundMidAir
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suitless_Right_Down_TurningAroundMidAir,
        sArmCannonAnim_Suitless_Left_Down_TurningAroundMidAir
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Landing[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_Landing,
        sArmCannonAnim_Suitless_Left_Landing
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_Landing,
        sArmCannonAnim_Suitless_Left_DiagonalUp_Landing
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_Landing,
        sArmCannonAnim_Suitless_Left_DiagonalDown_Landing
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_Landing,
        sArmCannonAnim_Suitless_Left_Up_Landing
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_AimingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_AimingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_DiagonalUp_AimingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_DiagonalDown_AimingWhileHanging
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_Up_AimingWhileHanging
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suitless_Right_Down_AimingWhileHanging,
        sArmCannonAnim_Suitless_Left_Down_AimingWhileHanging
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_ShootingWhileHanging[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_DiagonalUp_ShootingWhileHanging
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_DiagonalDown_ShootingWhileHanging
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_Up_ShootingWhileHanging
    },
    [ACD_DOWN] = {
        sArmCannonAnim_Suitless_Right_Down_ShootingWhileHanging,
        sArmCannonAnim_Suitless_Left_Down_ShootingWhileHanging
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_UncrouchingSuitless[4][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_UncrouchingSuitless
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_DiagonalUp_UncrouchingSuitless
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_DiagonalDown_UncrouchingSuitless
    },
    [ACD_UP] = {
        sArmCannonAnim_Suitless_Right_Up_UncrouchingSuitless,
        sArmCannonAnim_Suitless_Left_Up_UncrouchingSuitless
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_CrouchingSuitless[5][2] = {
    [ACD_FORWARD] = {
        sArmCannonAnim_Suitless_Right_CrouchingSuitless,
        sArmCannonAnim_Suitless_Left_CrouchingSuitless
    },
    [ACD_DIAGONALLY_UP] = {
        sArmCannonAnim_Suitless_Right_DiagonalUp_CrouchingSuitless,
        sArmCannonAnim_Suitless_Left_DiagonalUp_CrouchingSuitless
    },
    [ACD_DIAGONALLY_DOWN] = {
        sArmCannonAnim_Suitless_Right_DiagonalDown_CrouchingSuitless,
        sArmCannonAnim_Suitless_Left_DiagonalDown_CrouchingSuitless
    },
    [ACD_UP] = {
        NULL,
        NULL
    },
    [ACD_DOWN] = {
        NULL,
        NULL
    }
};

const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_CrawlingStopped[3][2] = {
    [FALSE] = {
        sArmCannonAnim_Suitless_Right_CrawlingStopped,
        sArmCannonAnim_Suitless_Left_CrawlingStopped
    },
    [TRUE] = {
        sArmCannonAnim_Suitless_Right_PistolUp_CrawlingStopped,
        sArmCannonAnim_Suitless_Left_PistolUp_CrawlingStopped
    },
    [2] = {
        NULL,
        NULL
    }
};


// Palette pointers

const u16* const sSamusPal_PowerSuit_SavingPointers[11] = {
    &sSamusPal_PowerSuit_Default[0 * 16],
    &sSamusPal_PowerSuit_Saving [0 * 16],
    &sSamusPal_PowerSuit_Saving [1 * 16],
    &sSamusPal_PowerSuit_Saving [2 * 16],
    &sSamusPal_PowerSuit_Default[0 * 16],
    &sSamusPal_PowerSuit_Saving [0 * 16],
    &sSamusPal_PowerSuit_Saving [1 * 16],
    &sSamusPal_PowerSuit_Saving [2 * 16],
    &sSamusPal_PowerSuit_Saving [0 * 16],
    &sSamusPal_PowerSuit_Saving [1 * 16],
    &sSamusPal_PowerSuit_Saving [2 * 16]
};

const u16* const sSamusPal_VariaSuit_SavingPointers[11] = {
    &sSamusPal_VariaSuit_Default[0 * 16],
    &sSamusPal_VariaSuit_Saving [0 * 16],
    &sSamusPal_VariaSuit_Saving [1 * 16],
    &sSamusPal_VariaSuit_Saving [2 * 16],
    &sSamusPal_VariaSuit_Default[0 * 16],
    &sSamusPal_VariaSuit_Saving [0 * 16],
    &sSamusPal_VariaSuit_Saving [1 * 16],
    &sSamusPal_VariaSuit_Saving [2 * 16],
    &sSamusPal_VariaSuit_Saving [0 * 16],
    &sSamusPal_VariaSuit_Saving [1 * 16],
    &sSamusPal_VariaSuit_Saving [2 * 16]
};

const u16* const sSamusPal_FullSuit_SavingPointers[11] = {
    &sSamusPal_FullSuit_Default[0 * 16],
    &sSamusPal_FullSuit_Saving [0 * 16],
    &sSamusPal_FullSuit_Saving [1 * 16],
    &sSamusPal_FullSuit_Saving [2 * 16],
    &sSamusPal_FullSuit_Default[0 * 16],
    &sSamusPal_FullSuit_Saving [0 * 16],
    &sSamusPal_FullSuit_Saving [1 * 16],
    &sSamusPal_FullSuit_Saving [2 * 16],
    &sSamusPal_FullSuit_Saving [0 * 16],
    &sSamusPal_FullSuit_Saving [1 * 16],
    &sSamusPal_FullSuit_Saving [2 * 16]
};

const u16* const sSamusPal_GravitySuit_SavingPointers[11] = {
    &sSamusPal_GravitySuit_Default[0 * 16],
    &sSamusPal_GravitySuit_Saving [0 * 16],
    &sSamusPal_GravitySuit_Saving [1 * 16],
    &sSamusPal_GravitySuit_Saving [2 * 16],
    &sSamusPal_GravitySuit_Default[0 * 16],
    &sSamusPal_GravitySuit_Saving [0 * 16],
    &sSamusPal_GravitySuit_Saving [1 * 16],
    &sSamusPal_GravitySuit_Saving [2 * 16],
    &sSamusPal_GravitySuit_Saving [0 * 16],
    &sSamusPal_GravitySuit_Saving [1 * 16],
    &sSamusPal_GravitySuit_Saving [2 * 16]
};

const u16* const sSamusPal_Suitless_SavingPointers[11] = {
    &sSamusPal_Suitless_Default[0 * 16],
    &sSamusPal_Suitless_Saving [0 * 16],
    &sSamusPal_Suitless_Saving [1 * 16],
    &sSamusPal_Suitless_Saving [2 * 16],
    &sSamusPal_Suitless_Default[0 * 16],
    &sSamusPal_Suitless_Saving [0 * 16],
    &sSamusPal_Suitless_Saving [1 * 16],
    &sSamusPal_Suitless_Saving [2 * 16],
    &sSamusPal_Suitless_Saving [0 * 16],
    &sSamusPal_Suitless_Saving [1 * 16],
    &sSamusPal_Suitless_Saving [2 * 16]
};


const u16* const sSamusPal_PowerSuit_DownloadingMapPointers[8] = {
    &sSamusPal_PowerSuit_DownloadingMap[0 * 16],
    &sSamusPal_PowerSuit_DownloadingMap[1 * 16],
    &sSamusPal_PowerSuit_Default       [0 * 16],
    &sSamusPal_PowerSuit_DownloadingMap[0 * 16],
    &sSamusPal_PowerSuit_DownloadingMap[1 * 16],
    &sSamusPal_PowerSuit_Default       [0 * 16],
    &sSamusPal_PowerSuit_DownloadingMap[0 * 16],
    &sSamusPal_PowerSuit_DownloadingMap[1 * 16]
};

const u16* const sSamusPal_VariaSuit_DownloadingMapPointers[8] = {
    &sSamusPal_VariaSuit_DownloadingMap[0 * 16],
    &sSamusPal_VariaSuit_DownloadingMap[1 * 16],
    &sSamusPal_VariaSuit_Default       [0 * 16],
    &sSamusPal_VariaSuit_DownloadingMap[0 * 16],
    &sSamusPal_VariaSuit_DownloadingMap[1 * 16],
    &sSamusPal_VariaSuit_Default       [0 * 16],
    &sSamusPal_VariaSuit_DownloadingMap[0 * 16],
    &sSamusPal_VariaSuit_DownloadingMap[1 * 16]
};

const u16* const sSamusPal_FullSuit_DownloadingMapPointers[8] = {
    &sSamusPal_FullSuit_DownloadingMap[0 * 16],
    &sSamusPal_FullSuit_DownloadingMap[1 * 16],
    &sSamusPal_FullSuit_Default       [0 * 16],
    &sSamusPal_FullSuit_DownloadingMap[0 * 16],
    &sSamusPal_FullSuit_DownloadingMap[1 * 16],
    &sSamusPal_FullSuit_Default       [0 * 16],
    &sSamusPal_FullSuit_DownloadingMap[0 * 16],
    &sSamusPal_FullSuit_DownloadingMap[1 * 16]
};

const u16* const sSamusPal_GravitySuit_DownloadingMapPointers[8] = {
    &sSamusPal_GravitySuit_DownloadingMap[0 * 16],
    &sSamusPal_GravitySuit_DownloadingMap[1 * 16],
    &sSamusPal_GravitySuit_Default       [0 * 16],
    &sSamusPal_GravitySuit_DownloadingMap[0 * 16],
    &sSamusPal_GravitySuit_DownloadingMap[1 * 16],
    &sSamusPal_GravitySuit_Default       [0 * 16],
    &sSamusPal_GravitySuit_DownloadingMap[0 * 16],
    &sSamusPal_GravitySuit_DownloadingMap[1 * 16]
};

const u16* const sSamusPal_Suitless_DownloadingMapPointers[8] = {
    &sSamusPal_Suitless_DownloadingMap[0 * 16],
    &sSamusPal_Suitless_DownloadingMap[1 * 16],
    &sSamusPal_Suitless_Default       [0 * 16],
    &sSamusPal_Suitless_DownloadingMap[0 * 16],
    &sSamusPal_Suitless_DownloadingMap[1 * 16],
    &sSamusPal_Suitless_Default       [0 * 16],
    &sSamusPal_Suitless_DownloadingMap[0 * 16],
    &sSamusPal_Suitless_DownloadingMap[1 * 16]
};


// Arm cannon graphics pointers

const u8* const sArmCannonGfxPointers_Upper_Standing[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Standing,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Standing,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Standing,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Standing
};

const u8* const sArmCannonGfxPointers_Lower_Standing[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Standing,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Standing,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Standing,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Standing
};

const u8* const sArmCannonGfxPointers_Upper_Armed_Standing[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Armed_Standing,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Armed_Standing,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Armed_Standing,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_Armed_Default,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_Armed_Default
};

const u8* const sArmCannonGfxPointers_Lower_Armed_Standing[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Armed_Standing,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Armed_Standing,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Armed_Standing,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Lower_Armed_Down
};


const u8* const sArmCannonGfxPointers_Upper_Right_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_Default,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Standing
};

const u8* const sArmCannonGfxPointers_Lower_Right_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_Default,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Standing
};

const u8* const sArmCannonGfxPointers_Upper_Left_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Left_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Left_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Left_Default,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Left_Default,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Left_Default
};

const u8* const sArmCannonGfxPointers_Lower_Left_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Left_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Left_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Left_Default,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Left_Default,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Left_Default
};


const u8* const sArmCannonGfxPointers_Upper_Right_Armed_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_Armed_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_Armed_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_Armed_Default,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_Armed_Default,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_Armed_Default
};

const u8* const sArmCannonGfxPointers_Lower_Right_Armed_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_Armed_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_Armed_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_Armed_Default,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Standing,
    [ACD_DOWN] = sArmCannonGfx_Lower_Armed_Down
};

const u8* const sArmCannonGfxPointers_Upper_Left_Armed_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Left_Armed_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Left_Armed_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Left_Armed_Default,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Left_Armed_Default,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Left_Armed_Default
};

const u8* const sArmCannonGfxPointers_Lower_Left_Armed_Default[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Left_Armed_Default,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Left_Armed_Default,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Left_Armed_Default,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Left_Armed_Default,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Left_Armed_Default
};


const u8* const sArmCannonGfxPointers_Upper_Left_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Left_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Left_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Left_Hanging,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Left_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Left_Hanging
};

const u8* const sArmCannonGfxPointers_Lower_Left_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Left_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Left_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Left_Hanging,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Left_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Left_Hanging
};

const u8* const sArmCannonGfxPointers_Upper_Right_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_OnZipline,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_Hanging,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_OnZipline,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_Hanging
};

const u8* const sArmCannonGfxPointers_Lower_Right_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_OnZipline,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_Hanging,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Right_OnZipline,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Right_Hanging
};


const u8* const sArmCannonGfxPointers_Upper_Left_Armed_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Left_Armed_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Left_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Left_Armed_Hanging,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Left_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Left_Armed_Hanging
};

const u8* const sArmCannonGfxPointers_Lower_Left_Armed_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Left_Armed_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Left_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Left_Armed_Hanging,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Left_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Left_Armed_Hanging
};

const u8* const sArmCannonGfxPointers_Upper_Right_Armed_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_Armed_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_Armed_Hanging,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_Armed_Hanging
};

const u8* const sArmCannonGfxPointers_Lower_Right_Armed_Hanging[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_Armed_Hanging,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_Armed_Hanging,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Right_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Right_Armed_Hanging
};


const u8* const sArmCannonGfxPointers_Upper_Right_OnZipline[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_OnZipline,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_OnZipline,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_OnZipline,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_OnZipline,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_OnZipline
};

const u8* const sArmCannonGfxPointers_Lower_Right_OnZipline[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_OnZipline,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_OnZipline,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_OnZipline,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Right_OnZipline,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Right_OnZipline
};

const u8* const sArmCannonGfxPointers_Upper_Right_Armed_OnZipline[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Upper_Forward_Right_Armed_OnZipline,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Upper_DiagonalUp_Right_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Upper_DiagonalDown_Right_Armed_OnZipline,
    [ACD_UP] = sArmCannonGfx_Upper_Up_Right_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Upper_Down_Right_Armed_OnZipline
};

const u8* const sArmCannonGfxPointers_Lower_Right_Armed_OnZipline[5] = {
    [ACD_FORWARD] = sArmCannonGfx_Lower_Forward_Right_Armed_OnZipline,
    [ACD_DIAGONALLY_UP] = sArmCannonGfx_Lower_DiagonalUp_Right_Armed_Hanging,
    [ACD_DIAGONALLY_DOWN] = sArmCannonGfx_Lower_DiagonalDown_Right_Armed_OnZipline,
    [ACD_UP] = sArmCannonGfx_Lower_Up_Right_Armed_Hanging,
    [ACD_DOWN] = sArmCannonGfx_Lower_Down_Right_Armed_OnZipline
};


// Samus effects pointers

const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Speedboosting[1][2] = {
    {
        sSamusEffectAnim_Right_Speedboosting,
        sSamusEffectAnim_Left_Speedboosting
    }
};

const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Shinesparking[3][2] = {
    [FORCED_MOVEMENT_UPWARDS_SHINESPARK] = {
        sSamusEffectAnim_Up_Shinesparking,
        sSamusEffectAnim_Up_Shinesparking
    },
    [FORCED_MOVEMENT_SIDEWARDS_SHINESPARK] = {
        sSamusEffectAnim_Right_Sidewards_Shinesparking,
        sSamusEffectAnim_Left_Sidewards_Shinesparking,
    },
    [FORCED_MOVEMENT_DIAGONAL_SHINESPARK] = {
        sSamusEffectAnim_Right_Diagonal_Shinesparking,
        sSamusEffectAnim_Left_Diagonal_Shinesparking,
    }
};

const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Ballsparking[3][2] = {
    [FORCED_MOVEMENT_UPWARDS_SHINESPARK] = {
        sSamusEffectAnim_Up_Ballsparking,
        sSamusEffectAnim_Up_Ballsparking
    },
    [FORCED_MOVEMENT_SIDEWARDS_SHINESPARK] = {
        sSamusEffectAnim_Right_Sidewards_Ballsparking,
        sSamusEffectAnim_Left_Sidewards_Ballsparking,
    },
    [FORCED_MOVEMENT_DIAGONAL_SHINESPARK] = {
        sSamusEffectAnim_Right_Diagonal_Ballsparking,
        sSamusEffectAnim_Left_Diagonal_Ballsparking,
    }
};


const s16 sSamusDrawDistanceOffsets[4][4] = {
    [SAMUS_HITBOX_TYPE_STANDING] = {
        -28, -124, 28, 0
    },
    [SAMUS_HITBOX_TYPE_CROUCHED] = {
        -28, -92, 28, 0
    },
    [SAMUS_HITBOX_TYPE_MORPHED] = {
        -28, -60, 28, 0
    },
    [SAMUS_HITBOX_TYPE_ZIPLINE] = {
        -28, -124, 28, -8
    }
};

const s16 sSamusHitboxData[3][3] = {
    [SAMUS_HITBOX_TYPE_STANDING] = {
        [SAMUS_HITBOX_LEFT] = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_RIGHT] = (HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_TOP] = -(BLOCK_SIZE * 2 - PIXEL_SIZE)
    },
    [SAMUS_HITBOX_TYPE_CROUCHED] = {
        [SAMUS_HITBOX_LEFT] = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_RIGHT] = (HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_TOP] = -(BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [SAMUS_HITBOX_TYPE_MORPHED] = {
        [SAMUS_HITBOX_LEFT] = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_RIGHT] = (HALF_BLOCK_SIZE - PIXEL_SIZE),
        [SAMUS_HITBOX_TOP] = -(BLOCK_SIZE - PIXEL_SIZE)
    }
};

const s16 sSamusHitboxData_Above[3] = {
    [SAMUS_HITBOX_LEFT] = -(EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
    [SAMUS_HITBOX_RIGHT] = (EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
    [SAMUS_HITBOX_TOP] = 0
};

const struct FrameData* const sSamusEnvEffectsFrameDataPointers[ENV_EFFECT_END - 1] = {
    [ENV_EFFECT_RUNNING_ON_WET_GROUND - 1] = sEnvEffectOam_RunningOnWetGround,
    [ENV_EFFECT_RUNNING_ON_DUSTY_GROUND - 1] = sEnvEffectOam_RunningOnDustyGround,
    [ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND - 1] = sEnvEffectOam_RunningOnVeryDustyGround,
    [ENV_EFFECT_GOING_OUT_OF_WATER - 1] = sEnvEffectOam_GoingOutOfWater,
    [ENV_EFFECT_RUNNING_INTO_WATER - 1] = sEnvEffectOam_RunningIntoWater,
    [ENV_EFFECT_GOING_OUT_OF_LAVA - 1] = sEnvEffectOam_GoingOutOfLava,
    [ENV_EFFECT_RUNNING_INTO_LAVA - 1] = sEnvEffectOam_RunningIntoLava,
    [ENV_EFFECT_GOING_OUT_OF_ACID - 1] = sEnvEffectOam_GoingOutOfAcid,
    [ENV_EFFECT_RUNNING_INTO_ACID - 1] = sEnvEffectOam_RunningIntoAcid,
    [ENV_EFFECT_TAKING_DAMAGE_IN_LAVA - 1] = sEnvEffectOam_TakingDamageInLava,
    [ENV_EFFECT_TAKING_DAMAGE_IN_ACID - 1] = sEnvEffectOam_TakingDamageInAcid,
    [ENV_EFFECT_LANDING_ON_WET_GROUND - 1] = sEnvEffectOam_LandingOnWetGround,
    [ENV_EFFECT_LANDING_ON_BUBBLY_GROUND - 1] = sEnvEffectOam_LandingOnBubblyGround,
    [ENV_EFFECT_LANDING_ON_DUSTY_GROUND - 1] = sEnvEffectOam_LandingOnDustyGround,
    [ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND - 1] = sEnvEffectOam_LandingOnVeryDustyGround,
    [ENV_EFFECT_SKIDDING_ON_WET_GROUND - 1] = sEnvEffectOam_LandingOnWetGround,
    [ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND - 1] = sEnvEffectOam_LandingOnDustyGround,
    [ENV_EFFECT_BREATHING_BUBBLES - 1] = sEnvEffectOam_BreathingBubbles
};

const u16 sSamusPullingSelfUpVelocity[4] = {
    [0] = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [1] = EIGHTH_BLOCK_SIZE,
    [2] = PIXEL_SIZE,
    [3] = 0
};
