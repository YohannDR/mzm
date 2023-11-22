#ifndef FUSION_GALLERY_STRUCT_H
#define FUSION_GALLERY_STRUCT_H

#include "types.h"

#define FUSION_GALLERY_DATA sNonGameplayRamPointer->fusionGallery

#define GALLERY_RESET_BG_POS()\
do {                          \
gBg0YPosition = 0;            \
gBg1YPosition = 0;            \
} while(0);

struct FusionGalleryImageEntry {
    const u32* const pTopGfx;
    const u32* const pBottomGfx;
    const u32* const pTopTileTable;
    const u32* const pBottomTileTable;
    const u16* const pPalette;
};

struct FusionGalleryData {
    u8 stage;
    u8 unk_1;
    u16 unk_2;
    u16 unk_4;
    u8 unk_6;
    u16 unk_8;
    u16 unk_A;
    u16 currentCreditLine;
    u16 unk_E;
    u16 creditLineTilemap_1[32];
    u16 creditLineTilemap_2[32];
    u32 unk_90;
    u16 unk_94;
    u16 unk_96;
    u8 unk_98;
    u8 currentImage;
    u8 language;
    u8 oamLength;
    u8 padding_9C[136];
    u8 unk_124[6];
    u8 unk_12A[17];
    u8 padding_13B[6];
    u8 unk_141;
    u8 endingLettersSpawnDelay[6];
    u8 unk_148[17];
    u8 padding_159[7];
    u8 unk_160[6];
    u8 unk_166[17];
    u8 unk_177;
    u8 unk_178;
    u8 unk_179;
    u8 padding_17A[3];
    u8 unk_17D;
    u16 oamXPositions[30];
    u16 oamYPositions[30];
    const u16* oamFramePointers[30];
    u8 padding_270[79];
    u16 dispcnt;
    u16 bldcnt;
};

#endif /* FUSION_GALLERY_STRUCT_H */
