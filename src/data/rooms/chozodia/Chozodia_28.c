#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_18_Scrolls[SCROLL_DATA_SIZE(1)] = {
	28, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	11, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_28_Clipdata[506] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Clipdata.gfx");

const u8 sChozodia_28_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	16, 13, SPRITESET_IDX(0),
	16, 31, SPRITESET_IDX(1),
	17, 23, SPRITESET_IDX(0),
	28, 5, SPRITESET_IDX(0),
	39, 31, SPRITESET_IDX(1),
	40, 19, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg2[326] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg2.gfx");

const u8 sChozodia_28_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	14, 10, SPRITESET_IDX(4),
	15, 20, SPRITESET_IDX(6),
	16, 31, SPRITESET_IDX(1),
	20, 7, SPRITESET_IDX(5),
	22, 20, SPRITESET_IDX(0),
	25, 20, SPRITESET_IDX(8),
	26, 27, SPRITESET_IDX(4),
	28, 5, SPRITESET_IDX(0),
	32, 20, SPRITESET_IDX(4),
	34, 27, SPRITESET_IDX(7),
	39, 31, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg1[854] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg1.gfx");

const u8 sChozodia_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	14, 10, SPRITESET_IDX(4),
	15, 20, SPRITESET_IDX(6),
	16, 31, SPRITESET_IDX(1),
	25, 20, SPRITESET_IDX(8),
	26, 27, SPRITESET_IDX(4),
	28, 5, SPRITESET_IDX(0),
	32, 20, SPRITESET_IDX(4),
	39, 31, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg0[16] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg0.gfx");

