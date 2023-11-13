#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_8_Clipdata[150] = INCBIN_U8("data/rooms/norfair/Norfair_8_Clipdata.gfx");

const u8 sNorfair_8_Bg2[292] = INCBIN_U8("data/rooms/norfair/Norfair_8_Bg2.gfx");

const u8 sNorfair_8_Bg1[347] = INCBIN_U8("data/rooms/norfair/Norfair_8_Bg1.gfx");

const u8 sNorfair_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	7, 9, 18,
	7, 20, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_8_Bg0[128] = INCBIN_U8("data/rooms/norfair/Norfair_8_Bg0.gfx");

