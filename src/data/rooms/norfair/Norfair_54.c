#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_15_Scrolls[SCROLL_DATA_SIZE(2)] = {
	54, // Room
	2, // Number of scrolls
	
	// Scroll 0
	16, 46, // X bounds
	2, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	13, 29, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_54_Clipdata[266] = INCBIN_U8("data/rooms/norfair/Norfair_54_Clipdata.gfx");

const u8 sNorfair_54_Bg2[606] = INCBIN_U8("data/rooms/norfair/Norfair_54_Bg2.gfx");

const u8 sNorfair_54_Bg1[927] = INCBIN_U8("data/rooms/norfair/Norfair_54_Bg1.gfx");

const u8 sNorfair_54_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	2, 23, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_54_Bg0[85] = INCBIN_U8("data/rooms/norfair/Norfair_54_Bg0.gfx");

