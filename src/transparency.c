#include "transparency.h"
#include "globals.h"

void transparency_set_room_effects_and_transparency(void)
{

}

u16 transparency_get_bg_size_flag(u8 size)
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

u16 transparency_check_is_dark_room(void)
{
    u16 flag;

    flag = 0x0;
    if (current_room_entry.bg0_prop == 0x45)
        flag = 0xFFFF;
    return flag;
}

void transparency_update_bldcnt(u8 action, u16 value)
{

}

void unk_55adc(u8 unk, u8 unk2, u8 unk3)
{

}

void unk_55b24(u8 eva, u8 evb, u8 unk, u8 fading_related)
{

}

void unk_55b9c(u8 unk, u8 unk2, u8 unk3)
{

}

void transparency_update_bldalpha(u8 eva, u8 evb, u8 unk, u8 fading_related)
{

}

void transparency_apply_new_effects(void)
{

}

void transparency_apply_new_bldalpha(struct bldalpha_data* pBldalpha)
{

}

void transparency_apply_new_bldcnt(struct bldcnt_data* pBldcnt)
{

}

void unk_55e60(void)
{

}

void unk_55f68(void)
{

}