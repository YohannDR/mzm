#include "room.h"
#include "gba.h"

#include "data/engine_pointers.h"
#include "data/empty_datatypes.h"
#include "data/common_pals.h"
#include "data/clipdata_types.h"
#include "data/clipdata_types_tilemap.h"
#include "data/rooms_data.h"

#include "constants/audio.h"
#include "constants/haze.h"
#include "constants/connection.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/room.h"
#include "constants/in_game_cutscene.h"
#include "constants/power_bomb_explosion.h"
#include "constants/menus/pause_screen.h"

#include "structs/audio.h"
#include "structs/haze.h"
#include "structs/animated_graphics.h"
#include "structs/bg_clip.h"
#include "structs/in_game_cutscene.h"
#include "structs/color_effects.h"
#include "structs/clipdata.h"
#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/scroll.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/text.h"
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
        if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_VARIA)
        {
            gEquipment.suitMiscActivation &= ~SMF_VARIA_SUIT;
            SamusSetPose(SPOSE_FACING_THE_FOREGROUND);

            gSamusData.xPosition = BLOCK_SIZE * 10 - 8;
            gSamusData.yPosition = BLOCK_SIZE * 8 - 1;

            gInGameCutscene.stage = 0;
            gInGameCutscene.queuedCutscene = IGC_GETTING_VARIA;
            InGameCutsceneStart(IGC_GETTING_VARIA);

            gDisablePause = TRUE;
            gSamusWeaponInfo.chargeCounter = 0;
            gSamusData.lastWallTouchedMidAir = TRUE;
        }
    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
    {
        gEquipment.suitMiscActivation &= ~SMF_GRAVITY_SUIT;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);

        gSamusData.xPosition = BLOCK_SIZE * 24 + HALF_BLOCK_SIZE;
        gSamusData.yPosition = BLOCK_SIZE * 31 - 1;

        gInGameCutscene.stage = 0;
        gInGameCutscene.queuedCutscene = IGC_GETTING_FULLY_POWERED;
        InGameCutsceneStart(IGC_GETTING_FULLY_POWERED);

        gDisablePause = TRUE;
        gSamusData.lastWallTouchedMidAir = TRUE;
        gCurrentItemBeingAcquired = ITEM_ACQUISITION_GRAVITY;
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
    InGameCutsceneCheckPlayOnTransition();

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && !gIsLoadingFile)
    {
        ScrollProcessGeneral();
        gBg1YPosition = gCamera.yPosition;
        gBg1XPosition = gCamera.xPosition;
        ScrollBg3Related();
        ScrollProcessGeneral();
    }

    // Load states, entities
    AnimatedGraphicsCheckPlayLightningEffect();
    RoomUpdateBackgroundsPosition();
    ConnectionLoadDoors();
    ConnectionCheckHatchLockEvents();
    RoomSetInitialTilemap(0x0);
    RoomSetInitialTilemap(0x1);
    RoomSetInitialTilemap(0x2);
    AnimatedGraphicsLoad();
    AnimatedGraphicsTanksAnimationReset();
    HazeSetBackgroundEffect();
    HazeProcess();
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

    InGameCutsceneCheckStartQueued();

    // Update rain sound effect
    if (gRainSoundEffect != RAIN_SOUND_NONE)
    {
        if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
        {
            if (gRainSoundEffect & RAIN_SOUND_PLAYING)
            {
                if (!(gRainSoundEffect & RAIN_SOUND_ENABLED))
                {
                    SoundFade(SOUND_RAIN, CONVERT_SECONDS(1.f / 6));
                    gRainSoundEffect &= ~RAIN_SOUND_PLAYING;
                }
            }
            else if (gRainSoundEffect & RAIN_SOUND_ENABLED)
            {
                SoundPlayNotAlreadyPlaying(SOUND_RAIN);
                gRainSoundEffect |= RAIN_SOUND_PLAYING;
            }
        }
        gRainSoundEffect &= ~RAIN_SOUND_ENABLED;
    }
}

/**
 * @brief 561e8 | 21c | Loads the tileset of the current room
 * 
 */
