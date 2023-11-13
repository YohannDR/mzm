#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_14_Scrolls[SCROLL_DATA_SIZE(1)] = {
	43, // Room
	1, // Number of scrolls
	
	// Scroll 0
	16, 46, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_43_Clipdata[486] = INCBIN_U8("data/rooms/norfair/Norfair_43_Clipdata.gfx");

const u8 sNorfair_43_Bg2[1237] = INCBIN_U8("data/rooms/norfair/Norfair_43_Bg2.gfx");

const u8 sNorfair_43_Bg1[1405] = INCBIN_U8("data/rooms/norfair/Norfair_43_Bg1.gfx");

const u8 sNorfair_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	2, 23, 17,
	17, 33, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_43_Bg0[489] = INCBIN_U8("data/rooms/norfair/Norfair_43_Bg0.gfx");

