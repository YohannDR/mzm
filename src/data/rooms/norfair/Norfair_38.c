#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_38_Clipdata[157] = INCBIN_U8("data/rooms/norfair/Norfair_38_Clipdata.gfx");

const u8 sNorfair_38_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg2.gfx");

const u8 sNorfair_38_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	4, 8, SPRITESET_IDX(1),
	7, 8, SPRITESET_IDX(1),
	8, 7, SPRITESET_IDX(0),
	9, 14, SPRITESET_IDX(0),
	14, 19, SPRITESET_IDX(1),
	14, 23, SPRITESET_IDX(1),
	21, 15, SPRITESET_IDX(4),
	21, 18, SPRITESET_IDX(4),
	21, 21, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_38_Bg1[462] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg1.gfx");

const u8 sNorfair_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	21, 11, SPRITESET_IDX(4),
	21, 18, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_38_Bg0[228] = INCBIN_U8("data/rooms/norfair/Norfair_38_Bg0.gfx");

