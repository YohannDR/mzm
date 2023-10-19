#include "data/menus/erase_sram_data.h"
#include "macros.h"
#include "constants/menus/erase_sram.h"

const u16 sEraseSramMenuObjectsPal[7 * 16] = INCBIN_U16("data/menus/EraseSram/Objects.pal");
const u16 sEraseSramMenuBackgroundPal[15 * 16 - 1] = INCBIN_U16("data/menus/EraseSram/Background.pal");

static const u16 sEraseSramOAM_ConfirmWindowNoSelected_Frame0[52] = {
    0x11,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1b8, 0x2098,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1d8, 0x209c,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x10, 0x50d8,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x30, 0x50dc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1a0, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1e0, 0x2088,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x20, 0x2090,
    0xe0, OBJ_SIZE_64x64 | 0x190, 0x3100,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_64x32 | 0x190, 0x3200,
    0xe0, OBJ_SIZE_64x64 | 0x30, 0x3104,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_64x32 | 0x30, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x1d0, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x1d0, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x1f0, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x1f0, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x10, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x10, 0x3204
};

static const u16 sEraseSramOAM_ConfirmWindowYesSelected_Frame0[52] = {
    0x11,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1b8, 0x5098,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1d8, 0x509c,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x10, 0x20d8,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x30, 0x20dc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1a0, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1e0, 0x2088,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x20, 0x2090,
    0xe0, OBJ_SIZE_64x64 | 0x190, 0x3100,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_64x32 | 0x190, 0x3200,
    0xe0, OBJ_SIZE_64x64 | 0x30, 0x3104,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_64x32 | 0x30, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x1d0, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x1d0, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x1f0, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x1f0, 0x3204,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_32x64 | 0x10, 0x3104,
    0x20, OBJ_SIZE_32x32 | 0x10, 0x3204
};

static const u16 sEraseSramOAM_CursorIdle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x8, 0x410d
};

static const u16 sEraseSramOAM_CursorIdle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x9, 0x410d
};

static const u16 sEraseSramOAM_CursorIdle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xa, 0x410d
};

static const u16 sEraseSramOAM_CursorSelecting_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x8, 0x410e
};

static const u16 sEraseSramOAM_UnusedFrame_4118d6[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x9, 0x410e
};

static const u16 sEraseSramOAM_UnusedFrame_4118de[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xa, 0x410e
};

static const u16 sEraseSramOAM_UnusedFrame_4118e6[4] = {
    0x1,
    0xf7, 0xc, 0x415d
};

static const u16 sEraseSramOAM_UnusedFrame_4118ee[4] = {
    0x1,
    0xf7, 0xd, 0x415e
};

static const u16 sEraseSramOAM_UnusedFrame_4118f6[4] = {
    0x1,
    0xf7, 0xa, 0x415f
};

static const u16 sEraseSramOAM_UnusedFrame_4118fe[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c
};

static const u16 sEraseSramOAM_QuestionWindowNoSelected_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b8, 0x2018,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d8, 0x201c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0x5058,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0x505c
};

static const u16 sEraseSramOAM_QuestionWindowYesSelected_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b8, 0x5018,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d8, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0x2058,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0x205c
};

