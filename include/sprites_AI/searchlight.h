#ifndef SEARCHLIGHT_AI_H
#define SEARCHLIGHT_AI_H

#include "types.h"

#define SEARCHLIGHT_POSE_IDLE 0x9
#define SEARCHLIGHT_POSE_ACTIVATING 0x23
#define SEARCHLIGHT_POSE_ACTIVATE_ALARM 0x25

void Searchlight(void);

#endif /* SEARCHLIGHT_AI_H */