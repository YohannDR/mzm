#include "data/engine_pointers.h"
#include "macros.h"

#include "data/rooms/brinstar_rooms_data.h"
#include "data/rooms/kraid_rooms_data.h"
#include "data/rooms/norfair_rooms_data.h"
#include "data/rooms/ridley_rooms_data.h"
#include "data/rooms/tourian_rooms_data.h"
#include "data/rooms/crateria_rooms_data.h"
#include "data/rooms/chozodia_rooms_data.h"

#include "macros.h"
#include "data/clipdata_data.h"
#include "data/animated_graphics_data.h"
#include "data/hatch_data.h"
#include "data/rooms_data.h"

#include "particle.h"
#include "projectile.h"
#include "color_fading.h"
#include "block.h"
#include "tourian_escape.h"
#include "cutscenes/cutscene_utils.h"

#include "constants/animated_graphics.h"
#include "constants/haze.h"
#include "constants/room.h"
#include "constants/particle.h"
#include "constants/projectile.h"

const ProjFunc_T sProcessProjectileFunctionPointers[16] = {
    [PROJ_TYPE_BEAM] = ProjectileProcessNormalBeam,
    [PROJ_TYPE_LONG_BEAM] = ProjectileProcessLongBeam,
    [PROJ_TYPE_ICE_BEAM] = ProjectileProcessIceBeam,
    [PROJ_TYPE_WAVE_BEAM] = ProjectileProcessWaveBeam,
    [PROJ_TYPE_PLASMA_BEAM] = ProjectileProcessPlasmaBeam,
    [PROJ_TYPE_PISTOL] = ProjectileProcessPistol,
    [PROJ_TYPE_CHARGED_BEAM] = ProjectileProcessChargedNormalBeam,
    [PROJ_TYPE_CHARGED_LONG_BEAM] = ProjectileProcessChargedLongBeam,
    [PROJ_TYPE_CHARGED_ICE_BEAM] = ProjectileProcessChargedIceBeam,
    [PROJ_TYPE_CHARGED_WAVE_BEAM] = ProjectileProcessChargedWaveBeam,
    [PROJ_TYPE_CHARGED_PLASMA_BEAM] = ProjectileProcessChargedPlasmaBeam,
    [PROJ_TYPE_CHARGED_PISTOL] = ProjectileProcessChargedPistol,
    [PROJ_TYPE_MISSILE] = ProjectileProcessMissile,
    [PROJ_TYPE_SUPER_MISSILE] = ProjectileProcessSuperMissile,
    [PROJ_TYPE_BOMB] = ProjectileProcessBomb,
    [PROJ_TYPE_POWER_BOMB] = ProjectileProcessPowerBomb
};

