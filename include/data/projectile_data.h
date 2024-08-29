#ifndef PROJECTILE_DATA_H
#define PROJECTILE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sTumblingMissileSpeed[16];

extern const u8 sProjectile_Array326cc8_Unused[64];

extern const struct FrameData sBombOam_Slow[5];

extern const struct FrameData sBombOam_Fast[5];

extern const struct FrameData sPowerBombOam_Slow[4];

extern const struct FrameData sPowerBombOam_Fast[4];

extern const struct FrameData sMissileOam_Horizontal[3];

extern const struct FrameData sMissileOam_Diagonal[3];

extern const struct FrameData sMissileOam_Vertical[3];

extern const struct FrameData sSuperMissileOam_Horizontal[3];

extern const struct FrameData sSuperMissileOam_Diagonal[3];

extern const struct FrameData sSuperMissileOam_Vertical[3];

extern const struct FrameData sMissileOam_Tumbling[9];

extern const struct FrameData sSuperMissileOam_Tumbling[9];

extern const struct FrameData sParticleMissileTrailOam[8];

extern const struct FrameData sParticleSuperMissileTrailOam[9];

extern const u16 sBeamPal[16 * 6];

extern const u8 sNormalBeamGfx_Top[512];
extern const u8 sNormalBeamGfx_Bottom[512];
extern const u8 sNormalBeamGfx_Charged_Top[512];
extern const u8 sNormalBeamGfx_Charged_Bottom[512];

extern const struct FrameData sNormalBeamOam_Horizontal[3];

extern const struct FrameData sNormalBeamOam_Diagonal[3];

extern const struct FrameData sNormalBeamOam_Vertical[3];

extern const struct FrameData sNormalBeamOam_Horizontal_Unused[3];

extern const struct FrameData sNormalBeamOam_Diagonal_Unused[3];

extern const struct FrameData sNormalBeamOam_Vertical_Unused[3];

extern const struct FrameData sChargedNormalBeamOam_Horizontal[3];

extern const struct FrameData sChargedNormalBeamOam_Diagonal[3];

extern const struct FrameData sChargedNormalBeamOam_Vertical[3];

extern const struct FrameData sChargedNormalBeamOam_Horizontal_Unused[5];

extern const u8 sLongBeamGfx_Top[512];
extern const u8 sLongBeamGfx_Bottom[512];
extern const u8 sLongBeamGfx_Charged_Top[512];
extern const u8 sLongBeamGfx_Charged_Bottom[512];

extern const struct FrameData sLongBeamOam_Horizontal[3];

extern const struct FrameData sLongBeamOam_Diagonal[3];

extern const struct FrameData sLongBeamOam_Vertical[3];

extern const struct FrameData sChargedLongBeamOam_Horizontal[3];

extern const struct FrameData sChargedLongBeamOam_Diagonal[3];

extern const struct FrameData sChargedLongBeamOam_Vertical[3];

extern const struct FrameData sParticleChargedLongBeamTrailOam[5];

extern const u8 sIceBeamGfx_Top[512];
extern const u8 sIceBeamGfx_Bottom[512];
extern const u8 sIceBeamGfx_Charged_Top[512];
extern const u8 sIceBeamGfx_Charged_Bottom[512];

extern const struct FrameData sIceBeamOam_Horizontal[3];

extern const struct FrameData sIceBeamOam_Diagonal[3];

extern const struct FrameData sIceBeamOam_Vertical[3];

extern const struct FrameData sIceBeamOam_Horizontal_Unused[3];

extern const struct FrameData sIceBeamOam_Diagonal_Unused[3];

extern const struct FrameData sIceBeamOam_Vertical_Unused[3];

extern const struct FrameData sChargedIceBeamOam_Horizontal[3];

extern const struct FrameData sChargedIceBeamOam_Diagonal[3];

extern const struct FrameData sChargedIceBeamOam_Vertical[3];

extern const struct FrameData sParticleChargedIceBeamTrailOam[6];

