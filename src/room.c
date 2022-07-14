#include "room.h"
#include "memory.h"
#include "screen_shake.h"
#include "globals.h"
#include "event.h"
#include "bg_clip.h"

/*const struct gBG3Movement empty_gBG3Movement = {
    0x0, 0x0, 0x0
};*/

void RoomLoad(void)
{

}

void RoomLoadTileset(void)
{

}

/**
 * 56404 | 168 | Load the current room entry
 * 
 */
void RoomLoadEntry(void)
{
    /*struct RoomEntryROM* entry;
    u16 effect_y;

    entry = entry_pointers[gCurrentArea][gCurrentRoom]; // memcpy at compilation

    // Fill basic dat
    gCurrentRoomEntry.tileset = entry.tileset;
    gCurrentRoomEntry.bg0_prop = entry.bg0_prop;
    gCurrentRoomEntry.bg1_prop = entry.bg1_prop;
    gCurrentRoomEntry.bg2_prop = entry.bg2_prop;
    gCurrentRoomEntry.bg3_prop = entry.bg3_prop;
    gCurrentRoomEntry.bg3_scrolling = entry.bg3_scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;
    gCurrentRoomEntry.map_x = entry.map_x;
    gCurrentRoomEntry.map_y = entry.map_y;
    gCurrentRoomEntry.effect = entry.effect;
    gCurrentRoomEntry.music_track = entry.music_track;

    // Check for room effect
    effect_y = entry.effect_y;
    if (effect_y != 0xFF)
        gCurrentRoomEntry.effect_y = effect_y << 0x6;
    else
        gCurrentRoomEntry.effect_y = 0xFFFF;

    // gCurrentRoomEntry.effect_y = effect_y;
    gSpritesetEnrtyUsed = 0x0;
    // Set events
    gCurrentRoomEntry.first_spriteset_event = entry.first_spriteset_event;
    gCurrentRoomEntry.second_spriteset_event = entry.second_spriteset_event;
    // Check for second spriteset
    if (entry.second_spriteset_event != EVENT_NONE && EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.second_spriteset_event))
    {
        gCurrentRoomEntry.enemy_room_data = entry.pSecondSpriteData;
        gSpriteset = entry.second_spriteset;
        gSpritesetEnrtyUsed = 0x2;
    }
    // Check for first spriteset
    if (gCurrentRoomEntry.first_spriteset_event != EVENT_NONE && gSpritesetEnrtyUsed == 0x0)
    {
        if (gSpritesetEnrtyUsed != 0x0)
        {
            gCurrentRoomEntry.scrolls_flag = 0x2;
            gCurrentRoomEntry.effect_clone = EFFECT_NONE;
            gCurrentRoomEntry.bg0_size = 0x0;
            gCurrentRoomEntry.bg3_size = 0x0;
        }
        else if (EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.first_spriteset_event))
        {
            gCurrentRoomEntry.enemy_room_data = entry.pFirstSpriteData;
            gSpriteset = entry.first_spriteset;
            gSpritesetEnrtyUsed = 0x1;
        }
    }

    if (gSpritesetEnrtyUsed == 0x0)
    {
        gCurrentRoomEntry.enemy_room_data = entry.pDefaultSpriteData;
        gSpriteset = entry.default_spriteset;
    }

    gCurrentRoomEntry.scrolls_flag = 0x2;
    gCurrentRoomEntry.effect_clone = EFFECT_NONE;
    gCurrentRoomEntry.bg0_size = 0x0;
    gCurrentRoomEntry.bg3_size = 0x0;

    if (gSpritesetEnrtyUsed != 0x0 && gCurrentRoomEntry.bg0_prop == 0x44)
    {
        gWaitingSpacePiratesPosition.x = 0x8000;
        gWaitingSpacePiratesPosition.y = 0x8000;
    }

    gCurrentRoomEntry.bg3_from_bottom_flag = 0x0;
    if (gCurrentRoomEntry.bg3_prop == 0x46)
    {
        gCurrentRoomEntry.bg3_from_bottom_flag = 0x1;
        gBG0Movement.type = gBG0Movement_WATER_CLOUDS;
    }*/
}

void RoomLoadBackgrounds(void)
{

}

void RoomRemoveNeverReformBlocksAndCollectedTanks(void)
{
	// remove_never_reform_blocks();
	BGClipRemoveCollectedTanks();
}

