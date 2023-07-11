#include "gba.h"
#include "power_bomb_explosion.h"

#include "data/engine_pointers.h"

#include "constants/clipdata.h"
#include "constants/haze.h"
#include "constants/game_state.h"
#include "constants/room.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/in_game_cutscene.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/power_bomb_explosion.h"
#include "temp_globals.h"

/**
 * 5745c | 48 | Subroutine for the power bomb explosion
 */
void PowerBombExplosionProcess(void)
{
    if (gCurrentPowerBomb.animationState > 1)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.unk_12 == 0) // Most likely a cancelled feature
        {
            if (gCurrentPowerBomb.animationState == 2)
                PowerBombExplosionBegin();
            else if (gCurrentPowerBomb.animationState == 5)
                PowerBombExplosionEnd();
            else if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
                PowerBombExplosion();
        }
    }
}

/**
 * @brief 574a4 | 248 | Updates the power bomb explosion, handles interacting with blocks
 * 
 */
void PowerBombExplosion(void)
{
    s32 verticalAxis;
    s32 horizontalAxis;
    s32 hitboxTop;
    s32 hitboxBottom;
    s32 hitboxLeft;
    s32 hitboxRight;
    s32 xLoop;
    s32 yLoop;
    s32 xPositionLeft;
    s32 xPositionRight;
    s32 yPositionTop;
    s32 yPositionBottom;
    u16 clipdata;
    
    verticalAxis = gCurrentPowerBomb.semiMinorAxis * 4;
    horizontalAxis = gCurrentPowerBomb.semiMinorAxis * 8;
    verticalAxis *= 0.95;
    horizontalAxis *= 0.95;

    hitboxLeft = (s16)-horizontalAxis;
    hitboxRight = (s16)horizontalAxis;
    hitboxTop = (s16)-verticalAxis;
    hitboxBottom = (s16)verticalAxis;

    horizontalAxis = hitboxLeft;
    if (gCurrentPowerBomb.xPosition + horizontalAxis < 0)
        hitboxLeft = (s16)-gCurrentPowerBomb.xPosition;

    verticalAxis = hitboxTop;    
    if (gCurrentPowerBomb.yPosition + verticalAxis < 0)
        hitboxTop = (s16)-gCurrentPowerBomb.yPosition;

    horizontalAxis = hitboxRight;
    if (gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE < (gCurrentPowerBomb.xPosition + horizontalAxis))
        hitboxRight = (s16)(gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE - gCurrentPowerBomb.xPosition);

    verticalAxis = hitboxBottom;
    if (gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE < (gCurrentPowerBomb.yPosition + verticalAxis))
        hitboxBottom = (s16)(gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE - gCurrentPowerBomb.yPosition);

    gCurrentPowerBomb.hitboxLeftOffset = hitboxLeft;
    gCurrentPowerBomb.hitboxRightOffset = hitboxRight;
    gCurrentPowerBomb.hitboxTopOffset = hitboxTop;
    gCurrentPowerBomb.hitboxBottomOffset = hitboxBottom;

    if (gCurrentPowerBomb.animationState < 4)
    {
        hitboxLeft = DIV_SHIFT(hitboxLeft + gCurrentPowerBomb.xPosition, BLOCK_SIZE);
        hitboxRight = DIV_SHIFT(hitboxRight + gCurrentPowerBomb.xPosition, BLOCK_SIZE);
        hitboxTop = DIV_SHIFT(hitboxTop + gCurrentPowerBomb.yPosition, BLOCK_SIZE);
        hitboxBottom = DIV_SHIFT(hitboxBottom + gCurrentPowerBomb.yPosition, BLOCK_SIZE);

        if (MOD_AND(gFrameCounter8Bit, 2) == 0)
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            for (xLoop = 0; xLoop < 2; xLoop++)
            {
                if (xLoop == 0)
                    horizontalAxis = hitboxLeft;
                else
                    horizontalAxis = hitboxRight;

                yPositionTop = gCurrentPowerBomb.yPosition / BLOCK_SIZE;
                yPositionBottom = yPositionTop;

                for (yLoop = 0; yLoop != 2;)
                {
                    yLoop = 0;
                    if (yPositionTop >= hitboxTop)
                    {
                        clipdata = gBgPointersAndDimensions.pClipDecomp[yPositionTop * gBgPointersAndDimensions.clipdataWidth + horizontalAxis];
                        if (clipdata != 0)
                            BlockApplyCCAA(yPositionTop, horizontalAxis, clipdata);

                        yPositionTop = (s16)(yPositionTop - 1);
                    }
                    else
                        yLoop = 0x1;
                    
                    if ((s32)yPositionBottom <= hitboxBottom)
                    {
                        clipdata = gBgPointersAndDimensions.pClipDecomp[yPositionBottom * gBgPointersAndDimensions.clipdataWidth + horizontalAxis];
                        if (clipdata != 0)
                            BlockApplyCCAA(yPositionBottom, horizontalAxis, clipdata);

                        yPositionBottom = (s16)(yPositionBottom + 1);
                    }
                    else
                        yLoop++;
                }
            }
        }
        else
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            for (xLoop = 0; xLoop < 2; xLoop++)
            {
                if (xLoop == 0)
                    verticalAxis = hitboxTop;
                else
                    verticalAxis = hitboxBottom;

                xPositionRight = gCurrentPowerBomb.xPosition / BLOCK_SIZE;
                xPositionLeft = xPositionRight;

                for (yLoop = 0; yLoop != 2; )
                {
                    yLoop = 0;
                    if (xPositionLeft >= hitboxLeft)
                    {
                        clipdata = gBgPointersAndDimensions.pClipDecomp[verticalAxis * gBgPointersAndDimensions.clipdataWidth + xPositionLeft];
                        if (clipdata != 0)
                            BlockApplyCCAA(verticalAxis, xPositionLeft, clipdata);
                        
                        xPositionLeft = (s16)(xPositionLeft - 1);
                    }
                    else
                        yLoop++;
                    
                    if (xPositionRight <= hitboxRight)
                    {
                        clipdata = gBgPointersAndDimensions.pClipDecomp[verticalAxis * gBgPointersAndDimensions.clipdataWidth + xPositionRight];
                        if (clipdata != 0)
                            BlockApplyCCAA(verticalAxis, xPositionRight, clipdata);

                        xPositionRight = (s16)(xPositionRight + 1);
                    }
                    else
                        yLoop++;
                }
            }
        }
        gCurrentClipdataAffectingAction = CAA_NONE;
    }
}

