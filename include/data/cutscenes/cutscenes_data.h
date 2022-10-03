#include "macros.h"
#include "types.h"
#include "cutscenes/kraid_rising.h"

#include "constants/cutscene.h"
#include "constants/event.h"

#include "structs/cutscene.h"

static const struct CutsceneInfo sCutsceneData[15] = {
    [CUTSCENE_NONE] = {
        .unk_0 = 0,
        .type = 1,
        .storyText = 0,
        .pFunction = CutsceneDefaultRoutine,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_INTRO_TEXT] = {

    },
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] = {

    },
    [CUTSCENE_COULD_I_SURVIVE] = {

    },
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] = {

    },
    [CUTSCENE_KRAID_RISING] = {
        .unk_0 = 1,
        .type = 0,
        .storyText = 0,
        .pFunction = KraidRisingSubroutine,
        .unk_8 = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_STATUE_OPENING] = {

    },
    [CUTSCENE_RIDLEY_IN_SPACE] = {

    },
    [CUTSCENE_RIDLEY_LANDING] = {

    },
    [CUTSCENE_RIDLEY_SPAWNING] = {

    },
    [CUTSCENE_ENTER_TOURIAN] = {

    },
    [CUTSCENE_BEFORE_CHARLIE] = {

    },
    [CUTSCENE_GETTING_FULLY_POWERED] = {

    },
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = {

    },
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] = {

    }
};

// Kraid rising

static const struct CutscenePageData sKraidRisingPagesData[4] = {
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = 1,
        .bg = DCNT_BG1,
        .unk_6 = 0
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 1,
        .bg = DCNT_BG1,
        .unk_6 = 0
    },
    {
        .graphicsPage = 0,
        .tiletablePage = 0xF,
        .priority = 2,
        .bg = DCNT_BG2,
        .unk_6 = 0
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .unk_6 = 0
    },
};

static const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData = {

};

static const struct CutsceneScrollingInfo sKraidRisingScrollingData = {

};

static const struct OamArray sKraidRisingCutsceneOAM[5] = {
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

static const u16 sKraidRisingOAM_Samus_Frame0[4] = {
    0x1,
    0xd0, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

static const u16 sKraidRisingOAM_Samus_Frame1[4] = {
    0x1,
    0xcf, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

static const u16 sKraidRisingOAM_Debris_Frame0[4] = {
    0x1,
    0xf8, 0x1f8, 0x1008
};

static const u16 sKraidRisingOAM_Debris_Frame1[4] = {
    0x1,
    0xf8, 0x1f8, 0x1009
};

static const u16 sKraidRisingOAM_Debris_Frame2[4] = {
    0x1,
    0xf8, 0x1f8, 0x100a
};

static const u16 sKraidRisingOAM_Debris_Frame3[4] = {
    0x1,
    0xf8, 0x1f8, 0x100b
};

static const u16 sKraidRisingOAM_SmallPuff_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x1028
};

static const u16 sKraidRisingOAM_SmallPuff_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102a
};

static const u16 sKraidRisingOAM_SmallPuff_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102c
};

static const u16 sKraidRisingOAM_SmallPuff_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102e
};

static const u16 sKraidRisingOAM_BigPuff_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1068
};

static const u16 sKraidRisingOAM_BigPuff_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x106c
};

static const u16 sKraidRisingOAM_BigPuff_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1070
};

static const u16 sKraidRisingOAM_BigPuff_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1074
};

static const struct FrameData sKraidRisingOAM_Samus[3] = {
    sKraidRisingOAM_Samus_Frame0,
    4,
    sKraidRisingOAM_Samus_Frame1,
    4,
    NULL,
    0
};

static const struct FrameData sKraidRisingOAM_Debris[5] = {
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

static const struct FrameData sKraidRisingOAM_SmallPuff[5] = {
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

static const struct FrameData sKraidRisingOAM_BigPuff[5] = {
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

static const u16 sKraidRisingCloseUpPAL[80] = INCBIN_U16("data/cutscenes/KraidRisingCloseUp.pal");
static const u16 sKraidRisingSamusPAL[16] = INCBIN_U16("data/cutscenes/KraidRisingSamus.pal");
static const u16 sKraidRisingParticlesPAL[16] = INCBIN_U16("data/cutscenes/KraidRisingParticles.pal");
static const u16 sKraidRisingSamusVariaPAL[16] = INCBIN_U16("data/cutscenes/KraidRisingSamusVaria.pal");
static const u16 sKraidRisingRisingPAL[80] = INCBIN_U16("data/cutscenes/KraidRisingRising.pal");
static const u8 sKraidRisingKraidCloseUpGFX[12348] = INCBIN_U8("data/cutscenes/KraidRisingCloseUp.gfx.lz");
static const u8 sKraidRisingOAMGFX[3012] = INCBIN_U8("data/cutscenes/KraidRisingOAM.gfx.lz");
static const u8 sKraidRisingKraidRisingGFX[6436] = INCBIN_U8("data/cutscenes/KraidRisingKraidRising.gfx.lz");
static const u8 sKraidRisingCaveBackroundGFX[5308] = INCBIN_U8("data/cutscenes/KraidRisingCaveBackround.gfx.lz");
static const u8 sKraidRisingKraidCloseUpEyesClosedTileTable[1472] = INCBIN_U8("data/cutscenes/KraidRisingKraidCloseUpEyesClosed.tt");
static const u8 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[1472] = INCBIN_U8("data/cutscenes/KraidRisingKraidCloseUpEyesBarelyOpened.tt");
static const u8 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[1472] = INCBIN_U8("data/cutscenes/KraidRisingKraidCloseUpEyesALittleOpened.tt");
static const u8 sKraidRisingKraidCloseUpEyesOpenedTileTable[1472] = INCBIN_U8("data/cutscenes/KraidRisingKraidCloseUpEyesOpened.tt");
static const u8 sKraidRisingKraidRisingTileTable[1180] = INCBIN_U8("data/cutscenes/KraidRisingKraidRising.tt");
static const u8 sKraidRisingCaveBackgroundTileTable[1180] = INCBIN_U8("data/cutscenes/KraidRisingCaveBackground.tt");
