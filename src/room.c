#include "room.h"
#include "gba.h"

#include "data/engine_pointers.h"
#include "data/empty_datatypes.h"
#include "data/common_pals.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/room.h"

#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/color_effects.h"
#include "structs/clipdata.h"
#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/scroll.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/screen_shake.h"
#include "structs/visual_effects.h"

/**
 * @brief 55f7c | 26c | Loads the current room
 * 
 */
void RoomLoad(void)
{
    ClipdataSetupCode();
    RoomReset();

    // Check for PSF
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        // No PSF, fully load room
        RoomLoadEntry();
        ScrollLoad();
        RoomSetBackgroundScrolling();
    }
    // Getting an item, init cutscene
    else if (gPauseScreenFlag == PAUSE_SCREEN_ITEM_ACQUISITION)
    {
        // Varia
        if (gCurrentItemBeingAcquired == 0xE)
        {
            gEquipment.suitMiscActivation &= ~SMF_VARIA_SUIT;
            SamusSetPose(SPOSE_FACING_THE_FOREGROUND);

            gSamusData.xPosition = 0x278;
            gSamusData.yPosition = 0x1FF;

            gInGameCutscene.stage = 0;
            gInGameCutscene.cutsceneNumber_Copy = 0x9;
            start_in_game_cutscene(9); // Undefined

            gDisablePause = TRUE;
            gSamusWeaponInfo.chargeCounter = 0;
            gSamusData.lastWallTouchedMidAir = TRUE;
        }
    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
    {
        gEquipment.suitMiscActivation &= ~SMF_GRAVITY_SUIT;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);

        gSamusData.xPosition = 0x620;
        gSamusData.yPosition = 0x7BF;

        gInGameCutscene.stage = 0;
        gInGameCutscene.cutsceneNumber_Copy = 0xA;
        start_in_game_cutscene(10); // Undefined

        gDisablePause = TRUE;
        gSamusData.lastWallTouchedMidAir = TRUE;
        gCurrentItemBeingAcquired = 0xF; // Gravity
        gSamusWeaponInfo.chargeCounter = 0;
    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_SUITLESS_ITEMS)
        PlayMusic(MUSIC_CHOZO_RUINS, 0x10);

    // Load graphics
    RoomLoadTileset();
    RoomLoadBackgrounds();
    RoomRemoveNeverReformBlocksAndCollectedTanks();
    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;
    TransparencySetRoomEffectsTransparency();
    load_first_room(); // Undefined

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && !gIsLoadingFile)
    {
        ScrollProcessGeneral();
        gBG1YPosition = gCamera.yPosition;
        gBG1XPosition = gCamera.xPosition;
        ScrollBG3Related();
        ScrollProcessGeneral();
    }

    // Load states, entities
    check_play_lightning_effect(); // Undefined
    RoomUpdateBackgroundsPosition();
    ConnectionLoadDoors();
    ConnectionCheckHatchLockEvents();
    RoomSetInitialTilemap(0x0);
    RoomSetInitialTilemap(0x1);
    RoomSetInitialTilemap(0x2);
    load_animated_graphics(); // Undefined
    reset_tanks_animation(); // Undefined
    set_bg_haze_effect(); // Undefined
    process_haze(); // Undefined
    MinimapCheckOnTransition();

    // Check using elevator
    if (!gIsLoadingFile && gGameModeSub3 != 0x0 && gPauseScreenFlag == PAUSE_SCREEN_NONE && gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        if (gSamusData.elevatorDirection == KEY_UP)
            gSamusData.yPosition += BLOCK_SIZE * 3;
        else
            gSamusData.yPosition -= BLOCK_SIZE * 3;
        gPreviousYPosition = gSamusData.yPosition;
    }

    sub_08060800(); // Undefined

    // Update rain sound effect
    if (gRainSoundEffect != RAIN_SOUND_NONE)
    {
        if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
        {
            if (gRainSoundEffect & RAIN_SOUND_PLAYING)
            {
                if (!(gRainSoundEffect & RAIN_SOUND_ENABLED))
                {
                    SoundFade(0x121, 0xA); // Rain
                    gRainSoundEffect &= ~RAIN_SOUND_PLAYING;
                }
            }
            else if (gRainSoundEffect & RAIN_SOUND_ENABLED)
            {
                SoundPlayNotAlreadyPlaying(0x121); // Rain
                gRainSoundEffect |= RAIN_SOUND_PLAYING;
            }
        }
        gRainSoundEffect &= ~RAIN_SOUND_ENABLED;
    }
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
    // https://decomp.me/scratch/TZ1cZ
    
    const struct Door* pDoor;
    i32 i;
    i32 yOffset;
    i32 xOffset;
    u16 count;
    u16* ptr;
    u16 temp;
    
    gColorFading.unk_3 = 0;
    gColorFading.timer = 0;
    gColorFading.status = 0;
    gColorFading.stage = 0;
    gColorFading.unk_6 = 0;

    if (gCurrentPowerBomb.animationState != 0)
        gScreenShakeX = sScreenShake_Empty;

    gCurrentPowerBomb = sPowerBomb_Empty;
    gWrittenToBLDCNT_Internal = 0;
    gScrollCounter = 0;
    gMusicTrackInfo.takingNormalTransition = FALSE;

    if (gGameModeSub3 == 0)
    {
        gMusicTrackInfo.currentRoomTrack = MUSIC_NONE;
        gMusicTrackInfo.unk = 0;
        gMusicTrackInfo.pauseScreenFlag = PAUSE_SCREEN_NONE;

        gCurrentClipdataAffectingAction = CAA_NONE;
        gAreaBeforeTransition = UCHAR_MAX;
        gDisableDoorAndTanks = FALSE;
        gCurrentCutscene = 0;

        gLastElevatorUsed = sLastElevatorUsed_Empty;
        gRainSoundEffect = RAIN_SOUND_NONE;

        if (!gIsLoadingFile && gCurrentDemo.status & 0xF0)
            init_demo_related(FALSE);
    
        gDoorPositionStart.x = 0;
        gDoorPositionStart.y = 0;
        gCurrentItemBeingAcquired = 0;

        save_most_recent_file_to_sram(); // Undefined
    }

    unk_5c158(); // Undefined

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    gDisableScrolling = FALSE;
    gSlowScrollingTimer = 0;
    gCollectingTank = FALSE;

    gScreenShakeRelated = 0;
    gDisablePause = FALSE;
    gDisableClipdataChangingTransparency = FALSE;
    
    gWrittenTo0x05000000 = 0;
    gScreenYOffset = 0;
    gScreenXOffset = 0;

    gDISPCNTBackup = 0;
    gInGameCutscene.cutsceneNumber = 0;
    gInGameCutscene.cutsceneNumber_Copy = 0;

    gEffectYPosition = 0;
    gHatchesState.unlocking = FALSE;
    gHatchesState.hatchesLockedWithTimer = 0;
    gHatchesState.unk = FALSE;
    gHatchesState.hatchesLockedWithEvent = 0;
    gHatchesState.unk2 = FALSE;
    gDoorUnlockTimer = 0;

    pDoor = &sAreaDoorsPointers[gCurrentArea][0];
    pDoor += gLastDoorUsed;
    gCurrentRoom = pDoor->sourceRoom;
    gLastDoorProperties = pDoor->type;
    gDisplayLocationText = (pDoor->type >> 6) & 1;

    gDoorPositionStart.x = pDoor->xStart;
    gDoorPositionStart.y = pDoor->yStart;

    gWaitingSpacePiratesPosition = sCoordsX_Empty;
    gLockScreen = sLockScreen_Empty;
    gBackgroundEffect = sBackgroundEffect_Empty;
    gWaterMovement = sWaterMovement_Empty;

    gEffectYPositionOffset = 0;
    gUnusedStruct_3005504 = sUnusedStruct_3005504_Empty;

    gBG0Movement = sBg0Movement_Empty;
    gBG2Movement.xOffset = 0;
    gBG2Movement.yOffset = 0;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
        gBrokenBlocks[i] = sBrokenBlock_Empty;

    for (i = 0; i < MAX_AMOUNT_OF_BOMB_CHAINS; i++)
        gBombChains[i] = sBombChain_Empty;

    gActiveBombChainTypes = 0;
    gDisableAnimatedGraphicsTimer = 0;

    count = 64;
    while (count != 0)
    {
        ptr = &gMakeSolidBlocks[count];
        *--ptr = 0;
        count--;
    }

    gScreenShakeY = sScreenShake_Empty;
    gScreenShakeX = sScreenShake_Empty;
    gScreenShakeXOffset = 0;
    gScreenShakeYOffset = 0;

    if (gIsLoadingFile)
        return;

    gCamera.xPosition = 0;
    gCamera.yPosition = 0;
    gCamera.xVelocity = 0;
    gCamera.yVelocity = 0;

    xOffset = pDoor->xStart;
    yOffset = pDoor->yEnd + 1;
    gSamusData.xPosition = xOffset * BLOCK_SIZE + (pDoor->xExit + 8) * 4;
    gSamusData.yPosition = (yOffset) * BLOCK_SIZE + pDoor->yExit * 4 - 1;

    if (gCurrentDemo.status & 0xF0)
        init_demo_related(TRUE);

    gWaitingSpacePiratesPosition.x = gSamusData.xPosition;
    gWaitingSpacePiratesPosition.y = gSamusData.yPosition;

    if (pDoor->xExit > 0)
        gWaitingSpacePiratesPosition.x -= HALF_BLOCK_SIZE;
    else if (pDoor->xExit < 0)
        gWaitingSpacePiratesPosition.x += HALF_BLOCK_SIZE;
    
    if (gSamusDoorPositionOffset != 0)
    {
        if (gSamusDoorPositionOffset < 0)
            gSamusDoorPositionOffset = 0;
        else
        {
            yOffset = -gSamusPhysics.drawDistanceTopOffset;
            temp = (u16)yOffset;
            if (temp + gSamusDoorPositionOffset > UCHAR_MAX)
                gSamusDoorPositionOffset = UCHAR_MAX - temp;
        }

        gSamusData.yPosition -= gSamusDoorPositionOffset;
        gSamusDoorPositionOffset = 0;
    }

    if (gSamusData.standingStatus == STANDING_ENEMY)
        gSamusData.standingStatus = STANDING_MIDAIR;

    gBG1XPosition = 0;
    gBG1YPosition = 0;
    gBG0XPosition = 0;
    gBG0YPosition = 0;
}

