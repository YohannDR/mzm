#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_2_Scrolls[SCROLL_DATA_SIZE(1)] = {
	5, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	3, 15, // Y bounds
	17, 15, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sKraid_5_Clipdata[233] = INCBIN_U8("data/rooms/kraid/Kraid_5_Clipdata.gfx");

const u8 sKraid_5_Bg2[41] = INCBIN_U8("data/rooms/kraid/Kraid_5_Bg2.gfx");

const u8 sKraid_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	4, 21, 18,
	5, 9, 19,
	5, 24, 19,
	13, 16, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_5_Bg1[480] = INCBIN_U8("data/rooms/kraid/Kraid_5_Bg1.gfx");

const u8 sKraid_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 21, 18,
	5, 9, 19,
	5, 24, 19,
	6, 15, 17,
	6, 18, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

