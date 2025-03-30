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
u8 FusionGalleryConnectProcess(void)
{
    u8 probeCount;
    
    gIoTransferInfo.result = TRANSFER_RESULT_NONE;

    switch (gIoTransferInfo.connectStage)
    {
        case CONNECT_STAGE_FADE_MUSIC:
            gIoTransferInfo.timer = 0;
            FadeMusic(ONE_THIRD_SECOND);
            gIoTransferInfo.connectStage++;
            break;

        case CONNECT_STAGE_WAIT_CLEAR_SOUND:
            gIoTransferInfo.timer++;
            if (gIoTransferInfo.timer > CONVERT_SECONDS(.5f))
            {
                ClearSoundData();
                gIoTransferInfo.musicTrack = gMusicInfo.musicTrack;
                gIoTransferInfo.musicPriority = gMusicInfo.priority;
                gIoTransferInfo.timer = 0;
                gIoTransferInfo.connectStage++;
            }
            break;

        case CONNECT_STAGE_MULTIBOOT_INIT:
            CallbackSetSerialCommunication(CableLinkSerialTransferExchangeData);
            CallbackSetTimer3(CableLinkBeginTransferWithTimer3);

            gDataSentPointer = sTransferData_8754bd0;
            gDataSentSize = (u32)sTransferRom - (u32)sTransferData_8754bd0;
            gMultiBootParamData.dataSentPointer = sTransferData_8754bd0;
            gMultiBootParamData.serverType = 0;
            MultiBootInit(&gMultiBootParamData);
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.connectStage++;
            break;

        case CONNECT_STAGE_MULTIBOOT_PROCESS:
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
                gIoTransferInfo.connectStage++;
                break;
            }

            if (gMultiBootParamData.probeCount != 0xD1 && (gChangedInput & KEY_B) && gMultiBootParamData.probeCount < 0xE0)
            {
                gIoTransferInfo.connectStage = CONNECT_STAGE_BACKED_OUT;
                break;
            }

            if (gIoTransferInfo.timer > CONVERT_SECONDS(3.f))
            {
                gIoTransferInfo.connectStage = CONNECT_STAGE_MULTIBOOT_TIMED_OUT;
            }
            break;

        case CONNECT_STAGE_SERIAL_TRANSFER_SEND_TRANSFER_ROM:
            if (CableLinkProcessSerialTransfer(sTransferRom_After - sTransferRom, (const u32*)sTransferRom) == 0)
            {
                gIoTransferInfo.connectStage++;
                break;
            }

            gIoTransferInfo.connectStage = CONNECT_STAGE_SERIAL_TRANSFER_FAILURE;
            break;

        case CONNECT_STAGE_SERIAL_TRANSFER_COMPLETE:
            // Always 0?
            switch (gMultibootUnk_3005880)
            {
                case 0:
                    gIoTransferInfo.connectStage++;
                    break;

                case 1:
                    gIoTransferInfo.connectStage = CONNECT_STAGE_BACKED_OUT;
                    break;

                case 2:
                    gIoTransferInfo.connectStage = CONNECT_STAGE_SERIAL_TRANSFER_FAILURE;
                    break;
            }

        case CONNECT_STAGE_SERIAL_TRANSFER_SUCCESS:
            gIoTransferInfo.connectStage = CONNECT_STAGE_SET_ACTIVE_LINK;
            break;

        case CONNECT_STAGE_BACKED_OUT:
            gIoTransferInfo.result = TRANSFER_RESULT_BACKED_OUT;
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_MULTIBOOT_TIMED_OUT:
            gIoTransferInfo.result = TRANSFER_RESULT_TIMED_OUT;
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_SERIAL_TRANSFER_FAILURE:
            gIoTransferInfo.result = TRANSFER_RESULT_FAILURE;
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_SET_ACTIVE_LINK:
            gIoTransferInfo.active = ACTIVE_TRANSFER_LINK;

        case CONNECT_STAGE_RESTORE_AUDIO:
            InitializeAudio();
            FileSelectApplyStereo();
            PlayMusic(gIoTransferInfo.musicTrack, gIoTransferInfo.musicPriority);
            gIoTransferInfo.connectStage = CONNECT_STAGE_FINISH;
            break;

        case CONNECT_STAGE_FINISH:
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
