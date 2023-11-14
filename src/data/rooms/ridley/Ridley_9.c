#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	9, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	10, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_9_Clipdata[231] = INCBIN_U8("data/rooms/ridley/Ridley_9_Clipdata.gfx");

const u8 sRidley_9_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_9_Bg2.gfx");

const u8 sRidley_9_Bg1[396] = INCBIN_U8("data/rooms/ridley/Ridley_9_Bg1.gfx");

const u8 sRidley_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	7, 8, 17,
	8, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

