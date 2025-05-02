#include "syscalls.h"
#include "data/generic_data.h"

#include "gba.h"
#include "constants/game_state.h"

#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/display.h"

void agbmain(void)
{
    InitializeGame();

    while (TRUE)
    {
        gVblankActive = FALSE;
        UpdateAudio();

        if (gResetGame)
            break;

        UpdateInput();
        SoftresetCheck();

        APPLY_DELTA_TIME_INC(gFrameCounter8Bit);
        APPLY_DELTA_TIME_INC(gFrameCounter16Bit);

        switch (gMainGameMode)
        {
            case GM_SOFTRESET:
                if (SoftresetSubroutine())
                {
                    gMainGameMode = GM_INTRO;
                    gGameModeSub1 = 0;
                }
                break;

            case GM_INTRO:
                #ifdef DEBUG
                if (gChangedInput & KEY_R)
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_DEBUG_MENU;
                }
                else
                #endif // DEBUG
                if (IntroSubroutine())
                {
                    gMainGameMode = GM_TITLE;
                    gGameModeSub1 = 0;
                }
                break;

            case GM_TITLE:
                #ifdef DEBUG
                if (gChangedInput & KEY_R)
                {
                    gGameModeSub1 = 0;
                    gPauseScreenFlag = 0;
                    gGameModeSub2 = 0;
                    gMainGameMode = GM_DEBUG_MENU;
                }
                else
                #endif // DEBUG
                if (TitleScreenSubroutine())
                {
                    if (gGameModeSub2 == 1)
                    {
                        gMainGameMode = GM_FILE_SELECT;
                    }
                    else if (gGameModeSub2 == 2)
                    {
                        DemoStart();
                        gMainGameMode = GM_DEMO;
                    }
                    else
                    {
                        #ifdef DEBUG
                        gMainGameMode = GM_DEBUG_MENU;
                        #else // !DEBUG
                        gMainGameMode = GM_INTRO;
                        #endif // DEBUG
                    }

                    gGameModeSub1 = 0;
                    gPauseScreenFlag = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_FILE_SELECT:
                if (FileSelectMenuSubroutine())
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
                if (InGameMainLoop()) 
                {
                    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
                    {
                        if (gCurrentCutscene != 0)
                        {
                            gMainGameMode = GM_CUTSCENE;
                        }
                        else if (gTourianEscapeCutsceneStage != 0)
                        {
                            gMainGameMode = GM_TOURIAN_ESCAPE;
                        }
                        else
                        {
                            #ifdef DEBUG
                            gMainGameMode = GM_DEBUG_MENU;
                            #else // !DEBUG
                            gMainGameMode = GM_TITLE;
                            #endif // DEBUG
                            gGameModeSub1 = 0;
                        }
                    }
                    else
                    {
                        gMainGameMode = GM_MAP_SCREEN;
                    }
                }
                break;

            case GM_MAP_SCREEN:
                if (PauseScreenSubroutine())
                {
                    gMainGameMode = gGameModeSub2;
                    gGameModeSub2 = 0;

                    switch (gPauseScreenFlag)
                    {
                        case PAUSE_SCREEN_UNKNOWN_1:
                            gGameModeSub3 = 0;

                        case PAUSE_SCREEN_SUITLESS_ITEMS:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            break;

                        case PAUSE_SCREEN_UNKNOWN_9:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            gGameModeSub2 = 1;
                            break;

                        case PAUSE_SCREEN_PAUSE_OR_CUTSCENE:
                        case PAUSE_SCREEN_UNKNOWN_3:
                        case PAUSE_SCREEN_CHOZO_HINT:
                        case PAUSE_SCREEN_MAP_DOWNLOAD:
                        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS:
                            break;
                    }

                    gGameModeSub1 = 0;
                }
                break;

            case GM_GAMEOVER:
                if (GameOverSubroutine())
                {
                    gMainGameMode = gGameModeSub2;
                    gGameModeSub1 = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_CHOZODIA_ESCAPE:
                if (ChozodiaEscapeSubroutine())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_CREDITS;
                }
                break;

            case GM_CREDITS:
                if (CreditsSubroutine())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_INTRO;
                    #ifdef DEBUG
                    if (gBootDebugActive || gDebugMode)
                        gMainGameMode = GM_DEBUG_MENU;
                    #endif // DEBUG
                }
                break;

            case GM_TOURIAN_ESCAPE:
                if (TourianEscapeSubroutine())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = gGameModeSub2;
                    #ifdef DEBUG
                    if (gBootDebugActive)
                        gMainGameMode = GM_DEBUG_MENU;
                    #endif // DEBUG
                }
                break;

            case GM_CUTSCENE:
                if (CutsceneSubroutine())
                {
                    gGameModeSub1 = 0;

                    if (gPauseScreenFlag == PAUSE_SCREEN_SUITLESS_ITEMS || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
                    {
                        gMainGameMode = GM_MAP_SCREEN;
                    }
                    else
                    {
                        gMainGameMode = GM_INGAME;
                        #ifdef DEBUG
                        if (gBootDebugActive)
                            gMainGameMode = gBootDebugActive;
                        #endif // DEBUG
                    }
                }
                break;

            case GM_DEMO:
                if (InGameMainLoop())
                {
                    if (gPauseScreenFlag == PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
                    {
                        gPauseScreenFlag = PAUSE_SCREEN_NONE;
                        gGameModeSub3 = 0;
                        gGameModeSub1 = 0;
                        if (gDemoState == 0)
                        {
                            gMainGameMode = gGameModeSub2;
                            gGameModeSub2 = gCurrentDemo.endedWithInput;
                        }
                        else {
                            DemoStart();
                            gMainGameMode = GM_DEMO;
                        }
                    }
                    else
                        gMainGameMode = GM_MAP_SCREEN;
                }
                break;

            case GM_GALLERY:
                if (GallerySubroutine())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_FILE_SELECT;
                }
                break;

            case GM_FUSION_GALLERY:
                if (FusionGallerySubroutine())
                {
                    gGameModeSub1 = 0;
                    gMainGameMode = GM_FILE_SELECT;
                }
                break;

            case GM_START_SOFTRESET:
                Softreset();
                break;

            case GM_ERASE_SRAM:
                if (EraseSramSubroutine())
                {
                    if (gGameModeSub2 == 1)
                    {
                        gResetGame = TRUE;
                    }
                    else
                    {
                        gMainGameMode = GM_SOFTRESET;
                        #ifdef DEBUG
                        if (gDebugMode)
                            gMainGameMode = GM_DEBUG_MENU;
                        #endif // DEBUG
                    }

                    gGameModeSub1 = 0;
                    gGameModeSub2 = 0;
                }
                break;

            case GM_DEBUG_MENU:
                #ifdef DEBUG
                if (BootDebugSubroutine())
                {
                    gGameModeSub1 = 0;

                    switch (gGameModeSub2)
                    {
                        case 1:
                            gMainGameMode = GM_INGAME;
                            break;
                        case 2:
                            gMainGameMode = GM_INTRO;
                            break;
                        case 3:
                            gMainGameMode = GM_MAP_SCREEN;
                            break;
                        case 6:
                            gMainGameMode = GM_DEMO;
                            break;
                        case 8:
                            gMainGameMode = GM_CUTSCENE;
                            gGameModeSub2 = 0x10;
                            break;
                        case 7:
                            gMainGameMode = GM_TOURIAN_ESCAPE;
                            gGameModeSub2 = 0x10;
                            break;
                        case 5:
                            gMainGameMode = GM_CREDITS;
                            break;
                        case 4:
                            gMainGameMode = GM_CHOZODIA_ESCAPE;
                            break;
                        default:
                            gMainGameMode = GM_DEBUG_MENU;
                            gWrittenToBLDY_NonGameplay = 0;
                            break;
                    }
                }
                #else // !DEBUG
                for (;;) {}
                #endif // DEBUG
                break;
        }
        

        gVBlankRequestFlag &= ~TRUE;
        gVblankActive = TRUE;

        do {
            SYSCALL(2); /* SYS_Halt */
        } while (!(gVBlankRequestFlag & 1));
    }
}