void RoomLoadTileset(void)
{
    struct TilesetEntry entry;
    u32 backgroundGfxSize;

    entry = sTilesetEntries[gCurrentRoomEntry.tileset];

    gTilemapAndClipPointers.pTilemap = gTilemap;
    gTilemapAndClipPointers.pClipCollisions = gClipdataCollisionTypes;
    gTilemapAndClipPointers.pClipBehaviors = gClipdataBehaviorTypes;

    DmaTransfer(3, entry.pTilemap + 2, gTilemap, sizeof(gTilemap) * 4, 0x10);

    if (gCurrentArea > AREA_DEBUG_1)
    {
        DmaTransfer(3, sClipdataCollisionTypes_Debug, gClipdataCollisionTypes, sizeof(gClipdataCollisionTypes), 0x10);
        DmaTransfer(3, sClipdataBehaviorTypes_Debug, gClipdataBehaviorTypes, sizeof(gClipdataBehaviorTypes), 0x10);
    }
    else
    {
        DmaTransfer(3, sClipdataCollisionTypes, gClipdataCollisionTypes, sizeof(gClipdataCollisionTypes), 0x10);
        DmaTransfer(3, sClipdataBehaviorTypes, gClipdataBehaviorTypes, sizeof(gClipdataBehaviorTypes), 0x10);
    }

    DmaTransfer(3, sCommonTilemap, gCommonTilemap, sizeof(gCommonTilemap) * 2, 0x10);
    DmaTransfer(3, sClipdataCollisionTypes_Tilemap, gClipdataCollisionTypes_Tilemap, sizeof(gClipdataCollisionTypes_Tilemap), 0x10);
    DmaTransfer(3, sClipdataBehaviorTypes_Tilemap, gClipdataBehaviorTypes_Tilemap, sizeof(gClipdataBehaviorTypes_Tilemap), 0x10);

    CallLZ77UncompVram(entry.pTileGraphics, VRAM_BASE + 0x5800);
    DmaTransfer(3, entry.pPalette + 0x10, PALRAM_BASE + 0x60, 0x1A0, 0x10);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    if (gUseMotherShipDoors == TRUE)
    {
        DmaTransfer(3, sCommonTilesMothershipGfx, VRAM_BASE + 0x4800, sizeof(sCommonTilesMothershipGfx), 0x10);
        DmaTransfer(3, sCommonTilesMotherShipPal, PALRAM_BASE + 2, 0x5E, 0x10);
    }
    else
    {
        DmaTransfer(3, sCommonTilesGfx, VRAM_BASE + 0x4800, sizeof(sCommonTilesGfx), 0x10);
        DmaTransfer(3, sCommonTilesPal, PALRAM_BASE + 2, 0x5E, 0x10);
    }

    gTilesetTransparentColor.transparentColor = *entry.pPalette;
    gTilesetTransparentColor.field_2 = 0;

    backgroundGfxSize = ((u8*)entry.pBackgroundGraphics)[2] << 8 | ((u8*)entry.pBackgroundGraphics)[1];
    CallLZ77UncompVram(entry.pBackgroundGraphics, VRAM_BASE + 0xfde0 - backgroundGfxSize);
    BitFill(3, 0, VRAM_BASE + 0xFFE0, 0x20, 0x20);

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    gCurrentRoomEntry.animatedTileset = gAnimatedGraphicsEntry.tileset = entry.animatedTileset;
    gCurrentRoomEntry.animatedPalette = gAnimatedGraphicsEntry.palette = entry.animatedPalette;

    if (gCurrentRoomEntry.Bg2Prop == BG_PROP_MOVING)
        BitFill(3, 0x40, VRAM_BASE + 0x2000, 0x1000, 0x10);
}

/**
 * 56404 | 168 | Load the current room entry
 * 
 */
