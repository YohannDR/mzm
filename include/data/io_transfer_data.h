#ifndef IO_TRANSFER_DATA_H
#define IO_TRANSFER_DATA_H

#include "types.h"
#include "structs/cable_link.h"

extern const struct IoTransferInfo sIoTransferInfo_Empty;

extern const u8 sPlayer4String[4];
extern const u8 sPlayer3String[4];
extern const u8 sPlayer2String[4];
extern const u8 sPlayer1String[4];

#ifdef DEBUG
extern const u8 sCableLinkDebugString_Blank[20];
extern const u8 sCableLinkDebugString_NotConnected1[20];
extern const u8 sCableLinkDebugString_NotConnected2[20];
extern const u8 sCableLinkDebugString_Checking1[16];
extern const u8 sCableLinkDebugString_Checking2[16];
extern const u8 sCableLinkDebugString_Ready1[16];
extern const u8 sCableLinkDebugString_Ready2[16];
extern const u8 sCableLinkDebugString_PressAButton1[20];
extern const u8 sCableLinkDebugString_PressAButton2[20];
extern const u8 sCableLinkDebugString_NowSending11[20];
extern const u8 sCableLinkDebugString_NowSending12[20];
extern const u8 sCableLinkDebugString_1_Right[20];
extern const u8 sCableLinkDebugString_2_Right[20];
extern const u8 sCableLinkDebugString_BootChecking1[20];
extern const u8 sCableLinkDebugString_BootChecking2[20];
extern const u8 sCableLinkDebugString_NoClientBit1[20];
extern const u8 sCableLinkDebugString_NoClientBit2[20];
extern const u8 sCableLinkDebugString_PressA1[12];
extern const u8 sCableLinkDebugString_PressA2[12];
extern const u8 sCableLinkDebugString_Sending1[12];
extern const u8 sCableLinkDebugString_Success[12];
extern const u8 sCableLinkDebugString_Retry[12];
extern const u8 sCableLinkDebugString_Error[12];
extern const u8 sCableLinkDebugString_TimeOut[12];
#endif // DEBUG

extern const u8 sErrorString_IdOver[16];
extern const u8 sErrorString_ChecksumError[20];
extern const u8 sErrorString_HardwareError[20];
extern const u8 sErrorString_SendOverflow[20];
extern const u8 sErrorString_ReceiveOverflow[20];
extern const u8 sErrorString_SioInternal[20];
extern const u8 sErrorString_SioStop[20];

#endif /* IO_TRANSFER_DATA_H */
