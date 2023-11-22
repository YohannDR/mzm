#include "tourian_escape.h"
#include "macros.h"
#include "fixed_point.h"
#include "complex_oam.h"
#include "callbacks.h"

#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/shortcut_pointers.h"
#include "data/tourian_escape_data.h"
#include "data/cutscenes/story_text_cutscene_data.h"
#include "data/internal_tourian_escape_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/tourian_escape.h"

/**
 * @brief 81248 | d8 | V-blank for the tourian escape
 * 
 */
void TourianEscapeVBLank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBg0XPosition / 4);
    write16(REG_BG0VOFS, gBg0YPosition / 4);

    write16(REG_BG1HOFS, gBg1XPosition / 4);
    write16(REG_BG1VOFS, gBg1YPosition / 4);

    write16(REG_BG2HOFS, gBg2XPosition / 4);
    write16(REG_BG2VOFS, gBg2YPosition / 4);

    write16(REG_BG3HOFS, gBg3XPosition / 4);
    write16(REG_BG3VOFS, gBg3YPosition / 4);

    AnimatedGraphicsTransfer();
}

/**
 * @brief 81320 | f8 | V-blank for the tourian escape (zebes exploding sequence)
 * 
 */
void TourianEscapeVBLankZebesExploding(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBg0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBg0YPosition & 0xFF);

    write16(REG_BG1HOFS, gBg1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBg1YPosition & 0xFF);

    write16(REG_BG2HOFS, gBg2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBg2YPosition & 0xFF);

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
    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));

    write16(REG_BG2PA, gWrittenToBG2PA);
    write16(REG_BG2PB, gWrittenToBG2PB);
    write16(REG_BG2PC, gWrittenToBG2PC);
    write16(REG_BG2PD, gWrittenToBG2PD);

    write16(REG_BG2X, gWrittenToBG2X);
    write16(REG_BG2X + 2, (gWrittenToBG2X & (0xFFF << 16)) >> 16);

    write16(REG_BG2Y, gWrittenToBG2Y);
    write16(REG_BG2Y + 2, (gWrittenToBG2Y & (0xFFF << 16)) >> 16);

    write16(REG_BG0HOFS, gBg0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBg0YPosition & 0xFF);

    write16(REG_BG1HOFS, gBg1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBg1YPosition & 0xFF);

    write16(REG_BG2HOFS, gBg2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBg2YPosition & 0xFF);
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

    gWrittenToBG2X = (120 << 8) - gWrittenToBG2PA * 120 - gWrittenToBG2PB * 80;
    gWrittenToBG2Y = (80 << 8) - gWrittenToBG2PC * 120 - gWrittenToBG2PD * 80;
}

/**
 * @brief 81788 | 144 | To document
 * 
 * @param param_1 To document
 */
void unk_81788(u8 param_1)
{
    s32 i;
    u32 var_0;
    u32 offset;

    for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[i] / 4;
        if (TOURIAN_ESCAPE_DATA.unk_8[i] & 1)
        {
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ce00[offset];
        }
        else
        {
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ce10[offset];
        }

        var_0 = FALSE;
        if (!param_1)
        {
            if (TOURIAN_ESCAPE_DATA.oamXPositions[i] < 256)
            {
                TOURIAN_ESCAPE_DATA.oamXPositions[i] += TOURIAN_ESCAPE_DATA.unk_96[i];
            }
            else
            {
                var_0 = TRUE;
            }
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.oamYPositions[i] < 252)
            {
                TOURIAN_ESCAPE_DATA.oamYPositions[i] -= TOURIAN_ESCAPE_DATA.unk_96[i];
            }
            else
            {
                var_0 = TRUE;
            }
        }

        if (var_0)
        {
            TOURIAN_ESCAPE_DATA.unk_8[i] ^= 3;
            TOURIAN_ESCAPE_DATA.oamFrames[i] = (TOURIAN_ESCAPE_DATA.oamFrames[i] + 1) & 15;

            TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            TOURIAN_ESCAPE_DATA.unk_96[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][2];
        }

        TOURIAN_ESCAPE_DATA.oamTimers[i] = (TOURIAN_ESCAPE_DATA.oamTimers[i] + 1) & 15;
    }
}

/**
 * @brief 818cc | 20c | To document
 * 
 */
void unk_818cc(void)
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

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[0];
        part = *src++;
        nextSlot = part & 0xFF;

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[0];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[0];
    
        for (currSlot = 0; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            
            part = *src++;
            *dst++ = part;
            
            *dst++ = *src++;
            dst++;

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, TOURIAN_ESCAPE_DATA.unk_82, TRUE, 0);
        }

        CalculateOamPart4(0, TOURIAN_ESCAPE_DATA.unk_82, 0);
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[1];
        part = *src++;
        nextSlot += part & 0xFF;

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[1];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[1];
    
        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            
            part = *src++;
            *dst++ = part;
            
            *dst++ = *src++;
            dst++;

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, TOURIAN_ESCAPE_DATA.oamScaling, TRUE, 4);
        }

        CalculateOamPart4(0, TOURIAN_ESCAPE_DATA.oamScaling, 16);
    }

    for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;

        src = TOURIAN_ESCAPE_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += part & 0xFF;

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[i];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[i];

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
 * @brief 81ad8 | 22c | To document
 * 
 */
