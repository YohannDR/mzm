#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_1_Scrolls[SCROLL_DATA_SIZE(2)] = {
	3, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	2, 18, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_3_Clipdata[258] = INCBIN_U8("data/rooms/chozodia/Chozodia_3_Clipdata.gfx");

const u8 sChozodia_3_Bg2[370] = INCBIN_U8("data/rooms/chozodia/Chozodia_3_Bg2.gfx");

const u8 sChozodia_3_Bg1[725] = INCBIN_U8("data/rooms/chozodia/Chozodia_3_Bg1.gfx");

const u8 sChozodia_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	6, 2, SPRITESET_IDX(1),
	6, 9, SPRITESET_IDX(6),
	10, 13, SPRITESET_IDX(6),
	16, 25, SPRITESET_IDX(9),
	16, 30, SPRITESET_IDX(9),
	16, 35, SPRITESET_IDX(9),
	16, 46, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_3_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_3_Bg0.gfx");

