#ifndef CHOZODIA_ESCAPE_STRUCT_H
#define CHOZODIA_ESCAPE_STRUCT_H

#include "types.h"

#define CHOZODIA_ESCAPE_DATA sNonGameplayRamPointer->chozodiaEscape

#define CHOZODIA_ESCAPE_MAX_OBJECTS 5

struct ChozodiaEscapeData {
    u8 stage;
    u8 unk_1;
    u8 unk_2;
    u16 timer;
    u8 oamTypes[CHOZODIA_ESCAPE_MAX_OBJECTS];
    const u16* const oamPointers[CHOZODIA_ESCAPE_MAX_OBJECTS];
    u8 unk_20[CHOZODIA_ESCAPE_MAX_OBJECTS];
    u8 unk_25[CHOZODIA_ESCAPE_MAX_OBJECTS];
    u16 oamXPositions[CHOZODIA_ESCAPE_MAX_OBJECTS];
    u16 oamYPositions[CHOZODIA_ESCAPE_MAX_OBJECTS];
    u8 unk_3E[CHOZODIA_ESCAPE_MAX_OBJECTS];

    i16 oamXOffset;
    u8 padding_46[8];
    i16 oamYOffset;

    u8 padding_51[18];
    i16 oamDivisor;
    u8 padding_64[8];

    u8 hblankCode[128];
    u16 explosionHazeValues[2][160];
    u16 unk_36c;
    u8 unk_36e;
    u8 unk_36f;

    u16 dispcnt;
    u16 bldcnt;
    u16 monochromePalette[16 * 16];
};

#endif /* CHOZODIA_ESCAPE_STRUCT_H */
