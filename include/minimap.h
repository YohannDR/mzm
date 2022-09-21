#ifndef MINIMAP_H
#define MINIMAP_H

#include "types.h"
#include "connection.h"

#define MINIMAP_SIZE 32

extern u32 gMinimapTilesWithObtainedItems[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE];
extern u32 gVisitedMinimapTiles[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE];
extern u16 gDecompressedMinimapVisitedTiles[MINIMAP_SIZE * MINIMAP_SIZE];
extern u16 gDecompressedMinimapData[MINIMAP_SIZE * MINIMAP_SIZE];
extern u8 gMinimapX;
extern u8 gMinimapY;
extern u8 gUpdateMinimapFlag;
extern u32 gMinimapTilesGFX[5 * 24];

extern struct LastAreaName gLastAreaNameVisited;

#define MINIMAP_UPDATE_FLAG_NONE 0x0
#define MINIMAP_UPDATE_FLAG_UPPER_LINE 0x1
#define MINIMAP_UPDATE_FLAG_MIDDLE_LINE 0x2
#define MINIMAP_UPDATE_FLAG_LOWER_LINE 0x3

typedef void (*MinimapFunc_T)(u32*, u16*, u8);

struct LastAreaName {
    u8 flags;
    u8 area;
    u8 mapX;
    u8 mapY;
};

void MinimapUpdate(void);
void MinimapSetTileAsExplored(void);
void MinimapCheckSetAreaNameAsExplored(u8 afterTransition);
void MinimapCheckForUnexploredTile(void);
void MinimapCheckOnTransition(void);
void MinimapUpdateForExploredTiles(void);
void MinimapDraw(void);
void MinimapCopyTileGFX(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXFlippedGFX(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileYFlippedGFX(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXYFlippedGFX(u32* dst, u16* pTile, u8 palette);
void MinimapSetTilesWithObtainedItems(u8 area, u16* dst);
void MinimapSetDownloadedTiles(u8 area, u16* dst);
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition);
u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition);
void MinimapLoadTilesWithObtainedItems(void);
void MinimapUpdateChunk(u8 event);

#endif /* MINIMAP_H */