void RoomLoadEntry(void)
{
    struct RoomEntryROM entry;

    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    gCurrentRoomEntry.tileset = entry.tileset;

    gCurrentRoomEntry.Bg0Prop = entry.Bg0Prop;
    gCurrentRoomEntry.Bg1Prop = entry.Bg1Prop;
    gCurrentRoomEntry.Bg2Prop = entry.Bg2Prop;
    gCurrentRoomEntry.Bg3Prop = entry.Bg3Prop;

    gCurrentRoomEntry.Bg3Scrolling = entry.Bg3Scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;

    gCurrentRoomEntry.mapX = entry.mapX;
    gCurrentRoomEntry.mapY = entry.mapY;

    gCurrentRoomEntry.visualEffect = entry.effect;
    gCurrentRoomEntry.musicTrack = entry.musicTrack;

    gCurrentRoomEntry.effectY = (entry.effectY != UCHAR_MAX) ? entry.effectY * 64 : USHORT_MAX;

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
    gCurrentRoomEntry.Bg0Size = 0;
    gCurrentRoomEntry.Bg3Size = 0;

    if (gSpritesetEntryUsed != 0 && gCurrentRoomEntry.Bg0Prop == 0x44)
    {
        gWaitingSpacePiratesPosition.x = 0x8000;
        gWaitingSpacePiratesPosition.y = 0x8000;
    }

    gCurrentRoomEntry.BG3FromBottomFlag = FALSE;

    if (gCurrentRoomEntry.Bg3Prop == BG_PROP_STARTS_FROM_BOTTOM)
    {
        gCurrentRoomEntry.BG3FromBottomFlag = TRUE;
        gBg0Movement.type = BG0_MOVEMENT_WATER_CLOUDS;
    }
}

/**
 * @brief 5656c | 158 | Loads the backgrounds of the current room
 * 
 */
void RoomLoadBackgrounds(void)
{
    struct RoomEntryROM entry;
    const u8* src;

    // Why
    entry = sAreaRoomEntryPointers[gCurrentArea][gCurrentRoom];

    // Load BG3, always LZ77
    gCurrentRoomEntry.Bg3Size = *entry.pBg3Data;
    src = entry.pBg3Data + 4;
    CallLZ77UncompWram(src, gDecompBg3Map);

    if (gPauseScreenFlag == 0)
    {
        if (gGameModeSub3 == 0 || gTourianEscapeCutsceneStage != 0)
            BitFill(3, 0x40, VRAM_BASE + 0x3000, 0x1000, 0x10);

        // Load BG0, either RLE or LZ77
        if (gCurrentRoomEntry.Bg0Prop & BG_PROP_RLE_COMPRESSED)
        {
            src = entry.pBg0Data;
            gBgPointersAndDimensions.backgrounds[0].pDecomp = gDecompBg0Map;
            gBgPointersAndDimensions.backgrounds[0].width = *src++;
            gBgPointersAndDimensions.backgrounds[0].height = *src++;
            RoomRleDecompress(TRUE, src, (u8*)gDecompBg0Map);
        }
        else if (gCurrentRoomEntry.Bg0Prop & BG_PROP_LZ77_COMPRESSED)
        {
            src = entry.pBg0Data;
            gCurrentRoomEntry.Bg0Size = *src;

            src += 4;
            CallLZ77UncompWram(src, gDecompBg0Map);
        }
        
        // Load clipdata, assume RLE
        src = entry.pClipData;
        gBgPointersAndDimensions.pClipDecomp = gDecompClipdataMap;
        gBgPointersAndDimensions.clipdataWidth = *src++;
        gBgPointersAndDimensions.clipdataHeight = *src++;
        RoomRleDecompress(TRUE, src, (u8*)gDecompClipdataMap);

        // Load BG1, assume RLE
        src = entry.pBg1Data;
        gBgPointersAndDimensions.backgrounds[1].pDecomp = gDecompBg1Map;
        gBgPointersAndDimensions.backgrounds[1].width = *src++;
        gBgPointersAndDimensions.backgrounds[1].height = *src++;
        RoomRleDecompress(TRUE, src, (u8*)gDecompBg1Map);

        // Load BG2, force RLE
        if (gCurrentRoomEntry.Bg2Prop & BG_PROP_RLE_COMPRESSED)
        {
            src = entry.pBg2Data;
            gBgPointersAndDimensions.backgrounds[2].pDecomp = gDecompBg2Map;
            gBgPointersAndDimensions.backgrounds[2].width = *src++;
            gBgPointersAndDimensions.backgrounds[2].height = *src++;

            RoomRleDecompress(TRUE, src, (u8*)gDecompBg2Map);
        }
    }
}

