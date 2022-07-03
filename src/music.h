#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"

void sound_play(u16 sound);
void sound_play2(u16 sound);
void sound_call_func(u16 sound, u8 action);
void update_audio(void);

#endif /* MUSIC_H */
