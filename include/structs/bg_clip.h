#ifndef BG_CLIP_STRUCT_H
#define BG_CLIP_STRUCT_H

#include "types.h"
#include "structs/connection.h"

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
extern struct BackgroundPointersAndDimensions gBGPointersAndDimensions;

extern struct BG2Movement gBG2Movement;
extern struct BG3Movement gBG3Movement;
extern struct BG0Movement gBG0Movement;

extern u16 gBG0XPosition;
extern u16 gBG0YPosition;
extern u16 gBG1XPosition;
extern u16 gBG1YPosition;
extern u16 gBG2XPosition;
extern u16 gBG2YPosition;
extern u16 gBG3XPosition;
extern u16 gBG3YPosition;

extern i8 gCollectingTank;
extern u8 gDisableDoorAndTanks;
extern u8 gDisableClipdataChangingTransparency;

#endif