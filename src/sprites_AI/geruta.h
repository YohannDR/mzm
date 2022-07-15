#ifndef GERUTA_AI_H
#define GERUTA_AI_H

#include "../types.h"

u8 GerutaYMovement(u16 movement);
u8 GerutaXMovement(u16 movement);
void GerutaInit(void);
void GerutaGFXInit(void);
void GerutaDetectSamus(void);
void GerutaGoDownGFXInit(void);
void GerutaCheckWarningEnded(void);
void GerutaCheckGoingDownAnimEnded(void);
void GerutaGoingDown(void);
void GerutaCheckBouncingAnimEnded(void);
void GerutaGoingUp(void);
void GerutaCheckResetAnimEnded(void);
void Geruta(void);

#endif /* GERUTA_AI_H */