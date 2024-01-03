#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_19_Scrolls[SCROLL_DATA_SIZE(2)] = {
	29, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 34, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	4, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_29_Clipdata[335] = INCBIN_U8("data/rooms/chozodia/Chozodia_29_Clipdata.gfx");

const u8 sChozodia_29_Bg2[385] = INCBIN_U8("data/rooms/chozodia/Chozodia_29_Bg2.gfx");

const u8 sChozodia_29_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	9, 40, SPRITESET_IDX(0),
	15, 41, SPRITESET_IDX(2),
	20, 40, SPRITESET_IDX(0),
	25, 37, SPRITESET_IDX(0),
	29, 20, SPRITESET_IDX(0),
	30, 5, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_29_Bg1[964] = INCBIN_U8("data/rooms/chozodia/Chozodia_29_Bg1.gfx");

const u8 sChozodia_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 41, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_29_Bg0[159] = INCBIN_U8("data/rooms/chozodia/Chozodia_29_Bg0.gfx");

