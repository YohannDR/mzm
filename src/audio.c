#include "audio.h"
#include "macros.h"
#include "gba.h"
#include "syscalls.h"

#include "data/audio.h"

#include "constants/audio_engine.h"

void UpdateMusic(void)
{
    // https://decomp.me/scratch/bxTYQ

    u32 var_0;
    s16 var_1;
    s16 var_2;
    u32 var_3;
    u16 var_4;
    u32 var_5;
    u8 var_6;
    u8 var_7;
    u8 var_8;
    u8* buffer;
    u8 vcount;
    u32 sampleRate;
    u16 i;
    struct SoundChannel* pChannel;
    struct TrackVariables* pVariables;

    var_0 = gMusicInfo.unk_9;
    if (var_0 != 0)
    {
        vcount = read8(REG_VCOUNT);
        if (vcount < SCREEN_SIZE_Y)
            vcount += VERTICAL_LINE_COUNT;

        var_0 += vcount;
    }

    var_8 = gMusicInfo.unk_10;
    var_4 = gMusicInfo.unk_11 * 16;
    var_7 = (gMusicInfo.unk_C * 2 + var_8) - 1;
    if (var_7 >= gMusicInfo.unk_E)
        var_7 -= gMusicInfo.unk_E;

    var_3 = 0;
    if (var_8 <= var_7 && var_7 <= gMusicInfo.unk_11)
    {
        var_8 = gMusicInfo.unk_C;
        var_4 = (var_7 - var_8 + 1) * 16;
        var_6 = var_8;
        if (var_7 + 1 == gMusicInfo.unk_E)
            var_7 = 0;

        gMusicInfo.unk_11 = var_7;
    }
    else if (gMusicInfo.unk_11 <= var_8 && var_8 <= var_7)
    {
        var_8 = gMusicInfo.unk_C;
        var_4 = (var_7 - var_8 + 1) * 16;
        var_6 = var_8;
        if (var_7 + 1 == gMusicInfo.unk_E)
            var_7 = 0;

        gMusicInfo.unk_C = var_7;
    }
    else if (var_7 <= gMusicInfo.unk_11 && gMusicInfo.unk_11 <= var_8)
    {
        var_4 = 0;
        var_6 = var_7 + 1;
        gMusicInfo.unk_11 = var_6;
    }
    else
    {
        if (gMusicInfo.unk_11 < var_7)
        {
            var_6 = (var_7 - var_6) + 1;
            if (var_7 + 1 == gMusicInfo.unk_E)
                var_7 = 0;

            gMusicInfo.unk_11 = var_7;
        }
        else if (var_8 > var_7)
        {
            var_6 = gMusicInfo.unk_E - var_8;
            var_7++;
            var_3 = var_7;

            gMusicInfo.unk_11 = var_7;
        }
        else
        {
            var_4 = 0;
            var_6 = var_7 + 1;
            gMusicInfo.unk_11 = var_6;
        }
    }


    if (var_6 == 0)
        return;

    buffer = &gMusicInfo.soundRawData[var_4];
    buffer = gSoundCodeBPointer((u32*)buffer, (u32*)buffer, gMusicInfo.musicRawData, var_6 * 8);
    if (var_3 != 0)
        gSoundCodeBPointer((u32*)gMusicInfo.soundRawData, (u32*)gMusicInfo.soundRawData, (u32*)buffer, var_3 * 8);

    gMusicInfo.currentSoundChannel = 0;
    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        if (var_0 != 0)
        {
            vcount = read8(REG_VCOUNT);
            if (vcount < SCREEN_SIZE_Y)
                vcount += VERTICAL_LINE_COUNT;

            if (var_0 <= vcount)
                break;
        }

        pChannel = &gMusicInfo.soundChannels[i];
        if (pChannel->unk_0 == 0)
            continue;

        gMusicInfo.currentSoundChannel++;
        pVariables = pChannel->pVariables;

        while (pChannel->unk_13 != 0)
        {
            if (pChannel->unk_13 & 0x2)
            {
                if (pChannel->unk_1 == 0x20)
                    pChannel->unk_18 = pChannel->pSample[3] << 0xE;
                else
                    pChannel->unk_18 = 0;

                pChannel->unk_10 = 0;
                pChannel->unk_13 &= ~0x2;
                pChannel->unk_13 |= 0x10;
            }
            else if (pChannel->unk_13 & 0x4)
            {
                pChannel->unk_13 &= ~0x4;
            }
            else if (pChannel->unk_13 & 0x10)
            {
                if (pVariables->unk_0 & 0x80)
                {
                    pVariables->unk_6 = pChannel->unk_3;
                    unk_4f10(pVariables);
                }

                pChannel->unk_4 = (pVariables->unk_8 * (pChannel->unk_F + 1)) >> 7;
                pChannel->unk_5 = (pVariables->unk_9 * (pChannel->unk_F + 1)) >> 7;

                pChannel->unk_13 &= ~0x10;
            }
        }

        var_1 = pChannel->unk_10;
        var_5 = pChannel->unk_0 & 0xF;
        if (var_5 == 0xA)
        {
            pChannel->unk_0 = 0;
            continue;
        }
        
        if (var_5 == 0x1)
        {
            if (pChannel->envelope.attack == UCHAR_MAX)
            {
                var_1 = 0;
                pChannel->unk_0 = var_5 = 2;
            }
        }

        switch (var_5)
        {
            case 2:
                var_1 += pChannel->envelope.attack;
                if (var_1 <= 0xFE)
                    break;

                if (pChannel->envelope.decay != 0)
                {
                    var_1 = UCHAR_MAX;
                    pChannel->unk_0 = 3;
                }
                else
                {
                    var_1 = pChannel->envelope.sustain;
                    pChannel->unk_0 = 4;
                    break;
                }

            case 3:
                var_1 = (var_1 * pChannel->envelope.release) >> 4;
                if (var_1 > pChannel->envelope.sustain)
                    break;

                if (pChannel->envelope.sustain != 0)
                {
                    var_1 = pChannel->envelope.sustain;
                    pChannel->unk_0 = 4;
                    break;
                }

            case 5:
                pChannel->unk_0 = 6;

            case 6:
                var_1 = (var_1 * pChannel->envelope.release) >> 4;
                if (var_1 > 0)
                    break;

                pChannel->unk_0 = 0x0;
                if (pChannel->unk_C != 0 && pChannel->unk_D != 0)
                    pChannel->unk_0 = 0x8;
                else
                    unk_20a4(pChannel);
                break;

            case 8:
                pChannel->unk_D--;
                if (pChannel->unk_D == 0)
                {
                    pChannel->unk_0 = 0;
                    unk_20a4(pChannel);
                }
                break;
        }

        pChannel->unk_10 = var_1;
        var_2 = (var_1 * (gMusicInfo.volume + 1)) >> 4;
        pChannel->unk_11 = var_2 * pChannel->unk_4 >> 8;
        pChannel->unk_12 = var_2 * pChannel->unk_5 >> 8;
        gSoundCodeAPointer(pChannel, gMusicInfo.musicRawData, 0);
    }

    buffer = &gMusicInfo.soundRawData[var_4];
    buffer = gSoundCodeCPointer((u32*)buffer, gMusicInfo.musicRawData, (var_6 + var_3) * 4);
    if (var_3 != 0)
    {
        gSoundCodeCPointer((u32*)gMusicInfo.soundRawData, (u32*)buffer, var_3 * 4);
    }
}

