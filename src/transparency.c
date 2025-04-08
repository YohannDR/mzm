#include "transparency.h"
#include "gba.h"

#include "data/empty_datatypes.h"

#include "constants/room.h"
#include "constants/game_state.h"
#include "constants/power_bomb_explosion.h"

#include "structs/power_bomb_explosion.h"
#include "structs/game_state.h"
#include "structs/in_game_cutscene.h"
#include "structs/display.h"
#include "structs/samus.h"
#include "structs/room.h"

/**
 * @brief 554ac | 54c | Sets the room transparency and backgrounds effects
 * 
 */
void TransparencySetRoomEffectsTransparency(void)
{
    u8 evb;
    u8 eva;
    u32 coef;
    u16 dispcnt;
    u16 dcnt;
    u16 bgCnt[4];

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        if (gInGameCutscene.queuedCutscene == 0)
        {
            coef = TransparencyCheckIsDarkRoom();
            if (coef != 0)
            {
                dcnt = DCNT_BG0 | gIoRegistersBackup.Dispcnt_NonGameplay;
                gIoRegistersBackup.Dispcnt_NonGameplay = dcnt & coef;
            }
        }

        write16(REG_BG1CNT, gIoRegistersBackup.BG1CNT);
        write16(REG_BG2CNT, gIoRegistersBackup.BG2CNT);

        write8(REG_WINOUT, gIoRegistersBackup.WINOUT_L);
        write8(REG_WININ + 1, gIoRegistersBackup.WININ_H);

        write16(REG_WIN1H, C_16_2_8(gSuitFlashEffect.left, gSuitFlashEffect.right));
        write16(REG_WIN1V, C_16_2_8(gSuitFlashEffect.top, gSuitFlashEffect.bottom));

        write16(REG_BLDALPHA, C_16_2_8(gIoRegistersBackup.BLDALPHA_NonGameplay_EVB, gIoRegistersBackup.BLDALPHA_NonGameplay_EVA));
        return;
    }

    bgCnt[0] = 0;
    bgCnt[1] = 0;
    bgCnt[2] = 0;
    bgCnt[3] = 0;

    gSamusOnTopOfBackgrounds = FALSE;

    gBldalphaData1 = sBldalphaData_Empty;
    gBldalphaData2 = sBldalphaData_Empty;
    gDefaultTransparency = sDefaultTransparency_Empty;
    gBLDYData1 = sBldyData_Empty;
    gBLDYData2 = sBldyData_Empty;

    if (gCurrentRoomEntry.Bg0Prop & BG_PROP_LZ77_COMPRESSED)
        bgCnt[0] = TransparencyGetBgSizeFlag(gCurrentRoomEntry.Bg0Size) | 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT;
    else
        bgCnt[0] = CREATE_BGCNT(1, 0, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);

    bgCnt[1] = CREATE_BGCNT(1, 2, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);
    bgCnt[2] = CREATE_BGCNT(1, 4, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256);
    bgCnt[3] = CREATE_BGCNT(0, 6, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256);

    switch (gCurrentRoomEntry.Bg3Prop)
    {
        case 0: // The value of this case doesn't matter
            bgCnt[3] |= 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT;
            break;

        default:
            bgCnt[3] |= 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT;
    }

    bgCnt[3] = TransparencyGetBgSizeFlag(gCurrentRoomEntry.Bg3Size) | bgCnt[3];

    switch (gCurrentRoomEntry.transparency)
    {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x8:
        case 0xC:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
        case 0x20:
        case 0x24:
        case 0x28:
        case 0x2C:
        case 0x30:
        default:
            bgCnt[0] |= BGCNT_HIGH_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            break;
     
        case 0x5:
        case 0x9:
        case 0xD:
        case 0x11:
        case 0x15:
        case 0x19:
        case 0x1D:
        case 0x21:
        case 0x25:
        case 0x29:
        case 0x2D:
        case 0x31:
            bgCnt[0] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            break;

        case 0x6:
        case 0xA:
        case 0xE:
        case 0x12:
        case 0x16:
        case 0x1A:
        case 0x1E:
        case 0x22:
        case 0x26:
        case 0x2A:
        case 0x2E:
        case 0x32:
            bgCnt[0] |= BGCNT_HIGH_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_LOW_MID_PRIORITY;
            gSamusOnTopOfBackgrounds = TRUE;
            break;

        case 0x7:
        case 0xB:
        case 0xF:
        case 0x13:
        case 0x17:
        case 0x1B:
        case 0x1F:
        case 0x23:
        case 0x27:
        case 0x2B:
        case 0x2F:
        case 0x33:
            bgCnt[0] |= BGCNT_LOW_MID_PRIORITY;
            bgCnt[1] |= BGCNT_HIGH_PRIORITY;
            bgCnt[2] |= BGCNT_HIGH_MID_PRIORITY;
            gSamusOnTopOfBackgrounds = TRUE;
            break;
    }
    
    eva = 0;
    evb = 0;

    switch (gCurrentRoomEntry.transparency)
    {
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
            evb = 0;
            break;

        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
            evb = 3;
            break;

        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
            evb = 6;
            break;

        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
            evb = 9;
            break;

        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            evb = 11;
            break;

        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
            evb = 13;
            break;

        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
            evb = 16;
            break;

        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
            eva = 7;
            break;

        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
            eva = 10;
            break;

        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            eva = 13;
            break;

        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            eva = 16;
            break;
    }

    if (eva == 0)
    {
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = evb;
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = 16 - gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

        gDefaultTransparency.unk_1 = 0;
    }
    else
    {
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = 16;
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = eva;

        gDefaultTransparency.unk_1 = 1;
    }

    gDefaultTransparency.evaCoef = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
    gDefaultTransparency.evbCoef = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

    gBldalphaData1.evaCoef = gDefaultTransparency.evaCoef;
    gBldalphaData1.evbCoef = gDefaultTransparency.evbCoef;

    write16(REG_BLDALPHA, C_16_2_8(gIoRegistersBackup.BLDALPHA_NonGameplay_EVB, gIoRegistersBackup.BLDALPHA_NonGameplay_EVA));

    gWrittenToBLDALPHA = 0;
    gWrittenToBLDY = -1;
    gTransparencyRelated = sTransparencyRelated_Empty;

    gSuitFlashEffect.left = 0;
    gSuitFlashEffect.right = SCREEN_SIZE_X;
    gSuitFlashEffect.top = 0;
    gSuitFlashEffect.bottom = SCREEN_SIZE_Y;
    gSuitFlashEffect.timer = 0;

    write8(REG_WININ, 0);
    write16(REG_WIN0H, 0);
    write16(REG_WIN0V, 0);

    gIoRegistersBackup.WININ_H = 0x3F;
    gIoRegistersBackup.WINOUT_L = 0x20;

    write8(REG_WINOUT, 0x20);
    write8(REG_WININ + 1, 0x3F);

    write16(REG_WIN1H, SCREEN_SIZE_X);
    write16(REG_WIN1V, SCREEN_SIZE_Y);

    write16(REG_BG1CNT, bgCnt[1]);
    write16(REG_BG2CNT, bgCnt[2]);

    gIoRegistersBackup.BG0CNT = bgCnt[0];
    gIoRegistersBackup.unk_12 = bgCnt[0];
    gIoRegistersBackup.BG1CNT = bgCnt[1];
    gIoRegistersBackup.BG2CNT = bgCnt[2];
    gIoRegistersBackup.BG3CNT = bgCnt[3];

    if (gCurrentRoomEntry.transparency < 8)
    {
        gDefaultTransparency.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
    }
    else
    {
        gDefaultTransparency.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
        gDefaultTransparency.bldcnt &= ~BLDCNT_BG0_SECOND_TARGET_PIXEL;
    }

    if (gCurrentRoomEntry.visualEffect == EFFECT_BG3_GRADIENT)
        gDefaultTransparency.bldcnt |= BLDCNT_BG3_FIRST_TARGET_PIXEL;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_BG2_GRADIENT)
        gDefaultTransparency.bldcnt |= BLDCNT_BG2_FIRST_TARGET_PIXEL;

    if (gCurrentRoomEntry.Bg0Prop == BG_PROP_DISABLE_TRANSPARENCY)
        gDefaultTransparency.bldcnt &= ~BLDCNT_BG0_FIRST_TARGET_PIXEL;

    TransparencyUpdateBldcnt(0, gDefaultTransparency.bldcnt);

    gWrittenToBLDCNT = 0;

    dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_WIN1;
    coef = TransparencyCheckIsDarkRoom();
    if (coef)
        dispcnt &= coef;

    gIoRegistersBackup.Dispcnt_NonGameplay = dispcnt;
}

