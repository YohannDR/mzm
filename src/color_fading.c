#include "color_fading.h"
#include "gba.h"
#include "color_effects.h"
#include "sprites_AI/ruins_test.h"

#include "data/engine_pointers.h"
#include "data/color_fading_data.h"
#include "data/common_pals.h"

#include "constants/audio.h"
#include "constants/animated_graphics.h"
#include "constants/connection.h"
#include "constants/color_fading.h"
#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/haze.h"
#include "constants/game_state.h"
#include "constants/room.h"
#include "constants/samus.h"

#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/color_effects.h"
#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/haze.h"
#include "structs/save_file.h"
#include "structs/sprite.h"
#include "structs/visual_effects.h"
#include "structs/room.h"

/**
 * @brief 5bcb0 | a8 | Processes the current color fading effect, visually
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingUpdate(void)
{
    u8 colorType;
    s32 stage;
    s32 color;

    // Get color set
    if (gColorFading.useSecondColorSet)
        colorType = sColorFadingData[gColorFading.type].secondColorSet;
    else
        colorType = sColorFadingData[gColorFading.type].firstColorSet;

    // Get color array size
    color = sColorFadingColorInfo[colorType].size;

    // Get color stage
    if (gColorFading.fadeTimer == 0)
        stage = COLOR_FADING_STAGE_STARTED;
    else if (gColorFading.fadeTimer == color)
        stage = COLOR_FADING_STAGE_FINISHED;
    else if (gColorFading.fadeTimer > color)
        stage = COLOR_FADING_STAGE_AFTER_FINISHED;
    else
        stage = COLOR_FADING_STAGE_IN_PROGRESS;

    // Get color
    if (stage <= COLOR_FADING_STAGE_IN_PROGRESS)
        color = sColorFadingColorInfo[colorType].colorArray[gColorFading.fadeTimer];
    else
        color = 0;

    // Process color
    colorType = sColorFadingData[gColorFading.type].pFadeSubroutine;
    if (sColorFadingSubroutinePointers[colorType](stage, color))
    {
        gColorFading.fadeTimer = 0;
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bd58 | 70 | To document
 * 
 * @param stage Stage
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5bd58(u8 stage, u8 color)
{
    switch (stage)
    {
        case COLOR_FADING_STAGE_STARTED:
            if (!gColorFading.useSecondColorSet)
                gWrittenToBLDY_NonGameplay = 0;

        case COLOR_FADING_STAGE_IN_PROGRESS:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.fadeTimer++;
            break;

        case COLOR_FADING_STAGE_FINISHED:
            if (!gColorFading.useSecondColorSet)
            {
                unk_5b2c4();
                gColorFading.status = COLOR_FADING_STATUS_ON_BG | COLOR_FADING_STATUS_ON_OBJ;
            }
            gColorFading.fadeTimer++;

        case COLOR_FADING_STAGE_AFTER_FINISHED:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bdc8 | b4 | To document
 * 
 * @param stage Stage
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5bdc8(u8 stage, u8 color)
{
    switch (stage)
    {
        case COLOR_FADING_STAGE_STARTED:
            if (!gColorFading.useSecondColorSet)
                gWrittenToBLDY_NonGameplay = 0;

        case COLOR_FADING_STAGE_IN_PROGRESS:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.fadeTimer++;
            break;

        case COLOR_FADING_STAGE_FINISHED:
            if (gColorFading.useSecondColorSet)
            {
                if (sColorFadingData[gColorFading.type].isWhite)
                {
                    write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                }
                else
                {
                    write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                }

                write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);
            }
            else
            {
                unk_5b2c4();
                gColorFading.status = COLOR_FADING_STATUS_ON_BG | COLOR_FADING_STATUS_ON_OBJ;
            }
            gColorFading.fadeTimer++;

        case COLOR_FADING_STAGE_AFTER_FINISHED:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5be7c | 4c | To document
 * 
 * @param stage Stage
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5be7c(u8 stage, u8 color)
{
    switch (stage)
    {
        case COLOR_FADING_STAGE_STARTED:
        case COLOR_FADING_STAGE_IN_PROGRESS:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.fadeTimer++;
            break;

        case COLOR_FADING_STAGE_FINISHED:
            gColorFading.fadeTimer++;

        case COLOR_FADING_STAGE_AFTER_FINISHED:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bec8 | 4 | Empty fading subroutine
 * 
 * @param stage Stage
 * @param color Color
 * @return u8 bool, ended
 */
