#include "room.h"
#include "memory.h"
#include "screen_shake.h"
#include "globals.h"
#include "event.h"
#include "bg_clip.h"

void RoomLoad(void)
{
    /*ClipdataSetupCode();
    RoomReset();

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        RoomLoadEntry();
        ScrollLoad();
        RoomSetBackgroundScrolling();
    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_ITEM_ACQUISITION)
    {

    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
    {

    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_SUITLESS_ITEMS)
        MusicPlay(0xE, 0x10); // Chozo ruins

    RoomLoadTileset();
    RoomLoadBackgrounds();
    RoomRemoveNeverReformBlocksAndCollectedTanks();
    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;
    TransparencySetRoomEffectsTransparency();
    LoadFirstRoom(); // Undefined

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && !gIsLoadingFile)
    {
        ScrollProcessGeneral();
        gBG1YPosition = gScreenPositionAndVelocity.yPosition;
        gBG1XPosition = gScreenPositionAndVelocity.xPosition;
        ScrollBG3Related();
        ScrollProcessGeneral();
    }

    CheckPlayLightningEffect(); // Undefined
    RoomUpdateBackgroundsPosition();
    ConnectionLoadDoors();
    ConnectionCheckHatchLockEvents();
    RoomSetInitialTilemap(0x0);
    RoomSetInitialTilemap(0x1);
    RoomSetInitialTilemap(0x2);
    LoadAnimatedGraphics(); // Undefined
    ResetTanksAnimation(); // Undefined
    SetBGHazeEffect(); // Undefined
    ProcessHaze(); // Undefined
    MinimapCheckOnTransition(); // Undefined

    if (!gIsLoadingFile && gGameModeSub3 != 0x0 && gPauseScreenFlag == PAUSE_SCREEN_NONE && gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        if (gSamusData.elevatorDirection == KEY_UP)
            gSamusData.yPosition += 0xC0;
        else
            gSamusData.yPosition -= 0xC0;
        gPreviousYPosition = gSamusData.yPosition;
    }

    sub_08060800(); // Undefined

    if (gRainSoundEffect != RAIN_SOUND_NONE)
    {
        if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
        {
            if (gRainSoundEffect & RAIN_SOUND_PLAYING)
            {
                if (!(gRainSoundEffect & RAIN_SOUND_ENABLED))
                    SoundFade(0x121, 0xA); // Rain
                    gRainSoundEffect &= ~RAIN_SOUND_PLAYING;
            }
            else if (gRainSoundEffect & RAIN_SOUND_ENABLED)
            {
                SoundPlayNotAlreadyPlaying(0x121); // Rain
                gRainSoundEffect |= RAIN_SOUND_PLAYING;
            }
        }
        gRainSoundEffect &= ~RAIN_SOUND_ENABLED;
    }*/
}

void RoomLoadTileset(void)
{

}

/**
 * 56404 | 168 | Load the current room entry
 * 
 */