u16 TransparencyGetBgSizeFlag(u8 size)
{
    u16 flag;

    flag = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT;

    switch (size)
    {
        case BGCNT_SIZE_256x256:
            flag = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT;
            break;
            
        case BGCNT_SIZE_512x256:
        default:
            flag = BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT;
            break;

        case BGCNT_SIZE_256x512:
            flag = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT;
            break;
        
    }

    return flag;
}

u32 TransparencyCheckIsDarkRoom(void)
{
    u16 flag;

    flag = 0;
    if (gCurrentRoomEntry.Bg0Prop == BG_PROP_DARK_ROOM)
        flag = USHORT_MAX;

    return flag;
}

/**
 * @brief 55a40 | 9c | Updates the BLDCNT register
 * 
 * @param action Action
 * @param value Value
 */
void TransparencyUpdateBldcnt(u8 action, u16 value)
{
    u16 effects;

    effects = value & (BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    gIoRegistersBackup.Bldcnt_NonGameplay = value;

    switch (action)
    {
        case 0:
            if (effects == BLDCNT_ALPHA_BLENDING_EFFECT)
                gBldalphaData1.BLDCNT = value;
            else
                gBLDYData1.BLDCNT = value;
            break;

        case 1:
            if (effects == BLDCNT_ALPHA_BLENDING_EFFECT)
                gBldalphaData2.BLDCNT = value;
            else
                gBLDYData2.BLDCNT = value;
            break;

        case 2:
            if (effects == BLDCNT_BRIGHTNESS_INCREASE_EFFECT)
                return;

        case 3:
            write16(REG_BLDCNT, gIoRegistersBackup.Bldcnt_NonGameplay);

        default:
            return;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING || effects != BLDCNT_BRIGHTNESS_INCREASE_EFFECT)
        gWrittenToBLDCNT = gIoRegistersBackup.Bldcnt_NonGameplay;
}

/**
 * @brief 55adc | 48 | Starts a bldy sprite effect
 * 
 * @param value Requested value
 * @param delay Delay between increments
 * @param intensity Intensity
 */
void TransparencySpriteUpdateBLDY(u8 value, u32 delay, u32 intensity)
{
    u8 above;
    s32 _delay;
    s32 _intensity;

    _delay = (s8)delay;
    _intensity = (u8)intensity;
    above = FALSE;
    
    if (value > 16)
        above = TRUE;

    if (above)
    {
        gBLDYData2.activeFlag &= ~TRUE;
        return;
    }
    
    gBLDYData2.delayMax = _delay;
    gBLDYData2.intensity = _intensity;
    gBLDYData2.value = value;
    gBLDYData2.delay = above;
    gBLDYData2.activeFlag = TRUE;

    TransparencyApplyNewEffects();
}

/**
 * @brief 55b24 | 78 | Queues a bldalpha update (for sprites)
 * 
 * @param eva Eva coefficient
 * @param evb Evb coefficient
 * @param delay Delay
 * @param intensity Intensity
 */
void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, s32 delay, u32 intensity)
{
    u32 invalid;
    s32 _delay;
    u32 _intensity;

    _delay = (s8)delay;
    _intensity = (u8)intensity;

    if (eva > 16)
        invalid = TRUE;
    else
        invalid = FALSE;

    if (evb > 16)
        invalid++;

    if (invalid)
    {
        gDefaultTransparency.unk_1 = (gBldalphaData1.evaCoef + gBldalphaData1.evbCoef != 16);
        return;
    }

    gBldalphaData2.delayMax = _delay;
    gBldalphaData2.intensity = _intensity;
    gBldalphaData2.evaCoef = eva;
    gBldalphaData2.evbCoef = evb;
    gBldalphaData2.delay = 0;

    gDefaultTransparency.unk_1 = (eva + evb != 16);
    gBldalphaData2.activeFlag = TRUE;

    TransparencyApplyNewEffects();
}