const ParticleFunc_T sProcessParticleFunctionPointers[61] = {
    [PE_SPRITE_SPLASH_WATER_SMALL] = ParticleSpriteSplashWaterSmall,
    [PE_SPRITE_SPLASH_WATER_BIG] = ParticleSpriteSplashWaterBig,
    [PE_SPRITE_SPLASH_WATER_HUGE] = ParticleSpriteSplashWaterHuge,
    [PE_SPRITE_SPLASH_LAVA_SMALL] = ParticleSpriteSplashLavaSmall,
    [PE_SPRITE_SPLASH_LAVA_BIG] = ParticleSpriteSplashLavaBig,
    [PE_SPRITE_SPLASH_LAVA_HUGE] = ParticleSpriteSplashLavaHuge,
    [PE_SPRITE_SPLASH_ACID_SMALL] = ParticleSpriteSplashAcidSmall,
    [PE_SPRITE_SPLASH_ACID_BIG] = ParticleSpriteSplashAcidBig,
    [PE_SPRITE_SPLASH_ACID_HUGE] = ParticleSpriteSplashAcidHuge,
    [PE_SHOOTING_BEAM_LEFT] = ParticleShootingBeamLeft,
    [PE_SHOOTING_BEAM_DIAG_UP_LEFT] = ParticleShootingBeamDiagUpLeft,
    [PE_SHOOTING_BEAM_DIAG_DOWN_LEFT] = ParticleShootingBeamDiagDownLeft,
    [PE_SHOOTING_BEAM_UP_LEFT] = ParticleShootingBeamUpLeft,
    [PE_SHOOTING_BEAM_DOWN_LEFT] = ParticleShootingBeamDownLeft,
    [PE_SHOOTING_BEAM_RIGHT] = ParticleShootingBeamRight,
    [PE_SHOOTING_BEAM_DIAG_UP_RIGHT] = ParticleShootingBeamDiagUpRight,
    [PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT] = ParticleShootingBeamDiagDownRight,
    [PE_SHOOTING_BEAM_UP_RIGHT] = ParticleShootingBeamUpRight,
    [PE_SHOOTING_BEAM_DOWN_RIGHT] = ParticleShootingBeamDownRight,
    [PE_BOMB] = ParticleBomb,
    [PE_MISSILE_TRAIL] = ParticleMissileTrail,
    [PE_SUPER_MISSILE_TRAIL] = ParticleSuperMissileTrail,
    [PE_BEAM_TRAILING_RIGHT] = ParticleBeamTrailingRight,
    [PE_BEAM_TRAILING_LEFT] = ParticleBeamTrailingLeft,
    [PE_CHARGED_LONG_BEAM_TRAIL] = ParticleChargedLongBeamTrail,
    [PE_CHARGED_ICE_BEAM_TRAIL] = ParticleChargedIceBeamTrail,
    [PE_CHARGED_WAVE_BEAM_TRAIL] = ParticleChargedWaveBeamTrail,
    [PE_CHARGED_PLASMA_BEAM_TRAIL] = ParticleChargedPlasmaBeamTrail,
    [PE_CHARGED_FULL_BEAM_TRAIL] = ParticleChargedFullBeamTrail,
    [PE_CHARGED_PISTOL_TRAIL] = ParticleChargedPistolTrail,
    [PE_SPRITE_EXPLOSION_HUGE] = ParticleSpriteExplosionHuge,
    [PE_SPRITE_EXPLOSION_SMALL] = ParticleSpriteExplosionSmall,
    [PE_SPRITE_EXPLOSION_MEDIUM] = ParticleSpriteExplosionMedium,
    [PE_SPRITE_EXPLOSION_BIG] = ParticleSpriteExplosionBig,
    [PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG] = ParticleSpriteExplosionSingleThenBig,
    [PE_SCREW_ATTACK_DESTROYED] = ParticleScrewAttackDestroyed,
    [PE_SHINESPARK_DESTROYED] = ParticleShinesparkDestroyed,
    [PE_SUDO_SCREW_DESTROYED] = ParticleSudoScrewDestroyed,
    [PE_SPEEDBOOSTER_DESTROYED] = ParticleSpeedboosterDestroyed,
    [PE_MAIN_BOSS_DEATH] = ParticleMainBossDeath,
    [PE_FREEZING_SPRITE_WITH_ICE] = ParticleFreezingSpriteWithIce,
    [PE_FREEZING_SPRITE_WITH_CHARGED_ICE] = ParticleFreezingSpriteWithChargedIce,
    [PE_HITTING_SOMETHING_WITH_NORMAL_BEAM] = ParticleHittingSomethingWithNormalBeam,
    [PE_HITTING_SOMETHING_WITH_LONG_BEAM] = ParticleHittingSomethingWithLongBeam,
    [PE_HITTING_SOMETHING_WITH_ICE_BEAM] = ParticleHittingSomethingWithIceBeam,
    [PE_HITTING_SOMETHING_WITH_WAVE_BEAM] = ParticleHittingSomethingWithWaveBeam,
    [PE_HITTING_SOMETHING_WITH_PLASMA_BEAM] = ParticleHittingSomethingWithPlasmaBeam,
    [PE_HITTING_SOMETHING_INVINCIBLE] = ParticleHittingSomethingInvincible,
    [PE_HITTING_SOMETHING_WITH_MISSILE] = ParticleHittingSomethingWithMissile,
    [PE_HITTING_SOMETHING_WITH_SUPER_MISSILE] = ParticleHittingSomethingWithSuperMissile,
    [PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA] = ParticleHittingSomethingWithFullBeamNoPlasma,
    [PE_HITTING_SOMETHING_WITH_FULL_BEAM] = ParticleHittingSomethingWithFullBeam,
    [PE_SMALL_DUST] = ParticleSmallDust,
    [PE_MEDIUM_DUST] = ParticleMediumDust,
    [PE_TWO_MEDIUM_DUST] = ParticleTwoMediumDust,
    [PE_SECOND_SMALL_DUST] = ParticleSecondSmallDust,
    [PE_SECOND_MEDIUM_DUST] = ParticleSecondMediumDust,
    [PE_SECOND_TWO_MEDIUM_DUST] = ParticleSecondTwoMediumDust,
    [PE_SAMUS_REFLECTION] = ParticleSamusReflection,
    [PE_CHARGING_BEAM] = ParticleChargingBeam,
    [PE_ESCAPE] = ParticleEscape,
};

