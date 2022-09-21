#ifndef ATOMIC_AI_H
#define ATOMIC_AI_H

#include "types.h"

#define ATOMIC_POSE_IDLE_INIT 0x8
#define ATOMIC_POSE_IDLE 0x9
#define ATOMIC_POSE_MOVE 0x23
#define ATOMIC_POSE_MOVE_BACK_IDLE 0x25
#define ATOMIC_POSE_CHASING_SAMUS_INIT 0x26
#define ATOMIC_POSE_CHASING_SAMUS 0x27

#define ATOMIC_ELECTRICITY_POSE_SPAWN 0x8
#define ATOMIC_ELECTRICITY_POSE_MOVE 0x9
#define ATOMIC_ELECTRICITY_POSE_EXPLODING 0x23
#define ATOMIC_ELECTRICITY_POSE_ON_GROUND 0x25

void AtomicSmoothMovement(void);
void AtomicUpdateDirectionToFleeSamus(void);
void AtomicCheckShootElectricity(void);
void AtomicInit(void);
void AtomicIdleInit(void);
void AtomicIdle(void);
void AtomicMove(void);
void AtomicMaybeMoveBackToIdle(void);
void AtomicChasingSamusInit(void);
void AtomicChaseSamus(void);
u8 AtomicElectricityCheckAtomicDead(u8 ramSlot);
void AtomicElectriciytInit(void);
void AtomicElectricitySpawn(void);
void AtomicElectricityMove(void);
void AtomicElectricityExploding(void);
void AtomicElectricityCheckOnGroundAnimEnded(void);
void Atomic(void);
void AtomicElectricity(void);

#endif /* ATOMIC_AI_H */