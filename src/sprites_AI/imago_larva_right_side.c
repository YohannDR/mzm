#include "imago_larva_right_side.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sImagoLarvaRightSideGFX[592];
const u16 sImagoLarvaRightSidePAL[32];

const u16 sImagoLarvaRightSideOAM_Frame0[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame1[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0xa00,
    0xef, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame2[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0xa00,
    0xee, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0xa02,
    0xef, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame3[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0xa00,
    0xee, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e2, OBJ_SPRITE_OAM | 0xa02,
    0xee, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0xa04,
    0xef, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame4[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0xa00,
    0xef, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0xa02,
    0xee, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0xa04,
    0xee, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xef, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame5[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xef, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xee, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xee, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xef, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame6[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xee, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xee, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xdf, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xef, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame7[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xef, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xee, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xde, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xee, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame8[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xef, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xde, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xee, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame9[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xdf, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0xa4a,
    0xef, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame11[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa18,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0xa58,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const u16 sImagoLarvaRightSideOAM_Frame12[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa1c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0xa5c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

const struct FrameData sImagoLarvaRightSideOAM[35] = {
    sImagoLarvaRightSideOAM_Frame0,
    0x6,
    sImagoLarvaRightSideOAM_Frame1,
    0x6,
    sImagoLarvaRightSideOAM_Frame2,
    0x6,
    sImagoLarvaRightSideOAM_Frame3,
    0x6,
    sImagoLarvaRightSideOAM_Frame4,
    0x6,
    sImagoLarvaRightSideOAM_Frame5,
    0x6,
    sImagoLarvaRightSideOAM_Frame6,
    0x6,
    sImagoLarvaRightSideOAM_Frame7,
    0x6,
    sImagoLarvaRightSideOAM_Frame8,
    0x6,
    sImagoLarvaRightSideOAM_Frame9,
    0x6,
    sImagoLarvaRightSideOAM_Frame0,
    0x6,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame0,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame0,
    0x3C,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame0,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame0,
    0x3C,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame0,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    sImagoLarvaRightSideOAM_Frame12,
    0x5,
    sImagoLarvaRightSideOAM_Frame11,
    0x5,
    NULL,
    0x0
};

/**
 * @brief 412a8 | 11c | Imago larva (right side) AI
 * 
 */
void ImagoLarvaRightSide(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pOam = sImagoLarvaRightSideOAM;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x0:
                SoundPlay(0xB1);
                break;

            case 0xB:
            case 0xF:
            case 0x13:
            case 0x17:
            case 0x1B:
            case 0x1F:
                SoundPlay(0xB2);
        }
    }
}