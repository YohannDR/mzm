#include "data/menus/boot_debug_data.h"
#include "constants/event.h"
#include "oam.h"
#include "structs/cutscene.h"

#ifdef DEBUG

const u8 sEasyHardEventActions[DIFF_END][2] = {
    [DIFF_EASY] = { EVENT_ACTION_SETTING, EVENT_ACTION_CLEARING },
    [DIFF_NORMAL] = { EVENT_ACTION_CLEARING, EVENT_ACTION_CLEARING },
    [DIFF_HARD] = { EVENT_ACTION_CLEARING, EVENT_ACTION_SETTING }
};

const u16 sBootDebugBgPal[128] = INCBIN_U16("data/menus/BootDebug/Background.pal");
const u16 sBootDebugObjPal[48] = INCBIN_U16("data/menus/BootDebug/Objects.pal");
const u32 sBootDebugObjGfx[222] = INCBIN_U32("data/menus/BootDebug/Objects.gfx.lz");

static const u16 sBootDebugOam_4185D8_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x0, 0x1000
};

static const u16 sBootDebugOam_4185B0_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f6, 0x2044
};

static const u16 sBootDebugOam_4185B0_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f7, 0x2044
};

static const u16 sBootDebugOam_4185B0_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, 0x2044
};

static const u16 sBootDebugOam_4185D8_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x3, 0x0, 0x2065
};

static const u16 sBootDebugOam_4185F0_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0x0, 0x1fa, 0x2047,
    0x8, OBJ_Y_FLIP | 0x1fa, 0x2047,
    0x0, OBJ_X_FLIP | 0x34, 0x2047,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x34, 0x2047
};

static const u16 sBootDebugOam_418600_Frame0[OAM_DATA_SIZE(45)] = {
    0x2d,
    0x0, 0x0, 0x1031,
    0x0, 0x10, 0x1021,
    0x0, 0x18, 0x1034,
    0x0, 0x20, 0x1033,
    0x0, 0x28, 0x1033,
    0x0, 0x30, 0x102e,
    0x0, 0x38, 0x102d,
    0x8, 0xd, 0x1033,
    0x8, 0x15, 0x1028,
    0x8, 0x1c, 0x1033,
    0x8, 0x24, 0x102b,
    0x8, 0x2c, 0x1024,
    0xff, 0x8, 0x100b,
    0xf8, 0x8, 0x100c,
    0xf8, 0x8, 0x100c,
    0xf8, 0x10, 0x100c,
    0xf8, 0x10, 0x100c,
    0xf8, 0x18, 0x100c,
    0xf8, 0x18, 0x100c,
    0xf8, 0x20, 0x100c,
    0xf8, 0x20, 0x100c,
    0xf8, 0x28, 0x100c,
    0xf8, 0x28, 0x100c,
    0xf8, 0x30, 0x100c,
    0xf8, 0x30, 0x100c,
    0x10, OBJ_Y_FLIP | 0x8, 0x100c,
    0x10, OBJ_Y_FLIP | 0x8, 0x100c,
    0x10, OBJ_Y_FLIP | 0x10, 0x100c,
    0x10, OBJ_Y_FLIP | 0x10, 0x100c,
    0x10, OBJ_Y_FLIP | 0x18, 0x100c,
    0x10, OBJ_Y_FLIP | 0x18, 0x100c,
    0x10, OBJ_Y_FLIP | 0x20, 0x100c,
    0x10, OBJ_Y_FLIP | 0x20, 0x100c,
    0x10, OBJ_Y_FLIP | 0x28, 0x100c,
    0x10, OBJ_Y_FLIP | 0x28, 0x100c,
    0x10, OBJ_Y_FLIP | 0x30, 0x100c,
    0x10, OBJ_Y_FLIP | 0x30, 0x100c,
    0x0, OBJ_X_FLIP | 0x1f8, 0x100e,
    0x8, OBJ_X_FLIP | 0x1f8, 0x100e,
    0x0, 0x40, 0x100e,
    0x8, 0x40, 0x100e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x38, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | 0x38, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x100c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x1f8, 0x100c
};

