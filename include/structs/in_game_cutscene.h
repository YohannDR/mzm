#include "types.h"

struct SuitFlashEffect {
    u8 left;
    u8 right;
    u8 top;
    u8 bottom;
    u8 timer;
};

struct InGameCutscene {
    u16 timer;
    u8 stage;
    u8 cutsceneNumber;
    u8 cutsceneNumber_Copy;
    u8 unknown;
    Func_T pSubroutine;
};

extern struct InGameCutscene gInGameCutscene;
extern struct SuitFlashEffect gSuitFlashEffect;