void RoomRemoveNeverReformBlocksAndCollectedTanks(void)
{
	BlockRemoveNeverReformBlocks();
	BgClipRemoveCollectedTanks();
}

/**
 * @brief 566d4 | 3f4 | Resets all the room related info during a transition
 * 
 */
void RoomReset(void)
{
    const struct Door* pDoor;
    s32 i;
    s32 yOffset;
    u16 xOffset;
    u16 count;
    u16* ptr;
    s32 temp;
    
    gColorFading.unk_3 = 0;
    gColorFading.timer = 0;
    gColorFading.status = 0;
    gColorFading.stage = 0;
    gColorFading.unk_6 = 0;

    if (gCurrentPowerBomb.animationState != PB_STATE_NONE)
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

        if (!gIsLoadingFile && gCurrentDemo.loading)
            unk_60cbc(FALSE);
    
        gDoorPositionStart.x = 0;
        gDoorPositionStart.y = 0;
        gCurrentItemBeingAcquired = 0;

        SramWrite_MostRecentSaveFile();
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
    
    gBackdropColor = 0;
    gScreenYOffset = 0;
    gScreenXOffset = 0;

    gDISPCNTBackup = 0;
    gInGameCutscene.cutsceneNumber = 0;
    gInGameCutscene.queuedCutscene = 0;

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

    gBg0Movement = sBg0Movement_Empty;
    gBg2Movement.xOffset = 0;
    gBg2Movement.yOffset = 0;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
        gBrokenBlocks[i] = sBrokenBlock_Empty;

    for (i = 0; i < MAX_AMOUNT_OF_BOMB_CHAINS; i++)
        gBombChains[i] = sBombChain_Empty;

    gActiveBombChainTypes = 0;
    gDisableAnimatedGraphicsTimer = 0;

    ptr = EWRAM_BASE + 0x27780;
    for (xOffset = 64; xOffset != 0; xOffset--)
    {
        ptr[xOffset - 1] = 0;
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
    gSamusData.yPosition = yOffset * BLOCK_SIZE + pDoor->yExit * 4 - 1;

    if (gCurrentDemo.loading)
        unk_60cbc(TRUE);

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
            temp = gSamusPhysics.drawDistanceTop;
            yOffset = (u16)-temp;
            temp = (u16)yOffset;
            if (temp + gSamusDoorPositionOffset > UCHAR_MAX)
                gSamusDoorPositionOffset = UCHAR_MAX - yOffset;
        }

        gSamusData.yPosition -= gSamusDoorPositionOffset;
        gSamusDoorPositionOffset = 0;
    }

    if (gSamusData.standingStatus == STANDING_ENEMY)
        gSamusData.standingStatus = STANDING_MIDAIR;

    gBg1YPosition = 0;
    gBg1XPosition = 0;
    gBg0XPosition = 0;
    gBg0YPosition = 0;
}

/**
 * @brief 56ac8 | 60 | Sets the automatic background scrolling (BG0 and BG3)
 * 
 */
void RoomSetBackgroundScrolling(void)
{
    gBg3Movement = sBg3Movement_Empty;

    switch (gCurrentRoomEntry.Bg3Scrolling)
    {
        case 7:
        case 8:
        case 10:
            gBg3Movement.active = TRUE;
    }

    if (gCurrentRoomEntry.visualEffect == EFFECT_WATER)
        gBg0Movement.type = BG0_MOVEMENT_WATER_CLOUDS;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD_KNOCKBACK)
        gBg0Movement.type = BG0_MOVEMENT_SNOWFLAKES;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_SNOWFLAKES_COLD)
        gBg0Movement.type = BG0_MOVEMENT_SNOWFLAKES;

    gInGameCutscene.queuedCutscene = 0;
}

/**
 * @brief 56b28 | 1f0 | Setups the initial tilemapfor the BG specified
 * 
 * @param bgNumber Background number
 */
