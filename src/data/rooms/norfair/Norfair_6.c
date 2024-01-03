#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_6_Clipdata[128] = INCBIN_U8("data/rooms/norfair/Norfair_6_Clipdata.gfx");

const u8 sNorfair_6_Bg2[111] = INCBIN_U8("data/rooms/norfair/Norfair_6_Bg2.gfx");

const u8 sNorfair_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 24, SPRITESET_IDX(0),
	12, 10, SPRITESET_IDX(1),
	12, 20, SPRITESET_IDX(1),
	12, 33, SPRITESET_IDX(1),
	12, 36, SPRITESET_IDX(1),
	12, 39, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_6_Bg1[280] = INCBIN_U8("data/rooms/norfair/Norfair_6_Bg1.gfx");

const u8 sNorfair_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 26, SPRITESET_IDX(0),
	12, 10, SPRITESET_IDX(1),
	12, 20, SPRITESET_IDX(1),
	12, 33, SPRITESET_IDX(1),
	12, 36, SPRITESET_IDX(1),
	12, 39, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_6_Bg0[175] = INCBIN_U8("data/rooms/norfair/Norfair_6_Bg0.gfx");

