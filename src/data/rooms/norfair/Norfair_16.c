#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_5_Scrolls[SCROLL_DATA_SIZE(3)] = {
	16, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	4, 11, // Breakeable block position
	3, // Breakeable block direction
	19, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	19, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_16_Clipdata[247] = INCBIN_U8("data/rooms/norfair/Norfair_16_Clipdata.gfx");

const u8 sNorfair_16_Bg2[285] = INCBIN_U8("data/rooms/norfair/Norfair_16_Bg2.gfx");

const u8 sNorfair_16_Bg1[452] = INCBIN_U8("data/rooms/norfair/Norfair_16_Bg1.gfx");

const u8 sNorfair_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 14, 18,
	18, 9, 18,
	21, 9, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

