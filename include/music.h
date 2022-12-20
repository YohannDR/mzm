#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"

// Functions

void SoundUpdateAudio(void);

void FadeCurrentMusicAndQueueNextMusic(u16 timer, u16 music, u8 priority);
void MusicUpdatePriority(u8 priority);
void MusicFade(u16 timer);
void MusicPlay(u16 music, u8 priority);
void MusicUpdateAfterAlarmDisable(void);

#endif /* MUSIC_H */
