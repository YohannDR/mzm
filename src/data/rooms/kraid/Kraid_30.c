#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_9_Scrolls[SCROLL_DATA_SIZE(1)] = {
	30, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	23, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_30_Clipdata[127] = INCBIN_U8("data/rooms/kraid/Kraid_30_Clipdata.gfx");

const u8 sKraid_30_Bg2[245] = INCBIN_U8("data/rooms/kraid/Kraid_30_Bg2.gfx");

const u8 sKraid_30_Bg1[468] = INCBIN_U8("data/rooms/kraid/Kraid_30_Bg1.gfx");

const u8 sKraid_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	32, 17, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_30_Spriteset_Unused[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	49, 44, 2,
	0, 1, 139,
	136, 107, 0,
	0, 0, 2,
	136, 108, 0,
	0, 0, 0 // /!\ No proper terminator
};

