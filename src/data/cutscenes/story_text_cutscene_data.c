#include "data/cutscenes/story_text_cutscene_data.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sStoryTextCutscenePagesData[1] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x14,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    }
};

const u32 sStoryTextCutsceneGfx_Unused[645] = INCBIN_U32("data/cutscenes/StoryText/UnusedLetters.gfx.lz");
const u16 sStoryTextCutscenePAL[1 * 16] = INCBIN_U16("data/cutscenes/StoryText/Palette.pal");
const u32 sStoryTextCutsceneTileTable[347] = INCBIN_U32("data/cutscenes/StoryText/Text.tt");
