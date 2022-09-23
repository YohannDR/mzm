#ifndef PARTICLE_STRUCT_H
#define PARTICLE_STRUCT_H

#include "types.h"

// Structs

struct ParticleEffect {
    u8 status;
    u8 animationDurationCounter;
    u8 effect;
    u8 stage;
    u8 frameCounter;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
};

// Typedefs

typedef void (*ParticleFunc_T)(struct ParticleEffect*);

// Globals

#define MAX_AMOUNT_OF_PARTICLES 16

extern struct ParticleEffect gParticleEffects[MAX_AMOUNT_OF_PARTICLES];
extern const u16* gCurrentParticleEffectOAMFramePointer;
extern u16 gParticleEscapeOAMFrames[25];
extern u16 gParticleSamusReflectionOAMFrames[73];

#endif