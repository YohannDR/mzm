#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_29_Scrolls[SCROLL_DATA_SIZE(1)] = {
	47, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_47_Clipdata[149] = INCBIN_U8("data/rooms/chozodia/Chozodia_47_Clipdata.gfx");

const u8 sChozodia_47_Bg1[316] = INCBIN_U8("data/rooms/chozodia/Chozodia_47_Bg1.gfx");

const u8 sChozodia_47_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	14, 7, SPRITESET_IDX(8),
	14, 11, SPRITESET_IDX(8),
	19, 2, SPRITESET_IDX(1),
	19, 7, SPRITESET_IDX(6),
	19, 11, SPRITESET_IDX(8),
	20, 2, SPRITESET_IDX(1),
	20, 16, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_47_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_47_Bg0.gfx");