const struct Door* const sAreaDoorsPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = sBrinstarDoors,
    [AREA_KRAID] = sKraidDoors,
    [AREA_NORFAIR] = sNorfairDoors,
    [AREA_RIDLEY] = sRidleyDoors,
    [AREA_TOURIAN] = sTourianDoors,
    [AREA_CRATERIA] = sCrateriaDoors,
    [AREA_CHOZODIA] = sChozodiaDoors
};

const struct RoomEntryROM* const sAreaRoomEntryPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = sBrinstarRoomEntries,
    [AREA_KRAID] = sKraidRoomEntries,
    [AREA_NORFAIR] = sNorfairRoomEntries,
    [AREA_RIDLEY] = sRidleyRoomEntries,
    [AREA_TOURIAN] = sTourianRoomEntries,
    [AREA_CRATERIA] = sCrateriaRoomEntries,
    [AREA_CHOZODIA] = sChozodiaRoomEntries,
};

static const u8* const sScrollPointer_Empty[] = {
    sScroll_Empty
};

static const u8* const sBrinstarScrolls[] = {
    sBrinstar_0_Scrolls,
    sBrinstar_1_Scrolls,
    sBrinstar_2_Scrolls,
    sBrinstar_3_Scrolls,
    sBrinstar_4_Scrolls,
    sBrinstar_5_Scrolls,
    sBrinstar_6_Scrolls,
    sBrinstar_7_Scrolls,
    sBrinstar_8_Scrolls,
    sBrinstar_9_Scrolls,
    sBrinstar_10_Scrolls,
    sBrinstar_11_Scrolls,
    sBrinstar_12_Scrolls,
    sBrinstar_13_Scrolls,
    sBrinstar_14_Scrolls,
    sBrinstar_15_Scrolls,
    sBrinstar_16_Scrolls,
    sBrinstar_17_Scrolls,
    sBrinstar_18_Scrolls,
    sScroll_Empty
};

static const u8* const sKraidScrolls[] = {
    sKraid_0_Scrolls,
    sKraid_1_Scrolls,
    sKraid_2_Scrolls,
    sKraid_3_Scrolls,
    sKraid_4_Scrolls,
    sKraid_5_Scrolls,
    sKraid_6_Scrolls,
    sKraid_7_Scrolls,
    sKraid_8_Scrolls,
    sKraid_9_Scrolls,
    sKraid_10_Scrolls,
    sScroll_Empty
};

static const u8* const sNorfairScrolls[] = {
    sNorfair_0_Scrolls,
    sNorfair_1_Scrolls,
    sNorfair_2_Scrolls,
    sNorfair_3_Scrolls,
    sNorfair_4_Scrolls,
    sNorfair_5_Scrolls,
    sNorfair_6_Scrolls,
    sNorfair_7_Scrolls,
    sNorfair_8_Scrolls,
    sNorfair_9_Scrolls,
    sNorfair_10_Scrolls,
    sNorfair_11_Scrolls,
    sNorfair_12_Scrolls,
    sNorfair_13_Scrolls,
    sNorfair_14_Scrolls,
    sNorfair_15_Scrolls,
    sNorfair_16_Scrolls,
    sScroll_Empty
};

static const u8* const sRidleyScrolls[] = {
    sRidley_0_Scrolls,
    sRidley_1_Scrolls,
    sRidley_2_Scrolls,
    sRidley_3_Scrolls,
    sRidley_4_Scrolls,
    sRidley_5_Scrolls,
    sRidley_6_Scrolls,
    sRidley_7_Scrolls,
    sRidley_8_Scrolls,
    sRidley_9_Scrolls,
    sRidley_10_Scrolls,
    sRidley_11_Scrolls,
    sRidley_12_Scrolls,
    sRidley_13_Scrolls,
    sScroll_Empty
};

static const u8* const sTourianScrolls[] = {
    sTourian_0_Scrolls,
    sTourian_1_Scrolls,
    sTourian_2_Scrolls,
    sTourian_3_Scrolls,
    sTourian_4_Scrolls,
    sTourian_5_Scrolls,
    sScroll_Empty
};

static const u8* const sCrateriaScrolls[] = {
    sCrateria_0_Scrolls,
    sCrateria_1_Scrolls,
    sCrateria_2_Scrolls,
    sCrateria_3_Scrolls,
    sCrateria_4_Scrolls,
    sCrateria_5_Scrolls,
    sCrateria_6_Scrolls,
    sCrateria_7_Scrolls,
    sCrateria_8_Scrolls,
    sCrateria_9_Scrolls,
    sCrateria_10_Scrolls,
    sScroll_Empty
};

