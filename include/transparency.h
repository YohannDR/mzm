#ifndef TRANSPARENCY_H
#define TRANSPARENCY_H

#include "types.h"
#include "structs/transparency.h"

// Defines

// Functions

void TransparencySetRoomEffectsTransparency(void);
u16 TransparencyGetBGSizeFlag(u8 size);
u32 TransparencyCheckIsDarkRoom(void);
void TransparencyUpdateBLDCNT(u8 action, u16 value);
void TransparencySpriteUpdateBLDY(u8 value, i8 delay, u8 intensity);
void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity);
void TransparencyUpdateBLDY(u8 value, i8 delay, u8 intensity);
void TransparencyUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity);
void TransparencyApplyNewEffects(void);
void TransparencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha);
void TransparencyApplyNewBLDY(struct BldyData* pBldy);
void unk_55e60(void);
void unk_55f68(void);

#endif /* TRANSPARENCY_H */