#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "callbacks.h"
#include "music_wrappers.h"
#include "multiboot.h"
#include "link.h"
#include "transfer.h"

#include "data/cable_link_data.h"
#include "data/io_transfer_data.h"
#include "data/internal_io_transfer_data.h"

#include "constants/cable_link.h"

#include "structs/cable_link.h"
#include "structs/game_state.h"
#include "structs/multiboot.h"

/**
 * @brief 88ea0 | 270 | Handles sending multiboot and fusion gallery transfer roms
 * 
 * @return u8 Connection result
 */
u8 FusionGalleryConnectProcess(void)
{
    u8 probeCount;
    #ifdef DEBUG
    u8 i;
    const u8* string;
    #endif // DEBUG
    
    gIoTransferInfo.result = TRANSFER_RESULT_NONE;

    switch (gIoTransferInfo.connectStage)
    {
        case CONNECT_STAGE_FADE_MUSIC:
            gIoTransferInfo.timer = 0;
            FadeMusic(ONE_THIRD_SECOND);
            gIoTransferInfo.connectStage++;
            break;

        case CONNECT_STAGE_WAIT_CLEAR_SOUND:
            APPLY_DELTA_TIME_INC(gIoTransferInfo.timer);
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
            #ifdef DEBUG
            string = sCableLinkDebugString_Blank;
            for (i = 1; i <= 3; i++)
            {
                CableLinkDrawErrorStr(string, VRAM_BASE + 0xE004 + (i + 2) * 0x40, 0xC);
                CableLinkDrawErrorStr(string, VRAM_BASE + 0xE00A + (i + 2) * 0x40, 0xC);
            }
            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE1C0, 0xC);
            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE200, 0xC);
            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE240, 0xC);
            #endif // DEBUG

            CallbackSetSerialCommunication(TransferExchangeData);
            CallbackSetTimer3(TransferReloadTransfer);

            gDataSentPointer = sTransferData_8754bd0;
            gDataSentSize = (u32)sTransferRom - (u32)sTransferData_8754bd0;
            gMultiBootParamData.dataSentPointer = sTransferData_8754bd0;
            gMultiBootParamData.serverType = 0;
            MultiBootInit(&gMultiBootParamData);
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.connectStage++;
            break;

        case CONNECT_STAGE_MULTIBOOT_PROCESS:
            APPLY_DELTA_TIME_INC(gIoTransferInfo.timer);

            #ifdef DEBUG
            for (i = 1; i <= 3; i++)
            {
                if ((gMultiBootParamData.responseBit >> i & 1) == 0)
                {
                    if (gIoTransferInfo.timer & 1)
                        string = sCableLinkDebugString_NotConnected1;
                    else
                        string = sCableLinkDebugString_NotConnected2;
                }
                else if ((gMultiBootParamData.clientBit >> i & 1) == 0)
                {
                    if (gIoTransferInfo.timer & 1)
                        string = sCableLinkDebugString_Checking1;
                    else
                        string = sCableLinkDebugString_Checking2;
                }
                else
                {
                    if (gIoTransferInfo.timer & 1)
                        string = sCableLinkDebugString_Ready1;
                    else
                        string = sCableLinkDebugString_Ready2;
                }

                CableLinkDrawErrorStr(sPlayerNumbersStringPointers[i], VRAM_BASE + 0xE004 + (i + 2) * 0x40, 0xC);
                CableLinkDrawErrorStr(string, VRAM_BASE + 0xE00A + (i + 2) * 0x40, 0xC);
            }

            if (gMultiBootParamData.clientBit & (2 | 4 | 8))
            {
                if (gMultiBootParamData.probeCount != 0 && gMultiBootParamData.probeCount != 0xD1)
                {
                    if (gIoTransferInfo.timer & 1)
                        string = sCableLinkDebugString_1_Right;
                    else
                        string = sCableLinkDebugString_2_Right;
                }
                else if (gMultiBootParamData.probeCount == 0)
                {
                    if (gBootDebugActive)
                    {
                        if (gIoTransferInfo.timer & 1)
                            string = sCableLinkDebugString_PressAButton1;
                        else
                            string = sCableLinkDebugString_PressAButton2;
                    }
                }
                else if (gMultiBootParamData.probeCount == 0xD1)
                {
                    gIoTransferInfo.timer = 0;
                    string = sCableLinkDebugString_NowSending12;
                }
                
                if (gMultiBootParamData.probeCount > 0xDF)
                {
                    gIoTransferInfo.timer = 0;
                    string = sCableLinkDebugString_BootChecking2;
                }
            }
            else
            {
                if (gIoTransferInfo.timer & 1)
                    string = sCableLinkDebugString_NoClientBit1;
                else
                    string = sCableLinkDebugString_NoClientBit2;
            }

            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE1C0, 0xC);
            #endif // DEBUG

            if (gMultiBootParamData.clientBit & (2 | 4 | 8))
            {
                probeCount = gMultiBootParamData.probeCount;
                if (probeCount == 0xD1)
                    gIoTransferInfo.timer = 0;
                
                if (gMultiBootParamData.probeCount >= 0xE0)
                    gIoTransferInfo.timer = 0;
            }

            #ifdef DEBUG
            if (gBootDebugActive)
                i = gChangedInput & KEY_A;
            else
                i = TRUE;
            // Written this way to produce matching code
            i++; i--;
            if (i)
            #endif // DEBUG
            {
                if (gMultiBootParamData.probeCount == 0 && gMultiBootParamData.clientBit)
                {
                    MultiBootStartParent(&gMultiBootParamData, gDataSentPointer + MULTIBOOT_HEADER_SIZE, gDataSentSize - MULTIBOOT_HEADER_SIZE, 4, 1);
                    #ifdef DEBUG
                    if (gIoTransferInfo.timer & 1)
                        string = sCableLinkDebugString_PressA1;
                    else
                        string = sCableLinkDebugString_PressA2;
                    CableLinkDrawErrorStr(string, VRAM_BASE + 0xE3C0, 0xC);
                    #endif
                }
            }

            gMultibootErrorFlags = MultiBootMain(&gMultiBootParamData);

            if (MultiBootCheckComplete(&gMultiBootParamData))
            {
                gMultibootInProgress = 0;
                gIoTransferInfo.connectStage++;
            }

            else if (gMultiBootParamData.probeCount != 0xD1 && (gChangedInput & KEY_B) && gMultiBootParamData.probeCount < 0xE0)
            {
                gIoTransferInfo.connectStage = CONNECT_STAGE_BACKED_OUT;
            }

            else if (gIoTransferInfo.timer > CONVERT_SECONDS(3.f))
            {
                gIoTransferInfo.connectStage = CONNECT_STAGE_MULTIBOOT_TIMED_OUT;
            }
            break;

        case CONNECT_STAGE_TRANSFER_SEND_TRANSFER_ROM:
            #ifdef DEBUG
            string = sCableLinkDebugString_Sending1;
            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE200, 0xC);
            #endif // DEBUG

            if (TransferProcessSend(sTransferRom_After - sTransferRom, (const u32*)sTransferRom) == 0)
            {
                gIoTransferInfo.connectStage++;
            }
            else
            {
                gIoTransferInfo.connectStage = CONNECT_STAGE_TRANSFER_FAILURE;
            }
            break;

        case CONNECT_STAGE_TRANSFER_COMPLETE:
            #ifdef DEBUG
            switch (gMultibootUnk_3005880)
            {
                case 0:
                    string = sCableLinkDebugString_Success;
                    break;
                case 1:
                    string = sCableLinkDebugString_Retry;
                    break;
                case 2:
                    string = sCableLinkDebugString_Error;
                    break;
            }

            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE240, 0xC);
            #endif // DEBUG

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
                    gIoTransferInfo.connectStage = CONNECT_STAGE_TRANSFER_FAILURE;
                    break;
            }

        case CONNECT_STAGE_TRANSFER_SUCCESS:
            gIoTransferInfo.connectStage = CONNECT_STAGE_SET_ACTIVE_LINK;
            break;

        case CONNECT_STAGE_BACKED_OUT:
            gIoTransferInfo.result = TRANSFER_RESULT_BACKED_OUT;
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_MULTIBOOT_TIMED_OUT:
            gIoTransferInfo.result = TRANSFER_RESULT_TIMED_OUT;
            #ifdef DEBUG
            string = sCableLinkDebugString_TimeOut;
            CableLinkDrawErrorStr(string, VRAM_BASE + 0xE3C0, 9);
            #endif // DEBUG
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_TRANSFER_FAILURE:
            gIoTransferInfo.result = TRANSFER_RESULT_FAILURE;
            gIoTransferInfo.connectStage = CONNECT_STAGE_RESTORE_AUDIO;
            break;

        case CONNECT_STAGE_SET_ACTIVE_LINK:
            gIoTransferInfo.active = ACTIVE_TRANSFER_LINK;

        case CONNECT_STAGE_RESTORE_AUDIO:
            InitializeAudio();
            #ifndef DEBUG
            FileSelectApplyStereo();
            #endif // !DEBUG
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

    if (!gBootDebugActive)
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