static const u8* const sChozodiaScrolls[] = {
    sChozodia_0_Scrolls,
    sChozodia_1_Scrolls,
    sChozodia_2_Scrolls,
    sChozodia_3_Scrolls,
    sChozodia_4_Scrolls,
    sChozodia_5_Scrolls,
    sChozodia_6_Scrolls,
    sChozodia_7_Scrolls,
    sChozodia_8_Scrolls,
    sChozodia_9_Scrolls,
    sChozodia_10_Scrolls,
    sChozodia_11_Scrolls,
    sChozodia_12_Scrolls,
    sChozodia_13_Scrolls,
    sChozodia_14_Scrolls,
    sChozodia_15_Scrolls,
    sChozodia_16_Scrolls,
    sChozodia_17_Scrolls,
    sChozodia_18_Scrolls,
    sChozodia_19_Scrolls,
    sChozodia_20_Scrolls,
    sChozodia_21_Scrolls,
    sChozodia_22_Scrolls,
    sChozodia_23_Scrolls,
    sChozodia_24_Scrolls,
    sChozodia_25_Scrolls,
    sChozodia_26_Scrolls,
    sChozodia_27_Scrolls,
    sChozodia_28_Scrolls,
    sChozodia_29_Scrolls,
    sChozodia_30_Scrolls,
    sChozodia_31_Scrolls,
    sChozodia_32_Scrolls,
    sChozodia_33_Scrolls,
    sChozodia_34_Scrolls,
    sChozodia_35_Scrolls,
    sChozodia_36_Scrolls,
    sChozodia_37_Scrolls,
    sChozodia_38_Scrolls,
    sChozodia_39_Scrolls,
    sChozodia_40_Scrolls,
    sChozodia_41_Scrolls,
    sChozodia_42_Scrolls,
    sChozodia_43_Scrolls,
    sChozodia_44_Scrolls,
    sChozodia_45_Scrolls,
    sChozodia_46_Scrolls,
    sChozodia_47_Scrolls,
    sChozodia_48_Scrolls,
    sChozodia_49_Scrolls,
    sChozodia_50_Scrolls,
    sChozodia_51_Scrolls,
    sChozodia_52_Scrolls,
    sChozodia_53_Scrolls,
    sChozodia_54_Scrolls,
    sChozodia_55_Scrolls,
    sChozodia_56_Scrolls,
    sChozodia_57_Scrolls,
    sChozodia_58_Scrolls,
    sChozodia_59_Scrolls,
    sScroll_Empty
};

const u8* const * const sAreaScrollPointers[AREA_END] = {
    [AREA_BRINSTAR] = sBrinstarScrolls,
    [AREA_KRAID] = sKraidScrolls,
    [AREA_NORFAIR] = sNorfairScrolls,
    [AREA_RIDLEY] = sRidleyScrolls,
    [AREA_TOURIAN] = sTourianScrolls,
    [AREA_CRATERIA] = sCrateriaScrolls,
    [AREA_CHOZODIA] = sChozodiaScrolls,
    [AREA_DEBUG_1] = sScrollPointer_Empty,
    [AREA_DEBUG_2] = sScrollPointer_Empty,
    [AREA_DEBUG_3] = sScrollPointer_Empty,
    [AREA_DEBUG_4] = sScrollPointer_Empty
};

const s8 sWaterLoopCounterArray[8][2] = {
    [0] = {
        0, 9
    },
    [1] = {
        1, 9
    },
    [2] = {
        2, 21
    },
    [3] = {
        1, 9
    },
    [4] = {
        0, 9
    },
    [5] = {
        -1, 12
    },
    [6] = {
        -2, 99
    },
    [7] = {
        -1, 12
    }
};

const BlockFunc_T sNonReformDestroyFunctionPointers[5] = {
    BlockDestroySingleBreakableBlock,
    BlockDestroySquareBlock,
    BlockDestroySingleBreakableBlock,
    BlockDestroySquareBlock,
    BlockDestroyBombChainBlock
};

const ColorFadingFunc_T sColorFadingSubroutinePointers[4] = {
    ColorFadingSubroutine_Empty,
    unk_5bd58,
    unk_5bdc8,
    unk_5be7c
};

/**
 * @brief Haze data for each room effect
 * 0 : Haze value
 * 1 : Damage effect
 * 2 : BG0 water moving flag
 * 3 : Power bomb related
 */
