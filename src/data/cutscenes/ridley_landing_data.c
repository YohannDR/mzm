#include "data/cutscenes/ridley_landing_data.h"
#include "cutscenes/ridley_landing.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sRidleyLandingPageData[5] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x12,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x8000
    },
    [2] = {
        .graphicsPage = 2,
        .tiletablePage = 0x14,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 2,
        .tiletablePage = 0x15,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

const struct CutsceneScrollingInfo sRidleyLandingScrollingInfo[3] = {
    [0] = {
        .direction = 1,
        .length = 0x318,
        .speed = 2,
        .maxDelay = 0
    },
    [1] = {
        .direction = 1,
        .length = 0x178,
        .speed = 3,
        .maxDelay = 0
    },
    [2] = {
        .direction = 1,
        .length = 0x158,
        .speed = 4,
        .maxDelay = 0
    }
};


extern const u16 sRidleyLandingOAM_ShipBottomPart_Frame0[13];
extern const u16 sRidleyLandingOAM_ShipMiddlePart_Frame0[13];
extern const u16 sRidleyLandingOAM_ShipTopPart_Frame0[7];
extern const u16 sRidleyLandingOAM_Ridley_Frame0[7];
extern const struct FrameData sRidleyLandingOAM_ShipInSpace[2];
extern const struct FrameData sRidleyLandingOAM_SmokeParticles[7];
extern const struct FrameData sRidleyLandingOAM_Rocks[5];

const struct FrameData sRidleyLandingOAM_ShipBottomPart[2] = {
    sRidleyLandingOAM_ShipBottomPart_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyLandingOAM_ShipMiddlePart[2] = {
    sRidleyLandingOAM_ShipMiddlePart_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyLandingOAM_ShipTopPart[2] = {
    sRidleyLandingOAM_ShipTopPart_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyLandingOAM_Ridley[2] = {
    sRidleyLandingOAM_Ridley_Frame0,
    128,
    NULL,
    0
};

const struct OamArray sRidleyLandingCutsceneOAM[11] = {
    [0] = {
        .pOam = sRidleyLandingOAM_ShipInSpace,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_IN_SPACE] = {
        .pOam = sRidleyLandingOAM_ShipInSpace,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }, 
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_BOTTOM_PART] = {
        .pOam = sRidleyLandingOAM_ShipBottomPart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_MIDDLE_PART] = {
        .pOam = sRidleyLandingOAM_ShipMiddlePart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_TOP_PART] = {
        .pOam = sRidleyLandingOAM_ShipTopPart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES_DISAPPEARING] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [7] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [RIDLEY_LANDING_OAM_ID_RIDLEY] = {
        .pOam = sRidleyLandingOAM_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_ROCKS] = {
        .pOam = sRidleyLandingOAM_Rocks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_ROCKS_AND_RIDLEY_SHADOW] = {
        .pOam = sRidleyLandingOAM_Rocks,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
};

const u16 sRidleyLandingOAM_ShipInSpace_Frame0[10] = {
    0x3,
    0xd8, OBJ_SIZE_64x64 | 0x1c8, OBJ_SPRITE_OAM | 0x0,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_32x64 | 0x8, OBJ_SPRITE_OAM | 0x8,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0xac
};

const struct FrameData sRidleyLandingOAM_ShipInSpace[2] = {
    sRidleyLandingOAM_ShipInSpace_Frame0,
    4,
    NULL,
    0
};

const u16 sRidleyLandingOAM_ShipBottomPart_Frame0[13] = {
    0x4,
    0x0, OBJ_SIZE_64x64 | 0x180, 0x200,
    0x0, OBJ_SIZE_64x64 | 0x1c0, 0x208,
    0x0, OBJ_SIZE_64x64 | 0x0, 0x210,
    0x0, OBJ_SIZE_64x64 | 0x40, 0x218
};

const u16 sRidleyLandingOAM_ShipMiddlePart_Frame0[13] = {
    0x4,
    0xc0, OBJ_SIZE_64x64 | 0x180, 0x100,
    0xc0, OBJ_SIZE_64x64 | 0x1c0, 0x108,
    0xc0, OBJ_SIZE_64x64 | 0x0, 0x110,
    0xc0, OBJ_SIZE_64x64 | 0x40, 0x118
};

const u16 sRidleyLandingOAM_ShipTopPart_Frame0[7] = {
    0x2,
    0x80, OBJ_SIZE_64x64 | 0x1c0, 0x8,
    0x80, OBJ_SIZE_64x64 | 0x0, 0x10
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame0[61] = {
    0x14,
    0xe8, OBJ_SIZE_16x16 | 0x1b0, 0x1360,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1c0, 0x1362,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b0, 0x13a0,
    0xf8, 0x1c0, 0x13a2,
    0xe8, OBJ_SIZE_16x16 | 0x30, 0x1360,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x40, 0x1362,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x30, 0x13a0,
    0xf8, 0x40, 0x13a2,
    0xf8, OBJ_SIZE_16x16 | 0x20, 0x13c0,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x1363,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x18, 0x1365,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x8, 0x13a3,
    0x0, 0x18, 0x13a5,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x1363,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1d8, 0x1365,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1c8, 0x13a3,
    0x0, 0x1d8, 0x13a5,
    0x0, 0x1a8, 0x1340,
    0xe8, OBJ_SIZE_16x16 | 0x28, 0x13c6,
    0xf0, OBJ_SIZE_16x16 | 0x1c0, 0x13c6
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame1[64] = {
    0x15,
    0xe8, OBJ_SIZE_16x16 | 0x1b0, 0x1363,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1c0, 0x1365,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b0, 0x13a3,
    0xf8, 0x1c0, 0x13a5,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x1366,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1d8, 0x1368,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1c8, 0x13a6,
    0x0, 0x1d8, 0x13a8,
    0xe8, OBJ_SIZE_16x16 | 0x30, 0x1363,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x40, 0x1365,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x30, 0x13a3,
    0xf8, 0x40, 0x13a5,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x1366,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x18, 0x1368,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x8, 0x13a6,
    0x0, 0x18, 0x13a8,
    0xf8, OBJ_SIZE_16x16 | 0x20, 0x13c2,
    0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x13c0,
    0x0, 0x1a8, 0x1341,
    0xf0, OBJ_SIZE_16x16 | 0x48, 0x13c0,
    0xf8, 0x1f0, 0x1340
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame2[82] = {
    0x1b,
    0xf0, OBJ_SIZE_16x16 | 0x1c0, 0x13c0,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x1360,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x10, 0x1362,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x0, 0x13a0,
    0xf8, 0x10, 0x13a2,
    0xe8, OBJ_SIZE_16x16 | 0x1b0, 0x1366,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1c0, 0x1368,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b0, 0x13a6,
    0xf8, 0x1c0, 0x13a8,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x1369,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1d8, 0x136b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1c8, 0x13a9,
    0x0, 0x1d8, 0x13ab,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x1369,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x18, 0x136b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x8, 0x13a9,
    0x0, 0x18, 0x13ab,
    0xe8, OBJ_SIZE_16x16 | 0x30, 0x1366,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x40, 0x1368,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x30, 0x13a6,
    0xf8, 0x40, 0x13a8,
    0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x13c2,
    0xf8, 0x1f0, 0x1341,
    0x0, 0x1a8, 0x1342,
    0xf0, OBJ_SIZE_16x16 | 0x48, 0x13c2,
    0xf8, OBJ_SIZE_16x16 | 0x20, 0x13c4,
    0xe8, OBJ_SIZE_16x16 | 0x28, 0x13c0
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame3[58] = {
    0x13,
    0xf0, OBJ_SIZE_16x16 | 0x1c0, 0x13c2,
    0xe8, OBJ_SIZE_16x16 | 0x1b0, 0x1369,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1c0, 0x136b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1b0, 0x13a9,
    0xf8, 0x1c0, 0x13ab,
    0xe8, OBJ_SIZE_16x16 | 0x30, 0x1369,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x40, 0x136b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x30, 0x13a9,
    0xf8, 0x40, 0x13ab,
    0xf8, OBJ_SIZE_16x16 | 0x20, 0x13c6,
    0xf8, 0x1f0, 0x1342,
    0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x13c4,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x1363,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x10, 0x1365,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x0, 0x13a3,
    0xf8, 0x10, 0x13a5,
    0x0, 0x1a8, 0x1343,
    0xe8, OBJ_SIZE_16x16 | 0x28, 0x13c2,
    0xf0, OBJ_SIZE_16x16 | 0x48, 0x13c4
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame4[28] = {
    0x9,
    0xf8, 0x1f0, 0x1343,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x1366,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x10, 0x1368,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x0, 0x13a6,
    0xf8, 0x10, 0x13a8,
    0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x13c6,
    0xf0, OBJ_SIZE_16x16 | 0x48, 0x13c6,
    0xf0, OBJ_SIZE_16x16 | 0x1c0, 0x13c4,
    0xe8, OBJ_SIZE_16x16 | 0x28, 0x13c4
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame5[22] = {
    0x7,
    0xf8, 0x1f0, 0x1343,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x1360,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x20, 0x1362,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x10, 0x13a0,
    0x0, 0x20, 0x13a2,
    0xe8, OBJ_SIZE_16x16 | 0x28, 0x13c6,
    0xf0, OBJ_SIZE_16x16 | 0x1c0, 0x13c6
};

const struct FrameData sRidleyLandingOAM_SmokeParticles[7] = {
    sRidleyLandingOAM_SmokeParticles_Frame0,
    4,
    sRidleyLandingOAM_SmokeParticles_Frame1,
    4,
    sRidleyLandingOAM_SmokeParticles_Frame2,
    4,
    sRidleyLandingOAM_SmokeParticles_Frame3,
    4,
    sRidleyLandingOAM_SmokeParticles_Frame4,
    4,
    sRidleyLandingOAM_SmokeParticles_Frame5,
    4,
    NULL,
    0
};

const u16 sRidleyLandingOAM_Ridley_Frame0[7] = {
    0x2,
    0xd8, OBJ_SIZE_64x64 | 0x1c8, 0x0,
    0xd8, OBJ_SIZE_64x64 | 0x8, 0x8
};

const u16 sRidleyLandingOAM_Rocks_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1c0, 0x1070,
    0xe0, OBJ_SIZE_64x64 | 0x0, 0x1078,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x20, 0x101c,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x8 | 0x20, 0x105c,
    0x10, OBJ_SIZE_16x16 | 0x1b0, 0x112e
};

const u16 sRidleyLandingOAM_Rocks_Frame1[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x0, 0x1308,
    0x10, OBJ_SIZE_16x16 | 0x1b0, 0x12c4,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x20, 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x8 | 0x20, 0x12ec,
    0xe0, OBJ_SIZE_64x64 | 0x1c0, 0x1300
};

const u16 sRidleyLandingOAM_Rocks_Frame2[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x0, 0x1318,
    0xe0, OBJ_SIZE_64x64 | 0x1c0, 0x1310,
    0x10, OBJ_SIZE_16x16 | 0x1b0, 0x12c0,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x20, 0x12bc,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x8 | 0x20, 0x12fc
};

const u16 sRidleyLandingOAM_Rocks_Frame3[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x0, 0x11b8,
    0xe0, OBJ_SIZE_64x64 | 0x1c0, 0x11b0,
    0x10, OBJ_SIZE_16x16 | 0x1b0, 0x126e,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x20, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x30, 0x101e
};

const struct FrameData sRidleyLandingOAM_Rocks[5] = {
    sRidleyLandingOAM_Rocks_Frame0,
    4,
    sRidleyLandingOAM_Rocks_Frame1,
    4,
    sRidleyLandingOAM_Rocks_Frame2,
    4,
    sRidleyLandingOAM_Rocks_Frame3,
    4,
    NULL,
    0
};



const u16 sCutscene_3a09d4_PAL[9 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/3a09d4.pal");
const u16 sCutsceneZebesPAL[13 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/CutsceneZebes.pal");
const u16 sCutsceneMotherShipPAL[5 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/CutsceneMotherShip.pal");
const u16 sRidleyLandingRidleyAndRocksPAL[2 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/Objects.pal");
const u16 sRidleyLandingSkyBackgroundPAL[5 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/SkyBackground.pal");

const u32 sRidleyLandingZebesBackgroundGfx[3167] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_1[38] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_1.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_2[59] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_2.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_3[65] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_3.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_4[88] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_4.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_5[90] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_5.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_6[97] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_6.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_7[75] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_7.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_8[40] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_8.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_9[18] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_9.gfx.lz");
const u32 sCutsceneZebesMotherShipBackgroundGfx[5067] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.gfx.lz");
const u32 sCutsceneZebesGroundGfx[477] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.gfx.lz");
const u32 sCutsceneZebesRockyBackgroundGfx[1514] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesRockyBackground.gfx.lz");
const u32 sCutsceneMotherShipEscapeShipParticlesGfx[2955] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneMotherShipEscapeShipParticles.gfx.lz");
const u32 sRidleyLandingRidleyAndRockShadowGfx[2788] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyAndRock.gfx.lz");
const u32 sRidleyLandingRidleyFlyingBackgroundGfx[2970] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.gfx.lz");
const u32 sRidleyLandingZebesBackgroundTileTable[545] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.tt");
const u32 sCutsceneZebesMotherShipBackgroundTileTable[640] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.tt");
const u32 sCutscene_3b5168_TileTable[261] = INCBIN_U32("data/cutscenes/RidleyLanding/3b5168.tt");
const u32 sCutsceneZebesGroundTileTable[111] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.tt");
const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.tt");