#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_12_Clipdata[379] = INCBIN_U8("data/rooms/brinstar/Brinstar_12_Clipdata.gfx");

const u8 sBrinstar_12_Bg2[337] = INCBIN_U8("data/rooms/brinstar/Brinstar_12_Bg2.gfx");

const u8 sBrinstar_12_Bg1[1226] = INCBIN_U8("data/rooms/brinstar/Brinstar_12_Bg1.gfx");

const u8 sBrinstar_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 13, SPRITESET_IDX(1),
	10, 113, SPRITESET_IDX(0),
	11, 41, SPRITESET_IDX(0),
	11, 88, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_12_Bg0[203] = INCBIN_U8("data/rooms/brinstar/Brinstar_12_Bg0.gfx");

