#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "gba.h"
#include "types.h"

#include "structs/cutscene.h"
#include "structs/intro.h"
#include "structs/menus/game_over.h"
#include "structs/ending_and_gallery.h"
#include "structs/menus/pause_screen.h"
#include "structs/menus/title_screen.h"
#include "structs/menus/erase_sram.h"
#include "structs/menus/file_select.h"
#include "structs/fusion_gallery.h"
#include "structs/chozodia_escape.h"
#include "structs/tourian_escape.h"


union NonGameplayRAM {
    struct CutsceneData cutscene;
    struct IntroData intro;
    struct GameOverData gameOver;
    struct EndingData ending;
    struct PauseScreenData pauseScreen;
    struct TitleScreenData titleScreen;
    struct EraseSramData eraseSram;
    struct FileSelectData fileSelect;
    struct FusionGalleryData fusionGallery;
    struct ChozodiaEscapeData chozodiaEscape;
    struct TourianEscapeData tourianEscape;
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

#endif
