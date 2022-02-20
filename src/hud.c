#include "hud.h"
#include "globals.h"

void hud_update_oam(void)
{

}

void hud_update_energy_tanks(void* dst, void* normal_src, void* refill_src, u8 nbr_tanks, u8 refill_stage)
{

}

void hud_draw_energy(u8 file_number)
{

}

void hud_draw_missile_digits(u16 hundreds_place, u16 tens_place, u16 ones_place, u16 highlight_status)
{

}

void hud_draw_super_missile_digits(u16 tens_place, u16 ones_place, u16 highlight_status)
{

}

void hud_draw_power_bomb_digits(u16 tens_place, u16 ones_place, u16 highlight_status)
{

}

void hud_draw_missiles(u8 update_highlight)
{

}

void hud_draw_power_bomb(u8 update_highlight)
{

}

void hud_draw_super_missiles(u8 update_highlight)
{

}

void hud_draw_highlight(void)
{

}

void hud_draw_suitless(void)
{

}

void hud_draw(void)
{
    hud_draw_energy(0x0);
    hud_draw_missiles(FALSE);
    hud_draw_power_bomb(FALSE);
    hud_draw_super_missile_digits(FALSE);
    hud_draw_highlight();
    if (equipment.suit_type == SUIT_SUITLESS)
        hud_draw_suitless();
    hud_update_oam();
}