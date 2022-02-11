#include "location_text.h"
#include "globals.h"
#include "sprite.h"
#include "gba/dma.h"

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

u8 location_text_load_area_banner_gfx(void)
{
    /*u8* pGfx;
    u8 gfx_slot;
    u8 count;

    gfx_slot = 0x80;
    count = 0x0;

    if (spriteset_sprite_id[0x0] == PSPRITE_AREA_BANNER)
    {
        pGfx = spriteset_sprite_gfx_slots;
        gfx_slot = *pGfx;
    }
    else
    {
        while (spriteset_sprite_id[count] != PSPRITE_AREA_BANNER)
        {
            count++;
            if (count > 0xE) break;
        }
        pGfx = spriteset_sprite_gfx_slots + count;
        gfx_slot = *pGfx;
    }

    if (gfx_slot > 0x7)
    {
        gfx_slot = 0x7;
        sprite_load_gfx(PSPRITE_AREA_BANNER, 0x7);
        sprite_load_pal(PSPRITE_AREA_BANNER, 0x7, 0x1);
    }

    return gfx_slot;*/
}

u8 location_text_get_gfx_slot(void)
{
    u8 gfx_slot;
    enum location_text lt;

    lt = LT_INVALID;
    gfx_slot = 0xFF;

    switch (spriteset)
    {
        case 0x21:
        case 0x3B:
        case 0x58:
            lt = LT_SAVE_ROOM;
            break;

        case 0x1B:
        case 0x67:
            lt = LT_MAP_ROOM;
    }

    if (lt != LT_INVALID)
    {
        sprite_data[0x0].room_slot = lt;
        gfx_slot = location_text_load_area_banner_gfx();
        draw_location_text(lt, gfx_slot);
    }
    else
    {
        if (bit_six_of_last_door_properties != 0x0)
        {
            switch (current_area)
            {
                case AREA_BRINSTAR:
                    lt = (u8)location_text_get_brinstar();
                    break;

                case AREA_KRAID:
                    lt = (u8)location_text_get_kraid();
                    break;

                case AREA_CRATERIA:
                    lt = (u8)location_text_get_crateria();
                    break;

                case AREA_NORFAIR:
                    lt = (u8)location_text_get_norfair();
                    break;

                case AREA_RIDLEY:
                    lt = (u8)location_text_get_ridley();
                    break;

                case AREA_CHOZODIA:
                    lt = (u8)location_text_get_chozodia();
                    break;

                case AREA_TOURIAN:
                    lt = (u8)location_text_get_tourian();
            }

            if (lt != LT_INVALID)
            {
                sprite_data[0x0].room_slot = lt;
                gfx_slot = location_text_load_area_banner_gfx();
                draw_location_text(lt, gfx_slot);
                if (lt < LT_SAVE_ROOM)
                    dma_set(3, array_2f7db4, array_5000300 + gfx_slot * 0x20, 0x80000010);
            }
        }
    }

    return gfx_slot;
}