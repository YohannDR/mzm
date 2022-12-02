#include "room.h"
#include "gba.h"

#include "data/pointers.h"

#include "constants/samus.h"
#include "constants/room.h"
#include "constants/game_state.h"

#include "structs/game_state.h"
#include "structs/color_effects.h"
#include "structs/bg_clip.h"
#include "structs/scroll.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"
#include "structs/visual_effects.h"


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
        MusicPlay(MUSIC_CHOZO_RUINS, 0x10);

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
        gBG1YPosition = gCamera.yPosition;
        gBG1XPosition = gCamera.xPosition;
        ScrollBG3Related();
        ScrollProcessGeneral();
    }

    check_play_lightning_effect(); // Undefined
    RoomUpdateBackgroundsPosition();
    ConnectionLoadDoors();
    ConnectionCheckHatchLockEvents();
    RoomSetInitialTilemap(0x0);
    RoomSetInitialTilemap(0x1);
    RoomSetInitialTilemap(0x2);
    load_animated_graphics(); // Undefined
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
    // https://decomp.me/scratch/Hh7MS

    struct RoomEntryROM entry;

    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    gCurrentRoomEntry.tileset = entry.tileset;

    gCurrentRoomEntry.BG0Prop = entry.BG0Prop;
    gCurrentRoomEntry.BG1Prop = entry.BG1Prop;
    gCurrentRoomEntry.BG2Prop = entry.BG2Prop;
    gCurrentRoomEntry.BG3Prop = entry.BG3Prop;

    gCurrentRoomEntry.BG3Scrolling = entry.BG3Scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;

    gCurrentRoomEntry.mapX = entry.mapX;
    gCurrentRoomEntry.mapY = entry.mapY;

    gCurrentRoomEntry.visualEffect = entry.effect;
    gCurrentRoomEntry.musicTrack = entry.musicTrack;

    if (entry.effectY != UCHAR_MAX)
        gCurrentRoomEntry.effectY = entry.effectY * 64;
    else
        gCurrentRoomEntry.effectY = USHORT_MAX;

    gSpritesetEntryUsed = 0;
    gCurrentRoomEntry.firstSpritesetEvent = entry.firstSpritesetEvent;
    gCurrentRoomEntry.secondSpritesetEvent = entry.secondSpritesetEvent;

    if (gCurrentRoomEntry.secondSpritesetEvent != EVENT_NONE && EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.secondSpritesetEvent))
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pSecondSpriteData;
        gSpriteset = entry.secondSpriteset;
        gSpritesetEntryUsed = 2;
    }

    if (gCurrentRoomEntry.firstSpritesetEvent != EVENT_NONE && gSpritesetEntryUsed == 0
        && EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.firstSpritesetEvent))
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pFirstSpriteData;
        gSpriteset = entry.firstSpriteset;
        gSpritesetEntryUsed = 1;
    }

    if (gSpritesetEntryUsed == 0)
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pDefaultSpriteData;
        gSpriteset = entry.defaultSpriteset;
    }

    gCurrentRoomEntry.scrollsFlag = ROOM_SCROLLS_FLAG_NO_SCROLLS;
    gCurrentRoomEntry.damageEffect = EFFECT_NONE;
    gCurrentRoomEntry.BG0Size = 0;
    gCurrentRoomEntry.BG3Size = 0;

    if (gSpritesetEntryUsed != 0 && gCurrentRoomEntry.BG0Prop == 0x44)
    {
        gWaitingSpacePiratesPosition.x = 0x8000;
        gWaitingSpacePiratesPosition.y = 0x8000;
    }

    gCurrentRoomEntry.BG3FromBottomFlag = FALSE;

    if (gCurrentRoomEntry.BG3Prop == BG_PROP_STARTS_FROM_BOTTOM)
    {
        gCurrentRoomEntry.BG3FromBottomFlag = TRUE;
        gBG0Movement.type = BG0_MOVEMENT_WATER_CLOUDS;
    }
}

/**
 * @brief 5656c | 158 | Loads the backgrounds of the current room
 * 
 */
