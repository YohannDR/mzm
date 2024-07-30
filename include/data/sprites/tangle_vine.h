#ifndef TANGLE_VINE_DATA_H
#define TANGLE_VINE_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum TangleVineOam {
    TANGLE_VINE_OAM_TALL_ON_GROUND,
    TANGLE_VINE_OAM_MEDIUM_ON_GROUND,
    TANGLE_VINE_OAM_SHORT_ON_GROUND,
    TANGLE_VINE_OAM_CURVED_ON_GROUND,
    TANGLE_VINE_OAM_TALL_ON_CEILING,
    TANGLE_VINE_OAM_MEDIUM_ON_CEILING,
    TANGLE_VINE_OAM_SHORT_ON_CEILING,
    TANGLE_VINE_OAM_CURVED_ON_CEILING,
    TANGLE_VINE_OAM_GERUTA_GRIP,
    TANGLE_VINE_OAM_GERUTA_ROOT,
    TANGLE_VINE_OAM_GERUTA_FULL,
    TANGLE_VINE_OAM_RED_GERUTA_OAM,
    TANGLE_VINE_OAM_GERUTA,

    TANGLE_VINE_OAM_END
};

extern const struct MultiSpriteData sTangleVineGerutaMultiSpriteData_Idle[5];

extern const u32 sTangleVineGfx[1298];
extern const u16 sTangleVinePal[80];

extern const u16 sTangleVineTallOam_OnGround_Frame3[13];

extern const u16 sTangleVineTallOam_OnGround_Frame2[13];

extern const u16 sTangleVineTallOam_OnGround_Frame1[13];

extern const u16 sTangleVineTallOam_OnGround_Frame0[13];

extern const u16 sTangleVineTallOam_OnCeiling_Frame0[13];

extern const u16 sTangleVineTallOam_OnCeiling_Frame1[13];

extern const u16 sTangleVineTallOam_OnCeiling_Frame2[13];

extern const u16 sTangleVineTallOam_OnCeiling_Frame3[13];

extern const u16 sTangleVineMediumOam_OnGround_Frame3[10];

extern const u16 sTangleVineMediumOam_OnGround_Frame2[10];

extern const u16 sTangleVineMediumOam_OnGround_Frame1[10];

extern const u16 sTangleVineMediumOam_OnGround_Frame0[10];

extern const u16 sTangleVineMediumOam_OnCeiling_Frame0[10];

extern const u16 sTangleVineMediumOam_OnCeiling_Frame1[10];

extern const u16 sTangleVineMediumOam_OnCeiling_Frame2[10];

extern const u16 sTangleVineMediumOam_OnCeiling_Frame3[10];

extern const u16 sTangleVineShortOam_OnGround_Frame3[10];

extern const u16 sTangleVineShortOam_OnGround_Frame2[10];

extern const u16 sTangleVineShortOam_OnGround_Frame1[10];

extern const u16 sTangleVineShortOam_OnGround_Frame0[10];

extern const u16 sTangleVineShortOam_OnCeiling_Frame0[10];

extern const u16 sTangleVineShortOam_OnCeiling_Frame1[10];

extern const u16 sTangleVineShortOam_OnCeiling_Frame2[10];

extern const u16 sTangleVineShortOam_OnCeiling_Frame3[10];

extern const u16 sTangleVineCurvedOam_OnGround_Frame0[10];

extern const u16 sTangleVineCurvedOam_OnGround_Frame1[10];

extern const u16 sTangleVineCurvedOam_OnGround_Frame2[10];

extern const u16 sTangleVineCurvedOam_OnGround_Frame3[10];

extern const u16 sTangleVineCurvedOam_OnCeiling_Frame0[10];

extern const u16 sTangleVineCurvedOam_OnCeiling_Frame1[10];

extern const u16 sTangleVineCurvedOam_OnCeiling_Frame2[10];

extern const u16 sTangleVineCurvedOam_OnCeiling_Frame3[10];

extern const u16 sTangleVineOam_Unused_Frame[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame2[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame4[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame0[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame1[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame3[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame5[4];

extern const u16 sTangleVineGerutaPartOam_Grip_Frame7[4];

extern const u16 sTangleVineGerutaOam_Full_Frame0[13];

extern const u16 sTangleVineGerutaOam_Full_Frame1[10];

extern const u16 sTangleVineGerutaOam_Full_Frame2[10];

extern const u16 sTangleVineGerutaOam_Full_Frame3[13];

extern const u16 sTangleVineGerutaOam_Root_Frame0[10];

extern const u16 sTangleVineGerutaOam_Root_Frame2[7];

extern const u16 sTangleVineGerutaOam_Root_Frame4[7];

extern const u16 sTangleVineGerutaOam_Root_Frame6[7];

extern const u16 sTangleVineGerutaOam_Root_Frame1[10];

extern const u16 sTangleVineGerutaOam_Root_Frame3[7];

extern const u16 sTangleVineGerutaOam_Root_Frame5[7];

extern const u16 sTangleVineGerutaOam_Root_Frame7[7];

extern const u16 sTangleVineRedGerutaOam_Frame0[28];

extern const u16 sTangleVineRedGerutaOam_Frame1[28];

extern const u16 sTangleVineRedGerutaOam_Frame2[28];

extern const u16 sTangleVineRedGerutaOam_Frame3[28];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame0[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame2[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame4[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame6[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame1[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame3[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame5[16];

extern const u16 sTangleVineGerutaPartOam_Geruta_Frame7[16];

extern const u16 sTangleVineLarvaRightOam_Frame0[10];

extern const u16 sTangleVineLarvaRightOam_Frame1[10];

extern const u16 sTangleVineLarvaRightOam_Frame2[10];

extern const u16 sTangleVineLarvaRightOam_Frame3[10];

extern const u16 sTangleVineLarvaLeftOam_Frame0[10];

extern const u16 sTangleVineLarvaLeftOam_Frame1[10];

extern const u16 sTangleVineLarvaLeftOam_Frame2[10];

extern const u16 sTangleVineLarvaLeftOam_Frame3[10];

extern const struct FrameData sTangleVineTallOam_OnGround[5];

extern const struct FrameData sTangleVineMediumOam_OnGround[5];

extern const struct FrameData sTangleVineShortOam_OnGround[5];

extern const struct FrameData sTangleVineCurvedOam_OnGround[7];

extern const struct FrameData sTangleVineTallOam_OnCeiling[5];

extern const struct FrameData sTangleVineMediumOam_OnCeiling[5];

extern const struct FrameData sTangleVineShortOam_OnCeiling[5];

extern const struct FrameData sTangleVineCurvedOam_OnCeiling[5];

extern const struct FrameData sTangleVineGerutaPartOam_Grip[9];

extern const struct FrameData sTangleVineGerutaOam_Root[9];

extern const struct FrameData sTangleVineGerutaOam_Full[5];

extern const struct FrameData sTangleVineRedGerutaOam[5];

extern const struct FrameData sTangleVineGerutaPartOam_Geruta[9];

extern const struct FrameData sTangleVineLarvaRightOam[5];

extern const struct FrameData sTangleVineLarvaLeftOam[5];

#endif /* TANGLE_VINE_DATA_H */
