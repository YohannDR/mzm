#ifndef TEXT_H
#define TEXT_H

#include "types.h"
#include "structs/text.h"

u32 TextGetCharacterWidth(u16 charID);
void TextDrawCharacter(u16 charID, u32* dst, u16 indent, u8 color);
void TextDrawMessageCharacter(u16 charID, u32* dst, u16 indent, u8 color);
void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText);
void TextDrawlocation(u8 locationText, u8 gfxSlot);
u8 unk_6f0a8(u8 textID, u8 gfxSlot, u8 param_3);
void TextStartMessage(u8 textID, u8 gfxSlot);
u8 TextProcessItemBanner(void);
void TextStartStory(u8 textID);
u8 TextProcessStory(void);
void TextStartFileScreen(u8 textID);
u8 TextProcessFileScreenPopUp(void);
void TextProcessDescription(void);
u8 TextProcessCurrentMessage(struct Message* pMessage, const u16* pText, u32* dst);
void TextDrawYesNoEasySleep(void);
void TextDrawEasySleep(void);

#endif /* TEXT_H */
