#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_62_Clipdata[199] = INCBIN_U8("data/rooms/chozodia/Chozodia_62_Clipdata.gfx");

const u8 sChozodia_62_Bg2[584] = INCBIN_U8("data/rooms/chozodia/Chozodia_62_Bg2.gfx");

const u8 sChozodia_62_Bg1[686] = INCBIN_U8("data/rooms/chozodia/Chozodia_62_Bg1.gfx");

const u8 sChozodia_62_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 6, SPRITESET_IDX(2),
	14, 12, SPRITESET_IDX(2),
	17, 7, SPRITESET_IDX(2),
	24, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