static const u16 sBootDebugOam_418610_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, 0x2046,
    0xfc, OBJ_X_FLIP | 0x4, 0x2046,
    0x4, OBJ_Y_FLIP | 0x1fc, 0x2046,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x2046
};

static const u16 sBootDebugOam_418610_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfb, 0x1fb, 0x2046,
    0xfb, OBJ_X_FLIP | 0x5, 0x2046,
    0x5, OBJ_Y_FLIP | 0x1fb, 0x2046,
    0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x2046
};

static const u16 sBootDebugOam_418610_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, 0x1fa, 0x2046,
    0xfa, OBJ_X_FLIP | 0x6, 0x2046,
    0x6, OBJ_Y_FLIP | 0x1fa, 0x2046,
    0x6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x6, 0x2046
};

static const struct FrameData sBootDebugOam_4185B0[5] = {
   [0] = {
       .pFrame = sBootDebugOam_4185B0_Frame0,
       .timer = CONVERT_SECONDS(0.2f)
   },
   [1] = {
       .pFrame = sBootDebugOam_4185B0_Frame1,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [2] = {
       .pFrame = sBootDebugOam_4185B0_Frame2,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [3] = {
       .pFrame = sBootDebugOam_4185B0_Frame1,
       .timer = CONVERT_SECONDS(0.1f)
   },
   [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBootDebugOam_4185D8[3] = {
   [0] = {
       .pFrame = sBootDebugOam_4185D8_Frame0,
       .timer = CONVERT_SECONDS(1.f / 3)
   },
   [1] = {
       .pFrame = sBootDebugOam_4185D8_Frame1,
       .timer = CONVERT_SECONDS(4.f / 15)
   },
   [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBootDebugOam_4185F0[2] = {
   [0] = {
       .pFrame = sBootDebugOam_4185F0_Frame0,
       .timer = CONVERT_SECONDS(1.f / 15)
   },
   [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBootDebugOam_418600[2] = {
   [0] = {
       .pFrame = sBootDebugOam_418600_Frame0,
       .timer = CONVERT_SECONDS(1.f)
   },
   [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBootDebugOam_418610[5] = {
   [0] = {
       .pFrame = sBootDebugOam_418610_Frame0,
       .timer = CONVERT_SECONDS(4.f / 15)
   },
   [1] = {
       .pFrame = sBootDebugOam_418610_Frame1,
       .timer = CONVERT_SECONDS(2.f / 15)
   },
   [2] = {
       .pFrame = sBootDebugOam_418610_Frame2,
       .timer = CONVERT_SECONDS(0.2f)
   },
   [3] = {
       .pFrame = sBootDebugOam_418610_Frame1,
       .timer = CONVERT_SECONDS(2.f / 15)
   },
   [4] = FRAME_DATA_TERMINATOR
};

const u32 sBootDebugBgGfx[771] = INCBIN_U32("data/menus/BootDebug/Background.gfx.lz");

static const u8 sBootDebug_CutsceneB_EscapeShip_Text[8] = SHIFT_JIS("コガタテイ");
static const u8 sBootDebug_CutsceneB_MechaRidley_Text[12] = SHIFT_JIS("メカ リドリー");
static const u8 sBootDebug_CutsceneB_PoweredSuit_Text[12] = SHIFT_JIS("パワードスーツ");
static const u8 sBootDebug_CutsceneB_ChozoMural_Text[8] = SHIFT_JIS("ヘキガ");
static const u8 sBootDebug_CutsceneB_Metroids_Text[8] = SHIFT_JIS("メトロイド");
static const u8 sBootDebug_CutsceneB_RidleyFight_Text[8] = SHIFT_JIS("リドリー");
static const u8 sBootDebug_CutsceneB_MotherShipLanding_Text[8] = SHIFT_JIS("チャクリク");
static const u8 sBootDebug_CutsceneB_MotherShipReturning_Text[12] = SHIFT_JIS("ヒキカエス ボカン");
static const u8 sBootDebug_CutsceneB_BossStatues_Text[8] = SHIFT_JIS("セキゾウ");
static const u8 sBootDebug_CutsceneB_KraidFight_Text[8] = SHIFT_JIS("クレイド");
static const u8 sBootDebug_CutsceneB_MotherBrain_Text[12] = SHIFT_JIS("マザー ブレイン");
static const u8 sBootDebug_CutsceneB_ShotDownMonologue2_Text[12] = SHIFT_JIS("MONOゲキツイ2");
static const u8 sBootDebug_CutsceneB_ShotDownMonologue1_Text[12] = SHIFT_JIS("MONOゲキツイ1");
static const u8 sBootDebug_CutsceneB_StartMonologue_Text[12] = SHIFT_JIS("MONO スタート");
static const u8 sBootDebug_Cutscene_Blank_Text[12] = SHIFT_JIS("---       ");
static const u8 sBootDebug_CutsceneA_ShotDown_Text[8] = SHIFT_JIS("ゲキツイ");
static const u8 sBootDebugMenuNames_DebugConfig_Text[12] = SHIFT_JIS("DEBUG CONFIG");
static const u8 sBootDebugMenuNames_Section_Text[8] = SHIFT_JIS("SECTION");
static const u8 sBootDebugMenuNames_Mode_Text[4] = SHIFT_JIS("MODE");
static const u8 sBootDebugMenuNames_Save_Text[4] = SHIFT_JIS("SAVE");
static const u8 sBootDebugMenuNames_Samus_Text[8] = SHIFT_JIS("SAMUS");
static const u8 sBootDebugMenuNames_Sound_Text[8] = SHIFT_JIS("Sound");
static const u8 sBootDebugMenuNames_Demo_Text[4] = SHIFT_JIS("DEMO");
static const u8 sBootDebugMenuNames_Etc_Text[4] = SHIFT_JIS("etc");
static const u8 sBootDebugMenuNames_Boot_Text[4] = SHIFT_JIS("boot");
static const u8 sBootDebugMenuNames_Erase_Text[8] = SHIFT_JIS("ERASE");
static const u8 sBootDebugModeMenu_Language_Text[12] = SHIFT_JIS("LANGUAGE ");
static const u8 sBootDebugModeMenu_Difficulty_Text[12] = SHIFT_JIS("LEVEL    ");
static const u8 sBootDebugLanguage_Japanese_Text[8] = SHIFT_JIS("Japanese");
static const u8 sBootDebugLanguage_Hiragana_Text[8] = SHIFT_JIS("hiragana");
static const u8 sBootDebugLanguage_English_Text[8] = SHIFT_JIS("English ");
static const u8 sBootDebugLanguage_German_Text[8] = SHIFT_JIS("German  ");
static const u8 sBootDebugLanguage_French_Text[8] = SHIFT_JIS("French  ");
static const u8 sBootDebugLanguage_Italian_Text[8] = SHIFT_JIS("Italian ");
static const u8 sBootDebugLanguage_Spanish_Text[8] = SHIFT_JIS("Spanish ");
static const u8 sBootDebugDifficulty_Easy_Text[8] = SHIFT_JIS("EASY  ");
static const u8 sBootDebugDifficulty_Normal_Text[8] = SHIFT_JIS("NORMAL");
static const u8 sBootDebugDifficulty_Hard_Text[8] = SHIFT_JIS("HARD  ");
static const u8 sBootDebugSectionMenu_Brinstar_Text[8] = SHIFT_JIS("ブリンスタ  ");
static const u8 sBootDebugSectionMenu_Kraid_Text[8] = SHIFT_JIS("クレイド   ");
static const u8 sBootDebugSectionMenu_Norfair_Text[8] = SHIFT_JIS("ノルフェア   ");
static const u8 sBootDebugSectionMenu_Ridley_Text[8] = SHIFT_JIS("リドリー   ");
static const u8 sBootDebugSectionMenu_Tourian_Text[8] = SHIFT_JIS("ツーリアン   ");
static const u8 sBootDebugSectionMenu_Crateria_Text[8] = SHIFT_JIS("クレテリア   ");
static const u8 sBootDebugSectionMenu_Chozodia_Text[8] = SHIFT_JIS("ナンパセン  ");
static const u8 sBootDebugSectionMenu_Blank_Text[8] = SHIFT_JIS("        ");
static const u8 sBootDebugSectionMenu_Test1_Text[8] = SHIFT_JIS("TEST 1  ");
static const u8 sBootDebugSectionMenu_Test2_Text[8] = SHIFT_JIS("TEST 2  ");
static const u8 sBootDebugSectionMenu_Test3_Text[8] = SHIFT_JIS("TEST 3  ");
static const u8 sBootDebugSectionMenu_Title_Text[8] = SHIFT_JIS("TITLE");
static const u8 sBootDebugSectionMenu_SaveA_Text[8] = SHIFT_JIS("SAVE(A)");
static const u8 sBootDebugSectionMenu_SaveB_Text[8] = SHIFT_JIS("SAVE(B)");
static const u8 sBootDebugSectionMenu_SaveC_Text[8] = SHIFT_JIS("SAVE(C)");
static const u8 sBootDebugSectionMenu_Select_Text[8] = SHIFT_JIS("Select");
static const u8 sBootDebugSamusMenu_GetMap_Text[8] = SHIFT_JIS("GetMap");
static const u8 sBootDebugSamusMenu_ArmWeapon_Text[8] = SHIFT_JIS("H-SHOT");
static const u8 sBootDebugSamusMenu_DiagonalAim_Text[8] = SHIFT_JIS("ナナメ-SHOT");
static const u8 sBootDebugSamusMenu_Pause_Text[8] = SHIFT_JIS("PAUSE");
static const u8 sBootDebugSamusMenu_SwapMissiles_Text[4] = SHIFT_JIS("ミサイル");
static const u8 sBootDebug_LButton_Text[8] = SHIFT_JIS("L-Button");
static const u8 sBootDebug_RButton_Text[8] = SHIFT_JIS("R-Button");
static const u8 sBootDebug_Start_Text[8] = SHIFT_JIS("START ");
static const u8 sBootDebug_Select_Text[8] = SHIFT_JIS("SELECT");
static const u8 sBootDebugSaveMenu_GalleryImages_Text[20] = SHIFT_JIS("POSTER   12345678");
static const u8 sBootDebugSaveMenu_DifficultiesCleared_Text[20] = SHIFT_JIS("ClearLevel  e/n/h");
static const u8 sBootDebugSaveMenu_LinkedWithFusion_Text[16] = SHIFT_JIS("Fusion   yes/no");
static const u8 sBootDebugSaveMenu_Id_Text[20] = SHIFT_JIS("ID       --------");
static const u8 sBootDebugSaveMenu_Save_Text[4] = SHIFT_JIS("SAVE");
static const u8 sBootDebugSoundMenu_Bgm_Text[4] = SHIFT_JIS("BGM");
static const u8 sBootDebugSoundMenu_Test_Text[4] = SHIFT_JIS("TEST");
static const u8 sBootDebugSoundMenu_Mono_Text[4] = SHIFT_JIS("モノラル");
static const u8 sBootDebugSoundMenu_Stereo_Text[4] = SHIFT_JIS("ステレオ");
static const u8 sBootDebugDemoMenu_CutsceneSwitch_Text[8] = SHIFT_JIS("DEMO SW");
static const u8 sBootDebugDemoMenu_CutsceneA_Text[8] = SHIFT_JIS("DEMO(A)");
static const u8 sBootDebugDemoMenu_CutsceneB_Text[8] = SHIFT_JIS("DEMO(B)");
static const u8 sBootDebugDemoMenu_DemoMode_Text[12] = SHIFT_JIS("オートデモMODE");
static const u8 sBootDebugDemoMenu_DemoNum_Text[12] = SHIFT_JIS("オートデモNUM");
static const u8 sBootDebugEtcMenu_Ending_Text[8] = SHIFT_JIS("Ending");
static const u8 sBootDebugEtcMenu_StaffRoll_Text[12] = SHIFT_JIS("STAFF ROLL");
static const u8 sBootDebugEtcMenu_MainEndObj_Text[12] = SHIFT_JIS("Main-End OBJ");
static const u8 sBootDebugEtcMenu_DoorTransition_Text[8] = SHIFT_JIS("ゲート コウカ");
static const u8 sBootDebugEraseMenu_EraseSram_Text[12] = SHIFT_JIS("ERASE SRAM");
static const u8 sBootDebug_On_Text[4] = SHIFT_JIS("ON ");
static const u8 sBootDebug_Off_Text[4] = SHIFT_JIS("OFF");
static const u8 sBootDebugEraseMenu_Yes_Text[4] = SHIFT_JIS("YES");
static const u8 sBootDebugEraseMenu_No_Text[4] = SHIFT_JIS("NO ");

const struct BootDebugText sBootDebugMenuNamesText[10] = {
    [BOOT_DEBUG_SUB_MENU_HEADER] = {
        .background = 3,
        .xPosition = 10,
        .yPosition = 0,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 12,
        .text = sBootDebugMenuNames_DebugConfig_Text
    },
    [BOOT_DEBUG_SUB_MENU_SECTION] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 7,
        .text = sBootDebugMenuNames_Section_Text
    },
    [BOOT_DEBUG_SUB_MENU_MODE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 4,
        .text = sBootDebugMenuNames_Mode_Text
    },
    [BOOT_DEBUG_SUB_MENU_SAVE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 4,
        .text = sBootDebugMenuNames_Save_Text
    },
    [BOOT_DEBUG_SUB_MENU_SAMUS] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 5,
        .text = sBootDebugMenuNames_Samus_Text
    },
    [BOOT_DEBUG_SUB_MENU_SOUND] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 5,
        .text = sBootDebugMenuNames_Sound_Text
    },
    [BOOT_DEBUG_SUB_MENU_DEMO] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 13,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 4,
        .text = sBootDebugMenuNames_Demo_Text
    },
    [BOOT_DEBUG_SUB_MENU_ETC] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 15,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 3,
        .text = sBootDebugMenuNames_Etc_Text
    },
    [BOOT_DEBUG_SUB_MENU_BOOT] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 17,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 4,
        .text = sBootDebugMenuNames_Boot_Text
    },
    [BOOT_DEBUG_SUB_MENU_ERASE] = {
        .background = 3,
        .xPosition = 2,
        .yPosition = 19,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE_SUB_MENU,
        .size = 5,
        .text = sBootDebugMenuNames_Erase_Text
    }
};

const struct BootDebugText sBootDebugSectionMenuText[16] = {
    [BOOT_DEBUG_SECTION_BRINSTAR] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 4,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Brinstar_Text
    },
    [BOOT_DEBUG_SECTION_KRAID] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 6,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Kraid_Text
    },
    [BOOT_DEBUG_SECTION_NORFAIR] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 8,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Norfair_Text
    },
    [BOOT_DEBUG_SECTION_RIDLEY] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 10,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Ridley_Text
    },
    [BOOT_DEBUG_SECTION_TOURIAN] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 12,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Tourian_Text
    },
    [BOOT_DEBUG_SECTION_CRATERIA] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 14,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Crateria_Text
    },
    [BOOT_DEBUG_SECTION_CHOZODIA] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 16,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Chozodia_Text
    },
    [BOOT_DEBUG_SECTION_BLANK] = {
        .background = 2,
        .xPosition = 1,
        .yPosition = 18,
        .palette = BOOT_DEBUG_COLOR_BLACK,
        .size = 8,
        .text = sBootDebugSectionMenu_Blank_Text
    },
    [BOOT_DEBUG_SECTION_TEST_1] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 4,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Test1_Text
    },
    [BOOT_DEBUG_SECTION_TEST_2] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 6,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Test2_Text
    },
    [BOOT_DEBUG_SECTION_TEST_3] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 8,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSectionMenu_Test3_Text
    },
    [BOOT_DEBUG_SECTION_TITLE] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 10,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 5,
        .text = sBootDebugSectionMenu_Title_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_A] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 12,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveA_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_B] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 14,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveB_Text
    },
    [BOOT_DEBUG_SECTION_SAVE_C] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 16,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugSectionMenu_SaveC_Text
    },
    [15] = {
        .background = 2,
        .xPosition = 11,
        .yPosition = 2,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 6,
        .text = sBootDebugSectionMenu_Select_Text
    }
};

