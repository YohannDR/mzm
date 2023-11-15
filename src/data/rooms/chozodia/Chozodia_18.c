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
	13, 31, 21,
	14, 12, 21,
	18, 19, 20,
	20, 23, 21,
	25, 43, 21,
	26, 38, 20,
	29, 10, 21,
	35, 29, 20,
	39, 20, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg2[14] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg2.gfx");

const u8 sChozodia_18_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	20, 46, 18,
	21, 2, 18,
	21, 13, 26,
	21, 18, 26,
	21, 23, 26,
	22, 8, 26,
	27, 31, 26,
	30, 17, 26,
	30, 22, 26,
	30, 27, 26,
	31, 8, 24,
	32, 34, 25,
	35, 8, 26,
	35, 13, 26,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg1[949] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg1.gfx");

const u8 sChozodia_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(23)] = {
	18, 12, 25,
	19, 46, 18,
	20, 2, 18,
	20, 46, 18,
	21, 2, 18,
	21, 13, 26,
	21, 18, 26,
	21, 23, 26,
	22, 8, 26,
	23, 19, 26,
	23, 24, 26,
	25, 30, 25,
	27, 31, 26,
	30, 17, 26,
	30, 22, 26,
	30, 27, 26,
	31, 8, 26,
	32, 34, 25,
	35, 8, 26,
	35, 13, 26,
	36, 19, 26,
	36, 25, 24,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_18_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_18_Bg0.gfx");