FORCE_RODATA
u8 sHazeData[13][4] = {
    [EFFECT_NONE] = {
        HAZE_VALUE_NONE, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_WATER] = {
        HAZE_VALUE_BG3, EFFECT_WATER, TRUE, 1
    },
    [EFFECT_STRONG_LAVA] = {
        HAZE_VALUE_BG3, EFFECT_STRONG_LAVA, FALSE, 1
    },
    [EFFECT_WEAK_LAVA] = {
        HAZE_VALUE_BG3, EFFECT_WEAK_LAVA, FALSE, 1
    },
    [EFFECT_STRONG_LAVA_HEAT_HAZE] = {
        HAZE_VALUE_BG3_STRONG_WEAK, EFFECT_STRONG_LAVA_HEAT_HAZE, FALSE, 1
    },
    [EFFECT_ACID] = {
        HAZE_VALUE_BG3, EFFECT_ACID, FALSE, 1
    },
    [EFFECT_SNOWFLAKES_COLD_KNOCKBACK] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD_KNOCKBACK, FALSE, 1
    },
    [EFFECT_SNOWFLAKES_COLD] = {
        HAZE_VALUE_COLD, EFFECT_SNOWFLAKES_COLD, FALSE, 1
    },
    [EFFECT_HEAT_BG3_HAZE] = {
        HAZE_VALUE_BG3_NONE_WEAK, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_HEAT_BG2_BG3_HAZE] = {
        HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM, EFFECT_NONE, FALSE, 0
    },
    [EFFECT_BG3_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE, 2
    },
    [EFFECT_BG2_GRADIENT] = {
        HAZE_VALUE_GRADIENT, EFFECT_NONE, FALSE, 2
    },
    [EFFECT_HAZE_BG1_BG2_BG3] = {
        HAZE_VALUE_BG3_BG2_BG1, EFFECT_NONE, FALSE, 0
    }
};

// FIXME use pointer to u16[3]
const u16* const sBackgroundEffectBehaviorPointers[9] = {
    [0] = (const u16* const)sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_LIGHTNING] = (const u16* const)sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_SLIGHT_YELLOW] = (const u16* const)sBackgroundEffectBehavior_SlightYellow,
    [BACKGROUND_EFFECT_HEAVY_YELLOW] = (const u16* const)sBackgroundEffectBehavior_HeavyYellow,
    [BACKGROUND_EFFECT_EXIT_ZEBES_FADE] = (const u16* const)sBackgroundEffectBehavior_ExitZebes,
    [BACKGROUND_EFFECT_INTRO_TEXT_FADE] = (const u16* const)sBackgroundEffectBehavior_IntroText,
    [BACKGROUND_EFFECT_QUICK_FLASH] = (const u16* const)sBackgroundEffectBehavior_QuickFlash,
    [BACKGROUND_EFFECT_ALL_BLACK] = (const u16* const)sBackgroundEffectBehavior_AllBlackWhite,
    [BACKGROUND_EFFECT_ALL_WHITE] = (const u16* const)sBackgroundEffectBehavior_AllBlackWhite,
};

const struct HatchLockEvent* const sHatchLockEventsPointers[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = sHatchLockEventsBrinstar,
    [AREA_KRAID] = sHatchLockEventsKraid,
    [AREA_NORFAIR] = sHatchLockEventsNorfair,
    [AREA_RIDLEY] = sHatchLockEventsNorfair,
    [AREA_TOURIAN] = sHatchLockEventsNorfair,
    [AREA_CRATERIA] = sHatchLockEventsNorfair,
    [AREA_CHOZODIA] = sHatchLockEventsChozodia
};

const struct SaveDemo* const sDemoRamDataPointers[MAX_AMOUNT_OF_DEMOS] = {
    [0] = &sDemo0_Ram,
    [1] = &sDemo1_Ram,
    [2] = &sDemo2_Ram,
    [3] = &sDemo3_Ram,
    [4] = &sDemo4_Ram,
    [5] = &sDemo5_Ram,
    [6] = &sDemo6_Ram,
    [7] = &sDemo7_Ram,
    [8] = &sDemo8_Ram,
    [9] = &sDemo9_Ram,
    [10] = &sDemo10_Ram,
    [11] = &sDemo11_Ram,
    [12] = &sDemo12_Ram,
    [13] = &sDemo13_Ram,
    [14] = &sDemo14_Ram,
    [15] = &sDemo15_Ram,
};

const TourianEscapeFunc_T sTourianEscapeFunctionPointers[2] = {
    CutsceneDefaultRoutine,
    TourianEscapeCallSubroutines,
};

const s8 sCutsceneScreenShakeOffsets_Set0[2] = {
    -1, 1
};

const s8* const sCutsceneScreenShakeOffsetSetPointers[4] = {
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0,
    sCutsceneScreenShakeOffsets_Set0
};

const u8 sCutsceneScreenShakeOffsetSetSizes[4] = {
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0),
    ARRAY_SIZE(sCutsceneScreenShakeOffsets_Set0)
};
