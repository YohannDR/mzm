#ifndef MOTHER_BRAIN_DATA_H
#define MOTHER_BRAIN_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum MotherBrainOam {
    MOTHER_BRAIN_OAM_IDLE,
    MOTHER_BRAIN_OAM_CHARGING_BEAM,
    MOTHER_BRAIN_OAM_EYE_CLOSED,
    MOTHER_BRAIN_OAM_2fa934,
    MOTHER_BRAIN_OAM_EYE_OPENING,
    MOTHER_BRAIN_OAM_2fa984,
    MOTHER_BRAIN_OAM_EYE_DYING,
    MOTHER_BRAIN_OAM_BOTTOM,
    MOTHER_BRAIN_OAM_BEAM_SPAWNING,
    MOTHER_BRAIN_OAM_BEAM_MOVING,

    MOTHER_BRAIN_OAM_END
};

extern const struct MultiSpriteData sMotherBrainMultiSpriteData[7];

extern const u8 sMotherBrainDynamicPaletteData[19][2];

extern const u32 sMotherBrainGfx[1871];
extern const u16 sMotherBrainPal[96];

extern const u16 sMotherBrainOam_Idle_Frame0[58];

extern const u16 sMotherBrainOam_Idle_Frame1[58];

extern const u16 sMotherBrainOam_Idle_Frame2[58];

extern const u16 sMotherBrainPartOam_EyeClosed_Frame0[7];

extern const u16 sMotherBrainPartOam_EyeClosed_Frame1[7];

extern const u16 sMotherBrainPartOam_EyeClosed_Frame2[7];

extern const u16 sMotherBrainPartOam_EyeOpening_Frame1[7];

extern const u16 sMotherBrainPartOam_EyeOpening_Frame2[7];

extern const u16 sMotherBrainPartOam_EyeOpening_Frame3[7];

extern const u16 sMotherBrainPartOam_Bottom_Frame0[16];

extern const u16 sMotherBrainPartOam_Bottom_Frame1[16];

extern const u16 sMotherBrainPartOam_Bottom_Frame2[16];

extern const u16 sMotherBrainPartOam_Bottom_Frame3[16];

extern const u16 sMotherBrainPartOam_BeamSpawning_Frame0[7];

extern const u16 sMotherBrainPartOam_BeamSpawning_Frame1[16];

extern const u16 sMotherBrainPartOam_BeamSpawning_Frame2[10];

extern const u16 sMotherBrainPartOam_BeamSpawning_Frame3[10];

extern const u16 sMotherBrainBeamOam_Moving_Frame0[4];

extern const u16 sMotherBrainBeamOam_Moving_Frame1[4];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame0[70];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame2[70];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame4[70];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame6[70];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame8[70];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame10[46];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame12[37];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame14[19];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame16[19];

extern const u16 sMotherBrainGlassBreakingOam_Breaking_Frame1[4];

extern const struct FrameData sMotherBrainOam_Idle[12];

extern const struct FrameData sMotherBrainOam_ChargingBeam[5];

extern const struct FrameData sMotherBrainPartOam_EyeClosed[12];

extern const struct FrameData sMotherBrainPartOam_2fa934[5];

extern const struct FrameData sMotherBrainPartOam_EyeOpening[5];

extern const struct FrameData sMotherBrainPartOam_2fa984[8];

extern const struct FrameData sMotherBrainPartOam_EyeDying[5];

extern const struct FrameData sMotherBrainPartOam_Bottom[7];

extern const struct FrameData sMotherBrainPartOam_BeamSpawning[5];

extern const struct FrameData sMotherBrainBeamOam_Moving[3];

extern const struct FrameData sMotherBrainGlassBreakingOam_Breaking[18];

extern const struct FrameData sMotherBrainPartOam_EyeClosing[4];

#endif /* MOTHER_BRAIN_DATA_H */