void RoomLoadBackgrounds(void)
{
    struct RoomEntryROM entry;
    u8* src;

    // Why
    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    // Load BG3, always LZ77
    gCurrentRoomEntry.BG3Size = *entry.pBG3Data;
    src = entry.pBG3Data + 4;
    CallLZ77UncompVRAM(src, EWRAM_BASE + 0x7000);

    if (gPauseScreenFlag == 0)
    {
        if (gGameModeSub3 == 0 || gTourianEscapeCutsceneStage != 0)
            BitFill(3, 0x40, VRAM_BASE + 0x3000, 0x1000, 0x10);

        // Load BG0, either RLE or LZ77
        if (gCurrentRoomEntry.BG0Prop & BG_PROP_RLE_COMPRESSED)
        {
            src = entry.pBG0Data;
            gBGPointersAndDimensions.backgrounds[0].pDecomp = gDecompBG0Map;
            gBGPointersAndDimensions.backgrounds[0].width = *src++;
            gBGPointersAndDimensions.backgrounds[0].height = *src++;
            RoomRLEDecompress(TRUE, src, (u8*)gDecompBG0Map);
        }
        else if (gCurrentRoomEntry.BG0Prop & BG_PROP_LZ77_COMPRESSED)
        {
            src = entry.pBG0Data;
            gCurrentRoomEntry.BG0Size = *src;

            src += 4;
            CallLZ77UncompVRAM(src, gDecompBG0Map);
        }
        
        // Load clipdata, assume RLE
        src = entry.pClipData;
        gBGPointersAndDimensions.pClipDecomp = gDecompClipdataMap;
        gBGPointersAndDimensions.clipdataWidth = *src++;
        gBGPointersAndDimensions.clipdataHeight = *src++;
        RoomRLEDecompress(TRUE, src, (u8*)gDecompClipdataMap);

        // Load BG1, assume RLE
        src = entry.pBG1Data;
        gBGPointersAndDimensions.backgrounds[1].pDecomp = gDecompBG1Map;
        gBGPointersAndDimensions.backgrounds[1].width = *src++;
        gBGPointersAndDimensions.backgrounds[1].height = *src++;
        RoomRLEDecompress(TRUE, src, (u8*)gDecompBG1Map);

        // Load BG2, force RLE
        if (gCurrentRoomEntry.BG2Prop & BG_PROP_RLE_COMPRESSED)
        {
            src = entry.pBG2Data;
            gBGPointersAndDimensions.backgrounds[2].pDecomp = gDecompBG2Map;
            gBGPointersAndDimensions.backgrounds[2].width = *src++;
            gBGPointersAndDimensions.backgrounds[2].height = *src++;

            RoomRLEDecompress(TRUE, src, (u8*)gDecompBG2Map);
        }
    }
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

/**
 * @brief 56d18 | 110 | RLE decompression algorithm
 * 
 * @param isBG Is background
 * @param src Source address
 * @param dst Destination address
 * @return u32 Size
 */
u32 RoomRLEDecompress(u8 isBG, u8* src, u8* dst)
{
    u32 size;
    i32 length;
    u8* dest;
    u8 numBytes;
    u32 value;
    u32 sizeType;

    // get decompressed size of data
    size = 0;
    length = 0x3000;
    if (!isBG)
    {
        sizeType = *src;
        size = 0x800;
        if (sizeType != 0)
        {
            size = 0x1000;
            if (sizeType == 3)
                size = 0x2000;
        }
        
        src++;
        length = 0x2000;
    }

    BitFill(3, 0, dst, length, 0x10);
    
    // do 2 passes, one for low byte and one for high byte
    for (length = 0; length < 2; )
    {
        dest = dst;
        if (length != 0)
            dest++;

        numBytes = *src++;
        if (numBytes == 1)
        {
            // read 1 byte at a type
            value = *src++;
            length++;

            while (value)
            {
                if (value & 0x80)
                {
                    // compressed, copy next byte
                    value &= 0x7F;
                    if (*src)
                    {
                        while (value)
                        {
                            *dest = *src;
                            dest += 2;
                            value--;
                        }
                    }
                    else
                        dest += value * 2;

                    src++;  
                }
                else
                {
                    // uncompressed, read next bytes
                    while (value)
                    {
                        *dest = *src++;
                        dest += 2;
                        value--;
                    }
                }

                value = *src++;
            }
        }
        else
        {
            // read 2 bytes at a type
            value = *src++;
            value <<= 8;
            value |= *src++;
            length++;

            while (value)
            {
                if (value & 0x8000)
                {
                    // compressed, copy next byte
                    value &= 0x7FFF;
                    if (*src)
                    {
                        if (value)
                        {
                            while (value)
                            {
                                *dest = *src;
                                dest += 2;
                                value--;
                            }
                        }
                        else
                            dest += value * 2;
                    }
                    else
                        dest += value * 2;

                    src++;
                }
                else
                {
                    // uncompressed, read next bytes
                    while (value)
                    {
                        *dest = *src++;
                        dest += 2;
                        value--;
                    }
                }

                value = *src++;
                value <<= 8;
                value |= *src++;
            }
        }
    }

    return size;
}

/**
 * @brief 56e28 | 4c | Updates the graphics information about a room
 * 
 */
void RoomUpdateGFXInfo(void)
{
    if (gSamusData.pose != SPOSE_USING_AN_ELEVATOR)
        gDisableDoorAndTanks &= 0x7F;
    else
        gDisableDoorAndTanks |= 0x80;

    if (gMonochromeBGFading != 0)
        apply_background_fading(); // Undefined
    else
    {
        MinimapUpdate();
        TransparencyApplyNewEffects();
    }
}

void RoomUpdateAnimatedGraphicsAndPalettes(void)
{

}

void RoomUpdateHatchFlashingAnimation(void)
{

}

/**
 * @brief 56fd0 | dc | Updates the current room
 * 
 */
void RoomUpdate(void)
{
    if (!gDisableScrolling && gColorFading.stage == 0)
    {
        // Update tilemaps
        RoomUpdateBackgroundsPosition();
        gScrollCounter++;

        // Horizontal
        if (gScrollCounter & 1 || gCamera.xVelocity < -28 || gCamera.xVelocity > 28)
        {
            RoomUpdateHorizontalTilemap(16);
            RoomUpdateHorizontalTilemap(-2);
        }

        // Vertical
        if (!(gScrollCounter & 1) || gCamera.yVelocity < -28 || gCamera.yVelocity > 28)
        {
            RoomUpdateVerticalTilemap(11);
            RoomUpdateVerticalTilemap(-2);
        }
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        BGClipCheckTouchingSpecialClipdata();

        // Check still in "playing" mode
        if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
        {
            BlockUpdateBrokenBlocks();
            BlockProcessBombChains();
            process_in_game_cutscene(); // Undefined
            ConnectionCheckUnlockDoors();
            ConnectionUpdateHatches();
        }
    }

    if (process_haze())
    {
        process_haze();
        if (gHazeInfo.flag & 0x7F)
            gHazeInfo.flag |= 0x80;
    }

    PowerBombExplosionProcess();
}

void RoomUpdateBackgroundsPosition(void)
{
    i32 yOffset;
    i32 xOffset;
    u16 xPosition;
    u16 yPosition;
    u16 bg3X;
    u16 bbg3Y;

    yOffset = ScreenShakeUpdateVertical();
    xOffset = ScreenShakeUpdateHorizontal();

    xPosition = gBG1XPosition >> 0x2 & 0x1FF;
    yPosition = gBG1YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[1].x = xPosition + xOffset;
    gBackgroundPositions.bg[1].y = yPosition + yOffset;
    xPosition = gBG2XPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].x = xPosition + xOffset;
    yPosition = gBG2YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].y = yPosition + yOffset;

    if (gScreenShakeRelated & 0x100)
    {
        gBackgroundPositions.bg[0].x = (gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF;
        gBackgroundPositions.bg[0].y = (gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = ((gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF) + xOffset;
        gBackgroundPositions.bg[0].y = ((gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF) + xOffset;
    }

    bg3X = (gBG3XPosition >> 0x2) + gBG3Movement.xOffset & 0x1FF;
    bbg3Y = gBG3YPosition >> 0x2 & 0x1FF;

    if (gScreenShakeRelated & 0x800)
    {
        gBackgroundPositions.bg[3].x = bg3X;
        gBackgroundPositions.bg[3].y = bbg3Y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = bg3X + (xOffset >> 0x1);
        gBackgroundPositions.bg[3].y = bbg3Y + (yOffset >> 0x1);
    }
}

void RoomUpdateVerticalTilemap(i8 offset)
{

}

void RoomUpdateHorizontalTilemap(i8 offset)
{

}

/**
 * @brief 5743c | 20 | Checks if DMA 3 has ended
 * 
 */
void RoomCheckDMA3Ended(void)
{
    vu32* pDma;

    pDma = (vu32*)REG_DMA3;

    while (pDma[2] & (DMA_ENABLE << 16));
}
