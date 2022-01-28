#include "callbacks.h"
#include "game_modes.h"
#include "gba_display.h"
#include "gba_dma.h"
#include "gba_interrupt.h"
#include "gba_keys.h"
#include "gba_memory.h"
#include "gba_waitstate.h"
#include "globals.h"
#include "io.h"
#include "types.h"

void clear_ram();
void load_intr_code();
void sub_080007c4();
void read_sram();
void init_sound();
void update_input();

void init_game(void) {
    write16(REG_DISPCNT, DCNT_BLANK);
    write16(REG_IME, 0);
    write16(REG_DISPSTAT, 0);

    dma_fill32(3, 0, IWRAM_BASE, 0x40000);
    dma_fill32(3, 0, EWRAM_BASE, 0x7e00);

    clear_ram();
    load_intr_code();
    set_vblank_callback(sub_080007c4);
    read_sram();
    init_sound();

    write16(REG_IE, IF_VBLANK | IF_DMA2 | IF_GAMEPAK);
    write16(REG_DISPSTAT, DSTAT_IF_VBLANK);
    write16(
        REG_WAITCNT,
        WAIT_SRAM_4CYCLES
            | WAIT_BANK0_3CYCLES | WAIT_BANK0_SUBSEQUENT_1CYCLE
            | WAIT_BANK1_3CYCLES | WAIT_BANK1_SUBSEQUENT_1CYCLE
            | WAIT_BANK2_3CYCLES | WAIT_BANK2_SUBSEQUENT_1CYCLE
            | WAIT_GAMEPACK_CGB
    );

    game_submode1 = 0;
    game_submode2 = 0;
    debug_flag = 0;
    button_input = KEY_NONE;
    button_input_old = KEY_NONE;
    buttons_changed = KEY_NONE;

    update_input();

    if (buttons_changed == (KEY_L | KEY_R)) {
        game_mode = GM_ERASE_SRAM;
    } else {
        game_mode = GM_SOFTRESET;
    }

    button_input = 0;
    button_input_old = 0;
    buttons_changed = 0;

    softreset_disabled = 0;
    stereo_enabled = 0;

    write16(REG_IF, 0xffff);
    write16(REG_IME, 1);
}
