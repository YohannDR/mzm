#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"
#include "oam.h"

// Globals

extern struct ParticleEffect pParticleEffects[16];
extern u16* gCurrentParticleEffectOAMFramePointer;
extern u16 gParticleEscapeOAMFrames[25];
extern u16 gParticleSamusReflectionOAMFrames[73];

// Defines

#define PE_SPRITE_SPLASH_WATER_SMALL 0x0
#define PE_SPRITE_SPLASH_WATER_BIG 0x1
#define PE_SPRITE_SPLASH_WATER_HUGE 0x2
#define PE_SPRITE_SPLASH_LAVA_SMALL 0x3
#define PE_SPRITE_SPLASH_LAVA_BIG 0x4
#define PE_SPRITE_SPLASH_LAVA_HUGE 0x5
#define PE_SPRITE_SPLASH_ACID_SMALL 0x6
#define PE_SPRITE_SPLASH_ACID_BIG 0x7
#define PE_SPRITE_SPLASH_ACID_HUGE 0x8
#define PE_SHOOTING_BEAM_LEFT 0x9
#define PE_SHOOTING_BEAM_DIAG_UP_LEFT 0xA
#define PE_SHOOTING_BEAM_DIAG_DOWN_LEFT 0xB
#define PE_SHOOTING_BEAM_UP_LEFT 0xC
#define PE_SHOOTING_BEAM_DOWN_LEFT 0xD
#define PE_SHOOTING_BEAM_RIGHT 0xE
#define PE_SHOOTING_BEAM_DIAG_UP_RIGHT 0xF
#define PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT 0x10
#define PE_SHOOTING_BEAM_UP_RIGHT 0x11
#define PE_SHOOTING_BEAM_DOWN_RIGHT 0x12
#define PE_BOMB 0x13
#define PE_MISSILE_TRAIL 0x14
#define PE_SUPER_MISSILE_TRAIL 0x15
#define PE_BEAM_TRAILING_RIGHT 0x16
#define PE_BEAM_TRAILING_LEFT 0x17
#define PE_CHARGED_LONG_BEAM_TRAIL 0x18
#define PE_CHARGED_ICE_BEAM_TRAIL 0x19
#define PE_CHARGED_WAVE_BEAM_TRAIL 0x1A
#define PE_CHARGED_PLASMA_BEAM_TRAIL 0x1B
#define PE_CHARGED_FULL_BEAM_TRAIL 0x1C
#define PE_CHARGED_PISTOL_TRAIL 0x1D
#define PE_SPRITE_EXPLOSION_HUGE 0x1E
#define PE_SPRITE_EXPLOSION_SMALL 0x1F
#define PE_SPRITE_EXPLOSION_MEDIUM 0x20
#define PE_SPRITE_EXPLOSION_BIG 0x21
#define PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG 0x22
#define PE_SCREW_ATTACK_DESTROYED 0x23
#define PE_SHINESPARK_DESTROYED 0x24
#define PE_SUDO_SCREW_DESTROYED 0x25
#define PE_SPEEDBOOSTER_DESTROYED 0x26
#define PE_MAIN_BOSS_DEATH 0x27
#define PE_FREEZING_SPRITE_WITH_ICE 0x28
#define PE_FREEZING_SPRITE_WITH_CHARGED_ICE 0x29
#define PE_HITTING_SOMETHING_WITH_BASE_BEAM 0x2A
#define PE_HITTING_SOMETHING_WITH_LONG_BEAM 0x2B
#define PE_HITTING_SOMETHING_WITH_ICE_BEAM 0x2C
#define PE_HITTING_SOMETHING_WITH_WAVE_BEAM 0x2D
#define PE_HITTING_SOMETHING_WITH_PLASMA_BEAM 0x2E
#define PE_HITTING_SOMETHING_INVINCIBLE 0x2F
#define PE_HITTING_SOMETHING_WITH_MISSILE 0x30
#define PE_HITTING_SOMETHING_WITH_SUPER_MISSILE 0x31
#define PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA 0x32
#define PE_HITTING_SOMETHING_WITH_FULL_BEAM 0x33
#define PE_SMALL_DUST 0x34
#define PE_MEDIUM_DUST 0x35
#define PE_TWO_MEDIUM_DUST 0x36
#define PE_SECOND_SMALL_DUST 0x37
#define PE_SECOND_MEDIUM_DUST 0x38
#define PE_SECOND_TWO_MEDIUM_DUST 0x39
#define PE_SAMUS_REFLECTION 0x3A
#define PE_CHARGING_BEAM 0x3B
#define PE_ESCAPE 0x3C

#define PARTICLE_STATUS_NONE 0x0
#define PARTICLE_STATUS_EXISTS 0x1
#define PARTICLE_STATUS_ONSCREEN 0x2
#define PARTICLE_STATUS_EXPLOSION 0x4
#define PARTICLE_STATUS_NOT_DRAWN 0x8
#define PARTICLE_STATUS_SPECIAL_EFFECT 0x10
#define PARTICLE_STATUS_LOW_PRIORITY 0x20
#define PARTICLE_STATUS_ABSOLUTE_POSITION 0x40
#define PARTICLE_STATUS_XFLIP 0x80

