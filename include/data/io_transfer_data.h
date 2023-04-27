#ifndef IO_TRANSFER_DATA_H
#define IO_TRANSFER_DATA_H

#include "types.h"
#include "structs/cable_link.h"

extern const struct IoTransferInfo sIoTransferInfo_Empty;

extern const u8 sPlayer4String[4];
extern const u8 sPlayer3String[4];
extern const u8 sPlayer2String[4];
extern const u8 sPlayer1String[4];

extern const u8 sErrorString_IdOver[16];
extern const u8 sErrorString_ChecksumError[20];
extern const u8 sErrorString_HardwareError[20];
extern const u8 sErrorString_SendOverflow[20];
extern const u8 sErrorString_ReceiveOverflow[20];
extern const u8 sErrorString_SioInternal[20];
extern const u8 sErrorString_SioStop[20];

#endif /* IO_TRANSFER_DATA_H */
