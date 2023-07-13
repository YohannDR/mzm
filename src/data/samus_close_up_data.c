#include "data/samus_close_up_data.h"
#include "macros.h"

const u16 sSamusCloseUpPal[6 * 16] = INCBIN_U16("data/close_up/Palette.pal");
const u32 sSamusCloseUpGfx[2319] = INCBIN_U32("data/close_up/CloseUp.gfx.lz");

const u32 sSamusCloseUpEyesGfx_1[80] = INCBIN_U32("data/close_up/Eyes1.gfx");
const u32 sSamusCloseUpEyesGfx_2[80] = INCBIN_U32("data/close_up/Eyes2.gfx");
const u32 sSamusCloseUpEyesGfx_3[1376] = INCBIN_U32("data/close_up/Eyes3.gfx");

const u32 sSamusCloseUpBackgroundMap[385] = INCBIN_U32("data/close_up/Background.tt");
const u32 sSamusCloseUpEyesTiletable[98] = INCBIN_U32("data/close_up/Eyes.tt");
