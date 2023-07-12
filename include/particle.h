#ifndef PARTICLE_H
#define PARTICLE_H

#include "types.h"
#include "oam.h"
#include "structs/particle.h"

// Functions

void ParticleCheckOnScreen(struct ParticleEffect* pParticle);
void ParticleDraw(struct ParticleEffect* pParticle);
void ParticleProcessAll(void);
void ParticleSet(u16 yPosition, u16 xPosition, u8 effect);
u8 ParticleUpdateAnimation(struct ParticleEffect* pParticle, const struct FrameData* pOam);
void ParticleSetCurrentOamFramePointer(struct ParticleEffect* pParticle, const struct FrameData* pOam);
void ParticleSpriteSplashWaterSmall(struct ParticleEffect* pParticle);
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
void ParticleShootingBeamUpLeft(struct ParticleEffect* pParticle);
void ParticleShootingBeamUpRight(struct ParticleEffect* pParticle);
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
void ParticleHittingSomethingWithNormalBeam(struct ParticleEffect* pParticle);
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