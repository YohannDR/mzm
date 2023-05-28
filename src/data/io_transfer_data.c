#include "data/io_transfer_data.h"

const struct IoTransferInfo sIoTransferInfo_Empty = {
    .pFunction = NULL,
    .unk_4 = 1,
    .timer = 0,
    .active = FALSE,
    .unk_9 = 0,
    .unk_A = 0,
    .result = 0,
    .errorFlag = 0,
    .unk_E = 0,
    .fusionGalleryImages = -1,
    .language = -1,
    .musicTrack = 0,
    .musicPriority = 0
};

const u8 sPlayer4String[4] = "4P";
const u8 sPlayer3String[4] = "3P";
const u8 sPlayer2String[4] = "2P";
const u8 sPlayer1String[4] = "";

const u8 sErrorString_IdOver[16] = " ID OVER ERROR ";
const u8 sErrorString_ChecksumError[20] = " CHECKSUM ERROR ";
const u8 sErrorString_HardwareError[20] = "   HARD ERROR   ";
const u8 sErrorString_SendOverflow[20] = " SEND OVER FLOW ";
const u8 sErrorString_ReceiveOverflow[20] = " RECV OVER FLOW ";
const u8 sErrorString_SioInternal[20] = "SIO INTERVAL ERROR";
const u8 sErrorString_SioStop[20] = "  SIO STOP ERROR  ";
