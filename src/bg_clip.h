#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

extern struct LastTank gLastTankCollected;

struct BackgroundPointersAndDimensions {
    struct {
        u16* pDecomp;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* pClipDecomp;
    u16 clipdataWidth;
    u16 clipdataHeight;
};

struct BG2Movement {
    i16 xOffset;
    i16 yOffset;
};

struct LastTank {
    u16 behavior;
    u8 xPosition;
    u8 yPosition;
};

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition);
void BGClipSetBG1BlockValue(u16 value, u16 yPosition, u16 xPosition);
void BGClipSetRawBG1BlockValue(u16 value, u16 yPosition, u16 xPosition);
void BGClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition);
void BGClipCheckTouchingSpecialClipdata(void);
void BGClipApplyClipdataChangingTransparency(void);
u16 BGClipGetNewBLDALPHAValue(u16 clip);
void BGClipCheckWalkingOnCrumbleBlock(void);
void BGClipCheckTouchingTransitionOnElevator(void);
void BGClipCheckTouchingTransitionOrTank(void);
void BGClipFinishCollectingTank(void);
void BGClipFinishCollectingAbility(void);
void BGClipCheckGrabbingCrumnbleBlock(u8 dontDestroy);
u8 BGClipCheckOpeningHatch(u16 xPosition, u16 yPosition);
void BGClipSetItemAsCollected(u8 xPosition, u8 yPosition, u8 type);
void BGClipRemoveCollectedTanks(void);
void BGClipCallMotherBrainUpdateGlass(u8 stage);

#endif /* BG_CLIP_H */