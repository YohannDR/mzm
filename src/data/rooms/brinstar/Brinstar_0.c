#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_0_Scrolls[SCROLL_DATA_SIZE(3)] = {
	0, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	31, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_0_Clipdata[311] = INCBIN_U8("data/rooms/brinstar/Brinstar_0_Clipdata.gfx");

const u8 sBrinstar_0_Bg2[124] = INCBIN_U8("data/rooms/brinstar/Brinstar_0_Bg2.gfx");

const u8 sBrinstar_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	22, 27, SPRITESET_IDX(4),
	22, 56, SPRITESET_IDX(4),
	23, 68, SPRITESET_IDX(4),
	24, 4, SPRITESET_IDX(4),
	27, 11, SPRITESET_IDX(1),
	30, 21, SPRITESET_IDX(4),
	30, 67, SPRITESET_IDX(4),
	34, 39, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_0_Bg1[1328] = INCBIN_U8("data/rooms/brinstar/Brinstar_0_Bg1.gfx");

const u8 sBrinstar_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	22, 27, SPRITESET_IDX(0),
	22, 56, SPRITESET_IDX(0),
	23, 68, SPRITESET_IDX(0),
	24, 4, SPRITESET_IDX(0),
	27, 11, SPRITESET_IDX(1),
	30, 21, SPRITESET_IDX(0),
	30, 67, SPRITESET_IDX(0),
	34, 39, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