u8 ColorFadingSubroutine_Empty(u8 stage, u8 color)
{
    return TRUE;
}

/**
 * @brief 5becc | 108 | Transfers the faded palette during a transition
 * 
 */
void ColorFadingTransferPaletteOnTransition(void)
{
    u32 value;
    s32 i;
    s32 color;

    gColorFading.fadeTimer = 0;
    unk_5b24c();
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
        unk_5b304();

    if (sColorFadingData[gColorFading.type].isWhite)
        value = COLOR_WHITE;
    else
        value = COLOR_BLACK;
    color = value;

    if (sColorFadingData[gColorFading.type].bgColorMask | sColorFadingData[gColorFading.type].objColorMask)
    {
        // Each color mask is a bitfield of palette rows to apply color bitfill to
        for (i = 0; i < COLORS_IN_PAL / PAL_ROW; i++)
        {
            if ((sColorFadingData[gColorFading.type].bgColorMask >> i) & 1)
                BitFill(3, color, PALRAM_BASE + i * PAL_ROW_SIZE, PAL_ROW_SIZE, 16);

            if ((sColorFadingData[gColorFading.type].objColorMask >> i) & 1)
                BitFill(3, color, PALRAM_OBJ + i * PAL_ROW_SIZE, PAL_ROW_SIZE, 16);
        }
    }

    DmaTransfer(3, PALRAM_BASE, COLOR_DATA_BG_EWRAM, PAL_SIZE, 16);
    DmaTransfer(3, PALRAM_OBJ, COLOR_DATA_OBJ_EWRAM, PAL_SIZE, 16);
}

/**
 * @brief 5bfd4 | a0 | Starts either a color fade or a background effect for a cutscene
 * 
 * @param request Request
 */
void StartEffectForCutscene(u8 request)
{
    switch (request)
    {
        case EFFECT_CUTSCENE_ESCAPING_CHOZODIA:
            gDisableSoftreset = TRUE;
            gSramOperationStage = 0;
            unk_5b340();
            ColorFadingStart(COLOR_FADING_CHOZODIA_ESCAPE);
            gGameModeSub1 = 3;
            break;

        case EFFECT_CUTSCENE_ESCAPE_FAILED:
            unk_5b340();
            ColorFadingStart(COLOR_FADING_ESCAPE_FAILED);
            gGameModeSub1 = 3;
            break;

        case EFFECT_CUTSCENE_EXITING_ZEBES:
            BackgroundEffectStart(BACKGROUND_EFFECT_EXIT_ZEBES_FADE);
            break;

        case EFFECT_CUTSCENE_GETTING_FULLY_POWERED:
            unk_5b340();
            ColorFadingStart(COLOR_FADING_GETTING_FULLY_POWERED);
            gGameModeSub1 = 3;
            break;

        case EFFECT_CUTSCENE_RIDLEY_SPAWN:
            unk_5b340();
            ColorFadingStart(COLOR_FADING_RIDLEY_SPAWN);
            gGameModeSub1 = 3;
            break;

        case EFFECT_CUTSCENE_STATUE_OPENING:
            unk_5b340();
            ColorFadingStart(COLOR_FADING_STATUE_CUTSCENE);
            gGameModeSub1 = 3;
            break;

        case EFFECT_CUTSCENE_INTRO_TEXT:
            BackgroundEffectStart(BACKGROUND_EFFECT_INTRO_TEXT_FADE);
            break;

        case EFFECT_CUTSCENE_SAMUS_IN_BLUE_SHIP:
            unk_5b340();
            ColorFadingStart(COLOR_FADING_SAMUS_IN_BLUE_SHIP);
            gGameModeSub1 = 3;
            break;
    }
}