extern const u8 sWaveBeamGfx_Top[512];
extern const u8 sWaveBeamGfx_Bottom[512];
extern const u8 sWaveBeamGfx_Charged_Top[512];
extern const u8 sWaveBeamGfx_Charged_Bottom[512];

extern const struct FrameData sWaveBeamOam_Horizontal[8];

extern const struct FrameData sWaveBeamOam_Diagonal[8];

extern const struct FrameData sWaveBeamOam_Vertical[8];

extern const struct FrameData sWaveBeamOam_Horizontal_Unused[8];

extern const struct FrameData sWaveBeamOam_Diagonal_Unused[8];

extern const struct FrameData sWaveBeamOam_Vertical_Unused[8];

extern const struct FrameData sChargedWaveBeamOam_Horizontal[8];

extern const struct FrameData sChargedWaveBeamOam_Diagonal[8];

extern const struct FrameData sChargedWaveBeamOam_Vertical[8];

extern const struct FrameData sParticleChargedWaveBeamTrailOam[5];

extern const u8 sPlasmaBeamGfx_Top[512];
extern const u8 sPlasmaBeamGfx_Bottom[512];
extern const u8 sPlasmaBeamGfx_Charged_Top[512];
extern const u8 sPlasmaBeamGfx_Charged_Bottom[512];

extern const struct FrameData sPlasmaBeamOam_Horizontal_NoWave[3];

extern const struct FrameData sPlasmaBeamOam_Diagonal_NoWave[3];

extern const struct FrameData sPlasmaBeamOam_Vertical_NoWave[3];

extern const struct FrameData sPlasmaBeamOam_Horizontal_NoWave_Unused[3];

extern const struct FrameData sPlasmaBeamOam_Diagonal_NoWave_Unused[3];

extern const struct FrameData sPlasmaBeamOam_Vertical_NoWave_Unused[3];

extern const struct FrameData sChargedPlasmaBeamOam_Horizontal_NoWave[3];

extern const struct FrameData sChargedPlasmaBeamOam_Diagonal_NoWave[3];

extern const struct FrameData sChargedPlasmaBeamOam_Vertical_NoWave[3];

extern const struct FrameData sPlasmaBeamOam_Horizontal_Wave[8];

extern const struct FrameData sPlasmaBeamOam_Diagonal_Wave[8];

extern const struct FrameData sPlasmaBeamOam_Vertical_Wave[8];

extern const struct FrameData sPlasmaBeamOam_Horizontal_Wave_Unused[6];

extern const struct FrameData sPlasmaBeamOam_Diagonal_Wave_Unused[6];

extern const struct FrameData sPlasmaBeamOam_Vertical_Wave_Unused[6];

extern const struct FrameData sChargedPlasmaBeamOam_Horizontal_Wave[8];

extern const struct FrameData sChargedPlasmaBeamOam_Diagonal_Wave[8];

extern const struct FrameData sChargedPlasmaBeamOam_Vertical_Wave[8];

extern const struct FrameData sParticleChargedPlasmaBeamTrailOam[5];

extern const struct FrameData sParticleChargedFullBeamTrailOam[9];

extern const u8 sPistolGfx_Top[512];
extern const u8 sPistolGfx_Bottom[512];
extern const u8 sPistolGfx_Charged_Top[512];
extern const u8 sPistolGfx_Charged_Bottom[512];

extern const struct FrameData sPistolOam_Horizontal[3];

extern const struct FrameData sPistolOam_Diagonal[3];

extern const struct FrameData sPistolOam_Vertical[3];

extern const struct FrameData sChargedPistolOam_Horizontal[3];

extern const struct FrameData sChargedPistolOam_Diagonal[3];

extern const struct FrameData sChargedPistolOam_Vertical[3];

extern const struct FrameData sParticleChargedPistolTrailOam[5];

extern const struct FrameData sParticleEscapeOam_Unused[2];

extern const struct FrameData sParticleSamusReflectionOam_Unused[2];

#endif /* PROJECTILE_DATA_H */
