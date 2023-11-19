#ifndef PROJECTILE_DATA_H
#define PROJECTILE_DATA_H

#include "types.h"
#include "oam.h"

// 326ca8

extern const s16 sTumblingMissileSpeed[16];

extern const u8 sProjectile_Array326cc8_Unused[64];

extern const u16 sBombOAM_Frame0[4];

extern const u16 sBombOAM_Frame1[4];

extern const u16 sBombOAM_Frame2[4];

extern const u16 sBombOAM_Frame3[4];

extern const u16 sPowerBombOAM_Frame0[4];

extern const u16 sPowerBombOAM_Frame1[4];

extern const u16 sPowerBombOAM_Frame2[4];

extern const struct FrameData sBombOAM_Slow[5];

extern const struct FrameData sBombOAM_Fast[5];

extern const struct FrameData sPowerBombOAM_Slow[4];

extern const struct FrameData sPowerBombOAM_Fast[4];

extern const u16 sMissileOAM_Horizontal_Frame0[7];

extern const u16 sMissileOAM_Horizontal_Frame1[7];

extern const u16 sMissileOAM_Diagonal_Frame0[7];

extern const u16 sMissileOAM_Diagonal_Frame1[7];

extern const u16 sMissileOAM_Vertical_Frame0[7];

extern const u16 sMissileOAM_Vertical_Frame1[7];

extern const u16 sSuperMissileOAM_Horizontal_Frame0[7];

extern const u16 sSuperMissileOAM_Horizontal_Frame1[7];

extern const u16 sSuperMissileOAM_Diagonal_Frame0[7];

extern const u16 sSuperMissileOAM_Diagonal_Frame1[7];

extern const u16 sSuperMissileOAM_Vertical_Frame0[7];

extern const u16 sSuperMissileOAM_Vertical_Frame1[7];

extern const u16 sMissileOAM_Tumbling_Frame0[4];

extern const u16 sMissileOAM_Tumbling_Frame1[4];

extern const u16 sMissileOAM_Tumbling_Frame2[4];

extern const u16 sMissileOAM_Tumbling_Frame3[4];

extern const u16 sMissileOAM_Tumbling_Frame4[4];

extern const u16 sMissileOAM_Tumbling_Frame5[4];

extern const u16 sMissileOAM_Tumbling_Frame6[4];

