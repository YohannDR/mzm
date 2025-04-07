#include "data/audio.h"
#include "gba.h"
#include "macros.h"

#include "audio.h"
#include "audio/track_internal.h"

#include "constants/audio_engine.h"

const u16 sUnk_808cad0[128] = {
    0x2c, 0x9d, 0x107, 0x16b, 0x1ca, 0x223, 0x277, 0x2c7, 0x312, 0x358, 0x39b, 0x3da, 0x2c, 0x9d, 0x107, 0x16b,
    0x1ca, 0x223, 0x277, 0x2c7, 0x312, 0x358, 0x39b, 0x3da, 0x2c, 0x9d, 0x107, 0x16b, 0x1ca, 0x223, 0x277, 0x2c7,
    0x312, 0x358, 0x39b, 0x3da, 0x2c, 0x9d, 0x107, 0x16b, 0x1ca, 0x223, 0x277, 0x2c7, 0x312, 0x358, 0x39b, 0x3da,
    0x416, 0x44e, 0x483, 0x4b6, 0x4e5, 0x511, 0x53c, 0x563, 0x589, 0x5ac, 0x5ce, 0x5ed, 0x60b, 0x627, 0x642, 0x65b,
    0x672, 0x689, 0x69e, 0x6b2, 0x6c4, 0x6d6, 0x6e7, 0x6f7, 0x706, 0x714, 0x721, 0x72d, 0x739, 0x744, 0x74f, 0x759,
    0x762, 0x76b, 0x773, 0x77b, 0x783, 0x789, 0x790, 0x797, 0x79d, 0x7a2, 0x7a7, 0x7ac, 0x7b1, 0x7b6, 0x7ba, 0x7be,
    0x7c1, 0x7c5, 0x7c8, 0x7cb, 0x7ce, 0x7d1, 0x7d4, 0x7d6, 0x7d9, 0x7db, 0x7dd, 0x7df, 0x7e1, 0x7e2, 0x7e4, 0x7e6,
    0x7e7, 0x7e9, 0x7ea, 0x7eb, 0x7ec, 0x7ed, 0x7ee, 0x7ef, 0x7f0, 0x7f1, 0x7f2, 0x7f3, 0x7f4, 0x7f4, 0x7f5, 0x7f6
};

const u8 gClockTable[49] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x1c, 0x1e, 0x20, 0x24, 0x28, 0x2a, 0x2c,
    0x30, 0x34, 0x36, 0x38, 0x3c, 0x40, 0x42, 0x44, 0x48, 0x4c, 0x4e, 0x50, 0x54, 0x58, 0x5a, 0x5c,
    0x60
};

const u8 gNoiseTable[60] = {
    0xd7, 0xd6, 0xd5, 0xd4, 0xc7, 0xc6, 0xc5, 0xc4, 0xb7, 0xb6, 0xb5, 0xb4, 0xa7, 0xa6, 0xa5, 0xa4, 0x97, 0x96, 0x95, 0x94,
    0x87, 0x86, 0x85, 0x84, 0x77, 0x76, 0x75, 0x74, 0x67, 0x66, 0x65, 0x64, 0x57, 0x56, 0x55, 0x54, 0x47, 0x46, 0x45, 0x44,
    0x37, 0x36, 0x35, 0x34, 0x27, 0x26, 0x25, 0x24, 0x17, 0x16, 0x15, 0x14, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00
};

const u8 gCgb3Vol[16] = {
    0x0, 0x0,
    0x60, 0x60, 0x60, 0x60,
    0x40, 0x40, 0x40, 0x40,
    0x80, 0x80, 0x80, 0x80,
    0x20, 0x20
};

const u8 sUnk_808cc4d[19] = {
    0x0, 0x20, 0x16, 0x10, 0xd, 0xb, 0xa, 0x8,
    0x8, 0xa, 0xb, 0xd, 0x10, 0x16, 0x20, 0x0,
    0x0, 0x0, 0x0,
};


