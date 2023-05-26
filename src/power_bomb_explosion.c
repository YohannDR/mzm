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
    if (gCurrentPowerBomb.animationState > 0x1)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.unk_12 == 0x0) // Most likely a cancelled feature
        {
            if (gCurrentPowerBomb.animationState == 0x2)
                PowerBombExplosionBegin();
            else if (gCurrentPowerBomb.animationState == 0x5)
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
    i32 verticalAxis;
    i32 horizontalAxis;
    i32 hitboxTop;
    i32 hitboxBottom;
    i32 hitboxLeft;
    i32 hitboxRight;
    i32 xLoop;
    i32 yLoop;
    u32 xPositionLeft;
    u32 xPositionRight;
    u32 yPositionTop;
    u32 yPositionBottom;
    u16 clipdata;
    i32 loopTemp;
    
    verticalAxis = gCurrentPowerBomb.semiMinorAxis * 0x4;
    horizontalAxis = gCurrentPowerBomb.semiMinorAxis * 0x8;
    verticalAxis *= 0.95;
    horizontalAxis *= 0.95;

    hitboxLeft = (i16)-horizontalAxis;
    hitboxRight = (i16)horizontalAxis;
    hitboxTop = (i16)-verticalAxis;
    hitboxBottom = (i16)verticalAxis;

    horizontalAxis = hitboxLeft;
    if ((i32)(gCurrentPowerBomb.xPosition + horizontalAxis) < 0x0)
        hitboxLeft = (i16)-gCurrentPowerBomb.xPosition;

    verticalAxis = hitboxTop;    
    if ((i32)(gCurrentPowerBomb.yPosition + verticalAxis) < 0x0)
        hitboxTop = (i16)-gCurrentPowerBomb.yPosition;

    horizontalAxis = hitboxRight;
    if ((i32)(gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE) < (gCurrentPowerBomb.xPosition + horizontalAxis))
        hitboxRight = (i16)((gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE) - gCurrentPowerBomb.xPosition);

    verticalAxis = hitboxBottom;
    if ((i32)(gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE) < (gCurrentPowerBomb.yPosition + verticalAxis))
        hitboxBottom = (i16)((gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE) - gCurrentPowerBomb.yPosition);

    gCurrentPowerBomb.hitboxLeftOffset = hitboxLeft;
    gCurrentPowerBomb.hitboxRightOffset = hitboxRight;
    gCurrentPowerBomb.hitboxTopOffset = hitboxTop;
    gCurrentPowerBomb.hitboxBottomOffset = hitboxBottom;

    if (gCurrentPowerBomb.animationState < 0x4)
    {
        hitboxLeft = (hitboxLeft + gCurrentPowerBomb.xPosition) >> 0x6;
        hitboxRight = (hitboxRight + gCurrentPowerBomb.xPosition) >> 0x6;
        hitboxTop = (hitboxTop + gCurrentPowerBomb.yPosition) >> 0x6;
        hitboxBottom = (hitboxBottom + gCurrentPowerBomb.yPosition) >> 0x6;

        if (!(gFrameCounter8Bit & 0x1))
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            for (xLoop = 0x0; xLoop < 0x2;)
            {
                if (xLoop == 0x0)
                    horizontalAxis = hitboxLeft;
                else
                    horizontalAxis = hitboxRight;

                yPositionTop = gCurrentPowerBomb.yPosition / BLOCK_SIZE;
                yPositionBottom = yPositionTop;
                xLoop++;
                loopTemp = xLoop;

                for (yLoop = 0x0; yLoop != 0x2;)
                {
                    yLoop = 0x0;
                    if ((i32)yPositionTop >= hitboxTop)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionTop * gBGPointersAndDimensions.clipdataWidth + horizontalAxis];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionTop, horizontalAxis, clipdata);

                        yPositionTop = (i16)(yPositionTop - 0x1);
                    }
                    else
                        yLoop = 0x1;
                    
                    if ((i32)yPositionBottom <= hitboxBottom)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionBottom * gBGPointersAndDimensions.clipdataWidth + horizontalAxis];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionBottom, horizontalAxis, clipdata);

                        yPositionBottom = (i16)(yPositionBottom + 0x1);
                    }
                    else
                        yLoop++;
                }

                xLoop = loopTemp;
            }
        }
        else
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            
            for (xLoop = 0x0; xLoop < 0x2;)
            {
                if (xLoop == 0x0)
                    verticalAxis = hitboxTop;
                else
                    verticalAxis = hitboxBottom;

                xPositionRight = gCurrentPowerBomb.xPosition / BLOCK_SIZE;
                xPositionLeft = xPositionRight;
                xLoop++;
                loopTemp = xLoop;

                for (yLoop = 0x0; yLoop != 0x2;)
                {
                    yLoop = 0x0;
                    if ((i32)xPositionLeft >= hitboxLeft)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[verticalAxis * gBGPointersAndDimensions.clipdataWidth + xPositionLeft];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(verticalAxis, xPositionLeft, clipdata);
                        
                        xPositionLeft = (i16)(xPositionLeft - 0x1);
                    }
                    else
                        yLoop++;
                    
                    if ((i32)xPositionRight <= hitboxRight)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[verticalAxis * gBGPointersAndDimensions.clipdataWidth + xPositionRight];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(verticalAxis, xPositionRight, clipdata);

                        xPositionRight = (i16)(xPositionRight + 0x1);
                    }
                    else
                        yLoop++;
                }

                xLoop = loopTemp;
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
    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.animationState == 0x0) // Check if there isn't already an explosion
        {
            gCurrentPowerBomb.xPosition = xPosition;
            gCurrentPowerBomb.yPosition = yPosition;
            gCurrentPowerBomb.owner = owner;
            if (gCurrentPowerBomb.unk_12 != 0x0)
                gCurrentPowerBomb.animationState = 0x2;
            else
                PowerBombExplosionBegin();
        }
    }
}

