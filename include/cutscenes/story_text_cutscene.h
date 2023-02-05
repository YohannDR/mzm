#ifndef STORY_TEXT_CUTSCENE
#define STORY_TEXT_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

u8 StoryTextCutsceneInit(void);
u8 StoryTextCutsceneProcessText(void);
u8 StoryTextCutsceneSetVerticalOffset(void);
u8 StoryTextCutsceneFadeIn(void);
u8 StoryTextCutsceneFadeOut(void);
u8 StoryTextCutsceneCheckInput(void);
u8 StoryTextCutsceneEnd(void);
u8 StoryTextCutsceneSubroutine(void);

#endif /* STORY_TEXT_CUTSCENE */
