#include "room_music.h"

#include "data/engine_pointers.h"
#include "data/cutscenes/cutscenes_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/demo.h"
#include "constants/game_state.h"
#include "constants/samus.h"

#include "structs/audio.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 60928 | bc | Checks if the current room music track should play
 * 
* @param area Area
 * @param room Room id
 */
void CheckPlayRoomMusicTrack(u8 area, u8 room)
{
    gMusicTrackInfo.currentRoomTrack = sAreaRoomEntryPointers[area][room].musicTrack;

    gMusicTrackInfo.unk = FALSE;

    switch (gAreaBeforeTransition)
    {
        case AREA_NORFAIR:
            if (gMusicTrackInfo.currentRoomTrack == 0x5F)
                gMusicTrackInfo.unk = TRUE;
            break;

        case AREA_CHOZODIA:
            if (gEquipment.suitType == SUIT_FULLY_POWERED && gAlarmTimer != 0 &&
                (gMusicTrackInfo.currentRoomTrack == 0x5B || gMusicTrackInfo.currentRoomTrack == 0x5C))
                gMusicTrackInfo.unk = TRUE;
    }

    if (!gMusicTrackInfo.unk)
    {
        if (!gCurrentCutscene || sCutsceneData[gCurrentCutscene].type)
        {
            CheckSetNewMusicTrack(gMusicTrackInfo.currentRoomTrack);
            gMusicTrackInfo.takingNormalTransition = TRUE;
        }
    }

    gDestinationRoom = room;
}

/**
 * @brief 609e4 | 64 | Checks if the loading jingle should play
 * 
 */
void CheckPlayLoadingJingle(void)
{
    gMusicTrackInfo.currentRoomTrack = gCurrentRoomEntry.musicTrack;

    if (!gGameModeSub3 && gDemoState == DEMO_STATE_NONE && gIsLoadingFile)
    {
        PlayCurrentMusicTrack();
        if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
        {
            gDisablePause = TRUE;
            InsertMusicAndQueueCurrent(MUSIC_LOADING_JINGLE, 1);
        }
    }
}

void UpdateMusicWhenPausing(void)
{
    gMusicTrackInfo.pauseScreenFlag = 0;
    switch (gPauseScreenFlag)
    {
        case PAUSE_SCREEN_UNKNOWN_1:
            break;

        case PAUSE_SCREEN_PAUSE_OR_CUTSCENE:
            DecreaseMusicVolume();
            gMusicTrackInfo.pauseScreenFlag = gPauseScreenFlag;
            break;

        case PAUSE_SCREEN_CHOZO_HINT:
        case PAUSE_SCREEN_ITEM_ACQUISITION:
            gMusicTrackInfo.pauseScreenFlag = gPauseScreenFlag;
            break;

        case PAUSE_SCREEN_MAP_DOWNLOAD:
            break;

        case PAUSE_SCREEN_SUITLESS_ITEMS:
            break;

        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS:
            break;
    }
}

/**
 * @brief 60ab8 | 5c | Updates the music after leaving the pause menu
 * 
 */
void UpdateMusicAfterPause(void)
{
    switch (gMusicTrackInfo.pauseScreenFlag)
    {
        case PAUSE_SCREEN_UNKNOWN_1:
            break;

        case PAUSE_SCREEN_PAUSE_OR_CUTSCENE:
            ResetMusicVolume();
            break;

        case PAUSE_SCREEN_CHOZO_HINT:
            break;

        case PAUSE_SCREEN_MAP_DOWNLOAD:
            break;

        case PAUSE_SCREEN_ITEM_ACQUISITION:
            RetrieveTrackData2SoundChannels();
            break;

        case PAUSE_SCREEN_SUITLESS_ITEMS:
            PlayMusic(MUSIC_CHOZO_RUINS, 16);
            break;

        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS:
            break;
    }
}
