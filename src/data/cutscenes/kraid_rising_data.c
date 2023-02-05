#include "data/cutscenes/kraid_rising_data.h"
#include "cutscenes/kraid_rising.h"
#include "gba.h"
#include "macros.h"

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
