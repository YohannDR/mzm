#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_8_Clipdata[62] = INCBIN_U8("data/rooms/ridley/Ridley_8_Clipdata.gfx");

const u8 sRidley_8_Bg2[118] = INCBIN_U8("data/rooms/ridley/Ridley_8_Bg2.gfx");

const u8 sRidley_8_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 10, SPRITESET_IDX(2),
	3, 17, SPRITESET_IDX(2),
	3, 23, SPRITESET_IDX(2),
	8, 17, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_8_Bg1[224] = INCBIN_U8("data/rooms/ridley/Ridley_8_Bg1.gfx");

const u8 sRidley_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 14, SPRITESET_IDX(2),
	3, 19, SPRITESET_IDX(2),
	8, 14, SPRITESET_IDX(2),
	8, 17, SPRITESET_IDX(2),
	8, 20, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_8_Bg0[127] = INCBIN_U8("data/rooms/ridley/Ridley_8_Bg0.gfx");

