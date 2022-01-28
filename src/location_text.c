#include "location_text.h"
#include "globals.h"

enum location_text location_text_get_brinstar(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch (current_room)
    {
        case 0x0:
        case 0x8:
        case 0xb:
        case 0x1a:
        case 0x21:
        case 0x22:
            lt = LT_BRINSTAR;
            break;
        case 0x20:
            lt = LT_MAP_ROOM;
    }
    return lt;
}

enum location_text location_text_get_kraid(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch (current_room)
    {
        case 0x0:
            lt = LT_KRAID;
            break;
        case 0x14:
        case 0x1f:
        case 0x20:
        case 0x24:
        case 0x27:
            lt = LT_SAVE_ROOM;
            break;
        case 0x23:
            lt = LT_MAP_ROOM;
    }
    return lt;
}

enum location_text location_text_get_crateria(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch (current_room)
    {
        case 0x3:
        case 0x4:
        case 0x6:
        case 0x12:
            lt = LT_CRATERIA;
            break;
        case 0x8:
        case 0x9:
        case 0xf:
        case 0x10:
        case 0x11:
            lt = LT_CHOZO_RUINS;
            break;
        case 0x0:
            lt = LT_PLANET_ZEBES;
    }
    return lt;
}

enum location_text location_text_get_norfair(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch(current_room)
    {
        case 0x24:
        case 0x27:
        case 0x29:
        case 0x2c:
        case 0x2d:
            lt = LT_SAVE_ROOM;
            break;
        case 0x0:
        case 0x2:
        case 0x23:
        case 0x2b:
            lt = LT_NORFAIR;
            break;
        case 0x28:
            lt = LT_MAP_ROOM;
    }
    return lt;
}

enum location_text location_text_get_ridley(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch(current_room)
    {        
        case 0x1:
        case 0x14:
        case 0x18:
        case 0x19:
            lt = LT_SAVE_ROOM;
            break;            
        case 0x15:
            lt = LT_MAP_ROOM;
            break; 
        case 0x0:
        case 0x2:
            lt = LT_RIDLEY;
    }
    return lt;
}

enum location_text location_text_get_chozodia(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch(current_room)
    {        
        case 0x0:
        case 0x22:
        case 0x44:
            lt = LT_CHOZODIA;
            break;
        case 0xa:
        case 0x14:
        case 0x32:
        case 0x4e:
        case 0x5d:
            lt = LT_MOTHERSHIP;
            break;
        case 0x19:
        case 0x39:
        case 0x43:
            lt = LT_CHOZO_RUINS;
    }
    return lt;
}

enum location_text location_text_get_tourian(void)
{
    enum location_text lt;

    lt = LT_INVALID;
    switch(current_room)
    {
        case 0x6:
        case 0xb:
        case 0x14:
            lt = LT_SAVE_ROOM;
            break;
        case 0x0:
        case 0x5:
        case 0x8:
            lt = LT_TOURIAN;
    }
    return lt;
}