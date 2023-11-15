#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_46_Scrolls[SCROLL_DATA_SIZE(1)] = {
	80, // Room
	1, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	1, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_80_Clipdata[155] = INCBIN_U8("data/rooms/chozodia/Chozodia_80_Clipdata.gfx");

const u8 sChozodia_80_Bg2[140] = INCBIN_U8("data/rooms/chozodia/Chozodia_80_Bg2.gfx");

const u8 sChozodia_80_Bg1[321] = INCBIN_U8("data/rooms/chozodia/Chozodia_80_Bg1.gfx");

const u8 sChozodia_80_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_80_Bg0[67] = INCBIN_U8("data/rooms/chozodia/Chozodia_80_Bg0.gfx");

