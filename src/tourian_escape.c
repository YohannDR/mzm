#include "tourian_escape.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/shortcut_pointers.h"
#include "data/tourian_escape_data.h"
#include "data/internal_tourian_escape_data.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/tourian_escape.h"

/**
 * @brief 81248 | d8 | V-blank for the tourian escape
 * 
 */
void TourianEscapeVBLank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBG0XPosition / 4);
    write16(REG_BG0VOFS, gBG0YPosition / 4);

    write16(REG_BG1HOFS, gBG1XPosition / 4);
    write16(REG_BG1VOFS, gBG1YPosition / 4);

    write16(REG_BG2HOFS, gBG2XPosition / 4);
    write16(REG_BG2VOFS, gBG2YPosition / 4);

    write16(REG_BG3HOFS, gBG3XPosition / 4);
    write16(REG_BG3VOFS, gBG3YPosition / 4);

    AnimatedGraphicsTransfer();
}

/**
 * @brief 81320 | f8 | V-blank for the tourian escape (zebes exploding sequence)
 * 
 */
void TourianEscapeVBLankZebesExploding(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBG0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBG0YPosition & 0xFF);

    write16(REG_BG1HOFS, gBG1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBG1YPosition & 0xFF);

    write16(REG_BG2HOFS, gBG2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBG2YPosition & 0xFF);

    write16(REG_WIN0H, TOURIAN_ESCAPE_DATA.win0h_H << 8 | TOURIAN_ESCAPE_DATA.win0h_L);
    write16(REG_WIN0V, TOURIAN_ESCAPE_DATA.win0v_H << 8 | TOURIAN_ESCAPE_DATA.win0v_L);
}

/**
 * @brief 81418 | 100 | V-blank for the tourian escape (samus surrounded sequence)
 * 
 */
void TourianEscapeVBLankSamusSurrounded(void)
{
    write16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);
    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);

    write16(REG_BG2PA, gWrittenToBG2PA);
    write16(REG_BG2PB, gWrittenToBG2PB);
    write16(REG_BG2PC, gWrittenToBG2PC);
    write16(REG_BG2PD, gWrittenToBG2PD);

    write16(REG_BG2X, gWrittenToBG2X);
    write16(REG_BG2X + 2, (gWrittenToBG2X & (0xFFF << 16)) >> 16);

    write16(REG_BG2Y, gWrittenToBG2Y);
    write16(REG_BG2Y + 2, (gWrittenToBG2Y & (0xFFF << 16)) >> 16);

    write16(REG_BG0HOFS, gBG0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBG0YPosition & 0xFF);

    write16(REG_BG1HOFS, gBG1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBG1YPosition & 0xFF);

    write16(REG_BG2HOFS, gBG2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBG2YPosition & 0xFF);
}

/**
 * @brief 81518 | 16c | Processes the OAM
 * 
 */
void TourianEscapeProcessOam(void)
{
    u16* dst;
    const u16* src;
    u16 nextSlot;
    u16 currSlot;
    u16 part;
    u16 yPosition;
    u16 xPosition;
    u16 i;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;
    
    if (TOURIAN_ESCAPE_DATA.unk_BE > 2)
    {
        src = sTourianEscape_375cc4;
        part = *src++;
        nextSlot += part & 0xFF;

        xPosition = 128;
        yPosition = 80;

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.objMode = 1;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;

            *dst++ = *src++;
            *dst++;
        }
    }

    for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;
        
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += part & 0xFF;

        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[i];
        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[i];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;

            *dst++ = *src++;

            gOamData[currSlot].split.priority = TOURIAN_ESCAPE_DATA.oamPriorities[i];
            *dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 81684 | 104 | Calcultes the BG2 position and matrix parameters
 * 
 */
void TourianEscapeCalculateBg2(void)
{
    gWrittenToBG2PA = FixedMultiplication(cos(gBg2Rotation), FixedInverse(gBg2Scaling));
    gWrittenToBG2PB = FixedMultiplication(sin(gBg2Rotation), FixedInverse(gBg2Scaling));
    gWrittenToBG2PC = FixedMultiplication(-sin(gBg2Rotation), FixedInverse(gUnk_30013a2));
    gWrittenToBG2PD = gWrittenToBG2PA;

    gWrittenToBG2X = 0x7800 - gWrittenToBG2PA * 0x78 - gWrittenToBG2PB * 0x50;
    gWrittenToBG2Y = 0x5000 - gWrittenToBG2PC * 0x78 - gWrittenToBG2PD * 0x50;
}

void unk_81788(u8 param_1)
{

}

void unk_818cc(void)
{

}

void unk_81ad8(void)
{

}

void TourianEscapeInit(void)
{

}

u8 TourianEscapeZebesExploding(void)
{

}

u8 TourianEscapeSamusInHerShip(void)
{

}

u8 TourianEscapeSamusLookingAround(void)
{

}

u8 TourianEscapeSamusSurrounded(void)
{

}

u8 TourianEscapeSamusFlyingIn(void)
{

}

u8 TourianEscapeSamusChasedByPirates(void)
{

}

u8 TourianEscapeSamusChasedByPiratesFiring(void)
{

}

u8 TourianEscapeSamusGettingShot(void)
{

}

u8 TourianEscapeSamusGoingToCrash(void)
{

}

u8 TourianEscapeSamusCrashing(void)
{

}

u8 TourianEscapeSamusLookingAtSky(void)
{

}

u8 TourianEscapeSamusLookingAtMotherShip(void)
{

}

/**
 * @brief 84714 | e4 | 
 * 
 * @return u8 
 */
u8 TourianEscapeCallSubroutines(void)
{
    u8 ended;
    u8 result;
    i32 i;

    ended = FALSE;
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
            TourianEscapeInit();
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            result = sTourianEscapeSubroutinePointers[TOURIAN_ESCAPE_DATA.stage]();

            if (result == TRUE)
            {
                TOURIAN_ESCAPE_DATA.stage++;
                TOURIAN_ESCAPE_DATA.unk_2 = 0;
                TOURIAN_ESCAPE_DATA.unk_5 = 0;
                TOURIAN_ESCAPE_DATA.timer = 0;
                TOURIAN_ESCAPE_DATA.unk_1 = 0;

                for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
                {
                    TOURIAN_ESCAPE_DATA.unk_8[i] = 0;
                    TOURIAN_ESCAPE_DATA.unk_46[i] = 0;
                    TOURIAN_ESCAPE_DATA.oamPriorities[i] = 0;

                    if (i < 4)
                        TOURIAN_ESCAPE_DATA.unk_3C[i] = 0;
                }
            }
            else if (result)
                gGameModeSub1++;

            ResetFreeOam();
            break;

        case 3:
            ended = TRUE;
    }

    return ended;
}
