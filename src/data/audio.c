#include "data/audio.h"
#include "macros.h"

const u8 sTempArray_8cad0[0x412] = INCBIN_U8("data/Blob_8cad0_8cee2.bin");

const u8 sArray_808cee2[10] = {
    1, 1, 1, 0, 1, 1, 0, 1, 1, 0
};

const u8 sTempArray_8ceec[0x2368] = INCBIN_U8("data/Blob_8ceec_8f253.bin");

const struct TrackGroupROMData sMusicTrackDataROM[9] = {
    [0] = {
        .pTrack = &gTrackData0,
        .pVariables = gTrack0Variables,
        .maxAmountOfTracks = 12,
        .unknonw_A = 1
    },
    [1] = {
        .pTrack = &gTrackData1,
        .pVariables = gTrack1Variables,
        .maxAmountOfTracks = 10,
        .unknonw_A = 1
    },
    [2] = {
        .pTrack = &gTrackData2,
        .pVariables = gTrack2Variables,
        .maxAmountOfTracks = 2,
        .unknonw_A = 1
    },
    [3] = {
        .pTrack = &gTrackData3,
        .pVariables = gTrack3Variables,
        .maxAmountOfTracks = 2,
        .unknonw_A = 0
    },
    [4] = {
        .pTrack = &gTrackData4,
        .pVariables = gTrack4Variables,
        .maxAmountOfTracks = 2,
        .unknonw_A = 1
    },
    [5] = {
        .pTrack = &gTrackData5,
        .pVariables = gTrack5Variables,
        .maxAmountOfTracks = 2,
        .unknonw_A = 1
    },
    [6] = {
        .pTrack = &gTrackData6,
        .pVariables = gTrack6Variables,
        .maxAmountOfTracks = 3,
        .unknonw_A = 0
    },
    [7] = {
        .pTrack = &gTrackData7,
        .pVariables = gTrack7Variables,
        .maxAmountOfTracks = 1,
        .unknonw_A = 1
    },
    [8] = {
        .pTrack = &gTrackData8,
        .pVariables = gTrack8Variables,
        .maxAmountOfTracks = 6,
        .unknonw_A = 1
    },
};

const u8 sTempArray_8f2c0[0x1620] = INCBIN_U8("data/Blob_8f2c0_908df.bin");
// const struct SoundEntry sSoundDataEntries[708] = {0};

const u8 sTempArray_908e0[0x1a1804] = INCBIN_U8("data/Blob_908e0_2320e4.bin");
