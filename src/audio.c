#include "audio.h"
#include "macros.h"
#include "syscalls.h"

void UpdateMusic(void)
{

}

void UpdatePsgSounds(void)
{

}

void UpdateTrack(struct TrackData* pTrack)
{

}

/**
 * @brief 1bf0 | 28 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1bf0(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
    {
        if (pChannel->unknown_E != 0 && pChannel->unknown_E-- == 1)
            pChannel->unknown_0 = 5;
    }
}

/**
 * @brief 1c18 | 24 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1c18(struct TrackVariables* pVariables)
{
    struct PSGSoundData* pSound;

    pSound = pVariables->pSoundPSG;

    if (pVariables->unknown_E != 0)
    {
        if (pVariables->unknown_E-- == 1)
        {
            pSound->unknown_0 = 5;
            pSound->unknown_18 = 0;
        }
    }
}

/**
 * @brief 1c3c | 90 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1c3c(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    i32 frequency;
    u16 midiKey;
    i16 tmp;

    pChannel = pVariables->pChannel;

    switch (pVariables->unknown_12)
    {
        case 1:
        case 2:
            unk_4f10(pVariables);
            for (; pChannel != NULL; pChannel = pChannel->pChannel2)
                pChannel->unknown_13 |= 0x10;
            break;
        
        case 0:
            unk_4eb4(pVariables);

            if (pChannel->unknown_1 != 0 && pChannel->unknown_1 != 0x20)
                break;

            for (; pChannel != NULL; pChannel = pChannel->pChannel2)
            {
                midiKey = pVariables->unknown_17 + pChannel->unknown_7;
                tmp = midiKey;

                if (tmp >= 0x80)
                    midiKey = 0x7F;
                else if (tmp < 0)
                    midiKey = 0;

                frequency = Midikey2Freq(pVariables->pSample1, midiKey, pVariables->unknown_18);
                pChannel->unknown_1C = frequency;

                if (frequency == gMusicInfo.maybe_frequency)
                    frequency = 0x4000;
                else
                    frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

                pChannel->unknown_1C = frequency;
            }
    }
}

void unk_1ccc(struct TrackVariables* pVariables, u16 param_2)
{

}

/**
 * @brief 1d5c | 1c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1d5c(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
        pChannel->unknown_13 |= 0x10;
}

/**
 * @brief 1d78 | 64 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1d78(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    i32 frequency;
    u16 midiKey;
    i16 tmp;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
    {
        midiKey = pVariables->unknown_17 + pChannel->unknown_7;
        tmp = midiKey;

        if (tmp >= 0x80)
            midiKey = 0x7F;
        else if (tmp < 0)
            midiKey = 0;

        frequency = Midikey2Freq(pChannel->pSample, midiKey, pVariables->unknown_18);
        pChannel->unknown_1C = frequency;

        if (frequency == gMusicInfo.maybe_frequency)
            frequency = 0x4000;
        else
            frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

        pChannel->unknown_1C = frequency;
        pChannel->unknown_13 |= 4;
    }
}

/**
 * @brief 1ddc | c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1ddc(struct TrackVariables* pVariables)
{
    pVariables->pSoundPSG->unknown_F |= 0x10;
}

/**
 * @brief 1de8 | 44 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1de8(struct TrackVariables* pVariables)
{
    u16 var_0;
    i16 tmp;

    var_0 = pVariables->unknown_17 + pVariables->pSoundPSG->unknown_1C;
    tmp = var_0;

    if (tmp >= 0x80)
        var_0 = 0x7F;
    else if (tmp < 0)
        var_0 = 0;

    pVariables->pSoundPSG->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unknown_18);
    pVariables->pSoundPSG->unknown_F |= 0x4;
}

void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

/**
 * @brief 1f3c | 54 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_1f3c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    if (pTrack->flags & 0x80)
    {
        if (++pTrack->unknown_23 <= pTrack->maxSoundChannels)
            unk_1e2c(pTrack, pVariables);
    }
    else if (pTrack->flags & 0x40)
    {
        if (++pTrack->unknown_23 <= pTrack->maxSoundChannels)
            unk_1e2c(pTrack, pVariables);
    }
}

void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

/**
 * @brief 2030 | 74 | To document
 * 
 * @param pSound PSG sound pointer
 * @param pVariables Track variables pointer
 * @param param_3 To document
 */
void unk_2030(struct PSGSoundData* pSound, struct TrackVariables* pVariables, u32 param_3)
{
    u16 var_0;
    i16 tmp;

    pSound->unknown_16 = param_3;
    pSound->unknown_1 = pVariables->channel;
    pSound->unknown_C = pVariables->unknown_6;
    pSound->unknown_17 = pVariables->unknown_1;

    if ((pVariables->unknown_0 & 0xF0) == 0x80)
        pSound->unknown_1C = pVariables->unknown_35;
    else
        pSound->unknown_1C = pVariables->unknown_1;

    var_0 = pVariables->unknown_17 + pSound->unknown_1C;
    tmp = var_0;

    if (tmp >= 0x80)
        var_0 = 0x7F;
    else if (tmp < 0)
        var_0 = 0;

    pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unknown_18);
    pSound->pVariables->pSoundPSG = NULL;
    pSound->pVariables = pVariables;
    pSound->unknown_F |= 2;
    pSound->unknown_0 = 1;
    pVariables->pSoundPSG = pSound;
}

