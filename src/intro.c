#include "intro.h"
#include "callbacks.h"
#include "macros.h"
#include "complex_oam.h" // Required

#include "data/shortcut_pointers.h"
#include "data/intro_data.h"
#include "data/internal_intro_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"
#include "constants/intro.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/intro.h"

/**
 * @brief 800f4 | 90 | V-blank code for the intro
 * 
 */
void IntroVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    write16(REG_DISPCNT, INTRO_DATA.dispcnt);
    write16(REG_BLDCNT, INTRO_DATA.bldcnt);

    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BG0HOFS, MOD_AND(gBg0XPosition, 512));
    write16(REG_BG0VOFS, MOD_AND(gBg0YPosition, 512));
}

/**
 * @brief 80184 | 58 | V-blank code for the intro fuzz
 * 
 */
void IntroFuzzVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    write16(REG_DISPCNT, INTRO_DATA.dispcnt);
    write16(REG_BLDCNT, INTRO_DATA.bldcnt);

    DMA_SET(3, INTRO_DATA.fuzzPalette, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(INTRO_DATA.fuzzPalette)));
}

/**
 * @brief 801dc | 1d4 | Initializes the intro
 * 
 */
void IntroInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);

    write16(REG_IF, IF_HBLANK);
    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);
    write16(REG_IME, FALSE);

    CallbackSetVBlank(IntroVBlank);

    write16(REG_IME, TRUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, C_32_2_16(DMA_ENABLE | DMA_SRC_FIXED | DMA_32BIT, sizeof(gNonGameplayRAM) / 4));

    INTRO_DATA.scaling = Q_8_8(.125f);
    INTRO_DATA.charDrawerX = 0x38;
    INTRO_DATA.charDrawerY = 0x60;

    ClearGfxRam();

    LZ77UncompVRAM(sIntroTextAndShipFlyingInGfx, VRAM_OBJ);
    LZ77UncompVRAM(sIntroSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVRAM(sIntroSpaceBackgroundTileTable, VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sIntro_47920c, VRAM_BASE + 0x9000);

    DMA_SET(3, sIntroTextAndShipPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroTextAndShipPal)));
    DMA_SET(3, sIntroTextAndShipPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroTextAndShipPal)));
    DMA_SET(3, sIntroPal_45f9d4, PALRAM_BASE + 0x1E0, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroPal_45f9d4)));

    write16(REG_BG0CNT, CREATE_BGCNT(0, 16, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    write16(REG_BG1CNT, CREATE_BGCNT(0, 18, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, gBg0XPosition);
    write16(REG_BG0VOFS, gBg0YPosition);
    write16(REG_BG1HOFS, gBg1XPosition);
    write16(REG_BG1VOFS, gBg1YPosition);
    write16(REG_BG2HOFS, gBg2XPosition);
    write16(REG_BG2VOFS, gBg2YPosition);
    write16(REG_BG3HOFS, gBg3XPosition);
    write16(REG_BG3VOFS, gBg3YPosition);

    UpdateMusicPriority(1);

    INTRO_DATA.dispcnt = DCNT_OBJ;
    INTRO_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDY_NonGameplay = 16;

    IntroVBlank();
}

void IntroTextProcessOAM(void)
{
    const u16* src;
    u16* dst;
    u16 i;
    u16 partCount;
    u16 yPosition;
    u16 xPosition;
    u16 part;

    switch (INTRO_DATA.unk_9++)
    {
        case 0:
        case 3:
            INTRO_DATA.charDrawerPalette = 1;
            break;

        case 1:
            INTRO_DATA.charDrawerPalette = 2;
            break;

        case 4:
            INTRO_DATA.charDrawerPalette = 0;
            INTRO_DATA.unk_9 = 0;
            break;
    }

    dst = (u16*)gOamData;
    i = 0;
    yPosition = BLOCK_SIZE * 2;
    xPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 2;

    if (INTRO_DATA.nextCharacter != 0)
    {
        src = INTRO_DATA.pTextOamFramePointer;
        partCount = *src++;
        for (; i < partCount; i++)
        {
            // Brackets are necesary
            if (i >= INTRO_DATA.nextCharacter) 
            {
                break;
            }

            part = *src++;
            *dst++ = part;

            gOamData[i].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[i].split.x = MOD_AND(part + xPosition, 512);
            *dst++ = *src++;

            if (i == INTRO_DATA.nextCharacter - 1)
                gOamData[i].split.paletteNum = INTRO_DATA.characterPalette;
            else
                gOamData[i].split.paletteNum = 0;

            dst++;
        }
    }

    src = sIntroTextMarkerOAM;
    partCount = i + *src++;

    yPosition = INTRO_DATA.charDrawerY;
    xPosition = INTRO_DATA.charDrawerX;

    for (; i < partCount; i++)
    {
        part = *src++;
        *dst++ = part;

        gOamData[i].split.y = part + yPosition;

        part = *src++;
        *dst++ = part;

        gOamData[i].split.x = MOD_AND(part + xPosition, 512);

        *dst++ = *src++;
        gOamData[i].split.paletteNum = INTRO_DATA.charDrawerPalette;

        dst++;
    }

    gNextOamSlot = i;
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
    s32 previousY;
    s32 newY;

    // TODO macro
    do{newY = (s16)indent;}while(0);

    dontProcess = FALSE;
    flag_unk2 = FALSE;
    newLine = FALSE;
    flag_unk3 = FALSE;

    previousY = INTRO_DATA.charDrawerX;

    switch (action)
    {
        case INTRO_TEXT_ACTION_END:
            if (INTRO_DATA.unk_A != 1)
            {
                if (INTRO_DATA.unk_A > 0x14)
                    return 2;
            }
            else
            {
                INTRO_DATA.charDrawerX += 8;
                SoundPlay(SOUND_INTRO_TEXT_LETTER);
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

        case INTRO_TEXT_ACTION_SPACE:
            if (INTRO_DATA.unk_A == 1)
                INTRO_DATA.charDrawerX += 8;
            else if (INTRO_DATA.unk_A > 3)
            {
                INTRO_DATA.nextCharacter++;
                INTRO_DATA.currentCharacter++;
                flag_unk3++;
            }

            dontProcess++;
            break;

        case INTRO_TEXT_ACTION_NEW_LINE:
            newLine++;

        case INTRO_TEXT_ACTION_UNKNOWN:
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
                    INTRO_DATA.charDrawerX = newY;
                    INTRO_DATA.charDrawerY += 0x18;
                }
                else
                    INTRO_DATA.charDrawerX += 0x8;
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

    if (previousY != INTRO_DATA.charDrawerX && action != INTRO_TEXT_ACTION_SPACE)
        SoundPlay(SOUND_INTRO_TEXT_LETTER);

    if (flag_unk3 != 0)
        return 1;
    
    return 0;
}

/**
 * @brief 806d0 | e8 | Handles the "Emergency order" text part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroEmergencyOrder(void)
{
    u8 textResult;

    switch (INTRO_DATA.timer++)
    {
        case 0:
            if (gLanguage != LANGUAGE_ENGLISH)
                TextStartStory(STORY_TEXT_EMERGENCY);
            break;

        case 10:
            INTRO_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            break;
    }

    if (INTRO_DATA.unk_42 == 0 && gLanguage != LANGUAGE_ENGLISH)
        INTRO_DATA.unk_42 = TextProcessStory();

    textResult = IntroProcessText(sIntroEmergencyOrderActions[INTRO_DATA.currentCharacter], 0x38);
    if (textResult == 2)
    {
        INTRO_DATA.stage++;
        INTRO_DATA.nextCharacter = 0;
        INTRO_DATA.currentCharacter = 0;
        INTRO_DATA.unk_A = 0;
        INTRO_DATA.timer = 0;
        INTRO_DATA.unk_42 = 0;
        INTRO_DATA.charDrawerX = 0x18;
        INTRO_DATA.charDrawerY = 0x50;
        INTRO_DATA.shipFlyingTowardsCameraX = 0x78;
        INTRO_DATA.shipFlyingTowardsCameraY = 0x1C;
    }
    else
    {
        INTRO_DATA.pTextOamFramePointer = sIntroEmergencyOrderTextOAM;
        IntroTextProcessOAM();
        if (textResult != 0)
            INTRO_DATA.unk_A = 0;
        else
            INTRO_DATA.unk_A++;
    }

    return FALSE;
}

/**
 * @brief 807b8 | 134 | Processes the OAM for the ship flying towards the camera
 * 
 */
void IntroShipFlyingTowardsCameraProcessOAM(void)
{
    const u16* src;
    u16* dst;
    u16 xPosition;
    u16 yPosition;
    u16 partCount;
    u16 i;
    u16 part;

    dst = (u16*)gOamData;

    if (INTRO_DATA.timer < 4)
        INTRO_DATA.shipFlyingTowardsCameraY += 8;
    else if (INTRO_DATA.timer < 8)
        INTRO_DATA.shipFlyingTowardsCameraY += 6;
    else if (INTRO_DATA.timer < 16)
        INTRO_DATA.shipFlyingTowardsCameraY += 3;
    else if (INTRO_DATA.timer < 20)
        INTRO_DATA.shipFlyingTowardsCameraY += 1;
    else if (INTRO_DATA.timer < 28)
        INTRO_DATA.shipFlyingTowardsCameraY -= 1;

    if (INTRO_DATA.scaling < Q_8_8(.5f))
        INTRO_DATA.scaling += Q_8_8(.035f);
    else if (INTRO_DATA.scaling < Q_8_8(1.25f))
        INTRO_DATA.scaling += Q_8_8(.065f);
    else if (INTRO_DATA.scaling < Q_8_8(1.875f))
        INTRO_DATA.scaling += Q_8_8(.125f);

    if (MOD_AND(INTRO_DATA.timer, 8) < 4)
        src = sIntroShipFlyingTowardsCameraOam_1;
    else
        src = sIntroShipFlyingTowardsCameraOam_2;

    partCount = *src++;
    yPosition = INTRO_DATA.shipFlyingTowardsCameraY;
    xPosition = INTRO_DATA.shipFlyingTowardsCameraX;

    for (i = 0; i < partCount; i++)
    {
        part = *src++;
        *dst++ = part;

        part = *src++;
        *dst++ = part;

        *dst++ = *src++;
        dst++;

        ProcessComplexOam(i, xPosition, yPosition, INTRO_DATA.rotation, INTRO_DATA.scaling, TRUE, 0);
    }

    gNextOamSlot = i;
    CalculateOamPart4(INTRO_DATA.rotation, INTRO_DATA.scaling, 0);
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
            SoundPlay(MUSIC_INTRO);
            SoundPlay(SOUND_INTRO_SHIP_FLYING_TOWARDS_CAMERA);
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

/**
 * @brief 80988 | 100 | Handles the samus in her ship part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroSamusInHerShip(void)
{
    u8 ended;

    ended = FALSE;

    switch (INTRO_DATA.timer)
    {
        case 0:
            LZ77UncompVRAM(sIntroSamusInHerShipGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sIntroSamusInHerShipTileTable, VRAM_BASE + 0x8000);
            break;

        case 2:
            DMA_SET(3, sIntroSamusInHerShipPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroSamusInHerShipPal)));
            break;

        case 3:
            INTRO_DATA.dispcnt = DCNT_BG0;
            SoundPlay(SOUND_INTRO_SHIP_INTERIOR);
            break;

        case 0x50:
            INTRO_DATA.dispcnt = 0;
            SoundFade(SOUND_INTRO_SHIP_INTERIOR, 0);
            INTRO_DATA.stage++;
            ended = TRUE;
    }

    if (MOD_AND(INTRO_DATA.unk_A, 4) < 2)
    {
        gBg0XPosition = 0;
        gBg0YPosition = 0;
    }
    else
    {
        gBg0XPosition--;
        gBg0YPosition--;
    }

    INTRO_DATA.unk_A++;
    if (ended)
    {
        INTRO_DATA.timer = 0;
        INTRO_DATA.unk_A = 0;
    }
    else
        INTRO_DATA.timer++;

    return FALSE;
}

/**
 * @brief 80a88 | f0 | Handles the "Exterminate..." text part of the intro
 * 
 * @return u8 
 */
u8 IntroExterminate(void)
{
    u8 textResult;

    switch (INTRO_DATA.timer++)
    {
        case 0:
            INTRO_DATA.dispcnt = DCNT_OBJ;
            if (gLanguage != LANGUAGE_ENGLISH)
                TextStartStory(STORY_TEXT_EXTERMINATE);
            break;

        case 10:
            INTRO_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            break;
    }

    if (INTRO_DATA.unk_42 == 0 && gLanguage != LANGUAGE_ENGLISH)
        INTRO_DATA.unk_42 = TextProcessStory();

    textResult = IntroProcessText(sIntroExterminateAllActions[INTRO_DATA.currentCharacter], PIXEL_SIZE * 2);
    if (textResult == 2)
    {
        INTRO_DATA.stage++;
        INTRO_DATA.nextCharacter = 0;
        INTRO_DATA.currentCharacter = 0;
        INTRO_DATA.unk_A = 0;
        INTRO_DATA.timer = 0;
        INTRO_DATA.unk_42 = 0;
        INTRO_DATA.charDrawerX = 0x18;
        INTRO_DATA.charDrawerY = 0x50;
        INTRO_DATA.dispcnt = 0;
    }
    else
    {
        INTRO_DATA.pTextOamFramePointer = sIntroExterminateAllTextOAM;
        IntroTextProcessOAM();
        if (textResult != 0)
            INTRO_DATA.unk_A = 0;
        else
            INTRO_DATA.unk_A++;
    }

    return FALSE;
}

/**
 * @brief 80b78 | 154 | Processes the OAM for the view of zebes part of the intro
 * 
 */
void IntroViewOfZebesProcessOAM(void)
{
    const u16* src;
    u16* dst;
    u16 i;
    u16 partCount;
    u16 yPosition;
    u16 xPosition;
    u16 part;

    dst = (u16*)gOamData;

    if (MOD_AND(INTRO_DATA.unk_3d, 4) < 2)
    {
        yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 1;
        xPosition = BLOCK_SIZE * 2;
    }
    else
    {
        yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
        xPosition = BLOCK_SIZE * 2 - 1;
    }

    src = sIntroViewOfZebesShipOAM;
    partCount = *src++;

    for (i = 0; i < partCount; i++)
    {
        part = *src++;
        *dst++ = part;
        gOamData[i].split.y = part + yPosition;

        gOamData[i].split.objMode = 1;

        part = *src++;
        *dst++ = part;
        gOamData[i].split.x = MOD_AND(part + xPosition, 512);

        *dst++ = *src++;
        dst++;
    }

    yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
    xPosition = BLOCK_SIZE * 2;

    if ((INTRO_DATA.unk_3d & 7) < 4)
        src = sIntroViewOfZebesHeatOAM_2;
    else
        src = sIntroViewOfZebesHeatOAM_1;

    partCount += *src++;

    for (; i < partCount; i++)
    {
        part = *src++;
        *dst++ = part;
        gOamData[i].split.y = part + yPosition;

        gOamData[i].split.objMode = 1;

        part = *src++;
        *dst++ = part;
        gOamData[i].split.x = MOD_AND(part + xPosition, 512);

        *dst++ = *src++;
        dst++;
    }

    gNextOamSlot = i;
    INTRO_DATA.unk_3d++;
}

/**
 * @brief 80ccc | 12c | Handles the view of zebes part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroViewOfZebes(void)
{
    u8 ended;

    ended = FALSE;

    switch (INTRO_DATA.timer)
    {
        case 0:
            LZ77UncompVRAM(sIntroSamusShipViewOfZebesGfx, VRAM_BASE + 0x10800);
            break;

        case 1:
            LZ77UncompVRAM(sIntroViewOfZebesGfx, VRAM_BASE);
            break;

        case 2:
            LZ77UncompVRAM(sIntroViewOfZebesTileTable, VRAM_BASE + 0x8000);
            DMA_SET(3, sIntroViewOfZebesPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroViewOfZebesPal)));
            DMA_SET(3, sIntroViewOfZebesPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroViewOfZebesPal)));
            gBg0XPosition = QUARTER_BLOCK_SIZE;
            break;

        case 3:
            write16(REG_BLDALPHA, C_16_2_8(7, 9));
            INTRO_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            INTRO_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL;
            SoundPlay(SOUND_INTRO_SHIP_FLYING_DOWN);
            break;

        case 80:
            INTRO_DATA.dispcnt = 0;
            INTRO_DATA.bldcnt = 0;
            SoundFade(SOUND_INTRO_SHIP_FLYING_DOWN, 0);
            INTRO_DATA.stage++;
            ended = TRUE;
    }

    if (INTRO_DATA.unk_A++ > 4)
    {
        INTRO_DATA.unk_A = 0;
        gBg0XPosition--;
    }

    if (ended)
    {
        INTRO_DATA.unk_A = 0;
        INTRO_DATA.timer = 0;
    }
    else
        INTRO_DATA.timer++;

    IntroViewOfZebesProcessOAM();

    return FALSE;
}

/**
 * @brief 80df8 | 100 | Handles the "Defeat..." text part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroDefeat(void)
{
    u8 textResult;

    switch (INTRO_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sIntroTextAndShipFlyingInGfx, VRAM_OBJ);
            if (gLanguage != LANGUAGE_ENGLISH)
                TextStartStory(STORY_TEXT_DEFEAT);
            break;

        case 1:
            INTRO_DATA.dispcnt = DCNT_OBJ;
            break;

        case 10:
            INTRO_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            break;
    }

    if (INTRO_DATA.unk_42 == 0 && gLanguage != LANGUAGE_ENGLISH)
        INTRO_DATA.unk_42 = TextProcessStory();

    textResult = IntroProcessText(sIntroDefeatTheActions[INTRO_DATA.currentCharacter], HALF_BLOCK_SIZE);
    if (textResult == 2)
    {
        INTRO_DATA.stage++;
        INTRO_DATA.nextCharacter = 0;
        INTRO_DATA.currentCharacter = 0;
        INTRO_DATA.unk_A = 0;
        INTRO_DATA.timer = 0;
        INTRO_DATA.unk_42 = 0;
        INTRO_DATA.dispcnt = 0;
    }
    else
    {
        INTRO_DATA.pTextOamFramePointer = sIntroDefeatTheTextOAM;
        IntroTextProcessOAM();
        if (textResult != 0)
            INTRO_DATA.unk_A = 0;
        else
            INTRO_DATA.unk_A++;
    }

    return FALSE;
}

/**
 * @brief 80ef8 | 120 | Handles the mother brain part of the intro
 * 
 * @return u8 FALSE
 */
u8 IntroMotherBrain(void)
{
    u8 ended;

    ended = FALSE;

    switch (INTRO_DATA.timer)
    {
        case 0:
            LZ77UncompVRAM(sIntroFuzzGfx, VRAM_OBJ);
            break;

        case 1:
            LZ77UncompVRAM(sIntroMotherBrainGfx, VRAM_BASE);
            break;

        case 2:
            LZ77UncompVRAM(sIntroMotherBrainTileTable, VRAM_BASE + 0x8000);
            gBg0XPosition = 0;
            gBg0YPosition = 0x60;
            break;

        case 3:
            DMA_SET(3, sIntroMotherBrainPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sIntroMotherBrainPal)));
            INTRO_DATA.dispcnt = DCNT_BG0;
            SoundPlay(SOUND_INTRO_MOTHER_BRAIN_JAR);
            SoundPlay(MUSIC_INTRO_MOTHER_BRAIN);
            break;

        case 0xBF:
            SoundFade(SOUND_INTRO_MOTHER_BRAIN_JAR, 0);
            break;

        case 0xC0:
            CallbackSetVBlank(IntroFuzzVBlank);
            INTRO_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            INTRO_DATA.stage++;
            ended = TRUE;
    }

    if (INTRO_DATA.timer > 40 && gBg0YPosition != 0)
        gBg0YPosition--;

    if (ended)
        INTRO_DATA.timer = 0;
    else
        INTRO_DATA.timer++;

    return FALSE;
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
        gOamData[i].split.x = MOD_AND(part + offset, 512);

        *dst++ = *src++;
        dst++;
    }

    gNextOamSlot = i;
}

/**
 * @brief 810a0 | dc | Handles the fuzz part of the intro
 * 
 * @return u8 bool, ended
 */
u8 IntroFuzz(void)
{
    switch (INTRO_DATA.timer++)
    {
        case 32:
            INTRO_DATA.dispcnt = 0;
            break;

        case 96:
            return TRUE;

        case 0:
            SoundPlay(SOUND_INTRO_FUZZ);
            break;

        case 1:
            INTRO_DATA.dispcnt = DCNT_OBJ;
    }

    switch (INTRO_DATA.unk_A & 7)
    {
        case 0:
            DMA_SET(3, sIntroFuzzRandomValues_1, INTRO_DATA.fuzzPalette, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(INTRO_DATA.fuzzPalette)));
            break;

        case 2:
            DMA_SET(3, sIntroFuzzRandomValues_2, INTRO_DATA.fuzzPalette, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(INTRO_DATA.fuzzPalette)));
            break;

        case 4:
            DMA_SET(3, sTimeAttackPasswordCharacters, INTRO_DATA.fuzzPalette, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(INTRO_DATA.fuzzPalette)));
            break;

        case 6:
            DMA_SET(3, sArray_45fd30[1], INTRO_DATA.fuzzPalette, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(INTRO_DATA.fuzzPalette)));
            break;
    }

    INTRO_DATA.unk_A++;
    IntroFuzzProcessOAM();
    return FALSE;
}

/**
 * @brief 8117c | cc | Subroutine for the intro
 * 
 * @return u32 bool, ended
 */
u32 IntroSubroutine(void)
{
    u32 ended;

    ended = FALSE;
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
            IntroInit();
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }
            
            INTRO_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            if (gChangedInput & (KEY_A | KEY_B | KEY_START))
            {
                gGameModeSub1++;
                gGameModeSub2 = 1;
                FadeAllSounds(10);
                FadeMusic(10);
            }
            else if (sIntroSubroutinesFunctionsPointer[INTRO_DATA.stage]())
            {
                gGameModeSub1++;
                gGameModeSub2 = 0;
            }

            ResetFreeOam();
            break;
    
        case 3:
            ended = TRUE;
    }

    return ended;
}
