#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_11_Scrolls[SCROLL_DATA_SIZE(1)] = {
	32, // Room
	1, // Number of scrolls
	
	// Scroll 0
	37, 76, // X bounds
	2, 11, // Y bounds
	38, 3, // Breakeable block position
	0, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sNorfair_32_Clipdata[193] = INCBIN_U8("data/rooms/norfair/Norfair_32_Clipdata.gfx");

const u8 sNorfair_32_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_32_Bg2.gfx");

const u8 sNorfair_32_Bg1[613] = INCBIN_U8("data/rooms/norfair/Norfair_32_Bg1.gfx");

const u8 sNorfair_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 60, 21,
	9, 52, 17,
	10, 56, 18,
	11, 66, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_32_Bg0[263] = INCBIN_U8("data/rooms/norfair/Norfair_32_Bg0.gfx");

