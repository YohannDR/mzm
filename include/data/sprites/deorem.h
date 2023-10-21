#ifndef DEOREM_DATA_H
#define DEOREM_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sDeoremSegmentXVelocity[33];
extern const s16 sDeoremThornYVelocity[40];

extern const u32 sDeoremGfx[1569];
extern const u16 sDeoremPal[16 * 5];

extern const struct FrameData sDeoremSegmentOam_Middle[5];
extern const struct FrameData sDeoremSegmentOam_Junction[5];
extern const struct FrameData sDeoremSegmentOam_Tail[5];
extern const struct FrameData sDeoremThornOam_Idle[2];
extern const struct FrameData sDeoremEyeOam_Idle[2];
extern const struct FrameData sDeoremEyeOam_Pulsing[6];
extern const struct FrameData sDeoremOam_ClosedSlow[5];
extern const struct FrameData sDeoremOam_Opening[5];
extern const struct FrameData sDeoremOam_OpenedSlow[5];
extern const struct FrameData sDeoremOam_Closing[5];
extern const struct FrameData sDeoremOam_Warning[9];
extern const struct FrameData sDeoremOam_GoingDown[3];
extern const struct FrameData sDeoremOam_OpenedFast[5];
extern const struct FrameData sDeoremOam_ClosedFast[5];
extern const struct FrameData sDeoremOam_Dying[5];

#endif /* DEOREM_DATA_H */
