#include "data/menus/status_screen_data.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/menus/status_screen.h"
#include "constants/menus/pause_screen.h"
#include "macros.h"

#ifdef DEBUG

const u8 sPauseDebugEventListBgPalette[2 * 16] = INCBIN_U16("data/menus/PauseScreen/PauseDebugEventListBg.pal");
const u32 sPauseDebugEventListTextGfx[336] = INCBIN_U32("data/menus/PauseScreen/PauseDebugEventListText.gfx.lz");

static const u8 sPauseDebug_Event4E_Text[32] = SHIFT_JIS("END         エンド            ");
static const u8 sPauseDebug_Event4D_Text[32] = SHIFT_JIS("BOMBGATE    アキ ボムゲート      ");
static const u8 sPauseDebug_Event4C_Text[32] = SHIFT_JIS("AKI         アキ              ");
static const u8 sPauseDebug_Event4B_Text[32] = SHIFT_JIS("LASTESCAPE  サイゴノダッシュツ     ");
static const u8 sPauseDebug_Event4A_Text[32] = SHIFT_JIS("MECHARIDLEYSIメカリドリー シ      ");
static const u8 sPauseDebug_Event49_Text[32] = SHIFT_JIS("GLASSTUBE   ガラスカン コワレ      ");
static const u8 sPauseDebug_Event48_Text[32] = SHIFT_JIS("PBOMBZEBES2 パワーボムゼーベス2  ");
static const u8 sPauseDebug_Event47_Text[32] = SHIFT_JIS("PBOMBZEBES1 パワーボムゼーベス1  ");
static const u8 sPauseDebug_Event46_Text[32] = SHIFT_JIS("LOSTPBOMB   パワーボムロスト      ");
static const u8 sPauseDebug_Event45_Text[32] = SHIFT_JIS("CHOZOBLOCK  チョウゾブロック      ");
static const u8 sPauseDebug_Event44_Text[32] = SHIFT_JIS("VARIATYOKU  バリア チョクドリデナイ ");
static const u8 sPauseDebug_Event43_Text[32] = SHIFT_JIS("POWSUITGET  ゲット パワードスーツ  ");
static const u8 sPauseDebug_Event42_Text[32] = SHIFT_JIS("AFROHAKKEN  ロロ ココカラコウハン ロロ  ");
static const u8 sPauseDebug_Event41_Text[32] = SHIFT_JIS("ESCAPE1     ダッシュツ チュウカン    ");
static const u8 sPauseDebug_Event40_Text[32] = SHIFT_JIS("ZEBETAITO4SIゼーベタイト4 シ     ");
static const u8 sPauseDebug_Event3F_Text[32] = SHIFT_JIS("ZEBETAITO3SIゼーベタイト3 シ     ");
static const u8 sPauseDebug_Event3E_Text[32] = SHIFT_JIS("ZEBETAITO2SIゼーベタイト2 シ     ");
static const u8 sPauseDebug_Event3D_Text[32] = SHIFT_JIS("ZEBETAITO1SIゼーベタイト1 シ     ");
static const u8 sPauseDebug_Event3C_Text[32] = SHIFT_JIS("METSIROOM5  メトロイド シ5       ");
static const u8 sPauseDebug_Event3B_Text[32] = SHIFT_JIS("METSIROOM4  メトロイド シ4       ");
static const u8 sPauseDebug_Event3A_Text[32] = SHIFT_JIS("METSIROOM3  メトロイド シ3       ");
static const u8 sPauseDebug_Event39_Text[32] = SHIFT_JIS("METSIROOM2  メトロイド シ2       ");
static const u8 sPauseDebug_Event38_Text[32] = SHIFT_JIS("METSIROOM1  メトロイド シ1       ");
static const u8 sPauseDebug_Event37_Text[32] = SHIFT_JIS("METOCHUSI   メトチュー シ         ");
static const u8 sPauseDebug_Event36_Text[32] = SHIFT_JIS("RIDLEYZOOP  リドリーゾウ オープン  ");
static const u8 sPauseDebug_Event35_Text[32] = SHIFT_JIS("KRAIDZOOP   クレイドゾウ オープン  ");
static const u8 sPauseDebug_Event34_Text[32] = SHIFT_JIS("BARISUTOSI  バリスト シ         ");
static const u8 sPauseDebug_Event33_Text[32] = SHIFT_JIS("TAMAGOMAME5SIタマゴマメ5 シ      ");
static const u8 sPauseDebug_Event32_Text[32] = SHIFT_JIS("TAMAGOMAME4SIタマゴマメ4 シ      ");
static const u8 sPauseDebug_Event31_Text[32] = SHIFT_JIS("TAMAGOMAME3SIタマゴマメ3 シ      ");
static const u8 sPauseDebug_Event30_Text[32] = SHIFT_JIS("TAMAGOMAME2SIタマゴマメ2 シ      ");
static const u8 sPauseDebug_Event2F_Text[32] = SHIFT_JIS("TAMAGOMAME1SIタマゴマメ1 シ      ");
static const u8 sPauseDebug_Event2E_Text[32] = SHIFT_JIS("HANG        ハングマシンデンゲン   ");
static const u8 sPauseDebug_Event2D_Text[32] = SHIFT_JIS("MAMEMUSHI24 マメムシ24 シ        ");
static const u8 sPauseDebug_Event2C_Text[32] = SHIFT_JIS("MERONOSU    メロノス シ          ");
static const u8 sPauseDebug_Event2B_Text[32] = SHIFT_JIS("DEATHGIGASI デスギーガ シ      ");
static const u8 sPauseDebug_Event2A_Text[32] = SHIFT_JIS("KRARIDZO    クレリド ゾウ ミル    ");
static const u8 sPauseDebug_Event29_Text[32] = SHIFT_JIS("GEKITAIM    ボス ゲキタイマシン シ  ");
static const u8 sPauseDebug_Event28_Text[32] = SHIFT_JIS("CROCOSI     ボス クロコマイヤー シ   ");
static const u8 sPauseDebug_Event27_Text[32] = SHIFT_JIS("MOTHERSI    ボス マザー シ      ");
static const u8 sPauseDebug_Event26_Text[32] = SHIFT_JIS("RIDLEYELZO   リドリーエレベタゾウ  ");
static const u8 sPauseDebug_Event25_Text[32] = SHIFT_JIS("RIDLEYSI    ボス リドリー シ     ");
static const u8 sPauseDebug_Event24_Text[32] = SHIFT_JIS("GADORARIDLEY リドリーマエ ガドラ シ");
static const u8 sPauseDebug_Event23_Text[32] = SHIFT_JIS("SEICHUSI    ボス セイチュウ シ     ");
static const u8 sPauseDebug_Event22_Text[32] = SHIFT_JIS("SANAGISI    ボス サナギ シ      ");
static const u8 sPauseDebug_Event21_Text[32] = SHIFT_JIS("SANAGIFUKA   サナギ フカ        ");
static const u8 sPauseDebug_Event20_Text[32] = SHIFT_JIS("IMOMUSHI    ボス イモムシ シ      ");
static const u8 sPauseDebug_Event1F_Text[32] = SHIFT_JIS("KRAIDELZO    クレイドエレベタゾウ  ");
static const u8 sPauseDebug_Event1E_Text[32] = SHIFT_JIS("KRAIDSHI    ボス クレイド シ     ");
static const u8 sPauseDebug_Event1D_Text[32] = SHIFT_JIS("GADORAKRAID  クレイドマエ ガドラ シ");
static const u8 sPauseDebug_Event1C_Text[32] = SHIFT_JIS("WORMSHI     ボス ワーム シ       ");
static const u8 sPauseDebug_Event1B_Text[32] = SHIFT_JIS("MUKADEAORB  ドチラノムカデ       ");
static const u8 sPauseDebug_Event1A_Text[32] = SHIFT_JIS("MUKADEB     ボス ムカデB       ");
static const u8 sPauseDebug_Event19_Text[32] = SHIFT_JIS("MUKADEA     ボス ムカデA       ");
static const u8 sPauseDebug_Event18_Text[32] = SHIFT_JIS("PLASMAB     ゲット プラズマ     ");
static const u8 sPauseDebug_Event17_Text[32] = SHIFT_JIS("GRAVITYGET  ゲット グラビティ    ");
static const u8 sPauseDebug_Event16_Text[32] = SHIFT_JIS("SPACEJ      ゲット スペースジャンプ");
static const u8 sPauseDebug_Event15_Text[32] = SHIFT_JIS("SCREW       ゲット スクリュー      ");
static const u8 sPauseDebug_Event14_Text[32] = SHIFT_JIS("CHARGEGET   ゲット チャージ      ");
static const u8 sPauseDebug_Event13_Text[32] = SHIFT_JIS("VARIA       ゲット バリアスーツ    ");
static const u8 sPauseDebug_Event12_Text[32] = SHIFT_JIS("HIJUMP      ゲット ハイジャンプ   ");
static const u8 sPauseDebug_Event11_Text[32] = SHIFT_JIS("CHOJINTOWER チョウジンポールノビル  ");
static const u8 sPauseDebug_Event10_Text[32] = SHIFT_JIS("POWERHANGGETゲット パワーグリップ ");
static const u8 sPauseDebug_Event0F_Text[32] = SHIFT_JIS("SCREWCHO    タチチョウ スクリュー     ");
static const u8 sPauseDebug_Event0E_Text[32] = SHIFT_JIS("WAVECHO     タチチョウ ウェーブ     ");
static const u8 sPauseDebug_Event0D_Text[32] = SHIFT_JIS("VARIACHO    タチチョウ バリア      ");
static const u8 sPauseDebug_Event0C_Text[32] = SHIFT_JIS("HIJUMPCHO   タチチョウ ハイジャンプ  ");
static const u8 sPauseDebug_Event0B_Text[32] = SHIFT_JIS("SPEEDCHO    タチチョウ スピード    ");
static const u8 sPauseDebug_Event0A_Text[32] = SHIFT_JIS("ICECHO      タチチョウ アイス       ");
static const u8 sPauseDebug_Event09_Text[32] = SHIFT_JIS("BOMBCHO     タチチョウ ボム       ");
static const u8 sPauseDebug_Event08_Text[32] = SHIFT_JIS("LONGCHO     タチチョウ ロングビーム  ");
static const u8 sPauseDebug_Event07_Text[32] = SHIFT_JIS("DMMETROID   デモ メトロイド チュー  ");
static const u8 sPauseDebug_Event06_Text[32] = SHIFT_JIS("DMMECHA     デモ メカリドリーキドウ ");
static const u8 sPauseDebug_Event05_Text[32] = SHIFT_JIS("DMLANDING   デモ ボカンチャクリク   ");
static const u8 sPauseDebug_Event04_Text[32] = SHIFT_JIS("DMRETURN    デモ リドリーキカン    ");
static const u8 sPauseDebug_Event03_Text[32] = SHIFT_JIS("DMWAKEUP    デモ マザーノメザメ   ");
static const u8 sPauseDebug_Event02_Text[32] = SHIFT_JIS("HARD        ハードモードオン      ");
static const u8 sPauseDebug_Event01_Text[32] = SHIFT_JIS("EASY        イージーモードオン     ");
static const u8 sPauseDebug_Event00_Text[29] = SHIFT_JIS("0           ダミーダコリャ       ");

