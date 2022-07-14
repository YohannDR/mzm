#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"

struct BackgroundPointersAndDimensions {
    struct SubBGPtr {
        u16* decompressed;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* clipdata_decompressed;
    u16 clipdata_width;
    u16 clipdata_height;
};

struct BG2Movement {
    i16 x_offset;
    i16 y_offset;
};

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 y_position, u16 x_position);
void BGClipSetBG1BlockValue(u16 value, u16 y_position, u16 x_position);
void BGClipSetRawBG1BlockValue(u16 value, u16 y_position, u16 x_position);
void BGClipSetClipdataBlockValue(u16 value, u16 y_position, u16 x_position);
void BGClipCheckTouchingSpecialClipdata(void);
void BGClipApplyClipdataChangingTransparency(void);
u16 BGClipGetNewBLDALPHAValue(u16 clip);
void BGClipCheckWalkingOnCrumbleBlock(void);
void BGClipCheckTouchingTransitionOnElevator(void);
void BGClipCheckTouchingTransitionOrTank(void);
void BGClipFinishCollectingTank(void);
void BGClipFinishCollectingAbility(void);
void BGClipCheckGrabbingCrumnbleBlock(u8 false);
u8 BGClipCheckOpeningHatch(u16 x_position, u16 y_position);
void BGClipSetItemAsCollected(u8 x_position, u8 y_position, u8 type);
void BGClipRemoveCollectedTanks(void);
void BGClipCallMotherBrainUpdateGlass(u8 stage);

#endif /* BG_CLIP_H */