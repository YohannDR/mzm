#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_28_Clipdata[250] = INCBIN_U8("data/rooms/ridley/Ridley_28_Clipdata.gfx");

const u8 sRidley_28_Bg2[157] = INCBIN_U8("data/rooms/ridley/Ridley_28_Bg2.gfx");

const u8 sRidley_28_Bg1[626] = INCBIN_U8("data/rooms/ridley/Ridley_28_Bg1.gfx");

const u8 sRidley_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	15, 8, SPRITESET_IDX(2),
	22, 6, SPRITESET_IDX(0),
	23, 5, SPRITESET_IDX(1),
	24, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_28_Bg0[116] = INCBIN_U8("data/rooms/ridley/Ridley_28_Bg0.gfx");

