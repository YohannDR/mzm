#ifndef LINK_STRUCTS_H
#define LINK_STRUCTS_H

#include "types.h"

#define MAX_LINK_PLAYERS 2
#define CMD_LENGTH 2
#define QUEUE_CAPACITY 32
#define LINKCMD_NONE 0xEFFF
#define PARENT_HANDSHAKE 0x8FFF
#define CHILD_HANDSHAKE 0x7C40

#define LINK_CHILD  0
#define LINK_PARENT 8

#define LINKCMD_2200 0x2200 // fusion gallery images received is less than 4
#define LINKCMD_3300 0x3300 // fusion gallery images done sending?
#define LINKCMD_4400 0x4400 // languages are synced
#define LINKCMD_5500 0x5500 // language to send/received
#define LINKCMD_6600 0x6600 // receiving fusion gallery images
#define LINKCMD_8800 0x8800 // unused?

enum LinkStage {
    LINK_STAGE_INIT,
    LINK_STAGE_PROCESS_CONNECTION,
    LINK_STAGE_RECEIVED_GALLERY,
    LINK_STAGE_ERROR0,
    LINK_STAGE_ERROR1,
    LINK_STAGE_UNK5
};

enum LinkState {
    LINK_STATE_START0,
    LINK_STATE_START1,
    LINK_STATE_HANDSHAKE,
    LINK_STATE_INIT_TIMER,
    LINK_STATE_CONN_ESTABLISHED
};

enum QueueFull {
    QUEUE_FULL_NONE,
    QUEUE_FULL_SEND,
    QUEUE_FULL_RECV
};

enum LagStatus {
    LAG_NONE,
    LAG_PARENT,
    LAG_CHILD
};

struct CableLinkInfo {
    u8 isParent;
    u8 state;
    u8 localId;
    u8 playerCount;
    u16 handshakeBuffer[4];
    u8 recievedNothing;
    u8 serialIntrCounter;
    u8 unk_E;
    u8 unk_F; // unused
    u8 handshakeAsParent;
    u8 unk_11;
    u8 hardwareErrorFlag;
    u8 checksumErrorFlag;
    u8 overflowErrorFlags;
    u8 sioErrorFlags;
    u16 checksum;
    u8 sendCmdIndex;
    u8 recvCmdIndex;
    u8 unk_1A; // unsued
    u8 unk_1B; // unused
    u16 sendQueue_Data[CMD_LENGTH][QUEUE_CAPACITY];
    u8 sendQueue_Pos;
    u8 sendQueue_Count;
    u8 unk_9E; // unused
    u8 unk_9F; // unused
    u16 recvQueue_Data[MAX_LINK_PLAYERS][CMD_LENGTH][QUEUE_CAPACITY];
    u8 recvQueue_Pos;
    u8 recvQueue_Count;
    u8 unk_1A2; // unused
};

#endif /* LINK_STRUCTS_H */
