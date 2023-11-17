#include "data/cutscenes/ridley_in_space_data.h"
#include "cutscenes/ridley_in_space.h"
#include "gba.h"
#include "macros.h"

const struct CutsceneScrollingInfo sRidleyInSpaceScrollingInfo[2] = {
    [0] = {
        .direction = 1,
        .length = -BLOCK_SIZE * 10,
        .speed = -4,
        .maxDelay = 0
    },
    [1] = {
        .direction = 0,
        .length = -BLOCK_SIZE,
        .speed = -4,
        .maxDelay = 2
    }
};

const struct CutscenePageData sRidleyInSpacePageData[6] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1C,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [2] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [3] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_LOW_MID_PRIORITY,
        .bg = DCNT_BG2,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [5] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    }
};

const struct CutscenePaletteData sRidleyInSpacePaletteData = {
    .active = TRUE,
    .timer = 0,
    .paletteRow = 0,
    .maxTimer = 2
};

const u8 sRidleyInSpaceRedAlertPaletteRows[10] = {
    0, 1, 2, 3, 4, 5, 4, 3, 2, 1
};

extern const u16 sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0[7];
extern const u16 sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0[13];
extern const u16 sRidleyInSpaceOAM_LeftBlueShip_Frame0[4];
extern const u16 sRidleyInSpaceOAM_RightBlueShip_Frame0[4];
extern const u16 sRidleyInSpaceOAM_MotherShip_Frame0[25];
extern const u16 sRidleyInSpaceOAM_ViewOfShipParticle_Frame0[4];
extern const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame2[4];
extern const u16 sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0[4];
extern const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0[4];

