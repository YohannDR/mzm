#ifndef TRANSFER_H
#define TRANSFER_H

#include "types.h"

u32 TransferProcessSend(u32 size, const u32* pData);
void TransferInit(void);
void TransferCloseSerial(void);
void TransferOpenSerialMulti(void);
void TransferOpenSerial32(void);
u16 TransferHandleTransfer(u32 transferMode, u32 size, const u32* pData, u32* recvBuffer);
u16 TransferDetermineSendRecvState(u8 transferMode);
void TransferSetUpTransferManager(u32 size, const u32* pData, u32* recvBuffer);
void TransferInitTimer(void);
void TransferReloadTransfer(void);
void TransferExchangeData(void);
void TransferStartTransfer(void);
void TransferStopTimer(void);
void TransferBackupIoRegs(void);
void TransferRetrieveIoRegs(void);

#endif /* TRANSFER_H */
