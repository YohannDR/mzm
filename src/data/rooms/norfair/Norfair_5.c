#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_2_Scrolls[SCROLL_DATA_SIZE(5)] = {
	5, // Room
	5, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	11, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	60, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	49, 62, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 4
	15, 29, // X bounds
	2, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_5_Clipdata[1592] = INCBIN_U8("data/rooms/norfair/Norfair_5_Clipdata.gfx");

const u8 sNorfair_5_Bg2[2172] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg2.gfx");

const u8 sNorfair_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	8, 11, SPRITESET_IDX(0),
	8, 14, SPRITESET_IDX(2),
	18, 14, SPRITESET_IDX(0),
	21, 6, SPRITESET_IDX(0),
	30, 10, SPRITESET_IDX(2),
	34, 14, SPRITESET_IDX(2),
	44, 13, SPRITESET_IDX(2),
	66, 3, SPRITESET_IDX(0),
	82, 4, SPRITESET_IDX(0),
	88, 9, SPRITESET_IDX(3),
	95, 7, SPRITESET_IDX(1),
	114, 23, SPRITESET_IDX(4),
	115, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_5_Bg1[2886] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg1.gfx");

const u8 sNorfair_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	6, 12, SPRITESET_IDX(2),
	8, 12, SPRITESET_IDX(0),
	18, 14, SPRITESET_IDX(0),
	21, 6, SPRITESET_IDX(0),
	34, 14, SPRITESET_IDX(2),
	45, 14, SPRITESET_IDX(0),
	66, 3, SPRITESET_IDX(0),
	82, 4, SPRITESET_IDX(0),
	88, 9, SPRITESET_IDX(3),
	95, 7, SPRITESET_IDX(1),
	114, 23, SPRITESET_IDX(4),
	115, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_5_Bg0[363] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg0.gfx");

