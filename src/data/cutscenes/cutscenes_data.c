#include "data/cutscenes/cutscenes_data.h"

#include "gba.h"
#include "cutscenes/kraid_rising.h"
#include "cutscenes/ridley_landing.h"
#include "cutscenes/ridley_spawn.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"

#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/text.h"

const struct CutsceneInfo sCutsceneData[15] = {
    [CUTSCENE_NONE] = {
        .unk_0 = 0,
        .type = 1,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8060e29,//CutsceneDefaultRoutine,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_INTRO_TEXT] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_THE_TIMING,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_COULD_I_SURVIVE,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_COULD_I_SURVIVE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_EMERGENCY,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .unk_8 = 7,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x806363d,
        .unk_8 = 4,
        .fadingTimer = 50,
        .bgFading = 10, // Slow black fade
        .event = EVENT_ENTER_NORFAIR_DEMO_PLAYED
    },
    [CUTSCENE_KRAID_RISING] = {
        .unk_0 = 1,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8062b25,// KraidRisingSubroutine,
        .unk_8 = 6,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_STATUE_OPENING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8067015,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_RIDLEY_IN_SPACE] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8064419,
        .unk_8 = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_EXIT_KRAID_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_LANDING] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8065285,
        .unk_8 = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_ENTER_RIDLEY_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_SPAWNING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x80658a5,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE 
    },
    [CUTSCENE_ENTER_TOURIAN] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8067d0d,
        .unk_8 = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_ENTER_TOURIAN_DEMO_PLAYED 
    },
    [CUTSCENE_BEFORE_CHARLIE] = {
        .unk_0 = 1,
        .skippable = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8066bd1,
        .unk_8 = 5,
        .fadingTimer = 0,
        .bgFading = 9, // Slow white fade
        .event = EVENT_NONE
    },
    [CUTSCENE_GETTING_FULLY_POWERED] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x806635d,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = {
        .unk_0 = 1,
        .type = 1,
        .storyText = 0,
        .pFunction = MechaRidleySeesSamusSubroutine,
        .unk_8 = 7,
        .fadingTimer = 0,
        .bgFading = 11, // 
        .event = EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED
    },
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x80680bd,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    }
};

const u8 sUnknownPadding_36be9c[8] = {
    0, 0, 0, 0, 1, 0, 0, 0
};

// Kraid rising

const struct CutscenePageData sKraidRisingPagesData[4] = {
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    {
        .graphicsPage = 0,
        .tiletablePage = 0xF,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
};

const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData = {
    .type = 1,
    .unk_1 = 4,
    .unk_2 = 0
};

const struct CutsceneScrollingInfo sKraidRisingScrollingInfo = {
    .unk_0 = 1,
    .unk_2 = 80,
    .unk_4 = 0x804
};

const struct OamArray sKraidRisingCutsceneOAM[5] = {
    [0] = {
        .pOam = sKraidRisingOAM_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [KRAID_RISING_OAM_ID_SAMUS] = {
        .pOam = sKraidRisingOAM_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [KRAID_RISING_OAM_ID_DEBRIS] = {
        .pOam = sKraidRisingOAM_Debris,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [KRAID_RISING_OAM_ID_SMALL_PUFF] = {
        .pOam = sKraidRisingOAM_SmallPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [KRAID_RISING_OAM_ID_BIG_PUFF] = {
        .pOam = sKraidRisingOAM_BigPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    }
};

const u16 sKraidRisingOAM_Samus_Frame0[4] = {
    0x1,
    0xd0, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

const u16 sKraidRisingOAM_Samus_Frame1[4] = {
    0x1,
    0xcf, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

const u16 sKraidRisingOAM_Debris_Frame0[4] = {
    0x1,
    0xf8, 0x1f8, 0x1008
};

const u16 sKraidRisingOAM_Debris_Frame1[4] = {
    0x1,
    0xf8, 0x1f8, 0x1009
};

const u16 sKraidRisingOAM_Debris_Frame2[4] = {
    0x1,
    0xf8, 0x1f8, 0x100a
};

const u16 sKraidRisingOAM_Debris_Frame3[4] = {
    0x1,
    0xf8, 0x1f8, 0x100b
};

const u16 sKraidRisingOAM_SmallPuff_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x1028
};

const u16 sKraidRisingOAM_SmallPuff_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102a
};

const u16 sKraidRisingOAM_SmallPuff_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102c
};

const u16 sKraidRisingOAM_SmallPuff_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102e
};

const u16 sKraidRisingOAM_BigPuff_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1068
};

const u16 sKraidRisingOAM_BigPuff_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x106c
};

const u16 sKraidRisingOAM_BigPuff_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1070
};

