#ifndef VISUAL_EFFECTS_DATA_H
#define VISUAL_EFFECTS_DATA_H

#include "types.h"
#include "oam.h"

extern const struct FrameData sEnvEffectOam_RunningOnDustyGround[6];
extern const struct FrameData sEnvEffectOam_LandingOnDustyGround[8];
extern const struct FrameData sEnvEffectOam_TakingDamageInLava[9];
extern const struct FrameData sEnvEffectOam_TakingDamageInAcid[9];
extern const struct FrameData sEnvEffectOam_RunningOnWetGround[6];
extern const struct FrameData sEnvEffectOam_LandingOnWetGround[6];
extern const struct FrameData sEnvEffectOam_GoingOutOfWater[10];
extern const struct FrameData sEnvEffectOam_RunningIntoWater[7];
extern const struct FrameData sEnvEffectOam_GoingOutOfLava[10];
extern const struct FrameData sEnvEffectOam_RunningIntoLava[7];
extern const struct FrameData sEnvEffectOam_GoingOutOfAcid[11];
extern const struct FrameData sEnvEffectOam_RunningIntoAcid[7];
extern const struct FrameData sEnvEffectOam_LandingOnBubblyGround[7];
extern const struct FrameData sEnvEffectOam_BreathingBubbles[8];
extern const struct FrameData sEnvEffectOam_RunningOnVeryDustyGround[12];
extern const struct FrameData sEnvEffectOam_LandingOnVeryDustyGround[18];

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
