#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_5_Scrolls[SCROLL_DATA_SIZE(1)] = {
	10, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 17, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sKraid_10_Clipdata[165] = INCBIN_U8("data/rooms/kraid/Kraid_10_Clipdata.gfx");

const u8 sKraid_10_Bg2[113] = INCBIN_U8("data/rooms/kraid/Kraid_10_Bg2.gfx");

const u8 sKraid_10_Bg1[413] = INCBIN_U8("data/rooms/kraid/Kraid_10_Bg1.gfx");

const u8 sKraid_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 25, 17,
	8, 18, 18,
	16, 16, 19,
	16, 19, 19,
	16, 22, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

