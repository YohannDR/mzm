#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_4_Scrolls[SCROLL_DATA_SIZE(3)] = {
	8, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 30, // X bounds
	10, 19, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	31, 76, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_8_Clipdata[395] = INCBIN_U8("data/rooms/kraid/Kraid_8_Clipdata.gfx");

const u8 sKraid_8_Bg2[121] = INCBIN_U8("data/rooms/kraid/Kraid_8_Bg2.gfx");

const u8 sKraid_8_Bg1[1051] = INCBIN_U8("data/rooms/kraid/Kraid_8_Bg1.gfx");

const u8 sKraid_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	3, 49, 18,
	4, 6, 19,
	4, 51, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_8_Bg0[183] = INCBIN_U8("data/rooms/kraid/Kraid_8_Bg0.gfx");

