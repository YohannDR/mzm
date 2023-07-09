#ifndef POLYP_AI_H
#define POLYP_AI_H

#include "types.h"

#define POLYP_POSE_IDLE_INIT 0x8
#define POLYP_POSE_IDLE 0x9
#define POLYP_POSE_WARNING 0x23
#define POLYP_POSE_SPITTING 0x25
#define POLYP_POSE_AFTER_SPITTING 0x27
#define POLYP_POSE_RETRACTING 0x29

#define POLYP_PROJECTILE_POSE_SPAWN 0x8
#define POLYP_PROJECTILE_POSE_MOVING 0x9
#define POLYP_PROJECTILE_POSE_EXPLODING 0x43

#define POLYP_SHOOT_DELAY (60 * 2)
#define POLYP_SPIT_DURATION (60 / 3)

void PolypInit(void);
void PolypIdleInit(void);
void PolypCheckSpawnProjectile(void);
void PolypCheckWarningEnded(void);
void PolypSpawnProjectile(void);
void PolypCheckAfterSpittingAnimEnded(void);
void PolypCheckRetractingAnimEnded(void);
void PolypProjectileInit(void);
void PolypProjectileSpawn(void);
void PolypProjectileMove(void);
void PolypProjectileExplodingInit(void);
void PolypProjectileCheckExplodingAnimEnded(void);
void Polyp(void);
void PolypProjectile(void);

#endif /* POLYP_AI_H */