const struct BootDebugText sBootDebugModeMenuText[2] = {
    [BOOT_DEBUG_MODE_LANGUAGE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 9,
        .text = sBootDebugModeMenu_Language_Text
    },
    [BOOT_DEBUG_MODE_DIFFICULTY] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 9,
        .text = sBootDebugModeMenu_Difficulty_Text
    }
};

const struct BootDebugText sBootDebugLanguageText[7] = {
    [LANGUAGE_JAPANESE] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 8,
        .text = sBootDebugLanguage_Japanese_Text
    },
    [LANGUAGE_HIRAGANA] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_YELLOW,
        .size = 8,
        .text = sBootDebugLanguage_Hiragana_Text
    },
    [LANGUAGE_ENGLISH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebugLanguage_English_Text
    },
    [LANGUAGE_GERMAN] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebugLanguage_German_Text
    },
    [LANGUAGE_FRENCH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebugLanguage_French_Text
    },
    [LANGUAGE_ITALIAN] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebugLanguage_Italian_Text
    },
    [LANGUAGE_SPANISH] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebugLanguage_Spanish_Text
    }
};

const struct BootDebugText sBootDebugDifficultyText[3] = {
    [DIFF_EASY] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_YELLOW,
        .size = 6,
        .text = sBootDebugDifficulty_Easy_Text
    },
    [DIFF_NORMAL] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 6,
        .text = sBootDebugDifficulty_Normal_Text
    },
    [DIFF_HARD] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 6,
        .text = sBootDebugDifficulty_Hard_Text
    }
};

