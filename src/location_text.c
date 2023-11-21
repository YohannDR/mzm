#include "location_text.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/area_banner.h"

#include "constants/connection.h"
#include "constants/sprite.h"

#include "structs/connection.h"
#include "structs/sprite.h"
#include "structs/room.h"

/**
 * @brief 11ed8 | b8 | Gets the location text of the current room for brinstar 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetBrinstar(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 0: // Spawn room
        case 8: // Elevator to kraid room
        case 11: // Elevator to tourian room
        case 26: // Elevator to norfair room
        // Useless cases, since the spriteset is checked before and those rooms have a spriteset that result in the save room text
        // Thus this function isn't even called
        case 33: // Save room 1 
        case 34: // Save room 2
            lt = LT_BRINSTAR;
            break;

        case 32: // Map room
            lt = LT_MAP_ROOM;
    }

    return lt;
}

/**
 * @brief 11f90 | d0 | Gets the location text of the current room for kraid 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetKraid(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 0: // Main shaft/elevator to brinstar room
            lt = LT_KRAID;
            break;

        case 20: // Save room 1
        case 31: // Save room 2
        case 32: // Save room 3
        case 36: // Save room 4
        case 39: // Save room 5
            lt = LT_SAVE_ROOM;
            break;

        case 35: // Map room
            lt = LT_MAP_ROOM;
    }

    return lt;
}

/**
 * @brief 12060 | 7c | Gets the location text of the current room for crateria 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetCrateria(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 3: // Elevator to brinstar room
        case 4: // Elevator to tourian (escape) room
        case 6: // Elevator to norfair room
        case 10:
        case 11:
        case 12:
        case 13:
        case 18: // Elevator to tourian room
            lt = LT_CRATERIA;
            break;

        case 8: // Chozo pillar (non extended) room
        case 9: // Surface after water cavern room
        case 15: // Surface after plasma beam room
        case 16: // Chozo pillar (going to extend) room
        case 17: // Chozo pillar (extended) room
            lt = LT_CHOZO_RUINS;
            break;

        case 0: // Surface (with ship) room
            lt = LT_PLANET_ZEBES;
    }

    return lt;
}

/**
 * @brief 120dc | e8 | Gets the location text of the current room for norfair 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetNorfair(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 36: // Save room 1
        case 39: // Save room 2
        case 41: // Save room 3
        case 44: // Save room 4
        case 45: // Save room 5
            lt = LT_SAVE_ROOM;
            break;

        case 0: // Elevator to brinstar room
        case 2: // Elevator to crateria room
        case 35: // Elevator to ridley room
        case 43: // Imago cocoon (with tunnel) room
            lt = LT_NORFAIR;
            break;

        case 40: // Map room
            lt = LT_MAP_ROOM;
    }

    return lt;
}

/**
 * @brief 121c4 | 98 | Gets the location text of the current room for ridley 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetRidley(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 1: // Save room 1
        case 20: // Save room 2
        case 24: // Save room 3
        case 25: // Save room 4
            lt = LT_SAVE_ROOM;
            break;

        case 21: // Map room
            lt = LT_MAP_ROOM;
            break; 

        case 0: // Elevator to norfair room
        case 2: // Imago cocoon tunnel room
            lt = LT_RIDLEY;
    }

    return lt;
}

/**
 * @brief 1225c | 1a8 | Gets the location text of the current room for chozodia 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetChozodia(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {        
        case 0: // Suitless spawn room
        case 34: // Crateria passage with missile tank room
        case 68: // Crateria passage without missile tank room
            lt = LT_CHOZODIA;
            break;

        case 10: // Entry of mothership from crash room
        case 20: // Entry of mothership from glass tube room (no pirates)
        case 50: // Entry of mothership from hidden passage room
        case 78: // Entry of mothership from shinespark puzzle room
        case 93: // Entry of mothership from glass tube room (with pirates)
            lt = LT_MOTHERSHIP;
            break;

        case 25: // Entry of chozo ruins from glass tube room (during suitless)
        case 57: // Entry of chozo ruins from shinespark puzzle room
        case 67: // Entry of chozo ruins from glass tube room (after suitless)
            lt = LT_CHOZO_RUINS;
    }

    return lt;
}

/**
 * @brief 12404 | 80 | Gets the location text of the current room for tourian 
 * 
 * @return u8 Location text
 */
