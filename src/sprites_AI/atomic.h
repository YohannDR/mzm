#ifndef ATOMIC_AI_H
#define ATOMIC_AI_H

#include "../types.h"

void AtomicSmoothMovement(void);
void AtomicUpdateDirectionToFleeSamus(void);
void AtomicShootElectricity(void);
void AtomicInit(void);
void AtomicGFXInit(void);
void AtomicIdleAnimation(void);
void AtomicMove(void);
void AtomicMaybeMoveBackToIdle(void);
void AtomicChasingSamusInit(void);
void AtomicChaseSamus(void);
u8 AtomicElectricityCheckAtomicAlive(u8 slot);
void AtomicElectriciytInit(void);
void AtomicElectricitySpawn(void);
void AtomicElectricityMove(void);
void AtomicElectricityExploding(void);
void AtomicElectricityCheckOnGroundAnimEnded(void);
void Atomic(void);
void AtomicElectricity(void);

#endif /* ATOMIC_AI_H */