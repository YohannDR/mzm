#ifndef ENDING_AND_GALLERY_STRUCT_H
#define ENDING_AND_GALLERY_STRUCT_H

#include "types.h"

#define ENDING_DATA sNonGameplayRamPointer->ending

struct EndingData {
    u8 stage;
    u8 unk_1;
    u8 endScreenTimer;
    u16 timer;
    u8 unk_6;
    u16 unk_8;
    u16 unk_A;
    u16 currentCreditLine;
    u16 unk_E;
    u16 creditLineTilemap_1[32];
    u16 creditLineTilemap_2[32];
    u32 unk_90;
    u32 unk_94;
    u8 endingNumber;
    u8 completionPercentage;
    u8 language;
    u8 oamLength;
    u8 padding_9C[136];
    u8 unk_124[6];
    u8 unk_12A[17];
    u8 padding_13B[6];
    u8 unk_141;
    u8 unk_142[6];
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
    u16* oamFramePointers[30];
    u8 padding_270[79];
    u16 dispcnt;
    u16 bldcnt;
};

#endif /* ENDING_AND_GALLERY_STRUCT_H */