const struct BootDebugText sBootDebugSaveMenuText[5] = {
    [BOOT_DEBUG_SAVE_GALLERY_IMAGES] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 17,
        .text = sBootDebugSaveMenu_GalleryImages_Text
    },
    [BOOT_DEBUG_SAVE_DIFFICULTIES_CLEARED] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 17,
        .text = sBootDebugSaveMenu_DifficultiesCleared_Text
    },
    [BOOT_DEBUG_SAVE_LINKED_WITH_FUSION] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 15,
        .text = sBootDebugSaveMenu_LinkedWithFusion_Text
    },
    [BOOT_DEBUG_SAVE_ID] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 17,
        .text = sBootDebugSaveMenu_Id_Text
    },
    [BOOT_DEBUG_SAVE_SAVE] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_BLACK,
        .size = 4,
        .text = sBootDebugSaveMenu_Save_Text
    }
};

const struct BootDebugText sBootDebugSamusMenuText[5] = {
    [BOOT_DEBUG_SAMUS_GET_MAP] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 6,
        .text = sBootDebugSamusMenu_GetMap_Text
    },
    [BOOT_DEBUG_SAMUS_ARM_WEAPON] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 6,
        .text = sBootDebugSamusMenu_ArmWeapon_Text
    },
    [BOOT_DEBUG_SAMUS_DIAGONAL_AIM] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugSamusMenu_DiagonalAim_Text
    },
    [BOOT_DEBUG_SAMUS_PAUSE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 5,
        .text = sBootDebugSamusMenu_Pause_Text
    },
    [BOOT_DEBUG_SAMUS_SWAP_MISSILES] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 4,
        .text = sBootDebugSamusMenu_SwapMissiles_Text
    }
};