extern const u16 sMissileOAM_Tumbling_Frame7[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame0[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame1[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame2[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame3[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame4[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame5[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame6[4];

extern const u16 sSuperMissileOAM_Tumbling_Frame7[4];

extern const u16 sParticleMissileTrailOam_Frame0[4];

extern const u16 sParticleMissileTrailOam_Frame1[4];

extern const u16 sParticleMissileTrailOam_Frame2[4];

extern const u16 sParticleSuperMissileTrailOam_Frame3[4];

extern const u16 sParticleMissileTrailOam_Frame3[4];

extern const u16 sParticleMissileTrailOam_Frame4[4];

extern const u16 sParticleMissileTrailOam_Frame5[4];

extern const u16 sParticleMissileTrailOam_Frame6[4];

extern const u16 sParticleSuperMissileTrailOam_Frame0[4];

extern const struct FrameData sMissileOAM_Horizontal[3];

extern const struct FrameData sMissileOAM_Diagonal[3];

extern const struct FrameData sMissileOAM_Vertical[3];

extern const struct FrameData sSuperMissileOAM_Horizontal[3];

extern const struct FrameData sSuperMissileOAM_Diagonal[3];

extern const struct FrameData sSuperMissileOAM_Vertical[3];

extern const struct FrameData sMissileOAM_Tumbling[9];

extern const struct FrameData sSuperMissileOAM_Tumbling[9];

extern const struct FrameData sParticleMissileTrailOam[8];

extern const struct FrameData sParticleSuperMissileTrailOam[9];

extern const u16 sBeamPAL[96];

extern const u8 sNormalBeamGfx_Top[512];
extern const u8 sNormalBeamGfx_Bottom[512];
extern const u8 sNormalBeamGfx_Charged_Top[512];
extern const u8 sNormalBeamGfx_Charged_Bottom[512];

extern const u16 sNormalBeamOAM_Horizontal_Frame0[4];

extern const u16 sNormalBeamOAM_Horizontal_Frame1[4];

extern const u16 sNormalBeamOAM_Diagonal_Frame0[4];

extern const u16 sNormalBeamOAM_Diagonal_Frame1[4];

extern const u16 sNormalBeamOAM_Vertical_Frame0[4];

extern const u16 sNormalBeamOAM_Vertical_Frame1[4];

extern const u16 sNormalBeamOAM_Horizontal_Unused_Frame0[4];

extern const u16 sNormalBeamOAM_Horizontal_Unused_Frame1[4];

extern const u16 sNormalBeamOAM_Diagonal_Unused_Frame0[4];

extern const u16 sNormalBeamOAM_Diagonal_Unused_Frame1[4];

extern const u16 sNormalBeamOAM_Vertical_Unused_Frame0[4];

extern const u16 sNormalBeamOAM_Vertical_Unused_Frame1[4];

extern const u16 sChargedNormalBeamOAM_Horizontal_Frame0[7];

extern const u16 sChargedNormalBeamOAM_Horizontal_Frame1[10];

extern const u16 sChargedNormalBeamOAM_Diagonal_Frame0[7];

extern const u16 sChargedNormalBeamOAM_Diagonal_Frame1[10];

extern const u16 sChargedNormalBeamOAM_Vertical_Frame0[7];

extern const u16 sChargedNormalBeamOAM_Vertical_Frame1[10];

extern const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame0[4];

extern const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame1[4];

extern const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame2[4];

extern const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame3[4];

extern const struct FrameData sNormalBeamOAM_Horizontal[3];

extern const struct FrameData sNormalBeamOAM_Diagonal[3];

extern const struct FrameData sNormalBeamOAM_Vertical[3];

extern const struct FrameData sNormalBeamOAM_Horizontal_Unused[3];

extern const struct FrameData sNormalBeamOAM_Diagonal_Unused[3];

extern const struct FrameData sNormalBeamOAM_Vertical_Unused[3];

extern const struct FrameData sChargedNormalBeamOAM_Horizontal[3];

extern const struct FrameData sChargedNormalBeamOAM_Diagonal[3];

extern const struct FrameData sChargedNormalBeamOAM_Vertical[3];

extern const struct FrameData sChargedNormalBeamOAM_Horizontal_Unused[5];

extern const u8 sLongBeamGfx_Top[512];
extern const u8 sLongBeamGfx_Bottom[512];
extern const u8 sLongBeamGfx_Charged_Top[512];
extern const u8 sLongBeamGfx_Charged_Bottom[512];

extern const u16 sLongBeamOAM_Horizontal_Frame0[4];

extern const u16 sLongBeamOAM_Horizontal_Frame1[4];

extern const u16 sLongBeamOAM_Diagonal_Frame0[4];

extern const u16 sLongBeamOAM_Diagonal_Frame1[4];

extern const u16 sLongBeamOAM_Vertical_Frame0[4];

extern const u16 sLongBeamOAM_Vertical_Frame1[4];

extern const u16 sChargedLongBeamOAM_Horizontal_Frame0[7];

extern const u16 sChargedLongBeamOAM_Horizontal_Frame1[10];

extern const u16 sChargedLongBeamOAM_Diagonal_Frame0[7];

extern const u16 sChargedLongBeamOAM_Diagonal_Frame1[10];

extern const u16 sChargedLongBeamOAM_Vertical_Frame0[7];

extern const u16 sChargedLongBeamOAM_Vertical_Frame1[10];

extern const u16 sParticleChargedLongBeamTrailOam_Frame0[4];

extern const u16 sParticleChargedLongBeamTrailOam_Frame1[4];

extern const u16 sParticleChargedLongBeamTrailOam_Frame2[4];

extern const u16 sParticleChargedLongBeamTrailOam_Frame3[4];

extern const struct FrameData sLongBeamOAM_Horizontal[3];

extern const struct FrameData sLongBeamOAM_Diagonal[3];

extern const struct FrameData sLongBeamOAM_Vertical[3];

extern const struct FrameData sChargedLongBeamOAM_Horizontal[3];

extern const struct FrameData sChargedLongBeamOAM_Diagonal[3];

extern const struct FrameData sChargedLongBeamOAM_Vertical[3];

extern const struct FrameData sParticleChargedLongBeamTrailOam[5];

extern const u8 sIceBeamGfx_Top[512];
extern const u8 sIceBeamGfx_Bottom[512];
extern const u8 sIceBeamGfx_Charged_Top[512];
extern const u8 sIceBeamGfx_Charged_Bottom[512];

extern const u16 sIceBeamOAM_Horizontal_Frame0[4];

extern const u16 sIceBeamOAM_Horizontal_Frame1[4];

extern const u16 sIceBeamOAM_Diagonal_Frame0[4];

extern const u16 sIceBeamOAM_Diagonal_Frame1[4];

extern const u16 sIceBeamOAM_Vertical_Frame0[4];

extern const u16 sIceBeamOAM_Vertical_Frame1[4];

extern const u16 sIceBeamOAM_Horizontal_Unused_Frame0[4];

extern const u16 sIceBeamOAM_Horizontal_Unused_Frame1[4];

extern const u16 sIceBeamOAM_Diagonal_Unused_Frame0[4];

extern const u16 sIceBeamOAM_Diagonal_Unused_Frame1[4];

extern const u16 sIceBeamOAM_Vertical_Unused_Frame0[4];

extern const u16 sIceBeamOAM_Vertical_Unused_Frame1[4];

extern const u16 sChargedIceBeamOAM_Horizontal_Frame0[13];

extern const u16 sChargedIceBeamOAM_Horizontal_Frame1[19];

extern const u16 sChargedIceBeamOAM_Diagonal_Frame0[7];

extern const u16 sChargedIceBeamOAM_Diagonal_Frame1[10];

extern const u16 sChargedIceBeamOAM_Vertical_Frame0[13];

extern const u16 sChargedIceBeamOAM_Vertical_Frame1[19];

extern const u16 sParticleChargedIceBeamTrailOam_Frame0[4];

extern const u16 sParticleChargedIceBeamTrailOam_Frame1[4];

extern const u16 sParticleChargedIceBeamTrailOam_Frame2[4];

extern const u16 sParticleChargedIceBeamTrailOam_Frame3[4];

extern const u16 sParticleChargedIceBeamTrailOam_Frame4[4];

extern const struct FrameData sIceBeamOAM_Horizontal[3];

extern const struct FrameData sIceBeamOAM_Diagonal[3];

extern const struct FrameData sIceBeamOAM_Vertical[3];

extern const struct FrameData sIceBeamOAM_Horizontal_Unused[3];

extern const struct FrameData sIceBeamOAM_Diagonal_Unused[3];

extern const struct FrameData sIceBeamOAM_Vertical_Unused[3];

extern const struct FrameData sChargedIceBeamOAM_Horizontal[3];

extern const struct FrameData sChargedIceBeamOAM_Diagonal[3];

extern const struct FrameData sChargedIceBeamOAM_Vertical[3];

extern const struct FrameData sParticleChargedIceBeamTrailOam[6];

extern const u8 sWaveBeamGfx_Top[512];
extern const u8 sWaveBeamGfx_Bottom[512];
extern const u8 sWaveBeamGfx_Charged_Top[512];
extern const u8 sWaveBeamGfx_Charged_Bottom[512];

extern const u16 sWaveBeamOAM_Horizontal_Frame0[4];

extern const u16 sWaveBeamOAM_Horizontal_Frame1[10];

extern const u16 sWaveBeamOAM_Horizontal_Frame2[10];

extern const u16 sWaveBeamOAM_Horizontal_Frame3[7];

extern const u16 sWaveBeamOAM_Horizontal_Frame4[13];

extern const u16 sWaveBeamOAM_Horizontal_Frame6[10];

extern const u16 sWaveBeamOAM_Diagonal_Frame0[4];

extern const u16 sWaveBeamOAM_Diagonal_Frame1[10];

extern const u16 sWaveBeamOAM_Diagonal_Frame2[10];

extern const u16 sWaveBeamOAM_Diagonal_Frame3[7];

extern const u16 sWaveBeamOAM_Diagonal_Frame4[13];

extern const u16 sWaveBeamOAM_Diagonal_Frame6[10];

extern const u16 sWaveBeamOAM_Vertical_Frame0[4];

extern const u16 sWaveBeamOAM_Vertical_Frame1[10];

extern const u16 sWaveBeamOAM_Vertical_Frame2[10];

extern const u16 sWaveBeamOAM_Vertical_Frame3[7];

extern const u16 sWaveBeamOAM_Vertical_Frame4[13];

extern const u16 sChargedWaveBeamOAM_Horizontal_Frame3[7];

extern const u16 sChargedWaveBeamOAM_Horizontal_Frame4[7];

extern const u16 sChargedWaveBeamOAM_Horizontal_Frame5[7];

extern const u16 sChargedWaveBeamOAM_Horizontal_Frame6[7];

extern const u16 sChargedWaveBeamOAM_Diagonal_Frame0[7];

extern const u16 sChargedWaveBeamOAM_Diagonal_Frame1[19];

extern const u16 sChargedWaveBeamOAM_Diagonal_Frame2[25];

extern const u16 sChargedWaveBeamOAM_Diagonal_Frame3[13];

extern const u16 sChargedWaveBeamOAM_Diagonal_Frame6[13];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame1[10];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame2[13];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame3[7];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame4[7];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame5[7];

extern const u16 sChargedWaveBeamOAM_Vertical_Frame6[7];

extern const u16 sParticleChargedWaveBeamTrailOam_Frame0[4];

extern const u16 sParticleChargedWaveBeamTrailOam_Frame1[7];

extern const u16 sParticleChargedWaveBeamTrailOam_Frame2[4];

extern const u16 sParticleChargedWaveBeamTrailOam_Frame3[7];

extern const struct FrameData sWaveBeamOAM_Horizontal[8];

extern const struct FrameData sWaveBeamOAM_Diagonal[8];

extern const struct FrameData sWaveBeamOAM_Vertical[8];

extern const struct FrameData sWaveBeamOAM_Horizontal_Unused[8];

extern const struct FrameData sWaveBeamOAM_Diagonal_Unused[8];

extern const struct FrameData sWaveBeamOAM_Vertical_Unused[8];

extern const struct FrameData sChargedWaveBeamOAM_Horizontal[8];

extern const struct FrameData sChargedWaveBeamOAM_Diagonal[8];

extern const struct FrameData sChargedWaveBeamOAM_Vertical[8];

extern const struct FrameData sParticleChargedWaveBeamTrailOam[5];

extern const u8 sPlasmaBeamGfx_Top[512];
extern const u8 sPlasmaBeamGfx_Bottom[512];
extern const u8 sPlasmaBeamGfx_Charged_Top[512];
extern const u8 sPlasmaBeamGfx_Charged_Bottom[512];

extern const u16 sPlasmaBeamOAM_Horizontal_NoWave_Frame0[4];

extern const u16 sPlasmaBeamOAM_Horizontal_NoWave_Frame1[4];

extern const u16 sPlasmaBeamOAM_Diagonal_NoWave_Frame0[4];

extern const u16 sPlasmaBeamOAM_Diagonal_NoWave_Frame1[4];

extern const u16 sPlasmaBeamOAM_Vertical_NoWave_Frame0[4];

extern const u16 sPlasmaBeamOAM_Vertical_NoWave_Frame1[4];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame0[10];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame1[16];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame0[13];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame1[19];

extern const u16 sChargedPlasmaBeamOAM_Vertical_NoWave_Frame0[13];

extern const u16 sChargedPlasmaBeamOAM_Vertical_NoWave_Frame1[19];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame1[10];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame2[13];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame3[10];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame4[16];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame5[13];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame3[10];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame4[16];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame5[13];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Frame3[10];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Frame4[16];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Frame5[13];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Frame6[10];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame3[19];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame4[13];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame1[10];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame2[16];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame3[16];

extern const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame4[10];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame0[4];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame1[13];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame2[16];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame3[10];

extern const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame4[13];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame0[7];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame1[19];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame2[25];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame3[19];

extern const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame4[19];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame3[19];

extern const u16 sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame4[13];

extern const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame0[7];

extern const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame1[19];

extern const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame2[25];

extern const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame3[19];

extern const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame4[19];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame1[19];

extern const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame2[13];

extern const u16 sParticleChargedPlasmaBeamTrailOam_Frame0[4];

extern const u16 sParticleChargedFullBeamTrailOam_Frame5[4];

extern const u16 sParticleChargedFullBeamTrailOam_Frame6[4];

extern const u16 sParticleChargedPlasmaBeamTrailOam_Frame3[4];

extern const struct FrameData sPlasmaBeamOAM_Horizontal_NoWave[3];

extern const struct FrameData sPlasmaBeamOAM_Diagonal_NoWave[3];

extern const struct FrameData sPlasmaBeamOAM_Vertical_NoWave[3];

extern const struct FrameData sPlasmaBeamOAM_Horizontal_NoWave_Unused[3];

extern const struct FrameData sPlasmaBeamOAM_Diagonal_NoWave_Unused[3];

extern const struct FrameData sPlasmaBeamOAM_Vertical_NoWave_Unused[3];

extern const struct FrameData sChargedPlasmaBeamOAM_Horizontal_NoWave[3];

extern const struct FrameData sChargedPlasmaBeamOAM_Diagonal_NoWave[3];

extern const struct FrameData sChargedPlasmaBeamOAM_Vertical_NoWave[3];

extern const struct FrameData sPlasmaBeamOAM_Horizontal_Wave[8];

extern const struct FrameData sPlasmaBeamOAM_Diagonal_Wave[8];

extern const struct FrameData sPlasmaBeamOAM_Vertical_Wave[8];

extern const struct FrameData sPlasmaBeamOAM_Horizontal_Wave_Unused[6];

extern const struct FrameData sPlasmaBeamOAM_Diagonal_Wave_Unused[6];

extern const struct FrameData sPlasmaBeamOAM_Vertical_Wave_Unused[6];

extern const struct FrameData sChargedPlasmaBeamOAM_Horizontal_Wave[8];

extern const struct FrameData sChargedPlasmaBeamOAM_Diagonal_Wave[8];

extern const struct FrameData sChargedPlasmaBeamOAM_Vertical_Wave[8];

extern const struct FrameData sParticleChargedPlasmaBeamTrailOam[5];

extern const struct FrameData sParticleChargedFullBeamTrailOam[9];

extern const u8 sPistolGfx_Top[512];
extern const u8 sPistolGfx_Bottom[512];
extern const u8 sPistolGfx_Charged_Top[512];
extern const u8 sPistolGfx_Charged_Bottom[512];

extern const u16 sPistolOAM_Horizontal_Frame0[4];

extern const u16 sPistolOAM_Horizontal_Frame1[4];

extern const u16 sPistolOAM_Diagonal_Frame0[4];

extern const u16 sPistolOAM_Diagonal_Frame1[4];

extern const u16 sPitsolOAM_Vertical_Frame0[4];

extern const u16 sPitsolOAM_Vertical_Frame1[4];

extern const u16 sChargedPistolOAM_Horizontal_Frame0[7];

extern const u16 sChargedPistolOAM_Horizontal_Frame1[10];

extern const u16 sChargedPistolOAM_Diagonal_Frame0[7];

extern const u16 sChargedPistolOAM_Diagonal_Frame1[10];

extern const u16 sChargedPistolOAM_Vertical_Frame0[7];

extern const u16 sChargedPistolOAM_Vertical_Frame1[10];

extern const u16 sParticleChargedPistolTrailOam_Frame0[4];

extern const u16 sParticleChargedPistolTrailOam_Frame1[4];

extern const u16 sParticleChargedPistolTrailOam_Frame2[4];

extern const u16 sParticleChargedPistolTrailOam_Frame3[4];

extern const struct FrameData sPistolOAM_Horizontal[3];

extern const struct FrameData sPistolOAM_Diagonal[3];

extern const struct FrameData sPistolOAM_Vertical[3];

extern const struct FrameData sChargedPistolOAM_Horizontal[3];

extern const struct FrameData sChargedPistolOAM_Diagonal[3];

extern const struct FrameData sChargedPistolOAM_Vertical[3];

extern const struct FrameData sParticleChargedPistolTrailOam[5];

extern const struct FrameData sParticleEscapeOam_Unused[2];

extern const struct FrameData sParticleSamusReflectionOAM_Unused[2];

// 32ba08

#endif