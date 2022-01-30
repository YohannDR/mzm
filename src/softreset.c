#include "softreset.h"

#include "game_modes.h"
#include "gba.h"
#include "globals.h"

#define SOFTRESET_KEYS (KEY_A | KEY_B | KEY_START | KEY_SELECT)

void softreset_vblank_callback(void) {
    /* probably left over from some debugging code */
    volatile char c = 0;
}

void check_softreset(void) {
    if (game_mode == GM_START_SOFTRESET) {
        return;
    }

    if (softreset_disabled) {
        return;
    }

    if ((button_input & SOFTRESET_KEYS) == SOFTRESET_KEYS) {
        game_mode = GM_START_SOFTRESET;
    }
}