const struct BootDebugText sBootDebugArmWeaponButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_YELLOW,
        .size = 8,
        .text = sBootDebug_LButton_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebug_RButton_Text
    }
};

const struct BootDebugText sBootDebugDiagonalAimButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_YELLOW,
        .size = 8,
        .text = sBootDebug_LButton_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_GREEN,
        .size = 8,
        .text = sBootDebug_RButton_Text
    }
};

const struct BootDebugText sBootDebugPauseButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 6,
        .text = sBootDebug_Start_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 6,
        .text = sBootDebug_Select_Text
    }
};

const struct BootDebugText sBootDebugSwapMissilesButtonText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 6,
        .text = sBootDebug_Start_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 9,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 6,
        .text = sBootDebug_Select_Text
    }
};

const struct BootDebugText sBootDebugSoundMenuText[4] = {
    [0] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 3,
        .text = sBootDebugSoundMenu_Bgm_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 4,
        .text = sBootDebugSoundMenu_Mono_Text
    },
    [2] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 4,
        .text = sBootDebugSoundMenu_Test_Text
    },
    [3] = {
        .background = 2,
        .xPosition = 5,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 4,
        .text = sBootDebugSoundMenu_Stereo_Text
    }
};

const struct BootDebugText sBootDebugBgmOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 6,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 6,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugDemoMenuText[5] = {
    [BOOT_DEBUG_DEMO_CUTSCENE_SWITCH] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneSwitch_Text
    },
    [BOOT_DEBUG_DEMO_CUTSCENE_A] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneA_Text
    },
    [BOOT_DEBUG_DEMO_CUTSCENE_B] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 7,
        .text = sBootDebugDemoMenu_CutsceneB_Text
    },
    [BOOT_DEBUG_DEMO_DEMO_MODE] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 11,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 10,
        .text = sBootDebugDemoMenu_DemoMode_Text
    },
    [BOOT_DEBUG_DEMO_DEMO_NUM] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 13,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 9,
        .text = sBootDebugDemoMenu_DemoNum_Text
    }
};

