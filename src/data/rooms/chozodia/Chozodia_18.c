#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_12_Scrolls[SCROLL_DATA_SIZE(1)] = {
	18, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	11, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_18_Clipdata[402] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Clipdata.gfx");

const u8 sChozodia_18_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	13, 31, SPRITESET_IDX(4),
	14, 12, SPRITESET_IDX(4),
	18, 19, SPRITESET_IDX(3),
	20, 23, SPRITESET_IDX(4),
	25, 43, SPRITESET_IDX(4),
	26, 38, SPRITESET_IDX(3),
	29, 10, SPRITESET_IDX(4),
	35, 29, SPRITESET_IDX(3),
	39, 20, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg2[14] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg2.gfx");

const u8 sChozodia_18_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	20, 46, SPRITESET_IDX(1),
	21, 2, SPRITESET_IDX(1),
	21, 13, SPRITESET_IDX(9),
	21, 18, SPRITESET_IDX(9),
	21, 23, SPRITESET_IDX(9),
	22, 8, SPRITESET_IDX(9),
	27, 31, SPRITESET_IDX(9),
	30, 17, SPRITESET_IDX(9),
	30, 22, SPRITESET_IDX(9),
	30, 27, SPRITESET_IDX(9),
	31, 8, SPRITESET_IDX(7),
	32, 34, SPRITESET_IDX(8),
	35, 8, SPRITESET_IDX(9),
	35, 13, SPRITESET_IDX(9),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg1[949] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg1.gfx");

const u8 sChozodia_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(23)] = {
	18, 12, SPRITESET_IDX(8),
	19, 46, SPRITESET_IDX(1),
	20, 2, SPRITESET_IDX(1),
	20, 46, SPRITESET_IDX(1),
	21, 2, SPRITESET_IDX(1),
	21, 13, SPRITESET_IDX(9),
	21, 18, SPRITESET_IDX(9),
	21, 23, SPRITESET_IDX(9),
	22, 8, SPRITESET_IDX(9),
	23, 19, SPRITESET_IDX(9),
	23, 24, SPRITESET_IDX(9),
	25, 30, SPRITESET_IDX(8),
	27, 31, SPRITESET_IDX(9),
	30, 17, SPRITESET_IDX(9),
	30, 22, SPRITESET_IDX(9),
	30, 27, SPRITESET_IDX(9),
	31, 8, SPRITESET_IDX(9),
	32, 34, SPRITESET_IDX(8),
	35, 8, SPRITESET_IDX(9),
	35, 13, SPRITESET_IDX(9),
	36, 19, SPRITESET_IDX(9),
	36, 25, SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg0.gfx");

