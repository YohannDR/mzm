#ifndef BG_CLIP_H
#define BG_CLIP_H

#include "types.h"
#include "connection.h"

// Structs

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

struct ItemInfo {
    u8 room;
    i8 type;
    u8 xPosition;
    u8 yPosition;
};

struct TankCollectionData {
    u16 behaviors[4];
    u16 yPositions[3];
    u16 xPositions[3];
};

// Globals

#define MAX_AMOUNT_OF_ITEMS_PER_AREA 64

extern struct ItemInfo gItemsCollected[MAX_AMOUNT_OF_AREAS][MAX_AMOUNT_OF_ITEMS_PER_AREA];
extern u8 gNeverReformBlocks[MAX_AMOUNT_OF_AREAS][512];
extern u8 gNumberOfNeverReformBlocks[MAX_AMOUNT_OF_AREAS];
extern u8 gNumberOfItemsCollected[MAX_AMOUNT_OF_AREAS];
extern struct LastTank gLastTankCollected;

extern u16 gBG0XPosition;
extern u16 gBG0YPosition;
extern u16 gBG1XPosition;
extern u16 gBG1YPosition;
extern u16 gBG2XPosition;
extern u16 gBG2YPosition;
extern u16 gBG3XPosition;
extern u16 gBG3YPosition;

// Functions

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition);
void BGClipSetBG1BlockValue(u32 value, u16 yPosition, u16 xPosition);
void BGClipSetRawBG1BlockValue(u32 value, u16 yPosition, u16 xPosition);
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
void BGClipSetItemAsCollected(u16 xPosition, u16 yPosition, u8 type);
void BGClipRemoveCollectedTanks(void);
void BGClipCallMotherBrainUpdateGlass(u8 stage);

#endif /* BG_CLIP_H */