/**
 * @brief 20a4 | 30 | To document
 * 
 * @param pChannel Sound channel pointer
 */
void unk_20a4(struct SoundChannel* pChannel)
{
    // Linked list?
    if (pChannel->pVariables != NULL)
    {
        if (pChannel->pChannel2 != NULL)
            pChannel->pChannel2->pChannel1 = pChannel->pChannel1;

        if (pChannel->pChannel1 != NULL)
            pChannel->pChannel1->pChannel2 = pChannel->pChannel2;
        else
            pChannel->pVariables->pChannel = pChannel->pChannel2;

        pChannel->pVariables = NULL;
    }
}

u16 GetNoteDelay(struct TrackVariables* pVariables, u8 param_2, u8 param_3)
{

}

void unk_2140(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_21b0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

/**
 * @brief 222c | 38 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_222c(struct TrackVariables* pVariables)
{
    i8 i;

    pVariables->pRawData++;

    for (i = ARRAY_SIZE(pVariables->unknown_28) - 1; i >= 0; i--)
    {
        if (pVariables->unknown_28[i])
        {
            pVariables->pRawData = pVariables->unknown_28[i];
            pVariables->unknown_28[i] = NULL;
            break;
        }
    }
}

/**
 * @brief 2264 | 40 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_2264(struct TrackVariables* pVariables)
{
    if (pVariables->unknown_A == 0)
    {
        pVariables->pRawData++;
        pVariables->unknown_A = *pVariables->pRawData;
        unk_5070(pVariables);
        return;
    }

    if (--pVariables->unknown_A == 0)
    {
        unk_222c(pVariables);
        return;
    }

    pVariables->pRawData++;
    unk_5070(pVariables);
}

/**
 * @brief 22a4 | 10 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_22a4(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->unknown_B = *pVariables->pRawData++;
}

/**
 * @brief 22b4 | 18 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_22b4(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->unknown_1C = *pVariables->pRawData;
    pVariables->unknown_0 |= 0x8;
    pVariables->pRawData++;
}

void unk_22cc(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

/**
 * @brief 238c | 14 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_238c(struct TrackVariables* pVariables)
{
    pVariables->unknown_4 = *pVariables->pRawData;
    pVariables->unknown_0 |= 0x4;
    pVariables->pRawData++;
}

/**
 * @brief 23a0 | 14 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_23a0(struct TrackVariables* pVariables)
{
    pVariables->unknown_6 = *pVariables->pRawData;
    pVariables->unknown_0 |= 0x4;
    pVariables->pRawData++;
}

/**
 * @brief 23b4 | 18 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_23b4(struct TrackVariables* pVariables)
{
    pVariables->unknown_19 = *pVariables->pRawData - 0x40;
    pVariables->unknown_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 23cc | 18 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_23cc(struct TrackVariables* pVariables)
{
    pVariables->unknown_1A = *pVariables->pRawData;
    pVariables->unknown_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 23e0 | 10 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_23e0(struct TrackVariables* pVariables)
{
    pVariables->unknown_10 = (*pVariables->pRawData + 1) / 2;
    pVariables->pRawData++;
}

/**
 * @brief 23f0 | 10 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_23f0(struct TrackVariables* pVariables)
{
    u8 temp;

    temp = *pVariables->pRawData;
    pVariables->unknown_14 = temp;
    pVariables->unknown_15 = temp;
    pVariables->pRawData++;
}

/**
 * @brief 2400 | c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_2400(struct TrackVariables* pVariables)
{
    pVariables->unknown_11 = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 240c | c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_240c(struct TrackVariables* pVariables)
{
    pVariables->unknown_12 = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 2418 | 18 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_2418(struct TrackVariables* pVariables)
{
    pVariables->unknown_1E = *pVariables->pRawData - 0x40;
    pVariables->unknown_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 2430 | 30 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_2430(struct TrackVariables* pVariables)
{
    if (*pVariables->pRawData == 8)
    {
        pVariables->pRawData++;
        pVariables->unknown_C = *pVariables->pRawData;
        pVariables->pRawData++;
    }

    if (*pVariables->pRawData == 9)
    {
        pVariables->pRawData++;
        pVariables->unknown_D = *pVariables->pRawData;
        pVariables->pRawData++;
    }
}

void unk_2460(struct TrackVariables* pVariables)
{

}

/**
 * @brief 24bc | 4 | Empty function
 * 
 * @param pVariables Track variables pointer
 */
void Music_Empty(struct TrackVariables* pVariables)
{
    return;
}

void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel)
{

}

void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel)
{

}