const struct FrameData sRidleyInSpaceOAM_LeftBlueShip[2] = {
    sRidleyInSpaceOAM_LeftBlueShip_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_RightBlueShip[2] = {
    sRidleyInSpaceOAM_RightBlueShip_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_MotherShip[2] = {
    sRidleyInSpaceOAM_MotherShip_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_MotherShipLeavingBack[2] = {
    sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_MotherShipLeavingFront[2] = {
    sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_ViewOfShipParticle[2] = {
    sRidleyInSpaceOAM_ViewOfShipParticle_Frame0,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_387010[2] = {
    sRidleyInSpaceOAM_ShipLeavingParticle_Frame2,
    128,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_ViewOfShipParticleSecond[2] = {
    sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0,
    128,
    NULL,
    0
};

extern const struct FrameData sRidleyInSpaceOAM_39d7e8[2];
extern const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticle[5];
extern const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticleSecond[5];

const struct OamArray sRidleyInSpaceCutsceneOAM[11] = {
    [0] = {
        .pOam = sRidleyInSpaceOAM_39d7e8,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_IN_SPACE_OAM_ID_LEFT_BLUE_SHIP] = {
        .pOam = sRidleyInSpaceOAM_LeftBlueShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_RIGHT_BLUE_SHIP] = {
        .pOam = sRidleyInSpaceOAM_RightBlueShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP] = {
        .pOam = sRidleyInSpaceOAM_MotherShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_BACK] = {
        .pOam = sRidleyInSpaceOAM_MotherShipLeavingBack,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_FRONT] = {
        .pOam = sRidleyInSpaceOAM_MotherShipLeavingFront,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE] = {
        .pOam = sRidleyInSpaceOAM_ViewOfShipParticle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [7] = {
        .pOam = sRidleyInSpaceOAM_387010,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE2] = {
        .pOam = sRidleyInSpaceOAM_ViewOfShipParticleSecond,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE] = {
        .pOam = sRidleyInSpaceOAM_ShipLeavingParticle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2] = {
        .pOam = sRidleyInSpaceOAM_ShipLeavingParticleSecond,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
};

const u32 sRidleyInSpaceShipsGfx[1565] = INCBIN_U32("data/cutscenes/RidleyInSpace/Ship.gfx.lz");
const u32 sRidleyInSpaceRidleySittingGfx[3848] = INCBIN_U32("data/cutscenes/RidleyInSpace/RidleySitting.gfx.lz");
const u32 sRidleyInSpaceShipInteriorGfx[4391] = INCBIN_U32("data/cutscenes/RidleyInSpace/ShipInterior.gfx.lz");
const u32 sRidleyInSpaceRidleySuspiciousGfx[1961] = INCBIN_U32("data/cutscenes/RidleyInSpace/RidleySuspicious.gfx.lz");
const u32 sRidleyInSpaceShipInterior2Gfx[4235] = INCBIN_U32("data/cutscenes/RidleyInSpace/ShipInterior2.gfx.lz");
const u32 sRidleyInSpaceMotherShipLeavingGfx[1497] = INCBIN_U32("data/cutscenes/RidleyInSpace/MotherShipLeaving.gfx.lz");
const u32 sRidleyInSpaceSpaceBackgroundGfx[5470] = INCBIN_U32("data/cutscenes/RidleyInSpace/SpaceBackground.gfx.lz");


const u16 sRidleyInSpaceOAM_LeftBlueShip_Frame0[4] = {
    0x1,
    0xe8, OBJ_SIZE_64x64 | 0x1e0, 0x1180
};

const u16 sRidleyInSpaceOAM_RightBlueShip_Frame0[4] = {
    0x1,
    0xe8, OBJ_SIZE_64x64 | 0x1e0, 0x1188
};

const u16 sRidleyInSpaceOAM_MotherShip_Frame0[25] = {
    0x8,
    0xc0, OBJ_SIZE_64x64 | 0x188, 0x2,
    0xc0, OBJ_SIZE_64x64 | 0x1c8, 0xa,
    0xc0, OBJ_SIZE_64x64 | 0x8, 0x12,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_32x64 | 0x48, 0x1a,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x68, 0x1e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x68, 0x9e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x1d0, 0x10b,
    0x0, OBJ_SIZE_32x32 | 0x10, 0x113
};

const u16 sRidleyInSpaceOAM_39d7a6_FrameUnused[4] = {
    0x1,
    0xfc, 0x1fc, 0x21dc
};

const u16 sRidleyInSpaceOAM_39d7ae_FrameUnused[4] = {
    0x1,
    0xfc, 0x1fc, 0x21dd
};

const u16 sRidleyInSpaceOAM_39d7b6_FrameUnused[4] = {
    0x1,
    0xfc, 0x1fc, 0x21de
};

const u16 sRidleyInSpaceOAM_39d7be_FrameUnused[4] = {
    0x1,
    0xfc, 0x1fc, 0x21df
};

const u16 sRidleyInSpaceOAM_39d7c6_FrameUnused[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fc
};

const u16 sRidleyInSpaceOAM_39d7ce_FrameUnused[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fd
};

const u16 sRidleyInSpaceOAM_39d7d6_FrameUnused[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fe
};

const u16 sRidleyInSpaceOAM_39d7de_FrameUnused[4] = {
    0x1,
    0xfb, 0x1fb, 0x21ff
};

const struct FrameData sRidleyInSpaceOAM_39d7e8[2] = {
    sRidleyInSpaceOAM_LeftBlueShip_Frame0,
    4,
    NULL,
    0
};

const u16 sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0[7] = {
    0x2,
    0xd8, OBJ_SIZE_64x64 | 0x1c0, 0x10,
    0xd8, OBJ_SIZE_64x64 | 0x0, 0x18
};

const u16 sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0[13] = {
    0x4,
    0xc0, OBJ_SIZE_64x64 | 0x1c0, 0x1000,
    0xc0, OBJ_SIZE_64x64 | 0x0, 0x1008,
    0x0, OBJ_SIZE_64x64 | 0x1c0, 0x1100,
    0x0, OBJ_SIZE_64x64 | 0x0, 0x1108
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x21dc
};

const u16 sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x21dd
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x21de
};

const u16 sRidleyInSpaceOAM_ViewOfShipParticle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x21df
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fc
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame1[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fd
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame2[4] = {
    0x1,
    0xfb, 0x1fb, 0x21fe
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame3[4] = {
    0x1,
    0xfb, 0x1fb, 0x21ff
};

const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticle[5] = {
    sRidleyInSpaceOAM_ShipLeavingParticle_Frame0,
    4,
    sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0,
    4,
    sRidleyInSpaceOAM_ShipLeavingParticle_Frame2,
    4,
    sRidleyInSpaceOAM_ViewOfShipParticle_Frame0,
    4,
    NULL,
    0
};

const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticleSecond[5] = {
    sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0,
    4,
    sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame1,
    4,
    sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame2,
    4,
    sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame3,
    4,
    NULL,
    0
};

const u16 sRidleyInSpaceShipsPal[3 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/Ships.pal");
const u16 sRidleyInSpace_39d910_Pal[6 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/39d910.pal");
const u16 sRidleyInSpaceRedAlertPAL[6 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/RedAlert.pal");
const u16 sRidleyInSpaceShipInteriorPal[15 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/ShipInterior.pal");
const u16 sRidleyInSpace_39dc70_Pal[3 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/39dc70.pal");
const u16 sRidleyInSpaceSpaceBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/RidleyInSpace/SpaceBackground.pal");

const u32 sRidleyInSpaceRidleySittingTileTable[449] = INCBIN_U32("data/cutscenes/RidleyInSpace/RidleySitting.tt");
const u32 sRidleyInSpaceShipInteriorTileTable[559] = INCBIN_U32("data/cutscenes/RidleyInSpace/ShipInterior.tt");
const u32 sRidleyInSpaceRidleySuspiciousEyesOpenTileTable[287] = INCBIN_U32("data/cutscenes/RidleyInSpace/RidleySuspiciousEyesOpen.tt");
const u32 sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable[287] = INCBIN_U32("data/cutscenes/RidleyInSpace/RidleySuspiciousSquintedEyes.tt");
const u32 sRidleyInSpaceShipInteriorTileTable2[385] = INCBIN_U32("data/cutscenes/RidleyInSpace/ShipInterior2.tt");
const u32 sRidleyInSpaceSpaceBackgroundTileTable[577] = INCBIN_U32("data/cutscenes/RidleyInSpace/SPaceBackground.tt");
