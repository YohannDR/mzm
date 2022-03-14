#include "funcs.h"
#include "game_modes.h"
#include "globals.h"
#include "init_game.h"
#include "softreset.h"
#include "syscalls.h"
#include "update_input.h"

void agbmain(void) {
    init_game();

    while (
        unk_03000c76 = 0,
        sub_08004d48(),
        !reset_game
    ) {
        update_input();
        check_softreset();

        ++frame_counter_8bit;
        ++frame_counter_16bit;

        switch (game_mode_main) {
        case GM_SOFTRESET:
            if (sub_0807ef9c()) {
                game_mode_main = GM_INTRO;
                game_mode_sub1 = 0;
            }
            break;

        case GM_INTRO:
            if (intro_main()) {
                game_mode_main = GM_TITLE;
                game_mode_sub1 = 0;
            }
            break;

        case GM_TITLE:
            if (titlescreen_main()) {
                if (game_mode_sub2 == 1) {
                    game_mode_main = GM_FILESELECT;
                } else if (game_mode_sub2 == 2) {
                    start_new_demo();
                    game_mode_main = GM_DEMO;
                } else {
                    game_mode_main = GM_INTRO;
                }
                game_mode_sub1 = 0;
                pause_screen_flag = 0;
                game_mode_sub2 = 0;
            }
            break;

        case GM_FILESELECT:
            if (fileselect_main()) {
                if (game_mode_sub2 == 1) {
                    game_mode_main = GM_INGAME;
                } else if (game_mode_sub2 == 2) {
                    game_mode_main = GM_INGAME;
                } else if (game_mode_sub2 == 4) {
                    game_mode_main = GM_FUSION_GALLERY;
                } else if (game_mode_sub2 == 5) {
                    game_mode_main = GM_GALLERY;
                } else {
                    game_mode_main = GM_INTRO;
                }
                game_mode_sub1 = 0;
                game_mode_sub3 = 0;
                game_mode_sub2 = 0;
            }
            break;

        case GM_INGAME:
            if (ingame_main()) {
                i8 psf = pause_screen_flag;
                if (psf == PAUSE_SCREEN_NONE) {
                    if (curr_cutscene != 0) {
                        game_mode_main = GM_CUTSCENE;
                    } else if (unk_0300007e != 0) {
                        game_mode_main = GM_TOURIAN_ESCAPE;
                    } else {
                        game_mode_main = GM_TITLE;
                        game_mode_sub1 = 0;
                    }
                } else {
                    game_mode_main = GM_MAP_SCREEN;
                }
            }
            break;

        case GM_MAP_SCREEN:
            if (map_screen_main()) {
                i8 psf;
                game_mode_main = game_mode_sub2;
                game_mode_sub2 = 0;

                psf = pause_screen_flag - 1;
                switch (psf) {
                case PAUSE_SCREEN_UNKNOWN_1 - 1:
                    game_mode_sub3 = 0;
                    /* FALLTHROUGH */
                case PAUSE_SCREEN_SUITLESS_ITEMS - 1:
                    pause_screen_flag = PAUSE_SCREEN_NONE;
                    break;
                case PAUSE_SCREEN_UNKNOWN_9 - 1:
                    pause_screen_flag = PAUSE_SCREEN_NONE;
                    game_mode_sub2 = 1;
                    break;

                case PAUSE_SCREEN_PAUSE_OR_CUTSCENE - 1:
                case PAUSE_SCREEN_UNKNOWN_3 - 1:
                case PAUSE_SCREEN_CHOZO_HINT - 1:
                case PAUSE_SCREEN_MAP_DOWNLOAD - 1:
                case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS - 1:
                    break;
                }

                game_mode_sub1 = 0;
            }
            break;

        case GM_GAMEOVER:
            if (gameover_main()) {
                game_mode_main = game_mode_sub2;
                game_mode_sub1 = 0;
                game_mode_sub2 = 0;
            }
            break;

        case GM_CHOZODIA_ESCAPE:
            if (chozodia_escape_main()) {
                game_mode_sub1 = 0;
                game_mode_main = GM_CREDITS;
            }
            break;

        case GM_CREDITS:
            if (credits_main()) {
                game_mode_sub1 = 0;
                game_mode_main = GM_INTRO;
            }
            break;

        case GM_TOURIAN_ESCAPE:
            if (tourian_escape_main()) {
                game_mode_sub1 = 0;
                game_mode_main = game_mode_sub2;
            }
            break;

        case GM_CUTSCENE:
            if (cutscene_main()) {
                u8 psf;
                game_mode_sub1 = 0;
                psf = pause_screen_flag - 7;
                if (psf <= 1) {
                    game_mode_main = GM_MAP_SCREEN;
                    break;
                }
                game_mode_main = GM_INGAME;
            }
            break;

        case GM_DEMO:
            if (ingame_main()) {
                i8 psf = pause_screen_flag;
                if (psf == PAUSE_SCREEN_PAUSE_OR_CUTSCENE) {
                    pause_screen_flag = PAUSE_SCREEN_NONE;
                    game_mode_sub3 = 0;
                    game_mode_sub1 = 0;
                    if (unk_030013d2 == 0) {
                        game_mode_main = game_mode_sub2;
                        game_mode_sub2 = (curr_demo << 4) >> 0x1c; /* XXX: probably struct */
                    } else {
                        start_new_demo();
                        game_mode_main = GM_DEMO;
                    }
                } else {
                    game_mode_main = GM_MAP_SCREEN;
                }
            }
            break;

        case GM_GALLERY:
            if (gallery_main()) {
                game_mode_sub1 = 0;
                game_mode_main = GM_FILESELECT;
            }
            break;

        case GM_FUSION_GALLERY:
            if (fusion_gallery_main()) {
                game_mode_sub1 = 0;
                game_mode_main = GM_FILESELECT;
            }
            break;

        case GM_START_SOFTRESET:
            softreset();
            break;

        case GM_ERASE_SRAM:
            if (erase_sram_main()) {
                if (game_mode_sub2 == 1) {
                    reset_game = 1;
                } else {
                    game_mode_main = GM_SOFTRESET;
                }
                game_mode_sub1 = 0;
                game_mode_sub2 = 0;
            }
            break;

        case GM_DEBUG_MENU:
            for (;;) {
                /* EMPTY */
            }
        }

        vblank_request_flag &= 0xfffe;
        unk_03000c76 = 1;

        do {
            SYSCALL(2); /* SYS_Halt */
        } while (!(vblank_request_flag & 1));
    }
}
