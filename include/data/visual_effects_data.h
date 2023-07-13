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

extern const struct FrameData sParticleSpriteSplashWaterBigOam[10];
extern const struct FrameData sParticleSpriteSplashWaterHugeOam[10];
extern const struct FrameData sParticleSpriteSplashWaterSmallOam[7];
extern const struct FrameData sParticleSpriteSplashLavaBigOam[10];
extern const struct FrameData sParticleSpriteSplashLavaHugeOam[10];
extern const struct FrameData sParticleSpriteSplashLavaSmallOam[7];
extern const struct FrameData sParticleSpriteSplashAcidBigOam[10];
extern const struct FrameData sParticleSpriteSplashAcidHugeOam[10];
extern const struct FrameData sParticleSpriteSplashAcidSmallOam[7];

extern const u8 sEscapeTimerDigitsGfx[1024 * 2];
extern const u16 sParticleEscapeOam[34];

#endif /* VISUAL_EFFECTS_DATA_H */
