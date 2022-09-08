#include "funcs.h"
#include "game_modes.h"
#include "globals.h"
#include "init_game.h"
#include "softreset.h"
#include "syscalls.h"
#include "update_input.h"

void agbmain(void)
{
    InitializeGame();

    while (gClearedEveryFrame = 0, sub_08004d48(), !gResetGame)
    {
        UpdateInput();
        SoftresetCheck();

        gFrameCounter8Bit++;
        gFrameCounter16Bit++;

        switch (gMainGameMode) {
            case GM_SOFTRESET:
                if (softreset_main()) {
                    gMainGameMode = GM_INTRO;
                    gGameModeSub1 = 0;
                }
                break;

            case GM_INTRO:
                if (intro_main()) {
                    gMainGameMode = GM_TITLE;
                    gGameModeSub1 = 0;
                }
                break;

            case GM_TITLE:
                if (titlescreen_main())
                {
                    if (gGameModeSub2 == 1)
                        gMainGameMode = GM_FILESELECT;
                    else if (gGameModeSub2 == 2)
                    {
                        start_new_demo();
                        gMainGameMode = GM_DEMO;
                    }
                    else
                        gMainGameMode = GM_INTRO;
                    gGameModeSub1 = 0;
                    gPauseScreenFlag = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_FILESELECT:
                if (fileselect_main())
                {
                    if (gGameModeSub2 == 1)
                        gMainGameMode = GM_INGAME;
                    else if (gGameModeSub2 == 2)
                        gMainGameMode = GM_INGAME;
                    else if (gGameModeSub2 == 4)
                        gMainGameMode = GM_FUSION_GALLERY;
                    else if (gGameModeSub2 == 5)
                        gMainGameMode = GM_GALLERY;
                    else
                        gMainGameMode = GM_INTRO;
                    gGameModeSub1 = 0;
                    gGameModeSub3 = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_INGAME:
                if (ingame_main()) 
                {
                    i8 psf = gPauseScreenFlag;
                    if (psf == PAUSE_SCREEN_NONE)
                    {
                        if (gCurrentCutscene != 0)
                            gMainGameMode = GM_CUTSCENE;
                        else if (gTourianEscapeCutsceneStage != 0)
                            gMainGameMode = GM_TOURIAN_ESCAPE;
                        else
                        {
                            gMainGameMode = GM_TITLE;
                            gGameModeSub1 = 0;
                        }
                    }
                    else
                        gMainGameMode = GM_MAP_SCREEN;
                }
                break;

            case GM_MAP_SCREEN:
                if (map_screen_main())
                {
                    i8 psf;
                    gMainGameMode = gGameModeSub2;
                    gGameModeSub2 = 0;

                    psf = gPauseScreenFlag - 1;
                    switch (psf) {
                        case PAUSE_SCREEN_UNKNOWN_1 - 1:
                            gGameModeSub3 = 0;

                        case PAUSE_SCREEN_SUITLESS_ITEMS - 1:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            break;

                        case PAUSE_SCREEN_UNKNOWN_9 - 1:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            gGameModeSub2   = 1;
                            break;

                        case PAUSE_SCREEN_PAUSE_OR_CUTSCENE - 1:
                        case PAUSE_SCREEN_UNKNOWN_3 - 1:
                        case PAUSE_SCREEN_CHOZO_HINT - 1:
                        case PAUSE_SCREEN_MAP_DOWNLOAD - 1:
                        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS - 1:
                            break;
                    }

                    gGameModeSub1 = 0;
                }
                break;

            case GM_GAMEOVER:
                if (gameover_main())
                {
                    gMainGameMode = gGameModeSub2;
                    gGameModeSub1 = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_CHOZODIA_ESCAPE:
                if (chozodia_escape_main())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_CREDITS;
                }
                break;

            case GM_CREDITS:
                if (credits_main())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_INTRO;
                }
                break;

            case GM_TOURIAN_ESCAPE:
                if (tourian_escape_main())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = gGameModeSub2;
                }
                break;

            case GM_CUTSCENE:
                if (cutscene_main())
                {
                    u8 psf;
                    gGameModeSub1 = 0;
                    psf = gPauseScreenFlag - 7;
                    if (psf <= 1)
                    {
                        gMainGameMode = GM_MAP_SCREEN;
                        break;
                    }
                    gMainGameMode = GM_INGAME;
                }
                break;

            case GM_DEMO:
                if (ingame_main())
                {
                    i8 psf = gPauseScreenFlag;
                    if (psf == PAUSE_SCREEN_PAUSE_OR_CUTSCENE) {
                        gPauseScreenFlag = PAUSE_SCREEN_NONE;
                        gGameModeSub3 = 0;
                        gGameModeSub1 = 0;
                        if (gDemoState == 0) {
                            gMainGameMode = gGameModeSub2;
                            gGameModeSub2 = (gCurrentDemo << 4) >> 0x1c; /* XXX: probably struct */
                        }
                        else {
                            start_new_demo();
                            gMainGameMode = GM_DEMO;
                        }
                    }
                    else
                        gMainGameMode = GM_MAP_SCREEN;
                }
                break;

            case GM_GALLERY:
                if (gallery_main())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_FILESELECT;
                }
                break;

            case GM_FUSION_GALLERY:
                if (fusion_gallery_main())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_FILESELECT;
                }
                break;

            case GM_START_SOFTRESET:
                Softreset();
                break;

            case GM_ERASE_SRAM:
                if (erase_sram_main())
                {
                    if (gGameModeSub2 == 1)
                        gResetGame = TRUE;
                    else
                        gMainGameMode = GM_SOFTRESET;

                    gGameModeSub1 = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_DEBUG_MENU:
                for (;;) {
                    // TODO add debug code
                    /* EMPTY */
                }
            }
        

        gVBlankRequestFlag &= 0xfffe;
        gClearedEveryFrame = 1;

        do {
            SYSCALL(2); /* SYS_Halt */
        } while (!(gVBlankRequestFlag & 1));
    }
}