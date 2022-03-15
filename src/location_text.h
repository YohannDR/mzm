#ifndef LOCATION_TEXT_H
#define LOCATION_TEXT_H

#include "types.h"

#define LT_BRINSTAR 0x0
#define LT_KRAID 0x1
#define LT_NORFAIR 0x2
#define LT_RIDLEY 0x3
#define LT_TOURIAN 0x4
#define LT_CRATERIA 0x5
#define LT_CHOZODIA 0x6
#define LT_MOTHERSHIP 0x7
#define LT_PLANET_ZEBES 0x8
#define LT_SAVE_ROOM 0x9
#define LT_RESEARCH_ROOM 0xA
#define LT_MAP_ROOM 0xB
#define LT_CHOZO_RUINS 0xC
#define LT_STARSHIP 0xD
#define LT_INVALID 0xFF

u8 location_text_get_brinstar(void);
u8 location_text_get_kraid(void);
u8 location_text_get_crateria(void);
u8 location_text_get_norfair(void);
u8 location_text_get_ridley(void);
u8 location_text_get_chozodia(void);
u8 location_text_get_tourian(void);
u8 location_text_load_area_banner_gfx(void);
u8 location_text_get_gfx_slot(void);

#endif /* LOCATION_TEXT_H */