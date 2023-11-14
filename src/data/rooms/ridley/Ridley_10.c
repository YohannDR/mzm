#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_4_Scrolls[SCROLL_DATA_SIZE(1)] = {
	10, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	9, 12, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sRidley_10_Clipdata[248] = INCBIN_U8("data/rooms/ridley/Ridley_10_Clipdata.gfx");

const u8 sRidley_10_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_10_Bg2.gfx");

const u8 sRidley_10_Bg1[855] = INCBIN_U8("data/rooms/ridley/Ridley_10_Bg1.gfx");

const u8 sRidley_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	14, 17, 22,
	15, 19, 22,
	17, 12, 22,
	17, 18, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