const u8 sPauseDebug_Language_Text[LANGUAGE_END + 1][3] = {
    [LANGUAGE_JAPANESE] = "JPN",
    [LANGUAGE_HIRAGANA] = "HIR",
    [LANGUAGE_ENGLISH] = "ENG",
    [LANGUAGE_GERMAN] = "GER",
    [LANGUAGE_FRENCH] = "FRA",
    [LANGUAGE_ITALIAN] = "ITA",
    [LANGUAGE_SPANISH] = "ESP",
    [LANGUAGE_END] = "@NG"
};

const u8 sPauseDebug_Region_Text[3][2] = {
    [0] = "JP",
    [1] = "EU",
    [2] = "US"
};

const u8 sPauseDebug_Area_Text[AREA_COUNT][3] = {
    [AREA_BRINSTAR] = "BRI",
    [AREA_KRAID] =    "CRA",
    [AREA_NORFAIR] =  "NOR",
    [AREA_RIDLEY] =   "RID",
    [AREA_TOURIAN] =  "TOU",
    [AREA_CRATERIA] = "CRT",
    [AREA_CHOZODIA] = "SHP",
    [AREA_DEBUG_1] =  "TST",
    [AREA_DEBUG_2] =  "TN1",
    [AREA_DEBUG_3] =  "TN2",
    [AREA_DEBUG_4] =  "TN3"
};

