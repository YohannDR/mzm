#include "data/cutscenes/kraid_rising_data.h"
#include "cutscenes/kraid_rising.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sKraidRisingPagesData[4] = {
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 0,
        .tiletablePage = 0xF,
        .priority = BGCNT_LOW_MID_PRIORITY,
        .bg = DCNT_BG2,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
};

const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData = {
    .type = 1,
    .maxDelay = 4,
    .set = 0
};

const struct CutsceneScrollingInfo sKraidRisingScrollingInfo = {
    .direction = 1,
    .length = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
    .speed = 4,
    .maxDelay = 8
};

const struct OamArray sKraidRisingCutsceneOam[5] = {
    [0] = {
        .pOam = sKraidRisingOam_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [KRAID_RISING_OAM_ID_SAMUS] = {
        .pOam = sKraidRisingOam_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [KRAID_RISING_OAM_ID_DEBRIS] = {
        .pOam = sKraidRisingOam_Debris,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [KRAID_RISING_OAM_ID_SMALL_PUFF] = {
        .pOam = sKraidRisingOam_SmallPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [KRAID_RISING_OAM_ID_BIG_PUFF] = {
        .pOam = sKraidRisingOam_BigPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    }
};

const u16 sKraidRisingOam_Samus_Frame0[4] = {
    0x1,
    0xd0, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

const u16 sKraidRisingOam_Samus_Frame1[4] = {
    0x1,
    0xcf, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

const u16 sKraidRisingOam_Debris_Frame0[4] = {
    0x1,
    0xf8, 0x1f8, 0x1008
};

const u16 sKraidRisingOam_Debris_Frame1[4] = {
    0x1,
    0xf8, 0x1f8, 0x1009
};

const u16 sKraidRisingOam_Debris_Frame2[4] = {
    0x1,
    0xf8, 0x1f8, 0x100a
};

const u16 sKraidRisingOam_Debris_Frame3[4] = {
    0x1,
    0xf8, 0x1f8, 0x100b
};

const u16 sKraidRisingOam_SmallPuff_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x1028
};

const u16 sKraidRisingOam_SmallPuff_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102a
};

const u16 sKraidRisingOam_SmallPuff_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102c
};

const u16 sKraidRisingOam_SmallPuff_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x102e
};

const u16 sKraidRisingOam_BigPuff_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1068
};

const u16 sKraidRisingOam_BigPuff_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x106c
};

const u16 sKraidRisingOam_BigPuff_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1070
};

const u16 sKraidRisingOam_BigPuff_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, 0x1074
};

const struct FrameData sKraidRisingOam_Samus[3] = {
    sKraidRisingOam_Samus_Frame0,
    4,
    sKraidRisingOam_Samus_Frame1,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOam_Debris[5] = {
    sKraidRisingOam_Debris_Frame0,
    4,
    sKraidRisingOam_Debris_Frame1,
    4,
    sKraidRisingOam_Debris_Frame2,
    4,
    sKraidRisingOam_Debris_Frame3,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOam_SmallPuff[5] = {
    sKraidRisingOam_SmallPuff_Frame0,
    4,
    sKraidRisingOam_SmallPuff_Frame1,
    4,
    sKraidRisingOam_SmallPuff_Frame2,
    4,
    sKraidRisingOam_SmallPuff_Frame3,
    4,
    NULL,
    0
};

const struct FrameData sKraidRisingOam_BigPuff[5] = {
    sKraidRisingOam_BigPuff_Frame0,
    4,
    sKraidRisingOam_BigPuff_Frame1,
    4,
    sKraidRisingOam_BigPuff_Frame2,
    4,
    sKraidRisingOam_BigPuff_Frame3,
    4,
    NULL,
    0
};

const u16 sKraidRisingCloseUpPal[5 * 16] = INCBIN_U16("data/cutscenes/KraidRising/CloseUp.pal");
const u16 sKraidRisingSamusPal[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Samus.pal");
const u16 sKraidRisingParticlesPal[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Particles.pal");
const u16 sKraidRisingSamusVariaPal[1 * 16] = INCBIN_U16("data/cutscenes/KraidRising/SamusVaria.pal");
const u16 sKraidRisingRisingPal[7 * 16] = INCBIN_U16("data/cutscenes/KraidRising/Rising.pal");
const u32 sKraidRisingKraidCloseUpGfx[3087] = INCBIN_U32("data/cutscenes/KraidRising/CloseUp.gfx.lz");
const u32 sKraidRisingOamGfx[753] = INCBIN_U32("data/cutscenes/KraidRising/OAM.gfx.lz");
const u32 sKraidRisingKraidRisingGfx[1609] = INCBIN_U32("data/cutscenes/KraidRising/KraidRising.gfx.lz");
const u32 sKraidRisingCaveBackroundGfx[1327] = INCBIN_U32("data/cutscenes/KraidRising/CaveBackround.gfx.lz");
const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesClosed.tt");
const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesBarelyOpened.tt");
const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesALittleOpened.tt");
const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368] = INCBIN_U32("data/cutscenes/KraidRising/KraidCloseUpEyesOpened.tt");
const u32 sKraidRisingKraidRisingTileTable[295] = INCBIN_U32("data/cutscenes/KraidRising/KraidRising.tt");
const u32 sKraidRisingCaveBackgroundTileTable[370] = INCBIN_U32("data/cutscenes/KraidRising/CaveBackground.tt");
