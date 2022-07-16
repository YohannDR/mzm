#include "transparency.h"
#include "globals.h"

void TransparencySetRoomEffectsTransparency(void)
{

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

u16 TransparencyCheckIsDarkRoom(void)
{
    u16 flag;

    flag = 0x0;
    if (gCurrentRoomEntry.BG0Prop == 0x45)
        flag = 0xFFFF;
    return flag;
}

void TransparencyUpdateBLDCNT(u8 action, u16 value)
{

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
        gBLDYData2.activeFlag &= ~TRANSPARENCY_ACTIVE;
    else
    {
        gBLDYData2.delayMax = delay;
        gBLDYData2.intensity = intensity;
        gBLDYData2.value = value;
        gBLDYData2.delay = above;
        gBLDYData2.activeFlag = TRANSPARENCY_ACTIVE;

        TransprencyApplyNewEffects();
    }*/
}

void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity)
{

}

void TransparencyUpdateBLDY(u8 value, i8 delay, u8 intensity)
{

}

void TransprencyUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity)
{

}

void TransprencyApplyNewEffects(void)
{

}

void TransprencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha)
{

}

void TransprencyApplyNewBLDY(struct BldyData* pBldy)
{

}

void unk_55e60(void)
{

}

void unk_55f68(void)
{

}