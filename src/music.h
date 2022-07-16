#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"

void SoundPlay(u16 sound);
void SoundStop(u16 sound);
void SoundUpdateAudio(void);
void SoundFade(u16 sound, u16 timer);
void SoundFadeAll(u16 timer);
void MusicFade(u16 timer);

#endif /* MUSIC_H */