/**
 * 57734 | c | Sets the field at offset 0x12 of the current power bomb to 0x0, purpose is unknown 
 * 
 */
void PowerBombExplosionSet0x12To0(void)
{
    gCurrentPowerBomb.unk_12 = 0x0;
}

/**
 * @brief 57740 | 78 | Begins a power bomb explosion
 * 
 */
void PowerBombExplosionBegin(void)
{
    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        gCurrentPowerBomb.animationState = 0x3;
        gCurrentPowerBomb.powerBombPlaced = FALSE;
        dma_set(3, PALRAM_BASE, EWRAM_BASE + (0x9000), DMA_ENABLE << 0x10 | 0x100);
        unk_02035400 = 0x0;
        HazeSetupCode(HAZE_VALUE_POWER_BOMB_EXPANDING);
        gCurrentPowerBomb.stage = 0x0;
        gCurrentPowerBomb.semiMinorAxis = 0x4;
        gCurrentPowerBomb.hitboxLeftOffset = 0x0;
        gCurrentPowerBomb.hitboxRightOffset = 0x0;
        gCurrentPowerBomb.hitboxTopOffset = 0x0;
        gCurrentPowerBomb.hitboxBottomOffset = 0x0;
        gCurrentPowerBomb.unk_12 = 0x0;
        gCurrentPowerBomb.unk_3 = 0x0;
        ScreenShakeStartHorizontal(0x78, 0x80);
        SoundPlay(0x101); // Power bomb explosion
    }
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
    u16* pDispcnt;

    if (gCurrentPowerBomb.stage == 0)
    {
        write16(REG_BLDY, 0);
        gWrittenToBLDCNT = gIoRegistersBackup.BLDCNT_NonGameplay;

        if (sHazeData[gCurrentRoomEntry.visualEffect][3] == 2)
            gWrittenToBLDALPHA = 0x10;
        else
            gWrittenToBLDALPHA = 0x1000;

        pDispcnt = &gWrittenToDISPCNT;
        write16(REG_DISPCNT, read16(REG_DISPCNT) | DCNT_WIN1);
        write16(pDispcnt, read16(REG_DISPCNT));

        gWrittenToWIN1H = gSuitFlashEffect.left << 8 | gSuitFlashEffect.right;
        gWrittenToWIN1V = gSuitFlashEffect.top << 8 | gSuitFlashEffect.bottom;

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
        eva = read16(REG_BLDALPHA);
        evb = read16(REG_BLDALPHA) >> 8;
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

        gWrittenToBLDALPHA = evb << 8 | eva;
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
