#ifndef ENDING_AND_GALLERY_H
#define ENDING_AND_GALLERY_H

#include "types.h"

void EndingImageUpdateLettersSpawnDelay(u32 offset);
void EndingImageLoadTextOAM(u32 set);
void EndingImageDisplayLinePermanently(u32 line);
void EndingImageLoadIGTAndPercentageGraphics(void);
void GalleryVBlank(void);
void EndScreenVBlank(void);
void UnlockedOptionsVBlank(void);
void CreditsInit(void);
u8 CreditsDisplayLine(u32 line);
u8 CreditsDisplay(void);
u8 CreditsChozoWallMovement(void);
u8 CreditsChozoWallZoom(void);
void EndScreenInit(void);
u8 EndScreenSamusPosing(void);
void EndingImageInit(void);
void EndingImageDisplayText(void);
u8 EndingImageDisplay(void);
void UnlockedOptionsInit(void);
u8 UnlockedOptionsPopUp(void);
u32 CreditsSubroutine(void);
void GalleryInit(void);
u32 GalleryDisplay(void);
u32 GallerySubroutine(void);

#endif /* ENDING_AND_GALLERY_H */
