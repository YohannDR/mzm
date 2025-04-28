#ifndef LINK_H
#define LINK_H

#include "types.h"
#include "structs/link.h"

u8 FusionGalleryLinkProcess(void);
u8* LinkHandleConnection(void);
void LinkBuildSendCmd(u16 command);
void LinkProcessRecvCmds(void);

void LinkDisableSerial(void);
void LinkEnableSerial(void);
void LinkResetSerial(void);
u32 LinkMain(u8* shouldAdvanceLinkState, u16 sendCmd[CMD_LENGTH], u16 recvCmds[MAX_LINK_PLAYERS][CMD_LENGTH]);
void LinkCheckParentOrChild(void);
void LinkInitTimer(void);
void LinkEnqueueSendCmd(u16 sendCmd[CMD_LENGTH]);
void LinkDequeueRecvCmds(u16 recvCmds[MAX_LINK_PLAYERS][CMD_LENGTH]);
void LinkVSync(void);
void LinkReloadTransfer(void);
void LinkCommunicate(void);
void LinkStartTransfer(void);
u8 LinkDoHandshake(void);
void LinkDoRecv(void);
void LinkDoSend(void);
void LinkStopTimer(void);
void LinkSendRecvDone(void);
void LinkResetSendBuffer(void);
void LinkResetRecvBuffer(void);

#endif /* LINK_H */
