#ifndef HAZE_H
#define HAZE_H

#include "types.h"

void HazeSetBackgroundEffect(void);
void HazeTransferAndDeactivate(void);
void unk_5d09c(void);
void HazeSetupCode(u8 hazeValue);
void HazeResetLoops(void);
void HazeCalculateGradient(void);
u32 HazeProcess(void);

void Haze_Bg3(void);
void Haze_Bg3StrongWeak(void);
void Haze_Bg3NoneWeak(void);

void Haze_Bg3Bg2StrongWeakMedium(void);
void Haze_Bg3Bg2Bg1(void);

u32 Haze_PowerBombExpanding(void);
u32 Haze_PowerBombRetracting(void);

#endif /* HAZE_H */