/**
 * @brief 5c074 | 18 | Starts a color fading
 * 
 * @param type Type
 */
void ColorFadingStart(u8 type)
{
    gColorFading.type = type;
    gColorFading.stage = 0;
    gColorFading.fadeTimer = 0;
    gColorFading.unk_3 = 0;
    gColorFading.status = 0;
    gColorFading.useSecondColorSet = FALSE;
    gColorFading.subroutineTimer = 0;
}

/**
 * @brief 5c08c | cc | Hides the screen during a load if necessary
 * 
 */
void ColorFadingHideScreenDuringLoad(void)
{
    if (gGameModeSub3 == 0 || gPauseScreenFlag != 0 || gCurrentCutscene != 0 || gTourianEscapeCutsceneStage != 0)
    {
        if (sColorFadingData[gColorFading.type].isWhite)
        {
            write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
        }
        else
        {
            write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
        }

        write16(REG_DISPCNT, 0);
    }
    else
    {
        if (sColorFadingData[gColorFading.type].isWhite)
        {
            write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
        }
        else
        {
            write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
        }

        write16(REG_BG3CNT, (BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT) | (6 << BGCNT_SCREEN_BASE_BLOCK_SHIFT) | (1 << BGCNT_CHAR_BASE_BLOCK_SHIFT));
        write16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    }
}

/**
 * @brief 5c158 | 38 | Sets BG3 position to BG3 or BG4
 * 
 */
void ColorFadingSetBg3Position(void)
{
    if (sColorFadingData[gColorFading.type].pFadeSubroutine == COLOR_FADING_SUBROUTINE_1)
        gWhichBGPositionIsWrittenToBG3OFS = 4;
    else
        gWhichBGPositionIsWrittenToBG3OFS = 3;
}

/**
 * @brief 5c190 | 90 | Starts a default fade
 * 
 */
void ColorFadingStartDefault(void)
{
    gBackgroundPositions.doorTransition.y = gBackgroundPositions.bg[3].y;
    gBackgroundPositions.doorTransition.x = gBackgroundPositions.bg[3].x;

    DmaTransfer(3, gDecompBg3Map, VRAM_BASE + 0x3000, sizeof(gDecompBg3Map), 16);

    write16(REG_BG0CNT, gIoRegistersBackup.unk_12);
    write16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

    gDisableDrawingSprites = FALSE;

    if (gHazeInfo.enabled)
        gHazeInfo.active = TRUE;

    TransparencyUpdateBldcnt(2, gIoRegistersBackup.Bldcnt_NonGameplay);
    write16(REG_DISPCNT, gIoRegistersBackup.Dispcnt_NonGameplay);

    if (gDoorUnlockTimer == 1 * DELTA_TIME)
        ConnectionLockHatchesWithTimer();
}

/**
 * @brief 5c220 | 5c | Starts a door transition fade | FIXME verify this function 
 * 
 */
void ColorFadingStartDoorTransition(void)
{
    gBackgroundPositions.doorTransition.y = gBackgroundPositions.bg[3].y;
    gBackgroundPositions.doorTransition.x = gBackgroundPositions.bg[3].x;

    unk_5b340();
    BlockShiftNeverReformBlocks();
    ConnectionUpdateHatches();

    gWrittenToBLDALPHA_L = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
    gWrittenToBLDALPHA_H = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

    if (gMusicTrackInfo.takingNormalTransition)
    {
        unk_39c8();
        gMusicTrackInfo.takingNormalTransition = FALSE;
    }

    gColorFading.unk_3 = 0;
}