void RoomReset(void)
{

}

void RoomSetBackgroundScrolling(void)
{

}

void RoomSetInitialTilemap(u8 bg_number)
{

}

u8 RoomRLEDecompress(u8 mode, u8* src, u8* dst)
{
    u32 len;
    u8* dest;
    u8* unk;
    u8* unk2;
    u8 unk3;
    u16 unk4;
    u32 i;

    len = 0x3000;
    if (mode == 0x0)
    {
        src++;
        len = 0x2000;
    }
    bit_fill(0x3, 0x0, dst, len, 0x10);

    len = 0x0;
    do {
        dest = dst;
        if (len != 0x0)
            dest = dst + 0x1;
        unk = src + 0x1;
        if (*src == 0x1)
        {
            unk3 = *unk;
            src += 0x2;
            while (i = unk3, i != 0x0)
            {
                if ((unk3 & 0x80) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dst += 0x2;
                    }
                }
                else
                {
                    i &= 0x7F;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        for (; i != 0x0; i--)
                        {
                            *dest = *src;
                            dest += 0x2;
                        }
                    }
                    src++;
                }
                unk3 = *src;
                src++;
            }
        }
        else
        {
            unk = src + 0x2;
            src += 0x3;
            unk4 = (*unk << 0x8 | *unk2);
            while (i = unk4, i != 0x0)
            {
                if ((unk4 & 0x8000) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dest += 0x2;
                    }
                }
                else
                {
                    i &= 0x7FFF;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        if ((unk4 & 0x7FFF) != 0x0)
                        {
                            do {
                                *dest = *src;
                                dest += 0x2;
                                i--;
                            } while(i != 0x0);
                        }
                    }
                    src++;
                }
                unk3 = *src;
                unk = src + 0x1;
                src += 0x2;
                unk4 = (unk3 << 0x8 | *unk);
            }
        }
        len++;
    } while (len < 0x2);
    return 0x0;
}

void RoomUpdateGFXInfo(void)
{

}

void RoomUpdateAnimatedGraphicsAndPalettes(void)
{

}

void RoomUpdateHatchFlashingAnimation(void)
{

}

void room_update(void)
{

}

void RoomUpdateBackgroundsPosition(void)
{
    i32 y_offset;
    i32 x_offset;
    u16 x_pos_shift;
    u16 y_pos_shift;
    u16 new_bg3_x;
    u16 new_bg3_y;

    y_offset = screen_shake_update_vertical();
    x_offset = screen_shake_update_horizontal();

    x_pos_shift = gBG1XPosition >> 0x2 & 0x1FF;
    y_pos_shift = gBG1YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[1].x = x_pos_shift + x_offset;
    gBackgroundPositions.bg[1].y = y_pos_shift + y_offset;
    x_pos_shift = gBG2XPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].x = x_pos_shift + x_offset;
    y_pos_shift = gBG2YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].y = y_pos_shift + y_offset;

    if ((gScreenShakeRelated & 0x100) != 0x0)
    {
        gBackgroundPositions.bg[0].x = (gBG0XPosition >> 0x2) + gBG0Movement.y_offset & 0x1FF;
        gBackgroundPositions.bg[0].y = (gBG0YPosition >> 0x2) + gBG0Movement.snowflakes_related & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = ((gBG0XPosition >> 0x2) + gBG0Movement.y_offset & 0x1FF) + x_offset;
        gBackgroundPositions.bg[0].y = ((gBG0YPosition >> 0x2) + gBG0Movement.snowflakes_related & 0x1FF) + x_offset;
    }

    new_bg3_x = (gBG3XPosition >> 0x2) + gBG3Movement.x_offset & 0x1FF;
    new_bg3_y = gBG3YPosition >> 0x2 & 0x1FF;

    if ((gScreenShakeRelated & 0x800) != 0x0)
    {
        gBackgroundPositions.bg[3].x = new_bg3_x;
        gBackgroundPositions.bg[3].y = new_bg3_y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = new_bg3_x + (x_offset >> 0x1);
        gBackgroundPositions.bg[3].y = new_bg3_y + (y_offset >> 0x1);
    }
}

void RoomUpdateVerticalTilemap(i8 offset)
{

}

void RoomUpdateHorizontalTilemap(i8 offset)
{

}

void RoomCheckDMA3Ended(void)
{

}