void RoomLoadEntry(void)
{
    /*struct RoomEntryROM* entry;
    u16 effectY;

    entry = entry_pointers[gCurrentArea][gCurrentRoom]; // memcpy at compilation

    // Fill basic dat
    gCurrentRoomEntry.tileset = entry.tileset;
    gCurrentRoomEntry.BG0Prop = entry.BG0Prop;
    gCurrentRoomEntry.BG1Prop = entry.BG1Prop;
    gCurrentRoomEntry.BG2Prop = entry.BG2Prop;
    gCurrentRoomEntry.BG3Prop = entry.BG3Prop;
    gCurrentRoomEntry.BG3Scrolling = entry.BG3Scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;
    gCurrentRoomEntry.mapX = entry.mapX;
    gCurrentRoomEntry.mapY = entry.mapY;
    gCurrentRoomEntry.effect = entry.effect;
    gCurrentRoomEntry.musicTrack = entry.musicTrack;

    // Check for room effect
    effectY = entry.effectY;
    if (effectY != 0xFF)
        gCurrentRoomEntry.effectY = effectY << 0x6;
    else
        gCurrentRoomEntry.effectY = 0xFFFF;

    // gCurrentRoomEntry.effectY = effectY;
    gSpritesetEntryUsed = 0x0;
    // Set events
    gCurrentRoomEntry.firstSpritesetEvent = entry.firstSpritesetEvent;
    gCurrentRoomEntry.secondSpritesetEvent = entry.secondSpritesetEvent;
    // Check for second spriteset
    if (entry.secondSpritesetEvent != EVENT_NONE && EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.secondSpritesetEvent))
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pSecondSpriteData;
        gSpriteset = entry.second_spriteset;
        gSpritesetEntryUsed = 0x2;
    }
    // Check for first spriteset
    if (gCurrentRoomEntry.firstSpritesetEvent != EVENT_NONE && gSpritesetEntryUsed == 0x0)
    {
        if (gSpritesetEntryUsed != 0x0)
        {
            gCurrentRoomEntry.scrollsFlag = 0x2;
            gCurrentRoomEntry.visualEffect = EFFECT_NONE;
            gCurrentRoomEntry.BG0Size = 0x0;
            gCurrentRoomEntry.BG3Size = 0x0;
        }
        else if (EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.firstSpritesetEvent))
        {
            gCurrentRoomEntry.pEnemyRoomData = entry.pFirstSpriteData;
            gSpriteset = entry.firstSpriteset;
            gSpritesetEntryUsed = 0x1;
        }
    }

    if (gSpritesetEntryUsed == 0x0)
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pDefaultSpriteData;
        gSpriteset = entry.defaultSpriteset;
    }

    gCurrentRoomEntry.scrollsFlag = 0x2;
    gCurrentRoomEntry.visualEffect = EFFECT_NONE;
    gCurrentRoomEntry.BG0Size = 0x0;
    gCurrentRoomEntry.BG3Size = 0x0;

    if (gSpritesetEntryUsed != 0x0 && gCurrentRoomEntry.BG0Prop == 0x44)
    {
        gWaitingSpacePiratesPosition.x = 0x8000;
        gWaitingSpacePiratesPosition.y = 0x8000;
    }

    gCurrentRoomEntry.BG3FromBottomFlag = 0x0;
    if (gCurrentRoomEntry.BG3Prop == 0x46)
    {
        gCurrentRoomEntry.BG3FromBottomFlag = 0x1;
        gBG0Movement.type = BG0MOVEMENT_WATER_CLOUDS;
    }*/
}

void RoomLoadBackgrounds(void)
{

}

void RoomRemoveNeverReformBlocksAndCollectedTanks(void)
{
	BlockRemoveNeverReformBlocks();
	BGClipRemoveCollectedTanks();
}

void RoomReset(void)
{

}

void RoomSetBackgroundScrolling(void)
{

}

void RoomSetInitialTilemap(u8 bgNumber)
{

}

u8 RoomRLEDecompress(u8 mode, u8* pSrc, u8* pDst)
{

}

void RoomUpdateGFXInfo(void)
{

}

void RoomUpdateAnimatedGraphicsAndPalettes(void)
{

}

void RoomUpdateHatchFlashingAnimation(void)
{

}

void RoomUpdate(void)
{

}

void RoomUpdateBackgroundsPosition(void)
{
    i32 yOffset;
    i32 xOffset;
    u16 x_pos_shift;
    u16 y_pos_shift;
    u16 new_bg3_x;
    u16 new_bg3_y;

    yOffset = ScreenShakeUpdateVertical();
    xOffset = ScreenShakeUpdateHorizontal();

    x_pos_shift = gBG1XPosition >> 0x2 & 0x1FF;
    y_pos_shift = gBG1YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[1].x = x_pos_shift + xOffset;
    gBackgroundPositions.bg[1].y = y_pos_shift + yOffset;
    x_pos_shift = gBG2XPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].x = x_pos_shift + xOffset;
    y_pos_shift = gBG2YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].y = y_pos_shift + yOffset;

    if ((gScreenShakeRelated & 0x100) != 0x0)
    {
        gBackgroundPositions.bg[0].x = (gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF;
        gBackgroundPositions.bg[0].y = (gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = ((gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF) + xOffset;
        gBackgroundPositions.bg[0].y = ((gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF) + xOffset;
    }

    new_bg3_x = (gBG3XPosition >> 0x2) + gBG3Movement.xOffset & 0x1FF;
    new_bg3_y = gBG3YPosition >> 0x2 & 0x1FF;

    if (gScreenShakeRelated & 0x800)
    {
        gBackgroundPositions.bg[3].x = new_bg3_x;
        gBackgroundPositions.bg[3].y = new_bg3_y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = new_bg3_x + (xOffset >> 0x1);
        gBackgroundPositions.bg[3].y = new_bg3_y + (yOffset >> 0x1);
    }
}

void RoomUpdateVerticalTilemap(i8 offset)
{

}

void RoomUpdateHorizontalTilemap(i8 offset)
{

}

void RoomCheckDMA3Ended(void)
{

}