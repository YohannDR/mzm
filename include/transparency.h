#ifndef TRANSPARENCY_H
#define TRANSPARENCY_H

#include "types.h"

// Globals

extern struct BldalphaData gBldalphaData1;
extern struct BldalphaData gBldalphaData2;
extern struct BldyData gBLDYData1;
extern struct BldyData gBLDYData2;

// Defines

#define TRANSPARENCY_ACTIVE 0x1

// Structs

struct BldalphaData {
    u16 BLDCNT;
    u8 activeFlag;
    u8 evbCoef;
    u8 evaCoef;
    i8 delayMax;
    i8 delay;
    u8 intensity;
};

struct BldyData {
    u16 BLDCNT;
    u8 activeFlag;
    u8 value;
    i8 delayMax;
    i8 delay;
    u8 intensity;
};

// Functions

void TransparencySetRoomEffectsTransparency(void);
u16 TransparencyGetBGSizeFlag(u8 size);
u16 TransparencyCheckIsDarkRoom(void);
void TransparencyUpdateBLDCNT(u8 action, u16 value);
void TransparencySpriteUpdateBLDY(u8 value, i8 delay, u8 intensity);
void TransparencySpriteUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity);
void TransparencyUpdateBLDY(u8 value, i8 delay, u8 intensity);
void TransprencyUpdateBLDALPHA(u8 eva, u8 evb, i8 delay, u8 intensity);
void TransprencyApplyNewEffects(void);
void TransprencyApplyNewBLDALPHA(struct BldalphaData* pBldalpha);
void TransprencyApplyNewBLDY(struct BldyData* pBldy);
void unk_55e60(void);
void unk_55f68(void);

#endif /* TRANSPARENCY_H */