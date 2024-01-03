#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_17_Clipdata[112] = INCBIN_U8("data/rooms/norfair/Norfair_17_Clipdata.gfx");

const u8 sNorfair_17_Bg2[20] = INCBIN_U8("data/rooms/norfair/Norfair_17_Bg2.gfx");

const u8 sNorfair_17_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	4, 12, SPRITESET_IDX(2),
	5, 24, SPRITESET_IDX(2),
	7, 11, SPRITESET_IDX(2),
	9, 18, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_17_Bg1[249] = INCBIN_U8("data/rooms/norfair/Norfair_17_Bg1.gfx");

const u8 sNorfair_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	4, 12, SPRITESET_IDX(2),
	5, 24, SPRITESET_IDX(2),
	6, 17, SPRITESET_IDX(2),
	7, 11, SPRITESET_IDX(2),
	8, 21, SPRITESET_IDX(2),
	9, 12, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