const u8 sPauseDebug_Difficulty_Text[DIFF_END + 1][6] = {
    [DIFF_EASY] = "EASY@@",
    [DIFF_NORMAL] = "NORMAL",
    [DIFF_HARD] = "HARD@@@",
    [DIFF_END] = "NG@@@"
};

const u8 sPauseDebug_ShutOpen_Text[2][4] = {
    [0] = "SHUT",
    [1] = "OPEN"
};

const u8 sPauseDebugAreaRoomDoorPositions[3][2] = {
    [0] = { // Area
        0, 7
    },
    [1] = { // Room
        0, 16
    },
    [2] = { // Door
        0, 25
    }
};

const u8 sPauseDebugDifficultyPosition[2] = {
    19, 23
};

const u8 sPauseDebugLanguagePosition[2] = {
    18, 23
};

const u8 sPauseDebugSaveHightlightPosition[2] = {
    13, 21
};

const struct StatusScreenGroupPositions sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_END] = {
    [PAUSE_DEBUG_GROUP_BEAM] = {
        .top = 3,
        .bottom = 7,
        .left = 9,
        .right = 15,
        .group = PAUSE_DEBUG_GROUP_BEAM
    },
    [PAUSE_DEBUG_GROUP_BOMB] = {
        .top = 3,
        .bottom = 3,
        .left = 1,
        .right = 7,
        .group = PAUSE_DEBUG_GROUP_BOMB
    },
    [PAUSE_DEBUG_GROUP_SUIT] = {
        .top = 10,
        .bottom = 11,
        .left = 9,
        .right = 15,
        .group = PAUSE_DEBUG_GROUP_SUIT
    },
    [PAUSE_DEBUG_GROUP_MISC] = {
        .top = 6,
        .bottom = 11,
        .left = 1,
        .right = 7,
        .group = PAUSE_DEBUG_GROUP_MISC
    },
    [PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .top = 3,
        .bottom = 3,
        .left = 20,
        .right = 23,
        .group = PAUSE_DEBUG_GROUP_CURRENT_ENERGY
    },
    [PAUSE_DEBUG_GROUP_MAX_ENERGY] = {
        .top = 3,
        .bottom = 3,
        .left = 25,
        .right = 28,
        .group = PAUSE_DEBUG_GROUP_MAX_ENERGY
    },
    [PAUSE_DEBUG_GROUP_CURRENT_MISSILES] = {
        .top = 5,
        .bottom = 5,
        .left = 21,
        .right = 23,
        .group = PAUSE_DEBUG_GROUP_CURRENT_MISSILES
    },
    [PAUSE_DEBUG_GROUP_MAX_MISSILES] = {
        .top = 5,
        .bottom = 5,
        .left = 25,
        .right = 27,
        .group = PAUSE_DEBUG_GROUP_MAX_MISSILES
    },
    [PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES] = {
        .top = 7,
        .bottom = 7,
        .left = 21,
        .right = 23,
        .group = PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES
    },
    [PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES] = {
        .top = 7,
        .bottom = 7,
        .left = 25,
        .right = 27,
        .group = PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES
    },
    [PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS] = {
        .top = 9,
        .bottom = 9,
        .left = 21,
        .right = 23,
        .group = PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS
    },
    [PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS] = {
        .top = 9,
        .bottom = 9,
        .left = 25,
        .right = 27,
        .group = PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS
    },
    [PAUSE_DEBUG_GROUP_GET_MAP] = {
        .top = 14,
        .bottom = 19,
        .left = 1,
        .right = 7,
        .group = PAUSE_DEBUG_GROUP_GET_MAP
    },
    [PAUSE_DEBUG_GROUP_S_EVENT] = {
        .top = 10,
        .bottom = 10,
        .left = 25,
        .right = 27,
        .group = PAUSE_DEBUG_GROUP_S_EVENT
    },
    [PAUSE_DEBUG_GROUP_EQUIP_TANK] = {
        .top = 11,
        .bottom = 11,
        .left = 18,
        .right = 27,
        .group = PAUSE_DEBUG_GROUP_EQUIP_TANK
    },
    [PAUSE_DEBUG_GROUP_TIME] = {
        .top = 16,
        .bottom = 16,
        .left = 21,
        .right = 28,
        .group = PAUSE_DEBUG_GROUP_TIME
    },
    [PAUSE_DEBUG_GROUP_SAVE] = {
        .top = 13,
        .bottom = 13,
        .left = 25,
        .right = 28,
        .group = PAUSE_DEBUG_GROUP_SAVE
    },
    [PAUSE_DEBUG_GROUP_DOOR_UNLOCK] = {
        .top = 14,
        .bottom = 14,
        .left = 25,
        .right = 28,
        .group = PAUSE_DEBUG_GROUP_DOOR_UNLOCK
    },
    [PAUSE_DEBUG_GROUP_WRITE_DEMO_RAM] = {
        .top = 0,
        .bottom = 0,
        .left = 29,
        .right = 29,
        .group = PAUSE_DEBUG_GROUP_WRITE_DEMO_RAM
    },
    [PAUSE_DEBUG_GROUP_LANGUAGE] = {
        .top = 18,
        .bottom = 18,
        .left = 23,
        .right = 25,
        .group = PAUSE_DEBUG_GROUP_LANGUAGE
    },
    [PAUSE_DEBUG_GROUP_DIFFICULTY] = {
        .top = 19,
        .bottom = 19,
        .left = 23,
        .right = 28,
        .group = PAUSE_DEBUG_GROUP_DIFFICULTY
    },
    [PAUSE_DEBUG_GROUP_SUIT_TYPE] = {
        .top = 14,
        .bottom = 16,
        .left = 9,
        .right = 15,
        .group = PAUSE_DEBUG_GROUP_SUIT_TYPE
    }
};

