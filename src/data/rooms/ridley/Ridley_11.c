#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_5_Scrolls[SCROLL_DATA_SIZE(2)] = {
	11, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_11_Clipdata[184] = INCBIN_U8("data/rooms/ridley/Ridley_11_Clipdata.gfx");

const u8 sRidley_11_Bg2[494] = INCBIN_U8("data/rooms/ridley/Ridley_11_Bg2.gfx");

const u8 sRidley_11_Bg1[407] = INCBIN_U8("data/rooms/ridley/Ridley_11_Bg1.gfx");

const u8 sRidley_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	7, 23, 20,
	15, 3, 21,
	19, 17, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_11_Bg0[73] = INCBIN_U8("data/rooms/ridley/Ridley_11_Bg0.gfx");