const struct BootDebugText sBootDebugDemoOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 10,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugEtcMenuText[4] = {
    [BOOT_DEBUG_ETC_ENDING] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 6,
        .text = sBootDebugEtcMenu_Ending_Text
    },
    [BOOT_DEBUG_ETC_STAFF_ROLL] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 10,
        .text = sBootDebugEtcMenu_StaffRoll_Text
    },
    [BOOT_DEBUG_ETC_MAIN_END_OBJ] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 12,
        .text = sBootDebugEtcMenu_MainEndObj_Text
    },
    [BOOT_DEBUG_ETC_DOOR_TRANSITION] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 8,
        .text = sBootDebugEtcMenu_DoorTransition_Text
    }
};

const struct BootDebugText sBootDebugMainEndObjOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugDoorTransitionOnOffText[2] = {
    [0] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_RED,
        .size = 3,
        .text = sBootDebug_On_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 14,
        .yPosition = 9,
        .palette = BOOT_DEBUG_COLOR_BLUE,
        .size = 3,
        .text = sBootDebug_Off_Text
    }
};

const struct BootDebugText sBootDebugEraseMenuText[3] = {
    [0] = {
        .background = 2,
        .xPosition = 0,
        .yPosition = 3,
        .palette = BOOT_DEBUG_COLOR_YELLOW,
        .size = 10,
        .text = sBootDebugEraseMenu_EraseSram_Text
    },
    [1] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 5,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 3,
        .text = sBootDebugEraseMenu_No_Text
    },
    [2] = {
        .background = 2,
        .xPosition = 2,
        .yPosition = 7,
        .palette = BOOT_DEBUG_COLOR_AZURE_WHITE,
        .size = 3,
        .text = sBootDebugEraseMenu_Yes_Text
    }
};