const u8 sEasyHardEventActions[DIFF_END][2] = {
    [DIFF_EASY] = { EVENT_ACTION_SETTING, EVENT_ACTION_CLEARING },
    [DIFF_NORMAL] = { EVENT_ACTION_CLEARING, EVENT_ACTION_CLEARING },
    [DIFF_HARD] = { EVENT_ACTION_CLEARING, EVENT_ACTION_SETTING }
};

const struct PauseDebugEnergyAmmoInfo sPauseDebugEnergyAmmoInfo[8] = {
    [PAUSE_DEBUG_GROUP_CURRENT_ENERGY - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 0,
        .is16bit = TRUE,
        .isMax = FALSE,
        .lastDigit = 3,
    },
    [PAUSE_DEBUG_GROUP_MAX_ENERGY - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 0,
        .is16bit = TRUE,
        .isMax = TRUE,
        .lastDigit = 3,
    },
    [PAUSE_DEBUG_GROUP_CURRENT_MISSILES - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 1,
        .is16bit = TRUE,
        .isMax = FALSE,
        .lastDigit = 2,
    },
    [PAUSE_DEBUG_GROUP_MAX_MISSILES - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 1,
        .is16bit = TRUE,
        .isMax = TRUE,
        .lastDigit = 2,
    },
    [PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 2,
        .is16bit = FALSE,
        .isMax = FALSE,
        .lastDigit = 2,
    },
    [PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 2,
        .is16bit = FALSE,
        .isMax = TRUE,
        .lastDigit = 2,
    },
    [PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 3,
        .is16bit = FALSE,
        .isMax = FALSE,
        .lastDigit = 2,
    },
    [PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS - PAUSE_DEBUG_GROUP_CURRENT_ENERGY] = {
        .type = 3,
        .is16bit = FALSE,
        .isMax = TRUE,
        .lastDigit = 2,
    }
};

