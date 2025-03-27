#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "callbacks.h"
#include "music_wrappers.h"
#include "multiboot.h"
#include "link.h"

#include "data/cable_link_data.h"

#include "constants/cable_link.h"

#include "structs/game_state.h"
#include "structs/multiboot.h"

#include "transfer.h"

/**
 * @brief 88ea0 | 270 | Handles sending 
 * 
 * @return u8 Connection result
 */
u8 CableLinkProcess(void)
{
    u8 probeCount;
    
    gIoTransferInfo.result = 0;

    switch (gIoTransferInfo.stage)
    {
        case 0:
            gIoTransferInfo.timer = 0;
            FadeMusic(ONE_THIRD_SECOND);
            gIoTransferInfo.stage++;
            break;

        case 1:
            gIoTransferInfo.timer++;
            if (gIoTransferInfo.timer > CONVERT_SECONDS(.5f))
            {
                ClearSoundData();
                gIoTransferInfo.musicTrack = gMusicInfo.musicTrack;
                gIoTransferInfo.musicPriority = gMusicInfo.priority;
                gIoTransferInfo.timer = 0;
                gIoTransferInfo.stage++;
            }
            break;

        case 2:
            CallbackSetSerialCommunication(CableLinkSerialTransferExchangeData);
            CallbackSetTimer3(CableLinkBeginTransferWithTimer3);

            gDataSentPointer = sTransferData_8754bd0;
            gDataSentSize = (u32)sTransferRom - (u32)sTransferData_8754bd0;
            gMultiBootParamData.dataSentPointer = sTransferData_8754bd0;
            gMultiBootParamData.serverType = 0;
            MultiBootInit(&gMultiBootParamData);
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.stage++;
            break;

        case 3:
            gIoTransferInfo.timer++;
            if (gMultiBootParamData.clientBit & (2 | 4 | 8))
            {
                probeCount = gMultiBootParamData.probeCount;
                if (probeCount == 0xD1)
                    gIoTransferInfo.timer = 0;
                
                if (gMultiBootParamData.probeCount > 0xDF)
                    gIoTransferInfo.timer = 0;
            }

            if (gMultiBootParamData.probeCount == 0 && gMultiBootParamData.clientBit)
            {
                MultiBootStartParent(&gMultiBootParamData, gDataSentPointer + 0xC0, gDataSentSize - 0xC0, 4, 1); // First 0xC0 bytes is header?
            }

            gMultibootErrorFlags = MultiBootMain(&gMultiBootParamData);

            if (MultiBootCheckComplete(&gMultiBootParamData))
            {
                gMultibootInProgress = 0;
                gIoTransferInfo.stage++;
                break;
            }

            if (gMultiBootParamData.probeCount != 0xD1 && gChangedInput & KEY_B && gMultiBootParamData.probeCount < 0xE0)
            {
                gIoTransferInfo.stage = 8;
                break;
            }

            if (gIoTransferInfo.timer > CONVERT_SECONDS(3.f))
            {
                gIoTransferInfo.stage = 7;
            }
            break;

        case 4:
            if (CableLinkProcessSerialTransfer(sTransferRom_After - sTransferRom, (const u32*)sTransferRom) == 0)
            {
                gIoTransferInfo.stage++;
                break;
            }

            gIoTransferInfo.stage = 9;
            break;

        case 5:
            // Always 0?
            switch (gMultibootUnk_3005880)
            {
                case 0:
                    gIoTransferInfo.stage++;
                    break;

                case 1:
                    gIoTransferInfo.stage = 8;
                    break;

                case 2:
                    gIoTransferInfo.stage = 9;
                    break;
            }

        case 6:
            gIoTransferInfo.stage = 10;
            break;

        case 8:
            gIoTransferInfo.result = 2;
            gIoTransferInfo.stage = 11;
            break;

        case 7:
            gIoTransferInfo.result = 3;
            gIoTransferInfo.stage = 11;
            break;

        case 9:
            gIoTransferInfo.result = 4;
            gIoTransferInfo.stage = 11;
            break;

        case 10:
            gIoTransferInfo.active = 2;

        case 11:
            InitializeAudio();
            FileSelectApplyStereo();
            PlayMusic(gIoTransferInfo.musicTrack, gIoTransferInfo.musicPriority);
            gIoTransferInfo.stage = 12;
            break;

        case 12:
            break;
    }

    return gIoTransferInfo.result;
}

/**
 * @brief 89110 | 84 | Draws an error string to the provided tilemap
 * 
 * @param str Error string
 * @param dst Destination
 * @param palette Palette
 */
void CableLinkDrawErrorStr(const u8* str, u16* dst, u8 palette)
{
    u16 letter;

    if (!gSramErrorFlag)
        return;

    while (*str)
    {
        letter = 0x28;
        if (*str >= '0')
        {
            if (*str <= '9')
                letter = *str - '0';
            else if (*str <= 'Z')
                letter = *str + -0x37;
        }

        *dst++ = letter | palette << 0xC;
        str++;
    }
}
