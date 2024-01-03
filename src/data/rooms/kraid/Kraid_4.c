#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_4_Clipdata[119] = INCBIN_U8("data/rooms/kraid/Kraid_4_Clipdata.gfx");

const u8 sKraid_4_Bg2[36] = INCBIN_U8("data/rooms/kraid/Kraid_4_Bg2.gfx");

const u8 sKraid_4_Bg1[253] = INCBIN_U8("data/rooms/kraid/Kraid_4_Bg1.gfx");

const u8 sKraid_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 27, SPRITESET_IDX(1),
	4, 11, SPRITESET_IDX(2),
	4, 29, SPRITESET_IDX(2),
	9, 11, SPRITESET_IDX(3),
	12, 25, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_4_Bg0[62] = INCBIN_U8("data/rooms/kraid/Kraid_4_Bg0.gfx");

