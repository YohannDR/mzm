#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_1_Clipdata[310] = INCBIN_U8("data/rooms/norfair/Norfair_1_Clipdata.gfx");

const u8 sNorfair_1_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	2, 10, 20,
	2, 12, 20,
	2, 14, 20,
	3, 53, 20,
	3, 55, 20,
	9, 65, 17,
	9, 94, 17,
	10, 84, 19,
	10, 108, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_1_Bg2[375] = INCBIN_U8("data/rooms/norfair/Norfair_1_Bg2.gfx");

const u8 sNorfair_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 11, 20,
	3, 13, 20,
	3, 15, 20,
	4, 12, 20,
	4, 14, 20,
	9, 65, 18,
	9, 94, 18,
	10, 70, 18,
	10, 72, 18,
	10, 84, 21,
	10, 108, 21,
	12, 29, 21,
	12, 60, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_1_Bg1[1181] = INCBIN_U8("data/rooms/norfair/Norfair_1_Bg1.gfx");

const u8 sNorfair_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	2, 10, 20,
	2, 12, 20,
	2, 14, 20,
	3, 11, 20,
	3, 13, 20,
	3, 53, 20,
	3, 55, 20,
	9, 65, 18,
	9, 71, 17,
	9, 94, 17,
	10, 84, 19,
	10, 108, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_1_Bg0[399] = INCBIN_U8("data/rooms/norfair/Norfair_1_Bg0.gfx");

const u8 sNorfair_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	2, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sNorfair_2_Clipdata[285] = INCBIN_U8("data/rooms/norfair/Norfair_2_Clipdata.gfx");

const u8 sNorfair_2_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	15, 9, 21,
	38, 9, 17,
	39, 11,	19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_2_Bg2[193] = INCBIN_U8("data/rooms/norfair/Norfair_2_Bg2.gfx");

const u8 sNorfair_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	15, 9, 21,
	18, 9, 19,
	33, 3, 17,
	36, 5, 18,
	38, 9, 18,
	39, 11,	19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_2_Bg1[659] = INCBIN_U8("data/rooms/norfair/Norfair_2_Bg1.gfx");

const u8 sNorfair_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	15, 9, 21,
	33,	3, 17,
	36,	5, 17,
	38, 9, 17,
	39, 11,	19,
	ROOM_SPRITE_DATA_TERMINATOR
};

