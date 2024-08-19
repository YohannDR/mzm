#ifndef DRAGON_DATA_H
#define DRAGON_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sDragonFireballYMovement[40];

extern const s16 sDragonFireballOamRotation[40];

extern const u32 sDragonGfx[512];
extern const u16 sDragonPal[16 * 2];

extern const struct FrameData sDragonOam_Idle[4];

extern const struct FrameData sDragonOam_Warning[3];

extern const struct FrameData sDragonOam_Spitting[3];

extern const struct FrameData sDragonOam_TurningAround[3];

extern const struct FrameData sDragonOam_TurningAroundPart2[3];

extern const struct FrameData sDragonFireballOam_Moving[4];

extern const struct FrameData sDragonFireballOam_Exploding[5];

#endif /* DRAGON_DATA_H */
