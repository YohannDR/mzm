#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_9_Clipdata[83] = INCBIN_U8("data/rooms/kraid/Kraid_9_Clipdata.gfx");

const u8 sKraid_9_Bg2[143] = INCBIN_U8("data/rooms/kraid/Kraid_9_Bg2.gfx");

const u8 sKraid_9_Bg1[334] = INCBIN_U8("data/rooms/kraid/Kraid_9_Bg1.gfx");

const u8 sKraid_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 24, SPRITESET_IDX(1),
	4, 22, SPRITESET_IDX(2),
	4, 60, SPRITESET_IDX(2),
	8, 37, SPRITESET_IDX(0),
	8, 43, SPRITESET_IDX(0),
	9, 40, SPRITESET_IDX(0),
	9, 46, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_9_Bg0[156] = INCBIN_U8("data/rooms/kraid/Kraid_9_Bg0.gfx");