const u8** sPauseDebugEventNamePointers[EVENT_COUNT] = {
    [EVENT_NONE] = sPauseDebug_Event00_Text,
    [EVENT_EASY] = sPauseDebug_Event01_Text,
    [EVENT_HARD] = sPauseDebug_Event02_Text,
    [EVENT_ENTER_NORFAIR_DEMO_PLAYED] = sPauseDebug_Event03_Text,
    [EVENT_EXIT_KRAID_DEMO_PLAYED] = sPauseDebug_Event04_Text,
    [EVENT_ENTER_RIDLEY_DEMO_PLAYED] = sPauseDebug_Event05_Text,
    [EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED] = sPauseDebug_Event06_Text,
    [EVENT_ENTER_TOURIAN_DEMO_PLAYED] = sPauseDebug_Event07_Text,
    [EVENT_STATUE_LONG_BEAM_GRABBED] = sPauseDebug_Event08_Text,
    [EVENT_STATUE_BOMBS_GRABBED] = sPauseDebug_Event09_Text,
    [EVENT_STATUE_ICE_BEAM_GRABBED] = sPauseDebug_Event0A_Text,
    [EVENT_STATUE_SPEEDBOOSTER_GRABBED] = sPauseDebug_Event0B_Text,
    [EVENT_STATUE_HIGH_JUMP_GRABBED] = sPauseDebug_Event0C_Text,
    [EVENT_STATUE_VARIA_SUIT_GRABBED] = sPauseDebug_Event0D_Text,
    [EVENT_STATUE_WAVE_BEAM_GRABBED] = sPauseDebug_Event0E_Text,
    [EVENT_STATUE_SCREW_ATTACK_GRABBED] = sPauseDebug_Event0F_Text,
    [EVENT_POWER_GRIP_OBTAINED] = sPauseDebug_Event10_Text,
    [EVENT_CHOZO_PILLAR_FULLY_EXTENDED] = sPauseDebug_Event11_Text,
    [EVENT_HIGH_JUMP_OBTAINED] = sPauseDebug_Event12_Text,
    [EVENT_VARIA_SUIT_OBTAINED] = sPauseDebug_Event13_Text,
    [EVENT_CHARGE_BEAM_OBTAINED] = sPauseDebug_Event14_Text,
    [EVENT_SCREW_ATTACK_OBTAINED] = sPauseDebug_Event15_Text,
    [EVENT_SPACE_JUMP_OBTAINED] = sPauseDebug_Event16_Text,
    [EVENT_GRAVITY_SUIT_OBTAINED] = sPauseDebug_Event17_Text,
    [EVENT_PLASMA_BEAM_OBTAINED] = sPauseDebug_Event18_Text,
    [EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED] = sPauseDebug_Event19_Text,
    [EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED] = sPauseDebug_Event1A_Text,
    [EVENT_DEOREM_KILLED_AT_SECOND_LOCATION] = sPauseDebug_Event1B_Text,
    [EVENT_ACID_WORM_KILLED] = sPauseDebug_Event1C_Text,
    [EVENT_KRAID_GADORA_KILLED] = sPauseDebug_Event1D_Text,
    [EVENT_KRAID_KILLED] = sPauseDebug_Event1E_Text,
    [EVENT_KRAID_ELEVATOR_STATUE_DESTROYED] = sPauseDebug_Event1F_Text,
    [EVENT_CATERPILLAR_KILLED] = sPauseDebug_Event20_Text,
    [EVENT_IMAGO_TUNNEL_DISCOVERED] = sPauseDebug_Event21_Text,
    [EVENT_IMAGO_COCOON_KILLED] = sPauseDebug_Event22_Text,
    [EVENT_IMAGO_KILLED] = sPauseDebug_Event23_Text,
    [EVENT_RIDLEY_GADORA_KILLED] = sPauseDebug_Event24_Text,
    [EVENT_RIDLEY_KILLED] = sPauseDebug_Event25_Text,
    [EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED] = sPauseDebug_Event26_Text,
    [EVENT_MOTHER_BRAIN_KILLED] = sPauseDebug_Event27_Text,
    [EVENT_CROCOMIRE_KILLED] = sPauseDebug_Event28_Text,
    [EVENT_REPEL_MACHINE_KILLED] = sPauseDebug_Event29_Text,
    [EVENT_VIEWED_STATUE_ROOM] = sPauseDebug_Event2A_Text,
    [EVENT_LONG_BEAM_DESSGEEGA_KILLED] = sPauseDebug_Event2B_Text,
    [EVENT_THREE_HIVES_DESTROYED] = sPauseDebug_Event2C_Text,
    [EVENT_BUGS_KILLED] = sPauseDebug_Event2D_Text,
    [EVENT_ZIPLINES_ACTIVATED] = sPauseDebug_Event2E_Text,
    [EVENT_PLANT_DESTROYED_LAVA] = sPauseDebug_Event2F_Text,
    [EVENT_PLANT_DESTROYED_POST_VARIA] = sPauseDebug_Event30_Text,
    [EVENT_PLANT_DESTROYED_VARIA2] = sPauseDebug_Event31_Text,
    [EVENT_PLANT_DESTROYED_VARIA3] = sPauseDebug_Event32_Text,
    [EVENT_PLANT_DESTROYED_VARIA1] = sPauseDebug_Event33_Text,
    [EVENT_KRAID_BARISTUTES_KILLED] = sPauseDebug_Event34_Text,
    [EVENT_KRAID_STATUE_OPENED] = sPauseDebug_Event35_Text,
    [EVENT_RIDLEY_STATUE_OPENED] = sPauseDebug_Event36_Text,
    [EVENT_FIRST_METROID_ROOM_CLEARED] = sPauseDebug_Event37_Text,
    [EVENT_THIRD_METROID_ROOM_CLEARED] = sPauseDebug_Event38_Text,
    [EVENT_FIFTH_METROID_ROOM_CLEARED] = sPauseDebug_Event39_Text,
    [EVENT_SECOND_METROID_ROOM_CLEARED] = sPauseDebug_Event3A_Text,
    [EVENT_SIXTH_METROID_ROOM_CLEARED] = sPauseDebug_Event3B_Text,
    [EVENT_FOURTH_METROID_ROOM_CLEARED] = sPauseDebug_Event3C_Text,
    [EVENT_ZEBETITE_ONE_DESTROYED] = sPauseDebug_Event3D_Text,
    [EVENT_ZEBETITE_TWO_DESTROYED] = sPauseDebug_Event3E_Text,
    [EVENT_ZEBETITE_THREE_DESTROYED] = sPauseDebug_Event3F_Text,
    [EVENT_ZEBETITE_FOUR_DESTROYED] = sPauseDebug_Event40_Text,
    [EVENT_ESCAPED_ZEBES] = sPauseDebug_Event41_Text,
    [EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP] = sPauseDebug_Event42_Text,
    [EVENT_FULLY_POWERED_SUIT_OBTAINED] = sPauseDebug_Event43_Text,
    [EVENT_SKIPPED_VARIA_SUIT] = sPauseDebug_Event44_Text,
    [EVENT_CHOZOBLOCK] = sPauseDebug_Event45_Text,
    [EVENT_POWER_BOMB_STOLEN] = sPauseDebug_Event46_Text,
    [EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE] = sPauseDebug_Event47_Text,
    [EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO] = sPauseDebug_Event48_Text,
    [EVENT_GLASS_TUBE_BROKEN] = sPauseDebug_Event49_Text,
    [EVENT_MECHA_RIDLEY_KILLED] = sPauseDebug_Event4A_Text,
    [EVENT_ESCAPED_CHOZODIA] = sPauseDebug_Event4B_Text,
    [EVENT_AKI] = sPauseDebug_Event4C_Text,
    [EVENT_BOMBATE] = sPauseDebug_Event4D_Text,
    [EVENT_END_UNUSED] = sPauseDebug_Event4E_Text
};

