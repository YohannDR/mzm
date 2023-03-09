#include "color_fading.h"
#include "gba.h"
#include "color_effects.h"
#include "sprites_AI/ruins_test.h"

#include "data/engine_pointers.h"
#include "data/color_fading_data.h"
#include "data/common_pals.h"

#include "constants/audio.h"
#include "constants/haze.h"
#include "constants/animated_graphics.h"
#include "constants/connection.h"
#include "constants/color_fading.h"
#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/game_state.h"
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
    i32 stage;
    i32 color;

    if (gColorFading.unk_5)
        colorType = sColorFadingData[gColorFading.type].unk_10;
    else
        colorType = sColorFadingData[gColorFading.type].unk_8;

    color = sColorFadingColorInfo[colorType].size;
    if (gColorFading.timer == 0)
        stage = 0;
    else 
    {
        if (gColorFading.timer == color)
            stage = 2;
        else if (gColorFading.timer > color)
            stage = 3;
        else
            stage = 1;
    }
    
    if (stage < 2)
        color = sColorFadingColorInfo[colorType].colorArray[gColorFading.timer];
    else
        color = 0;

    colorType = sColorFadingData[gColorFading.type].unk_16;
    if (sColorFadingSubroutinePointers[colorType](stage, color))
    {
        gColorFading.timer = 0;
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bd58 | 70 | To document
 * 
 * @param param_1 To document
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5bd58(u8 param_1, u8 color)
{
    switch (param_1)
    {
        case 0:
            if (!gColorFading.unk_5)
                gWrittenToBLDY_NonGameplay = 0;

        case 1:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.timer++;
            break;

        case 2:
            if (!gColorFading.unk_5)
            {
                unk_5b2c4();
                gColorFading.status = (0x1 | 0x2);
            }
            gColorFading.timer++;

        case 3:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bdc8 | b4 | To document
 * 
 * @param param_1 To document
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5bdc8(u8 param_1, u8 color)
{
    switch (param_1)
    {
        case 0:
            if (!gColorFading.unk_5)
                gWrittenToBLDY_NonGameplay = 0;

        case 1:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.timer++;
            break;

        case 2:
            if (gColorFading.unk_5)
            {
                if (sColorFadingData[gColorFading.type].isWhite)
                {
                    write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                        BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                }
                else
                {
                    write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                }

                write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);
            }
            else
            {
                unk_5b2c4();
                gColorFading.status = (0x1 | 0x2);
            }
            gColorFading.timer++;

        case 3:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5be7c | 4c | To document
 * 
 * @param param_1 To document
 * @param color Color
 * @return u8 bool, ended
 */
u8 unk_5be7c(u8 param_1, u8 color)
{
    switch (param_1)
    {
        case 0:
        case 1:
            CallApplySpecialBackgroundFadingColor(color);
            gColorFading.timer++;
            break;

        case 2:
            gColorFading.timer++;

        case 3:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5bec8 | 4 | Empty fading subroutine
 * 
 * @param param_1 To document
 * @param color Color
 * @return u8 bool, ended
 */
u8 ColorFadingSubroutine_Empty(u8 param_1, u8 color)
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
    i32 i;
    i32 color;

    gColorFading.timer = 0;
    unk_5b24c();
    if (gPauseScreenFlag == 0)
        unk_5b304();

    if (sColorFadingData[gColorFading.type].isWhite)
        value = 0x7FFF;
    else
        value = 0;
    color = value;

    if (sColorFadingData[gColorFading.type].bgColorMask | sColorFadingData[gColorFading.type].objColorMask)
    {
        for (i = 0; i < 16; i++)
        {
            if ((sColorFadingData[gColorFading.type].bgColorMask >> i) & 1)
                BitFill(3, color, PALRAM_BASE + i * 32, 32, 16);

            if ((sColorFadingData[gColorFading.type].objColorMask >> i) & 1)
                BitFill(3, color, PALRAM_BASE + PALRAM_SIZE / 2 + i * 32, 32, 16);
        }
    }

    DMATransfer(3, PALRAM_BASE, EWRAM_BASE + 0x35000, PALRAM_SIZE / 2, 16);
    DMATransfer(3, PALRAM_BASE + PALRAM_SIZE / 2, EWRAM_BASE + 0x35200, PALRAM_SIZE / 2, 16);
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
    gColorFading.timer = 0;
    gColorFading.unk_3 = 0;
    gColorFading.status = 0;
    gColorFading.unk_5 = FALSE;
    gColorFading.unk_6 = 0;
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
            write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
        }
        else
        {
            write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
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
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
        }

        write16(REG_BG3CNT, 0x4604);
        write16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    }
}

/**
 * @brief 5c158 | 38 | To document
 * 
 */
void unk_5c158(void)
{
    if (sColorFadingData[gColorFading.type].unk_16 == 1)
        gWhichBGPositionIsWrittenToBG3OFS = 4;
    else
        gWhichBGPositionIsWrittenToBG3OFS = 3;
}

/**
 * @brief 5c190 | 90 | To document
 * 
 */
void unk_5c190(void)
{
    gBackgroundPositions.doorTransition.y = gBackgroundPositions.bg[3].y;
    gBackgroundPositions.doorTransition.x = gBackgroundPositions.bg[3].x;

    DMATransfer(3, EWRAM_BASE + 0x7000, VRAM_BASE + 0x3000, 0x1000, 16);

    write16(REG_BG0CNT, gIoRegistersBackup.unknown_12);
    write16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

    gDisableDrawingSprites = FALSE;

    if (gHazeInfo.enabled)
        gHazeInfo.active = TRUE;

    TransparencyUpdateBLDCNT(2, gIoRegistersBackup.BLDCNT_NonGameplay);
    write16(REG_DISPCNT, gIoRegistersBackup.DISPCNT_NonGameplay);

    if (gDoorUnlockTimer == 1)
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
 * @brief 5c27c | 70 | To document
 * 
 * @param delay Delay
 */
void unk_5c27c(u8 delay)
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
 * @brief 5c2ec | c0 | To document
 * 
 */
void unk_5c2ec(void)
{
    unk_5d09c();
    write16(PALRAM_BASE, 0);
    write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3));
    
    // FIXME RoomRLEDecompress(FALSE, sDoorTransitionTilemap, EWRAM_BASE + 0x7000);
    RoomRLEDecompress(FALSE, 0x8364f80, EWRAM_BASE + 0x7000);
    DMATransfer(3, EWRAM_BASE + 0x7000, VRAM_BASE + 0x3000, 0x1000, 16);
    write16(REG_BG3CNT, 0x4604);

    gBackgroundPositions.bg[3].y = BLOCK_SIZE;
    gBackgroundPositions.doorTransition.y = BLOCK_SIZE;

    write16(REG_BG3VOFS, BLOCK_SIZE);
    write16(REG_DISPCNT, read16(REG_DISPCNT) | DCNT_BG3);

    if (gUseMotherShipDoors == TRUE)
    {
        // FIXME DMATransfer(3, sDoorTransitionMotherShipPAL, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
        DMATransfer(3, 0x85e0040, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
    }
    else
    {
        // FIXME DMATransfer(3, sDoorTransitionPAL, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
        DMATransfer(3, 0x85dfe40, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
    }
}

/**
 * @brief 5c3ac | b4 `
 * 
 * @return u32 
 */
u32 unk_5c3ac(void)
{
    gColorFading.unk_5 = FALSE;

    if (sColorFadingData[gColorFading.type].unk_4 && sColorFadingData[gColorFading.type].unk_4())
    {
        switch (sColorFadingData[gColorFading.type].unk_16)
        {
            case 1:
                if (gMusicTrackInfo.unk == 0)
                    CheckPlayTransitionMusicTrack();
                break;

            case 2:
                if (gMusicTrackInfo.pauseScreenFlag)
                    update_music_after_unpause(); // Undefined
                break;
        }

        gMusicTrackInfo.unk = 0;
        gMusicTrackInfo.pauseScreenFlag = 0;

        ColorFadingStart(2);
        write16(REG_BLDY, gIoRegistersBackup.BLDY_NonGameplay);
        TransparencyUpdateBLDCNT(3, gIoRegistersBackup.BLDCNT_NonGameplay);
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
    gColorFading.unk_5 = TRUE;

    if (gColorFading.unk_3 != UCHAR_MAX)
        gColorFading.unk_3++;

    if (sColorFadingData[gColorFading.type].unk_C == NULL || !sColorFadingData[gColorFading.type].unk_C())
        return FALSE;

    gNextOamSlot = 0;
    HUDDraw();
    ParticleProcessAll();
    ResetFreeOAM();

    gColorFading.stage = 0;
    return TRUE;
}

/**
 * @brief 5c4c0 | 268 | Door transition fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_DoorTransition(void)
{
    i32 bldalphaH;
    i32 bldalphaL;
    u8 bgProp;

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
            unk_5c27c(0);
            break;

        case 2:
            unk_5d09c();
            write16(PALRAM_BASE, 0);

            if (gUseMotherShipDoors == TRUE)
            {
                // FIXME DMATransfer(3, sDoorTransitionMotherShipPAL, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
                DMATransfer(3, 0x85e0040, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
            }
            else
            {
                // FIXME DMATransfer(3, sDoorTransitionPAL, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
                DMATransfer(3, 0x85dfe40, PALRAM_BASE + 0x20, 16 * 2 * sizeof(u16), 16);
            }

            write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG2 | DCNT_BG3 | DCNT_WIN1));
            gSamusOnTopOfBackgrounds = FALSE;
            gColorFading.stage++;
            break;

        case 3:
            // FIXME RoomRLEDecompress(FALSE, sDoorTransitionTilemap, EWRAM_BASE + 0x7000);
            RoomRLEDecompress(FALSE, 0x8364f80, EWRAM_BASE + 0x7000);
            DMATransfer(3, EWRAM_BASE + 0x7000, VRAM_BASE + 0x3000, 0x1000, 16);
            
            if (gDoorPositionStart.x != 0)
                gBackgroundPositions.doorTransition.x = BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE;
            else
                gBackgroundPositions.doorTransition.x = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE;

            gBackgroundPositions.doorTransition.y = ((BLOCK_SIZE * 16 -
                (gDoorPositionStart.y * BLOCK_SIZE - gBG1YPosition)) >> 2);

            write16(REG_BG3HOFS, gBackgroundPositions.doorTransition.x);
            write16(REG_BG3VOFS, gBackgroundPositions.doorTransition.y);
            gWrittenToBLDCNT = 0x3F48;

            bgProp = gCurrentRoomEntry.BG0Prop;
            if (bgProp != 0x43 && bgProp != 0x44 && bgProp != 0x45)
            {
                gWrittenToBLDALPHA_H = 16;
                gWrittenToBLDALPHA_L = 0;
            }
            gWrittenToBLDALPHA = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;

            gBg3CntDuringDoorTransition = 0x4604;
            gBg1CntDuringDoorTransition = read16(REG_BG1CNT) | 1;
            gWrittenToDISPCNT = read16(REG_DISPCNT);
            gWrittenToDISPCNT |= DCNT_BG3;
            gWrittenToDISPCNT &= ~DCNT_BG0;

            gColorFading.stage = 4;
            gColorFading.unk_3 = 0;
            break;

        case 4:
            if (gWrittenToBLDALPHA_H != 0 || gWrittenToBLDALPHA_L < 16)
            {
                bldalphaH = gWrittenToBLDALPHA_H - 2;
                if (bldalphaH < 0)
                    bldalphaH = 0;

                gWrittenToBLDALPHA_H = bldalphaH;

                bldalphaL = gWrittenToBLDALPHA_L + 2;
                if (bldalphaL > 16)
                    bldalphaL = 16;

                gWrittenToBLDALPHA_L = bldalphaL;

                gWrittenToBLDALPHA = bldalphaL | bldalphaH << 8;
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
u8 ColorFading_Default(void)
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

            unk_5c27c(0);
            break;

        case 2:
            unk_5c2ec();
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c77c | 98 | Escape failed fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_EscapeFailed(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            gPauseScreenFlag = 0;
            ColorFadingStartDoorTransition();
            FadeAllSounds(60);
            FadeMusic(60);
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
                gColorFading.stage++;
            break;

        case 2:
            unk_5d09c();
            write16(PALRAM_BASE, 0x7FFF);
            gColorFading.unk_6 = 0;
            gColorFading.stage++;
            break;

        case 3:
            gColorFading.unk_6++;
            if (gColorFading.unk_6 > 60)
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
u8 ColorFading_ChozodiaEscape(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            write16(PALRAM_BASE, 0);
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
            {
                gGameModeSub1 = 0;
                gMainGameMode = GM_CHOZODIA_ESCAPE;
            }
    }

    return FALSE;
}

/**
 * @brief 5c8ac | 78 | Before demo end fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_BeforeDemoEnding(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            if (gColorFading.type == COLOR_FADING_DEMO_ENDING_WITH_INPUT)
                gCurrentDemo.unk_3 = 1;

            end_demo(); // Undefined
            gColorFading.stage++;
            break;

        case 1:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            unk_5c27c(3);
            break;

        case 2:
            unk_5d09c();
            write16(PALRAM_BASE, 0);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5c924 | 78 | Before tourian escape fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_TourianEscape(void)
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

            gColorFading.unk_6 = 0;
            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            unk_5c27c(7);
            break;

        case 3:
            unk_5c2ec();
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
u8 ColorFading_GettingFullyPowered(void)
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

            unk_5c27c(7);
            break;

        case 3:
            unk_5c2ec();

            gCurrentCutscene = CUTSCENE_GETTING_FULLY_POWERED;
            ColorFadingStart(2);

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
u8 ColorFading_BeforeRidleySpawn(void)
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

            unk_5c27c(7);
            break;

        case 3:
            unk_5c2ec();

            gCurrentCutscene = CUTSCENE_RIDLEY_SPAWNING;
            ColorFadingStart(2);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cad8 | a0 | Before statue opening cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_StatueOpening(void)
{
    switch (gColorFading.stage)
    {
        case 0:
            ColorFadingStartDoorTransition();
            gColorFading.stage++;
            break;

        case 1:
            if (gCurrentArea == AREA_KRAID || gCurrentArea == AREA_RIDLEY)
                FadeCurrentInsertMusicQueueCurrent(60, MUSIC_STATUE_ROOM_OPENED, 0);

            if (gAnimatedGraphicsEntry.palette != 0)
                gAnimatedGraphicsEntry.palette = 0;

            gColorFading.stage++;
            break;

        case 2:
            if (ColorFadingUpdate())
                gColorFading.stage++;

            unk_5c27c(7);
            break;

        case 3:
            unk_5c2ec();

            gCurrentCutscene = CUTSCENE_STATUE_OPENING;
            ColorFadingStart(2);
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cb78 | a4 | Before statue opening cutscene fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_BeforeIntroText(void)
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

            unk_5c27c(7);
            break;

        case 3:
            gCurrentCutscene = CUTSCENE_INTRO_TEXT;

            unk_5c2ec();
            ColorFadingStart(2);

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
u8 ColorFading_BeforeBlueShip(void)
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

            unk_5c27c(7);
            break;

        case 3:
            unk_5c2ec();

            gCurrentCutscene = CUTSCENE_SAMUS_IN_BLUE_SHIP;
            ColorFadingStart(2);

            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 5cc94 | 5c | Before ship landing sequence fade subroutine
 * 
 * @return u8 bool, ended
 */
u8 ColorFading_BeforeLandingShip(void)
{
    u8 ended;

    ended = FALSE;

    switch (gColorFading.stage)
    {
        case 0:
            unk_5c190();
            gColorFading.unk_6 = 0;
            gColorFading.stage++;
            break;

        case 1:
            gColorFading.unk_6++;

            if (gColorFading.unk_6 > 60)
            {
                gColorFading.unk_6 = 0;
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
u8 ColorFading_UpdateDefault(void)
{
    u8 ended;

    ended = FALSE;

    if (gColorFading.stage == 0)
    {
        unk_5c190();
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
u8 ColorFading_UpdateDoorTransition(void)
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

            gDoorPositionStart.y = BLOCK_SIZE * 4 - ((gDoorPositionStart.y * BLOCK_SIZE - gBG1YPosition) >> 2);

            if (gDoorUnlockTimer == 1)
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

                DMATransfer(3, EWRAM_BASE + 0x7000, VRAM_BASE + 0x3000, 0x1000, 16);

                write16(REG_BG0CNT, gIoRegistersBackup.unknown_12);
                write16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

                gBackgroundPositions.doorTransition.y = gBackgroundPositions.bg[3].y;
                gBackgroundPositions.doorTransition.x = gBackgroundPositions.bg[3].x;

                if (gHazeInfo.enabled)
                    gHazeInfo.active = TRUE;

                TransparencyUpdateBLDCNT(2, gIoRegistersBackup.BLDCNT_NonGameplay);
                write16(REG_DISPCNT, gIoRegistersBackup.DISPCNT_NonGameplay);

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
    if (gMonochromeBgFading == 0 || gMonochromeBgFading == UCHAR_MAX)
        return;

    gColorFading.unk_5 = TRUE;

    if (gMonochromeBgFading & 0x80)
    {
        if (ColorFadingUpdate())
        {
            write16(REG_DISPCNT, read16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3));
            gMonochromeBgFading = UCHAR_MAX;
        }
    }
    else
    {
        if (gMonochromeBgFading == 1)
        {
            ColorFadingStart(0x18);
            if (gCurrentHazeValue != 0)
            {
                gCurrentHazeValue = 0;
                unk_5d09c();
            }
        }
        else if (gMonochromeBgFading == 2)
        {
            ColorFadingStart(0x17);
        }
        else
        {
            gMonochromeBgFading = 0;
        }

        unk_5b340();
        gMonochromeBgFading |= 0x80;
    }
}
