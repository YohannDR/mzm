#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_7_Clipdata[180] = INCBIN_U8("data/rooms/norfair/Norfair_7_Clipdata.gfx");

const u8 sNorfair_7_Bg2[251] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg2.gfx");

const u8 sNorfair_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	4, 8, SPRITESET_IDX(2),
	14, 8, SPRITESET_IDX(2),
	16, 5, SPRITESET_IDX(1),
	17, 10, SPRITESET_IDX(2),
	17, 13, SPRITESET_IDX(1),
	20, 7, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg1[478] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg1.gfx");

const u8 sNorfair_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	11, 11, SPRITESET_IDX(2),
	15, 9, SPRITESET_IDX(2),
	19, 7, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg0[82] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg0.gfx");

