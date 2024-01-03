#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_9_Clipdata[117] = INCBIN_U8("data/rooms/norfair/Norfair_9_Clipdata.gfx");

const u8 sNorfair_9_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	11, 20, SPRITESET_IDX(0),
	11, 31, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_9_Bg2.gfx");

const u8 sNorfair_9_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	2, 20, SPRITESET_IDX(0),
	2, 31, SPRITESET_IDX(0),
	11, 18, SPRITESET_IDX(0),
	11, 20, SPRITESET_IDX(2),
	11, 23, SPRITESET_IDX(0),
	11, 28, SPRITESET_IDX(2),
	11, 34, SPRITESET_IDX(0),
	11, 36, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg1[282] = INCBIN_U8("data/rooms/norfair/Norfair_9_Bg1.gfx");

const u8 sNorfair_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 20, SPRITESET_IDX(0),
	2, 31, SPRITESET_IDX(0),
	11, 18, SPRITESET_IDX(0),
	11, 26, SPRITESET_IDX(0),
	11, 34, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg0[265] = INCBIN_U8("data/rooms/norfair/Norfair_9_Bg0.gfx");

