#ifndef CABLE_LINK_STRUCTS_H
#define CABLE_LINK_STRUCTS_H

#include "types.h"

struct MultiBootData {
    u32 systemWork_1[5];
    u8 handshakeData;
    u16 handshakeTimeout;
    u8 probeCount;
    u8 clientData[3];
    u8 paletteData;
    u8 responseBit;
    u8 clientBit;
    u8 reserved_1;
    const u8* bootSourcePointer;
    const u8* bootEndPointer;
    const u8* dataSentPointer;
    u8* reserved_2[3];
    u32 systemWork_2[4];
    u8 sendFlag;
    u8 probeTargetBit;
    u8 checkWait;
    u8 serverType;
};

struct IoTransferInfo {
    Func_T pFunction;
    u8 unk_4;
    u16 timer;
    u8 active;
    u8 unk_9;
    u8 unk_A;
    u8 result;
    u8 errorFlag;
    u16 unk_E;
    i8 fusionGalleryImages;
    u8 language;
    u16 musicTrack;
    u16 musicPriority;
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

extern u32 gUnk_3005874;
extern u8 gUnk_3005884;
extern u32 gUnk_3005880;

#endif /* CABLE_LINK_STRUCTS_H */