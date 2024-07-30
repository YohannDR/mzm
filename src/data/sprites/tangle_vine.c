#include "data/sprites/tangle_vine.h"
#include "macros.h"

#include "sprites_AI/tangle_vine.h"

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame0[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame1[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame2[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame3[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

const struct MultiSpriteData sTangleVineGerutaMultiSpriteData_Idle[5] = {
    [0] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const u32 sTangleVineGfx[1298] = INCBIN_U32("data/sprites/TangleVine.gfx.lz");
const u16 sTangleVinePal[80] = INCBIN_U16("data/sprites/TangleVine.pal");

const u16 sTangleVineTallOam_OnGround_Frame3[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x12c8,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1258,
    0xdc, 0x1f5, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnGround_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1259,
    0xdb, 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnGround_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x125a,
    0xdc, 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnGround_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x124e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125b,
    0xdc, 0x1f3, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnCeiling_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x125a,
    0x1c, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnCeiling_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x124e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125b,
    0x1c, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnCeiling_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x1258,
    0x1c, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOam_OnCeiling_Frame3[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1259,
    0x1d, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineMediumOam_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1250,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d0,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125e
};

const u16 sTangleVineMediumOam_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1252,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

const u16 sTangleVineMediumOam_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1254,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOam_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x1256,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineMediumOam_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1252,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOam_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1254,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineMediumOam_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1256,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOam_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1250,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineShortOam_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0xdd, 0x1fb, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineShortOam_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1259,
    0xdc, 0x1fb, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineShortOam_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125a,
    0xde, 0x1fa, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125e
};

const u16 sTangleVineShortOam_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x125b,
    0xdd, 0x1fa, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

const u16 sTangleVineShortOam_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0x14, 0x0, OBJ_SPRITE_OAM | 0x1311,
    0x1b, 0x1fd, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOam_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1259,
    0x14, 0x1, OBJ_SPRITE_OAM | 0x1311,
    0x1b, 0x1fa, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOam_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125a,
    0x15, 0x0, OBJ_SPRITE_OAM | 0x1311,
    0x1a, 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOam_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125b,
    0x14, 0x1ff, OBJ_SPRITE_OAM | 0x1311,
    0x1c, 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOam_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125e,
    0xdf, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOam_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125d,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f,
    0xdd, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOam_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125c,
    0xdc, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOam_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d,
    0xdb, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125e,
    0x1c, 0x1f7, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125f,
    0x1d, 0x1f8, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125c,
    0x1d, 0x1fa, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125f,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125d,
    0x1d, 0x1fc, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineOam_Unused_Frame[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x1240
};

const u16 sTangleVineGerutaPartOam_Grip_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1242
};

const u16 sTangleVineGerutaPartOam_Grip_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sTangleVineGerutaPartOam_Grip_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1, OBJ_SPRITE_OAM | 0x1246
};

const u16 sTangleVineGerutaPartOam_Grip_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x1240
};

const u16 sTangleVineGerutaPartOam_Grip_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1242
};

const u16 sTangleVineGerutaPartOam_Grip_Frame5[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sTangleVineGerutaPartOam_Grip_Frame7[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1, OBJ_SPRITE_OAM | 0x1246
};

const u16 sTangleVineGerutaOam_Full_Frame0[13] = {
    0x4,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xc8, 0x1ff, OBJ_SPRITE_OAM | 0x1261
};

const u16 sTangleVineGerutaOam_Full_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOam_Full_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOam_Full_Frame3[13] = {
    0x4,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1246,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x1f8, OBJ_SPRITE_OAM | 0x126e
};

const u16 sTangleVineGerutaOam_Root_Frame0[10] = {
    0x3,
    0xc7, 0x1ff, OBJ_SPRITE_OAM | 0x1261,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288
};

const u16 sTangleVineGerutaOam_Root_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOam_Root_Frame4[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOam_Root_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e
};

const u16 sTangleVineGerutaOam_Root_Frame1[10] = {
    0x3,
    0xc7, 0x1ff, OBJ_SPRITE_OAM | 0x1261,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288
};

const u16 sTangleVineGerutaOam_Root_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOam_Root_Frame5[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOam_Root_Frame7[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e
};

const u16 sTangleVineRedGerutaOam_Frame0[28] = {
    0x9,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22d8,
    0xd5, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x2202,
    0xd3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2208,
    0xd4, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2208,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x2212,
    0xd9, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c0
};

const u16 sTangleVineRedGerutaOam_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x1fb, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x22da,
    0xd5, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x2202,
    0xd3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x2208,
    0xd4, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2208,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x2212,
    0xd9, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c2
};

const u16 sTangleVineRedGerutaOam_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd7, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22dc,
    0xd7, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x2202,
    0xd5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x2208,
    0xd6, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2208,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x2212,
    0xdb, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sTangleVineRedGerutaOam_Frame3[28] = {
    0x9,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22da,
    0xd6, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x2202,
    0xd4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2208,
    0xd5, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2208,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x2212,
    0xda, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c6
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame0[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame2[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame4[16] = {
    0x5,
    0xf5, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x210
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame6[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame3[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame5[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x208,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x208,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame7[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x200,
    0xf9, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x208,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineLarvaRightOam_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOam_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_Y_FLIP | 0x1, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOam_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOam_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOam_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOam_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOam_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOam_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x2313
};

const struct FrameData sTangleVineTallOam_OnGround[5] = {
    sTangleVineTallOam_OnGround_Frame0,
    0xC,
    sTangleVineTallOam_OnGround_Frame1,
    0xC,
    sTangleVineTallOam_OnGround_Frame2,
    0xC,
    sTangleVineTallOam_OnGround_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineMediumOam_OnGround[5] = {
    sTangleVineMediumOam_OnGround_Frame0,
    0xA,
    sTangleVineMediumOam_OnGround_Frame1,
    0xA,
    sTangleVineMediumOam_OnGround_Frame2,
    0xA,
    sTangleVineMediumOam_OnGround_Frame3,
    0xA,
    NULL,
    0x0
};

const struct FrameData sTangleVineShortOam_OnGround[5] = {
    sTangleVineShortOam_OnGround_Frame0,
    0x8,
    sTangleVineShortOam_OnGround_Frame1,
    0x8,
    sTangleVineShortOam_OnGround_Frame2,
    0x8,
    sTangleVineShortOam_OnGround_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sTangleVineCurvedOam_OnGround[7] = {
    sTangleVineCurvedOam_OnGround_Frame0,
    0xA,
    sTangleVineCurvedOam_OnGround_Frame1,
    0xA,
    sTangleVineCurvedOam_OnGround_Frame2,
    0x6,
    sTangleVineCurvedOam_OnGround_Frame3,
    0x6,
    sTangleVineCurvedOam_OnGround_Frame2,
    0x6,
    sTangleVineCurvedOam_OnGround_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineTallOam_OnCeiling[5] = {
    sTangleVineTallOam_OnCeiling_Frame0,
    0xD,
    sTangleVineTallOam_OnCeiling_Frame1,
    0xD,
    sTangleVineTallOam_OnCeiling_Frame2,
    0xD,
    sTangleVineTallOam_OnCeiling_Frame3,
    0xD,
    NULL,
    0x0
};

const struct FrameData sTangleVineMediumOam_OnCeiling[5] = {
    sTangleVineMediumOam_OnCeiling_Frame0,
    0xB,
    sTangleVineMediumOam_OnCeiling_Frame1,
    0xB,
    sTangleVineMediumOam_OnCeiling_Frame2,
    0xB,
    sTangleVineMediumOam_OnCeiling_Frame3,
    0xB,
    NULL,
    0x0
};

const struct FrameData sTangleVineShortOam_OnCeiling[5] = {
    sTangleVineShortOam_OnCeiling_Frame0,
    0x7,
    sTangleVineShortOam_OnCeiling_Frame1,
    0x7,
    sTangleVineShortOam_OnCeiling_Frame2,
    0x7,
    sTangleVineShortOam_OnCeiling_Frame3,
    0x7,
    NULL,
    0x0
};

const struct FrameData sTangleVineCurvedOam_OnCeiling[5] = {
    sTangleVineCurvedOam_OnCeiling_Frame0,
    0x5,
    sTangleVineCurvedOam_OnCeiling_Frame1,
    0x5,
    sTangleVineCurvedOam_OnCeiling_Frame2,
    0x5,
    sTangleVineCurvedOam_OnCeiling_Frame3,
    0x5,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaPartOam_Grip[9] = {
    sTangleVineGerutaPartOam_Grip_Frame0,
    0x4,
    sTangleVineGerutaPartOam_Grip_Frame1,
    0x6,
    sTangleVineGerutaPartOam_Grip_Frame2,
    0x4,
    sTangleVineGerutaPartOam_Grip_Frame3,
    0x6,
    sTangleVineGerutaPartOam_Grip_Frame4,
    0x4,
    sTangleVineGerutaPartOam_Grip_Frame5,
    0x6,
    sTangleVineGerutaPartOam_Grip_Frame0,
    0x4,
    sTangleVineGerutaPartOam_Grip_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaOam_Root[9] = {
    sTangleVineGerutaOam_Root_Frame0,
    0x4,
    sTangleVineGerutaOam_Root_Frame1,
    0x6,
    sTangleVineGerutaOam_Root_Frame2,
    0x4,
    sTangleVineGerutaOam_Root_Frame3,
    0x6,
    sTangleVineGerutaOam_Root_Frame4,
    0x4,
    sTangleVineGerutaOam_Root_Frame5,
    0x6,
    sTangleVineGerutaOam_Root_Frame6,
    0x4,
    sTangleVineGerutaOam_Root_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaOam_Full[5] = {
    sTangleVineGerutaOam_Full_Frame0,
    0xC,
    sTangleVineGerutaOam_Full_Frame1,
    0xC,
    sTangleVineGerutaOam_Full_Frame2,
    0xC,
    sTangleVineGerutaOam_Full_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineRedGerutaOam[5] = {
    sTangleVineRedGerutaOam_Frame0,
    0xC,
    sTangleVineRedGerutaOam_Frame1,
    0xC,
    sTangleVineRedGerutaOam_Frame2,
    0xC,
    sTangleVineRedGerutaOam_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaPartOam_Geruta[9] = {
    sTangleVineGerutaPartOam_Geruta_Frame0,
    0x4,
    sTangleVineGerutaPartOam_Geruta_Frame1,
    0x6,
    sTangleVineGerutaPartOam_Geruta_Frame2,
    0x4,
    sTangleVineGerutaPartOam_Geruta_Frame3,
    0x6,
    sTangleVineGerutaPartOam_Geruta_Frame4,
    0x4,
    sTangleVineGerutaPartOam_Geruta_Frame5,
    0x6,
    sTangleVineGerutaPartOam_Geruta_Frame6,
    0x4,
    sTangleVineGerutaPartOam_Geruta_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineLarvaRightOam[5] = {
    sTangleVineLarvaRightOam_Frame0,
    0xC,
    sTangleVineLarvaRightOam_Frame1,
    0xC,
    sTangleVineLarvaRightOam_Frame2,
    0xC,
    sTangleVineLarvaRightOam_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineLarvaLeftOam[5] = {
    sTangleVineLarvaLeftOam_Frame0,
    0x8,
    sTangleVineLarvaLeftOam_Frame1,
    0x8,
    sTangleVineLarvaLeftOam_Frame2,
    0x8,
    sTangleVineLarvaLeftOam_Frame3,
    0x8,
    NULL,
    0x0
};
