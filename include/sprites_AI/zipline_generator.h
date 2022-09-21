#ifndef ZIPLINE_GENERATOR_AI_H
#define ZIPLINE_GENERATOR_AI_H

#include "types.h"

#define ZIPLINE_GENERATOR_POSE_DETECT_SAMUS 0x9
#define ZIPLINE_GENERATOR_POSE_ACTIVATING 0xB
#define ZIPLINE_GENERATOR_POSE_ACTIVATED 0xc
#define ZIPLINE_GENERATOR_POSE_ALREADY_ACTIVATED 0xF

// Zipline generator part

#define ZIPLINE_GENERATOR_PART_POSE_MORPH_SYMBOL_ACTIVATING 0xB
#define ZIPLINE_GENERATOR_PART_POSE_IDLE 0x61

#define ZIPLINE_GENERATOR_PART_CONDUCTOR 0x0
#define ZIPLINE_GENERATOR_PART_MORPH_SYMBOL 0x1
#define ZIPLINE_GENERATOR_PART_ELECTRICITY 0x2

void ZiplineGeneratorChangeCCAA(u8 caa);
void ZiplineGeneratorInit(void);
void ZiplineGeneratorDetectSamus(void);
void ZiplineGeneratorActivating(void);
void ZiplineGenerator(void);
void ZiplineGeneratorPart(void);

#endif /* ZIPLINE_GENERATOR_AI_H */