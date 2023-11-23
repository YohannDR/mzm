#ifndef AUDIO_STRUCT_H
#define AUDIO_STRUCT_H

#include "types.h"

// Structs

struct MusicTrackInfo {
    u16 currentRoomTrack;
    s8 pauseScreenFlag;
    s8 takingNormalTransition;
    s8 unk;
};

struct Envelope {
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct Voice {
    u8 instrumentType;
    u8 pitch;
    u8 unk_2;
    u8 unk_3;
    u32* pSample;
    struct Envelope envelope;
};


struct SoundQueue {
    u8 exists;
    u8 priority;
    u16 fadingTimer;
    const u8* pHeader;
};

struct SoundChannel {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    struct Envelope envelope;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u32* pSize;
    u32 unk_18;
    u32 unk_1C;
    u32* pSample; // Type?
    u8* pData;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannel1;
    struct SoundChannel* pChannel2;
};

struct SoundChannelBackup {
    struct SoundChannel* pChannel;
    struct SoundChannel channel;
};

struct PSGSoundData {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    struct Envelope envelope;
    u16 maybe_noteDelay;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 undefined_13;
    u16 unk_14;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18;
    s8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u32* pSample; // Type?
    struct TrackVariables* pVariables;
};

struct TrackVariables {
    u8 unk_0;
    u8 unk_1;
    u8 delay;
    u8 unk_3;
    u8 volume;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 repeatCount;
    u8 priority;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 lfoSpeed;
    u8 modulationDepth;
    u8 modulationType;
    s8 unk_13;
    u8 unk_14;
    u8 unk_15;
    s8 unk_16;
    s8 unk_17;
    u8 unk_18;
    s8 pitchBend;
    u8 bendRange;
    u8 unk_1B;
    u8 keyShift;
    u8 unk_1D;
    u8 tune;
    u8 unk_1F;
    u32 unk_20;
    const u8* pRawData;
    const u8* patternStartPointers[3];
    u8 channel;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;

    u32* pSample1; // Type?
    struct Envelope envelope1;
    u32* pSample2; // Type?
    struct Envelope envelope2;

    struct SoundChannel* pChannel;
    struct PSGSoundData* pSoundPSG;
};

struct TrackData {
    u8 flags;
    u8 amountOfTracks;

    u8 undefined_2;
    u8 unk_3;
    u8 currentTrack;

    u8 maxAmountOfTracks;
    u16 maybe_volume;
    u16 fadingTimer;

    u16 unk_A;
    u16 unk_C;
    u16 unk_E;

    const u8* pHeader;
    struct Voice* pVoice;
    struct TrackVariables* pVariables;

    u8 occupied;
    u8 unk_1D;
    u8 unk_1E;
    u8 priority;
    u16 musicTrack;
    u8 maxSoundChannels;

    u8 unk_23;
    u16 unk_24;
    u16 unk_26;

    u8 queueFlags;

    u8 undefined_29;
    u8 undefined_2A;
    u8 undefined_2B;
    u8 undefined_2C;
    u8 undefined_2D;
    u8 undefined_2E;
    u8 undefined_2F;
    u8 undefined_30;
    u8 undefined_31;
    u8 undefined_32;

    u8 unk_33;
    u8 unk_34;
    u8 unk_35;

    u8 undefined_36;
    u8 undefined_37;
    u8 undefined_38;
    u8 undefined_39;
    u8 undefined_3A;
    u8 undefined_3B;
    u8 undefined_3C;
    u8 undefined_3D;
    u8 undefined_3E;
    u8 undefined_3F;
};

struct TrackGroupROMData {
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    u16 maxAmountOfTracks;
    u16 unknonw_A;
};

struct SoundEntry {
    const u8* pHeader;
    u16 trackGroundNumber;
    u16 trackGroundNumber_2;
};


struct MusicInfo {
    u8 unk_0;
    u8 occupied;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 maxSoundChannels;
    u8 volume;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 currentSoundChannel;
    u8 volumeDownFlag;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 sampleRate;
    u8 unk_11;
    u16 maybe_frequency;
    u32 unk_14;
    u32 pitch;
    u16 musicTrack;
    u16 unk_1E;
    u8 unk_20;
    u8 priority;
    u16 musicTrackOnTransition;
    u32 musicRawData[768];
    u8 soundRawData[3072];
    struct SoundChannel soundChannels[11];
};


typedef void (*MusicFunc_T)(struct TrackVariables*);

extern u8 gStereoFlag;
extern struct MusicTrackInfo gMusicTrackInfo;

extern struct MusicInfo gMusicInfo;

// Linker variables
extern char gNumMusicPlayers[];
extern char gUnk_Audio0x64[];
extern char gUnk_Audio0x194F700[];
extern char gUnk_Audio0x50[];

extern struct TrackData gTrackData0;
extern struct TrackData gTrackData1;
extern struct TrackData gTrackData2;
extern struct TrackData gTrackData3;
extern struct TrackData gTrackData4;
extern struct TrackData gTrackData5;
extern struct TrackData gTrackData6;
extern struct TrackData gTrackData7;
extern struct TrackData gTrackData8;

extern struct SoundChannelBackup gSoundChannelBackup[7];
extern struct SoundChannelBackup gSoundChannelTrack2Backup[7];
extern struct SoundQueue gSoundQueue[9];

extern struct TrackVariables gTrack0Variables[12];
extern struct TrackVariables gTrack1Variables[10];
extern struct TrackVariables gTrack2Variables[2];
extern struct TrackVariables gTrack3Variables[2];
extern struct TrackVariables gTrack4Variables[2];
extern struct TrackVariables gTrack5Variables[2];
extern struct TrackVariables gTrack6Variables[3];
extern struct TrackVariables gTrack7Variables[1];
extern struct TrackVariables gTrack8Variables[6];

typedef void (*SoundCodeAFunc_T)(struct SoundChannel*, u32*, u8);
typedef u8* (*SoundCodeBFunc_T)(u32*, u32*, u32*, u8);
typedef u8* (*SoundCodeCFunc_T)(u32*, u32*, u8);

extern SoundCodeAFunc_T gSoundCodeAPointer;
extern u8 gSoundCodeA[1624];
extern SoundCodeBFunc_T gSoundCodeBPointer;
extern u8 gSoundCodeB[164];
extern SoundCodeCFunc_T gSoundCodeCPointer;
extern u8 gSoundCodeC[176];

extern struct PSGSoundData gUnk_300376c[];
extern struct PSGSoundData gPsgSounds[4];

#endif
