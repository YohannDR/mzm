#ifndef PARTICLE_STRUCT_H
#define PARTICLE_STRUCT_H

#include "types.h"
#include "macros.h"

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
extern const u16* gCurrentParticleEffectOamFramePointer;
extern u16 gParticleEscapeOamFrames[OAM_DATA_SIZE(8)];
extern u16 gParticleSamusReflectionOamFrames[OAM_DATA_SIZE(24)];

#endif /* PARTICLE_STRUCT_H */