u8 LocationTextGetTourian(void)
{
    u8 lt;

    lt = LT_INVALID;
    switch (gCurrentRoom)
    {
        case 6: // Save room 1
        case 11: // Save room 2
        case 20: // This room doesn't exists, very likely it's just a removed save room
            lt = LT_SAVE_ROOM;
            break;

        case 0: // Elevator to brinstar room
        case 5: // Elevator to crateria (escape) room
        case 8: // Elevator to crateria (destroyed) room
            lt = LT_TOURIAN;
    }

    return lt;
}

/**
 * @brief 12484 | 58 | Loads area banner graphics and palette
 * 
 * @return u8 Gfx Slot
 */
u8 LocationTextLoadAreaBannerGfx(void)
{
    u8 count;
    u8 gfxSlot;

    gfxSlot = 0x80; // Default

    // Loop through sprites to try and find if an area banner is in the spriteset
    for (count = 0; count < MAX_AMOUNT_OF_SPRITE_TYPES; count++)
    {
        if (gSpritesetSpritesID[count] == PSPRITE_AREA_BANNER)
        {
            // Found area banner, load the gfx slot
            gfxSlot = gSpritesetGfxSlots[count];
            break;
        }
    }

    // Check if found an area banner
    if (gfxSlot > 0x7)
    {
        // Use 7 as default and load Gfx/PAL
        gfxSlot = 7;
        SpriteLoadGfx(PSPRITE_AREA_BANNER, 7);
        SpriteLoadPAL(PSPRITE_AREA_BANNER, 7, 1);
    }

    return gfxSlot;
}

/**
 * 124dc | 10c | 
 * Gets the current area location text number and returns the Gfx slot for it, also does some part of the area banner sprite setup 
 * 
 * @return The Gfx Slot 
 */
u8 LocationTextGetGfxSlot(void)
{
    u8 gfxSlot;
    u8 lt;

    lt = LT_INVALID;
    gfxSlot = UCHAR_MAX;

    switch (gSpriteset)
    {
        case 33: // Normal save platform spriteset
        case 59: // Chozodia save platform spriteset
        case 88: // Chozodia save platform with pirates spriteset
            lt = LT_SAVE_ROOM;
            break;

        case 27: // Map station spriteset
        case 103: // Map station with pirates spriteset
            lt = LT_MAP_ROOM;
    }

    if (lt != LT_INVALID)
    {
        // Location text found with spriteset
        gSpriteData[0].roomSlot = lt;
        gfxSlot = LocationTextLoadAreaBannerGfx();
        // Draw location text
        TextDrawlocation(lt, gfxSlot);
    }
    else
    {
        // Bit 6 of last door properties
        if (gDisplayLocationText)
        {
            // Get location text for current area
            switch (gCurrentArea)
            {
                case AREA_BRINSTAR:
                    lt = LocationTextGetBrinstar();
                    break;

                case AREA_KRAID:
                    lt = LocationTextGetKraid();
                    break;

                case AREA_CRATERIA:
                    lt = LocationTextGetCrateria();
                    break;

                case AREA_NORFAIR:
                    lt = LocationTextGetNorfair();
                    break;

                case AREA_RIDLEY:
                    lt = LocationTextGetRidley();
                    break;

                case AREA_CHOZODIA:
                    lt = LocationTextGetChozodia();
                    break;

                case AREA_TOURIAN:
                    lt = LocationTextGetTourian();
            }

            if (lt != LT_INVALID)
            {
                // If found
                gSpriteData[0].roomSlot = lt;
                gfxSlot = LocationTextLoadAreaBannerGfx();

                // Draw location text
                TextDrawlocation(lt, gfxSlot);

                // Load different palette for some reason
                if (lt < LT_SAVE_ROOM)
                    DMA_SET(3, sAreaBannerLocationTextPAL, (PALRAM_BASE + 0x300) + (gfxSlot * 0x20), C_32_2_16(DMA_ENABLE, 16));
            }
        }
    }

    return gfxSlot;
}
