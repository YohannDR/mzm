#ifndef CABLE_LINK_STRUCTS_H
#define CABLE_LINK_STRUCTS_H

#include "types.h"

typedef u16 (CableLinkBuffer1_T)[2][2];

struct IoTransferInfo {
    Func_T pFunction;
    u8 linkInProgress;
    u16 timer;
    u8 active;
    u8 stage;
    u8 linkStage;
    u8 result;
    u8 errorFlag;
    u16 command;
    s8 fusionGalleryImages;
    s8 language;
    u16 musicTrack;
    u16 musicPriority;
};

struct CableLinkSerialTransferInfo {
    u8 isParent;
    u8 stage;
    u8 unk_2; // set but never read?
    u8 dataTransferStage;
    u8 verifyTransferResult; // 0 if transfer not verified yet, 1 if correct number of GBA's, 2 if more than 2 GBA's detected
    u8 errorDuringTransfer;
    u8 unk_6; // unused
    u8 unk_7; // unused
    const u32* pData; // pointer to data to transfer
    s32 dataCursor; // index into data to transfer
    s32 dataSizeInt;
    u32 dataChecksum;
};

extern struct IoTransferInfo gIoTransferInfo;

extern struct MultiBootData gMultiBootParamData;
extern const u8* gDataSentPointer;
extern u32 gDataSentSize;

extern u16 gRegIme_Backup;
extern u16 gRegIe_Backup;
extern u16 gRegTm3Cnt_H_Backup;
extern u16 gRegSiocnt_Backup;
extern u16 gRegRcnt_Backup;

extern u32 gMultibootErrorFlags;
extern u8 gMultibootInProgress;
extern u32 gMultibootUnk_3005880;
extern u16 gMultibootRequiredData[4];//MULTIBOOT_MAX_CHILD

extern u8 gCableLinkUnk_30058aa; // unused
extern u16 gSerialTransferDataTimer;
extern u8 gSerialTransferStartupTimer;
extern u8 gCableLinkUnk_30058af; // unused
extern u8 gSerialTransferGbaDetectedCount;
extern u8 gSerialTransferGbaId; // unused, 0 = parent, 1-3 = child 1-3 GBA

extern u16 gSerialTransferUpdateResult;
extern struct CableLinkSerialTransferInfo gCableLinkSerialTransferInfo;

extern u32 gErrorFlag;
extern u16 gSendCmd[2];//CMD_LENGTH
extern CableLinkBuffer1_T gRecvCmds;

extern struct CableLinkInfo gCableLinkInfo;
extern u16 gLinkSavedIme;
extern u8 sNumVBlanksWithoutSerialIntr;
extern u8 sSendBufferEmpty;
extern u8 gLastRecvQueueCount;
extern u8 sHandshakePlayerCount;
extern u8 sChecksumAvailable;
extern u16 sSendNonzeroCheck;
extern u16 sRecvNonzeroCheck;
extern u8 gLastSendQueueCount;

extern u8 gShouldAdvanceLinkState;
extern u8 gLinkPlayerCount;
extern u8 gLinkLocalId;
extern u8 gLinkUnkFlag9;

#endif /* CABLE_LINK_STRUCTS_H */
