#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"

// Functions

void SoundPlay(u16 sound);
void SoundStop(u16 sound);
void SoundPlayNotAlreadyPlaying(u16 sound);
void SoundUpdateAudio(void);
void SoundFade(u16 sound, u16 timer);
void SoundFadeAll(u16 timer);
void FadeCurrentMusicAndQueueNextMusic(u16 timer, u16 music, u8 priority);
void MusicUpdatePriority(u8 priority);
void MusicFade(u16 timer);
void MusicPlay(u16 music, u8 priority);
void MusicUpdateAfterAlarmDisable(void);

#endif /* MUSIC_H */
