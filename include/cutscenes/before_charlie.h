#ifndef BEFORE_CHARLIE_CUTSCENE
#define BEFORE_CHARLIE_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"
#include "macros.h"

#include "data/cutscenes/before_charlie_data.h"

struct BeforeCharlieEwramData {
    u16 wallPal[ARRAY_SIZE(sBeforeCharlieChozoWallPal)];

    u8 padding_100[0x300];

    u16 wallPalMonochromeTransition[ARRAY_SIZE(sBeforeCharlieChozoWallPal) * 2];
    
    u8 padding_500[0x3200];

    u16 wallPalMonochrome[ARRAY_SIZE(sBeforeCharlieChozoWallPal)];
};

#define BEFORE_CHARLIE_EWRAM sEwramPointer->beforeCharlie

u8 BeforeCharlieSamusCloseUp(void);
u8 BeforeCharlieWallAndGreyVoice(void);
void BeforeCharlieWallAndGreyVoiceScrollAndLoadYoungSamusGfx(struct CutsceneGraphicsData* pGraphics);
void BeforeCharlieWallAndGreyVoiceApplyMonochrome(struct CutsceneGraphicsData* pGraphics);
void BeforeCharlieWallAndGreyScrollCloseUp(struct CutsceneGraphicsData* pGraphics);
u8 BeforeCharlieChozoWallSides(void);
u8 BeforeCharlieInit(void);
u8 BeforeCharlieSubroutine(void);

#endif /* BEFORE_CHARLIE_CUTSCENE */