/**
 * @brief 56ac8 | 60 | Sets the automatic background scrolling (BG0 and BG3)
 * 
 */
void RoomSetBackgroundScrolling(void)
{
    gBG3Movement = sBg3Movement_Empty;

    switch (gCurrentRoomEntry.BG3Scrolling)
    {
        case 0x7:
        case 0x8:
        case 0xA:
            gBG3Movement.direction = TRUE;
    }

    if (gCurrentRoomEntry.visualEffect == EFFECT_WATER)
        gBG0Movement.type = BG0_MOVEMENT_WATER_CLOUDS;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD_KNOCKBACK)
        gBG0Movement.type = BG0_MOVEMENT_SNOWFLAKES;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD)
        gBG0Movement.type = BG0_MOVEMENT_SNOWFLAKES;

    gInGameCutscene.cutsceneNumber_Copy = 0;
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

/**
 * @brief 56e74 | 80 | Checks if the animated graphics, palette and effects should be updated
 * 
 */
void RoomUpdateAnimatedGraphicsAndPalettes(void)
{
    u8 dontUpdateBgEffect;
    u8 dontUpdateGraphics;

    dontUpdateBgEffect = FALSE;
    dontUpdateGraphics = FALSE;

    if (gGameModeSub1 == SUB_GAME_MODE_DOOR_TRANSITION || gGameModeSub1 == SUB_GAME_MODE_LOADING_ROOM)
        dontUpdateBgEffect = TRUE;
    else if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
    {
        dontUpdateBgEffect = TRUE;
        dontUpdateGraphics = TRUE;
    }

    if (gPreventMovementTimer != 0)
        dontUpdateGraphics = TRUE;

    if (gDisableAnimatedGraphicsTimer != 0)
    {
        gDisableAnimatedGraphicsTimer--;
        dontUpdateBgEffect = TRUE;
        dontUpdateGraphics = TRUE;
    }

    if (!dontUpdateBgEffect && gBackgroundEffect.type != 0 && gCurrentPowerBomb.animationState == 0)
        check_apply_background_effect_color(); // Undefined

    if (!dontUpdateGraphics)
    {
        update_animated_graphics(); // Undefined
        update_tanks_animation(); // Undefined
        update_animated_palette(); // Undefined
        RoomUpdateHatchFlashingAnimation();
    }
}

