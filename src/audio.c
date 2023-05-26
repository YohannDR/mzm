#include "audio.h"
#include "macros.h"
#include "gba.h"
#include "syscalls.h"

#include "data/audio.h"

void UpdateMusic(void)
{

}

void UpdatePsgSounds(void)
{

}

/**
 * @brief 1850 | 3a0 | Updates a track data
 * 
 * @param pTrack Track data pointer
 */
void UpdateTrack(struct TrackData* pTrack)
{
    u8 i;
    struct TrackVariables* pVariables;
    u8 var_0;
    u8 var_1;
    i16 var_2;

    if (pTrack->occupied)
        return;

    pTrack->occupied = TRUE;

    if (!(pTrack->unknown_1E & 1))
    {
        if (pTrack->flags & 0xF8)
        {
            if (pTrack->flags & 0x98)
                unk_2d2c(pTrack);
            else
                unk_2e6c(pTrack);
        }

        if (pTrack->flags & 0x2)
        {
            var_1 = unk_4cfc(pTrack);
            while (var_1 != 0)
            {
                for (i = 0, pVariables = pTrack->pVariables; i < pTrack->amountOfTracks; i++, pVariables++)
                {
                    if (pVariables->unknown_0 == 0)
                        continue;

                    if (pVariables->pChannel != NULL)
                        unk_1bf0(pVariables);

                    if (pVariables->pSoundPSG != NULL)
                        unk_1c18(pVariables);

                    if (pVariables->maybe_delayBeforeStart != 0)
                    {
                        pVariables->maybe_delayBeforeStart--;
                        if (pVariables->unknown_15 != 0)
                        {
                            pVariables->unknown_15--;
                        }
                        else
                        {
                            if (pVariables->unknown_10 != 0 && pVariables->unknown_11 != 0)
                            {
                                if (pVariables->pChannel != NULL)
                                {
                                    if (pVariables->pChannel->unknown_0 != 0)
                                    {
                                        pVariables->unknown_16 += pVariables->unknown_10;
                                        if ((i8)(pVariables->unknown_16 - 0x40) < 0)
                                            var_2 = pVariables->unknown_16;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->unknown_16;

                                        if (var_2 != (i8)pVariables->unknown_13)
                                        {
                                            pVariables->unknown_13 = (var_2 * (pVariables->unknown_11 + 1)) >> 7;
                                            unk_1c3c(pVariables);
                                        }
                                    }
                                }
                                else
                                {
                                    if (pVariables->pSoundPSG != NULL && pVariables->pSoundPSG->unknown_0 != 0)
                                    {
                                        pVariables->unknown_16 += pVariables->unknown_10;
                                        if ((i8)(pVariables->unknown_16 - 0x40) < 0)
                                            var_2 = pVariables->unknown_16;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->unknown_16;

                                        if (var_2 != (i8)pVariables->unknown_13)
                                        {
                                            pVariables->unknown_13 = (var_2 * (pVariables->unknown_11 + 1)) >> 7;
                                            unk_1c3c(pVariables);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    while (pVariables->maybe_delayBeforeStart == 0)
                    {
                        var_0 = *pVariables->pRawData;
                        if ((i8)var_0 >= 0)
                            var_0 = pVariables->unknown_3;
                        else if (var_0 > 0xBC)
                        {
                            pVariables->unknown_3 = var_0;
                            pVariables->pRawData++;
                        }

                        if (var_0 > 0xCE)
                        {
                            pVariables->unknown_0 |= 0x2;
                            pVariables->unknown_E = sDelayNoteLengthTable[var_0 - 0xCF];

                            var_0 = *pVariables->pRawData;

                            if (pVariables->unknown_14 != 0)
                                pVariables->unknown_15 = pVariables->unknown_14;

                            if ((i8)var_0 >= 0)
                            {
                                pVariables->unknown_1 = var_0;
                                pVariables->pRawData++;

                                var_0 = *pVariables->pRawData;
                                if ((i8)var_0 >= 0)
                                {
                                    pVariables->unknown_F = var_0;
                                    pVariables->pRawData++;
                                
                                    var_0 = *pVariables->pRawData;
                                    if ((i8)var_0 >= 0)
                                    {
                                        pVariables->unknown_E += var_0;
                                        pVariables->pRawData++;
                                    }
                                }
                            }

                            if ((pVariables->unknown_0 & 0xF0) > 0x3F)
                                unk_4e10(pVariables);

                            pVariables->unknown_13 = 0;
                            unk_4eb4(pVariables);
                            unk_4f10(pVariables);

                            if (pTrack->flags & 0xC0)
                            {
                                if (pVariables->channel & 7)
                                    unk_1fe0(pTrack, pVariables);
                                else
                                    unk_1f3c(pTrack, pVariables);
                            }
                            else
                            {
                                if (pVariables->channel & 7)
                                    unk_1f90(pTrack, pVariables);
                                else
                                    unk_1e2c(pTrack, pVariables);
                            }
                        }
                        else if (var_0 > 0xB0)
                        {
                            if (var_0 == 0xBB)
                            {
                                unk_4d1c(pTrack, pVariables);
                            }
                            else if (var_0 == 0xBD)
                            {
                                unk_22cc(pTrack, pVariables);
                            }
                            else if (var_0 == 0xB1)
                            {
                                unk_2140(pTrack, pVariables);
                                break;
                            }
                            else if (var_0 == 0xB6)
                            {
                                unk_21b0(pTrack, pVariables);
                                break;
                            }
                            else
                            {
                                sMusicCommandFunctionPointers[var_0 - 0xB1](pVariables);
                            }
                        }
                        else
                        {
                            pVariables->maybe_delayBeforeStart = sDelayNoteLengthTable[var_0 - 0x80];
                            pVariables->pRawData++;
                            break;
                        }
                    }


                    if (pVariables->unknown_0 & 4)
                    {
                        unk_4f10(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d5c(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1ddc(pVariables);

                        pVariables->unknown_0 &= ~4;
                    }

                    if (pVariables->unknown_0 & 8)
                    {
                        unk_4eb4(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d78(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1de8(pVariables);

                        pVariables->unknown_0 &= ~8;
                    }
                }
                
                var_1--;
            }
        }
    }

    pTrack->occupied = FALSE;
    if (pTrack->queueFlags == 0x1)
    {
        PlayMusic(pTrack->musicTrack, pTrack->priority);
        pTrack->occupied = TRUE;

        pTrack->musicTrack = 0;
        pTrack->priority = 0;
        pTrack->queueFlags = 0;
        pTrack->occupied = FALSE;
    }
    else if (pTrack->queueFlags & 0x4)
    {
        SoundPlay(pTrack->musicTrack & SHORT_MAX);
        pTrack->occupied = TRUE;

        pTrack->musicTrack = 0;
        pTrack->priority = 0;
        pTrack->queueFlags = 0;
        pTrack->occupied = FALSE;
    }
    else if (pTrack->queueFlags & 0x2)
    {
        if (pTrack->queueFlags & 0x80)
            ReplayQueuedMusic(pTrack->queueFlags);

        pTrack->queueFlags = 0;
    }
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

/**
 * @brief 1ccc | 90 | To document
 * 
 * @param pVariables Track variables pointer
 * @param param_2 To document
 */
void unk_1ccc(struct TrackVariables* pVariables, i16 param_2)
{
    struct PSGSoundData* pSound;
    u16 var_0;
    i16 tmp;

    pSound = pVariables->pSoundPSG;

    if (pVariables->unknown_12 == 1)
    {
        unk_4f10(pVariables);
        pSound->unknown_12 = (pSound->unknown_19 + (i32)pVariables->unknown_13 / sUnk_808cc4d[param_2]) * 16;
        pSound->unknown_F |= 0x20;
    }
    else if (pVariables->unknown_12 == 0)
    {
        unk_4eb4(pVariables);

        var_0 = pVariables->unknown_17 + pVariables->pSoundPSG->unknown_1C;
        tmp = var_0;

        if (tmp >= 0x80)
            var_0 = 0x7F;
        else if (tmp < 0)
            var_0 = 0;

        pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unknown_18);
        pSound->unknown_F |= 0x4;
    }
    else if (pVariables->unknown_12 == 2)
    {
        unk_4f10(pVariables);
        pSound->unknown_F |= 0x10;
    }
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
    // https://decomp.me/scratch/gWp3a

    u8 var_0;
    u8 var_1;
    u8 var_2;
    u8 i;
    struct SoundChannel* pChannel;

    if (pTrack->unknown_3 + pVariables->unknown_B > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unknown_3 + pVariables->unknown_B;

    var_2 = var_0;
    var_1 = FALSE;
    pChannel = NULL;

    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        if (gMusicInfo.soundChannels[i].unknown_0 == 0)
        {
            pChannel = &gMusicInfo.soundChannels[i];
            // break;
        }

        if ((u8)(gMusicInfo.soundChannels[i].unknown_0 - 5) < 2 || gMusicInfo.soundChannels[i].unknown_0 == 8)
        {
            if (!var_1)
                var_1 = TRUE;
        }

        if (!var_1)
        {
            if (gMusicInfo.soundChannels[i].unknown_2 >= var_2 &&
                (gMusicInfo.soundChannels[i].unknown_2 > var_2 ||
                (gMusicInfo.soundChannels[i].pVariables <= pVariables &&
                gMusicInfo.soundChannels[i].pVariables < pVariables)))
            {
                continue;
            }
        }
        else
        {
            continue;
        }

        var_2 = gMusicInfo.soundChannels[i].unknown_2;
        pVariables = gMusicInfo.soundChannels[i].pVariables;
        pChannel = &gMusicInfo.soundChannels[i];
    }

    if (pChannel != NULL)
    {
        unk_4f8c(pChannel, pVariables, var_0);
    }
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

/**
 * @brief 1f90 | 50 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 var_0;
    struct PSGSoundData* pSound;

    if (pTrack->unknown_3 + pVariables->unknown_B > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unknown_3 + pVariables->unknown_B;

    pSound = &gUnk_300376c[pVariables->channel & 7];
    if (pSound->unknown_0 == 0 ||
        (var_0 >= pSound->unknown_16 &&
        (var_0 != pSound->unknown_16 ||
        pVariables <= pSound->pVariables)))
    {
        unk_2030(pSound, pVariables, var_0);
    }
}

/**
 * @brief 1fe0 | 50 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 var_0;
    struct PSGSoundData* pSound;

    if (pTrack->unknown_3 + pVariables->unknown_B > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unknown_3 + pVariables->unknown_B;

    pSound = &gUnk_300376c[pVariables->channel & 7];
    if (pSound->unknown_0 == 0 ||
        (var_0 >= pSound->unknown_16 &&
        (var_0 != pSound->unknown_16 ||
        pVariables <= pSound->pVariables)))
    {
        unk_2030(pSound, pVariables, var_0);
    }
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

/**
 * @brief 20d4 | 6c | Gets the delay for a note (probably)
 * 
 * @param pVariables Track variables pointer
 * @param param_2 Note?
 * @param param_3 To document
 * @return u16 Delay
 */
u16 GetNoteDelay(struct TrackVariables* pVariables, u8 param_2, u8 param_3)
{
    u16 delay;
    u16 temp;

    if ((pVariables->channel & 7) < 4)
    {
        delay = sUnk_808cad0[param_2];
        if (param_3 != 0)
        {
            if (param_2 + 1 > 0x7F)
                param_2 = 0x7F;

            temp = (sUnk_808cad0[param_2 + 1] - delay) * (param_3 + 1) >>8;
            delay += temp;
        }
    }
    else
    {
        delay = sUnk_808cc01[param_2 - 0x15] | (u8)(u32)pVariables->pSample1;
    }
    
    return delay;
}

/**
 * @brief 2140 | 70 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_2140(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct SoundChannel* pNext;

    if (pVariables->pSoundPSG != NULL)
    {
        ClearRegistersForPsg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1);
        pVariables->pSoundPSG->unknown_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->unknown_0 = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannel2;
            pChannel->pChannel2 = NULL;
            pChannel->pChannel1 = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->unknown_4 == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->unknown_4 = 0;
    }

    pVariables->unknown_0 = 0;
}

/**
 * @brief 21b0 | 7c | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_21b0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct SoundChannel* pNext;

    if (pVariables->pSoundPSG != NULL)
    {
        ClearRegistersForPsg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1);
        pVariables->pSoundPSG->unknown_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->unknown_0 = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannel2;
            pChannel->pChannel2 = NULL;
            pChannel->pChannel1 = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->unknown_4 == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->unknown_4 = 0;
        pTrack->queueFlags |= 0x2;
    }

    pVariables->unknown_0 = 0;
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

/**
 * @brief 22cc | c0 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_22cc(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct Voice* pVoice;
    u32 channel;

    pVoice = &pTrack->pVoice[*pVariables->pRawData];
    pVariables->channel = pVoice->instrumentType;

    if (pVariables->channel > 0x3F)
    {
        if (pVariables->channel == 0x80)
        {
            pVariables->unknown_0 |= 0x80;
            pVariables->pSample2 = pVoice->pSample;
        }
        else if (pVariables->channel == 0x40)
        {
            pVariables->unknown_0 |= 0x40;
            pVariables->pSample2 = pVoice->pSample;
            pVariables->envelope2 = pVoice->envelope;
        }
    }
    else
    {
        pVariables->unknown_0 &= 0xF;
        pVariables->unknown_36 = pVoice->unk_2;

        channel = pVariables->channel & 7;

        if (channel == 0)
        {
            pVariables->pSample1 = pVoice->pSample;
        }
        else if (channel < 3)
        {
            if (!(pVoice->unk_3 & 0x80) && pVoice->unk_3 & 0x70)
                pVariables->unknown_37 = pVoice->unk_3;
            else
                pVariables->unknown_37 = 8;

            pVariables->pSample1 = (u32*)((u32)pVoice->pSample << 0x1E >> 0x18);
        }
        else if (channel == 3)
        {
            UploadSampleToWaveRAM(pVoice->pSample);
        }
        else if (channel == 4)
        {
            pVariables->pSample1 = (u32*)((u32)pVoice->pSample << 0x1B >> 0x18);
        }
        
        pVariables->envelope1 = pVoice->envelope;
    }

    pVariables->pRawData++;
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

/**
 * @brief 2460 | 5c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_2460(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct PSGSoundData* pSound;
    u32 var_0;

    if ((i8)*pVariables->pRawData >= 0)
    {
        var_0 = *pVariables->pRawData;
        pVariables->unknown_1 = var_0;
        pVariables->pRawData++;
    }
    else
    {
        var_0 = pVariables->unknown_1;
    }
    
    if (pVariables->pChannel)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
        {
            if ((u8)(pChannel->unknown_0 - 1) < 4 && pChannel->unknown_6 == var_0)
            {
                pChannel->unknown_0 = 5;
                break;
            }
        }
    }

    pSound = pVariables->pSoundPSG;
    if (pSound != NULL && pSound->unknown_17 == var_0)
    {
        pSound->unknown_0 = 5;
        pVariables->pSoundPSG->unknown_18 = 0;
    }
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

/**
 * @brief 24c0 | 5c | Clears the registers for a PSG sound
 * 
 * @param pSound PSG sound pointer
 * @param channel Channel
 */
void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel)
{
    switch (channel)
    {
        case 0:
            write8(REG_SOUND1CNT_H + 1, 8);
            write16(REG_SOUND1CNT_X, 0x8000);
            break;

        case 1:
            write8(REG_SOUND2CNT_L + 1, 8);
            write16(REG_SOUND2CNT_H, 0x8000);
            break;

        case 2:
            write8(REG_SOUND3CNT_L, 0);
            break;

        case 3:
            write8(REG_SOUND4CNT_L + 1, 8);
            write16(REG_SOUND4CNT_H, 0x8000);
            break;
    }
}

/**
 * @brief 251c | 48 | Clears the registers for a PSG sound, unused
 * 
 * @param pSound PSG sound pointer
 * @param channel Channel
 */
void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel)
{
    switch (channel)
    {
        case 0:
            write8(REG_SOUND1CNT_H + 1, 0);
            break;

        case 1:
            write8(REG_SOUND2CNT_L + 1, 0);
            break;

        case 2:
            write8(REG_SOUND3CNT_L, 0);
            break;

        case 3:
            write8(REG_SOUND4CNT_L + 1, 0);
            break;
    }
}
