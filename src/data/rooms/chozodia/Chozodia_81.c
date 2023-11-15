#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_47_Scrolls[SCROLL_DATA_SIZE(1)] = {
	81, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_81_Clipdata[190] = INCBIN_U8("data/rooms/chozodia/Chozodia_81_Clipdata.gfx");

const u8 sChozodia_81_Bg2[97] = INCBIN_U8("data/rooms/chozodia/Chozodia_81_Bg2.gfx");

const u8 sChozodia_81_Bg1[319] = INCBIN_U8("data/rooms/chozodia/Chozodia_81_Bg1.gfx");

const u8 sChozodia_81_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_81_Bg0[133] = INCBIN_U8("data/rooms/chozodia/Chozodia_81_Bg0.gfx");

