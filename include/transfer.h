#ifndef TRANSFER_H
#define TRANSFER_H

#include "types.h"

u32 CableLinkProcessSerialTransfer(u32 size, const u32* pData);
void CableLinkResetSerialTransfer(void);
void CableLinkStopSerialTransfer(void);
void CableLinkInitializeSerialTransfer(void);
void CableLinkSetNormalSerialWait(void);
u16 CableLinkUpdateSerialTransfer(u32 param_1, u32 size, const u32* pData, u32 param_3);
u16 CableLinkIsGbaParent(u8 wantParent);
void CableLinkLoadDataAndSizeToTransfer(u32 size, const u32* pData, u32 param_3);
void CableLinkInitializeTimer3(void);
void CableLinkBeginTransferWithTimer3(void);
void CableLinkSerialTransferExchangeData(void);
void CableLinkStartSerialTransfer(void);
void CableLinkStopAndReloadTimer3(void);
void CableLinkBackupIoRegs(void);
void CableLinkRetrieveIoRegs(void);

#endif /* TRANSFER_H */
