#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_58_Scrolls[SCROLL_DATA_SIZE(1)] = {
	97, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	1, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_97_Clipdata[135] = INCBIN_U8("data/rooms/chozodia/Chozodia_97_Clipdata.gfx");

const u8 sChozodia_97_Bg1[177] = INCBIN_U8("data/rooms/chozodia/Chozodia_97_Bg1.gfx");

const u8 sChozodia_97_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 2, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

