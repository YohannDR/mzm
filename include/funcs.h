#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"

void RestartSound(void);
void QueueSound(u16 id, u32 unk); /* TODO: unk type */
void StopOrFadeSound(u16 id, u32 unk); /* TODO: unk type */
void UpdateAudio();

#endif /* FUNCS_H */
