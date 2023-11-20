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
    s16 xOffset;
    s16 yOffset;
};

struct LastTank {
    u16 behavior;
    u8 xPosition;
    u8 yPosition;
};

struct ItemInfo {
    u8 room;
    s8 type;
    u8 xPosition;
    u8 yPosition;
};

// Globals

#define MAX_AMOUNT_OF_ITEMS_PER_AREA 64

extern struct ItemInfo gItemsCollected[MAX_AMOUNT_OF_AREAS][MAX_AMOUNT_OF_ITEMS_PER_AREA];
extern u8 gNeverReformBlocks[MAX_AMOUNT_OF_AREAS][512];
extern u8 gNumberOfNeverReformBlocks[MAX_AMOUNT_OF_AREAS];
extern u8 gNumberOfItemsCollected[MAX_AMOUNT_OF_AREAS];
extern struct LastTank gLastTankCollected;
extern struct BackgroundPointersAndDimensions gBgPointersAndDimensions;

extern struct BG2Movement gBg2Movement;
extern struct BG3Movement gBg3Movement;
extern struct BG0Movement gBg0Movement;

extern u16 gBg0XPosition;
extern u16 gBg0YPosition;
extern u16 gBg1XPosition;
extern u16 gBg1YPosition;
extern u16 gBg2XPosition;
extern u16 gBg2YPosition;
extern u16 gBg3XPosition;
extern u16 gBg3YPosition;

extern s8 gCollectingTank;
extern u8 gDisableDoorAndTanks;
extern u8 gDisableClipdataChangingTransparency;

#endif