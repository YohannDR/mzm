#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	22, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	9, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_22_Clipdata[264] = INCBIN_U8("data/rooms/norfair/Norfair_22_Clipdata.gfx");

const u8 sNorfair_22_Bg2[456] = INCBIN_U8("data/rooms/norfair/Norfair_22_Bg2.gfx");

const u8 sNorfair_22_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	9, 21, SPRITESET_IDX(4),
	9, 30, SPRITESET_IDX(4),
	16, 18, SPRITESET_IDX(0),
	16, 24, SPRITESET_IDX(1),
	17, 35, SPRITESET_IDX(1),
	19, 29, SPRITESET_IDX(1),
	21, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_22_Bg1[647] = INCBIN_U8("data/rooms/norfair/Norfair_22_Bg1.gfx");

const u8 sNorfair_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	9, 21, SPRITESET_IDX(4),
	9, 30, SPRITESET_IDX(4),
	16, 18, SPRITESET_IDX(0),
	16, 24, SPRITESET_IDX(0),
	17, 35, SPRITESET_IDX(0),
	19, 29, SPRITESET_IDX(1),
	21, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_22_Bg0[175] = INCBIN_U8("data/rooms/norfair/Norfair_22_Bg0.gfx");

