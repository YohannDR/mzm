#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_7_Clipdata[180] = INCBIN_U8("data/rooms/norfair/Norfair_7_Clipdata.gfx");

const u8 sNorfair_7_Bg2[251] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg2.gfx");

const u8 sNorfair_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	4, 8, 19,
	14, 8, 19,
	16, 5, 18,
	17, 10, 19,
	17, 13, 18,
	20, 7, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg1[478] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg1.gfx");

const u8 sNorfair_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	11, 11, 19,
	15, 9, 19,
	19, 7, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg0[82] = INCBIN_U8("data/rooms/norfair/Norfair_7_Bg0.gfx");

