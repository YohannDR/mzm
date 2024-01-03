#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_28_Scrolls[SCROLL_DATA_SIZE(1)] = {
	44, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_44_Clipdata[136] = INCBIN_U8("data/rooms/chozodia/Chozodia_44_Clipdata.gfx");

const u8 sChozodia_44_Bg2[221] = INCBIN_U8("data/rooms/chozodia/Chozodia_44_Bg2.gfx");

const u8 sChozodia_44_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 4, SPRITESET_IDX(3),
	13, 3, SPRITESET_IDX(3),
	21, 16, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_44_Bg1[344] = INCBIN_U8("data/rooms/chozodia/Chozodia_44_Bg1.gfx");

const u8 sChozodia_44_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	6, 4, SPRITESET_IDX(3),
	6, 16, SPRITESET_IDX(1),
	10, 12, SPRITESET_IDX(3),
	13, 3, SPRITESET_IDX(3),
	21, 16, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

