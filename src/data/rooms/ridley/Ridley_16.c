#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_9_Scrolls[SCROLL_DATA_SIZE(3)] = {
	16, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	12, 21, // Y bounds
	6, 12, // Breakeable block position
	2, // Breakeable block direction
	10, // Breakeable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	17, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_16_Clipdata[311] = INCBIN_U8("data/rooms/ridley/Ridley_16_Clipdata.gfx");

const u8 sRidley_16_Bg2[1456] = INCBIN_U8("data/rooms/ridley/Ridley_16_Bg2.gfx");

const u8 sRidley_16_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	5, 22, 19,
	5, 28, 19,
	17, 51, 17,
	18, 45, 22,
	19, 51, 17,
	20, 12, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_16_Bg1[760] = INCBIN_U8("data/rooms/ridley/Ridley_16_Bg1.gfx");

const u8 sRidley_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	5, 22, 19,
	5, 25, 19,
	5, 28, 19,
	17, 51, 17,
	18, 45, 22,
	19, 51, 18,
	20, 12, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_16_Bg0[218] = INCBIN_U8("data/rooms/ridley/Ridley_16_Bg0.gfx");

