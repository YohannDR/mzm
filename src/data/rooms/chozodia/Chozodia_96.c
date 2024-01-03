#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_96_Clipdata[222] = INCBIN_U8("data/rooms/chozodia/Chozodia_96_Clipdata.gfx");

const u8 sChozodia_96_Bg2[805] = INCBIN_U8("data/rooms/chozodia/Chozodia_96_Bg2.gfx");

const u8 sChozodia_96_Bg1[861] = INCBIN_U8("data/rooms/chozodia/Chozodia_96_Bg1.gfx");

const u8 sChozodia_96_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 46, SPRITESET_IDX(1),
	10, 32, SPRITESET_IDX(3),
	18, 40, SPRITESET_IDX(0),
	20, 21, SPRITESET_IDX(3),
	25, 27, SPRITESET_IDX(3),
	30, 46, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_96_Bg0[71] = INCBIN_U8("data/rooms/chozodia/Chozodia_96_Bg0.gfx");

