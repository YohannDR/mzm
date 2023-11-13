#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sNorfair_0_Clipdata[238] = INCBIN_U8("data/rooms/norfair/Norfair_0_Clipdata.gfx");

const u8 sNorfair_0_Bg2[167] = INCBIN_U8("data/rooms/norfair/Norfair_0_Bg2.gfx");

const u8 sNorfair_0_Bg1[501] = INCBIN_U8("data/rooms/norfair/Norfair_0_Bg1.gfx");

const u8 sNorfair_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	15, 9, 21,
	21, 8, 19,
	25, 8, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

