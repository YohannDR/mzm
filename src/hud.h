#ifndef HUD_H
#define HUD_H

#include "types.h"

void hud_update_oam(void);
void hud_update_energy_tanks(void* dst, void* normal_src, void* refill_src, u8 nbr_tanks, u8 refill_stage);
void hud_draw_energy(u8 file_number);
void hud_draw_missile_digits(u16 hundreds_place, u16 tens_place, u16 ones_place, u16 highlight_status);
void hud_draw_super_missile_digits(u16 tens_place, u16 ones_place, u16 highlight_status);
void hud_draw_power_bomb_digits(u16 tens_place, u16 ones_place, u16 highlight_status);
void hud_draw_missiles(u8 update_highlight);
void hud_draw_power_bomb(u8 update_highlight);
void hud_draw_super_missiles(u8 update_highlight);
void hud_draw_highlight(void);
void hud_draw_suitless(void);
void hud_draw(void);

#endif /* HUD_H */