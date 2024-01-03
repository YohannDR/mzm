#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_38_Clipdata[83] = INCBIN_U8("data/rooms/kraid/Kraid_38_Clipdata.gfx");

const u8 sKraid_38_Bg2[14] = INCBIN_U8("data/rooms/kraid/Kraid_38_Bg2.gfx");

const u8 sKraid_38_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	5, 4, SPRITESET_IDX(4),
	6, 6, SPRITESET_IDX(4),
	8, 4, SPRITESET_IDX(4),
	10, 5, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_38_Bg1[185] = INCBIN_U8("data/rooms/kraid/Kraid_38_Bg1.gfx");

const u8 sKraid_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 6, SPRITESET_IDX(0),
	8, 4, SPRITESET_IDX(0),
	10, 5, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_38_Bg0[59] = INCBIN_U8("data/rooms/kraid/Kraid_38_Bg0.gfx");