void RoomSetInitialTilemap(u8 bgNumber)
{
    s32 properties;
    s32 yPosition;
    u16 xPosition;
    s32 i;
    s32 j;

    u16* pDecomp;
    u16 yPos;
    u16 xPos;

    u16 xSize;
    u16 ySize;

    s32 offset;
    u16 iWidth;

    u16 tmpY;
    u16 tmpX;

    u16* dst;
    u16* pTilemap;

    u32 tmpOffset;

    if (bgNumber == 0)
    {
        properties = gCurrentRoomEntry.Bg0Prop;
        do {
            yPosition = SUB_PIXEL_TO_BLOCK(gBg0YPosition);
            xPosition = SUB_PIXEL_TO_BLOCK(gBg0XPosition);
        } while (0);
    }
    else if (bgNumber == 1)
    {
        properties = gCurrentRoomEntry.Bg1Prop;
        yPosition = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
        xPosition = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    }
    else
    {
        properties = gCurrentRoomEntry.Bg2Prop;
        yPosition = SUB_PIXEL_TO_BLOCK(gBg2YPosition);
        xPosition = SUB_PIXEL_TO_BLOCK(gBg2XPosition);
    }

    if (properties & BG_PROP_RLE_COMPRESSED)
    {
        xSize = 0x15;

        offset = xPosition - 3;
        if (offset < 0)
            offset = 0;

        if (xSize > gBgPointersAndDimensions.backgrounds[bgNumber].width - offset)
            xSize = gBgPointersAndDimensions.backgrounds[bgNumber].width - offset;

        xPos = offset;

        ySize = 0x10;

        offset = yPosition - 3;
        if (offset < 0)
            offset = 0;

        if (ySize > gBgPointersAndDimensions.backgrounds[bgNumber].height - offset)
            ySize = gBgPointersAndDimensions.backgrounds[bgNumber].height - offset;

        pDecomp = &gBgPointersAndDimensions.backgrounds[bgNumber].pDecomp[xPos + gBgPointersAndDimensions.backgrounds[bgNumber].width * (u16)offset];
        yPos = offset;

        for (i = 0; i < ySize; i++, yPos++)
        {
            iWidth = i * gBgPointersAndDimensions.backgrounds[bgNumber].width;

            tmpX = xPos;
            for (yPosition = 0; yPosition < xSize; iWidth++, yPosition++, tmpX++)
            {
                dst = VRAM_BASE + bgNumber * 0x1000;

                tmpOffset = 0x800; // Needed to produce matching ASM.
                if (tmpX & 0x10)
                    dst = VRAM_BASE + tmpOffset + bgNumber * 0x1000;

                dst = &dst[(tmpX & 0xF) * 2 + (yPos & 0xF) * 64];

                offset = pDecomp[iWidth];
                offset *= 4;
                pTilemap = &gTilemapAndClipPointers.pTilemap[offset];

                dst[0] = *pTilemap++;
                dst[1] = *pTilemap++;
                dst[32] = *pTilemap++;
                dst[32 + 1] = *pTilemap++;
            }
        }
    }
    else
    {
        s32 *offsetPtr; // Needed to produce matching ASM.

        if (properties == 0)
        {
            BitFill(3, 0x40, VRAM_BASE + bgNumber * 0x1000, 0x1000, 16);
            return;
        }

        offsetPtr = &offset;
        if (properties & BG_PROP_LZ77_COMPRESSED && bgNumber == 0)
        {
            offset = 0x800;
            if (gCurrentRoomEntry.Bg0Size & 1)
                offset *= 2;

            if (gCurrentRoomEntry.Bg0Size & 2)
                offset *= 2;

            DmaTransfer(3, gDecompBg0Map, VRAM_BASE, offset, 16);
        }
    }
}

/**
 * @brief 56d18 | 110 | RLE decompression algorithm
 * 
 * @param isBG Is background
 * @param src Source address
 * @param dst Destination address
 * @return u32 Size
 */