/**
 * @brief 5c27c | 70 | Handles fading for BG2 and BG3 gradient except on delay frames
 * 
 * @param delay Delay
 */
void ColorFadingGradients(u8 delay)
{
    u16 bldalpha;

    if (gFrameCounter8Bit & delay)
        return;

    bldalpha = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;
    if (sHazeData[gCurrentRoomEntry.visualEffect][3] == 2 && bldalpha != 0)
    {
        if (gWrittenToBLDALPHA_H != 0)
            gWrittenToBLDALPHA_H--;

        if (gWrittenToBLDALPHA_L != 0)
            gWrittenToBLDALPHA_L--;
        
        gWrittenToBLDALPHA = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;
    }
}

/**
 * @brief 5c2ec | c0 | Finishes a door fade and sets up door transition drawing
 * 
 */
void ColorFadingFinishDoorFade(void)
{
    unk_5d09c();
    SET_BACKDROP_COLOR(COLOR_BLACK);
    write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3));
    
    // Decompress and write the door transition tilemap to BG3
    RoomRleDecompress(FALSE, sDoorTransitionTilemap, gDecompBg3Map);
    DmaTransfer(3, gDecompBg3Map, VRAM_BASE + 0x3000, sizeof(gDecompBg3Map), 16);
    write16(REG_BG3CNT, (BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT) | (6 << BGCNT_SCREEN_BASE_BLOCK_SHIFT) | (1 << BGCNT_CHAR_BASE_BLOCK_SHIFT));

    gBackgroundPositions.bg[3].y = BLOCK_SIZE;
    gBackgroundPositions.doorTransition.y = BLOCK_SIZE;

    write16(REG_BG3VOFS, BLOCK_SIZE);
    write16(REG_DISPCNT, read16(REG_DISPCNT) | DCNT_BG3);

    if (gUseMotherShipDoors == TRUE)
    {
        DmaTransfer(3, sDoorTransitionMotherShipPal, (u16*)PALRAM_BASE + 1 * PAL_ROW, 2 * PAL_ROW_SIZE, 16);
    }
    else
    {
        DmaTransfer(3, sDoorTransitionPal, (u16*)PALRAM_BASE + 1 * PAL_ROW, 2 * PAL_ROW_SIZE, 16);
    }
}

/**
 * @brief 5c3ac | b4 | Handle door transition update and ending
 * 
 * @return u32 bool, finished
 */
