#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_11_Scrolls[SCROLL_DATA_SIZE(2)] = {
	19, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	47, 61, // X bounds
	2, 11, // Y bounds
	56, 11, // Breakeable block position
	3, // Breakeable block direction
	17, // Breakeable block Y bound extension
};

const u8 sRidley_19_Clipdata[297] = INCBIN_U8("data/rooms/ridley/Ridley_19_Clipdata.gfx");

const u8 sRidley_19_Bg2[462] = INCBIN_U8("data/rooms/ridley/Ridley_19_Bg2.gfx");

const u8 sRidley_19_Bg1[794] = INCBIN_U8("data/rooms/ridley/Ridley_19_Bg1.gfx");

const u8 sRidley_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	14, 11, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

