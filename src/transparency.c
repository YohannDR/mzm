#include "transparency.h"
#include "gba.h"

#include "data/empty_datatypes.h"

#include "constants/room.h"
#include "constants/game_state.h"

#include "structs/power_bomb_explosion.h"
#include "structs/game_state.h"
#include "structs/in_game_cutscene.h"
#include "structs/display.h"
#include "structs/samus.h"
#include "structs/room.h"

void TransparencySetRoomEffectsTransparency(void)
{
    // https://decomp.me/scratch/iOkAi

    u8 evb;
    u8 eva;
    u32 coef;
    u16 dispcnt;
    u16 bgCnt[4];

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        if (gInGameCutscene.queriedCutscene == 0)
        {
            coef = TransparencyCheckIsDarkRoom();
            if (coef != 0)
                gIoRegistersBackup.DISPCNT_NonGameplay = (gIoRegistersBackup.DISPCNT_NonGameplay | DCNT_BG0) & coef;
        }

        write16(REG_BG1CNT, gIoRegistersBackup.BG1CNT);
        write16(REG_BG2CNT, gIoRegistersBackup.BG2CNT);

        write8(0x400004a, gIoRegistersBackup.WINOUT_L);
        write8(0x4000049, gIoRegistersBackup.WININ_H);

        write16(0x4000042, gSuitFlashEffect.left << 8 | gSuitFlashEffect.right);
        write16(0x4000046, gSuitFlashEffect.top << 8 | gSuitFlashEffect.bottom);

        write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
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

    if (gCurrentRoomEntry.BG0Prop & BG_PROP_LZ77_COMPRESSED)
        bgCnt[0] = TransparencyGetBGSizeFlag(gCurrentRoomEntry.BG0Size) | 8;
    else
        bgCnt[0] = 0x4000 | 0x4;

    bgCnt[1] = 0x4000 | 0x200 | 4;
    bgCnt[2] = 0x4000 | 0x400 | 4;

    bgCnt[3] = 0x200 | 0x400 | 0x2 | 0x1;
    gCurrentRoomEntry.BG3Prop; // ?
    bgCnt[3] |= 8;
    bgCnt[3] |= TransparencyGetBGSizeFlag(gCurrentRoomEntry.BG3Size);

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
            bgCnt[0] |= 0;
            bgCnt[1] |= 1;
            bgCnt[2] |= 2;
            break;
     
        case 0x5:
        case 0x9:
        case 0xD:
        case 0x11:
        case 0x15:
        case 0x19:
        case 0x1D:
        case 0x25:
        case 0x29:
        case 0x2D:
        case 0x31:
            bgCnt[0] |= 1;
            bgCnt[1] |= 0;
            bgCnt[2] |= 2;
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
            bgCnt[0] |= 1;
            bgCnt[1] |= 0;
            bgCnt[2] |= 2;
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
            bgCnt[0] |= 2;
            bgCnt[1] |= 0;
            bgCnt[2] |= 1;
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
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = 0x10 - gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

        gDefaultTransparency.unknown_1 = 0;
    }
    else
    {
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = 0x10;
        gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = eva;

        gDefaultTransparency.unknown_1 = 1;
    }

    gDefaultTransparency.evaCoef = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
    gDefaultTransparency.evbCoef = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;

    gBldalphaData1.evaCoef = gDefaultTransparency.evaCoef;
    gBldalphaData1.evbCoef = gDefaultTransparency.evbCoef;

    write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);

    gWrittenToBLDALPHA = 0;
    gWrittenToBLDY = -1;
    gTransparencyRelated = sTransparencyRelated_Empty;

    gSuitFlashEffect.left = 0;
    gSuitFlashEffect.right = 0xF0;
    gSuitFlashEffect.top = 0;
    gSuitFlashEffect.bottom = 0xA0;
    gSuitFlashEffect.timer = 0;

    write8(0x4000048, 0);
    write16(0x4000040, 0);
    write16(0x4000044, 0);

    gIoRegistersBackup.WININ_H = 0x3F;
    gIoRegistersBackup.WINOUT_L = 0x20;

    write8(0x400004a, 0x20);
    write8(0x4000049, 0x3F);

    write16(0x4000042, 0xF0);
    write16(0x4000046, 0xA0);

    write16(REG_BG1CNT, bgCnt[1]);
    write16(REG_BG2CNT, bgCnt[2]);

    gIoRegistersBackup.BG0CNT = bgCnt[0];
    gIoRegistersBackup.unknown_12 = bgCnt[0];
    gIoRegistersBackup.BG1CNT = bgCnt[1];
    gIoRegistersBackup.BG2CNT = bgCnt[2];
    gIoRegistersBackup.BG3CNT = bgCnt[3];

    if (gCurrentRoomEntry.transparency < 8)
        gDefaultTransparency.unknown_4 = 0x3f40;
    else
        gDefaultTransparency.unknown_4 = 0x3E41;

    if (gCurrentRoomEntry.visualEffect == EFFECT_BG3_GRADIENT)
        gDefaultTransparency.unknown_4 |= 8;
    else if (gCurrentRoomEntry.visualEffect == EFFECT_BG2_GRADIENT)
        gDefaultTransparency.unknown_4 |= 4;

    if (gCurrentRoomEntry.BG0Prop == 0x12)
        gDefaultTransparency.unknown_4 &= ~1;

    TransparencyUpdateBLDCNT(0, gDefaultTransparency.unknown_4);

    gWrittenToBLDCNT = 0;

    dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_WIN1;
    coef = TransparencyCheckIsDarkRoom();
    if (coef)
        dispcnt &= coef;

    gIoRegistersBackup.DISPCNT_NonGameplay = dispcnt;
}

