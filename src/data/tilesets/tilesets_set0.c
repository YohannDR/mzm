#include "data/tilesets/tilesets_set0.h"
#include "data/common_pals.h"
#include "macros.h"

const u32 sTileset_42_Gfx[736] = INCBIN_U32("data/tilesets/42.gfx.lz");
const u32 sTileset_78_Gfx[736] = INCBIN_U32("data/tilesets/78.gfx.lz");
const u32 sTileset_27_Gfx[807] = INCBIN_U32("data/tilesets/27.gfx.lz");

const u32 sTileset_42_Bg_Gfx[591] = INCBIN_U32("data/tilesets/42_Bg.gfx.lz");
const u32 sTileset_27_Bg_Gfx[1487] = INCBIN_U32("data/tilesets/27_Bg.gfx.lz");

const u16 sTileset_42_Pal[14 * 16] = INCBIN_U16("data/tilesets/42.pal");

const u16 sAnimatedPal_7[4 * 16] = INCBIN_U16("data/tilesets/animated_palettes/7.pal");
const u16 sAnimatedPal_16[8 * 16] = INCBIN_U16("data/tilesets/animated_palettes/16.pal");
const u16 sAnimatedPal_0[4 * 16] = INCBIN_U16("data/tilesets/animated_palettes/0.pal");

const u16 sTileset_27_Pal[14 * 16] = INCBIN_U16("data/tilesets/27.pal");

const u16 sAnimatedPal_5[4 * 16 + 1] = INCBIN_U16("data/tilesets/animated_palettes/5.pal");

// Need to be in this file because alignment
const u16 sCommonTilesPal[1 * 16 - 1] = INCBIN_U16("data/common/CommonTiles.pal");