void UpdatePsgSounds(void)
{
    // https://decomp.me/scratch/1qI1m

    s16 var_0;
    u8 control;
    u8 i;
    u8* ptr;
    struct PSGSoundData* pSound;
    struct TrackVariables* pVariables;

    var_0 = FALSE;

    for (i = 0; i < ARRAY_SIZE(gPsgSounds); i++)
    {
        pSound = &gPsgSounds[i];

        if (pSound->unk_0 == 0)
            continue;

        while (pSound->unk_F)
        {
            if (pSound->unk_F & 0x2)
            {
                pVariables = pSound->pVariables;

                pSound->unk_A = pVariables->unk_F;
                pSound->unk_B = pVariables->volume;
                pSound->unk_D = pVariables->unk_C;
                pSound->unk_E = pVariables->unk_D;
                pSound->unk_1D = pVariables->unk_36;
                pSound->unk_1E = pVariables->unk_37;
                
                pSound->pSample = pVariables->pSample1;
                pSound->envelope.attack = pVariables->envelope1.attack;
                pSound->envelope.decay = pVariables->envelope1.decay;
                pSound->envelope.sustain = pVariables->envelope1.sustain;
                pSound->envelope.release = pVariables->envelope1.release;

                pSound->unk_1F = pVariables->modulationType;

                pSound->unk_F &= ~0x2;
                pSound->unk_F |= 0x10;
                continue;
            }

            if (pSound->unk_F & 0x4)
            {
                pSound->unk_14 = pSound->maybe_noteDelay;

                unk_5104(pSound);

                pSound->unk_F &= ~0x4;
                continue;
            }

            if (pSound->unk_F & 0x10)
            {
                if (pSound->pVariables->unk_6 != pSound->unk_C)
                {
                    pSound->pVariables->unk_6 = pSound->unk_C;
                    unk_4f10(pSound->pVariables);
                }

                pSound->unk_2 = (pSound->pVariables->unk_8 * (pSound->unk_A + 1)) >> 7;
                pSound->unk_3 = (pSound->pVariables->unk_9 * (pSound->unk_A + 1)) >> 7;

                pSound->unk_1A = (pSound->unk_2 + pSound->unk_3) >> 4;
                pSound->unk_1B = (pSound->unk_1A * pSound->envelope.sustain + 0xF) >> 4;

                ptr = (u8*)(REG_SOUNDCNT_L + 1);
                control = read8(ptr) & ~(0x11 << i);

                if (pSound->unk_2 >= pSound->unk_3)
                {
                    if ((pSound->unk_2 >> 1) > pSound->unk_3)
                    {
                        *ptr = control | (1 << i);
                    }
                    else
                    {
                        *ptr = control | (17 << i);
                    }
                }
                else
                {
                    if ((pSound->unk_3 >> 1) > pSound->unk_2)
                    {
                        *ptr = control | (16 << i);
                    }
                    else
                    {
                        *ptr = control | (17 << i);
                    }
                }

                pSound->unk_12 = 0;
                pSound->unk_14 |= 0x8000;

                var_0 = TRUE;

                pSound->unk_F &= ~0x10;
                continue;
            }

            if (pSound->unk_F & 0x20)
            {
                pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;

                unk_5104(pSound);

                pSound->unk_F &= ~0x20;
            }
        }

        control = pSound->unk_0 & 0xF;

        if (control == 0xA)
        {
            ClearRegistersForPsg(pSound, i);
            continue;
        }

        if (control == 0x1)
        {
            if (i == 0)
            {
                pSound->unk_10 = pSound->unk_1E;
            }
            else if (i == 2)
            {
                pSound->unk_10 = 0x80;
            }

            if (i < 2)
                pSound->unk_11 = (u8)(u32)pSound->pSample;
            else
                pSound->unk_11 = 0;

            pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;

            if (pSound->unk_1D != 0)
            {
                goto lbl_pre_case_9;
            }

            if (pSound->envelope.attack != 0)
            {
                goto lbl_pre_case_2;
            }
            else
            {
                goto lbl_3;
            }
        }

        if (pSound->unk_18 == 0)
        {
            switch (pSound->unk_0 & 0xF)
            {
                case 2:
                    goto lbl_case_2;

                    lbl_pre_case_2:
                    pSound->unk_19 = 0;
                    if (i == 2)
                        pSound->unk_12 = 0;
                    else
                        pSound->unk_12 = pSound->envelope.attack + 8;

                    pSound->unk_0 = 2;
                    unk_5104(pSound);

                    lbl_case_2:
                    if (++pSound->unk_19 >= pSound->unk_1A)
                    {
                        lbl_3:
                        if (pSound->envelope.decay == 0)
                        {
                            goto lbl_1;
                        }
                        else
                        {
                            goto lbl_2;
                        }
                    }
                    else
                    {
                        if (i == 2)
                        {
                            pSound->unk_12 = 0;
                            var_0 = TRUE;
                        }
    
                        pSound->unk_18 = pSound->envelope.attack;
                        break;
                    }
                    

                case 3:
                    goto lbl_case_3;
                    
                    lbl_2:
                    pSound->unk_19 = pSound->unk_1A;
                    if (i == 2)
                    {
                        pSound->unk_12 = 0;
                    }
                    else
                    {
                        pSound->unk_12 = pSound->envelope.decay;
                        pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;
                    }

                    pSound->unk_0 = 3;
                    var_0 = TRUE;

                    lbl_case_3:
                    if (--pSound->unk_19 > pSound->unk_1B)
                    {
                        if (i == 2)
                        {
                            pSound->unk_12 = 0;
                            var_0 = TRUE;
                        }

                        pSound->unk_18 = pSound->envelope.decay;
                        break;
                    }

                    lbl_1:
                    pSound->unk_19 = pSound->unk_1B;

                    if (i == 2)
                    {
                        pSound->unk_12 = 0;
                    }
                    else
                    {
                        pSound->unk_12 = 0;
                        pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;
                    }
                    
                    pSound->unk_0 = 4;
                    var_0 = TRUE;

                case 4:
                    pSound->unk_19 = pSound->unk_1B;
                    
                    if ((pSound->unk_0 & 0xF) == 4)
                        pSound->unk_18 = 1;
                    break;

                case 5:
                    if (pSound->envelope.release != 0 && pSound->unk_1D == 0)
                    {
                        if (i != 2)
                        {
                            pSound->unk_12 = pSound->envelope.release;
                            pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;
                        }

                        pSound->unk_0 = 6;
                        var_0 = TRUE;
                    }
                    else
                    {
                        goto lbl_0;
                    }

                case 6:
                    pSound->unk_19--;
                    if (pSound->unk_19 > 0)
                    {
                        if (i == 2)
                        {
                            pSound->unk_12 = 0;
                            var_0 = TRUE;
                        }

                        pSound->unk_18 = pSound->envelope.release;
                        break;
                    }

                    lbl_0:
                    pSound->unk_0 = 0;

                    if (pSound->unk_D != 0 && pSound->unk_E != 0)
                    {
                        pSound->unk_19 = (pSound->unk_1A * pSound->unk_D + 0xFF) >> 8;
                        pSound->unk_18 = pSound->unk_E;

                        if (i == 2)
                        {
                            pSound->unk_12 = gCgb3Vol[pSound->unk_19];
                        }
                        else
                        {
                            pSound->unk_12 = 0;
                            pSound->unk_14 = pSound->maybe_noteDelay | 0x8000;
                        }

                        pSound->unk_0 = 8;
                        var_0 = TRUE;
                    }
                    else
                    {
                        ClearRegistersForPsg(pSound, i);
                        continue;
                    }
                    break;

                case 8:
                    if (pSound->unk_18 == 0)
                    {
                        ClearRegistersForPsg(pSound, i);
                        pSound->unk_0 = 0;
                    }
                    continue;

                case 9:
                    goto lbl_case_9;

                    lbl_pre_case_9:
                    pSound->unk_11 |= pSound->unk_1D;
                    pSound->unk_12 = 0;
                    pSound->unk_19 = pSound->unk_1B;
                    pSound->unk_14 |= 0x4000;
                    pSound->unk_0 = 9;

                    var_0 = TRUE;

                    lbl_case_9:
                    pSound->unk_18 = UCHAR_MAX;
                    if (var_0)
                    {
                        pSound->unk_14 |= 0x4000;
                    }
                    break;
            }
        }

        if (var_0)
        {
            var_0 = FALSE;
            control = (u8)pSound->unk_19;

            if (i == 2)
                pSound->unk_12 = gCgb3Vol[control];
            else
                pSound->unk_12 |= control << 4;

            unk_5104(pSound);
        }

        pSound->unk_18--;
    }
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
    s16 var_2;

    if (pTrack->occupied)
        return;

    pTrack->occupied = TRUE;

    if (!(pTrack->unk_1E & TRUE))
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
                    if (pVariables->unk_0 == 0)
                        continue;

                    if (pVariables->pChannel != NULL)
                        unk_1bf0(pVariables);

                    if (pVariables->pSoundPSG != NULL)
                        unk_1c18(pVariables);

                    if (pVariables->delay != 0)
                    {
                        pVariables->delay--;
                        if (pVariables->unk_15 != 0)
                        {
                            pVariables->unk_15--;
                        }
                        else
                        {
                            if (pVariables->lfoSpeed != 0 && pVariables->modulationDepth != 0)
                            {
                                if (pVariables->pChannel != NULL)
                                {
                                    if (pVariables->pChannel->unk_0 != 0)
                                    {
                                        pVariables->unk_16 += pVariables->lfoSpeed;
                                        if ((s8)(pVariables->unk_16 - 0x40) < 0)
                                            var_2 = pVariables->unk_16;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->unk_16;

                                        if (var_2 != (s8)pVariables->unk_13)
                                        {
                                            pVariables->unk_13 = (var_2 * (pVariables->modulationDepth + 1)) >> 7;
                                            unk_1c3c(pVariables);
                                        }
                                    }
                                }
                                else
                                {
                                    if (pVariables->pSoundPSG != NULL && pVariables->pSoundPSG->unk_0 != 0)
                                    {
                                        pVariables->unk_16 += pVariables->lfoSpeed;
                                        if ((s8)(pVariables->unk_16 - 0x40) < 0)
                                            var_2 = pVariables->unk_16;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->unk_16;

                                        if (var_2 != (s8)pVariables->unk_13)
                                        {
                                            pVariables->unk_13 = (var_2 * (pVariables->modulationDepth + 1)) >> 7;
                                            unk_1c3c(pVariables);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    while (pVariables->delay == 0)
                    {
                        var_0 = *pVariables->pRawData;
                        if ((s8)var_0 >= 0)
                            var_0 = pVariables->unk_3;
                        else if (var_0 > 0xBC)
                        {
                            pVariables->unk_3 = var_0;
                            pVariables->pRawData++;
                        }

                        if (var_0 > 0xCE)
                        {
                            pVariables->unk_0 |= 0x2;
                            pVariables->unk_E = gClockTable[var_0 - 0xCF];

                            var_0 = *pVariables->pRawData;

                            if (pVariables->unk_14 != 0)
                                pVariables->unk_15 = pVariables->unk_14;

                            if ((s8)var_0 >= 0)
                            {
                                pVariables->unk_1 = var_0;
                                pVariables->pRawData++;

                                var_0 = *pVariables->pRawData;
                                if ((s8)var_0 >= 0)
                                {
                                    pVariables->unk_F = var_0;
                                    pVariables->pRawData++;
                                
                                    var_0 = *pVariables->pRawData;
                                    if ((s8)var_0 >= 0)
                                    {
                                        pVariables->unk_E += var_0;
                                        pVariables->pRawData++;
                                    }
                                }
                            }

                            if ((pVariables->unk_0 & 0xF0) > 0x3F)
                                unk_4e10(pVariables);

                            pVariables->unk_13 = 0;
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
                            if (var_0 == TEMPO)
                            {
                                unk_4d1c(pTrack, pVariables);
                            }
                            else if (var_0 == VOICE)
                            {
                                AudioCommand_Voice(pTrack, pVariables);
                            }
                            else if (var_0 == FINE)
                            {
                                AudioCommand_Fine(pTrack, pVariables);
                                break;
                            }
                            else if (var_0 == 0xB6)
                            {
                                unk_21b0(pTrack, pVariables);
                                break;
                            }
                            else
                            {
                                sMusicCommandFunctionPointers[var_0 - FINE](pVariables);
                            }
                        }
                        else
                        {
                            pVariables->delay = gClockTable[var_0 - 0x80];
                            pVariables->pRawData++;
                            break;
                        }
                    }


                    if (pVariables->unk_0 & 4)
                    {
                        unk_4f10(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d5c(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1ddc(pVariables);

                        pVariables->unk_0 &= ~4;
                    }

                    if (pVariables->unk_0 & 8)
                    {
                        unk_4eb4(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d78(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1de8(pVariables);

                        pVariables->unk_0 &= ~8;
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
        if (pChannel->unk_E != 0 && pChannel->unk_E-- == 1)
            pChannel->unk_0 = 5;
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

    if (pVariables->unk_E != 0)
    {
        if (pVariables->unk_E-- == 1)
        {
            pSound->unk_0 = 5;
            pSound->unk_18 = 0;
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
    s32 frequency;
    u16 midiKey;
    s16 tmp;

    pChannel = pVariables->pChannel;

    switch (pVariables->modulationType)
    {
        case 1:
        case 2:
            unk_4f10(pVariables);
            for (; pChannel != NULL; pChannel = pChannel->pChannel2)
                pChannel->unk_13 |= 0x10;
            break;
        
        case 0:
            unk_4eb4(pVariables);

            if (pChannel->unk_1 != 0 && pChannel->unk_1 != 0x20)
                break;

            for (; pChannel != NULL; pChannel = pChannel->pChannel2)
            {
                midiKey = pVariables->unk_17 + pChannel->unk_7;
                tmp = midiKey;

                if (tmp >= 0x80)
                    midiKey = 0x7F;
                else if (tmp < 0)
                    midiKey = 0;

                frequency = Midikey2Freq(pVariables->pSample1, midiKey, pVariables->unk_18);
                pChannel->unk_1C = frequency;

                if (frequency == gMusicInfo.sampleRate)
                    frequency = 0x4000;
                else
                    frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

                pChannel->unk_1C = frequency;
            }
    }
}

/**
 * @brief 1ccc | 90 | To document
 * 
 * @param pVariables Track variables pointer
 * @param param_2 To document
 */
void unk_1ccc(struct TrackVariables* pVariables, s16 param_2)
{
    struct PSGSoundData* pSound;
    u16 var_0;
    s16 tmp;

    pSound = pVariables->pSoundPSG;

    if (pVariables->modulationType == 1)
    {
        unk_4f10(pVariables);
        pSound->unk_12 = (pSound->unk_19 + (s32)pVariables->unk_13 / sUnk_808cc4d[param_2]) * 16;
        pSound->unk_F |= 0x20;
    }
    else if (pVariables->modulationType == 0)
    {
        unk_4eb4(pVariables);

        var_0 = pVariables->unk_17 + pVariables->pSoundPSG->unk_1C;
        tmp = var_0;

        if (tmp >= 0x80)
            var_0 = 0x7F;
        else if (tmp < 0)
            var_0 = 0;

        pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unk_18);
        pSound->unk_F |= 0x4;
    }
    else if (pVariables->modulationType == 2)
    {
        unk_4f10(pVariables);
        pSound->unk_F |= 0x10;
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
        pChannel->unk_13 |= 0x10;
}

/**
 * @brief 1d78 | 64 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1d78(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    s32 frequency;
    u16 midiKey;
    s16 tmp;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
    {
        midiKey = pVariables->unk_17 + pChannel->unk_7;
        tmp = midiKey;

        if (tmp >= 0x80)
            midiKey = 0x7F;
        else if (tmp < 0)
            midiKey = 0;

        frequency = Midikey2Freq(pChannel->pSample, midiKey, pVariables->unk_18);
        pChannel->unk_1C = frequency;

        if (frequency == gMusicInfo.sampleRate)
            frequency = 0x4000;
        else
            frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

        pChannel->unk_1C = frequency;
        pChannel->unk_13 |= 4;
    }
}

/**
 * @brief 1ddc | c | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1ddc(struct TrackVariables* pVariables)
{
    pVariables->pSoundPSG->unk_F |= 0x10;
}

/**
 * @brief 1de8 | 44 | To document
 * 
 * @param pVariables Track variables pointer
 */
void unk_1de8(struct TrackVariables* pVariables)
{
    u16 var_0;
    s16 tmp;

    var_0 = pVariables->unk_17 + pVariables->pSoundPSG->unk_1C;
    tmp = var_0;

    if (tmp >= 0x80)
        var_0 = 0x7F;
    else if (tmp < 0)
        var_0 = 0;

    pVariables->pSoundPSG->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unk_18);
    pVariables->pSoundPSG->unk_F |= 0x4;
}

/**
 * @brief 1e2c | 110 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 var_0;
    u8 var_1;
    u32 var_2;
    s32 var_3;
    s32 var_4;
    u8 i;
    struct SoundChannel* pChannel;
    struct TrackVariables* pVariables2;

    if (pTrack->unk_3 + pVariables->priority > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unk_3 + pVariables->priority;

    var_2 = var_0;
    pVariables2 = pVariables;
    var_1 = FALSE;
    pChannel = NULL;

    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        if (gMusicInfo.soundChannels[i].unk_0 == 0)
        {
            pChannel = &gMusicInfo.soundChannels[i];
            goto end;
            //unk_4f8c(pChannel, pVariables, var_0);
            //return;
        }
        
        if (gMusicInfo.soundChannels[i].unk_0 == 5 || gMusicInfo.soundChannels[i].unk_0 == 6 || gMusicInfo.soundChannels[i].unk_0 == 8)
        {
            if (!var_1)
            {
                var_1 = TRUE;
                var_4 = FALSE;
                var_3 = TRUE;
            }
            else
            {
                var_4 = TRUE;
                var_3 = FALSE;
            }
        }
        else
        {
            var_4 = FALSE;
            var_3 = FALSE;
        }

        if (!var_3)
        {
            if (var_4 || !var_1)
            {
                if (gMusicInfo.soundChannels[i].unk_2 >= var_2 &&
                    (gMusicInfo.soundChannels[i].unk_2 > var_2 ||
                    (gMusicInfo.soundChannels[i].pVariables <= pVariables2 &&
                    gMusicInfo.soundChannels[i].pVariables < pVariables2)))
                {
                    continue;
                }
                var_3 = TRUE;
            }
            else
            {
                var_3 = FALSE;
            }
        }

        if (var_3)
        {
            var_2 = gMusicInfo.soundChannels[i].unk_2;
            pVariables2 = gMusicInfo.soundChannels[i].pVariables;
            pChannel = &gMusicInfo.soundChannels[i];
        }
    }

    if (pChannel != NULL)
    {
        end:
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
        if (++pTrack->unk_23 <= pTrack->maxSoundChannels)
            unk_1e2c(pTrack, pVariables);
    }
    else if (pTrack->flags & 0x40)
    {
        if (++pTrack->unk_23 <= pTrack->maxSoundChannels)
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

    if (pTrack->unk_3 + pVariables->priority > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unk_3 + pVariables->priority;

    pSound = &gUnk_300376c[pVariables->channel & 7];
    if (pSound->unk_0 == 0 ||
        (var_0 >= pSound->unk_16 &&
        (var_0 != pSound->unk_16 ||
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

    if (pTrack->unk_3 + pVariables->priority > UCHAR_MAX)
        var_0 = UCHAR_MAX;
    else
        var_0 = pTrack->unk_3 + pVariables->priority;

    pSound = &gUnk_300376c[pVariables->channel & 7];
    if (pSound->unk_0 == 0 ||
        (var_0 >= pSound->unk_16 &&
        (var_0 != pSound->unk_16 ||
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
    s16 tmp;

    pSound->unk_16 = param_3;
    pSound->unk_1 = pVariables->channel;
    pSound->unk_C = pVariables->unk_6;
    pSound->unk_17 = pVariables->unk_1;

    if ((pVariables->unk_0 & 0xF0) == 0x80)
        pSound->unk_1C = pVariables->unk_35;
    else
        pSound->unk_1C = pVariables->unk_1;

    var_0 = pVariables->unk_17 + pSound->unk_1C;
    tmp = var_0;

    if (tmp >= 0x80)
        var_0 = 0x7F;
    else if (tmp < 0)
        var_0 = 0;

    pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->unk_18);
    pSound->pVariables->pSoundPSG = NULL;
    pSound->pVariables = pVariables;
    pSound->unk_F |= 2;
    pSound->unk_0 = 1;
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

            temp = (sUnk_808cad0[param_2 + 1] - delay) * (param_3 + 1) >> 8;
            delay += temp;
        }
    }
    else
    {
        delay = gNoiseTable[param_2 - 0x15] | (u8)(u32)pVariables->pSample1;
    }
    
    return delay;
}

/**
 * @brief 2140 | 70 | Processes the audio command FINE
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void AudioCommand_Fine(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct SoundChannel* pNext;

    if (pVariables->pSoundPSG != NULL)
    {
        ClearRegistersForPsg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1);
        pVariables->pSoundPSG->unk_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->unk_0 = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannel2;
            pChannel->pChannel2 = NULL;
            pChannel->pChannel1 = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->currentTrack == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->currentTrack = 0;
    }

    pVariables->unk_0 = 0;
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
        pVariables->pSoundPSG->unk_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->unk_0 = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannel2;
            pChannel->pChannel2 = NULL;
            pChannel->pChannel1 = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->currentTrack == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->currentTrack = 0;
        pTrack->queueFlags |= 0x2;
    }

    pVariables->unk_0 = 0;
}

/**
 * @brief 222c | 38 | Processes the audio command PEND
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PatternEnd(struct TrackVariables* pVariables)
{
    s8 i;

    pVariables->pRawData++;

    for (i = ARRAY_SIZE(pVariables->patternStartPointers) - 1; i >= 0; i--)
    {
        if (pVariables->patternStartPointers[i])
        {
            pVariables->pRawData = pVariables->patternStartPointers[i];
            pVariables->patternStartPointers[i] = NULL;
            break;
        }
    }
}

/**
 * @brief 2264 | 40 | Processes the audio command REPT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Repeat(struct TrackVariables* pVariables)
{
    if (pVariables->repeatCount == 0)
    {
        // Setup repeat
        pVariables->pRawData++;

        // Get repeat count
        pVariables->repeatCount = *pVariables->pRawData;

        // Start pattern
        AudioCommand_PatternPlay(pVariables);
        return;
    }

    if (--pVariables->repeatCount == 0)
    {
        // Repeat count reached 0, end pattern
        AudioCommand_PatternEnd(pVariables);
        return;
    }

    pVariables->pRawData++;

    // Replay pattern
    AudioCommand_PatternPlay(pVariables);
}

/**
 * @brief 22a4 | 10 | Processes the audio command PRIO
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Priority(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->priority = *pVariables->pRawData++;
}

/**
 * @brief 22b4 | 18 | Processes the audio command KEYSH
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_KeyShift(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->keyShift = *pVariables->pRawData;
    pVariables->unk_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 22cc | c0 | Processes the audio command VOICE
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void AudioCommand_Voice(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct Voice* pVoice;
    u32 channel;

    pVoice = &pTrack->pVoice[*pVariables->pRawData];
    pVariables->channel = pVoice->instrumentType;

    if (pVariables->channel > 0x3F)
    {
        if (pVariables->channel == 0x80)
        {
            pVariables->unk_0 |= 0x80;
            pVariables->pSample2 = pVoice->pSample;
        }
        else if (pVariables->channel == 0x40)
        {
            pVariables->unk_0 |= 0x40;
            pVariables->pSample2 = pVoice->pSample;
            pVariables->envelope2 = pVoice->envelope;
        }
    }
    else
    {
        pVariables->unk_0 &= 0xF;
        pVariables->unk_36 = pVoice->unk_2;

        channel = pVariables->channel & 7;

        if (channel == 0)
        {
            pVariables->pSample1 = pVoice->pSample;
        }
        else if (channel < 3)
        {
            if (!(pVoice->unk_3 & 0x80) && pVoice->unk_3 & 0x70)
                pVariables->unk_37 = pVoice->unk_3;
            else
                pVariables->unk_37 = 8;

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
 * @brief 238c | 14 | Processes the audio command VOL
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Volume(struct TrackVariables* pVariables)
{
    pVariables->volume = *pVariables->pRawData;
    pVariables->unk_0 |= 0x4;
    pVariables->pRawData++;
}

/**
 * @brief 23a0 | 14 | Processes the audio command PAN
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PanPot(struct TrackVariables* pVariables)
{
    pVariables->unk_6 = *pVariables->pRawData;
    pVariables->unk_0 |= 0x4;
    pVariables->pRawData++;
}

/**
 * @brief 23b4 | 18 | Processes the audio command BEND
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PitchBend(struct TrackVariables* pVariables)
{
    pVariables->pitchBend = *pVariables->pRawData - C_V;
    pVariables->unk_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 23cc | 18 | Processes the audio command BENDR
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_BendRange(struct TrackVariables* pVariables)
{
    pVariables->bendRange = *pVariables->pRawData;
    pVariables->unk_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 23e0 | 10 | Processes the audio command LFOS
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_LfoSpeed(struct TrackVariables* pVariables)
{
    pVariables->lfoSpeed = (*pVariables->pRawData + 1) / 2;
    pVariables->pRawData++;
}

/**
 * @brief 23f0 | 10 | Processes the audio command LFODL
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_LfoDelay(struct TrackVariables* pVariables)
{
    u8 param;

    param = *pVariables->pRawData;
    pVariables->unk_14 = param;
    pVariables->unk_15 = param;
    pVariables->pRawData++;
}

/**
 * @brief 2400 | c | Processes the audio command MOD
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ModulationDepth(struct TrackVariables* pVariables)
{
    pVariables->modulationDepth = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 240c | c | Processes the audio command MODT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ModulationType(struct TrackVariables* pVariables)
{
    pVariables->modulationType = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 2418 | 18 | Processes the audio command TUNE
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Tune(struct TrackVariables* pVariables)
{
    pVariables->tune = *pVariables->pRawData - C_V;
    pVariables->unk_0 |= 0x8;
    pVariables->pRawData++;
}

/**
 * @brief 2430 | 30 | Processes the audio command XCMD
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ExtendCommand(struct TrackVariables* pVariables)
{
    if (*pVariables->pRawData == xIECV)
    {
        pVariables->pRawData++;
        pVariables->unk_C = *pVariables->pRawData;
        pVariables->pRawData++;
    }

    if (*pVariables->pRawData == xIECL)
    {
        pVariables->pRawData++;
        pVariables->unk_D = *pVariables->pRawData;
        pVariables->pRawData++;
    }
}

/**
 * @brief 2460 | 5c | Processes the audio command EOT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_EndOfTie(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct PSGSoundData* pSound;
    u32 param;

    if ((s8)*pVariables->pRawData >= 0)
    {
        param = *pVariables->pRawData;
        pVariables->unk_1 = param;
        pVariables->pRawData++;
    }
    else
    {
        param = pVariables->unk_1;
    }
    
    if (pVariables->pChannel)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
        {
            if ((u8)(pChannel->unk_0 - 1) < 4 && pChannel->unk_6 == param)
            {
                pChannel->unk_0 = 5;
                break;
            }
        }
    }

    pSound = pVariables->pSoundPSG;
    if (pSound != NULL && pSound->unk_17 == param)
    {
        pSound->unk_0 = 5;
        pVariables->pSoundPSG->unk_18 = 0;
    }
}

/**
 * @brief 24bc | 4 | Empty function
 * 
 * @param pVariables Track variables pointer
 */
void Music_EmptyCommand(struct TrackVariables* pVariables)
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
            write16(REG_SOUND1CNT_X, SOUNDCNT_RESTART_SOUND);
            break;

        case 1:
            write8(REG_SOUND2CNT_L + 1, 8);
            write16(REG_SOUND2CNT_H, SOUNDCNT_RESTART_SOUND);
            break;

        case 2:
            write8(REG_SOUND3CNT_L, 0);
            break;

        case 3:
            write8(REG_SOUND4CNT_L + 1, 8);
            write16(REG_SOUND4CNT_H, SOUNDCNT_RESTART_SOUND);
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
