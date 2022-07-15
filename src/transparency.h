#ifndef TRANSPARENCY_H
#define TRANSPARENCY_H

#include "types.h"

struct BldalphaData {
    u16 maybe_bldcnt;
    u8 unk;
    u8 eva;
    u8 evb;
    u8 unk2;
    u8 unk3;
    u8 fading_related;
};

struct BldyData {
    u16 unk;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};

void TransparencySetRoomEffectsTransparency(void);
u16 TransparencyGetBGSizeFlag(u8 size);
u16 TransparencyCheckIsDarkRoom(void);
void TransparencyUpdateBLDCNT(u8 action, u16 value);
void TransparencySpriteUpdateBLDY(u8 value, u8 delay, u8 intensity);
void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, u8 delay, u8 intensity);
void TransparencyUpdateBLDY(u8 value, u8 delay, u8 intensity);
void TransprencyUpdateBLDALPHA(u8 eva, u8 evb, u8 unk, u8 fading_related);
void TransprencyApplyNewEffects(void);
void TransprencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha);
void TransprencyApplyNewBLDY(struct BldyData* pBldy);
void unk_55e60(void);
void unk_55f68(void);

#endif /* TRANSPARENCY_H */