/**
 * @brief 55b9c | 34 | Queues a bldy update
 * 
 * @param value Destination value
 * @param delay Delay
 * @param intensity Intensity
 */
void TransparencyUpdateBLDY(u8 value, s32 delay, u32 intensity)
{
    u8 invalid;
    s32 _delay;
    u32 _intensity;

    _delay = (s8)delay;
    _intensity = (u8)intensity;

    if (value > 16)
        invalid = TRUE;
    else
        invalid = FALSE;

    if (invalid)
        return;

    gBLDYData1.delayMax = _delay;
    gBLDYData1.intensity = _intensity;
    gBLDYData1.value = value;
    gBLDYData1.delay = 0;
    gBLDYData1.activeFlag = TRUE;
}

/**
 * @brief 55bd0 | 54 | Queues a bldalpha update
 * 
 * @param eva Eva coefficient
 * @param evb Evb coefficient
 * @param delay Delay
 * @param intensity Intensity
 */
void TransparencyUpdateBLDALPHA(u8 eva, u8 evb, s8 delay, u32 intensity)
{
    u32 invalid;
    s32 _delay;
    u32 _intensity;

    _delay = (s8)delay;
    _intensity = (u8)intensity;

    if (eva > 16)
        invalid = TRUE;
    else
        invalid = FALSE;

    if (evb > 16)
        invalid++;

    if (invalid)
        return;

    gBldalphaData1.delayMax = _delay;
    gBldalphaData1.intensity = _intensity;
    gBldalphaData1.evaCoef = eva;
    gBldalphaData1.evbCoef = evb;
    gBldalphaData1.delay = 0;

    gDefaultTransparency.unk_1 = (eva + evb != 16);
    gBldalphaData1.activeFlag = TRUE;
}