#endif // DEBUG

const u16 sStatusScreenUnknownItemsWhiteFlashingPal[6 * 16] = INCBIN_U16("data/menus/PauseScreen/MapScreenUnknownItemsFlashing.pal");
const u16 sStatusScreenUnknownItemsNamesFlashingPal[4 * 16] = INCBIN_U16("data/menus/PauseScreen/MapScreenUnknownItemsNamesFlashing.pal");

const struct StatusScreenGroupPositions sStatusScreenGroupsPositions[ABILITY_GROUP_END] = {
    [ABILITY_GROUP_BEAMS] = {
        .top = 4,
        .bottom = 10,
        .left = 0,
        .right = 7,
        .group = ABILITY_GROUP_BEAMS
    },
    [ABILITY_GROUP_BOMBS] = {
        .top = 2,
        .bottom = 5,
        .left = 18,
        .right = 29,
        .group = ABILITY_GROUP_BOMBS
    },
    [ABILITY_GROUP_SUITS] = {
        .top = 5,
        .bottom = 8,
        .left = 20,
        .right = 29,
        .group = ABILITY_GROUP_SUITS
    },
    [ABILITY_GROUP_MISC] = {
        .top = 9,
        .bottom = 16,
        .left = 20,
        .right = 29,
        .group = ABILITY_GROUP_MISC
    },
    [ABILITY_GROUP_MISSILES] = {
        .top = 11,
        .bottom = 16,
        .left = 0,
        .right = 8,
        .group = ABILITY_GROUP_MISSILES
    },
    [ABILITY_GROUP_CURRENT_ENERGY] = {
        .top = 2,
        .bottom = 2,
        .left = 8,
        .right = 11,
        .group = ABILITY_GROUP_CURRENT_ENERGY
    },
    [ABILITY_GROUP_MAX_ENERGY] = {
        .top = 2,
        .bottom = 2,
        .left = 13,
        .right = 16,
        .group = ABILITY_GROUP_MAX_ENERGY
    },
    [ABILITY_GROUP_CURRENT_MISSILES] = {
        .top = 13,
        .bottom = 13,
        .left = 1,
        .right = 3,
        .group = ABILITY_GROUP_CURRENT_MISSILES
    },
    [ABILITY_GROUP_MAX_MISSILES] = {
        .top = 13,
        .bottom = 13,
        .left = 5,
        .right = 7,
        .group = ABILITY_GROUP_MAX_MISSILES
    },
    [ABILITY_GROUP_CURRENT_SUPER_MISSILES] = {
        .top = 15,
        .bottom = 15,
        .left = 1,
        .right = 3,
        .group = ABILITY_GROUP_CURRENT_SUPER_MISSILES
    },
    [ABILITY_GROUP_MAX_SUPER_MISSILES] = {
        .top = 15,
        .bottom = 15,
        .left = 5,
        .right = 7,
        .group = ABILITY_GROUP_MAX_SUPER_MISSILES
    },
    [ABILITY_GROUP_CURRENT_POWER_BOMBS] = {
        .top = 4,
        .bottom = 4,
        .left = 24,
        .right = 25,
        .group = ABILITY_GROUP_CURRENT_POWER_BOMBS
    },
    [ABILITY_GROUP_MAX_POWER_BOMBS] = {
        .top = 4,
        .bottom = 4,
        .left = 27,
        .right = 28,
        .group = ABILITY_GROUP_MAX_POWER_BOMBS
    }
};

