#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_11_Scrolls[SCROLL_DATA_SIZE(2)] = {
	22, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 24, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_22_Clipdata[172] = INCBIN_U8("data/rooms/brinstar/Brinstar_22_Clipdata.gfx");

const u8 sBrinstar_22_Bg2[50] = INCBIN_U8("data/rooms/brinstar/Brinstar_22_Bg2.gfx");

const u8 sBrinstar_22_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 10, SPRITESET_IDX(0),
	17, 14, SPRITESET_IDX(0),
	23, 4, SPRITESET_IDX(2),
	23, 5, SPRITESET_IDX(2),
	23, 6, SPRITESET_IDX(2),
	23, 8, SPRITESET_IDX(2),
	23, 9, SPRITESET_IDX(2),
	25, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_22_Bg1[611] = INCBIN_U8("data/rooms/brinstar/Brinstar_22_Bg1.gfx");

const u8 sBrinstar_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 11, SPRITESET_IDX(0),
	25, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_22_Bg0[93] = INCBIN_U8("data/rooms/brinstar/Brinstar_22_Bg0.gfx");

