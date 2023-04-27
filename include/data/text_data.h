#ifndef TEXT_DATA_H
#define TEXT_DATA_H

#include "types.h"
#include "structs/text.h"

extern const u8 sCharacterWidths[1184];

extern const struct Message sMessage_Empty;

extern const struct Message sMessageStoryText_Empty;

extern const struct Message sMessageFileScreen_Empty;

extern const struct Message sMessageDescription_Empty;

// Temp
extern const u16** const sStoryTextPointers[7];
extern const u16** const sLocationTextpointers[7];
extern const u16** const sMessageTextpointers[7];
extern const u16** const sFileScreenTextPointers[7];
extern const u16** const sDescriptionTextPointers[7];

extern const u32 sCharactersGFX[1];
extern const u32 sArray_760338[24];
extern const u32 sArray_760398[8];

#endif /* TEXT_DATA_H */