static const u8 sBootDebug_DemoState_RomRun_Text[8] = SHIFT_JIS("ROMRUN");
static const u8 sBootDebug_DemoState_RamRun_Text[8] = SHIFT_JIS("RAMRUN");
static const u8 sBootDebug_DemoState_GetKey_Text[8] = SHIFT_JIS("GETKEY");
static const u8 sBootDebug_DemoState_Free_Text[8] = SHIFT_JIS("FREE");
static const u8 sBootDebug_DemoState_Blank_Text[7] = SHIFT_JIS("      ");

const u8 sBootDebugSectionCursorMovement[BOOT_DEBUG_SECTION_COUNT][4] = {
    [BOOT_DEBUG_SECTION_BRINSTAR] = {0x08, 0x80, 0x80, 0x01},
    [BOOT_DEBUG_SECTION_KRAID] = {0x09, 0x80, 0x00, 0x02},
    [BOOT_DEBUG_SECTION_NORFAIR] = {0x0A, 0x80, 0x01, 0x03},
    [BOOT_DEBUG_SECTION_RIDLEY] = {0x0B, 0x80, 0x02, 0x04},
    [BOOT_DEBUG_SECTION_TOURIAN] = {0x0C, 0x80, 0x03, 0x05},
    [BOOT_DEBUG_SECTION_CRATERIA] = {0x0D, 0x80, 0x04, 0x06},
    [BOOT_DEBUG_SECTION_CHOZODIA] = {0x0E, 0x80, 0x05, 0x80},
    [BOOT_DEBUG_SECTION_BLANK] = {0x80, 0x80, 0x06, 0x80},
    [BOOT_DEBUG_SECTION_TEST_1] = {0x80, 0x00, 0x80, 0x09},
    [BOOT_DEBUG_SECTION_TEST_2] = {0x80, 0x01, 0x08, 0x0A},
    [BOOT_DEBUG_SECTION_TEST_3] = {0x80, 0x02, 0x09, 0x0B},
    [BOOT_DEBUG_SECTION_TITLE] = {0x80, 0x03, 0x0A, 0x0C},
    [BOOT_DEBUG_SECTION_SAVE_A] = {0x80, 0x04, 0x0B, 0x0D},
    [BOOT_DEBUG_SECTION_SAVE_B] = {0x80, 0x05, 0x0C, 0x0E},
    [BOOT_DEBUG_SECTION_SAVE_C] = {0x80, 0x06, 0x0D, 0x80}
};

