#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_6_Clipdata[254] = INCBIN_U8("data/rooms/kraid/Kraid_6_Clipdata.gfx");

const u8 sKraid_6_Bg2[14] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg2.gfx");

const u8 sKraid_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	14, 12, SPRITESET_IDX(4),
	15, 10, SPRITESET_IDX(4),
	16, 13, SPRITESET_IDX(4),
	17, 11, SPRITESET_IDX(4),
	23, 12, SPRITESET_IDX(4),
	24, 10, SPRITESET_IDX(4),
	25, 13, SPRITESET_IDX(4),
	26, 11, SPRITESET_IDX(4),
	28, 4, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_6_Bg1[522] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg1.gfx");

const u8 sKraid_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	14, 12, SPRITESET_IDX(0),
	15, 10, SPRITESET_IDX(0),
	16, 13, SPRITESET_IDX(0),
	17, 11, SPRITESET_IDX(0),
	23, 12, SPRITESET_IDX(0),
	24, 10, SPRITESET_IDX(0),
	25, 13, SPRITESET_IDX(0),
	26, 11, SPRITESET_IDX(0),
	28, 4, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_6_Bg0[86] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg0.gfx");

