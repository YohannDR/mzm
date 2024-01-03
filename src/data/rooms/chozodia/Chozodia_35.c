#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_35_Clipdata[121] = INCBIN_U8("data/rooms/chozodia/Chozodia_35_Clipdata.gfx");

const u8 sChozodia_35_Bg2[312] = INCBIN_U8("data/rooms/chozodia/Chozodia_35_Bg2.gfx");

const u8 sChozodia_35_Bg1[492] = INCBIN_U8("data/rooms/chozodia/Chozodia_35_Bg1.gfx");

const u8 sChozodia_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 2, SPRITESET_IDX(1),
	5, 20, SPRITESET_IDX(3),
	5, 58, SPRITESET_IDX(0),
	6, 32, SPRITESET_IDX(3),
	9, 44, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_35_Bg0[53] = INCBIN_U8("data/rooms/chozodia/Chozodia_35_Bg0.gfx");

