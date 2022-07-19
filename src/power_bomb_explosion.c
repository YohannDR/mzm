#include "power_bomb_explosion.h"
#include "clipdata.h"
#include "screen_shake.h"
#include "globals.h"

/**
 * 5745c | 48 | Subroutine for the power bomb explosion
 */
void PowerBombExplosionProcess(void)
{
    if (gCurrentPowerBomb.animationState > 0x1)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.alsoAlwaysZero == 0x0) // Most likely a cancelled feature
        {
            if (gCurrentPowerBomb.animationState == 0x2)
                PowerBombExplosionBegin();
            else if (gCurrentPowerBomb.animationState == 0x5)
                PowerBombExplosionEnd();
            else if (gGameModeSub1 == 0x2)
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
    // https://decomp.me/scratch/0gXpq

    /*i32 verticalAxis;
    i32 horizontalAxis;
    i32 hitboxLeft;
    i32 hitboxRight;
    i32 hitboxTop;
    i32 hitboxBottom;
    i32 xLoop;
    i32 yLoop;
    u32 xPositionLeft;
    u32 xPositionRight;
    u32 yPositionTop;
    u32 yPositionBottom;
    u16 clipdata;
    
    verticalAxis = gCurrentPowerBomb.semiMinorAxis * 0x4;
    horizontalAxis = gCurrentPowerBomb.semiMinorAxis * 0x8;
    verticalAxis *= 0.95;
    horizontalAxis *= 0.95;

    hitboxLeft = (i16)-horizontalAxis;
    hitboxRight = (i16)horizontalAxis;
    hitboxTop = (i16)-verticalAxis;
    hitboxBottom = (i16)verticalAxis;

    if ((i32)(gCurrentPowerBomb.xPosition + hitboxLeft) < 0x0)
        hitboxLeft = (i16)-gCurrentPowerBomb.xPosition;
    
    if ((i32)(gCurrentPowerBomb.yPosition + hitboxTop) < 0x0)
        hitboxLeft = (i16)-gCurrentPowerBomb.xPosition;

    if ((i32)(gBGPointersAndDimensions.clipdataWidth << 0x6) < (gCurrentPowerBomb.xPosition + hitboxRight))
        hitboxRight = (i16)((gBGPointersAndDimensions.clipdataWidth << 0x6) - gCurrentPowerBomb.xPosition);

    if ((i32)(gBGPointersAndDimensions.clipdataHeight << 0x6) < (gCurrentPowerBomb.yPosition + hitboxBottom))
        hitboxRight = (i16)((gBGPointersAndDimensions.clipdataHeight << 0x6) - gCurrentPowerBomb.yPosition);

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
            gCurrentClipdataAffectingAction = CCAA_POWER_BOMB;

            xLoop = 0x0;
            do
            {
                if (xLoop == 0x0)
                    xPositionLeft = hitboxLeft;
                else
                    xPositionLeft = hitboxRight;

                yPositionTop = (gCurrentPowerBomb.yPosition >> 0x6);
                yPositionBottom = yPositionTop;
                xLoop++;

                do
                {
                    yLoop = 0x0;
                    if ((i32)yPositionTop >= hitboxTop)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionTop * gBGPointersAndDimensions.clipdataWidth + xPositionLeft];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionTop, xPositionLeft, clipdata);

                        yPositionTop = (i16)(yPositionTop - 0x1);
                    }
                    else
                        yLoop = 0x1;
                    
                    if ((i32)yPositionBottom <= hitboxBottom)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionBottom * gBGPointersAndDimensions.clipdataWidth + xPositionLeft];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionBottom, xPositionLeft, clipdata);

                        yPositionBottom = (i16)(yPositionBottom + 0x1);
                    }
                    else
                        yLoop++;
                } while (yLoop != 0x2);

            } while (xLoop < 0x2);
        }
        else
        {
            gCurrentClipdataAffectingAction = CCAA_POWER_BOMB;

            xLoop = 0x0;
            do
            {
                if (xLoop == 0x0)
                    yPositionTop = hitboxTop;
                else
                    yPositionTop = hitboxBottom;

                xPositionLeft = (gCurrentPowerBomb.xPosition >> 0x6);
                xPositionRight = xPositionLeft;
                xLoop++;

                do
                {
                    yLoop = 0x0;
                    if ((i32)xPositionLeft >= hitboxLeft)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionTop * gBGPointersAndDimensions.clipdataWidth + xPositionLeft];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionTop, xPositionLeft, clipdata);

                        xPositionLeft = (i16)(xPositionLeft - 0x1);
                    }
                    else
                        yLoop = 0x1;
                    
                    if ((i32)xPositionRight <= hitboxRight)
                    {
                        clipdata = gBGPointersAndDimensions.pClipDecomp[yPositionTop * gBGPointersAndDimensions.clipdataWidth + xPositionRight];
                        if (clipdata != 0x0)
                            BlockApplyCCAA(yPositionTop, xPositionRight, clipdata);

                        xPositionRight = (i16)(xPositionRight + 0x1);
                    }
                    else
                        yLoop++;
                } while (yLoop != 0x2);

            } while (xLoop < 0x2);
        }
        gCurrentClipdataAffectingAction = CCAA_NONE;
    }*/
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
    if (gGameModeSub1 == 0x2)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.animationState == 0x0) // Check if there isn't already an explosion
        {
            gCurrentPowerBomb.xPosition = xPosition;
            gCurrentPowerBomb.yPosition = yPosition;
            gCurrentPowerBomb.owner = owner;
            if (gCurrentPowerBomb.alsoAlwaysZero != 0x0)
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
    gCurrentPowerBomb.alsoAlwaysZero = 0x0;
}

/**
 * @brief 57740 | 78 | Begins a power bomb explosion
 * 
 */
void PowerBombExplosionBegin(void)
{
    if (gGameModeSub1 == 0x2)
    {
        gCurrentPowerBomb.animationState = 0x3;
        gCurrentPowerBomb.powerBombPlaced = FALSE;
        dma_set(3, PALRAM_BASE, IWRAM_BASE + (0x9000), DMA_ENABLE << 0x10 | 0x100);
        unk_02035400 = 0x0;
        // TODO defines
        SetupHazeCode(0x7); // Undefined | Power bomb expanding
        gCurrentPowerBomb.stage = 0x0;
        gCurrentPowerBomb.semiMinorAxis = 0x4;
        gCurrentPowerBomb.hitboxLeftOffset = 0x0;
        gCurrentPowerBomb.hitboxRightOffset = 0x0;
        gCurrentPowerBomb.hitboxTopOffset = 0x0;
        gCurrentPowerBomb.hitboxBottomOffset = 0x0;
        gCurrentPowerBomb.alsoAlwaysZero = 0x0;
        gCurrentPowerBomb.unknown = 0x0;
        ScreenShakeStartHorizontal(0x78, 0x80);
        SoundPlay(0x101); // Power bomb explosion
    }
}

void PowerBombExplosionEnd(void)
{

}