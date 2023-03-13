#include "data/in_game_cutscene_data.h"
#include "macros.h"

#include "constants/in_game_cutscene.h"
#include "constants/connection.h"
#include "in_game_cutscene.h"

const struct InGameCutsceneData sInGameCutsceneData[32] = {
    [0] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [1] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [2] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [3] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [IGC_CLOSE_UP] = {
        .unk_0 = 0,
        .area = AREA_BRINSTAR,
        .pSubroutine = InGameCutsceneSamusCloseUp
    },
    [5] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [6] = {
        .unk_0 = 0,
        .area = AREA_CRATERIA,
        .pSubroutine = NULL
    },
    [IGC_LONG_BEAM_HINT] = {
        .unk_0 = 0,
        .area = AREA_BRINSTAR,
        .pSubroutine = NULL
    },
    [8] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [IGC_GETTING_VARIA] = {
        .unk_0 = 0,
        .area = SCHAR_MAX,
        .pSubroutine = InGameCutsceneUpgradingSuit
    },
    [IGC_GETTING_FULLY_POWERED] = {
        .unk_0 = 0,
        .area = SCHAR_MAX,
        .pSubroutine = InGameCutsceneUpgradingSuit
    },
    [11] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [12] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [13] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [14] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [15] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [16] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [17] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [18] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [19] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [20] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [21] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [22] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [23] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [24] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [25] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [26] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [27] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [28] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [29] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [30] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    },
    [31] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pSubroutine = NULL
    }
};
