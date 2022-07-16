#include "location_text.h"
#include "sprite.h"
#include "gba.h"
#include "../data/data.h"
#include "globals.h"

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
        case 0x0: // Spawn room
        case 0x8: // Elevator to kraid room
        case 0xB: // Elevator to tourian room
        case 0x1A: // Elevator to norfair room
        // Useless cases, since the spriteset is checked before and those rooms have a spriteset that result in the save room text
        // Thus this function isn't even called
        case 0x21: // Save room 1 
        case 0x22: // Save room 2
            lt = LT_BRINSTAR;
            break;
        case 0x20: // Map room
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
        case 0x0: // Main shaft/elevator to brinstar room
            lt = LT_KRAID;
            break;
        case 0x14: // Save room 1
        case 0x1F: // Save room 2
        case 0x20: // Save room 3
        case 0x24: // Save room 4
        case 0x27: // Save room 5
            lt = LT_SAVE_ROOM;
            break;
        case 0x23: // Map room
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
        case 0x3: // Elevator to brinstar room
        case 0x4: // Elevator to tourian (escape) room
        case 0x6: // Elevator to norfair room
        case 0x12: // Elevator to tourian room
            lt = LT_CRATERIA;
            break;
        case 0x8: // Chozo pillar (non extended) room
        case 0x9: // Surface after water cavern room
        case 0xF: // Surface after plasma beam room
        case 0x10: // Chozo pillar (going to extend) room
        case 0x11: // Chozo pillar (extended) room
            lt = LT_CHOZO_RUINS;
            break;
        case 0x0: // Surface (with ship) room
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
    switch(gCurrentRoom)
    {
        case 0x24: // Save room 1
        case 0x27: // Save room 2
        case 0x29: // Save room 3
        case 0x2C: // Save room 4
        case 0x2D: // Save room 5
            lt = LT_SAVE_ROOM;
            break;
        case 0x0: // Elevator to brinstar room
        case 0x2: // Elevator to crateria room
        case 0x23: // Elevator to ridley room
        case 0x2B: // Imago cocoon (with tunnel) room
            lt = LT_NORFAIR;
            break;
        case 0x28: // Map room
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
    switch(gCurrentRoom)
    {
        case 0x1: // Save room 1
        case 0x14: // Save room 2
        case 0x18: // Save room 3
        case 0x19: // Save room 4
            lt = LT_SAVE_ROOM;
            break;
        case 0x15: // Map room
            lt = LT_MAP_ROOM;
            break; 
        case 0x0: // Elevator to norfair room
        case 0x2: // Imago cocoon tunnel room
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
    switch(gCurrentRoom)
    {        
        case 0x0: // Suitless spawn room
        case 0x22: // Crateria passage with missile tank room
        case 0x44: // Crateria passage without missile tank room
            lt = LT_CHOZODIA;
            break;
        case 0xA: // Entry of mothership from crash room
        case 0x14: // Entry of mothership from glass tube room (no pirates)
        case 0x32: // Entry of mothership from hidden passage room
        case 0x4E: // Entry of mothership from shinespark puzzle room
        case 0x5D: // Entry of mothership from glass tube room (with pirates)
            lt = LT_MOTHERSHIP;
            break;
        case 0x19: // Entry of chozo ruins from glass tube room (during suitless)
        case 0x39: // Entry of chozo ruins from shinespark puzzle room
        case 0x43: // Entry of chozo ruins from glass tube room (after suitless)
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
    switch(gCurrentRoom)
    {
        case 0x6: // Save room 1
        case 0xB: // Save room 2
        case 0x14: // This room doesn't exists, very likely it's just a removed save room
            lt = LT_SAVE_ROOM;
            break;
        case 0x0: // Elevator to brinstar room
        case 0x5: // Elevator to crateria (escape) room
        case 0x8: // Elevator to crateria (destroyed) room
            lt = LT_TOURIAN;
    }
    return lt;
}

/**
 * @brief 12484 | 58 | Loads area banner graphics and palette
 * 
 * @return u8 GFX Slot
 */
u8 LocationTextLoadAreaBannerGFX(void)
{
    u8 count;
    u8 gfx_slot;

    gfx_slot = 0x80; // Default

    // Loop through sprites to try and find if an area banner is in the spriteset
    for (count = 0x0; count < 0xF; count++)
    {
        if (gSpritesetSpritesID[count] == PSPRITE_AREA_BANNER)
        {
            // Found area banner, load the gfx slot
            gfx_slot = gSpritesetGFXSlots[count];
            break;
        }
    }

    // Check if found an area banner
    if (gfx_slot > 0x7)
    {
        // Use 7 as default and load GFX/PAL
        gfx_slot = 0x7;
        SpriteLoadGFX(PSPRITE_AREA_BANNER, 0x7);
        SpriteLoadPAL(PSPRITE_AREA_BANNER, 0x7, 0x1);
    }

    return gfx_slot;
}

/**
 * 124dc | 10c | 
 * Gets the current area location text number and returns the GFX slot for it, also does some part of the area banner sprite setup 
 * 
 * @return The GFX Slot 
 */
u8 LocationTextGetGFXSlot(void)
{
    u8 gfx_slot;
    u8 lt;

    lt = LT_INVALID;
    gfx_slot = 0xFF;

    switch (gSpriteset)
    {
        case 0x21: // Normal save platform spriteset
        case 0x3B: // Chozodia save platform spriteset
        case 0x58: // Chozodia save platform with pirates spriteset
            lt = LT_SAVE_ROOM;
            break;

        case 0x1B: // Map station spriteset
        case 0x67: // Map station with pirates spriteset
            lt = LT_MAP_ROOM;
    }

    if (lt != LT_INVALID)
    {
        // Location text found with spriteset
        gSpriteData[0x0].roomSlot = lt;
        gfx_slot = LocationTextLoadAreaBannerGFX();
        // Draw location text
        draw_location_text(lt, gfx_slot);
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
                gSpriteData[0x0].roomSlot = lt;
                gfx_slot = LocationTextLoadAreaBannerGFX();
                // Draw location text
                draw_location_text(lt, gfx_slot);
                // Load different palette for some reason
                if (lt < LT_SAVE_ROOM)
                    dma_set(3, area_banner_location_text_pal, (VRAM_BASE + 0x300) + (gfx_slot * 0x20), DMA_ENABLE | 0x10);
            }
        }
    }

    return gfx_slot;
}