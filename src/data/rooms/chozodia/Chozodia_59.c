#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_59_Clipdata[374] = INCBIN_U8("data/rooms/chozodia/Chozodia_59_Clipdata.gfx");

const u8 sChozodia_59_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	6, 11, SPRITESET_IDX(3),
	15, 13, SPRITESET_IDX(3),
	21, 12, SPRITESET_IDX(0),
	34, 5, SPRITESET_IDX(0),
	40, 2, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_59_Bg1[793] = INCBIN_U8("data/rooms/chozodia/Chozodia_59_Bg1.gfx");

const u8 sChozodia_59_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	6, 11, SPRITESET_IDX(3),
	15, 13, SPRITESET_IDX(3),
	21, 12, SPRITESET_IDX(0),
	34, 5, SPRITESET_IDX(0),
	34, 10, SPRITESET_IDX(0),
	40, 13, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