// Structs

struct ParticleEffect {
    u8 status;
    u8 animationDuratoinCounter;
    u8 effect;
    u8 stage;
    u8 frame_counter;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
};

// Typedefs

typedef void (*ParticleFunc_T)(struct ParticleEffect*);

// Functions

void ParticleCheckOnScreen(struct ParticleEffect* pParticle);
void ParticleDraw(struct ParticleEffect* pParticle);
void ParticleProcessAll(void);
void ParticleSet(u16 yPosition, u16 xPosition, u8 effect);
u8 ParticleUpdateAnimation(struct ParticleEffect* pParticle, struct FrameData* pOam);
void ParticleSetCurrentOAMFramePointer(struct ParticleEffect* pParticle, struct FrameData* pOam);
void ParticleSpriteSplashSmall(struct ParticleEffect* pParticle);
void ParticleSpriteSplashWaterBig(struct ParticleEffect* pParticle);
void ParticleSpriteSplashWaterHuge(struct ParticleEffect* pParticle);
void ParticleSpriteSplashLavaSmall(struct ParticleEffect* pParticle);
void ParticleSpriteSplashLavaBig(struct ParticleEffect* pParticle);
void ParticleSpriteSplashLavaHuge(struct ParticleEffect* pParticle);
void ParticleSpriteSplashAcidSmall(struct ParticleEffect* pParticle);
void ParticleSpriteSplashAcidBig(struct ParticleEffect* pParticle);
void ParticleSpriteSplashAcidHuge(struct ParticleEffect* pParticle);
void ParticleShootingBeamLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamRight(struct ParticleEffect* pParticle);
void ParticleShootingBeamDiagUpLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamDiagUpRight(struct ParticleEffect* pParticle);
void ParticleShootingBeamDiagDownLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamDiagDownRight(struct ParticleEffect* pParticle);
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle);
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle);
void ParticleBomb(struct ParticleEffect* pParticle);
void ParticleMissileTrail(struct ParticleEffect* pParticle);
void ParticleSuperMissileTrail(struct ParticleEffect* pParticle);
void ParticleBeamTrailingRight(struct ParticleEffect* pParticle);
void ParticleBeamTrailingLeft(struct ParticleEffect* pParticle);
void ParticleChargedLongBeamTrail(struct ParticleEffect* pParticle);
void ParticleChargedIceBeamTrail(struct ParticleEffect* pParticle);
void ParticleChargedWaveBeamTrail(struct ParticleEffect* pParticle);
void ParticleChargedPlasmaBeamTrail(struct ParticleEffect* pParticle);
void ParticleChargedFullBeamTrail(struct ParticleEffect* pParticle);
void ParticleChargedPistolTrail(struct ParticleEffect* pParticle);
void ParticleSpriteExplosionHuge(struct ParticleEffect* pParticle);
void ParticleSpriteExplosionSmall(struct ParticleEffect* pParticle);
void ParticleSpriteExplosionMedium(struct ParticleEffect* pParticle);
void ParticleSpriteExplosionBig(struct ParticleEffect* pParticle);
void ParticleSpriteExplosionSingleThenBig(struct ParticleEffect* pParticle);
void ParticleScrewAttackDestroyed(struct ParticleEffect* pParticle);
void ParticleShinesparkDestroyed(struct ParticleEffect* pParticle);
void ParticleSudoScrewDestroyed(struct ParticleEffect* pParticle);
void ParticleSpeedboosterDestroyed(struct ParticleEffect* pParticle);
void ParticleMainBossDeath(struct ParticleEffect* pParticle);
void ParticleFreezingSpriteWithIce(struct ParticleEffect* pParticle);
void ParticleFreezingSpriteWithChargedIce(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithBaseBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithLongBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithIceBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithWaveBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithFullBeamNoPlasma(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithPlasmaBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithFullBeam(struct ParticleEffect* pParticle);
void ParticleHittingSomethingInvincible(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithMissile(struct ParticleEffect* pParticle);
void ParticleHittingSomethingWithSuperMissile(struct ParticleEffect* pParticle);
void ParticleSmallDust(struct ParticleEffect* pParticle);
void ParticleMediumDust(struct ParticleEffect* pParticle);
void ParticleTwoMediumDust(struct ParticleEffect* pParticle);
void ParticleSecondSmallDust(struct ParticleEffect* pParticle);
void ParticleSecondMediumDust(struct ParticleEffect* pParticle);
void ParticleSecondTwoMediumDust(struct ParticleEffect* pParticle);
void ParticlePlayBeginToChargeSound(void);
void ParticleStopBeginToChargeSound(void);
void ParticlePlayBeamFullChargedSound(void);
void ParticleChargingBeam(struct ParticleEffect* pParticle);
void ParticleEscape(struct ParticleEffect* pParticle);
void ParticleSamusReflection(struct ParticleEffect* pParticle);

#endif /* PARTICLE_H */