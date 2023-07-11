#ifndef TITLE_SCREEN_MENU_H
#define TITLE_SCREEN_MENU_H

#include "types.h"
#include "structs/menus/title_screen.h"

void TitleScreenSetBGCNTPageData(const struct TitleScreenPageData* const pPageData);
void TitleScreenLoadPageData(const struct TitleScreenPageData* const pPageData);
void TitleScreenLoadPageData_Copy(const struct TitleScreenPageData* const pPageData);
void TitleScreenUpdateOamId(u8 offset, u8 oamId);
void TitleScreenCallProcessOAM(void);
void TitleScreenResetOAM(void);
u32 TitleScreenFadingIn(void);
u32 TitleScreenFadingOut(u8 intensity, u8 delay);
void unk_76710(u8 param_1);
void unk_767a4(void);
void TitleScreenUpdateAnimatedPalette(void);
void unk_76978(u8 param_1);
u32 unk_76a98(void);
u32 TitleScreenCometsView(void);
void TitleScreenTransferGroundGraphics(void);
void TitleScreenProcessOAM(void);
void TitleScreenProcessComets(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam, u8 cometNumber);
void TitleScreenProcessTopSparkle(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam);
u32 TitleScreenProcessBottomSparkle(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam);
s8 TitleScreenCheckPlayEffects(void);
u32 TitleScreenSubroutine(void);
u32 TitleScreenIdle(void);
void TitleScreenSetIdleStage(u8 stage);
void TitleScreenInit(void);
void TitleScreenVBlank(void);
void TitleScreenVBlank_Empty(void);
void unk_777d8(u8 param_1);
void unk_77824(u8* param_1, u16* dst, u8 palette);

#endif /* TITLE_SCREEN_MENU_H */
