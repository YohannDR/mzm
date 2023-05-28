#include "data/cutscenes/ridley_spawn_data.h"
#include "cutscenes/ridley_spawn.h"
#include "gba.h"
#include "macros.h"

extern const u16 sRidleySpawnOAM_RidleyFlying_Frame0[13];
extern const u16 sRidleySpawnOAM_RidleyScreaming_Frame0[13];
extern const u16 sRidleySpawnOAM_RidleyFlyingReflection_Frame0[23];

const struct CutscenePageData sRidleySpawnPageData[4] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
};

const struct FrameData sRidleySpawnOAM_RidleyFlyingReflection[2] = {
    sRidleySpawnOAM_RidleyFlyingReflection_Frame0,
    0x80,
    NULL,
    0
};

const struct FrameData sRidleySpawnOAM_RidleyFlying[2] = {
    sRidleySpawnOAM_RidleyFlying_Frame0,
    0x80,
    NULL,
    0
};

const struct FrameData sRidleySpawnOAM_RidleyScreaming[2] = {
    sRidleySpawnOAM_RidleyScreaming_Frame0,
    0x80,
    NULL,
    0
};

const struct OamArray sRidleySpawnOam[5] = {
    [0] = {
        .pOam = sRidleySpawnOAM_RidleyFlyingReflection,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING_REFLECTION] = {
        .pOam = sRidleySpawnOAM_RidleyFlyingReflection,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING] = {
        .pOam = sRidleySpawnOAM_RidleyFlying,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING] = {
        .pOam = sRidleySpawnOAM_RidleyScreaming,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_SAMUS] = {
        .pOam = sRidleySpawnOAM_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const u16 sRidleySpawnOAM_Samus_Frame0[13] = {
    0x4,
    0xd0, OBJ_SIZE_64x64 | 0x1c0, 0x0,
    0xd0, OBJ_SIZE_64x64 | 0x0, 0x8,
    0x10, OBJ_SIZE_64x64 | 0x1c0, 0x1010,
    0x10, OBJ_SIZE_64x64 | 0x0, 0x1018
};

const u16 sRidleySpawnOAM_RidleyFlyingReflection_Frame0[23] = {
    0x7,
    0xc0, OBJ_SIZE_64x64 | 0x1a0, 0x2100,
    0xc0, OBJ_SIZE_64x64 | 0x1e0, 0x2108,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x1a0, 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x1e0, 0x2208,
    0xc0, OBJ_SIZE_64x64 | 0x20, 0x2110,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x20, 0x2210,
    0xd0, OBJ_SIZE_16x16 | 0x60, 0x1158
};

const struct FrameData sRidleySpawnOAM_Samus[2] = {
    sRidleySpawnOAM_Samus_Frame0,
    4,
    NULL,
    0
};

const u16 sRidleySpawnOAM_RidleyFlying_Frame0[13] = {
    0x4,
    0xc0, OBJ_SIZE_64x64 | 0x1c0, 0x0,
    0xc0, OBJ_SIZE_64x64 | 0x0, 0x8,
    0x0, OBJ_SIZE_64x64 | 0x1c0, 0x100,
    0x0, OBJ_SIZE_64x64 | 0x0, 0x108
};

const u16 sRidleySpawnOAM_RidleyScreaming_Frame0[13] = {
    0x4,
    0xc0, OBJ_SIZE_64x64 | 0x1c0, 0x10,
    0xc0, OBJ_SIZE_64x64 | 0x0, 0x18,
    0x0, OBJ_SIZE_64x64 | 0x1c0, 0x110,
    0x0, OBJ_SIZE_64x64 | 0x0, 0x118
};

const struct FrameData sRidleySpawnOAM_RidleyFlyingAndScreaming_Unused[3] = {
    sRidleySpawnOAM_RidleyFlying_Frame0,
    50,
    sRidleySpawnOAM_RidleyScreaming_Frame0,
    50,
    NULL,
    0
};


const u16 sRidleySpawnSamusPAL[3 * 16] = INCBIN_U16("data/cutscenes/RidleySpawn/Samus.pal");
const u16 sRidleySpawnSamusVariaPAL[3 * 16] = INCBIN_U16("data/cutscenes/RidleySpawn/SamusVaria.pal");
const u16 sRidleySpawnBackgroundPAL[13 * 16] = INCBIN_U16("data/cutscenes/RidleySpawn/Background.pal");
const u16 sRidleySpawnRidleyScreamingPAL[1 * 16] = INCBIN_U16("data/cutscenes/RidleySpawn/RidleyScreaming.pal");
const u32 sRidleySpawnBackgroundGfx[2830] = INCBIN_U32("data/cutscenes/RidleySpawn/Background.gfx.lz");
const u32 sRidleySpawnSamusAndRidleyGfx[2215] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusAndRidley.gfx.lz");
const u32 sRidleySpawnSamusHelmetFaceGfx[3164] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusHelmetFace.gfx.lz");
const u32 sRidleySpawnScreamingGfx[1663] = INCBIN_U32("data/cutscenes/RidleySpawn/RidleyScreaming.gfx.lz");
const u32 sRidleySpawnBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/RidleySpawn/Background.tt");
const u32 sRidleySpawnSamusHelmetTileTable[368] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusHelmet.tt");
const u32 sRidleySpawnSamusFaceTileTable[189] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusFace.tt");
