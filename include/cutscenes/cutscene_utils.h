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
void CutsceneStartSpriteEffect(u16 bldcnt, u8 bldy, u32 interval, u8 intensity);
void CutsceneStartBackgroundEffect(u16 bldcnt, u8 bldalphaL, u8 bldalphaH, u32 interval, u8 intensity);
void CutsceneReset(void);
void CutsceneFadeScreenToBlack(void);
void CutsceneFadeScreenToWhite(void);
u32 CutsceneTransferAndUpdateFade(void);
void CutsceneTransferFade(void);
u8 CutsceneStartBackgroundFading(u8 type);
u8 CutsceneUpdateFading(void);
#ifdef DEBUG
void CutsceneCheckSkipStage(u8 fade);
#endif // DEBUG

#endif // CUTSCENE_UTILS_H
