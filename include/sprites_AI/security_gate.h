#ifndef SECURITY_GATE_AI_H
#define SECURITY_GATE_AI_H

#include "types.h"

void SecurityGateChangeCCAA(u8 caa);
void SecurityGateOpen(void);
void SecurityGateStartClosing(void);
void SecurityGateDefaultOpenInit(void);
void SecurityGateDefaultOpenCheckAlarm(void);
void SecurityGateCheckClosingAnimEnded(void);
void SecurityGateDefaultOpenOpenAfterAlarm(void);
void SecurityGateCheckOpeningAnimEnded(void);
void SecurityGateDeath(void);
void SecurityGateDefaultClosedInit(void);
void SecurityGateDefaultClosedCheckAlarm(void);
void SecurityGateDefaultClosedCloseAfterAlarm(void);
void SecurityGateDefaultOpen(void);
void SecurityGateDefaultClosed(void);

#endif /* SECURITY_GATE_AI_H */