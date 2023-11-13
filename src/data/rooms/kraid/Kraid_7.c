#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	7, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_7_Clipdata[246] = INCBIN_U8("data/rooms/kraid/Kraid_7_Clipdata.gfx");

const u8 sKraid_7_Bg2[259] = INCBIN_U8("data/rooms/kraid/Kraid_7_Bg2.gfx");

const u8 sKraid_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 6, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_7_Bg1[684] = INCBIN_U8("data/rooms/kraid/Kraid_7_Bg1.gfx");

const u8 sKraid_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 6, 17,
	18, 17, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_7_Bg0[70] = INCBIN_U8("data/rooms/kraid/Kraid_7_Bg0.gfx");