/**
 * @brief 55c24 | b8 | Applies the new transparency effects
 * 
 */
void TransparencyApplyNewEffects(void)
{
    if (gDefaultTransparency.unk_0 != 0)
    {
        gBLDYData2.activeFlag &= TRUE;
        gBldalphaData2.activeFlag &= TRUE;
        gBLDYData1.activeFlag &= TRUE;
        gBldalphaData1.activeFlag &= TRUE;
    }
    else
    {
        if (gBLDYData2.activeFlag & TRUE)
            TransparencyApplyNewBLDY(&gBLDYData2);
        else if (gBldalphaData2.activeFlag & TRUE)
            TransparencyApplyNewBLDALPHA(&gBldalphaData2);
        else if (gBLDYData1.activeFlag & TRUE)
            TransparencyApplyNewBLDY(&gBLDYData1);
        else if (gBldalphaData1.activeFlag & TRUE)
            TransparencyApplyNewBLDALPHA(&gBldalphaData1);
    }

    if (gTransparencyRelated.unk_0 != 0)
        unk_55e60();
}

/**
 * @brief 55cdc | d8 | Applies the bldalpha effect 
 * 
 * @param pBldy Bldalpha data pointer
 */
void TransparencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha)
{
    s32 newValue;

    newValue = FALSE;
    if (gWrittenToBLDALPHA != 0)
        newValue = TRUE;
    else if (gCurrentPowerBomb.animationState != PB_STATE_NONE)
        newValue = TRUE;
    else if (pBldalpha->activeFlag & 0x80)
        newValue = TRUE;

    if (newValue)
        return;

    if (pBldalpha->delay != 0)
    {
        pBldalpha->delay--;
        return;
    }

    pBldalpha->delay = pBldalpha->delayMax;
    if (pBldalpha->intensity == 0)
        pBldalpha->intensity = 1;

    if (pBldalpha->evaCoef != gIoRegistersBackup.BLDALPHA_NonGameplay_EVA)
    {
        newValue = pBldalpha->intensity;
        if (pBldalpha->evaCoef < gIoRegistersBackup.BLDALPHA_NonGameplay_EVA)
        {
            newValue = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA - newValue;
            if (newValue < pBldalpha->evaCoef)
                newValue = pBldalpha->evaCoef;
        }
        else
        {
            newValue = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA + newValue;
            if (newValue > pBldalpha->evaCoef)
                newValue = pBldalpha->evaCoef;
        }

        gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = newValue;
        newValue = TRUE;
    }

    if (pBldalpha->evbCoef != gIoRegistersBackup.BLDALPHA_NonGameplay_EVB)
    {
        newValue = pBldalpha->intensity;
        if (pBldalpha->evbCoef < gIoRegistersBackup.BLDALPHA_NonGameplay_EVB)
        {
            newValue = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB - newValue;
            if (newValue < pBldalpha->evbCoef)
                newValue = pBldalpha->evbCoef;
        }
        else
        {
            newValue = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB + newValue;
            if (newValue > pBldalpha->evbCoef)
                newValue = pBldalpha->evbCoef;
        }

        gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = newValue;
        newValue = TRUE;
    }

    if (newValue)
    {
        gWrittenToBLDALPHA = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
        if (pBldalpha->activeFlag == TRUE)
        {
            pBldalpha->activeFlag |= 2;
            gWrittenToBLDCNT = pBldalpha->BLDCNT;
        }
    }
    else
        pBldalpha->activeFlag = FALSE;
}