const struct StatusScreenGroupPositions sStatusScreenUnknownItemsPositions[10] = {
    [ABILITY_GROUP_BEAMS] = {
        .top = 20,
        .bottom = 25,
        .left = 0,
        .right = 7,
        .group = ABILITY_GROUP_BEAMS
    },
    [ABILITY_GROUP_BOMBS] = {
            .top = 20,
            .bottom = 24,
            .left = 8,
            .right = 19,
            .group = ABILITY_GROUP_BOMBS
    },
    [ABILITY_GROUP_SUITS] = {
            .top = 25,
            .bottom = 27,
            .left = 10,
            .right = 19,
            .group = ABILITY_GROUP_SUITS
    },
    [ABILITY_GROUP_MISC] = {
            .top = 24,
            .bottom = 31,
            .left = 20,
            .right = 29,
            .group = ABILITY_GROUP_MISC
    },
    [ABILITY_GROUP_MISSILES] = {
            .top = 26,
            .bottom = 31,
            .left = 0,
            .right = 8,
            .group = ABILITY_GROUP_MISSILES
    },
    [ABILITY_GROUP_CURRENT_ENERGY] = {
            .top = 0,
            .bottom = 0,
            .left = 0,
            .right = 0,
            .group = 0
    },
    [ABILITY_GROUP_MAX_ENERGY] = {
            .top = 0,
            .bottom = 0,
            .left = 0,
            .right = 0,
            .group = 0
    },
    [ABILITY_GROUP_CURRENT_MISSILES] = {
            .top = 0,
            .bottom = 0,
            .left = 0,
            .right = 0,
            .group = 0
    },
    [ABILITY_GROUP_MAX_MISSILES] = {
            .top = 0,
            .bottom = 0,
            .left = 0,
            .right = 0,
            .group = 0
    },
    [ABILITY_GROUP_CURRENT_SUPER_MISSILES] = {
            .top = 0,
            .bottom = 0,
            .left = 0,
            .right = 0,
            .group = 0
    }
};

