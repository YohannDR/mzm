#include "data/internal_text_data.h"
#include "data/text_pointers.h"
#include "data/menus/status_screen_data.h"
#include "macros.h"

const u16* const * const sDescriptionTextPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sJapaneseTextPointers_Description,
    [LANGUAGE_HIRAGANA] = sHiraganaTextPointers_Description,
    [LANGUAGE_ENGLISH] = sEnglishTextPointers_Description,
    [LANGUAGE_GERMAN] = sEnglishTextPointers_Description,
    [LANGUAGE_FRENCH] = sEnglishTextPointers_Description,
    [LANGUAGE_ITALIAN] = sEnglishTextPointers_Description,
    [LANGUAGE_SPANISH] = sEnglishTextPointers_Description
};

FORCE_RODATA
u32 sArray_7602f0[9] = {
    [0] = UINT_MAX ^ (UINT_MAX << 0 * sizeof(u32)),
    [1] = UINT_MAX ^ (UINT_MAX << 1 * sizeof(u32)),
    [2] = UINT_MAX ^ (UINT_MAX << 2 * sizeof(u32)),
    [3] = UINT_MAX ^ (UINT_MAX << 3 * sizeof(u32)),
    [4] = UINT_MAX ^ (UINT_MAX << 4 * sizeof(u32)),
    [5] = UINT_MAX ^ (UINT_MAX << 5 * sizeof(u32)),
    [6] = UINT_MAX ^ (UINT_MAX << 6 * sizeof(u32)),
    [7] = UINT_MAX ^ (UINT_MAX << 7 * sizeof(u32)),
    [8] = UINT_MAX
};

FORCE_RODATA
u32 sArray_760314[9] = {
    [0] = UINT_MAX ^ (UINT_MAX >> 0 * sizeof(u32)),
    [1] = UINT_MAX ^ (UINT_MAX >> 1 * sizeof(u32)),
    [2] = UINT_MAX ^ (UINT_MAX >> 2 * sizeof(u32)),
    [3] = UINT_MAX ^ (UINT_MAX >> 3 * sizeof(u32)),
    [4] = UINT_MAX ^ (UINT_MAX >> 4 * sizeof(u32)),
    [5] = UINT_MAX ^ (UINT_MAX >> 5 * sizeof(u32)),
    [6] = UINT_MAX ^ (UINT_MAX >> 6 * sizeof(u32)),
    [7] = UINT_MAX ^ (UINT_MAX >> 7 * sizeof(u32)),
    [8] = UINT_MAX
};

FORCE_RODATA
u32 sArray_760338[8] = {
    [0] = 15 << 0 * sizeof(u32),
    [1] = 15 << 1 * sizeof(u32),
    [2] = 15 << 2 * sizeof(u32),
    [3] = 15 << 3 * sizeof(u32),
    [4] = 15 << 4 * sizeof(u32),
    [5] = 15 << 5 * sizeof(u32),
    [6] = 15 << 6 * sizeof(u32),
    [7] = 15 << 7 * sizeof(u32)
};

#ifdef DEBUG
const u8* const sPauseDebugEventNamePointers[EVENT_COUNT] = {
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

const u32 sArray_760358[8] = {
    [0] = 2 << 0 * sizeof(u32),
    [1] = 2 << 1 * sizeof(u32),
    [2] = 2 << 2 * sizeof(u32),
    [3] = 2 << 3 * sizeof(u32),
    [4] = 2 << 4 * sizeof(u32),
    [5] = 2 << 5 * sizeof(u32),
    [6] = 2 << 6 * sizeof(u32),
    [7] = 2 << 7 * sizeof(u32)
};

const u32 sArray_760378[8] = {
    [0] = 1 << 0 * sizeof(u32),
    [1] = 1 << 1 * sizeof(u32),
    [2] = 1 << 2 * sizeof(u32),
    [3] = 1 << 3 * sizeof(u32),
    [4] = 1 << 4 * sizeof(u32),
    [5] = 1 << 5 * sizeof(u32),
    [6] = 1 << 6 * sizeof(u32),
    [7] = 1 << 7 * sizeof(u32)
};

FORCE_RODATA
u32 sArray_760398[8] = {
    [0] = 4 << 0 * sizeof(u32),
    [1] = 4 << 1 * sizeof(u32),
    [2] = 4 << 2 * sizeof(u32),
    [3] = 4 << 3 * sizeof(u32),
    [4] = 4 << 4 * sizeof(u32),
    [5] = 4 << 5 * sizeof(u32),
    [6] = 4 << 6 * sizeof(u32),
    [7] = 4 << 7 * sizeof(u32)
};

FORCE_RODATA
u32 sArray_7603b8[8] = {
    [0] = 15 << 0 * sizeof(u32),
    [1] = 15 << 1 * sizeof(u32),
    [2] = 15 << 2 * sizeof(u32),
    [3] = 15 << 3 * sizeof(u32),
    [4] = 15 << 4 * sizeof(u32),
    [5] = 15 << 5 * sizeof(u32),
    [6] = 15 << 6 * sizeof(u32),
    [7] = 15 << 7 * sizeof(u32)
};
