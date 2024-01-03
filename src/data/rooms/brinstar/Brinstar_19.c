#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_19_Clipdata[325] = INCBIN_U8("data/rooms/brinstar/Brinstar_19_Clipdata.gfx");

const u8 sBrinstar_19_Bg2[42] = INCBIN_U8("data/rooms/brinstar/Brinstar_19_Bg2.gfx");

const u8 sBrinstar_19_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 16, SPRITESET_IDX(0),
	3, 20, SPRITESET_IDX(0),
	3, 24, SPRITESET_IDX(0),
	3, 77, SPRITESET_IDX(0),
	3, 81, SPRITESET_IDX(0),
	3, 96, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_19_Bg1[935] = INCBIN_U8("data/rooms/brinstar/Brinstar_19_Bg1.gfx");

const u8 sBrinstar_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 13, SPRITESET_IDX(1),
	3, 50, SPRITESET_IDX(0),
	3, 80, SPRITESET_IDX(0),
	3, 96, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_19_Bg0[274] = INCBIN_U8("data/rooms/brinstar/Brinstar_19_Bg0.gfx");

