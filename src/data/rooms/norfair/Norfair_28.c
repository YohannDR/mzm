#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_28_Clipdata[251] = INCBIN_U8("data/rooms/norfair/Norfair_28_Clipdata.gfx");

const u8 sNorfair_28_Bg2[165] = INCBIN_U8("data/rooms/norfair/Norfair_28_Bg2.gfx");

const u8 sNorfair_28_Bg1[724] = INCBIN_U8("data/rooms/norfair/Norfair_28_Bg1.gfx");

const u8 sNorfair_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	7, 24, SPRITESET_IDX(0),
	7, 46, SPRITESET_IDX(0),
	7, 52, SPRITESET_IDX(1),
	7, 56, SPRITESET_IDX(1),
	8, 11, SPRITESET_IDX(0),
	9, 54, SPRITESET_IDX(1),
	12, 7, SPRITESET_IDX(4),
	12, 12, SPRITESET_IDX(4),
	12, 25, SPRITESET_IDX(4),
	12, 34, SPRITESET_IDX(4),
	12, 40, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_28_Bg0[832] = INCBIN_U8("data/rooms/norfair/Norfair_28_Bg0.gfx");

