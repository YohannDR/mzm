#ifndef DRAGON_DATA_H
#define DRAGON_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sDragonFireballYMovement[40];

extern const s16 sDragonFireballOamRotation[40];

extern const u32 sDragonGfx[512];
extern const u16 sDragonPAL[32];

extern const u16 sDragonOAM_Spitting_Frame0[7];

extern const u16 sDragonOAM_Spitting_Frame1[7];

extern const u16 sDragonOAM_Idle_Frame0[7];

extern const u16 sDragonOAM_Idle_Frame1[7];

extern const u16 sDragonOAM_Idle_Frame2[13];

extern const u16 sDragonOAM_TurningAround_Frame0[7];

extern const u16 sDragonOAM_TurningAround_Frame1[7];

extern const u16 sDragonOAM_Unused_0[7];

extern const u16 sDragonOAM_Unused_1[7];

extern const u16 sDragonFireballOAM_Moving_Frame0[4];

extern const u16 sDragonFireballOAM_Moving_Frame1[4];

extern const u16 sDragonFireballOAM_Moving_Frame2[4];

extern const u16 sDragonFireballOAM_Exploding_Frame0[4];

extern const u16 sDragonFireballOAM_Exploding_Frame1[4];

extern const u16 sDragonFireballOAM_Exploding_Frame2[4];

extern const u16 sDragonFireballOAM_Exploding_Frame3[4];

extern const struct FrameData sDragonOAM_Idle[4];

extern const struct FrameData sDragonOAM_Warning[3];

extern const struct FrameData sDragonOAM_Spitting[3];

extern const struct FrameData sDragonOAM_TurningAround[3];

extern const struct FrameData sDragonOAM_TurningAroundPart2[3];

extern const struct FrameData sDragonFireballOAM_Moving[4];

extern const struct FrameData sDragonFireballOAM_Exploding[5];

#endif