#ifndef SKULTERA_AI_H
#define SKULTERA_AI_H

#include "../types.h"

void SkulteraSetSidesHitbox(void);
u8 SkulteraXMovement(u16 movement);
void SkulteraInit(void);
void SkulteraGFXInit(void);
void SkulteraMoving(void);
void SkulteraChasingSamusGFXInit(void);
void SkulteraChasingSamus(void);
void SkulteraTurningAroundGFXInit(void);
void SkulteraCheckTurningAroundAnimEnded(void);
void skultera(void);

#endif /* SKULTERA_AI_H */