/**
 * @brief 56ef4 | dc | Updates the hatches flashing animation
 * 
 */
void RoomUpdateHatchFlashingAnimation(void)
{
    const u16* pPalette;
    
    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    // Get palette pointer
    if (gUseMotherShipDoors)
        pPalette = sHatchFlashingMotherShipPAL;
    else
        pPalette = sHatchFlashingPAL;

    // Update hatches that unlocked
    if (gHatchesState.unlocking)
    {
        gHatchFlashingAnimation.unlocking_delay++;
        if (gHatchFlashingAnimation.unlocking_delay > 7)
        {
            gHatchFlashingAnimation.unlocking_delay = 0;
            gHatchFlashingAnimation.unlocking_paletteRow++;

            if (gHatchFlashingAnimation.unlocking_paletteRow > 5)
                gHatchFlashingAnimation.unlocking_paletteRow = 0;

            DMATransfer(3, &pPalette[gHatchFlashingAnimation.unlocking_paletteRow * 16 + 6], PALRAM_BASE + 0x2C, 4, 0x10);
        }
    }

    // Left over code?
    if (gHatchesState.unk)
    {
        gHatchFlashingAnimation.navigation_delay++;
        if (gHatchFlashingAnimation.navigation_delay > 7)
        {
            gHatchFlashingAnimation.navigation_delay = 0;
            gHatchFlashingAnimation.navigation_paletteRow++;

            if (gHatchFlashingAnimation.navigation_paletteRow > 5)
                gHatchFlashingAnimation.navigation_paletteRow = 0;

            dma_set(3, &pPalette[gHatchFlashingAnimation.navigation_paletteRow * 16 + 6], PALRAM_BASE + 0x4C, DMA_ENABLE << 16 | 2);
        }
    }
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
    // https://decomp.me/scratch/wGbln

    u16 properties;
    u16 yPosition;
    u16 xPosition;
    i32 i;
    u16* pTilemap;
    i32 width;
    u16 value;
    u16 unk;
    u32* dst;
    i32 posOffset;
    u32 tilemapOffset;

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            properties = gCurrentRoomEntry.BG0Prop;
            yPosition = gBG0YPosition / BLOCK_SIZE;
            xPosition = gBG0XPosition / BLOCK_SIZE;
        }
        else if (i == 1)
        {
            properties = gCurrentRoomEntry.BG1Prop;
            yPosition = gBG1YPosition / BLOCK_SIZE;
            xPosition = gBG1XPosition / BLOCK_SIZE;
        }
        else
        {
            properties = gCurrentRoomEntry.BG2Prop;
            yPosition = gBG2YPosition / BLOCK_SIZE;
            xPosition = gBG2XPosition / BLOCK_SIZE;
        }

        if (!(properties & BG_PROP_RLE_COMPRESSED))
            continue;

        posOffset = yPosition + offset;
        if (posOffset < 0)
            continue;

        if (posOffset > gBGPointersAndDimensions.backgrounds[i].height)
            continue;
            
        yPosition = posOffset;

        posOffset = xPosition - 2;
        if (posOffset < 0)
            posOffset = 0;

        xPosition = posOffset;

        width = 0x13;
        if (gBGPointersAndDimensions.backgrounds[i].width < width)
            width = gBGPointersAndDimensions.backgrounds[i].width;

        tilemapOffset = yPosition * gBGPointersAndDimensions.backgrounds[i].width + xPosition;
        
        dst = VRAM_BASE + i * 4096;
        dst += (yPosition & 0xF) * 32;

        while (width != 0)
        {
            value = gBGPointersAndDimensions.backgrounds[i].pDecomp[tilemapOffset];

            pTilemap = &gTilemapAndClipPointers.pTilemap[value * 4];

            unk = xPosition & 0xF;
            if (xPosition & 0x10)
                unk += 0x200;

            dst[unk] = pTilemap[0] | pTilemap[1] << 0x10;
            dst[unk + 0x10] = pTilemap[2] | pTilemap[3] << 0x10;

            width--;
            xPosition++;
            tilemapOffset++;
        }
    }
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
