#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_19_Clipdata[237] = INCBIN_U8("data/rooms/norfair/Norfair_19_Clipdata.gfx");

const u8 sNorfair_19_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_19_Bg2.gfx");

const u8 sNorfair_19_Bg1[552] = INCBIN_U8("data/rooms/norfair/Norfair_19_Bg1.gfx");

const u8 sNorfair_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	2, 9, SPRITESET_IDX(1),
	2, 21, SPRITESET_IDX(0),
	2, 39, SPRITESET_IDX(1),
	9, 24, SPRITESET_IDX(3),
	11, 32, SPRITESET_IDX(2),
	12, 13, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_19_Bg0[656] = INCBIN_U8("data/rooms/norfair/Norfair_19_Bg0.gfx");

