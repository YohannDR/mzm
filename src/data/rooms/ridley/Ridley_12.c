#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_6_Scrolls[SCROLL_DATA_SIZE(1)] = {
	12, // Room
	1, // Number of scrolls
	
	// Scroll 0
	7, 26, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_12_Clipdata[126] = INCBIN_U8("data/rooms/ridley/Ridley_12_Clipdata.gfx");

const u8 sRidley_12_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_12_Bg2.gfx");

const u8 sRidley_12_Bg1[343] = INCBIN_U8("data/rooms/ridley/Ridley_12_Bg1.gfx");

const u8 sRidley_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	11, 16, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_12_Bg0[289] = INCBIN_U8("data/rooms/ridley/Ridley_12_Bg0.gfx");

