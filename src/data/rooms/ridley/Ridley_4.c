#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_1_Scrolls[SCROLL_DATA_SIZE(2)] = {
	4, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_4_Clipdata[187] = INCBIN_U8("data/rooms/ridley/Ridley_4_Clipdata.gfx");

const u8 sRidley_4_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_4_Bg2.gfx");

const u8 sRidley_4_Bg1[435] = INCBIN_U8("data/rooms/ridley/Ridley_4_Bg1.gfx");

const u8 sRidley_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	5, 9, 17,
	21, 4, 17,
	21, 14, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_4_Bg0[78] = INCBIN_U8("data/rooms/ridley/Ridley_4_Bg0.gfx");

