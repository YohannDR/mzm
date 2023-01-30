#include "intro.h"
#include "temp_globals.h"

#include "data/intro_data.h"

#include "constants/intro.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/intro.h"

/**
 * @brief 800f4 | 90 | V-blank code for the intro
 * 
 */
void IntroVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, INTRO_DATA.dispcnt);
    write16(REG_BLDCNT, INTRO_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BG0HOFS, gBG0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBG0YPosition & 0x1FF);
}

/**
 * @brief 80184 | 58 | V-blank code for the intro fuzz
 * 
 */
void IntroFuzzVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, INTRO_DATA.dispcnt);
    write16(REG_BLDCNT, INTRO_DATA.bldcnt);

    dma_set(3, INTRO_DATA.fuzzPalette, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | sizeof(INTRO_DATA.fuzzPalette) / 2);
}

void IntroInit(void)
{

}

void IntroTextProcessOAM(void)
{
    
}

/**
 * @brief 80550 | 180 | Processes the intro text
 * 
 * @param action Text action
 * @param indent Indent
 * @return u8 To document
 */
u8 IntroProcessText(u8 action, u16 indent)
{
    u8 dontProcess;
    u8 flag_unk2;
    u8 newLine;
    u8 flag_unk3;
    i32 previousY;
    i32 newY;

    // TODO macro
    do{newY = (i16)indent;}while(0);

    dontProcess = FALSE;
    flag_unk2 = FALSE;
    newLine = FALSE;
    flag_unk3 = FALSE;

    previousY = INTRO_DATA.charDrawerY;

    switch (action)
    {
        case INTRO_TEXT_END:
            if (INTRO_DATA.unk_A != 1)
            {
                if (INTRO_DATA.unk_A > 0x14)
                    return 2;
            }
            else
            {
                INTRO_DATA.charDrawerY += 8;
                SoundPlay(0x226);
            }
            return 0;

        case INTRO_TEXT_ACTION_START:
            if (INTRO_DATA.unk_A > 3)
            {
                INTRO_DATA.nextCharacter += 2;
                INTRO_DATA.currentCharacter++;
                flag_unk3++;
            }
            dontProcess++;
            break;

        case INTRO_TEXT_SPACE:
            if (INTRO_DATA.unk_A == 1)
                INTRO_DATA.charDrawerY += 8;
            else if (INTRO_DATA.unk_A > 3)
            {
                INTRO_DATA.nextCharacter++;
                INTRO_DATA.currentCharacter++;
                flag_unk3++;
            }

            dontProcess++;
            break;

        case INTRO_TEXT_NEW_LINE:
            newLine++;

        case INTRO_TEXT_UNKNOWN:
            flag_unk2++;
    }

    if (!dontProcess)
    {
        switch (INTRO_DATA.unk_A)
        {
            case 0:
            case 3:
                INTRO_DATA.characterPalette = 1;
                break;

            case 1:
                INTRO_DATA.characterPalette = 2;
                if (newLine)
                {
                    INTRO_DATA.charDrawerY = newY;
                    INTRO_DATA.charDrawerX += 0x18;
                }
                else
                    INTRO_DATA.charDrawerY += 0x8;
                break;

            case 4:
                INTRO_DATA.characterPalette = 0;
                break;

            case 5:
                INTRO_DATA.currentCharacter++;
                if (flag_unk2)
                    INTRO_DATA.nextCharacter += 2;
                else
                    INTRO_DATA.nextCharacter++;
                flag_unk3++;
        }
    }

    if (previousY != INTRO_DATA.charDrawerY && action != INTRO_TEXT_SPACE)
        SoundPlay(0x226);

    if (flag_unk3 != 0)
        return 1;
    
    return 0;
}

u8 IntroEmergencyOrder(void)
{

}

void IntroShipFlyingTowardsCameraProcessOAM(void)
{

}

/**
 * @brief 808ec | 9c | Handles the ship flying towards camera part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroShipFlyingTowardsCamera(void)
{
    u8 ended;

    ended = FALSE;

    switch (INTRO_DATA.timer)
    {
        case 0:
            INTRO_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL;
            gWrittenToBLDALPHA_L = 9;
            gWrittenToBLDALPHA_H = 7;
            break;

        case 1:
            INTRO_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            SoundPlay(4);
            SoundPlay(0x227);
            break;

        case 0x20:
            INTRO_DATA.dispcnt = 0;
            INTRO_DATA.bldcnt = 0;
            INTRO_DATA.stage++;
            ended = TRUE;
    }

    IntroShipFlyingTowardsCameraProcessOAM();
    if (ended)
        INTRO_DATA.timer = 0;
    else
        INTRO_DATA.timer++;

    return FALSE;
}

u8 IntroSamusInHerShip(void)
{

}

u8 IntroExterminate(void)
{

}

void IntroViewOfZebesProcessOAM(void)
{

}

u8 IntroViewOfZebes(void)
{

}

u8 IntroDefeat(void)
{

}

u8 IntroMotherBrain(void)
{

}

/**
 * @brief 81018 | 88 | Processes the OAM for the intro fuzz
 * 
 */
void IntroFuzzProcessOAM(void)
{
    u16* dst;
    const u16* src;
    u16 partCount;
    u16 i;
    u16 part;
    u16 offset;

    dst = (u16*)gOamData;
    src = sIntroFuzzOAM;
    partCount = *src++;

    offset = BLOCK_SIZE * 2;

    for (i = 0; i < partCount; i++)
    {
        part = *src++;
        *dst++ = part;
        gOamData[i].split.y = part - BLOCK_SIZE * 2;

        part = *src++;
        *dst++ = part;
        gOamData[i].split.x = (part + offset) & 0x1FF;

        *dst++ = *src++;
        dst++;
    }

    gNextOAMSlot = i;
}

u8 IntroFuzz(void)
{

}

u32 IntroSubroutine(void)
{

}
