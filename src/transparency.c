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

void TransparencySpriteUpdateBLDY(u8 value, u8 delay, u8 intensity)
{

}

void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, u8 delay, u8 intensity)
{

}

void TransparencyUpdateBLDY(u8 value, u8 delay, u8 intensity)
{

}

void TransprencyUpdateBLDALPHA(u8 eva, u8 evb, u8 unk, u8 fading_related)
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