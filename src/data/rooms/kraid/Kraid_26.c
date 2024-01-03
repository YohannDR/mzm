#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 32, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	30, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_26_Clipdata[415] = INCBIN_U8("data/rooms/kraid/Kraid_26_Clipdata.gfx");

const u8 sKraid_26_Bg2[545] = INCBIN_U8("data/rooms/kraid/Kraid_26_Bg2.gfx");

const u8 sKraid_26_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	20, 11, SPRITESET_IDX(4),
	24, 12, SPRITESET_IDX(1),
	28, 8, SPRITESET_IDX(4),
	32, 10, SPRITESET_IDX(1),
	34, 5, SPRITESET_IDX(1),
	72, 11, SPRITESET_IDX(4),
	74, 9, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_26_Bg1[1009] = INCBIN_U8("data/rooms/kraid/Kraid_26_Bg1.gfx");

const u8 sKraid_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	20, 11, SPRITESET_IDX(0),
	24, 12, SPRITESET_IDX(1),
	28, 8, SPRITESET_IDX(0),
	32, 10, SPRITESET_IDX(1),
	72, 11, SPRITESET_IDX(0),
	74, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_26_Bg0[712] = INCBIN_U8("data/rooms/kraid/Kraid_26_Bg0.gfx");

