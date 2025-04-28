#ifndef LINK_STRUCTS_H
#define LINK_STRUCTS_H

#include "types.h"

#define MAX_LINK_PLAYERS 2
#define CMD_LENGTH 2
#define QUEUE_CAPACITY 32

#define PARENT_HANDSHAKE 0x8FFF
#define CHILD_HANDSHAKE 0x7C40

#define LINK_CHILD  0
#define LINK_PARENT 8

#define LINK_STAT_LOCAL_ID 0x3

#define LINK_STAT_SHIFT_PLAYER_COUNT     2
#define LINK_STAT_SHIFT_PARENT           5
#define LINK_STAT_SHIFT_CONN_ESTABLISHED 6
#define LINK_STAT_SHIFT_RECEIVED_NOTHING 8
#define LINK_STAT_SHIFT_ERRORS           9

#define LINK_STAT_PLAYER_COUNT     (7 << LINK_STAT_SHIFT_PLAYER_COUNT)
#define LINK_STAT_PARENT           (1 << LINK_STAT_SHIFT_PARENT)
#define LINK_STAT_CONN_ESTABLISHED (1 << LINK_STAT_SHIFT_CONN_ESTABLISHED)
#define LINK_STAT_RECEIVED_NOTHING (1 << LINK_STAT_SHIFT_RECEIVED_NOTHING)
#define LINK_STAT_ERRORS           (7 << LINK_STAT_SHIFT_ERRORS)

#define LINK_ERROR_SHIFT_HARDWARE 0x10
#define LINK_ERROR_SHIFT_CHECKSUM 0x11
#define LINK_ERROR_SHIFT_OVERFLOW 0x12
#define LINK_ERROR_SHIFT_SIO      0x14
#define LINK_ERROR_SHIFT_ID_OVER  0x16

#define LINK_ERROR_HARDWARE         (1 << LINK_ERROR_SHIFT_HARDWARE)
#define LINK_ERROR_CHECKSUM         (1 << LINK_ERROR_SHIFT_CHECKSUM)
#define LINK_ERROR_SEND_OVERFLOW    (1 << LINK_ERROR_SHIFT_OVERFLOW)
#define LINK_ERROR_RECEIVE_OVERFLOW (2 << LINK_ERROR_SHIFT_OVERFLOW)
#define LINK_ERROR_SIO_INTERNAL     (1 << LINK_ERROR_SHIFT_SIO)
#define LINK_ERROR_SIO_STOP         (2 << LINK_ERROR_SHIFT_SIO)
#define LINK_ERROR_ID_OVER          (1 << LINK_ERROR_SHIFT_ID_OVER)

#define EXTRACT_PLAYER_COUNT(status) (((status) & LINK_STAT_PLAYER_COUNT) >> LINK_STAT_SHIFT_PLAYER_COUNT)
#define EXTRACT_LINK_ERRORS(status) (((status) & LINK_STAT_ERRORS) >> LINK_STAT_SHIFT_ERRORS)

// TODO: document/verify commands
#define LINKCMD_2200 0x2200 // fusion gallery images received is less than 4
#define LINKCMD_3300 0x3300 // fusion gallery images done sending?
#define LINKCMD_4400 0x4400 // languages are synced
#define LINKCMD_5500 0x5500 // language to send/received
#define LINKCMD_6600 0x6600 // receiving fusion gallery images
#define LINKCMD_8800 0x8800 // unused?
#define LINKCMD_NONE 0xEFFF

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

struct LinkSession {
    u8 isParent;
    u8 state;
    u8 localId;
    u8 playerCount;
    u16 handshakeBuffer[4];
    u8 receivedNothing;
    u8 serialIntrCounter;
};

struct LinkConnection {
    u8 handshakeAsParent;
    u8 unk_11;
    u8 hardwareErrorFlag;
    u8 checksumErrorFlag;
    u8 overflowErrorFlags;
    u8 sioErrorFlags;
    u16 checksum;
    u8 sendCmdIndex;
    u8 recvCmdIndex;
};

struct SendQueue {
    u16 data[CMD_LENGTH][QUEUE_CAPACITY];
    u8 pos;
    u8 count;
};

struct RecvQueue {
    u16 data[MAX_LINK_PLAYERS][CMD_LENGTH][QUEUE_CAPACITY];
    u8 pos;
    u8 count;
};

struct LinkInfo {
    struct LinkSession session;
    struct LinkConnection connection;
    struct SendQueue sendQueue;
    struct RecvQueue recvQueue;
};

extern u32 gErrorFlag;
extern u16 gSendCmd[CMD_LENGTH];
extern u16 gRecvCmds[MAX_LINK_PLAYERS][CMD_LENGTH]; // players and commands are switched?

extern u8 gShouldAdvanceLinkState;
extern u8 gLinkPlayerCount;
extern u8 gLinkLocalId;
extern u8 gLinkUnkFlag9; // set but never read
extern u16 gLinkSavedIme;

extern u8 gNumVBlanksWithoutSerialIntr;
extern u8 gSendBufferEmpty;
extern u8 gHandshakePlayerCount;
extern u8 gChecksumAvailable;
extern u16 gSendNonzeroCheck;
extern u16 gRecvNonzeroCheck;

extern u8 gLastSendQueueCount;
extern u8 gLastRecvQueueCount;
extern struct LinkInfo gLink;

#endif /* LINK_STRUCTS_H */
