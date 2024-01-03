#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_24_Clipdata[130] = INCBIN_U8("data/rooms/norfair/Norfair_24_Clipdata.gfx");

const u8 sNorfair_24_Bg2[101] = INCBIN_U8("data/rooms/norfair/Norfair_24_Bg2.gfx");

const u8 sNorfair_24_Bg1[542] = INCBIN_U8("data/rooms/norfair/Norfair_24_Bg1.gfx");

const u8 sNorfair_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	4, 36, SPRITESET_IDX(0),
	5, 11, SPRITESET_IDX(8),
	5, 37, SPRITESET_IDX(8),
	6, 16, SPRITESET_IDX(9),
	6, 24, SPRITESET_IDX(3),
	8, 33, SPRITESET_IDX(5),
	9, 13, SPRITESET_IDX(3),
	9, 16, SPRITESET_IDX(1),
	9, 19, SPRITESET_IDX(4),
	9, 23, SPRITESET_IDX(2),
	9, 27, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

