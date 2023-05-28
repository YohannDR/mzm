#ifndef MINIMAP_H
#define MINIMAP_H

#include "types.h"

void MinimapUpdate(void);
void MinimapSetTileAsExplored(void);
void MinimapCheckSetAreaNameAsExplored(u8 afterTransition);
void MinimapCheckForUnexploredTile(void);
void MinimapCheckOnTransition(void);
void MinimapUpdateForExploredTiles(void);
void MinimapDraw(void);
void MinimapCopyTileGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileYFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXYFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapSetTilesWithObtainedItems(u8 area, u16* dst);
void MinimapSetDownloadedTiles(u8 area, u16* dst);
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition);
u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition);
void MinimapLoadTilesWithObtainedItems(void);
void MinimapUpdateChunk(u8 event);

#endif /* MINIMAP_H */