const struct OamArray sBootDebugOam[6] = {
    [0] = {
        .pOam = sBootDebugOam_4185B0,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sBootDebugOam_4185B0,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [2] = {
        .pOam = sBootDebugOam_4185D8,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [3] = {
        .pOam = sBootDebugOam_4185F0,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sBootDebugOam_418600,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [5] = {
        .pOam = sBootDebugOam_418610,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
};

const u8 sZeroSaveText[8] = "ZEROSAVE";

const u8* const sBootDebugCutsceneBTextPointers[CUTSCENE_END] = {
    [CUTSCENE_NONE] =                    sBootDebug_Cutscene_Blank_Text,
    [CUTSCENE_INTRO_TEXT] =              sBootDebug_CutsceneB_StartMonologue_Text,
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] =    sBootDebug_CutsceneB_ShotDownMonologue1_Text,
    [CUTSCENE_COULD_I_SURVIVE] =         sBootDebug_CutsceneB_ShotDownMonologue2_Text,
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] =   sBootDebug_CutsceneB_MotherBrain_Text,
    [CUTSCENE_KRAID_RISING] =            sBootDebug_CutsceneB_KraidFight_Text,
    [CUTSCENE_STATUE_OPENING] =          sBootDebug_CutsceneB_BossStatues_Text,
    [CUTSCENE_RIDLEY_IN_SPACE] =         sBootDebug_CutsceneB_MotherShipReturning_Text,
    [CUTSCENE_RIDLEY_LANDING] =          sBootDebug_CutsceneB_MotherShipLanding_Text,
    [CUTSCENE_RIDLEY_SPAWNING] =         sBootDebug_CutsceneB_RidleyFight_Text,
    [CUTSCENE_ENTER_TOURIAN] =           sBootDebug_CutsceneB_Metroids_Text,
    [CUTSCENE_BEFORE_CHARLIE] =          sBootDebug_CutsceneB_ChozoMural_Text,
    [CUTSCENE_GETTING_FULLY_POWERED] =   sBootDebug_CutsceneB_PoweredSuit_Text,
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = sBootDebug_CutsceneB_MechaRidley_Text,
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] =      sBootDebug_CutsceneB_EscapeShip_Text
};

const u8* const sBootDebugCutsceneATextPointers[2] = {
    sBootDebug_Cutscene_Blank_Text,
    sBootDebug_CutsceneA_ShotDown_Text
};

const u8* const sBootDebugDemoStateTextPointers[5] = {
    sBootDebug_DemoState_Blank_Text,
    sBootDebug_DemoState_Free_Text,
    sBootDebug_DemoState_GetKey_Text,
    sBootDebug_DemoState_RamRun_Text,
    sBootDebug_DemoState_RomRun_Text
};

FORCE_RODATA
u8 sBootDebugTextToggleColors[2][2] = {
    [FALSE] = { BOOT_DEBUG_COLOR_BLACK, BOOT_DEBUG_COLOR_YELLOW },
    [TRUE] = { BOOT_DEBUG_COLOR_YELLOW, BOOT_DEBUG_COLOR_BLACK }
};

#endif /* DEBUG */
