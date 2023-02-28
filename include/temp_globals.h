#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "gba.h"
#include "types.h"

#include "structs/cutscene.h"
#include "structs/intro.h"
#include "structs/game_over.h"
#include "structs/ending_and_gallery.h"
#include "structs/menus/pause_screen.h"
#include "structs/menus/title_screen.h"


union NonGameplayRAM {
    struct CutsceneData cutscene;
    struct IntroData intro;
    struct GameOverData gameOver;
    struct EndingData ending;
    struct PauseScreenData pauseScreen;
    struct TitleScreenData titleScreen;
    u8 inGame[1576];
};

extern u16 unk_02035400;

extern u8 gUnk_03004fc9;
extern union NonGameplayRAM gNonGameplayRAM;

extern u16 gBG0HOFS_NonGameplay;
extern u16 gBG0VOFS_NonGameplay;
extern u16 gBG1HOFS_NonGameplay;
extern u16 gBG1VOFS_NonGameplay;
extern u16 gBG2HOFS_NonGameplay;
extern u16 gBG2VOFS_NonGameplay;
extern u16 gBG3HOFS_NonGameplay;
extern u16 gBG3VOFS_NonGameplay;

extern u16 gCurrentOamRotation;
extern u16 gCurrentOamScaling;

extern i8 gMenuOamXOffset;
extern i8 gMenuOamYOffset;

#endif
