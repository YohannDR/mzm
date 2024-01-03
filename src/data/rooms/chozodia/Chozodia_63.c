#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_63_Clipdata[133] = INCBIN_U8("data/rooms/chozodia/Chozodia_63_Clipdata.gfx");

const u8 sChozodia_63_Bg2[574] = INCBIN_U8("data/rooms/chozodia/Chozodia_63_Bg2.gfx");

const u8 sChozodia_63_Bg1[415] = INCBIN_U8("data/rooms/chozodia/Chozodia_63_Bg1.gfx");

const u8 sChozodia_63_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	6, 8, SPRITESET_IDX(4),
	6, 12, SPRITESET_IDX(4),
	7, 15, SPRITESET_IDX(4),
	9, 7, SPRITESET_IDX(4),
	11, 21, SPRITESET_IDX(4),
	13, 16, SPRITESET_IDX(4),
	15, 27, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

