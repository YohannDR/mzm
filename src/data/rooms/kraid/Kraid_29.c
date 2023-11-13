#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	29, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	4, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 5, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_29_Clipdata[61] = INCBIN_U8("data/rooms/kraid/Kraid_29_Clipdata.gfx");

const u8 sKraid_29_Bg2[106] = INCBIN_U8("data/rooms/kraid/Kraid_29_Bg2.gfx");

const u8 sKraid_29_Bg1[209] = INCBIN_U8("data/rooms/kraid/Kraid_29_Bg1.gfx");

const u8 sKraid_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 3, 24,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_29_Bg0[80] = INCBIN_U8("data/rooms/kraid/Kraid_29_Bg0.gfx");

