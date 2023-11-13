#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_12_Scrolls[SCROLL_DATA_SIZE(3)] = {
	34, // Room
	3, // Number of scrolls
	
	// Scroll 0
	16, 31, // X bounds
	2, 14, // Y bounds
	23, 13, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	12, 21, // Y bounds
	32, 16, // Breakeable block position
	0, // Breakeable block direction
	16, // Breakeable block Y bound extension
};

const u8 sNorfair_34_Clipdata[269] = INCBIN_U8("data/rooms/norfair/Norfair_34_Clipdata.gfx");

const u8 sNorfair_34_Bg2[332] = INCBIN_U8("data/rooms/norfair/Norfair_34_Bg2.gfx");

const u8 sNorfair_34_Bg1[704] = INCBIN_U8("data/rooms/norfair/Norfair_34_Bg1.gfx");

const u8 sNorfair_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	2, 23, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_34_Bg0[87] = INCBIN_U8("data/rooms/norfair/Norfair_34_Bg0.gfx");

