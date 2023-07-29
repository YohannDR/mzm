#ifndef CUTSCENE_UTILS_H
#define CUTSCENE_UTILS_H

#include "types.h"
#include "structs/cutscene.h"

u8 CutsceneDefaultRoutine(void);
u8 TourianEscapeSubroutine(void);
void CutsceneUpdateMusicAfterSkip(void);
void CutsceneEnd(void);
u8 CutsceneSubroutine(void);
u8 CutsceneEndFunction(void);
void CutsceneVBlank(void);
void CutsceneLoadingVBlank(void);
void CutsceneInit(void);
void CutsceneSetBgcntPageData(struct CutscenePageData pageData);
void CutsceneSetBgcnt(u16 value, u16 bg);
void CutsceneSetBackgroundPosition(u8 type, u16 bg, u16 value);
u16* CutsceneGetBgHorizontalPointer(u16 bg);
u16* CutsceneGetBgVerticalPointer(u16 bg);
u32 CutsceneStartBackgroundScrolling(struct CutsceneScrollingInfo scrollingData, u16 bg);
void CutsceneUpdateBackgroundScrolling(struct CutsceneScrolling* pScrolling);
u8 CutsceneCheckBackgroundScrollingActive(u16 bg);
void CutsceneUpdateBackgroundsPosition(u8 updateScrolling);
void CutsceneUpdateScreenShake(u8 affectVertical, struct CutsceneScreenShake* pShake);
void CutsceneStartScreenShake(struct CutsceneScreenShakeInfo shakeInfo, u16 bg);
void CutsceneUpdateSpecialEffect(void);
void CutsceneStartSpriteEffect(u16 bldcnt, u8 bldy, u8 interval, u8 intensity);
void CutsceneStartBackgroundEffect(u16 bldcnt, u8 bldalphaL, u8 bldalphaH, u8 interval, u8 intensity);
void CutsceneReset(void);
void unk_61f0c(void);
void unk_61f28(void);
u32 unk_61f44(void);
void unk_61f60(void);
u8 CutsceneStartBackgroundFading(u8 type);
u8 CutsceneUpdateFading(void);

#endif