u32 ColorFadingFinishDoorTransition(void)
{
    gColorFading.useSecondColorSet = FALSE;

    if (sColorFadingData[gColorFading.type].pUpdateSubroutine && sColorFadingData[gColorFading.type].pUpdateSubroutine())
    {
        switch (sColorFadingData[gColorFading.type].pFadeSubroutine)
        {
            case COLOR_FADING_SUBROUTINE_1:
                if (!gMusicTrackInfo.unk)
                    CheckPlayTransitionMusicTrack();
                break;

            case COLOR_FADING_SUBROUTINE_2:
                if (gMusicTrackInfo.pauseScreenFlag)
                    UpdateMusicAfterPause();
                break;
        }

        gMusicTrackInfo.unk = FALSE;
        gMusicTrackInfo.pauseScreenFlag = 0;

        ColorFadingStart(COLOR_FADING_CANCEL);
        write16(REG_BLDY, gIoRegistersBackup.BLDY_NonGameplay);
        TransparencyUpdateBldcnt(3, gIoRegistersBackup.Bldcnt_NonGameplay);
        gDisableDrawingSprites = FALSE;
        gColorFading.stage = 0;

        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c460 | 60 | Processes the current color fading effect
 * 
 * @return u32 bool, ended
 */
u32 ColorFadingProcess(void)
{
    gColorFading.useSecondColorSet = TRUE;

    if (gColorFading.unk_3 != UCHAR_MAX)
        gColorFading.unk_3++;

    if (sColorFadingData[gColorFading.type].pProcessSubroutine == NULL || !sColorFadingData[gColorFading.type].pProcessSubroutine())
        return FALSE;

    gNextOamSlot = 0;
    HudDraw();
    ParticleProcessAll();
    ResetFreeOam();

    gColorFading.stage = 0;
    return TRUE;
}

/**
 * @brief 5c4c0 | 268 | Door transition fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_DoorTransition(void)
{
    s32 bldalphaH;
    s32 bldalphaL;
    u8 bgProp;
    s32 offset;

    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
            {
                gDisableDrawingSprites = TRUE;
                gColorFading.stage++;
            }
            ColorFadingGradients(0);
            break;

        case 2:
            unk_5d09c();

            SET_BACKDROP_COLOR(COLOR_BLACK);

            if (gUseMotherShipDoors == TRUE)
            {
                DmaTransfer(3, sDoorTransitionMotherShipPal, PALRAM_BASE + 1 * PAL_ROW_SIZE, 2 * PAL_ROW_SIZE, 16);
            }
            else
            {
                DmaTransfer(3, sDoorTransitionPal, PALRAM_BASE + 1 * PAL_ROW_SIZE, 2 * PAL_ROW_SIZE, 16);
            }

            write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG2 | DCNT_BG3 | DCNT_WIN1));
            gSamusOnTopOfBackgrounds = FALSE;
            gColorFading.stage++;
            break;

        case 3:
            RoomRleDecompress(FALSE, sDoorTransitionTilemap, gDecompBg3Map);
            DmaTransfer(3, gDecompBg3Map, VRAM_BASE + 0x3000, sizeof(gDecompBg3Map), 16);
            
            if (gDoorPositionStart.x != 0)
                gBackgroundPositions.doorTransition.x = BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE;
            else
                gBackgroundPositions.doorTransition.x = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE;

            offset = BLOCK_TO_SUB_PIXEL(gDoorPositionStart.y) - gBg1YPosition;
            gBackgroundPositions.doorTransition.y = SUB_PIXEL_TO_PIXEL_(BLOCK_SIZE * 16 - offset);

            write16(REG_BG3HOFS, gBackgroundPositions.doorTransition.x);
            write16(REG_BG3VOFS, gBackgroundPositions.doorTransition.y);

            gWrittenToBLDCNT = BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

            bgProp = gCurrentRoomEntry.Bg0Prop; BG_PROP_CLOSE_UP;
            if (bgProp != 0x43 && bgProp != 0x44 && bgProp != BG_PROP_DARK_ROOM)
            {
                gWrittenToBLDALPHA_H = 16;
                gWrittenToBLDALPHA_L = 0;
            }
            gWrittenToBLDALPHA = C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L);

            gBg3CntDuringDoorTransition = CREATE_BGCNT(1, 6, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);
            gBg1CntDuringDoorTransition = read16(REG_BG1CNT) | BGCNT_HIGH_MID_PRIORITY;

            gWrittenToDISPCNT = read16(REG_DISPCNT);
            gWrittenToDISPCNT |= DCNT_BG3;
            gWrittenToDISPCNT &= ~DCNT_BG0;

            gColorFading.stage = 4;
            gColorFading.unk_3 = 0;
            break;

        case 4:
            if (gWrittenToBLDALPHA_H != 0 || gWrittenToBLDALPHA_L < BLDALPHA_MAX_VALUE)
            {
                bldalphaH = gWrittenToBLDALPHA_H - 2;
                if (bldalphaH < 0)
                    bldalphaH = 0;

                gWrittenToBLDALPHA_H = bldalphaH;

                bldalphaL = gWrittenToBLDALPHA_L + 2;
                if (bldalphaL > BLDALPHA_MAX_VALUE)
                    bldalphaL = BLDALPHA_MAX_VALUE;

                gWrittenToBLDALPHA_L = bldalphaL;

                gWrittenToBLDALPHA = C_16_2_8_(bldalphaH, bldalphaL);
            }
            else
            {
                write16(REG_DISPCNT, read16(REG_DISPCNT) & ~DCNT_BG1);
                gColorFading.unk_3 = 0;
                gColorFading.stage = 5;
            }
            break;

        case 5:
            gColorFading.stage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c728 | 54 | Default subroutine for a color fading
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_Default(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(0);
            break;

        case 2:
            ColorFadingFinishDoorFade();
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c77c | 98 | Escape failed fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_EscapeFailed(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            gPauseScreenFlag = 0;
            ColorFadingStartDoorTransition();
            FadeAllSounds(CONVERT_SECONDS(1.f));
            FadeMusic(CONVERT_SECONDS(1.f));
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
                gColorFading.stage++;
            break;

        case 2:
            unk_5d09c();
            SET_BACKDROP_COLOR(COLOR_WHITE);
            gColorFading.subroutineTimer = 0;
            gColorFading.stage++;
            break;

        case 3:
            gColorFading.subroutineTimer++;
            if (gColorFading.subroutineTimer > CONVERT_SECONDS(1.f))
            {
                gGameModeSub1 = 0;
                gMainGameMode = GM_GAMEOVER;
                return TRUE;
            }
    }

    return FALSE;
}

/**
 * @brief 5c814 | 98 | Before chozodia escape fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_ChozodiaEscape(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            SET_BACKDROP_COLOR(COLOR_BLACK);
            gWrittenToDISPCNT = read16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            gColorFading.stage++;
            break;

        case 1:
            unk_5d09c();
            gPauseScreenFlag = 0;
            gCurrentCutscene = 0;
            gSramOperationStage = 0;
            gCompletedGameFlagCopy = gGameCompletion.completedGame;
            gColorFading.stage++;
            break;

        case 2:
            if (SramProcessEndingSave())
                gColorFading.stage++;
            break;

        default:
            #ifdef DEBUG
            if (gDebugMode)
            {
                gDisableSoftreset = FALSE;
                gCompletedGameFlagCopy = 0x80;
            }
            #endif // DEBUG
            gGameModeSub1 = 0;
            gMainGameMode = GM_CHOZODIA_ESCAPE;
            break;
    }

    return FALSE;
}

/**
 * @brief 5c8ac | 78 | Before demo end fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_BeforeDemoEnding(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();

            // Set input ended flag
            if (gColorFading.type == COLOR_FADING_DEMO_ENDING_WITH_INPUT)
                gCurrentDemo.endedWithInput = TRUE;

            DemoEnd();
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(3);
            break;

        case 2:
            unk_5d09c();
            SET_BACKDROP_COLOR(COLOR_BLACK);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c924 | 78 | Before tourian escape fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_TourianEscape(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.subroutineTimer = 0;
            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            ColorFadingFinishDoorFade();
            gTourianEscapeCutsceneStage = 1;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c99c | bc | Before getting fully powered suit cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_GettingFullyPowered(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.unk_3 = 0;
            gColorFading.stage++;
            break;

        case 1:
            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.unk_3 = 0;
            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            ColorFadingFinishDoorFade();

            gCurrentCutscene = CUTSCENE_GETTING_FULLY_POWERED;
            ColorFadingStart(COLOR_FADING_CANCEL);

            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE;
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_VARIA_SUIT_GRABBED);

            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_VARIA_SUIT_OBTAINED))
            {
                EventFunction(EVENT_ACTION_SETTING, EVENT_VARIA_SUIT_OBTAINED);
                EventFunction(EVENT_ACTION_SETTING, EVENT_SKIPPED_VARIA_SUIT);
            }

            gEquipment.suitMisc |= SMF_VARIA_SUIT;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5ca58 | 80 | Before ridley spawn cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_BeforeRidleySpawn(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.unk_3 = 0;
            gColorFading.stage++;
            break;

        case 1:
            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.unk_3 = 0;
            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            ColorFadingFinishDoorFade();

            gCurrentCutscene = CUTSCENE_RIDLEY_SPAWNING;
            ColorFadingStart(COLOR_FADING_CANCEL);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cad8 | a0 | Before statue opening cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_StatueOpening(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (gCurrentArea == AREA_KRAID || gCurrentArea == AREA_RIDLEY)
                FadeCurrentInsertMusicQueueCurrent(CONVERT_SECONDS(1.f), MUSIC_STATUE_ROOM_OPENED, 0);

            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            ColorFadingFinishDoorFade();

            gCurrentCutscene = CUTSCENE_STATUE_OPENING;
            ColorFadingStart(COLOR_FADING_CANCEL);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cb78 | a4 | Before intro text cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_BeforeIntroText(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            gCurrentCutscene = CUTSCENE_INTRO_TEXT;

            ColorFadingFinishDoorFade();
            ColorFadingStart(COLOR_FADING_CANCEL);

            if (gDifficulty != DIFF_NORMAL)
            {
                if (gDifficulty == DIFF_HARD)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_HARD);
                else if (gDifficulty == DIFF_EASY)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_EASY);
                else
                {
                    // ?
                    gColorFading.stage++;
                    break;
                }
            }

            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cc1c | 78 | Before samus in blue ship cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_BeforeBlueShip(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            ColorFadingGradients(7);
            break;

        case 3:
            ColorFadingFinishDoorFade();

            gCurrentCutscene = CUTSCENE_SAMUS_IN_BLUE_SHIP;
            ColorFadingStart(COLOR_FADING_CANCEL);

            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cc94 | 5c | Before ship landing sequence fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingProcess_BeforeLandingShip(void)
{
    u8 ended;

    ended = FALSE;

    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDefault();
            gColorFading.subroutineTimer = 0;
            gColorFading.stage++;
            break;

        case 1:
            gColorFading.subroutineTimer++;

            if (gColorFading.subroutineTimer > CONVERT_SECONDS(1.f))
            {
                gColorFading.subroutineTimer = 0;
                gColorFading.stage++;
            }
            break;

        case 2:
            if (ColorFadingUpdate())
            {
                gColorFading.stage++;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 5ccf0 | 34 | Default behavior for a fade
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingUpdate_Default(void)
{
    u8 ended;

    ended = FALSE;

    if (gColorFading.stage == 0)
    {
        ColorFadingStartDefault();
        gColorFading.stage++;
    }
    else if (gColorFading.stage == 1)
    {
        if (ColorFadingUpdate())
            ended = TRUE;
    }

    return ended;
}

/**
 * @brief 5cd24 | 228 | Updates a door transition
 * 
 * @return u8 bool, ended
 */
u8 ColorFadingUpdate_DoorTransition(void)
{
    if (gColorFading.unk_3 != UCHAR_MAX)
        gColorFading.unk_3++;

    switch (gColorFading.stage)
    {
        case 0:
            if (gBackgroundPositions.doorTransition.x == BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE)
                gDoorPositionStart.x = BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE;
            else
                gDoorPositionStart.x = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE;

            gDoorPositionStart.y = BLOCK_SIZE * 4 - ((gDoorPositionStart.y * BLOCK_SIZE - gBg1YPosition) >> 2);

            if (gDoorUnlockTimer == 1 * DELTA_TIME)
                ConnectionLockHatchesWithTimer();

            gColorFading.stage++;
            break;

        case 1:
            if (gDoorPositionStart.y > gBackgroundPositions.doorTransition.y)
            {
                gBackgroundPositions.doorTransition.y += 3;
                if (gBackgroundPositions.doorTransition.y > gDoorPositionStart.y)
                    gBackgroundPositions.doorTransition.y = gDoorPositionStart.y;
            }
            else if (gDoorPositionStart.y < gBackgroundPositions.doorTransition.y)
            {
                gBackgroundPositions.doorTransition.y -= 3;
                if (gBackgroundPositions.doorTransition.y < gDoorPositionStart.y)
                    gBackgroundPositions.doorTransition.y = gDoorPositionStart.y;
            }
            else
            {
                gColorFading.unk_3 = 0;
                gColorFading.stage = 2;
            }
            break;

        case 2:
            if (gColorFading.unk_3 > 2)
            {
                gColorFading.unk_3 = 0;
                gColorFading.stage++;
            }
            break;

        case 3:
            if (gDoorPositionStart.x > gBackgroundPositions.doorTransition.x)
            {
                gBackgroundPositions.doorTransition.x += 6;
                if (gDoorPositionStart.x < gBackgroundPositions.doorTransition.x)
                    gBackgroundPositions.doorTransition.x = gDoorPositionStart.x;
            }
            else if (gDoorPositionStart.x < gBackgroundPositions.doorTransition.x)
            {
                gBackgroundPositions.doorTransition.x -= 6;
                if (gDoorPositionStart.x > gBackgroundPositions.doorTransition.x)
                    gBackgroundPositions.doorTransition.x = gDoorPositionStart.x;
            }
            else
            {
                write16(REG_DISPCNT, read16(REG_DISPCNT) | DCNT_BG1);
                write16(REG_BLDCNT, read16(REG_BLDCNT) & ~BLDCNT_BG1_FIRST_TARGET_PIXEL);
                write16(REG_DISPCNT, read16(REG_DISPCNT) & ~DCNT_BG3);

                DmaTransfer(3, gDecompBg3Map, BGCNT_TO_VRAM_TILE_BASE(6), sizeof(gDecompBg3Map), 16);

                write16(REG_BG0CNT, gIoRegistersBackup.unk_12);
                write16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

                gBackgroundPositions.doorTransition.y = gBackgroundPositions.bg[3].y;
                gBackgroundPositions.doorTransition.x = gBackgroundPositions.bg[3].x;

                if (gHazeInfo.enabled)
                    gHazeInfo.active = TRUE;

                TransparencyUpdateBldcnt(2, gIoRegistersBackup.Bldcnt_NonGameplay);
                write16(REG_DISPCNT, gIoRegistersBackup.Dispcnt_NonGameplay);

                gColorFading.unk_3 = 0;
                gDisableDrawingSprites = FALSE;
                gColorFading.stage = 5;
            }
            break;

        case 4:
            if (gColorFading.unk_3 != 0)
            {
                gColorFading.unk_3 = 0;
                gDisableDrawingSprites = FALSE;
                gColorFading.stage++;
            }
            break;

        case 5:
            if (ColorFadingUpdate())
                gColorFading.stage++;
            break;

        case 6:
            gColorFading.stage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cf4c | 94 | Applies the monochrome background fading
 * 
 */
void ColorFadingApplyMonochrome(void)
{
    if (gMonochromeBgFading == 0 || gMonochromeBgFading == MONOCHROME_FADING_ENDED)
        return;

    gColorFading.useSecondColorSet = TRUE;

    if (gMonochromeBgFading & MONOCHROME_FADING_ACTIVE)
    {
        if (ColorFadingUpdate())
        {
            write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3));
            gMonochromeBgFading = MONOCHROME_FADING_ENDED;
        }
    }
    else
    {
        if (gMonochromeBgFading == MONOCHROME_FADING_BLACK)
        {
            ColorFadingStart(COLOR_FADING_TO_BLACK);
            if (gCurrentHazeValue != 0)
            {
                gCurrentHazeValue = 0;
                unk_5d09c();
            }
        }
        else if (gMonochromeBgFading == MONOCHROME_FADING_WHITE)
        {
            ColorFadingStart(COLOR_FADING_TO_WHITE);
        }
        else
        {
            gMonochromeBgFading = 0;
        }

        unk_5b340();
        gMonochromeBgFading |= MONOCHROME_FADING_ACTIVE;
    }
}
