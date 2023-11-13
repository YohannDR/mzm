#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_6_Scrolls[SCROLL_DATA_SIZE(2)] = {
	25, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_25_Clipdata[195] = INCBIN_U8("data/rooms/kraid/Kraid_25_Clipdata.gfx");

const u8 sKraid_25_Bg2[229] = INCBIN_U8("data/rooms/kraid/Kraid_25_Bg2.gfx");

const u8 sKraid_25_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	3, 9, 21,
	6, 6, 20,
	10, 7, 21,
	13, 11, 21,
	14, 15, 20,
	15, 11, 21,
	15, 20, 21,
	21, 10, 22,
	21, 20, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_25_Bg1[487] = INCBIN_U8("data/rooms/kraid/Kraid_25_Bg1.gfx");

const u8 sKraid_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	3, 9, 17,
	6, 6, 20,
	10, 7, 17,
	13, 11, 17,
	14, 15, 20,
	15, 11, 17,
	15, 20, 17,
	21, 10, 22,
	21, 20, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