static const u16 sEraseSramOAM_UnusedFrame_41193a[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4191,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4193,
    OBJ_SHAPE_VERTICAL | 0xef, 0xa, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_41194e[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4194,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4196,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_411962[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4197,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4199,
    0xf7, 0xc, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_411976[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x419a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x419c,
    0xf7, 0xb, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_41198a[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    OBJ_SHAPE_VERTICAL | 0xef, 0xa, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_41199e[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_4119b2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    0xf7, 0xc, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_4119c6[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    0xf7, 0xb, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_4119da[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    OBJ_SHAPE_VERTICAL | 0xef, 0xa, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_4119ee[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_411a02[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c,
    0xf7, 0xc, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_411a16[10] = {
    0x3,
    0xf7, 0xb, 0x411e,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c
};

static const u16 sEraseSramOAM_UnusedFrame_411a2a[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xef, 0xa, 0x411d,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c
};

static const u16 sEraseSramOAM_UnusedFrame_411a3e[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, 0x411d,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4157,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4159
};

static const u16 sEraseSramOAM_UnusedFrame_411a52[10] = {
    0x3,
    0xf7, 0xc, 0x411e,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4117,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4119
};

static const u16 sEraseSramOAM_UnusedFrame_411a66[10] = {
    0x3,
    0xf7, 0xb, 0x411e,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4117,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4119
};

static const u16 sEraseSramOAM_UnusedFrame_411a7a[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4117,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4119,
    OBJ_SHAPE_VERTICAL | 0xef, 0xa, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_411a8e[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4117,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4119,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, 0x411d
};

static const u16 sEraseSramOAM_UnusedFrame_411aa2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x4157,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x4159,
    0xf7, 0xc, 0x411e
};

static const u16 sEraseSramOAM_UnusedFrame_411ab6[10] = {
    0x3,
    0xf7, 0xb, 0x411e,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x411a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, 0x411c
};

static const struct FrameData sEraseSramOAM_CursorIdle[4] = {
    sEraseSramOAM_CursorIdle_Frame0,
    6,
    sEraseSramOAM_CursorIdle_Frame1,
    6,
    sEraseSramOAM_CursorIdle_Frame2,
    6,
    NULL,
    0
};

static const struct FrameData sEraseSramOAM_CursorSelecting[7] = {
    sEraseSramOAM_CursorIdle_Frame0,
    4,
    sEraseSramOAM_CursorSelecting_Frame1,
    4,
    sEraseSramOAM_CursorIdle_Frame0,
    4,
    sEraseSramOAM_CursorSelecting_Frame1,
    4,
    sEraseSramOAM_CursorIdle_Frame0,
    4,
    sEraseSramOAM_CursorSelecting_Frame1,
    4,
    NULL,
    0
};

static const struct FrameData sEraseSramOAM_QuestionWindowNoSelected[2] = {
    sEraseSramOAM_QuestionWindowNoSelected_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sEraseSramOAM_QuestionWindowYesSelected[2] = {
    sEraseSramOAM_QuestionWindowYesSelected_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sEraseSramOAM_ConfirmWindowNoSelected[2] = {
    sEraseSramOAM_ConfirmWindowNoSelected_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sEraseSramOAM_ConfirmWindowYesSelected[2] = {
    sEraseSramOAM_ConfirmWindowYesSelected_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

const u32 sEraseSramMenuObjectsGfx[477] = INCBIN_U32("data/menus/EraseSram/Objects.gfx.lz");
const u32 sEraseSramMenuFirstBoxGfx[118] = INCBIN_U32("data/menus/EraseSram/FirstBox.gfx.lz");
const u32 sEraseSramMenuConfirmJapanseGfx[245] = INCBIN_U32("data/menus/EraseSram/ConfirmJapanse.gfx.lz");
const u32 sEraseSramMenuConfirmEnglishGfx[1027] = INCBIN_U32("data/menus/EraseSram/ConfirmEnglish.gfx.lz");
const u32 sEraseSramMenuQuestionJapaneseGfx[245] = INCBIN_U32("data/menus/EraseSram/QuestionJapanese.gfx.lz");
const u32 sEraseSramMenuQuestionEnglishGfx[1006] = INCBIN_U32("data/menus/EraseSram/QuestionEnglish.gfx.lz");
const u32 sEraseSramMenuBoxTileTable[137] = INCBIN_U32("data/menus/EraseSram/Box.tt");
const u32 sEraseSramMenuBackgroundTileTable[368] = INCBIN_U32("data/menus/EraseSram/Background.tt");

const u8 sEraseSramQuestionWindowNoSelectedOamId = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED;
const u8 sEraseSramQuestionWindowYesSelectedOamId = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED;
const u8 sEraseSramConfirmWindowNoSelectedOamId = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED;
const u8 sEraseSramConfirmWindowYesSelectedOamId = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED;

const u16 sEraseSramMenuSoundsID[5] = {
    0, 0x1FC, 0x208, 0x209, 0x1FA
};

const u16 sEraseSramMenuCursorPosition[2][2] = {
    [0] = {
        BLOCK_SIZE * 8, BLOCK_SIZE * 5 + HALF_BLOCK_SIZE
    },
    [1] = {
        BLOCK_SIZE * 8 - 8, BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 8
    }
};

const u16 sEraseSramMenuCursorPositionOffset[4][2] = {
    [ERASE_SRAM_OPTION_QUESTION_NO] = {
        -(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), -8
    },
    [ERASE_SRAM_OPTION_QUESTION_YES] = {
        QUARTER_BLOCK_SIZE, -8
    },
    [ERASE_SRAM_OPTION_CONFIRM_NO] = {
        -(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), BLOCK_SIZE * 2 + 0x18
    },
    [ERASE_SRAM_OPTION_CONFIRM_YES] = {
        QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 + 0x18
    }
};

const struct OamArray sEraseSramMenuOam[7] = {
    [0] = {
        .pOam = sEraseSramOAM_CursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [ERASE_SRAM_OAM_ID_CURSOR_IDLE] = {
        .pOam = sEraseSramOAM_CursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [ERASE_SRAM_OAM_ID_CURSOR_SELECTING] = {
        .pOam = sEraseSramOAM_CursorSelecting,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED] = {
        .pOam = sEraseSramOAM_QuestionWindowNoSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED] = {
        .pOam = sEraseSramOAM_QuestionWindowYesSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED] = {
        .pOam = sEraseSramOAM_ConfirmWindowNoSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED] = {
        .pOam = sEraseSramOAM_ConfirmWindowYesSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
};
