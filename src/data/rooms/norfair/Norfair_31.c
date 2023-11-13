#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	31, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_31_Clipdata[120] = INCBIN_U8("data/rooms/norfair/Norfair_31_Clipdata.gfx");

const u8 sNorfair_31_Bg2[296] = INCBIN_U8("data/rooms/norfair/Norfair_31_Bg2.gfx");

const u8 sNorfair_31_Bg1[322] = INCBIN_U8("data/rooms/norfair/Norfair_31_Bg1.gfx");

const u8 sNorfair_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	14, 11, 19,
	15, 14, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_31_Bg0[215] = INCBIN_U8("data/rooms/norfair/Norfair_31_Bg0.gfx");

