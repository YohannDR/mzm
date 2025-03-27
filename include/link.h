#ifndef LINK_H
#define LINK_H

#include "types.h"
#include "structs/cable_link.h"

u8 FusionGalleryLinkProcess(void);
u8* HandleLinkConnection(void);
void BuildSendCmd(u16 command);
void ProcessRecvCmds(void);

void DisableSerial(void);
void EnableSerial(void);
void ResetSerial(void);
u32 LinkMain(u8* shouldAdvanceLinkState, u16* sendCmd, CableLinkBuffer1_T recvCmds);
void CheckParentOrChild(void);
void InitTimer(void);
void EnqueueSendCmd(u16* sendCmd);
void DequeueRecvCmds(CableLinkBuffer1_T recvCmds);
void LinkVSync(void);
void Timer3Intr(void);
void SerialCB(void);
void StartTransfer(void);
u8 DoHandshake(void);
void DoRecv(void);
void DoSend(void);
void StopTimer(void);
void SendRecvDone(void);
void ResetSendBuffer(void);
void ResetRecvBuffer(void);

#endif /* LINK_H */
