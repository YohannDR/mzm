#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_21_Clipdata[210] = INCBIN_U8("data/rooms/norfair/Norfair_21_Clipdata.gfx");

const u8 sNorfair_21_Bg2[28] = INCBIN_U8("data/rooms/norfair/Norfair_21_Bg2.gfx");

const u8 sNorfair_21_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 18, SPRITESET_IDX(1),
	2, 29, SPRITESET_IDX(1),
	5, 14, SPRITESET_IDX(2),
	5, 34, SPRITESET_IDX(2),
	8, 24, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_21_Bg1[452] = INCBIN_U8("data/rooms/norfair/Norfair_21_Bg1.gfx");

const u8 sNorfair_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 18, SPRITESET_IDX(1),
	2, 29, SPRITESET_IDX(1),
	5, 14, SPRITESET_IDX(4),
	5, 34, SPRITESET_IDX(4),
	8, 24, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_21_Bg0[174] = INCBIN_U8("data/rooms/norfair/Norfair_21_Bg0.gfx");

