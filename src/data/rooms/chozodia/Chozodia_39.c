#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_25_Scrolls[SCROLL_DATA_SIZE(3)] = {
	39, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	61, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 76, // X bounds
	10, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_39_Clipdata[432] = INCBIN_U8("data/rooms/chozodia/Chozodia_39_Clipdata.gfx");

const u8 sChozodia_39_Bg2[677] = INCBIN_U8("data/rooms/chozodia/Chozodia_39_Bg2.gfx");

const u8 sChozodia_39_Bg1[1598] = INCBIN_U8("data/rooms/chozodia/Chozodia_39_Bg1.gfx");

const u8 sChozodia_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	8, 61, SPRITESET_IDX(4),
	19, 47, SPRITESET_IDX(3),
	26, 16, SPRITESET_IDX(0),
	26, 30, SPRITESET_IDX(0),
	26, 44, SPRITESET_IDX(0),
	26, 76, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

