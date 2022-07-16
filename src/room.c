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
    u16 effectY;

    entry = entry_pointers[gCurrentArea][gCurrentRoom]; // memcpy at compilation

    // Fill basic dat
    gCurrentRoomEntry.tileset = entry.tileset;
    gCurrentRoomEntry.BG0Prop = entry.BG0Prop;
    gCurrentRoomEntry.BG1Prop = entry.BG1Prop;
    gCurrentRoomEntry.BG2Prop = entry.BG2Prop;
    gCurrentRoomEntry.BG3Prop = entry.BG3Prop;
    gCurrentRoomEntry.BG3Scrolling = entry.BG3Scrolling;
    gCurrentRoomEntry.transparency = entry.transparency;
    gCurrentRoomEntry.mapX = entry.mapX;
    gCurrentRoomEntry.mapY = entry.mapY;
    gCurrentRoomEntry.effect = entry.effect;
    gCurrentRoomEntry.musicTrack = entry.musicTrack;

    // Check for room effect
    effectY = entry.effectY;
    if (effectY != 0xFF)
        gCurrentRoomEntry.effectY = effectY << 0x6;
    else
        gCurrentRoomEntry.effectY = 0xFFFF;

    // gCurrentRoomEntry.effectY = effectY;
    gSpritesetEnrtyUsed = 0x0;
    // Set events
    gCurrentRoomEntry.firstSpritesetEvent = entry.firstSpritesetEvent;
    gCurrentRoomEntry.secondSpritesetEvent = entry.secondSpritesetEvent;
    // Check for second spriteset
    if (entry.secondSpritesetEvent != EVENT_NONE && EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.secondSpritesetEvent))
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pSecondSpriteData;
        gSpriteset = entry.second_spriteset;
        gSpritesetEnrtyUsed = 0x2;
    }
    // Check for first spriteset
    if (gCurrentRoomEntry.firstSpritesetEvent != EVENT_NONE && gSpritesetEnrtyUsed == 0x0)
    {
        if (gSpritesetEnrtyUsed != 0x0)
        {
            gCurrentRoomEntry.scrollsFlag = 0x2;
            gCurrentRoomEntry.visualEffect = EFFECT_NONE;
            gCurrentRoomEntry.BG0Size = 0x0;
            gCurrentRoomEntry.BG3Size = 0x0;
        }
        else if (EventFunction(EVENT_ACTION_CHECKING, gCurrentRoomEntry.firstSpritesetEvent))
        {
            gCurrentRoomEntry.pEnemyRoomData = entry.pFirstSpriteData;
            gSpriteset = entry.firstSpriteset;
            gSpritesetEnrtyUsed = 0x1;
        }
    }

    if (gSpritesetEnrtyUsed == 0x0)
    {
        gCurrentRoomEntry.pEnemyRoomData = entry.pDefaultSpriteData;
        gSpriteset = entry.defaultSpriteset;
    }

    gCurrentRoomEntry.scrollsFlag = 0x2;
    gCurrentRoomEntry.visualEffect = EFFECT_NONE;
    gCurrentRoomEntry.BG0Size = 0x0;
    gCurrentRoomEntry.BG3Size = 0x0;

    if (gSpritesetEnrtyUsed != 0x0 && gCurrentRoomEntry.BG0Prop == 0x44)
    {
        gWaitingSpacePiratesPosition.x = 0x8000;
        gWaitingSpacePiratesPosition.y = 0x8000;
    }

    gCurrentRoomEntry.BG3FromBottomFlag = 0x0;
    if (gCurrentRoomEntry.BG3Prop == 0x46)
    {
        gCurrentRoomEntry.BG3FromBottomFlag = 0x1;
        gBG0Movement.type = BG0MOVEMENT_WATER_CLOUDS;
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

u8 RoomRLEDecompress(u8 mode, u8* pSrc, u8* pDst)
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
        pSrc++;
        len = 0x2000;
    }
    bit_fill(0x3, 0x0, pDst, len, 0x10);

    len = 0x0;
    do {
        dest = pDst;
        if (len != 0x0)
            dest = pDst + 0x1;
        unk = pSrc + 0x1;
        if (*pSrc == 0x1)
        {
            unk3 = *unk;
            pSrc += 0x2;
            while (i = unk3, i != 0x0)
            {
                if ((unk3 & 0x80) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *pSrc;
                        pSrc++;
                        pDst += 0x2;
                    }
                }
                else
                {
                    i &= 0x7F;
                    if (*pSrc == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        for (; i != 0x0; i--)
                        {
                            *dest = *pSrc;
                            dest += 0x2;
                        }
                    }
                    pSrc++;
                }
                unk3 = *pSrc;
                pSrc++;
            }
        }
        else
        {
            unk = pSrc + 0x2;
            pSrc += 0x3;
            unk4 = (*unk << 0x8 | *unk2);
            while (i = unk4, i != 0x0)
            {
                if ((unk4 & 0x8000) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *pSrc;
                        pSrc++;
                        dest += 0x2;
                    }
                }
                else
                {
                    i &= 0x7FFF;
                    if (*pSrc == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        if ((unk4 & 0x7FFF) != 0x0)
                        {
                            do {
                                *dest = *pSrc;
                                dest += 0x2;
                                i--;
                            } while(i != 0x0);
                        }
                    }
                    pSrc++;
                }
                unk3 = *pSrc;
                unk = pSrc + 0x1;
                pSrc += 0x2;
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
    i32 yOffset;
    i32 xOffset;
    u16 x_pos_shift;
    u16 y_pos_shift;
    u16 new_bg3_x;
    u16 new_bg3_y;

    yOffset = ScreenShakeUpdateVertical();
    xOffset = ScreenShakeUpdateHorizontal();

    x_pos_shift = gBG1XPosition >> 0x2 & 0x1FF;
    y_pos_shift = gBG1YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[1].x = x_pos_shift + xOffset;
    gBackgroundPositions.bg[1].y = y_pos_shift + yOffset;
    x_pos_shift = gBG2XPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].x = x_pos_shift + xOffset;
    y_pos_shift = gBG2YPosition >> 0x2 & 0x1FF;
    gBackgroundPositions.bg[2].y = y_pos_shift + yOffset;

    if ((gScreenShakeRelated & 0x100) != 0x0)
    {
        gBackgroundPositions.bg[0].x = (gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF;
        gBackgroundPositions.bg[0].y = (gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF;
    }
    else
    {
        gBackgroundPositions.bg[0].x = ((gBG0XPosition >> 0x2) + gBG0Movement.yOffset & 0x1FF) + xOffset;
        gBackgroundPositions.bg[0].y = ((gBG0YPosition >> 0x2) + gBG0Movement.snowflakesRelated & 0x1FF) + xOffset;
    }

    new_bg3_x = (gBG3XPosition >> 0x2) + gBG3Movement.xOffset & 0x1FF;
    new_bg3_y = gBG3YPosition >> 0x2 & 0x1FF;

    if ((gScreenShakeRelated & 0x800) != 0x0)
    {
        gBackgroundPositions.bg[3].x = new_bg3_x;
        gBackgroundPositions.bg[3].y = new_bg3_y;
    }
    else
    {
        gBackgroundPositions.bg[3].x = new_bg3_x + (xOffset >> 0x1);
        gBackgroundPositions.bg[3].y = new_bg3_y + (yOffset >> 0x1);
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