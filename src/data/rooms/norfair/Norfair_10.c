#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_10_Clipdata[160] = INCBIN_U8("data/rooms/norfair/Norfair_10_Clipdata.gfx");

const u8 sNorfair_10_Bg2[134] = INCBIN_U8("data/rooms/norfair/Norfair_10_Bg2.gfx");

const u8 sNorfair_10_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	4, 27, SPRITESET_IDX(3),
	7, 9, SPRITESET_IDX(0),
	7, 22, SPRITESET_IDX(0),
	8, 35, SPRITESET_IDX(0),
	12, 4, SPRITESET_IDX(4),
	12, 28, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_10_Bg1[341] = INCBIN_U8("data/rooms/norfair/Norfair_10_Bg1.gfx");

const u8 sNorfair_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	4, 27, SPRITESET_IDX(3),
	7, 22, SPRITESET_IDX(0),
	8, 35, SPRITESET_IDX(0),
	9, 18, SPRITESET_IDX(1),
	12, 4, SPRITESET_IDX(4),
	12, 28, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_10_Bg0[659] = INCBIN_U8("data/rooms/norfair/Norfair_10_Bg0.gfx");

