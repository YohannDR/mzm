#ifndef MINIMAP_STRUCT_H
#define MINIMAP_STRUCT_H

#include "types.h"
#include "structs/connection.h"

#define MINIMAP_SIZE 32

typedef void (*MinimapFunc_T)(u32*, u16*, u8);

struct LastAreaName {
    u8 flags;
    u8 area;
    u8 mapX;
    u8 mapY;
};

extern struct LastAreaName gLastAreaNameVisited;
extern u32 gMinimapTilesWithObtainedItems[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE * 2];
extern u32 gVisitedMinimapTiles[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE];
extern u16 gDecompressedMinimapVisitedTiles[MINIMAP_SIZE * MINIMAP_SIZE];
extern u16 gDecompressedMinimapData[MINIMAP_SIZE * MINIMAP_SIZE];
extern u8 gMinimapX;
extern u8 gMinimapY;
extern u8 gUpdateMinimapFlag;
extern u32 gMinimapTilesGfx[5 * 24];

#endif