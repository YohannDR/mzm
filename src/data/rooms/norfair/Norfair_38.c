#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_38_Clipdata[157] = INCBIN_U8("data/rooms/norfair/Norfair_38_Clipdata.gfx");

const u8 sNorfair_38_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg2.gfx");

const u8 sNorfair_38_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	4, 8, 18,
	7, 8, 18,
	8, 7, 17,
	9, 14, 17,
	14, 19, 18,
	14, 23, 18,
	21, 15, 21,
	21, 18, 21,
	21, 21, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_38_Bg1[462] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg1.gfx");

const u8 sNorfair_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	21, 11, 21,
	21, 18, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_38_Bg0[228] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg0.gfx");

