#ifndef LOCATION_TEXT_H
#define LOCATION_TEXT_H

#include "types.h"

// Globals


// Defines

enum LocationTextId {
    LT_BRINSTAR,
    LT_KRAID,
    LT_NORFAIR,
    LT_RIDLEY,
    LT_TOURIAN,
    LT_CRATERIA,
    LT_CHOZODIA,
    LT_MOTHERSHIP,
    LT_PLANET_ZEBES,
    LT_SAVE_ROOM,
    LT_RESEARCH_ROOM,
    LT_MAP_ROOM,
    LT_CHOZO_RUINS,
    LT_STARSHIP,

    LT_UNUSED_7,
    LT_UNUSED_8,
    LT_UNUSED_9,
    LT_UNUSED_10,
    LT_UNUSED_11,
    LT_UNUSED_12,
    LT_UNUSED_13,
    LT_UNUSED_14,
    LT_UNUSED_15,
    LT_UNUSED_16,
    LT_UNUSED_17,
    LT_UNUSED_18,

    LT_END,

    LT_INVALID = UCHAR_MAX
};

// Functions

u8 LocationTextGetBrinstar(void);
u8 LocationTextGetKraid(void);
u8 LocationTextGetCrateria(void);
u8 LocationTextGetNorfair(void);
u8 LocationTextGetRidley(void);
u8 LocationTextGetChozodia(void);
u8 LocationTextGetTourian(void);
u8 LocationTextLoadAreaBannerGfx(void);
u8 LocationTextGetGfxSlot(void);

#endif /* LOCATION_TEXT_H */