const u32 sNativeSampleRate[SOUND_MODE_FREQ_END] = {
    0,
    SAMPLES_PER_SECOND(96), SAMPLES_PER_SECOND(132), SAMPLES_PER_SECOND(176),
    SAMPLES_PER_SECOND(224), SAMPLES_PER_SECOND(264), SAMPLES_PER_SECOND(304),
    SAMPLES_PER_SECOND(352), SAMPLES_PER_SECOND(448), SAMPLES_PER_SECOND(528),
    SAMPLES_PER_SECOND(608), SAMPLES_PER_SECOND(672), SAMPLES_PER_SECOND(704)
};

const u32 sMusicPitchData[SOUND_MODE_FREQ_END] = {
    0x0,
    0xB6DEB, 0x85002, 0x63C01,
    0x4E5FF, 0x42801, 0x39C02,
    0x31E00, 0x272FF, 0x21400,
    0x1CE01, 0x1A1FF, 0x18F00
};

const u16 gPcmSamplesPerVBlankTable[SOUND_MODE_FREQ_END] = {
    0,             // unk1          // unk2
    96, 132, 176,  // 6, 8.25, 11   // 16.00, 11.6363, 8.7272
    224, 264, 304, // 14, 16.5, 19  // 6.8571, 5.8181, 5.0526
    352, 448, 528, // 22, 28, 33    // 4.3636, 3.4286, 2.9090
    608, 672, 704, // 38, 42, 44    // 2.5263, 2.2857, 2.1818
};

const u8 sArray_808cce2[512] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
    176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
    192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
    208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
    224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};

const u8 sArray_808cee2[10] = {
    1, 1, 1, 0, 1, 1, 0, 1, 1, 0
};

void* const sDma1ControlPointer = REG_DMA1_CNT;
const u32 sDma1ControlValue = C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED, 4);
static const u16 sAudio_8cef4 = DMA_ENABLE | DMA_START_SPECIAL | DMA_REPEAT | DMA_32BIT;
static const u16 sAudio_8cef6 = DMA_ENABLE | DMA_INTR_ENABLE | DMA_START_SPECIAL | DMA_REPEAT | DMA_32BIT;

const MusicFunc_T sMusicCommandFunctionPointers[30] = {
    [FINE - FINE] = Music_EmptyCommand,
    [GOTO - FINE] = AudioCommand_Goto,
    [PATT - FINE] = AudioCommand_PatternPlay,
    [PEND - FINE] = AudioCommand_PatternEnd,
    [REPT - FINE] = AudioCommand_Repeat,
    [5] = Music_EmptyCommand,
    [6] = Music_EmptyCommand,
    [7] = Music_EmptyCommand,
    [MEMACC - FINE] = Music_EmptyCommand,
    [PRIO - FINE] = AudioCommand_Priority,
    [TEMPO - FINE] = Music_EmptyCommand,
    [KEYSH - FINE] = AudioCommand_KeyShift,
    [VOICE - FINE] = Music_EmptyCommand,
    [VOL - FINE] = AudioCommand_Volume,
    [PAN - FINE] = AudioCommand_PanPot,
    [BEND - FINE] = AudioCommand_PitchBend,
    [BENDR - FINE] = AudioCommand_BendRange,
    [LFOS - FINE] = AudioCommand_LfoSpeed,
    [LFODL - FINE] = AudioCommand_LfoDelay,
    [MOD - FINE] = AudioCommand_ModulationDepth,
    [MODT - FINE] = AudioCommand_ModulationType,
    [21] = Music_EmptyCommand,
    [22] = Music_EmptyCommand,
    [TUNE - FINE] = AudioCommand_Tune,
    [24] = Music_EmptyCommand,
    [25] = Music_EmptyCommand,
    [26] = Music_EmptyCommand,
    [27] = Music_EmptyCommand,
    [XCMD - FINE] = AudioCommand_ExtendCommand,
    [EOT - FINE] = AudioCommand_EndOfTie
};
