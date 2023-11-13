#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_12_Clipdata[110] = INCBIN_U8("data/rooms/norfair/Norfair_12_Clipdata.gfx");

const u8 sNorfair_12_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 14, 19,
	4, 17, 20,
	4, 20, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg2[48] = INCBIN_U8("data/rooms/norfair/Norfair_12_Bg2.gfx");

const u8 sNorfair_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, 20,
	4, 17, 19,
	4, 20, 20,
	5, 16, 20,
	5, 18, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg1[269] = INCBIN_U8("data/rooms/norfair/Norfair_12_Bg1.gfx");

const u8 sNorfair_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, 19,
	4, 17, 20,
	4, 20, 19,
	5, 16, 19,
	5, 18, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg0[129] = INCBIN_U8("data/rooms/norfair/Norfair_12_Bg0.gfx");

