#ifndef TRANSFER_STRUCTS_H
#define TRANSFER_STRUCTS_H

#include "types.h"

struct TransferStatus {
    u8 isParent;
    u8 stage;
    u8 unk_2; // set but never read, cursor * 100 / sizeInt
    u8 dataTransferStage;
    u8 verifyTransferResult; // 0 if transfer not verified yet, 1 if correct number of GBA's, 2 if more than 2 GBA's detected
    u8 errorDuringTransfer;
};

struct TransferData {
    const u32* pData; // pointer to data to transfer
    s32 cursor; // index into data to transfer
    s32 sizeInt;
    u32 checksum;
};

struct TransferManager {
    struct TransferStatus status;
    struct TransferData data;
};

extern u16 gRegIme_Backup;
extern u16 gRegIe_Backup;
extern u16 gRegTm3Cnt_H_Backup;
extern u16 gRegSiocnt_Backup;
extern u16 gRegRcnt_Backup;

extern u8 gTransferUnk_30058aa; // set but never read
extern u16 gTransferDataTimer;
extern u8 gTransferStartupTimer;
extern u8 gTransferUnk_30058af; // set but never read
extern u8 gTransferGbaDetectedCount;
extern u8 gTransferGbaId; // unused, 0 = parent, 1-3 = child 1-3 GBA

extern u16 gTransferUpdateResult;
extern struct TransferManager gTransferManager;

#endif /* TRANSFER_STRUCTS_H */
