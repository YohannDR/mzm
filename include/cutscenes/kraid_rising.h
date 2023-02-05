#ifndef KRAID_RISING_CUTSCENE
#define KRAID_RISING_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

#define KRAID_RISING_OAM_ID_SAMUS 1
#define KRAID_RISING_OAM_ID_DEBRIS 2
#define KRAID_RISING_OAM_ID_SMALL_PUFF 3
#define KRAID_RISING_OAM_ID_BIG_PUFF 4

u8 KraidRisingRising(void);
struct CutsceneOamData* KraidRisingUpdatePuff(struct CutsceneOamData* pOam, u8 puffID);
struct CutsceneOamData* KraidRisingUpdateDebris(struct CutsceneOamData* pOam, u8 debrisID);
u8 KraidRisingOpeningEyes(void);
u8 KraidRisingInit(void);
u8 KraidRisingSubroutine(void);
void KraidRisingProcessOAM(void);

#endif /* KRAID_RISING_CUTSCENE */