u32 RoomRleDecompress(u8 isBG, const u8* src, u8* dst)
{
    u32 size;
    s32 length;
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
void RoomUpdateGfxInfo(void)
{
    if (gSamusData.pose != SPOSE_USING_AN_ELEVATOR)
        gDisableDoorAndTanks &= 0x7F;
    else
        gDisableDoorAndTanks |= 0x80;

    if (gMonochromeBgFading != 0)
        ColorFadingApplyMonochrome();
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

    if (!dontUpdateBgEffect && gBackgroundEffect.type != 0 && gCurrentPowerBomb.animationState == PB_STATE_NONE)
        BackgroundEffectUpdate();

    if (!dontUpdateGraphics)
    {
        AnimatedGraphicsUpdate();
        AnimatedGraphicsTanksAnimationUpdate();
        AnimatedPaletteUpdate();
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
        pPalette = sHatchFlashingMotherShipPal;
    else
        pPalette = sHatchFlashingPal;

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

            DmaTransfer(3, &pPalette[gHatchFlashingAnimation.unlocking_paletteRow * 16 + 6], PALRAM_BASE + 0x2C, 4, 0x10);
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

            DMA_SET(3, &pPalette[gHatchFlashingAnimation.navigation_paletteRow * 16 + 6], PALRAM_BASE + 0x4C, DMA_ENABLE << 16 | 2);
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
        BgClipCheckTouchingSpecialClipdata();

        // Check still in "playing" mode
        if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
        {
            BlockUpdateBrokenBlocks();
            BlockProcessBombChains();
            InGameCutsceneProcess();
            ConnectionCheckUnlockDoors();
            ConnectionUpdateHatches();
        }
    }

    if (HazeProcess())
    {
        HazeProcess();
        if (gHazeInfo.enabled)
            gHazeInfo.active = TRUE;
    }

    PowerBombExplosionProcess();
}

/**
 * @brief 570ac | 128 | Updates the positions of the backgrounds
 * 
 */
void RoomUpdateBackgroundsPosition(void)
{
    s32 yOffset;
    s32 xOffset;
    u16 xPosition;
    u16 yPosition;
    u16 bg3X;
    u16 bg3Y;

    yOffset = ScreenShakeUpdateVertical();
    xOffset = ScreenShakeUpdateHorizontal();

    xPosition = gBg1XPosition >> 0x2 & 0x1FF;
    yPosition = gBg1YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[1].x = xPosition + xOffset;
    gBackgroundPositions.bg[1].y = yPosition + yOffset;
    xPosition = gBg2XPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].x = xPosition + xOffset;
    yPosition = gBg2YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].y = yPosition + yOffset;

    if (gScreenShakeRelated & 0x100)
    {
        gBackgroundPositions.bg[0].x = (gBg0XPosition >> 0x2) + gBg0Movement.xOffset & 0x1FF;
        gBackgroundPositions.bg[0].y = (gBg0YPosition >> 0x2) + gBg0Movement.yOffset & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = ((gBg0XPosition >> 0x2) + gBg0Movement.xOffset & 0x1FF) + xOffset;
        gBackgroundPositions.bg[0].y = ((gBg0YPosition >> 0x2) + gBg0Movement.yOffset & 0x1FF) + yOffset;
    }

    bg3X = (gBg3XPosition >> 0x2) + gBg3Movement.xOffset & 0x1FF;
    bg3Y = gBg3YPosition >> 0x2 & 0x1FF;

    if (gScreenShakeRelated & 0x800)
    {
        gBackgroundPositions.bg[3].x = bg3X;
        gBackgroundPositions.bg[3].y = bg3Y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = bg3X + (xOffset >> 0x1);
        gBackgroundPositions.bg[3].y = bg3Y + (yOffset >> 0x1);
    }
}

/**
 * @brief 571d4 | 124 | Updates the vertical tilemap of the room
 * 
 * @param offset Movement offset
 */
