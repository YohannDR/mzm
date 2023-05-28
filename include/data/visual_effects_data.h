#ifndef VISUAL_EFFECTS_DATA_H
#define VISUAL_EFFECTS_DATA_H

#include "types.h"
#include "oam.h"

extern const struct FrameData sEnvEffectOAM_RunningOnDustyGround[6];
extern const struct FrameData sEnvEffectOAM_LandingOnDustyGround[8];
extern const struct FrameData sEnvEffectOAM_TakingDamageInLava[9];
extern const struct FrameData sEnvEffectOAM_TakingDamageInAcid[9];
extern const struct FrameData sEnvEffectOAM_RunningOnWetGround[6];
extern const struct FrameData sEnvEffectOAM_LandingOnWetGround[6];
extern const struct FrameData sEnvEffectOAM_GoingOutOfWater[10];
extern const struct FrameData sEnvEffectOAM_RunningIntoWater[7];
extern const struct FrameData sEnvEffectOAM_GoingOutOfLava[10];
extern const struct FrameData sEnvEffectOAM_RunningIntoLava[7];
extern const struct FrameData sEnvEffectOAM_GoingOutOfAcid[11];
extern const struct FrameData sEnvEffectOAM_RunningIntoAcid[7];
extern const struct FrameData sEnvEffectOAM_LandingOnBubblyGround[7];
extern const struct FrameData sEnvEffectOAM_BreathingBubbles[8];
extern const struct FrameData sEnvEffectOAM_RunningOnVeryDustyGround[12];
extern const struct FrameData sEnvEffectOAM_LandingOnVeryDustyGround[18];

extern const struct FrameData sParticleSpriteSplashWaterBigOAM[10];
extern const struct FrameData sParticleSpriteSplashWaterHugeOAM[10];
extern const struct FrameData sParticleSpriteSplashWaterSmallOAM[7];
extern const struct FrameData sParticleSpriteSplashLavaBigOAM[10];
extern const struct FrameData sParticleSpriteSplashLavaHugeOAM[10];
extern const struct FrameData sParticleSpriteSplashLavaSmallOAM[7];
extern const struct FrameData sParticleSpriteSplashAcidBigOAM[10];
extern const struct FrameData sParticleSpriteSplashAcidHugeOAM[10];
extern const struct FrameData sParticleSpriteSplashAcidSmallOAM[7];

extern const u8 sEscapeTimerDigitsGfx[1024 * 2];
extern const u16 sParticleEscapeOAM[34];

#endif /* VISUAL_EFFECTS_DATA_H */