void unk_81ad8(void)
{
    const u16* src;
    u16* dst;
    u16 currSlot;
    u16 nextSlot;
    u16 yPosition;
    u16 xPosition;
    u16 part;
    u8 offset;
    u16 i;
    const u16* pal;

    if ((TOURIAN_ESCAPE_DATA.oamTimers[0] & 3) < 2)
    {
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x6D;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x46;
    }
    else
    {
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x6C;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x47;
    }

    TOURIAN_ESCAPE_DATA.oamTimers[0]++;

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[1]++ / 4;
        if (offset > 7)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x46;
            offset = 0;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47cea0[offset];
        TOURIAN_ESCAPE_DATA.oamXPositions[1] += sTourianEscape_47ce80[offset];
        TOURIAN_ESCAPE_DATA.oamYPositions[1] += sTourianEscape_47ce90[offset];
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[2])
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[2]++ / 4;
        if (offset >= ARRAY_SIZE(sTourianEscape_47ce90))
        {
            TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0x46;
            offset = 0;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47cea0[offset];
        TOURIAN_ESCAPE_DATA.oamXPositions[2] += sTourianEscape_47ce80[offset];
        TOURIAN_ESCAPE_DATA.oamYPositions[2] -= sTourianEscape_47ce90[offset];
    }

    if ((TOURIAN_ESCAPE_DATA.timer & 7) < 4)
    {
        pal = sTourianEscape_479f00 - 16;
    }
    else
    {
        pal = sTourianEscape_479f00;
    }

    DMA_SET(3, pal, PALRAM_OBJ + 0xA0, DMA_ENABLE << 16 | 16);

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < 4; i++)
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
            gOamData[currSlot].split.objMode = 1;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;

            *dst++ = *src++;
            dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 81d04 | 12c | Initializes the tourian escape
 * 
 */
void TourianEscapeInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);
    write16(REG_BLDCNT, 0);

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 0;

    write16(REG_IME, FALSE);
    CallbackSetVBlank(NULL);
    write16(REG_IME, TRUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    ClearGfxRam();

    LZ77UncompVRAM(sMotherShipBlowingUpExplosionsGfx, VRAM_OBJ);
    LZ77UncompVRAM(sTourianEscapeDebrisGfx, VRAM_BASE + 0x13000);

    DMA_SET(3, sMotherShipBlowingUpExplosionsPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sMotherShipBlowingUpExplosionsPal));

    LoadRoomCutscene(AREA_TOURIAN, 4 + 1, BLOCK_SIZE * 5, BLOCK_SIZE * 10);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(TourianEscapeVBLank);
    write16(REG_IME, TRUE);
    gNextOamSlot = 0;
    ResetFreeOam();

    TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
    TourianEscapeVBLank();
}

