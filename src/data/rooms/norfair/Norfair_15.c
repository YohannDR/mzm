#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_15_Clipdata[70] = INCBIN_U8("data/rooms/norfair/Norfair_15_Clipdata.gfx");

const u8 sNorfair_15_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_15_Bg2.gfx");

const u8 sNorfair_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	9, 13, 17,
	9, 17, 17,
	9, 21, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_15_Bg1[210] = INCBIN_U8("data/rooms/norfair/Norfair_15_Bg1.gfx");

const u8 sNorfair_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 16, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_15_Bg0[128] = INCBIN_U8("data/rooms/norfair/Norfair_15_Bg0.gfx");