void RoomUpdateVerticalTilemap(s32 offset)
{
    s32 properties;
    u16 yPosition;
    u16 xPosition;
    s32 i;
    u16* pTilemap;
    u32 unk;
    u32* dst;
    u32 tilemapOffset;
    s32 size;

    s32 offset_ = (s8)offset;

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            properties = gCurrentRoomEntry.Bg0Prop;
            yPosition = gBg0YPosition / BLOCK_SIZE;
            xPosition = gBg0XPosition / BLOCK_SIZE;
        }
        else if (i == 1)
        {
            properties = gCurrentRoomEntry.Bg1Prop;
            yPosition = gBg1YPosition / BLOCK_SIZE;
            xPosition = gBg1XPosition / BLOCK_SIZE;
        }
        else
        {
            properties = gCurrentRoomEntry.Bg2Prop;
            yPosition = gBg2YPosition / BLOCK_SIZE;
            xPosition = gBg2XPosition / BLOCK_SIZE;
        }

        if (!(properties & BG_PROP_RLE_COMPRESSED))
            continue;

        properties = yPosition + offset_;
        if (properties < 0)
            continue;

        if (properties > gBgPointersAndDimensions.backgrounds[i].height)
            continue;
            
        yPosition = properties;

        properties = xPosition - 2;
        if (properties < 0)
            properties = 0;

        xPosition = properties;

        size = 0x13;
        if (gBgPointersAndDimensions.backgrounds[i].width < size)
            size = gBgPointersAndDimensions.backgrounds[i].width;

        tilemapOffset = yPosition * gBgPointersAndDimensions.backgrounds[i].width + xPosition;
        
        dst = VRAM_BASE + i * 4096;
        dst += (yPosition & 0xF) * 32;

        for (properties = 0; properties < size; properties++, xPosition++, tilemapOffset++)
        {
            pTilemap = &gTilemapAndClipPointers.pTilemap[gBgPointersAndDimensions.backgrounds[i].pDecomp[tilemapOffset] * 4];

            unk = xPosition & 0xF;
            if (xPosition & 0x10)
                unk += 0x200;

            dst[unk] = pTilemap[0] | pTilemap[1] << 0x10;
            dst[unk + 0x10] = pTilemap[2] | pTilemap[3] << 0x10;
        }
    }
}

/**
 * @brief 572f8 | 144 | Updates the horizontal tilemap of the room
 * 
 * @param offset Movement offset
 */
void RoomUpdateHorizontalTilemap(s32 offset)
{
    s32 properties;
    u16 yPosition;
    u16 xPosition;
    s32 i;
    u16* pTilemap;
    u32 unk;
    u32* dst;
    u32 tilemapOffset;
    s32 size;

    s32 offset_ = (s8)offset;

    for (i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            properties = gCurrentRoomEntry.Bg0Prop;
            yPosition = gBg0YPosition / BLOCK_SIZE;
            xPosition = gBg0XPosition / BLOCK_SIZE;
        }
        else if (i == 1)
        {
            properties = gCurrentRoomEntry.Bg1Prop;
            yPosition = gBg1YPosition / BLOCK_SIZE;
            xPosition = gBg1XPosition / BLOCK_SIZE;
        }
        else
        {
            properties = gCurrentRoomEntry.Bg2Prop;
            yPosition = gBg2YPosition / BLOCK_SIZE;
            xPosition = gBg2XPosition / BLOCK_SIZE;
        }

        if (!(properties & BG_PROP_RLE_COMPRESSED))
            continue;

        properties = xPosition + offset_;
        if (properties < 0)
            continue;

        if (properties > gBgPointersAndDimensions.backgrounds[i].width)
            continue;
            
        xPosition = properties;

        properties = yPosition - 2;
        if (properties < 0)
            properties = 0;

        yPosition = properties;

        size = 0xE;
        if (gBgPointersAndDimensions.backgrounds[i].height < size)
            size = gBgPointersAndDimensions.backgrounds[i].height;

        tilemapOffset = gBgPointersAndDimensions.backgrounds[i].width * yPosition + xPosition;
        
        dst = VRAM_BASE + i * 4096;
        if (xPosition & 0x10)
            dst = VRAM_BASE + 0x800 + i * 4096;
        dst += (xPosition & 0xF);

        for (properties = 0; properties < size; properties++)
        {
            pTilemap = &gTilemapAndClipPointers.pTilemap[gBgPointersAndDimensions.backgrounds[i].pDecomp[tilemapOffset] * 4];

            unk = (yPosition & 0xF) * 32;

            dst[unk] = pTilemap[0] | pTilemap[1] << 0x10;
            dst[unk + 0x10] = pTilemap[2] | pTilemap[3] << 0x10;

            tilemapOffset += gBgPointersAndDimensions.backgrounds[i].width;
            yPosition++;
        }
    }
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
