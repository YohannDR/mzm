#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	37, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	23, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	30, 46, // X bounds
	31, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_37_Clipdata[130] = INCBIN_U8("data/rooms/kraid/Kraid_37_Clipdata.gfx");

const u8 sKraid_37_Bg2[45] = INCBIN_U8("data/rooms/kraid/Kraid_37_Bg2.gfx");

const u8 sKraid_37_Bg1[447] = INCBIN_U8("data/rooms/kraid/Kraid_37_Bg1.gfx");

const u8 sKraid_37_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_37_Spriteset_Unused[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	49, 44, 2,
	0, 1, 139,
	136, 107, 0,
	0, 0, 2,
	136, 108, 0 // /!\ No proper terminator
};

