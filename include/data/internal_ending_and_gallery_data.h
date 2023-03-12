#ifndef INTERNAL_ENDING_AND_GALLERY_DATA
#define INTERNAL_ENDING_AND_GALLERY_DATA

#include "types.h"

typedef u8 (*CreditsFunc_T)(void);

extern const CreditsFunc_T sCreditsFunctionPointers[3];
extern const CreditsFunc_T sEndScreenFunctionPointers[1];
extern const CreditsFunc_T sEndingImageFunctionPointers[1];
extern const CreditsFunc_T sUnlockedOptionsFunctionPointers[2];

#endif /* INTERNAL_ENDING_AND_GALLERY_DATA */
