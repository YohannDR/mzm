#ifndef TEXT_POINTERS_DATA_H
#define TEXT_POINTERS_DATA_H

#include "types.h"
#include "location_text.h"

#include "constants/game_state.h"
#include "constants/text.h"

extern const u16* const sJapaneseTextPointers_Message[MESSAGE_END];
extern const u16* const sJapaneseTextPointers_Location[LT_END];

extern const u16* const sHiraganaTextPointers_Message[MESSAGE_END];
extern const u16* const sHiraganaTextPointers_Location[LT_END];

extern const u16* const sEnglishTextPointers_Message[MESSAGE_END];
extern const u16* const sEnglishTextPointers_Location[LT_END];

extern const u16* const * const sLocationTextPointers[LANGUAGE_END];
extern const u16* const * const sMessageTextPointers[LANGUAGE_END];
extern const u16* const * const sFileScreenTextPointers[LANGUAGE_END];

extern const u16* const sJapaneseTextPointers_Description[DESCRIPTION_TEXT_END];
extern const u16* const sJapaneseTextPointers_Story[STORY_TEXT_END];
extern const u16* const sJapaneseTextPointers_FileScreen[FILE_SCREEN_TEXT_END];

extern const u16* const sHiraganaTextPointers_Description[DESCRIPTION_TEXT_END];
extern const u16* const sHiraganaTextPointers_Story[STORY_TEXT_END];
extern const u16* const sHiraganaTextPointers_FileScreen[FILE_SCREEN_TEXT_END];

extern const u16* const sEnglishTextPointers_Description[DESCRIPTION_TEXT_END];
extern const u16* const sEnglishTextPointers_Story[STORY_TEXT_END];
extern const u16* const sEnglishTextPointers_FileScreen[FILE_SCREEN_TEXT_END];

#endif /* TEXT_POINTERS_DATA_H */