const struct StatusScreenItemData sStatusScreenItemsData[STATUS_SLOT_END] = {
    [STATUS_SLOT_0] = {
        .group = ABILITY_GROUP_CURRENT_ENERGY,
        .abilityOffset = 0,
        .row = 0,
        .unk_3 = 0
    },
    [STATUS_SLOT_LONG_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_LONG,
        .row = 1,
        .unk_3 = 1
    },
    [STATUS_SLOT_CHARGE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_CHARGE,
        .row = 2,
        .unk_3 = 1
    },
    [STATUS_SLOT_ICE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_ICE,
        .row = 3,
        .unk_3 = 1
    },
    [STATUS_SLOT_WAVE_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_WAVE,
        .row = 4,
        .unk_3 = 1
    },
    [STATUS_SLOT_PLASMA_BEAM] = {
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_PLASMA,
        .row = 5,
        .unk_3 = 1
    },
    [STATUS_SLOT_NORMAL_MISSILE] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_NORMAL,
        .row = 1,
        .unk_3 = 0
    },
    [STATUS_SLOT_SUPER_MISSILE] = {
        .group = ABILITY_GROUP_MISSILES,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_SUPER,
        .row = 3,
        .unk_3 = 0
    },
    [STATUS_SLOT_NORMAL_BOMB] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_NORMAL,
        .row = 1,
        .unk_3 = 0
    },
    [STATUS_SLOT_POWER_BOMB] = {
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_POWER,
        .row = 2,
        .unk_3 = 0
    },
    [STATUS_SLOT_VARIA] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_VARIA,
        .row = 1,
        .unk_3 = 2
    },
    [STATUS_SLOT_GRAVITY] = {
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_GRAVITY,
        .row = 2,
        .unk_3 = 2
    },
    [STATUS_SLOT_MORPH_BALL] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_MORPH_BALL,
        .row = 1,
        .unk_3 = 2
    },
    [STATUS_SLOT_POWER_GRIP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_POWER_GRIP,
        .row = 2,
        .unk_3 = 2
    },
    [STATUS_SLOT_SPEED_BOOSTER] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER,
        .row = 3,
        .unk_3 = 2
    },
    [STATUS_SLOT_HIGH_JUMP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP,
        .row = 4,
        .unk_3 = 2
    },
    [STATUS_SLOT_SCREW_ATTACK] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK,
        .row = 5,
        .unk_3 = 2
    },
    [STATUS_SLOT_SPACE_JUMP] = {
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP,
        .row = 6,
        .unk_3 = 2
    }
};

const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[ITEM_ACQUISITION_END] = {
    [0] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [1] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [2] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_NORMAL,
        .statusSlot = STATUS_SLOT_NORMAL_MISSILE
    },
    [4] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_SUPER_MISSILES] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_MISSILE_OFFSET_SUPER + 1,
        .statusSlot = STATUS_SLOT_SUPER_MISSILE
    },
    [6] = {
        .unk_0 = 0,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = 0,
        .statusSlot = 0
    },
    [ITEM_ACQUISITION_POWER_BOMB] = {
        .unk_0 = 1,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_POWER,
        .statusSlot = STATUS_SLOT_POWER_BOMB
    },
    [ITEM_ACQUISITION_LONG_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_LONG,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_CHARGE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_CHARGE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_ICE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_ICE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_WAVE_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_WAVE,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_PLASMA_BEAM] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_BEAMS,
        .abilityOffset = STATUS_SCREEN_BEAM_OFFSET_PLASMA,
        .statusSlot = STATUS_SLOT_BEAM
    },
    [ITEM_ACQUISITION_BOMBS] = {
        .unk_0 = 2,
        .group = ABILITY_GROUP_BOMBS,
        .abilityOffset = STATUS_SCREEN_BOMB_OFFSET_NORMAL,
        .statusSlot = STATUS_SLOT_NORMAL_BOMB
    },
    [ITEM_ACQUISITION_VARIA] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_VARIA,
        .statusSlot = STATUS_SLOT_SUIT
    },
    [ITEM_ACQUISITION_GRAVITY] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_SUITS,
        .abilityOffset = STATUS_SCREEN_SUIT_OFFSET_GRAVITY,
        .statusSlot = STATUS_SLOT_SUIT
    },
    [ITEM_ACQUISITION_MORPH_BALL] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_MORPH_BALL,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SPEEDBOOSTER] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_HIGH_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SCREW_ATTACK] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_SPACE_JUMP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP,
        .statusSlot = STATUS_SLOT_MISC
    },
    [ITEM_ACQUISITION_POWER_GRIP] = {
        .unk_0 = 3,
        .group = ABILITY_GROUP_MISC,
        .abilityOffset = STATUS_SCREEN_MISC_OFFSET_POWER_GRIP,
        .statusSlot = STATUS_SLOT_MISC
    },
};

const u8 sStatusScreenUnknownItemsPartialFlash[8] = {
    0, 1, 2, 3,
    4, 3, 2, 1
};

const u8 sStatusScreenUnknownItemsFullFlash[6] = {
    0, 1, 2, 3, 4, 5
};

const u8 sStatusScreenUnknownItemsNamesFlash[4] = {
    0, 1, 2, 3
};


