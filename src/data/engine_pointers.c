#include "data/engine_pointers.h"
#include "macros.h"

#include "data/clipdata_data.h"
#include "data/animated_graphics_data.h"
#include "data/hatch_data.h"
#include "data/rooms_data.h"

#include "particle.h"
#include "projectile.h"
#include "color_fading.h"

#include "constants/animated_graphics.h"
#include "constants/haze.h"
#include "constants/connection.h"
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
    (const struct RoomEntryROM*)0x8340ad4,
    (const struct RoomEntryROM*)0x83414ac,
    (const struct RoomEntryROM*)0x8341e84,
    (const struct RoomEntryROM*)0x8342be0,
    (const struct RoomEntryROM*)0x834339c,
    (const struct RoomEntryROM*)0x834384c,
    (const struct RoomEntryROM*)0x8343d74,
};

const u8* const sScrollPointer_Empty = sScroll_Empty;

const u8 sTempArray_75fae4[0x294] = INCBIN_U8("data/Blob_75fae4_75fd78.bin");

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
const u8 sHazeData[13][4] = {
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

const u8 sTempArray_75fdfc[0x60] = INCBIN_U8("data/Blob_75fdfc_75fe5c.bin");
