#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_1_Clipdata[310] = INCBIN_U8("data/rooms/norfair/Norfair_1_Clipdata.gfx");

const u8 sNorfair_1_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	2, 10, SPRITESET_IDX(3),
	2, 12, SPRITESET_IDX(3),
	2, 14, SPRITESET_IDX(3),
	3, 53, SPRITESET_IDX(3),
	3, 55, SPRITESET_IDX(3),
	9, 65, SPRITESET_IDX(0),
	9, 94, SPRITESET_IDX(0),
	10, 84, SPRITESET_IDX(2),
	10, 108, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_1_Bg2[375] = INCBIN_U8("data/rooms/norfair/Norfair_1_Bg2.gfx");

const u8 sNorfair_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 11, SPRITESET_IDX(3),
	3, 13, SPRITESET_IDX(3),
	3, 15, SPRITESET_IDX(3),
	4, 12, SPRITESET_IDX(3),
	4, 14, SPRITESET_IDX(3),
	9, 65, SPRITESET_IDX(1),
	9, 94, SPRITESET_IDX(1),
	10, 70, SPRITESET_IDX(1),
	10, 72, SPRITESET_IDX(1),
	10, 84, SPRITESET_IDX(4),
	10, 108, SPRITESET_IDX(4),
	12, 29, SPRITESET_IDX(4),
	12, 60, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_1_Bg1[1181] = INCBIN_U8("data/rooms/norfair/Norfair_1_Bg1.gfx");

const u8 sNorfair_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	2, 10, SPRITESET_IDX(3),
	2, 12, SPRITESET_IDX(3),
	2, 14, SPRITESET_IDX(3),
	3, 11, SPRITESET_IDX(3),
	3, 13, SPRITESET_IDX(3),
	3, 53, SPRITESET_IDX(3),
	3, 55, SPRITESET_IDX(3),
	9, 65, SPRITESET_IDX(1),
	9, 71, SPRITESET_IDX(0),
	9, 94, SPRITESET_IDX(0),
	10, 84, SPRITESET_IDX(2),
	10, 108, SPRITESET_IDX(2),
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
	15, 9, SPRITESET_IDX(4),
	38, 9, SPRITESET_IDX(0),
	39, 11,	SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_2_Bg2[193] = INCBIN_U8("data/rooms/norfair/Norfair_2_Bg2.gfx");

const u8 sNorfair_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	15, 9, SPRITESET_IDX(4),
	18, 9, SPRITESET_IDX(2),
	33, 3, SPRITESET_IDX(0),
	36, 5, SPRITESET_IDX(1),
	38, 9, SPRITESET_IDX(1),
	39, 11,	SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_2_Bg1[659] = INCBIN_U8("data/rooms/norfair/Norfair_2_Bg1.gfx");

const u8 sNorfair_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	15, 9, SPRITESET_IDX(4),
	33,	3, SPRITESET_IDX(0),
	36,	5, SPRITESET_IDX(0),
	38, 9, SPRITESET_IDX(0),
	39, 11,	SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

