#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_2_Clipdata[273] = INCBIN_U8("data/rooms/ridley/Ridley_2_Clipdata.gfx");

const u8 sRidley_2_Bg2[229] = INCBIN_U8("data/rooms/ridley/Ridley_2_Bg2.gfx");

const u8 sRidley_2_Bg1[666] = INCBIN_U8("data/rooms/ridley/Ridley_2_Bg1.gfx");

const u8 sRidley_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	22, 6, SPRITESET_IDX(0),
	23, 5, SPRITESET_IDX(1),
	24, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_2_Bg0[116] = INCBIN_U8("data/rooms/ridley/Ridley_2_Bg0.gfx");

