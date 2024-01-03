#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_41_Clipdata[93] = INCBIN_U8("data/rooms/norfair/Norfair_41_Clipdata.gfx");

const u8 sNorfair_41_Bg1[165] = INCBIN_U8("data/rooms/norfair/Norfair_41_Bg1.gfx");

const u8 sNorfair_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

