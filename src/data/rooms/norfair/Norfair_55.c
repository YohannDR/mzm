#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_16_Scrolls[SCROLL_DATA_SIZE(1)] = {
	55, // Room
	1, // Number of scrolls
	
	// Scroll 0
	16, 31, // X bounds
	2, 41, // Y bounds
	16, 32, // Breakeable block position
	0, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sNorfair_55_Clipdata[406] = INCBIN_U8("data/rooms/norfair/Norfair_55_Clipdata.gfx");

const u8 sNorfair_55_Bg2[142] = INCBIN_U8("data/rooms/norfair/Norfair_55_Bg2.gfx");

const u8 sNorfair_55_Bg1[1189] = INCBIN_U8("data/rooms/norfair/Norfair_55_Bg1.gfx");

const u8 sNorfair_55_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_55_Bg0[750] = INCBIN_U8("data/rooms/norfair/Norfair_55_Bg0.gfx");

