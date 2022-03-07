#include "softreset.h"

#include "callbacks.h"
#include "funcs.h"
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

void softreset(void) {
    sub_0805d034();
    sub_080033dc();

    write16(REG_IME, 0);
    write16(REG_IE, 0);
    write16(REG_DISPSTAT, 0);
    PLTT_BG[0] = 0;
    write16(REG_DISPCNT, 0);
    write16(REG_BLDY, 0x10);
    write16(REG_BLDCNT, 0xff);

    dma_fill32(3, 0, IWRAM_BASE, 0x40000);
    dma_fill32(3, 0, EWRAM_BASE, 0x7e00);

    clear_ram();
    load_intr_code();
    set_vblank_callback(softreset_vblank_callback);
    read_sram();
    init_sound();

    write16(REG_IE, IF_VBLANK | IF_DMA2 | IF_GAMEPAK);
    write16(REG_DISPSTAT, DSTAT_IF_VBLANK);

    game_mode = GM_INTRO;
    game_submode1 = 0;
    game_submode2 = 0;
    reset_game = 0;
    stereo_enabled = 0;
    button_input = KEY_NONE;
    button_input_old = KEY_NONE;
    buttons_changed = KEY_NONE;

    write16(REG_IF, 0xffff);
    write16(REG_IME, 1);
}
