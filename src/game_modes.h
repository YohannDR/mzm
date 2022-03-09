#ifndef GAME_MODE_H
#define GAME_MODE_H

#include "types.h"

enum game_mode {
    GM_SOFTRESET,
    GM_INTRO,
    GM_TITLE,
    GM_FILESELECT,
    GM_INGAME,
    GM_MAP_SCREEN,
    GM_GAMEOVER,
    GM_CHOZODIA_ESCAPE,
    GM_CREDITS,
    GM_TOURIAN_ESCAPE,
    GM_CUTSCENE,
    GM_DEMO,
    GM_GALLERY,
    GM_FUSION_GALLERY,
    GM_START_SOFTRESET, /* probably */
    GM_ERASE_SRAM,
    GM_DEBUG_MENU,
};

extern i16 game_mode;
extern i16 game_submode1;
extern i8 next_game_mode;

#endif /* GAME_MODE_H */
