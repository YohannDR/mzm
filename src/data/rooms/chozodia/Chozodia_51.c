#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_51_Clipdata[449] = INCBIN_U8("data/rooms/chozodia/Chozodia_51_Clipdata.gfx");

const u8 sChozodia_51_Bg2[1632] = INCBIN_U8("data/rooms/chozodia/Chozodia_51_Bg2.gfx");

const u8 sChozodia_51_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	7, 21, SPRITESET_IDX(5),
	10, 41, SPRITESET_IDX(3),
	12, 9, SPRITESET_IDX(3),
	20, 46, SPRITESET_IDX(1),
	25, 23, SPRITESET_IDX(3),
	30, 12, SPRITESET_IDX(0),
	30, 23, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_51_Bg1[999] = INCBIN_U8("data/rooms/chozodia/Chozodia_51_Bg1.gfx");

const u8 sChozodia_51_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 21, SPRITESET_IDX(5),
	10, 41, SPRITESET_IDX(3),
	18, 2, SPRITESET_IDX(1),
	20, 46, SPRITESET_IDX(1),
	30, 15, SPRITESET_IDX(3),
	30, 27, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