u16 TransparencyGetBGSizeFlag(u8 size)
{
    u16 flag;

    flag = 0x0;

    switch (size)
    {
        case 0x0:
            flag = 0x0;
            break;
            
        case 0x1:
        default:
            flag = 0x4000;
            break;

        case 0x2:
            flag = 0x8000;
            break;
        
    }

    return flag;
}

u32 TransparencyCheckIsDarkRoom(void)
{
    u16 flag;

    flag = 0x0;
    if (gCurrentRoomEntry.BG0Prop == BG_PROP_DARK_ROOM)
        flag = 0xFFFF;
    return flag;
}

/**
 * @brief 55a40 | 9c | Updates the BLDCNT register
 * 
 * @param action Action
 * @param value Value
 */
void TransparencyUpdateBLDCNT(u8 action, u16 value)
{
    u16 effects = value & (BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    gIoRegistersBackup.BLDCNT_NonGameplay = value;

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
            write16(REG_BLDCNT, gIoRegistersBackup.BLDCNT_NonGameplay);

        default:
            return;
    }

    if (gGameModeSub1 == 2 || effects != BLDCNT_BRIGHTNESS_INCREASE_EFFECT)
        gWrittenToBLDCNT = gIoRegistersBackup.BLDCNT_NonGameplay;
}

void TransparencySpriteUpdateBLDY(u8 value, i8 delay, u8 intensity)
{
    // https://decomp.me/scratch/SjDPH

    // Can't generate signed cast for delay
    /*u8 above;

    above = FALSE;
    
    if (value > 0x10)
        above = TRUE;

    if (above)
        gBLDYData2.activeFlag &= ~TRUE;
    else
    {
        gBLDYData2.delayMax = delay;
        gBLDYData2.intensity = intensity;
        gBLDYData2.value = value;
        gBLDYData2.delay = above;
        gBLDYData2.activeFlag = TRUE;

        TransparencyApplyNewEffects();
    }*/
}

void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity)
{

}

void TransparencyUpdateBLDY(u8 value, i8 delay, u8 intensity)
{

}

void TransparencyUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity)
{

}

/**
 * @brief 55c24 | b8 | Applies the new transparency effects
 * 
 */
void TransparencyApplyNewEffects(void)
{
    if (gDefaultTransparency.unknown_0 != 0)
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

    if (gTransparencyRelated.unknown_0 != 0)
        unk_55e60();
}

void TransparencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha)
{
    // https://decomp.me/scratch/6zyTC

    i32 newValue;

    newValue = FALSE;
    if (gWrittenToBLDALPHA != 0)
        return;

    if (gCurrentPowerBomb.animationState != 0)
        return;

    if (!(pBldalpha->activeFlag & 0x80))
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

void TransparencyApplyNewBLDY(struct BldyData* pBldy)
{
    // https://decomp.me/scratch/puH7O

    i32 newValue;

    newValue = FALSE;
    if (gWrittenToBLDY >= 0)
        return;

    if (gCurrentPowerBomb.animationState != 0)
        return;

    if (!(pBldy->activeFlag & 0x80))
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

void unk_55e60(void)
{

}

/**
 * @brief 55f68 | To document
 * 
 */
void unk_55f68(void)
{
    UpdateAnimatedPaletteAfterTransitionOrReload();
    ColorFadingTransferPaletteOnTransition(); // Undefined
    check_play_loading_jingle(); // Undefind
}