/**
 * @brief 55db4 | ac | Applies the bldy effect 
 * 
 * @param pBldy Bldy data pointer
 */
void TransparencyApplyNewBLDY(struct BldyData* pBldy)
{
    s32 newValue;

    newValue = FALSE;
    if (gWrittenToBLDY >= 0)
        newValue = TRUE;
    else if (gCurrentPowerBomb.animationState != PB_STATE_NONE)
        newValue = TRUE;
    else if (pBldy->activeFlag & 0x80)
        newValue = TRUE;

    if (newValue)
        return;

    if (pBldy->delay != 0)
    {
        pBldy->delay--;
        return;
    }

    pBldy->delay = pBldy->delayMax;
    if (pBldy->intensity == 0)
        pBldy->intensity = 1;

    if (pBldy->value != gIoRegistersBackup.BLDY_NonGameplay)
    {
        newValue = pBldy->intensity;
        if (pBldy->value < gIoRegistersBackup.BLDY_NonGameplay)
        {
            newValue = gIoRegistersBackup.BLDY_NonGameplay - newValue;
            if (newValue < pBldy->value)
                newValue = pBldy->value;
        }
        else
        {
            newValue = gIoRegistersBackup.BLDY_NonGameplay + newValue;
            if (newValue > pBldy->value)
                newValue = pBldy->value;
        }
    
        gIoRegistersBackup.BLDY_NonGameplay = newValue;
        newValue = TRUE;
    }

    if (newValue)
    {
        gWrittenToBLDY = gIoRegistersBackup.BLDY_NonGameplay;
        if (pBldy->activeFlag == TRUE)
        {
            pBldy->activeFlag |= 2;
            gWrittenToBLDCNT = pBldy->BLDCNT;
        }
    }
    else
        pBldy->activeFlag = FALSE;
}

/**
 * @brief 55e60 | 108 | To document
 * 
 */
void unk_55e60(void)
{
    s32 coef;
    s32 eva;
    s32 evb;

    switch (gCurrentPowerBomb.animationState)
    {
        case PB_STATE_UNK_1:
            gTransparencyRelated.unk_2 = 0;
            gTransparencyRelated.unk_1 = 2;

            coef = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB + 2;
            gWrittenToBLDALPHA = C_16_2_8(coef, 16 - coef);
            break;

        case PB_STATE_NONE:
            gTransparencyRelated.unk_2++;
            if (gTransparencyRelated.unk_0 != 2)
            {
                if (gTransparencyRelated.unk_2 < 20)
                    break;

                gTransparencyRelated.unk_2 = 0;
                gTransparencyRelated.unk_1++;
                gTransparencyRelated.unk_1 &= 7;

                coef = gTransparencyRelated.unk_1 & 3;
                if (gTransparencyRelated.unk_1 & 3)
                {
                    if (coef & 1)
                        coef = 1;
                    else
                        coef = 2;
                }

                if (gTransparencyRelated.unk_1 & 4)
                    coef = -coef;

                eva = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
                evb = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

                evb += coef;
                if (evb < 0)
                    evb = 0;
                else if (evb > 16)
                    evb = 16;

                eva -= coef;
                if (eva < 0)
                    eva = 0;
                else if (eva > 16)
                    eva = 16;

                gWrittenToBLDALPHA = C_16_2_8(evb, eva);
            }
            else
            {
                if (gTransparencyRelated.unk_2 < 2)
                    break;

                gTransparencyRelated.unk_2 = 0;

                gTransparencyRelated.unk_1++;
                if (gTransparencyRelated.unk_1 > 3)
                    gTransparencyRelated.unk_1 = 0;

                coef = gTransparencyRelated.unk_1;
                if (gTransparencyRelated.unk_1 > 2)
                    coef = 4 - coef;

                coef = -coef;

                eva = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
                evb = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

                evb += coef;
                if (evb < 0)
                    evb = 0;
                else if (evb > 16)
                    evb = 16;

                eva -= coef;
                if (eva < 0)
                    eva = 0;
                else if (eva > 16)
                    eva = 16;

                gWrittenToBLDALPHA = C_16_2_8(evb, eva);
            }
            break;
    }
}

/**
 * @brief 55f68 | Update animated and faded palette and music on transition
 * 
 */
void unk_55f68(void)
{
    UpdateAnimatedPaletteAfterTransitionOrReload();
    ColorFadingTransferPaletteOnTransition();
    CheckPlayLoadingJingle();
}