/**
 * @brief 81e30 | 834 | Handles the rooms exploding and ship leaving the planet part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeZebesExploding(void)
{
    u8 ended;
    s32 var_0;
    u16 i;
    u8 offset;

    ended = FALSE;
    var_0 = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = sTourianEscape_47ced0[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = sTourianEscape_47ced0[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = sTourianEscape_47cef0[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = sTourianEscape_47cef0[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = sTourianEscape_47cf10[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = sTourianEscape_47cf10[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[3] = 8;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = sTourianEscape_47cf30[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = sTourianEscape_47cf30[0][1];

            for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = TRUE;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = i;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(0x23E);
            break;

        case 64:
        case 136:
        case 208:
        case 352:
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            TOURIAN_ESCAPE_DATA.unk_1++;
            break;

        case 65:
            SoundPlay(0x23F);
            break;

        case 137:
            SoundPlay(0x241);
            break;

        case 209:
            SoundPlay(0x243);
            break;

        case 104:
            LoadRoomCutscene(AREA_TOURIAN, 5 + 1, BLOCK_SIZE * 2, BLOCK_SIZE * 12);

            i = 4;
            var_0 = TRUE;
            for (; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = (TOURIAN_ESCAPE_DATA.oamFrames[i] + 1) & 7;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(0x240);
            break;

        case 176:
            LoadRoomCutscene(AREA_CRATERIA, 1 + 1, BLOCK_SIZE * 2, BLOCK_SIZE * 16);

            i = 4;
            var_0 = TRUE;
            for (; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = (TOURIAN_ESCAPE_DATA.oamFrames[i] + 1) & 7;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(0x240);
            break;

        case 246:
            write16(REG_IME, FALSE);
            CallbackSetVBlank(TourianEscapeVBLankZebesExploding);
            write16(REG_IME, TRUE);

            LZ77UncompVRAM(sTourianEscapeZebesGfx, VRAM_BASE);
            break;

        case 247:
            LZ77UncompVRAM(sTourianEscapeZebesExplodingShipAndExplosionsGfx, VRAM_OBJ);
            TOURIAN_ESCAPE_DATA.unk_2++;
            TOURIAN_ESCAPE_DATA.unk_5 = 0;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 3;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x59;
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            for (i = 2; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = 0;
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
            }

            gBg0XPosition = 0;
            gBg0YPosition = 0;
            gBg1XPosition = 0;
            gBg1YPosition = 0;
            gBg2XPosition = 0;
            gBg2YPosition = 0;
            FadeCurrentMusicAndQueueNextMusic(0, MUSIC_ESCAPING_ZEBES_CUTSCENE, 0);
            break;

        case 248:
            LZ77UncompVRAM(sTourianEscapeZebesTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeExplodingPal));
            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeExplodingPal));

            write16(REG_BG0CNT, 0x1E00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            gWrittenToBLDALPHA_L = 10;
            gWrittenToBLDALPHA_H = 6;

            var_0 = 2;
            SoundPlay(0x244);
            break;

        case 512:
            gBg0XPosition = 0;
            gBg0YPosition = 0;
            ended = TRUE;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.timer < 60 * 4)
        AnimatedGraphicsUpdate();

    if (var_0)
    {
        TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
            BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

        gWrittenToBLDY_NonGameplay = 0;
        TOURIAN_ESCAPE_DATA.unk_1 = 0;
    }

    if (TOURIAN_ESCAPE_DATA.unk_1)
    {
        if (TOURIAN_ESCAPE_DATA.timer >= 256)
        {
            if (TOURIAN_ESCAPE_DATA.unk_5++ > 5)
            {
                if (gWrittenToBLDY_NonGameplay < 16)
                    gWrittenToBLDY_NonGameplay++;

                TOURIAN_ESCAPE_DATA.unk_5 = 0;
            }
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.unk_5++ & 1)
            {
                if (gWrittenToBLDY_NonGameplay < 16)
                    gWrittenToBLDY_NonGameplay++;
            }
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if ((TOURIAN_ESCAPE_DATA.timer & 7) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a4e0;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a506;

        if ((TOURIAN_ESCAPE_DATA.timer & 3) < 2)
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a52c;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a540;

        if (TOURIAN_ESCAPE_DATA.oamTimers[1] > 11)
        {
            gBg0XPosition++;
            TOURIAN_ESCAPE_DATA.oamXPositions[1]--;
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1]++;
        }
    }
    else
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] >= sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[0]++;

            if (sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[0] = ((TOURIAN_ESCAPE_DATA.unk_8[0] + 1) & 7) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[0] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[0] = sTourianEscape_47ced0[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[0] = sTourianEscape_47ced0[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[1] >= sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[1]++;

            if (sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[1] = ((TOURIAN_ESCAPE_DATA.unk_8[1] + 1) & 7) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[1] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[1] = sTourianEscape_47cef0[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[1] = sTourianEscape_47cef0[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[2] >= sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[2]++;

            if (sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[2] = ((TOURIAN_ESCAPE_DATA.unk_8[2] + 1) & 7) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[2] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[2] = sTourianEscape_47cf10[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[2] = sTourianEscape_47cf10[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[3] >= sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[3] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[3]++;

            if (sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[3] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[3] = ((TOURIAN_ESCAPE_DATA.unk_8[3] + 1) & 7) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[3] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[3] = sTourianEscape_47cf30[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[3] = sTourianEscape_47cf30[offset][1];
            }
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].pFrame;

        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
        TOURIAN_ESCAPE_DATA.oamTimers[1]++;
        TOURIAN_ESCAPE_DATA.oamTimers[2]++;
        TOURIAN_ESCAPE_DATA.oamTimers[3]++;

        for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
        {
            if (TOURIAN_ESCAPE_DATA.oamTimers[i] < 15)
                TOURIAN_ESCAPE_DATA.oamTimers[i]++;

            offset = TOURIAN_ESCAPE_DATA.oamTimers[i] / 4;
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47cec0[offset];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] += 4;
        }

        i = TOURIAN_ESCAPE_DATA.timer & 7;

        if (i == 1)
        {
            gBg0XPosition += 8;
            gBg0YPosition -= 8;
            gBg1XPosition += 8;
            gBg1YPosition -= 8;
            gBg2XPosition += 8;
            gBg2YPosition -= 8;
        }
        
        if (i == 3)
        {
            gBg3XPosition += 8;
            gBg3YPosition -= 8;
        }
        
        if (i == 4)
        {
            gBg0XPosition -= 8;
            gBg0YPosition += 8;
            gBg1XPosition -= 8;
            gBg1YPosition += 8;
            gBg2XPosition -= 8;
            gBg2YPosition += 8;
        }
        
        if (i == 6)
        {
            gBg3XPosition -= 8;
            gBg3YPosition += 8;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 82664 | 36c | Handles the samus in her ship part of the cutscene
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusInHerShip(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sMotherShipExplodingFlashGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sMotherShipExplodingFlashTileTable, VRAM_BASE + 0xF000);

            if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            {
                DMA_SET(3, sTourianEscapeSamusInHerShipVariaSuitPal, PALRAM_BASE,
                    DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusInHerShipVariaSuitPal));
            }
            else
            {
                DMA_SET(3, sTourianEscapeSamusInHerShipPowerSuitPal, PALRAM_BASE,
                    DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusInHerShipPowerSuitPal));
            }
            break;

        case 3:
            write16(REG_BG0CNT, 0x1E08);
            write16(REG_BG1CNT, 0xE01);

            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDY_NonGameplay = 0;
            break;

        case 56:
            TOURIAN_ESCAPE_DATA.dispcnt |= DCNT_WIN0;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBLDY_NonGameplay = 10;

            write16(REG_WININ, 0x3F);
            write16(REG_WINOUT, 0x1F);

            TOURIAN_ESCAPE_DATA.win0h_H = 0x77;
            TOURIAN_ESCAPE_DATA.win0h_L = 0x79;
            TOURIAN_ESCAPE_DATA.win0v_H = 0x4F;
            TOURIAN_ESCAPE_DATA.win0v_L = 0x51;

            TOURIAN_ESCAPE_DATA.unk_2++;
            SoundPlay(0x245);
            break;

        case 160:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessGfx, VRAM_BASE);
            break;

        case 161:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessEyesOpenedTileTable, VRAM_BASE + 0x7800);

            DMA_SET(3, sTourianEscapeSamusInHerShipSuitlessPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusInHerShipSuitlessPal));
            break;

        case 162:
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_2++;

            SoundPlay(0x246);
            break;

        case 200:
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;
            gWrittenToBLDALPHA_L = 16;

            TOURIAN_ESCAPE_DATA.unk_2++;
            SoundPlay(0x247);
            break;

        case 352:
            write16(REG_BG1CNT, 0xF00);
            break;

        case 372:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDY_NonGameplay = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 1)
    {
        if (TOURIAN_ESCAPE_DATA.unk_5++ < 40)
        {
            TOURIAN_ESCAPE_DATA.win0v_H -= 3;
            TOURIAN_ESCAPE_DATA.win0v_L += 3;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.win0h_H -= 4;
            TOURIAN_ESCAPE_DATA.win0h_L += 4;
        }

        if (TOURIAN_ESCAPE_DATA.win0v_H < 0)
            TOURIAN_ESCAPE_DATA.win0v_H = 0;

        if (TOURIAN_ESCAPE_DATA.win0v_L > 160)
            TOURIAN_ESCAPE_DATA.win0v_L = 160;

        if (TOURIAN_ESCAPE_DATA.win0h_H < 0)
            TOURIAN_ESCAPE_DATA.win0h_H = 0;

        if (TOURIAN_ESCAPE_DATA.win0h_L > 240)
            TOURIAN_ESCAPE_DATA.win0h_L = 240;

        if (TOURIAN_ESCAPE_DATA.timer >= 128 && TOURIAN_ESCAPE_DATA.timer & 1)
        {
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 == 2)
    {
        if (TOURIAN_ESCAPE_DATA.timer & 1)
        {
            if (gWrittenToBLDY_NonGameplay != 0)
                gWrittenToBLDY_NonGameplay--;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 != 0)
    {
        if (!(TOURIAN_ESCAPE_DATA.timer & 3))
        {
            if (gWrittenToBLDALPHA_L != 0)
            {
                gWrittenToBLDALPHA_L--;
                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }
        }
    }

    return ended;
}

/**
 * @brief 829d0 | 288 | Handles the samus looking around part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusLookingAround(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingGfx, VRAM_OBJ);

            gWrittenToBLDALPHA_L = 8;
            gWrittenToBLDALPHA_H = 8;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a554;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a56e;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE * 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingLeftTileTable, VRAM_BASE + 0x8000);
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingRightTileTable, VRAM_BASE + 0x8800);

            DMA_SET(3, sTourianEscapeSamusLookingAroundPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusLookingAroundPal));

            DMA_SET(3, sTourianEscapeSamusLookingAroundPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusLookingAroundPal));
            break;

        case 3:
            write16(REG_BG0CNT, 0x1000);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL;
            break;

        case 16:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 32:
            write16(REG_BG0CNT, 0x1100);
            break;

        case 56:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;

            gBg2Rotation = 0;
            gBg2Scaling = 0x600;
            gUnk_30013a2 = 0x600;
            ended++;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (TOURIAN_ESCAPE_DATA.oamYPositions[0] < 80)
        {
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 8;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] -= 8;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 82c58 | 178 | Handles the samus being surrounded part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusSurrounded(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusSurroundedBackgroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscape_49cb90, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusSurroundedBackgroundTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscape_49fb70, VRAM_BASE + 0x7800);

            DMA_SET(3, sTourianEscapeSamusSurroundedPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusSurroundedPal));

            gBg0XPosition = 0;
            gBg0YPosition = 0;

            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            break;

        case 3:
            write16(REG_IME, FALSE);
            CallbackSetVBlank(TourianEscapeVBLankSamusSurrounded);
            write16(REG_IME, TRUE);
            break;

        case 4:
            write16(REG_BG0CNT, 0xE01);
            write16(REG_BG1CNT, 0xE02);
            write16(REG_BG2CNT, 0x4F88);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_MODE_1 | DCNT_BG0 | DCNT_BG2 | DCNT_OBJ;
            break;

        case 32:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 112:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            ended = TRUE;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (gBg2Scaling > 256)
        {
            gBg2Scaling -= 80;
            gUnk_30013a2 -= 80;
        }
        else
        {
            gBg2Scaling = 256;
            gUnk_30013a2 = 256;
        }
    }

    TourianEscapeCalculateBg2();

    return ended;
}

/**
 * @brief 82dd0 | 1d0 | Handles the samus flying in part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusFlyingIn(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            write16(REG_IME, FALSE);
            CallbackSetVBlank(TourianEscapeVBLankZebesExploding);
            write16(REG_IME, TRUE);

            LZ77UncompVRAM(sIntroTextAndShipFlyingInGfx, VRAM_OBJ);
            SoundPlay(0x235);
            break;

        case 1:
            LZ77UncompVRAM(sIntroSpaceBackgroundGfx, VRAM_BASE);
            break;

        case 2:
            LZ77UncompVRAM(sIntroSpaceBackgroundTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sIntroTextAndShipPAL, PALRAM_BASE, DMA_ENABLE << 16 | sizeof(sIntroTextAndShipPAL) / 2 + 16);
            DMA_SET(3, sIntroTextAndShipPAL, PALRAM_OBJ, DMA_ENABLE << 16 | sizeof(sIntroTextAndShipPAL) / 2 + 16);

            write16(REG_BG0CNT, 0x1E00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;

            gWrittenToBLDALPHA_L = 9;
            gWrittenToBLDALPHA_H = 7;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_82 = 32;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x1C;
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            break;

        case 32:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;

            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 8;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 8)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 6;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 16)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 3;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 20)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 1;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 28)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] -= 1;

        if (TOURIAN_ESCAPE_DATA.unk_82 < 128)
            TOURIAN_ESCAPE_DATA.unk_82 += 8;
        else if (TOURIAN_ESCAPE_DATA.unk_82 < 320)
            TOURIAN_ESCAPE_DATA.unk_82 += 16;
        else if (TOURIAN_ESCAPE_DATA.unk_82 < 480)
            TOURIAN_ESCAPE_DATA.unk_82 += 32;

        if ((TOURIAN_ESCAPE_DATA.oamTimers[0]++ & 7) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sIntroShipFlyingTowardsCameraOam_1;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sIntroShipFlyingTowardsCameraOam_2;
    }

    unk_818cc();

    return ended;
}

/**
 * @brief 82fa0 | 424 | Handles the samus being chased by pirates part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusChasedByPirates(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusChasedBackgroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusSamusChasedShipsGfx, VRAM_OBJ);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusChasedBackgroundTileTable, VRAM_BASE + 0xE000);

            DMA_SET(3, sTourianEscapeSamusChasedBackgroundPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusChasedBackgroundPal));
            DMA_SET(3, sTourianEscapeSamusChasedShipsPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusChasedShipsPal));

            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a602;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0xDC;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0xDC;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a622;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x100;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0xF0;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47a642;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0xB4;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0xF0;
            TOURIAN_ESCAPE_DATA.oamPriorities[2] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a662;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = 0xD4;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = 0xBE;
            TOURIAN_ESCAPE_DATA.oamPriorities[3] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[4] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[5] = 6;

            TOURIAN_ESCAPE_DATA.unk_8[6] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[6] = 14;

            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[7] = 9;

            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[8] = 3;

            TOURIAN_ESCAPE_DATA.unk_8[9] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[9] = 11;

            for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
            {
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
                TOURIAN_ESCAPE_DATA.unk_96[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][2];
            }

            gBg0XPosition = 0;
            gBg0YPosition = 0;
            break;

        case 3:
            write16(REG_BG0CNT, 0x1C00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            break;

        case 40:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            SoundPlay(0x236);
            break;

        case 64:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;

            SoundPlay(0x237);
            break;

        case 72:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 116:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a5d4;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;

            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47a5f4;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 119:
            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a5f4;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 160:
            TOURIAN_ESCAPE_DATA.unk_8[0] = 2;
            SoundPlay(0x238);
            break;

        case 176:
            TOURIAN_ESCAPE_DATA.unk_8[1] = 2;
            SoundPlay(0x239);
            break;

        case 182:
            TOURIAN_ESCAPE_DATA.unk_8[2] = 2;
            break;

        case 184:
            TOURIAN_ESCAPE_DATA.unk_8[3] = 2;
            break;

        case 177:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 192:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            break;

        case 198:
            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            break;

        case 200:
            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            break;

        case 256:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            ended = TRUE;
    }

    if (!(TOURIAN_ESCAPE_DATA.timer & 7))
        gBg0XPosition--;

    for (i = 0; i < 4; i++)
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[i] == 1)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] -= 6;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] += 6;
        }
        else if (TOURIAN_ESCAPE_DATA.unk_8[i] == 2)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] += 14;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] -= 14;
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(FALSE);

    if (TOURIAN_ESCAPE_DATA.unk_8[0] == 2)
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a588;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a5ae;

        TOURIAN_ESCAPE_DATA.oamTimers[0] = MOD_AND(TOURIAN_ESCAPE_DATA.oamTimers[0] + 1, 8);
    }

    TourianEscapeProcessOam();
    
    return ended;
}

/**
 * @brief 833c4 | 49c | Handles the samus chased by pirates firing part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusChasedByPiratesFiring(void)
{
    u8 ended;
    s32 velocity;
    u32 var_0;
    u32 var_1;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeShipsAndProjectilesGfx, VRAM_OBJ);
            break;

        case 1:
            DMA_SET(3, sTourianEscapeSamusChasedByPiratesFiringPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusChasedByPiratesFiringPal));

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE + HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.unk_82 = 0xC0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamScaling = Q_8_8(1.f);

            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[6] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[9] = TRUE;

            TOURIAN_ESCAPE_DATA.oamXPositions[2] = TOURIAN_ESCAPE_DATA.oamXPositions[0] * 8;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = TOURIAN_ESCAPE_DATA.oamYPositions[0] * 8;

            TOURIAN_ESCAPE_DATA.unk_96[2] = sTourianEscape_47cfa4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_AE = sTourianEscape_47cfb4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_96[3] = sTourianEscape_47cfc4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_B0 = sTourianEscape_47cfd4[TOURIAN_ESCAPE_DATA.oamFrames[3]];

            gBg0XPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
            gBg0YPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            break;

        case 2:
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            SoundPlay(0x23A);
            SoundPlay(0x248);
            break;

        case 120:
            TOURIAN_ESCAPE_DATA.unk_8[1]++;
            break;

        case 160:
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;

        case 126:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            break;

        case 192:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            break;

        case 368:
            SoundPlay(0x23B);
            break;

        case 384:
            ended = TRUE;
    }

    if (!(TOURIAN_ESCAPE_DATA.timer & 7))
        gBg0YPosition--;

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[0] == 1)
        {
            velocity = TOURIAN_ESCAPE_DATA.unk_96[2];

            if (velocity > 48)
                velocity = 48;

            if (velocity < -48)
                velocity = -48;

            TOURIAN_ESCAPE_DATA.oamXPositions[2] += velocity;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = TOURIAN_ESCAPE_DATA.oamXPositions[2] >> 3;

            velocity = TOURIAN_ESCAPE_DATA.unk_AE;

            if (velocity > 24)
                velocity = 24;

            if (velocity < -24)
                velocity = -24;

            TOURIAN_ESCAPE_DATA.oamYPositions[2] += velocity;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = TOURIAN_ESCAPE_DATA.oamYPositions[2] >> 3;

            TOURIAN_ESCAPE_DATA.unk_96[2] += TOURIAN_ESCAPE_DATA.unk_96[3];
            TOURIAN_ESCAPE_DATA.unk_AE += TOURIAN_ESCAPE_DATA.unk_B0;

            var_0 = 0;

            switch (TOURIAN_ESCAPE_DATA.oamFrames[2])
            {
                case 0:
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] >= 0)
                        var_0 = 1;
                    break;

                case 1:
                case 3:
                    if (TOURIAN_ESCAPE_DATA.oamTimers[2]++ > 19)
                    {
                        TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
                        var_0 = 2;
                    }
                    break;

                case 2:
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] <= 0)
                        var_0 = 1;
                    break;
            }

            if (var_0 == 1)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                TOURIAN_ESCAPE_DATA.unk_96[3] = 0;
                TOURIAN_ESCAPE_DATA.unk_B0 = 0;
            }
            
            if (var_0 == 2)
            {
                if (TOURIAN_ESCAPE_DATA.oamFrames[2] < 3)
                    TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                else
                    TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;

                if (TOURIAN_ESCAPE_DATA.oamFrames[3] < 7)
                    TOURIAN_ESCAPE_DATA.oamFrames[3]++;
                else
                    TOURIAN_ESCAPE_DATA.oamFrames[3] = 0;

                TOURIAN_ESCAPE_DATA.unk_96[2] = sTourianEscape_47cfa4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_AE = sTourianEscape_47cfb4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_96[3] = sTourianEscape_47cfc4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_B0 = sTourianEscape_47cfd4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            }

            if (TOURIAN_ESCAPE_DATA.oamTimers[0] & 1)
                TOURIAN_ESCAPE_DATA.unk_82++;
        }

        if (TOURIAN_ESCAPE_DATA.unk_8[0] < 3)
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[0] > 14)
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[0] >= 23)
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 23;

            if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 4;
            else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 8)
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 2;
            else
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 1;

            if (TOURIAN_ESCAPE_DATA.unk_82 < 0x1F8)
                TOURIAN_ESCAPE_DATA.unk_82 += 8;
        }
        
        var_1 = TOURIAN_ESCAPE_DATA.oamFrames[0] / 4;
        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47cf70[var_1];

        TOURIAN_ESCAPE_DATA.oamFrames[0]++;
        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(TRUE);

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        var_1 = 0;
        if (TOURIAN_ESCAPE_DATA.oamScaling > Q_8_8(.625f))
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[1] > 26)
                TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;

            var_1 = TOURIAN_ESCAPE_DATA.oamFrames[1] / 4;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47cf88[var_1];

        if (TOURIAN_ESCAPE_DATA.unk_8[1] == 1)
            TOURIAN_ESCAPE_DATA.oamScaling -= Q_8_8(.005f);
        else
            TOURIAN_ESCAPE_DATA.oamScaling -= Q_8_8(.01f);

        if (TOURIAN_ESCAPE_DATA.oamScaling < Q_8_8(.035f))
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;

        TOURIAN_ESCAPE_DATA.oamFrames[1]++;
        TOURIAN_ESCAPE_DATA.oamTimers[1]++;
    }

    unk_818cc();

    return ended;
}

/**
 * @brief 83860 | 4b0 | Handles the samus getting shot part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusGettingShot(void)
{
    u8 ended;
    s32 velocity;
    u16 position;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotGfx, VRAM_BASE + 0x8000);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotShipGfx, VRAM_OBJ);
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            gWrittenToBLDY_NonGameplay = 16;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotTileTable, VRAM_BASE + 0xF000);
            DMA_SET(3, sTourianEscapeSamusGettingShotPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusGettingShotPal));

            gBg0XPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gBg0YPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.unk_1++;
            break;

        case 3:
            write16(REG_BG0CNT, 0x1C00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[6] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[9] = TRUE;
            break;

        case 24:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a904;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x12D;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0xAE;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 0;

            TOURIAN_ESCAPE_DATA.oamXPositions[1] = TOURIAN_ESCAPE_DATA.oamXPositions[0] * 32;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = TOURIAN_ESCAPE_DATA.oamYPositions[0] * 32;

            TOURIAN_ESCAPE_DATA.unk_96[1] = 0x38;
            TOURIAN_ESCAPE_DATA.unk_96[2] = 0x1C;
            break;

        case 128:
            TOURIAN_ESCAPE_DATA.unk_96[1] = 0;
            TOURIAN_ESCAPE_DATA.unk_96[2] = 0;

        case 136:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            break;

        case 336:
            DMA_SET(3, sTourianEscapeSamusGettingShotPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusGettingShotPal));
            write16(REG_BG1CNT, 0x1E09);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_8[0] = 0;
            SoundPlay(0x23C);
            break;

        case 400:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_1)
    {
        if (gWrittenToBLDY_NonGameplay != 0)
        {
            if (!(TOURIAN_ESCAPE_DATA.timer & 7))
                gWrittenToBLDY_NonGameplay--;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            TOURIAN_ESCAPE_DATA.unk_1 = FALSE;
        }
    }

    if (!(TOURIAN_ESCAPE_DATA.timer & 7))
        gBg0XPosition--;

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(FALSE);

    if (TOURIAN_ESCAPE_DATA.unk_8[0] == 1)
    {
        if (TOURIAN_ESCAPE_DATA.timer > 0x6F)
        {
            TOURIAN_ESCAPE_DATA.unk_96[1]--;
            if (TOURIAN_ESCAPE_DATA.timer & 1)
                TOURIAN_ESCAPE_DATA.unk_96[2]--;
        }

        position = TOURIAN_ESCAPE_DATA.oamXPositions[1] -= TOURIAN_ESCAPE_DATA.unk_96[1];
        TOURIAN_ESCAPE_DATA.oamXPositions[2] -= TOURIAN_ESCAPE_DATA.unk_96[2];
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = TOURIAN_ESCAPE_DATA.oamXPositions[1] / 32;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = TOURIAN_ESCAPE_DATA.oamXPositions[2] / 32;
    }
    else if (TOURIAN_ESCAPE_DATA.unk_8[0] == 3)
    {
        switch (TOURIAN_ESCAPE_DATA.oamFrames[1])
        {
            case 0:
                TOURIAN_ESCAPE_DATA.unk_96[1]--;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] < -27)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 1:
                TOURIAN_ESCAPE_DATA.unk_96[1]++;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] == 0)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 2:
            case 5:
                if (TOURIAN_ESCAPE_DATA.oamTimers[3]++ > 3)
                {
                    if (TOURIAN_ESCAPE_DATA.oamFrames[1] == 2)
                        TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                    else
                        TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;

                    TOURIAN_ESCAPE_DATA.oamTimers[3] = 0;
                }
                break;

            case 3:
                TOURIAN_ESCAPE_DATA.unk_96[1]++;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] > 39)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 4:
                TOURIAN_ESCAPE_DATA.unk_96[1]--;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] == 0)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;
        }
        
        velocity = TOURIAN_ESCAPE_DATA.unk_96[1];
        if (velocity > 16)
            velocity = 16;
    
        if (velocity < -16)
            velocity = -16;
    
        position = TOURIAN_ESCAPE_DATA.oamXPositions[1] += velocity;
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = position / 32;
    
        switch (TOURIAN_ESCAPE_DATA.oamFrames[2])
        {
                case 0:
                    TOURIAN_ESCAPE_DATA.unk_96[2]--;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] < -19)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 1:
                    TOURIAN_ESCAPE_DATA.unk_96[2]++;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] == 0)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 2:
                case 5:
                    if (TOURIAN_ESCAPE_DATA.oamTimers[4]++ > 3)
                    {
                        if (TOURIAN_ESCAPE_DATA.oamFrames[2] == 2)
                            TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                        else
                            TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;
    
                        TOURIAN_ESCAPE_DATA.oamTimers[4] = 0;
                    }
                    break;
    
                case 3:
                    TOURIAN_ESCAPE_DATA.unk_96[2]++;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] > 19)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 4:
                    TOURIAN_ESCAPE_DATA.unk_96[2]--;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] == 0)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
        }
    
        velocity = TOURIAN_ESCAPE_DATA.unk_96[2];
        if (velocity > 8)
            velocity = 8;
    
        if (velocity < -8)
            velocity = -8;
    
        position = TOURIAN_ESCAPE_DATA.oamXPositions[2] += velocity;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = position / 32;
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 83d10 | 198 | Handles the samus going to crash part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusGoingToCrash(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeZebesGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeShipGoingToCrashGfx, VRAM_OBJ);
            gBg0XPosition = 16;
            gBg0YPosition = 0;

            gWrittenToBLDALPHA_L = 9;
            gWrittenToBLDALPHA_H = 7;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeZebesTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeExplodingPal));
            DMA_SET(3, sTourianEscapeSamusGoingToCrashPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusGoingToCrashPal));

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a98a;
            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a958;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = 0x88;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = 0x58;
            break;

        case 3:
            write16(REG_BG0CNT, 0x1E00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            SoundPlay(0x23D);
            break;

        case 6:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x46;
            break;

        case 12:
            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0x46;
            break;

        case 80:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_5++ > 4)
    {
        TOURIAN_ESCAPE_DATA.unk_5 = 0;
        gBg0XPosition--;
    }

    unk_81ad8();

    return ended;
}

/**
 * @brief 83ea8 | 25c | Handles the samus crashing part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusCrashing(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeShipCrashingForegroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeShipCrashingExplosionGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeShipCrashingBackgroundAndShipGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sTourianEscapeShipCrashingForegroundTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeShipCrashingExplosionTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sTourianEscapeSamusCrashingForegroundPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusCrashingForegroundPal));
            break;

        case 4:
            DMA_SET(3, sTourianEscapeShipCrashingBackgroundAndShipPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeShipCrashingBackgroundAndShipPal));

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47aa96;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x68;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 2;

            gBg0XPosition = 0;
            gBg0YPosition = 0;

            SoundPlay(0x249);
            break;

        case 5:
            write16(REG_BG0CNT, 0xE00);
            write16(REG_BG1CNT, 0x1E09);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            break;

        case 10:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0xFA;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x10;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 2;
            break;

        case 64:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 104:
            DMA_SET(3, sTourianEscape_479f80, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscape_479f80));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47ab28;
            TOURIAN_ESCAPE_DATA.unk_2++;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            SoundPlay(0x24A);
            break;

        case 288:
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (TOURIAN_ESCAPE_DATA.unk_5 & 1)
        {
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
        }

        TOURIAN_ESCAPE_DATA.unk_5++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        TOURIAN_ESCAPE_DATA.oamFrames[0] = (TOURIAN_ESCAPE_DATA.oamTimers[0] & 31) / 8;
        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47cfe4[TOURIAN_ESCAPE_DATA.oamFrames[0]];
        TOURIAN_ESCAPE_DATA.oamXPositions[0] -= 4;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] += 2;
        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 84104 | 288 | Handles the samus looking at the sky part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusLookingAtSky(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkySkyBackgroundGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyPiratesShipGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkySkyBackgroundTileTable, VRAM_BASE + 0xE000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyTopTileTable, VRAM_BASE + 0xF000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyBottomTileTable, VRAM_BASE + 0xF800);

            DMA_SET(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusLookingAtSkyPal));
            DMA_SET(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusLookingAtSkyPal));

            gBg0YPosition = 0;
            gBg1YPosition = 0;
            gBg2YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 4:
            write16(REG_BG0CNT, 0x1C0A);
            write16(REG_BG1CNT, 0x1E01);
            write16(REG_BG2CNT, 0x1F00);
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;

        case 160:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 16:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47abba;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 2;

            SoundPlay(0x24B);
            break;

        case 24:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47abc8;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 2;
            break;

        case 96:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 104:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            break;

        case 432:
            SET_BACKDROP_COLOR(COLOR_BLACK);
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            gBg0YPosition = 0;
            gBg1YPosition = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 1)
    {
        if (TOURIAN_ESCAPE_DATA.timer & 1)
        {
            if (gWrittenToBLDY_NonGameplay != 0)
                gWrittenToBLDY_NonGameplay--;
            else
                TOURIAN_ESCAPE_DATA.bldcnt = 0;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 == 2)
    {
        gBg0YPosition++;
        gBg1YPosition++;

        if (gBg0YPosition >= 96)
            gBg2YPosition++;

        if ((gBg2YPosition & 0xFF) == 160)
            TOURIAN_ESCAPE_DATA.unk_2 = 0;
    }

    for (i = 0; i < 2; i++)
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[i])
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] += 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] -= 3;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 8438c | 388 | Handles the samus looking at the mother ship part
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSamusLookingAtMotherShip(void)
{
    u8 ended;
    u8 i;
    u16 position;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipMotherShipGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipMotherShipTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sTourianEscapeSamusLookingAtMotherShipPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusLookingAtMotherShipPal));

            gBg0XPosition = 16;
            gBg1XPosition = 0;
            break;

        case 3:
            BitFill(3, 0, VRAM_OBJ, 0x8000, 32);
            LZ77UncompVRAM(sTourianEscapeRainGfx, VRAM_OBJ);
            DMA_SET(3, sTourianEscapeRainPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeRainPal));
            DMA_SET(3, sStoryTextCutscenePAL, PALRAM_OBJ + PALRAM_SIZE / 2 - 16 * 2, DMA_ENABLE << 16 | ARRAY_SIZE(sStoryTextCutscenePAL));

            for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = TRUE;
                TOURIAN_ESCAPE_DATA.oamTimers[i] = sTourianEscape_47cff4[i];
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cffe[i];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = BLOCK_SIZE * 4 - 4;
                TOURIAN_ESCAPE_DATA.oamPriorities[i] = 0;
            }

            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            gWrittenToBLDY_NonGameplay = 0;
            break;

        case 4:
            write16(REG_BG0CNT, 0xE00);
            write16(REG_BG1CNT, 0x1E09);

            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BRIGHTNESS_INCREASE_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;

        case 96:
        case 160:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 5:
            TextStartStory(STORY_TEXT_THE_TIMING);
            break;

        case 6:
        case 224:
            TOURIAN_ESCAPE_DATA.unk_BE++;
            break;

        case 448:
            TOURIAN_ESCAPE_DATA.timer--;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.timer >= 448 && gChangedInput & (KEY_A | KEY_B))
        ended = TRUE + 1;

    if (TOURIAN_ESCAPE_DATA.unk_BE == 1)
    {
        if (TextProcessStory())
            TOURIAN_ESCAPE_DATA.unk_BE++;
    }
    else if (TOURIAN_ESCAPE_DATA.unk_BE == 3)
    {
        if (!(TOURIAN_ESCAPE_DATA.unk_BF++ & 3))
        {
            if (gWrittenToBLDALPHA_L < 16)
            {
                gWrittenToBLDALPHA_L++;
                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 < 2)
    {
        i = TOURIAN_ESCAPE_DATA.unk_5++ & 15;
        if (i == 0)
        {
            gBg0XPosition--;
            gBg1XPosition++;
        }
        
        if (i == 8)
            gBg1XPosition++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 3 && TOURIAN_ESCAPE_DATA.timer & 1)
    {
        if (gWrittenToBLDY_NonGameplay < 4)
            gWrittenToBLDY_NonGameplay++;
    }

    for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;

        if (TOURIAN_ESCAPE_DATA.oamTimers[i] != 0)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[i]--;
            continue;
        }

        TOURIAN_ESCAPE_DATA.oamXPositions[i] -= 2;
        position = TOURIAN_ESCAPE_DATA.oamYPositions[i];
        TOURIAN_ESCAPE_DATA.oamYPositions[i] += 4;
        position -= (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        
        if (position < 13)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cffe[i];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] = BLOCK_SIZE * 4 - 4;
        }

        if ((TOURIAN_ESCAPE_DATA.timer & 7) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ac10;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ac18;
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 84714 | e4 | Executes the current tourian escape subroutine
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeCallSubroutines(void)
{
    u8 ended;
    u8 result;
    s32 i;

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
                    TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                    TOURIAN_ESCAPE_DATA.oamPriorities[i] = 0;

                    if (i < 4)
                        TOURIAN_ESCAPE_DATA.oamFrames[i] = 0;
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
