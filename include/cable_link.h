#ifndef CABLE_LINK_H
#define CABLE_LINK_H

#include "types.h"
#include "structs/cable_link.h"

#define READ_SIO_MULTI(i) (*(((vu16*)REG_SIO_MULTI) + i))

u8 CableLinkProcess(void);
void CableLinkDrawErrorStr(const u8* str, u16* dst, u8 palette);
void CableLinkResetTransfer(struct MultiBootData* pMultiBoot);
u32 unk_891a0(struct MultiBootData* pMultiBoot);
u32 CableLinkStartTransfer(struct MultiBootData* pMultiBoot, u16 data);
void unk_895dc(struct MultiBootData* pMultiBoot);
void unk_89600(struct MultiBootData* pMultiBoot, const u8* src, s32 length, u8 param_4, u8 param_5);
u32 unk_896b8(struct MultiBootData* pMultiBoot);
u32 unk_896cc(struct MultiBootData* pMultiBoot);
void CableLinkCheckCurrentMemoryRegion(s32 param_1);
void unk_897d0(void);
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
u8 unk_89e30(void);
u8* CableLinkCheckError(void);
void unk_8a12c(u16 param_1);
void unk_8a1d4(void);
void unk_8a260(void);
void unk_8a2c8(void);
void unk_8a39c(void);
u32 CableLinkDetectError(u8* param_1, u16* param_2, CableLinkBuffer1_T param_3);
void unk_8a4cc(void);
void unk_8a4f8(void);
void unk_8a548(u16* param_1);
void unk_8a628(CableLinkBuffer1_T param_1);
void unk_8a730(void);
void unk_8a7a0(void);
void unk_8a7b0(void);
void CableLinkStartSerialTransfer_Duplicate(void);
u8 unk_8a850(void);
void unk_8a94c(void);
void unk_8aa54(void);
void unk_8aaf0(void);
void unk_8ab24(void);
void unk_8ab54(void);
void unk_8ab9c(void);

#endif /* CABLE_LINK_H */