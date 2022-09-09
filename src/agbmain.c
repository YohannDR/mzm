#include "funcs.h"
#include "game_modes.h"
#include "globals.h"
#include "init_game.h"
#include "softreset.h"
#include "syscalls.h"
#include "update_input.h"

// Temp place
static const i16 sSineYValues[320] = {
    0, 6, 12, 18, 25, 31, 37, 43, 49, 56, 62, 68, 74, 80,
    86, 92, 97, 103, 109, 115, 120, 126, 131, 136, 142,
    147, 152, 157, 162, 167, 171, 176, 181, 185, 189, 193,
    197, 201, 205, 209, 212, 216, 219, 222, 225, 228, 231,
    234, 236, 238, 241, 243, 244, 246, 248, 249, 251, 252,
    253, 254, 254, 255, 255, 255, 256, 255, 255, 255, 254,
    254, 253, 252, 251, 249, 248, 246, 244, 243, 241, 238,
    236, 234, 231, 228, 225, 222, 219, 216, 212, 209, 205,
    201, 197, 193, 189, 185, 181, 176, 171, 167, 162, 157,
    152, 147, 142, 136, 131, 126, 120, 115, 109, 103, 97,
    92, 86, 80, 74, 68, 62, 56, 49, 43, 37, 31, 25, 18, 12,
    6, 0, -6, -12, -18, -25, -31, -37, -43, -49, -56, -62,
    -68, -74, -80, -86, -92, -97, -103, -109, -115, -120,
    -126, -131, -136, -142, -147, -152, -157, -162, -167,
    -171, -176, -181, -185, -189, -193, -197, -201, -205,
    -209, -212, -216, -219, -222, -225, -228, -231, -234,
    -236, -238, -241, -243, -244, -246, -248, -249, -251,
    -252, -253, -254, -254, -255, -255, -255, -256, -255,
    -255, -255, -254, -254, -253, -252, -251, -249, -248,
    -246, -244, -243, -241, -238, -236, -234, -231, -228,
    -225, -222, -219, -216, -212, -209, -205, -201, -197,
    -193, -189, -185, -181, -176, -171, -167, -162, -157,
    -152, -147, -142, -136, -131, -126, -120, -115, -109,
    -103, -97, -92, -86, -80, -74, -68, -62, -56, -49, -43,
    -37, -31, -25, -18, -12, -6, 0, 6, 12, 18, 25, 31, 37,
    43, 49, 56, 62, 68, 74, 80, 86, 92, 97, 103, 109, 115,
    120, 126, 131, 136, 142, 147, 152, 157, 162, 167, 171,
    176, 181, 185, 189, 193, 197, 201, 205, 209, 212, 216,
    219, 222, 225, 228, 231, 234, 236, 238, 241, 243, 244,
    246, 248, 249, 251, 252, 253, 254, 254, 255, 255, 255
};

static const u8 sRandomNumberTable[251] = {
    53, 11, 235, 164, 249, 33, 138, 195, 58, 150, 167, 169,
    196, 154, 26, 233, 1, 50, 31, 15, 10, 230, 54, 229, 232,
    182, 200, 89, 170, 209, 27, 143, 39, 146, 91, 67, 204,
    158, 240, 191, 34, 110, 156, 185, 250, 211, 221, 92, 181,
    129, 114, 101, 35, 141, 145, 121, 238, 68, 197, 118, 107,
    198, 74, 16, 216, 93, 144, 190, 188, 32, 171, 239, 173, 139,
    134, 72, 44, 111, 37, 28, 123, 251, 199, 160, 254, 253, 147,
    157, 96, 109, 115, 59, 105, 243, 217, 14, 4, 205, 38, 0, 202,
    6, 83, 201, 75, 57, 172, 192, 86, 219, 102, 155, 189, 122,
    212, 218, 3, 108, 247, 29, 120, 126, 165, 85, 152, 179, 80,
    21, 73, 64, 2, 65, 79, 69, 13, 132, 99, 51, 207, 18, 41, 215,
    226, 127, 255, 220, 128, 124, 184, 70, 17, 45, 30, 178, 242,
    193, 90, 43, 241, 194, 187, 25, 48, 62, 20, 168, 214, 163,
    119, 234, 246, 210, 252, 228, 224, 174, 159, 106, 61, 97, 63,
    162, 137, 183, 42, 40, 236, 84, 12, 81, 95, 104, 112, 130,
    56, 22, 23, 231, 206, 88, 227, 9, 113, 8, 208, 76, 177, 248,
    135, 49, 222, 55, 142, 117, 203, 186, 149, 125, 133, 103, 161,
    151, 245, 140, 19, 87, 213, 244, 98, 47, 77, 166, 225, 136,
    94, 100, 36, 82, 46, 52, 5, 71, 176, 24, 66, 131, 148, 237,
    116, 180, 78
};

const Func_T sIntrTable[13] = {
    sub_08003380,
    CallbackCallSerialCommunication,
    CallbackCallTimer3,
    CallbackCallVblank,
    CallbackCallHBlank,
    CallbackCallVCount,
    Callback_Empty,
    Callback_Empty,
    Callback_Empty,
    Callback_Empty,
    Callback_Empty,
    Callback_Empty,
    Callback_Empty,
};

void agbmain(void)
{
    InitializeGame();

    while (gClearedEveryFrame = 0, UpdateAudio(), !gResetGame)
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