const u16 sKraidRisingOAM_BigPuff_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1074
};

const struct FrameData sKraidRisingOAM_Samus[3] = {
    sKraidRisingOAM_Samus_Frame0,
    4,
    sKraidRisingOAM_Samus_Frame1,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOAM_Debris[5] = {
    sKraidRisingOAM_Debris_Frame0,
    4,
    sKraidRisingOAM_Debris_Frame1,
    4,
    sKraidRisingOAM_Debris_Frame2,
    4,
    sKraidRisingOAM_Debris_Frame3,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOAM_SmallPuff[5] = {
    sKraidRisingOAM_SmallPuff_Frame0,
    4,
    sKraidRisingOAM_SmallPuff_Frame1,
    4,
    sKraidRisingOAM_SmallPuff_Frame2,
    4,
    sKraidRisingOAM_SmallPuff_Frame3,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOAM_BigPuff[5] = {
    sKraidRisingOAM_BigPuff_Frame0,
    4,
    sKraidRisingOAM_BigPuff_Frame1,
    4,
    sKraidRisingOAM_BigPuff_Frame2,
    4,
    sKraidRisingOAM_BigPuff_Frame3,
    4,
    NULL,
    0
};

const u16 sKraidRisingCloseUpPAL[5 * 16] = INCBIN_U16("data/cutscenes/KraidRising/CloseUp.pal");
const u16 sKraidRisingSamusPAL[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Samus.pal");
const u16 sKraidRisingParticlesPAL[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Particles.pal");
const u16 sKraidRisingSamusVariaPAL[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/SamusVaria.pal");
const u16 sKraidRisingRisingPAL[7 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Rising.pal");
const u32 sKraidRisingKraidCloseUpGFX[3087] = INCBIN_U32("data/cutscenes/KraidRising/CloseUp.gfx.lz");
const u32 sKraidRisingOAMGFX[753] = INCBIN_U32("data/cutscenes/KraidRising/OAM.gfx.lz");
const u32 sKraidRisingKraidRisingGFX[1609] = INCBIN_U32("data/cutscenes/KraidRising/KraidRising.gfx.lz");
const u32 sKraidRisingCaveBackroundGFX[1327] = INCBIN_U32("data/cutscenes/KraidRising/CaveBackround.gfx.lz");
const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesClosed.tt");
const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesBarelyOpened.tt");
const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesALittleOpened.tt");
const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesOpened.tt");
const u32 sKraidRisingKraidRisingTileTable[295] = INCBIN_U32("data/cutscenes/KraidRising/KraidRising.tt");
const u32 sKraidRisingCaveBackgroundTileTable[370] = INCBIN_U32("data/cutscenes/KraidRising/CaveBackground.tt");

const u8 sTempArray_374d1c[0x2b814] = INCBIN_U8("data/Blob_374d1c_3a0530.bin");

// Ridley landing

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
        .unk_0 = 1,
        .unk_2 = 0x318,
        .unk_4 = 2
    },
    [1] = {
        .unk_0 = 1,
        .unk_2 = 0x178,
        .unk_4 = 3
    },
    [2] = {
        .unk_0 = 1,
        .unk_2 = 0x158,
        .unk_4 = 4
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

const u32 sRidleyLandingZebesBackgroundGFX[3167] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_1[38] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_1.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_2[59] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_2.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_3[65] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_3.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_4[88] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_4.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_5[90] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_5.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_6[97] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_6.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_7[75] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_7.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_8[40] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_8.gfx.lz");
const u32 sRidleyLandingMotherShipGFX_9[18] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_9.gfx.lz");
const u32 sCutsceneZebesMotherShipBackgroundGFX[5067] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.gfx.lz");
const u32 sCutsceneZebesGroundGFX[477] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.gfx.lz");
const u32 sCutsceneZebesRockyBackgroundGFX[1514] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesRockyBackground.gfx.lz");
const u32 sCutsceneMotherShipEscapeShipParticlesGFX[2955] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneMotherShipEscapeShipParticles.gfx.lz");
const u32 sRidleyLandingRidleyAndRockShadowGFX[2788] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyAndRock.gfx.lz");
const u32 sRidleyLandingRidleyFlyingBackgroundGFX[2970] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.gfx.lz");
const u32 sRidleyLandingZebesBackgroundTileTable[545] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.tt");
const u32 sCutsceneZebesMotherShipBackgroundTileTable[640] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.tt");
const u32 sCutscene_3b5168_TileTable[261] = INCBIN_U32("data/cutscenes/RidleyLanding/3b5168.tt");
const u32 sCutsceneZebesGroundTileTable[111] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.tt");
const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.tt");


// Ridley spawn

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
const u32 sRidleySpawnBackgroundGFX[2830] = INCBIN_U32("data/cutscenes/RidleySpawn/Background.gfx.lz");
const u32 sRidleySpawnSamusAndRidleyGFX[2215] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusAndRidley.gfx.lz");
const u32 sRidleySpawnSamusHelmetFaceGFX[3164] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusHelmetFace.gfx.lz");
const u32 sRidleySpawnScreamingGFX[1663] = INCBIN_U32("data/cutscenes/RidleySpawn/RidleyScreaming.gfx.lz");
const u32 sRidleySpawnBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/RidleySpawn/Background.tt");
const u32 sRidleySpawnSamusHelmetTileTable[368] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusHelmet.tt");
const u32 sRidleySpawnSamusFaceTileTable[189] = INCBIN_U32("data/cutscenes/RidleySpawn/SamusFace.tt");

// Mecha sees Samus

const struct CutscenePageData sMechaRidleySeesSamusPagesData[1] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    }
};

const struct OamArray sMechaSeesSamusCutsceneOAM[5] = {
    [0] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sMechaSeesSamusOAM_OpeningEye,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [2] = {
        .pOam = sMechaSeesSamusOAM_OpeningEye,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [3] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [4] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame0[109] = {
    0x24,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x109,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x10d,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x109,
    0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x10d,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x109,
    0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x10d,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x109,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x10d,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x109,
    0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x10d,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0x5,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0xd,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x8d,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x105,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x109,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x10d
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame1[109] = {
    0x24,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x112,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x116,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x112,
    0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x116,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x112,
    0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x116,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x112,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x116,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x112,
    0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x116,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0xe,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x16,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x96,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x10e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x112,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x116
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame2[73] = {
    0x18,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0x17,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1f,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x9f,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x117,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x11b,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x11f,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0x17,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x1f,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x9f,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x117,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x11b,
    0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x11f,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x1b8, OBJ_SPRITE_OAM | 0x17,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1f,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x9f,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x117,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x11b,
    0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x11f,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x64 | 0x8, OBJ_SPRITE_OAM | 0x17,
    OBJ_SHAPE_VERTICAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x1f,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x9f,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x117,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x11b,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x11f
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame0[70] = {
    0x17,
    0xb8, OBJ_SIZE_64x64 | 0x1d8, OBJ_SPRITE_OAM | 0x11c4,
    0xf8, OBJ_SIZE_64x64 | 0x1d8, OBJ_SPRITE_OAM | 0x12c4,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x13c4,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1f8, OBJ_SPRITE_OAM | 0x13c8,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_32x64 | 0x1b8, OBJ_SPRITE_OAM | 0x1240,
    0x18, OBJ_SIZE_32x32 | 0x1b8, OBJ_SPRITE_OAM | 0x1340,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x13c0,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1c0, OBJ_SPRITE_OAM | 0x1221,
    0xd0, 0x1d0, OBJ_SPRITE_OAM | 0x1223,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x1c8, OBJ_SPRITE_OAM | 0x1202,
    0xc0, 0x1d0, OBJ_SPRITE_OAM | 0x11e3,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x11cc,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x12cc,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x134c,
    0x38, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x13cc,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0x11ee,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0x126e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0x12ee,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0x136e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x1230,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x1330
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame1[91] = {
    0x1e,
    0xb8, OBJ_SIZE_64x64 | 0x1c8, OBJ_SPRITE_OAM | 0x11d4,
    0xf8, OBJ_SIZE_64x64 | 0x1c8, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x13d5,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_SIZE_16x32 | 0x1b8, OBJ_SPRITE_OAM | 0x1212,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1b8, OBJ_SPRITE_OAM | 0x1292,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1b8, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_HORIZONTAL | 0x28, 0x1b8, OBJ_SPRITE_OAM | 0x1392,
    0x38, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x13d9,
    OBJ_SHAPE_VERTICAL | 0x38, 0x0, OBJ_SPRITE_OAM | 0x13db,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x11dc,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x8, OBJ_SPRITE_OAM | 0x125c,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x11de,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x28, OBJ_SPRITE_OAM | 0x1180,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x12de,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x135e,
    0x38, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x13de,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x129c,
    0x8, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x131c,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x135c,
    0x38, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x13dc,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x30, OBJ_SPRITE_OAM | 0x112e,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x40, OBJ_SPRITE_OAM | 0x1130,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x30, OBJ_SPRITE_OAM | 0x11ae,
    0xf8, 0x40, OBJ_SPRITE_OAM | 0x11b0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x30, OBJ_SPRITE_OAM | 0x1131,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x40, OBJ_SPRITE_OAM | 0x1133,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x30, OBJ_SPRITE_OAM | 0x11b1,
    0x20, 0x40, OBJ_SPRITE_OAM | 0x11b3,
    0x28, OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x1134
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame2[94] = {
    0x1f,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x30, OBJ_SPRITE_OAM | 0x1002,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x40, OBJ_SPRITE_OAM | 0x1004,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x30, OBJ_SPRITE_OAM | 0x1082,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x40, OBJ_SPRITE_OAM | 0x1084,
    0x28, OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x1102,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x1040,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x20, OBJ_SPRITE_OAM | 0x10c0,
    0x38, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x1140,
    0x38, 0x18, OBJ_SPRITE_OAM | 0x1001,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_64x32 | 0x1c8, OBJ_SPRITE_OAM | 0x1123,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x112b,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x18, OBJ_SPRITE_OAM | 0x112d,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x11a3,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1e8, OBJ_SPRITE_OAM | 0x11a7,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x11a9,
    0xc0, 0x20, OBJ_SPRITE_OAM | 0x11a1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1b8, OBJ_SPRITE_OAM | 0x1136,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1c8, OBJ_SPRITE_OAM | 0x1138,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1b8, OBJ_SPRITE_OAM | 0x11b6,
    0x10, 0x1c8, OBJ_SPRITE_OAM | 0x11b8,
    0x8, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0x1199,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1e0, OBJ_SPRITE_OAM | 0x11bb,
    0x20, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x113c,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x11bc,
    0x20, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x113a,
    0x20, OBJ_SIZE_16x16 | 0x1b8, OBJ_SPRITE_OAM | 0x1138,
    0x30, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x117a,
    OBJ_SHAPE_HORIZONTAL | 0x18, 0x1d8, OBJ_SPRITE_OAM | 0x11f0,
    0x18, 0x1e8, OBJ_SPRITE_OAM | 0x11f2,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1b8, OBJ_SPRITE_OAM | 0x11ce,
    0x18, 0x1f0, OBJ_SPRITE_OAM | 0x11b5
};


const struct FrameData sMechaSeesSamusOAM_FocusingEye[4] = {
    sMechaSeesSamusOAM_FocusingEye_Frame0,
    10,
    sMechaSeesSamusOAM_FocusingEye_Frame1,
    8,
    sMechaSeesSamusOAM_FocusingEye_Frame2,
    10,
    NULL,
    0
};

const struct FrameData sMechaSeesSamusOAM_OpeningEye[4] = {
    sMechaSeesSamusOAM_OpeningEye_Frame0,
    10,
    sMechaSeesSamusOAM_OpeningEye_Frame1,
    8,
    sMechaSeesSamusOAM_OpeningEye_Frame2,
    2,
    NULL,
    0
};

const u32 sMechaSeesSamusMetalGFX[2382] = INCBIN_U32("data/cutscenes/MechaSeesSamus/Metal.gfx.lz");
const u32 sMechaSeesSamusCoverEyeGFX[2671] = INCBIN_U32("data/cutscenes/MechaSeesSamus/EyeCover.gfx.lz");
const u16 sMechaSeesSamusPAL[10 * 16] = INCBIN_U16("data/cutscenes/MechaSeesSamus/Palette.pal");
const u32 sMechaSeesSamusCoverMetalTileTable[368] = INCBIN_U32("data/cutscenes/MechaSeesSamus/Metal.tt");

const u8 sTempArray_3c63f0[0x9906c] = INCBIN_U8("data/Blob_3c63f0_45f45c.bin");
