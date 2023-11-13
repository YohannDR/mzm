#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_13_Scrolls[SCROLL_DATA_SIZE(2)] = {
	35, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_35_Clipdata[159] = INCBIN_U8("data/rooms/norfair/Norfair_35_Clipdata.gfx");

const u8 sNorfair_35_Bg2[183] = INCBIN_U8("data/rooms/norfair/Norfair_35_Bg2.gfx");

const u8 sNorfair_35_Bg1[601] = INCBIN_U8("data/rooms/norfair/Norfair_35_Bg1.gfx");

const u8 sNorfair_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	9, 9, 17,
	9, 15, 18,
	11, 24, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

