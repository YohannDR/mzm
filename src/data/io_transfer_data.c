#include "data/io_transfer_data.h"

const struct IoTransferInfo sIoTransferInfo_Empty = {
    .pFunction = NULL,
    .linkInProgress = 1,
    .timer = 0,
    .active = FALSE,
    .connectStage = 0,
    .linkStage = 0,
    .result = 0,
    .errorFlag = 0,
    .command = 0,
    .fusionGalleryImages = -1,
    .language = -1,
    .musicTrack = 0,
    .musicPriority = 0
};

const u8 sPlayer4String[4] = "4P";
const u8 sPlayer3String[4] = "3P";
const u8 sPlayer2String[4] = "2P";
const u8 sPlayer1String[4] = "";

#ifdef DEBUG
const u8 sCableLinkDebugString_Blank[20] = "                ";
const u8 sCableLinkDebugString_NotConnected1[20] = "NOT CONNECTED 1 ";
const u8 sCableLinkDebugString_NotConnected2[20] = "NOT CONNECTED  2";
const u8 sCableLinkDebugString_Checking1[16] = "CHECKING  1  ";
const u8 sCableLinkDebugString_Checking2[16] = "CHECKING   2 ";
const u8 sCableLinkDebugString_Ready1[16] = "READY     1  ";
const u8 sCableLinkDebugString_Ready2[16] = "READY      2 ";
const u8 sCableLinkDebugString_PressAButton1[20] = " PRESS A BUTTON 1 ";
const u8 sCableLinkDebugString_PressAButton2[20] = " PRESS A BUTTON  2";
const u8 sCableLinkDebugString_NowSending11[20] = "  NOW SENDING 1 1 ";
const u8 sCableLinkDebugString_NowSending12[20] = "  NOW SENDING 1  2";
const u8 sCableLinkDebugString_1_Right[20] = "                1 ";
const u8 sCableLinkDebugString_2_Right[20] = "                 2";
const u8 sCableLinkDebugString_BootChecking1[20] = "BOOT CHECKING...1 ";
const u8 sCableLinkDebugString_BootChecking2[20] = "BOOT CHECKING... 2";
const u8 sCableLinkDebugString_NoClientBit1[20] = "  NO CLIENT BIT 1 ";
const u8 sCableLinkDebugString_NoClientBit2[20] = "  NO CLIENT BIT  2";
const u8 sCableLinkDebugString_PressA1[12] = "PRESS A 1 ";
const u8 sCableLinkDebugString_PressA2[12] = "PRESS A  2";
const u8 sCableLinkDebugString_Sending1[12] = "SENDING 1";
const u8 sCableLinkDebugString_Success[12] = " SUCCESS!";
const u8 sCableLinkDebugString_Retry[12] = " RETRY!  ";
const u8 sCableLinkDebugString_Error[12] = " ERROR!  ";
const u8 sCableLinkDebugString_TimeOut[12] = "TIME OUT";
#endif // DEBUG

const u8 sErrorString_IdOver[16] = " ID OVER ERROR ";
const u8 sErrorString_ChecksumError[20] = " CHECKSUM ERROR ";
const u8 sErrorString_HardwareError[20] = "   HARD ERROR   ";
const u8 sErrorString_SendOverflow[20] = " SEND OVER FLOW ";
const u8 sErrorString_ReceiveOverflow[20] = " RECV OVER FLOW ";
const u8 sErrorString_SioInternal[20] = "SIO INTERVAL ERROR";
const u8 sErrorString_SioStop[20] = "  SIO STOP ERROR  ";
