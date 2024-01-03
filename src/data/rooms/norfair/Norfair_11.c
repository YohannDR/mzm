#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_11_Clipdata[111] = INCBIN_U8("data/rooms/norfair/Norfair_11_Clipdata.gfx");

const u8 sNorfair_11_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 16, SPRITESET_IDX(4),
	6, 26, SPRITESET_IDX(4),
	7, 35, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_11_Bg2[38] = INCBIN_U8("data/rooms/norfair/Norfair_11_Bg2.gfx");

const u8 sNorfair_11_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	6, 16, SPRITESET_IDX(4),
	6, 26, SPRITESET_IDX(4),
	7, 35, SPRITESET_IDX(1),
	9, 21, SPRITESET_IDX(4),
	11, 8, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_11_Bg1[311] = INCBIN_U8("data/rooms/norfair/Norfair_11_Bg1.gfx");

const u8 sNorfair_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 16, SPRITESET_IDX(4),
	6, 26, SPRITESET_IDX(4),
	7, 35, SPRITESET_IDX(0),
	11, 8, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_11_Bg0[199] = INCBIN_U8("data/rooms/norfair/Norfair_11_Bg0.gfx");

