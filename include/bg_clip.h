#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

// Functions

void BgClipSetBgBlockValue(u8 bg, u16 value, u16 yPosition, u16 xPosition);
void BgClipSetBg1BlockValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipSetRawBG1BlockValue(u32 value, u16 yPosition, u16 xPosition);
void BgClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition);
void BgClipCheckTouchingSpecialClipdata(void);
void BgClipApplyClipdataChangingTransparency(void);
u16 BgClipGetNewBldalphaValue(u16 clip, u16);
void BgClipCheckWalkingOnCrumbleBlock(void);
void BgClipCheckTouchingTransitionOnElevator(void);
void BgClipCheckTouchingTransitionOrTank(void);
void BgClipFinishCollectingTank(void);
void BgClipFinishCollectingAbility(void);
void BgClipCheckGrabbingCrumbleBlock(u8 dontDestroy);
u8 BgClipCheckOpeningHatch(u16 xPosition, u16 yPosition);
void BgClipSetItemAsCollected(u16 xPosition, u16 yPosition, u8 type);
void BgClipRemoveCollectedTanks(void);
void BgClipCallMotherBrainUpdateGlass(u8 stage);

#endif /* BG_CLIP_H */