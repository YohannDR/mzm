#ifndef POLYP_AI_H
#define POLYP_AI_H

#include "../types.h"

void PolypInit(void);
void PolypGFXInit(void);
void PolypCheckSpawnProjectile(void);
void PolypCheckSpittingAnimEnded(void);
void PolypSpawnProjectile(void);
void PolypCheckAfterSpittingAnimEnded(void);
void PolypCheckRetractingAnimEnded(void);
void PolypProjectileInit(void);
void PolypProjectileSpawn(void);
void PolypProjectileMove(void);
void PolypProjectileExplodingGFXInit(void);
void PolypProjectileCheckExplodingAnimEnded(void);
void Polyp(void);
void PolypProjectile(void);

#endif /* POLYP_AI_H */