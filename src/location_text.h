#ifndef LOCATION_TEXT_H
#define LOCATION_TEXT_H

enum location_text {
    LT_BRINSTAR = 0x0,
    LT_KRAID = 0x1,
    LT_NORFAIR = 0x2,
    LT_RIDLEY = 0x3,
    LT_TOURIAN = 0x4,
    LT_CRATERIA = 0x5,
    LT_CHOZODIA = 0x6,
    LT_MOTHERSHIP = 0x7,
    LT_PLANET_ZEBES = 0x8,
    LT_SAVE_ROOM = 0x9,
    LT_RESEARCH_ROOM = 0xA,
    LT_MAP_ROOM = 0xB,
    LT_CHOZO_RUINS = 0xC,
    LT_STARSHIP = 0xD,
    LT_INVALID = 0xFF,
};

enum location_text location_text_get_brinstar(void);
enum location_text location_text_get_kraid(void);
enum location_text location_text_get_crateria(void);
enum location_text location_text_get_norfair(void);
enum location_text location_text_get_ridley(void);
enum location_text location_text_get_chozodia(void);
enum location_text location_text_get_tourian(void);
u8 location_text_load_area_banner_gfx(void);
u8 location_text_get_gfx_slot(void);

#endif /* LOCATION_TEXT_H */