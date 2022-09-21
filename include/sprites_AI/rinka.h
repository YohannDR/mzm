#ifndef RINKA_AI_H
#define RINKA_AI_H

#include "types.h"

#define RINKA_POSE_SPAWNING_INIT 0x8
#define RINKA_POSE_SPAWNING 0x9
#define RINKA_POSE_MOVING 0x23

void RinkaInit(void);
void RinkaSpawningInit(void);
void RinkaRespawn(void);
void RinkaSpawning(void);
void RinkaMove(void);
void RinkaMotherBrainSpawningInit(void);
void RinkaMotherBrainRespawn(void);
void RinkaMotherBrainSpawning(void);
void RinkaMotherBrainMove(void);
void Rinka(void);
void RinkaMotherBrain(void);

#endif /* RINKA_AI_H */