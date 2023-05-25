#include "audio.h"

void UpdateMusic(void)
{

}

void UpdatePsgSounds(void)
{

}

void UpdateTrack(struct TrackData* pTrack)
{

}

void unk_1bd0(struct TrackVariables* pVariables)
{

}

void unk_1c18(struct TrackVariables* pVariables)
{

}

void unk_1c38(struct TrackVariables* pVariables)
{

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

void unk_1d78(struct TrackVariables* pVariables)
{

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

void unk_1de8(struct TrackVariables* pVariables)
{

}

void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_1f3c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{

}

void unk_2030(struct TrackData* pTrack, struct TrackVariables* pVariables, u32 param_3)
{

}

void unk_20a4(struct SoundChannel* pChannel)
{

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

void unk_222c(struct TrackVariables* pVariables)
{

}

void unk_2264(struct TrackVariables* pVariables)
{

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

