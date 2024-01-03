#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_60_Clipdata[256] = INCBIN_U8("data/rooms/chozodia/Chozodia_60_Clipdata.gfx");

const u8 sChozodia_60_Bg2[811] = INCBIN_U8("data/rooms/chozodia/Chozodia_60_Bg2.gfx");

const u8 sChozodia_60_Bg1[858] = INCBIN_U8("data/rooms/chozodia/Chozodia_60_Bg1.gfx");

const u8 sChozodia_60_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	7, 46, SPRITESET_IDX(1),
	10, 32, SPRITESET_IDX(3),
	20, 21, SPRITESET_IDX(3),
	29, 23, SPRITESET_IDX(0),
	30, 46, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_60_Bg0[45] = INCBIN_U8("data/rooms/chozodia/Chozodia_60_Bg0.gfx");