/**
 * 576ec | 48 | Starts a power bomb explosion at the given parameters
 * 
 * @param xPosition The X Position of the epicenter
 * @param yPosition The Y Position of the epicenter
 * @param owner Owner of the power bomb, left over from fusion
 */
void PowerBombExplosionStart(u16 xPosition, u16 yPosition, u8 owner)
{
    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    PowerBombExplosionSet0x12To0();
    if (gCurrentPowerBomb.animationState == 0) // Check if there isn't already an explosion
    {
        gCurrentPowerBomb.xPosition = xPosition;
        gCurrentPowerBomb.yPosition = yPosition;
        gCurrentPowerBomb.owner = owner;

        if (gCurrentPowerBomb.unk_12 != 0)
            gCurrentPowerBomb.animationState = 2;
        else
            PowerBombExplosionBegin();
    }
}

/**
 * 57734 | c | Sets the field at offset 0x12 of the current power bomb to 0x0, purpose is unknown 
 * 
 */
void PowerBombExplosionSet0x12To0(void)
{
    gCurrentPowerBomb.unk_12 = 0;
}

/**
 * @brief 57740 | 78 | Begins a power bomb explosion
 * 
 */
void PowerBombExplosionBegin(void)
{
    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    gCurrentPowerBomb.animationState = 3;
    gCurrentPowerBomb.powerBombPlaced = FALSE;

    DMA_SET(3, PALRAM_BASE, EWRAM_BASE + 0x9000, C_32_2_16(DMA_ENABLE, PALRAM_SIZE / 4));
    unk_02035400 = 0;

    HazeSetupCode(HAZE_VALUE_POWER_BOMB_EXPANDING);

    gCurrentPowerBomb.stage = 0;
    gCurrentPowerBomb.semiMinorAxis = 0x4;

    gCurrentPowerBomb.hitboxLeftOffset = 0;
    gCurrentPowerBomb.hitboxRightOffset = 0;
    gCurrentPowerBomb.hitboxTopOffset = 0;
    gCurrentPowerBomb.hitboxBottomOffset = 0;

    gCurrentPowerBomb.unk_12 = 0;
    gCurrentPowerBomb.unk_3 = 0;

    ScreenShakeStartHorizontal(120, 0x80);

    SoundPlay(0x101); // Power bomb explosion
}

/**
 * @brief 577b8 | 154 | Handles ending a power bomb explosion
 * 
 */
void PowerBombExplosionEnd(void)
{
    u8 eva;
    u8 evb;
    u8 done;

    if (gCurrentPowerBomb.stage == 0)
    {
        write16(REG_BLDY, 0);
        gWrittenToBLDCNT = gIoRegistersBackup.BLDCNT_NonGameplay;

        if (sHazeData[gCurrentRoomEntry.visualEffect][3] == 2)
            gWrittenToBLDALPHA = C_16_2_8(0, 16);
        else
            gWrittenToBLDALPHA = C_16_2_8(16, 0);

        gWrittenToDISPCNT = write16(REG_DISPCNT, read16(REG_DISPCNT) | DCNT_WIN1);

        gWrittenToWIN1H = C_16_2_8(gSuitFlashEffect.left, gSuitFlashEffect.right);
        gWrittenToWIN1V = C_16_2_8(gSuitFlashEffect.top, gSuitFlashEffect.bottom);

        // Set transparent color
        write16(PALRAM_BASE, 0);

        gWrittenToWININ_H = gIoRegistersBackup.WININ_H;
        gWrittenToWINOUT_L = gIoRegistersBackup.WINOUT_L;

        // Get BGCNT backups
        write16(REG_BG0CNT, gIoRegistersBackup.BG0CNT);
        write16(REG_BG1CNT, gIoRegistersBackup.BG1CNT);
        write16(REG_BG2CNT, gIoRegistersBackup.BG2CNT);
        write16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

        gWrittenToDISPCNT = gIoRegistersBackup.DISPCNT_NonGameplay;
        gCurrentPowerBomb.stage = 1;
    }
    else if (gCurrentPowerBomb.stage == 1)
    {
        // Fade BLDALPHA until it was the same as before the power bomb
        eva = LOW_BYTE(read16(REG_BLDALPHA));
        evb = HIGH_BYTE(read16(REG_BLDALPHA));
        done = TRUE;

        if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVB != evb)
        {
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVB < evb)
                evb--;
            else
                evb++;

            done = FALSE;
        }

        if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA != eva)
        {
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA < eva)
                eva--;
            else
                eva++;

            done = FALSE;
        }

        gWrittenToBLDALPHA = C_16_2_8(evb, eva);

        if (done)
            gCurrentPowerBomb.stage = 2;
    }
    else if (gCurrentPowerBomb.stage == 2)
    {
        // Kill the power bomb
        gCurrentPowerBomb.animationState = 0;
        gCurrentPowerBomb.owner = 0;
        gCurrentPowerBomb.stage = 0;
    }
}
