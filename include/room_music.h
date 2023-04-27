#ifndef ROOM_MUSIC_H
#define ROOM_MUSIC_H

#include "types.h"

void CheckPlayRoomMusicTrack(u8 area, u8 room);
void CheckPlayLoadingJingle(void);
void UpdateMusicWhenPausing(void);
void UpdateMusicAfterPause(void);

#endif /* ROOM_MUSIC_H */
