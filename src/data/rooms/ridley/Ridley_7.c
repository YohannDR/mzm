#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_7_Clipdata[76] = INCBIN_U8("data/rooms/ridley/Ridley_7_Clipdata.gfx");

const u8 sRidley_7_Bg2[68] = INCBIN_U8("data/rooms/ridley/Ridley_7_Bg2.gfx");

const u8 sRidley_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 10, SPRITESET_IDX(2),
	2, 15, SPRITESET_IDX(2),
	2, 18, SPRITESET_IDX(2),
	2, 23, SPRITESET_IDX(2),
	8, 16, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_7_Bg1[206] = INCBIN_U8("data/rooms/ridley/Ridley_7_Bg1.gfx");

const u8 sRidley_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	2, 10, SPRITESET_IDX(2),
	2, 14, SPRITESET_IDX(3),
	2, 19, SPRITESET_IDX(3),
	2, 23, SPRITESET_IDX(2),
	8, 14, SPRITESET_IDX(2),
	8, 16, SPRITESET_IDX(2),
	8, 18, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_7_Bg0[464] = INCBIN_U8("data/rooms/ridley/Ridley_7_Bg0.gfx");

