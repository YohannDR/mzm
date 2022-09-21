#ifndef ESCAPE_GATE_AI_H
#define ESCAPE_GATE_AI_H

#include "types.h"

#define ESCAPE_GATE_POSE_LOAD_GRAPHICS 0x1
#define ESCAPE_GATE_POSE_IDLE 0x9
#define ESCAPE_GATE_POSE_CHECK_OPEN 0x22
#define ESCAPE_GATE_POSE_OPENING 0x23
#define ESCAPE_GATE_POSE_OPENED 0x25
#define ESCAPE_GATE_POSE_ESCAPING 0x27

void EscapeGateChangeCCAA(u8 caa);
void EscapeGate(void);

#endif /* ESCAPE_GATE_AI_H */